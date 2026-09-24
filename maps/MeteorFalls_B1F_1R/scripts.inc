MeteorFalls_B1F_1R_MapScripts::
	.byte 0

.set LOCALID_ULTRA_WORMHOLE, 1
EventScript_POIPOLE::
	lock
	faceplayer
	playbgm MUS_RG_ENCOUNTER_DEOXYS, FALSE
	waitse
	playmoncry SPECIES_POIPOLE, 2
	delay 40
	waitmoncry
	setvar VAR_0x8004, SPECIES_POIPOLE
	setvar VAR_0x8005, 30 @ level
	setvar VAR_0x8006, ITEM_NONE
	special CreateEventLegalEnemyMon
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	special BattleSetup_StartLegendaryBattle
	waitstate
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq EventScript_DefeatedUltraBeastPOIPOLE
	compare VAR_RESULT, B_OUTCOME_CAUGHT
	goto_if_eq EventScript_DefeatedUltraBeastPOIPOLE
	release
	end

EventScript_DefeatedUltraBeastPOIPOLE:
	removeobject LOCALID_ULTRA_WORMHOLE
	waitstate
	end
