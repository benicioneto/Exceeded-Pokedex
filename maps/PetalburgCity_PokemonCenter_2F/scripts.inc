PetalburgCity_PokemonCenter_2F_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, CableClub_OnFrame
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, CableClub_OnWarp
	map_script MAP_SCRIPT_ON_LOAD, CableClub_OnLoad
	map_script MAP_SCRIPT_ON_TRANSITION, CableClub_OnTransition
	.byte 0

@ The below 3 are unused and leftover from RS
PetalburgCity_PokemonCenter_2F_EventScript_Colosseum::
	call CableClub_EventScript_Colosseum
	end

PetalburgCity_PokemonCenter_2F_EventScript_TradeCenter::
	call CableClub_EventScript_TradeCenter
	end

PetalburgCity_PokemonCenter_2F_EventScript_RecordCorner::
	call CableClub_EventScript_RecordCorner
	end

PetalburgCity_CableClub_EventScript_Girl::
	lock
	faceplayer
	goto_if_set FLAG_PETALBURGCITY_TRADE_VULPIX, PetalburgCity_CableClub_EventScript_TradeCompleted
	setvar VAR_0x8008, INGAME_TRADE_ALOLAN_VULPIX
	copyvar VAR_0x8004, VAR_0x8008
	specialvar VAR_RESULT, GetInGameTradeSpeciesInfo
	copyvar VAR_0x8009, VAR_RESULT
	msgbox PetalburgCity_CableClub_Text_IllTradeIfYouWant, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq PetalburgCity_CableClub_EventScript_DeclineTrade
	special ChoosePartyMon
	waitstate
	copyvar VAR_0x800A, VAR_0x8004
	compare VAR_0x8004, 255
	goto_if_eq PetalburgCity_CableClub_EventScript_DeclineTrade
	copyvar VAR_0x8005, VAR_0x800A
	specialvar VAR_RESULT, GetTradeSpecies
	copyvar VAR_0x800B, VAR_RESULT
	compare VAR_RESULT, VAR_0x8009
	goto_if_ne PetalburgCity_CableClub_EventScript_NotRequestedMon
	copyvar VAR_0x8004, VAR_0x8008
	copyvar VAR_0x8005, VAR_0x800A
	removeobject 7
	special CreateInGameTradePokemon
	special DoInGameTradeScene
	waitstate
	msgbox PetalburgCity_CableClub_Text_PleaseBeGoodToMyPokemon, MSGBOX_DEFAULT
	setflag FLAG_PETALBURGCITY_TRADE_VULPIX
	release
	end

PetalburgCity_PokemonCenter_2F_EventScript_Pokemon::
	lock
	faceplayer
	setvar VAR_0x8009, SPECIES_VULPIX_ALOLAN
	playmoncry VAR_0x8009, 0
	msgbox PetalburgCity_PokemonCenter_2F_Text_Pokemon, MSGBOX_DEFAULT
	waitmoncry
	release
	end

PetalburgCity_PokemonCenter_2F_Text_Pokemon:
	.string "Vul-pix!$"

PetalburgCity_CableClub_EventScript_DeclineTrade::
	msgbox PetalburgCity_CableClub_Text_YouDontWantToThatsOkay, MSGBOX_DEFAULT
	release
	end

PetalburgCity_CableClub_EventScript_NotRequestedMon::
	bufferspeciesname 0, VAR_0x8009
	msgbox PetalburgCity_CableClub_Text_DoesntLookLikeMonToMe, MSGBOX_DEFAULT
	release
	end

PetalburgCity_CableClub_EventScript_TradeCompleted::
	msgbox PetalburgCity_CableClub_Text_AnyPokemonCanBeCute, MSGBOX_DEFAULT
	release
	end

PetalburgCity_CableClub_Text_IllTradeIfYouWant:
	.string "I'll trade you my Ice-type {STR_VAR_2} for\n"
	.string "a normal {STR_VAR_1} if you want.$"

PetalburgCity_CableClub_Text_PleaseBeGoodToMyPokemon:
	.string "I love this Vulpix, it is so warm!$"

PetalburgCity_CableClub_Text_DoesntLookLikeMonToMe:
	.string "Huh? This is not\n"
	.string "a {STR_VAR_1}.$"

PetalburgCity_CableClub_Text_YouDontWantToThatsOkay:
	.string "I need a Pokémon to warm me …$"

PetalburgCity_CableClub_Text_AnyPokemonCanBeCute:
	.string "Vulpix is so beautiful!$"

PetalburgCity_CableClub_EventScript_Boy::
	lock
	faceplayer
	goto_if_set FLAG_PETALBURGCITY_TRADE_SANDSHREW, PetalburgCity_CableClub_EventScript_TradeCompleted2
	setvar VAR_0x8008, INGAME_TRADE_ALOLAN_SANDSHREW
	copyvar VAR_0x8004, VAR_0x8008
	specialvar VAR_RESULT, GetInGameTradeSpeciesInfo
	copyvar VAR_0x8009, VAR_RESULT
	msgbox PetalburgCity_CableClub_Text_IllTradeIfYouWant, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq PetalburgCity_CableClub_EventScript_DeclineTrade2
	special ChoosePartyMon
	waitstate
	copyvar VAR_0x800A, VAR_0x8004
	compare VAR_0x8004, 255
	goto_if_eq PetalburgCity_CableClub_EventScript_DeclineTrade2
	copyvar VAR_0x8005, VAR_0x800A
	specialvar VAR_RESULT, GetTradeSpecies
	copyvar VAR_0x800B, VAR_RESULT
	compare VAR_RESULT, VAR_0x8009
	goto_if_ne PetalburgCity_CableClub_EventScript_NotRequestedMon
	copyvar VAR_0x8004, VAR_0x8008
	copyvar VAR_0x8005, VAR_0x800A
	removeobject 8
	special CreateInGameTradePokemon
	special DoInGameTradeScene
	waitstate
	msgbox PetalburgCity_CableClub_Text_PleaseBeGoodToMyPokemon2, MSGBOX_DEFAULT
	setflag FLAG_PETALBURGCITY_TRADE_SANDSHREW
	release
	end

PetalburgCity_PokemonCenter_2F_EventScript_Pokemon2::
	lock
	faceplayer
	setvar VAR_0x8009, SPECIES_SANDSHREW_ALOLAN
	playmoncry VAR_0x8009, 0
	msgbox PetalburgCity_PokemonCenter_2F_Text_Pokemon2, MSGBOX_DEFAULT
	waitmoncry
	release
	end

PetalburgCity_PokemonCenter_2F_Text_Pokemon2:
	.string "Shr-ew!$"

PetalburgCity_CableClub_EventScript_DeclineTrade2::
	msgbox PetalburgCity_CableClub_Text_YouDontWantToThatsOkay2, MSGBOX_DEFAULT
	release
	end

PetalburgCity_CableClub_EventScript_TradeCompleted2::
	msgbox PetalburgCity_CableClub_Text_AnyPokemonCanBeCute2, MSGBOX_DEFAULT
	release
	end

PetalburgCity_CableClub_Text_PleaseBeGoodToMyPokemon2:
	.string "Now i can start digging to hunt\n"
	.string "some treasures!$"

PetalburgCity_CableClub_Text_YouDontWantToThatsOkay2:
	.string "Despite that my Pokémon digs very well\n"
	.string "on the snow, here it can't do much…$"

PetalburgCity_CableClub_Text_AnyPokemonCanBeCute2:
	.string "Nice! Thank you so much, now i can\n"
	.string "start digging!$"
