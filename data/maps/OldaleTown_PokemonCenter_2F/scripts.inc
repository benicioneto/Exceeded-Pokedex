OldaleTown_PokemonCenter_2F_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, CableClub_OnFrame
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, CableClub_OnWarp
	map_script MAP_SCRIPT_ON_LOAD, CableClub_OnLoad
	map_script MAP_SCRIPT_ON_TRANSITION, CableClub_OnTransition
	.byte 0

@ The below 3 are unused and leftover from RS
OldaleTown_PokemonCenter_2F_EventScript_Colosseum::
	call CableClub_EventScript_Colosseum
	end

OldaleTown_PokemonCenter_2F_EventScript_TradeCenter::
	call CableClub_EventScript_TradeCenter
	end

OldaleTown_PokemonCenter_2F_EventScript_RecordCorner::
	call CableClub_EventScript_RecordCorner
	end


OldaleTown_CableClub_EventScript_Girl::
	msgbox OldaleTown_CableClub_Text_MyBrotherWantsZigzagoon, MSGBOX_NPC
	end

OldaleTown_CableClub_EventScript_LittleBoy::
	lock
	faceplayer
	goto_if_set FLAG_OLDALETOWN_TRADE, OldaleTown_CableClub_EventScript_TradeCompleted
	setvar VAR_0x8008, INGAME_TRADE_HERDIER
	copyvar VAR_0x8004, VAR_0x8008
	specialvar VAR_RESULT, GetInGameTradeSpeciesInfo
	copyvar VAR_0x8009, VAR_RESULT
	msgbox OldaleTown_CableClub_Text_IllTradeIfYouWant, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq OldaleTown_CableClub_EventScript_DeclineTrade
	special ChoosePartyMon
	waitstate
	copyvar VAR_0x800A, VAR_0x8004
	compare VAR_0x8004, 255
	goto_if_eq OldaleTown_CableClub_EventScript_DeclineTrade
	copyvar VAR_0x8005, VAR_0x800A
	specialvar VAR_RESULT, GetTradeSpecies
	copyvar VAR_0x800B, VAR_RESULT
	compare VAR_RESULT, VAR_0x8009
	goto_if_ne OldaleTown_CableClub_EventScript_NotRequestedMon
	copyvar VAR_0x8004, VAR_0x8008
	copyvar VAR_0x8005, VAR_0x800A
	removeobject 8
	special CreateInGameTradePokemon
	special DoInGameTradeScene
	waitstate
	msgbox OldaleTown_CableClub_Text_PleaseBeGoodToMyPokemon, MSGBOX_DEFAULT
	release
	end


OldaleTown_CableClub_EventScript_DeclineTrade::
	msgbox OldaleTown_CableClub_Text_YouDontWantToThatsOkay, MSGBOX_DEFAULT
	release
	end

OldaleTown_CableClub_EventScript_NotRequestedMon::
	bufferspeciesname 0, VAR_0x8009
	msgbox OldaleTown_CableClub_Text_DoesntLookLikeMonToMe, MSGBOX_DEFAULT
	release
	end

OldaleTown_CableClub_EventScript_TradeCompleted::
	msgbox OldaleTown_CableClub_Text_AnyPokemonCanBeCute, MSGBOX_DEFAULT
	release
	end

OldaleTown_CableClub_EventScript_Hiker::
	msgbox OldaleTown_CableClub_Text_AllSortsOfPlaces, MSGBOX_NPC
	end

OldaleTown_CableClub_Text_IllTradeIfYouWant:
	.string "I'll trade you my {STR_VAR_2} for\n"
	.string "a {STR_VAR_1} if you want.$"

OldaleTown_CableClub_Text_PleaseBeGoodToMyPokemon:
	.string "Zigzagoon is so cute!$"

OldaleTown_CableClub_Text_DoesntLookLikeMonToMe:
	.string "Huh? This is not\n"
	.string "a {STR_VAR_1}.$"

OldaleTown_CableClub_Text_YouDontWantToThatsOkay:
	.string "=($"

OldaleTown_CableClub_Text_AnyPokemonCanBeCute:
	.string "Lillipup is a strong Pokémon!$"

OldaleTown_CableClub_Text_AllSortsOfPlaces:
	.string "I've been in Sinnoh for a long time\n"
	.string "and still there are some species of\l"
	.string "Pokémon to discover!$"

OldaleTown_CableClub_Text_MyBrotherWantsZigzagoon:
	.string "My little brother wants to catch\n"
	.string "a Zigzagoon. But they Run Away\l"
	.string "so we couldn't catch any.$"

OldaleTown_PokemonCenter_2F_EventScript_Pokemon::
	lock
	faceplayer
	setvar VAR_0x8009, SPECIES_LILLIPUP
	playmoncry VAR_0x8009, 0
	msgbox OldaleTown_PokemonCenter_2F_Text_Pokemon, MSGBOX_DEFAULT
	waitmoncry
	release
	end

OldaleTown_PokemonCenter_2F_Text_Pokemon:
	.string "Lilli-pup!$"
