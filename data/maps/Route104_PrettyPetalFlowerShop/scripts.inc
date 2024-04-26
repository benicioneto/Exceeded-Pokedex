.set LOCALID_OWNER, 1

Route104_PrettyPetalFlowerShop_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route104_PrettyPetalFlowerShop_OnTransition
	.byte 0

Route104_PrettyPetalFlowerShop_OnTransition:
	setflag FLAG_LANDMARK_FLOWER_SHOP
	goto_if_unset FLAG_MET_PRETTY_PETAL_SHOP_OWNER, Route104_PrettyPetalFlowerShop_EventScript_MoveShopOwner
	goto_if_unset FLAG_BADGE03_GET, Route104_PrettyPetalFlowerShop_EventScript_MoveShopOwner
	clearflag FLAG_HIDE_GRANDFATHER_IN_FLOWER_SHOP
	setflag FLAG_TEMP_1
	end

Route104_PrettyPetalFlowerShop_EventScript_MoveShopOwner::
	setobjectxyperm LOCALID_OWNER, 4, 6
	end

Route104_PrettyPetalFlowerShop_EventScript_Grandfather::
	lock
	faceplayer
	goto_if_set FLAG_TEMP_2, Route104_PrettyPetalFlowerShop_EventScript_GiveBonsly
	msgbox Route104_PrettyPetalFlowerShop_Text_HelpingMyGrandaughter, MSGBOX_DEFAULT
	release
	end

Route104_PrettyPetalFlowerShop_EventScript_GiveBonsly::
	msgbox Route104_PrettyPetalFlowerShop_Text_ClientDeservesABonsly, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq Route104_PrettyPetalFlowerShop_EventScript_ClientWantsBonsly
Route104_PrettyPetalFlowerShop_EventScript_EndConversation:
	msgbox Route104_PrettyPetalFlowerShop_Text_ComeBackSoon, MSGBOX_DEFAULT
	clearflag FLAG_TEMP_2
	release
	end

Route104_PrettyPetalFlowerShop_EventScript_ClientWantsBonsly:
	playfanfare MUS_OBTAIN_ITEM
	bufferspeciesname 0, SPECIES_BONSLY
	setvar VAR_TEMP_1, SPECIES_BONSLY
	givemon SPECIES_BONSLY, 2
    switch VAR_RESULT
    case 0, EventScript_SendBonslyToParty
    case 1, EventScript_SendBonslyToPC
    case 2, Common_EventScript_NoMoreRoomForPokemon @"There's no more room for any more\..."
	end

EventScript_SendBonslyToParty:
	playfanfare MUS_OBTAIN_ITEM
	message BonslyAdquired
	waitmessage
	waitfanfare
    msgbox gText_NicknameThisPokemon, MSGBOX_YESNO @"Do you want to give a nickname to\..."
    compare VAR_RESULT, 0
    goto_if_eq Route104_PrettyPetalFlowerShop_EventScript_EndConversation
    call Common_EventScript_GetGiftMonPartySlot
	call Common_EventScript_NameReceivedPartyMon
    goto Route104_PrettyPetalFlowerShop_EventScript_EndConversation
	end

EventScript_SendBonslyToPC:
	playfanfare MUS_OBTAIN_ITEM
	message BonslyAdquired
	waitmessage
	waitfanfare
    msgbox gText_NicknameThisPokemon, MSGBOX_YESNO @"Do you want to give a nickname to\..."
    compare VAR_RESULT, 0
    goto_if_eq EventScript_BonslyTransferredToPC
    call Common_EventScript_NameReceivedBoxMon
    goto EventScript_BonslyTransferredToPC
	end

EventScript_BonslyTransferredToPC:
	call Common_EventScript_TransferredToPC
	goto Route104_PrettyPetalFlowerShop_EventScript_EndConversation
	end

Route104_PrettyPetalFlowerShop_Text_HelpingMyGrandaughter:
	.string "Hello, I'm the grandfather of the!\n"
	.string "owner of flower shop. I'm here\l"
	.string "helping my granddaughter because\l"
	.string "the number of customers has\l"
	.string "increased because of the new\l"
	.string "promotion.\p"
	.string "Buy a decoration and take a Bonsly!$"

Route104_PrettyPetalFlowerShop_Text_ClientDeservesABonsly:
	.string "Oh, a customer! Are you here because\n"
	.string "of the gift?$"

Route104_PrettyPetalFlowerShop_Text_ComeBackSoon:
	.string "Thank you for choosing this flower\n"
	.string "shop! Check back often!$"

BonslyAdquired:
	.string "{PLAYER} received the {STR_VAR_1}!$"

Route104_PrettyPetalFlowerShop_EventScript_ShopOwner::
	lock
	faceplayer
	goto_if_set FLAG_TEMP_1, Route104_PrettyPetalFlowerShop_EventScript_SellDecorations
	msgbox Route104_PrettyPetalFlowerShop_Text_ThisIsPrettyPetalFlowerShop, MSGBOX_DEFAULT
	goto_if_set FLAG_MET_PRETTY_PETAL_SHOP_OWNER, Route104_PrettyPetalFlowerShop_EventScript_AlreadyMet
	setflag FLAG_MET_PRETTY_PETAL_SHOP_OWNER
	msgbox Route104_PrettyPetalFlowerShop_Text_IntroLearnAboutBerries, MSGBOX_YESNO
	compare VAR_RESULT, YES
	call_if_eq Route104_PrettyPetalFlowerShop_EventScript_ExplainBerries
	compare VAR_RESULT, NO
	call_if_eq Route104_PrettyPetalFlowerShop_EventScript_DontExplainBerries
	release
	end

Route104_PrettyPetalFlowerShop_EventScript_AlreadyMet::
	msgbox Route104_PrettyPetalFlowerShop_Text_LearnAboutBerries, MSGBOX_YESNO
	compare VAR_RESULT, YES
	call_if_eq Route104_PrettyPetalFlowerShop_EventScript_ExplainBerries
	compare VAR_RESULT, NO
	call_if_eq Route104_PrettyPetalFlowerShop_EventScript_DontExplainBerries
	release
	end

Route104_PrettyPetalFlowerShop_EventScript_ExplainBerries::
	msgbox Route104_PrettyPetalFlowerShop_Text_BerriesExplanation, MSGBOX_DEFAULT
	return

Route104_PrettyPetalFlowerShop_EventScript_DontExplainBerries::
	msgbox Route104_PrettyPetalFlowerShop_Text_FlowersBringHappiness, MSGBOX_DEFAULT
	return

Route104_PrettyPetalFlowerShop_EventScript_SellDecorations::
	message gText_PlayerWhatCanIDoForYou
	waitmessage
	pokemartdecoration2 Route104_PrettyPetalFlowerShop_Pokemart_Plants
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
Route104_PrettyPetalFlowerShop_Pokemart_Plants:
	.2byte DECOR_RED_PLANT
	.2byte DECOR_TROPICAL_PLANT
	.2byte DECOR_PRETTY_FLOWERS
	.2byte DECOR_COLORFUL_PLANT
	.2byte DECOR_BIG_PLANT
	.2byte DECOR_GORGEOUS_PLANT
	.2byte DECOR_NONE
	release
	end

Route104_PrettyPetalFlowerShop_EventScript_WailmerPailGirl::
	lock
	faceplayer
	goto_if_unset FLAG_RECEIVED_WAILMER_PAIL, Route104_PrettyPetalFlowerShop_EventScript_GiveWailmerPail
	msgbox Route104_PrettyPetalFlowerShop_Text_WailmerPailExplanation, MSGBOX_DEFAULT
	release
	end

Route104_PrettyPetalFlowerShop_EventScript_GiveWailmerPail::
	msgbox Route104_PrettyPetalFlowerShop_Text_YouCanHaveThis, MSGBOX_DEFAULT
	giveitem ITEM_WAILMER_PAIL
	msgbox Route104_PrettyPetalFlowerShop_Text_WailmerPailExplanation, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_WAILMER_PAIL
	release
	end

Route104_PrettyPetalFlowerShop_EventScript_RandomBerryGirl::
	lock
	faceplayer
	dotimebasedevents
	goto_if_set FLAG_DAILY_FLOWER_SHOP_RECEIVED_BERRY, Route104_PrettyPetalFlowerShop_EventScript_AlreadyReceivedBerry
	msgbox Route104_PrettyPetalFlowerShop_Text_ImGrowingFlowers, MSGBOX_DEFAULT
	random 8
	addvar VAR_RESULT, FIRST_BERRY_INDEX
	giveitem VAR_RESULT
	compare VAR_RESULT, 0
	goto_if_eq Common_EventScript_ShowBagIsFull
	setflag FLAG_DAILY_FLOWER_SHOP_RECEIVED_BERRY
	msgbox Route104_PrettyPetalFlowerShop_Text_MachineMixesBerries, MSGBOX_DEFAULT
	release
	end

Route104_PrettyPetalFlowerShop_EventScript_AlreadyReceivedBerry::
	msgbox Route104_PrettyPetalFlowerShop_Text_MachineMixesBerries, MSGBOX_DEFAULT
	release
	end
