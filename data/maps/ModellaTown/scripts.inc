ModellaTown_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, ModellaTown_OnTransition
	.byte 0

ModellaTown_OnTransition:
	setrespawn HEAL_LOCATION_MODELLA_TOWN
	end

ModellaTown_EventScript_UsedToBeMoreResidents::
	msgbox ModellaTown_Text_UsedToBeMoreResidents, MSGBOX_NPC
	end

ModellaTown_EventScript_TownSign::
	msgbox ModellaTown_Text_TownSign, MSGBOX_SIGN
	end

ModellaTown_EventScript_ForSale::
	msgbox ModellaTown_Text_ForSale, MSGBOX_SIGN
	end

ModellaTown_Text_UsedToBeMoreResidents:
	.string "There used to be many more residents\n"
	.string "living here, now it's just a few families.\p"
	.string "How time flies...$"

ModellaTown_Text_TownSign:
	.string "MODELLA TOWN\n"
	.string "Where work and leisure go hand in hand.$"

ModellaTown_Text_ForSale:
	.string "FOR SALE!\n"
	.string "Please contact X for enquiries$"
