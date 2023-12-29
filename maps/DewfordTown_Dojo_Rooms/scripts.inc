.set LOCALID_BRUNO, 2

DewfordTown_Dojo_Rooms_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, DewfordTown_Dojo_Rooms_MAP_SCRIPT_ON_LOAD
	.byte 0

DewfordTown_Dojo_Rooms_MAP_SCRIPT_ON_LOAD:
	special GetDayOfWeek
	compare VAR_RESULT, 0 @sunday
	goto_if_eq DewfordTown_Dojo_Rooms_EventScript_ShowBruno
	compare VAR_RESULT, 6 @saturday
	goto_if_eq DewfordTown_Dojo_Rooms_EventScript_ShowBruno
	goto DewfordTown_Dojo_Rooms_EventScript_HideBruno

DewfordTown_Dojo_Rooms_EventScript_ShowBruno:
	clearflag FLAG_HIDE_ELITE_FOUR_BRUNO
	return

DewfordTown_Dojo_Rooms_EventScript_HideBruno:
	setflag FLAG_HIDE_ELITE_FOUR_BRUNO
	return

DewfordTown_Dojo_Rooms_EventScript_Bruno::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_TYROGUE, DewfordTown_Dojo_Rooms_EventScript_BrunoFinal
	msgbox DewfordTown_Dojo_Rooms_Text_TryGiveTyrogue, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq DewfordTown_Dojo_Rooms_EventScript_AcceptedTyrogue
	msgbox DewfordTown_Dojo_Rooms_Text_DeclinedTyrogue, MSGBOX_DEFAULT
	release
	end

DewfordTown_Dojo_Rooms_EventScript_BrunoFinal:
	msgbox DewfordTown_Dojo_Rooms_Text_HowIsTyrogue, MSGBOX_DEFAULT
	release
	end

DewfordTown_Dojo_Rooms_EventScript_AcceptedTyrogue:
	trainerbattle_no_intro TRAINER_ELITE_FOUR_BRUNO, DewfordTown_Dojo_Rooms_Text_BrunoDefeat
	call EventScript_RocketEdition_TryStealPokemon_Return
	msgbox DewfordTown_Dojo_Rooms_Text_BrunoAfterDefeat, MSGBOX_DEFAULT
	closemessage
	setflag FLAG_RECEIVED_TYROGUE
	givecustommonsimple SPECIES_TYROGUE, 10, ITEM_NONE, MOVE_DIZZY_PUNCH, MOVE_HIGH_JUMP_KICK, MOVE_FAKE_OUT, MOVE_HELPING_HAND
	bufferspeciesname 0, SPECIES_TYROGUE
	setvar VAR_TEMP_1, SPECIES_TYROGUE
	goto DewfordTown_Dojo_EventScript_GiveMon

DewfordTown_Dojo_Rooms_Text_HowIsTyrogue:
	.string "Keep up the hard work. I'll\n"
	.string "keep my training now.\p"
	.string "Farewell.$"

DewfordTown_Dojo_Rooms_Text_BrunoAfterDefeat:
	.string "My job is done! Here, take\n"
	.string "this reward.$"

DewfordTown_Dojo_Rooms_Text_BrunoDefeat:
	.string "why? How could I lose?.$"

DewfordTown_Dojo_Rooms_Text_DeclinedTyrogue:
	.string "You won't become the next\n"
	.string "Champion if you run of a battle.$"

DewfordTown_Dojo_Rooms_Text_TryGiveTyrogue:
	.string "I'm Bruno, one of the Elite\n"
	.string "Four member from Johto!\p"
	.string "I came to Hoenn to train with\n"
	.string "Brawly!\p"
	.string "Through rigorous training, people\n"
	.string "and Pokémon can become stronger!\p"
	.string "I've weight trained with my\n"
	.string "Pokémon! And that will never\l"
	.string "change! {PLAYER}!\p"
	.string "Did you come to challenge me?\n"
	.string "Haha…$"
