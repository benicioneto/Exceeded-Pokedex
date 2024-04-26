.set LOCALID_WALLY, 2
.set LOCALID_BOY, 3
.set LOCALID_WALLYS_DAD, 5
.set LOCALID_GYM_BOY, 8
.set LOCALID_SCOTT, 9
.set LOCALID_BRENDAN, 12
.set LOCALID_MAY, 13
.set LOCALID_WALLY_2, 14
.set LOCALID_BRENDAN_2, 16
.set LOCALID_MAY_2, 17

PetalburgCity_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, PetalburgCity_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, PetalburgCity_OnFrame
	.byte 0

PetalburgCity_OnTransition:
	setflag FLAG_VISITED_PETALBURG_CITY
	compare VAR_PETALBURG_CITY_STATE, 0
	call_if_eq PetalburgCity_EventScript_MoveGymBoyToWestEntrance
	compare VAR_PETALBURG_CITY_STATE, 2
	call_if_eq PetalburgCity_EventScript_DisableMapNameAndMusic
	compare VAR_PETALBURG_CITY_STATE, 4
	call_if_eq PetalburgCity_EventScript_DisableMapNameAndMusic
	compare VAR_PETALBURG_GYM_STATE, 8
	call_if_eq PetalburgCity_EventScript_SetGymDoorsUnlocked
	end

PetalburgCity_EventScript_MoveGymBoyToWestEntrance::
	setobjectxyperm LOCALID_GYM_BOY, 5, 11
	return

PetalburgCity_EventScript_DisableMapNameAndMusic::
	setflag FLAG_HIDE_MAP_NAME_POPUP
	savebgm MUS_FOLLOW_ME
	return

PetalburgCity_EventScript_SetGymDoorsUnlocked::
	setvar VAR_PETALBURG_GYM_STATE, 7
	return

PetalburgCity_OnFrame:
	map_script_2 VAR_PETALBURG_CITY_STATE, 2, PetalburgCity_EventScript_WallyTutorial
	map_script_2 VAR_PETALBURG_CITY_STATE, 4, PetalburgCity_EventScript_WalkToWallyHouse
	.2byte 0

PetalburgCity_EventScript_WallyTutorial::
	lockall
	special SavePlayerParty
	special PutZigzagoonInPlayerParty
	applymovement LOCALID_WALLY, PetalburgCity_Movement_WallyTutorialWally
	applymovement OBJ_EVENT_ID_PLAYER, PetalburgCity_Movement_WallyTutorialPlayer
	waitmovement 0
	msgbox Route102_Text_WatchMeCatchPokemon, MSGBOX_DEFAULT
	special StartWallyTutorialBattle
	waitstate
	msgbox Route102_Text_WallyIDidIt, MSGBOX_DEFAULT
	applymovement LOCALID_WALLY, Common_Movement_WalkInPlaceFastestLeft, MAP_PETALBURG_CITY
	waitmovement LOCALID_WALLY, MAP_PETALBURG_CITY
	msgbox Route102_Text_LetsGoBack, MSGBOX_DEFAULT
	closemessage
	clearflag FLAG_HIDE_MAP_NAME_POPUP
	setvar VAR_PETALBURG_CITY_STATE, 3
	fadedefaultbgm
	clearflag FLAG_DONT_TRANSITION_MUSIC
	special LoadPlayerParty
	setvar VAR_PETALBURG_GYM_STATE, 1
	warp MAP_PETALBURG_CITY_GYM, 255, 4, 108
	waitstate
	releaseall
	end

PetalburgCity_EventScript_WalkToWallyHouse::
	lockall
	setflag FLAG_HIDE_MAP_NAME_POPUP
	applymovement LOCALID_WALLYS_DAD, PetalburgCity_Movement_WalkToWallyHouseWallysDad
	applymovement OBJ_EVENT_ID_PLAYER, PetalburgCity_Movement_WalkToWallyHousePlayer
	waitmovement 0
	setvar VAR_0x8004, 7
	setvar VAR_0x8005, 5
	opendoor VAR_0x8004, VAR_0x8005
	waitdooranim
	applymovement LOCALID_WALLYS_DAD, PetalburgCity_Movement_WalkInsideHouseWallysDad
	applymovement OBJ_EVENT_ID_PLAYER, PetalburgCity_Movement_WalkInsideHousePlayer
	waitmovement 0
	setflag FLAG_HIDE_PETALBURG_CITY_WALLYS_DAD
	hideobjectat OBJ_EVENT_ID_PLAYER, MAP_PETALBURG_CITY
	closedoor VAR_0x8004, VAR_0x8005
	waitdooranim
	clearflag FLAG_HIDE_MAP_NAME_POPUP
	fadedefaultbgm
	clearflag FLAG_DONT_TRANSITION_MUSIC
	warp MAP_PETALBURG_CITY_WALLYS_HOUSE, 255, 2, 4
	waitstate
	releaseall
	end

PetalburgCity_EventScript_Boy::
	lock
	faceplayer
	msgbox PetalburgCity_Text_WaterReflection, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_BOY, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

PetalburgCity_EventScript_WallysMom::
	msgbox PetalburgCity_Text_WhereIsWally, MSGBOX_NPC
	end

PetalburgCity_Movement_WalkToWallyHousePlayer:
	delay_8
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

PetalburgCity_Movement_WalkInsideHousePlayer:
	walk_up
	walk_up
	step_end

PetalburgCity_Movement_WalkToWallyHouseWallysDad:
	delay_8
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

PetalburgCity_Movement_WalkInsideHouseWallysDad:
	walk_up
	set_invisible
	step_end

PetalburgCity_Movement_WallyTutorialPlayer:
	delay_8
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_up
	walk_up
	walk_in_place_fastest_right
	step_end

PetalburgCity_Movement_WallyTutorialWally:
	delay_8
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_up
	walk_up
	walk_right
	delay_16
	walk_in_place_fastest_up
	delay_16
	delay_16
	walk_in_place_fastest_right
	step_end

PetalburgCity_EventScript_GymSign::
	msgbox PetalburgCity_Text_GymSign, MSGBOX_SIGN
	end

PetalburgCity_EventScript_CitySign::
	msgbox PetalburgCity_Text_CitySign, MSGBOX_SIGN
	end

PetalburgCity_EventScript_Gentleman::
	msgbox PetalburgCity_Text_FullPartyExplanation, MSGBOX_NPC
	end

PetalburgCity_EventScript_WallyHouseSign::
	msgbox PetalburgCity_Text_WallyHouseSign, MSGBOX_SIGN
	end

PetalburgCity_EventScript_ShowGymToPlayer0::
	lockall
	setvar VAR_0x8008, 0
	goto PetalburgCity_EventScript_ShowGymToPlayer
	end

PetalburgCity_EventScript_ShowGymToPlayer1::
	lockall
	setvar VAR_0x8008, 1
	goto PetalburgCity_EventScript_ShowGymToPlayer
	end

PetalburgCity_EventScript_ShowGymToPlayer2::
	lockall
	setvar VAR_0x8008, 2
	goto PetalburgCity_EventScript_ShowGymToPlayer
	end

PetalburgCity_EventScript_ShowGymToPlayer3::
	lockall
	setvar VAR_0x8008, 3
	goto PetalburgCity_EventScript_ShowGymToPlayer
	end

PetalburgCity_EventScript_ShowGymToPlayer::
	applymovement LOCALID_GYM_BOY, Common_Movement_FacePlayer
	waitmovement 0
	playbgm MUS_FOLLOW_ME, FALSE
	playse SE_PIN
	applymovement LOCALID_GYM_BOY, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_GYM_BOY, Common_Movement_Delay48
	waitmovement 0
	compare VAR_0x8008, 0
	call_if_eq PetalburgCity_EventScript_BoyApproachPlayer0
	compare VAR_0x8008, 1
	call_if_eq PetalburgCity_EventScript_BoyApproachPlayer1
	compare VAR_0x8008, 2
	call_if_eq PetalburgCity_EventScript_BoyApproachPlayer2
	compare VAR_0x8008, 3
	call_if_eq PetalburgCity_EventScript_BoyApproachPlayer3
	msgbox PetalburgCity_Text_AreYouRookieTrainer, MSGBOX_DEFAULT
	closemessage
	compare VAR_0x8008, 0
	call_if_eq PetalburgCity_EventScript_LeadPlayerToGym0
	compare VAR_0x8008, 1
	call_if_eq PetalburgCity_EventScript_LeadPlayerToGym1
	compare VAR_0x8008, 2
	call_if_eq PetalburgCity_EventScript_LeadPlayerToGym2
	compare VAR_0x8008, 3
	call_if_eq PetalburgCity_EventScript_LeadPlayerToGym3
	msgbox PetalburgCity_Text_ThisIsPetalburgGym, MSGBOX_DEFAULT
	applymovement LOCALID_GYM_BOY, Common_Movement_WalkInPlaceFastestRight
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFastestRight
	waitmovement 0
	msgbox PetalburgCity_Text_ThisIsGymSign, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_GYM_BOY, PetalburgCity_Movement_BoyWalkAway
	waitmovement 0
	fadedefaultbgm
	releaseall
	end

PetalburgCity_EventScript_BoyApproachPlayer0::
	applymovement LOCALID_GYM_BOY, PetalburgCity_Movement_BoyApproachPlayer0
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFastestDown
	waitmovement 0
	return

PetalburgCity_EventScript_BoyApproachPlayer1::
	applymovement LOCALID_GYM_BOY, PetalburgCity_Movement_BoyApproachPlayer1
	waitmovement 0
	return

PetalburgCity_EventScript_BoyApproachPlayer2::
	applymovement LOCALID_GYM_BOY, PetalburgCity_Movement_BoyApproachPlayer2
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFastestUp
	waitmovement 0
	return

PetalburgCity_EventScript_BoyApproachPlayer3::
	applymovement LOCALID_GYM_BOY, PetalburgCity_Movement_BoyApproachPlayer3
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFastestUp
	waitmovement 0
	return

PetalburgCity_EventScript_LeadPlayerToGym0::
	applymovement LOCALID_GYM_BOY, PetalburgCity_Movement_BoyWalkToGym0
	applymovement OBJ_EVENT_ID_PLAYER, PetalburgCity_Movement_PlayerWalkToGym0
	waitmovement 0
	return

PetalburgCity_EventScript_LeadPlayerToGym1::
	applymovement LOCALID_GYM_BOY, PetalburgCity_Movement_BoyWalkToGym1
	applymovement OBJ_EVENT_ID_PLAYER, PetalburgCity_Movement_PlayerWalkToGym1
	waitmovement 0
	return

PetalburgCity_EventScript_LeadPlayerToGym2::
	applymovement LOCALID_GYM_BOY, PetalburgCity_Movement_BoyWalkToGym2
	applymovement OBJ_EVENT_ID_PLAYER, PetalburgCity_Movement_PlayerWalkToGym2
	waitmovement 0
	return

PetalburgCity_EventScript_LeadPlayerToGym3::
	applymovement LOCALID_GYM_BOY, PetalburgCity_Movement_BoyWalkToGym3
	applymovement OBJ_EVENT_ID_PLAYER, PetalburgCity_Movement_PlayerWalkToGym3
	waitmovement 0
	return

@ Unused
PetalburgCity_Movement_Delay48::
	delay_16
	delay_16
	delay_16
	step_end

PetalburgCity_Movement_BoyApproachPlayer0:
	walk_right
	walk_right
	walk_right
	walk_in_place_fastest_up
	step_end

PetalburgCity_Movement_BoyApproachPlayer1:
	walk_right
	walk_right
	step_end

PetalburgCity_Movement_BoyApproachPlayer2:
	walk_right
	walk_right
	walk_right
	walk_in_place_fastest_down
	step_end

PetalburgCity_Movement_BoyApproachPlayer3:
	walk_down
	walk_right
	walk_right
	walk_right
	walk_in_place_fastest_down
	step_end

PetalburgCity_Movement_BoyWalkToGym0:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_up
	walk_right
	walk_in_place_fastest_up
	step_end

PetalburgCity_Movement_BoyWalkToGym1:
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_up
	walk_up
	walk_right
	walk_in_place_fastest_up
	step_end

PetalburgCity_Movement_BoyWalkToGym2:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_up
	walk_right
	walk_in_place_fastest_up
	step_end

PetalburgCity_Movement_BoyWalkToGym3:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_up
	walk_up
	walk_right
	walk_in_place_fastest_up
	step_end

PetalburgCity_Movement_BoyWalkAway:
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

PetalburgCity_Movement_PlayerWalkToGym0:
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_up
	step_end

PetalburgCity_Movement_PlayerWalkToGym1:
	delay_16
	delay_16
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_up
	walk_up
	step_end

PetalburgCity_Movement_PlayerWalkToGym2:
	walk_up
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_up
	step_end

PetalburgCity_Movement_PlayerWalkToGym3:
	walk_up
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_up
	walk_up
	step_end

PetalburgCity_EventScript_Scott0::
	lockall
	addobject LOCALID_SCOTT
	setvar VAR_0x8008, 0
	setobjectxy LOCALID_SCOTT, 13, 10
	goto PetalburgCity_EventScript_Scott
	end

PetalburgCity_EventScript_Scott1::
	lockall
	addobject LOCALID_SCOTT
	setvar VAR_0x8008, 1
	setobjectxy LOCALID_SCOTT, 13, 11
	goto PetalburgCity_EventScript_Scott
	end

PetalburgCity_EventScript_Scott2::
	lockall
	addobject LOCALID_SCOTT
	setvar VAR_0x8008, 2
	setobjectxy LOCALID_SCOTT, 13, 12
	goto PetalburgCity_EventScript_Scott
	end

PetalburgCity_EventScript_Scott3::
	lockall
	addobject LOCALID_SCOTT
	setvar VAR_0x8008, 3
	setobjectxy LOCALID_SCOTT, 13, 13
	goto PetalburgCity_EventScript_Scott
	end

PetalburgCity_EventScript_Scott::
	applymovement LOCALID_SCOTT, PetalburgCity_Movement_ScottStartWalkLeft
	waitmovement 0
	playse SE_PIN
	applymovement LOCALID_SCOTT, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_SCOTT, Common_Movement_Delay48
	waitmovement 0
	applymovement LOCALID_SCOTT, PetalburgCity_Movement_ScottApproachPlayer
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFastestRight
	waitmovement 0
	setvar VAR_SCOTT_STATE, 1
	msgbox PetalburgCity_Text_AreYouATrainer, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SCOTT, Common_Movement_WalkInPlaceFastestRight
	waitmovement 0
	delay 30
	msgbox PetalburgCity_Text_WellMaybeNot, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SCOTT, Common_Movement_WalkInPlaceFastestLeft
	waitmovement 0
	delay 30
	msgbox PetalburgCity_Text_ImLookingForTalentedTrainers, MSGBOX_DEFAULT
	closemessage
	compare VAR_0x8008, 0
	call_if_eq PetalburgCity_EventScript_ScottExit0
	compare VAR_0x8008, 1
	call_if_eq PetalburgCity_EventScript_ScottExit1
	compare VAR_0x8008, 2
	call_if_eq PetalburgCity_EventScript_ScottExit2
	compare VAR_0x8008, 3
	call_if_eq PetalburgCity_EventScript_ScottExit3
	setvar VAR_SCOTT_PETALBURG_ENCOUNTER, 1
	removeobject LOCALID_SCOTT
	releaseall
	end

PetalburgCity_EventScript_ScottExit0::
	applymovement OBJ_EVENT_ID_PLAYER, PetalburgCity_Movement_PlayerWatchScottExit0
	applymovement LOCALID_SCOTT, PetalburgCity_Movement_ScottExit0
	waitmovement 0
	return

PetalburgCity_EventScript_ScottExit1::
	applymovement OBJ_EVENT_ID_PLAYER, PetalburgCity_Movement_PlayerWatchScottExit1
	applymovement LOCALID_SCOTT, PetalburgCity_Movement_ScottExit1
	waitmovement 0
	return

PetalburgCity_EventScript_ScottExit2::
	applymovement OBJ_EVENT_ID_PLAYER, PetalburgCity_Movement_PlayerWatchScottExit2
	applymovement LOCALID_SCOTT, PetalburgCity_Movement_ScottExit2
	waitmovement 0
	return

PetalburgCity_EventScript_ScottExit3::
	applymovement OBJ_EVENT_ID_PLAYER, PetalburgCity_Movement_PlayerWatchScottExit3
	applymovement LOCALID_SCOTT, PetalburgCity_Movement_ScottExit3
	waitmovement 0
	return

PetalburgCity_Movement_ScottStartWalkLeft:
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

PetalburgCity_Movement_ScottApproachPlayer:
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

PetalburgCity_Movement_ScottExit0:
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

PetalburgCity_Movement_PlayerWatchScottExit0:
	delay_16
	walk_in_place_fastest_down
	delay_16
	delay_16
	delay_8
	walk_in_place_fastest_left
	step_end

PetalburgCity_Movement_ScottExit1:
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

PetalburgCity_Movement_PlayerWatchScottExit1:
	delay_16
	walk_in_place_fastest_down
	delay_16
	delay_8
	walk_in_place_fastest_left
	step_end

PetalburgCity_Movement_ScottExit2:
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

PetalburgCity_Movement_PlayerWatchScottExit2:
	delay_16
	walk_in_place_fastest_down
	delay_16
	delay_8
	walk_in_place_fastest_left
	step_end

PetalburgCity_Movement_ScottExit3:
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

PetalburgCity_Movement_PlayerWatchScottExit3:
	delay_16
	walk_in_place_fastest_up
	delay_16
	delay_8
	walk_in_place_fastest_left
	step_end

PetalburgCity_EventScript_GymBoy::
	msgbox PetalburgCity_Text_AreYouRookieTrainer, MSGBOX_NPC
	end

PetalburgCity_Text_WhereIsWally:
	.string "Where has our Wally gone?\p"
	.string "We have to leave for Verdanturf Town\n"
	.string "very soon…$"

PetalburgCity_Text_AreYouRookieTrainer:
	.string "Hiya! Are you maybe…\n"
	.string "A rookie Trainer?\p"
	.string "Do you know what Pokémon Trainers\n"
	.string "do when they reach a new town?\p"
	.string "They first check what kind of Gym\n"
	.string "is in the town.$"

PetalburgCity_Text_ThisIsPetalburgGym:
	.string "See? This is Petalburg City's Gym.$"

PetalburgCity_Text_ThisIsGymSign:
	.string "This is the Gym's sign. Look for it\n"
	.string "whenever you're looking for a Gym.$"

PetalburgCity_Text_WaterReflection:
	.string "My face is reflected in the water.\p"
	.string "It's a shining grin full of hope…\p"
	.string "Or it could be a look of somber silence\n"
	.string "struggling with fear…\p"
	.string "What do you see reflected in your face?$"

PetalburgCity_Text_FullPartyExplanation:
	.string "Let's say you have six Pokémon.\n"
	.string "If you catch another one…\p"
	.string "It is automatically sent to a Storage\n"
	.string "Box over a PC connection.$"

PetalburgCity_Text_GymSign:
	.string "Petalburg City Pokémon Gym\n"
	.string "Leader: Norman\l"
	.string "“A man in pursuit of power!”$"

PetalburgCity_Text_CitySign:
	.string "Petalburg City\n"
	.string "“Where people mingle with nature.”$"

PetalburgCity_Text_WallyHouseSign:
	.string "Wally's House$"

@PetalburgCity_Text_AreYouATrainer:
@	.string "Excuse me!\p"
@	.string "Let me guess, from the way you're\n"
@	.string "dressed, are you a Pokémon Trainer?$"

PetalburgCity_Text_AreYouATrainer:
	.string "Excuse me!\p"
	.string "I watched your battle, and you\n"
	.string "seems like a real Pokémon Trainer!$"

PetalburgCity_Text_WellMaybeNot:
	.string "… … … … … …\p"
	.string "Well, maybe not.\n"
	.string "Your clothes aren't all that dirty.\p"
	.string "You're either a rookie Trainer,\n"
	.string "or maybe you're just an ordinary kid.$"

PetalburgCity_Text_ImLookingForTalentedTrainers:
	.string "I'm roaming the land in search of\n"
	.string "talented Trainers.\p"
	.string "I'm sorry to have taken your time.$"

@ new code

PetalburgCity_Text_HeyPlayer:
	.string "Brendan & May: Hey, {PLAYER}!$"

PetalburgCity_Text_LetBattle:
	.string "Brendan & May: We saw you leaving\n"
	.string "the lab for a Pokémon adventure,\l"
	.string "and we were wondering how\l"
	.string "strong your Pokémon are!\p"
	.string "So let's test them!$"

PetalburgCity_Text_GoBattle:
	.string "Wally: You cannot let me out of\n"
	.string "this battle!$"

PetalburgCity_EventScript_DoubleBattle0::
	lockall
	addobject LOCALID_BRENDAN
	addobject LOCALID_MAY
	addobject LOCALID_SCOTT
	setobjectxy LOCALID_SCOTT, 13, 10
	setvar VAR_0x8008, 0
	setobjectxy LOCALID_BRENDAN, 13, 10
	setobjectxy LOCALID_MAY, 13, 11
	goto PetalburgCity_EventScript_DoubleBattle
	end

PetalburgCity_EventScript_DoubleBattle1::
	lockall
	addobject LOCALID_BRENDAN
	addobject LOCALID_MAY
	addobject LOCALID_SCOTT
	setobjectxy LOCALID_SCOTT, 13, 11
	setvar VAR_0x8008, 1
	setobjectxy LOCALID_BRENDAN, 13, 11
	setobjectxy LOCALID_MAY, 13, 12
	goto PetalburgCity_EventScript_DoubleBattle
	end

PetalburgCity_EventScript_DoubleBattle2::
	lockall
	addobject LOCALID_BRENDAN
	addobject LOCALID_MAY
	addobject LOCALID_SCOTT
	setobjectxy LOCALID_SCOTT, 13, 12
	setvar VAR_0x8008, 2
	setobjectxy LOCALID_BRENDAN, 13, 12
	setobjectxy LOCALID_MAY, 13, 13
	goto PetalburgCity_EventScript_DoubleBattle
	end

PetalburgCity_EventScript_DoubleBattle3::
	lockall
	addobject LOCALID_BRENDAN
	addobject LOCALID_MAY
	addobject LOCALID_SCOTT
	setobjectxy LOCALID_SCOTT, 13, 13
	setvar VAR_0x8008, 3
	setobjectxy LOCALID_BRENDAN, 13, 12
	setobjectxy LOCALID_MAY, 13, 13
	goto PetalburgCity_EventScript_DoubleBattle
	end

PetalburgCity_EventScript_DoubleBattle::
	applymovement LOCALID_BRENDAN, PetalburgCity_Movement_ScottStartWalkLeft
	applymovement LOCALID_MAY, PetalburgCity_Movement_ScottStartWalkLeft
	waitmovement 0
	playse SE_PIN
	applymovement LOCALID_BRENDAN, Common_Movement_ExclamationMark
	applymovement LOCALID_MAY, Common_Movement_ExclamationMark
	waitmovement 0
	msgbox PetalburgCity_Text_HeyPlayer, MSGBOX_AUTOCLOSE
	applymovement LOCALID_BRENDAN, Common_Movement_Delay48
	applymovement LOCALID_MAY, Common_Movement_Delay48
	waitmovement 0
	applymovement LOCALID_BRENDAN, PetalburgCity_Movement_ScottApproachPlayer
	applymovement LOCALID_MAY, PetalburgCity_Movement_ScottApproachPlayer
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFastestRight
	waitmovement 0
	msgbox PetalburgCity_Text_LetBattle, MSGBOX_AUTOCLOSE
	compare VAR_0x8008, 0
	call_if_eq PetalburgCity_EventScript_WallyEnter0
	compare VAR_0x8008, 1
	call_if_eq PetalburgCity_EventScript_WallyEnter1
	compare VAR_0x8008, 2
	call_if_eq PetalburgCity_EventScript_WallyEnter2
	compare VAR_0x8008, 3
	call_if_eq PetalburgCity_EventScript_WallyEnter3
	msgbox PetalburgCity_Text_GoBattle, MSGBOX_DEFAULT
	closemessage	
	multi_fixed_2_vs_2 TRAINER_BRENDAN_PETALBURG_CITY, BrendanDefeatText, TRAINER_MAY_PETALBURG_CITY, MayDefeatText, TRAINER_WALLY_PETALBURG_CITY, TRAINER_BACK_PIC_WALLY
	specialvar VAR_RESULT, GetBattleOutcome
    compare VAR_RESULT, B_OUTCOME_LOST
    goto_if_eq PetalburgCity_EventScript_EventScript_PlayerLostTheFight	
	applymovement LOCALID_BRENDAN, Common_Movement_FaceLeft
	applymovement LOCALID_MAY, Common_Movement_FaceLeft
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceRight
	waitmovement 0
	msgbox PetalburgCity_Text_PlayerWonBattle, MSGBOX_DEFAULT
	closemessage
	goto PetalburgCity_EventScript_EventScript_AfterBattle

PetalburgCity_EventScript_EventScript_PlayerLostTheFight::
	@fadescreen FADE_TO_BLACK
	@special SetCB2WhiteOut
	@waitstate
	applymovement LOCALID_BRENDAN, Common_Movement_FaceLeft
	applymovement LOCALID_MAY, Common_Movement_FaceLeft
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceRight
	waitmovement 0
	special HealPlayerParty
	msgbox PetalburgCity_Text_PlayerLostBattle, MSGBOX_DEFAULT
	closemessage
	goto PetalburgCity_EventScript_EventScript_AfterBattle

PetalburgCity_EventScript_EventScript_AfterBattle:
	compare VAR_0x8008, 0
	call_if_eq PetalburgCity_EventScript_GoesAway0
	compare VAR_0x8008, 1
	call_if_eq PetalburgCity_EventScript_GoesAway1
	compare VAR_0x8008, 2
	call_if_eq PetalburgCity_EventScript_GoesAway2
	compare VAR_0x8008, 3
	call_if_eq PetalburgCity_EventScript_GoesAway3
	setflag FLAG_HIDE_HOUSE_WALLY
	removeobject LOCALID_BRENDAN
	removeobject LOCALID_MAY
	removeobject LOCALID_BRENDAN_2
	removeobject LOCALID_MAY_2
	setflag FLAG_HIDE_BRENDAN_MAY_PETALBURG_CITY
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceUp
	waitmovement 0
	msgbox PetalburgCity_Text_BetterGoToo, MSGBOX_DEFAULT
	closemessage
	compare VAR_0x8008, 0
	call_if_eq PetalburgCity_EventScript_WallyLeaves0
	compare VAR_0x8008, 1
	call_if_eq PetalburgCity_EventScript_WallyLeaves1
	compare VAR_0x8008, 2
	call_if_eq PetalburgCity_EventScript_WallyLeaves2
	compare VAR_0x8008, 3
	call_if_eq PetalburgCity_EventScript_WallyLeaves3
	removeobject LOCALID_WALLY_2
	goto PetalburgCity_EventScript_Scott
	releaseall
	end

PetalburgCity_EventScript_WallyEnter0::
	addobject LOCALID_WALLY_2
	applymovement OBJ_EVENT_ID_PLAYER, PetalburgCity_Movement_Surprise
	applymovement LOCALID_BRENDAN, PetalburgCity_Movement_Surprise
	applymovement LOCALID_MAY, PetalburgCity_Movement_Surprise
	applymovement LOCALID_WALLY_2, PetalburgCity_Movement_WallyEntering0
	waitmovement 0
	return

PetalburgCity_EventScript_WallyEnter1::
	addobject LOCALID_WALLY_2
	applymovement OBJ_EVENT_ID_PLAYER, PetalburgCity_Movement_Surprise
	applymovement LOCALID_BRENDAN, PetalburgCity_Movement_Surprise
	applymovement LOCALID_MAY, PetalburgCity_Movement_Surprise
	applymovement LOCALID_WALLY_2, PetalburgCity_Movement_WallyEntering1
	waitmovement 0
	return

PetalburgCity_EventScript_WallyEnter2::
	addobject LOCALID_WALLY_2
	applymovement OBJ_EVENT_ID_PLAYER, PetalburgCity_Movement_Surprise
	applymovement LOCALID_BRENDAN, PetalburgCity_Movement_Surprise
	applymovement LOCALID_MAY, PetalburgCity_Movement_Surprise
	applymovement LOCALID_WALLY_2, PetalburgCity_Movement_WallyEntering2
	waitmovement 0
	return

PetalburgCity_EventScript_WallyEnter3::
	addobject LOCALID_WALLY_2
	applymovement OBJ_EVENT_ID_PLAYER, PetalburgCity_Movement_Surprise
	applymovement LOCALID_BRENDAN, PetalburgCity_Movement_Surprise
	applymovement LOCALID_MAY, PetalburgCity_Movement_Surprise
	applymovement LOCALID_WALLY_2, PetalburgCity_Movement_WallyEntering3
	waitmovement 0
	return

PetalburgCity_EventScript_GoesAway0::
	applymovement LOCALID_BRENDAN, PetalburgCity_Movement_PlayerWatchBrendanExit0
	applymovement LOCALID_MAY, PetalburgCity_Movement_PlayerWatchMayExit0
	waitmovement 0
	return

PetalburgCity_EventScript_GoesAway1::
	applymovement LOCALID_BRENDAN, PetalburgCity_Movement_PlayerWatchBrendanExit1
	applymovement LOCALID_MAY, PetalburgCity_Movement_PlayerWatchMayExit1
	waitmovement 0
	return

PetalburgCity_EventScript_GoesAway2::
	applymovement LOCALID_BRENDAN, PetalburgCity_Movement_PlayerWatchBrendanExit2
	applymovement LOCALID_MAY, PetalburgCity_Movement_PlayerWatchMayExit2
	waitmovement 0
	return

PetalburgCity_EventScript_GoesAway3::
	applymovement LOCALID_BRENDAN, PetalburgCity_Movement_PlayerWatchBrendanExit3
	applymovement LOCALID_MAY, PetalburgCity_Movement_PlayerWatchMayExit3
	waitmovement 0
	return

PetalburgCity_EventScript_WallyLeaves0::
	applymovement LOCALID_WALLY_2, PetalburgCity_Movement_WallyExit0
	waitmovement 0
	return

PetalburgCity_EventScript_WallyLeaves1::
	applymovement LOCALID_WALLY_2, PetalburgCity_Movement_WallyExit1
	waitmovement 0
	return

PetalburgCity_EventScript_WallyLeaves2::
	applymovement LOCALID_WALLY_2, PetalburgCity_Movement_WallyExit2
	waitmovement 0
	return

PetalburgCity_EventScript_WallyLeaves3::
	applymovement LOCALID_WALLY_2, PetalburgCity_Movement_WallyExit3
	waitmovement 0
	return

PetalburgCity_Movement_WallyExit0:
	walk_right
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

PetalburgCity_Movement_WallyExit1:
	walk_right
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

PetalburgCity_Movement_WallyExit2:
	walk_left
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

PetalburgCity_Movement_WallyExit3:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

PetalburgCity_Movement_PlayerWatchBrendanExit0:
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

PetalburgCity_Movement_PlayerWatchMayExit0:
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

PetalburgCity_Movement_PlayerWatchBrendanExit1:
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

PetalburgCity_Movement_PlayerWatchMayExit1:
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

PetalburgCity_Movement_PlayerWatchBrendanExit2:
	delay_16
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

PetalburgCity_Movement_PlayerWatchMayExit2:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

PetalburgCity_Movement_PlayerWatchBrendanExit3:
	walk_up
	walk_left
	walk_left
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

PetalburgCity_Movement_PlayerWatchMayExit3:
	delay_16
	walk_up
	walk_up
	walk_left
	walk_left
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

PetalburgCity_Movement_Surprise:
	emote_question_mark
	walk_in_place_fastest_up
	step_end

PetalburgCity_Movement_WallyEntering0:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_in_place_fastest_down
	step_end

PetalburgCity_Movement_WallyEntering1:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_in_place_fastest_down
	step_end

PetalburgCity_Movement_WallyEntering2:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_in_place_fastest_down
	step_end

PetalburgCity_Movement_WallyEntering3:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_down
	walk_in_place_fastest_down
	step_end

BrendanDefeatText:
	.string "Brendan: I disappointed\n"
	.string "my dad…$"

MayDefeatText:
	.string "May: Someday we will be\n"
	.string "the best trainers in Hoenn!$"

PetalburgCity_Text_PlayerLostBattle:
	.string "Brendan & May: Better train\n"
	.string "your Pokémon before battles!$"

PetalburgCity_Text_PlayerWonBattle:
	.string "Brendan & May: Your Pokémon\n"
	.string "are tough!$"

PetalburgCity_Text_BetterGoToo: 
	.string "Wally: That was a good fight!\n"
	.string "Your Pokémon are tough.\l"
	.string "I will train harder!$"

PetalburgCity_EventScript_Brendan::
	msgbox PetalburgCity_Text_Brendan, MSGBOX_NPC
	end

PetalburgCity_EventScript_May::
	msgbox PetalburgCity_Text_May, MSGBOX_NPC
	end

PetalburgCity_Text_Brendan: 
	.string "Brendan: I don't know how\n"
	.string "to swim to get that Zygarde Cell…$"

PetalburgCity_Text_May: 
	.string "May: I'm collecting some berries\n"
	.string "for our new adventure!$"

Common_EventScript_SchoolSign::
	msgbox Common_Text_SchoolSign, MSGBOX_SIGN
	end

Common_Text_SchoolSign:
	.string "Pokémon Trainer's School\p"
	.string "“We'll teach you anything about\n"
	.string "Pokémon!”$"
