DewfordTown_PokemonCenter_2F_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, CableClub_OnFrame
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, CableClub_OnWarp
	map_script MAP_SCRIPT_ON_LOAD, CableClub_OnLoad
	map_script MAP_SCRIPT_ON_TRANSITION, CableClub_OnTransition
	.byte 0

@ The below 3 are unused and leftover from RS
DewfordTown_PokemonCenter_2F_EventScript_Colosseum::
	call CableClub_EventScript_Colosseum
	end

DewfordTown_PokemonCenter_2F_EventScript_TradeCenter::
	call CableClub_EventScript_TradeCenter
	end

DewfordTown_PokemonCenter_2F_EventScript_RecordCorner::
	call CableClub_EventScript_RecordCorner
	end

DewfordTown_CableClub_EventScript_Fighter::
	lock
	faceplayer
	goto_if_set FLAG_DEWFORD_TM_BODY_PRESS, DewfordTown_CableClub_EventScript_ExplainTmBodyPress
	msgbox DewfordTown_CableClub_Text_GivesTmBodyPress, MSGBOX_DEFAULT
	giveitem ITEM_TM55_BODY_PRESS
	compare VAR_RESULT, FALSE
	goto_if_eq Common_EventScript_ShowBagIsFull
	setflag FLAG_DEWFORD_TM_BODY_PRESS
DewfordTown_CableClub_EventScript_ExplainTmBodyPress:
	msgbox DewfordTown_CableClub_Text_ExplainTmBodyPress, MSGBOX_DEFAULT
	release
	end

DewfordTown_CableClub_EventScript_Random::
	msgbox DewfordTown_CableClub_Text_RandomTalk, MSGBOX_NPC
	end

DewfordTown_CableClub_EventScript_Girl::
	lock
	faceplayer
	goto_if_set FLAG_DEWFORD_TRADE, DewfordTown_CableClub_EventScript_TradeCompleted
	setvar VAR_0x8008, INGAME_TRADE_ALOLAN_GEODUDE
	copyvar VAR_0x8004, VAR_0x8008
	specialvar VAR_RESULT, GetInGameTradeSpeciesInfo
	copyvar VAR_0x8009, VAR_RESULT
	msgbox DewfordTown_CableClub_Text_IllTradeIfYouWant, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq DewfordTown_CableClub_EventScript_DeclineTrade
	special ChoosePartyMon
	waitstate
	copyvar VAR_0x800A, VAR_0x8004
	compare VAR_0x8004, 255
	goto_if_eq DewfordTown_CableClub_EventScript_DeclineTrade
	copyvar VAR_0x8005, VAR_0x800A
	specialvar VAR_RESULT, GetTradeSpecies
	copyvar VAR_0x800B, VAR_RESULT
	compare VAR_RESULT, VAR_0x8009
	goto_if_ne DewfordTown_CableClub_EventScript_NotRequestedMon
	copyvar VAR_0x8004, VAR_0x8008
	copyvar VAR_0x8005, VAR_0x800A
	removeobject 8
	special CreateInGameTradePokemon
	special DoInGameTradeScene
	waitstate
	msgbox DewfordTown_CableClub_Text_PleaseBeGoodToMyPokemon, MSGBOX_DEFAULT
	setflag FLAG_DEWFORD_TRADE
	release
	end

DewfordTown_PokemonCenter_2F_EventScript_Pokemon::
	lock
	faceplayer
	setvar VAR_0x8009, SPECIES_GEODUDE_ALOLAN
	playmoncry VAR_0x8009, 0
	msgbox DewfordTown_PokemonCenter_2F_Text_Pokemon, MSGBOX_DEFAULT
	waitmoncry
	release
	end

DewfordTown_PokemonCenter_2F_Text_Pokemon:
	.string "Dude!$"

DewfordTown_CableClub_EventScript_DeclineTrade::
	msgbox DewfordTown_CableClub_Text_YouDontWantToThatsOkay, MSGBOX_DEFAULT
	release
	end

DewfordTown_CableClub_EventScript_NotRequestedMon::
	bufferspeciesname 0, VAR_0x8009
	msgbox DewfordTown_CableClub_Text_DoesntLookLikeMonToMe, MSGBOX_DEFAULT
	release
	end

DewfordTown_CableClub_EventScript_TradeCompleted::
	msgbox DewfordTown_CableClub_Text_AnyPokemonCanBeCute, MSGBOX_DEFAULT
	release
	end

DewfordTown_CableClub_Text_IllTradeIfYouWant:
	.string "I'll trade you my Alolan {STR_VAR_2} for\n"
	.string "a normal {STR_VAR_1} if you want.$"

DewfordTown_CableClub_Text_PleaseBeGoodToMyPokemon:
	.string "Take care of my Geodude!$"

DewfordTown_CableClub_Text_DoesntLookLikeMonToMe:
	.string "Huh? This is not\n"
	.string "a {STR_VAR_1}.$"

DewfordTown_CableClub_Text_YouDontWantToThatsOkay:
	.string "I think you should visit Granite Cave.$"

DewfordTown_CableClub_Text_AnyPokemonCanBeCute:
	.string "Geodude is so solid!$"

DewfordTown_CableClub_Text_ExplainTmBodyPress:
	.string "The move Body Press deals more damage\n"
	.string "the higher is the user's Defense.$"

DewfordTown_CableClub_Text_GivesTmBodyPress:
	.string "Here, takes this TM55. I've learned\n"
	.string "with the Dewford Gym Leader.$"

DewfordTown_CableClub_Text_RandomTalk:
	.string "We arrived here from another\n"
	.string "continent to discover new Pokémon.$"
