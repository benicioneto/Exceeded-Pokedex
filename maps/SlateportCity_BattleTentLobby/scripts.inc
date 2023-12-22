.set LOCALID_ATTENDANT, 1

SlateportCity_BattleTentLobby_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, SlateportCity_BattleTentLobby_OnFrame
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, SlateportCity_BattleTentLobby_OnWarp
	.byte 0

SlateportCity_BattleTentLobby_OnWarp:
	map_script_2 VAR_TEMP_1, 0, SlateportCity_BattleTentLobby_EventScript_TurnPlayerNorth
	.2byte 0

SlateportCity_BattleTentLobby_EventScript_TurnPlayerNorth::
	setvar VAR_TEMP_1, 1
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
	end

SlateportCity_BattleTentLobby_OnFrame:
	map_script_2 VAR_TEMP_0, 0, SlateportCity_BattleTentLobby_EventScript_GetChallengeStatus
	map_script_2 VAR_TEMP_0, CHALLENGE_STATUS_SAVING, SlateportCity_BattleTentLobby_EventScript_QuitWithoutSaving
	map_script_2 VAR_TEMP_0, CHALLENGE_STATUS_PAUSED, SlateportCity_BattleTentLobby_EventScript_ResumeChallenge
	map_script_2 VAR_TEMP_0, CHALLENGE_STATUS_WON, SlateportCity_BattleTentLobby_EventScript_WonChallenge
	map_script_2 VAR_TEMP_0, CHALLENGE_STATUS_LOST, SlateportCity_BattleTentLobby_EventScript_LostChallenge
	.2byte 0

SlateportCity_BattleTentLobby_EventScript_GetChallengeStatus::
	frontier_getstatus
	end

SlateportCity_BattleTentLobby_EventScript_QuitWithoutSaving::
	lockall
	msgbox SlateportCity_BattleTentLobby_Text_DidntSaveBeforeQuitting, MSGBOX_DEFAULT
	closemessage
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, 0
	setvar VAR_TEMP_0, 255
	frontier_set FRONTIER_DATA_LVL_MODE, FRONTIER_LVL_50
	releaseall
	end

SlateportCity_BattleTentLobby_EventScript_WonChallenge::
	lockall
	message SlateportCity_BattleTentLobby_Text_WonThreeMatchesReturnMons2
	waitmessage
	slateporttent_setrandomprize
	frontier_set FRONTIER_DATA_LVL_MODE, FRONTIER_LVL_50
	slateporttent_save 0
	playse SE_SAVE
	waitse
	goto SlateportCity_BattleTentLobby_EventScript_GivePrize
@SlateportCity_BattleTentLobby_EventScript_GivePrize::
@	msgbox SlateportCity_BattleTentLobby_Text_AwardYouThisPrize, MSGBOX_DEFAULT
@	slateporttent_giveprize
@	switch VAR_RESULT
@	case FALSE, SlateportCity_BattleTentLobby_EventScript_NoRoomForPrize
@	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, 0
@	message BattleFrontier_BattleTowerLobby_Text_ReceivedPrize  @ Odd that it uses Tower's instead of Factory's or its own
@	waitmessage
@	playfanfare MUS_OBTAIN_ITEM
@	waitfanfare
@	goto SlateportCity_BattleTentLobby_EventScript_EndGivePrize

SlateportCity_BattleTentLobby_EventScript_NoRoomForPrize::
	msgbox BattleTentLobby_Text_NoRoomInBagMakeRoom, MSGBOX_DEFAULT
	slateporttent_givepoints
	msgbox BattleFrontier_Text_ObtainedXSlateportPoints, MSGBOX_GETPOINTS
	goto SlateportCity_BattleTentLobby_EventScript_EndGivePrize

SlateportCity_BattleTentLobby_EventScript_LostChallenge::
	lockall
	message SlateportCity_BattleTentLobby_Text_ReturnRentalMonsSaveResults
	waitmessage
	slateporttent_setrandomprize
	frontier_set FRONTIER_DATA_LVL_MODE, FRONTIER_LVL_50
	slateporttent_save 0
	playse SE_SAVE
	waitse

SlateportCity_BattleTentLobby_EventScript_EndGivePrize::
	msgbox BattleTentLobby_Text_LookForwardToNextVisit, MSGBOX_DEFAULT
	closemessage
	setvar VAR_TEMP_0, 255
	releaseall
	end

SlateportCity_BattleTentLobby_EventScript_ResumeChallenge::
	lockall
	message SlateportCity_BattleTentLobby_Text_BeenWaitingForYou
	waitmessage
	slateporttent_save CHALLENGE_STATUS_SAVING
	playse SE_SAVE
	waitse
	frontier_set FRONTIER_DATA_PAUSED, FALSE
	setvar VAR_TEMP_0, 255
	setvar VAR_0x8006, 2
	goto SlateportCity_BattleTentLobby_EventScript_EnterChallenge

SlateportCity_BattleTentLobby_EventScript_Attendant::
	lock
	faceplayer
	slateporttent_getprize
	compare VAR_RESULT, ITEM_NONE
	goto_if_ne SlateportCity_BattleTentLobby_EventScript_GivePrize
	special SavePlayerParty
	msgbox SlateportCity_BattleTentLobby_Text_WelcomeToBattleTent, MSGBOX_DEFAULT
SlateportCity_BattleTentLobby_EventScript_AskEnterChallenge::
	message SlateportCity_BattleTentLobby_Text_TakeChallenge
	waitmessage
	multichoice 17, 6, MULTI_CHALLENGEINFO, FALSE
	switch VAR_RESULT
	case 0, SlateportCity_BattleTentLobby_EventScript_TryEnterChallenge
	case 1, SlateportCity_BattleTentLobby_EventScript_ExplainChallenge
	case 2, SlateportCity_BattleTentLobby_EventScript_CancelChallenge
	case MULTI_B_PRESSED, SlateportCity_BattleTentLobby_EventScript_CancelChallenge

SlateportCity_BattleTentLobby_EventScript_TryEnterChallenge::
	setvar VAR_FRONTIER_FACILITY, FRONTIER_FACILITY_FACTORY
	setvar VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES
	frontier_set FRONTIER_DATA_LVL_MODE, FRONTIER_LVL_TENT
	msgbox SlateportCity_BattleTentLobby_Text_SaveBeforeChallenge, MSGBOX_YESNO
	switch VAR_RESULT
	case NO, SlateportCity_BattleTentLobby_EventScript_LoadPartyCancelChallenge
	case YES, SlateportCity_BattleTentLobby_EventScript_SaveBeforeChallenge
	case MULTI_B_PRESSED, SlateportCity_BattleTentLobby_EventScript_LoadPartyCancelChallenge

SlateportCity_BattleTentLobby_EventScript_SaveBeforeChallenge::
	setvar VAR_TEMP_0, 0
	frontier_set FRONTIER_DATA_SELECTED_MON_ORDER
	slateporttent_init
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, CHALLENGE_STATUS_SAVING
	frontier_set FRONTIER_DATA_PAUSED, FALSE
	closemessage
	delay 2
	call Common_EventScript_SaveGame
	setvar VAR_TEMP_0, 255
	compare VAR_RESULT, 0
	goto_if_eq SlateportCity_BattleTentLobby_EventScript_CancelChallengeSaveFailed
	setvar VAR_0x8006, 0
SlateportCity_BattleTentLobby_EventScript_EnterChallenge::
	msgbox SlateportCity_BattleTentLobby_Text_StepThisWay, MSGBOX_DEFAULT
	closemessage
	call SlateportCity_BattleTentLobby_EventScript_WalkToDoor
	warp MAP_SLATEPORT_CITY_BATTLE_TENT_CORRIDOR, 255, 2, 7
	setvar VAR_TEMP_0, 0
	waitstate
	end

SlateportCity_BattleTentLobby_EventScript_WalkToDoor::
	applymovement LOCALID_ATTENDANT, SlateportCity_BattleTentLobby_Movement_AttendantWalkToDoor
	applymovement OBJ_EVENT_ID_PLAYER, SlateportCity_BattleTentLobby_Movement_PlayerWalkToDoor
	waitmovement 0
	opendoor 6, 1
	waitdooranim
	applymovement LOCALID_ATTENDANT, SlateportCity_BattleTentLobby_Movement_AttendantEnterDoor
	applymovement OBJ_EVENT_ID_PLAYER, SlateportCity_BattleTentLobby_Movement_PlayerEnterDoor
	waitmovement 0
	closedoor 6, 1
	waitdooranim
	return

SlateportCity_BattleTentLobby_Movement_AttendantWalkToDoor:
	walk_up
	walk_up
	walk_up
	step_end

SlateportCity_BattleTentLobby_Movement_AttendantEnterDoor:
	walk_up
	set_invisible
	step_end

SlateportCity_BattleTentLobby_Movement_PlayerWalkToDoor:
	walk_up
	walk_up
	walk_up
	step_end

SlateportCity_BattleTentLobby_Movement_PlayerEnterDoor:
	walk_up
	walk_up
	set_invisible
	step_end

SlateportCity_BattleTentLobby_EventScript_ExplainChallenge::
	msgbox SlateportCity_BattleTentLobby_Text_ExplainSlateportTent, MSGBOX_DEFAULT
	goto SlateportCity_BattleTentLobby_EventScript_AskEnterChallenge

SlateportCity_BattleTentLobby_EventScript_CancelChallengeSaveFailed::
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, 0
	goto SlateportCity_BattleTentLobby_EventScript_CancelChallenge

SlateportCity_BattleTentLobby_EventScript_LoadPartyCancelChallenge::
	special LoadPlayerParty
SlateportCity_BattleTentLobby_EventScript_CancelChallenge::
	msgbox BattleTentLobby_Text_LookForwardToNextVisit, MSGBOX_DEFAULT
	release
	end

@ Unused
SlateportCity_BattleTentLobby_Movement_UnusedEnterDoor::
	walk_up
	walk_up
	walk_up
	set_invisible
	step_end

SlateportCity_BattleTentLobby_EventScript_TormentGiver::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_TM41, SlateportCity_BattleTentLobby_EventScript_ReceivedTorment
	msgbox SlateportCity_BattleTentLobby_Text_CouldntFindMonForMe, MSGBOX_DEFAULT
	giveitem ITEM_TM41
	compare VAR_RESULT, FALSE
	goto_if_eq Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_TM41
	msgbox SlateportCity_BattleTentLobby_Text_ExplainTorment, MSGBOX_DEFAULT
	release
	end

SlateportCity_BattleTentLobby_EventScript_ReceivedTorment::
	msgbox SlateportCity_BattleTentLobby_Text_ExplainTorment, MSGBOX_DEFAULT
	release
	end

SlateportCity_BattleTentLobby_EventScript_Man::
	msgbox SlateportCity_BattleTentLobby_Text_IllTryUsingBugMons, MSGBOX_NPC
	end

SlateportCity_BattleTentLobby_EventScript_Girl::
	msgbox SlateportCity_BattleTentLobby_Text_BattleEvenWithoutToughMons, MSGBOX_NPC
	end

SlateportCity_BattleTentLobby_EventScript_Woman::
	msgbox SlateportCity_BattleTentLobby_Text_NiceIfMoreSelection, MSGBOX_NPC
	end

SlateportCity_BattleTentLobby_EventScript_RulesBoard::
	lockall
	msgbox BattleFrontier_BattleFactoryLobby_Text_RulesAreListed, MSGBOX_DEFAULT
	goto SlateportCity_BattleTentLobby_EventScript_ReadRulesBoard
	end

SlateportCity_BattleTentLobby_EventScript_ReadRulesBoard::
	message BattleFrontier_BattleFactoryLobby_Text_ReadWhichHeading
	waitmessage
	multichoice 17, 0, MULTI_SLATEPORT_TENT_RULES, FALSE
	switch VAR_RESULT
	case 0, SlateportCity_BattleTentLobby_EventScript_RulesBasics
	case 1, SlateportCity_BattleTentLobby_EventScript_RulesSwapPartner
	case 2, SlateportCity_BattleTentLobby_EventScript_RulesSwapNumber
	case 3, SlateportCity_BattleTentLobby_EventScript_RulesSwapNotes
	case 4, SlateportCity_BattleTentLobby_EventScript_RulesMons
	case 5, SlateportCity_BattleTentLobby_EventScript_ExitRules
	case MULTI_B_PRESSED, SlateportCity_BattleTentLobby_EventScript_ExitRules
	end

SlateportCity_BattleTentLobby_EventScript_RulesBasics::
	msgbox SlateportCity_BattleTentLobby_Text_ExplainBasicRules, MSGBOX_DEFAULT
	goto SlateportCity_BattleTentLobby_EventScript_ReadRulesBoard
	end

SlateportCity_BattleTentLobby_EventScript_RulesSwapPartner::
	msgbox SlateportCity_BattleTentLobby_Text_ExplainSwapPartnerRules, MSGBOX_DEFAULT
	goto SlateportCity_BattleTentLobby_EventScript_ReadRulesBoard
	end

SlateportCity_BattleTentLobby_EventScript_RulesSwapNumber::
	msgbox SlateportCity_BattleTentLobby_Text_ExplainSwapNumberRules, MSGBOX_DEFAULT
	goto SlateportCity_BattleTentLobby_EventScript_ReadRulesBoard
	end

SlateportCity_BattleTentLobby_EventScript_RulesSwapNotes::
	msgbox SlateportCity_BattleTentLobby_Text_ExplainSwapNotes, MSGBOX_DEFAULT
	goto SlateportCity_BattleTentLobby_EventScript_ReadRulesBoard
	end

SlateportCity_BattleTentLobby_EventScript_RulesMons::
	msgbox SlateportCity_BattleTentLobby_Text_ExplainMonRules, MSGBOX_DEFAULT
	goto SlateportCity_BattleTentLobby_EventScript_ReadRulesBoard
	end

SlateportCity_BattleTentLobby_EventScript_ExitRules::
	releaseall
	end

SlateportCity_BattleTentLobby_Text_CouldntFindMonForMe:
	.string "So, like, I couldn't find myself any\n"
	.string "Pokémon that were, like, for me.\p"
	.string "So, I figured, like, hey, I should file\n"
	.string "a complaint to the guy there?\p"
	.string "And he wouldn't hear me out, like, hey!\n"
	.string "So, like, total bummer, man!\p"
	.string "Hey, like, you! Zip it, you know?\n"
	.string "Just, you know, take this!$"

SlateportCity_BattleTentLobby_Text_ExplainTorment:
	.string "That's, like, TM41, you know?\n"
	.string "Hey, it's Torment, you hearing me?\p"
	.string "Like, it won't let the other guy\n"
	.string "use the same move twice in a row, see?\p"
	.string "Hey, now, you listen here, like,\n"
	.string "I'm not laying a torment on you!$"

SlateportCity_BattleTentLobby_Text_IllTryUsingBugMons:
	.string "I don't really like Bug Pokémon,\n"
	.string "but maybe I'll try using some for\l"
	.string "a change of pace.\p"
	.string "Who knows, I might even get to like\n"
	.string "them!$"

SlateportCity_BattleTentLobby_Text_BattleEvenWithoutToughMons:
	.string "You can battle all you want here even\n"
	.string "if you don't have any tough Pokémon.$"

SlateportCity_BattleTentLobby_Text_NiceIfMoreSelection:
	.string "Wouldn't it be nice if they had more of\n"
	.string "a selection?$"

@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
@		New Code
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

SlateportCity_BattleTentLobby_EventScript_GivePrize::
	msgbox SlateportCity_BattleTentLobby_Text_AwardYouThisPrize2, MSGBOX_DEFAULT
	slateporttent_giveprize
	switch VAR_RESULT
	case FALSE, SlateportCity_BattleTentLobby_EventScript_NoRoomForPrize
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, 0
	message BattleFrontier_BattleTowerLobby_Text_ReceivedPrize2
	waitmessage
	playfanfare MUS_OBTAIN_ITEM
	waitfanfare
	slateporttent_givepoints
	msgbox BattleFrontier_Text_ObtainedXSlateportPoints, MSGBOX_GETPOINTS
	goto SlateportCity_BattleTentLobby_EventScript_EndGivePrize

SlateportCity_BattleTentLobby_Text_AwardYouThisPrize2:
	.string "In recognition,\n"
	.string "we award you this prize.$"

BattleFrontier_Text_ObtainedXSlateportPoints:
	.string "{PLAYER} obtained {STR_VAR_2} Slateport\n"
	.string "Point(s).$"

SlateportCity_BattleTentLobby_ExchangeServiceCorner_EventScript_HoldItemClerk::
	lock
	faceplayer
	setvar VAR_TEMP_2, EXCHANGE_CORNER_HOLD_ITEM_CLERK
	call SlateportCity_BattleTentLobby_ExchangeServiceCorner_EventScript_ClerkWelcome
	goto SlateportCity_BattleTentLobby_ExchangeServiceCorner_EventScript_ChooseHoldItem
	end

SlateportCity_BattleTentLobby_ExchangeServiceCorner_EventScript_ClerkWelcome::
	msgbox SlateportCity_BattleTentLobby_ExchangeServiceCorner_Text_WelcomePleaseChoosePrize, MSGBOX_DEFAULT
	special ShowSlateportPointsWindow
	return

SlateportCity_BattleTentLobby__ExchangeServiceCorner_EventScript_ClerkGoodbye::
	msgbox SlateportCity_BattleTentLobby_ExchangeServiceCorner_Text_ThankYouVisitWithPoints, MSGBOX_DEFAULT
	special CloseBattlePointsWindow
	release
	end

SlateportCity_BattleTentLobby_ExchangeServiceCorner_EventScript_ChooseHoldItem::
	setvar VAR_0x8004, SCROLL_MULTI_ST_EXCHANGE_CORNER_EVOLVE_STONE_VENDOR
	special ShowFrontierExchangeCornerItemIconWindow
	special ShowScrollableMultichoice
	waitstate
	special CloseFrontierExchangeCornerItemIconWindow
	switch VAR_RESULT
	case 0, SlateportCity_BattleTentLobby_ExchangeServiceCorner_EventScript_FireStone
	case 1, SlateportCity_BattleTentLobby_ExchangeServiceCorner_EventScript_WaterStone
	case 2, SlateportCity_BattleTentLobby_ExchangeServiceCorner_EventScript_ThunderStone
	case 3, SlateportCity_BattleTentLobby_ExchangeServiceCorner_EventScript_LeafStone
	case 4, SlateportCity_BattleTentLobby_ExchangeServiceCorner_EventScript_MoonStone
	case 5, SlateportCity_BattleTentLobby_ExchangeServiceCorner_EventScript_SunStone
	case 6, SlateportCity_BattleTentLobby_ExchangeServiceCorner_EventScript_ShinyStone
	case 7, SlateportCity_BattleTentLobby_ExchangeServiceCorner_EventScript_DuskStone
	case 8, SlateportCity_BattleTentLobby_ExchangeServiceCorner_EventScript_DawnStone
	case 9, SlateportCity_BattleTentLobby_ExchangeServiceCorner_EventScript_IceStone
	case 10, SlateportCity_BattleTentLobby__ExchangeServiceCorner_EventScript_ClerkGoodbye
	case MULTI_B_PRESSED, SlateportCity_BattleTentLobby__ExchangeServiceCorner_EventScript_ClerkGoodbye
	end

SlateportCity_BattleTentLobby_ExchangeServiceCorner_EventScript_FireStone::
	msgbox SlateportCity_BattleTentLobby_ExchangeServiceCorner_Text_ConfirmFireStone, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq SlateportCity_BattleTentLobby_ExchangeServiceCorner_EventScript_ChooseHoldItem
	setvar VAR_0x8008, 48
	setvar VAR_0x8009, ITEM_FIRE_STONE
	goto SlateportCity_BattleTentLobby_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

SlateportCity_BattleTentLobby_ExchangeServiceCorner_EventScript_WaterStone::
	msgbox SlateportCity_BattleTentLobby_ExchangeServiceCorner_Text_ConfirmWaterStone, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq SlateportCity_BattleTentLobby_ExchangeServiceCorner_EventScript_ChooseHoldItem
	setvar VAR_0x8008, 48
	setvar VAR_0x8009, ITEM_WATER_STONE
	goto SlateportCity_BattleTentLobby_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

SlateportCity_BattleTentLobby_ExchangeServiceCorner_EventScript_ThunderStone::
	msgbox SlateportCity_BattleTentLobby_ExchangeServiceCorner_Text_ConfirmThunderStone, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq SlateportCity_BattleTentLobby_ExchangeServiceCorner_EventScript_ChooseHoldItem
	setvar VAR_0x8008, 48
	setvar VAR_0x8009, ITEM_THUNDER_STONE
	goto SlateportCity_BattleTentLobby_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

SlateportCity_BattleTentLobby_ExchangeServiceCorner_EventScript_LeafStone::
	msgbox SlateportCity_BattleTentLobby_ExchangeServiceCorner_Text_ConfirmLeafStone, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq SlateportCity_BattleTentLobby_ExchangeServiceCorner_EventScript_ChooseHoldItem
	setvar VAR_0x8008, 48
	setvar VAR_0x8009, ITEM_LEAF_STONE
	goto SlateportCity_BattleTentLobby_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

SlateportCity_BattleTentLobby_ExchangeServiceCorner_EventScript_MoonStone::
	msgbox SlateportCity_BattleTentLobby_ExchangeServiceCorner_Text_ConfirmMoonStone, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq SlateportCity_BattleTentLobby_ExchangeServiceCorner_EventScript_ChooseHoldItem
	setvar VAR_0x8008, 64
	setvar VAR_0x8009, ITEM_MOON_STONE
	goto SlateportCity_BattleTentLobby_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

SlateportCity_BattleTentLobby_ExchangeServiceCorner_EventScript_SunStone::
	msgbox SlateportCity_BattleTentLobby_ExchangeServiceCorner_Text_ConfirmSunStone, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq SlateportCity_BattleTentLobby_ExchangeServiceCorner_EventScript_ChooseHoldItem
	setvar VAR_0x8008, 64
	setvar VAR_0x8009, ITEM_SUN_STONE
	goto SlateportCity_BattleTentLobby_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

SlateportCity_BattleTentLobby_ExchangeServiceCorner_EventScript_ShinyStone::
	msgbox SlateportCity_BattleTentLobby_ExchangeServiceCorner_Text_ConfirmShinyStone, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq SlateportCity_BattleTentLobby_ExchangeServiceCorner_EventScript_ChooseHoldItem
	setvar VAR_0x8008, 128
	setvar VAR_0x8009, ITEM_SHINY_STONE
	goto SlateportCity_BattleTentLobby_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

SlateportCity_BattleTentLobby_ExchangeServiceCorner_EventScript_DuskStone::
	msgbox SlateportCity_BattleTentLobby_ExchangeServiceCorner_Text_ConfirmDuskStone, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq SlateportCity_BattleTentLobby_ExchangeServiceCorner_EventScript_ChooseHoldItem
	setvar VAR_0x8008, 128
	setvar VAR_0x8009, ITEM_DUSK_STONE
	goto SlateportCity_BattleTentLobby_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

SlateportCity_BattleTentLobby_ExchangeServiceCorner_EventScript_DawnStone::
	msgbox SlateportCity_BattleTentLobby_ExchangeServiceCorner_Text_ConfirmDawnStone, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq SlateportCity_BattleTentLobby_ExchangeServiceCorner_EventScript_ChooseHoldItem
	setvar VAR_0x8008, 128
	setvar VAR_0x8009, ITEM_DAWN_STONE
	goto SlateportCity_BattleTentLobby_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

SlateportCity_BattleTentLobby_ExchangeServiceCorner_EventScript_IceStone::
	msgbox SlateportCity_BattleTentLobby_ExchangeServiceCorner_Text_ConfirmIceStone, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq SlateportCity_BattleTentLobby_ExchangeServiceCorner_EventScript_ChooseHoldItem
	setvar VAR_0x8008, 128
	setvar VAR_0x8009, ITEM_ICE_STONE
	goto SlateportCity_BattleTentLobby_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

SlateportCity_BattleTentLobby_ExchangeServiceCorner_EventScript_RazorClaw::
	msgbox SlateportCity_BattleTentLobby_ExchangeServiceCorner_Text_ConfirmRazorClaw, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq SlateportCity_BattleTentLobby_ExchangeServiceCorner_EventScript_ChooseHoldItem
	setvar VAR_0x8008, 48
	setvar VAR_0x8009, ITEM_RAZOR_CLAW
	goto SlateportCity_BattleTentLobby_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

SlateportCity_BattleTentLobby_ExchangeServiceCorner_EventScript_RazorFang::
	msgbox SlateportCity_BattleTentLobby_ExchangeServiceCorner_Text_ConfirmRazorFang, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq SlateportCity_BattleTentLobby_ExchangeServiceCorner_EventScript_ChooseHoldItem
	setvar VAR_0x8008, 48
	setvar VAR_0x8009, ITEM_RAZOR_FANG
	goto SlateportCity_BattleTentLobby_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

SlateportCity_BattleTentLobby_ExchangeServiceCorner_EventScript_Sachet::
	msgbox SlateportCity_BattleTentLobby_ExchangeServiceCorner_Text_ConfirmSachet, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq SlateportCity_BattleTentLobby_ExchangeServiceCorner_EventScript_ChooseHoldItem
	setvar VAR_0x8008, 48
	setvar VAR_0x8009, ITEM_SACHET
	goto SlateportCity_BattleTentLobby_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

SlateportCity_BattleTentLobby_ExchangeServiceCorner_EventScript_TryPurchasePrize::
	specialvar VAR_TEMP_1, GetSlateportTentPoints
	compare VAR_TEMP_1, VAR_0x8008
	goto_if_ge SlateportCity_BattleTentLobby_ExchangeServiceCorner_EventScript_TryGiveItem
	msgbox SlateportCity_BattleTentLobby_ExchangeServiceCorner_Text_DontHaveEnoughPoints, MSGBOX_DEFAULT
	goto SlateportCity_BattleTentLobby_ExchangeServiceCorner_EventScript_ChooseHoldItem
	end

SlateportCity_BattleTentLobby_ExchangeServiceCorner_EventScript_TryGiveItem::
	checkitemspace VAR_0x8009, 1
	compare VAR_RESULT, FALSE
	goto_if_eq BattleFrontier_ExchangeServiceCorner_EventScript_BagFull	
	copyvar VAR_0x8004, VAR_0x8008
	special TakeSlateportTentPoints
	additem VAR_0x8009
	special UpdateSlateportPointsWindow
	playse SE_SHOP
	msgbox BattleFrontier_ExchangeServiceCorner_Text_HereIsYourPrize, MSGBOX_DEFAULT
	goto SlateportCity_BattleTentLobby_ExchangeServiceCorner_EventScript_ChooseHoldItem
	end

SlateportCity_BattleTentLobby_ExchangeServiceCorner_Text_WelcomePleaseChoosePrize:
	.string "Hello, this is the Exchange Service\n"
	.string "Corner.\p"
	.string "We exchange the Slateport Points you\n"
	.string "have collected for lovely prizes.\p"
	.string "Please choose a prize from this list.$"

SlateportCity_BattleTentLobby_ExchangeServiceCorner_Text_ConfirmFireStone:
	.string "You've chosen the Fire Stone.\n"
	.string "Is that correct?$"

SlateportCity_BattleTentLobby_ExchangeServiceCorner_Text_ConfirmWaterStone:
	.string "You've chosen the Water Stone.\n"
	.string "Is that correct?$"

SlateportCity_BattleTentLobby_ExchangeServiceCorner_Text_ConfirmThunderStone:
	.string "You've chosen the Thunder Stone.\n"
	.string "Is that correct?$"

SlateportCity_BattleTentLobby_ExchangeServiceCorner_Text_ConfirmLeafStone:
	.string "You've chosen the Leaf Stone.\n"
	.string "Is that correct?$"

SlateportCity_BattleTentLobby_ExchangeServiceCorner_Text_ConfirmSunStone:
	.string "You've chosen the Sun Stone.\n"
	.string "Is that correct?$"

SlateportCity_BattleTentLobby_ExchangeServiceCorner_Text_ConfirmMoonStone:
	.string "You've chosen the Moon Stone.\n"
	.string "Is that correct?$"

SlateportCity_BattleTentLobby_ExchangeServiceCorner_Text_ConfirmShinyStone:
	.string "You've chosen the Shiny Stone.\n"
	.string "Is that correct?$"

SlateportCity_BattleTentLobby_ExchangeServiceCorner_Text_ConfirmDuskStone:
	.string "You've chosen the Dusk Stone.\n"
	.string "Is that correct?$"

SlateportCity_BattleTentLobby_ExchangeServiceCorner_Text_ConfirmIceStone:
	.string "You've chosen the Ice Stone.\n"
	.string "Is that correct?$"

SlateportCity_BattleTentLobby_ExchangeServiceCorner_Text_ConfirmDawnStone:
	.string "You've chosen the Dawn Stone.\n"
	.string "Is that correct?$"

SlateportCity_BattleTentLobby_ExchangeServiceCorner_Text_ConfirmRazorClaw:
	.string "You've chosen the Razor Claw.\n"
	.string "Is that correct?$"

SlateportCity_BattleTentLobby_ExchangeServiceCorner_Text_ConfirmRazorFang:
	.string "You've chosen the Razor Fang.\n"
	.string "Is that correct?$"

SlateportCity_BattleTentLobby_ExchangeServiceCorner_Text_ConfirmSachet:
	.string "You've chosen the Sachet.\n"
	.string "Is that correct?$"

SlateportCity_BattleTentLobby_ExchangeServiceCorner_Text_ThankYouVisitWithPoints:
	.string "Thank you very much.\p"
	.string "Please visit us when you have\n"
	.string "saved up Slateport Points.$"

SlateportCity_BattleTentLobby_ExchangeServiceCorner_Text_DontHaveEnoughPoints:
	.string "I'm so sorry…\n"
	.string "You don't have enough Slateport Points…$"
