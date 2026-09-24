.set LOCALID_EEVEE_POKEBALL, 1

RustboroCity_Flat1_3F_MapScripts::
	.byte 0

RustboroCity_Flat1_3F_EventScript_GiveEevee::
	lock
	faceplayer
	givemonsimple SPECIES_EEVEE, 5, ITEM_QUICK_CLAW, ITEM_NONE, ITEM_NONE, MOVE_VEEVEE_VOLLEY, MOVE_NONE, MOVE_NONE, MOVE_NONE
	bufferspeciesname 0, SPECIES_EEVEE
	compare VAR_RESULT, 0
	goto_if_eq RustboroCity_Flat1_3F_EventScript_SendEeveeToParty
	compare VAR_RESULT, 1
	goto_if_eq RustboroCity_Flat1_3F_EventScript_SendEeveeToPC
	hidemonpic
	goto Common_EventScript_NoMoreRoomForPokemon
	end

RustboroCity_Flat1_3F_EventScript_SendEeveeToParty:
	playfanfare MUS_OBTAIN_ITEM
	message RustboroCity_Flat1_3F_Text_ReceivedEevee
	waitmessage
	waitfanfare
	removeobject LOCALID_EEVEE_POKEBALL
	goto_if_eq RustboroCity_Flat1_3F_EventScript_ReceivedEevee
	call Common_EventScript_GetGiftMonPartySlot
	call Common_EventScript_NameReceivedPartyMon
	goto RustboroCity_Flat1_3F_EventScript_ReceivedEevee
	end

RustboroCity_Flat1_3F_EventScript_SendEeveeToPC:
	playfanfare MUS_OBTAIN_ITEM
	message RustboroCity_Flat1_3F_Text_ReceivedEevee
	waitmessage
	waitfanfare
	removeobject LOCALID_EEVEE_POKEBALL
	goto_if_eq RustboroCity_Flat1_3F_EventScript_ReceivedEevee
	call Common_EventScript_GetGiftMonPartySlot
	call Common_EventScript_NameReceivedPartyMon
	goto RustboroCity_Flat1_3F_EventScript_ReceivedEevee
	end

RustboroCity_Flat1_3F_EventScript_ReceivedEevee:
	setflag FLAG_RECEIVED_EEVEE
	release
	end

RustboroCity_Flat1_3F_Text_ReceivedEevee:
	.string "{PLAYER} received the {STR_VAR_1}!$"
