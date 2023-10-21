Route138_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route138_OnTransition
	.byte 0

Route138_OnTransition::
	compare VAR_HO_OH_STATE, 2
	goto_if_ge Route138_EventScript_ShouldHideHooh
	checkitem ITEM_RAINBOW_WING, 1
	compare VAR_RESULT, FALSE
	goto_if_eq Route138_EventScript_ShouldHideHooh
	special GetDayOfWeek
	compare VAR_RESULT, 1 @sunday
	goto_if_eq Route138_EventScript_ShowHooh
Route138_EventScript_ShouldHideHooh:
	goto Route138_EventScript_HideHooh
	end

Route138_EventScript_HideHooh:
	setflag FLAG_HIDE_HO_OH
	setvar VAR_HO_OH_STATE, 0
	end

Route138_EventScript_ShowHooh:
	setvar VAR_HO_OH_STATE, 1
	end

Route138_EventScript_HoOh::
	lockall
	setvar VAR_HO_OH_STATE, 2
	clearflag FLAG_HIDE_HO_OH
	msgbox Route138F_Text_RainbowWingIsGlowing, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, Route138F_MovementTurnUpSurprise
	waitmovement 0
	special SpawnCameraObject
	setvar VAR_0x8004, 3  @ num loops
	setvar VAR_0x8005, 35 @ delay
	special LoopWingFlapSE
	applymovement LOCALID_HO_OH, Route138_Movement_HoOhAppear
	applymovement OBJ_EVENT_ID_CAMERA, Route138_Movement_CameraPanUp
	waitmovement 0
	delay 50
	setweather WEATHER_NONE
	doweather
	waitse
	playmoncry SPECIES_HO_OH, 2
	delay 30
	waitmoncry
	delay 60
	setvar VAR_0x8004, 3  @ num loops
	setvar VAR_0x8005, 35 @ delay
	special LoopWingFlapSE
	applymovement OBJ_EVENT_ID_CAMERA, Route138_Movement_CameraPanDown
	applymovement LOCALID_HO_OH, Route138_Movement_HoOhApproach
	waitmovement 0
	special RemoveCameraObject
	setvar VAR_0x8004, SPECIES_HO_OH
	setvar VAR_0x8005, 70 @ level
	setvar VAR_0x8006, ITEM_NONE
	special CreateEventLegalEnemyMon
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	special BattleSetup_StartLegendaryBattle
	waitstate
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	setvar VAR_LAST_TALKED, LOCALID_HO_OH
	specialvar VAR_RESULT, GetBattleOutcome
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq Route138_EventScript_DefeatedHoOh
	compare VAR_RESULT, B_OUTCOME_RAN
	goto_if_eq Route138_EventScript_RanFromHoOh
	compare VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED
	goto_if_eq Route138_EventScript_RanFromHoOh
	setflag FLAG_CAUGHT_HO_OH
	releaseall
	end

Route138_EventScript_DefeatedHoOh::
	setflag FLAG_DEFEATED_HO_OH
	setvar VAR_0x8004, SPECIES_HO_OH
	goto Common_EventScript_LegendaryFlewAway
	end

Route138_EventScript_RanFromHoOh::
	setvar VAR_0x8004, SPECIES_HO_OH
	goto Common_EventScript_LegendaryFlewAway
	end

Route138_Movement_CameraPanUp:
	walk_up
	walk_up
	walk_up
	step_end

Route138_Movement_CameraPanDown:
	delay_16
	delay_16
	walk_down
	walk_down
	walk_down
	step_end

Route138_Movement_HoOhApproach:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_in_place_down
	delay_16
	delay_16
	step_end

Route138_Movement_HoOhAppear:
	delay_16
	delay_16
	walk_in_place_down
	walk_in_place_down
	walk_in_place_down
	walk_in_place_down
	step_end

Route138F_MovementTurnUpSurprise:
	emote_exclamation_mark
	walk_in_place_fast_up
	step_end

Route138F_Text_RainbowWingIsGlowing:
	.string "Rainbow Wing is glowing!$"
