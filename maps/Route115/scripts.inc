Route115_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, Route115_OnLoad
	map_script MAP_SCRIPT_ON_TRANSITION, Route115_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Route115_OnFrame
	.byte 0

Route115_OnLoad:
	compare VAR_ABNORMAL_WEATHER_LOCATION, ABNORMAL_WEATHER_ROUTE_115_WEST
	call_if_eq AbnormalWeather_EventScript_PlaceTilesRoute115West
	compare VAR_ABNORMAL_WEATHER_LOCATION, ABNORMAL_WEATHER_ROUTE_115_EAST
	call_if_eq AbnormalWeather_EventScript_PlaceTilesRoute115East
	end

Route115_OnTransition:
	compare VAR_SHOULD_END_ABNORMAL_WEATHER, 1
	call_if_eq AbnormalWeather_EventScript_HideMapNamePopup
	compare VAR_ABNORMAL_WEATHER_LOCATION, ABNORMAL_WEATHER_ROUTE_115_WEST
	call_if_eq AbnormalWeather_StartGroudonWeather
	compare VAR_ABNORMAL_WEATHER_LOCATION, ABNORMAL_WEATHER_ROUTE_115_EAST
	call_if_eq AbnormalWeather_StartGroudonWeather
	end

Route115_OnFrame:
	map_script_2 VAR_SHOULD_END_ABNORMAL_WEATHER, 1, AbnormalWeather_EventScript_EndEventAndCleanup_1
	.2byte 0

Route115_EventScript_Woman::
	msgbox Route115_Text_NeverKnowWhenCavePokemonWillAppear, MSGBOX_NPC
	end

Route115_EventScript_RouteSignRustboro::
	msgbox Route115_Text_RouteSignRustboro, MSGBOX_SIGN
	end

Route115_EventScript_RouteSignSnowValley::
	msgbox Route115_Text_RouteSignSnowValley, MSGBOX_SIGN
	end

Route115_EventScript_MeteorFallsSign::
	msgbox Route115_Text_MeteorFallsSign, MSGBOX_SIGN
	end

Route115_EventScript_Timothy::
	trainerbattle_single TRAINER_TIMOTHY_1, Route115_Text_TimothyIntro, Route115_Text_TimothyDefeat, Route115_EventScript_RegisterTimothy
	specialvar VAR_RESULT, ShouldTryRematchBattle
	compare VAR_RESULT, TRUE
	goto_if_eq Route115_EventScript_RematchTimothy
	msgbox Route115_Text_TimothyPostBattle, MSGBOX_DEFAULT
	release
	end

Route115_EventScript_RegisterTimothy::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route115_Text_TimothyRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_TIMOTHY_1
	call EventScript_RocketEdition_TryStealPokemon
	release
	end

Route115_EventScript_RematchTimothy::
	trainerbattle_rematch TRAINER_TIMOTHY_1, Route115_Text_TimothyRematchIntro, Route115_Text_TimothyRematchDefeat
	msgbox Route115_Text_TimothyPostRematch, MSGBOX_AUTOCLOSE
	end

Route115_EventScript_Koichi::
	trainerbattle_single TRAINER_KOICHI, Route115_Text_KoichiIntro, Route115_Text_KoichiDefeat, EventScript_RocketEdition_TryStealPokemon
	msgbox Route115_Text_KoichiPostBattle, MSGBOX_AUTOCLOSE
	end

Route115_EventScript_Nob::
	trainerbattle_single TRAINER_NOB_1, Route115_Text_NobIntro, Route115_Text_NobDefeat, Route115_EventScript_RegisterNob
	specialvar VAR_RESULT, ShouldTryRematchBattle
	compare VAR_RESULT, TRUE
	goto_if_eq Route115_EventScript_RematchNob
	msgbox Route115_Text_NobPostBattle, MSGBOX_DEFAULT
	release
	end

Route115_EventScript_RegisterNob::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route115_Text_NobRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_NOB_1
	call EventScript_RocketEdition_TryStealPokemon
	release
	end

Route115_EventScript_RematchNob::
	trainerbattle_rematch TRAINER_NOB_1, Route115_Text_NobRematchIntro, Route115_Text_NobRematchDefeat
	msgbox Route115_Text_NobPostRematch, MSGBOX_AUTOCLOSE
	end

Route115_EventScript_Cyndy::
	trainerbattle_single TRAINER_CYNDY_1, Route115_Text_CyndyIntro, Route115_Text_CyndyDefeat, Route115_EventScript_RegisterCyndy
	specialvar VAR_RESULT, ShouldTryRematchBattle
	compare VAR_RESULT, TRUE
	goto_if_eq Route115_EventScript_RematchCyndy
	msgbox Route115_Text_CyndyPostBattle, MSGBOX_DEFAULT
	release
	end

Route115_EventScript_RegisterCyndy::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route115_Text_CyndyRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_CYNDY_1
	call EventScript_RocketEdition_TryStealPokemon
	release
	end

Route115_EventScript_RematchCyndy::
	trainerbattle_rematch TRAINER_CYNDY_1, Route115_Text_CyndyRematchIntro, Route115_Text_CyndyRematchDefeat
	msgbox Route115_Text_CyndyPostRematch, MSGBOX_AUTOCLOSE
	end

Route115_EventScript_Hector::
	trainerbattle_single TRAINER_HECTOR, Route115_Text_HectorIntro, Route115_Text_HectorDefeat, EventScript_RocketEdition_TryStealPokemon
	msgbox Route115_Text_HectorPostBattle, MSGBOX_AUTOCLOSE
	end

Route115_EventScript_Kyra::
	trainerbattle_single TRAINER_KYRA, Route115_Text_KyraIntro, Route115_Text_KyraDefeat, EventScript_RocketEdition_TryStealPokemon
	msgbox Route115_Text_KyraPostBattle, MSGBOX_AUTOCLOSE
	end

Route115_EventScript_Jaiden::
	trainerbattle_single TRAINER_JAIDEN, Route115_Text_JaidenIntro, Route115_Text_JaidenDefeat, EventScript_RocketEdition_TryStealPokemon
	msgbox Route115_Text_JaidenPostBattle, MSGBOX_AUTOCLOSE
	end

Route115_EventScript_Alix::
	trainerbattle_single TRAINER_ALIX, Route115_Text_AlixIntro, Route115_Text_AlixDefeat, EventScript_RocketEdition_TryStealPokemon
	msgbox Route115_Text_AlixPostBattle, MSGBOX_AUTOCLOSE
	end

Route115_EventScript_Helene::
	trainerbattle_single TRAINER_HELENE, Route115_Text_HeleneIntro, Route115_Text_HeleneDefeat, EventScript_RocketEdition_TryStealPokemon
	msgbox Route115_Text_HelenePostBattle, MSGBOX_AUTOCLOSE
	end

Route115_EventScript_Marlene::
	trainerbattle_single TRAINER_MARLENE, Route115_Text_MarleneIntro, Route115_Text_MarleneDefeat, EventScript_RocketEdition_TryStealPokemon
	msgbox Route115_Text_MarlenePostBattle, MSGBOX_AUTOCLOSE
	end

Route115_Text_NeverKnowWhenCavePokemonWillAppear:
	.string "Exploring a cave isn't like walking\n"
	.string "on a road.\p"
	.string "You never know when wild Pokémon will\n"
	.string "appear. It's full of suspense.$"

Route115_Text_RouteSignSnowValley:
	.string "Snow Valley$"

Route115_Text_RouteSignRustboro:
	.string "{UP_ARROW} Snow Valley\n"
	.string "Route 115\l"
	.string "{DOWN_ARROW} Rustboro City$"

Route115_Text_MeteorFallsSign:
	.string "Meteor Falls\n"
	.string "Fallarbor Town through here$"


Route115_EventScript_SnowTrigger::
	setweather WEATHER_SNOW
	fadenewbgm MUS_ROUTE104	
	doweather
	setvar VAR_TEMP_3, 0
	end

Route115_EventScript_SunTrigger::
	setweather WEATHER_SUNNY
	fadenewbgm MUS_ROUTE104	
	doweather
	setvar VAR_TEMP_3, 1
	end

Route115_EventScript_ViciousHailstormTrigger::
	goto Route115_EventScript_PreventRouteAccess
	checkitem ITEM_GO_GOGGLES, 1
	compare VAR_RESULT, FALSE
	goto_if_eq Route111_EventScript_PreventRouteAccess
	setvar VAR_TEMP_3, 0
	releaseall
	end

Route115_EventScript_PreventRouteAccess::
	msgbox gText_HailstormIsVicious, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, Route115_Movement_PushDownFromRoute
	waitmovement 0
	releaseall
	end

Route115_Movement_PushDownFromRoute:
	walk_down
	step_end

gText_HailstormIsVicious:
	.string "The hailstorm is vicious.\n"
	.string "It's impossible to keep going.$"
