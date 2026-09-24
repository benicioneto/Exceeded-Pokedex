.set LOCALID_LOTAD_DOLL, 2

Route114_LanettesHouse_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route114_LanettesHouse_OnTransition
	.byte 0

Route114_LanettesHouse_OnTransition:
	setflag FLAG_LANDMARK_LANETTES_HOUSE
	end

Route114_LanettesHouse_EventScript_Eevee::
	lock
	faceplayer
	msgbox Route114_LanettesHouse_Text_EeveeTalk, MSGBOX_DEFAULT
	release
	end

Route114_LanettesHouse_EventScript_LotadDoll::
	givedecoration DECOR_LOTAD_DOLL
	removeobject LOCALID_LOTAD_DOLL
	release
	end

Route114_LanettesHouse_EventScript_Lanette::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_PORYGON, Route114_LanettesHouse_EventScript_OfferAdvice
	msgbox Route114_LanettesHouse_EventScript_AskToCareEevee, MSGBOX_YESNO
	compare VAR_RESULT, 0
	goto_if_eq Route114_LanettesHouse_EventScript_EeveeDecline
	givemonsimple SPECIES_PORYGON, 20, ITEM_METRONOME, ITEM_NONE, ITEM_NONE, MOVE_TRICK_ROOM, MOVE_PSYBEAM, MOVE_THUNDER_SHOCK, MOVE_MAGNET_RISE
	bufferspeciesname 0, SPECIES_PORYGON
	compare VAR_RESULT, 0
	goto_if_eq Route114_LanettesHouse_EventScript_SendEeveeToParty
	compare VAR_RESULT, 1
	goto_if_eq Route114_LanettesHouse_EventScript_SendEeveeToPC
	hidemonpic
	goto Common_EventScript_NoMoreRoomForPokemon
	end

Route114_LanettesHouse_EventScript_SendEeveeToParty:
	playfanfare MUS_OBTAIN_ITEM
	message Route114_LanettesHouse_Text_ReceivedEevee
	waitmessage
	waitfanfare
	@removeobject LOCALID_EEVEE
	goto_if_eq Route114_LanettesHouse_EventScript_ReceivedEevee
	call Common_EventScript_GetGiftMonPartySlot
	call Common_EventScript_NameReceivedPartyMon
	goto Route114_LanettesHouse_EventScript_ReceivedEevee
	end

Route114_LanettesHouse_EventScript_SendEeveeToPC:
	playfanfare MUS_OBTAIN_ITEM
	message Route114_LanettesHouse_Text_ReceivedEevee
	waitmessage
	waitfanfare
	@removeobject LOCALID_EEVEE
	goto_if_eq Route114_LanettesHouse_EventScript_ReceivedEevee
	call Common_EventScript_GetGiftMonPartySlot
	call Common_EventScript_NameReceivedPartyMon
	goto Route114_LanettesHouse_EventScript_ReceivedEevee
	end

Route114_LanettesHouse_EventScript_ReceivedEevee:
	setflag FLAG_RECEIVED_PORYGON
	release
	end

Route114_LanettesHouse_EventScript_EeveeDecline::
	msgbox Route114_LanettesHouse_Text_EeveeDeclined, MSGBOX_DEFAULT
	release
	end

Route114_LanettesHouse_EventScript_OfferAdvice::
	msgbox Route114_LanettesHouse_Text_OrganizeYourBoxes, MSGBOX_DEFAULT
	release
	end

Route114_LanettesHouse_EventScript_Notebook::
	lockall
	msgbox Route114_LanettesHouse_Text_ResearchNotesPage1, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq Route114_LanettesHouse_EventScript_NotebookPage2
	msgbox Route114_LanettesHouse_Text_ClosedTheNotebook, MSGBOX_DEFAULT
	releaseall
	end

Route114_LanettesHouse_EventScript_NotebookPage2::
	msgbox Route114_LanettesHouse_Text_ResearchNotesPage2, MSGBOX_YESNO
	compare VAR_RESULT, YES
	call_if_eq Route114_LanettesHouse_EventScript_NotebookPage3
	releaseall
	end

Route114_LanettesHouse_EventScript_NotebookPage3::
	msgbox Route114_LanettesHouse_Text_ResearchNotesPage3, MSGBOX_DEFAULT
	return

Route114_LanettesHouse_EventScript_PC::
	msgbox Route114_LanettesHouse_Text_EmailFromBill, MSGBOX_SIGN
	end

Route114_LanettesHouse_Text_EeveeDeclined:
	.string "Oh… I understand.\p"
	.string "I suppose I can't ask you to take care\n"
	.string "of Eevee if you're too busy…\p"
	.string "I'll try my best to spend more time\n"
	.string "with it myself.\p"
	.string "Thank you for listening, {PLAYER}{KUN}.$"

Route114_LanettesHouse_EventScript_AskToCareEevee:
	.string "Lanette: Oh! {PLAYER}{KUN}!\p"
	.string "I'm sorry to ask you this out of the blue,\n"
	.string "but there's something I need help with…\p"
	.string "You see, Bill recently gave me a\n"
	.string "Porygon to look after.\p"
	.string "It's a wonderful Pokémon, but…\n"
	.string "I'm not very good at taking care of it.\p"
	.string "I get so caught up in my research that\n"
	.string "I hardly ever leave the house…\p"
	.string "I'm afraid Porygon must be terribly bored\n"
	.string "spending all its time here with me.\p"
	.string "So… would you mind taking it with you\n"
	.string "from time to time?\p"
	.string "I'd really like it to see the world outside\n"
	.string "the PC and have some real adventures.\p"
	.string "Could I count on you, {PLAYER}{KUN}?$"

Route114_LanettesHouse_Text_OrganizeYourBoxes:
	.string "May I offer advice about my Pokémon\n"
	.string "Storage System?\p"
	.string "You should organize your Boxes so you\n"
	.string "can tell which Pokémon are in them.$"

Route114_LanettesHouse_Text_ResearchNotesPage1:
	.string "It's Lanette's research notes.\n"
	.string "There's information about Boxes.\p"
	.string "Design Boxes to hold 30 Pokémon each.\p"
	.string "Each Trainer should be able to store\n"
	.string "420 Pokémon on the PC system.\p"
	.string "Keep reading?$"

Route114_LanettesHouse_Text_ResearchNotesPage2:
	.string "A marking system should be added to\n"
	.string "make Pokémon easier to organize.\p"
	.string "The name and wallpaper design of each\n"
	.string "Box will be made changeable to please\l"
	.string "the stored Pokémon.\p"
	.string "Keep reading?$"

Route114_LanettesHouse_Text_ResearchNotesPage3:
	.string "When storing a Pokémon, it should be\n"
	.string "sent to the Box inspected last.\p"
	.string "If that Box is full, the received\n"
	.string "Pokémon is stored in the next Box.\p"
	.string "In other words, when a Box is examined,\n"
	.string "it is automatically selected as the Box\l"
	.string "to which Pokémon are sent.$"

Route114_LanettesHouse_Text_ClosedTheNotebook:
	.string "{PLAYER} closed the notebook.$"

Route114_LanettesHouse_Text_EmailFromBill:
	.string "There's an e-mail from someone on\n"
	.string "the PC.\p"
	.string "“… … … … … … …\p"
	.string "“Your Storage System offers more\n"
	.string "convenience than mine.\p"
	.string "“It has a lot of user-friendly features\n"
	.string "that make it fun and useful, too.\p"
	.string "“It makes me proud that I played\n"
	.string "a part in its development.\p"
	.string "“Here's hoping that you'll continue\n"
	.string "research in Storage Systems.\p"
	.string "“From Bill\n"
	.string "… … … … … … … …”$"

Route114_LanettesHouse_Text_ReceivedEevee:
	.string "{PLAYER} received the {STR_VAR_1}!$"

Route114_LanettesHouse_Text_EeveeTalk:
	.string "Eevee: {EMOJI_TIRED}$"

