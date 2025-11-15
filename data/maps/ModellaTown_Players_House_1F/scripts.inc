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

@ From emerald, but needed
PlayersHouse_1F_Text_GoSetTheClock:
	.string "MOM: {PLAYER}.\p"
	.string "Go set the clock in your room, honey.$"

@ Below leftover from Littleroot player houses
PlayersHouse_1F_Text_IsntItNiceInHere:
	.string "MOM: See, {PLAYER}?\n"
	.string "Isn't it nice in here, too?$"

PlayersHouse_1F_Text_MoversPokemonGoSetClock:
	.string "The mover's POKéMON do all the work\n"
	.string "of moving us in and cleaning up after.\l"
	.string "This is so convenient!\p"
	.string "{PLAYER}, your room is upstairs.\n"
	.string "Go check it out, dear!\p"
	.string "DAD bought you a new clock to mark\n"
	.string "our move here.\l"
	.string "Don't forget to set it!$"

PlayersHouse_1F_Text_ArentYouInterestedInRoom:
	.string "MOM: Well, {PLAYER}?\p"
	.string "Aren't you interested in seeing your\n"
	.string "very own room?$"

PlayersHouse_1F_Text_OhComeQuickly:
	.string "MOM: Oh! {PLAYER}, {PLAYER}!\n"
	.string "Quick! Come quickly!$"

PlayersHouse_1F_Text_MaybeDadWillBeOn:
	.string "MOM: Look! It's PETALBURG GYM!\n"
	.string "Maybe DAD will be on!$"

PlayersHouse_1F_Text_ReportFromPetalburgGym:
	.string "INTERVIEWER: …We brought you this\n"
	.string "report from in front of PETALBURG GYM.$"

PlayersHouse_1F_Text_ItsOverWeMissedHim:
	.string "MOM: Oh… It's over.\p"
	.string "I think DAD was on, but we missed him.\n"
	.string "Too bad.$"

PlayersHouse_1F_Text_GoIntroduceYourselfNextDoor:
	.string "Oh, yes.\n"
	.string "One of DAD's friends lives in town.\p"
	.string "PROF. BIRCH is his name.\p"
	.string "He lives right next door, so you should\n"
	.string "go over and introduce yourself.$"

PlayersHouse_1F_Text_DidYouMeetProfBirch:
	.string "MOM: Did you introduce yourself to\n"
	.string "PROF. BIRCH?$"

PlayersHouse_1F_Text_RunningShoesManual:
	.string "It's the instruction booklet for the\n"
	.string "RUNNING SHOES.\p"
	.string "“Press the B Button to run while\n"
	.string "wearing your RUNNING SHOES.\p"
	.string "“Lace up your RUNNING SHOES and hit\n"
	.string "the road running!”$"

PlayersHouse_1F_Text_DontPushYourselfTooHard:
	.string "Don't push yourself too hard, dear.\n"
	.string "You can always come home.\p"
	.string "Go for it, honey!$"

PlayersHouse_1F_Text_IsThatAPokenav:
	.string "MOM: What is that, honey? A POKéNAV?\n"
	.string "Someone from DEVON gave it to you?\p"
	.string "Well, honey, how about registering\n"
	.string "your mom?\p"
	.string "… … …$"

PlayersHouse_1F_Text_RegisteredMom:
	.string "Registered MOM\n"
	.string "in the POKéNAV.$"

PlayersHouse_1F_Text_GotDadsBadgeHeresSomethingFromMom:
	.string "MOM: Oh? Did DAD give you that BADGE?\p"
	.string "Then here's something from your MOM!$"

PlayersHouse_1F_Text_TicketFromBrineyCameForYou:
	.string "DAD: Hm?\p"
	.string "Hey, it's {PLAYER}!\p"
	.string "It's been a while since I saw you,\n"
	.string "but you look…stronger, somehow.\p"
	.string "That's the impression I get.\n"
	.string "But your old man hasn't given up yet!\p"
	.string "Oh, yes, I have something for you.\n"
	.string "This came to you from someone named\l"
	.string "MR. BRINEY.$"

PlayersHouse_1F_Text_PortsInSlateportLilycove:
	.string "DAD: Hm, a TICKET for a ferry?\p"
	.string "If I recall, there are ferry ports in\n"
	.string "SLATEPORT and LILYCOVE.$"

PlayersHouse_1F_Text_BetterGetBackToGym:
	.string "I'd better get back to PETALBURG GYM.\p"
	.string "MOM, thanks for looking after the house\n"
	.string "while I'm away.$"

PlayersHouse_1F_Text_DadShouldStayLonger:
	.string "MOM: That DAD of yours…\p"
	.string "He comes home for the first time in a\n"
	.string "while, but all he talks about is POKéMON.\p"
	.string "He should relax and stay a little longer.$"

PlayersHouse_1F_Text_IsThatABreakingStory:
	.string "MOM: Is that a breaking news story?$"

PlayersHouse_1F_Text_LatiEmergencyNewsFlash:
	.string "We bring you this emergency\n"
	.string "news flash!\p"
	.string "In various HOENN locales, there have\n"
	.string "been reports of a BZZT…colored\l"
	.string "POKéMON in flight.\p"
	.string "The identity of this POKéMON is\n"
	.string "currently unknown.\p"
	.string "We now return you to the regular\n"
	.string "movie program.$"

PlayersHouse_1F_Text_WhatColorDidTheySay:
	.string "MOM: {PLAYER}, did you catch that?\p"
	.string "What color did the announcer say\n"
	.string "that POKéMON was?$"

PlayersHouse_1F_Text_StillUnknownPokemon:
	.string "MOM: Well, isn't that something!\n"
	.string "There are still unknown POKéMON.$"

PlayersHouse_1F_Text_YouShouldRestABit:
	.string "MOM: How are you doing, {PLAYER}?\n"
	.string "You look a little tired.\p"
	.string "I think you should rest a bit.$"

PlayersHouse_1F_Text_SeeYouHoney:
	.string "MOM: See you, honey!$"

PlayersHouse_1F_Text_TakeCareHoney:
	.string "MOM: Take care, honey!$"

PlayersHouse_1F_Text_TheresAMovieOnTV:
	.string "There is a movie on TV.\p"
	.string "Two men are dancing on a big piano\n"
	.string "keyboard.\p"
	.string "Better get going!$"

PlayersHouse_1F_Text_Vigoroth1:
	.string "Fugiiiiih!$"

PlayersHouse_1F_Text_Vigoroth2:
	.string "Huggoh, uggo uggo…$"
