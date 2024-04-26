@ Steal Pokémon from last Trainer
EventScript_RocketEdition_TryStealPokemon_Releaseall::
    setflag FLAG_ROCKET_EDITION_FUNC
    goto EventScript_RocketEdition_TryStealPokemon

EventScript_RocketEdition_TryStealPokemon_Return::
    clearflag FLAG_ROCKET_EDITION_FUNC
EventScript_RocketEdition_TryStealPokemon::
    callfunc IsRocketEditionOn
    switch VAR_RESULT
    case 0, EventScript_RocketEdition_End
    case 2, EventScript_RocketEdition_MapBlockedReturn
    case 3, EventScript_RocketEdition_OneTypeBlockedReturn
    case 4, EventScript_RocketEdition_SpeciesReturn
    case 5, EventScript_RocketEdition_EvolineReturn
    case 6, EventScript_RocketEdition_NoMonToStealReturn
    msgbox Text_RocketEdition_WantToSteal, MSGBOX_YESNO
	closemessage
    compare VAR_RESULT, YES
    goto_if_eq EventScript_RocketEdition_WhichPokemon
EventScript_RocketEdition_End::
	goto_if_set FLAG_ROCKET_EDITION_FUNC, EventScript_RocketEdition_End2
    closemessage
    return

EventScript_RocketEdition_End2::
    releaseall
    end

EventScript_RocketEdition_MapBlockedReturn::
    msgbox Text_RocketEdition_MapBlocked, MSGBOX_DEFAULT
    goto EventScript_RocketEdition_End
EventScript_RocketEdition_OneTypeBlockedReturn::
    msgbox Text_RocketEdition_OneTypeBlocked, MSGBOX_DEFAULT
    goto EventScript_RocketEdition_End
EventScript_RocketEdition_SpeciesReturn::
    msgbox Text_RocketEdition_SpeciesBlocked, MSGBOX_DEFAULT
    goto EventScript_RocketEdition_End
EventScript_RocketEdition_EvolineReturn::
    msgbox Text_RocketEdition_EvolineBlocked, MSGBOX_DEFAULT
    goto EventScript_RocketEdition_End
EventScript_RocketEdition_NoMonToStealReturn::
    msgbox Text_RocketEdition_NoMonToSteal, MSGBOX_DEFAULT
    goto EventScript_RocketEdition_End

EventScript_RocketEdition_WhichPokemon::
    specialvar VAR_RESULT, CalculateEnemyPartyCount
    compare VAR_RESULT, 1
    goto_if_eq EventScript_RocketEdition_StealFirstPokemon
    msgbox Text_RocketEdition_WhichPokemon, MSGBOX_DEFAULT
    closemessage
    callfunc ScrFunc_BufferTrainerMons  @store partysize in VAR_RESULT & set species name in gStringVars
    compare VAR_RESULT, 1
    goto_if_eq EventScript_RocketEdition_StealFirstPokemon
    compare VAR_RESULT, 2
    goto_if_eq EventScript_RocketEdition_ChooseBetweenTwo
    compare VAR_RESULT, 3
    goto_if_eq EventScript_RocketEdition_ChooseBetweenThree
    compare VAR_RESULT, 4
    goto_if_eq EventScript_RocketEdition_ChooseBetweenFour
    compare VAR_RESULT, 5
    goto_if_eq EventScript_RocketEdition_ChooseBetweenFive
    compare VAR_RESULT, 6
    goto_if_eq EventScript_RocketEdition_ChooseBetweenSix
    end

EventScript_RocketEdition_ChooseBetweenTwo::
    multichoice 0, 0, MULTI_DYNAMIC_MULTICHOICE_2, TRUE, TRUE
    switch VAR_RESULT
    case 0, EventScript_RocketEdition_StealFirstPokemon
    case 1, EventScript_RocketEdition_StealSecondPokemon
    case 2, EventScript_RocketEdition_End
    end

EventScript_RocketEdition_ChooseBetweenThree::
    multichoice 0, 0, MULTI_DYNAMIC_MULTICHOICE_3, TRUE, TRUE
    switch VAR_RESULT
    case 0, EventScript_RocketEdition_StealFirstPokemon
    case 1, EventScript_RocketEdition_StealSecondPokemon
    case 2, EventScript_RocketEdition_StealThirdPokemon
    case 3, EventScript_RocketEdition_End
    end

EventScript_RocketEdition_ChooseBetweenFour::
    multichoice 0, 0, MULTI_DYNAMIC_MULTICHOICE_4, TRUE, TRUE
    switch VAR_RESULT
    case 0, EventScript_RocketEdition_StealFirstPokemon
    case 1, EventScript_RocketEdition_StealSecondPokemon
    case 2, EventScript_RocketEdition_StealThirdPokemon
    case 3, EventScript_RocketEdition_StealFourthPokemon
    case 4, EventScript_RocketEdition_End
    end

EventScript_RocketEdition_ChooseBetweenFive::
    multichoice 0, 0, MULTI_DYNAMIC_MULTICHOICE_5, TRUE, TRUE
    switch VAR_RESULT
    case 0, EventScript_RocketEdition_StealFirstPokemon
    case 1, EventScript_RocketEdition_StealSecondPokemon
    case 2, EventScript_RocketEdition_StealThirdPokemon
    case 3, EventScript_RocketEdition_StealFourthPokemon
    case 4, EventScript_RocketEdition_StealFifthPokemon
    case 5, EventScript_RocketEdition_End
    end

EventScript_RocketEdition_ChooseBetweenSix::
    multichoice 0, 0, MULTI_DYNAMIC_MULTICHOICE_6, TRUE, TRUE
    switch VAR_RESULT
    case 0, EventScript_RocketEdition_StealFirstPokemon
    case 1, EventScript_RocketEdition_StealSecondPokemon
    case 2, EventScript_RocketEdition_StealThirdPokemon
    case 3, EventScript_RocketEdition_StealFourthPokemon
    case 4, EventScript_RocketEdition_StealFifthPokemon
    case 5, EventScript_RocketEdition_StealSixthPokemon
    case 6, EventScript_RocketEdition_End
    end

@ partyId is stored in VAR_RESULT
EventScript_RocketEdition_StealFirstPokemon::
	stealmon 0
    switch VAR_RESULT
    case 0, EventScript_RocketEdition_SendStolenPokemonToParty
    case 1, EventScript_RocketEdition_SendStolenPokemonToPC
    case 2, Common_EventScript_NoMoreRoomForPokemon @"There's no more room for any more\..."
    end
EventScript_RocketEdition_StealSecondPokemon::
	stealmon 1
    switch VAR_RESULT
    case 0, EventScript_RocketEdition_SendStolenPokemonToParty
    case 1, EventScript_RocketEdition_SendStolenPokemonToPC
    case 2, Common_EventScript_NoMoreRoomForPokemon @"There's no more room for any more\..."
    end
EventScript_RocketEdition_StealThirdPokemon::
	stealmon 2
    switch VAR_RESULT
    case 0, EventScript_RocketEdition_SendStolenPokemonToParty
    case 1, EventScript_RocketEdition_SendStolenPokemonToPC
    case 2, Common_EventScript_NoMoreRoomForPokemon @"There's no more room for any more\..."
    end
EventScript_RocketEdition_StealFourthPokemon::
	stealmon 3
    switch VAR_RESULT
    case 0, EventScript_RocketEdition_SendStolenPokemonToParty
    case 1, EventScript_RocketEdition_SendStolenPokemonToPC
    case 2, Common_EventScript_NoMoreRoomForPokemon @"There's no more room for any more\..."
    end
EventScript_RocketEdition_StealFifthPokemon::
	stealmon 4
    switch VAR_RESULT
    case 0, EventScript_RocketEdition_SendStolenPokemonToParty
    case 1, EventScript_RocketEdition_SendStolenPokemonToPC
    case 2, Common_EventScript_NoMoreRoomForPokemon @"There's no more room for any more\..."
    end
EventScript_RocketEdition_StealSixthPokemon::
	stealmon 5
    switch VAR_RESULT
    case 0, EventScript_RocketEdition_SendStolenPokemonToParty
    case 1, EventScript_RocketEdition_SendStolenPokemonToPC
    case 2, Common_EventScript_NoMoreRoomForPokemon @"There's no more room for any more\..."
    end

EventScript_RocketEdition_SendStolenPokemonToParty:
    call EventScript_RocketEdition_Fanfare
    msgbox Text_RocketEdition_Nickname, MSGBOX_YESNO
    compare VAR_RESULT, NO
    goto_if_eq EventScript_RocketEdition_End
    call Common_EventScript_GetGiftMonPartySlot
	call Common_EventScript_NameReceivedPartyMon
    goto EventScript_RocketEdition_End
	end

EventScript_RocketEdition_SendStolenPokemonToPC:
    call EventScript_RocketEdition_Fanfare
    msgbox Text_RocketEdition_Nickname, MSGBOX_YESNO
    compare VAR_RESULT, NO
    goto_if_eq EventScript_RocketEdition_StolenPokemonTransferredToPC
    call Common_EventScript_NameReceivedBoxMon
    goto EventScript_RocketEdition_StolenPokemonTransferredToPC
	end

EventScript_RocketEdition_Fanfare:
	playfanfare MUS_OBTAIN_ITEM
    @bufferspeciesname 0, VAR_TEMP_1
    @buffertrainerclassname 1, VAR_TEMP_2
    @buffertrainername 2, VAR_TEMP_2
	message Text_RocketEdition_StolenFrom
	waitmessage
	waitfanfare
	return

EventScript_RocketEdition_StolenPokemonTransferredToPC:
    call Common_EventScript_TransferredToPC
    goto EventScript_RocketEdition_End
    end

Text_RocketEdition_WantToSteal:
    .string "Steal a Pokémon from this Trainer?$"

Text_RocketEdition_StolenFrom:
    .string "{PLAYER} stole {STR_VAR_1} from\n"
    .string "{STR_VAR_2} {STR_VAR_3}!$"

Text_RocketEdition_Nickname:
    .string "Would you like to give a nickname\n"
    .string "to the stolen {STR_VAR_1}?$"

Text_RocketEdition_WhichPokemon:
    .string "Steal which Pokémon?$"

Text_RocketEdition_MapBlocked:
    .string "Nuzlocke rule: You have already used\nyour encounter for this area!$"
Text_RocketEdition_OneTypeBlocked:
    .string "One Type Challenge rule: You can only\nsteal {STR_VAR_1}-type Pokémon!!$"
Text_RocketEdition_SpeciesBlocked:
    .string "Nuzlocke rule: You have already caught\n or stolen this Pokémon!!$"
Text_RocketEdition_EvolineBlocked:
    .string "Nuzlocke rule: You have already caught\n or stolen a Pokémon in this\nevolution line!$"
Text_RocketEdition_NoMonToSteal:
    .string "There were no Pokémon you could\nsteal by the Challenge rules!$"
