FieryPath_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, FieryPath_OnTransition
	.byte 0

FieryPath_OnTransition:
	call_if_unset FLAG_LANDMARK_FIERY_PATH, FieryPath_EventScript_MoveScottToFallarbor
	setflag FLAG_LANDMARK_FIERY_PATH
	end

FieryPath_EventScript_MoveScottToFallarbor::
	setflag FLAG_HIDE_VERDANTURF_TOWN_SCOTT
	clearflag FLAG_HIDE_FALLARBOR_TOWN_BATTLE_TENT_SCOTT
	return

.set LOCALID_ULTRA_WORMHOLE, 2
EventScript_BLACEPHALON::
	lock
	faceplayer
	playbgm MUS_RG_ENCOUNTER_DEOXYS, FALSE
	waitse
	playmoncry SPECIES_BLACEPHALON, 2
	delay 40
	waitmoncry
	setvar VAR_0x8004, SPECIES_BLACEPHALON
	setvar VAR_0x8005, 60 @ level
	setvar VAR_0x8006, ITEM_NONE
	special CreateEventLegalEnemyMon
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	special BattleSetup_StartLegendaryBattle
	waitstate
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq EventScript_DefeatedUltraBeastBLACEPHALON
	compare VAR_RESULT, B_OUTCOME_CAUGHT
	goto_if_eq EventScript_DefeatedUltraBeastBLACEPHALON
	release
	end

EventScript_DefeatedUltraBeastBLACEPHALON:
	removeobject LOCALID_ULTRA_WORMHOLE
	waitstate
	end

