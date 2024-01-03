MossdeepCity_PokemonCenter_2F_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, CableClub_OnFrame
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, CableClub_OnWarp
	map_script MAP_SCRIPT_ON_LOAD, CableClub_OnLoad
	map_script MAP_SCRIPT_ON_TRANSITION, CableClub_OnTransition
	.byte 0

@ The below 3 are unused and leftover from RS
MossdeepCity_PokemonCenter_2F_EventScript_Colosseum::
	call CableClub_EventScript_Colosseum
	end

MossdeepCity_PokemonCenter_2F_EventScript_TradeCenter::
	call CableClub_EventScript_TradeCenter
	end

MossdeepCity_PokemonCenter_2F_EventScript_RecordCorner::
	call CableClub_EventScript_RecordCorner
	end

MossdeepCity_PokemonCenter_2F_EventScript_Woman5::
	msgbox MossdeepCity_PokemonCenter_2F_Text_Woman5, MSGBOX_NPC
	end

MossdeepCity_PokemonCenter_2F_Text_Woman5:
	.string "If I win a whole lot of link battles\n"
	.string "and show everyone how good I am,\l"
	.string "I might get a fan following!$"


MossdeepCity_CableClub_EventScript_LittleBoy::
	lock
	faceplayer
	goto_if_set FLAG_MOSSDEEPCITY_TRADE, MossdeepCity_CableClub_EventScript_TradeCompleted
	setvar VAR_0x8008, INGAME_TRADE_POLTHCAGEIST
	copyvar VAR_0x8004, VAR_0x8008
	specialvar VAR_RESULT, GetInGameTradeSpeciesInfo
	copyvar VAR_0x8009, VAR_RESULT
	msgbox MossdeepCity_CableClub_Text_IllTradeIfYouWant, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq MossdeepCity_CableClub_EventScript_DeclineTrade
	special ChoosePartyMon
	waitstate
	copyvar VAR_0x800A, VAR_0x8004
	compare VAR_0x8004, 255
	goto_if_eq MossdeepCity_CableClub_EventScript_DeclineTrade
	copyvar VAR_0x8005, VAR_0x800A
	specialvar VAR_RESULT, GetTradeSpecies
	copyvar VAR_0x800B, VAR_RESULT
	compare VAR_RESULT, VAR_0x8009
	goto_if_ne MossdeepCity_CableClub_EventScript_NotRequestedMon
	copyvar VAR_0x8004, VAR_0x8008
	copyvar VAR_0x8005, VAR_0x800A
	removeobject 7
	special CreateInGameTradePokemon
	special DoInGameTradeScene
	waitstate
	msgbox MossdeepCity_CableClub_Text_PleaseBeGoodToMyPokemon, MSGBOX_DEFAULT
	release
	end


MossdeepCity_CableClub_EventScript_DeclineTrade::
	msgbox MossdeepCity_CableClub_Text_YouDontWantToThatsOkay, MSGBOX_DEFAULT
	release
	end

MossdeepCity_CableClub_EventScript_NotRequestedMon::
	bufferspeciesname 0, VAR_0x8009
	msgbox MossdeepCity_CableClub_Text_DoesntLookLikeMonToMe, MSGBOX_DEFAULT
	release
	end

MossdeepCity_CableClub_EventScript_TradeCompleted::
	msgbox MossdeepCity_CableClub_Text_AnyPokemonCanBeCute, MSGBOX_DEFAULT
	release
	end

MossdeepCity_CableClub_Text_IllTradeIfYouWant:
	.string "I'll trade you my {STR_VAR_2} for\n"
	.string "a {STR_VAR_1} if you want.$"

MossdeepCity_CableClub_Text_PleaseBeGoodToMyPokemon:
	.string "I prefer a natural tea!$"

MossdeepCity_CableClub_Text_DoesntLookLikeMonToMe:
	.string "Huh? This is not\n"
	.string "a {STR_VAR_1}.$"

MossdeepCity_CableClub_Text_YouDontWantToThatsOkay:
	.string "That's okay.$"

MossdeepCity_CableClub_Text_AnyPokemonCanBeCute:
	.string "I love tea!$"

MossdeepCity_PokemonCenter_2F_EventScript_Pokemon::
	lock
	faceplayer
	setvar VAR_0x8009, SPECIES_POLTCHAGEIST
	playmoncry VAR_0x8009, 0
	msgbox MossdeepCity_PokemonCenter_2F_Text_Pokemon, MSGBOX_DEFAULT
	waitmoncry
	release
	end

MossdeepCity_PokemonCenter_2F_Text_Pokemon:
	.string "Polt-cha!$"

