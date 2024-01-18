.set LOCALID_FOSSIL_SCIENTIST, 5

RustboroCity_DevonCorp_2F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, RustboroCity_DevonCorp_2F_OnTransition
	.byte 0

RustboroCity_DevonCorp_2F_OnTransition:
	compare VAR_FOSSIL_RESURRECTION_STATE, 1
	call_if_eq RustboroCity_DevonCorp_2F_EventScript_SetFossilReady
	end

RustboroCity_DevonCorp_2F_EventScript_SetFossilReady::
	call_if_unset FLAG_DAILY_FOSSIL_REVIVE, RustboroCity_DevonCorp_2F_EventScript_SetFossilReady_for_sure
	@call RustboroCity_DevonCorp_2F_EventScript_SetFossilReady_for_sure
	return

RustboroCity_DevonCorp_2F_EventScript_SetFossilReady_for_sure:
	setvar VAR_FOSSIL_RESURRECTION_STATE, 2
	return

RustboroCity_DevonCorp_2F_EventScript_TalkToPokemonScientist::
	lock
	faceplayer
	compare VAR_FOSSIL_RESURRECTION_STATE, 1
	call_if_eq RustboroCity_DevonCorp_2F_EventScript_SetFossilReady
	msgbox RustboroCity_DevonCorp_2F_Text_DeviceForTalkingToPokemon, MSGBOX_DEFAULT
	release
	end

RustboroCity_DevonCorp_2F_EventScript_BallScientist::
	lock
	faceplayer
	compare VAR_FOSSIL_RESURRECTION_STATE, 1
	call_if_eq RustboroCity_DevonCorp_2F_EventScript_SetFossilReady
	goto_if_set FLAG_MET_DEVON_EMPLOYEE, RustboroCity_DevonCorp_2F_EventScript_DevelopedBalls
	msgbox RustboroCity_DevonCorp_2F_Text_DevelopingNewBalls, MSGBOX_DEFAULT
	release
	end

RustboroCity_DevonCorp_2F_EventScript_DevelopedBalls::
	msgbox RustboroCity_DevonCorp_2F_Text_WeFinallyMadeNewBalls, MSGBOX_DEFAULT
	release
	end

RustboroCity_DevonCorp_2F_EventScript_PokenavScientist::
	lock
	faceplayer
	compare VAR_FOSSIL_RESURRECTION_STATE, 1
	call_if_eq RustboroCity_DevonCorp_2F_EventScript_SetFossilReady
	goto_if_set FLAG_RECEIVED_POKENAV, RustboroCity_DevonCorp_2F_EventScript_HasPokenav
	msgbox RustboroCity_DevonCorp_2F_Text_IMadePokenav, MSGBOX_DEFAULT
	release
	end

RustboroCity_DevonCorp_2F_EventScript_HasPokenav::
	msgbox RustboroCity_DevonCorp_2F_Text_WowThatsAPokenav, MSGBOX_DEFAULT
	release
	end

RustboroCity_DevonCorp_2F_EventScript_PokemonDreamsScientist::
	lock
	faceplayer
	compare VAR_FOSSIL_RESURRECTION_STATE, 1
	call_if_eq RustboroCity_DevonCorp_2F_EventScript_SetFossilReady
	msgbox RustboroCity_DevonCorp_2F_Text_DeviceToVisualizePokemonDreams, MSGBOX_DEFAULT
	release
	end

@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
RustboroCity_DevonCorp_2F_EventScript_FossilScientistReworked::
	lock
	faceplayer
	compare VAR_FOSSIL_RESURRECTION_STATE, 2
	goto_if_eq RustboroCity_DevonCorp_2F_EventScript_FossilPokemonIsReady
	compare VAR_FOSSIL_RESURRECTION_STATE, 1
	goto_if_eq RustboroCity_DevonCorp_2F_EventScript_StillRegenerating	@Ok to reuse
	msgbox RustboroCity_DevonCorp_2F_Text_DoYouHaveSomeFossil, MSGBOX_DEFAULT
	playse SE_PIN
	applymovement LOCALID_FOSSIL_SCIENTIST, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_FOSSIL_SCIENTIST, Common_Movement_Delay48
	waitmovement 0
RustboroCity_DevonCorp_2F_EventScript_ReturnToChooseFossil:
	setvar VAR_0x8004, SCROLL_MULTI_FOSSIL_REGENERATOR_DEVICE
	special ShowFrontierExchangeCornerItemIconWindow
	special ShowScrollableMultichoice
	waitstate
	special CloseFrontierExchangeCornerItemIconWindow
	switch VAR_RESULT
	case 0, RustboroCity_DevonCorp_2F_EventScript_Helix
	case 1, RustboroCity_DevonCorp_2F_EventScript_Dome
	case 2, RustboroCity_DevonCorp_2F_EventScript_Old_Amber
	case 3, RustboroCity_DevonCorp_2F_EventScript_Root
	case 4, RustboroCity_DevonCorp_2F_EventScript_Claw
	case 5, RustboroCity_DevonCorp_2F_EventScript_Skull
	case 6, RustboroCity_DevonCorp_2F_EventScript_Armor
	case 7, RustboroCity_DevonCorp_2F_EventScript_Cover
	case 8, RustboroCity_DevonCorp_2F_EventScript_Plume
	case 9, RustboroCity_DevonCorp_2F_EventScript_Jaw
	case 10, RustboroCity_DevonCorp_2F_EventScript_Sail
	case 11, RustboroCity_DevonCorp_2F_EventScript_Bird
	case 12, RustboroCity_DevonCorp_2F_EventScript_Fish
	case 13, RustboroCity_DevonCorp_2F_EventScript_Drake
	case 14, RustboroCity_DevonCorp_2F_EventScript_Dino
	case 15, RustboroCity_DevonCorp_2F_EventScript_CancelPokemonSelect
	case MULTI_B_PRESSED, RustboroCity_DevonCorp_2F_EventScript_CancelPokemonSelect
	goto RustboroCity_DevonCorp_2F_EventScript_CancelPokemonSelect
	end

RustboroCity_DevonCorp_2F_EventScript_Helix::
	setvar VAR_TEMP_1, 1
	bufferitemname 0, ITEM_HELIX_FOSSIL
	goto RustboroCity_DevonCorp_2F_EventScript_ConfirmRevive

RustboroCity_DevonCorp_2F_EventScript_Dome::
	setvar VAR_TEMP_1, 2
	bufferitemname 0, ITEM_DOME_FOSSIL
	goto RustboroCity_DevonCorp_2F_EventScript_ConfirmRevive

RustboroCity_DevonCorp_2F_EventScript_Old_Amber::
	setvar VAR_TEMP_1, 3
	bufferitemname 0, ITEM_OLD_AMBER
	goto RustboroCity_DevonCorp_2F_EventScript_ConfirmRevive

RustboroCity_DevonCorp_2F_EventScript_Root::
	setvar VAR_TEMP_1, 4
	bufferitemname 0, ITEM_ROOT_FOSSIL
	goto RustboroCity_DevonCorp_2F_EventScript_ConfirmRevive

RustboroCity_DevonCorp_2F_EventScript_Claw::
	setvar VAR_TEMP_1, 5
	bufferitemname 0, ITEM_CLAW_FOSSIL
	goto RustboroCity_DevonCorp_2F_EventScript_ConfirmRevive

RustboroCity_DevonCorp_2F_EventScript_Skull::
	setvar VAR_TEMP_1, 6
	bufferitemname 0, ITEM_SKULL_FOSSIL
	goto RustboroCity_DevonCorp_2F_EventScript_ConfirmRevive

RustboroCity_DevonCorp_2F_EventScript_Armor::
	setvar VAR_TEMP_1, 7
	bufferitemname 0, ITEM_ARMOR_FOSSIL
	goto RustboroCity_DevonCorp_2F_EventScript_ConfirmRevive

RustboroCity_DevonCorp_2F_EventScript_Cover::
	setvar VAR_TEMP_1, 8
	bufferitemname 0, ITEM_COVER_FOSSIL
	goto RustboroCity_DevonCorp_2F_EventScript_ConfirmRevive

RustboroCity_DevonCorp_2F_EventScript_Plume::
	setvar VAR_TEMP_1, 9
	bufferitemname 0, ITEM_PLUME_FOSSIL
	goto RustboroCity_DevonCorp_2F_EventScript_ConfirmRevive

RustboroCity_DevonCorp_2F_EventScript_Jaw::
	setvar VAR_TEMP_1, 10
	bufferitemname 0, ITEM_JAW_FOSSIL
	goto RustboroCity_DevonCorp_2F_EventScript_ConfirmRevive

RustboroCity_DevonCorp_2F_EventScript_Sail::
	setvar VAR_TEMP_1, 11
	bufferitemname 0, ITEM_SAIL_FOSSIL
	goto RustboroCity_DevonCorp_2F_EventScript_ConfirmRevive

RustboroCity_DevonCorp_2F_EventScript_Bird::
	setvar VAR_TEMP_1, 12
	bufferitemname 0, ITEM_FOSSILIZED_BIRD
	goto RustboroCity_DevonCorp_2F_EventScript_ConfirmRevive

RustboroCity_DevonCorp_2F_EventScript_Fish::
	setvar VAR_TEMP_1, 13
	bufferitemname 0, ITEM_FOSSILIZED_FISH
	goto RustboroCity_DevonCorp_2F_EventScript_ConfirmRevive

RustboroCity_DevonCorp_2F_EventScript_Drake::
	setvar VAR_TEMP_1, 14
	bufferitemname 0, ITEM_FOSSILIZED_DRAKE
	goto RustboroCity_DevonCorp_2F_EventScript_ConfirmRevive

RustboroCity_DevonCorp_2F_EventScript_Dino::
	setvar VAR_TEMP_1, 15
	bufferitemname 0, ITEM_FOSSILIZED_DINO
	goto RustboroCity_DevonCorp_2F_EventScript_ConfirmRevive

RustboroCity_DevonCorp_2F_EventScript_ConfirmRevive:
	msgbox RustboroCity_DevonCorp_2F_Text_SoYourChoiceIsTheItemX, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq RustboroCity_DevonCorp_2F_EventScript_ReturnToChooseFossil
	switch VAR_TEMP_1
	case 1, RustboroCity_DevonCorp_2F_EventScript_Helix_Revive
	case 2, RustboroCity_DevonCorp_2F_EventScript_Dome_Revive
	case 3, RustboroCity_DevonCorp_2F_EventScript_Old_Amber_Revive
	case 4, RustboroCity_DevonCorp_2F_EventScript_Root_Revive
	case 5, RustboroCity_DevonCorp_2F_EventScript_Claw_Revive
	case 6, RustboroCity_DevonCorp_2F_EventScript_Skull_Revive
	case 7, RustboroCity_DevonCorp_2F_EventScript_Armor_Revive
	case 8, RustboroCity_DevonCorp_2F_EventScript_Cover_Revive
	case 9, RustboroCity_DevonCorp_2F_EventScript_Plume_Revive
	case 10, RustboroCity_DevonCorp_2F_EventScript_Jaw_Revive
	case 11, RustboroCity_DevonCorp_2F_EventScript_Sail_Revive
	case 12, RustboroCity_DevonCorp_2F_EventScript_Bird_Revive
	case 13, RustboroCity_DevonCorp_2F_EventScript_Fish_Revive
	case 14, RustboroCity_DevonCorp_2F_EventScript_Drake_Revive
	case 15, RustboroCity_DevonCorp_2F_EventScript_Dino_Revive
	end

RustboroCity_DevonCorp_2F_EventScript_Helix_Revive:
	checkitem ITEM_HELIX_FOSSIL, 1
	compare VAR_RESULT, FALSE
	goto_if_eq RustboroCity_DevonCorp_2F_EventScript_NoFossil
	removeitem ITEM_HELIX_FOSSIL, 1
	setvar VAR_WHICH_FOSSIL_REVIVED, 1
	goto RustboroCity_DevonCorp_2F_EventScript_GiveTheFossil
	end

RustboroCity_DevonCorp_2F_EventScript_Dome_Revive:
	checkitem ITEM_DOME_FOSSIL, 1
	compare VAR_RESULT, FALSE
	goto_if_eq RustboroCity_DevonCorp_2F_EventScript_NoFossil
	removeitem ITEM_DOME_FOSSIL, 1
	setvar VAR_WHICH_FOSSIL_REVIVED, 2
	goto RustboroCity_DevonCorp_2F_EventScript_GiveTheFossil
	end

RustboroCity_DevonCorp_2F_EventScript_Old_Amber_Revive:
	checkitem ITEM_OLD_AMBER, 1
	compare VAR_RESULT, FALSE
	goto_if_eq RustboroCity_DevonCorp_2F_EventScript_NoFossil
	removeitem ITEM_OLD_AMBER, 1
	setvar VAR_WHICH_FOSSIL_REVIVED, 3
	goto RustboroCity_DevonCorp_2F_EventScript_GiveTheFossil
	end

RustboroCity_DevonCorp_2F_EventScript_Root_Revive:
	checkitem ITEM_ROOT_FOSSIL, 1
	compare VAR_RESULT, FALSE
	goto_if_eq RustboroCity_DevonCorp_2F_EventScript_NoFossil
	removeitem ITEM_ROOT_FOSSIL, 1
	setvar VAR_WHICH_FOSSIL_REVIVED, 4
	goto RustboroCity_DevonCorp_2F_EventScript_GiveTheFossil
	end

RustboroCity_DevonCorp_2F_EventScript_Claw_Revive:
	checkitem ITEM_CLAW_FOSSIL, 1
	compare VAR_RESULT, FALSE
	goto_if_eq RustboroCity_DevonCorp_2F_EventScript_NoFossil
	removeitem ITEM_CLAW_FOSSIL, 1
	setvar VAR_WHICH_FOSSIL_REVIVED, 5
	goto RustboroCity_DevonCorp_2F_EventScript_GiveTheFossil
	end

RustboroCity_DevonCorp_2F_EventScript_Skull_Revive:
	checkitem ITEM_SKULL_FOSSIL, 1
	compare VAR_RESULT, FALSE
	goto_if_eq RustboroCity_DevonCorp_2F_EventScript_NoFossil
	removeitem ITEM_SKULL_FOSSIL, 1
	setvar VAR_WHICH_FOSSIL_REVIVED, 6
	goto RustboroCity_DevonCorp_2F_EventScript_GiveTheFossil
	end

RustboroCity_DevonCorp_2F_EventScript_Armor_Revive:
	checkitem ITEM_ARMOR_FOSSIL, 1
	compare VAR_RESULT, FALSE
	goto_if_eq RustboroCity_DevonCorp_2F_EventScript_NoFossil
	removeitem ITEM_ARMOR_FOSSIL, 1
	setvar VAR_WHICH_FOSSIL_REVIVED, 7
	goto RustboroCity_DevonCorp_2F_EventScript_GiveTheFossil
	end

RustboroCity_DevonCorp_2F_EventScript_Cover_Revive:
	checkitem ITEM_COVER_FOSSIL, 1
	compare VAR_RESULT, FALSE
	goto_if_eq RustboroCity_DevonCorp_2F_EventScript_NoFossil
	removeitem ITEM_COVER_FOSSIL, 1
	setvar VAR_WHICH_FOSSIL_REVIVED, 8
	goto RustboroCity_DevonCorp_2F_EventScript_GiveTheFossil
	end

RustboroCity_DevonCorp_2F_EventScript_Plume_Revive:
	checkitem ITEM_PLUME_FOSSIL, 1
	compare VAR_RESULT, FALSE
	goto_if_eq RustboroCity_DevonCorp_2F_EventScript_NoFossil
	removeitem ITEM_PLUME_FOSSIL, 1
	setvar VAR_WHICH_FOSSIL_REVIVED, 9
	goto RustboroCity_DevonCorp_2F_EventScript_GiveTheFossil
	end

RustboroCity_DevonCorp_2F_EventScript_Jaw_Revive:
	checkitem ITEM_JAW_FOSSIL, 1
	compare VAR_RESULT, FALSE
	goto_if_eq RustboroCity_DevonCorp_2F_EventScript_NoFossil
	removeitem ITEM_JAW_FOSSIL, 1
	setvar VAR_WHICH_FOSSIL_REVIVED, 10
	goto RustboroCity_DevonCorp_2F_EventScript_GiveTheFossil
	end

RustboroCity_DevonCorp_2F_EventScript_Sail_Revive:
	checkitem ITEM_SAIL_FOSSIL, 1
	compare VAR_RESULT, FALSE
	goto_if_eq RustboroCity_DevonCorp_2F_EventScript_NoFossil
	removeitem ITEM_SAIL_FOSSIL, 1
	setvar VAR_WHICH_FOSSIL_REVIVED, 11
	goto RustboroCity_DevonCorp_2F_EventScript_GiveTheFossil
	end

RustboroCity_DevonCorp_2F_EventScript_Bird_Revive:
	checkitem ITEM_FOSSILIZED_BIRD, 1
	compare VAR_RESULT, FALSE
	goto_if_eq RustboroCity_DevonCorp_2F_EventScript_NoFossil
	setvar VAR_TEMP_3, 1
	goto RustboroCity_DevonCorp_2F_EventScript_MissingHalfBird
	end

RustboroCity_DevonCorp_2F_EventScript_Fish_Revive:
	checkitem ITEM_FOSSILIZED_FISH, 1
	compare VAR_RESULT, FALSE
	goto_if_eq RustboroCity_DevonCorp_2F_EventScript_NoFossil
	setvar VAR_TEMP_3, 2
	goto RustboroCity_DevonCorp_2F_EventScript_MissingHalfFish
	end

RustboroCity_DevonCorp_2F_EventScript_Drake_Revive:
	checkitem ITEM_FOSSILIZED_DRAKE, 1
	compare VAR_RESULT, FALSE
	goto_if_eq RustboroCity_DevonCorp_2F_EventScript_NoFossil
	setvar VAR_TEMP_3, 3
	goto RustboroCity_DevonCorp_2F_EventScript_MissingHalfDrake
	end

RustboroCity_DevonCorp_2F_EventScript_Dino_Revive:
	checkitem ITEM_FOSSILIZED_DINO, 1
	compare VAR_RESULT, FALSE
	goto_if_eq RustboroCity_DevonCorp_2F_EventScript_NoFossil
	setvar VAR_TEMP_3, 4
	goto RustboroCity_DevonCorp_2F_EventScript_MissingHalfDino
	end

RustboroCity_DevonCorp_2F_EventScript_MissingHalfBird:
	msgbox RustboroCity_DevonCorp_2F_Text_MissingHalf, MSGBOX_DEFAULT
	setvar VAR_0x8004, SCROLL_MULTI_FOSSIL_REGENERATOR_DEVICE_BIRD_FISH
	special ShowFrontierExchangeCornerItemIconWindow
	special ShowScrollableMultichoice
	waitstate
	special CloseFrontierExchangeCornerItemIconWindow
	switch VAR_RESULT
	case 0, RustboroCity_DevonCorp_2F_EventScript_Bird_Drake
	case 1, RustboroCity_DevonCorp_2F_EventScript_Bird_Dino
	case MULTI_B_PRESSED, RustboroCity_DevonCorp_2F_EventScript_CancelPokemonSelect
	goto RustboroCity_DevonCorp_2F_EventScript_CancelPokemonSelect
	end

RustboroCity_DevonCorp_2F_EventScript_Bird_Drake:
	checkitem ITEM_FOSSILIZED_DRAKE, 1
	compare VAR_RESULT, FALSE
	goto_if_eq RustboroCity_DevonCorp_2F_EventScript_NoFossil
	msgbox RustboroCity_DevonCorp_2F_Text_AreYouSureTheyMatch, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq RustboroCity_DevonCorp_2F_EventScript_MissingHalfBird
	removeitem ITEM_FOSSILIZED_BIRD, 1
	removeitem ITEM_FOSSILIZED_DRAKE, 1
	setvar VAR_WHICH_FOSSIL_REVIVED, 12
	bufferitemname 1, ITEM_FOSSILIZED_DRAKE
	goto RustboroCity_DevonCorp_2F_EventScript_GiveTheTwoFossil
	end

RustboroCity_DevonCorp_2F_EventScript_Bird_Dino:
	checkitem ITEM_FOSSILIZED_DINO, 1
	compare VAR_RESULT, FALSE
	goto_if_eq RustboroCity_DevonCorp_2F_EventScript_NoFossil
	msgbox RustboroCity_DevonCorp_2F_Text_AreYouSureTheyMatch, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq RustboroCity_DevonCorp_2F_EventScript_MissingHalfBird
	removeitem ITEM_FOSSILIZED_BIRD, 1
	removeitem ITEM_FOSSILIZED_DINO, 1
	setvar VAR_WHICH_FOSSIL_REVIVED, 13
	bufferitemname 1, ITEM_FOSSILIZED_DINO
	goto RustboroCity_DevonCorp_2F_EventScript_GiveTheTwoFossil
	end

RustboroCity_DevonCorp_2F_EventScript_MissingHalfFish:
	msgbox RustboroCity_DevonCorp_2F_Text_MissingHalf, MSGBOX_DEFAULT
	setvar VAR_0x8004, SCROLL_MULTI_FOSSIL_REGENERATOR_DEVICE_BIRD_FISH
	special ShowFrontierExchangeCornerItemIconWindow
	special ShowScrollableMultichoice
	waitstate
	special CloseFrontierExchangeCornerItemIconWindow
	switch VAR_RESULT
	case 0, RustboroCity_DevonCorp_2F_EventScript_Fish_Drake
	case 1, RustboroCity_DevonCorp_2F_EventScript_Fish_Dino
	case MULTI_B_PRESSED, RustboroCity_DevonCorp_2F_EventScript_CancelPokemonSelect
	goto RustboroCity_DevonCorp_2F_EventScript_CancelPokemonSelect
	end

RustboroCity_DevonCorp_2F_EventScript_Fish_Drake:
	checkitem ITEM_FOSSILIZED_DRAKE, 1
	compare VAR_RESULT, FALSE
	goto_if_eq RustboroCity_DevonCorp_2F_EventScript_NoFossil
	msgbox RustboroCity_DevonCorp_2F_Text_AreYouSureTheyMatch, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq RustboroCity_DevonCorp_2F_EventScript_MissingHalfFish
	removeitem ITEM_FOSSILIZED_FISH, 1
	removeitem ITEM_FOSSILIZED_DRAKE, 1
	setvar VAR_WHICH_FOSSIL_REVIVED, 14
	bufferitemname 1, ITEM_FOSSILIZED_DRAKE
	goto RustboroCity_DevonCorp_2F_EventScript_GiveTheTwoFossil
	end

RustboroCity_DevonCorp_2F_EventScript_Fish_Dino:
	checkitem ITEM_FOSSILIZED_DINO, 1
	compare VAR_RESULT, FALSE
	goto_if_eq RustboroCity_DevonCorp_2F_EventScript_NoFossil
	msgbox RustboroCity_DevonCorp_2F_Text_AreYouSureTheyMatch, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq RustboroCity_DevonCorp_2F_EventScript_MissingHalfFish
	removeitem ITEM_FOSSILIZED_FISH, 1
	removeitem ITEM_FOSSILIZED_DINO, 1
	setvar VAR_WHICH_FOSSIL_REVIVED, 15
	bufferitemname 1, ITEM_FOSSILIZED_DINO
	goto RustboroCity_DevonCorp_2F_EventScript_GiveTheTwoFossil
	end

RustboroCity_DevonCorp_2F_EventScript_MissingHalfDrake:
	msgbox RustboroCity_DevonCorp_2F_Text_MissingHalf, MSGBOX_DEFAULT
	setvar VAR_0x8004, SCROLL_MULTI_FOSSIL_REGENERATOR_DEVICE_DRAKE_DINO
	special ShowFrontierExchangeCornerItemIconWindow
	special ShowScrollableMultichoice
	waitstate
	special CloseFrontierExchangeCornerItemIconWindow
	switch VAR_RESULT
	case 0, RustboroCity_DevonCorp_2F_EventScript_Drake_Bird
	case 1, RustboroCity_DevonCorp_2F_EventScript_Drake_Fish
	case MULTI_B_PRESSED, RustboroCity_DevonCorp_2F_EventScript_CancelPokemonSelect
	goto RustboroCity_DevonCorp_2F_EventScript_CancelPokemonSelect
	end

RustboroCity_DevonCorp_2F_EventScript_Drake_Bird:
	checkitem ITEM_FOSSILIZED_BIRD, 1
	compare VAR_RESULT, FALSE
	goto_if_eq RustboroCity_DevonCorp_2F_EventScript_NoFossil
	msgbox RustboroCity_DevonCorp_2F_Text_AreYouSureTheyMatch, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq RustboroCity_DevonCorp_2F_EventScript_MissingHalfDrake
	removeitem ITEM_FOSSILIZED_DRAKE, 1
	removeitem ITEM_FOSSILIZED_BIRD, 1
	setvar VAR_WHICH_FOSSIL_REVIVED, 12
	bufferitemname 1, ITEM_FOSSILIZED_BIRD
	goto RustboroCity_DevonCorp_2F_EventScript_GiveTheTwoFossil
	end

RustboroCity_DevonCorp_2F_EventScript_Drake_Fish:
	checkitem ITEM_FOSSILIZED_FISH, 1
	compare VAR_RESULT, FALSE
	goto_if_eq RustboroCity_DevonCorp_2F_EventScript_NoFossil
	msgbox RustboroCity_DevonCorp_2F_Text_AreYouSureTheyMatch, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq RustboroCity_DevonCorp_2F_EventScript_MissingHalfDrake
	removeitem ITEM_FOSSILIZED_DRAKE, 1
	removeitem ITEM_FOSSILIZED_FISH, 1
	setvar VAR_WHICH_FOSSIL_REVIVED, 14
	bufferitemname 1, ITEM_FOSSILIZED_FISH
	goto RustboroCity_DevonCorp_2F_EventScript_GiveTheTwoFossil
	end

RustboroCity_DevonCorp_2F_EventScript_MissingHalfDino:
	msgbox RustboroCity_DevonCorp_2F_Text_MissingHalf, MSGBOX_DEFAULT
	setvar VAR_0x8004, SCROLL_MULTI_FOSSIL_REGENERATOR_DEVICE_DRAKE_DINO
	special ShowFrontierExchangeCornerItemIconWindow
	special ShowScrollableMultichoice
	waitstate
	special CloseFrontierExchangeCornerItemIconWindow
	switch VAR_RESULT
	case 0, RustboroCity_DevonCorp_2F_EventScript_Dino_Bird
	case 1, RustboroCity_DevonCorp_2F_EventScript_Dino_Fish
	case MULTI_B_PRESSED, RustboroCity_DevonCorp_2F_EventScript_CancelPokemonSelect
	goto RustboroCity_DevonCorp_2F_EventScript_CancelPokemonSelect
	end

RustboroCity_DevonCorp_2F_EventScript_Dino_Bird:
	checkitem ITEM_FOSSILIZED_BIRD, 1
	compare VAR_RESULT, FALSE
	goto_if_eq RustboroCity_DevonCorp_2F_EventScript_NoFossil
	msgbox RustboroCity_DevonCorp_2F_Text_AreYouSureTheyMatch, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq RustboroCity_DevonCorp_2F_EventScript_MissingHalfDino
	removeitem ITEM_FOSSILIZED_DINO, 1
	removeitem ITEM_FOSSILIZED_BIRD, 1
	setvar VAR_WHICH_FOSSIL_REVIVED, 13
	bufferitemname 1, ITEM_FOSSILIZED_BIRD
	goto RustboroCity_DevonCorp_2F_EventScript_GiveTheTwoFossil
	end

RustboroCity_DevonCorp_2F_EventScript_Dino_Fish:
	checkitem ITEM_FOSSILIZED_FISH, 1
	compare VAR_RESULT, FALSE
	goto_if_eq RustboroCity_DevonCorp_2F_EventScript_NoFossil
	msgbox RustboroCity_DevonCorp_2F_Text_AreYouSureTheyMatch, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq RustboroCity_DevonCorp_2F_EventScript_MissingHalfDino
	removeitem ITEM_FOSSILIZED_DINO, 1
	removeitem ITEM_FOSSILIZED_FISH, 1
	setvar VAR_WHICH_FOSSIL_REVIVED, 15
	bufferitemname 1, ITEM_FOSSILIZED_FISH
	goto RustboroCity_DevonCorp_2F_EventScript_GiveTheTwoFossil
	end

RustboroCity_DevonCorp_2F_EventScript_GiveTheFossil:
	playse SE_SHOP
	setvar VAR_FOSSIL_RESURRECTION_STATE, 1
	setflag FLAG_DAILY_FOSSIL_REVIVE
	msgbox RustboroCity_DevonCorp_2F_Text_HereYouGo, MSGBOX_DEFAULT
	release
	end

RustboroCity_DevonCorp_2F_EventScript_GiveTheTwoFossil:
	playse SE_SHOP
	setvar VAR_FOSSIL_RESURRECTION_STATE, 1
	setflag FLAG_DAILY_FOSSIL_REVIVE
	msgbox RustboroCity_DevonCorp_2F_Text_HereYouGoTwo, MSGBOX_DEFAULT
	release
	end

RustboroCity_DevonCorp_2F_EventScript_CancelPokemonSelect:
	msgbox RustboroCity_DevonCorp_2F_Text_Cancel, MSGBOX_DEFAULT
	release
	end

RustboroCity_DevonCorp_2F_EventScript_NoFossil:
	msgbox RustboroCity_DevonCorp_2F_Text_NoFossil, MSGBOX_DEFAULT
	release
	end

RustboroCity_DevonCorp_2F_EventScript_FossilPokemonIsReady:
	compare VAR_WHICH_FOSSIL_REVIVED, 1
	goto_if_eq RustboroCity_DevonCorp_2F_EventScript_OmanyteReady
	compare VAR_WHICH_FOSSIL_REVIVED, 2
	goto_if_eq RustboroCity_DevonCorp_2F_EventScript_KabutoReady
	compare VAR_WHICH_FOSSIL_REVIVED, 3
	goto_if_eq RustboroCity_DevonCorp_2F_EventScript_AerodactylReady
	compare VAR_WHICH_FOSSIL_REVIVED, 4
	goto_if_eq RustboroCity_DevonCorp_2F_EventScript_LileepReady2
	compare VAR_WHICH_FOSSIL_REVIVED, 5
	goto_if_eq RustboroCity_DevonCorp_2F_EventScript_AnorithReady2
	compare VAR_WHICH_FOSSIL_REVIVED, 6
	goto_if_eq RustboroCity_DevonCorp_2F_EventScript_CranidosReady
	compare VAR_WHICH_FOSSIL_REVIVED, 7
	goto_if_eq RustboroCity_DevonCorp_2F_EventScript_ShieldonReady
	compare VAR_WHICH_FOSSIL_REVIVED, 8
	goto_if_eq RustboroCity_DevonCorp_2F_EventScript_TirtougaReady
	compare VAR_WHICH_FOSSIL_REVIVED, 9
	goto_if_eq RustboroCity_DevonCorp_2F_EventScript_ArchenReady
	compare VAR_WHICH_FOSSIL_REVIVED, 10
	goto_if_eq RustboroCity_DevonCorp_2F_EventScript_TyruntReady
	compare VAR_WHICH_FOSSIL_REVIVED, 11
	goto_if_eq RustboroCity_DevonCorp_2F_EventScript_AmauraReady
	compare VAR_WHICH_FOSSIL_REVIVED, 12
	goto_if_eq RustboroCity_DevonCorp_2F_EventScript_DracozoltReady
	compare VAR_WHICH_FOSSIL_REVIVED, 13
	goto_if_eq RustboroCity_DevonCorp_2F_EventScript_ArctozoltReady
	compare VAR_WHICH_FOSSIL_REVIVED, 14
	goto_if_eq RustboroCity_DevonCorp_2F_EventScript_DracovishReady
	compare VAR_WHICH_FOSSIL_REVIVED, 15
	goto_if_eq RustboroCity_DevonCorp_2F_EventScript_ArctovishReady
	end

RustboroCity_DevonCorp_2F_EventScript_OmanyteReady:
	setvar VAR_TEMP_1, SPECIES_OMANYTE
	bufferspeciesname 0, SPECIES_OMANYTE
	msgbox RustboroCity_DevonCorp_2F_Text_FossilizedMonBroughtBackToLife, MSGBOX_DEFAULT
	goto RustboroCity_DevonCorp_2F_EventScript_ReceiveFossil
	end

RustboroCity_DevonCorp_2F_EventScript_KabutoReady:
	setvar VAR_TEMP_1, SPECIES_KABUTO
	bufferspeciesname 0, SPECIES_KABUTO
	msgbox RustboroCity_DevonCorp_2F_Text_FossilizedMonBroughtBackToLife, MSGBOX_DEFAULT
	goto RustboroCity_DevonCorp_2F_EventScript_ReceiveFossil
	end

RustboroCity_DevonCorp_2F_EventScript_AerodactylReady:
	setvar VAR_TEMP_1, SPECIES_AERODACTYL
	bufferspeciesname 0, SPECIES_AERODACTYL
	msgbox RustboroCity_DevonCorp_2F_Text_FossilizedMonBroughtBackToLife, MSGBOX_DEFAULT
	goto RustboroCity_DevonCorp_2F_EventScript_ReceiveFossil
	end

RustboroCity_DevonCorp_2F_EventScript_LileepReady2:
	setvar VAR_TEMP_1, SPECIES_LILEEP
	bufferspeciesname 0, SPECIES_LILEEP
	msgbox RustboroCity_DevonCorp_2F_Text_FossilizedMonBroughtBackToLife, MSGBOX_DEFAULT
	goto RustboroCity_DevonCorp_2F_EventScript_ReceiveFossil
	end

RustboroCity_DevonCorp_2F_EventScript_AnorithReady2:
	setvar VAR_TEMP_1, SPECIES_ANORITH
	bufferspeciesname 0, SPECIES_ANORITH
	msgbox RustboroCity_DevonCorp_2F_Text_FossilizedMonBroughtBackToLife, MSGBOX_DEFAULT
	goto RustboroCity_DevonCorp_2F_EventScript_ReceiveFossil
	end

RustboroCity_DevonCorp_2F_EventScript_CranidosReady:
	setvar VAR_TEMP_1, SPECIES_CRANIDOS
	bufferspeciesname 0, SPECIES_CRANIDOS
	msgbox RustboroCity_DevonCorp_2F_Text_FossilizedMonBroughtBackToLife, MSGBOX_DEFAULT
	goto RustboroCity_DevonCorp_2F_EventScript_ReceiveFossil
	end

RustboroCity_DevonCorp_2F_EventScript_ShieldonReady:
	setvar VAR_TEMP_1, SPECIES_SHIELDON
	bufferspeciesname 0, SPECIES_SHIELDON
	msgbox RustboroCity_DevonCorp_2F_Text_FossilizedMonBroughtBackToLife, MSGBOX_DEFAULT
	goto RustboroCity_DevonCorp_2F_EventScript_ReceiveFossil
	end

RustboroCity_DevonCorp_2F_EventScript_TirtougaReady:
	setvar VAR_TEMP_1, SPECIES_TIRTOUGA
	bufferspeciesname 0, SPECIES_TIRTOUGA
	msgbox RustboroCity_DevonCorp_2F_Text_FossilizedMonBroughtBackToLife, MSGBOX_DEFAULT
	goto RustboroCity_DevonCorp_2F_EventScript_ReceiveFossil
	end

RustboroCity_DevonCorp_2F_EventScript_ArchenReady:
	setvar VAR_TEMP_1, SPECIES_ARCHEN
	bufferspeciesname 0, SPECIES_ARCHEN
	msgbox RustboroCity_DevonCorp_2F_Text_FossilizedMonBroughtBackToLife, MSGBOX_DEFAULT
	goto RustboroCity_DevonCorp_2F_EventScript_ReceiveFossil
	end

RustboroCity_DevonCorp_2F_EventScript_TyruntReady:
	setvar VAR_TEMP_1, SPECIES_TYRUNT
	bufferspeciesname 0, SPECIES_TYRUNT
	msgbox RustboroCity_DevonCorp_2F_Text_FossilizedMonBroughtBackToLife, MSGBOX_DEFAULT
	goto RustboroCity_DevonCorp_2F_EventScript_ReceiveFossil
	end

RustboroCity_DevonCorp_2F_EventScript_AmauraReady:
	setvar VAR_TEMP_1, SPECIES_AMAURA
	bufferspeciesname 0, SPECIES_AMAURA
	msgbox RustboroCity_DevonCorp_2F_Text_FossilizedMonBroughtBackToLife, MSGBOX_DEFAULT
	goto RustboroCity_DevonCorp_2F_EventScript_ReceiveFossil
	end

RustboroCity_DevonCorp_2F_EventScript_DracozoltReady:
	setvar VAR_TEMP_1, SPECIES_DRACOZOLT
	bufferspeciesname 0, SPECIES_DRACOZOLT
	msgbox RustboroCity_DevonCorp_2F_Text_FossilizedMonBroughtBackToLife, MSGBOX_DEFAULT
	goto RustboroCity_DevonCorp_2F_EventScript_ReceiveFossil
	end

RustboroCity_DevonCorp_2F_EventScript_ArctozoltReady:
	setvar VAR_TEMP_1, SPECIES_ARCTOZOLT
	bufferspeciesname 0, SPECIES_ARCTOZOLT
	msgbox RustboroCity_DevonCorp_2F_Text_FossilizedMonBroughtBackToLife, MSGBOX_DEFAULT
	goto RustboroCity_DevonCorp_2F_EventScript_ReceiveFossil
	end

RustboroCity_DevonCorp_2F_EventScript_DracovishReady:
	setvar VAR_TEMP_1, SPECIES_DRACOVISH
	bufferspeciesname 0, SPECIES_DRACOVISH
	msgbox RustboroCity_DevonCorp_2F_Text_FossilizedMonBroughtBackToLife, MSGBOX_DEFAULT
	goto RustboroCity_DevonCorp_2F_EventScript_ReceiveFossil
	end

RustboroCity_DevonCorp_2F_EventScript_ArctovishReady:
	setvar VAR_TEMP_1, SPECIES_ARCTOVISH
	bufferspeciesname 0, SPECIES_ARCTOVISH
	msgbox RustboroCity_DevonCorp_2F_Text_FossilizedMonBroughtBackToLife, MSGBOX_DEFAULT
	goto RustboroCity_DevonCorp_2F_EventScript_ReceiveFossil
	end

RustboroCity_DevonCorp_2F_EventScript_ReceiveFossil:
	givemon VAR_TEMP_1, 20
	compare VAR_RESULT, 0
	goto_if_eq RustboroCity_DevonCorp_2F_EventScript_ReceiveFossilParty
	compare VAR_RESULT, 1
	goto_if_eq RustboroCity_DevonCorp_2F_EventScript_ReceiveFossilPC
	goto Common_EventScript_NoMoreRoomForPokemon
	end

RustboroCity_DevonCorp_2F_EventScript_ReceiveFossilParty:
	call RustboroCity_DevonCorp_2F_EventScript_ReceivedFossilFanfare
	specialvar VAR_RESULT, IsNuzlockeNicknamingActive
	compare VAR_RESULT, TRUE
	goto_if_eq RustboroCity_DevonCorp_2F_EventScript_ReceiveFossilParty_Nuzlocke
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq RustboroCity_DevonCorp_2F_EventScript_FinishReceivingLileep
	call Common_EventScript_GetGiftMonPartySlot
	call Common_EventScript_NameReceivedPartyMon
	goto RustboroCity_DevonCorp_2F_EventScript_FinishReceivingLileep
	end

RustboroCity_DevonCorp_2F_EventScript_ReceiveFossilPC:
	call RustboroCity_DevonCorp_2F_EventScript_ReceivedFossilFanfare
	specialvar VAR_RESULT, IsNuzlockeNicknamingActive
	compare VAR_RESULT, TRUE
	goto_if_eq RustboroCity_DevonCorp_2F_EventScript_ReceiveFossilPC_Nuzlocke
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq RustboroCity_DevonCorp_2F_EventScript_TransferFossilToPC
	call Common_EventScript_NameReceivedBoxMon
	goto RustboroCity_DevonCorp_2F_EventScript_TransferFossilToPC
	end

RustboroCity_DevonCorp_2F_EventScript_ReceivedFossilFanfare::
	bufferspeciesname 0, VAR_TEMP_1
	playfanfare MUS_OBTAIN_ITEM
	message RustboroCity_DevonCorp_2F_Text_ReceivedMonFromResearcher
	waitmessage
	waitfanfare
	bufferspeciesname 0, VAR_TEMP_1
	return

RustboroCity_DevonCorp_2F_EventScript_ReceiveFossilParty_Nuzlocke:
	call Common_EventScript_GetGiftMonPartySlot
	call Common_EventScript_NameReceivedPartyMon
	goto RustboroCity_DevonCorp_2F_EventScript_FinishReceivingFossil
	end

RustboroCity_DevonCorp_2F_EventScript_ReceiveFossilPC_Nuzlocke:
	call Common_EventScript_NameReceivedBoxMon
	goto RustboroCity_DevonCorp_2F_EventScript_TransferFossilToPC
	end

RustboroCity_DevonCorp_2F_EventScript_TransferFossilToPC:
	call Common_EventScript_TransferredToPC
	goto RustboroCity_DevonCorp_2F_EventScript_FinishReceivingFossil
	end

RustboroCity_DevonCorp_2F_EventScript_FinishReceivingFossil:
	setvar VAR_FOSSIL_RESURRECTION_STATE, 0
	setflag FLAG_RECEIVED_REVIVED_FOSSIL_MON
	release
	end

RustboroCity_DevonCorp_2F_Text_MissingHalf:
	.string "It is missing half of the Fossil…\n"
	.string "Which is the missing part?$"

RustboroCity_DevonCorp_2F_Text_AreYouSureTheyMatch:
	.string "Are you sure they match?$"

RustboroCity_DevonCorp_2F_Text_NoFossil:
	.string "Seems that you don't have it…\p"
	.string "You can find them in the Desert\n"
	.string "or Oceans, these are the best places\l"
	.string "to find Fossils.$"

RustboroCity_DevonCorp_2F_Text_HereYouGo:
	.string "Excellent!\n"
	.string "It'll take some time.\p"
	.string "{PLAYER} handed the {STR_VAR_1} to\n"
	.string "the Devon Researcher.$"

RustboroCity_DevonCorp_2F_Text_HereYouGoTwo:
	.string "Excellent!\n"
	.string "It'll take some time.\p"
	.string "{PLAYER} handed the {STR_VAR_1} and\n"
	.string "{STR_VAR_2} to the Devon\l"
	.string "Researcher.$"

RustboroCity_DevonCorp_2F_Text_SoYourChoiceIsTheItemX:
	.string "So your choice is\n"
	.string "the {STR_VAR_1}?$"

RustboroCity_DevonCorp_2F_Text_Cancel:
	.string "Oh, is that so? \n"
	.string "You need to find Fossils by exploring\l"
	.string "Hoenn before coming back here.$"

RustboroCity_DevonCorp_2F_Text_DoYouHaveSomeFossil:
	.string "I've been trying to develop a device\n"
	.string "that resurrects Pokémon from Fossils…\p"
	.string "And, it's working!\p"
	.string "So, do you have any Fossil with you?$"

@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

RustboroCity_DevonCorp_2F_EventScript_FossilScientist::
	lock
	faceplayer
	compare VAR_FOSSIL_RESURRECTION_STATE, 2
	goto_if_eq RustboroCity_DevonCorp_2F_EventScript_FossilMonReady
	compare VAR_FOSSIL_RESURRECTION_STATE, 1
	goto_if_eq RustboroCity_DevonCorp_2F_EventScript_StillRegenerating
	msgbox RustboroCity_DevonCorp_2F_Text_DevelopDeviceToResurrectFossils, MSGBOX_DEFAULT
	checkitem ITEM_ROOT_FOSSIL, 1
	compare VAR_RESULT, TRUE
	goto_if_eq RustboroCity_DevonCorp_2F_EventScript_NoticeRootFossil
	checkitem ITEM_CLAW_FOSSIL, 1
	compare VAR_RESULT, TRUE
	goto_if_eq RustboroCity_DevonCorp_2F_EventScript_NoticeClawFossil
	release
	end

@ This whole section has needless duplication and could be condensed considerably
RustboroCity_DevonCorp_2F_EventScript_NoticeRootFossil::
	closemessage
	playse SE_PIN
	applymovement LOCALID_FOSSIL_SCIENTIST, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_FOSSIL_SCIENTIST, Common_Movement_Delay48
	waitmovement 0
	msgbox RustboroCity_DevonCorp_2F_Text_WantToBringFossilBackToLife, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq RustboroCity_DevonCorp_2F_EventScript_DeclineGiveFossil
	checkitem ITEM_CLAW_FOSSIL, 1
	compare VAR_RESULT, TRUE
	goto_if_eq RustboroCity_DevonCorp_2F_EventScript_ChooseFossil
	goto RustboroCity_DevonCorp_2F_EventScript_GiveRootFossil
	end

RustboroCity_DevonCorp_2F_EventScript_GiveRootFossil::
	bufferitemname 0, ITEM_ROOT_FOSSIL
	msgbox RustboroCity_DevonCorp_2F_Text_HandedFossilToResearcher, MSGBOX_DEFAULT
	removeitem ITEM_ROOT_FOSSIL
	setvar VAR_FOSSIL_RESURRECTION_STATE, 1
	setvar VAR_WHICH_FOSSIL_REVIVED, 1
	release
	end

RustboroCity_DevonCorp_2F_EventScript_NoticeClawFossil::
	closemessage
	playse SE_PIN
	applymovement LOCALID_FOSSIL_SCIENTIST, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_FOSSIL_SCIENTIST, Common_Movement_Delay48
	waitmovement 0
	msgbox RustboroCity_DevonCorp_2F_Text_WantToBringFossilBackToLife, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq RustboroCity_DevonCorp_2F_EventScript_DeclineGiveFossil
	checkitem ITEM_ROOT_FOSSIL, 1
	compare VAR_RESULT, TRUE
	goto_if_eq RustboroCity_DevonCorp_2F_EventScript_ChooseFossil
	goto RustboroCity_DevonCorp_2F_EventScript_GiveClawFossil
	end

RustboroCity_DevonCorp_2F_EventScript_GiveClawFossil::
	bufferitemname 0, ITEM_CLAW_FOSSIL
	msgbox RustboroCity_DevonCorp_2F_Text_HandedFossilToResearcher, MSGBOX_DEFAULT
	removeitem ITEM_CLAW_FOSSIL
	setvar VAR_FOSSIL_RESURRECTION_STATE, 1
	setvar VAR_WHICH_FOSSIL_REVIVED, 2
	release
	end

RustboroCity_DevonCorp_2F_EventScript_DeclineGiveFossil::
	msgbox RustboroCity_DevonCorp_2F_Text_OhIsThatSo, MSGBOX_DEFAULT
	release
	end

RustboroCity_DevonCorp_2F_EventScript_StillRegenerating::
	msgbox RustboroCity_DevonCorp_2F_Text_FossilRegeneratorTakesTime, MSGBOX_DEFAULT
	release
	end

RustboroCity_DevonCorp_2F_EventScript_FossilMonReady::
	compare VAR_WHICH_FOSSIL_REVIVED, 1
	goto_if_eq RustboroCity_DevonCorp_2F_EventScript_LileepReady
	compare VAR_WHICH_FOSSIL_REVIVED, 2
	goto_if_eq RustboroCity_DevonCorp_2F_EventScript_AnorithReady
	end

RustboroCity_DevonCorp_2F_EventScript_LileepReady::
	bufferspeciesname 1, SPECIES_LILEEP
	msgbox RustboroCity_DevonCorp_2F_Text_FossilizedMonBroughtBackToLife, MSGBOX_DEFAULT
	goto RustboroCity_DevonCorp_2F_EventScript_ReceiveLileep
	end

RustboroCity_DevonCorp_2F_EventScript_AnorithReady::
	bufferspeciesname 1, SPECIES_ANORITH
	msgbox RustboroCity_DevonCorp_2F_Text_FossilizedMonBroughtBackToLife, MSGBOX_DEFAULT
	goto RustboroCity_DevonCorp_2F_EventScript_ReceiveAnorith
	end

RustboroCity_DevonCorp_2F_EventScript_ReceiveLileep::
	setvar VAR_TEMP_1, SPECIES_LILEEP
	givemon SPECIES_LILEEP, 20
	compare VAR_RESULT, 0
	goto_if_eq RustboroCity_DevonCorp_2F_EventScript_ReceiveLileepParty
	compare VAR_RESULT, 1
	goto_if_eq RustboroCity_DevonCorp_2F_EventScript_ReceiveLileepPC
	goto Common_EventScript_NoMoreRoomForPokemon
	end

RustboroCity_DevonCorp_2F_EventScript_ReceiveLileepParty::
	call RustboroCity_DevonCorp_2F_EventScript_ReceivedLileepFanfare
	specialvar VAR_RESULT, IsNuzlockeNicknamingActive
	compare VAR_RESULT, TRUE
	goto_if_eq RustboroCity_DevonCorp_2F_EventScript_ReceiveLileepParty_Nuzlocke
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq RustboroCity_DevonCorp_2F_EventScript_FinishReceivingLileep
	call Common_EventScript_GetGiftMonPartySlot
	call Common_EventScript_NameReceivedPartyMon
	goto RustboroCity_DevonCorp_2F_EventScript_FinishReceivingLileep
	end

RustboroCity_DevonCorp_2F_EventScript_ReceiveLileepParty_Nuzlocke::
	call Common_EventScript_GetGiftMonPartySlot
	call Common_EventScript_NameReceivedPartyMon
	goto RustboroCity_DevonCorp_2F_EventScript_FinishReceivingLileep
	end

RustboroCity_DevonCorp_2F_EventScript_ReceiveLileepPC::
	call RustboroCity_DevonCorp_2F_EventScript_ReceivedLileepFanfare
	specialvar VAR_RESULT, IsNuzlockeNicknamingActive
	compare VAR_RESULT, TRUE
	goto_if_eq RustboroCity_DevonCorp_2F_EventScript_ReceiveLileepPC_Nuzlocke
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq RustboroCity_DevonCorp_2F_EventScript_TransferLileepToPC
	call Common_EventScript_NameReceivedBoxMon
	goto RustboroCity_DevonCorp_2F_EventScript_TransferLileepToPC
	end

RustboroCity_DevonCorp_2F_EventScript_ReceiveLileepPC_Nuzlocke::
	call Common_EventScript_NameReceivedBoxMon
	goto RustboroCity_DevonCorp_2F_EventScript_TransferLileepToPC
	end

RustboroCity_DevonCorp_2F_EventScript_TransferLileepToPC::
	call Common_EventScript_TransferredToPC
	goto RustboroCity_DevonCorp_2F_EventScript_FinishReceivingLileep
	end

RustboroCity_DevonCorp_2F_EventScript_ReceivedLileepFanfare::
	bufferspeciesname 1, SPECIES_LILEEP
	playfanfare MUS_OBTAIN_ITEM
	message RustboroCity_DevonCorp_2F_Text_ReceivedMonFromResearcher
	waitmessage
	waitfanfare
	bufferspeciesname 0, SPECIES_LILEEP
	return

RustboroCity_DevonCorp_2F_EventScript_FinishReceivingLileep::
	setvar VAR_FOSSIL_RESURRECTION_STATE, 0
	setflag FLAG_RECEIVED_REVIVED_FOSSIL_MON
	release
	end

RustboroCity_DevonCorp_2F_EventScript_ReceiveAnorith::
	setvar VAR_TEMP_1, SPECIES_ANORITH
	givemon SPECIES_ANORITH, 20
	compare VAR_RESULT, 0
	goto_if_eq RustboroCity_DevonCorp_2F_EventScript_ReceiveAnorithParty
	compare VAR_RESULT, 1
	goto_if_eq RustboroCity_DevonCorp_2F_EventScript_ReceiveAnorithPC
	goto Common_EventScript_NoMoreRoomForPokemon
	end

RustboroCity_DevonCorp_2F_EventScript_ReceiveAnorithParty::
	call RustboroCity_DevonCorp_2F_EventScript_ReceivedAnorithFanfare
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq RustboroCity_DevonCorp_2F_EventScript_FinishReceivingAnorith
	call Common_EventScript_GetGiftMonPartySlot
	call Common_EventScript_NameReceivedPartyMon
	goto RustboroCity_DevonCorp_2F_EventScript_FinishReceivingAnorith
	end

RustboroCity_DevonCorp_2F_EventScript_ReceiveAnorithPC::
	call RustboroCity_DevonCorp_2F_EventScript_ReceivedAnorithFanfare
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq RustboroCity_DevonCorp_2F_EventScript_TransferAnorithToPC
	call Common_EventScript_NameReceivedBoxMon
	goto RustboroCity_DevonCorp_2F_EventScript_TransferAnorithToPC
	end

RustboroCity_DevonCorp_2F_EventScript_TransferAnorithToPC::
	call Common_EventScript_TransferredToPC
	goto RustboroCity_DevonCorp_2F_EventScript_FinishReceivingAnorith
	end

RustboroCity_DevonCorp_2F_EventScript_ReceivedAnorithFanfare::
	bufferspeciesname 1, SPECIES_ANORITH
	playfanfare MUS_OBTAIN_ITEM
	message RustboroCity_DevonCorp_2F_Text_ReceivedMonFromResearcher
	waitmessage
	waitfanfare
	bufferspeciesname 0, SPECIES_ANORITH
	return

RustboroCity_DevonCorp_2F_EventScript_FinishReceivingAnorith::
	setvar VAR_FOSSIL_RESURRECTION_STATE, 0
	setflag FLAG_RECEIVED_REVIVED_FOSSIL_MON
	release
	end

RustboroCity_DevonCorp_2F_EventScript_ChooseFossil::
	message RustboroCity_DevonCorp_2F_Text_TwoFossilsPickOne
	waitmessage
	multichoice 17, 6, MULTI_FOSSIL, FALSE
	switch VAR_RESULT
	case 0, RustboroCity_DevonCorp_2F_EventScript_ChooseClawFossil
	case 1, RustboroCity_DevonCorp_2F_EventScript_ChooseRootFossil
	case 2, RustboroCity_DevonCorp_2F_EventScript_CancelFossilSelect
	case MULTI_B_PRESSED, RustboroCity_DevonCorp_2F_EventScript_CancelFossilSelect
	end

RustboroCity_DevonCorp_2F_EventScript_ChooseClawFossil::
	goto RustboroCity_DevonCorp_2F_EventScript_GiveClawFossil
	end

RustboroCity_DevonCorp_2F_EventScript_ChooseRootFossil::
	goto RustboroCity_DevonCorp_2F_EventScript_GiveRootFossil
	end

RustboroCity_DevonCorp_2F_EventScript_CancelFossilSelect::
	release
	end

RustboroCity_DevonCorp_2F_EventScript_MatchCallScientist::
	lock
	faceplayer
	compare VAR_FOSSIL_RESURRECTION_STATE, 1
	call_if_eq RustboroCity_DevonCorp_2F_EventScript_SetFossilReady
	compare VAR_RUSTBORO_CITY_STATE, 6
	goto_if_ge RustboroCity_DevonCorp_2F_EventScript_WorkOnNext
	msgbox RustboroCity_DevonCorp_2F_Text_DevelopNewPokenavFeature, MSGBOX_DEFAULT
	release
	end

RustboroCity_DevonCorp_2F_EventScript_WorkOnNext::
	msgbox RustboroCity_DevonCorp_2F_Text_WhatToWorkOnNext, MSGBOX_DEFAULT
	release
	end

RustboroCity_DevonCorp_2F_Text_DeviceForTalkingToPokemon:
	.string "We're developing a device for talking\n"
	.string "with Pokémon.\p"
	.string "But we haven't had much success…$"

RustboroCity_DevonCorp_2F_Text_DevelopingNewBalls:
	.string "I'm developing new kinds of\n"
	.string "Poké Balls…\p"
	.string "But I haven't made much headway…$"

RustboroCity_DevonCorp_2F_Text_WeFinallyMadeNewBalls:
	.string "We finally made new kinds of\n"
	.string "Poké Balls!\p"
	.string "The REPEAT Ball makes it easier to\n"
	.string "catch Pokémon you've caught before.\p"
	.string "The TIMER Ball gets better at catching\n"
	.string "Pokémon the longer a battle runs.\p"
	.string "Both are proudly developed by\n"
	.string "the Devon Corporation.\p"
	.string "Please give them a try!$"

RustboroCity_DevonCorp_2F_Text_IMadePokenav:
	.string "I made the Pokénav!\p"
	.string "As an engineer, I feel blessed to have\n"
	.string "made something so great!$"

RustboroCity_DevonCorp_2F_Text_WowThatsAPokenav:
	.string "Oh, wow!\n"
	.string "That's a Pokénav!\p"
	.string "It came about as a result of our\n"
	.string "President's desire to learn about\l"
	.string "the feelings of Pokémon.\p"
	.string "Would you like me to describe its\n"
	.string "features in detail?\p"
	.string "No, no. I think you'll find out just by\n"
	.string "trying the Pokénav out.$"

RustboroCity_DevonCorp_2F_Text_DeviceToVisualizePokemonDreams:
	.string "I'm trying to develop a device that\n"
	.string "visually reproduces the dreams of\l"
	.string "Pokémon…\p"
	.string "But it's not going well.$"

RustboroCity_DevonCorp_2F_Text_DevelopDeviceToResurrectFossils:
	.string "I've been trying to develop a device\n"
	.string "that resurrects Pokémon from Fossils…\p"
	.string "And, it's working!$"

RustboroCity_DevonCorp_2F_Text_WantToBringFossilBackToLife:
	.string "Wait! That thing you have there…\n"
	.string "Is that a Pokémon Fossil?\p"
	.string "Would you like to bring that Pokémon\n"
	.string "back to life?\p"
	.string "I can with my newly developed\n"
	.string "Fossil Regenerator.$"

RustboroCity_DevonCorp_2F_Text_OhIsThatSo:
	.string "Oh, is that so?\p"
	.string "Devon's technological expertise\n"
	.string "is outstanding, I tell you.$"

RustboroCity_DevonCorp_2F_Text_TwoFossilsPickOne:
	.string "Oh, now that's a surprise!\n"
	.string "You have not one, but two, Fossils?\p"
	.string "Unfortunately, my machine can only\n"
	.string "regenerate one Pokémon at a time.\p"
	.string "Would you like to pick one of your\n"
	.string "Fossils for regeneration?$"

RustboroCity_DevonCorp_2F_Text_HandedFossilToResearcher:
	.string "Excellent!\n"
	.string "Let's do this right away.\p"
	.string "{PLAYER} handed the {STR_VAR_1} to\n"
	.string "the Devon Researcher.$"

RustboroCity_DevonCorp_2F_Text_FossilRegeneratorTakesTime:
	.string "The Fossil Regenerator, which I made,\n"
	.string "is incredible.\p"
	.string "But it has one drawback--it takes\n"
	.string "a long time to work.\p"
	.string "So, uh… How about you go for a stroll\n"
	.string "and look around for a while?$"

RustboroCity_DevonCorp_2F_Text_FossilizedMonBroughtBackToLife:
	.string "Thanks for waiting!\p"
	.string "Your Fossilized Pokémon has been\n"
	.string "brought back to life!\p"
	.string "The Fossil was an ancient Pokémon.\n"
	.string "{STR_VAR_1}, it was!$"

RustboroCity_DevonCorp_2F_Text_ReceivedMonFromResearcher:
	.string "{PLAYER} received {STR_VAR_1} from\n"
	.string "the Devon Researcher.$"

@ Unused
RustboroCity_DevonCorp_2F_Text_TooManyPokemon:
	.string "Uh-oh, you've got too many Pokémon.\n"
	.string "You have no room for this one.$"

RustboroCity_DevonCorp_2F_Text_DevelopNewPokenavFeature:
	.string "I'm trying to develop a new feature\n"
	.string "for the Pokénav…\p"
	.string "But it's not going well.$"

RustboroCity_DevonCorp_2F_Text_WhatToWorkOnNext:
	.string "Well, now what shall I work on\n"
	.string "developing next?\p"
	.string "Our company allows us to make our\n"
	.string "inspirations into reality.\p"
	.string "One couldn't ask for a better\n"
	.string "environment as an engineer.$"

