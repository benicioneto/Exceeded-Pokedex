LilycoveCity_DepartmentStoreRooftop_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, LilycoveCity_DepartmentStoreRooftop_OnTransition
	.byte 0

LilycoveCity_DepartmentStoreRooftop_OnTransition:
	getpricereduction POKENEWS_LILYCOVE
	compare VAR_RESULT, TRUE
	call_if_eq LilycoveCity_DepartmentStoreRooftop_EventScript_ShowSaleWoman
	compare VAR_RESULT, FALSE
	call_if_eq LilycoveCity_DepartmentStoreRooftop_EventScript_HideSaleWoman
	end

LilycoveCity_DepartmentStoreRooftop_EventScript_ShowSaleWoman::
	clearflag FLAG_HIDE_LILYCOVE_DEPARTMENT_STORE_ROOFTOP_SALE_WOMAN
	return

LilycoveCity_DepartmentStoreRooftop_EventScript_HideSaleWoman::
	setflag FLAG_HIDE_LILYCOVE_DEPARTMENT_STORE_ROOFTOP_SALE_WOMAN
	return

LilycoveCity_DepartmentStoreRooftop_EventScript_SaleWoman::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemartdecoration LilycoveCity_DepartmentStoreRooftop_PokemartDecor_ClearOutSale
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
LilycoveCity_DepartmentStoreRooftop_PokemartDecor_ClearOutSale:
	.2byte DECOR_MUD_BALL
	.2byte DECOR_FENCE_LENGTH
	.2byte DECOR_FENCE_WIDTH
	.2byte DECOR_TIRE
	.2byte DECOR_BREAKABLE_DOOR
	.2byte DECOR_SOLID_BOARD
	.2byte DECOR_SAND_ORNAMENT
	.2byte DECOR_STAND
	.2byte DECOR_SLIDE
	.2byte DECOR_TV
	.2byte DECOR_ROUND_TV
	.2byte DECOR_CUTE_TV
	.2byte DECOR_WAILMER_DOLL
	.2byte DECOR_RHYDON_DOLL
	.2byte 0
	release
	end

LilycoveCity_DepartmentStoreRooftop_EventScript_Man::
	lock
	faceplayer
	getpricereduction POKENEWS_LILYCOVE
	compare VAR_RESULT, TRUE
	call_if_eq LilycoveCity_DepartmentStoreRooftop_EventScript_ManClearOutSale
	msgbox LilycoveCity_DepartmentStoreRooftop_Text_SetDatesForClearOutSales, MSGBOX_DEFAULT
	release
	end

LilycoveCity_DepartmentStoreRooftop_EventScript_ManClearOutSale::
	msgbox LilycoveCity_DepartmentStoreRooftop_Text_BeenWaitingForClearOutSale, MSGBOX_DEFAULT
	release
	end

LilycoveCity_DepartmentStoreRooftop_EventScript_ThirstyMan::
	lock
	faceplayer
	call CeladonCity_DepartmentStore_Roof_EventScript_CheckPlayerHasDrinks
	compare VAR_TEMP_1, 0
	goto_if_eq CeladonCity_DepartmentStore_Roof_EventScript_IWantDrink
	goto CeladonCity_DepartmentStore_Roof_EventScript_AskGiveDrink
	end

CeladonCity_DepartmentStore_Roof_EventScript_CheckPlayerHasDrinks::
	setvar VAR_TEMP_1, 0
	checkitem ITEM_FRESH_WATER, 1
	compare VAR_RESULT, TRUE
	call_if_eq CeladonCity_DepartmentStore_Roof_EventScript_SetHasFreshWater
	checkitem ITEM_SODA_POP, 1
	compare VAR_RESULT, TRUE
	call_if_eq CeladonCity_DepartmentStore_Roof_EventScript_SetHasSodaPop
	checkitem ITEM_LEMONADE, 1
	compare VAR_RESULT, TRUE
	call_if_eq CeladonCity_DepartmentStore_Roof_EventScript_SetHasLemonade
	return

CeladonCity_DepartmentStore_Roof_EventScript_SetHasFreshWater:: @ 816BD2C
	addvar VAR_TEMP_1, 1
	return

CeladonCity_DepartmentStore_Roof_EventScript_SetHasSodaPop:: @ 816BD32
	addvar VAR_TEMP_1, 2
	return

CeladonCity_DepartmentStore_Roof_EventScript_SetHasLemonade:: @ 816BD38
	addvar VAR_TEMP_1, 4
	return

CeladonCity_DepartmentStore_Roof_EventScript_AskGiveDrink:: @ 816BD3E
	msgbox CeladonCity_DepartmentStore_Roof_Text_ImThirstyGiveHerDrink, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq CeladonCity_DepartmentStore_Roof_EventScript_DontGiveDrink
	message CeladonCity_DepartmentStore_Roof_Text_GiveWhichDrink
	waitmessage
	switch VAR_TEMP_1
	case 1, CeladonCity_DepartmentStore_Roof_EventScript_AskGiveFreshWater
	case 2, CeladonCity_DepartmentStore_Roof_EventScript_AskGiveSodaPop
	case 3, CeladonCity_DepartmentStore_Roof_EventScript_AskGiveFreshWaterSodaPop
	case 4, CeladonCity_DepartmentStore_Roof_EventScript_AskGiveLemonade
	case 5, CeladonCity_DepartmentStore_Roof_EventScript_AskGiveFreshWaterLemonade
	case 6, CeladonCity_DepartmentStore_Roof_EventScript_AskGiveSodaPopLemonade
	case 7, CeladonCity_DepartmentStore_Roof_EventScript_AskGiveAllDrinks
	end

LilycoveCity_DepartmentStoreRooftop_EventScript_VendingMachine::
	lockall
	message LilycoveCity_DepartmentStoreRooftop_Text_WhichDrinkWouldYouLike
	waitmessage
	showmoneybox 0, 0, 0
	goto LilycoveCity_DepartmentStoreRooftop_EventScript_ChooseDrink
	end

LilycoveCity_DepartmentStoreRooftop_EventScript_ChooseDrink::
	multichoice 16, 0, MULTI_VENDING_MACHINE, FALSE
	copyvar VAR_TEMP_1, VAR_RESULT
	switch VAR_TEMP_1
	case 0, LilycoveCity_DepartmentStoreRooftop_EventScript_FreshWater
	case 1, LilycoveCity_DepartmentStoreRooftop_EventScript_SodaPop
	case 2, LilycoveCity_DepartmentStoreRooftop_EventScript_Lemonade
	msgbox LilycoveCity_DepartmentStoreRooftop_Text_DecidedAgainstBuyingDrink, MSGBOX_DEFAULT
	goto LilycoveCity_DepartmentStoreRooftop_EventScript_ExitVendingMachine
	end

LilycoveCity_DepartmentStoreRooftop_EventScript_FreshWater::
	setvar VAR_TEMP_0, ITEM_FRESH_WATER
	goto LilycoveCity_DepartmentStoreRooftop_EventScript_TryBuyDrink
	end

LilycoveCity_DepartmentStoreRooftop_EventScript_SodaPop::
	setvar VAR_TEMP_0, ITEM_SODA_POP
	goto LilycoveCity_DepartmentStoreRooftop_EventScript_TryBuyDrink
	end

LilycoveCity_DepartmentStoreRooftop_EventScript_Lemonade::
	setvar VAR_TEMP_0, ITEM_LEMONADE
	goto LilycoveCity_DepartmentStoreRooftop_EventScript_TryBuyDrink
	end

LilycoveCity_DepartmentStoreRooftop_EventScript_CheckMoneyFreshWater::
	checkmoney 200, 0
	return

LilycoveCity_DepartmentStoreRooftop_EventScript_CheckMoneySodaPop::
	checkmoney 300, 0
	return

LilycoveCity_DepartmentStoreRooftop_EventScript_CheckMoneyLemonade::
	checkmoney 350, 0
	return

LilycoveCity_DepartmentStoreRooftop_EventScript_RemoveMoneyFreshWater::
	removemoney 200, 0
	return

LilycoveCity_DepartmentStoreRooftop_EventScript_RemoveMoneySodaPop::
	removemoney 300, 0
	return

LilycoveCity_DepartmentStoreRooftop_EventScript_RemoveMoneyLemonade::
	removemoney 350, 0
	return

LilycoveCity_DepartmentStoreRooftop_EventScript_TryBuyDrink::
	compare VAR_TEMP_1, 0
	call_if_eq LilycoveCity_DepartmentStoreRooftop_EventScript_CheckMoneyFreshWater
	compare VAR_TEMP_1, 1
	call_if_eq LilycoveCity_DepartmentStoreRooftop_EventScript_CheckMoneySodaPop
	compare VAR_TEMP_1, 2
	call_if_eq LilycoveCity_DepartmentStoreRooftop_EventScript_CheckMoneyLemonade
	compare VAR_RESULT, FALSE
	goto_if_eq LilycoveCity_DepartmentStoreRooftop_EventScript_NotEnoughMoneyForDrink
	checkitemspace VAR_TEMP_0, 1
	compare VAR_RESULT, FALSE
	goto_if_eq LilycoveCity_DepartmentStoreRooftop_EventScript_NoRoomForDrink
	compare VAR_TEMP_1, 0
	call_if_eq LilycoveCity_DepartmentStoreRooftop_EventScript_RemoveMoneyFreshWater
	compare VAR_TEMP_1, 1
	call_if_eq LilycoveCity_DepartmentStoreRooftop_EventScript_RemoveMoneySodaPop
	compare VAR_TEMP_1, 2
	call_if_eq LilycoveCity_DepartmentStoreRooftop_EventScript_RemoveMoneyLemonade
	updatemoneybox 0, 0
	bufferitemname 0, VAR_TEMP_0
	playse SE_VEND
	msgbox LilycoveCity_DepartmentStoreRooftop_Text_CanOfDrinkDroppedDown, MSGBOX_DEFAULT
	additem VAR_TEMP_0
	bufferitemname 1, VAR_TEMP_0
	bufferstdstring 2, STDSTRING_ITEMS
	msgbox gText_PutItemInPocket, MSGBOX_DEFAULT
	random 64  @ 1/64 chance of an additional drink dropping
	compare VAR_RESULT, 0
	goto_if_ne LilycoveCity_DepartmentStoreRooftop_EventScript_ChooseNewDrink
	checkitemspace VAR_TEMP_0, 1
	compare VAR_RESULT, FALSE
	goto_if_eq LilycoveCity_DepartmentStoreRooftop_EventScript_NoRoomForDrink
	playse SE_VEND
	msgbox LilycoveCity_DepartmentStoreRooftop_Text_ExtraCanOfDrinkDroppedDown, MSGBOX_DEFAULT
	additem VAR_TEMP_0
	bufferitemname 1, VAR_TEMP_0
	bufferstdstring 2, STDSTRING_ITEMS
	msgbox gText_PutItemInPocket, MSGBOX_DEFAULT
	random 64  @ 1/64 * the prev 1/64 chance of a third additional drink dropping, ~ 0.02% chance
	compare VAR_RESULT, 0
	goto_if_ne LilycoveCity_DepartmentStoreRooftop_EventScript_ChooseNewDrink
	checkitemspace VAR_TEMP_0, 1
	compare VAR_RESULT, 0
	goto_if_eq LilycoveCity_DepartmentStoreRooftop_EventScript_NoRoomForDrink
	playse SE_VEND
	msgbox LilycoveCity_DepartmentStoreRooftop_Text_ExtraCanOfDrinkDroppedDown, MSGBOX_DEFAULT
	additem VAR_TEMP_0
	bufferitemname 1, VAR_TEMP_0
	bufferstdstring 2, STDSTRING_ITEMS
	msgbox gText_PutItemInPocket, MSGBOX_DEFAULT
	goto LilycoveCity_DepartmentStoreRooftop_EventScript_ChooseNewDrink
	end

LilycoveCity_DepartmentStoreRooftop_EventScript_ChooseNewDrink::
	message LilycoveCity_DepartmentStoreRooftop_Text_WhichDrinkWouldYouLike
	waitmessage
	goto LilycoveCity_DepartmentStoreRooftop_EventScript_ChooseDrink
	end

LilycoveCity_DepartmentStoreRooftop_EventScript_NotEnoughMoneyForDrink::
	msgbox LilycoveCity_DepartmentStoreRooftop_Text_NotEnoughMoney, MSGBOX_DEFAULT
	goto LilycoveCity_DepartmentStoreRooftop_EventScript_ExitVendingMachine
	end

LilycoveCity_DepartmentStoreRooftop_EventScript_NoRoomForDrink::
	msgbox gText_TheBagIsFull, MSGBOX_DEFAULT
	goto LilycoveCity_DepartmentStoreRooftop_EventScript_ExitVendingMachine
	end

LilycoveCity_DepartmentStoreRooftop_EventScript_ExitVendingMachine::
	hidemoneybox
	releaseall
	end

LilycoveCity_DepartmentStoreRooftop_Text_SetDatesForClearOutSales:
	.string "Don't they have set dates for their\n"
	.string "clear-out sales?\p"
	.string "I watch Tv, but they never show any\n"
	.string "commercials.$"

LilycoveCity_DepartmentStoreRooftop_Text_BeenWaitingForClearOutSale:
	.string "Yes! I've been waiting a long time for\n"
	.string "this clear-out sale.\p"
	.string "They have items that you can only get\n"
	.string "here. I'm going to load up, that I am!$"

LilycoveCity_DepartmentStoreRooftop_Text_BoneDryThirsty:
	.string "Ohh… I'm bone-dry thirsty!$"

LilycoveCity_DepartmentStoreRooftop_Text_WhichDrinkWouldYouLike:
	.string "It's a Vending Machine.\n"
	.string "Which drink would you like?$"

LilycoveCity_DepartmentStoreRooftop_Text_CanOfDrinkDroppedDown:
	.string "Clang!\p"
	.string "A can of {STR_VAR_1} dropped down.$"

LilycoveCity_DepartmentStoreRooftop_Text_ExtraCanOfDrinkDroppedDown:
	.string "Clang!\p"
	.string "Score! An extra can of {STR_VAR_1}\n"
	.string "dropped down!$"

LilycoveCity_DepartmentStoreRooftop_Text_NotEnoughMoney:
	.string "Not enough money…$"

LilycoveCity_DepartmentStoreRooftop_Text_DecidedAgainstBuyingDrink:
	.string "Decided against buying a drink.$"
CeladonCity_DepartmentStore_Roof_Text_ImThirstyGiveHerDrink:: @ 8195D22
    .string "I'm thirsty!\n"
    .string "I want something to drink!\p"
    .string "{SIZE}ÁGive him a drink?$"

CeladonCity_DepartmentStore_Roof_Text_GiveWhichDrink:: @ 8195D5F
    .string "Give her which drink?$"

CeladonCity_DepartmentStore_Roof_Text_YayFreshWaterHaveThis:: @ 8195D75
    .string "Yay!\p"
    .string "Fresh Water!\p"
    .string "Thank you!\n"
    .string "You can have this from me!$"

Text_ReceivedItemFromLittleGirl:: @ 8195DAD
    .string "{PLAYER} received a {STR_VAR_2}\n"
    .string "from the boy.$"

CeladonCity_DepartmentStore_Roof_Text_ExplainTM16:: @ 8195DD4
    .string "TM62 contains Frozen Terrain.\p"
    .string "It's a move that boosts the power\n"
    .string "of Ice-type moves of Pokémon\l"
	.string "standing on the ice.\p"
	.string "Also, they Pokémon may slip\n"
	.string "on the ice and hurt itself!$"

CeladonCity_DepartmentStore_Roof_Text_YaySodaPopHaveThis:: @ 8195E33
    .string "Yay!\p"
    .string "Soda Pop!\p"
    .string "Thank you!\n"
    .string "You can have this from me!$"

CeladonCity_DepartmentStore_Roof_Text_ExplainTM20:: @ 8195E68
    .string "TM63 contains Sandy Terrain.\p"
    .string "It's a move that boosts the power\n"
    .string "of Ground-type moves of Pokémon\l"
	.string "standing on the sand.\p"
	.string "Also, Pokémon have their\n"
	.string "evasion lowered!$"

CeladonCity_DepartmentStore_Roof_Text_YayLemonadeHaveThis:: @ 8195EBF
    .string "Yay!\p"
    .string "Lemonade!\p"
    .string "Thank you!\n"
    .string "You can have this from me!$"

CeladonCity_DepartmentStore_Roof_Text_ExplainTM33:: @ 8195EF4
    .string "TM64 contains Swamp Terrain.\p"
    .string "It's a move that boosts the power\n"
    .string "of Water-type moves of Pokémon\l"
	.string "standing on the mud.\p"
	.string "Also, Pokémon have their\n"
	.string "speed lowered!$"

CeladonCity_DepartmentStore_Roof_Text_DontHaveSpaceForThis:: @ 8195F4F
    .string "You don't have space for this!$"

CeladonCity_DepartmentStore_Roof_Text_ImNotThirstyAfterAll:: @ 8195F6E
    .string "No, thank you!\n"
    .string "I'm not thirsty after all!$"


CeladonCity_DepartmentStore_Roof_EventScript_AskGiveFreshWater:: @ 816BDAE
	multichoice 0, 0, MULTI_FRESH_WATER, FALSE
	switch VAR_RESULT
	case 0, CeladonCity_DepartmentStore_Roof_EventScript_GiveFreshWater
	case 1, CeladonCity_DepartmentStore_Roof_EventScript_DontGiveDrink
	case 127, CeladonCity_DepartmentStore_Roof_EventScript_DontGiveDrink
	end

CeladonCity_DepartmentStore_Roof_EventScript_AskGiveSodaPop:: @ 816BDDA
	multichoice 0, 0, MULTI_SODA_POP, FALSE
	switch VAR_RESULT
	case 0, CeladonCity_DepartmentStore_Roof_EventScript_GiveSodaPop
	case 1, CeladonCity_DepartmentStore_Roof_EventScript_DontGiveDrink
	case 127, CeladonCity_DepartmentStore_Roof_EventScript_DontGiveDrink
	end

CeladonCity_DepartmentStore_Roof_EventScript_AskGiveFreshWaterSodaPop:: @ 816BE06
	multichoice 0, 0, MULTI_FRESH_WATER_SODA_POP, FALSE
	switch VAR_RESULT
	case 0, CeladonCity_DepartmentStore_Roof_EventScript_GiveFreshWater
	case 1, CeladonCity_DepartmentStore_Roof_EventScript_GiveSodaPop
	case 2, CeladonCity_DepartmentStore_Roof_EventScript_DontGiveDrink
	case 127, CeladonCity_DepartmentStore_Roof_EventScript_DontGiveDrink
	end

CeladonCity_DepartmentStore_Roof_EventScript_AskGiveLemonade:: @ 816BE3D
	multichoice 0, 0, MULTI_LEMONADE, FALSE
	switch VAR_RESULT
	case 0, CeladonCity_DepartmentStore_Roof_EventScript_GiveLemonade
	case 1, CeladonCity_DepartmentStore_Roof_EventScript_DontGiveDrink
	case 127, CeladonCity_DepartmentStore_Roof_EventScript_DontGiveDrink
	end

CeladonCity_DepartmentStore_Roof_EventScript_AskGiveFreshWaterLemonade:: @ 816BE69
	multichoice 0, 0, MULTI_FRESH_WATER_LEMONADE, FALSE
	switch VAR_RESULT
	case 0, CeladonCity_DepartmentStore_Roof_EventScript_GiveFreshWater
	case 1, CeladonCity_DepartmentStore_Roof_EventScript_GiveLemonade
	case 2, CeladonCity_DepartmentStore_Roof_EventScript_DontGiveDrink
	case 127, CeladonCity_DepartmentStore_Roof_EventScript_DontGiveDrink
	end

CeladonCity_DepartmentStore_Roof_EventScript_AskGiveSodaPopLemonade:: @ 816BEA0
	multichoice 0, 0, MULTI_SODA_POP_LEMONADE, FALSE
	switch VAR_RESULT
	case 0, CeladonCity_DepartmentStore_Roof_EventScript_GiveSodaPop
	case 1, CeladonCity_DepartmentStore_Roof_EventScript_GiveLemonade
	case 2, CeladonCity_DepartmentStore_Roof_EventScript_DontGiveDrink
	case 127, CeladonCity_DepartmentStore_Roof_EventScript_DontGiveDrink
	end

CeladonCity_DepartmentStore_Roof_EventScript_AskGiveAllDrinks:: @ 816BED7
	multichoice 0, 0, MULTI_FRESH_WATER_SODA_POP_LEMONADE, FALSE
	switch VAR_RESULT
	case 0, CeladonCity_DepartmentStore_Roof_EventScript_GiveFreshWater
	case 1, CeladonCity_DepartmentStore_Roof_EventScript_GiveSodaPop
	case 2, CeladonCity_DepartmentStore_Roof_EventScript_GiveLemonade
	case 3, CeladonCity_DepartmentStore_Roof_EventScript_DontGiveDrink
	case 127, CeladonCity_DepartmentStore_Roof_EventScript_DontGiveDrink
	end

CeladonCity_DepartmentStore_Roof_EventScript_GiveFreshWater:: @ 816BF19
	setvar VAR_0x8008, ITEM_FRESH_WATER
	setvar VAR_0x8009, ITEM_TM62
	goto_if_set FLAG_RECEIVED_TM62, CeladonCity_DepartmentStore_Roof_EventScript_NotThirstyAfterAll
	msgbox CeladonCity_DepartmentStore_Roof_Text_YayFreshWaterHaveThis
	goto CeladonCity_DepartmentStore_Roof_EventScript_GiveDrink
	end

CeladonCity_DepartmentStore_Roof_EventScript_GiveSodaPop:: @ 816BF3A
	setvar VAR_0x8008, ITEM_SODA_POP
	setvar VAR_0x8009, ITEM_TM63
	goto_if_set FLAG_RECEIVED_TM63, CeladonCity_DepartmentStore_Roof_EventScript_NotThirstyAfterAll
	msgbox CeladonCity_DepartmentStore_Roof_Text_YaySodaPopHaveThis
	goto CeladonCity_DepartmentStore_Roof_EventScript_GiveDrink
	end

CeladonCity_DepartmentStore_Roof_EventScript_GiveLemonade:: @ 816BF5B
	setvar VAR_0x8008, ITEM_LEMONADE
	setvar VAR_0x8009, ITEM_TM64
	goto_if_set FLAG_RECEIVED_TM64, CeladonCity_DepartmentStore_Roof_EventScript_NotThirstyAfterAll
	msgbox CeladonCity_DepartmentStore_Roof_Text_YayLemonadeHaveThis
	goto CeladonCity_DepartmentStore_Roof_EventScript_GiveDrink
	end

CeladonCity_DepartmentStore_Roof_EventScript_GiveDrink:: @ 816BF7C
	bufferitemname 0, VAR_0x8008
	bufferitemname 1, VAR_0x8009
	removeitem VAR_0x8008, 1
	giveitem VAR_0x8009
	message Text_ReceivedItemFromLittleGirl
	waitmessage
	waitfanfare
	compare VAR_0x8008, ITEM_FRESH_WATER
	call_if_eq CeladonCity_DepartmentStore_Roof_EventScript_ExplainTM16
	compare VAR_0x8008, ITEM_SODA_POP
	call_if_eq CeladonCity_DepartmentStore_Roof_EventScript_ExplainTM20
	compare VAR_0x8008, ITEM_LEMONADE
	call_if_eq CeladonCity_DepartmentStore_Roof_EventScript_ExplainTM33
	release
	end

CeladonCity_DepartmentStore_Roof_EventScript_ExplainTM16:: @ 816BFDE
	setflag FLAG_RECEIVED_TM62
	msgbox CeladonCity_DepartmentStore_Roof_Text_ExplainTM16
	return

CeladonCity_DepartmentStore_Roof_EventScript_ExplainTM20:: @ 816BFEA
	setflag FLAG_RECEIVED_TM63
	msgbox CeladonCity_DepartmentStore_Roof_Text_ExplainTM20
	return

CeladonCity_DepartmentStore_Roof_EventScript_ExplainTM33:: @ 816BFF6
	setflag FLAG_RECEIVED_TM64
	msgbox CeladonCity_DepartmentStore_Roof_Text_ExplainTM33
	return

CeladonCity_DepartmentStore_Roof_EventScript_NoRoomForReward:: @ 816C002
	msgbox CeladonCity_DepartmentStore_Roof_Text_DontHaveSpaceForThis
	release
	end

CeladonCity_DepartmentStore_Roof_EventScript_DontGiveDrink:: @ 816C00C
	release
	end

CeladonCity_DepartmentStore_Roof_EventScript_IWantDrink:: @ 816C00E
	msgbox CeladonCity_DepartmentStore_Roof_Text_ImThirstyIWantDrink
	release
	end

CeladonCity_DepartmentStore_Roof_EventScript_NotThirstyAfterAll:: @ 816C018
	msgbox CeladonCity_DepartmentStore_Roof_Text_ImNotThirstyAfterAll
	release
	end

CeladonCity_DepartmentStore_Roof_Text_ImThirstyIWantDrink:: @ 8195FEF
    .string "I'm thirsty!\n"
    .string "I want something to drink!$"
