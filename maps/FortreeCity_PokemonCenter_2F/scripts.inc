FortreeCity_PokemonCenter_2F_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, CableClub_OnFrame
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, CableClub_OnWarp
	map_script MAP_SCRIPT_ON_LOAD, CableClub_OnLoad
	map_script MAP_SCRIPT_ON_TRANSITION, CableClub_OnTransition
	.byte 0

@ The below 3 are unused and leftover from RS
FortreeCity_PokemonCenter_2F_EventScript_Colosseum::
	call CableClub_EventScript_Colosseum
	end

FortreeCity_PokemonCenter_2F_EventScript_TradeCenter::
	call CableClub_EventScript_TradeCenter
	end

FortreeCity_PokemonCenter_2F_EventScript_RecordCorner::
	call CableClub_EventScript_RecordCorner
	end

FortreeCity_CableClub_EventScript_LittleBoy::
	lock
	faceplayer
	goto_if_set FLAG_FORTREECITY_TRADE, FortreeCity_CableClub_EventScript_TradeCompleted
	setvar VAR_0x8008, INGAME_TRADE_WIGGLET
	copyvar VAR_0x8004, VAR_0x8008
	specialvar VAR_RESULT, GetInGameTradeSpeciesInfo
	copyvar VAR_0x8009, VAR_RESULT
	msgbox FortreeCity_CableClub_Text_IllTradeIfYouWant, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq FortreeCity_CableClub_EventScript_DeclineTrade
	special ChoosePartyMon
	waitstate
	copyvar VAR_0x800A, VAR_0x8004
	compare VAR_0x8004, 255
	goto_if_eq FortreeCity_CableClub_EventScript_DeclineTrade
	copyvar VAR_0x8005, VAR_0x800A
	specialvar VAR_RESULT, GetTradeSpecies
	copyvar VAR_0x800B, VAR_RESULT
	compare VAR_RESULT, VAR_0x8009
	goto_if_ne FortreeCity_CableClub_EventScript_NotRequestedMon
	copyvar VAR_0x8004, VAR_0x8008
	copyvar VAR_0x8005, VAR_0x800A
	removeobject 5
	special CreateInGameTradePokemon
	special DoInGameTradeScene
	waitstate
	msgbox FortreeCity_CableClub_Text_PleaseBeGoodToMyPokemon, MSGBOX_DEFAULT
	release
	end


FortreeCity_CableClub_EventScript_DeclineTrade::
	msgbox FortreeCity_CableClub_Text_YouDontWantToThatsOkay, MSGBOX_DEFAULT
	release
	end

FortreeCity_CableClub_EventScript_NotRequestedMon::
	bufferspeciesname 0, VAR_0x8009
	msgbox FortreeCity_CableClub_Text_DoesntLookLikeMonToMe, MSGBOX_DEFAULT
	release
	end

FortreeCity_CableClub_EventScript_TradeCompleted::
	msgbox FortreeCity_CableClub_Text_AnyPokemonCanBeCute, MSGBOX_DEFAULT
	release
	end

FortreeCity_CableClub_Text_IllTradeIfYouWant:
	.string "I'll trade you my {STR_VAR_2} for\n"
	.string "a {STR_VAR_1} if you want.$"

FortreeCity_CableClub_Text_PleaseBeGoodToMyPokemon:
	.string "Please be good to my Pokémon!$"

FortreeCity_CableClub_Text_DoesntLookLikeMonToMe:
	.string "Huh? This is not\n"
	.string "a {STR_VAR_1}.$"

FortreeCity_CableClub_Text_YouDontWantToThatsOkay:
	.string "Okay ...$"

FortreeCity_CableClub_Text_AnyPokemonCanBeCute:
	.string "He leaves in the sea!$"

FortreeCity_PokemonCenter_2F_EventScript_Pokemon::
	lock
	faceplayer
	setvar VAR_0x8009, SPECIES_WIGLETT
	playmoncry VAR_0x8009, 0
	msgbox FortreeCity_PokemonCenter_2F_Text_Pokemon, MSGBOX_DEFAULT
	waitmoncry
	release
	end

FortreeCity_PokemonCenter_2F_Text_Pokemon:
	.string "Wiglett!$"


