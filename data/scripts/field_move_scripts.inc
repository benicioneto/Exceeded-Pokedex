@ Interact with cuttable tree
EventScript_CutTree::
	lockall
	goto_if_unset FLAG_BADGE01_GET, EventScript_CheckTreeCantCut
	special CanUseCutOnTree
	compare VAR_0x8004, PARTY_SIZE
	goto_if_eq EventScript_CheckTreeCantCut
	setfieldeffectarg 0, VAR_0x8004
	bufferpartymonnick 0, VAR_0x8004
	buffermovename 1, MOVE_CUT
	msgbox Text_WantToCut, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq EventScript_CancelCut
	msgbox Text_MonUsedFieldMove, MSGBOX_DEFAULT
	closemessage
EventScript_CutTreeCommon:
	specialvar VAR_0x8004, IsFollowerOnVar8004 @ skip pose if so
	dofieldeffect FLDEFF_USE_CUT_ON_TREE
	waitstate
EventScript_CutTreeDown::
	compare VAR_0x8004, TRUE
	call_if_eq EventScript_FollowerFieldMove
	applymovement VAR_LAST_TALKED, Movement_CutTreeDown
	waitmovement 0
	removeobject VAR_LAST_TALKED
	releaseall
	end

@ Use cut from party menu
EventScript_UseCut::
	lockall
	goto EventScript_CutTreeCommon

Movement_CutTreeDown:
	cut_tree
	step_end

EventScript_CheckTreeCantCut::
	msgbox Text_CantCut, MSGBOX_DEFAULT
	releaseall
	end

EventScript_CancelCut::
	closemessage
	releaseall
	end

Text_WantToCut:
	.string "This tree looks like it can be\n"
	.string "Cut down!\p"
	.string "Would you like to Cut it?$"

Text_MonUsedFieldMove:
	.string "{STR_VAR_1} used {STR_VAR_2}!$"

Text_CantCut:
	.string "This tree looks like it can be\n"
	.string "Cut down!$"

@ Interact with smashable rock
EventScript_RockSmash::
	lockall
	goto_if_unset FLAG_BADGE03_GET, EventScript_CantSmashRock
	special CanUseRockSmashOnRock
	compare VAR_0x8004, PARTY_SIZE
	goto_if_eq EventScript_CantSmashRock
	setfieldeffectarg 0, VAR_0x8004
	bufferpartymonnick 0, VAR_0x8004
	buffermovename 1, MOVE_ROCK_SMASH
	msgbox Text_WantToSmash, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq EventScript_CancelSmash
	msgbox Text_MonUsedFieldMove, MSGBOX_DEFAULT
	closemessage
EventScript_RockSmashCommon:
	specialvar VAR_0x8004, IsFollowerOnVar8004 @ skip pose if so
	dofieldeffect FLDEFF_USE_ROCK_SMASH
	waitstate
EventScript_SmashRock::
	compare VAR_0x8004, TRUE
	call_if_eq EventScript_FollowerFieldMove
	applymovement VAR_LAST_TALKED, Movement_SmashRock
	waitmovement 0
	removeobject VAR_LAST_TALKED
	specialvar VAR_RESULT, TryUpdateRusturfTunnelState
	compare VAR_RESULT, TRUE
	goto_if_eq EventScript_EndSmash
	special RockSmashWildEncounter
	compare VAR_RESULT, FALSE
	goto_if_eq EventScript_EndSmash
	waitstate
	releaseall
	end

@ Use rock smash from party menu
EventScript_UseRockSmash::
	lockall
	special IsFollowerOnArgument @ skip pose if so
	dofieldeffect FLDEFF_USE_ROCK_SMASH
	waitstate
	goto EventScript_SmashRock
	end


EventScript_EndSmash::
	releaseall
	end

Movement_SmashRock:
	rock_smash_break
	step_end

EventScript_CantSmashRock::
	msgbox Text_CantSmash, MSGBOX_DEFAULT
	releaseall
	end

EventScript_CancelSmash::
	closemessage
	releaseall
	end

Text_WantToSmash:
	.string "This rock appears to be breakable.\n"
	.string "Would you like to use Rock Smash?$"

Text_CantSmash:
	.string "It's a rugged rock, but a Pokémon\n"
	.string "may be able to smash it.$"

EventScript_StrengthBoulder::
	lockall
	goto_if_unset FLAG_BADGE04_GET, EventScript_CantStrength
	goto_if_set FLAG_SYS_USE_STRENGTH, EventScript_CheckActivatedBoulder
	special CanUseStrengthOnBoulder
	compare VAR_0x8004, PARTY_SIZE
	goto_if_eq EventScript_CantStrength
	setfieldeffectarg 0, VAR_0x8004
	msgbox Text_WantToStrength, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq EventScript_CancelStrength
	closemessage
	special IsFollowerOnVar8004 @ skip pose if so
	dofieldeffect FLDEFF_USE_STRENGTH
	waitstate
	goto EventScript_ActivateStrength
	end

EventScript_UseStrength::
	lockall
	special IsFollowerOnArgument @ skip pose if so
	dofieldeffect FLDEFF_USE_STRENGTH
	waitstate
	goto EventScript_ActivateStrength
	end

EventScript_ActivateStrength::
	setflag FLAG_SYS_USE_STRENGTH
	msgbox Text_MonUsedStrength, MSGBOX_DEFAULT
	releaseall
	end

EventScript_CantStrength::
	msgbox Text_CantStrength, MSGBOX_DEFAULT
	releaseall
	end

EventScript_CheckActivatedBoulder::
	msgbox Text_StrengthActivated, MSGBOX_DEFAULT
	releaseall
	end

EventScript_CancelStrength::
	closemessage
	releaseall
	end

Text_WantToStrength:
	.string "It's a big boulder, but a Pokémon\n"
	.string "may be able to push it aside.\p"
	.string "Would you like to use Strength?$"

Text_MonUsedStrength:
	.string "{STR_VAR_1} used Strength!\p"
	.string "{STR_VAR_1}'s Strength made it\n"
	.string "possible to move boulders around!$"

Text_CantStrength:
	.string "It's a big boulder, but a Pokémon\n"
	.string "may be able to push it aside.$"

Text_StrengthActivated:
	.string "Strength made it possible to move\n"
	.string "boulders around.$"

EventScript_UseWaterfall::
	lockall
	special CanUseWaterfallOnWaterfall
	compare VAR_0x8004, PARTY_SIZE
	goto_if_eq EventScript_CantWaterfall
	bufferpartymonnick 0, VAR_0x8004
	setfieldeffectarg 0, VAR_0x8004
	msgbox Text_WantToWaterfall, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq EventScript_EndWaterfall
	msgbox Text_MonUsedWaterfall, MSGBOX_DEFAULT
	special IsFollowerOnVar8004 @ skip pose if so
	dofieldeffect FLDEFF_USE_WATERFALL
	goto EventScript_EndWaterfall

EventScript_CannotUseWaterfall::
	lockall

EventScript_CantWaterfall::
	msgbox Text_CantWaterfall, MSGBOX_DEFAULT

EventScript_EndWaterfall::
	releaseall
	end

Text_CantWaterfall:
	.string "A wall of water is crashing down with\n"
	.string "a mighty roar.$"

Text_WantToWaterfall:
	.string "It's a large waterfall.\n"
	.string "Would you like to use Watefall?$"

Text_MonUsedWaterfall:
	.string "{STR_VAR_1} used Watefall.$"

EventScript_UseDive::
	lockall
	special CanUseDiveOnWater
	compare VAR_0x8004, PARTY_SIZE
	goto_if_eq EventScript_CantDive
	bufferpartymonnick 0, VAR_0x8004
	setfieldeffectarg 0, VAR_0x8004
	setfieldeffectarg 1, 1
	msgbox Text_WantToDive, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq EventScript_EndDive
	msgbox Text_MonUsedDive, MSGBOX_DEFAULT
	special IsFollowerOnVar8004 @ skip pose if so
	dofieldeffect FLDEFF_USE_DIVE
	goto EventScript_EndDive
	end

EventScript_CantDive::
	msgbox Text_CantDive, MSGBOX_DEFAULT
	releaseall
	end

EventScript_EndDive::
	releaseall
	end

EventScript_UseDiveUnderwater::
	lockall
	special CanUseDiveUnderwater
	compare VAR_0x8004, PARTY_SIZE
	goto_if_eq EventScript_CantSurface
	bufferpartymonnick 0, VAR_0x8004
	setfieldeffectarg 0, VAR_0x8004
	setfieldeffectarg 1, 1
	msgbox Text_WantToSurface, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq EventScript_EndSurface
	msgbox Text_MonUsedDive, MSGBOX_DEFAULT
	special IsFollowerOnVar8004 @ skip pose if so
	dofieldeffect FLDEFF_USE_DIVE
	goto EventScript_EndSurface
	end

EventScript_CantSurface::
	lockall
	msgbox Text_CantSurface, MSGBOX_DEFAULT
	goto EventScript_EndSurface
	end

EventScript_EndSurface::
	releaseall
	end

Text_CantDive:
	.string "The sea is deep here. A Pokémon\n"
	.string "may be able to go underwater.$"

Text_WantToDive:
	.string "The sea is deep here.\n"
	.string "Would you like to use Dive?$"

Text_MonUsedDive:
	.string "{STR_VAR_1} used Dive.$"

Text_CantSurface:
	.string "Light is filtering down from above.\n"
	.string "A Pokémon may be able to surface.$"

Text_WantToSurface:
	.string "Light is filtering down from above.\n"
	.string "Would you like to use Dive?$"

EventScript_FailSweetScent::
	msgbox Text_FailSweetScent, MSGBOX_SIGN
	end

Text_FailSweetScent:
	.string "Looks like there's nothing here…$"


@ new code

PetalburgWoods_EventScript_BigMushroom::
	lockall
	removeobject VAR_LAST_TALKED
	setflag FLAG_DAILY_BIG_MUSHROOM
	call PetalburgWoods_BigMushroomResult
	releaseall
	end

PetalburgWoods_EventScript_TinyMushroom1::
	lockall
	removeobject VAR_LAST_TALKED
	setflag FLAG_DAILY_TINY_MUSHROOM_1
	call PetalburgWoods_TinyMushroomResult
	releaseall
	end

PetalburgWoods_EventScript_TinyMushroom2::
	lockall
	removeobject VAR_LAST_TALKED
	setflag FLAG_DAILY_TINY_MUSHROOM_2
	call PetalburgWoods_TinyMushroomResult
	releaseall
	end

PetalburgWoods_EventScript_TinyMushroom3::
	lockall
	removeobject VAR_LAST_TALKED
	setflag FLAG_DAILY_TINY_MUSHROOM_3
	call PetalburgWoods_TinyMushroomResult
	releaseall
	end

PetalburgWoods_EventScript_TinyMushroom4::
	lockall
	removeobject VAR_LAST_TALKED
	setflag FLAG_DAILY_TINY_MUSHROOM_4
	call PetalburgWoods_TinyMushroomResult
	releaseall
	end

PetalburgWoods_EventScript_TinyMushroom5::
	lockall
	removeobject VAR_LAST_TALKED
	setflag FLAG_DAILY_TINY_MUSHROOM_5
	call PetalburgWoods_TinyMushroomResult
	releaseall
	end

PetalburgWoods_EventScript_TinyMushroom6::
	lockall
	removeobject VAR_LAST_TALKED
	setflag FLAG_DAILY_TINY_MUSHROOM_6
	call PetalburgWoods_TinyMushroomResult
	releaseall
	end

PetalburgWoods_BigMushroomResult:
	random 10
    switch VAR_RESULT
	case 0, giveBigMushroom
	case 1, giveBigMushroom
	case 2, giveBigMushroom
	case 3, giveBigMushroom
	case 4, giveBigMushroom
	case 5, giveBigMushroom
	case 6, summonAmoonguss
	case 7, summonBreloom
	case 8, summonShiinotic
	case 9, summonParasect
	return

PetalburgWoods_TinyMushroomResult:
	random 10
    switch VAR_RESULT
	case 0, giveTinyMushroom
	case 1, giveTinyMushroom
	case 2, giveTinyMushroom
	case 3, giveTinyMushroom
	case 4, giveTinyMushroom
	case 5, giveTinyMushroom
	case 6, summonFoongus
	case 7, summonShroomish
	case 8, summonMorelull
	case 9, summonParas
	return

giveBigMushroom:
	giveitem ITEM_BIG_MUSHROOM
	return 
giveTinyMushroom:
	giveitem ITEM_TINY_MUSHROOM
	return 
summonFoongus:
	setwildbattle SPECIES_FOONGUS, 5, ITEM_TINY_MUSHROOM
	waitse
	playmoncry SPECIES_FOONGUS, 2
	delay 40
	waitmoncry
	dowildbattle
	return 
summonShroomish:
	setwildbattle SPECIES_SHROOMISH, 5, ITEM_TINY_MUSHROOM
	waitse
	playmoncry SPECIES_SHROOMISH, 2
	delay 40
	waitmoncry
	dowildbattle
	return 
summonMorelull:
	setwildbattle SPECIES_MORELULL, 5, ITEM_TINY_MUSHROOM
	waitse
	playmoncry SPECIES_MORELULL, 2
	delay 40
	waitmoncry
	dowildbattle
	return 
summonParas:
	setwildbattle SPECIES_PARAS, 5, ITEM_TINY_MUSHROOM
	waitse
	playmoncry SPECIES_PARAS, 2
	delay 40
	waitmoncry
	dowildbattle
	return 
summonAmoonguss:
	setwildbattle SPECIES_AMOONGUSS, 20, ITEM_BIG_MUSHROOM
	waitse
	playmoncry SPECIES_AMOONGUSS, 2
	delay 40
	waitmoncry
	dowildbattle
	return 
summonBreloom:
	setwildbattle SPECIES_BRELOOM, 20, ITEM_BIG_MUSHROOM
	waitse
	playmoncry SPECIES_BRELOOM, 2
	delay 40
	waitmoncry
	dowildbattle
	return 
summonShiinotic:
	setwildbattle SPECIES_SHIINOTIC, 20, ITEM_BIG_MUSHROOM
	waitse
	playmoncry SPECIES_SHIINOTIC, 2
	delay 40
	waitmoncry
	dowildbattle
	return 
summonParasect:
	setwildbattle SPECIES_PARASECT, 20, ITEM_BIG_MUSHROOM
	waitse
	playmoncry SPECIES_PARASECT, 2
	delay 40
	waitmoncry
	dowildbattle
	return 

General_EventScript_ZygardeCell::
	lockall
	showmonpic SPECIES_ZYGARDE_CELL, 1, 4
	checkitem ITEM_ZYGARDE_CUBE, 1
	compare VAR_RESULT, FALSE
	goto_if_eq General_EventScript_NoZygardeCube
	msgbox General_Text_CollectedCell, MSGBOX_DEFAULT
	hidemonpic
	removeobject VAR_LAST_TALKED
	getzygardescript
	compare VAR_0x8004, 7
	goto_if_eq General_EventScript_GiveZygardeCell
	compare VAR_0x8004, 8
	goto_if_eq General_EventScript_GiveZygardeCore
	compare VAR_0x8004, 1
	goto_if_eq General_EventScript_GiveZygarde10
	compare VAR_0x8004, 2
	goto_if_eq General_EventScript_TurnZygarde50
	compare VAR_0x8004, 3
	goto_if_eq General_EventScript_EnablePowerConstruct
	releaseall
	end

General_EventScript_ZygardeCore::
	lockall
	showmonpic SPECIES_ZYGARDE_CORE, 1, 4
	checkitem ITEM_ZYGARDE_CUBE, 1
	compare VAR_RESULT, FALSE
	goto_if_eq General_EventScript_NoZygardeCube
	msgbox General_Text_CollectedCore, MSGBOX_DEFAULT
	removeobject VAR_LAST_TALKED
	hidemonpic
	getzygardescript
	compare VAR_0x8004, 7
	goto_if_eq General_EventScript_GiveZygardeCell
	compare VAR_0x8004, 8
	goto_if_eq General_EventScript_GiveZygardeCore
	compare VAR_0x8004, 1
	goto_if_eq General_EventScript_GiveZygarde10
	compare VAR_0x8004, 2
	goto_if_eq General_EventScript_TurnZygarde50
	compare VAR_0x8004, 3
	goto_if_eq General_EventScript_EnablePowerConstruct
	releaseall
	end

@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
General_EventScript_GiveZygardeCell::
	playse SE_PIN
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
	waitmovement 0
	bufferspeciesname 0, SPECIES_ZYGARDE_CELL
	setvar VAR_TEMP_1, SPECIES_ZYGARDE_CELL
	msgbox General_Text_GatheringToFormZygardeCell, MSGBOX_DEFAULT
    switch VAR_0x8005
    case 0, EventScript_SendZygardeToParty
    case 1, EventScript_SendZygardeToPC
    case 2, Common_EventScript_NoMoreRoomForPokemon
	end

General_EventScript_GiveZygardeCore::
	playse SE_PIN
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
	waitmovement 0
	bufferspeciesname 0, SPECIES_ZYGARDE_CORE
	setvar VAR_TEMP_1, SPECIES_ZYGARDE_CORE
	msgbox General_Text_GatheringToFormZygardeCore, MSGBOX_DEFAULT
    switch VAR_0x8005
    case 0, EventScript_SendZygardeToParty
    case 1, EventScript_SendZygardeToPC
    case 2, Common_EventScript_NoMoreRoomForPokemon
	end

General_EventScript_GiveZygarde10::
	playse SE_PIN
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
	waitmovement 0
	bufferspeciesname 0, SPECIES_ZYGARDE_10
	setvar VAR_TEMP_1, SPECIES_ZYGARDE_10
	msgbox General_Text_GatheringToFormZygarde10, MSGBOX_DEFAULT
    switch VAR_0x8005
    case 0, EventScript_SendZygardeToParty
    case 1, EventScript_SendZygardeToPC
    case 2, Common_EventScript_NoMoreRoomForPokemon
	end

EventScript_SendZygardeToParty:
	playfanfare MUS_OBTAIN_ITEM
	message ZygardeCellsFormed
	waitmessage
	waitfanfare
    msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
    compare VAR_RESULT, 0
    goto_if_eq EventScript_ZygardeScriptEnd
    call Common_EventScript_GetGiftMonPartySlot
	call Common_EventScript_NameReceivedPartyMon
    goto EventScript_ZygardeScriptEnd
	end

EventScript_SendZygardeToPC:
	playfanfare MUS_OBTAIN_ITEM
	message ZygardeCellsFormed
	waitmessage
	waitfanfare
    msgbox gText_NicknameThisPokemon, MSGBOX_YESNO @"Do you want to give a nickname to\..."
    compare VAR_RESULT, 0
    goto_if_eq EventScript_ZygardeTransferredToPC
    call Common_EventScript_NameReceivedBoxMon
    goto EventScript_ZygardeTransferredToPC2
	end

EventScript_ZygardeTransferredToPC:
    call Common_EventScript_TransferredToPC
    goto EventScript_ZygardeScriptEnd
    end

EventScript_ZygardeTransferredToPC2:
    call Common_EventScript_TransferredToPC
    goto EventScript_ZygardeScriptEnd
    end

EventScript_ZygardeScriptEnd:
	releaseall
    end

ZygardeCellsFormed:
	.string "Zygarde was formed!$"

@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
General_EventScript_TurnZygarde50::
	playse SE_PIN
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
	waitmovement 0
	playfanfare MUS_OBTAIN_ITEM
	msgbox General_Text_Zygarde50, MSGBOX_NPC
	waitfanfare
	releaseall
	end

@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
General_EventScript_EnablePowerConstruct::
	playfanfare MUS_OBTAIN_ITEM
	msgbox General_Text_EnabledPowerConstruct, MSGBOX_NPC
	waitfanfare
	releaseall
	end

General_EventScript_NoZygardeCube::
	msgbox General_Text_CantCollectWithNoZygardeCube, MSGBOX_DEFAULT
	hidemonpic
	releaseall
	end

General_Text_GatheringToFormZygardeCell::
	.string "This small and green thing\n"
	.string "is actually a Pokémon!$"

General_Text_GatheringToFormZygardeCore::
	.string "The Pokémon got part of its brain.\n"
	.string "It looks more intellectual now!$"

General_Text_GatheringToFormZygarde10:
	.string "The Zygarde Cells are clumpling\n"
	.string "together in the Core, reaching\l"
	.string "10% of its complete form!$"

General_Text_CollectedCell:
	.string "{PLAYER} collected a Zygarde Cell!$"

General_Text_CollectedCore:
	.string "{PLAYER} collected a Zygarde Core!$"

General_Text_Zygarde50:
	.string "The Zygarde Cells are clumpling\n"
	.string "together in the Zygarde, reaching\l"
	.string "50% of its complete form!$"

General_Text_EnabledPowerConstruct:
	.string "Zygarde's Power Construct was\n"
	.string "enabled!$"

General_Text_CantCollectWithNoZygardeCube:
	.string "You can't collect if you don't have\n"
	.string "a Zygarde Cube.$"

@@@@@
General_EventScript_SpiritombWisp::
	lock
	checkitem ITEM_ODD_KEYSTONE, 1
	compare VAR_RESULT, FALSE
	goto_if_eq General_EventScript_NoOddKeystone
	msgbox General_Text_CollectedWisps, MSGBOX_DEFAULT
	getspiritombscript VAR_LAST_TALKED
	compare VAR_0x8004, 1
	goto_if_eq General_EventScript_GiveSpiritomb
	compare VAR_0x8004, 2
	goto_if_eq General_EventScript_UpgradeSpiritomb
	release
	end

General_EventScript_NoOddKeystone::
	msgbox General_Text_CantCollectWithNoOddKeystone, MSGBOX_DEFAULT
	release
	end

General_EventScript_GiveSpiritomb::
	playse SE_PIN
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
	waitmovement 0
	bufferspeciesname 0, SPECIES_SPIRITOMB
	setvar VAR_TEMP_1, SPECIES_SPIRITOMB
	msgbox General_Text_GatheringToFormSpiritomb, MSGBOX_DEFAULT
    switch VAR_0x8005
    case 0, EventScript_SendSpiritombToParty
    case 1, EventScript_SendSpiritombToPC
    case 2, Common_EventScript_NoMoreRoomForPokemon
	end

@
EventScript_SendSpiritombToParty:
	playfanfare MUS_OBTAIN_ITEM
	message SpiritombFormed
	waitmessage
	waitfanfare
    msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
    compare VAR_RESULT, 0
    goto_if_eq EventScript_SpiritombScriptEnd
    call Common_EventScript_GetGiftMonPartySlot
	call Common_EventScript_NameReceivedPartyMon
    goto EventScript_SpiritombScriptEnd
	end

EventScript_SendSpiritombToPC:
	playfanfare MUS_OBTAIN_ITEM
	message SpiritombFormed
	waitmessage
	waitfanfare
    msgbox gText_NicknameThisPokemon, MSGBOX_YESNO @"Do you want to give a nickname to\..."
    compare VAR_RESULT, 0
    goto_if_eq EventScript_SpiritombTransferredToPC
    call Common_EventScript_NameReceivedBoxMon
    goto EventScript_SpiritombTransferredToPC2
	end

EventScript_SpiritombTransferredToPC:
    call Common_EventScript_TransferredToPC
    goto EventScript_SpiritombScriptEnd
    end

EventScript_SpiritombTransferredToPC2:
    call Common_EventScript_TransferredToPC
    goto EventScript_SpiritombScriptEnd
    end

EventScript_SpiritombScriptEnd:
	release
    end

SpiritombFormed:
	.string "Spiritomb was formed!$"

@
General_EventScript_UpgradeSpiritomb::
	playse SE_PIN
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
	waitmovement 0
	playfanfare MUS_OBTAIN_ITEM
	msgbox General_Text_SpiritombUpgrade, MSGBOX_NPC
	waitfanfare
	release
	end

General_Text_SpiritombUpgrade:
	.string "Spiritomb is getting stronger!$"

General_Text_GatheringToFormSpiritomb:
	.string "The spirits awakened!$"

General_Text_CollectedWisps:
	.string "{PLAYER} collected a wisp!$"

General_Text_CantCollectWithNoOddKeystone:
	.string "You can't collect if you don't have\n"
	.string "a Odd Keystone.$"

EventScript_HeadbuttTree::
	lockall
	checkpartymove MOVE_HEADBUTT
	compare VAR_RESULT, PARTY_SIZE
	goto_if_eq EventScript_EndHeadbutt
	setfieldeffectarg 0, VAR_RESULT
	bufferpartymonnick 0, VAR_RESULT
	buffermovename 1, MOVE_HEADBUTT
	msgbox Text_WantToHeadbutt, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq EventScript_CancelHeadbutt
	msgbox Text_MonUsedFieldMove, MSGBOX_DEFAULT
	closemessage
	special IsFollowerOnVar8004 @ skip pose if so
	goto EventScript_DoHeadbutt
	end

EventScript_UseHeadbutt::
	lockall
	special IsFollowerOnArgument @ skip pose if so
EventScript_DoHeadbutt:
	dofieldeffect FLDEFF_USE_HEADBUTT
	waitstate
	waitse
	special HeadbuttTreeWildEncounter
	compare VAR_RESULT, 0
	goto_if_eq EventScript_HeadbuttNothing
	waitstate
EventScript_EndHeadbutt:
	releaseall
	end

EventScript_HeadbuttNothing:
	msgbox Text_HeadbuttNothing, MSGBOX_DEFAULT
	releaseall
	end

EventScript_CancelHeadbutt::
	closemessage
	releaseall
	end

Text_WantToHeadbutt:
	.string "A Pokémon could be in this tree.\n"
	.string "Want to Headbutt it?$"

Text_HeadbuttNothing::
	.string "Nope. Nothing…$"

@@@ Follower using HM @@@
EventScript_FollowerFieldMove:
	specialvar VAR_0x8005, GetFollowerDirectionToFace
	specialvar VAR_0x8006, GetPlayerFacingDirection
	compare VAR_0x8005, DIR_NONE
	goto_if_eq EventScript_FollowerFieldMoveEnd
	@ Swap follower and player
	call EventScript_FollowerSwap
	@ Face follower in direction and jump
	switch VAR_0x8006
	case DIR_NORTH, EventScript_FollowerJumpNorth
	case DIR_EAST, EventScript_FollowerJumpEast
	case DIR_SOUTH, EventScript_FollowerJumpSouth
	case DIR_WEST, EventScript_FollowerJumpWest
EventScript_FollowerFieldMoveEnd:
	return

EventScript_FollowerSwap:
	switch VAR_0x8005
	case DIR_NORTH, EventScript_FollowerMoveNorth
	case DIR_EAST, EventScript_FollowerMoveEast
	case DIR_SOUTH, EventScript_FollowerMoveSouth
	case DIR_WEST, EventScript_FollowerMoveWest
	return

EventScript_FollowerMoveNorth:
	applymovement OBJ_EVENT_ID_FOLLOWER, Movement_WalkUp
	applymovement OBJ_EVENT_ID_PLAYER, Movement_WalkDown
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceUp
	waitmovement 0
	return

EventScript_FollowerMoveEast:
	applymovement OBJ_EVENT_ID_FOLLOWER, Movement_WalkRight
	applymovement OBJ_EVENT_ID_PLAYER, Movement_WalkLeft
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceRight
	waitmovement 0
	return

EventScript_FollowerMoveSouth:
	applymovement OBJ_EVENT_ID_FOLLOWER, Movement_WalkDown
	applymovement OBJ_EVENT_ID_PLAYER, Movement_WalkUp
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceDown
	waitmovement 0
	return

EventScript_FollowerMoveWest:
	applymovement OBJ_EVENT_ID_FOLLOWER, Movement_WalkLeft
	applymovement OBJ_EVENT_ID_PLAYER, Movement_WalkRight
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceLeft
	waitmovement 0
	return

EventScript_FollowerJumpNorth:
	applymovement OBJ_EVENT_ID_FOLLOWER, Movement_JumpUp
	waitmovement 0
	return

EventScript_FollowerJumpEast:
	applymovement OBJ_EVENT_ID_FOLLOWER, Movement_JumpRight
	waitmovement 0
	return

EventScript_FollowerJumpSouth:
	applymovement OBJ_EVENT_ID_FOLLOWER, Movement_JumpDown
	waitmovement 0
	return

EventScript_FollowerJumpWest:
	applymovement OBJ_EVENT_ID_FOLLOWER, Movement_JumpLeft
	waitmovement 0
	return

Movement_WalkUp:
	walk_up
	step_end

Movement_JumpUp:
	@jump_in_place_up
	jump_up
	lock_facing_direction
	walk_fast_down
	unlock_facing_direction
	step_end

Movement_WalkRight:
	walk_right
	step_end

Movement_JumpRight:
	@jump_in_place_right
	jump_right
	lock_facing_direction
	walk_fast_left
	unlock_facing_direction
	step_end

Movement_WalkDown:
	walk_down
	step_end

Movement_JumpDown:
	@jump_in_place_down
	jump_down
	lock_facing_direction
	walk_fast_up
	unlock_facing_direction
	step_end

Movement_WalkLeft:
	walk_left
	step_end

Movement_JumpLeft:
	@jump_in_place_left
	jump_left
	lock_facing_direction
	walk_fast_right
	unlock_facing_direction
	step_end
