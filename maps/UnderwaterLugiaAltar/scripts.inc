.set LOCALID_LUGIA, 1

UnderwaterLugiaAltar_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, UnderwaterLugiaAltar_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, UnderwaterLugiaAltar_OnResume
	.byte 0

UnderwaterLugiaAltar_OnTransition:
	call_if_set FLAG_CAUGHT_LUGIA, UnderwaterLugiaAltar_EventScript_HideLugia
	call_if_unset FLAG_CAUGHT_LUGIA, UnderwaterLugiaAltar_EventScript_TryShowLugia
	end

UnderwaterLugiaAltar_EventScript_HideLugia::
	setflag FLAG_HIDE_LUGIA
	return

UnderwaterLugiaAltar_EventScript_TryShowLugia::
	goto_if_set FLAG_DEFEATED_LUGIA, Common_EventScript_NopReturn
	clearflag FLAG_HIDE_LUGIA
	return

UnderwaterLugiaAltar_OnResume:
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, UnderwaterLugiaAltar_EventScript_TryRemoveLugia
	end

UnderwaterLugiaAltar_EventScript_TryRemoveLugia::
	specialvar VAR_RESULT, GetBattleOutcome
	compare VAR_RESULT, B_OUTCOME_CAUGHT
	goto_if_ne Common_EventScript_NopReturn
	removeobject LOCALID_LUGIA
	return

UnderwaterLugiaAltar_EventScript_Lugia::
	lock
	faceplayer
	waitse
	delay 20
	playse SE_THUNDERSTORM_STOP
	setvar VAR_0x8004, 0  @ vertical pan
	setvar VAR_0x8005, 3  @ horizontal pan
	setvar VAR_0x8006, 4  @ num shakes
	setvar VAR_0x8007, 2  @ shake delay
	special ShakeCamera
	delay 30
	playse SE_THUNDERSTORM_STOP
	setvar VAR_0x8004, 0  @ vertical pan
	setvar VAR_0x8005, 3  @ horizontal pan
	setvar VAR_0x8006, 4  @ num shakes
	setvar VAR_0x8007, 2  @ shake delay
	special ShakeCamera
	delay 30
	delay 50
	waitse
	playmoncry SPECIES_LUGIA, 2
	waitmoncry
	delay 20
	setvar VAR_0x8004, SPECIES_LUGIA
	setvar VAR_0x8005, 70  @ level
	setvar VAR_0x8006, ITEM_NONE
	special CreateEventLegalEnemyMon
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	special BattleSetup_StartLegendaryBattle
	waitstate
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq UnderwaterLugiaAltar_EventScript_DefeatedLugia
	compare VAR_RESULT, B_OUTCOME_RAN
	goto_if_eq UnderwaterLugiaAltar_EventScript_RanFromLugia
	compare VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED
	goto_if_eq UnderwaterLugiaAltar_EventScript_RanFromLugia
	setflag FLAG_CAUGHT_LUGIA
	release
	end

UnderwaterLugiaAltar_EventScript_DefeatedLugia::
	setflag FLAG_DEFEATED_LUGIA
	setvar VAR_0x8004, SPECIES_LUGIA
	goto Common_EventScript_LegendaryFlewAway
	end

UnderwaterLugiaAltar_EventScript_RanFromLugia::
	setvar VAR_0x8004, SPECIES_LUGIA
	goto Common_EventScript_LegendaryFlewAway
	end
