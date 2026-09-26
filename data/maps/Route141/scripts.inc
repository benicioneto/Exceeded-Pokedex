Route141_MapScripts::
	.byte 0


.set LOCALID_ULTRA_WORMHOLE, 3
EventScript_Buzzwole::
	lock
	faceplayer
	playbgm MUS_RG_ENCOUNTER_DEOXYS, FALSE
	waitse
	playmoncry SPECIES_BUZZWOLE, 2
	delay 40
	waitmoncry
	setvar VAR_0x8004, SPECIES_BUZZWOLE
	setvar VAR_0x8005, 60 @ level
	setvar VAR_0x8006, ITEM_NONE
	special CreateEventLegalEnemyMon
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	special BattleSetup_StartLegendaryBattle
	waitstate
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq EventScript_DefeatedUltraBeastBUZZWOLE
	compare VAR_RESULT, B_OUTCOME_CAUGHT
	goto_if_eq EventScript_DefeatedUltraBeastBUZZWOLE
	release
	end

EventScript_DefeatedUltraBeastBUZZWOLE:
	removeobject LOCALID_ULTRA_WORMHOLE
	release
	end
