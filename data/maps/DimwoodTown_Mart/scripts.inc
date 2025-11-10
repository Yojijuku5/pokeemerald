DimwoodTown_Mart_MapScripts::
	.byte 0

DimwoodTown_Mart_EventScript_Employee::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_RUNNING_SHOES, DimwoodTown_Mart_Items
	goto_if_set FLAG_MOMS_PARCEL_RECEIVED, DimwoodTown_Mart_GaveParcel
	playse SE_PIN
	applymovement LOCALID_DIMWOOD_MART_EMPLOYEE, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_DIMWOOD_MART_EMPLOYEE, Common_Movement_Delay48
	waitmovement 0
	msgbox DimwoodTown_Mart_Text_ReceiveDelivery, MSGBOX_DEFAULT
	closemessage
	giveitem ITEM_OAKS_PARCEL
	setvar VAR_MODELLA_INTRO_STATE, 4
	setflag FLAG_MOMS_PARCEL_RECEIVED
	clearflag FLAG_HIDE_DIMWOOD_RIVAL
	clearflag FLAG_HIDE_ROUTE_101_BIRCH
	clearflag FLAG_HIDE_ROUTE_101_BIRCH_STARTERS_BAG
	setvar VAR_ROUTE23_STATE, 2
	release
	end

DimwoodTown_Mart_GaveParcel::
	msgbox DimwoodTown_Mart_Text_MakeSureToDeliver, MSGBOX_DEFAULT
	closemessage
	end

DimwoodTown_Mart_Items::
	message gText_HowMayIServeYou
	waitmessage
	pokemart DimwoodTown_Mart_Pokemart
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
DimwoodTown_Mart_Pokemart:
	.2byte ITEM_POKE_BALL
	.2byte ITEM_POTION
	.2byte ITEM_ANTIDOTE
	.2byte ITEM_PARALYZE_HEAL
	.2byte ITEM_AWAKENING
	pokemartlistend

DimwoodTown_Mart_Movement_EmployeeGiveParcel:
	emote_exclamation_mark
	delay_16
	delay_16
	step_end

DimwoodTown_Mart_Text_ReceiveDelivery:
	.string "Oh!\n"
	.string "Your mother sent you to collect a\l"
	.string "parcel didn't she?\p"
	.string "Here you go!$"

DimwoodTown_Mart_Text_MakeSureToDeliver:
	.string "Make sure you deliver that Parcel!$"
