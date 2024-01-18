ProfBirchRanch_MapScripts::
	.byte 0

ProfBirchRanch_EventScript_BirchsHouseSign::
	lockall
	msgbox ProfBirchRanch_Text_ProfBirchsRanch, MSGBOX_DEFAULT	
	releaseall
	end

ProfBirchRanch_Text_ProfBirchsRanch:
	.string "Prof. Birch's Ranch$"

ProfBirchRanch_EventScript_TakePokemon:
	bufferspeciesname 0, VAR_0x8009
	showmonpic VAR_0x8009, 5, 4
    msgbox ProfBirchRanch_Text_TakePokemon, MSGBOX_YESNO
    compare VAR_RESULT, 0 
    goto_if_eq ProfBirchRanch_EventScript_DontTake
	hidemonpic
    givemon VAR_0x8009, 5
    switch VAR_RESULT
    case 0, ProfBirchRanch_EventScript_SendToParty
    case 1, ProfBirchRanch_EventScript_SendToPC
    case 2, Common_EventScript_NoMoreRoomForPokemon
    end

ProfBirchRanch_EventScript_SendToParty:
    call ProfBirchRanch_EventScript_Fanfare
    msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
    compare VAR_RESULT, 0
    goto_if_eq ProfBirchRanch_EventScript_ReceivedPokemon
    call Common_EventScript_GetGiftMonPartySlot
	call Common_EventScript_NameReceivedPartyMon
    goto ProfBirchRanch_EventScript_ReceivedPokemon
	end

ProfBirchRanch_EventScript_SendToPC:
    call ProfBirchRanch_EventScript_Fanfare
    msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
    compare VAR_RESULT, 0
    goto_if_eq ProfBirchRanch_EventScript_TransferredToPC
    call Common_EventScript_NameReceivedBoxMon
    call Common_EventScript_TransferredToPC
    goto ProfBirchRanch_EventScript_ReceivedPokemon
	end

ProfBirchRanch_EventScript_TransferredToPC:
	call Common_EventScript_TransferredToPC
	goto ProfBirchRanch_EventScript_ReceivedPokemon

ProfBirchRanch_EventScript_Fanfare:
	addvar VAR_PROF_BIRCH_NEW_STARTER_STAGE, 1
	clearflag FLAG_BIRCH_ALLOW_TAKE_NEW_STARTER
	removeobject VAR_LAST_TALKED
	playfanfare MUS_OBTAIN_ITEM
	message ProfBirchRanch_Text_ReceivedPokemon
	waitmessage
	waitfanfare
	return

ProfBirchRanch_EventScript_ReceivedPokemon:
	release
	end

ProfBirchRanch_EventScript_DontTake:
	hidemonpic
	release
	end

ProfBirchRanch_Text_ReceivedPokemon:
	.string "{PLAYER} received the {STR_VAR_1}!$"

ProfBirchRanch_Text_TakePokemon:
	.string "Do you want to take {STR_VAR_1}\n"
	.string "as a gift from Prof. Birch?$"

ProfBirchRanch_EventScript_TURTWIG::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_TURTWIG, 0
	waitmoncry
	setvar VAR_TEMP_1, SPECIES_TURTWIG
	setvar VAR_0x8009, SPECIES_TURTWIG
	goto_if_set FLAG_BIRCH_ALLOW_TAKE_NEW_STARTER, ProfBirchRanch_EventScript_TakePokemon
	msgbox ProfBirchRanch_Text_TURTWIG, MSGBOX_DEFAULT
	release
	end

ProfBirchRanch_Text_TURTWIG:
	.string "Tur-Twig!$"

ProfBirchRanch_EventScript_SNIVY::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_SNIVY, 0
	setvar VAR_TEMP_1, SPECIES_SNIVY
	setvar VAR_0x8009, SPECIES_SNIVY
	goto_if_set FLAG_BIRCH_ALLOW_TAKE_NEW_STARTER, ProfBirchRanch_EventScript_TakePokemon
	msgbox ProfBirchRanch_Text_SNIVY, MSGBOX_DEFAULT
	waitmoncry
	release
	end

ProfBirchRanch_Text_SNIVY:
	.string "Snivy!$"

ProfBirchRanch_EventScript_CHESPIN::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_CHESPIN, 0
	setvar VAR_TEMP_1, SPECIES_CHESPIN
	setvar VAR_0x8009, SPECIES_CHESPIN
	goto_if_set FLAG_BIRCH_ALLOW_TAKE_NEW_STARTER, ProfBirchRanch_EventScript_TakePokemon
	msgbox ProfBirchRanch_Text_CHESPIN, MSGBOX_DEFAULT
	waitmoncry
	release
	end

ProfBirchRanch_Text_CHESPIN:
	.string "Ches-pin!$"

ProfBirchRanch_EventScript_CHIMCHAR::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_CHIMCHAR, 0
	setvar VAR_TEMP_1, SPECIES_CHIMCHAR
	setvar VAR_0x8009, SPECIES_CHIMCHAR
	goto_if_set FLAG_BIRCH_ALLOW_TAKE_NEW_STARTER, ProfBirchRanch_EventScript_TakePokemon
	msgbox ProfBirchRanch_Text_CHIMCHAR, MSGBOX_DEFAULT
	waitmoncry
	release
	end

ProfBirchRanch_Text_CHIMCHAR:
	.string "Chim-char!$"

ProfBirchRanch_EventScript_TEPIG::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_TEPIG, 0
	setvar VAR_TEMP_1, SPECIES_TEPIG
	setvar VAR_0x8009, SPECIES_TEPIG
	goto_if_set FLAG_BIRCH_ALLOW_TAKE_NEW_STARTER, ProfBirchRanch_EventScript_TakePokemon
	msgbox ProfBirchRanch_Text_TEPIG, MSGBOX_DEFAULT
	waitmoncry
	release
	end

ProfBirchRanch_Text_TEPIG:
	.string "Te-pig!$"

ProfBirchRanch_EventScript_FENNEKIN::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_FENNEKIN, 0
	setvar VAR_TEMP_1, SPECIES_FENNEKIN
	setvar VAR_0x8009, SPECIES_FENNEKIN
	goto_if_set FLAG_BIRCH_ALLOW_TAKE_NEW_STARTER, ProfBirchRanch_EventScript_TakePokemon
	msgbox ProfBirchRanch_Text_FENNEKIN, MSGBOX_DEFAULT
	waitmoncry
	release
	end

ProfBirchRanch_Text_FENNEKIN:
	.string "Fenne-kin!$"

ProfBirchRanch_EventScript_PIPLUP::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_PIPLUP, 0
	setvar VAR_TEMP_1, SPECIES_PIPLUP
	setvar VAR_0x8009, SPECIES_PIPLUP
	goto_if_set FLAG_BIRCH_ALLOW_TAKE_NEW_STARTER, ProfBirchRanch_EventScript_TakePokemon
	msgbox ProfBirchRanch_Text_PIPLUP, MSGBOX_DEFAULT
	waitmoncry
	release
	end

ProfBirchRanch_Text_PIPLUP:
	.string "Pip-lup!$"

ProfBirchRanch_EventScript_OSHAWOTT::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_OSHAWOTT, 0
	setvar VAR_TEMP_1, SPECIES_OSHAWOTT
	setvar VAR_0x8009, SPECIES_OSHAWOTT
	goto_if_set FLAG_BIRCH_ALLOW_TAKE_NEW_STARTER, ProfBirchRanch_EventScript_TakePokemon
	msgbox ProfBirchRanch_Text_OSHAWOTT, MSGBOX_DEFAULT
	waitmoncry
	release
	end

ProfBirchRanch_Text_OSHAWOTT:
	.string "Osha-wott!$"

ProfBirchRanch_EventScript_FROAKIE::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_FROAKIE, 0
	setvar VAR_TEMP_1, SPECIES_FROAKIE
	setvar VAR_0x8009, SPECIES_FROAKIE
	goto_if_set FLAG_BIRCH_ALLOW_TAKE_NEW_STARTER, ProfBirchRanch_EventScript_TakePokemon
	msgbox ProfBirchRanch_Text_FROAKIE, MSGBOX_DEFAULT
	waitmoncry
	release
	end

ProfBirchRanch_Text_FROAKIE:
	.string "Froa-kie!$"

ProfBirchRanch_EventScript_CHARMANDER::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_CHARMANDER, 0
	setvar VAR_TEMP_1, SPECIES_CHARMANDER
	setvar VAR_0x8009, SPECIES_CHARMANDER
	goto_if_set FLAG_BIRCH_ALLOW_TAKE_NEW_STARTER, ProfBirchRanch_EventScript_TakePokemon
	msgbox ProfBirchRanch_Text_CHARMANDER, MSGBOX_DEFAULT
	waitmoncry
	release
	end

ProfBirchRanch_Text_CHARMANDER:
	.string "Char-mander-char!$"

ProfBirchRanch_EventScript_TOTODILE::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_TOTODILE, 0
	setvar VAR_TEMP_1, SPECIES_TOTODILE
	setvar VAR_0x8009, SPECIES_TOTODILE
	goto_if_set FLAG_BIRCH_ALLOW_TAKE_NEW_STARTER, ProfBirchRanch_EventScript_TakePokemon
	msgbox ProfBirchRanch_Text_TOTODILE, MSGBOX_DEFAULT
	waitmoncry
	release
	end

ProfBirchRanch_Text_TOTODILE:
	.string "To-to-dile!$"

ProfBirchRanch_EventScript_ROWLET::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_ROWLET, 0
	setvar VAR_TEMP_1, SPECIES_ROWLET
	setvar VAR_0x8009, SPECIES_ROWLET
	goto_if_set FLAG_BIRCH_ALLOW_TAKE_NEW_STARTER, ProfBirchRanch_EventScript_TakePokemon
	msgbox ProfBirchRanch_Text_ROWLET, MSGBOX_DEFAULT
	waitmoncry
	release
	end

ProfBirchRanch_Text_ROWLET:
	.string "Row-let!$"

