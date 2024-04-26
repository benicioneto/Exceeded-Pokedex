.set LOCALID_CELEBI, 3

EverGrandeCity_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, EverGrandeCity_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, EverGrandeCity_OnFrame
	.byte 0

EverGrandeCity_OnTransition:
	call_if_set FLAG_SYS_WEATHER_CTRL, Common_EventScript_SetAbnormalWeather
	end

EverGrandeCity_EventScript_VictoryRoadSign::
	msgbox EverGrandeCity_Text_EnteringVictoryRoad, MSGBOX_SIGN
	end

EverGrandeCity_EventScript_CitySign::
	msgbox EverGrandeCity_Text_CitySign, MSGBOX_SIGN
	end

EverGrandeCity_EventScript_PokemonLeagueSign::
	msgbox EverGrandeCity_Text_EnteringPokemonLeague, MSGBOX_SIGN
	setflag FLAG_VISITED_EVER_GRANDE_CITY
	end

EverGrandeCity_EventScript_SetVisitedEverGrande::
	setflag FLAG_VISITED_EVER_GRANDE_CITY
	setvar VAR_TEMP_1, 1
	end

EverGrandeCity_Text_EnteringVictoryRoad:
	.string "Entering Victory Road$"

EverGrandeCity_Text_EnteringPokemonLeague:
	.string "Entering Pokémon League\n"
	.string "Center Gate$"

EverGrandeCity_Text_CitySign:
	.string "Ever Grande City\p"
	.string "“The paradise of flowers, the sea,\n"
	.string "and Pokémon.”$"

EverGrandeCity_OnFrame:
	map_script_2 VAR_TEMP_0, 0, EverGrandeCity_EventScript_TryCelebiWarpTime
	.2byte 0

EverGrandeCity_EventScript_TryCelebiWarpTime:
	setvar VAR_TEMP_0, 1
	compare VAR_END_OF_THE_WORLD, 1
	goto_if_eq EverGrandeCity_EventScript_CelebiWarpTime
	end

EverGrandeCity_EventScript_CelebiWarpTime:
	lockall
	playse SE_PIN
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
	waitmovement 0
	delay 20
	applymovement OBJ_EVENT_ID_PLAYER, EverGrandeCity_Movement_PlayerConfused
	waitmovement 0
	delay 20
	msgbox EverGrandeCity_Text_PlayerFirstSpeech, MSGBOX_DEFAULT
	closemessage
	delay 20
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFastestUp
	waitmovement 0
	delay 20
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceLeft
	waitmovement 0
	delay 8
	msgbox EverGrandeCity_Text_PlayerSecondSpeech, MSGBOX_DEFAULT
	closemessage
	delay 20
	playmoncry SPECIES_CELEBI, 1
	msgbox EverGrandeCity_Text_CelebiSpeech, MSGBOX_DEFAULT
	waitmoncry
	closemessage
	delay 20
	removeobject LOCALID_CELEBI
	delay 20
	setvar VAR_END_OF_THE_WORLD, 2
	releaseall
	end

EverGrandeCity_Text_CelebiSpeech:
	.string "Biii!$"

EverGrandeCity_Text_PlayerFirstSpeech:
	.string "{PLAYER}: What is this?\p"
	.string "Where I am?$"

EverGrandeCity_Text_PlayerSecondSpeech:
	.string "{PLAYER}: Did you bring me\n"
	.string "back in time?\p"
	.string "…\p"
	.string "…\p"
	.string "Do you choose me to stop the\n"
	.string "meteor?\p"
	.string "But how?…$"

EverGrandeCity_Movement_PlayerConfused:
	walk_in_place_fast_down
	walk_in_place_fast_right
	walk_in_place_fast_up
	walk_in_place_fast_left
	walk_in_place_fast_left
	step_end
