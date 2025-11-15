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

PlayersHouse_2F_Text_ClockIsStopped:
	.string "The clock is stopped…\p"
	.string "Better set it and start it!$"

PlayersHouse_2F_Text_Notebook:
	.string "{PLAYER} flipped open the notebook.\p"
	.string "ADVENTURE RULE NO. 1\n"
	.string "Open the MENU with START.\p"
	.string "ADVENTURE RULE NO. 2\n"
	.string "Record your progress with SAVE.\p"
	.string "The remaining pages are blank…$"

@ Move to rivals house?
Common_Text_LookCloserAtMap:
	.string "{PLAYER} took a closer look at the\n"
	.string "HOENN region map.$"

PlayersHouse_2F_Text_ItsAGameCube:
	.string "It's a Nintendo GameCube.\p"
	.string "A Game Boy Advance is connected to\n"
	.string "serve as the Controller.$"
