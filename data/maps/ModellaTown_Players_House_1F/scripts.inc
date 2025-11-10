ModellaTown_Players_House_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, ModellaTown_Players_House_1F_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, ModellaTown_Players_House_1F_OnFrame
	.byte 0

	@ State descriptions for VAR_MODELLA_INTRO_STATE
	@ 0: Wake up
	@ 1: Before set clock
	@ 2: After set clock
	@ 3: Go on errand
	@ 4: Collected Parcel
	@ 5: Given Parcel

ModellaTown_Players_House_1F_OnTransition::
	call_if_eq VAR_MODELLA_INTRO_STATE, 1, ModellaTown_Players_House_1F_EventScript_MoveMomToStairs
	call_if_eq VAR_MODELLA_INTRO_STATE, 2, ModellaTown_Players_House_1F_EventScript_MoveMomToSeat
	end

ModellaTown_Players_House_1F_EventScript_MoveMomToStairs::
	setobjectxyperm LOCALID_PLAYERS_HOUSE_1F_MOM, 8, 4
	setobjectmovementtype LOCALID_PLAYERS_HOUSE_1F_MOM, MOVEMENT_TYPE_FACE_UP
	return

ModellaTown_Players_House_1F_EventScript_MoveMomToSeat::
	setobjectxyperm LOCALID_PLAYERS_HOUSE_1F_MOM, 2, 6
	setobjectmovementtype LOCALID_PLAYERS_HOUSE_1F_MOM, MOVEMENT_TYPE_FACE_RIGHT
	return

ModellaTown_Players_House_1F_OnFrame::
	map_script_2 VAR_MODELLA_INTRO_STATE, 1, ModellaTown_Players_House_1F_EventScript_GoUpstairsToSetClock
	map_script_2 VAR_MODELLA_INTRO_STATE, 2, ModellaTown_Players_House_1F_EventScript_GoOnErrand
	.2byte 0

ModellaTown_Players_House_1F_EventScript_GoUpstairsToSetClock::
	lockall
	msgbox PlayersHouse_1F_Text_GoSetTheClock, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PLAYER, ModellaTown_Players_House_1F_Movement_PushTowardStairs
	applymovement LOCALID_PLAYERS_HOUSE_1F_MOM, ModellaTown_Players_House_1F_Movement_PushTowardStairs
	waitmovement 0
	warp MAP_MODELLA_TOWN_PLAYERS_HOUSE_2F, 7, 1
	waitstate
	releaseall
	end

ModellaTown_Players_House_1F_EventScript_GoOnErrand::
	setvar VAR_MODELLA_INTRO_STATE, 3
	playse SE_PIN
	applymovement LOCALID_PLAYERS_HOUSE_1F_MOM, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_PLAYERS_HOUSE_1F_MOM, Common_Movement_Delay48
	waitmovement 0
	applymovement LOCALID_PLAYERS_HOUSE_1F_MOM, ModellaTown_Players_House_1F_Movement_MoveTowardsPlayer
	waitmovement 0
	msgbox ModellaTown_Players_House_1F_Text_SpeakErrand, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PLAYERS_HOUSE_1F_MOM, ModellaTown_Players_House_1F_Movement_MoveTowardsSeat
	waitmovement 0
	end

ModellaTown_Players_House_1F_EventScript_Mom::
	call_if_eq VAR_MODELLA_INTRO_STATE, 3, ModellaTown_Players_House_1F_EventScript_MomGoGetParcel
	call_if_eq VAR_MODELLA_INTRO_STATE, 4, ModellaTown_Players_House_1F_EventScript_GiveParcel
	call_if_eq VAR_MODELLA_INTRO_STATE, 5, ModellaTown_Players_House_1F_EventScript_WelcomeHomeRest
	end

ModellaTown_Players_House_1F_EventScript_MomGoGetParcel::
	lock
	faceplayer
	msgbox ModellaTown_Players_House_1F_Text_GoGetParcel, MSGBOX_DEFAULT
	closemessage
	release
	end

ModellaTown_Players_House_1F_EventScript_GiveParcel::
	lock
	faceplayer
	msgbox ModellaTown_Players_House_1F_Text_GiveParcel, MSGBOX_DEFAULT
	closemessage
	setvar VAR_0x8004, ITEM_OAKS_PARCEL
	call Common_EventScript_PlayerHandedOverTheItem
	msgbox ModellaTown_Players_House_1F_Text_ExplainPokemon, MSGBOX_DEFAULT
	playfanfare MUS_OBTAIN_ITEM
	message ModellaTown_Players_House_Text_SwitchShoesWithRunningShoes
	waitfanfare
	setflag FLAG_RECEIVED_RUNNING_SHOES
	msgbox ModellaTown_Players_House_Text_ExplainRunningShoes, MSGBOX_DEFAULT
	msgbox ModellaTown_Players_House_Text_ComeHomeIfAnythingHappens, MSGBOX_DEFAULT
	closemessage
	setflag FLAG_SYS_B_DASH
	setflag FLAG_HIDE_DIMWOOD_RIVAL
	clearflag FLAG_HIDE_ROUTE23_RIVAL
	setvar VAR_MODELLA_INTRO_STATE, 5
	setvar VAR_ROUTE23_STATE, 7
	release
	end

ModellaTown_Players_House_1F_EventScript_WelcomeHomeRest::
	msgbox ModellaTown_Players_House_1F_Text_YouShouldRestABit, MSGBOX_DEFAULT
	goto ModellaTown_Players_House_1F_EventScript_HealParty
	end

ModellaTown_Players_House_1F_EventScript_HealParty::
	closemessage
	call Common_EventScript_OutOfCenterPartyHeal
	incrementgamestat GAME_STAT_RESTED_AT_HOME
	msgbox ModellaTown_Players_House_1F_Text_TakeCare, MSGBOX_DEFAULT
	release
	end
	

ModellaTown_Players_House_1F_Movement_PushTowardStairs:
	walk_up
	step_end

ModellaTown_Players_House_1F_Movement_MoveTowardsPlayer:
	walk_up
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_up
	step_end

ModellaTown_Players_House_1F_Movement_MoveTowardsSeat:
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	walk_in_place_faster_right
	step_end

ModellaTown_Players_House_1F_Text_SpeakErrand:
	.string "{PLAYER}, have you set your clock?\p"
	.string "... ... ...\p"
	.string "Good, good. Now if you don't mind, I'd\n"
	.string "like you to do me a quick favor.\p"
	.string "Up in DIMWOOD TOWN's POKéMART, I've had\n"
	.string "a parcel delivered.\l"
	.string "If you could go and collect it,\l"
	.string "that would be very nice.\p"
	.string "But remember! You don't have any\n"
	.string "POKéMON with you, so be sure to\l"
	.string "stay out of the tall grass!$"

ModellaTown_Players_House_1F_Text_GoGetParcel:
	.string "{PLAYER}, don't forget to collect my\n"
	.string "Parcel up in DIMWOOD town!$"

ModellaTown_Players_House_1F_Text_GiveParcel:
	.string "{PLAYER}, did you get the parcel?$"

ModellaTown_Players_House_1F_Text_ExplainPokemon:
	.string "Thank you so much! And you made sure to\n"
	.string "stay safe as well!\p"
	.string "What's that you said?\p"
	.string "A POKéMON professor gave you a\n"
	.string "POKéMON?\p"
	.string "Good for you! It looks so cute!\n"
	.string "I'm sure it's safe in your hands.\p"
	.string "... ... ...\p"
	.string "This professor also asked you to head\n"
	.string "to her POKéMON lab as well?!\p"
	.string "Well now aren't you a lucky one!\n"
	.string "Maybe she'll even give you a POKéDEX!\p"
	.string "I get the sense you'll be itching to\n"
	.string "head off on your own POKéMON\l"
	.string "adventure.\p"
	.string "... ... ...\p"
	.string "Now, proper adventures need proper\n"
	.string "equipment, and it just so happens that\l"
	.string "the Parcel you delivered contained a\l"
	.string "new pair of RUNNING SHOES for you.\l"
	.string "Why don't you try them on now?$"

ModellaTown_Players_House_Text_SwitchShoesWithRunningShoes:
	.string "{PLAYER} switched shoes with the\n"
	.string "RUNNING SHOES.$"

ModellaTown_Players_House_Text_ExplainRunningShoes:
	.string "I'm sure you know how to run, you've\n"
	.string "been doing it for 14 years now!\l"
	.string "...But just in case, you “Press the B\l"
	.string "button” to run extra fast.$"

ModellaTown_Players_House_Text_ComeHomeIfAnythingHappens:
	.string "Well, I guess you'll be off then...\n"
	.string "Despite our humble living, I hope you'll\l"
	.string "come back to visit from time to time.\l"
	.string "I'll at least always be here!\l"
	.string "Now go have the time of your life!$"

ModellaTown_Players_House_1F_Text_YouShouldRestABit:
	.string "MOM: How are you doing, {PLAYER}?\n"
	.string "You look a little tired.\p"
	.string "I think you should rest a bit.$"

ModellaTown_Players_House_1F_Text_TakeCare:
	.string "Take care now!\n"
	.string "Remember I'll always be here for you!$"
