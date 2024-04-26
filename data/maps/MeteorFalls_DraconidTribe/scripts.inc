.set LOCALID_CELEBI, 1

MeteorFalls_DraconidTribe_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, MeteorFalls_DraconidTribe_OnFrame
	.byte 0

MeteorFalls_DraconidTribe_EventScript_SetVisitedDraconidTribe::
	setflag FLAG_VISITED_DRACONID_TRIBE
	setvar VAR_TEMP_1, 1
	end

MeteorFalls_DraconidTribe_OnFrame::
	map_script_2 VAR_END_OF_THE_WORLD, 3, MeteorFalls_DraconidTribe_EventScript_CelebiThankYou
	.2byte 0

MeteorFalls_DraconidTribe_EventScript_CelebiThankYou::
	lockall
	playse SE_PIN
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
	waitmovement 0
	delay 20
	applymovement LOCALID_CELEBI, MeteorFalls_1F_1R_Movement_CosmogHeart
	waitmovement 0
	applymovement LOCALID_CELEBI, MeteorFalls_DraconidTribe_Movement_CelebiCircle
	waitmovement 0
	playmoncry SPECIES_CELEBI, 1
	msgbox MeteorFalls_DraconidTribe_Text_CelebiThankYou, MSGBOX_DEFAULT
	waitmoncry
	closemessage
	msgbox MeteorFalls_DraconidTribe_Text_PlayerThankYou, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_CELEBI, Common_Movement_WalkUp
	waitmovement 0
	delay 80
	removeobject LOCALID_CELEBI
	setvar VAR_END_OF_THE_WORLD, 4
	delay 20
	msgbox MeteorFalls_DraconidTribe_Text_PlayerWait, MSGBOX_DEFAULT
	closemessage
	releaseall
	end

MeteorFalls_DraconidTribe_Movement_CelebiCircle:
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_right
	walk_fast_right
	walk_fast_right
	face_up
	step_end

MeteorFalls_DraconidTribe_Text_PlayerWait:
	.string "{PLAYER}: Wait, don't go!\p"
	.string "…$"

MeteorFalls_DraconidTribe_Text_PlayerThankYou:
	.string "{PLAYER}: Are you saying\n"
	.string "“Thank you”?$"

MeteorFalls_DraconidTribe_Text_CelebiThankYou:
	.string "Biiii!$"
