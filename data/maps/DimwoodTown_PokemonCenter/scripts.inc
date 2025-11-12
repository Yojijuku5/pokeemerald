DimwoodTown_PokemonCenter_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, DimwoodTown_PokemonCenter_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

DimwoodTown_PokemonCenter_OnTransition:
	setrespawn HEAL_LOCATION_DIMWOOD_TOWN
	goto_if_set FLAG_SYS_POKEMON_GET, DimwoodTown_PokemonCenter_EventScript_SetPCNPCPos
	end

DimwoodTown_PokemonCenter_EventScript_Nurse::
	goto_if_set FLAG_SYS_POKEMON_GET, DimwoodTown_PokemonCenter_EventScript_HealMon
	msgbox DimwoodTown_PokemonCenter_Text_NurseBeforeMon, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_DIMWOOD_NURSE, Movement_PkmnCenterNurse_Bow
	end

DimwoodTown_PokemonCenter_EventScript_HealMon::
	setvar VAR_0x800B, LOCALID_DIMWOOD_NURSE
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

DimwoodTown_PokemonCenter_EventScript_SetPCNPCPos::
	setobjectxyperm LOCALID_PCNPC, 10, 6
	setobjectmovementtype LOCALID_PCNPC, MOVEMENT_TYPE_FACE_RIGHT
	return

DimwoodTown_PokemonCenter_EventScript_PCNPC::
	goto_if_unset FLAG_SYS_POKEMON_GET, DimwoodTown_PokemonCenter_EventScript_BeforeGetPokemonPC
	goto_if_set FLAG_SYS_POKEMON_GET, DimwoodTown_PokemonCenter_EventScript_UsePC
	end

DimwoodTown_PokemonCenter_EventScript_BeforeGetPokemonPC::
	msgbox DimwoodTown_PokemonCenter_Text_BeforeGetPokemonPC, MSGBOX_DEFAULT
	closemessage
	end

DimwoodTown_PokemonCenter_EventScript_UsePC::
	msgbox DimwoodTown_PokemonCenter_Text_UsePC, MSGBOX_NPC
	end

DimwoodTown_PokemonCenter_EventScript_ItCanGetRough::
	msgbox DimwoodTown_PokemonCenter_Text_ItCanGetRough, MSGBOX_NPC
	end

DimwoodTown_PokemonCenter_EventScript_PokemonCenterFree::
	msgbox DimwoodTown_PokemonCenter_Text_PokemonCenterFree, MSGBOX_NPC
	end

DimwoodTown_PokemonCenter_Text_NurseBeforeMon:
	.string "Hello, and welcome to\n"
	.string "the POKéMON CENTER.\p"
	.string "We restore your tired POKéMON\n"
	.string "to full health.\p"
	.string "It seems like you don't have any\n"
	.string "POKéMON with you right now.\p"
	.string "Please come back when you\n"
	.string "obtain a POKéMON.\p"
	.string "We hope to see you again!$"

DimwoodTown_PokemonCenter_Text_BeforeGetPokemonPC:
	.string "Hang On!\n"
	.string "Almost finished!$"

DimwoodTown_PokemonCenter_Text_UsePC:
	.string "You can use the PC in the corner to\n"
	.string "organize your inventory of both items\l"
	.string "and POKéMON. It's pretty nifty!$"

DimwoodTown_PokemonCenter_Text_ItCanGetRough:
	.string "Your POKéMON can get pretty roughed\n"
	.string "up from battling,\l"
	.string "so it's great that there are always\l"
	.string "POKéMON CENTERS nearby.$"

DimwoodTown_PokemonCenter_Text_PokemonCenterFree:
	.string "If you think about it, it's pretty\n"
	.string "amazing we can heal our POKéMON for\l"
	.string "free, whenever we want.$"
