VerdanturfTown_PokemonCenter_2F_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, CableClub_OnFrame
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, CableClub_OnWarp
	map_script MAP_SCRIPT_ON_LOAD, CableClub_OnLoad
	map_script MAP_SCRIPT_ON_TRANSITION, CableClub_OnTransition
	.byte 0

@ The below 3 are unused and leftover from RS
VerdanturfTown_PokemonCenter_2F_EventScript_Colosseum::
	call CableClub_EventScript_Colosseum
	end

VerdanturfTown_PokemonCenter_2F_EventScript_TradeCenter::
	call CableClub_EventScript_TradeCenter
	end

VerdanturfTown_PokemonCenter_2F_EventScript_RecordCorner::
	call CableClub_EventScript_RecordCorner
	end

VerdanturfTown_CableClub_EventScript_Girl::
	lock
	faceplayer
	goto_if_set FLAG_VERDANTURF_TRADE_MEOWTH, VerdanturfTown_CableClub_EventScript_TradeCompleted
	setvar VAR_0x8008, INGAME_TRADE_ALOLAN_MEOWTH
	copyvar VAR_0x8004, VAR_0x8008
	specialvar VAR_RESULT, GetInGameTradeSpeciesInfo
	copyvar VAR_0x8009, VAR_RESULT
	msgbox VerdanturfTown_CableClub_Text_IllTradeIfYouWant, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq VerdanturfTown_CableClub_EventScript_DeclineTrade
	special ChoosePartyMon
	waitstate
	copyvar VAR_0x800A, VAR_0x8004
	compare VAR_0x8004, 255
	goto_if_eq VerdanturfTown_CableClub_EventScript_DeclineTrade
	copyvar VAR_0x8005, VAR_0x800A
	specialvar VAR_RESULT, GetTradeSpecies
	copyvar VAR_0x800B, VAR_RESULT
	compare VAR_RESULT, VAR_0x8009
	goto_if_ne VerdanturfTown_CableClub_EventScript_NotRequestedMon
	copyvar VAR_0x8004, VAR_0x8008
	copyvar VAR_0x8005, VAR_0x800A
	removeobject 7
	special CreateInGameTradePokemon
	special DoInGameTradeScene
	waitstate
	msgbox VerdanturfTown_CableClub_Text_PleaseBeGoodToMyPokemon, MSGBOX_DEFAULT
	setflag FLAG_VERDANTURF_TRADE_MEOWTH
	release
	end

VerdanturfTown_PokemonCenter_2F_EventScript_Pokemon::
	lock
	faceplayer
	setvar VAR_0x8009, SPECIES_MEOWTH_ALOLAN
	playmoncry VAR_0x8009, 0
	msgbox VerdanturfTown_PokemonCenter_2F_Text_Pokemon, MSGBOX_DEFAULT
	waitmoncry
	release
	end

VerdanturfTown_PokemonCenter_2F_Text_Pokemon:
	.string "Meow!$"

VerdanturfTown_CableClub_EventScript_DeclineTrade::
	msgbox VerdanturfTown_CableClub_Text_YouDontWantToThatsOkay, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_CableClub_EventScript_NotRequestedMon::
	bufferspeciesname 0, VAR_0x8009
	msgbox VerdanturfTown_CableClub_Text_DoesntLookLikeMonToMe, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_CableClub_EventScript_TradeCompleted::
	msgbox VerdanturfTown_CableClub_Text_AnyPokemonCanBeCute, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_CableClub_Text_IllTradeIfYouWant:
	.string "I'll trade you my Alolan {STR_VAR_2} for\n"
	.string "a normal {STR_VAR_1} if you want.$"

VerdanturfTown_CableClub_Text_PleaseBeGoodToMyPokemon:
	.string "I love Meowth.$"

VerdanturfTown_CableClub_Text_DoesntLookLikeMonToMe:
	.string "It's not\n"
	.string "a {STR_VAR_1}.$"

VerdanturfTown_CableClub_Text_YouDontWantToThatsOkay:
	.string "I want every species of Meowth!$"

VerdanturfTown_CableClub_Text_AnyPokemonCanBeCute:
	.string "I love cats!$"

VerdanturfTown_CableClub_EventScript_Girl2::
	lock
	faceplayer
	goto_if_set FLAG_VERDANTURF_TRADE_EXEGGUTOR, VerdanturfTown_CableClub_EventScript_TradeCompleted2
	setvar VAR_0x8008, INGAME_TRADE_ALOLAN_EXEGGUTOR
	copyvar VAR_0x8004, VAR_0x8008
	specialvar VAR_RESULT, GetInGameTradeSpeciesInfo
	copyvar VAR_0x8009, VAR_RESULT
	msgbox VerdanturfTown_CableClub_Text_IllTradeIfYouWant2, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq VerdanturfTown_CableClub_EventScript_DeclineTrade2
	special ChoosePartyMon
	waitstate
	copyvar VAR_0x800A, VAR_0x8004
	compare VAR_0x8004, 255
	goto_if_eq VerdanturfTown_CableClub_EventScript_DeclineTrade2
	copyvar VAR_0x8005, VAR_0x800A
	specialvar VAR_RESULT, GetTradeSpecies
	copyvar VAR_0x800B, VAR_RESULT
	compare VAR_RESULT, VAR_0x8009
	goto_if_ne VerdanturfTown_CableClub_EventScript_NotRequestedMon2
	copyvar VAR_0x8004, VAR_0x8008
	copyvar VAR_0x8005, VAR_0x800A
	removeobject 8
	special CreateInGameTradePokemon
	special DoInGameTradeScene
	waitstate
	msgbox VerdanturfTown_CableClub_Text_PleaseBeGoodToMyPokemon2, MSGBOX_DEFAULT
	setflag FLAG_VERDANTURF_TRADE_EXEGGUTOR
	release
	end

VerdanturfTown_PokemonCenter_2F_EventScript_Pokemon2::
	lock
	faceplayer
	setvar VAR_0x8009, SPECIES_EXEGGUTOR_ALOLAN
	playmoncry VAR_0x8009, 0
	msgbox VerdanturfTown_PokemonCenter_2F_Text_Pokemon2, MSGBOX_DEFAULT
	waitmoncry
	release
	end

VerdanturfTown_PokemonCenter_2F_Text_Pokemon2:
	.string "Exe-ggutor!$"

VerdanturfTown_CableClub_EventScript_DeclineTrade2::
	msgbox VerdanturfTown_CableClub_Text_YouDontWantToThatsOkay2, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_CableClub_EventScript_NotRequestedMon2::
	bufferspeciesname 0, VAR_0x8009
	msgbox VerdanturfTown_CableClub_Text_DoesntLookLikeMonToMe2, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_CableClub_EventScript_TradeCompleted2::
	msgbox VerdanturfTown_CableClub_Text_AnyPokemonCanBeCute2, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_CableClub_Text_IllTradeIfYouWant2:
	.string "I'll trade you my Alolan {STR_VAR_2} for\n"
	.string "a normal {STR_VAR_1} if you want.$"

VerdanturfTown_CableClub_Text_PleaseBeGoodToMyPokemon2:
	.string "I love coconuts.$"

VerdanturfTown_CableClub_Text_DoesntLookLikeMonToMe2:
	.string "It's not\n"
	.string "a {STR_VAR_1}.$"

VerdanturfTown_CableClub_Text_YouDontWantToThatsOkay2:
	.string "I will go to the beach!$"

VerdanturfTown_CableClub_Text_AnyPokemonCanBeCute2:
	.string "I love the classics!$"
