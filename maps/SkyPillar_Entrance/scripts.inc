SkyPillar_Entrance_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, SkyPillar_Entrance_OnTransition
	.byte 0

SkyPillar_Entrance_OnTransition:
	setflag FLAG_LANDMARK_SKY_PILLAR
	end

.set LOCALID_ULTRA_WORMHOLE, 1
EventScript_STAKATAKA::
	lock
	faceplayer
	playbgm MUS_RG_ENCOUNTER_DEOXYS, FALSE
	waitse
	playmoncry SPECIES_STAKATAKA, 2
	delay 40
	waitmoncry
	setvar VAR_0x8004, SPECIES_STAKATAKA
	setvar VAR_0x8005, 60 @ level
	setvar VAR_0x8006, ITEM_NONE
	special CreateEventLegalEnemyMon
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	special BattleSetup_StartLegendaryBattle
	waitstate
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq EventScript_DefeatedUltraBeastSTAKATAKA
	compare VAR_RESULT, B_OUTCOME_CAUGHT
	goto_if_eq EventScript_DefeatedUltraBeastSTAKATAKA
	release
	end

EventScript_DefeatedUltraBeastSTAKATAKA:
	removeobject LOCALID_ULTRA_WORMHOLE
	waitstate
	end

