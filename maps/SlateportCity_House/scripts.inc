SlateportCity_House_MapScripts::
	.byte 0

SlateportCity_House_EventScript_PokefanM::
	msgbox SlateportCity_House_Text_NatureToDoWithStatGains, MSGBOX_NPC
	end

SlateportCity_House_EventScript_Girl::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_MORPEKO, SlateportCity_House_EventScript_GirlThank
	msgbox SlateportCity_House_Text_MustBeGoingToBattleTent, MSGBOX_YESNO
	compare VAR_RESULT, 0
	goto_if_eq SlateportCity_House_EventScript_GirlDecline
	givemon SPECIES_MORPEKO, 15, ITEM_NONE
	bufferspeciesname 0, SPECIES_MORPEKO
	compare VAR_RESULT, 0
	goto_if_eq SlateportCity_House_EventScript_SendMorpekoCosplayToParty
	compare VAR_RESULT, 1
	goto_if_eq SlateportCity_House_EventScript_SendMorpekoCosplayToPC
	hidemonpic
	goto Common_EventScript_NoMoreRoomForPokemon
	end

SlateportCity_House_EventScript_GirlThank:
	msgbox SlateportCity_House_Text_Thank, MSGBOX_DEFAULT
	release
	end

SlateportCity_House_EventScript_SendMorpekoCosplayToParty:
	playfanfare MUS_OBTAIN_ITEM
	message SlateportCity_House_Text_ReceivedMorpekoCosplay
	waitmessage
	waitfanfare
	removeobject LOCALID_PIKACHU_COSPLAY
	goto_if_eq SlateportCity_House_EventScript_ReceivedMorpeko
	call Common_EventScript_GetGiftMonPartySlot
	call Common_EventScript_NameReceivedPartyMon
	goto SlateportCity_House_EventScript_ReceivedMorpeko
	end

SlateportCity_House_EventScript_SendMorpekoCosplayToPC:
	playfanfare MUS_OBTAIN_ITEM
	message SlateportCity_House_Text_ReceivedMorpekoCosplay
	waitmessage
	waitfanfare
	removeobject LOCALID_PIKACHU_COSPLAY
	goto_if_eq SlateportCity_House_EventScript_ReceivedMorpeko
	call Common_EventScript_GetGiftMonPartySlot
	call Common_EventScript_NameReceivedPartyMon
	goto SlateportCity_House_EventScript_ReceivedMorpeko
	end

SlateportCity_House_EventScript_ReceivedMorpeko:
	setflag FLAG_RECEIVED_MORPEKO
	release
	end

SlateportCity_House_EventScript_GirlDecline:
	msgbox SlateportCity_House_Text_Declined, MSGBOX_DEFAULT
	release
	end

SlateportCity_House_Text_Thank:
	.string "Thank you, {PLAYER}!$"

SlateportCity_House_Text_ReceivedMorpekoCosplay:
	.string "{PLAYER} received the {STR_VAR_1}!$"

SlateportCity_House_Text_Declined:
	.string "I don't think I can take care\n"
	.string "of it.$"

SlateportCity_House_Text_NatureToDoWithStatGains:
	.string "My Pokémon has a Hasty nature.\p"
	.string "It has higher Speed compared to\n"
	.string "my other Pokémon.\p"
	.string "Maybe their nature has something to\n"
	.string "do with the stat gains of Pokémon.$"

SlateportCity_House_Text_MustBeGoingToBattleTent:
	.string "I can't count the Pokémon because\n"
	.string "his mood is unstable! He's a\l"
	.string "sweetheart, but there are times\l"
	.string "when he starts fighting with\l"
	.string "everyone around him! Do you want\l"
	.string "to have him for you?$"

