Route23_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Route23_OnFrame
	.byte 0

	@ State descriptions for VAR_ROUTE23_STATE
	@ 0: First enter route
	@ 1: Walk up to Dimwood for Parcel
	@ 2: Collected Parcel
	@ 3: Started Starter Event
	@ 4: Before opening Prof's bag
	@ 5: Before first battle
	@ 6: After first battle
	@ 7: Before first Rival battle (delivered parcel)
	@ 8: After first Rival battle
	@ 9: Reached Ironside City (Prof's lab)

Route23_OnFrame:
	map_script_2 VAR_ROUTE23_STATE, 0, Route23_EventScript_FirstEnterRoute
	map_script_2 VAR_ROUTE23_STATE, 5, Route23_EventScript_FirstBattleEnd
	.2byte 0

Route23_EventScript_FirstEnterRoute::
	setflag FLAG_HIDE_ROUTE_101_BIRCH_STARTERS_BAG
	setflag FLAG_HIDE_DIMWOOD_RIVAL
	setflag FLAG_HIDE_ROUTE23_RIVAL
	setvar VAR_ROUTE23_STATE, 1
	end

Route23_EventScript_StopEnterGrassSouth::
	lockall
	msgbox Route23_Text_NoPokemon, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PLAYER, Common_Movement_WalkUp
	waitmovement 0
	releaseall
	end

Route23_EventScript_StopEnterGrassEast::
	lockall
	msgbox Route23_Text_NoPokemon, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PLAYER, Common_Movement_WalkLeft
	waitmovement 0
	releaseall
	end

Route23_EventScript_StopEnterGrassWest::
	lockall
	msgbox Route23_Text_NoPokemon, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PLAYER, Common_Movement_WalkRight
	waitmovement 0
	releaseall
	end

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
	applymovement LOCALID_ROUTE23_PROF, Common_Movement_Delay48
	waitmovement 0
	msgbox Route23_Text_ProfAskForHelp2, MSGBOX_DEFAULT
	closemessage
	setvar VAR_ROUTE23_STATE, 3
	releaseall
	end

Route23_EventScript_PreventExitWestBeforePokemon::
	lockall
	msgbox Route23_Text_DontLeaveMe, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PLAYER, Common_Movement_WalkRight
	waitmovement 0
	releaseall
	end

Route23_EventScript_PreventExitEastBeforePokemon::
	lockall
	msgbox Route23_Text_DontLeaveMe, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PLAYER, Common_Movement_WalkLeft
	waitmovement 0
	releaseall
	end

Route23_EventScript_PreventExitSouthBeforePokemon::
	lockall
	msgbox Route23_Text_DontLeaveMe, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PLAYER, Common_Movement_WalkUp
	waitmovement 0
	releaseall
	end

Route23_EventScript_ProfsBag::
	call_if_eq VAR_ROUTE23_STATE, 3, Route23_EventScript_BagGetPokemon
	call_if_eq VAR_ROUTE23_STATE, 4, Route23_EventScript_BagGotPokemon
	end

Route23_EventScript_BagGetPokemon::
	lock
	faceplayer
	setflag FLAG_SYS_POKEMON_GET
	setvar VAR_ROUTE23_STATE, 4
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

Route23_EventScript_PreventExitSouthAfterPokemon::
	lockall
	msgbox Route23_Text_DontWander, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PLAYER, Common_Movement_WalkUp
	waitmovement 0
	releaseall
	end

Route23_EventScript_FirstBattleEnd::
	lock
	setvar VAR_ROUTE23_STATE, 6
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

Route23_EventScript_Rival::
	call_if_eq VAR_ROUTE23_STATE, 7, Route23_EventScript_RivalBattle
	call_if_eq VAR_ROUTE23_STATE, 8, Route23_EventScript_RivalStayBehind
	end

Route23_EventScript_RivalBattle::
	playbgm MUS_ENCOUNTER_BRENDAN, TRUE
	msgbox Route23_Text_RivalIntro, MSGBOX_DEFAULT
	switch VAR_STARTER_MON
	case 0, Route23_EventScript_StartRivalBattleTreecko
	case 1, Route23_EventScript_StartRivalBattleTorchic
	case 2, Route23_EventScript_StartRivalBattleMudkip
	end

Route23_EventScript_StartRivalBattleTreecko::
	trainerbattle_no_intro TRAINER_BRENDAN_ROUTE_103_TREECKO, Route23_Text_RivalDefeated
	goto Route23_EventScript_AfterRivalBattle
	end

Route23_EventScript_StartRivalBattleTorchic::
	trainerbattle_no_intro TRAINER_BRENDAN_ROUTE_103_TORCHIC, Route23_Text_RivalDefeated
	goto Route23_EventScript_AfterRivalBattle
	end

Route23_EventScript_StartRivalBattleMudkip::
	trainerbattle_no_intro TRAINER_BRENDAN_ROUTE_103_MUDKIP, Route23_Text_RivalDefeated
	goto Route23_EventScript_AfterRivalBattle
	end

Route23_EventScript_AfterRivalBattle::
	setvar VAR_ROUTE23_STATE, 8
	setflag FLAG_DEFEATED_RIVAL_ROUTE103
	setflag FLAG_HIDE_ROUTE23_RIVAL
	msgbox Route23_Text_AfterRivalBattle, MSGBOX_DEFAULT
	closemessage
	savebgm MUS_DUMMY
	fadedefaultbgm
	end

Route23_EventScript_RivalStayBehind::
	faceplayer
	msgbox Route23_Text_RivalStayBehind, MSGBOX_DEFAULT
	closemessage
	end

Route23_EventScript_FatMan::
	msgbox Route23_Text_CutTree, MSGBOX_DEFAULT
	closemessage
	end

Route23_EventScript_RouteSign::
	msgbox Route23_Text_RouteSign, MSGBOX_SIGN
	end

Route23_Movement_ProfApproachPlayer:
	walk_down
	walk_in_place_faster_right
	step_end

Route23_Movement_MoveProfToGrass:
	walk_right
	walk_right
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

Route23_Text_NoPokemon:
	.string "MOM's voice rings in your head...\p"
	.string "{PLAYER}! It's too dangerous to enter\n"
	.string "the tall grass without a POKéMON!$"

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

Route23_Text_DontWander:
	.string "Try not to stray too far away!$"

Route23_Text_StarterGet:
	.string "So you chose {STR_VAR_1}?\n"
	.string "Great choice!\p"
	.string "{PLAYER} received the {STR_VAR_1}!$"

Route23_Text_WhyNotGiveNicknameToMon:
	.string "Do you want to give a nickname to\n"
	.string "{STR_VAR_1}?$"

Route23_Text_BattleInstructions:
	.string "Now, what I'd like you to do is walk into\n"
	.string "the patch of grass to the right of us\l"
	.string "and battle a wild POKéMON.\p"
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

Route23_Text_RivalIntro:
	.string "Aha! Trainer spotted!\n"
	.string "And you know what that means! ...Right?$"

Route23_Text_RivalDefeated:
	.string "W-Wow...!$"

Route23_Text_AfterRivalBattle:
	.string "That was... Amazing!\p"
	.string "I've never seen someone so composed\n"
	.string "when battling! ...Not that I've been a\l"
	.string "trainer for very long though... Haha...\l"
	.string "Although it seems like you're a new\l"
	.string "trainer as well. Looks like I've got a\l"
	.string "lot to learn already...\p"
	.string "Oh, what's your name by the way?\p"
	.string "... ... ...\p"
	.string "{PLAYER}!\n"
	.string "I'm THOMAS, nice to meet you!\p"
	.string "... ... ...\p"
	.string "I-I'm going to be heading towards\n"
	.string "IRONSIDE city next, what about you?\p"
	.string "Oh! You as well, that's good to hear.\n"
	.string "Maybe I'll see you up ahead then!\p"
	.string "Oh! You go ahead though, I need to\n"
	.string "organize my items and POKéMON first...$"

Route23_Text_RivalStayBehind:
	.string "Don't mind me!\n"
	.string "See you at IRONSIDE city!$"

Route23_Text_CutTree:
	.string "I don't remember this tree being here...\p"
	.string "If only there was a way to cut it down...$"

Route23_Text_RouteSign:
	.string "ROUTE 23\p"
	.string "{UP_ARROW} DIMWOOD TOWN\n"
	.string "{DOWN_ARROW} MODELLA TOWN$"
