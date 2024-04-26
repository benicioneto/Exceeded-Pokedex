.set LOCALID_ATTENDANT, 1

FallarborTown_BattleTentLobby_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, FallarborTown_BattleTentLobby_OnFrame
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, FallarborTown_BattleTentLobby_OnWarp
	.byte 0

FallarborTown_BattleTentLobby_OnWarp:
	map_script_2 VAR_TEMP_1, 0, FallarborTown_BattleTentLobby_EventScript_TurnPlayerNorth
	.2byte 0

FallarborTown_BattleTentLobby_EventScript_TurnPlayerNorth::
	setvar VAR_TEMP_1, 1
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
	end

FallarborTown_BattleTentLobby_OnFrame:
	map_script_2 VAR_TEMP_0, 0, FallarborTown_BattleTentLobby_EventScript_GetChallengeStatus
	map_script_2 VAR_TEMP_0, CHALLENGE_STATUS_SAVING, FallarborTown_BattleTentLobby_EventScript_QuitWithoutSaving
	map_script_2 VAR_TEMP_0, CHALLENGE_STATUS_PAUSED, FallarborTown_BattleTentLobby_EventScript_ResumeChallenge
	map_script_2 VAR_TEMP_0, CHALLENGE_STATUS_WON, FallarborTown_BattleTentLobby_EventScript_WonChallenge
	map_script_2 VAR_TEMP_0, CHALLENGE_STATUS_LOST, FallarborTown_BattleTentLobby_EventScript_LostChallenge
	.2byte 0

FallarborTown_BattleTentLobby_EventScript_GetChallengeStatus::
	frontier_getstatus
	end

FallarborTown_BattleTentLobby_EventScript_QuitWithoutSaving::
	lockall
	msgbox FallarborTown_BattleTentLobby_Text_DidntSaveBeforeQuitting, MSGBOX_DEFAULT
	closemessage
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, 0
	setvar VAR_TEMP_0, 255
	frontier_set FRONTIER_DATA_LVL_MODE, FRONTIER_LVL_50
	releaseall
	end

FallarborTown_BattleTentLobby_EventScript_WonChallenge::
	lockall
	message BattleTentLobby_Text_WonThreeMatchesReturnMons2
	waitmessage
	fallarbortent_setrandomprize
	frontier_set FRONTIER_DATA_LVL_MODE, FRONTIER_LVL_50
	fallarbortent_save 0
	playse SE_SAVE
	waitse
	goto FallarborTown_BattleTentLobby_EventScript_GivePrize

FallarborTown_BattleTentLobby_EventScript_EndGivePrize::
	msgbox BattleTentLobby_Text_LookForwardToNextVisit, MSGBOX_DEFAULT
	closemessage
	setvar VAR_TEMP_0, 255
	releaseall
	end

@FallarborTown_BattleTentLobby_EventScript_GivePrize::
@	msgbox FallarborTown_BattleTentLobby_Text_PresentYouWithPrize, MSGBOX_DEFAULT
@	fallarbortent_giveprize
@	switch VAR_RESULT
@	case FALSE, FallarborTown_BattleTentLobby_EventScript_NoRoomForPrize
@	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, 0
@	message FallarborTown_BattleTentLobby_Text_ReceivedPrize
@	waitmessage
@	playfanfare MUS_OBTAIN_ITEM
@	waitfanfare
@	msgbox FallarborTown_BattleTentLobby_Text_AwaitAnotherChallenge2, MSGBOX_DEFAULT
@	closemessage
@	setvar VAR_TEMP_0, 255
@	releaseall
@	end

FallarborTown_BattleTentLobby_EventScript_NoRoomForPrize::
	msgbox BattleTentLobby_Text_NoRoomInBagMakeRoom, MSGBOX_DEFAULT
	fallarbortent_givepoints
	msgbox BattleFrontier_Text_ObtainedXFallarborPoints, MSGBOX_GETPOINTS
	goto FallarborTown_BattleTentLobby_EventScript_EndGivePrize

FallarborTown_BattleTentLobby_EventScript_PrizeWaiting::
	lockall
	message BattleTentLobby_Text_WonThreeMatchesReturnMons2 @Ok
	waitmessage
	fallarbortent_setrandomprize
	frontier_set FRONTIER_DATA_LVL_MODE, FRONTIER_LVL_50
	fallarbortent_save 0
	playse SE_SAVE
	waitse
	goto FallarborTown_BattleTentLobby_EventScript_GivePrize

FallarborTown_BattleTentLobby_EventScript_LostChallenge::
	lockall
	message FallarborTown_BattleTentLobby_Text_ThankYouWaitWhileSaving
	waitmessage
	fallarbortent_setrandomprize
	frontier_set FRONTIER_DATA_LVL_MODE, FRONTIER_LVL_50
	fallarbortent_save 0
	playse SE_SAVE
	waitse
	msgbox FallarborTown_BattleTentLobby_Text_AwaitAnotherChallenge2, MSGBOX_DEFAULT
	closemessage
	setvar VAR_TEMP_0, 255
	releaseall
	end

FallarborTown_BattleTentLobby_EventScript_ResumeChallenge::
	lockall
	message FallarborTown_BattleTentLobby_Text_LookingForwardToArrival
	waitmessage
	fallarbortent_save CHALLENGE_STATUS_SAVING
	playse SE_SAVE
	waitse
	frontier_set FRONTIER_DATA_PAUSED, FALSE
	setvar VAR_TEMP_0, 255
	goto FallarborTown_BattleTentLobby_EventScript_EnterChallenge

FallarborTown_BattleTentLobby_EventScript_Attendant::
	lock
	faceplayer
	fallarbortent_getprize
	compare VAR_RESULT, ITEM_NONE
	goto_if_ne FallarborTown_BattleTentLobby_EventScript_GivePrize
	special SavePlayerParty
	msgbox FallarborTown_BattleTentLobby_Text_WelcomeToBattleTent, MSGBOX_DEFAULT
FallarborTown_BattleTentLobby_EventScript_AskEnterChallenge::
	message FallarborTown_BattleTentLobby_Text_TakeChallenge
	waitmessage
	multichoice 17, 6, MULTI_CHALLENGEINFO, FALSE
	switch VAR_RESULT
	case 0, FallarborTown_BattleTentLobby_EventScript_TryEnterChallenge
	case 1, FallarborTown_BattleTentLobby_EventScript_ExplainChallenge
	case 2, FallarborTown_BattleTentLobby_EventScript_CancelChallenge
	case MULTI_B_PRESSED, FallarborTown_BattleTentLobby_EventScript_CancelChallenge

FallarborTown_BattleTentLobby_EventScript_TryEnterChallenge::
	setvar VAR_FRONTIER_FACILITY, FRONTIER_FACILITY_ARENA
	setvar VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES
	setvar VAR_RESULT, 2
	frontier_checkineligible
	compare VAR_0x8004, TRUE
	goto_if_eq FallarborTown_BattleTentLobby_EventScript_NotEnoughValidMons
	frontier_set FRONTIER_DATA_LVL_MODE, FRONTIER_LVL_TENT
	msgbox FallarborTown_BattleTentLobby_Text_SelectThreeMons, MSGBOX_DEFAULT
	fadescreen FADE_TO_BLACK
	setvar VAR_0x8004, 2
	setvar VAR_0x8005, FRONTIER_PARTY_SIZE
	special ChoosePartyForBattleFrontier
	waitstate
	compare VAR_RESULT, 0
	goto_if_eq FallarborTown_BattleTentLobby_EventScript_LoadPartyCancelChallenge
	msgbox FallarborTown_BattleTentLobby_Text_SaveBeforeChallenge, MSGBOX_YESNO
	switch VAR_RESULT
	case NO, FallarborTown_BattleTentLobby_EventScript_LoadPartyCancelChallenge
	case YES, FallarborTown_BattleTentLobby_EventScript_SaveBeforeChallenge
	case MULTI_B_PRESSED, FallarborTown_BattleTentLobby_EventScript_LoadPartyCancelChallenge

FallarborTown_BattleTentLobby_EventScript_SaveBeforeChallenge::
	setvar VAR_TEMP_0, 0
	frontier_set FRONTIER_DATA_SELECTED_MON_ORDER
	fallarbortent_init
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, CHALLENGE_STATUS_SAVING
	frontier_set FRONTIER_DATA_PAUSED, FALSE
	special LoadPlayerParty
	closemessage
	delay 2
	call Common_EventScript_SaveGame
	setvar VAR_TEMP_0, 255
	compare VAR_RESULT, 0
	goto_if_eq FallarborTown_BattleTentLobby_EventScript_CancelChallengeSaveFailed
FallarborTown_BattleTentLobby_EventScript_EnterChallenge::
	special SavePlayerParty
	frontier_setpartyorder FRONTIER_PARTY_SIZE
	msgbox FallarborTown_BattleTentLobby_Text_GuideYouToBattleTent, MSGBOX_DEFAULT
	closemessage
	call FallarborTown_BattleTentLobby_EventScript_WalkToDoor
	warp MAP_FALLARBOR_TOWN_BATTLE_TENT_CORRIDOR, 255, 2, 7
	setvar VAR_TEMP_0, 0
	waitstate
	end

FallarborTown_BattleTentLobby_EventScript_ExplainChallenge::
	msgbox FallarborTown_BattleTentLobby_Text_ExplainFallarborTent, MSGBOX_DEFAULT
	goto FallarborTown_BattleTentLobby_EventScript_AskEnterChallenge

FallarborTown_BattleTentLobby_EventScript_NotEnoughValidMons::
	switch VAR_RESULT
	case FRONTIER_LVL_50, FallarborTown_BattleTentLobby_EventScript_NotEnoughValidMonsLv50
	case FRONTIER_LVL_OPEN, FallarborTown_BattleTentLobby_EventScript_NotEnoughValidMonsLvOpen
FallarborTown_BattleTentLobby_EventScript_NotEnoughValidMonsLv50::
	msgbox FallarborTown_BattleTentLobby_Text_NotEnoughValidMonsLv50, MSGBOX_DEFAULT
	goto FallarborTown_BattleTentLobby_EventScript_EndCancelChallenge

FallarborTown_BattleTentLobby_EventScript_NotEnoughValidMonsLvOpen::
	msgbox FallarborTown_BattleTentLobby_Text_NotEnoughValidMonsLvOpen, MSGBOX_DEFAULT
	goto FallarborTown_BattleTentLobby_EventScript_EndCancelChallenge

FallarborTown_BattleTentLobby_EventScript_CancelChallengeSaveFailed::
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, 0
	goto FallarborTown_BattleTentLobby_EventScript_CancelChallenge

FallarborTown_BattleTentLobby_EventScript_LoadPartyCancelChallenge::
	special LoadPlayerParty
FallarborTown_BattleTentLobby_EventScript_CancelChallenge::
	msgbox FallarborTown_BattleTentLobby_Text_AwaitAnotherChallenge, MSGBOX_DEFAULT
FallarborTown_BattleTentLobby_EventScript_EndCancelChallenge::
	release
	end

FallarborTown_BattleTentLobby_EventScript_WalkToDoor::
	applymovement LOCALID_ATTENDANT, FallarborTown_BattleTentLobby_Movement_AttendantWalkToDoor
	applymovement OBJ_EVENT_ID_PLAYER, FallarborTown_BattleTentLobby_Movement_PlayerWalkToDoor
	waitmovement 0
	opendoor 6, 1
	waitdooranim
	applymovement LOCALID_ATTENDANT, FallarborTown_BattleTentLobby_Movement_AttendantEnterDoor
	applymovement OBJ_EVENT_ID_PLAYER, FallarborTown_BattleTentLobby_Movement_PlayerEnterDoor
	waitmovement 0
	closedoor 6, 1
	waitdooranim
	return

FallarborTown_BattleTentLobby_Movement_AttendantWalkToDoor:
	walk_up
	walk_up
	walk_up
	step_end

FallarborTown_BattleTentLobby_Movement_AttendantEnterDoor:
	walk_up
	set_invisible
	step_end

FallarborTown_BattleTentLobby_Movement_PlayerWalkToDoor:
	walk_up
	walk_up
	walk_up
	step_end

FallarborTown_BattleTentLobby_Movement_PlayerEnterDoor:
	walk_up
	walk_up
	set_invisible
	step_end

FallarborTown_BattleTentLobby_EventScript_Hiker::
	msgbox FallarborTown_BattleTentLobby_Text_CameToCampOut, MSGBOX_NPC
	end

FallarborTown_BattleTentLobby_EventScript_LittleBoy::
	msgbox FallarborTown_BattleTentLobby_Text_MakeThinkImJustKid, MSGBOX_NPC
	end

FallarborTown_BattleTentLobby_EventScript_Lass::
	msgbox FallarborTown_BattleTentLobby_Text_FallarborTentMyFavorite, MSGBOX_NPC
	end

FallarborTown_BattleTentLobby_EventScript_Scott::
	lock
	faceplayer
	goto_if_set FLAG_MET_SCOTT_IN_FALLARBOR, FallarborTown_BattleTentLobby_EventScript_ScottAlreadySpokenTo
	msgbox FallarborTown_BattleTentLobby_Text_ScottLookingForSomeone, MSGBOX_DEFAULT
	addvar VAR_SCOTT_STATE, 1
	setflag FLAG_MET_SCOTT_IN_FALLARBOR
	release
	end

FallarborTown_BattleTentLobby_EventScript_ScottAlreadySpokenTo::
	msgbox FallarborTown_BattleTentLobby_Text_ScottMakeChallenge, MSGBOX_DEFAULT
	release
	end

FallarborTown_BattleTentLobby_EventScript_RulesBoard::
	lockall
	msgbox BattleFrontier_BattleArenaLobby_Text_RulesAreListed, MSGBOX_DEFAULT
	goto FallarborTown_BattleTentLobby_EventScript_ReadRulesBoard
	end

FallarborTown_BattleTentLobby_EventScript_ReadRulesBoard::
	message BattleFrontier_BattleArenaLobby_Text_ReadWhichHeading
	waitmessage
	multichoice 17, 0, MULTI_FALLARBOR_TENT_RULES, FALSE
	switch VAR_RESULT
	case 0, FallarborTown_BattleTentLobby_EventScript_RulesLevel
	case 1, FallarborTown_BattleTentLobby_EventScript_RulesBattle
	case 2, FallarborTown_BattleTentLobby_EventScript_RulesMind
	case 3, FallarborTown_BattleTentLobby_EventScript_RulesSkill
	case 4, FallarborTown_BattleTentLobby_EventScript_RulesBody
	case 5, FallarborTown_BattleTentLobby_EventScript_ExitRules
	case MULTI_B_PRESSED, FallarborTown_BattleTentLobby_EventScript_ExitRules
	end

FallarborTown_BattleTentLobby_EventScript_RulesLevel::
	msgbox BattleTentLobby_Text_ExplainLevelRules, MSGBOX_DEFAULT
	goto FallarborTown_BattleTentLobby_EventScript_ReadRulesBoard
	end

FallarborTown_BattleTentLobby_EventScript_RulesBattle::
	msgbox BattleFrontier_BattleArenaLobby_Text_ExplainBattleRules, MSGBOX_DEFAULT
	goto FallarborTown_BattleTentLobby_EventScript_ReadRulesBoard
	end

FallarborTown_BattleTentLobby_EventScript_RulesMind::
	msgbox BattleFrontier_BattleArenaLobby_Text_ExplainMindRules, MSGBOX_DEFAULT
	goto FallarborTown_BattleTentLobby_EventScript_ReadRulesBoard
	end

FallarborTown_BattleTentLobby_EventScript_RulesSkill::
	msgbox BattleFrontier_BattleArenaLobby_Text_ExplainSkillRules, MSGBOX_DEFAULT
	goto FallarborTown_BattleTentLobby_EventScript_ReadRulesBoard
	end

FallarborTown_BattleTentLobby_EventScript_RulesBody::
	msgbox BattleFrontier_BattleArenaLobby_Text_ExplainBodyRules, MSGBOX_DEFAULT
	goto FallarborTown_BattleTentLobby_EventScript_ReadRulesBoard
	end

FallarborTown_BattleTentLobby_EventScript_ExitRules::
	releaseall
	end

FallarborTown_BattleTentLobby_Text_MakeThinkImJustKid:
	.string "Fufufufufu.\p"
	.string "I'm going to make everyone think\n"
	.string "I'm just a kid and let them play down.\p"
	.string "Then, I'll shock them and grab\n"
	.string "the title!$"

FallarborTown_BattleTentLobby_Text_FallarborTentMyFavorite:
	.string "You know how Battle Tents offer\n"
	.string "different events in different towns?\p"
	.string "My favorite is definitely the Battle\n"
	.string "Tent in Fallarbor Town.\p"
	.string "I think it's fantastic how Trainers\n"
	.string "try to win with all their faith in\l"
	.string "their Pokémon.$"

FallarborTown_BattleTentLobby_Text_CameToCampOut:
	.string "I heard something about some tent,\n"
	.string "so I came to camp out.\p"
	.string "I didn't know that tents these days\n"
	.string "are so luxurious!\p"
	.string "Since I'm here, I may as well try\n"
	.string "my hand at battling!$"

FallarborTown_BattleTentLobby_Text_ScottLookingForSomeone:
	.string "Scott: Hi, {PLAYER}{KUN}!\n"
	.string "So you came out to this Battle Tent!\p"
	.string "The people in these parts tend to be\n"
	.string "easygoing and laid-back.\p"
	.string "But, you see, what I'm looking for are\n"
	.string "people with…\p"
	.string "How should I say this?\p"
	.string "Someone bursting with the desire\n"
	.string "and the drive to win.\p"
	.string "If there were a Trainer like that,\n"
	.string "I'd immediately…\p"
	.string "Whoops! Never mind!\n"
	.string "Keep working at it!$"

FallarborTown_BattleTentLobby_Text_ScottMakeChallenge:
	.string "Scott: Instead of wasting your\n"
	.string "time with the likes of me, why not\l"
	.string "make a challenge?$"


@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
@		New Code
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

FallarborTown_BattleTentLobby_EventScript_GivePrize::
	msgbox FallarborTown_BattleTentLobby_Text_AwardYouThisPrize2, MSGBOX_DEFAULT
	fallarbortent_giveprize
	switch VAR_RESULT
	case FALSE, FallarborTown_BattleTentLobby_EventScript_NoRoomForPrize
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, 0
	message BattleFrontier_BattleTowerLobby_Text_ReceivedPrize2
	waitmessage
	playfanfare MUS_OBTAIN_ITEM
	waitfanfare
	fallarbortent_givepoints
	msgbox BattleFrontier_Text_ObtainedXFallarborPoints, MSGBOX_GETPOINTS
	goto FallarborTown_BattleTentLobby_EventScript_EndGivePrize

FallarborTown_BattleTentLobby_Text_AwardYouThisPrize2:
	.string "In recognition,\n"
	.string "we award you this prize.$"

BattleFrontier_Text_ObtainedXFallarborPoints:
	.string "{PLAYER} obtained {STR_VAR_2} Fallarbor\n"
	.string "Point(s).$"

FallarborTown_BattleTentLobby_ExchangeServiceCorner_EventScript_HoldItemClerk::
	lock
	faceplayer
	setvar VAR_TEMP_2, EXCHANGE_CORNER_HOLD_ITEM_CLERK
	call FallarborTown_BattleTentLobby_ExchangeServiceCorner_EventScript_ClerkWelcome
	goto FallarborTown_BattleTentLobby_ExchangeServiceCorner_EventScript_ChooseHoldItem
	end

FallarborTown_BattleTentLobby_ExchangeServiceCorner_EventScript_ClerkWelcome::
	msgbox FallarborTown_BattleTentLobby_ExchangeServiceCorner_Text_WelcomePleaseChoosePrize, MSGBOX_DEFAULT
	special ShowFallarborPointsWindow
	return

FallarborTown_BattleTentLobby__ExchangeServiceCorner_EventScript_ClerkGoodbye::
	msgbox FallarborTown_BattleTentLobby_ExchangeServiceCorner_Text_ThankYouVisitWithPoints, MSGBOX_DEFAULT
	special CloseBattlePointsWindow
	release
	end

FallarborTown_BattleTentLobby_ExchangeServiceCorner_EventScript_ChooseHoldItem::
	setvar VAR_0x8004, SCROLL_MULTI_FT_EXCHANGE_CORNER_EVOLVE_ITEM_VENDOR
	special ShowFrontierExchangeCornerItemIconWindow
	special ShowScrollableMultichoice
	waitstate
	special CloseFrontierExchangeCornerItemIconWindow
	switch VAR_RESULT
	case 0, FallarborTown_BattleTentLobby_ExchangeServiceCorner_EventScript_FireStone
	case 1, FallarborTown_BattleTentLobby_ExchangeServiceCorner_EventScript_WaterStone
	case 2, FallarborTown_BattleTentLobby_ExchangeServiceCorner_EventScript_ThunderStone
	case 3, FallarborTown_BattleTentLobby_ExchangeServiceCorner_EventScript_LeafStone
	case 4, FallarborTown_BattleTentLobby_ExchangeServiceCorner_EventScript_MoonStone
	case 5, FallarborTown_BattleTentLobby_ExchangeServiceCorner_EventScript_SunStone
	case 6, FallarborTown_BattleTentLobby_ExchangeServiceCorner_EventScript_ShinyStone
	case 7, FallarborTown_BattleTentLobby_ExchangeServiceCorner_EventScript_DuskStone
	case 8, FallarborTown_BattleTentLobby_ExchangeServiceCorner_EventScript_DawnStone
	case 9, FallarborTown_BattleTentLobby_ExchangeServiceCorner_EventScript_IceStone
	case 10, FallarborTown_BattleTentLobby_ExchangeServiceCorner_EventScript_PrismScale
	case 11, FallarborTown_BattleTentLobby_ExchangeServiceCorner_EventScript_AuspiciousArmor
	case 12, FallarborTown_BattleTentLobby__ExchangeServiceCorner_EventScript_MaliciousArmor
	case 13, FallarborTown_BattleTentLobby__ExchangeServiceCorner_EventScript_ClerkGoodbye
	case MULTI_B_PRESSED, FallarborTown_BattleTentLobby__ExchangeServiceCorner_EventScript_ClerkGoodbye
	end

FallarborTown_BattleTentLobby_ExchangeServiceCorner_EventScript_FireStone::
	msgbox FallarborTown_BattleTentLobby_ExchangeServiceCorner_Text_ConfirmFireStone, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq FallarborTown_BattleTentLobby_ExchangeServiceCorner_EventScript_ChooseHoldItem
	setvar VAR_0x8008, 64
	setvar VAR_0x8009, ITEM_SACHET
	goto FallarborTown_BattleTentLobby_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

FallarborTown_BattleTentLobby_ExchangeServiceCorner_EventScript_WaterStone::
	msgbox FallarborTown_BattleTentLobby_ExchangeServiceCorner_Text_ConfirmWaterStone, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq FallarborTown_BattleTentLobby_ExchangeServiceCorner_EventScript_ChooseHoldItem
	setvar VAR_0x8008, 64
	setvar VAR_0x8009, ITEM_WHIPPED_DREAM
	goto FallarborTown_BattleTentLobby_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

FallarborTown_BattleTentLobby_ExchangeServiceCorner_EventScript_ThunderStone::
	msgbox FallarborTown_BattleTentLobby_ExchangeServiceCorner_Text_ConfirmThunderStone, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq FallarborTown_BattleTentLobby_ExchangeServiceCorner_EventScript_ChooseHoldItem
	setvar VAR_0x8008, 64
	setvar VAR_0x8009, ITEM_OVAL_STONE
	goto FallarborTown_BattleTentLobby_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

FallarborTown_BattleTentLobby_ExchangeServiceCorner_EventScript_LeafStone::
	msgbox FallarborTown_BattleTentLobby_ExchangeServiceCorner_Text_ConfirmLeafStone, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq FallarborTown_BattleTentLobby_ExchangeServiceCorner_EventScript_ChooseHoldItem
	setvar VAR_0x8008, 99
	setvar VAR_0x8009, ITEM_DRAGON_SCALE
	goto FallarborTown_BattleTentLobby_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

FallarborTown_BattleTentLobby_ExchangeServiceCorner_EventScript_MoonStone::
	msgbox FallarborTown_BattleTentLobby_ExchangeServiceCorner_Text_ConfirmMoonStone, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq FallarborTown_BattleTentLobby_ExchangeServiceCorner_EventScript_ChooseHoldItem
	setvar VAR_0x8008, 99
	setvar VAR_0x8009, ITEM_UP_GRADE
	goto FallarborTown_BattleTentLobby_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

FallarborTown_BattleTentLobby_ExchangeServiceCorner_EventScript_SunStone::
	msgbox FallarborTown_BattleTentLobby_ExchangeServiceCorner_Text_ConfirmSunStone, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq FallarborTown_BattleTentLobby_ExchangeServiceCorner_EventScript_ChooseHoldItem
	setvar VAR_0x8008, 128
	setvar VAR_0x8009, ITEM_DUBIOUS_DISC
	goto FallarborTown_BattleTentLobby_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

FallarborTown_BattleTentLobby_ExchangeServiceCorner_EventScript_ShinyStone::
	msgbox FallarborTown_BattleTentLobby_ExchangeServiceCorner_Text_ConfirmShinyStone, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq FallarborTown_BattleTentLobby_ExchangeServiceCorner_EventScript_ChooseHoldItem
	setvar VAR_0x8008, 128
	setvar VAR_0x8009, ITEM_ELECTIRIZER
	goto FallarborTown_BattleTentLobby_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

FallarborTown_BattleTentLobby_ExchangeServiceCorner_EventScript_DuskStone::
	msgbox FallarborTown_BattleTentLobby_ExchangeServiceCorner_Text_ConfirmDuskStone, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq FallarborTown_BattleTentLobby_ExchangeServiceCorner_EventScript_ChooseHoldItem
	setvar VAR_0x8008, 128
	setvar VAR_0x8009, ITEM_MAGMARIZER
	goto FallarborTown_BattleTentLobby_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

FallarborTown_BattleTentLobby_ExchangeServiceCorner_EventScript_DawnStone::
	msgbox FallarborTown_BattleTentLobby_ExchangeServiceCorner_Text_ConfirmDawnStone, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq FallarborTown_BattleTentLobby_ExchangeServiceCorner_EventScript_ChooseHoldItem
	setvar VAR_0x8008, 128
	setvar VAR_0x8009, ITEM_PROTECTOR
	goto FallarborTown_BattleTentLobby_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

FallarborTown_BattleTentLobby_ExchangeServiceCorner_EventScript_IceStone::
	msgbox FallarborTown_BattleTentLobby_ExchangeServiceCorner_Text_ConfirmIceStone, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq FallarborTown_BattleTentLobby_ExchangeServiceCorner_EventScript_ChooseHoldItem
	setvar VAR_0x8008, 128
	setvar VAR_0x8009, ITEM_REAPER_CLOTH
	goto FallarborTown_BattleTentLobby_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

FallarborTown_BattleTentLobby_ExchangeServiceCorner_EventScript_PrismScale::
	msgbox FallarborTown_BattleTentLobby_ExchangeServiceCorner_Text_ConfirmPrismScale, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq FallarborTown_BattleTentLobby_ExchangeServiceCorner_EventScript_ChooseHoldItem
	setvar VAR_0x8008, 128
	setvar VAR_0x8009, ITEM_PRISM_SCALE
	goto FallarborTown_BattleTentLobby_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

FallarborTown_BattleTentLobby_ExchangeServiceCorner_EventScript_AuspiciousArmor::
	msgbox FallarborTown_BattleTentLobby_ExchangeServiceCorner_Text_ConfirmAuspiciousArmor, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq FallarborTown_BattleTentLobby_ExchangeServiceCorner_EventScript_ChooseHoldItem
	setvar VAR_0x8008, 128
	setvar VAR_0x8009, ITEM_AUSPICIOUS_ARMOR
	goto FallarborTown_BattleTentLobby_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

FallarborTown_BattleTentLobby__ExchangeServiceCorner_EventScript_MaliciousArmor::
	msgbox FallarborTown_BattleTentLobby_ExchangeServiceCorner_Text_ConfirmMaliciousArmor, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq FallarborTown_BattleTentLobby_ExchangeServiceCorner_EventScript_ChooseHoldItem
	setvar VAR_0x8008, 128
	setvar VAR_0x8009, ITEM_MALICIOUS_ARMOR
	goto FallarborTown_BattleTentLobby_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

FallarborTown_BattleTentLobby_ExchangeServiceCorner_EventScript_TryPurchasePrize::
	specialvar VAR_TEMP_1, GetFallarborTentPoints
	compare VAR_TEMP_1, VAR_0x8008
	goto_if_ge FallarborTown_BattleTentLobby_ExchangeServiceCorner_EventScript_TryGiveItem
	msgbox FallarborTown_BattleTentLobby_ExchangeServiceCorner_Text_DontHaveEnoughPoints, MSGBOX_DEFAULT
	goto FallarborTown_BattleTentLobby_ExchangeServiceCorner_EventScript_ChooseHoldItem
	end

FallarborTown_BattleTentLobby_ExchangeServiceCorner_EventScript_TryGiveItem::
	checkitemspace VAR_0x8009, 1
	compare VAR_RESULT, FALSE
	goto_if_eq BattleFrontier_ExchangeServiceCorner_EventScript_BagFull	
	copyvar VAR_0x8004, VAR_0x8008
	special TakeFallarborTentPoints
	additem VAR_0x8009
	special UpdateFallarborPointsWindow
	playse SE_SHOP
	msgbox BattleFrontier_ExchangeServiceCorner_Text_HereIsYourPrize, MSGBOX_DEFAULT
	goto FallarborTown_BattleTentLobby_ExchangeServiceCorner_EventScript_ChooseHoldItem
	end

FallarborTown_BattleTentLobby_ExchangeServiceCorner_Text_WelcomePleaseChoosePrize:
	.string "Hello, this is the Exchange Service\n"
	.string "Corner.\p"
	.string "We exchange the Fallarbor Points you\n"
	.string "have collected for lovely prizes.\p"
	.string "Please choose a prize from this list.$"

FallarborTown_BattleTentLobby_ExchangeServiceCorner_Text_ConfirmFireStone:
	.string "You've chosen the Sachet.\n"
	.string "Is that correct?$"

FallarborTown_BattleTentLobby_ExchangeServiceCorner_Text_ConfirmWaterStone:
	.string "You've chosen the Whipped Dream.\n"
	.string "Is that correct?$"

FallarborTown_BattleTentLobby_ExchangeServiceCorner_Text_ConfirmThunderStone:
	.string "You've chosen the Oval Stone.\n"
	.string "Is that correct?$"

FallarborTown_BattleTentLobby_ExchangeServiceCorner_Text_ConfirmLeafStone:
	.string "You've chosen the Dragon Scale.\n"
	.string "Is that correct?$"

FallarborTown_BattleTentLobby_ExchangeServiceCorner_Text_ConfirmMoonStone:
	.string "You've chosen the Upgrade.\n"
	.string "Is that correct?$"

FallarborTown_BattleTentLobby_ExchangeServiceCorner_Text_ConfirmSunStone:
	.string "You've chosen the Dubious Disc.\n"
	.string "Is that correct?$"

FallarborTown_BattleTentLobby_ExchangeServiceCorner_Text_ConfirmShinyStone:
	.string "You've chosen the Electirizer.\n"
	.string "Is that correct?$"

FallarborTown_BattleTentLobby_ExchangeServiceCorner_Text_ConfirmDuskStone:
	.string "You've chosen the Magmarizer.\n"
	.string "Is that correct?$"

FallarborTown_BattleTentLobby_ExchangeServiceCorner_Text_ConfirmDawnStone:
	.string "You've chosen the Protector.\n"
	.string "Is that correct?$"

FallarborTown_BattleTentLobby_ExchangeServiceCorner_Text_ConfirmIceStone:
	.string "You've chosen the Reaper Cloth.\n"
	.string "Is that correct?$"

FallarborTown_BattleTentLobby_ExchangeServiceCorner_Text_ConfirmPrismScale:
	.string "You've chosen the Prism Scale.\n"
	.string "Is that correct?$"

FallarborTown_BattleTentLobby_ExchangeServiceCorner_Text_ConfirmAuspiciousArmor:
	.string "You've chosen the Auspicious Armor.\n"
	.string "Is that correct?$"

FallarborTown_BattleTentLobby_ExchangeServiceCorner_Text_ConfirmMaliciousArmor:
	.string "You've chosen the Malicious Armor.\n"
	.string "Is that correct?$"

FallarborTown_BattleTentLobby_ExchangeServiceCorner_Text_ThankYouVisitWithPoints:
	.string "Thank you very much.\p"
	.string "Please visit us when you have\n"
	.string "saved up Fallarbor Points.$"

FallarborTown_BattleTentLobby_ExchangeServiceCorner_Text_DontHaveEnoughPoints:
	.string "I'm so sorry…\n"
	.string "You don't have enough Fallarbor Points…$"

