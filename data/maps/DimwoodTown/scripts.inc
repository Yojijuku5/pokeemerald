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

DimwoodTown_EventScript_AboutRoute22::
	msgbox DimwoodTown_Text_AboutRoute22, MSGBOX_NPC
	end

DimwoodTown_EventScript_AlwaysRaining::
	msgbox DimwoodTown_Text_AlwaysRaining, MSGBOX_NPC
	end

DimwoodTown_EventScript_ILikeRain::
	msgbox DimwoodTown_Text_ILikeRain, MSGBOX_NPC
	end

DimwoodTown_EventScript_TownSign::
	msgbox DimwoodTown_Text_TownSign, MSGBOX_SIGN
	end

DimwoodTown_Text_RivalGettingReady:
	.string "POKéMON check!\n"
	.string "POTIONS check!$"

DimwoodTown_Text_AboutRoute22:
	.string "Anyone used to be able to travel\n"
	.string "through ROUTE 22, but it's since fallen\l"
	.string "into a state of disrepair.\p"
	.string "Now only experienced trainers can\n"
	.string "traverse the route.$"

DimwoodTown_Text_AlwaysRaining:
	.string "The eastern edge of REGION is always\n"
	.string "prone to rain. It seems to never stop.$"

DimwoodTown_Text_ILikeRain:
	.string "I like that it's always raining.\n"
	.string "It has a calming effect.$"

DimwoodTown_Text_TownSign:
	.string "DIMWOOD TOWN\n"
	.string "The humble town hidden in rain.$"
