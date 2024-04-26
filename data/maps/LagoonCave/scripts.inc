LagoonCave_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, LagoonCave_OnResume
	map_script MAP_SCRIPT_ON_LOAD, LagoonCave_OnLoad
	map_script MAP_SCRIPT_ON_TRANSITION, LagoonCave_OnTransition
	.byte 0

LagoonCave_OnResume:
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, LagoonCave_EventScript_TryRemoveRegieleki
	end

LagoonCave_EventScript_TryRemoveRegieleki::
	specialvar VAR_RESULT, GetBattleOutcome
	compare VAR_RESULT, B_OUTCOME_CAUGHT
	goto_if_ne Common_EventScript_NopReturn
	removeobject VAR_LAST_TALKED
	return

LagoonCave_OnTransition:
	@setflag FLAG_LANDMARK_ANCIENT_TOMB
	call_if_unset FLAG_DEFEATED_REGIELEKI, LagoonCave_EventScript_ShowRegieleki
	end

LagoonCave_EventScript_ShowRegieleki::
	clearflag FLAG_HIDE_REGIELEKI
	return

LagoonCave_OnLoad:
	call_if_unset FLAG_SYS_REGIELEKI_PUZZLE_COMPLETED, LagoonCave_EventScript_HideRegiEntrance
	end

LagoonCave_EventScript_HideRegiEntrance::
	setmetatile 7, 19, METATILE_Cave_EntranceCover, 1
	setmetatile 8, 19, METATILE_Cave_EntranceCover, 1
	setmetatile 9, 19, METATILE_Cave_EntranceCover, 1
	setmetatile 7, 20, METATILE_Cave_SealedChamberBraille_Mid, 1
	setmetatile 8, 20, METATILE_Cave_SealedChamberBraille_Mid, 1
	setmetatile 9, 20, METATILE_Cave_SealedChamberBraille_Mid, 1
	return

LagoonCave_EventScript_CaveEntranceMiddle::
	lockall
	goto_if_set FLAG_SYS_REGIELEKI_PUZZLE_COMPLETED, LagoonCave_EventScript_BigHoleInWall
	braillemessage LagoonCave_Braille_ShineInTheMiddle
	waitbuttonpress
	closebraillemessage
	releaseall
	end

LagoonCave_EventScript_BigHoleInWall::
	msgbox gText_BigHoleInTheWall, MSGBOX_DEFAULT
	releaseall
	end

LagoonCave_EventScript_CaveEntranceSide::
	lockall
	braillemessage LagoonCave_Braille_ShineInTheMiddle
	waitbuttonpress
	closebraillemessage
	releaseall
	end

LagoonCave_EventScript_Regieleki::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_REGIELEKI, 2
	delay 40
	waitmoncry
	setwildbattle SPECIES_REGIELEKI, 40, ITEM_NONE
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	special StartRegiBattle
	waitstate
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq LagoonCave_EventScript_DefeatedRegieleki
	compare VAR_RESULT, B_OUTCOME_RAN
	goto_if_eq LagoonCave_EventScript_RanFromRegieleki
	compare VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED
	goto_if_eq LagoonCave_EventScript_RanFromRegieleki
	setflag FLAG_DEFEATED_REGIELEKI
	release
	end

LagoonCave_EventScript_DefeatedRegieleki::
	setflag FLAG_DEFEATED_REGIELEKI
	goto Common_EventScript_RemoveStaticPokemon
	end

LagoonCave_EventScript_RanFromRegieleki::
	setvar VAR_0x8004, SPECIES_REGIELEKI
	goto Common_EventScript_LegendaryFlewAway
	end

