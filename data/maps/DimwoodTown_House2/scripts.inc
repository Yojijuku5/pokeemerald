DimwoodTown_House2_MapScripts::
	.byte 0

DimwoodTown_House2_EventScript_PokemonLvlUp::
	msgbox DimwoodTown_House2_Text_PokemonLvlUp, MSGBOX_NPC
	end

DimwoodTown_House2_EventScript_MostTrainersGoLeft::
	msgbox DimwoodTown_House2_Text_MostTrainersGoLeft, MSGBOX_NPC
	end

DimwoodTown_House2_Text_PokemonLvlUp:
	.string "When you battle enough POKéMON,\n"
	.string "they can level up and potentially\l"
	.string "learn new, more powerful moves.$"

DimwoodTown_House2_Text_MostTrainersGoLeft:
	.string "Most trainers around here head left\n"
	.string "for IRONSIDE CITY, but sometimes\l"
	.string "a more powerful trainer will head north\l"
	.string "for ROUTE 22.$"
