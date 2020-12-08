#include <CMixFile.h>
#include <GlobalVars.h>

#include "../../FA2sp.h"

#include <map>

static std::map<CString, CString> CSFFiles_Stringtable;
static char* pEDIBuffer;
static bool bLoadRes = false;

void LoadCSFFiles(DWORD pThisAddr);
void LoadCSFFile(const char* tmpFilePath, const char* pName, DWORD& pThisAddr);
bool ParseCSFFile(char* buffer, DWORD& size);
void WriteCSFFile();
bool LoadToBuffer();

DEFINE_HOOK(492D10, CSFFiles_Stringtables_Support_1, 5)
{
    if (ExtConfigs::Stringtables)
    {
        LoadCSFFiles(R->Stack32(0x2C0 - 0x268));
        bLoadRes = LoadToBuffer();
        if (bLoadRes)
        {
            R->EDI(pEDIBuffer);
            return 0x49305F;
        }
        else
            return 0;
    }
    return 0;
}

DEFINE_HOOK(49433B, CSFFiles_Stringtables_Support_2, 6)
{
    // Cleanning up
    if (ExtConfigs::Stringtables && bLoadRes)
    {
        GameDelete(pEDIBuffer);
        char tmpCsfFile[0x400];
        strcpy_s(tmpCsfFile, GlobalVars::ExePath());
        strcat_s(tmpCsfFile, "\\RA2Tmp.csf");
        DeleteFile(tmpCsfFile);
        Logger::Debug("Successfully loaded %d csf labels.",CSFFiles_Stringtable.size());
        CSFFiles_Stringtable.clear();
        bLoadRes = false;
    }
    return 0;
}

void LoadCSFFiles(DWORD pThisAddr)
{
    char tmpCsfFile[0x400];
    strcpy_s(tmpCsfFile, GlobalVars::ExePath());
    strcat_s(tmpCsfFile, "\\RA2Tmp.csf");

    char nameBuffer[0x400];
    if (*reinterpret_cast<bool*>(0x5D32AC))
        strcpy_s(nameBuffer, "RA2MD.CSF");
    else
        strcpy_s(nameBuffer, "RA2.CSF");
    LoadCSFFile(tmpCsfFile, nameBuffer, pThisAddr);
    char stringtable[20];
    for (int i = 1; i <= 99; ++i)
    {
        sprintf_s(stringtable, "stringtable%02d.csf", i);
        LoadCSFFile(tmpCsfFile, stringtable, pThisAddr);
    }
    WriteCSFFile();
}

void LoadCSFFile(const char* tmpFilePath, const char* pName, DWORD& pThisAddr)
{
    bool flag = true;
    HANDLE hFile = INVALID_HANDLE_VALUE;
    char directoryBuffer[0x400];
    strcpy_s(directoryBuffer, GlobalVars::FilePath());
    strcat_s(directoryBuffer, "\\");
    strcat_s(directoryBuffer, pName);
    hFile = CreateFile(directoryBuffer, GENERIC_READ, FILE_SHARE_READ, nullptr,
        OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, nullptr);
    if (hFile == INVALID_HANDLE_VALUE)
    {
        if (CMixFile::FindAndCopyTo(pName, tmpFilePath, pThisAddr))
        {
            hFile = CreateFile(tmpFilePath, GENERIC_READ, FILE_SHARE_READ, nullptr,
                OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, nullptr);
            if (hFile == INVALID_HANDLE_VALUE)
                flag = false;
        }
        else
            flag = false;
    }
    if (flag)
    {
        DWORD filesize = GetFileSize(hFile, nullptr);
        ULONG nReadBytes;
        char* fileBuffer = new char[filesize];
        if (ReadFile(hFile, fileBuffer, filesize, &nReadBytes, nullptr) == TRUE)
        {
            bool result = ParseCSFFile(fileBuffer, filesize);
            flag = result;
        }
        CloseHandle(hFile);
        delete[] fileBuffer;
    }
    Logger::Debug(flag ? "Successfully Loaded file %s.\n" : "Cannot read %s while parsing CSFFiles.\n", pName);
    return;
}

bool ParseCSFFile(char* buffer, DWORD& size)
{
    char* pos = buffer;

    auto read_int = [&pos](const void* dest)
    {
        memcpy((void*)dest, pos, 4);
        pos += 4;
    };

    // Parse CSF header
    if (memcmp(pos, " FSC", 0x4) != 0) {
        return false;
    }
    pos += 4; // FSC
    pos += 4; // version
    int _numLabels;
    read_int(&_numLabels);
    pos += 4; // numstrings
    pos += 4; // useless
    pos += 4; // lang
    // Read CSF labels
    for (int i = 0; i < _numLabels; ++i)
    {
        // Read CSF label header
        int identifier;
        read_int(&identifier);
        if (identifier == 0x4C424C20) // " LBL"
        {
            int numPairs;
            read_int(&numPairs);
            int strLength;
            read_int(&strLength);
            
            char* labelstr = new char[strLength + 1];
            labelstr[strLength] = '\0';
            memcpy_s(labelstr, strLength, pos, strLength);

            pos += strLength;
            // CSF labels are not case sensitive.
            for (int k = 0; k < strLength; ++k)
                labelstr[k] = tolower(labelstr[k]);

            read_int(&identifier);
            read_int(&strLength);

            char* tmpWideBuffer = new char[(strLength << 1) + 2];
            for (int i = 0; i < strLength << 1; ++i)
                tmpWideBuffer[i] = ~pos[i];
            wchar_t* ptrWideBuffer = reinterpret_cast<wchar_t*>(tmpWideBuffer);
            ptrWideBuffer[strLength] = '\0';
            
            char* value = nullptr;
            int valueBufferSize = WideCharToMultiByte(CP_ACP, NULL, ptrWideBuffer, strLength, value, 0, NULL, NULL) + 1;
            value = new char[valueBufferSize];
            WideCharToMultiByte(CP_ACP, NULL, ptrWideBuffer, strLength, value, valueBufferSize, NULL, NULL);
            value[valueBufferSize - 1] = '\0';

            pos += (strLength << 1);
            if (identifier == 0x53545257)
            {
                read_int(&strLength);
                pos += strLength;
            }
            CSFFiles_Stringtable[labelstr] = CString(value);
            delete[] labelstr;
            delete[] value;

            for (int j = 1; j < numPairs; ++j)
            {
                read_int(&identifier);
                read_int(&strLength);
                pos += (strLength << 1);
                if (identifier == 0x53545257)
                {
                    read_int(&strLength);
                    pos += strLength;
                }
            }
        }
        else {
            break;
        }
    }
    return true;
}

void WriteCSFFile()
{
    char tmpCsfFile[0x400];
    strcpy_s(tmpCsfFile, GlobalVars::ExePath());
    strcat_s(tmpCsfFile, "\\RA2Tmp.csf");
    HANDLE hFile = CreateFile(tmpCsfFile, GENERIC_WRITE, FILE_SHARE_WRITE, nullptr,
        CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, nullptr);
    if (hFile == INVALID_HANDLE_VALUE)
        return;

    auto write_to_stream = [&hFile](const void* buffer, size_t size = 4) {
        WriteFile(hFile, buffer, size, nullptr, nullptr);
    };

    auto write_int = [&hFile](int n) {
        WriteFile(hFile, &n, 4, nullptr, nullptr);
    };

    // CSF header
    write_to_stream(" FSC");
    write_int(3);
    write_int(CSFFiles_Stringtable.size());
    write_int(CSFFiles_Stringtable.size());
    write_to_stream("sFA2"); // useless
    write_int(0);

    // CSF labels
    for (auto& lbl : CSFFiles_Stringtable)
    {
        // label
        write_to_stream(" LBL");
        write_int(1);
        write_int(lbl.first.GetLength());
        write_to_stream(lbl.first, lbl.first.GetLength());

        // value
        write_to_stream(" RTS");
        wchar_t* value = nullptr;
        int valueBufferSize = MultiByteToWideChar(CP_ACP, NULL, lbl.second, lbl.second.GetLength(), value, 0);
        value = new wchar_t[valueBufferSize + 1];
        MultiByteToWideChar(CP_ACP, NULL, lbl.second, lbl.second.GetLength(), value, valueBufferSize);
        value[valueBufferSize] = '\0';
        char* buffer = reinterpret_cast<char*>(value);
        for (int i = 0; i < valueBufferSize << 1; ++i)
            buffer[i] = ~buffer[i];
        write_int(valueBufferSize);
        write_to_stream(buffer, valueBufferSize << 1);
        delete[] value;
    }
    CloseHandle(hFile);
}

bool LoadToBuffer()
{
    HANDLE hFile = INVALID_HANDLE_VALUE;
    char directoryBuffer[0x400];
    strcpy_s(directoryBuffer, GlobalVars::ExePath());
    strcat_s(directoryBuffer, "\\");
    strcat_s(directoryBuffer, "RA2Tmp.csf");
    hFile = CreateFile(directoryBuffer, GENERIC_READ, FILE_SHARE_READ, nullptr,
        OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, nullptr);
    if (hFile != INVALID_HANDLE_VALUE)
    {
        DWORD dwFileSize = GetFileSize(hFile, nullptr);
        pEDIBuffer = GameCreateArray<char>(dwFileSize);
        return pEDIBuffer != nullptr && ReadFile(hFile, pEDIBuffer, dwFileSize, nullptr, nullptr);
    }
    return false;
}