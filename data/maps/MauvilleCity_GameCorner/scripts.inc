.set LOCALID_ATENDENTE, 1
.set LOCALID_ROCKET_GRUNT, 15
.set LOCALID_POSTER, 16

MauvilleCity_GameCorner_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, MauvilleCity_GameCorner_OnFrame
	map_script MAP_SCRIPT_ON_LOAD, MauvilleCity_GameCorner_OnLoad
	.byte 0

MauvilleCity_GameCorner_OnFrame:
	map_script_2 VAR_GAME_CORNER_FIRST_VISIT, 0, MauvilleCity_GameCorner_EventScript_FirstVisit
	.2byte 0

MauvilleCity_GameCorner_OnLoad:
	call_if_unset FLAG_TEAM_ROCKET_POSTER, MauvilleCity_GameCorner_CloseTeamRocketHideoutEntrance
	end

MauvilleCity_GameCorner_CloseTeamRocketHideoutEntrance:
	setmetatile 17, 0, METATILE_MauvilleGameCorner_TeamRocketClosedDoorUp, 1
	setmetatile 17, 1, METATILE_MauvilleGameCorner_TeamRocketClosedDoorMiddle, 1
	setmetatile 17, 2, METATILE_MauvilleGameCorner_TeamRocketClosedDoorBottom, 0
	return

    @ Game Corner prices
	.set TM32_COINS,  1500
	.set TM29_COINS,  3500
	.set TM35_COINS,  4000
	.set TM24_COINS,  4000
	.set TM13_COINS,  4000
	.set DOLL_COINS,  1000

	.set COINS_PRICE_50,  1000
	.set COINS_PRICE_500, 10000

	.set TRAPINCH_COINS,  50
	.set HORSEA_COINS,  120
	.set PANPOUR_COINS,  750
	.set PANSAGE_COINS,  750
	.set PANSEAR_COINS,  750
	.set HERACROSS_COINS,  2000
	.set SOBBLE_COINS,  3200
	.set GROOKEY_COINS,  3200
	.set SCORBUNNY_COINS,  3200
	.set JANGMOO_COINS,  7500
	.set MELTAN_COINS,  9999

MauvilleCity_GameCorner_EventScript_CoinsClerk::
	lock
	faceplayer
	msgbox MauvilleCity_GameCorner_Text_ThisIsMauvilleGameCorner, MSGBOX_DEFAULT
	checkitem ITEM_COIN_CASE, 1
	compare VAR_RESULT, FALSE
	goto_if_eq MauvilleCity_GameCorner_EventScript_NeedCoinCase
	message MauvilleCity_GameCorner_Text_WereYouLookingForCoins
	waitmessage
	showmoneybox 0, 0, 0
	showcoinsbox 1, 6
	goto MauvilleCity_GameCorner_EventScript_ChooseCoinsDefault50

MauvilleCity_GameCorner_EventScript_ChooseCoinsDefault50::
	multichoicedefault 15, 0, MULTI_GAME_CORNER_COINS, 0, FALSE
	switch VAR_RESULT
	case 0, MauvilleCity_GameCorner_EventScript_Buy50Coins
	case 1, MauvilleCity_GameCorner_EventScript_Buy500Coins
	goto MauvilleCity_GameCorner_EventScript_CancelBuyCoins
	end

@ Unused
MauvilleCity_GameCorner_EventScript_ChooseCoinsDefault500::
	multichoicedefault 15, 0, MULTI_GAME_CORNER_COINS, 1, FALSE
	switch VAR_RESULT
	case 0, MauvilleCity_GameCorner_EventScript_Buy50Coins
	case 1, MauvilleCity_GameCorner_EventScript_Buy500Coins
	goto MauvilleCity_GameCorner_EventScript_CancelBuyCoins
	end

MauvilleCity_GameCorner_EventScript_Buy50Coins::
	checkcoins VAR_TEMP_1
	compare VAR_TEMP_1, (MAX_COINS + 1 - 50)
	goto_if_ge MauvilleCity_GameCorner_EventScript_NoRoomForCoins
	checkmoney COINS_PRICE_50, 0
	compare VAR_RESULT, FALSE
	goto_if_eq MauvilleCity_GameCorner_EventScript_NotEnoughMoney
	addcoins 50
	removemoney COINS_PRICE_50, 0
	updatemoneybox 0, 0
	updatecoinsbox 1, 6
	playse SE_SHOP
	msgbox MauvilleCity_GameCorner_Text_ThankYouHereAreYourCoins, MSGBOX_DEFAULT
	hidemoneybox
	hidecoinsbox 0, 5
	release
	end

MauvilleCity_GameCorner_EventScript_Buy500Coins::
	checkcoins VAR_TEMP_1
	compare VAR_TEMP_1, (MAX_COINS + 1 - 500)
	goto_if_ge MauvilleCity_GameCorner_EventScript_NoRoomForCoins
	checkmoney COINS_PRICE_500, 0
	compare VAR_RESULT, FALSE
	goto_if_eq MauvilleCity_GameCorner_EventScript_NotEnoughMoney
	addcoins 500
	removemoney COINS_PRICE_500, 0
	updatemoneybox 0, 0
	updatecoinsbox 1, 6
	playse SE_SHOP
	msgbox MauvilleCity_GameCorner_Text_ThankYouHereAreYourCoins, MSGBOX_DEFAULT
	hidemoneybox
	hidecoinsbox 0, 5
	release
	end

MauvilleCity_GameCorner_EventScript_NeedCoinCase::
	msgbox MauvilleCity_GameCorner_Text_NeedCoinCaseForCoins, MSGBOX_DEFAULT
	release
	end

MauvilleCity_GameCorner_EventScript_NotEnoughMoney::
	msgbox MauvilleCity_GameCorner_Text_DontHaveEnoughMoney, MSGBOX_DEFAULT
	hidemoneybox
	hidecoinsbox 0, 5
	release
	end

MauvilleCity_GameCorner_EventScript_CancelBuyCoins::
	msgbox MauvilleCity_GameCorner_Text_DontNeedCoinsThen, MSGBOX_DEFAULT
	hidemoneybox
	hidecoinsbox 0, 5
	release
	end

MauvilleCity_GameCorner_EventScript_NoRoomForCoins::
	msgbox MauvilleCity_GameCorner_Text_CoinCaseIsFull, MSGBOX_DEFAULT
	hidemoneybox
	hidecoinsbox 0, 5
	release
	end

MauvilleCity_GameCorner_EventScript_PrizeCornerDolls::
	lock
	faceplayer
	msgbox MauvilleCity_GameCorner_Text_ExchangeCoinsForPrizes, MSGBOX_DEFAULT
	checkitem ITEM_COIN_CASE, 1
	compare VAR_RESULT, TRUE
	goto_if_eq MauvilleCity_GameCorner_EventScript_ChooseDollPrizeMessage
	release
	end

MauvilleCity_GameCorner_EventScript_ChooseDollPrizeMessage::
	message MauvilleCity_GameCorner_Text_WhichPrize
	waitmessage
	setvar VAR_TEMP_1, 0
	showcoinsbox 1, 1
	goto MauvilleCity_GameCorner_EventScript_ChooseDollPrize

MauvilleCity_GameCorner_EventScript_ReturnToChooseDollPrize::
	message MauvilleCity_GameCorner_Text_WhichPrize
	waitmessage
	goto MauvilleCity_GameCorner_EventScript_ChooseDollPrize

MauvilleCity_GameCorner_EventScript_ChooseDollPrize::
	multichoice 12, 0, MULTI_GAME_CORNER_DOLLS, FALSE
	switch VAR_RESULT
	case 0, MauvilleCity_GameCorner_EventScript_TreeckoDoll
	case 1, MauvilleCity_GameCorner_EventScript_TorchicDoll
	case 2, MauvilleCity_GameCorner_EventScript_MudkipDoll
	case 3, MauvilleCity_GameCorner_EventScript_CancelDollSelect
	goto MauvilleCity_GameCorner_EventScript_CancelDollSelect
	end

MauvilleCity_GameCorner_EventScript_TreeckoDoll::
	setvar VAR_TEMP_1, 1
	bufferdecorationname 0, DECOR_TREECKO_DOLL
	goto MauvilleCity_GameCorner_EventScript_ConfirmDollPrize

MauvilleCity_GameCorner_EventScript_TorchicDoll::
	setvar VAR_TEMP_1, 2
	bufferdecorationname 0, DECOR_TORCHIC_DOLL
	goto MauvilleCity_GameCorner_EventScript_ConfirmDollPrize

MauvilleCity_GameCorner_EventScript_MudkipDoll::
	setvar VAR_TEMP_1, 3
	bufferdecorationname 0, DECOR_MUDKIP_DOLL
	goto MauvilleCity_GameCorner_EventScript_ConfirmDollPrize

MauvilleCity_GameCorner_EventScript_ConfirmDollPrize::
	msgbox MauvilleCity_GameCorner_Text_SoYourChoiceIsX, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq MauvilleCity_GameCorner_EventScript_CancelDollSelect
	switch VAR_TEMP_1
	case 1, MauvilleCity_GameCorner_EventScript_BuyTreeckoDoll
	case 2, MauvilleCity_GameCorner_EventScript_BuyTorchicDoll
	case 3, MauvilleCity_GameCorner_EventScript_BuyMudkipDoll
	end

MauvilleCity_GameCorner_EventScript_BuyTreeckoDoll::
	checkcoins VAR_TEMP_2
	compare VAR_TEMP_2, DOLL_COINS
	goto_if_lt MauvilleCity_GameCorner_EventScript_NotEnoughCoinsForDoll
	bufferdecorationname 1, DECOR_TREECKO_DOLL
	checkdecorspace DECOR_TREECKO_DOLL
	compare VAR_RESULT, FALSE
	goto_if_eq MauvilleCity_GameCorner_EventScript_NoRoomForDoll
	removecoins DOLL_COINS
	adddecoration DECOR_TREECKO_DOLL
	updatecoinsbox 1, 1
	playse SE_SHOP
	msgbox MauvilleCity_GameCorner_Text_SendToYourHomePC, MSGBOX_DEFAULT
	goto MauvilleCity_GameCorner_EventScript_ReturnToChooseDollPrize
	end

MauvilleCity_GameCorner_EventScript_BuyTorchicDoll::
	checkcoins VAR_TEMP_2
	compare VAR_TEMP_2, DOLL_COINS
	goto_if_lt MauvilleCity_GameCorner_EventScript_NotEnoughCoinsForDoll
	bufferdecorationname 1, DECOR_TORCHIC_DOLL
	checkdecorspace DECOR_TORCHIC_DOLL
	compare VAR_RESULT, FALSE
	goto_if_eq MauvilleCity_GameCorner_EventScript_NoRoomForDoll
	removecoins DOLL_COINS
	adddecoration DECOR_TORCHIC_DOLL
	updatecoinsbox 1, 1
	playse SE_SHOP
	msgbox MauvilleCity_GameCorner_Text_SendToYourHomePC, MSGBOX_DEFAULT
	goto MauvilleCity_GameCorner_EventScript_ReturnToChooseDollPrize
	end

MauvilleCity_GameCorner_EventScript_BuyMudkipDoll::
	checkcoins VAR_TEMP_2
	compare VAR_TEMP_2, DOLL_COINS
	goto_if_lt MauvilleCity_GameCorner_EventScript_NotEnoughCoinsForDoll
	bufferdecorationname 1, DECOR_MUDKIP_DOLL
	checkdecorspace DECOR_MUDKIP_DOLL
	compare VAR_RESULT, FALSE
	goto_if_eq MauvilleCity_GameCorner_EventScript_NoRoomForDoll
	removecoins DOLL_COINS
	adddecoration DECOR_MUDKIP_DOLL
	updatecoinsbox 1, 1
	playse SE_SHOP
	msgbox MauvilleCity_GameCorner_Text_SendToYourHomePC, MSGBOX_DEFAULT
	goto MauvilleCity_GameCorner_EventScript_ReturnToChooseDollPrize
	end

MauvilleCity_GameCorner_EventScript_NotEnoughCoinsForDoll::
	msgbox MauvilleCity_GameCorner_Text_NotEnoughCoins, MSGBOX_DEFAULT
	goto MauvilleCity_GameCorner_EventScript_ReturnToChooseDollPrize
	end

MauvilleCity_GameCorner_EventScript_NoRoomForDoll::
	call Common_EventScript_NoRoomForDecor
	goto MauvilleCity_GameCorner_EventScript_ReturnToChooseDollPrize
	end

MauvilleCity_GameCorner_EventScript_CancelDollSelect::
	msgbox MauvilleCity_GameCorner_Text_OhIsThatSo, MSGBOX_DEFAULT
	hidecoinsbox 0, 0
	release
	end

MauvilleCity_GameCorner_EventScript_PrizeCornerTMs::
	lock
	faceplayer
	msgbox MauvilleCity_GameCorner_Text_ExchangeCoinsForPrizes, MSGBOX_DEFAULT
	checkitem ITEM_COIN_CASE, 1
	compare VAR_RESULT, TRUE
	goto_if_eq MauvilleCity_GameCorner_EventScript_ChooseTMPrizeMessage
	release
	end

MauvilleCity_GameCorner_EventScript_ChooseTMPrizeMessage::
	message MauvilleCity_GameCorner_Text_WhichPrize
	waitmessage
	setvar VAR_TEMP_1, 0
	showcoinsbox 1, 1
	goto MauvilleCity_GameCorner_EventScript_ChooseTMPrize

MauvilleCity_GameCorner_EventScript_ReturnToChooseTMPrize::
	message MauvilleCity_GameCorner_Text_WhichPrize
	waitmessage
	goto MauvilleCity_GameCorner_EventScript_ChooseTMPrize

MauvilleCity_GameCorner_EventScript_ChooseTMPrize::
	multichoice 12, 0, MULTI_GAME_CORNER_TMS, FALSE
	switch VAR_RESULT
	case 0, MauvilleCity_GameCorner_EventScript_TM32
	case 1, MauvilleCity_GameCorner_EventScript_TM29
	case 2, MauvilleCity_GameCorner_EventScript_TM35
	case 3, MauvilleCity_GameCorner_EventScript_TM24
	case 4, MauvilleCity_GameCorner_EventScript_TM13
	case 5, MauvilleCity_GameCorner_EventScript_CancelTMSelect
	goto MauvilleCity_GameCorner_EventScript_CancelTMSelect
	end

MauvilleCity_GameCorner_EventScript_TM32::
	setvar VAR_TEMP_1, 1
	bufferitemname 0, ITEM_TM32
	setvar VAR_0x8004, ITEM_TM32
	goto MauvilleCity_GameCorner_EventScript_ConfirmTMPrize

MauvilleCity_GameCorner_EventScript_TM29::
	setvar VAR_TEMP_1, 2
	bufferitemname 0, ITEM_TM29
	setvar VAR_0x8004, ITEM_TM29
	goto MauvilleCity_GameCorner_EventScript_ConfirmTMPrize

MauvilleCity_GameCorner_EventScript_TM35::
	setvar VAR_TEMP_1, 3
	bufferitemname 0, ITEM_TM35
	setvar VAR_0x8004, ITEM_TM35
	goto MauvilleCity_GameCorner_EventScript_ConfirmTMPrize

MauvilleCity_GameCorner_EventScript_TM24::
	setvar VAR_TEMP_1, 4
	bufferitemname 0, ITEM_TM24
	setvar VAR_0x8004, ITEM_TM24
	goto MauvilleCity_GameCorner_EventScript_ConfirmTMPrize

MauvilleCity_GameCorner_EventScript_TM13::
	setvar VAR_TEMP_1, 5
	bufferitemname 0, ITEM_TM13
	setvar VAR_0x8004, ITEM_TM13
	goto MauvilleCity_GameCorner_EventScript_ConfirmTMPrize

MauvilleCity_GameCorner_EventScript_ConfirmTMPrize::
	special BufferTMHMMoveName
	msgbox MauvilleCity_GameCorner_Text_SoYourChoiceIsTheTMX, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq MauvilleCity_GameCorner_EventScript_ReturnToChooseTMPrize
	switch VAR_TEMP_1
	case 1, MauvilleCity_GameCorner_EventScript_BuyTM32
	case 2, MauvilleCity_GameCorner_EventScript_BuyTM29
	case 3, MauvilleCity_GameCorner_EventScript_BuyTM35
	case 4, MauvilleCity_GameCorner_EventScript_BuyTM24
	case 5, MauvilleCity_GameCorner_EventScript_BuyTM13
	end

MauvilleCity_GameCorner_EventScript_BuyTM32::
	checkcoins VAR_TEMP_2
	compare VAR_TEMP_2, TM32_COINS
	goto_if_lt MauvilleCity_GameCorner_EventScript_NotEnoughCoinsForTM
	checkitem ITEM_TM32, 1
    compare VAR_RESULT, TRUE
	goto_if_eq MauvilleCity_GameCorner_EventScript_YouAlreadyHaveThis
	removecoins TM32_COINS
	additem ITEM_TM32
	updatecoinsbox 1, 1
	playse SE_SHOP
	msgbox MauvilleCity_GameCorner_Text_HereYouGo, MSGBOX_DEFAULT
	goto MauvilleCity_GameCorner_EventScript_ReturnToChooseTMPrize
	end

MauvilleCity_GameCorner_EventScript_BuyTM29::
	checkcoins VAR_TEMP_2
	compare VAR_TEMP_2, TM29_COINS
	goto_if_lt MauvilleCity_GameCorner_EventScript_NotEnoughCoinsForTM
	checkitem ITEM_TM29, 1
    compare VAR_RESULT, TRUE
	goto_if_eq MauvilleCity_GameCorner_EventScript_YouAlreadyHaveThis
	removecoins TM29_COINS
	additem ITEM_TM29
	updatecoinsbox 1, 1
	playse SE_SHOP
	msgbox MauvilleCity_GameCorner_Text_HereYouGo, MSGBOX_DEFAULT
	goto MauvilleCity_GameCorner_EventScript_ReturnToChooseTMPrize
	end

MauvilleCity_GameCorner_EventScript_BuyTM35::
	checkcoins VAR_TEMP_2
	compare VAR_TEMP_2, TM35_COINS
	goto_if_lt MauvilleCity_GameCorner_EventScript_NotEnoughCoinsForTM
	checkitem ITEM_TM35, 1
    compare VAR_RESULT, TRUE
	goto_if_eq MauvilleCity_GameCorner_EventScript_YouAlreadyHaveThis
	removecoins TM35_COINS
	additem ITEM_TM35
	updatecoinsbox 1, 1
	playse SE_SHOP
	msgbox MauvilleCity_GameCorner_Text_HereYouGo, MSGBOX_DEFAULT
	goto MauvilleCity_GameCorner_EventScript_ReturnToChooseTMPrize
	end

MauvilleCity_GameCorner_EventScript_BuyTM24::
	checkcoins VAR_TEMP_2
	compare VAR_TEMP_2, TM24_COINS
	goto_if_lt MauvilleCity_GameCorner_EventScript_NotEnoughCoinsForTM
	checkitem ITEM_TM24, 1
    compare VAR_RESULT, TRUE
	goto_if_eq MauvilleCity_GameCorner_EventScript_YouAlreadyHaveThis
	removecoins TM24_COINS
	additem ITEM_TM24
	updatecoinsbox 1, 1
	playse SE_SHOP
	msgbox MauvilleCity_GameCorner_Text_HereYouGo, MSGBOX_DEFAULT
	goto MauvilleCity_GameCorner_EventScript_ReturnToChooseTMPrize
	end

MauvilleCity_GameCorner_EventScript_BuyTM13::
	checkcoins VAR_TEMP_2
	compare VAR_TEMP_2, TM13_COINS
	goto_if_lt MauvilleCity_GameCorner_EventScript_NotEnoughCoinsForTM
	checkitem ITEM_TM13, 1
    compare VAR_RESULT, TRUE
	goto_if_eq MauvilleCity_GameCorner_EventScript_YouAlreadyHaveThis
	removecoins TM13_COINS
	additem ITEM_TM13
	updatecoinsbox 1, 1
	playse SE_SHOP
	msgbox MauvilleCity_GameCorner_Text_HereYouGo, MSGBOX_DEFAULT
	goto MauvilleCity_GameCorner_EventScript_ReturnToChooseTMPrize
	end

MauvilleCity_GameCorner_EventScript_NotEnoughCoinsForTM::
	msgbox MauvilleCity_GameCorner_Text_NotEnoughCoins, MSGBOX_DEFAULT
	goto MauvilleCity_GameCorner_EventScript_ReturnToChooseTMPrize
	end

MauvilleCity_GameCorner_EventScript_YouAlreadyHaveThis::
    msgbox gText_YouAlreadyHaveThis, MSGBOX_DEFAULT
	goto MauvilleCity_GameCorner_EventScript_ReturnToChooseTMPrize
	end

MauvilleCity_GameCorner_EventScript_CancelTMSelect::
	msgbox MauvilleCity_GameCorner_Text_OhIsThatSo, MSGBOX_DEFAULT
	hidecoinsbox 0, 0
	release
	end

MauvilleCity_GameCorner_EventScript_Woman2::
	msgbox MauvilleCity_GameCorner_Text_CoinsAreNeededToPlay, MSGBOX_NPC
	end

MauvilleCity_GameCorner_EventScript_Gentleman::
	msgbox MauvilleCity_GameCorner_Text_RouletteOnlyLuck, MSGBOX_NPC
	end

MauvilleCity_GameCorner_EventScript_Girl::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_STARTER_DOLL, MauvilleCity_GameCorner_EventScript_ReceivedStarterDoll
	msgbox MauvilleCity_GameCorner_Text_GotTwoOfSameDollWantOne, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq MauvilleCity_GameCorner_EventScript_DeclineStarterDoll
	switch VAR_STARTER_MON
	case 0, MauvilleCity_GameCorner_EventScript_GiveTreeckoDoll
	case 1, MauvilleCity_GameCorner_EventScript_GiveTorchicDoll
	case 2, MauvilleCity_GameCorner_EventScript_GiveMudkipDoll
	end

MauvilleCity_GameCorner_EventScript_GiveTreeckoDoll::
	bufferdecorationname 1, DECOR_TREECKO_DOLL
	checkdecorspace DECOR_TREECKO_DOLL
	compare VAR_RESULT, FALSE
	goto_if_eq MauvilleCity_GameCorner_EventScript_NoRoomForStarterDoll
	msgbox MauvilleCity_GameCorner_Text_HereYouGo2, MSGBOX_DEFAULT
	givedecoration DECOR_TREECKO_DOLL
	setflag FLAG_RECEIVED_STARTER_DOLL
	goto MauvilleCity_GameCorner_EventScript_ReceivedStarterDoll
	end

MauvilleCity_GameCorner_EventScript_GiveTorchicDoll::
	bufferdecorationname 1, DECOR_TORCHIC_DOLL
	checkdecorspace DECOR_TORCHIC_DOLL
	compare VAR_RESULT, FALSE
	goto_if_eq MauvilleCity_GameCorner_EventScript_NoRoomForStarterDoll
	msgbox MauvilleCity_GameCorner_Text_HereYouGo2, MSGBOX_DEFAULT
	givedecoration DECOR_TORCHIC_DOLL
	setflag FLAG_RECEIVED_STARTER_DOLL
	goto MauvilleCity_GameCorner_EventScript_ReceivedStarterDoll
	end

MauvilleCity_GameCorner_EventScript_GiveMudkipDoll::
	bufferdecorationname 1, DECOR_MUDKIP_DOLL
	checkdecorspace DECOR_MUDKIP_DOLL
	compare VAR_RESULT, FALSE
	goto_if_eq MauvilleCity_GameCorner_EventScript_NoRoomForStarterDoll
	msgbox MauvilleCity_GameCorner_Text_HereYouGo2, MSGBOX_DEFAULT
	givedecoration DECOR_MUDKIP_DOLL
	setflag FLAG_RECEIVED_STARTER_DOLL
	goto MauvilleCity_GameCorner_EventScript_ReceivedStarterDoll
	end

MauvilleCity_GameCorner_EventScript_NoRoomForStarterDoll::
	call Common_EventScript_NoRoomForDecor
	msgbox MauvilleCity_GameCorner_Text_YouWantItButNotNow, MSGBOX_DEFAULT
	release
	end

MauvilleCity_GameCorner_EventScript_DeclineStarterDoll::
	msgbox MauvilleCity_GameCorner_Text_DontBeNegative, MSGBOX_DEFAULT
	release
	end

MauvilleCity_GameCorner_EventScript_ReceivedStarterDoll::
	msgbox MauvilleCity_GameCorner_Text_CantWinJackpot, MSGBOX_DEFAULT
	release
	end

MauvilleCity_GameCorner_EventScript_PokefanM::
	lock
	faceplayer
	checkitem ITEM_COIN_CASE, 1
	compare VAR_RESULT, TRUE
	goto_if_eq MauvilleCity_GameCorner_EventScript_TryGive20Coins
	msgbox MauvilleCity_GameCorner_Text_NeedCoinCaseGoNextDoor, MSGBOX_DEFAULT
	goto MauvilleCity_GameCorner_EventScript_NPCReturnToSlots
	end

MauvilleCity_GameCorner_EventScript_TryGive20Coins::
	goto_if_set FLAG_RECEIVED_20_COINS, MauvilleCity_GameCorner_EventScript_PokefanMNormal
	checkcoins VAR_TEMP_1
	compare VAR_TEMP_1, 1  @ Only give 20 coins if player has no coins
	goto_if_ge MauvilleCity_GameCorner_EventScript_PokefanMNormal
	setflag FLAG_RECEIVED_20_COINS
	addcoins 20
	msgbox MauvilleCity_GameCorner_Text_LuckOnlyLastSoLongTakeCoins, MSGBOX_DEFAULT
	playse SE_SHOP
	goto MauvilleCity_GameCorner_EventScript_PokefanMNormal
	end

MauvilleCity_GameCorner_EventScript_PokefanMNormal::
	msgbox MauvilleCity_GameCorner_Text_MauvilleSomethingForEveryone, MSGBOX_DEFAULT
	goto MauvilleCity_GameCorner_EventScript_NPCReturnToSlots
	end

MauvilleCity_GameCorner_EventScript_OldMan::
	lock
	faceplayer
	msgbox MauvilleCity_GameCorner_Text_RouletteTablesDifferentRates, MSGBOX_DEFAULT
	goto MauvilleCity_GameCorner_EventScript_NPCReturnToSlots
	end

MauvilleCity_GameCorner_EventScript_Cook::
	lock
	faceplayer
	msgbox MauvilleCity_GameCorner_Text_EasyToLoseTrackOfTime, MSGBOX_DEFAULT
	goto MauvilleCity_GameCorner_EventScript_NPCReturnToSlots
	end

MauvilleCity_GameCorner_EventScript_Man::
	lock
	faceplayer
	msgbox MauvilleCity_GameCorner_Text_UpTo3CoinsCanBeUsed, MSGBOX_DEFAULT
	goto MauvilleCity_GameCorner_EventScript_NPCReturnToSlots
	end

MauvilleCity_GameCorner_EventScript_NPCReturnToSlots::
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

MauvilleCity_GameCorner_EventScript_Maniac::
	lock
	faceplayer
	msgbox MauvilleCity_GameCorner_Text_DifficultToStopOn7, MSGBOX_DEFAULT
	goto MauvilleCity_GameCorner_EventScript_NPCReturnToSlots
	end

MauvilleCity_GameCorner_EventScript_Woman::
	lock
	faceplayer
	msgbox MauvilleCity_GameCorner_Text_HeresSomeSlotsInfo, MSGBOX_DEFAULT
	goto MauvilleCity_GameCorner_EventScript_NPCReturnToSlots
	end

MauvilleCity_GameCorner_EventScript_SlotMachine0::
	lockall
	checkitem ITEM_COIN_CASE, 1
	compare VAR_RESULT, FALSE
	goto_if_eq MauvilleCity_GameCorner_EventScript_NoCoinCase
	setvar VAR_0x8004, 0
	specialvar VAR_RESULT, GetSlotMachineId
	playslotmachine VAR_RESULT
	releaseall
	end

MauvilleCity_GameCorner_EventScript_SlotMachine1::
	lockall
	checkitem ITEM_COIN_CASE, 1
	compare VAR_RESULT, FALSE
	goto_if_eq MauvilleCity_GameCorner_EventScript_NoCoinCase
	setvar VAR_0x8004, 1
	specialvar VAR_RESULT, GetSlotMachineId
	playslotmachine VAR_RESULT
	releaseall
	end

MauvilleCity_GameCorner_EventScript_SlotMachine2::
	lockall
	checkitem ITEM_COIN_CASE, 1
	compare VAR_RESULT, FALSE
	goto_if_eq MauvilleCity_GameCorner_EventScript_NoCoinCase
	setvar VAR_0x8004, 2
	specialvar VAR_RESULT, GetSlotMachineId
	playslotmachine VAR_RESULT
	releaseall
	end

MauvilleCity_GameCorner_EventScript_SlotMachine3::
	lockall
	checkitem ITEM_COIN_CASE, 1
	compare VAR_RESULT, FALSE
	goto_if_eq MauvilleCity_GameCorner_EventScript_NoCoinCase
	setvar VAR_0x8004, 3
	specialvar VAR_RESULT, GetSlotMachineId
	playslotmachine VAR_RESULT
	releaseall
	end

MauvilleCity_GameCorner_EventScript_SlotMachine4::
	lockall
	msgbox MauvilleCity_GameCorner_Text_OutService, MSGBOX_DEFAULT
	goto_if_set FLAG_DAILY_SLOT_MACHINE_4_COINS, MauvilleCity_GameCorner_EventScript_SlotMachineEnd
	goto_if_unset FLAG_RECEIVED_GALLADITE, MauvilleCity_GameCorner_EventScript_SlotMachine4_Galladite
	checkitem ITEM_COIN_CASE, 1
	compare VAR_RESULT, FALSE
	goto_if_eq MauvilleCity_GameCorner_EventScript_SlotMachineEnd
	setflag FLAG_DAILY_SLOT_MACHINE_4_COINS
	playfanfare MUS_OBTAIN_ITEM
	message MauvilleCity_GameCorner_Text_FoundCoins
	waitmessage
	waitfanfare
	addcoins 200
	releaseall
	end

MauvilleCity_GameCorner_EventScript_SlotMachineEnd:
	releaseall
	end

MauvilleCity_GameCorner_EventScript_SlotMachine4_Galladite:
	msgbox MauvilleCity_GameCorner_Text_FoundGalladite, MSGBOX_DEFAULT
	giveitem ITEM_GALLADITE
	setflag FLAG_RECEIVED_GALLADITE
	setflag FLAG_DAILY_SLOT_MACHINE_4_COINS
	releaseall
	end

MauvilleCity_GameCorner_Text_FoundGalladite:
    .string "{PLAYER} found Galladite\n"
    .string "stucked in the machine!$"

MauvilleCity_GameCorner_Text_FoundCoins:
    .string "{PLAYER} found 200 coins\n"
    .string "stucked in the machine!$"

MauvilleCity_GameCorner_Text_OutService:
    .string "Machine 4 seems\n"
    .string "broken.$"

MauvilleCity_GameCorner_EventScript_SlotMachine5::
	lockall
	checkitem ITEM_COIN_CASE, 1
	compare VAR_RESULT, FALSE
	goto_if_eq MauvilleCity_GameCorner_EventScript_NoCoinCase
	setvar VAR_0x8004, 5
	specialvar VAR_RESULT, GetSlotMachineId
	playslotmachine VAR_RESULT
	releaseall
	end

MauvilleCity_GameCorner_EventScript_SlotMachine6::
	lockall
	checkitem ITEM_COIN_CASE, 1
	compare VAR_RESULT, FALSE
	goto_if_eq MauvilleCity_GameCorner_EventScript_NoCoinCase
	setvar VAR_0x8004, 6
	specialvar VAR_RESULT, GetSlotMachineId
	playslotmachine VAR_RESULT
	releaseall
	end

MauvilleCity_GameCorner_EventScript_SlotMachine7::
	lockall
	checkitem ITEM_COIN_CASE, 1
	compare VAR_RESULT, FALSE
	goto_if_eq MauvilleCity_GameCorner_EventScript_NoCoinCase
	setvar VAR_0x8004, 7
	specialvar VAR_RESULT, GetSlotMachineId
	playslotmachine VAR_RESULT
	releaseall
	end

MauvilleCity_GameCorner_EventScript_SlotMachine8::
	lockall
	checkitem ITEM_COIN_CASE, 1
	compare VAR_RESULT, FALSE
	goto_if_eq MauvilleCity_GameCorner_EventScript_NoCoinCase
	setvar VAR_0x8004, 8
	specialvar VAR_RESULT, GetSlotMachineId
	playslotmachine VAR_RESULT
	releaseall
	end

MauvilleCity_GameCorner_EventScript_SlotMachine9::
	lockall
	checkitem ITEM_COIN_CASE, 1
	compare VAR_RESULT, FALSE
	goto_if_eq MauvilleCity_GameCorner_EventScript_NoCoinCase
	setvar VAR_0x8004, 9
	specialvar VAR_RESULT, GetSlotMachineId
	playslotmachine VAR_RESULT
	releaseall
	end

MauvilleCity_GameCorner_EventScript_SlotMachine10::
	lockall
	checkitem ITEM_COIN_CASE, 1
	compare VAR_RESULT, FALSE
	goto_if_eq MauvilleCity_GameCorner_EventScript_NoCoinCase
	setvar VAR_0x8004, 10
	specialvar VAR_RESULT, GetSlotMachineId
	playslotmachine VAR_RESULT
	releaseall
	end

MauvilleCity_GameCorner_EventScript_SlotMachine11::
	lockall
	checkitem ITEM_COIN_CASE, 1
	compare VAR_RESULT, FALSE
	goto_if_eq MauvilleCity_GameCorner_EventScript_NoCoinCase
	setvar VAR_0x8004, 11
	specialvar VAR_RESULT, GetSlotMachineId
	playslotmachine VAR_RESULT
	releaseall
	end

MauvilleCity_GameCorner_EventScript_NoCoinCase::
	msgbox MauvilleCity_GameCorner_Text_CantPlayWithNoCoinCase, MSGBOX_DEFAULT
	releaseall
	end

MauvilleCity_GameCorner_Text_ThisIsMauvilleGameCorner:
	.string "This is Mauville Game Corner.$"

MauvilleCity_GameCorner_Text_NeedCoinCaseForCoins:
	.string "Okay, you wanted some Coins for\n"
	.string "the games?\p"
	.string "But you don't have a Coin Case for\n"
	.string "stowing the Coins.$"

MauvilleCity_GameCorner_Text_WereYouLookingForCoins:
	.string "Were you looking for Coins?\p"
	.string "It's ¥1000 for 50 Coins.\n"
	.string "Would you like some?$"

MauvilleCity_GameCorner_Text_ThankYouHereAreYourCoins:
	.string "Thank you very much!\n"
	.string "Here are your Coins!$"

MauvilleCity_GameCorner_Text_DontHaveEnoughMoney:
	.string "Um… You don't appear to have\n"
	.string "enough money…$"

MauvilleCity_GameCorner_Text_CoinCaseIsFull:
	.string "Oh?\n"
	.string "Your Coin Case is full.$"

MauvilleCity_GameCorner_Text_DontNeedCoinsThen:
	.string "Oh… You don't need Coins, then?\n"
	.string "Good luck on your adventure!$"

MauvilleCity_GameCorner_Text_ExchangeCoinsForPrizes:
	.string "Welcome.\p"
	.string "You can exchange your Coins for\n"
	.string "prizes here.$"

MauvilleCity_GameCorner_Text_WhichPrize:
	.string "Which prize would you like?$"

MauvilleCity_GameCorner_Text_SoYourChoiceIsTheTMX:
	.string "So your choice is\n"
	.string "the {STR_VAR_1} {STR_VAR_2}?$"

MauvilleCity_GameCorner_Text_SendToYourHomePC:
	.string "Thank you!\n"
	.string "We'll send it to your PC at home.$"

MauvilleCity_GameCorner_Text_NotEnoughCoins:
	.string "You don't have enough Coins.$"

@ Unused
MauvilleCity_GameCorner_Text_NoRoomForPlacingDecor:
	.string "There isn't any room available for\n"
	.string "placing {STR_VAR_1}.$"

MauvilleCity_GameCorner_Text_OhIsThatSo:
	.string "Oh, is that so? \n"
	.string "You need to save some Coins before\l"
	.string "coming back here.$"

MauvilleCity_GameCorner_Text_SoYourChoiceIsX:
	.string "So your choice is {STR_VAR_1}?$"

MauvilleCity_GameCorner_Text_HereYouGo:
	.string "Here you go!$"

@ Unused
MauvilleCity_GameCorner_Text_CantCarryAnyMore:
	.string "Oh, you can't carry any more than that.$"

MauvilleCity_GameCorner_Text_GotTwoOfSameDollWantOne:
	.string "I made a mistake and got two of\n"
	.string "the same Dolls.\p"
	.string "Would you like one of them?$"

MauvilleCity_GameCorner_Text_HereYouGo2:
	.string "Here you go!$"

MauvilleCity_GameCorner_Text_YouWantItButNotNow:
	.string "Huh?\n"
	.string "You want it, but not right now?$"

MauvilleCity_GameCorner_Text_DontBeNegative:
	.string "Oh, don't be so negative!\n"
	.string "You can have this!$"

MauvilleCity_GameCorner_Text_CantWinJackpot:
	.string "There's a prize I want, but I can't win\n"
	.string "the jackpot.$"

MauvilleCity_GameCorner_Text_NeedCoinCaseGoNextDoor:
	.string "Hey, kid, if you want to play here,\n"
	.string "you need a Coin Case.\p"
	.string "I think the young lady next door\n"
	.string "had one. Go see her!$"

MauvilleCity_GameCorner_Text_LuckOnlyLastSoLongTakeCoins:
	.string "My luck can only last so long.\n"
	.string "This is too much for me.\l"
	.string "Here, take some Coins!$"

MauvilleCity_GameCorner_Text_MauvilleSomethingForEveryone:
	.string "Mauville has something for\n"
	.string "everyone.\p"
	.string "For me, it's the Game Corner.$"

MauvilleCity_GameCorner_Text_RouletteTablesDifferentRates:
	.string "The Roulette tables have different\n"
	.string "rates.\p"
	.string "Check your Coins if you're going to\n"
	.string "pick a table.$"

MauvilleCity_GameCorner_Text_EasyToLoseTrackOfTime:
	.string "It's easy to lose track of time in here. \n"
	.string "I should get back to work.$"

MauvilleCity_GameCorner_Text_CoinsAreNeededToPlay:
	.string "Coins are needed to play here\n"
	.string "in the Game Corner.$"

MauvilleCity_GameCorner_Text_RouletteOnlyLuck:
	.string "This Roulette thing…\n"
	.string "It's rather demanding.\p"
	.string "Win or lose, it's only by luck.$"

MauvilleCity_GameCorner_Text_UpTo3CoinsCanBeUsed:
	.string "Up to three Coins can be used to play\n"
	.string "the Slots.$"

MauvilleCity_GameCorner_Text_DifficultToStopOn7:
	.string "It's very difficult to make it stop\n"
	.string "right on “7.”\p"
	.string "If it stops on “7” during the Reel Time\n"
	.string "bonus game, you'll receive extra Coins.$"

MauvilleCity_GameCorner_Text_HeresSomeSlotsInfo:
	.string "Here's some information for you\n"
	.string "about the Slots.\p"
	.string "The more lightning bolts you stock,\n"
	.string "the more Reel Time chances you get.\p"
	.string "In a game with the maximum five\n"
	.string "Reel Time chances…\p"
	.string "It is possible to receive four regular\n"
	.string "bonuses, then a big bonus.\p"
	.string "That would total 660 Coins, but it's\n"
	.string "very difficult to get.$"

MauvilleCity_GameCorner_Text_CantPlayWithNoCoinCase:
	.string "You can't play if you don't have\n"
	.string "a Coin Case.$"


@NEW CODE
	
MauvilleCity_GameCorner_EventScript_FirstVisit::
	lockall
	playse SE_PIN
	applymovement LOCALID_ATENDENTE, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_ATENDENTE, Common_Movement_Delay48
	waitmovement 0
	applymovement LOCALID_ATENDENTE, MauvilleCity_GameCorner_AtendenteApproachPlayer
	waitmovement 0
	msgbox MauvilleCity_GameCorner_WelcomeToGameCornerFirstVisit, MSGBOX_DEFAULT
	closemessage
	giveitem ITEM_COIN_CASE
	setvar VAR_GAME_CORNER_FIRST_VISIT, 1
	releaseall
	end

MauvilleCity_GameCorner_AtendenteApproachPlayer:
	walk_down
	walk_down
	step_end

MauvilleCity_GameCorner_WelcomeToGameCornerFirstVisit:
	.string "Welcome to the Game Corner!\p"
	.string "Oh! You're a new visitor!\n"
	.string "Well, since this is the first time\l"
	.string "you come here, I will give a Coin Case.\l"
	.string "This is needed if you wanna play here.$"


MauvilleCity_GameCorner_EventScript_PrizeCornerPokemon::
	lock
	faceplayer
	msgbox MauvilleCity_GameCorner_Text_ExchangeCoinsForPrizes, MSGBOX_DEFAULT
	checkitem ITEM_COIN_CASE, 1
	compare VAR_RESULT, TRUE
	goto_if_eq MauvilleCity_GameCorner_EventScript_ChoosePokemonPrizeMessage
	release
	end
	
MauvilleCity_GameCorner_EventScript_ChoosePokemonPrizeMessage::
	message MauvilleCity_GameCorner_Text_WhichPrize
	waitmessage
	setvar VAR_TEMP_1, 0
	showcoinsbox 1, 1
	goto MauvilleCity_GameCorner_EventScript_ChoosePokemonPrize

MauvilleCity_GameCorner_EventScript_ReturnToChoosePokemonPrize::
	hidemonpic
	message MauvilleCity_GameCorner_Text_WhichPrize
	waitmessage
	goto MauvilleCity_GameCorner_EventScript_ChoosePokemonPrize

	@set TRAPINCH_COINS,  50
	@set HORSEA_COINS,  120
	@set PANPOUR_COINS,  750
	@set PANSAGE_COINS,  750
	@set PANSEAR_COINS,  750
	@set HERACROSS_COINS,  2000
	@set SOBBLE_COINS,  3200
	@set GROOKEY_COINS,  3200
	@set SCORBUNNY_COINS,  3200
	@set JANGMOO_COINS,  7500
	@set MELTAN_COINS,  9999
MauvilleCity_GameCorner_EventScript_ChoosePokemonPrize:
	setvar VAR_0x8004, SCROLL_MULTI_GAME_CORNER_POKEMONS
	special ShowScrollableMultichoice
	waitstate
	switch VAR_RESULT
	case 0, MauvilleCity_GameCorner_EventScript_TRAPINCH
	case 1, MauvilleCity_GameCorner_EventScript_HORSEA
	case 2, MauvilleCity_GameCorner_EventScript_PANPOUR
	case 3, MauvilleCity_GameCorner_EventScript_PANSAGE
	case 4, MauvilleCity_GameCorner_EventScript_PANSEAR
	case 5, MauvilleCity_GameCorner_EventScript_HERACROSS
	case 6, MauvilleCity_GameCorner_EventScript_SOBBLE
	case 7, MauvilleCity_GameCorner_EventScript_GROOKEY
	case 8, MauvilleCity_GameCorner_EventScript_SCORBUNNY
	case 9, MauvilleCity_GameCorner_EventScript_JANGMOO
	case 10, MauvilleCity_GameCorner_EventScript_MELTAN
	case 11, MauvilleCity_GameCorner_EventScript_CancelPokemonSelect
	goto MauvilleCity_GameCorner_EventScript_CancelPokemonSelect
	end

MauvilleCity_GameCorner_EventScript_CancelPokemonSelect::
	msgbox MauvilleCity_GameCorner_Text_OhIsThatSo, MSGBOX_DEFAULT
	hidecoinsbox 0, 0
	hidemonpic
	release
	end

MauvilleCity_GameCorner_EventScript_NotEnoughCoinsForPokemon::
	hidemonpic
	msgbox MauvilleCity_GameCorner_Text_NotEnoughCoins, MSGBOX_DEFAULT
	goto MauvilleCity_GameCorner_EventScript_ReturnToChoosePokemonPrize
	end

MauvilleCity_GameCorner_EventScript_TRAPINCH::
	setvar VAR_TEMP_1, 1
	bufferspeciesname 0, SPECIES_TRAPINCH
	setvar VAR_0x8004, SPECIES_TRAPINCH
	showmonpic VAR_0x8004, 5, 4
	goto MauvilleCity_GameCorner_EventScript_ConfirmPokemonPrize

MauvilleCity_GameCorner_EventScript_HORSEA::
	setvar VAR_TEMP_1, 2
	bufferspeciesname 0, SPECIES_HORSEA
	setvar VAR_0x8004, SPECIES_HORSEA
	showmonpic VAR_0x8004, 5, 4
	goto MauvilleCity_GameCorner_EventScript_ConfirmPokemonPrize

MauvilleCity_GameCorner_EventScript_PANPOUR::
	setvar VAR_TEMP_1, 3
	bufferspeciesname 0, SPECIES_PANPOUR
	setvar VAR_0x8004, SPECIES_PANPOUR
	showmonpic VAR_0x8004, 5, 4
	goto MauvilleCity_GameCorner_EventScript_ConfirmPokemonPrize

MauvilleCity_GameCorner_EventScript_PANSAGE::
	setvar VAR_TEMP_1, 4
	bufferspeciesname 0, SPECIES_PANSAGE
	setvar VAR_0x8004, SPECIES_PANSAGE
	showmonpic VAR_0x8004, 5, 4
	goto MauvilleCity_GameCorner_EventScript_ConfirmPokemonPrize

MauvilleCity_GameCorner_EventScript_PANSEAR::
	setvar VAR_TEMP_1, 5
	bufferspeciesname 0, SPECIES_PANSEAR
	setvar VAR_0x8004, SPECIES_PANSEAR
	showmonpic VAR_0x8004, 5, 4
	goto MauvilleCity_GameCorner_EventScript_ConfirmPokemonPrize

MauvilleCity_GameCorner_EventScript_HERACROSS::
	setvar VAR_TEMP_1, 6
	bufferspeciesname 0, SPECIES_HERACROSS
	setvar VAR_0x8004, SPECIES_HERACROSS
	showmonpic VAR_0x8004, 5, 4
	goto MauvilleCity_GameCorner_EventScript_ConfirmPokemonPrize

MauvilleCity_GameCorner_EventScript_SOBBLE::
	setvar VAR_TEMP_1, 7
	bufferspeciesname 0, SPECIES_SOBBLE
	setvar VAR_0x8004, SPECIES_SOBBLE
	showmonpic VAR_0x8004, 5, 4
	goto MauvilleCity_GameCorner_EventScript_ConfirmPokemonPrize

MauvilleCity_GameCorner_EventScript_GROOKEY::
	setvar VAR_TEMP_1, 8
	bufferspeciesname 0, SPECIES_GROOKEY
	setvar VAR_0x8004, SPECIES_GROOKEY
	showmonpic VAR_0x8004, 5, 4
	goto MauvilleCity_GameCorner_EventScript_ConfirmPokemonPrize

MauvilleCity_GameCorner_EventScript_SCORBUNNY::
	setvar VAR_TEMP_1, 9
	bufferspeciesname 0, SPECIES_SCORBUNNY
	setvar VAR_0x8004, SPECIES_SCORBUNNY
	showmonpic VAR_0x8004, 5, 4
	goto MauvilleCity_GameCorner_EventScript_ConfirmPokemonPrize

MauvilleCity_GameCorner_EventScript_JANGMOO::
	setvar VAR_TEMP_1, 10
	bufferspeciesname 0, SPECIES_JANGMO_O
	setvar VAR_0x8004, SPECIES_JANGMO_O
	showmonpic VAR_0x8004, 5, 4
	goto MauvilleCity_GameCorner_EventScript_ConfirmPokemonPrize

MauvilleCity_GameCorner_EventScript_MELTAN::
	setvar VAR_TEMP_1, 11
	bufferspeciesname 0, SPECIES_MELTAN
	setvar VAR_0x8004, SPECIES_MELTAN
	showmonpic VAR_0x8004, 5, 4
	goto MauvilleCity_GameCorner_EventScript_ConfirmPokemonPrize

	@set TRAPINCH_COINS,  50
	@set HORSEA_COINS,  120
	@set PANPOUR_COINS,  750
	@set PANSAGE_COINS,  750
	@set PANSEAR_COINS,  750
	@set HERACROSS_COINS,  2000
	@set SOBBLE_COINS,  3200
	@set GROOKEY_COINS,  3200
	@set SCORBUNNY_COINS,  3200
	@set JANGMOO_COINS,  7500
	@set MELTAN_COINS,  9999
MauvilleCity_GameCorner_EventScript_ConfirmPokemonPrize:
	msgbox MauvilleCity_GameCorner_Text_SoYourChoiceIsThePokemonX, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq MauvilleCity_GameCorner_EventScript_ReturnToChoosePokemonPrize
	switch VAR_TEMP_1
	case 1, MauvilleCity_GameCorner_EventScript_BuyTRAPINCH
	case 2, MauvilleCity_GameCorner_EventScript_BuyHORSEA
	case 3, MauvilleCity_GameCorner_EventScript_BuyPANPOUR
	case 4, MauvilleCity_GameCorner_EventScript_BuyPANSAGE
	case 5, MauvilleCity_GameCorner_EventScript_BuyPANSEAR
	case 6, MauvilleCity_GameCorner_EventScript_BuyHERACROSS
	case 7, MauvilleCity_GameCorner_EventScript_BuySOBBLE
	case 8, MauvilleCity_GameCorner_EventScript_BuyGROOKEY
	case 9, MauvilleCity_GameCorner_EventScript_BuySCORBUNNY
	case 10, MauvilleCity_GameCorner_EventScript_BuyJANGMOO
	case 11, MauvilleCity_GameCorner_EventScript_BuyMELTAN
	end

MauvilleCity_GameCorner_EventScript_BuyTRAPINCH::
	checkcoins VAR_TEMP_2
	compare VAR_TEMP_2, TRAPINCH_COINS
	goto_if_lt MauvilleCity_GameCorner_EventScript_NotEnoughCoinsForPokemon
	removecoins TRAPINCH_COINS
	givemon SPECIES_TRAPINCH, 10
	updatecoinsbox 1, 1
	playse SE_SHOP
	msgbox MauvilleCity_GameCorner_Text_HereYouGo, MSGBOX_DEFAULT
	goto MauvilleCity_GameCorner_EventScript_ReturnToChoosePokemonPrize
	end

MauvilleCity_GameCorner_EventScript_BuyHORSEA::
	checkcoins VAR_TEMP_2
	compare VAR_TEMP_2, HORSEA_COINS
	goto_if_lt MauvilleCity_GameCorner_EventScript_NotEnoughCoinsForPokemon
	removecoins HORSEA_COINS
	givemon SPECIES_HORSEA, 10
	updatecoinsbox 1, 1
	playse SE_SHOP
	msgbox MauvilleCity_GameCorner_Text_HereYouGo, MSGBOX_DEFAULT
	goto MauvilleCity_GameCorner_EventScript_ReturnToChoosePokemonPrize
	end

MauvilleCity_GameCorner_EventScript_BuyPANPOUR::
	checkcoins VAR_TEMP_2
	compare VAR_TEMP_2, PANPOUR_COINS
	goto_if_lt MauvilleCity_GameCorner_EventScript_NotEnoughCoinsForPokemon
	removecoins PANPOUR_COINS
	givemon SPECIES_PANPOUR, 10
	updatecoinsbox 1, 1
	playse SE_SHOP
	msgbox MauvilleCity_GameCorner_Text_HereYouGo, MSGBOX_DEFAULT
	goto MauvilleCity_GameCorner_EventScript_ReturnToChoosePokemonPrize
	end

MauvilleCity_GameCorner_EventScript_BuyPANSAGE::
	checkcoins VAR_TEMP_2
	compare VAR_TEMP_2, PANSAGE_COINS
	goto_if_lt MauvilleCity_GameCorner_EventScript_NotEnoughCoinsForPokemon
	removecoins PANSAGE_COINS
	givemon SPECIES_PANSAGE, 10
	updatecoinsbox 1, 1
	playse SE_SHOP
	msgbox MauvilleCity_GameCorner_Text_HereYouGo, MSGBOX_DEFAULT
	goto MauvilleCity_GameCorner_EventScript_ReturnToChoosePokemonPrize
	end

MauvilleCity_GameCorner_EventScript_BuyPANSEAR::
	checkcoins VAR_TEMP_2
	compare VAR_TEMP_2, PANSEAR_COINS
	goto_if_lt MauvilleCity_GameCorner_EventScript_NotEnoughCoinsForPokemon
	removecoins PANSEAR_COINS
	givemon SPECIES_PANSEAR, 10
	updatecoinsbox 1, 1
	playse SE_SHOP
	msgbox MauvilleCity_GameCorner_Text_HereYouGo, MSGBOX_DEFAULT
	goto MauvilleCity_GameCorner_EventScript_ReturnToChoosePokemonPrize
	end

MauvilleCity_GameCorner_EventScript_BuyHERACROSS::
	checkcoins VAR_TEMP_2
	compare VAR_TEMP_2, HERACROSS_COINS
	goto_if_lt MauvilleCity_GameCorner_EventScript_NotEnoughCoinsForPokemon
	removecoins HERACROSS_COINS
	givemon SPECIES_HERACROSS, 25
	updatecoinsbox 1, 1
	playse SE_SHOP
	msgbox MauvilleCity_GameCorner_Text_HereYouGo, MSGBOX_DEFAULT
	goto MauvilleCity_GameCorner_EventScript_ReturnToChoosePokemonPrize
	end

MauvilleCity_GameCorner_EventScript_BuySOBBLE::
	checkcoins VAR_TEMP_2
	compare VAR_TEMP_2, SOBBLE_COINS
	goto_if_lt MauvilleCity_GameCorner_EventScript_NotEnoughCoinsForPokemon
	removecoins SOBBLE_COINS
	givemon SPECIES_SOBBLE, 5
	updatecoinsbox 1, 1
	playse SE_SHOP
	msgbox MauvilleCity_GameCorner_Text_HereYouGo, MSGBOX_DEFAULT
	goto MauvilleCity_GameCorner_EventScript_ReturnToChoosePokemonPrize
	end

MauvilleCity_GameCorner_EventScript_BuyGROOKEY::
	checkcoins VAR_TEMP_2
	compare VAR_TEMP_2, GROOKEY_COINS
	goto_if_lt MauvilleCity_GameCorner_EventScript_NotEnoughCoinsForPokemon
	removecoins GROOKEY_COINS
	givemon SPECIES_GROOKEY, 5
	updatecoinsbox 1, 1
	playse SE_SHOP
	msgbox MauvilleCity_GameCorner_Text_HereYouGo, MSGBOX_DEFAULT
	goto MauvilleCity_GameCorner_EventScript_ReturnToChoosePokemonPrize
	end

MauvilleCity_GameCorner_EventScript_BuySCORBUNNY::
	checkcoins VAR_TEMP_2
	compare VAR_TEMP_2, SCORBUNNY_COINS
	goto_if_lt MauvilleCity_GameCorner_EventScript_NotEnoughCoinsForPokemon
	removecoins SCORBUNNY_COINS
	givemon SPECIES_SCORBUNNY, 5
	updatecoinsbox 1, 1
	playse SE_SHOP
	msgbox MauvilleCity_GameCorner_Text_HereYouGo, MSGBOX_DEFAULT
	goto MauvilleCity_GameCorner_EventScript_ReturnToChoosePokemonPrize
	end

MauvilleCity_GameCorner_EventScript_BuyJANGMOO::
	checkcoins VAR_TEMP_2
	compare VAR_TEMP_2, JANGMOO_COINS
	goto_if_lt MauvilleCity_GameCorner_EventScript_NotEnoughCoinsForPokemon
	removecoins JANGMOO_COINS
	givemon SPECIES_JANGMO_O, 5
	updatecoinsbox 1, 1
	playse SE_SHOP
	msgbox MauvilleCity_GameCorner_Text_HereYouGo, MSGBOX_DEFAULT
	goto MauvilleCity_GameCorner_EventScript_ReturnToChoosePokemonPrize
	end

MauvilleCity_GameCorner_EventScript_BuyMELTAN::
	checkcoins VAR_TEMP_2
	compare VAR_TEMP_2, MELTAN_COINS
	goto_if_lt MauvilleCity_GameCorner_EventScript_NotEnoughCoinsForPokemon
	removecoins MELTAN_COINS
	givemon SPECIES_MELTAN, 5
	updatecoinsbox 1, 1
	playse SE_SHOP
	msgbox MauvilleCity_GameCorner_Text_HereYouGo, MSGBOX_DEFAULT
	goto MauvilleCity_GameCorner_EventScript_ReturnToChoosePokemonPrize
	end

MauvilleCity_GameCorner_Text_SoYourChoiceIsThePokemonX:
	.string "So your choice is\n"
	.string "the {STR_VAR_1}?$"

MauvilleCity_GameCorner_EventScript_RocketGruntBlocking::
	lock
	faceplayer
	msgbox MauvilleCity_GameCorner_Text_GetOff, MSGBOX_DEFAULT
	applymovement LOCALID_ROCKET_GRUNT, Common_Movement_FaceUp
	waitmovement 0
	release
	end

MauvilleCity_GameCorner_Text_GetOff:
    .string "What do you want?\n"
    .string "Get lost!$"

MauvilleCity_GameCorner_EventScript_PosterSign::
	msgbox MauvilleCity_GameCorner_Text_Poster, MSGBOX_SIGN
	end

MauvilleCity_GameCorner_Text_Poster:
    .string "Slot Machine 4 is\n"
	.string "out of service.$"

MauvilleCity_GameCorner_EventScript_TeamRocketPoster::
	lockall
	msgbox MauvilleCity_GameCorner_Text_TeamRocketPoster, MSGBOX_DEFAULT
	waitmessage
	msgbox MauvilleCity_GameCorner_Text_LookBehind, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq MauvilleCity_GameCorner_EventScript_TeamRocketPosterCancel
	waitse
	playse SE_UNLOCK
	setmetatile 17, 0, METATILE_MauvilleGameCorner_TeamRocketDoorUp, 1
	setmetatile 17, 1, METATILE_MauvilleGameCorner_TeamRocketDoorMiddle, 0
	setmetatile 17, 2, METATILE_MauvilleGameCorner_TeamRocketDoorBottom, 0
	special DrawWholeMapView
	removeobject LOCALID_POSTER
MauvilleCity_GameCorner_EventScript_TeamRocketPosterCancel:
	releaseall
	end

MauvilleCity_GameCorner_Text_LookBehind:
    .string "Hey!\p"
    .string "A switch behind the poster!?\n"
    .string "Do you want to push it?$"

MauvilleCity_GameCorner_Text_TeamRocketPoster:
    .string "A photograpy with a serious\n"
    .string "man called Giovanni.$"
