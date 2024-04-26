.set LOCALID_GUARD, 1

MeteorFalls_BehindWaterfall_MapScripts::
	.byte 0

MeteorFalls_BehindWaterfall_EventScript_Trigger::
	compare VAR_END_OF_THE_WORLD, 2
	goto_if_ge MeteorFalls_BehindWaterfall_EventScript_DontTrigger
	lock
	applymovement LOCALID_GUARD, Common_Movement_FaceRight
	waitmovement 0
	msgbox MeteorFalls_BehindWaterfall_Text_OnlyTribe, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkDown
	waitmovement 0
	delay 8
	applymovement LOCALID_GUARD, Common_Movement_FaceDown
	waitmovement 0
	release
	end

MeteorFalls_BehindWaterfall_EventScript_DontTrigger:
	setvar VAR_TEMP_0, 1
	end

MeteorFalls_BehindWaterfall_EventScript_Guard::
	lock
	faceplayer
	compare VAR_END_OF_THE_WORLD, 2
	goto_if_ge MeteorFalls_BehindWaterfall_EventScript_RayquazaEvent
	msgbox MeteorFalls_BehindWaterfall_Text_OnlyTribe, MSGBOX_DEFAULT
	delay 8
	applymovement LOCALID_GUARD, Common_Movement_FaceDown
	waitmovement 0
	release
	end

MeteorFalls_BehindWaterfall_EventScript_RayquazaEvent:
	msgbox MeteorFalls_BehindWaterfall_Text_DragonidTribe, MSGBOX_DEFAULT
	release
	end

MeteorFalls_BehindWaterfall_Text_OnlyTribe:
	.string "????: How did you find our secret\n"
	.string "the entrance?\p"
	.string "However, only people from our tribe\n"
	.string "are allowed to pass.\p"
	.string "You shall not pass!$"

MeteorFalls_BehindWaterfall_Text_DragonidTribe:
	.string "Draconid Guard: You must be the hero\n"
	.string "that Zinnia talked about.\p"
	.string "She will explain the legends of\n"
	.string "Rayquaza! You shall pass!$"
