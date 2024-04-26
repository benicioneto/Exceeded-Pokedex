FallarborTown_PokemonCenter_2F_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, CableClub_OnFrame
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, CableClub_OnWarp
	map_script MAP_SCRIPT_ON_LOAD, CableClub_OnLoad
	map_script MAP_SCRIPT_ON_TRANSITION, CableClub_OnTransition
	.byte 0

@ The below 3 are unused and leftover from RS
FallarborTown_PokemonCenter_2F_EventScript_Colosseum::
	call CableClub_EventScript_Colosseum
	end

FallarborTown_PokemonCenter_2F_EventScript_TradeCenter::
	call CableClub_EventScript_TradeCenter
	end

FallarborTown_PokemonCenter_2F_EventScript_RecordCorner::
	call CableClub_EventScript_RecordCorner
	end

FallarborTown_CableClub_EventScript_Girl::
	lock
	faceplayer
	goto_if_set FLAG_FALLARBOR_TRADE_MAROWAK, FallarborTown_CableClub_EventScript_TradeCompleted
	setvar VAR_0x8008, INGAME_TRADE_ALOLAN_MAROWAK
	copyvar VAR_0x8004, VAR_0x8008
	specialvar VAR_RESULT, GetInGameTradeSpeciesInfo
	copyvar VAR_0x8009, VAR_RESULT
	msgbox FallarborTown_CableClub_Text_IllTradeIfYouWant, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq FallarborTown_CableClub_EventScript_DeclineTrade
	special ChoosePartyMon
	waitstate
	copyvar VAR_0x800A, VAR_0x8004
	compare VAR_0x8004, 255
	goto_if_eq FallarborTown_CableClub_EventScript_DeclineTrade
	copyvar VAR_0x8005, VAR_0x800A
	specialvar VAR_RESULT, GetTradeSpecies
	copyvar VAR_0x800B, VAR_RESULT
	compare VAR_RESULT, VAR_0x8009
	goto_if_ne FallarborTown_CableClub_EventScript_NotRequestedMon
	copyvar VAR_0x8004, VAR_0x8008
	copyvar VAR_0x8005, VAR_0x800A
	removeobject 9
	special CreateInGameTradePokemon
	special DoInGameTradeScene
	waitstate
	msgbox FallarborTown_CableClub_Text_PleaseBeGoodToMyPokemon, MSGBOX_DEFAULT
	setflag FLAG_FALLARBOR_TRADE_MAROWAK
	release
	end

FallarborTown_PokemonCenter_2F_EventScript_Pokemon::
	lock
	faceplayer
	setvar VAR_0x8009, SPECIES_MAROWAK_ALOLAN
	playmoncry VAR_0x8009, 0
	msgbox FallarborTown_PokemonCenter_2F_Text_Pokemon, MSGBOX_DEFAULT
	waitmoncry
	release
	end

FallarborTown_PokemonCenter_2F_Text_Pokemon:
	.string "Maro-wak!$"

FallarborTown_CableClub_EventScript_DeclineTrade::
	msgbox FallarborTown_CableClub_Text_YouDontWantToThatsOkay, MSGBOX_DEFAULT
	release
	end

FallarborTown_CableClub_EventScript_NotRequestedMon::
	bufferspeciesname 0, VAR_0x8009
	msgbox FallarborTown_CableClub_Text_DoesntLookLikeMonToMe, MSGBOX_DEFAULT
	release
	end

FallarborTown_CableClub_EventScript_TradeCompleted::
	msgbox FallarborTown_CableClub_Text_AnyPokemonCanBeCute, MSGBOX_DEFAULT
	release
	end

FallarborTown_CableClub_Text_IllTradeIfYouWant:
	.string "I'll trade you my Alolan {STR_VAR_2} for\n"
	.string "a normal {STR_VAR_1} if you want.$"

FallarborTown_CableClub_Text_PleaseBeGoodToMyPokemon:
	.string "Poor Cubone…$"

FallarborTown_CableClub_Text_DoesntLookLikeMonToMe:
	.string "It's not\n"
	.string "a {STR_VAR_1}.$"

FallarborTown_CableClub_Text_YouDontWantToThatsOkay:
	.string "My baby Cubone from Kanto\n"
	.string "needs a mother…$"

FallarborTown_CableClub_Text_AnyPokemonCanBeCute:
	.string "Now my baby Cubone have a new mom!$"

FallarborTown_CableClub_EventScript_Random::
	msgbox FallarborTown_CableClub_Text_RandomTalk, MSGBOX_NPC
	end

FallarborTown_CableClub_EventScript_Random2::
	msgbox FallarborTown_CableClub_Text_RandomTalk2, MSGBOX_NPC
	end

FallarborTown_CableClub_EventScript_Random3::
	msgbox FallarborTown_CableClub_Text_RandomTalk3, MSGBOX_NPC
	goto_if_set FLAG_FALLARBOR_TRADE_MAROWAK, FallarborTown_CableClub_EventScript_Random4
	end

FallarborTown_CableClub_EventScript_Random4:
	applymovement 8, ContestHall_Movement_Heart
	end

FallarborTown_CableClub_Text_RandomTalk:
	.string "We need to find a new mom\n"
	.string "to our Cubone.$"

FallarborTown_CableClub_Text_RandomTalk2:
	.string "We found this little Cubone in\n"
	.string "another continent.$"

FallarborTown_CableClub_Text_RandomTalk3:
	.string "Cu-cubone.$"

