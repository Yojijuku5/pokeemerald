ModellaTown_MapScripts::
	.byte 0

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
