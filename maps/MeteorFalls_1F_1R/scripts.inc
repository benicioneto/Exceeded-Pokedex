.set LOCALID_RIVAL, 11
.set LOCALID_MARS, 7
.set LOCALID_GRUNT_1, 5
.set LOCALID_GRUNT_2, 6
.set LOCALID_DEOXYS, 8
.set LOCALID_BLACK_TRIANGLE, 10
.set LOCALID_JESSIE, 11
.set LOCALID_JAMES, 12
.set LOCALID_MEOWTH, 13
.set LOCALID_SATURN, 15
.set LOCALID_ULTRA_WORMHOLE, 16
.set LOCALID_COSMOG, 17

MeteorFalls_1F_1R_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, MeteorFalls_1F_1R_OnLoad
	map_script MAP_SCRIPT_ON_TRANSITION, MeteorFalls_1F_1R_OnTransition
	.byte 0

MeteorFalls_1F_1R_OnLoad:
	call_if_set FLAG_SYS_GAME_CLEAR, MeteorFalls_1F_1R_EventScript_OpenStevensCave
	compare VAR_TEAM_GALACTIC_STATE, 4
	call_if_ge MeteorFalls_1F_1R_EventScript_RemovesMachine
	end

MeteorFalls_1F_1R_OnTransition:
	call Common_EventScript_SetupRivalGfxId
	end

MeteorFalls_1F_1R_EventScript_OpenStevensCave::
	setmetatile 4, 1, METATILE_MeteorFalls_CaveEntrance_Top, 1
	setmetatile 3, 2, METATILE_MeteorFalls_CaveEntrance_Left, 1
	setmetatile 4, 2, METATILE_MeteorFalls_CaveEntrance_Bottom, 0
	setmetatile 5, 2, METATILE_MeteorFalls_CaveEntrance_Right, 1
	return

MeteorFalls_1F_1R_EventScript_RemovesMachine:
	setmetatile 9, 20, 0x21E, FALSE
	setmetatile 9, 21, 0x201, FALSE
	removeobject LOCALID_DEOXYS
	removeobject LOCALID_COSMOG
	return

MeteorFalls_1F_1R_Text_WithThisMeteorite:
	.string "Hehehe!\p"
	.string "With this Meteorite, that thing in\n"
	.string "Mt. Chimney will…$"

MeteorFalls_1F_1R_Text_DontExpectMercyFromMagma:
	.string "Heh?\p"
	.string "I don't know who you are, but if you get\n"
	.string "in the way of Team Magma, don't\l"
	.string "expect any mercy!$"

MeteorFalls_1F_1R_Text_HoldItRightThereMagma:
	.string "Hold it right there, Team Magma!\p"
	.string "You're badly mistaken if you think you\n"
	.string "can have your way with the world!$"

MeteorFalls_1F_1R_Text_BeSeeingYouTeamAqua:
	.string "Hehehe!\n"
	.string "Even Team Aqua joins us!\p"
	.string "But it's too much trouble to deal with\n"
	.string "you all…\p"
	.string "Heh, it doesn't matter!\p"
	.string "We've got the Meteorite, so off to\n"
	.string "Mt. Chimney we go!\p"
	.string "Hehehe! Be seeing you, you Team\n"
	.string "Aqua dingbats!$"

MeteorFalls_1F_1R_Text_ArchieSeenYouBefore:
	.string "Archie: Didn't I see you before?\n"
	.string "At Slateport's Museum?\p"
	.string "Ah, so your name is {PLAYER}.\p"
	.string "At the time, I thought you were one\n"
	.string "of Team Magma's goons.\p"
	.string "Humph…\n"
	.string "You're one odd kid.\p"
	.string "Team Magma is a dangerous group of\n"
	.string "total fanatics.\p"
	.string "They engage in destruction, claiming\n"
	.string "to expand the land mass.\p"
	.string "They are the rivals to us,\n"
	.string "the sea-loving Team Aqua!$"

MeteorFalls_1F_1R_Text_BossWeShouldChaseMagma:
	.string "Boss, we should give chase to\n"
	.string "Team Magma…$"

MeteorFalls_1F_1R_Text_ArchieYesNoTellingWhatMagmaWillDo:
	.string "Archie: Yes, yes, we must!\n"
	.string "We've got to hurry.\p"
	.string "There's no telling what Team Magma\n"
	.string "will do at Mt. Chimney!$"

MeteorFalls_1F_1R_Text_ArchieFarewell:
	.string "Archie: {PLAYER}, you should keep\n"
	.string "an eye out for Team Magma, too.\p"
	.string "Farewell!$"

MeteorFalls_1F_1R_Text_MeetProfCozmo:
	.string "I… I'm Cozmo…\n"
	.string "I'm a Professor\p"
	.string "Team Magma asked me to guide them\n"
	.string "to Meteor Falls…\p"
	.string "But they tricked me.\n"
	.string "They even took my Meteorite away…\p"
	.string "And then another similar bunch,\n"
	.string "Team Aqua showed up.\p"
	.string "After that…\n"
	.string "I don't understand any of it.\p"
	.string "But that Team Magma…\p"
	.string "What are they going to do with that\n"
	.string "Meteorite at Mt. Chimney?$"

MeteorFalls_1F_1R_Text_WhatsTeamMagmaDoingAtMtChimney:
	.string "Prof. Cozmo: But that Team Magma…\p"
	.string "What are they going to do with that\n"
	.string "Meteorite at Mt. Chimney?$"

@ NEW code
@.set LOCALID_MARS, 7
@.set LOCALID_GRUNT_1, 5
@.set LOCALID_GRUNT_2, 6

MeteorFalls_1F_1R_EventScript_GalacticTeamPlans::
	lockall
	playse SE_PIN
	applymovement OBJ_EVENT_ID_PLAYER, MeteorFalls_1F_1R_Movement_PlayerSurprise
	waitmovement 0
	applymovement LOCALID_GRUNT_1, MeteorFalls_1F_1R_Movement_Grunt1StopPlayer
	applymovement LOCALID_GRUNT_2, MeteorFalls_1F_1R_Movement_Grunt2StopPlayer
	waitmovement 0
	msgbox MeteorFalls_1F_1R_Text_GruntStopPlayer, MSGBOX_DEFAULT
	closemessage
	delay 16
	applymovement LOCALID_SATURN, Common_Movement_WalkInPlaceFastestUp
	waitmovement 0
	delay 16
	msgbox MeteorFalls_1F_1R_Text_MarsPlans, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SATURN, MeteorFalls_1F_1R_Movement_TakesStone
	waitmovement 0
	delay 16
	removeobject LOCALID_BLACK_TRIANGLE
	applymovement LOCALID_SATURN, MeteorFalls_1F_1R_Movement_PowerUpMachine
	waitmovement 0
	playse SE_PC_LOGIN
	waitse
	delay 16
	setvar VAR_0x8004, 1
	setvar VAR_0x8005, 1
	setvar VAR_0x8006, 20
	setvar VAR_0x8007, 3
	special ShakeCamera
	waitstate
	playse SE_M_ROCK_THROW
	waitse
	playse SE_PIN
	applymovement LOCALID_SATURN, Common_Movement_ExclamationMark
	applymovement LOCALID_MARS, Common_Movement_ExclamationMark
	applymovement LOCALID_GRUNT_1, MeteorFalls_1F_1R_Movement_GruntAffraid
	applymovement LOCALID_GRUNT_2, MeteorFalls_1F_1R_Movement_GruntAffraid
	waitmovement 0
	delay 16
	setvar VAR_0x8004, 1
	setvar VAR_0x8005, 1
	setvar VAR_0x8006, 20
	setvar VAR_0x8007, 3
	special ShakeCamera
	waitstate
	playse SE_M_ROCK_THROW
	waitse
	msgbox MeteorFalls_1F_1R_Text_MarsWhatAreYouDoingHere, MSGBOX_DEFAULT
	closemessage
	delay 16
	setvar VAR_0x8004, 1
	setvar VAR_0x8005, 1
	setvar VAR_0x8006, 20
	setvar VAR_0x8007, 3
	special ShakeCamera
	waitstate
	applymovement LOCALID_MARS, MeteorFalls_1F_1R_Movement_StepAway
	waitmovement 0
	msgbox MeteorFalls_1F_1R_Text_SaturnSomethinWrong, MSGBOX_DEFAULT
	closemessage
	playse SE_PIN
	waitse
	addobject LOCALID_ULTRA_WORMHOLE
	clearflag FLAG_HIDE_ULTRA_WORMHOLE
	delay 16
	delay 16
	applymovement LOCALID_SATURN, MeteorFalls_1F_1R_Movement_SeePortal
	waitmovement 0
	msgbox MeteorFalls_1F_1R_Text_SaturnWhatIsThis, MSGBOX_DEFAULT
	closemessage
	delay 16
	applymovement LOCALID_SATURN, MeteorFalls_1F_1R_Movement_SaturnStepAway
	waitmovement 0
	addobject LOCALID_COSMOG
	clearflag FLAG_HIDE_COSMOG_METEOR_FALLS
	applymovement LOCALID_COSMOG, MeteorFalls_1F_1R_Movement_CosmogExitUltraWorm
	waitmovement 0
	playmoncry SPECIES_COSMOG, 0
	msgbox MeteorFalls_1F_1R_Text_CosmogAppears, MSGBOX_DEFAULT
	closemessage
	waitmoncry
	applymovement LOCALID_SATURN, Common_Movement_WalkInPlaceDown
	applymovement LOCALID_MARS, Common_Movement_WalkInPlaceFastestUp
	waitmovement 0
	msgbox MeteorFalls_1F_1R_Text_MarsWantExit, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SATURN, MeteorFalls_1F_1R_Movement_GruntAffraid
	applymovement LOCALID_MARS, MeteorFalls_1F_1R_Movement_GruntAffraid
	waitmovement 0
	addobject LOCALID_DEOXYS
	clearflag FLAG_HIDE_DEOXYS
	applymovement LOCALID_COSMOG, Common_Movement_WalkInPlaceFastestLeft
	applymovement LOCALID_DEOXYS, MeteorFalls_1F_1R_Movement_DeoxysAppears
	waitmovement 0
	playmoncry SPECIES_DEOXYS, 2
	waitmoncry
	applymovement LOCALID_SATURN, Common_Movement_WalkInPlaceDown
	applymovement LOCALID_MARS, Common_Movement_WalkInPlaceFastestUp
	waitmovement 0
	msgbox MeteorFalls_1F_1R_Text_MarsLeave, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SATURN, MeteorFalls_1F_1R_Movement_SaturnTakesMachine
	applymovement LOCALID_MARS, MeteorFalls_1F_1R_Movement_MarsTakesMachine
	waitmovement 0
	delay 16
	setmetatile 9, 20, 0x21E, FALSE
	setmetatile 9, 21, 0x201, FALSE
	special DrawWholeMapView
	delay 16
	applymovement LOCALID_SATURN, MeteorFalls_1F_1R_Movement_SaturnLeaves
	applymovement LOCALID_MARS, MeteorFalls_1F_1R_Movement_MarsLeaves
	waitmovement 0
	removeobject LOCALID_SATURN
	removeobject LOCALID_MARS
	setflag FLAG_HIDE_VILLAINS_IN_METEOR_FALLS_AND_FALLARBOR_TOWN
	applymovement LOCALID_GRUNT_1, Common_Movement_WalkInPlaceFastestRight
	applymovement LOCALID_GRUNT_2, Common_Movement_WalkInPlaceFastestUp
	waitmovement 0
	msgbox MeteorFalls_1F_1R_Text_Grunt1WantsHelp, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_GRUNT_1, MeteorFalls_1F_1R_Movement_Grunt1Leaves
	applymovement LOCALID_GRUNT_2, MeteorFalls_1F_1R_Movement_Grunt2Leaves
	waitmovement 0
	removeobject LOCALID_GRUNT_1
	removeobject LOCALID_GRUNT_2
	playmoncry SPECIES_DEOXYS, 2
	waitmoncry
	applymovement OBJ_EVENT_ID_PLAYER, MeteorFalls_1F_1R_Movement_PlayerGoHelpCosmog
	waitmovement 0
MeteorFalls_1F_1R_EventScript_DeoxysBattle:
	setvar VAR_TEAM_GALACTIC_STATE, 4
	setvar VAR_0x8004, SPECIES_DEOXYS
	setvar VAR_0x8005, 30 @ level
	setvar VAR_0x8006, ITEM_NONE
	special CreateEventLegalEnemyMon
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	special BattleSetup_StartLegendaryBattle
	waitstate
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	setvar VAR_0x8004, SPECIES_DEOXYS
	fadescreenswapbuffers FADE_TO_BLACK
	removeobject LOCALID_DEOXYS
	specialvar VAR_RESULT, GetBattleOutcome
	compare VAR_RESULT, B_OUTCOME_CAUGHT
	goto_if_eq MeteorFalls_1F_1R_EventScript_Captured
	compare VAR_RESULT, B_OUTCOME_LOST
	goto_if_eq MeteorFalls_1F_1R_EventScript_Lost
	bufferspeciesname 0, VAR_0x8004
	msgbox gText_LegendaryFlewAway, MSGBOX_DEFAULT
	closemessage
MeteorFalls_1F_1R_EventScript_Captured:
	fadescreenswapbuffers FADE_FROM_BLACK
	applymovement OBJ_EVENT_ID_PLAYER, MeteorFalls_1F_1R_Movement_PlayerApproachCosmog
	waitmovement 0
	applymovement LOCALID_COSMOG, MeteorFalls_1F_1R_Movement_CosmogHeart
	waitmovement 0
	msgbox MeteorFalls_1F_1R_Text_CosmogJoin, MSGBOX_YESNO
	closemessage
	switch VAR_RESULT
	case NO, MeteorFalls_1F_1R_EventScript_DontJoin
	case YES, MeteorFalls_1F_1R_EventScript_Join
	case MULTI_B_PRESSED, MeteorFalls_1F_1R_EventScript_DontJoin
	releaseall
	end

MeteorFalls_1F_1R_EventScript_Lost:
    removeobject LOCALID_DEOXYS
    removeobject LOCALID_ULTRA_WORMHOLE
    removeobject LOCALID_COSMOG
	special SetCB2WhiteOut
	waitstate

MeteorFalls_1F_1R_EventScript_DontJoin:
	playmoncry SPECIES_COSMOG, 0
	waitmoncry
	delay 16
	applymovement LOCALID_COSMOG, Common_Movement_FaceUp
	waitmovement 0
	delay 16
	applymovement LOCALID_COSMOG, Common_Movement_FaceLeft
	waitmovement 0
	delay 16
	applymovement LOCALID_COSMOG, Common_Movement_WalkUp2
	waitmovement 0
	removeobject LOCALID_COSMOG
	delay 16	
	removeobject LOCALID_ULTRA_WORMHOLE
	releaseall
	end

MeteorFalls_1F_1R_EventScript_Join:
	givemon SPECIES_COSMOG, 5, ITEM_NONE
	bufferspeciesname 0, SPECIES_COSMOG
	compare VAR_RESULT, 0
	goto_if_eq MeteorFalls_1F_1R_EventScript_SendCosmogToParty
	compare VAR_RESULT, 1
	goto_if_eq MeteorFalls_1F_1R_EventScript_SendCosmogToPC
	goto MeteorFalls_1F_1R_EventScript_DontJoin

MeteorFalls_1F_1R_EventScript_SendCosmogToParty:
	playfanfare MUS_OBTAIN_ITEM
	message MeteorFalls_1F_1R_Text_ReceivedCosmog
	waitmessage
	waitfanfare
	removeobject LOCALID_COSMOG
	goto_if_eq MeteorFalls_1F_1R_EventScript_ReceivedCosmog
	call Common_EventScript_GetGiftMonPartySlot
	call Common_EventScript_NameReceivedPartyMon
	goto MeteorFalls_1F_1R_EventScript_ReceivedCosmog
	end

MeteorFalls_1F_1R_EventScript_SendCosmogToPC:
	playfanfare MUS_OBTAIN_ITEM
	message MeteorFalls_1F_1R_Text_ReceivedCosmog
	waitmessage
	waitfanfare
	removeobject LOCALID_COSMOG
	goto_if_eq MeteorFalls_1F_1R_EventScript_ReceivedCosmog
	call Common_EventScript_GetGiftMonPartySlot
	call Common_EventScript_NameReceivedPartyMon
	goto MeteorFalls_1F_1R_EventScript_ReceivedCosmog
	end

MeteorFalls_1F_1R_EventScript_ReceivedCosmog:
	release
	end

MeteorFalls_1F_1R_Text_ReceivedCosmog:
	.string "{PLAYER} received the {STR_VAR_1}!$"

MeteorFalls_1F_1R_Movement_PlayerApproachCosmog:
	walk_up
	face_right
	step_end

MeteorFalls_1F_1R_Movement_CosmogHeart::
	emote_heart
	step_end

MeteorFalls_1F_1R_Movement_PlayerGoHelpCosmog:
	walk_fast_left
	walk_fast_left
	walk_fast_down
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_in_place_fast_up
	step_end

MeteorFalls_1F_1R_Movement_SaturnTakesMachine:
	walk_down
	walk_down
	walk_left
	walk_left
	walk_in_place_fast_up
	step_end

MeteorFalls_1F_1R_Movement_MarsTakesMachine:
	walk_down
	walk_left
	walk_left
	walk_left
	walk_in_place_right
	step_end

MeteorFalls_1F_1R_Movement_Grunt1Leaves:
	walk_down
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
	step_end

MeteorFalls_1F_1R_Movement_Grunt2Leaves:
	delay_16
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
	step_end

MeteorFalls_1F_1R_Movement_MarsLeaves:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

MeteorFalls_1F_1R_Movement_SaturnLeaves:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

MeteorFalls_1F_1R_Movement_DeoxysAppears:
	walk_slow_right
	walk_slow_right
	walk_slow_right
	walk_slow_right
	walk_slow_right
	step_end

MeteorFalls_1F_1R_Movement_Grunt1StopPlayer:
	walk_right
	walk_right
	step_end

MeteorFalls_1F_1R_Movement_Grunt2StopPlayer:
	walk_right
	walk_right
	face_up
	step_end

MeteorFalls_1F_1R_Movement_CosmogExitUltraWorm:
	walk_down
	walk_down
	face_right
	step_end

MeteorFalls_1F_1R_Movement_SaturnStepAway:
	walk_right
	face_left
	lock_facing_direction
	walk_right
	unlock_facing_direction
	step_end

MeteorFalls_1F_1R_Movement_SeePortal:
	walk_left
	walk_up
	walk_up
	walk_right
	walk_in_place_fastest_up
	step_end

MeteorFalls_1F_1R_Movement_PlayerSurprise:
	emote_exclamation_mark
	face_left
	step_end

MeteorFalls_1F_1R_Movement_StepAway:
	lock_facing_direction
	walk_right
	unlock_facing_direction
	step_end

MeteorFalls_1F_1R_Movement_GruntAffraid:
	walk_in_place_fast_left
	emote_exclamation_mark
	step_end

MeteorFalls_1F_1R_Movement_TakesStone:
	walk_left
	walk_in_place_fast_up
	step_end

MeteorFalls_1F_1R_Movement_PowerUpMachine:
	walk_right
	walk_in_place_fast_up
	step_end

MeteorFalls_1F_1R_Text_CosmogJoin:
	.string "Cosmog seems happy and\n"
	.string "wants to join {PLAYER}!$"

MeteorFalls_1F_1R_Text_Grunt1WantsHelp:
	.string "Poor Pokémon…\p"
	.string "It will get destroyed by Deoxys!$"

MeteorFalls_1F_1R_Text_MarsLeave:
	.string "Mars: The energy from that stone\n"
	.string "must have attracted the Deoxys…\p"
	.string "We must leave him now!$"

MeteorFalls_1F_1R_Text_GruntStopPlayer:
	.string "Stop right there…\p"
	.string "Our Boss doesn't want interference!$"

MeteorFalls_1F_1R_Text_MarsWantExit:
	.string "Saturn: Looks like a Pokémon\n"
	.string "is coming from that dimension…\p"
	.string "Mars: Forget it, we should tell Boss\n"
	.string "that we finished the machine!$"

MeteorFalls_1F_1R_Text_CosmogAppears:
	.string "Cos-mog!$"

MeteorFalls_1F_1R_Text_SaturnSomethinWrong:
	.string "Mars: Something is wrong…$"

MeteorFalls_1F_1R_Text_SaturnWhatIsThis:
	.string "Saturn: This shouldn't happen…\p"
	.string "Wait…\p"
	.string "What?!\p"
	.string "Something is coming…$"

MeteorFalls_1F_1R_Text_MarsPlans:
	.string "Saturn: Let's use the energy\n"
	.string "of this mystical stone to power\l"
	.string "our reality-warp machine…$"

MeteorFalls_1F_1R_Text_MarsWhatAreYouDoingHere:
	.string "Saturn: It's done…$"

MeteorFalls_1F_1R_EventScript_TeamRocketTrigger1::
	goto_if_set FLAG_DEFEATED_JESSIE_JAMES_METEOR_FALLS, MeteorFalls_1F_1R_EventScript_AlreadyDefeated
	lockall
	setvar VAR_TEMP_5, 1
	applymovement LOCALID_JESSIE, MeteorFalls_1F_1R_Movement_Jessie1
	applymovement LOCALID_JAMES, MeteorFalls_1F_1R_Movement_James1
	waitmovement 0
	goto MeteorFalls_1F_1R_EventScript_TeamRocketAppear

MeteorFalls_1F_1R_EventScript_TeamRocketTrigger2::
	goto_if_set FLAG_DEFEATED_JESSIE_JAMES_METEOR_FALLS, MeteorFalls_1F_1R_EventScript_AlreadyDefeated
	lockall
	setvar VAR_TEMP_5, 2
	applymovement LOCALID_JESSIE, MeteorFalls_1F_1R_Movement_Jessie2
	applymovement LOCALID_JAMES, MeteorFalls_1F_1R_Movement_James2
	waitmovement 0
	goto MeteorFalls_1F_1R_EventScript_TeamRocketAppear

MeteorFalls_1F_1R_EventScript_AlreadyDefeated:
	setvar VAR_TEMP_5, 1
	end

MeteorFalls_1F_1R_EventScript_TeamRocketAppear:
	delay 16
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFastestUp
	waitmovement 0
	msgbox MeteorFalls_1F_1R_Text_JessieText1, MSGBOX_DEFAULT
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceDown
	waitmovement 0
	msgbox MeteorFalls_1F_1R_Text_JamesText1, MSGBOX_DEFAULT
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFastestUp
	waitmovement 0
	msgbox MeteorFalls_1F_1R_Text_JessieText2, MSGBOX_DEFAULT
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceDown
	waitmovement 0
	msgbox MeteorFalls_1F_1R_Text_JamesText2, MSGBOX_DEFAULT
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFastestUp
	waitmovement 0
	msgbox MeteorFalls_1F_1R_Text_JessieText3, MSGBOX_DEFAULT
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceDown
	waitmovement 0
	msgbox MeteorFalls_1F_1R_Text_JamesText3, MSGBOX_DEFAULT
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFastestUp
	waitmovement 0
	msgbox MeteorFalls_1F_1R_Text_JessieText4, MSGBOX_DEFAULT
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceDown
	waitmovement 0
	msgbox MeteorFalls_1F_1R_Text_JamesText4, MSGBOX_DEFAULT
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFastestUp
	waitmovement 0
	msgbox MeteorFalls_1F_1R_Text_JessieText5, MSGBOX_DEFAULT
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceDown
	waitmovement 0
	msgbox MeteorFalls_1F_1R_Text_JamesText5, MSGBOX_DEFAULT
	addobject LOCALID_MEOWTH
	compare VAR_TEMP_5, 1
	call_if_eq MeteorFalls_1F_1R_EventScript_SetMeowthPosition1
	compare VAR_TEMP_5, 2
	call_if_eq MeteorFalls_1F_1R_EventScript_SetMeowthPosition2
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceLeft
	waitmovement 0
	msgbox MeteorFalls_1F_1R_Text_Meowth, MSGBOX_DEFAULT
	multi_1_vs_1 TRAINER_JESSIE_JAMES_METEOR_FALLS, JessieJamesDefeatText
	removeobject LOCALID_MEOWTH
	specialvar VAR_RESULT, GetBattleOutcome
    compare VAR_RESULT, B_OUTCOME_LOST
    goto_if_eq MeteorFalls_1F_1R_EventScript_EventScript_PlayerLostTheFight
	compare VAR_TEMP_5, 1
	goto_if_eq MeteorFalls_1F_1R_EventScript_EventScript_AfterBattle1
	compare VAR_TEMP_5, 2
	goto_if_eq MeteorFalls_1F_1R_EventScript_EventScript_AfterBattle2
	end

MeteorFalls_1F_1R_EventScript_EventScript_PlayerLostTheFight:
	fadescreen FADE_TO_BLACK
	special SetCB2WhiteOut
	waitstate

MeteorFalls_1F_1R_EventScript_EventScript_AfterBattle1:
	checkplayergender
	compare VAR_RESULT, MALE
	call_if_eq MeteorFalls_1F_1R_EventScript_SetPlayerGfxMale
	compare VAR_RESULT, FEMALE
	call_if_eq MeteorFalls_1F_1R_EventScript_SetPlayerGfxFemale
	applymovement LOCALID_JESSIE, MeteorFalls_1F_1R_Movement_JessieExit1
	applymovement LOCALID_JAMES, MeteorFalls_1F_1R_Movement_JamesExit1
	waitmovement 0
	setflag FLAG_DEFEATED_JESSIE_JAMES_METEOR_FALLS
	removeobject LOCALID_JESSIE
	removeobject LOCALID_JAMES
	releaseall
	end

MeteorFalls_1F_1R_EventScript_SetPlayerGfxMale:
	msgbox MeteorFalls_1F_1R_Text_JessieMale, MSGBOX_DEFAULT
	closemessage
	return

MeteorFalls_1F_1R_EventScript_SetPlayerGfxFemale:
	msgbox MeteorFalls_1F_1R_Text_JessieFemale, MSGBOX_DEFAULT
	closemessage
	return

MeteorFalls_1F_1R_EventScript_EventScript_AfterBattle2:
	checkplayergender
	compare VAR_RESULT, MALE
	call_if_eq MeteorFalls_1F_1R_EventScript_SetPlayerGfxMale2
	compare VAR_RESULT, FEMALE
	call_if_eq MeteorFalls_1F_1R_EventScript_SetPlayerGfxFemale2
	applymovement LOCALID_JESSIE, MeteorFalls_1F_1R_Movement_JessieExit2
	applymovement LOCALID_JAMES, MeteorFalls_1F_1R_Movement_JamesExit2
	waitmovement 0
	setflag FLAG_DEFEATED_JESSIE_JAMES_METEOR_FALLS
	removeobject LOCALID_JESSIE
	removeobject LOCALID_JAMES
	releaseall
	end

MeteorFalls_1F_1R_EventScript_SetPlayerGfxMale2:
	msgbox MeteorFalls_1F_1R_Text_JamesMale, MSGBOX_DEFAULT
	closemessage
	return

MeteorFalls_1F_1R_EventScript_SetPlayerGfxFemale2:
	msgbox MeteorFalls_1F_1R_Text_JamesFemale, MSGBOX_DEFAULT
	closemessage
	return

MeteorFalls_1F_1R_EventScript_SetMeowthPosition1:
	setobjectxy LOCALID_MEOWTH, 16, 18
	return

MeteorFalls_1F_1R_EventScript_SetMeowthPosition2:
	setobjectxy LOCALID_MEOWTH, 16, 19
	return

MeteorFalls_1F_1R_Movement_Jessie1:
	emote_exclamation_mark
	face_down
	step_end

Common_Movement_WalkRightMeowth:
	walk_right
	step_end

MeteorFalls_1F_1R_Movement_James1:
	emote_exclamation_mark
	walk_up
	step_end

MeteorFalls_1F_1R_Movement_Jessie2:
	emote_exclamation_mark
	walk_down
	step_end

MeteorFalls_1F_1R_Movement_James2:
	emote_exclamation_mark
	face_up
	step_end

MeteorFalls_1F_1R_Movement_JessieExit1:
	walk_left
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_up
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

MeteorFalls_1F_1R_Movement_JamesExit1:
	walk_right
	walk_right
	walk_in_place_fast_left
	delay_16
	delay_16
	walk_up
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

MeteorFalls_1F_1R_Movement_JessieExit2:
	walk_right
	walk_right
	walk_in_place_fast_left
	delay_16
	delay_16
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

MeteorFalls_1F_1R_Movement_JamesExit2:
	walk_left
	walk_up
	walk_up
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

MeteorFalls_1F_1R_Text_JessieText1:
	.string "??? ♀: Prepare for trouble!$"

MeteorFalls_1F_1R_Text_JamesText1:
	.string "??? ♂: Make it double!$"

MeteorFalls_1F_1R_Text_JessieText2:
	.string "??? ♀: To protect the world\nfrom devastation!$"

MeteorFalls_1F_1R_Text_JamesText2:
	.string "??? ♂: To unite all peoples\nwithin our nation!$"

MeteorFalls_1F_1R_Text_JessieText3:
	.string "??? ♀: To denounce the evils\nof truth and love!$"

MeteorFalls_1F_1R_Text_JamesText3:
	.string "??? ♂: To extend our reach\nto the stars above!$"

MeteorFalls_1F_1R_Text_JessieText4:
	.string "??? ♀: Jessie!$"

MeteorFalls_1F_1R_Text_JamesText4:
	.string "??? ♂: James!$"

MeteorFalls_1F_1R_Text_JessieText5:
	.string "Jessie: Team Rocket blasts off\nat the speed of light!$"

MeteorFalls_1F_1R_Text_JamesText5:
	.string "James: Surrender now or\nprepare to fight!$"

MeteorFalls_1F_1R_Text_Meowth:
	.string "Meowth: Meowth! That's right!$"

JessieJamesDefeatText:
	.string "Jessie & James: Team Rocket blasts off\nagain!$"

MeteorFalls_1F_1R_Text_JessieMale:
	.string "Jessie: I can't belive we lost\nto this little twerp!$"

MeteorFalls_1F_1R_Text_JessieFemale:
	.string "Jessie: I can't belive we lost\nto this little twerpette!$"

MeteorFalls_1F_1R_Text_JamesMale:
	.string "James: I can't belive we lost\nto this little twerp!$"

MeteorFalls_1F_1R_Text_JamesFemale:
	.string "James: I can't belive we lost\nto this little twerpette!$"

MeteorFalls_1F_1R_EventScript_UltraWormhole::
	msgbox MeteorFalls_1F_1R_Text_UltraWormhole, MSGBOX_NPC
	end

MeteorFalls_1F_1R_Text_UltraWormhole:
	.string "A Ultra Wormhole…\n"
	.string "Must not enter!$"
