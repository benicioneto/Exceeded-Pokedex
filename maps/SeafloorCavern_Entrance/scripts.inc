.set LOCALID_GRUNT, 1

SeafloorCavern_Entrance_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, SeafloorCavern_Entrance_OnResume
	.byte 0

SeafloorCavern_Entrance_OnResume:
	setdivewarp MAP_UNDERWATER_SEAFLOOR_CAVERN, 255, 6, 5
	setescapewarp MAP_UNDERWATER_SEAFLOOR_CAVERN, 255, 6, 5
	end

SeafloorCavern_Entrance_EventScript_Grunt::
	lockall
	compare VAR_HAS_TALKED_TO_SEAFLOOR_CAVERN_ENTRANCE_GRUNT, 1
	goto_if_eq SeafloorCavern_Entrance_EventScript_GruntSpeechShort
	waitse
	playse SE_PIN
	applymovement LOCALID_GRUNT, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_GRUNT, Common_Movement_Delay48
	waitmovement 0
	delay 20
	compare VAR_FACING, DIR_WEST
	call_if_eq SeafloorCavern_Entrance_EventScript_GruntFacePlayerWest
	compare VAR_FACING, DIR_EAST
	call_if_eq SeafloorCavern_Entrance_EventScript_GruntFacePlayerEast
	compare VAR_FACING, DIR_NORTH
	call_if_eq SeafloorCavern_Entrance_EventScript_GruntFacePlayerNorth
	delay 30
	setvar VAR_HAS_TALKED_TO_SEAFLOOR_CAVERN_ENTRANCE_GRUNT, 1
	copyobjectxytoperm LOCALID_GRUNT
	msgbox SeafloorCavern_Entrance_Text_HearMagmaNearMossdeep, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_GRUNT, Common_Movement_WalkInPlaceFastestUp
	waitmovement 0
	releaseall
	end

.set LOCALID_ULTRA_WORMHOLE, 2
EventScript_NIHILEGO::
	lock
	faceplayer
	playbgm MUS_RG_ENCOUNTER_DEOXYS, FALSE
	waitse
	playmoncry SPECIES_NIHILEGO, 2
	delay 40
	waitmoncry
	setvar VAR_0x8004, SPECIES_NIHILEGO
	setvar VAR_0x8005, 60 @ level
	setvar VAR_0x8006, ITEM_NONE
	special CreateEventLegalEnemyMon
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	special BattleSetup_StartLegendaryBattle
	waitstate
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq EventScript_DefeatedUltraBeastNIHILEGO
	compare VAR_RESULT, B_OUTCOME_CAUGHT
	goto_if_eq EventScript_DefeatedUltraBeastNIHILEGO
	release
	end

EventScript_DefeatedUltraBeastNIHILEGO:
	removeobject LOCALID_ULTRA_WORMHOLE
	release
	end

SeafloorCavern_Entrance_EventScript_GruntSpeechShort::
	compare VAR_FACING, DIR_WEST
	call_if_eq SeafloorCavern_Entrance_EventScript_GruntFacePlayerWest
	compare VAR_FACING, DIR_EAST
	call_if_eq SeafloorCavern_Entrance_EventScript_GruntFacePlayerEast
	compare VAR_FACING, DIR_NORTH
	call_if_eq SeafloorCavern_Entrance_EventScript_GruntFacePlayerNorth
	msgbox SeafloorCavern_Entrance_Text_HearMagmaNearMossdeepShort, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_GRUNT, Common_Movement_WalkInPlaceFastestUp
	waitmovement 0
	releaseall
	end

SeafloorCavern_Entrance_EventScript_GruntFacePlayerEast::
	applymovement LOCALID_GRUNT, Common_Movement_WalkInPlaceFastestLeft
	waitmovement 0
	return

SeafloorCavern_Entrance_EventScript_GruntFacePlayerWest::
	applymovement LOCALID_GRUNT, Common_Movement_WalkInPlaceFastestRight
	waitmovement 0
	return

SeafloorCavern_Entrance_EventScript_GruntFacePlayerNorth::
	applymovement LOCALID_GRUNT, Common_Movement_WalkInPlaceFastestDown
	waitmovement 0
	return

SeafloorCavern_Entrance_Text_HearMagmaNearMossdeep:
	.string "Hey!\n"
	.string "I remember your face!\p"
	.string "If you're here, it must mean that\n"
	.string "you're about to mess with us again!\p"
	.string "A punk like you, do you really think\n"
	.string "you can take on Team Aqua?\p"
	.string "I'd say you're too early by about\n"
	.string "a trillion years!\p"
	.string "You're a perfect fit for the likes of\n"
	.string "Team Magma!\p"
	.string "Speaking of Team Magma, I hear they\n"
	.string "were spotted near Mossdeep.\p"
	.string "That bunch of goons, they sure don't\n"
	.string "look good near the sea!$"

SeafloorCavern_Entrance_Text_HearMagmaNearMossdeepShort:
	.string "A punk like you, do you really think\n"
	.string "you can take on Team Aqua?\p"
	.string "I'd say you're too early by about\n"
	.string "a trillion years!\p"
	.string "You're a perfect fit for the likes of\n"
	.string "Team Magma!\p"
	.string "Speaking of Team Magma, I hear they\n"
	.string "were spotted near Mossdeep.\p"
	.string "That bunch of goons, they sure don't\n"
	.string "look good near the sea!$"

