ModellaTown_Players_House_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, ModellaTown_Players_House_1F_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, ModellaTown_Players_House_1F_OnFrame
	.byte 0

	@ State descriptions for VAR_MODELLA_INTRO_STATE
	@ 0: Wake up
	@ 1: Before set clock
	@ 2: After set clock
	@ 3: Go on errand

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
