#pragma once

#include <CPropertyUnit.h>
#include "../FA2Expand.h"

class NOVTABLE CPropertyUnitExt : public CPropertyUnit
{
public:

	BOOL PreTranslateMessageExt(MSG* pMsg);

	static void ProgramStartupInit();

private:

};