# FINALALERT2 - SP  帮助文档（Enderseven Tina汉化）

## 开始
- FA2SP和Ares一样需要Syringe.exe工作，可以参考Ares。
- FA2SP推荐原版FinalAlert2 v1.02，其他版本可能会出错！
- 首次启动它请正确编写下面的 ini 文件，尤其是基本文件（以**x**标记）。
- 如果有任何问题，请直接与我联系或邮件至3179369262@qq.com。
- 你可以加入 Discord 服务器 https://discord.gg/k4SVuMm，并在 `DEDICATED PROJECTS` 下找到 `map-editors` 。
- 可能不稳定，请常保存以防损失！XD

多选功能现已可用。Ctrl选择磁贴，Ctrl+Shift取消选择。Ctrl+D清除所有选定的磁贴。
此功能支持 RaiseSingleTile/LowerSingleTile（尽管它们不再是“单一”）、复制粘贴和计算选定的区域矿石值。

## 基本
- **INTEGER** 整数
  - $[-2147483648,2147483647]$ 之间的整数
    - $-1$ $|$ $2$ $|$ $114514$
- **POINT** 列表
  - **INTEGER**, **INTEGER**
    - $1, 2$ $|$ $114514, 1919810$
- **BOOLEAN** 是非
  - $Yes/No$, $True/False$, $1/0$
    - $Yes$ $|$ $true$ $|$ $1$
- **COLORREF** 颜色
  - RGB颜色，数值在 $[0,255]$ 之间
    - $255, 255 ,0$ $|$ $0, 0, 60$

## 基本
- FAData.ini
    - [ExtConfigs]
        - **ObjectBrowser**，`ModernObjectBrowser` 启用时 `BrowserRedraw` 将不会有用。
            - `BrowserRedraw` = **BOOLEAN** ; 启用重构的ObjectBrowserView 
            - `ModernObjectBrowser` = **BOOLEAN** ; 启用实验对象浏览器，替换原版树状视图，默认不启用
                - `ObjectBrowser.GuessMode` = **$0/1$** ; 判断阵营的标准，$0$（默认）为Prerequisite，$1$ 为Owner的第一位
                - `ObjectBrowser.CleanUp` = **BOOLEAN** ; 清除阵营里的空项目
                - `ObjectBrowser.SafeHouses` = **BOOLEAN** ; 重新排列国家
        - `AllowIncludes` = **BOOLEAN** ; 读取其他ini的#include部分（不推荐）
        - `AllowPlusEqual` = **BOOLEAN** ; 读取 += 符号（不推荐）
        - `TutorialTexts.Fix` = **BOOLEAN** ; 将文本加载到组合框时替换原始进程
        - `TutorialTexts.Hide` = **BOOLEAN** ; 减少滞后，因为组合框中的文本可能无用
        - `SortByTriggerName` = **BOOLEAN** ; 按照名称对触发进行排序
        - `AdjustDropdownWidth` = **BOOLEAN** ; 自动调整参数下拉列表宽度
            - `AdjustDropdownWidth.Factor` = **INTEGER** ; 一个字符需要多长时间，默认 $8$
            - `AdjustDropdownWidth.Max` = **INTEGER** ; 组合框的最大长度，默认为 360
        - `CopySelectionBound.Color` = **COLORREF** ; 复制时选择框的颜色，默认 $255,0,0$
        - `CursorSelectionBound.Color` = **COLORREF** ; 当前单元格边界的颜色，默认为 $60,160,60$
        - `HeightIndicatorColor.Color` = **COLORREF** ; 当前单元格高度指示器的颜色，默认为 $60,60,60$
        - `Waypoint.Color` = **COLORREF** ; 航点文本的颜色，默认为 $0,0,255$
        - `Waypoint.Background` = **BOOLEAN** ; 为航点绘制矩形背景。 默认为 false
        - `Waypoint.Background.Color` = **COLORREF** ; 航点背景颜色，默认为 $255,255,255$
        - `Waypoint.Text.ExtraOffset` = **POINT** ; 航点文本的附加 X 轴和 Y 轴偏移量，默认为 $0,0$
        - `ExtWaypoints` = **BOOLEAN** ; 支持无限数量的航点，默认为 **false**（需要Phobos平台）
        - `UndoRedoLimit` = **INTEGER** ; 确定撤消/重做的最大次数，默认为 $16$
        - `UseRGBHouseColor` = **BOOLEAN** ; 国家颜色使用RGB，默认为 **false** 
        - `SaveMap.AutoSave` = **BOOLEAN** ; 自动保存地图
            - `SaveMap.AutoSave.Interval` = **INTEGER** ; 几秒保存一次，建议不小于$30$，默认为 $300$
            - `SaveMap.AutoSave.MaxCount` = **INTEGER** ; 缓存次数，设置为 $-1$ 将禁用自动清理，默认为 $10$
        - `SaveMap.OnlySaveMAP` = **BOOLEAN** ; 只保存为 *.map* 文件
        - `SaveMap.DefaultPreviewOptionMP` = **INTEGER** ; 保存多人游戏地图时用于生成预览的默认单选选项按钮
          - $0$ = 生成新预览
          - $1$ = 不生成新预览
          - $2$ = 生成隐藏预览
          - 默认为 $0$.
        - `SaveMap.DefaultPreviewOptionSP` = **INTEGER** ; 以 **MP** 保存 **SP** 地图，默认为 $1$
        - `VerticalLayout` = **BOOLEAN** ; 将底部视图转到右侧
        - `RecentFileLimit` = **INTEGER** ; 保留最近的文件数，范围从 $4$ 到 $9$ 不等
        - `MultiSelectionColor` = **COLORREF** ; 选定磁贴的背景色
        - `MultiSelectionShiftDeselect` = **BOOLEAN** ; 取消选择所有的快捷键，CTRL+SHIFT+D为 **true** ，CTRL+D为 **false** , 默认为 **false**
        - `RandomTerrainObjects` = **BOOLEAN** ; 在随机树行对话框中显示所有地形对象，默认为 **false**
        - `DDrawInVideoMem` = **BOOLEAN** ; 在视频内存中分配DirectDraw图面，默认为 **true**
        - `DDrawEmulation` = **BOOLEAN** ; DirectDrawCreate使用仿真模式，默认为 **false**
        - `NoHouseNameTranslation` = **BOOLEAN** ; 使用国家的UIName, 默认为 **false**
        - `EnableMultiSelection` = **BOOLEAN** ; 启用体验多选功能，默认为 **false**
        - `ExtendedValidationNoError` = **BOOLEAN** ; 扩展地图验证以警告代替出错，默认为 **false**
        - `HideNoRubbleBuilding` = **BOOLEAN** ; 不渲染HP=0且 `LeaveRubble=no` 的建筑物,默认为 **false**
    - **`[Sides]`** （**x** 表示此项目是 **敏感** ，FA2SP需要此部分才能正常工作）
        - rules中注册的阵营列表
        ```ini
        [Sides]
        0=Allied
        1=Soviet
        2=Yuri
        3=Neutral
        4=Special
        ```
    - `[Theaters]`
        - 环境名称列表，只有现有的6个名称有效。如果未列出，则按以下顺序使用和显示所有默认的6个环境：
        ```ini
        [Theaters]
        0=TEMPERATE
        1=SNOW
        2=URBAN
        3=NEWURBAN
        4=LUNAR
        5=DESERT
        ```
    - `[ForceName]`
        - xxx = Objecttype
        - 强制使用 Name 而不是 UIName 的对象类型列表
        ```ini
        [ForceName]
        0=E1
        ```
    - `[ForceSides]`
        - Technotype = SideIndex
        - 无法直接确定其阵营的对象列表
        ```ini
        [ForceSides]
        ENGINEER=0
        SENGINEER=1
        YENGINEER=2
        ; A LOT OF WESTWOOD CIVILIAN VEHICLES WITH PREREQUISITE 
        ; [NAWEAP] WILL BE GUESSED INTO SOVIETS, FIX THEM MANUALLY
        ```
    - `[ObjectBrowser.SmudgeTypes]` and `[ObjectBrowser.TerrainTypes]`
        - Falanguage中的string = 翻译
        ```ini
        [ObjectBrowser.SmudgeTypes]
        CRATER=SmudgeCraterObList
        BURNT=SmudgeBurntObList
        
        [ObjectBrowser.TerrainTypes]
        TREE=TreesObList
        TRFF=TrafficLightsObList
        SIGN=SignsObList
        LT=LightPostsObList
        ```
    - `[TileManagerDataXXX]` *TEM, SNO, URB, UBN, LUN, DES*
        - DisplayName = 正则表达式
        ```ini
        [TileManagerDataTEM]
        Cliff=cliff
        Water=water
        Ramp=ramp|slope
        Bridge=bridge
        Road=road|highway
        Feature=feature|farm
        Railway=rail|train
        Tunnel=tunnel|tube
        Ramp=ramp|slope
        Shore=shore
        Pavement=pave
        Fix=fix
        LAT=lat
        ```
    - `[XXXInfo]` *TemperateInfo, SnowInfo, UrbanInfo, NewUrbanInfo, DesertInfo, LunarInfo*
        - `Ramps=Tilesets`
        - `Morphables=Tilesets`
          - 此处的所有磁贴集都应 `Morphable=true`。你不需要在这里写 RampBase，只需要在这里添加其他Ramps。渐变和可变形对象应具有相同长度的磁贴集，并且这些磁贴集应是一对一的对应关系。旧的NewUrbanInfo的键 `Ramps2` 和 `Morphable2` 已被放弃，因此您需要手动添加它们。
        ```ini
        [NewUrbanInfo]
        Morphables=114,123
        Ramps=117,193 
        ```
    - `[ExtraMixes]`
        - `Filename = ReadFromMapEditorPathInsteadOfGamePath`
        ```ini
        [ExtraConfigs]
        buxu\123.mix=Yes
        money.txt=No
        
        ; 添加 {FA2PATH\buxu\123.mix}，如果没有找到该文件，它将在 {GAMEPATH\money.txt} 中搜索该文件，如果找不到该文件，FA2将尝试像以前一样查找该文件。
        ```
    - `[OverlayDisplayLimit]`
        - `OverlayIndex = DisplayLimit` *DisplayLimit应小于等于 $60$*
        ```ini
        [OverlayDisplayLimit]
        243=48
        ; 不会在48以后显示地形243的帧
        ```
    - `[Filenames]`
        - `EVA = FILENAME`
        - `EVAYR = FILENAME`
        - `Sound = FILENAME`
        - `SoundYR = FILENAME`
        - `Theme = FILENAME`
        - `ThemeYR = FILENAME`
        - `AI = FILENAME`
        - `AIYR = FILENAME`
        - `RulesYR = FILENAME`
        - `Rules = FILENAME`
        - `ArtYR = FILENAME`
        - `Art = FILENAME`
        - `TemperateYR = FILENAME`
        - `Temperate = FILENAME`
        - `SnowYR = FILENAME`
        - `Snow = FILENAME`
        - `UrbanYR = FILENAME`
        - `Urban = FILENAME`
        - `UrbanNYR = FILENAME`
        - `LunarYR = FILENAME`
        - `DesertYR = FILENAME`
        - `MixExtension = FILENAME SUFFIX`
        ```ini
        EVAYR=evamp.ini
        SoundYR=soundmp.ini
        ThemeYR=thememp.ini
        AIYR=aimp.ini
        RulesYR=rulesmp.ini
        ArtYR=artmp.ini
        TemperateYR=temperatmp.ini
        SnowYR=snowmp.ini
        UrbanYR=urbanmp.ini
        UrbanNYR=urbannmp.ini
        LunarYR=lunarmp.ini
        DesertYR=desertmp.ini
        MixExtension=mp
        ```
    - `[ScriptTypeLists]`
        - 参数类型列表
            - 键从 $1$ 开始，并且必须是 **INTEGER**
        - `X=TypeListName`
    - `[TypeListName]`
        - 这只是个例子，它已在 `[ScriptTypeLists]` 中注册。
    ```ini
    [TypeListName]
    HasExtraParam = BOOLEAN
    ExtraParamType = ExtraParamTypeListName
    BuiltInType = INTEGER
    ScriptActionParam = Read the Description below 
    ; 比如 0=Buildings，键必须是整数，如果设置了 BuiltInType 且不是 -1，则忽略
    ```
    - [ExtraParamTypeListName]
        - 这只是个例子，它不需要在 `[ScriptTypeLists]` 中注册。
    ```ini
    [ExtraParamTypeListName]
    BuiltInType = INTEGER
    ScriptActionExtraParam = Read the Description below
    ; 比如 0=Nearest，键必须是整数，如果设置了 BuiltInType 且不是 -1，则忽略
    ```
    - **`[ScriptParams]`**
        - 用于脚本的参数类型列表
            - 脚本参数是独立的

        | ID | Meaning |
        | :-: | :-: |
        | 0 | Nothing |
        | 1 | Target |
        | 2 | Waypoint |
        | 3 | ScriptLine |
        | 4 | SplitGroup |
        | 5 | GlobalVariable |
        | 6 | ScriptTypes |
        | 7 | TeamTypes |
        | 8 | Houses |
        | 9 | Speeches |
        | 10 | Sounds |
        | 11 | Movies |
        | 12 | Themes |
        | 13 | Countries | 
        | 14 | LocalVariables |
        | 15 | Facing |
        | 16 | BuildingTypes | 
        | 17 | Animations |
        | 18 | TalkBubbles |
        | 19 | Status |
        | 20 | Boolean |
        | -X | ScriptTypeList at `[ScriptTypeLists]` X |

        ```ini
        [ScriptParams] ; 示例列表
        0=Nothing,0
        1=Target,1
        2=Waypoint,2
        3=Jump To Line #,3
        4=Split Group,4
        5=Global,5
        6=Script,6
        7=Team,7
        8=House,8
        9=Speech,9
        10=Sound,10
        11=Movie,11
        12=Theme,12
        13=Country,13
        14=Local,14
        15=Facing,15
        16=Building,16
        17=Animation,17
        18=Talk Bubble,18
        19=Enter Status,19
        20=Integer,0
        21=Boolean,20
        ```
    - **`[ScriptsRA2]`**
        - `index = 名称, 参数, 不可见, 带参数, 描述`
        - 脚本列表
        ```ini
        [ScriptsRA2] ; Caco的举例
        0=0 - Attack,1,0,1,Attack some general TARGET.
        1=1 - Attack WP,2,0,1,Attack specified WAYPOINT (or THINGS on it).
        2=2 - Go Berserk,0,1,0,Cyborgs go berserk (--Obsolete--)
        3=3 - Move to WP,2,0,1,Move to WAYPOINT.
        4=4 - Move to Cell,20,0,1,Move to specified CELL (formula to result: x+y*128).
        5=5 - Guard in Sec,20,0,1,Do AREA GUARD for SECOND(S) defined by argument.
        6=6 - Jump to Line #,3,0,1,Jump to specified LINE with scripts above done.
        7=7 - Player Win,0,0,0,Force player to WIN.
        8=8 - Unload,4,0,1,Kick ALL passengers. Use argument to set which type(s) should CONTINUE the script.
        9=9 - Deploy,0,0,0,Deploy all deployable units.
        10=10 - Follow friendlies,0,0,0,Follow the NEAREST friendly units.
        11=11 - Do this,19,0,1,Cause the team to DO specified MISSION.
        12=12 - Set Global var,5,0,1,Set a GLOBAL variable (1/On).
        13=13 - Idle,0,0,0,Infantries in this team PLAY IDLE ANIMS.
        14=14 - Load onto Transport,0,0,0,Let all units enter the transportation IF POSSIBLE.
        15=15 - Spy into,0,1,0,(--Obsolete--)
        16=16 - Patrol to WP,2,0,1,Patrol (Attack-Move) to WAYPOINT.
        17=17 - Change Script,6,0,1,Change SCRIPT the taskforce used. 
        18=18 - Change Team,7,0,1,Change TEAM the taskforce belong to. 
        19=19 - Panic,0,0,0,Causes all units in the team to panic. (Usually for civilian use)
        20=20 - Change Owner,13,0,1,Specified COUNTRY will own the whole team.
        21=21 - Scatter,0,0,0,Scatter all units.
        22=22 - Escape to Shroud,0,0,0,Cause all units escape to SHROUD.
        23=23 - Player Lose,0,0,0,Force player to LOSE.
        24=24 - Play EVA Speech,9,0,1,Play specified SPEECH.
        25=25 - Play Sound,10,0,1,Play specified SOUND.
        26=26 - Play Movie,11,0,1,Play specified MOVIE (on radar screen).
        27=27 - Play Theme,12,0,1,Play specified THEME.
        28=28 - Reduce Ore,0,0,0,Reduce the value of ORE AROUND TEAM MEMBERS.
        29=29 - Begin Production,0,0,0,Cause the OWNER OF THIS TEAM produce (as planned).
        30=30 - Sell 'n' Hunt,0,0,0,Cause AI SELL their buildings and HUNT their enemies.
        31=31 - Self Destroy,0,0,0,Destroy the team ITSELF.
        32=32 - Start Storm in Sec,20,0,1,Begin the Lightning Storm after specified SECOND(S).
        33=33 - End Storm,0,0,0,End up the CURRENT Lightning Storm.
        34=34 - Center focus on this team,20,0,1,Center focus on this team with specified MOVE SPEED.
        35=35 - Reshroud Map,0,0,0,Reshroud current map.
        36=36 - Reveal Map,0,0,0,Reveal ALL terrain of current map.
        37=37 - Delete Team,0,0,0,Delete ALL members of this team.
        38=38 - Clear Global Var,5,0,1,Clear specified GLOBAL var (0/Off).
        39=39 - Set Local Var,14,0,1,Set specified LOCAL var (1/On).
        40=40 - Clear Local Var,14,0,1,Clear specified LOCAL var (0/Off).
        41=41 - Unpanic,0,0,0,Calm down all units in this team.
        42=42 - Force Facing,15,0,1,Turn all units in this team to a specified direction.
        43=43 - Wait till full,0,0,0,Wait until all passengers loaded.
        44=44 - Truck unload,0,0,0,UNLOAD the goods as all trucks go empty.
        45=45 - Truck load,0,0,0,LOAD the goods as all trucks go full.
        46=46 - Attack enemy buildings,16,0,1,Attack specified BUILDINGS. (+0: MIN threat +65536: MAX threat +131072: nearest, +262144: furthest).
        47=47 - Move to enemy buildings,16,0,1,Move to specified BUILDINGS. (+0: MIN threat +65536: MAX threat +131072: nearest, +262144: furthest).
        48=48 - Scout,0,0,0,The team would scout the shroud area.
        49=49 - Success,0,0,0,Put up the weight of AI trigger attached.
        50=50 - Flash for frames,20,0,1,Flash this team for a number of FRAMES.
        51=51 - Play Animation,17,0,1,Play specified anim on each unit.
        52=52 - Talk bubble,18,0,1,Show a talk bubble on the FIRST UNIT of this team.
        53=53 - Gather outside enemy,20,0,1,Gather outside the enemy's base. Arguments with positive or negative could affect the global distance since Ares 2.0.
        54=54 - Gather outside team,20,0,1,Gather outside the team's base. Arguments with positive or negative could affect the global distance since Ares 2.0.
        55=55 - Ask for SW,20,0,1,AI would queue a SuperWeapon for this team. Arguments decide which group of SW since Ares 2.0 (SW.Group).
        56=56 - Chronoshift to Building,16,0,1,Chronoshift the team to specified buildings if possible. Need EXTRA orders however.
        57=57 - Chronoshift to Target,1,0,1,Chronoshift the team to specified type if possible. Need EXTRA orders however.
        ;YR Only
        58=58 - Move to friendlies buildings,16,0,1,Move to friendlies BUILDINGS. (+0: MIN threat +65536: MAX threat +131072: nearest, +262144: furthest).
        59=59 - Attack (or Garrison) buildings on WP,2,0,1,Attack the building on specified WP. AI would usually try to GARRISON if possible.
        60=60 - Enter Grinder,0,0,0,Get the team into nearest grinder.
        61=61 - Enter Tank Bunker,0,0,0,Get EACH unit in the team into nearest tank bunker.
        62=62 - Enter Bio Reactor,0,0,0,Get EACH infantry in the team into nearest bio reactor.
        63=63 - Enter Battle Bunker,0,0,0,Get EACH infantry in the team into nearest battle bunker (if possible).
        64=64 - Enter Neutral Buildings,0,0,0,Get EACH infantry in the team into nearest civilian buildings (if possible).
        ;Ares 3.0 Only
        65=65 - Auxiliary Power (Ares 3.0 Only),20,0,1,Permanently changes the power output of the house owning the team.
        66=66 - Kill Drivers (Ares 3.0 Only),0,0,0,Kills ALL drivers of the units in this team.
        67=67 - Take Vehicles (Ares 3.0 Only),0,0,0,All CanDrive or VehicleThief infantry in this team will be assigned the closest vehicle they can drive or hijack.
        68=68 - Convert Type (Ares 3.0 Only),0,0,0,Immediately changes all members of this team into their respective script conversion types (Convert.Script).
        69=69 - Sonar Reveal (Ares 3.0 Only),20,0,1,Disables the ability of all team members to cloak themselves for a number of FRAMES.
        70=70 - Disable Weapons (Ares 3.0 Only),20,0,1,Disables the ability of all team members to fire for a number of FRAMES.
        ```
    - `[VehicleVoxelBarrelsRA2]`
    - `[StructureOverlappingCheckIgnores]`
        - id = BuildingRegName
    ```ini
    [StructureOverlappingCheckIgnorance]
    Index = RegName
    ; 比如 0=INORANLAMP，值必须为有效建筑注册名
    ```
- `FALanguage.ini`
    ```ini
    [CURRENTLANGUAGE-StringsRA2]
    [CURRENTLANGUAGE-Strings]
    [CURRENTLANGUAGE-TranslationsRA2]
    [CURRENTLANGUAGE-Translations]
    ; 这四个都可以，只要其中一个就可以了
    MV_OverlapStructures = TEXT(%1 for count, %2 for X, %3 for Y)
    MV_LogicMissingParams = TEXT(%1 for section, %2 for key)
    TabPages.TilePlacement = TEXT
    TabPages.TriggerSort = TEXT
    Menu.File = TEXT
    Menu.File.New = TEXT
    Menu.File.Open = TEXT
    Menu.File.Save = TEXT
    Menu.File.SaveAs = TEXT
    Menu.File.CheckMap = TEXT
    Menu.File.RunGame = TEXT
    Menu.File.Quit = TEXT
    Menu.Edit = TEXT
    Menu.Edit.Undo = TEXT
    Menu.Edit.Redo = TEXT
    Menu.Edit.Copy = TEXT
    Menu.Edit.CopyWholeMap = TEXT
    Menu.Edit.Paste = TEXT
    Menu.Edit.PasteCentered = TEXT
    Menu.Edit.Map = TEXT
    Menu.Edit.Basic = TEXT
    Menu.Edit.SpecialFlags = TEXT
    Menu.Edit.Lighting = TEXT
    Menu.Edit.Houses = TEXT
    Menu.Edit.TriggerEditor = TEXT
    Menu.Edit.TagEditor = TEXT
    Menu.Edit.Taskforces = TEXT
    Menu.Edit.Scripts = TEXT
    Menu.Edit.Teams = TEXT
    Menu.Edit.AITriggers = TEXT
    Menu.Edit.AITriggerEnable = TEXT
    Menu.Edit.LocalVariables = TEXT
    Menu.Edit.SingleplayerSettings = TEXT
    Menu.Edit.INIEditor = TEXT
    Menu.Terrain = TEXT
    Menu.Terrain.RaiseGround = TEXT
    Menu.Terrain.LowerGround = TEXT
    Menu.Terrain.FlattenGround = TEXT
    Menu.Terrain.HideTileset = TEXT
    Menu.Terrain.ShowEveryTileset = TEXT
    Menu.Terrain.HideSingleField = TEXT
    Menu.Terrain.ShowAllFields = TEXT
    Menu.Terrain.RaiseSingleTile = TEXT
    Menu.Terrain.LowerSingleTile = TEXT
    Menu.MapTools = TEXT
    Menu.MapTools.ChangeMapHeight = TEXT
    Menu.MapTools.AutoCreateShores = TEXT
    Menu.MapTools.AutoLevelUsingCliffs = TEXT
    Menu.MapTools.PaintCliffFront = TEXT
    Menu.MapTools.PaintCliffBack = TEXT
    Menu.MapTools.SearchWaypoint = TEXT
    Menu.MapTools.NavigateCoordinate = TEXT
    Menu.MapTools.ToolScripts = TEXT
    Menu.Online = TEXT
    Menu.Online.Westwood = TEXT
    Menu.Online.FA2Fansite = TEXT
    Menu.Online.FA2Forum = TEXT
    Menu.Options = TEXT
    Menu.Options.Settings = TEXT
    Menu.Options.ShowMinimap = TEXT
    Menu.Options.Easymode = TEXT
    Menu.Options.Sounds = TEXT
    Menu.Options.ShowBuildingOutline = TEXT
    Menu.Options.DisableAutoShore = TEXT
    Menu.Options.DisableAutoLAT = TEXT
    Menu.Options.DisableSlopeCorrection = TEXT
    Menu.Help = TEXT
    Menu.Help.Manual = TEXT
    Menu.Help.Info = TEXT
    Menu.Help.Credits = TEXT
    Menu.Help.TipOfTheDay = TEXT
    Menu.Layers = TEXT
    Menu.Layers.Structures = TEXT
    Menu.Layers.Infantries = TEXT
    Menu.Layers.Units = TEXT
    Menu.Layers.Aircrafts = TEXT
    Menu.Layers.Basenodes = TEXT
    Menu.Layers.Waypoints = TEXT
    Menu.Layers.Celltags = TEXT
    Menu.Layers.MoneyOnMap = TEXT
    Menu.Layers.Overlays = TEXT
    Menu.Layers.Terrains = TEXT
    Menu.Layers.Smudges = TEXT
    Menu.Layers.Tubes = TEXT
    Menu.Layers.Bounds = TEXT
    Menu.Lighting = TEXT
    Menu.Lighting.None = TEXT
    Menu.Lighting.Normal = TEXT
    Menu.Lighting.Lightning = TEXT
    Menu.Lighting.Dominator = TEXT
    Menu.PropertyBrush = TEXT
    Menu.PropertyBrush.AutoAircraft = TEXT
    Menu.PropertyBrush.AutoBuilding = TEXT
    Menu.PropertyBrush.AutoInfantry = TEXT
    Menu.PropertyBrush.AutoVehicle = TEXT
    DialogBar.TileManager = TEXT
    DialogBar.TerrainOrGround = TEXT
    DialogBar.OverlayAndSpecial = TEXT
    AITriggerTitle = TEXT
    AITriggerList = TEXT
    AITriggerName = TEXT
    AITriggerTeam1 = TEXT
    AITriggerHouse = TEXT
    AITriggerTeam2 = TEXT
    AITriggerTechlevel = TEXT
    AITriggerType = TEXT
    AITriggerWeight = TEXT
    AITriggerMinWeight = TEXT
    AITriggerMaxWeight = TEXT
    AITriggerMinDiff = TEXT
    AITriggerSide = TEXT
    AITriggerTechnoType = TEXT
    AITriggerCondition = TEXT
    AITriggerNumber = TEXT
    AITriggerAdditionalDesc = TEXT
    AITriggerData = TEXT
    AITriggerEnabled = TEXT
    AITriggerAdd = TEXT
    AITriggerDel = TEXT
    AITriggerClo = TEXT
    AITriggerBaseDefense = TEXT
    AITriggerSkirmish = TEXT
    AITriggerEasy = TEXT
    AITriggerMedium = TEXT
    AITriggerHard = TEXT
    TaskforceTitle = TEXT
    TaskforceList = TEXT
    TaskforceUnits = TEXT
    TaskforceGroup = TEXT
    TaskforceUnitNumber = TEXT
    TaskforceUnitType = TEXT
    TaskforceSelected = TEXT
    TaskforceName = TEXT
    TaskforceNewTask = TEXT
    TaskforceDelTask = TEXT
    TaskforceCloTask = TEXT
    TaskforceNewUnit = TEXT
    TaskforceDelUnit = TEXT
    TaskforceCloUnit = TEXT
    TeamTypesTitle = TEXT
    TeamTypesNewTeam = TEXT
    TeamTypesDelTeam = TEXT
    TeamTypesCloTeam = TEXT
    TeamTypesMainDesc = TEXT
    TeamTypesCurrentTeamLabel = TEXT
    TeamTypesSelectedTeam = TEXT
    TeamTypesLabelName = TEXT
    TeamTypesLabelHouse = TEXT
    TeamTypesLabelTaskforce = TEXT
    TeamTypesLabelScript = TEXT
    TeamTypesLabelTag = TEXT
    TeamTypesLabelVeteranLevel = TEXT
    TeamTypesLabelPriority = TEXT
    TeamTypesLabelMax = TEXT
    TeamTypesLabelTechlevel = TEXT
    TeamTypesLabelTransportWaypoint = TEXT
    TeamTypesLabelGroup = TEXT
    TeamTypesLabelWaypoint = TEXT
    TeamTypesLabelMindControlDecision = TEXT
    TeamTypesCheckBoxLoadable = TEXT
    TeamTypesCheckBoxFull = TEXT
    TeamTypesCheckBoxAnnoyance = TEXT
    TeamTypesCheckBoxGuardSlower = TEXT
    TeamTypesCheckBoxRecruiter = TEXT
    TeamTypesCheckBoxAutoCreate = TEXT
    TeamTypesCheckBoxPrebuild = TEXT
    TeamTypesCheckBoxReinforce = TEXT
    TeamTypesCheckBoxCargoPlane = TEXT
    TeamTypesCheckBoxWhiner = TEXT
    TeamTypesCheckBoxLooseRecruit = TEXT
    TeamTypesCheckBoxAggressive = TEXT
    TeamTypesCheckBoxSuicide = TEXT
    TeamTypesCheckBoxOnTransOnly = TEXT
    TeamTypesCheckBoxAvoidThreats = TEXT
    TeamTypesCheckBoxIonImmune = TEXT
    TeamTypesCheckBoxTransportsReturnOnUnload = TEXT
    TeamTypesCheckBoxAreTeamMembersRecruitable = TEXT
    TeamTypesCheckBoxIsBaseDefense = TEXT
    TeamTypesCheckBoxOnlyTargetHouseEnemy = TEXT
    TriggerFrameTitle = TEXT
    TriggerFrameSelectedTrigger = TEXT
    TriggerFrameNew = TEXT
    TriggerFrameDel = TEXT
    TriggerFramePlace = TEXT
    TriggerFrameClone = TEXT
    TriggerOptionType = TEXT
    TriggerOptionName = TEXT
    TriggerOptionHouse = TEXT
    TriggerOptionAttached = TEXT
    TriggerOptionDisabled = TEXT
    TriggerOptionDisabledDesc = TEXT
    TriggerOptionEasy = TEXT
    TriggerOptionMedium = TEXT
    TriggerOptionHard = TEXT
    TriggerEventCurrent = TEXT
    TriggerEventNew = TEXT
    TriggerEventDel = TEXT
    TriggerEventClo = TEXT
    TriggerEventOptions = TEXT
    TriggerEventType = TEXT
    TriggerEventParameter = TEXT
    TriggerEventParamValue = TEXT
    TriggerEventDesc = TEXT
    TriggerActionCurrent = TEXT
    TriggerActionNew = TEXT
    TriggerActionDel = TEXT
    TriggerActionClo = TEXT
    TriggerActionOptions = TEXT
    TriggerActionType = TEXT
    TriggerActionParameter = TEXT
    TriggerActionParamValue = TEXT
    TriggerActionDesc = TEXT
    TriggerRepeatType.OneTimeOr= TEXT
    TriggerRepeatType.OneTimeAnd= TEXT
    TriggerRepeatType.RepeatingOr= TEXT
    ScriptTypesTitle = TEXT
    ScriptTypesDesc = TEXT
    ScriptTypesSelectedScript = TEXT
    ScriptTypesName = TEXT
    ScriptTypesActions = TEXT
    ScriptTypesActionType = TEXT
    ScriptTypesActionDesc = TEXT
    ScriptTypesAddScript = TEXT
    ScriptTypesDelScript = TEXT
    ScriptTypesCloScript = TEXT
    ScriptTypesAddAction = TEXT
    ScriptTypesDelAction = TEXT
    ScriptTypesActionParam = TEXT
    ScriptTypesCloAction = TEXT
    ScriptTypesInsertMode = TEXT
    ScriptTypesExtraParam = TEXT
    ScriptTypesMoveUp = TEXT
    ScriptTypesMoveDown = TEXT
    SingleplayerParTimeEasy = TEXT
    SingleplayerParTimeMedium = TEXT
    SingleplayerParTimeHard = TEXT
    SingleplayerOverParTitle = TEXT
    SingleplayerOverParMessage = TEXT
    SingleplayerUnderParTitle = TEXT
    SingleplayerUnderParMessage = TEXT
    LightingTitle = TEXT
    LightingDesc = TEXT
    LightingNormal = TEXT
    LightingIonStorm = TEXT
    LightingDominator = TEXT
    LightingAmbient = TEXT
    LightingGreen = TEXT
    LightingRed = TEXT
    LightingBlue = TEXT
    LightingLevel = TEXT
    LightingGround = TEXT
    LightingNukeAmbientChangeRate = TEXT
    LightingDominatorAmbientChangeRate = TEXT
    PropertyBrushObList = TEXT
    PropertyBrushBuilding = TEXT
    PropertyBrushInfantry = TEXT
    PropertyBrushVehicle = TEXT
    PropertyBrushAircraft = TEXT
    TheaterNameTem = TEXT
    TheaterNameSno = TEXT
    TheaterNameUrb = TEXT
    TheaterNameUbn = TEXT
    TheaterNameLun = TEXT
    TheaterNameDes = TEXT
    AllieEditorTitle = TEXT
    AllieEditorEnemies = TEXT
    AllieEditorAllies = TEXT
    AllieEditorOK = TEXT
    AllieEditorCancel = TEXT
    TileManagerTitle = TEXT
    NavigateCoordTitle = TEXT
    NavigateCoordMessage = TEXT
    NavigateCoordInvalidFormat = TEXT
    NavigateCoordInvalidCoord = TEXT
    NavigateCoordInvalidTitle = TEXT
    FileWatcherMessage = TEXT
    ; 脚本参数
    ; 例如ScriptParam.Status.0
    ScriptParam.Target.[0 - 11] = TEXT
    ScriptParam.SplitGroup.[0 - 3] = TEXT
    ScriptParam.Facing.[0 - 7] = TEXT
    ScriptParam.TalkBubble.[0 - 3] = TEXT
    ScriptParam.Status.[0 - 31] = TEXT 
    ScriptParam.Boolean.[0 - 1] = TEXT
    ScriptExtraParam.Preference.[0 - 3] = TEXT
    ```

## 写在最后
- 这个项目是在 FA2Copy 之后开发的，还有很多错误需要修复，然后 Zero Fanker 建议使用内联钩子而不是 Win32API 消息钩子来实现更多功能并修复更多错误，最后我们来到 FA2SP。

- 感谢AlexB，他给了我许多反编译的建议和有用的信息。因为时差在半夜和他聊天也很有趣。

- Zero Fanker为这个项目的建立做出了巨大的贡献，提出了许多重要的建议。

- Caco为这个项目做了大量的测试工作，也带来了许多我以前没有注意到的问题。

- Tomsons26在反编译方面提供了很大的帮助，真的很有帮助。

- thomassneddon为我提供了VXL绘图库和绘图辅助，没有就无法绘制VXL内容。

- 顺便说一句，FA2 的代码真的很乱！充满了不必要的构造函数。我讨厌它！
