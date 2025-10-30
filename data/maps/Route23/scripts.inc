Route23_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Route23_OnFrame
	.byte 0

	@ State descriptions for VAR_ROUTE23_STATE
	@ 0: First enter route
	@ 1: Init flags
	@ 2: Start Starter event
	@ 3: Chosen Starter
	@ 4: Finished battle tutorial
	@ 5: Finished talking with Prof
	@ 6: Collected Parcel for Mom

Route23_OnFrame:
	map_script_2 VAR_ROUTE23_STATE, 4, Route23_EventScript_FirstBattleEnd
	.2byte 0

Route23_EventScript_StartStarterEvent::
	lockall
	playse SE_PIN
	applymovement LOCALID_ROUTE23_PROF, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_ROUTE23_PROF, Common_Movement_Delay48
	waitmovement 0
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	msgbox Route23_Text_ProfAskForHelp1, MSGBOX_DEFAULT
	closemessage
	playse SE_PIN
	applymovement LOCALID_ROUTE23_PROF, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_PLAYERS_HOUSE_1F_MOM, Common_Movement_Delay48
	waitmovement 0
	msgbox Route23_Text_ProfAskForHelp2, MSGBOX_DEFAULT
	closemessage
	setvar VAR_ROUTE23_STATE, 2
	releaseall
	end

Route23_EventScript_PreventExitWestBeforePokemon::
	lockall
	msgbox Route23_Text_DontLeaveMe, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PLAYER, Route23_Movement_PreventExitWest
	waitmovement 0
	releaseall
	end

Route23_EventScript_PreventExitWestAfterPokemon::
	lockall
	msgbox Route23_Text_GrassIsHere, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PLAYER, Route23_Movement_PreventExitWest
	waitmovement 0
	releaseall
	end

Route23_EventScript_PreventExitNorth::
	lockall
	msgbox Route23_Text_GrassIsHere, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PLAYER, Route23_Movement_MovePlayerDown
	waitmovement 0
	releaseall
	end

Route23_EventScript_PreventExitBattleSouth::
	lockall
	msgbox Route23_Text_NeedPokemon, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PLAYER, Route23_Movement_MovePlayerUp
	waitmovement 0
	releaseall
	end

Route23_EventScript_PreventExitBattleEast::
	lockall
	msgbox Route23_Text_NeedPokemon, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PLAYER, Route23_Movement_PreventBattleEast
	waitmovement 0
	releaseall
	end

Route23_EventScript_ProfsBag::
	call_if_eq VAR_ROUTE23_STATE, 2, Route23_EventScript_BagGetPokemon
	call_if_eq VAR_ROUTE23_STATE, 3, Route23_EventScript_BagGotPokemon
	end

Route23_EventScript_BagGetPokemon::
	lock
	faceplayer
	setflag FLAG_SYS_POKEMON_GET
	setvar VAR_ROUTE23_STATE, 3
	fadescreen FADE_TO_BLACK
	special ChooseStarter
	waitstate
	bufferleadmonspeciesname STR_VAR_1
	applymovement LOCALID_ROUTE23_PROF, Route23_Movement_ProfApproachPlayer
	waitmovement 0
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	message Route23_Text_StarterGet
	waitmessage
	playfanfare MUS_OBTAIN_ITEM
	waitfanfare
	msgbox Route23_Text_WhyNotGiveNicknameToMon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Route23_EventScript_NicknameStarter
	goto_if_eq VAR_RESULT, NO, Route23_EventScript_BattleInstructions
	release
	end

Route23_EventScript_NicknameStarter::
	setvar VAR_0x8004, 0
	call Common_EventScript_NameReceivedPartyMon
	goto Route23_EventScript_BattleInstructions
	end

Route23_EventScript_BattleInstructions::
	msgbox Route23_Text_BattleInstructions, MSGBOX_DEFAULT
	closemessage
	end

Route23_EventScript_BagGotPokemon::
	msgbox Route23_Text_GotPokemon
	closemessage
	end

Route23_EventScript_FirstBattleEnd::
	lock
	setvar VAR_ROUTE23_STATE, 5
	applymovement LOCALID_ROUTE23_PROF, Route23_Movement_MoveProfToGrass
	waitmovement 0
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	msgbox Route23_Text_FirstBattleEnd, MSGBOX_DEFAULT
	goto Route23_EventScript_ProfHealsStarter
	end

Route23_EventScript_ProfHealsStarter::
	closemessage
	call Common_EventScript_OutOfCenterPartyHeal
	msgbox Route23_Text_YouShouldHeadToLab, MSGBOX_DEFAULT
	closemessage
	fadescreen FADE_TO_BLACK
	removeobject LOCALID_ROUTE23_PROF
	setflag FLAG_HIDE_ROUTE_101_BIRCH
	removeobject LOCALID_PROFS_BAG
	setflag FLAG_HIDE_ROUTE_101_BIRCH_STARTERS_BAG
	applymovement LOCALID_PLAYER, Common_Movement_Delay48
	waitmovement 0
	fadescreen FADE_FROM_BLACK
	release
	end

Route23_EventScript_MomParcelReminder::
	lockall
	msgbox Route23_Text_GoGetParcel, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PLAYER, Route23_Movement_MovePlayerUp
	waitmovement 0
	releaseall
	end

Route23_EventScript_FatMan::
	msgbox Route23_Text_CutTree, MSGBOX_DEFAULT
	closemessage
	end

Route23_EventScript_RouteSign::
	msgbox Route23_Text_RouteSign, MSGBOX_SIGN
	end

Route23_Movement_MovePlayerDown:
	walk_down
	step_end

Route23_Movement_MovePlayerUp:
	walk_up
	step_end

Route23_Movement_PreventExitWest:
	walk_right
	step_end

Route23_Movement_PreventBattleEast:
	walk_left
	step_end

Route23_Movement_ProfApproachPlayer:
	walk_down
	walk_in_place_faster_right
	step_end

Route23_Movement_MoveProfToGrass:
	walk_right
	walk_down
	walk_right
	face_player
	step_end

Route23_Movement_MoveProfOutOfScene:
	walk_right
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

Route23_Text_ProfAskForHelp1:
	.string "Sorry, but do you mind helping me out\n"
	.string "with my research?\p"
	.string "Ah, I should probably introduce myself\n"
	.string "first huh?\p"
	.string "I'm Professor Maple, and I specialize in\n"
	.string "researching anything to do with\l"
	.string "POKéMON moves.\p"
	.string "And as part of that research, I was\n"
	.string "doing a little field work on this route.\p"
	.string "But I wasn't really getting what I\n"
	.string "wanted by myself see...\p"
	.string "So I'd like to ask you to battle a wild\n"
	.string "POKéMON for me.$"

Route23_Text_ProfAskForHelp2:
	.string "What! You don't have any POKéMON with\n"
	.string "you?! And here I'd thought everyone\l"
	.string "your age would have a POKéMON\l"
	.string "these days. I mean it's all the rage\l"
	.string "isn't it! Battling! Leveling up!\l"
	.string "Learning more and more powerful moves!\p"
	.string "... ... ...\p"
	.string "Ahem, I'm getting ahead of myself.\p"
	.string "You know what! Since you don't have a\n"
	.string "POKéMON yet, I'll give you one!\p"
	.string "I just so happen to have three in my\n"
	.string "bag right now, go take a look!$"

Route23_Text_DontLeaveMe:
	.string "Do you not want a POKéMON?$"

Route23_Text_GrassIsHere:
	.string "Hey! The wild POKéMON are over here!$"

Route23_Text_NeedPokemon:
	.string "You need a POKéMON first!$"

Route23_Text_StarterGet:
	.string "So you chose {STR_VAR_1}?\n"
	.string "Great choice!\p"
	.string "{PLAYER} received the {STR_VAR_1}!$"

Route23_Text_WhyNotGiveNicknameToMon:
	.string "Do you want to give a nickname to\n"
	.string "{STR_VAR_1}?$"

Route23_Text_BattleInstructions:
	.string "Now, what I'd like you to do is walk into\n"
	.string "the patch of grass south of us and\l"
	.string "battle a wild POKéMON.\p"
	.string "Don't worry! As long as you have your\n"
	.string "POKéMON by your side you'll be fine!$"

Route23_Text_GotPokemon:
	.string "You've already chosen your POKéMON!$"

Route23_Text_FirstBattleEnd:
	.string "Wow! For a first battle, you sure had\n"
	.string "everything under control!\p"
	.string "Here, let me heal your POKéMON for you.$"

Route23_Text_YouShouldHeadToLab:
	.string "Thanks for the help, I've gotten all the\n"
	.string "data I need.\p"
	.string "Hmm... ... ...\p"
	.string "You know what, why don't you head to my\n"
	.string "lab? I have something there I'd like to\l"
	.string "give you. Just head past DIMWOOD TOWN\l"
	.string "along ROUTE 6 to IRONSIDE CITY and\l"
	.string "you'll find my POKéMON lab.\p"
	.string "See you there!$"

Route23_Text_GoGetParcel:
	.string "Mom's voice echoes in your head...\p"
	.string "{PLAYER}! Please go collect my parcel\n"
	.string "in DIMWOOD TOWN!$"

Route23_Text_CutTree:
	.string "I don't remember this tree being here...\p"
	.string "If only there was a way to cut it down...$"

Route23_Text_RouteSign:
	.string "ROUTE 23\p"
	.string "{UP_ARROW} DIMWOOD TOWN\n"
	.string "{DOWN_ARROW} MODELLA TOWN$"
