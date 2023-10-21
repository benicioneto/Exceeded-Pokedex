MauvilleCity_PokemonCenter_2F_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, CableClub_OnFrame
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, CableClub_OnWarp
	map_script MAP_SCRIPT_ON_LOAD, CableClub_OnLoad
	map_script MAP_SCRIPT_ON_TRANSITION, CableClub_OnTransition
	.byte 0

@ The below 3 are unused and leftover from RS
MauvilleCity_PokemonCenter_2F_EventScript_Colosseum::
	call CableClub_EventScript_Colosseum
	end

MauvilleCity_PokemonCenter_2F_EventScript_TradeCenter::
	call CableClub_EventScript_TradeCenter
	end

MauvilleCity_PokemonCenter_2F_EventScript_RecordCorner::
	call CableClub_EventScript_RecordCorner
	end

MauvilleCity_PokemonCenter_2F_EventScript_Youngster::
	msgbox MauvilleCity_PokemonCenter_2F_Text_Youngster, MSGBOX_NPC
	end

MauvilleCity_PokemonCenter_2F_Text_Youngster:
	.string "Did you know that you can link battle\n"
	.string "at the Colosseum here?\p"
	.string "They put up your record on the wall\n"
	.string "for everyone to see.\p"
	.string "It's embarrassing if you lose more\n"
	.string "often than you win…$"

MauvilleCity_PokemonCenter_2F_EventScript_Random1::
	msgbox MauvilleCity_PokemonCenter_2F_Text_Random1, MSGBOX_NPC
	end

MauvilleCity_PokemonCenter_2F_EventScript_Random2::
	msgbox MauvilleCity_PokemonCenter_2F_Text_Random2, MSGBOX_NPC
	end

MauvilleCity_PokemonCenter_2F_Text_Random1:
	.string "I'm waiting here to find a way to pass\n"
	.string "through the sandstorm.$"

MauvilleCity_PokemonCenter_2F_Text_Random2:
	.string "I think I should buy a Pokémon\n"
	.string "at the Cassino …$"

MauvilleCity_CableClub_EventScript_Girl::
	lock
	faceplayer
	goto_if_set FLAG_MAUVILLE_TRADE, MauvilleCity_CableClub_EventScript_TradeCompleted
	setvar VAR_0x8008, INGAME_TRADE_ALOLAN_DIGLETT
	copyvar VAR_0x8004, VAR_0x8008
	specialvar VAR_RESULT, GetInGameTradeSpeciesInfo
	copyvar VAR_0x8009, VAR_RESULT
	msgbox MauvilleCity_CableClub_Text_IllTradeIfYouWant, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq MauvilleCity_CableClub_EventScript_DeclineTrade
	special ChoosePartyMon
	waitstate
	copyvar VAR_0x800A, VAR_0x8004
	compare VAR_0x8004, 255
	goto_if_eq MauvilleCity_CableClub_EventScript_DeclineTrade
	copyvar VAR_0x8005, VAR_0x800A
	specialvar VAR_RESULT, GetTradeSpecies
	copyvar VAR_0x800B, VAR_RESULT
	compare VAR_RESULT, VAR_0x8009
	goto_if_ne MauvilleCity_CableClub_EventScript_NotRequestedMon
	copyvar VAR_0x8004, VAR_0x8008
	copyvar VAR_0x8005, VAR_0x800A
	removeobject 10
	special CreateInGameTradePokemon
	special DoInGameTradeScene
	waitstate
	msgbox MauvilleCity_CableClub_Text_PleaseBeGoodToMyPokemon, MSGBOX_DEFAULT
	setflag FLAG_MAUVILLE_TRADE
	release
	end

MauvilleCity_PokemonCenter_2F_EventScript_Pokemon::
	lock
	faceplayer
	setvar VAR_0x8009, SPECIES_DIGLETT_ALOLAN
	playmoncry VAR_0x8009, 0
	msgbox MauvilleCity_PokemonCenter_2F_Text_Pokemon, MSGBOX_DEFAULT
	waitmoncry
	release
	end

MauvilleCity_PokemonCenter_2F_Text_Pokemon:
	.string "Dig-lett!$"

MauvilleCity_CableClub_EventScript_DeclineTrade::
	msgbox MauvilleCity_CableClub_Text_YouDontWantToThatsOkay, MSGBOX_DEFAULT
	release
	end

MauvilleCity_CableClub_EventScript_NotRequestedMon::
	bufferspeciesname 0, VAR_0x8009
	msgbox MauvilleCity_CableClub_Text_DoesntLookLikeMonToMe, MSGBOX_DEFAULT
	release
	end

MauvilleCity_CableClub_EventScript_TradeCompleted::
	msgbox MauvilleCity_CableClub_Text_AnyPokemonCanBeCute, MSGBOX_DEFAULT
	release
	end

MauvilleCity_CableClub_Text_IllTradeIfYouWant:
	.string "I'll trade you my Alolan {STR_VAR_2} for\n"
	.string "a normal {STR_VAR_1} if you want.$"

MauvilleCity_CableClub_Text_PleaseBeGoodToMyPokemon:
	.string "I prefer the bald ones!$"

MauvilleCity_CableClub_Text_DoesntLookLikeMonToMe:
	.string "No… It's not\n"
	.string "a {STR_VAR_1}.$"

MauvilleCity_CableClub_Text_YouDontWantToThatsOkay:
	.string "Don't try to deceive me…$"

MauvilleCity_CableClub_Text_AnyPokemonCanBeCute:
	.string "I hate the cut!$"

MauvilleCity_PokemonCenter_EventScript_UltimateTutor::
	lock
	faceplayer
	msgbox MoveTutor_Text_UltimateTeach, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq MoveTutor_EventScript_UltimateDeclined
	call MoveTutor_EventScript_CanOnlyBeLearnedOnce
	compare VAR_RESULT, NO
	goto_if_eq MoveTutor_EventScript_UltimateDeclined
	msgbox MoveTutor_Text_UltimateWhichMon, MSGBOX_DEFAULT
	setvar VAR_0x8005, TUTOR_MOVE_ULTIMATE
	call MoveTutor_EventScript_OpenPartyMenu
	compare VAR_RESULT, 0
	goto_if_eq MoveTutor_EventScript_UltimateDeclined
	goto MoveTutor_EventScript_UltimateTaught
	end

MoveTutor_EventScript_UltimateDeclined::
	msgbox MoveTutor_Text_UltimateDeclined, MSGBOX_DEFAULT
	release
	end

MoveTutor_EventScript_UltimateTaught::
	msgbox MoveTutor_Text_UltimateTaught, MSGBOX_DEFAULT
	release
	end

MoveTutor_Text_UltimateTeach:
    .string "The Pokémon must be worthy of\n"
    .string "learning my ultimate move!\p"
    .string "Will you allow it?$"

MoveTutor_Text_UltimateDeclined:
    .string "Gaah! You reject it?\n"
    .string "No, I won't be dissuaded!$"

MoveTutor_Text_UltimateWhichMon:
	.string "Which Pokémon should I teach?$"

MoveTutor_Text_UltimateTaught:
    .string "Gasp, gasp, gasp…\p"
    .string "I didn't think I could teach that\n"
    .string "move while I still lived…$"
