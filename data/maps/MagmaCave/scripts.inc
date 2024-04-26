MagmaCave_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, MagmaCave_OnResume
	map_script MAP_SCRIPT_ON_LOAD, MagmaCave_OnLoad
	map_script MAP_SCRIPT_ON_TRANSITION, MagmaCave_OnTransition
	.byte 0

MagmaCave_OnResume:
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, MagmaCave_EventScript_TryRemoveRegidrago
	end

MagmaCave_EventScript_TryRemoveRegidrago::
	specialvar VAR_RESULT, GetBattleOutcome
	compare VAR_RESULT, B_OUTCOME_CAUGHT
	goto_if_ne Common_EventScript_NopReturn
	removeobject VAR_LAST_TALKED
	return

MagmaCave_OnLoad:
	call_if_unset FLAG_SYS_BRAILLE_REGIDRAGO_COMPLETED, MagmaCave_EventScript_HideRegiEntrance
	end

MagmaCave_EventScript_HideRegiEntrance::
	setmetatile 7, 19, METATILE_Cave_EntranceCover, 1
	setmetatile 8, 19, METATILE_Cave_EntranceCover, 1
	setmetatile 9, 19, METATILE_Cave_EntranceCover, 1
	setmetatile 7, 20, METATILE_Cave_SealedChamberBraille_Mid, 1
	setmetatile 8, 20, METATILE_Cave_SealedChamberBraille_Mid, 1
	setmetatile 9, 20, METATILE_Cave_SealedChamberBraille_Mid, 1
	return

MagmaCave_OnTransition:
	@setflag FLAG_LANDMARK_ISLAND_CAVE
	call MagmaCave_EventScript_ClearSteps
	call_if_unset FLAG_DEFEATED_REGIDRAGO, MagmaCave_EventScript_ShowRegidrago
	end

MagmaCave_EventScript_ShowRegidrago::
	clearflag FLAG_HIDE_REGIDRAGO
	return

MagmaCave_EventScript_OpenRegiEntrance::
	setmetatile 7, 19, METATILE_Cave_SealedChamberEntrance_TopLeft, 1
	setmetatile 8, 19, METATILE_Cave_SealedChamberEntrance_TopMid, 1
	setmetatile 9, 19, METATILE_Cave_SealedChamberEntrance_TopRight, 1
	setmetatile 7, 20, METATILE_Cave_SealedChamberEntrance_BottomLeft, 1
	setmetatile 8, 20, METATILE_Cave_SealedChamberEntrance_BottomMid, 0
	setmetatile 9, 20, METATILE_Cave_SealedChamberEntrance_BottomRight, 1
	special DrawWholeMapView
	playse SE_BANG
	setflag FLAG_SYS_BRAILLE_REGIDRAGO_COMPLETED
	end

MagmaCave_EventScript_CaveEntranceMiddle::
	lockall
	call_if_set FLAG_TEMP_3, MagmaCave_EventScript_ClearSteps
	goto_if_set FLAG_SYS_BRAILLE_REGIDRAGO_COMPLETED, MagmaCave_EventScript_BigHoleInWall
	braillemessage IslandCave_Braille_RunLapAroundWall
	setflag FLAG_TEMP_2
	special ShouldDoBrailleRegidragoPuzzle
	goto MagmaCave_EventScript_CloseBrailleMsg
	end

MagmaCave_EventScript_BigHoleInWall::
	msgbox gText_BigHoleInTheWall, MSGBOX_DEFAULT
	releaseall
	end

MagmaCave_EventScript_CaveEntranceSide::
	lockall
	call_if_set FLAG_TEMP_3, MagmaCave_EventScript_ClearSteps
	braillemessage IslandCave_Braille_RunLapAroundWall
	goto_if_set FLAG_SYS_BRAILLE_REGIDRAGO_COMPLETED, MagmaCave_EventScript_CloseBrailleMsg
	setflag FLAG_TEMP_2
	special ShouldDoBrailleRegidragoPuzzle
	goto MagmaCave_EventScript_CloseBrailleMsg
	end

MagmaCave_EventScript_CloseBrailleMsg::
	waitbuttonpress
	closebraillemessage
	releaseall
	end

MagmaCave_EventScript_ClearSteps::
	setvar VAR_REGIDRAGO_STEPS_1, 0
	setvar VAR_REGIDRAGO_STEPS_2, 0
	setvar VAR_REGIDRAGO_STEPS_3, 0
	clearflag FLAG_TEMP_3
	return

MagmaCave_EventScript_Regidrago::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_REGIDRAGO, 2
	delay 40
	waitmoncry
	setwildbattle SPECIES_REGIDRAGO, 40, ITEM_NONE
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	special StartRegiBattle
	waitstate
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq MagmaCave_EventScript_DefeatedRegidrago
	compare VAR_RESULT, B_OUTCOME_RAN
	goto_if_eq MagmaCave_EventScript_RanFromRegidrago
	compare VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED
	goto_if_eq MagmaCave_EventScript_RanFromRegidrago
	setflag FLAG_DEFEATED_REGIDRAGO
	release
	end

MagmaCave_EventScript_DefeatedRegidrago::
	setflag FLAG_DEFEATED_REGIDRAGO
	goto Common_EventScript_RemoveStaticPokemon
	end

MagmaCave_EventScript_RanFromRegidrago::
	setvar VAR_0x8004, SPECIES_REGIDRAGO
	goto Common_EventScript_LegendaryFlewAway
	end

