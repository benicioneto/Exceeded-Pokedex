.set LOCALID_GRUNT_1, 1
.set LOCALID_GRUNT_2, 6
.set LOCALID_RIVAL, 13

Route112_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route112_OnTransition
	.byte 0

Route112_OnTransition:
	clearflag FLAG_FORCE_MIRAGE_TOWER_VISIBLE
	setvar VAR_JAGGED_PASS_ASH_WEATHER, 0
	call Common_EventScript_SetupRivalGfxId
	end

Route112_EventScript_MagmaGrunts::
	lockall
	delay 40
	applymovement LOCALID_GRUNT_1, Common_Movement_WalkInPlaceFastestRight
	waitmovement 0
	delay 20
	msgbox Route112_Text_LeaderGoingToAwakenThing, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_GRUNT_1, Common_Movement_FaceOriginalDirection
	waitmovement 0
	delay 40
	applymovement LOCALID_GRUNT_2, Common_Movement_WalkInPlaceFastestLeft
	waitmovement 0
	delay 20
	msgbox Route112_Text_YeahWeNeedMeteorite, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_GRUNT_2, Common_Movement_FaceOriginalDirection
	waitmovement 0
	delay 40
	applymovement LOCALID_GRUNT_1, Common_Movement_WalkInPlaceFastestRight
	waitmovement 0
	delay 20
	msgbox Route112_Text_OhThatsWhyCrewWentToFallarbor, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_GRUNT_1, Common_Movement_FaceOriginalDirection
	waitmovement 0
	delay 40
	applymovement LOCALID_GRUNT_2, Common_Movement_WalkInPlaceFastestLeft
	waitmovement 0
	delay 20
	msgbox Route112_Text_CantLetAnyonePassUntilTheyreBack, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_GRUNT_2, Common_Movement_FaceOriginalDirection
	waitmovement 0
	releaseall
	end

Route112_EventScript_MtChimneyCableCarSign::
	msgbox Route112_Text_MtChimneyCableCarSign, MSGBOX_SIGN
	end

Route112_EventScript_MtChimneySign::
	msgbox Route112_Text_MtChimneySign, MSGBOX_SIGN
	end

Route112_EventScript_RouteSignLavaridge::
	msgbox Route112_Text_RouteSignLavaridge, MSGBOX_SIGN
	end

Route112_EventScript_Hiker::
	msgbox Route112_Text_NotEasyToGetBackToLavaridge, MSGBOX_NPC
	end

Route112_EventScript_Brice::
	trainerbattle_single TRAINER_BRICE, Route112_Text_BriceIntro, Route112_Text_BriceDefeat, EventScript_RocketEdition_TryStealPokemon
	msgbox Route112_Text_BricePostBattle, MSGBOX_AUTOCLOSE
	end

Route112_EventScript_Trent::
	trainerbattle_single TRAINER_TRENT_1, Route112_Text_TrentIntro, Route112_Text_TrentDefeat, Route112_EventScript_RegisterTrent
	specialvar VAR_RESULT, ShouldTryRematchBattle
	compare VAR_RESULT, TRUE
	goto_if_eq Route112_EventScript_RematchTrent
	msgbox Route112_Text_TrentPostBattle, MSGBOX_DEFAULT
	release
	end

Route112_EventScript_RegisterTrent::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route112_Text_TrentRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_TRENT_1
	call EventScript_RocketEdition_TryStealPokemon
	release
	end

Route112_EventScript_RematchTrent::
	trainerbattle_rematch TRAINER_TRENT_1, Route112_Text_TrentRematchIntro, Route112_Text_TrentRematchDefeat
	msgbox Route112_Text_TrentRematchPostBattle, MSGBOX_AUTOCLOSE
	end

Route112_EventScript_Larry::
	trainerbattle_single TRAINER_LARRY, Route112_Text_LarryIntro, Route112_Text_LarryDefeat, EventScript_RocketEdition_TryStealPokemon
	msgbox Route112_Text_LarryPostBattle, MSGBOX_AUTOCLOSE
	end

Route112_EventScript_Carol::
	trainerbattle_single TRAINER_CAROL, Route112_Text_CarolIntro, Route112_Text_CarolDefeat, EventScript_RocketEdition_TryStealPokemon
	msgbox Route112_Text_CarolPostBattle, MSGBOX_AUTOCLOSE
	end

Route112_EventScript_Bryant::
	trainerbattle_single TRAINER_BRYANT, Route112_Text_BryantIntro, Route112_Text_BryantDefeat, EventScript_RocketEdition_TryStealPokemon
	msgbox Route112_Text_BryantPostBattle, MSGBOX_AUTOCLOSE
	end

Route112_EventScript_Shayla::
	trainerbattle_single TRAINER_SHAYLA, Route112_Text_ShaylaIntro, Route112_Text_ShaylaDefeat, EventScript_RocketEdition_TryStealPokemon
	msgbox Route112_Text_ShaylaPostBattle, MSGBOX_AUTOCLOSE
	end

Route112_Text_LeaderGoingToAwakenThing:
	.string "Hey, man, is our leader really going\n"
	.string "to awaken that thing?$"

Route112_Text_YeahWeNeedMeteorite:
	.string "Sounds like it, yeah. But I heard\n"
	.string "we need a Meteorite to do it.$"

Route112_Text_OhThatsWhyCrewWentToFallarbor:
	.string "Oh, I get it now. That's why the rest\n"
	.string "of the crew went out to Fallarbor.$"

Route112_Text_CantLetAnyonePassUntilTheyreBack:
	.string "You got it. And until they come back,\n"
	.string "we're not to let anyone pass, right.$"

Route112_Text_NotEasyToGetBackToLavaridge:
	.string "Eh, I'd like to get to Mauville, but if\n"
	.string "I went down these ledges, it'd be no\l"
	.string "easy matter to get back to Lavaridge.$"

Route112_Text_MtChimneyCableCarSign:
	.string "Mt. Chimney Cable Car\n"
	.string "“A short walk {UP_ARROW} way!”$"

Route112_Text_MtChimneySign:
	.string "Mt. Chimney\p"
	.string "“For Lavaridge Town or the summit,\n"
	.string "please take the Cable Car.”$"

Route112_Text_RouteSignLavaridge:
	.string "Route 112\n"
	.string "{LEFT_ARROW} Lavaridge Town$"

@NEW CODE

Route112_EventScript_RivalEncounter0::
	lockall
	setobjectxy LOCALID_RIVAL, 31, 46
	setvar VAR_0x8008, 0
	goto Route112_EventScript_RivalEncounter
	end

Route112_EventScript_RivalEncounter1::
	lockall
	setobjectxy LOCALID_RIVAL, 31, 47
	setvar VAR_0x8008, 1
	goto Route112_EventScript_RivalEncounter
	end

Route112_EventScript_RivalEncounter2::
	lockall
	setobjectxy LOCALID_RIVAL, 31, 48
	setvar VAR_0x8008, 2
	goto Route112_EventScript_RivalEncounter
	end

Route112_EventScript_RivalEncounter3::
	lockall
	setobjectxy LOCALID_RIVAL, 31, 49
	setvar VAR_0x8008, 3
	goto Route112_EventScript_RivalEncounter
	end

Route112_EventScript_RivalEncounter4::
	lockall
	setobjectxy LOCALID_RIVAL, 31, 50
	setvar VAR_0x8008, 4
	goto Route112_EventScript_RivalEncounter
	end

Route112_EventScript_RivalEncounter5::
	lockall
	setobjectxy LOCALID_RIVAL, 31, 51
	setvar VAR_0x8008, 5
	goto Route112_EventScript_RivalEncounter
	end

Route112_EventScript_RivalEncounter:
	applymovement LOCALID_RIVAL, PetalburgCity_Movement_RivalStartWalkRight
	waitmovement 0
	playse SE_PIN
	applymovement LOCALID_RIVAL, Common_Movement_ExclamationMark
	waitmovement 0
	msgbox Route112_Text_Ah, MSGBOX_DEFAULT
	applymovement LOCALID_RIVAL, Common_Movement_Delay48
	waitmovement 0
	applymovement LOCALID_RIVAL, Route112_Movement_RivalApproachPlayer
	waitmovement 0
	msgbox Route112_Text_RivalTalks, MSGBOX_DEFAULT
	applymovement LOCALID_RIVAL, Common_Movement_WalkInPlaceFastestLeft
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFastestLeft
	waitmovement 0
	delay 20
	msgbox Route112_Text_RivalTalksAboutMt, MSGBOX_DEFAULT
	applymovement LOCALID_RIVAL, Common_Movement_WalkInPlaceFastestRight
	waitmovement 0
	msgbox Route112_Text_RivalTalksAboutMt2, MSGBOX_DEFAULT
	playfanfare MUS_HEAL
	waitfanfare
    special HealPlayerParty
	delay 20
	msgbox Route112_Text_RivalTakesThis, MSGBOX_DEFAULT
	giveitem ITEM_HM04_STRENGTH
	setflag FLAG_RECEIVED_HM04	
	msgbox Route112_Text_RivalStrentgh, MSGBOX_AUTOCLOSE
	applymovement LOCALID_RIVAL, Route112_Movement_RivalLeaves
	waitmovement 0
	removeobject LOCALID_RIVAL
	setflag FLAG_HIDE_ROUTE_112_RIVAL
	setvar VAR_RIVAL_ROUTE112_ENCOUNTER, 1
	releaseall
	end

PetalburgCity_Movement_RivalStartWalkRight:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

Route112_Movement_RivalApproachPlayer:
	walk_right
	walk_right
	step_end

Route112_Movement_RivalLeaves:
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
	walk_left
	step_end

Route112_Text_Ah:
	.string "Ah!$"

Route112_Text_RivalTalks:
	.string "{PLAYER}!\p"
	.string "Look! Right up there!\n"
	.string "That's Mt. Chimney!$"

Route112_Text_RivalTalksAboutMt:
	.string "It sure is big…\p"
	.string "No, more like huge…\p"
	.string "It totally takes my breath away!\n"
	.string "I'd love to take the Cable Car all\l"
	.string "the way up to the top someday…$"

Route112_Text_RivalTalksAboutMt2:
	.string "Hm? Hey, {PLAYER}, don't your Pokémon\n"
	.string "seem a bit ragged around the edges?\l"
	.string "Here, let me give them a little boost!$"

Route112_Text_RivalTakesThis:
	.string "Here! Take this, too!$"

Route112_Text_RivalStrentgh:
	.string "I bet you can find all kinds of ways\n"
	.string "to use it in the mountains\l"
	.string "that lie ahead!\p"
	.string "But it won't work outside of\n"
	.string "battle if you don't have the\l"
	.string "Badge from Lavaridge Gym.\p"
	.string "Well I should head off and do\n"
	.string "some field research. We'll\l"
	.string "definitely have a battle next time!$"
