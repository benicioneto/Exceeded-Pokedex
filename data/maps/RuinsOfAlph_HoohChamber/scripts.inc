RuinsOfAlph_HoohChamber_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, RuinsOfAlph_HoohChamber_MapScripts_MAP_SCRIPT_ON_TRANSITION
	map_script MAP_SCRIPT_ON_LOAD, RuinsOfAlph_HoohChamber_MapScripts_MAP_SCRIPT_ON_LOAD
	map_script MAP_SCRIPT_ON_FRAME_TABLE, RuinsOfAlph_HoohChamber_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

@@@@@
RuinsOfAlph_HoohChamber_MapScripts_MAP_SCRIPT_ON_TRANSITION:
	goto_if_set FLAG_SYS_HO_OH_IN_PARTY, RuinsOfAlph_HoohChamber_MapScripts_MAP_SCRIPT_ON_TRANSITION_2
	return

RuinsOfAlph_HoohChamber_MapScripts_MAP_SCRIPT_ON_TRANSITION_1:
	setflag FLAG_HIDE_MAP_NAME_POPUP
	setvar VAR_TEMP_0, 1
	return

RuinsOfAlph_HoohChamber_MapScripts_MAP_SCRIPT_ON_TRANSITION_2:
	goto_if_unset FLAG_OPENED_WALL_IN_HO_OH_CHAMBER, RuinsOfAlph_HoohChamber_MapScripts_MAP_SCRIPT_ON_TRANSITION_1
	return

@@@@@
RuinsOfAlph_HoohChamber_MapScripts_MAP_SCRIPT_ON_LOAD:
	goto_if_set FLAG_SOLVED_HOOH_PUZZLE, RuinsOfAlph_HoohChamber_MapScripts_MAP_SCRIPT_ON_LOAD_2
RuinsOfAlph_HoohChamber_MapScripts_MAP_SCRIPT_ON_LOAD_1:
	goto_if_set FLAG_OPENED_WALL_IN_HO_OH_CHAMBER, RuinsOfAlph_HoohChamber_MapScripts_MAP_SCRIPT_ON_LOAD_4
	return

RuinsOfAlph_HoohChamber_MapScripts_MAP_SCRIPT_ON_LOAD_2:
	setmetatile 4, 5, METATILE_RuinsOfAlph_Puzzle_Hole_Left, FALSE
	setmetatile 5, 5, METATILE_RuinsOfAlph_Puzzle_Hole_Center, FALSE
	setmetatile 6, 5, METATILE_RuinsOfAlph_Puzzle_Hole_Right, FALSE
	goto RuinsOfAlph_HoohChamber_MapScripts_MAP_SCRIPT_ON_LOAD_1

RuinsOfAlph_HoohChamber_MapScripts_MAP_SCRIPT_ON_LOAD_4:
	setmetatile 5, 1, METATILE_RuinsOfAlph_HoleInWall, FALSE
	return

@@@@@
RuinsOfAlph_HoohChamber_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
	map_script_2 VAR_TEMP_0, 1, RuinsOfAlph_HoohChamber_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0
	.2byte 0

RuinsOfAlph_HoohChamber_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0:
	lockall
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
	setmetatile 5, 1, METATILE_RuinsOfAlph_HoleInWall, FALSE
	special DrawWholeMapView
	playse SE_M_ROCK_THROW
	waitstate
	clearflag FLAG_HIDE_MAP_NAME_POPUP
	setflag FLAG_OPENED_WALL_IN_HO_OH_CHAMBER
	setvar VAR_TEMP_0, 0
	releaseall
	return

@@@@@

RuinsOfAlph_HoohChamber_EventScript_HoohDescription::
	msgbox RuinsOfAlph_HoohChamber_EventScript_HoohDescription_Text_0, MSGBOX_SIGN
	return

RuinsOfAlph_HoohChamber_EventScript_HoohPuzzle::
	lockall
	setvar VAR_0x8004, 3
	special DoRuinsOfAlphPuzzle
	waitstate
	compare VAR_RESULT, 1
	goto_if_eq RuinsOfAlph_HoohChamber_EventScript_HoohPuzzle_2
RuinsOfAlph_HoohChamber_EventScript_HoohPuzzle_1:
	releaseall
	return

RuinsOfAlph_HoohChamber_EventScript_HoohPuzzle_2:
	setflag FLAG_SOLVED_HOOH_PUZZLE
	call RuinsOfAlph_Chambers_EventScript_SolvePuzzle
	setwarp MAP_RUINS_OF_ALPH_INNER_CHAMBER, 11, 0, 0
	special DoFallWarp
	waitstate
	goto RuinsOfAlph_HoohChamber_EventScript_HoohPuzzle_1

RuinsOfAlph_HoohChamber_EventScript_HoohDescription_Text_0:
	.string "A Pokemon that flew gracefully\n"
	.string "on rainbow-colored wings.$"

RuinsOfAlph_HoohChamber_EventScript_BackWall::
	lockall
	goto_if_set FLAG_OPENED_WALL_IN_HO_OH_CHAMBER, RuinsOfAlph_HoohChamber_EventScript_BackWall_2
	message RuinsOfAlph_HoohChamber_EventScript_BackWall_Text_1
	waitmessage
	unownmessage RuinsOfAlph_HoohChamber_Unown_Hooh
	waitbuttonpress
	closeunownmessage
	special IsFirstMonHooh
	compare VAR_RESULT, TRUE
	goto_if_eq RuinsOfAlph_HoohChamber_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0
RuinsOfAlph_HoohChamber_EventScript_BackWall_1:
	releaseall
	return

RuinsOfAlph_HoohChamber_EventScript_BackWall_2:
	msgbox RuinsOfAlph_HoohChamber_EventScript_BackWall_Text_0, MSGBOX_SIGN
	goto RuinsOfAlph_HoohChamber_EventScript_BackWall_1

RuinsOfAlph_HoohChamber_EventScript_BackWall_Text_0:
	.string "There's a big hole in the wall!$"

RuinsOfAlph_HoohChamber_EventScript_BackWall_Text_1:
	.string "Patterns appeared on the walls…$"

RuinsOfAlph_HoohChamber_Unown_Hooh:
	.unown "HO OH$"

