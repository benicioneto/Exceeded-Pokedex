.set LOCALID_TEAM_GALACTIC_GRUNT, 11

GraniteCave_B2F_MapScripts::
	.byte 0

GraniteCave_EventScript_TeamGalacticFoundItem::
	lockall
	msgbox GraniteCave_Text_TeamGalacticPlans, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_TEAM_GALACTIC_GRUNT, GraniteCave_Movement_LookLeft
	waitmovement 0
	msgbox GraniteCave_Text_TeamGalacticBattle, MSGBOX_DEFAULT
	closemessage
	trainerbattle_no_intro TRAINER_GALACTIC_GRUNT_GRANITE_CAVE, GraniteCave_EventScript_Text_GruntDefeat
	msgbox GraniteCave_GraniteCave_Text_BossGoingToBeFurious, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_TEAM_GALACTIC_GRUNT, GraniteCave_Movement_GruntExit1
	waitmovement 0
	removeobject LOCALID_TEAM_GALACTIC_GRUNT
	delay 30
	setvar VAR_TEAM_GALACTIC_STATE, 2
	setflag FLAG_HIDE_GRANITE_CAVE_TEAM_GALATIC
	releaseall
	end

GraniteCave_EventScript_TeamGalacticFoundItem2::
	lockall
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceUp
	waitmovement 0
	msgbox GraniteCave_Text_TeamGalacticPlans, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_TEAM_GALACTIC_GRUNT, GraniteCave_Movement_LookDown
	waitmovement 0
	msgbox GraniteCave_Text_TeamGalacticBattle, MSGBOX_DEFAULT
	closemessage
	trainerbattle_no_intro TRAINER_GALACTIC_GRUNT_GRANITE_CAVE, GraniteCave_EventScript_Text_GruntDefeat
	msgbox GraniteCave_GraniteCave_Text_BossGoingToBeFurious, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_TEAM_GALACTIC_GRUNT, GraniteCave_Movement_GruntExit2
	waitmovement 0
	removeobject LOCALID_TEAM_GALACTIC_GRUNT
	delay 30
	setvar VAR_TEAM_GALACTIC_STATE, 2
	setflag FLAG_HIDE_GRANITE_CAVE_TEAM_GALATIC
	releaseall
	end

GraniteCave_EventScript_Text_GruntDefeat:
	.string "What?!\n"
	.string "I lost!$"

GraniteCave_Text_TeamGalacticPlans:
	.string "So the northern team found a\n"
	.string "clue that lead us to the ancient\l"
	.string "Dragonid tribe and the leaders\l"
	.string "are heading there…$"

GraniteCave_Text_TeamGalacticBattle:
	.string "Oh no…\p"
	.string "…\p"
	.string "…\p"
	.string "Nobody should know details of\n"
	.string "Team Galactic's plan…\l"
	.string "now I'll have to defeat you!$"

GraniteCave_GraniteCave_Text_BossGoingToBeFurious:
	.string "I'll take revenge… But for\n"
	.string "now I'll let it go, because\l"
	.string "Granite Cave was a false lead\l"
	.string "and the northern team\l"
	.string "was successful! Haha…$"

GraniteCave_Movement_GruntExit1:
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

GraniteCave_Movement_GruntExit2:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

GraniteCave_Movement_LookDown:
	face_down
	emote_exclamation_mark
	step_end

GraniteCave_Movement_LookLeft:
	face_left
	emote_exclamation_mark
	step_end
