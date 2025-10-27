ModellaTown_Players_House_2F_MapScripts::
	.byte 0

ModellaTown_Players_House_2F_EventScript_SetClock::
	msgbox ModellaTown_Players_House_2F_Text_SetClockThenLeave, MSGBOX_DEFAULT
	closemessage
	setvar VAR_LITTLEROOT_INTRO_STATE, 5
	end

ModellaTown_Players_House_2F_Text_SetClockThenLeave:
	.string "MOM: {PLAYER}! Have you had a chance\n"
	.string "to set your new clock yet?\p"
	.string "Do that then come downstairs!$"
