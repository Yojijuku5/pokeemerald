ModellaTown_House2_MapScripts::
	.byte 0

ModellaTown_House2_EventScript_Mother::
	msgbox ModellaTown_House2_Text_TownBitFar, MSGBOX_NPC
	end

ModellaTown_House2_EventScript_YoungGirl::
	msgbox ModellaTown_House2_Text_NoMoreRain, MSGBOX_NPC
	end

ModellaTown_House2_Text_TownBitFar:
	.string "It's a bit far from the POKéMART,\n"
	.string "but aside from that it's nice to be in a\l"
	.string "quieter part of the region.$"

ModellaTown_House2_Text_NoMoreRain:
	.string "I wish it didn't rain here all the time!$"
