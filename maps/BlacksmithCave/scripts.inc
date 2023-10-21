.set LOCALID_CHARIZARD_X, 3
.set LOCALID_CHARIZARD_Y, 4

BlacksmithCave_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, BlacksmithCave_MapScripts_MAP_SCRIPT_ON_LOAD
	.byte 0

BlacksmithCave_MapScripts_MAP_SCRIPT_ON_LOAD::
	call_if_unset FLAG_LAVARIDGE_BLACKSMITH, BlacksmithCave_MapScripts_RemoveLava
	return

BlacksmithCave_MapScripts_RemoveLava:
	setmetatileblacksmithcave
	return

BlacksmithCave_EventScript_ItemCharizardX::
	lockall
	giveitem ITEM_CHARIZARDITE_X
	closemessage
	setflag FLAG_LAVARIDGE_BLACKSMITH
	removeobject LOCALID_CHARIZARD_X
	delay 30
	goto BlacksmithCave_EventScript_Lavaflow
	end

BlacksmithCave_EventScript_ItemCharizardY::
	lockall
	giveitem ITEM_CHARIZARDITE_Y
	closemessage
	setflag FLAG_LAVARIDGE_BLACKSMITH
	removeobject LOCALID_CHARIZARD_Y
	delay 30
	goto BlacksmithCave_EventScript_Lavaflow
	end

BlacksmithCave_EventScript_Lavaflow:
	setvar VAR_0x8004, 1   @ vertical pan
	setvar VAR_0x8005, 1   @ horizontal pan
	setvar VAR_0x8006, 20  @ num shakes
	setvar VAR_0x8007, 2   @ shake delay
	special ShakeCamera
	waitstate
	delay 30
	playse SE_PIN
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
	waitmovement 0
	message BlacksmithCave_Text_BetterRun
	waitmessage
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_Delay48
	waitmovement 0
	delay 4
	setvar VAR_0x8004, 2
	setvar VAR_0x8005, 2
	setvar VAR_0x8006, 32
	setvar VAR_0x8007, 3
	special ShakeCamera
	waitstate
	delay 30
	warp MAP_BLACKSMITH_CAVE, 255, 25, 23
	waitstate
	release
	end

BlacksmithCave_Text_BetterRun:
	.string "Better run right now!$"
