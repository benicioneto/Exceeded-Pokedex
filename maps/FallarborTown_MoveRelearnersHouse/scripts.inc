.set LOCALID_MOVE_RELEARNER, 1
.set LOCALID_EGG_MOVE_TEACHER, 2

FallarborTown_MoveRelearnersHouse_MapScripts::
	.byte 0

@@@@@@@@@@@ OLD MOVE @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

FallarborTown_MoveRelearnersHouse_EventScript_OldMoveTeacher::
	lockall
	applymovement LOCALID_MOVE_RELEARNER, Common_Movement_FacePlayer
	waitmovement 0
	goto_if_set FLAG_TEMP_1, FallarborTown_MoveRelearnersHouse_EventScript_AskTeachOldMove
	msgbox FallarborTown_MoveRelearnersHouse_Text_ImTheOldMoveTutor, MSGBOX_DEFAULT
	setflag FLAG_TEMP_1
	goto FallarborTown_MoveRelearnersHouse_EventScript_AskTeachOldMove
	end

FallarborTown_MoveRelearnersHouse_EventScript_AskTeachOldMove::
	checkitem ITEM_TINY_MUSHROOM, 2
	compare VAR_RESULT, TRUE
	goto_if_eq FallarborTown_MoveRelearnersHouse_EventScript_HaveEnoughMushrooms
	checkitem ITEM_BIG_MUSHROOM, 1
	compare VAR_RESULT, TRUE
	goto_if_eq FallarborTown_MoveRelearnersHouse_EventScript_HaveEnoughMushrooms
FallarborTown_MoveRelearnersHouse_EventScript_ComeBackWithMushrooms::
	msgbox FallarborTown_MoveRelearnersHouse_Text_ComeBackWithMushroom, MSGBOX_DEFAULT
	releaseall
	end

FallarborTown_MoveRelearnersHouse_EventScript_HaveEnoughMushrooms::
	msgbox FallarborTown_MoveRelearnersHouse_Text_ThatsAMushroomWantMeToTeachMove, MSGBOX_YESNO
	switch VAR_RESULT
	case NO, FallarborTown_MoveRelearnersHouse_EventScript_ComeBackWithMushrooms
	goto FallarborTown_MoveRelearnersHouse_EventScript_ChooseMonToTeachOldMove
	end

FallarborTown_MoveRelearnersHouse_EventScript_ChooseMonToTeachOldMove::
	msgbox FallarborTown_MoveRelearnersHouse_Text_TutorWhichMon, MSGBOX_DEFAULT
	@special ChooseMonForEggMoveTeacher
	special ChooseMonForMoveRelearner
	waitstate
	compare VAR_0x8004, 255
	goto_if_eq FallarborTown_MoveRelearnersHouse_EventScript_ComeBackWithMushrooms
	special IsSelectedMonEgg
	compare VAR_RESULT, TRUE
	goto_if_eq FallarborTown_MoveRelearnersHouse_EventScript_CantTeachEggAOldMove
	compare VAR_0x8005, 0
	goto_if_eq FallarborTown_MoveRelearnersHouse_EventScript_NoOldMoveToTeachMon
	goto FallarborTown_MoveRelearnersHouse_EventScript_ChooseOldMove
	end

FallarborTown_MoveRelearnersHouse_EventScript_ChooseOldMove::
	msgbox FallarborTown_MoveRelearnersHouse_Text_TeachWhichMove, MSGBOX_DEFAULT
	@special TeachMoveEggMove
	special TeachMoveRelearnerMove
	waitstate
	compare VAR_0x8004, 0
	goto_if_eq FallarborTown_MoveRelearnersHouse_EventScript_ChooseMonToTeachOldMove	
	checkitem ITEM_TINY_MUSHROOM, 2
	compare VAR_RESULT, TRUE
	goto_if_eq FallarborTown_MoveRelearnersHouse_EventScript_TakeTwoTinyMushrooms
	msgbox FallarborTown_MoveRelearnersHouse_Text_HandedOverOneBigMushroom, MSGBOX_DEFAULT
	removeitem ITEM_BIG_MUSHROOM
	goto FallarborTown_MoveRelearnersHouse_EventScript_ComeBackWithMushrooms
	end

FallarborTown_MoveRelearnersHouse_EventScript_TakeTwoTinyMushrooms::
	msgbox FallarborTown_MoveRelearnersHouse_Text_HandedOverTwoTinyMushrooms, MSGBOX_DEFAULT
	removeitem ITEM_TINY_MUSHROOM, 2
	goto FallarborTown_MoveRelearnersHouse_EventScript_ComeBackWithMushrooms
	end

FallarborTown_MoveRelearnersHouse_EventScript_NoOldMoveToTeachMon::
	msgbox FallarborTown_MoveRelearnersHouse_Text_DontHaveMoveToTeachPokemon, MSGBOX_DEFAULT
	goto FallarborTown_MoveRelearnersHouse_EventScript_ChooseMonToTeachOldMove
	end

FallarborTown_MoveRelearnersHouse_EventScript_CantTeachEggAOldMove::
	msgbox FallarborTown_MoveRelearnersHouse_Text_CantTeachEgg, MSGBOX_DEFAULT
	goto FallarborTown_MoveRelearnersHouse_EventScript_ChooseMonToTeachOldMove
	end

FallarborTown_MoveRelearnersHouse_Text_ImTheOldMoveTutor:
	.string "I'm the Move Reminder.\p"
	.string "I know all the moves that Pokémon\n"
	.string "learn--every one of them--and I can\l"
	.string "teach Pokémon those moves.\p"
	.string "I can teach a move to a Pokémon\n"
	.string "of yours if you'd like.\p"
	.string "I'll do it for two Tiny Mushrooms\n"
	.string "or one Big Mushroom.\l"
	.string "I'm collecting those now.$"

FallarborTown_MoveRelearnersHouse_Text_ComeBackWithMushroom:
	.string "If your Pokémon need to learn a move,\n"
	.string "come back with mushrooms.$"

FallarborTown_MoveRelearnersHouse_Text_ThatsAMushroomWantMeToTeachMove:
	.string "Sniff, Sniff… hm! You smell of\n"
	.string "mushrooms! Do you want me to teach\l"
	.string "a move to a Pokémon of yours?$"

FallarborTown_MoveRelearnersHouse_Text_HandedOverOneBigMushroom:
	.string "{PLAYER} handed over a Big Mushroom\n"
	.string "in exchange.$"

FallarborTown_MoveRelearnersHouse_Text_HandedOverTwoTinyMushrooms:
	.string "{PLAYER} handed over two Tiny Mushrooms\n"
	.string "in exchange.$"

@@@@@@@@@@@ EGG MOVE @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

FallarborTown_MoveRelearnersHouse_EventScript_EggMoveTeacher::
	lockall
	applymovement LOCALID_EGG_MOVE_TEACHER, Common_Movement_FacePlayer
	waitmovement 0
	goto_if_set FLAG_TEMP_2, FallarborTown_MoveRelearnersHouse_EventScript_AskTeachEggMove
	msgbox FallarborTown_MoveRelearnersHouse_Text_ImTheEggMoveTutor, MSGBOX_DEFAULT
	setflag FLAG_TEMP_2
	goto FallarborTown_MoveRelearnersHouse_EventScript_AskTeachEggMove
	end

FallarborTown_MoveRelearnersHouse_EventScript_AskTeachEggMove::
	checkitem ITEM_HEART_SCALE, 1
	compare VAR_RESULT, TRUE
	goto_if_eq FallarborTown_MoveRelearnersHouse_EventScript_HaveEnoughHeartScale
FallarborTown_MoveRelearnersHouse_EventScript_ComeBackWithHeartScale::
	msgbox FallarborTown_MoveRelearnersHouse_Text_ComeBackWithHeartScale, MSGBOX_DEFAULT
	releaseall
	end

FallarborTown_MoveRelearnersHouse_EventScript_HaveEnoughHeartScale::
	msgbox FallarborTown_MoveRelearnersHouse_Text_ThatsAHeartScaleWantMeToTeachMove, MSGBOX_YESNO
	switch VAR_RESULT
	case NO, FallarborTown_MoveRelearnersHouse_EventScript_ComeBackWithHeartScale
	goto FallarborTown_MoveRelearnersHouse_EventScript_ChooseMonToTeachEggMove
	end

FallarborTown_MoveRelearnersHouse_EventScript_ChooseMonToTeachEggMove::
	msgbox FallarborTown_MoveRelearnersHouse_Text_TutorWhichMon, MSGBOX_DEFAULT
	special ChooseMonForEggMoveTeacher
	waitstate
	compare VAR_0x8004, 255
	goto_if_eq FallarborTown_MoveRelearnersHouse_EventScript_ComeBackWithHeartScale
	special IsSelectedMonEgg
	compare VAR_RESULT, TRUE
	goto_if_eq FallarborTown_MoveRelearnersHouse_EventScript_CantTeachEggAEggMove
	compare VAR_0x8005, 0
	goto_if_eq FallarborTown_MoveRelearnersHouse_EventScript_NoEggMoveToTeachMon
	goto FallarborTown_MoveRelearnersHouse_EventScript_ChooseEggMove
	end

FallarborTown_MoveRelearnersHouse_EventScript_ChooseEggMove::
	msgbox FallarborTown_MoveRelearnersHouse_Text_TeachWhichMove, MSGBOX_DEFAULT
	special TeachMoveEggMove
	waitstate
	compare VAR_0x8004, 0
	goto_if_eq FallarborTown_MoveRelearnersHouse_EventScript_ChooseMonToTeachEggMove	
	msgbox FallarborTown_MoveRelearnersHouse_Text_HandedOverHeartScale, MSGBOX_DEFAULT
	removeitem ITEM_HEART_SCALE
	goto FallarborTown_MoveRelearnersHouse_EventScript_ComeBackWithHeartScale
	end

FallarborTown_MoveRelearnersHouse_EventScript_NoEggMoveToTeachMon::
	msgbox FallarborTown_MoveRelearnersHouse_Text_DontHaveMoveToTeachPokemon, MSGBOX_DEFAULT
	goto FallarborTown_MoveRelearnersHouse_EventScript_ChooseMonToTeachEggMove
	end

FallarborTown_MoveRelearnersHouse_EventScript_CantTeachEggAEggMove::
	msgbox FallarborTown_MoveRelearnersHouse_Text_CantTeachEgg, MSGBOX_DEFAULT
	goto FallarborTown_MoveRelearnersHouse_EventScript_ChooseMonToTeachEggMove
	end

FallarborTown_MoveRelearnersHouse_Text_ImTheEggMoveTutor:
	.string "I'm the Egg Move Tutor.\p"
	.string "I know all the moves that Pokémon\n"
	.string "learn through breeding from the\l"
	.string "parent--every one of them--and I\l"
	.string "can teach Pokémon those moves.\p"
	.string "I can teach a egg move to a Pokémon\n"
	.string "of yours if you'd like.\p"
	.string "I'll do it for a Heart Scale.\n"
	.string "I'm collecting those now.$"

FallarborTown_MoveRelearnersHouse_Text_ThatsAHeartScaleWantMeToTeachMove:
	.string "Oh! That's it! That's an honest to\n"
	.string "goodness Heart Scale!\p"
	.string "Let me guess, you want me to teach\n"
	.string "an egg move?$"

FallarborTown_MoveRelearnersHouse_Text_HandedOverHeartScale:
	.string "{PLAYER} handed over one Heart Scale\n"
	.string "in exchange.$"

FallarborTown_MoveRelearnersHouse_Text_ComeBackWithHeartScale:
	.string "If your Pokémon need to learn a move,\n"
	.string "come back with a Heart Scale.$"

@@@@@@@@@@@ Common phrases @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

FallarborTown_MoveRelearnersHouse_Text_TutorWhichMon:
	.string "Which Pokémon needs tutoring?$"

FallarborTown_MoveRelearnersHouse_Text_TeachWhichMove:
	.string "Which move should I teach?$"

FallarborTown_MoveRelearnersHouse_Text_CantTeachEgg:
	.string "Hunh? There isn't a single move that\n"
	.string "I can teach an Egg.$"

FallarborTown_MoveRelearnersHouse_Text_DontHaveMoveToTeachPokemon:
	.string "Sorry…\p"
	.string "It doesn't appear as if I have any move\n"
	.string "I can teach that Pokémon.$"

@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
