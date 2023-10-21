UnderwaterAltar_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, UnderwaterAltar_MapScripts_MAP_SCRIPT_ON_LOAD
	.byte 0

UnderwaterAltar_MapScripts_MAP_SCRIPT_ON_LOAD:
	goto_if_set FLAG_OPENED_LUGIA_CHAMBER, Underwater_Altar_EventScript_OpenChamber
	end

Underwater_Altar_EventScript_OpenChamber:
	setmetatile 10, 7, METATILE_Underwater_Door_Up, FALSE
	setmetatile 10, 8, METATILE_Underwater_Door_Down, FALSE
	end

Underwater_Altar_EventScript_Braille::
	goto_if_set FLAG_OPENED_LUGIA_CHAMBER, Underwater_Altar_EventScript_NoEffect
	lockall
	braillemessage Underwater_Altar_Braille_SilverWing
	waitbuttonpress
	closebraillemessage
	checkitem ITEM_SILVER_WING, 1
	compare VAR_RESULT, FALSE
	goto_if_eq Underwater_Altar_EventScript_NoEffect
	setvar VAR_0x8004, 1
	setvar VAR_0x8005, 1
	setvar VAR_0x8006, 20
	setvar VAR_0x8007, 3
	special ShakeCamera
	waitstate
	playse SE_PIN
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_Delay48
	waitmovement 0
	delay 4
	setvar VAR_0x8004, 2
	setvar VAR_0x8005, 2
	setvar VAR_0x8006, 20
	setvar VAR_0x8007, 3
	special ShakeCamera
	delay 30
	setmetatile 10, 7, METATILE_Underwater_Door_Up, FALSE
	setmetatile 10, 8, METATILE_Underwater_Door_Down, FALSE
	special DrawWholeMapView
	playse SE_M_ROCK_THROW
	waitstate
	setflag FLAG_OPENED_LUGIA_CHAMBER
	releaseall
	end	

Underwater_Altar_EventScript_NoEffect::
	releaseall
	end
