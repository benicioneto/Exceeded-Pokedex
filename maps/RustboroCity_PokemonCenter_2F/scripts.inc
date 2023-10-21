RustboroCity_PokemonCenter_2F_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, CableClub_OnFrame
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, CableClub_OnWarp
	map_script MAP_SCRIPT_ON_LOAD, CableClub_OnLoad
	map_script MAP_SCRIPT_ON_TRANSITION, CableClub_OnTransition
	.byte 0

@ The below 3 are unused and leftover from RS
RustboroCity_PokemonCenter_2F_EventScript_Colosseum::
	call CableClub_EventScript_Colosseum
	end

RustboroCity_PokemonCenter_2F_EventScript_TradeCenter::
	call CableClub_EventScript_TradeCenter
	end

RustboroCity_PokemonCenter_2F_EventScript_RecordCorner::
	call CableClub_EventScript_RecordCorner
	end

RustboroCity_CableClub_EventScript_Girl::
	lock
	faceplayer
	goto_if_set FLAG_RUSTBORO_TRADE, RustboroCity_CableClub_EventScript_TradeCompleted
	setvar VAR_0x8008, INGAME_TRADE_ALOLAN_RAICHU
	copyvar VAR_0x8004, VAR_0x8008
	specialvar VAR_RESULT, GetInGameTradeSpeciesInfo
	copyvar VAR_0x8009, VAR_RESULT
	msgbox RustboroCity_CableClub_Text_IllTradeIfYouWant, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq RustboroCity_CableClub_EventScript_DeclineTrade
	special ChoosePartyMon
	waitstate
	copyvar VAR_0x800A, VAR_0x8004
	compare VAR_0x8004, 255
	goto_if_eq RustboroCity_CableClub_EventScript_DeclineTrade
	copyvar VAR_0x8005, VAR_0x800A
	specialvar VAR_RESULT, GetTradeSpecies
	copyvar VAR_0x800B, VAR_RESULT
	compare VAR_RESULT, VAR_0x8009
	goto_if_ne RustboroCity_CableClub_EventScript_NotRequestedMon
	copyvar VAR_0x8004, VAR_0x8008
	copyvar VAR_0x8005, VAR_0x800A
	removeobject 6
	special CreateInGameTradePokemon
	special DoInGameTradeScene
	waitstate
	msgbox RustboroCity_CableClub_Text_PleaseBeGoodToMyPokemon, MSGBOX_DEFAULT
	setflag FLAG_RUSTBORO_TRADE
	release
	end

RustboroCity_PokemonCenter_2F_EventScript_Pokemon::
	lock
	faceplayer
	setvar VAR_0x8009, SPECIES_RAICHU_ALOLAN
	playmoncry VAR_0x8009, 0
	msgbox RustboroCity_PokemonCenter_2F_Text_Pokemon, MSGBOX_DEFAULT
	waitmoncry
	release
	end

RustboroCity_PokemonCenter_2F_Text_Pokemon:
	.string "Chuu!$"

RustboroCity_CableClub_EventScript_DeclineTrade::
	msgbox RustboroCity_CableClub_Text_YouDontWantToThatsOkay, MSGBOX_DEFAULT
	release
	end

RustboroCity_CableClub_EventScript_NotRequestedMon::
	bufferspeciesname 0, VAR_0x8009
	msgbox RustboroCity_CableClub_Text_DoesntLookLikeMonToMe, MSGBOX_DEFAULT
	release
	end

RustboroCity_CableClub_EventScript_TradeCompleted::
	msgbox RustboroCity_CableClub_Text_AnyPokemonCanBeCute, MSGBOX_DEFAULT
	release
	end

RustboroCity_CableClub_Text_IllTradeIfYouWant:
	.string "I'll trade you my Alolan {STR_VAR_2} for\n"
	.string "a normal {STR_VAR_1} if you want.$"

RustboroCity_CableClub_Text_PleaseBeGoodToMyPokemon:
	.string "This Raichu reminds me old times!$"

RustboroCity_CableClub_Text_DoesntLookLikeMonToMe:
	.string "Huh? This is not\n"
	.string "a {STR_VAR_1}.$"

RustboroCity_CableClub_Text_YouDontWantToThatsOkay:
	.string "…$"

RustboroCity_CableClub_Text_AnyPokemonCanBeCute:
	.string "Raichu is so old school!$"
