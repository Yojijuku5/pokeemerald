ModellaTown_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, ModellaTown_OnFrame
	.byte 0

ModellaTown_OnFrame:
	map_script_2 VAR_ROUTE23_STATE, 0, ModellaTown_EventScript_SetFlagsForStarter
	.2byte 0

ModellaTown_EventScript_SetFlagsForStarter::
	clearflag FLAG_HIDE_ROUTE_101_BIRCH
	setvar VAR_ROUTE23_STATE, 1
	end

ModellaTown_EventScript_TownSign::
	msgbox ModellaTown_Text_TownSign, MSGBOX_SIGN
	end

ModellaTown_EventScript_ForSale::
	msgbox ModellaTown_Text_ForSale, MSGBOX_SIGN
	end

ModellaTown_Text_TownSign:
	.string "MODELLA TOWN\n"
	.string "Where work and leisure go hand in hand.$"

ModellaTown_Text_ForSale:
	.string "For Sale!\n"
	.string "Please contact X for enquiries$"
