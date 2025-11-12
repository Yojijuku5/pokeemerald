DimwoodTown_Rivals_House_2F_MapScripts::
	.byte 0

DimwoodTown_Rivals_House_2F_EventScript_CheckRivalsPC::
	msgbox gText_PokemonTrainerSchoolEmail, MSGBOX_DEFAULT
	releaseall
	end

DimwoodTown_Rivals_House_2F_EventScript_AzurillDoll::
	msgbox DimwoodTown_Rivals_House_2F_Text_AzurillDoll, MSGBOX_DEFAULT
	closemessage
	end

DimwoodTown_Rivals_House_2F_Text_AzurillDoll:
	.string "It's an Azurill Doll.\n"
	.string "It's quite fluffy.$"
