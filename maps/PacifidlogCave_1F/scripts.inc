.set LOCALID_MARSHADOW_1, 4
.set LOCALID_MARSHADOW_SHADOW_1, 2
.set LOCALID_MARSHADOW_2, 5
.set LOCALID_MARSHADOW_SHADOW_2, 3

PacifidlogCave_1F_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, PacifidlogCave_1F_OnLoad
	map_script MAP_SCRIPT_ON_FRAME_TABLE, PacifidlogCave_1F_OnFrame
	.byte 0

PacifidlogCave_1F_OnLoad:
	goto_if_unset FLAG_BATTLED_WITH_MARSHADOW, PacifidlogCave_1F_EventScript_ShowMarshadow
	goto PacifidlogCave_1F_EventScript_HideMarshadow
	end

PacifidlogCave_1F_EventScript_ShowMarshadow:
	addobject LOCALID_MARSHADOW_SHADOW_1
	addobject LOCALID_MARSHADOW_SHADOW_2
	clearflag FLAG_HIDE_MARSHADOW_SHADOW
	end

PacifidlogCave_1F_EventScript_HideMarshadow:
	removeobject LOCALID_MARSHADOW_SHADOW_1
	removeobject LOCALID_MARSHADOW_SHADOW_2
	end

@
PacifidlogCave_1F_OnFrame:
	map_script_2 VAR_TEMP_0, 0, PacifidlogCave_1F_EventScript_MarshadowTryHitOrRun
	.2byte 0

PacifidlogCave_1F_EventScript_MarshadowTryHitOrRun:
	setvar VAR_TEMP_0, 1
	goto_if_unset FLAG_BATTLED_WITH_MARSHADOW, PacifidlogCave_1F_EventScript_MarshadowHitOrRun
	end

PacifidlogCave_1F_EventScript_MarshadowHitOrRun:
	checkitem ITEM_RAINBOW_WING, 1
	compare VAR_RESULT, FALSE
	goto_if_eq PacifidlogCave_1F_EventScript_MarshadowRun
	goto PacifidlogCave_1F_EventScript_MarshadowHit
	end

PacifidlogCave_1F_EventScript_MarshadowRun:
	lock
	applymovement LOCALID_MARSHADOW_SHADOW_1, PacifidlogCave_1F_Movement_Shadow_Run1
	applymovement LOCALID_MARSHADOW_SHADOW_2, PacifidlogCave_1F_Movement_Shadow_Run2
	waitmovement 0
	delay 50
	msgbox PacifidlogCave_1F_Text_SawShadows, MSGBOX_DEFAULT
	removeobject LOCALID_MARSHADOW_SHADOW_1
	removeobject LOCALID_MARSHADOW_SHADOW_2
	release
	end

PacifidlogCave_1F_EventScript_TurnPlayerDown:
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceDown
	waitmovement 0
	return

PacifidlogCave_1F_EventScript_TurnPlayerRight:
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceRight
	waitmovement 0
	return

PacifidlogCave_1F_EventScript_MarshadowHit:
	lock
	getplayerxy VAR_TEMP_0, VAR_TEMP_1
	compare VAR_TEMP_0, 29
	call_if_eq PacifidlogCave_1F_EventScript_TurnPlayerDown
	playse SE_PIN
	applymovement LOCALID_MARSHADOW_SHADOW_1, PacifidlogCave_1F_Movement_Shadow_Approach1
	applymovement LOCALID_MARSHADOW_SHADOW_2, PacifidlogCave_1F_Movement_Shadow_Approach2
	waitmovement 0
	waitse
	delay 112
	getplayerxy VAR_TEMP_0, VAR_TEMP_1
	compare VAR_TEMP_0, 29
	call_if_ne PacifidlogCave_1F_EventScript_TurnPlayerRight
	msgbox PacifidlogCave_1F_Text_RainbowWingAttracted, MSGBOX_DEFAULT
	closemessage
	clearflag FLAG_HIDE_MARSHADOW
	addobject LOCALID_MARSHADOW_1
	addobject LOCALID_MARSHADOW_2
	setobjectxy LOCALID_MARSHADOW_1, 16, 40
	setobjectxy LOCALID_MARSHADOW_2, 29, 7
	delay 20
    playmoncry SPECIES_MARSHADOW, 0 
    waitmoncry
	setwildbattle SPECIES_MARSHADOW, 50, ITEM_MARSHADIUM_Z
	dowildbattle
	setflag FLAG_BATTLED_WITH_MARSHADOW
	compare VAR_RESULT, B_OUTCOME_LOST
	goto_if_eq PacifidlogCave_1F_Movement_Shadow_StealRainbowWingFainted
	compare VAR_RESULT, B_OUTCOME_RAN
	goto_if_eq PacifidlogCave_1F_Movement_Shadow_StealRainbowWing
	compare VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED
	goto_if_eq PacifidlogCave_1F_Movement_Shadow_StealRainbowWing
    delay B_WAIT_TIME_SHORT
    fadescreen FADE_TO_BLACK
    removeobject LOCALID_MARSHADOW_1
    removeobject LOCALID_MARSHADOW_2
    removeobject LOCALID_MARSHADOW_SHADOW_1
    removeobject LOCALID_MARSHADOW_SHADOW_2
    fadescreen FADE_FROM_BLACK
	release
	end

PacifidlogCave_1F_Movement_Shadow_StealRainbowWing:
    delay B_WAIT_TIME_SHORT
    fadescreen FADE_TO_BLACK
    removeobject LOCALID_MARSHADOW_1
    removeobject LOCALID_MARSHADOW_2
    removeobject LOCALID_MARSHADOW_SHADOW_1
    removeobject LOCALID_MARSHADOW_SHADOW_2
    msgbox PacifidlogCave_1F_Text_Shadow_StealRainbowWing, MSGBOX_AUTOCLOSE
    fadescreen FADE_FROM_BLACK
    removeitem ITEM_RAINBOW_WING, 1
    release
    end

PacifidlogCave_1F_Movement_Shadow_StealRainbowWingFainted:
    delay B_WAIT_TIME_SHORT
    fadescreen FADE_TO_BLACK
    removeobject LOCALID_MARSHADOW_1
    removeobject LOCALID_MARSHADOW_2
    removeobject LOCALID_MARSHADOW_SHADOW_1
    removeobject LOCALID_MARSHADOW_SHADOW_2
    msgbox PacifidlogCave_1F_Text_Shadow_StealRainbowWing, MSGBOX_AUTOCLOSE
    removeitem ITEM_RAINBOW_WING, 1
	special SetCB2WhiteOut
	waitstate

PacifidlogCave_1F_Movement_Shadow_Approach1:
	emote_exclamation_mark
	delay_16
	walk_down
	walk_right
	walk_right
	walk_right
	delay_16
	delay_16
	walk_right
	walk_down
	step_end

PacifidlogCave_1F_Movement_Shadow_Approach2:
	emote_exclamation_mark
	delay_16
	walk_left
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_up
	walk_up
	walk_up
	step_end

PacifidlogCave_1F_Movement_Shadow_Run1:
	walk_left
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

PacifidlogCave_1F_Movement_Shadow_Run2:
	walk_right
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

PacifidlogCave_1F_Text_SawShadows:
	.string "There's a sneaky shadow nearby…$"

PacifidlogCave_1F_Text_RainbowWingAttracted:
	.string "Seems that the shadow is attracted\n"
	.string "with the Rainbow Wing!$"

PacifidlogCave_1F_Text_Shadow_StealRainbowWing:
	.string "Marshadow stole\n"
	.string "{PLAYER}'s Rainbow Wing!$"
