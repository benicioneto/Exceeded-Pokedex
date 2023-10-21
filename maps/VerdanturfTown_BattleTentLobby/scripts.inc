.set LOCALID_ATTENDANT, 1

VerdanturfTown_BattleTentLobby_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, VerdanturfTown_BattleTentLobby_OnFrame
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, VerdanturfTown_BattleTentLobby_OnWarp
	.byte 0

VerdanturfTown_BattleTentLobby_OnWarp:
	map_script_2 VAR_TEMP_1, 0, VerdanturfTown_BattleTentLobby_EventScript_TurnPlayerNorth
	.2byte 0

VerdanturfTown_BattleTentLobby_EventScript_TurnPlayerNorth::
	setvar VAR_TEMP_1, 1
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
	end

VerdanturfTown_BattleTentLobby_OnFrame:
	map_script_2 VAR_TEMP_0, 0, VerdanturfTown_BattleTentLobby_EventScript_GetChallengeStatus
	map_script_2 VAR_TEMP_0, CHALLENGE_STATUS_SAVING, VerdanturfTown_BattleTentLobby_EventScript_QuitWithoutSaving
	map_script_2 VAR_TEMP_0, CHALLENGE_STATUS_PAUSED, VerdanturfTown_BattleTentLobby_EventScript_ResumeChallenge
	map_script_2 VAR_TEMP_0, CHALLENGE_STATUS_WON, VerdanturfTown_BattleTentLobby_EventScript_WonChallenge
	map_script_2 VAR_TEMP_0, CHALLENGE_STATUS_LOST, VerdanturfTown_BattleTentLobby_EventScript_LostChallenge
	.2byte 0

VerdanturfTown_BattleTentLobby_EventScript_GetChallengeStatus::
	frontier_getstatus
	end

VerdanturfTown_BattleTentLobby_EventScript_QuitWithoutSaving::
	lockall
	msgbox BattleFrontier_BattlePalaceLobby_Text_FailedToSaveBeforeEndingChallenge, MSGBOX_DEFAULT
	closemessage
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, 0
	setvar VAR_TEMP_0, 255
	frontier_set FRONTIER_DATA_LVL_MODE, FRONTIER_LVL_50
	releaseall
	end

VerdanturfTown_BattleTentLobby_EventScript_WonChallenge::
	lockall
	message BattleTentLobby_Text_WonThreeMatchesReturnMons2
	waitmessage
	verdanturftent_setrandomprize
	frontier_set FRONTIER_DATA_LVL_MODE, FRONTIER_LVL_50
	verdanturftent_save 0
	playse SE_SAVE
	waitse
	goto VerdanturfTown_BattleTentLobby_EventScript_GivePrize

VerdanturfTown_BattleTentLobby_EventScript_EndGivePrize::
	msgbox BattleTentLobby_Text_LookForwardToNextVisit, MSGBOX_DEFAULT
	closemessage
	setvar VAR_TEMP_0, 255
	releaseall
	end

VerdanturfTown_BattleTentLobby_EventScript_PrizeWaiting::
	lockall
	message BattleTentLobby_Text_WonThreeMatchesReturnMons2 @Ok
	waitmessage
	verdanturftent_setrandomprize
	frontier_set FRONTIER_DATA_LVL_MODE, FRONTIER_LVL_50
	verdanturftent_save 0
	playse SE_SAVE
	waitse
	goto VerdanturfTown_BattleTentLobby_EventScript_GivePrize

VerdanturfTown_BattleTentLobby_EventScript_NoRoomForPrize::
	msgbox BattleTentLobby_Text_NoRoomInBagMakeRoom, MSGBOX_DEFAULT
	verdanturftent_givepoints
	msgbox BattleFrontier_Text_ObtainedXVerdanturfPoints, MSGBOX_GETPOINTS
	goto VerdanturfTown_BattleTentLobby_EventScript_EndGivePrize

VerdanturfTown_BattleTentLobby_EventScript_LostChallenge::
	lockall
	message VerdanturfTown_BattleTentLobby_Text_ResultsWillBeRecorded
	waitmessage
	verdanturftent_setrandomprize
	frontier_set FRONTIER_DATA_LVL_MODE, FRONTIER_LVL_50
	verdanturftent_save 0
	playse SE_SAVE
	waitse
	msgbox VerdanturfTown_BattleTentLobby_Text_ReturnFortified, MSGBOX_DEFAULT
	closemessage
	setvar VAR_TEMP_0, 255
	releaseall
	end

VerdanturfTown_BattleTentLobby_EventScript_ResumeChallenge::
	lockall
	msgbox BattleFrontier_BattlePalaceLobby_Text_WeHaveBeenWaiting, MSGBOX_DEFAULT
	message BattleFrontier_BattlePalaceLobby_Text_MustSaveBeforeChallenge
	waitmessage
	verdanturftent_save CHALLENGE_STATUS_SAVING
	playse SE_SAVE
	waitse
	frontier_set FRONTIER_DATA_PAUSED, FALSE
	setvar VAR_TEMP_0, 255
	goto VerdanturfTown_BattleTentLobby_EventScript_EnterChallenge

VerdanturfTown_BattleTentLobby_EventScript_Attendant::
	lock
	faceplayer
	verdanturftent_getprize
	compare VAR_RESULT, ITEM_NONE
	goto_if_ne VerdanturfTown_BattleTentLobby_EventScript_GivePrize
	special SavePlayerParty
	msgbox VerdanturfTown_BattleTentLobby_Text_WelcomeToBattleTent, MSGBOX_DEFAULT
VerdanturfTown_BattleTentLobby_EventScript_AskEnterChallenge::
	message VerdanturfTown_BattleTentLobby_Text_TakeChallenge
	waitmessage
	multichoice 17, 6, MULTI_CHALLENGEINFO, FALSE
	switch VAR_RESULT
	case 0, VerdanturfTown_BattleTentLobby_EventScript_TryEnterChallenge
	case 1, VerdanturfTown_BattleTentLobby_EventScript_ExplainChallenge
	case 2, VerdanturfTown_BattleTentLobby_EventScript_CancelChallenge
	case MULTI_B_PRESSED, VerdanturfTown_BattleTentLobby_EventScript_CancelChallenge

VerdanturfTown_BattleTentLobby_EventScript_TryEnterChallenge::
	setvar VAR_FRONTIER_FACILITY, FRONTIER_FACILITY_PALACE
	setvar VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES
	setvar VAR_RESULT, 2
	frontier_checkineligible
	compare VAR_0x8004, TRUE
	goto_if_eq VerdanturfTown_BattleTentLobby_EventScript_NotEnoughValidMons
	frontier_set FRONTIER_DATA_LVL_MODE, FRONTIER_LVL_TENT
	msgbox VerdanturfTown_BattleTentLobby_Text_SelectThreeMons, MSGBOX_DEFAULT
	fadescreen FADE_TO_BLACK
	setvar VAR_0x8004, 1
	setvar VAR_0x8005, FRONTIER_PARTY_SIZE
	special ChoosePartyForBattleFrontier
	waitstate
	compare VAR_RESULT, 0
	goto_if_eq VerdanturfTown_BattleTentLobby_EventScript_LoadPartyCancelChallenge
	msgbox VerdanturfTown_BattleTentLobby_Text_SaveBeforeChallenge, MSGBOX_YESNO
	switch VAR_RESULT
	case NO, VerdanturfTown_BattleTentLobby_EventScript_LoadPartyCancelChallenge
	case YES, VerdanturfTown_BattleTentLobby_EventScript_SaveBeforeChallenge
	case MULTI_B_PRESSED, VerdanturfTown_BattleTentLobby_EventScript_LoadPartyCancelChallenge

VerdanturfTown_BattleTentLobby_EventScript_SaveBeforeChallenge::
	setvar VAR_TEMP_0, 0
	frontier_set FRONTIER_DATA_SELECTED_MON_ORDER
	verdanturftent_init
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, CHALLENGE_STATUS_SAVING
	frontier_set FRONTIER_DATA_PAUSED, FALSE
	special LoadPlayerParty
	closemessage
	delay 2
	call Common_EventScript_SaveGame
	setvar VAR_TEMP_0, 255
	compare VAR_RESULT, 0
	goto_if_eq VerdanturfTown_BattleTentLobby_EventScript_CancelChallengeSaveFailed
VerdanturfTown_BattleTentLobby_EventScript_EnterChallenge::
	special SavePlayerParty
	frontier_setpartyorder FRONTIER_PARTY_SIZE
	msgbox VerdanturfTown_BattleTentLobby_Text_NowFollowMe, MSGBOX_DEFAULT
	closemessage
	call VerdanturfTown_BattleTentLobby_EventScript_WalkToDoor
	warp MAP_VERDANTURF_TOWN_BATTLE_TENT_CORRIDOR, 255, 2, 7
	setvar VAR_TEMP_0, 0
	waitstate
	end

VerdanturfTown_BattleTentLobby_EventScript_ExplainChallenge::
	msgbox VerdanturfTown_BattleTentLobby_Text_ExplainVerdanturfTent, MSGBOX_DEFAULT
	goto VerdanturfTown_BattleTentLobby_EventScript_AskEnterChallenge

VerdanturfTown_BattleTentLobby_EventScript_NotEnoughValidMons::
	switch VAR_RESULT
	case FRONTIER_LVL_50, VerdanturfTown_BattleTentLobby_EventScript_NotEnoughValidMonsLv50
	case FRONTIER_LVL_OPEN, VerdanturfTown_BattleTentLobby_EventScript_NotEnoughValidMonsLvOpen

VerdanturfTown_BattleTentLobby_EventScript_NotEnoughValidMonsLv50::
	msgbox VerdanturfTown_BattleTentLobby_Text_NotEnoughValidMonsLv50, MSGBOX_DEFAULT
	goto VerdanturfTown_BattleTentLobby_EventScript_EndCancelChallenge

VerdanturfTown_BattleTentLobby_EventScript_NotEnoughValidMonsLvOpen::
	msgbox VerdanturfTown_BattleTentLobby_Text_NotEnoughValidMonsLvOpen, MSGBOX_DEFAULT
	goto VerdanturfTown_BattleTentLobby_EventScript_EndCancelChallenge

VerdanturfTown_BattleTentLobby_EventScript_CancelChallengeSaveFailed::
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, 0
	goto VerdanturfTown_BattleTentLobby_EventScript_CancelChallenge

VerdanturfTown_BattleTentLobby_EventScript_LoadPartyCancelChallenge::
	special LoadPlayerParty
VerdanturfTown_BattleTentLobby_EventScript_CancelChallenge::
	msgbox VerdanturfTown_BattleTentLobby_Text_ReturnFortified, MSGBOX_DEFAULT
VerdanturfTown_BattleTentLobby_EventScript_EndCancelChallenge::
	release
	end

VerdanturfTown_BattleTentLobby_EventScript_WalkToDoor::
	applymovement LOCALID_ATTENDANT, VerdanturfTown_BattleTentLobby_Movement_WalkToDoor
	applymovement OBJ_EVENT_ID_PLAYER, VerdanturfTown_BattleTentLobby_Movement_WalkToDoor
	waitmovement 0
	opendoor 6, 1
	waitdooranim
	applymovement LOCALID_ATTENDANT, VerdanturfTown_BattleTentLobby_Movement_AttendantEnterDoor
	applymovement OBJ_EVENT_ID_PLAYER, VerdanturfTown_BattleTentLobby_Movement_PlayerEnterDoor
	waitmovement 0
	closedoor 6, 1
	waitdooranim
	return

VerdanturfTown_BattleTentLobby_Movement_WalkToDoor:
	walk_up
	walk_up
	walk_up
	step_end

VerdanturfTown_BattleTentLobby_Movement_AttendantEnterDoor:
	walk_up
	set_invisible
	step_end

VerdanturfTown_BattleTentLobby_Movement_PlayerEnterDoor:
	walk_up
	walk_up
	set_invisible
	step_end

VerdanturfTown_BattleTentLobby_EventScript_AttractGiver::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_TM45, VerdanturfTown_BattleTentLobby_EventScript_ReceivedAttract
	msgbox VerdanturfTown_BattleTentLobby_Text_AttractionRunsDeep, MSGBOX_DEFAULT
	giveitem ITEM_TM45
	compare VAR_RESULT, 0
	goto_if_eq Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_TM45
	msgbox VerdanturfTown_BattleTentLobby_Text_AttractionMutual, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_BattleTentLobby_EventScript_ReceivedAttract::
	msgbox VerdanturfTown_BattleTentLobby_Text_AttractionMutual, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_BattleTentLobby_EventScript_Boy1::
	msgbox VerdanturfTown_BattleTentLobby_Text_TaughtWhatKindsOfMoves, MSGBOX_NPC
	end

VerdanturfTown_BattleTentLobby_EventScript_Boy2::
	lock
	msgbox VerdanturfTown_BattleTentLobby_Text_MonsReluctantToUseDislikedMoves, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_BattleTentLobby_EventScript_Scott::
	lock
	faceplayer
	goto_if_set FLAG_MET_SCOTT_IN_VERDANTURF, VerdanturfTown_BattleTentLobby_EventScript_ScottAlreadySpokenTo
	msgbox VerdanturfTown_BattleTentLobby_Text_ScottCanMeetToughTrainers, MSGBOX_DEFAULT
	addvar VAR_SCOTT_STATE, 1
	setflag FLAG_MET_SCOTT_IN_VERDANTURF
	release
	end

VerdanturfTown_BattleTentLobby_EventScript_ScottAlreadySpokenTo::
	msgbox VerdanturfTown_BattleTentLobby_Text_ScottVisitRegularly, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_BattleTentLobby_EventScript_LittleBoy::
	lock
	msgbox VerdanturfTown_BattleTentLobby_Text_GentleMonsScaryIfAngry, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_BattleTentLobby_EventScript_RulesBoard::
	lockall
	msgbox VerdanturfTown_BattleTentLobby_Text_RulesAreListed, MSGBOX_DEFAULT
	goto VerdanturfTown_BattleTentLobby_EventScript_ReadRulesBoard
	end

VerdanturfTown_BattleTentLobby_EventScript_ReadRulesBoard::
	message BattleFrontier_BattlePalaceLobby_Text_ReadWhichHeading
	waitmessage
	setvar VAR_0x8004, SCROLL_MULTI_BATTLE_TENT_RULES
	special ShowScrollableMultichoice
	waitstate
	switch VAR_RESULT
	case 0, VerdanturfTown_BattleTentLobby_EventScript_RulesLevel
	case 1, VerdanturfTown_BattleTentLobby_EventScript_RulesBasics
	case 2, VerdanturfTown_BattleTentLobby_EventScript_RulesNature
	case 3, VerdanturfTown_BattleTentLobby_EventScript_RulesMoves
	case 4, VerdanturfTown_BattleTentLobby_EventScript_RulesUnderpowered
	case 5, VerdanturfTown_BattleTentLobby_EventScript_RulesWhenInDanger
	case 6, VerdanturfTown_BattleTentLobby_EventScript_ExitRules
	case MULTI_B_PRESSED, VerdanturfTown_BattleTentLobby_EventScript_ExitRules
	end

VerdanturfTown_BattleTentLobby_EventScript_RulesLevel::
	msgbox BattleTentLobby_Text_ExplainLevelRules, MSGBOX_DEFAULT
	goto VerdanturfTown_BattleTentLobby_EventScript_ReadRulesBoard
	end

VerdanturfTown_BattleTentLobby_EventScript_RulesBasics::
	msgbox BattleFrontier_BattlePalaceLobby_Text_ExplainRulesBasics, MSGBOX_DEFAULT
	goto VerdanturfTown_BattleTentLobby_EventScript_ReadRulesBoard
	end

VerdanturfTown_BattleTentLobby_EventScript_RulesNature::
	msgbox BattleFrontier_BattlePalaceLobby_Text_ExplainRulesNature, MSGBOX_DEFAULT
	goto VerdanturfTown_BattleTentLobby_EventScript_ReadRulesBoard
	end

VerdanturfTown_BattleTentLobby_EventScript_RulesMoves::
	msgbox BattleFrontier_BattlePalaceLobby_Text_ExplainRulesMoves, MSGBOX_DEFAULT
	goto VerdanturfTown_BattleTentLobby_EventScript_ReadRulesBoard
	end

VerdanturfTown_BattleTentLobby_EventScript_RulesUnderpowered::
	msgbox BattleFrontier_BattlePalaceLobby_Text_ExplainRulesUnderpowered, MSGBOX_DEFAULT
	goto VerdanturfTown_BattleTentLobby_EventScript_ReadRulesBoard
	end

VerdanturfTown_BattleTentLobby_EventScript_RulesWhenInDanger::
	msgbox BattleFrontier_BattlePalaceLobby_Text_ExplainRulesWhenInDanger, MSGBOX_DEFAULT
	goto VerdanturfTown_BattleTentLobby_EventScript_ReadRulesBoard
	end

VerdanturfTown_BattleTentLobby_EventScript_ExitRules::
	releaseall
	end

VerdanturfTown_BattleTentLobby_Text_MonsReluctantToUseDislikedMoves:
	.string "If it doesn't like a certain move,\n"
	.string "a Pokémon will be reluctant to use it.\p"
	.string "It doesn't matter how strong it is,\n"
	.string "either.\p"
	.string "For example, a Pokémon with a Gentle\n"
	.string "nature probably won't enjoy hurting\l"
	.string "its opponents.\p"
	.string "If it can't seem to live up to its\n"
	.string "potential, it's probably failing at\l"
	.string "using a disliked move against its will.$"

VerdanturfTown_BattleTentLobby_Text_GentleMonsScaryIfAngry:
	.string "My big sister is gentle usually.\n"
	.string "But when she gets angry,\l"
	.string "she's really, really scary!\p"
	.string "I bet a gentle Pokémon will be scary\n"
	.string "if it gets angry!$"

VerdanturfTown_BattleTentLobby_Text_AttractionRunsDeep:
	.string "My feelings toward my Pokémon…\n"
	.string "The attraction runs deep…\p"
	.string "Oh, hi, you didn't see that, did you?\n"
	.string "Well, it doesn't matter.\p"
	.string "How would you like this TM for\n"
	.string "your Pokémon?$"

VerdanturfTown_BattleTentLobby_Text_AttractionMutual:
	.string "My feelings toward my Pokémon…\n"
	.string "I'm sure the attraction is mutual!\p"
	.string "They battle exactly the way I want\n"
	.string "them to!$"

VerdanturfTown_BattleTentLobby_Text_TaughtWhatKindsOfMoves:
	.string "What kind of moves have you taught\n"
	.string "your Pokémon?\p"
	.string "I think you would give yourself\n"
	.string "an advantage if they knew how to\l"
	.string "heal or protect themselves.$"

VerdanturfTown_BattleTentLobby_Text_ScottCanMeetToughTrainers:
	.string "Scott: Hey there, {PLAYER}{KUN}!\n"
	.string "I thought I might see you here.\p"
	.string "A Battle Tent's a place where\n"
	.string "you can meet tough Trainers.\p"
	.string "It doesn't matter what the rules are,\n"
	.string "or how battles are waged, either.\p"
	.string "{PLAYER}{KUN}, I expect you to do\n"
	.string "the best you can!$"

VerdanturfTown_BattleTentLobby_Text_ScottVisitRegularly:
	.string "Scott: I visit here regularly in hopes\n"
	.string "of seeing tough Trainers in action\l"
	.string "in whatever the situation.$"


@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
@		New Code
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

VerdanturfTown_BattleTentLobby_EventScript_GivePrize::
	msgbox VerdanturfTown_BattleTentLobby_Text_AwardYouThisPrize2, MSGBOX_DEFAULT
	verdanturftent_giveprize
	switch VAR_RESULT
	case FALSE, VerdanturfTown_BattleTentLobby_EventScript_NoRoomForPrize
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, 0
	message BattleFrontier_BattleTowerLobby_Text_ReceivedPrize2
	waitmessage
	playfanfare MUS_OBTAIN_ITEM
	waitfanfare
	verdanturftent_givepoints
	msgbox BattleFrontier_Text_ObtainedXVerdanturfPoints, MSGBOX_GETPOINTS
	goto VerdanturfTown_BattleTentLobby_EventScript_EndGivePrize

VerdanturfTown_BattleTentLobby_Text_AwardYouThisPrize2:
	.string "In recognition,\n"
	.string "we award you this prize.$"

BattleFrontier_BattleTowerLobby_Text_ReceivedPrize2:
	.string "{PLAYER} received the prize\n"
	.string "{STR_VAR_1}.$"	

BattleFrontier_Text_ObtainedXVerdanturfPoints:
	.string "{PLAYER} obtained {STR_VAR_2} Verdanturf\n"
	.string "Point(s).$"

VerdanturfTown_BattleTentLobby_ExchangeServiceCorner_EventScript_HoldItemClerk::
	lock
	faceplayer
	setvar VAR_TEMP_2, EXCHANGE_CORNER_HOLD_ITEM_CLERK
	call VerdanturfTown_BattleTentLobby_ExchangeServiceCorner_EventScript_ClerkWelcome
	goto VerdanturfTown_BattleTentLobby_ExchangeServiceCorner_EventScript_ChooseHoldItem
	end

VerdanturfTown_BattleTentLobby_ExchangeServiceCorner_EventScript_ClerkWelcome::
	msgbox VerdanturfTown_BattleTentLobby_ExchangeServiceCorner_Text_WelcomePleaseChoosePrize, MSGBOX_DEFAULT
	special ShowVerdanturfPointsWindow
	return

VerdanturfTown_BattleTentLobby__ExchangeServiceCorner_EventScript_ClerkGoodbye::
	msgbox VerdanturfTown_BattleTentLobby_ExchangeServiceCorner_Text_ThankYouVisitWithPoints, MSGBOX_DEFAULT
	special CloseBattlePointsWindow
	release
	end

VerdanturfTown_BattleTentLobby_ExchangeServiceCorner_EventScript_ChooseHoldItem::
	setvar VAR_0x8004, SCROLL_MULTI_VT_EXCHANGE_CORNER_EVOLVE_ITEM_VENDOR
	special ShowFrontierExchangeCornerItemIconWindow
	special ShowScrollableMultichoice
	waitstate
	special CloseFrontierExchangeCornerItemIconWindow
	switch VAR_RESULT
	case 0, VerdanturfTown_BattleTentLobby_ExchangeServiceCorner_EventScript_FireStone
	case 1, VerdanturfTown_BattleTentLobby_ExchangeServiceCorner_EventScript_WaterStone
	case 2, VerdanturfTown_BattleTentLobby_ExchangeServiceCorner_EventScript_ThunderStone
	case 3, VerdanturfTown_BattleTentLobby_ExchangeServiceCorner_EventScript_LeafStone
	case 4, VerdanturfTown_BattleTentLobby_ExchangeServiceCorner_EventScript_MoonStone
	case 5, VerdanturfTown_BattleTentLobby_ExchangeServiceCorner_EventScript_SunStone
	case 6, VerdanturfTown_BattleTentLobby_ExchangeServiceCorner_EventScript_ShinyStone
	case 7, VerdanturfTown_BattleTentLobby_ExchangeServiceCorner_EventScript_DuskStone
	case 8, VerdanturfTown_BattleTentLobby_ExchangeServiceCorner_EventScript_DawnStone
	case 9, VerdanturfTown_BattleTentLobby_ExchangeServiceCorner_EventScript_IceStone
	case 10, VerdanturfTown_BattleTentLobby__ExchangeServiceCorner_EventScript_ClerkGoodbye
	case MULTI_B_PRESSED, VerdanturfTown_BattleTentLobby__ExchangeServiceCorner_EventScript_ClerkGoodbye
	end

VerdanturfTown_BattleTentLobby_ExchangeServiceCorner_EventScript_FireStone::
	msgbox VerdanturfTown_BattleTentLobby_ExchangeServiceCorner_Text_ConfirmFireStone, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq VerdanturfTown_BattleTentLobby_ExchangeServiceCorner_EventScript_ChooseHoldItem
	setvar VAR_0x8008, 64
	setvar VAR_0x8009, ITEM_CHIPPED_POT
	goto VerdanturfTown_BattleTentLobby_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

VerdanturfTown_BattleTentLobby_ExchangeServiceCorner_EventScript_WaterStone::
	msgbox VerdanturfTown_BattleTentLobby_ExchangeServiceCorner_Text_ConfirmWaterStone, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq VerdanturfTown_BattleTentLobby_ExchangeServiceCorner_EventScript_ChooseHoldItem
	setvar VAR_0x8008, 64
	setvar VAR_0x8009, ITEM_CRACKED_POT
	goto VerdanturfTown_BattleTentLobby_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

VerdanturfTown_BattleTentLobby_ExchangeServiceCorner_EventScript_ThunderStone::
	msgbox VerdanturfTown_BattleTentLobby_ExchangeServiceCorner_Text_ConfirmThunderStone, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq VerdanturfTown_BattleTentLobby_ExchangeServiceCorner_EventScript_ChooseHoldItem
	setvar VAR_0x8008, 64
	setvar VAR_0x8009, ITEM_GALARICA_CUFF
	goto VerdanturfTown_BattleTentLobby_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

VerdanturfTown_BattleTentLobby_ExchangeServiceCorner_EventScript_LeafStone::
	msgbox VerdanturfTown_BattleTentLobby_ExchangeServiceCorner_Text_ConfirmLeafStone, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq VerdanturfTown_BattleTentLobby_ExchangeServiceCorner_EventScript_ChooseHoldItem
	setvar VAR_0x8008, 64
	setvar VAR_0x8009, ITEM_GALARICA_WREATH
	goto VerdanturfTown_BattleTentLobby_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

VerdanturfTown_BattleTentLobby_ExchangeServiceCorner_EventScript_MoonStone::
	msgbox VerdanturfTown_BattleTentLobby_ExchangeServiceCorner_Text_ConfirmMoonStone, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq VerdanturfTown_BattleTentLobby_ExchangeServiceCorner_EventScript_ChooseHoldItem
	setvar VAR_0x8008, 99
	setvar VAR_0x8009, ITEM_SWEET_APPLE
	goto VerdanturfTown_BattleTentLobby_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

VerdanturfTown_BattleTentLobby_ExchangeServiceCorner_EventScript_SunStone::
	msgbox VerdanturfTown_BattleTentLobby_ExchangeServiceCorner_Text_ConfirmSunStone, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq VerdanturfTown_BattleTentLobby_ExchangeServiceCorner_EventScript_ChooseHoldItem
	setvar VAR_0x8008, 99
	setvar VAR_0x8009, ITEM_TART_APPLE
	goto VerdanturfTown_BattleTentLobby_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

VerdanturfTown_BattleTentLobby_ExchangeServiceCorner_EventScript_ShinyStone::
	msgbox VerdanturfTown_BattleTentLobby_ExchangeServiceCorner_Text_ConfirmShinyStone, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq VerdanturfTown_BattleTentLobby_ExchangeServiceCorner_EventScript_ChooseHoldItem
	setvar VAR_0x8008, 128
	setvar VAR_0x8009, ITEM_RAZOR_CLAW
	goto VerdanturfTown_BattleTentLobby_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

VerdanturfTown_BattleTentLobby_ExchangeServiceCorner_EventScript_DuskStone::
	msgbox VerdanturfTown_BattleTentLobby_ExchangeServiceCorner_Text_ConfirmDuskStone, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq VerdanturfTown_BattleTentLobby_ExchangeServiceCorner_EventScript_ChooseHoldItem
	setvar VAR_0x8008, 128
	setvar VAR_0x8009, ITEM_RAZOR_FANG
	goto VerdanturfTown_BattleTentLobby_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

VerdanturfTown_BattleTentLobby_ExchangeServiceCorner_EventScript_DawnStone::
	msgbox VerdanturfTown_BattleTentLobby_ExchangeServiceCorner_Text_ConfirmDawnStone, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq VerdanturfTown_BattleTentLobby_ExchangeServiceCorner_EventScript_ChooseHoldItem
	setvar VAR_0x8008, 128
	setvar VAR_0x8009, ITEM_PEAT_BLOCK
	goto VerdanturfTown_BattleTentLobby_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

VerdanturfTown_BattleTentLobby_ExchangeServiceCorner_EventScript_IceStone::
	msgbox VerdanturfTown_BattleTentLobby_ExchangeServiceCorner_Text_ConfirmIceStone, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq VerdanturfTown_BattleTentLobby_ExchangeServiceCorner_EventScript_ChooseHoldItem
	setvar VAR_0x8008, 128
	setvar VAR_0x8009, ITEM_BLACK_AUGURITE
	goto VerdanturfTown_BattleTentLobby_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

VerdanturfTown_BattleTentLobby_ExchangeServiceCorner_EventScript_TryPurchasePrize::
	specialvar VAR_TEMP_1, GetVerdanturfTentPoints
	compare VAR_TEMP_1, VAR_0x8008
	goto_if_ge VerdanturfTown_BattleTentLobby_ExchangeServiceCorner_EventScript_TryGiveItem
	msgbox VerdanturfTown_BattleTentLobby_ExchangeServiceCorner_Text_DontHaveEnoughPoints, MSGBOX_DEFAULT
	goto VerdanturfTown_BattleTentLobby_ExchangeServiceCorner_EventScript_ChooseHoldItem
	end

VerdanturfTown_BattleTentLobby_ExchangeServiceCorner_EventScript_TryGiveItem::
	checkitemspace VAR_0x8009, 1
	compare VAR_RESULT, FALSE
	goto_if_eq BattleFrontier_ExchangeServiceCorner_EventScript_BagFull	
	copyvar VAR_0x8004, VAR_0x8008
	special TakeVerdanturfTentPoints
	additem VAR_0x8009
	special UpdateVerdanturfPointsWindow
	playse SE_SHOP
	msgbox BattleFrontier_ExchangeServiceCorner_Text_HereIsYourPrize, MSGBOX_DEFAULT
	goto VerdanturfTown_BattleTentLobby_ExchangeServiceCorner_EventScript_ChooseHoldItem
	end

VerdanturfTown_BattleTentLobby_ExchangeServiceCorner_Text_WelcomePleaseChoosePrize:
	.string "Hello, this is the Exchange Service\n"
	.string "Corner.\p"
	.string "We exchange the Verdanturf Points you\n"
	.string "have collected for lovely prizes.\p"
	.string "Please choose a prize from this list.$"

VerdanturfTown_BattleTentLobby_ExchangeServiceCorner_Text_ConfirmFireStone:
	.string "You've chosen the Chipped Pot.\n"
	.string "Is that correct?$"

VerdanturfTown_BattleTentLobby_ExchangeServiceCorner_Text_ConfirmWaterStone:
	.string "You've chosen the Cracked Pot.\n"
	.string "Is that correct?$"

VerdanturfTown_BattleTentLobby_ExchangeServiceCorner_Text_ConfirmThunderStone:
	.string "You've chosen the Galarica Cuff.\n"
	.string "Is that correct?$"

VerdanturfTown_BattleTentLobby_ExchangeServiceCorner_Text_ConfirmLeafStone:
	.string "You've chosen the Galarica Wreath.\n"
	.string "Is that correct?$"

VerdanturfTown_BattleTentLobby_ExchangeServiceCorner_Text_ConfirmMoonStone:
	.string "You've chosen the Sweet Apple.\n"
	.string "Is that correct?$"

VerdanturfTown_BattleTentLobby_ExchangeServiceCorner_Text_ConfirmSunStone:
	.string "You've chosen the Tart Apple.\n"
	.string "Is that correct?$"

VerdanturfTown_BattleTentLobby_ExchangeServiceCorner_Text_ConfirmShinyStone:
	.string "You've chosen the Razor Claw.\n"
	.string "Is that correct?$"

VerdanturfTown_BattleTentLobby_ExchangeServiceCorner_Text_ConfirmDuskStone:
	.string "You've chosen the Razor Fang.\n"
	.string "Is that correct?$"

VerdanturfTown_BattleTentLobby_ExchangeServiceCorner_Text_ConfirmDawnStone:
	.string "You've chosen the Peat Block.\n"
	.string "Is that correct?$"

VerdanturfTown_BattleTentLobby_ExchangeServiceCorner_Text_ConfirmIceStone:
	.string "You've chosen the Black Augurite.\n"
	.string "Is that correct?$"

VerdanturfTown_BattleTentLobby_ExchangeServiceCorner_Text_ThankYouVisitWithPoints:
	.string "Thank you very much.\p"
	.string "Please visit us when you have\n"
	.string "saved up Verdanturf Points.$"

VerdanturfTown_BattleTentLobby_ExchangeServiceCorner_Text_DontHaveEnoughPoints:
	.string "I'm so sorry…\n"
	.string "You don't have enough Verdanturf Points…$"

