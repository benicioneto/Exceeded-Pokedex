PetalburgCity_House1_MapScripts::
	.byte 0

@@PetalburgCity_House1_EventScript_Man::
@@	msgbox PetalburgCity_House1_Text_TravelingIsWonderful, MSGBOX_NPC
@@	end

PetalburgCity_House1_EventScript_Woman::
	msgbox PetalburgCity_House1_Text_GoOnAdventure, MSGBOX_NPC
	end

@@PetalburgCity_House1_Text_TravelingIsWonderful:
@@	.string "Traveling is wonderful!\p"
@@	.string "When I was young, I roamed the seas\n"
@@	.string "and the mountains!$"

PetalburgCity_House1_Text_GoOnAdventure:
	.string "Sigh…\p"
	.string "I wish I could go on an adventure\n"
	.string "with some Pokémon…\p"
	.string "Crawl through some damp grass…\n"
	.string "Climb rocky, rugged mountains…\p"
	.string "Cross the raging seas…\n"
	.string "Wander about in dark caves…\p"
	.string "And, sometimes, even get a little\n"
	.string "homesick…\p"
	.string "It must be fabulous to travel!$"


@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
@@		New Scripts
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

PetalburgCity_House1_EventScript_Man::
	lock
    faceplayer    
	goto_if_set FLAG_RECEIVED_ELEMENTAL_MONKEY, EventScript_ReceivedMonkey
    switch VAR_STARTER_MON
    case 0, GivePanpour  @Player choice Grass
    case 1, GivePansage  @Player choice Fire
    case 2, GivePansear  @Player choice Water
    end

DontWantElementalMonkey:
    msgbox ThenComeBackAnyTime, MSGBOX_NPC
    release
    end

GivePanpour:
    msgbox DoYouWantPanpour, MSGBOX_YESNO
    compare VAR_RESULT, 0 
    goto_if_eq DontWantElementalMonkey  
    msgbox PanpourBenefits, MSGBOX_NPC
	bufferspeciesname 0, SPECIES_PANPOUR
	setvar VAR_TEMP_1, SPECIES_PANPOUR
    givemon SPECIES_PANPOUR, 5, ITEM_NONE
    switch VAR_RESULT
    case 0, EventScript_SendMonkeyToParty
    case 1, EventScript_SendMonkeyToPC
    case 2, Common_EventScript_NoMoreRoomForPokemon @"There's no more room for any more\..."
    end

GivePansear:
    msgbox DoYouWantPansear, MSGBOX_YESNO
    compare VAR_RESULT, 0 
    goto_if_eq DontWantElementalMonkey  
    msgbox PansearBenefits, MSGBOX_NPC
	bufferspeciesname 0, SPECIES_PANSEAR
	setvar VAR_TEMP_1, SPECIES_PANSEAR
    givemon SPECIES_PANSEAR, 5, ITEM_NONE
    switch VAR_RESULT
    case 0, EventScript_SendMonkeyToParty
    case 1, EventScript_SendMonkeyToPC
    case 2, Common_EventScript_NoMoreRoomForPokemon @"There's no more room for any more\..."
    end

GivePansage:
    msgbox DoYouWantPansage, MSGBOX_YESNO
    compare VAR_RESULT, 0 
    goto_if_eq DontWantElementalMonkey  
    msgbox PansageBenefits, MSGBOX_NPC
	bufferspeciesname 0, SPECIES_PANSAGE
	setvar VAR_TEMP_1, SPECIES_PANSAGE
    givemon SPECIES_PANSAGE, 5, ITEM_NONE
    switch VAR_RESULT
    case 0, EventScript_SendMonkeyToParty
    case 1, EventScript_SendMonkeyToPC
    case 2, Common_EventScript_NoMoreRoomForPokemon @"There's no more room for any more\..."
    end

EventScript_SendMonkeyToParty:
    call ElementalMonkeyPayFor
    msgbox gText_NicknameThisPokemon, MSGBOX_YESNO @"Do you want to give a nickname to\..."
    compare VAR_RESULT, 0
    goto_if_eq ElementalMonkeyHideMoney
    call Common_EventScript_GetGiftMonPartySlot
	call Common_EventScript_NameReceivedPartyMon
    goto EventScript_ReceivedMonkey
	end

EventScript_SendMonkeyToPC:
    call ElementalMonkeyPayFor
    msgbox gText_NicknameThisPokemon, MSGBOX_YESNO @"Do you want to give a nickname to\..."
    compare VAR_RESULT, 0
    goto_if_eq EventScript_MonkeyTransferredToPC
    call Common_EventScript_NameReceivedBoxMon
    goto EventScript_MonkeyTransferredToPC2
	end

ElementalMonkeyPayFor:
	playfanfare MUS_OBTAIN_ITEM
	message ElementalMonkeyPayed
	waitmessage
	waitfanfare
	return

ElementalMonkeyHideMoney:
    goto EventScript_ReceivedMonkey
    end

EventScript_ReceivedMonkey:    
	msgbox ElementalMonkeyReward, MSGBOX_NPC
    setflag FLAG_RECEIVED_ELEMENTAL_MONKEY
    release
    end

EventScript_MonkeyTransferredToPC:
    call Common_EventScript_TransferredToPC
    goto ElementalMonkeyHideMoney
    end

EventScript_MonkeyTransferredToPC2:
    call Common_EventScript_TransferredToPC
    goto EventScript_ReceivedMonkey
    end

ThenComeBackAnyTime:
	.string "My, my. If you want it, come back\n"
	.string "and talk to me again, Ok?$"

ElementalMonkeyPayed:
	.string "{PLAYER} received the {STR_VAR_1}!$"

DoYouWantPanpour:
	.string "Hey! Hey, you!\n"
	.string "What was the first Pokémon you\l"
	.string "received?\l"
	.string "…\l"
	.string "…\p"
	.string "Rowlet! Really?\n"
	.string "Then Panpour could be a big help!\l"
	.string "Your Rowlet does not do well\l"
	.string "against Fire-type Pokémon!\p"
	.string "Say, do you want this Panpour of mine?$"

DoYouWantPansear:
	.string "Hey! Hey, you!\n"
	.string "What was the first Pokémon you\l"
	.string "received?\l"
	.string "…\l"
	.string "…\p"
	.string "Totodile! Really?\n"
	.string "Then Pansear could be a big help!\l"
	.string "Your Totodile does not do well\l"
	.string "against Grass-type Pokémon!\p"
	.string "Say, do you want this Pansear of mine?$"

DoYouWantPansage:
	.string "Hey! Hey, you!\n"
	.string "What was the first Pokémon you\l"
	.string "received?\l"
	.string "…\l"
	.string "…\p"
	.string "Charmander! Really?\n"
	.string "Then Pansage could be a big help!\l"
	.string "Your Charmander does not do well\l"
	.string "against Water-type Pokémon!\p"
	.string "Say, do you want this Pansage of mine?$"

PanpourBenefits:
	.string "Ok. Here you go!\p"
	.string "It can use Water-type moves, so that\n"
	.string "makes it great against Fire types!$"

PansearBenefits:
	.string "Ok. Here you go!\p"
	.string "It can use Fire-type moves, so that\n"
	.string "makes it great against Grass types!$"

PansageBenefits:
	.string "Ok. Here you go!\p"
	.string "It can use Grass-type moves, so that\n"
	.string "makes it great against Water types!$"

ElementalMonkeyReward:
	.string "If you have many types of Pokémon,\n"
	.string "something will work out, no matter\l"
	.string "what kind of Pokémon you have to face.$"
