.set LOCALID_GRUNT, 3
.set LOCALID_DEVON_EMPLOYEE, 4
.set LOCALID_PIKACHU_COSPLAY, 14

PetalburgWoods_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, PetalburgWoods_PikachuLocation_OnLoad
	map_script MAP_SCRIPT_ON_TRANSITION, PetalburgWoods_OnTransition
	.byte 0

PetalburgWoods_OnTransition:
	call PetalburgWoods_EventScript_TryHideOrShowSpiritombWisps
	end

PetalburgWoods_EventScript_TryHideOrShowSpiritombWisps:
	gettimeofday
	compare VAR_0x8000, 2
	goto_if_eq PetalburgWoods_EventScript_TryShowWisps
	goto PetalburgWoods_EventScript_HideWisps
	end

PetalburgWoods_EventScript_TryShowWisps:
	goto_if_unset FLAG_RECEIVED_WISPS_8, PetalburgWoods_EventScript_ShowWisp
	return

PetalburgWoods_EventScript_ShowWisp:
	clearflag FLAG_HIDE_WISPS_8
	return

PetalburgWoods_EventScript_HideWisps:
	setflag FLAG_HIDE_WISPS_8
	return

PetalburgWoods_EventScript_DevonResearcherLeft::
	lockall
	call PetalburgWoods_EventScript_DevonResearcherIntro
	applymovement LOCALID_DEVON_EMPLOYEE, PetalburgWoods_Movement_DevonResearcherApproachPlayerLeft
	waitmovement 0
	msgbox PetalburgWoods_Text_HaveYouSeenShroomish, MSGBOX_DEFAULT
	closemessage
	playbgm MUS_ENCOUNTER_AQUA, FALSE
	applymovement LOCALID_GRUNT, PetalburgWoods_Movement_AquaEntrance
	waitmovement 0
	msgbox PetalburgWoods_Text_IWasGoingToAmbushYou, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_GRUNT, PetalburgWoods_Movement_AquaApproachResearcherLeft
	waitmovement 0
	applymovement LOCALID_DEVON_EMPLOYEE, Common_Movement_WalkInPlaceFastestUp
	waitmovement 0
	msgbox PetalburgWoods_Text_HandOverThosePapers, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_DEVON_EMPLOYEE, PetalburgWoods_Movement_DevonResearcherFleeToPlayerLeft
	waitmovement 0
	msgbox PetalburgWoods_Text_YouHaveToHelpMe, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_GRUNT, PetalburgWoods_Movement_AquaApproachPlayer
	waitmovement 0
	msgbox PetalburgWoods_Text_NoOneCrossesTeamAqua, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_GRUNT_PETALBURG_WOODS, PetalburgWoods_Text_YoureKiddingMe
	call EventScript_RocketEdition_TryStealPokemon
	applymovement LOCALID_GRUNT, PetalburgWoods_Movement_AquaBackOff
	waitmovement 0
	call PetalburgWoods_EventScript_DevonResearcherPostBattle
	applymovement OBJ_EVENT_ID_PLAYER, PetalburgWoods_Movement_WatchResearcherLeave
	applymovement LOCALID_DEVON_EMPLOYEE, PetalburgWoods_Movement_DevonResearcherExitLeft
	waitmovement 0
	goto PetalburgWoods_EventScript_RemoveDevonResearcher
	end

PetalburgWoods_EventScript_DevonResearcherRight::
	lockall
	call PetalburgWoods_EventScript_DevonResearcherIntro
	applymovement LOCALID_DEVON_EMPLOYEE, PetalburgWoods_Movement_DevonResearcherApproachPlayerRight
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFastestLeft
	waitmovement 0
	msgbox PetalburgWoods_Text_HaveYouSeenShroomish, MSGBOX_DEFAULT
	closemessage
	playbgm MUS_ENCOUNTER_AQUA, FALSE
	applymovement LOCALID_GRUNT, PetalburgWoods_Movement_AquaEntrance
	waitmovement 0
	msgbox PetalburgWoods_Text_IWasGoingToAmbushYou, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_GRUNT, PetalburgWoods_Movement_AquaApproachResearcherRight
	waitmovement 0
	applymovement LOCALID_DEVON_EMPLOYEE, Common_Movement_WalkInPlaceFastestUp
	waitmovement 0
	msgbox PetalburgWoods_Text_HandOverThosePapers, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_DEVON_EMPLOYEE, PetalburgWoods_Movement_DevonResearcherFleeToPlayerRight
	waitmovement 0
	msgbox PetalburgWoods_Text_YouHaveToHelpMe, MSGBOX_DEFAULT
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFastestUp
	waitmovement 0
	msgbox PetalburgWoods_Text_NoOneCrossesTeamAqua, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_GRUNT_PETALBURG_WOODS, PetalburgWoods_Text_YoureKiddingMe
	call EventScript_RocketEdition_TryStealPokemon
	applymovement LOCALID_GRUNT, PetalburgWoods_Movement_AquaBackOff
	waitmovement 0
	call PetalburgWoods_EventScript_DevonResearcherPostBattle
	applymovement OBJ_EVENT_ID_PLAYER, PetalburgWoods_Movement_WatchResearcherLeave
	applymovement LOCALID_DEVON_EMPLOYEE, PetalburgWoods_Movement_DevonResearcherExitRight
	waitmovement 0
	goto PetalburgWoods_EventScript_RemoveDevonResearcher
	end

PetalburgWoods_EventScript_DevonResearcherIntro::
	applymovement LOCALID_DEVON_EMPLOYEE, PetalburgWoods_Movement_DevonResearcherLookAround
	waitmovement 0
	msgbox PetalburgWoods_Text_NotAOneToBeFound, MSGBOX_DEFAULT
	closemessage
	return

PetalburgWoods_EventScript_DevonResearcherPostBattle::
	msgbox PetalburgWoods_Text_YouveGotSomeNerve, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_GRUNT, PetalburgWoods_Movement_AquaRunAway
	waitmovement 0
	removeobject LOCALID_GRUNT
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFastestDown
	waitmovement 0
	msgbox PetalburgWoods_Text_ThatWasAwfullyClose, MSGBOX_DEFAULT
	@giveitem ITEM_GREAT_BALL
	giveitem ITEM_EXP_SHARE
	compare VAR_RESULT, FALSE
	goto_if_eq PetalburgWoods_EventScript_BagFull
	setflag FLAG_RECEIVED_EXP_SHARE
	setflag FLAG_SYS_EXP_SHARE
	msgbox PetalburgWoods_Text_Text_ExplainExpShare, MSGBOX_DEFAULT
	closemessage
	goto PetalburgWoods_EventScript_DevonResearcherFinish
	end

PetalburgWoods_EventScript_BagFull::
	msgbox PetalburgWoods_Text_YoureLoadedWithItems, MSGBOX_DEFAULT
	goto PetalburgWoods_EventScript_DevonResearcherFinish
	end

PetalburgWoods_EventScript_DevonResearcherFinish::
	msgbox PetalburgWoods_Text_TeamAquaAfterSomethingInRustboro, MSGBOX_DEFAULT
	applymovement LOCALID_DEVON_EMPLOYEE, PetalburgWoods_Movement_DevonResearcherStartExit
	waitmovement 0
	msgbox PetalburgWoods_Text_ICantBeWastingTime, MSGBOX_DEFAULT
	closemessage
	return

PetalburgWoods_EventScript_RemoveDevonResearcher::
	removeobject LOCALID_DEVON_EMPLOYEE
	setvar VAR_PETALBURG_WOODS_STATE, 1
	releaseall
	end

PetalburgWoods_Movement_DevonResearcherLookAround:
	face_up
	delay_16
	delay_4
	face_right
	delay_16
	delay_8
	face_left
	delay_16
	delay_8
	face_down
	delay_16
	face_right
	delay_16
	delay_8
	face_up
	delay_16
	step_end

PetalburgWoods_Movement_DevonResearcherExitLeft:
	walk_fast_right
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	step_end

PetalburgWoods_Movement_DevonResearcherApproachPlayerLeft:
	delay_16
	face_player
	walk_down
	walk_down
	step_end

PetalburgWoods_Movement_DevonResearcherApproachPlayerRight:
	delay_16
	face_player
	walk_down
	walk_down
	walk_down
	walk_in_place_fastest_right
	step_end

PetalburgWoods_Movement_DevonResearcherExitRight:
	walk_fast_left
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	step_end

PetalburgWoods_Movement_WatchResearcherLeave:
	delay_16
	delay_16
	walk_in_place_fastest_up
	step_end

PetalburgWoods_Movement_DevonResearcherFleeToPlayerLeft:
	walk_fast_right
	walk_fast_down
	walk_fast_down
	walk_fast_left
	walk_in_place_fastest_up
	step_end

PetalburgWoods_Movement_DevonResearcherFleeToPlayerRight:
	walk_fast_down
	walk_fast_right
	walk_in_place_fastest_up
	step_end

PetalburgWoods_Movement_DevonResearcherStartExit:
	walk_in_place_fastest_down
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	face_up
	step_end

PetalburgWoods_Movement_AquaApproachResearcherLeft:
	walk_fast_down
	walk_fast_down
	step_end

PetalburgWoods_Movement_AquaBackOff:
	lock_facing_direction
	walk_up
	unlock_facing_direction
	step_end

PetalburgWoods_Movement_AquaRunAway:
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	delay_16
	delay_16
	step_end

PetalburgWoods_Movement_AquaApproachResearcherRight:
	walk_fast_down
	walk_fast_down
	walk_fast_down
	step_end

PetalburgWoods_Movement_AquaEntrance:
	walk_down
	walk_down
	delay_16
	delay_16
	step_end

PetalburgWoods_Movement_AquaApproachPlayer:
	walk_down
	step_end

PetalburgWoods_EventScript_Boy1::
	msgbox PetalburgWoods_Text_StayOutOfTallGrass, MSGBOX_NPC
	end

PetalburgWoods_EventScript_Boy2::
	msgbox PetalburgWoods_Text_HiddenItemsExplanation, MSGBOX_NPC
	end

PetalburgWoods_EventScript_Girl::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_MIRACLE_SEED, PetalburgWoods_EventScript_ExplainMiracleSeed
	msgbox PetalburgWoods_Text_TryUsingThisItem, MSGBOX_DEFAULT
	giveitem ITEM_MIRACLE_SEED
	compare VAR_RESULT, FALSE
	goto_if_eq Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_MIRACLE_SEED
	release
	end

PetalburgWoods_EventScript_ExplainMiracleSeed::
	msgbox PetalburgWoods_Text_MiracleSeedExplanation, MSGBOX_DEFAULT
	release
	end

PetalburgWoods_EventScript_Sign1::
	msgbox PetalburgWoods_Text_TrainerTipsExperience, MSGBOX_SIGN
	end

PetalburgWoods_EventScript_Sign2::
	msgbox PetalburgWoods_Text_TrainerTipsPP, MSGBOX_SIGN
	end

PetalburgWoods_EventScript_Lyle::
	trainerbattle_single TRAINER_LYLE, PetalburgWoods_Text_GoBugPokemonTeam, PetalburgWoods_Text_ICouldntWin, EventScript_RocketEdition_TryStealPokemon
	msgbox PetalburgWoods_Text_ImOutOfPokeBalls, MSGBOX_AUTOCLOSE
	end

PetalburgWoods_EventScript_James::
	trainerbattle_single TRAINER_JAMES_1, PetalburgWoods_Text_InstantlyPopularWithBugPokemon, PetalburgWoods_Text_CantBePopularIfILose, PetalburgWoods_EventScript_TryRegisterJames
	specialvar VAR_RESULT, ShouldTryRematchBattle
	compare VAR_RESULT, TRUE
	goto_if_eq PetalburgWoods_EventScript_JamesRematch
	setvar VAR_0x8004, TRAINER_JAMES_1
	specialvar VAR_RESULT, IsTrainerRegistered
	compare VAR_RESULT, FALSE
	goto_if_eq PetalburgWoods_EventScript_TryRegisterJames2
	msgbox PetalburgWoods_Text_PeopleRespectYou, MSGBOX_DEFAULT
	release
	end

PetalburgWoods_EventScript_TryRegisterJames::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	goto_if_set FLAG_HAS_MATCH_CALL, PetalburgWoods_EventScript_RegisterJames
	call EventScript_RocketEdition_TryStealPokemon
	release
	end

PetalburgWoods_EventScript_RegisterJames::
	msgbox PetalburgWoods_Text_IWantRematch1, MSGBOX_DEFAULT
	register_matchcall TRAINER_JAMES_1
	call EventScript_RocketEdition_TryStealPokemon
	release
	end

PetalburgWoods_EventScript_TryRegisterJames2::
	goto_if_set FLAG_HAS_MATCH_CALL, PetalburgWoods_EventScript_RegisterJames2
	msgbox PetalburgWoods_Text_PeopleRespectYou, MSGBOX_DEFAULT
	release
	end

PetalburgWoods_EventScript_RegisterJames2::
	msgbox PetalburgWoods_Text_IWantRematch2, MSGBOX_DEFAULT
	register_matchcall TRAINER_JAMES_1
	release
	end

PetalburgWoods_EventScript_JamesRematch::
	trainerbattle_rematch TRAINER_JAMES_1, PetalburgWoods_Text_MyPokemonHaveGrown, PetalburgWoods_Text_CantBePopularIfLose
	msgbox PetalburgWoods_Text_IveBeenTrainingHard, MSGBOX_AUTOCLOSE
	end

PetalburgWoods_Text_NotAOneToBeFound:
	.string "Hmmm…\n"
	.string "Not a one to be found…$"

PetalburgWoods_Text_HaveYouSeenShroomish:
	.string "Hello, have you seen any Pokémon\n"
	.string "called Pineco around here?\p"
	.string "I really love that Pokémon.$"

PetalburgWoods_Text_IWasGoingToAmbushYou:
	.string "I was going to ambush you, but you\n"
	.string "had to dawdle in Petalburg Woods\l"
	.string "forever, didn't you?\p"
	.string "I got sick of waiting, so here I am!$"

PetalburgWoods_Text_HandOverThosePapers:
	.string "You! Devon Researcher!\p"
	.string "Hand over those papers!$"

PetalburgWoods_Text_YouHaveToHelpMe:
	.string "Aiyeeeh!\p"
	.string "You're a Pokémon Trainer, aren't you?\n"
	.string "You've got to help me, please!$"

PetalburgWoods_Text_NoOneCrossesTeamAqua:
	.string "Hunh? What do you think you're doing?\n"
	.string "What, you're going to protect him?\p"
	.string "No one who crosses Team Aqua\n"
	.string "gets any mercy, not even a kid!\p"
	.string "Come on and battle me!$"

PetalburgWoods_Text_YoureKiddingMe:
	.string "You're kidding me! You're tough!$"

PetalburgWoods_Text_YouveGotSomeNerve:
	.string "Grrr… You've got some nerve\n"
	.string "meddling with Team Aqua!\l"
	.string "Come on and battle me again!\p"
	.string "I wish I could say that, but I'm out of\n"
	.string "Pokémon…\p"
	.string "And, hey, we of Team Aqua are also\n"
	.string "after something in Rustboro.\p"
	.string "I'll let you go today!$"

PetalburgWoods_Text_ThatWasAwfullyClose:
	.string "Whew…\n"
	.string "That was awfully close!\p"
	.string "Thanks to you, he didn't rob me of\n"
	.string "these important papers.\p"
	.string "I know, I'll give you a Exp. Share as\n"
	.string "my thanks!\p"
	.string "It should help you, a Trainer.$"

PetalburgWoods_Text_TeamAquaAfterSomethingInRustboro:
	.string "Didn't that Team Aqua thug say\n"
	.string "they were after something in\l"
	.string "Rustboro, too?$"

PetalburgWoods_Text_ICantBeWastingTime:
	.string "Uh-oh! It's a crisis!\n"
	.string "I can't be wasting time!$"

PetalburgWoods_Text_YoureLoadedWithItems:
	.string "You're loaded with items.\n"
	.string "I can't give you this GREAT Ball.$"

PetalburgWoods_Text_GoBugPokemonTeam:
	.string "I caught a whole bunch of Pokémon!\p"
	.string "Go, go, go!\n"
	.string "My Bug Pokémon team!$"

PetalburgWoods_Text_ICouldntWin:
	.string "I have all these Pokémon,\n"
	.string "but I couldn't win…$"

PetalburgWoods_Text_ImOutOfPokeBalls:
	.string "I caught a bunch of Pokémon.\n"
	.string "Now I'm out of Poké Balls.$"

PetalburgWoods_Text_InstantlyPopularWithBugPokemon:
	.string "If you take Bug Pokémon to school,\n"
	.string "you get to be instantly popular!$"

PetalburgWoods_Text_CantBePopularIfILose:
	.string "I can't be popular if I lose.$"

PetalburgWoods_Text_PeopleRespectYou:
	.string "If you have a big Bug Pokémon,\n"
	.string "people respect you for it.$"

PetalburgWoods_Text_IWantRematch1:
	.string "I want a rematch when my Bug\n"
	.string "Pokémon grow up!\p"
	.string "I'm registering you in my Pokénav!$"

PetalburgWoods_Text_IWantRematch2:
	.string "I want a rematch when my Bug \n"
	.string "Pokémon grow up!\p"
	.string "I'm registering you in my Pokénav!$"

PetalburgWoods_Text_MyPokemonHaveGrown:
	.string "My Bug Pokémon have grown.\n"
	.string "I'll be popular again.$"

PetalburgWoods_Text_CantBePopularIfLose:
	.string "I can't be popular if I lose.$"

PetalburgWoods_Text_IveBeenTrainingHard:
	.string "You get to be popular if you have\n"
	.string "strong Pokémon, right?\l"
	.string "So, I've been training hard.$"

PetalburgWoods_Text_StayOutOfTallGrass:
	.string "Yo, there!\n"
	.string "Your Pokémon doing okay?\p"
	.string "If your Pokémon are weak and you want\n"
	.string "to avoid battles, you should stay out\l"
	.string "of tall grass.$"

PetalburgWoods_Text_HiddenItemsExplanation:
	.string "Sometimes, there are things on the\n"
	.string "ground even if you can't see them.\p"
	.string "That's why I always check where I'm\n"
	.string "walking.$"

PetalburgWoods_Text_TryUsingThisItem:
	.string "Oh, neat!\p"
	.string "You must be a Trainer.\n"
	.string "You should try using this item.$"

PetalburgWoods_Text_MiracleSeedExplanation:
	.string "It's a Miracle Seed.\n"
	.string "If a Pokémon holds that item, its\l"
	.string "Grass-type moves become stronger.\p"
	.string "Besides Miracle Seed, I think there are\n"
	.string "other convenient items for Pokémon\l"
	.string "to hold.$"

PetalburgWoods_Text_TrainerTipsExperience:
	.string "Trainer Tips\p"
	.string "Any Pokémon that appears even once\n"
	.string "in a battle is awarded Exp Points.\p"
	.string "To raise a weak Pokémon, put it at the\n"
	.string "left of the team list.\p"
	.string "As soon as a battle starts, switch it\n"
	.string "out. It will earn Exp Points without\l"
	.string "being exposed to any harm.$"

PetalburgWoods_Text_TrainerTipsPP:
	.string "Trainer Tips\p"
	.string "In addition to Hit Points (HP), Pokémon\n"
	.string "have Power Points (PP) that are used to\l"
	.string "make moves during battle.\p"
	.string "If a Pokémon runs out of PP, it must be\n"
	.string "taken to a Pokémon Center.$"

@@@@@@@@@@@@@@@@
@@ NEW CODE
@@@@@@@@@@@@@@@@

PetalburgWoods_PikachuLocation_OnLoad::
    switch VAR_PETALBURG_WOODS_PIKACHU_COSPLAY
    case 1, PikachuSetLocation1
    case 2, PikachuSetLocation2
    case 3, PikachuSetLocation3
    case 4, PikachuSetLocation4
    case 5, PikachuSetLocation5
    case 6, PikachuSetLocation6
    case 7, PikachuSetLocation7
	end

PikachuSetLocation1::
    setobjectxyperm LOCALID_PIKACHU_COSPLAY, 40, 35
	end

PikachuSetLocation2::
    setobjectxyperm LOCALID_PIKACHU_COSPLAY, 7, 28
	end

PikachuSetLocation3::
    setobjectxyperm LOCALID_PIKACHU_COSPLAY, 5, 18
	end

PikachuSetLocation4::
    setobjectxyperm LOCALID_PIKACHU_COSPLAY, 26, 6
	end

PikachuSetLocation5::
    setobjectxyperm LOCALID_PIKACHU_COSPLAY, 42, 26
	end

PikachuSetLocation6::
    setobjectxyperm LOCALID_PIKACHU_COSPLAY, 38, 44
	end

PikachuSetLocation7::
    setobjectxyperm LOCALID_PIKACHU_COSPLAY, 49, 59
	end

EventScript_PikachuCosplay::
    lock    
	faceplayer
    switch VAR_PETALBURG_WOODS_PIKACHU_COSPLAY
    case 0, PikachuMove1
    case 1, PikachuMove2
    case 2, PikachuMove3
    case 3, PikachuMove4
    case 4, PikachuMove5
    case 5, PikachuMove6
    case 6, PikachuMove7
    waitse
    playmoncry SPECIES_PICHU_SPIKY_EARED, 0 
    waitmoncry
    msgbox Pikachu_Battle, MSGBOX_DEFAULT
	setwildbattle SPECIES_PICHU_SPIKY_EARED, 12, ITEM_NONE
	dowildbattle
	compare VAR_RESULT, B_OUTCOME_CAUGHT
	call_if_eq EventScript_PokemonGotCaptured
    setflag FLAG_PIKACHU_COSPLAY_PETALBURG_WOODS
    setvar VAR_PETALBURG_WOODS_PIKACHU_COSPLAY, 8
    removeobject LOCALID_PIKACHU_COSPLAY
    release
    end

EventScript_PokemonGotCaptured:
	setflag FLAG_CAPTURED_PETALWOOD_GALARIAN_FARFETCH
	return

PikachuMove1:  
    delay B_WAIT_TIME_SHORT
    fadescreen FADE_TO_BLACK
    removeobject LOCALID_PIKACHU_COSPLAY 
    setobjectxyperm LOCALID_PIKACHU_COSPLAY, 40, 35
    msgbox Pikachu_fled, MSGBOX_AUTOCLOSE
    setvar VAR_PETALBURG_WOODS_PIKACHU_COSPLAY, 1 
    fadescreen FADE_FROM_BLACK
    addobject LOCALID_PIKACHU_COSPLAY
    clearflag FLAG_PIKACHU_COSPLAY_PETALBURG_WOODS
    release
    end

PikachuMove2: 
    delay B_WAIT_TIME_SHORT
    fadescreen FADE_TO_BLACK
    removeobject LOCALID_PIKACHU_COSPLAY 
    setobjectxyperm LOCALID_PIKACHU_COSPLAY, 7, 28
    msgbox Pikachu_fled, MSGBOX_AUTOCLOSE
    setvar VAR_PETALBURG_WOODS_PIKACHU_COSPLAY, 2
    fadescreen FADE_FROM_BLACK
    addobject LOCALID_PIKACHU_COSPLAY
    clearflag FLAG_PIKACHU_COSPLAY_PETALBURG_WOODS
    release
    end

PikachuMove3:  
    delay B_WAIT_TIME_SHORT
    fadescreen FADE_TO_BLACK
    removeobject LOCALID_PIKACHU_COSPLAY 
    setobjectxyperm LOCALID_PIKACHU_COSPLAY, 5, 18
    msgbox Pikachu_fled, MSGBOX_AUTOCLOSE
    setvar VAR_PETALBURG_WOODS_PIKACHU_COSPLAY, 3
    fadescreen FADE_FROM_BLACK
    clearflag FLAG_PIKACHU_COSPLAY_PETALBURG_WOODS
    addobject LOCALID_PIKACHU_COSPLAY
    clearflag FLAG_PIKACHU_COSPLAY_PETALBURG_WOODS
    release
    end

PikachuMove4:   
    delay B_WAIT_TIME_SHORT
    fadescreen FADE_TO_BLACK
    removeobject LOCALID_PIKACHU_COSPLAY 
    setobjectxyperm LOCALID_PIKACHU_COSPLAY, 26, 8
    msgbox Pikachu_fled, MSGBOX_AUTOCLOSE
    setvar VAR_PETALBURG_WOODS_PIKACHU_COSPLAY, 4
    fadescreen FADE_FROM_BLACK
    clearflag FLAG_PIKACHU_COSPLAY_PETALBURG_WOODS
    addobject LOCALID_PIKACHU_COSPLAY
    clearflag FLAG_PIKACHU_COSPLAY_PETALBURG_WOODS
    release
    end

PikachuMove5:   
    delay B_WAIT_TIME_SHORT
    fadescreen FADE_TO_BLACK
    removeobject LOCALID_PIKACHU_COSPLAY 
    setobjectxyperm LOCALID_PIKACHU_COSPLAY, 42, 26
    msgbox Pikachu_fled, MSGBOX_AUTOCLOSE
    setvar VAR_PETALBURG_WOODS_PIKACHU_COSPLAY, 5
    fadescreen FADE_FROM_BLACK
    clearflag FLAG_PIKACHU_COSPLAY_PETALBURG_WOODS
    addobject LOCALID_PIKACHU_COSPLAY
    clearflag FLAG_PIKACHU_COSPLAY_PETALBURG_WOODS
    release
    end

PikachuMove6:   
    delay B_WAIT_TIME_SHORT
    fadescreen FADE_TO_BLACK
    removeobject LOCALID_PIKACHU_COSPLAY 
    setobjectxyperm LOCALID_PIKACHU_COSPLAY, 37, 45
    msgbox Pikachu_fled, MSGBOX_AUTOCLOSE
    setvar VAR_PETALBURG_WOODS_PIKACHU_COSPLAY, 6
    fadescreen FADE_FROM_BLACK
    clearflag FLAG_PIKACHU_COSPLAY_PETALBURG_WOODS
    addobject LOCALID_PIKACHU_COSPLAY
    clearflag FLAG_PIKACHU_COSPLAY_PETALBURG_WOODS
    release
    end

PikachuMove7:     
    delay B_WAIT_TIME_SHORT
    fadescreen FADE_TO_BLACK
    removeobject LOCALID_PIKACHU_COSPLAY 
    setobjectxyperm LOCALID_PIKACHU_COSPLAY, 14, 7
    msgbox Pikachu_fled, MSGBOX_AUTOCLOSE
    setvar VAR_PETALBURG_WOODS_PIKACHU_COSPLAY, 7
    fadescreen FADE_FROM_BLACK
    clearflag FLAG_PIKACHU_COSPLAY_PETALBURG_WOODS
    addobject LOCALID_PIKACHU_COSPLAY
    clearflag FLAG_PIKACHU_COSPLAY_PETALBURG_WOODS
    release
    end

Pikachu_fled:
	.string "The Pokémon fled!$"

Pikachu_Battle:
	.string "Pichu-pi!$"

PetalburgWoods_Text_Text_ExplainExpShare:
	.string "Exp. Share allows you to\n"
	.string "share the battle experience with all\l"
	.string "your Pokémon in your party.\p"
	.string "It will get Exp Points even if it didn't\n"
	.string "actually battle.\p"
	.string "I would say Exp. Share is quite useful\n"
	.string "for raising weak Pokémon.\p"
	.string "You can turn off the Exp. Share from\n"
	.string "your bag.$"

@NEW CODE

@NEW CODE

PetalburgWoods_EventScript_ItemTM53::
	finditem ITEM_TM53_BUG_BUZZ
	end

PetalburgWoods_EventScript_HeadbuttTMgiver::
	goto_if_unset FLAG_RECEIVED_TM66_HEADBUTT, PetalburgWoods_EventScript_HeadbuttTM
	msgbox PetalburgWoods_Text_HeadbuttExplain, MSGBOX_NPC
	end

PetalburgWoods_EventScript_HeadbuttTM::
	lock
	faceplayer
	msgbox PetalburgWoods_Text_Headbutt, MSGBOX_DEFAULT
	waitmessage
	giveitem ITEM_TM66_HEADBUTT
	compare VAR_RESULT, FALSE
	goto_if_eq Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_TM66_HEADBUTT
	msgbox PetalburgWoods_Text_HeadbuttExplain, MSGBOX_DEFAULT
	waitmessage
	release
	end

PetalburgWoods_Text_Headbutt::
	.string "What am I doing?\p"
	.string "I'm shaking trees using Headbutt.\p"
	.string "It's fun. Here, you try it\n"
	.string "with your Pokémon, too!$"

PetalburgWoods_Text_HeadbuttExplain::
	.string "Rattle trees with Headbutt. Sometimes,\n"
	.string "sleeping Pokémon fall out.$"

