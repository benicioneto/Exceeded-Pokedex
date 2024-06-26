.set LOCALID_STEVEN, 19
.set LOCALID_LATIAS, 22

Route118_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route118_OnTransition
	map_script MAP_SCRIPT_ON_LOAD, Route118_OnLoad
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Route118_OnFrame
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, Route118_OnWarp
	.byte 0

Route118_OnTransition:
	call GabbyAndTy_EventScript_UpdateLocation
	compare VAR_SHOULD_END_ABNORMAL_WEATHER, 1
	call_if_eq AbnormalWeather_EventScript_HideMapNamePopup
	compare VAR_ABNORMAL_WEATHER_LOCATION, ABNORMAL_WEATHER_ROUTE_118_EAST
	call_if_eq AbnormalWeather_StartGroudonWeather
	compare VAR_ABNORMAL_WEATHER_LOCATION, ABNORMAL_WEATHER_ROUTE_118_WEST
	call_if_eq AbnormalWeather_StartGroudonWeather
	end

Route118_OnLoad:
	compare VAR_ABNORMAL_WEATHER_LOCATION, ABNORMAL_WEATHER_ROUTE_118_EAST
	call_if_eq AbnormalWeather_EventScript_PlaceTilesRoute118East
	compare VAR_ABNORMAL_WEATHER_LOCATION, ABNORMAL_WEATHER_ROUTE_118_WEST
	call_if_eq AbnormalWeather_EventScript_PlaceTilesRoute118West
	end

Route118_OnFrame:
	map_script_2 VAR_SHOULD_END_ABNORMAL_WEATHER, 1, AbnormalWeather_EventScript_EndEventAndCleanup_1
	map_script_2 VAR_ROUTE118_STATE, 3, LatiEventEnd
	.2byte 0

Route118_OnWarp:
	map_script_2 VAR_ROUTE118_STATE, 3, Route118_EventScript_ChangeDir
	.2byte 0

Route118_EventScript_ChangeDir::
	turnobject OBJ_EVENT_ID_PLAYER, DIR_EAST
	end

LatiEventEnd::
	lock	
	setobjectxy LOCALID_STEVEN, 44, 11
	turnobject LOCALID_STEVEN, DIR_WEST
	msgbox Route118_Text_StevenGoodbye, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_STEVEN, Route118_Movement_StevenExitFinal
	waitmovement 0
	removeobject LOCALID_STEVEN
	release
	setvar VAR_ROUTE118_STATE, 4
	clearflag FLAG_LANDMARK_SOUTHERN_ISLAND
	end

Route118_EventScript_GoodRodFisherman::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_GOOD_ROD, Route118_EventScript_ReceivedGoodRod
	msgbox Route118_Text_YouAgreeGoodRodIsGood, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq Route118_EventScript_ReceiveGoodRod
	compare VAR_RESULT, NO
	goto_if_eq Route118_EventScript_DeclineGoodRod
	end

Route118_EventScript_ReceiveGoodRod::
	msgbox Route118_Text_IdenticalMindsTakeThis, MSGBOX_DEFAULT
	giveitem ITEM_GOOD_ROD
	setflag FLAG_RECEIVED_GOOD_ROD
	msgbox Route118_Text_TryYourLuckFishing, MSGBOX_DEFAULT
	release
	end

Route118_EventScript_DeclineGoodRod::
	msgbox Route118_Text_DontYouLikeToFish, MSGBOX_DEFAULT
	release
	end

Route118_EventScript_ReceivedGoodRod::
	msgbox Route118_Text_TryCatchingMonWithGoodRod, MSGBOX_DEFAULT
	release
	end

Route118_EventScript_Girl::
	msgbox Route118_Text_CanCrossRiversWithSurf, MSGBOX_NPC
	end

Route118_EventScript_RouteSignMauville::
	msgbox Route118_Text_RouteSignMauville, MSGBOX_SIGN
	end

Route118_EventScript_RouteSign119::
	msgbox Route118_Text_RouteSign119, MSGBOX_SIGN
	end

Route118_EventScript_StevenTrigger0::
	lockall
	setvar VAR_0x8008, 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceUp
	waitmovement 0
	applymovement LOCALID_STEVEN, Route118_Movement_StevenApproachLedge0
	waitmovement 0
	goto Route118_EventScript_StevenTrigger
	end

Route118_EventScript_StevenTrigger1::
	lockall
	setvar VAR_0x8008, 1
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceUp
	waitmovement 0
	goto Route118_EventScript_StevenTrigger
	end

Route118_EventScript_StevenTrigger2::
	lockall
	setvar VAR_0x8008, 2
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceUp
	waitmovement 0
	applymovement LOCALID_STEVEN, Route118_Movement_StevenApproachLedge2
	waitmovement 0
	goto Route118_EventScript_StevenTrigger
	end

Route118_EventScript_StevenTrigger::
	addobject LOCALID_LATIAS
	playse SE_LEDGE
	applymovement LOCALID_STEVEN, Route118_Movement_StevenJumpLedge
	waitmovement 0
	delay 30
	msgbox Route118_Text_StevenQuestions, MSGBOX_DEFAULT
	closemessage
	playmoncry SPECIES_LATIAS, 0
	delay 90
	playse SE_PIN
	applymovement LOCALID_STEVEN, Common_Movement_ExclamationMark
	delay 30
	compare VAR_0x8008, 0
	call_if_eq Route118_EventScript_StevenExit0
	compare VAR_0x8008, 1
	call_if_eq Route118_EventScript_StevenExit1
	compare VAR_0x8008, 2
	call_if_eq Route118_EventScript_StevenExit2
	applymovement LOCALID_LATIAS, Route118_Movement_LatiasEnter
	waitmovement 0
	playmoncry SPECIES_LATIAS, 0
	delay 90
	msgbox Route118_Text_StevenLatias1, MSGBOX_DEFAULT
	compare VAR_0x8008, 0
	call_if_eq Route118_EventScript_StevenTurn0
	compare VAR_0x8008, 1
	call_if_eq Route118_EventScript_StevenTurn1
	compare VAR_0x8008, 2
	call_if_eq Route118_EventScript_StevenTurn1
	msgbox Route118_Text_StevenLatias2, MSGBOX_DEFAULT
	clearflag FLAG_HIDE_ROUTE118_LATIAS
	setflag FLAG_SOUTHERNISLAND_SHIP
	warp MAP_SOUTHERN_ISLAND_EXTERIOR, 255, 15, 20
	end

Route118_EventScript_StevenExit0::
	applymovement OBJ_EVENT_ID_PLAYER, Route118_Movement_PlayerWatchStevenExit
	applymovement LOCALID_STEVEN, Route118_Movement_StevenExit0
	waitmovement 0
	return

Route118_EventScript_StevenExit1::
	applymovement OBJ_EVENT_ID_PLAYER, Route118_Movement_TurnToStevenLeft
	applymovement LOCALID_STEVEN, Route118_Movement_StevenExit1
	waitmovement 0
	return

Route118_EventScript_StevenExit2::
	applymovement OBJ_EVENT_ID_PLAYER, Route118_Movement_TurnToStevenLeft
	applymovement LOCALID_STEVEN, Route118_Movement_StevenExit1
	waitmovement 0
	return

Route118_Movement_TurnToStevenLeft:
	delay_16
	walk_in_place_fastest_left
	step_end

Route118_Movement_PlayerWatchStevenExit:
	delay_16
	walk_in_place_fastest_right
	step_end

Route118_EventScript_StevenTurn0::
	applymovement OBJ_EVENT_ID_PLAYER, Route118_Movement_PlayerTurnsRight
	applymovement 19, Route118_Movement_PlayerTurnsLeft
	waitmovement 0
	return

Route118_EventScript_StevenTurn1::
	applymovement OBJ_EVENT_ID_PLAYER, Route118_Movement_PlayerTurnsLeft
	applymovement 19, Route118_Movement_PlayerTurnsRight
	waitmovement 0
	return

Route118_Movement_PlayerTurnsRight::
	walk_in_place_right
	step_end

Route118_Movement_PlayerTurnsLeft::
	walk_in_place_left
	step_end

Route118_Movement_StevenApproachLedge0:
	walk_left
	step_end

Route118_Movement_StevenApproachLedge2:
	walk_right
	step_end

Route118_Movement_StevenJumpLedge:
	jump_2_down
	delay_16
	walk_down
	step_end

Route118_Movement_StevenExit0:
	walk_right
	walk_down
	step_end

Route118_Movement_StevenExit1:
	walk_left
	walk_down
	step_end

Route118_Movement_LatiasEnter:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

Route118_Movement_StevenExitFinal:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

Route118_Text_StevenLatias1:
	.string "…Hm?\p"
	.string "Latias!!\p"
	.string "Do you…want us to soar somewhere\n"
	.string "with you?$"

Route118_Text_StevenLatias2:
	.string "{PLAYER}{KUN}.\p"
	.string "Come with me.\p"
	.string "Latias…\n"
	.string "I believe that she sought us out for\l"
	.string "help.\p"
	.string "If that's the case, let's go!$"

Route118_EventScript_Rose::
	trainerbattle_single TRAINER_ROSE_1, Route118_Text_RoseIntro, Route118_Text_RoseDefeat, Route118_EventScript_RegisterRose
	specialvar VAR_RESULT, ShouldTryRematchBattle
	compare VAR_RESULT, TRUE
	goto_if_eq Route118_EventScript_RematchRose
	msgbox Route118_Text_RosePostBattle, MSGBOX_DEFAULT
	release
	end

Route118_EventScript_RegisterRose::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route118_Text_RoseRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_ROSE_1
	call EventScript_RocketEdition_TryStealPokemon_Return
	release
	end

Route118_EventScript_RematchRose::
	trainerbattle_rematch TRAINER_ROSE_1, Route118_Text_RoseRematchIntro, Route118_Text_RoseRematchDefeat
	msgbox Route118_Text_RosePostRematch, MSGBOX_AUTOCLOSE
	end

Route118_EventScript_Barny::
	trainerbattle_single TRAINER_BARNY, Route118_Text_BarnyIntro, Route118_Text_BarnyDefeat, EventScript_RocketEdition_TryStealPokemon_Releaseall
	msgbox Route118_Text_BarnyPostBattle, MSGBOX_AUTOCLOSE
	end

Route118_EventScript_Wade::
	trainerbattle_single TRAINER_WADE, Route118_Text_WadeIntro, Route118_Text_WadeDefeat, EventScript_RocketEdition_TryStealPokemon_Releaseall
	msgbox Route118_Text_WadePostBattle, MSGBOX_AUTOCLOSE
	end

Route118_EventScript_Dalton::
	trainerbattle_single TRAINER_DALTON_1, Route118_Text_DaltonIntro, Route118_Text_DaltonDefeat, Route118_EventScript_RegisterDalton
	specialvar VAR_RESULT, ShouldTryRematchBattle
	compare VAR_RESULT, TRUE
	goto_if_eq Route118_EventScript_RematchDalton
	msgbox Route118_Text_DaltonPostBattle, MSGBOX_DEFAULT
	release
	end

Route118_EventScript_RegisterDalton::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route118_Text_DaltonRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_DALTON_1
	call EventScript_RocketEdition_TryStealPokemon_Return
	release
	end

Route118_EventScript_RematchDalton::
	trainerbattle_rematch TRAINER_DALTON_1, Route118_Text_DaltonRematchIntro, Route118_Text_DaltonRematchDefeat
	msgbox Route118_Text_DaltonPostRematch, MSGBOX_AUTOCLOSE
	end

Route118_EventScript_Perry::
	trainerbattle_single TRAINER_PERRY, Route118_Text_PerryIntro, Route118_Text_PerryDefeat, EventScript_RocketEdition_TryStealPokemon_Releaseall
	msgbox Route118_Text_PerryPostBattle, MSGBOX_AUTOCLOSE
	end

Route118_EventScript_Chester::
	trainerbattle_single TRAINER_CHESTER, Route118_Text_ChesterIntro, Route118_Text_ChesterDefeat, EventScript_RocketEdition_TryStealPokemon_Releaseall
	msgbox Route118_Text_ChesterPostBattle, MSGBOX_AUTOCLOSE
	end

Route118_EventScript_Deandre::
	trainerbattle_single TRAINER_DEANDRE, Route118_Text_DeandreIntro, Route118_Text_DeandreDefeat, EventScript_RocketEdition_TryStealPokemon_Releaseall
	msgbox Route118_Text_DeandrePostBattle, MSGBOX_AUTOCLOSE
	end

Route118_Text_StevenQuestions:
	.string "Steven: Hi, {PLAYER}{KUN}!\p"
	.string "It's me, Steven!\n"
	.string "We met in the cave near Dewford.\p"
	.string "Have you met many kinds of Pokémon\n"
	.string "since I last saw you?\p"
	.string "There are many, many kinds of Pokémon\n"
	.string "in this wide world of ours.\p"
	.string "If you wanted to raise only your\n"
	.string "favorites, that's fine.\p"
	.string "Perhaps you find it more fun to raise\n"
	.string "all sorts of Pokémon.\p"
	.string "As a Trainer of Pokémon,\n"
	.string "what do you think?\p"
	.string "Of course, it's not any of my business.\p"
	.string "It would be nice if we were to meet\n"
	.string "again somewhere.$"

Route118_Text_YouAgreeGoodRodIsGood:
	.string "Hmm!\n"
	.string "A Good Rod is really good!\p"
	.string "Wouldn't you agree?$"

Route118_Text_IdenticalMindsTakeThis:
	.string "Hmm!\n"
	.string "We're of identical minds!\p"
	.string "Hmm!\n"
	.string "Take this Good Rod!$"

Route118_Text_TryYourLuckFishing:
	.string "Wherever there's water, try your luck\n"
	.string "at fishing.$"

Route118_Text_DontYouLikeToFish:
	.string "Don't you like to fish?$"

Route118_Text_TryCatchingMonWithGoodRod:
	.string "Try catching all sorts of Pokémon\n"
	.string "with your Good Rod.$"

Route118_Text_CanCrossRiversWithSurf:
	.string "Even if there isn't a boat, you can\n"
	.string "cross rivers and the sea if you have\l"
	.string "a Pokémon that knows Surf.\p"
	.string "Pokémon can be counted on to do so\n"
	.string "much!$"

Route118_Text_RouteSignMauville:
	.string "Route 118\n"
	.string "{LEFT_ARROW} Mauville City$"

Route118_Text_RouteSign119:
	.string "Route 118\n"
	.string "{UP_ARROW} Route 119$"

Route118_Text_StevenGoodbye:
	.string "Thank you for your help {PLAYER}{KUN}.\p"
	.string "In the end you were a far greater\n"
	.string "help than I expected you might be.\p"
	.string "I expect that you and your team will\n"
	.string "be able to best both Route 119 ahead\l"
	.string "and even the Fortree Gym beyond that.\p"
	.string "I'll be curious to see how much stronger\n"
	.string "you might grow by the next time we meet.\p"
	.string "Until then, {PLAYER}{KUN}.$"

