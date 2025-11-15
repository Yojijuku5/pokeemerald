ModellaTown_Players_House_2F_MapScripts::
	.byte 0

ModellaTown_Players_House_2F_EventScript_SetClock::
	msgbox ModellaTown_Players_House_2F_Text_SetClockThenLeave, MSGBOX_DEFAULT
	closemessage
	setvar VAR_MODELLA_INTRO_STATE, 1
	end

ModellaTown_Players_House_2F_EventScript_PC::
	lockall
	goto ModellaTown_Players_House_2F_EventScript_CheckPlayersPC
	end

ModellaTown_Players_House_2F_EventScript_CheckPlayersPC::
	setvar VAR_0x8004, PC_LOCATION_BRENDANS_HOUSE
	special DoPCTurnOnEffect
	playse SE_PC_ON
	msgbox gText_PlayerHouseBootPC, MSGBOX_DEFAULT
	special BedroomPC
	waitstate
	releaseall
	end

ModellaTown_Players_House_2F_EventScript_TurnOffPlayerPC::
	setvar VAR_0x8004, PC_LOCATION_BRENDANS_HOUSE
	playse SE_PC_OFF
	special DoPCTurnOffEffect
	releaseall
	end

ModellaTown_Players_House_2F_EventScript_Doll::
	msgbox ModellaTown_Players_House_2F_Text_Doll, MSGBOX_DEFAULT
	closemessage
	end

PlayersHouse_2F_EventScript_Notebook::
	msgbox PlayersHouse_2F_Text_Notebook, MSGBOX_SIGN
	end

PlayersHouse_2F_EventScript_GameCube::
	msgbox PlayersHouse_2F_Text_ItsAGameCube, MSGBOX_SIGN
	end

ModellaTown_Players_House_2F_Text_SetClockThenLeave:
	.string "MOM: {PLAYER}! Have you had a chance\n"
	.string "to set your new clock yet?\p"
	.string "Do that then come downstairs!$"

ModellaTown_Players_House_2F_Text_Doll:
	.string "It's a BALTOY Doll you were given when\n"
	.string "you were little.$"
