RustboroCity_House3_MapScripts::
	.byte 0

RustboroCity_House3_EventScript_OldMan::
	msgbox RustboroCity_House3_Text_IGivePerfectlySuitedNicknames, MSGBOX_NPC
	end

@RustboroCity_House3_EventScript_OldWoman::
@	msgbox RustboroCity_House3_Text_NamingPikachuPekachu, MSGBOX_NPC
@	end

RustboroCity_House3_EventScript_OldWoman::
	lock
	goto_if_unset FLAG_CAPTURED_PETALWOOD_GALARIAN_FARFETCH, RustboroCity_House3_EventScript_SomethingInTheWoods
	goto_if_unset FLAG_BADGE03_GET, RustboroCity_House3_EventScript_TakeTimeToGoAgain
	goto_if_unset FLAG_ITEM_RUSTBOROCITY_LEEK, RustboroCity_House3_EventScript_CapturedFarfetchGiveLeek
	msgbox RustboroCity_House3_Text_Worried, MSGBOX_NPC
	release
	end

RustboroCity_House3_EventScript_SomethingInTheWoods:
	msgbox RustboroCity_House3_Text_SomethingInTheWoods, MSGBOX_NPC
	release
	end

RustboroCity_House3_EventScript_TakeTimeToGoAgain:
	msgbox RustboroCity_House3_Text_TakeTimeToGoAgaint, MSGBOX_NPC
	release
	end

RustboroCity_House3_EventScript_CapturedFarfetchGiveLeek:
	msgbox RustboroCity_House3_Text_CapturedFarfetchGiveLeek, MSGBOX_NPC
	giveitem ITEM_LIGHT_BALL
	setflag FLAG_ITEM_RUSTBOROCITY_LEEK
	release
	end

@ Misspelling on purpose, see nickname
RustboroCity_House3_EventScript_Pekachu::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_PIKACHU, 0
	msgbox RustboroCity_House3_Text_Pekachu, MSGBOX_DEFAULT
	waitmoncry
	release
	end

RustboroCity_House3_Text_SomethingInTheWoods:
	.string "There is something in the\n"
	.string "woods…\p"
	.string "I think you should investigate\n"
	.string "more deep! People are becoming\l"
	.string "afraid to go to the forest…$"

RustboroCity_House3_Text_TakeTimeToGoAgaint:
	.string "Oh?! Did you take care of\n"
	.string "the spooky one in the woods?…\p"
	.string "But I need more time to\n"
	.string "to go to there again…\p"
	.string "I'm too scaried…$"

RustboroCity_House3_Text_CapturedFarfetchGiveLeek:
	.string "Oh… So you really took\n"
	.string "care of it!\p"
	.string "So It was a Pichu, right?\p"
	.string "I thought it was something\n"
	.string "dangerous for the travellers.\p"
	.string "Also, I found this item\n"
	.string "in the woods this morning.\p"
	.string "I think Electric-type Pokémon\n"
	.string "really like it!\p"
	.string "Here, take it!$"

RustboroCity_House3_Text_Worried:
	.string "Now I can go to the woods with\n"
	.string "no worries!$"

RustboroCity_House3_Text_IGivePerfectlySuitedNicknames:
	.string "For my own Pokémon, I give them\n"
	.string "perfectly suited nicknames!\p"
	.string "It's my expression of, uh…\n"
	.string "originality, yes, that's it!$"

RustboroCity_House3_Text_NamingPikachuPekachu:
	.string "But giving the name Pekachu to\n"
	.string "a Pikachu? It seems pointless.\p"
	.string "I suppose it is good to use a name\n"
	.string "that's easy to understand, but…$"

RustboroCity_House3_Text_Pekachu:
	.string "Pekachu: Peka!$"

