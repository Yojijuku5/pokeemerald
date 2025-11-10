DimwoodTown_MapScripts::
	.byte 0

	@ State descriptions for VAR_DIMWOOD_STATE
	@ 0: First enter town
	@ 1: Collected Parcel (rival outside house)
	@ 2: Delivered Parcel (rival move to Route 23)

DimwoodTown_EventScript_RivalGettingReady::
	lock
	faceplayer
	msgbox DimwoodTown_Text_RivalGettingReady, MSGBOX_DEFAULT
	closemessage
	release
	end

DimwoodTown_EventScript_TownSign::
	msgbox DimwoodTown_Text_TownSign, MSGBOX_SIGN
	end

DimwoodTown_Text_RivalGettingReady:
	.string "POKéMON check!\n"
	.string "Potions check!$"

DimwoodTown_Text_TownSign:
	.string "DIMWOOD TOWN\n"
	.string "The humble town hidden in rain.$"
