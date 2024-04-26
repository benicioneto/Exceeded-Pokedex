DewfordTown_House2_MapScripts::
	.byte 0

DewfordTown_House2_EventScript_Man::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_SILK_SCARF, DewfordTown_House2_EventScript_ExplainSilkScarf
	msgbox DewfordTown_House2_Text_WantYouToHaveSilkScarf, MSGBOX_DEFAULT
	giveitem ITEM_SILK_SCARF
	compare VAR_RESULT, FALSE
	goto_if_eq DewfordTown_House2_EventScript_NoRoomForScarf
	setflag FLAG_RECEIVED_SILK_SCARF
	release
	end

DewfordTown_House2_EventScript_NoRoomForScarf::
	msgbox DewfordTown_House2_Text_NoRoom, MSGBOX_DEFAULT
	release
	end

DewfordTown_House2_EventScript_ExplainSilkScarf::
	msgbox DewfordTown_House2_Text_ExplainSilkScarf, MSGBOX_DEFAULT
	release
	end

@DewfordTown_House2_EventScript_Boy::
@	msgbox DewfordTown_House2_Text_BrawlySoCool, MSGBOX_NPC
@	end

DewfordTown_House2_EventScript_Boy::
	lockall
	faceplayer
	goto_if_set FLAG_RECEIVED_TM_BRINE, DewfordTown_House2_EventScript_ExplainBrine
	msgbox DewfordTown_House2_Text_BrawlySoCool, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq DewfordTown_House2_EventScript_MyDream	
	special ChoosePartyMon
	waitstate
	copyvar VAR_RESULT, VAR_0x8004
	compare VAR_RESULT, 255
	goto_if_eq DewfordTown_House2_EventScript_MyDream
	specialvar VAR_RESULT, ScriptGetPartyMonSpecies
	compare VAR_RESULT, SPECIES_KRABBY
	goto_if_eq DewfordTown_House2_EventScript_GiveBrineTM
	msgbox DewfordTown_House2_Text_NoKrabby, MSGBOX_NPC
	release
	end

DewfordTown_House2_EventScript_ExplainBrine:
	msgbox DewfordTown_House2_Text_ExplainBrine, MSGBOX_NPC
	releaseall
	end

DewfordTown_House2_EventScript_MyDream:
	msgbox DewfordTown_House2_Text_MyDream, MSGBOX_NPC
	releaseall
	end

DewfordTown_House2_EventScript_GiveBrineTM:
	msgbox DewfordTown_House2_Text_YeahKrabby, MSGBOX_NPC
	giveitem ITEM_TM51_BRINE
	setflag FLAG_RECEIVED_TM_BRINE
	releaseall
	end

DewfordTown_House2_Text_YeahKrabby:
	.string "Yeah! That's a big Krabby!\p"
	.string "Let me give you this reward.$"

DewfordTown_House2_Text_NoKrabby:
	.string "Oh… That's not a Krabby…$"

DewfordTown_House2_Text_WantYouToHaveSilkScarf:
	.string "Gorge your eyes on this!\p"
	.string "It's a Silk Scarf. It's right at the\n"
	.string "cutting edge of fashion, yeah!\p"
	.string "Oh, I can see your eyes twinkling!\n"
	.string "You appreciate my dazzling style!\p"
	.string "Oh, you're a delight!\n"
	.string "Here you go. I want you to have it!$"

DewfordTown_House2_Text_NoRoom:
	.string "Oh, you don't have room?\p"
	.string "Now, listen tight, this Scarf is a must-\n"
	.string "have! Why, I would sell all my items\l"
	.string "in order to get it!$"

DewfordTown_House2_Text_ExplainSilkScarf:
	.string "The Silk Scarf raises the power of\n"
	.string "Normal-type moves.\p"
	.string "It's a marvelous Scarf that will go\n"
	.string "with almost all Pokémon!$"

@DewfordTown_House2_Text_BrawlySoCool:
@	.string "Wow, you bothered to cross the sea\n"
@	.string "to visit Dewford?\p"
@	.string "Did you maybe come here because you\n"
@	.string "heard about Brawly?\p"
@	.string "He's so cool…\n"
@	.string "Everyone idolizes him.$"

DewfordTown_House2_Text_BrawlySoCool:
	.string "I always wanted to catch a Krabby\n"
	.string "with my rod, but i never could…\p"
	.string "Could you show me a Krabby you caught?$"

DewfordTown_House2_Text_MyDream:
	.string "It's my dream to caught a big one…$"

DewfordTown_House2_Text_ExplainBrine:
	.string "Brine deals more damage if the target\n"
	.string "is lower than half HP.$"
