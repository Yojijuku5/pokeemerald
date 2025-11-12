ModellaTown_House1_MapScripts::
	.byte 0


ModellaTown_House1_EventScript_OldWoman::
	lock
	msgbox ModellaTown_House1_Text_TheseHouses, MSGBOX_NPC
	release
	end

ModellaTown_House1_Text_TheseHouses:
	.string "These houses might not be the most\n"
	.string "modern, but they serve their purpose.$"
