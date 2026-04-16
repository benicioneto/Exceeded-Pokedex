AbilityTutor_EventScript_CanOnlyBeLearnedOnce::
	msgbox AbilityTutor_Text_ThisAbilityCanOnlyBeLearnedOnce, MSGBOX_YESNO
	return

AbilityTutor_EventScript_OpenPartyMenu::
	special ChooseMonForAbilityTutor
	waitstate
	lock
	faceplayer
	return
	
AbilityTutor_Text_ThisAbilityCanOnlyBeLearnedOnce:
	.string "Are you sure you want to\n"
	.string "teach this ability?$"

@

AbilityTutor_EventScript_EventScript_DragonHoardTutor::
	lock
	faceplayer
	msgbox AbilityTutor_Text_DragonHoardTeach, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq AbilityTutor_EventScript_DragonHoardDeclined
	call AbilityTutor_EventScript_CanOnlyBeLearnedOnce
	compare VAR_RESULT, NO
	goto_if_eq AbilityTutor_EventScript_DragonHoardDeclined
	msgbox AbilityTutor_Text_DragonHoardWhichMon, MSGBOX_DEFAULT
	setvar VAR_0x8005, TUTOR_ABILITY_DRAGON_HOARD
	call AbilityTutor_EventScript_OpenPartyMenu
	compare VAR_RESULT, 0
	goto_if_eq AbilityTutor_EventScript_DragonHoardDeclined
	goto AbilityTutor_EventScript_DragonHoardTaught
	end

AbilityTutor_EventScript_DragonHoardDeclined::
	msgbox AbilityTutor_Text_DragonHoardDeclined, MSGBOX_DEFAULT
	release
	end

AbilityTutor_EventScript_DragonHoardTaught::
	msgbox AbilityTutor_Text_DragonHoardTaught, MSGBOX_DEFAULT
	release
	end

AbilityTutor_Text_DragonHoardTeach:
	.string "Dragons tends to guard\n"
	.string "hoards of treasure -\l"
	.string "typically by lying on top of it.\p"
	.string "Do you want me to teach your\n"
	.string "Pokémon Dragon Hoard ability?$"

AbilityTutor_Text_DragonHoardDeclined:
	.string "That breath isn't hot as\n"
	.string "I thought.$"

AbilityTutor_Text_DragonHoardWhichMon:
	.string "Roooarr!\n"
	.string "Which Pokémon should I teach?$"

AbilityTutor_Text_DragonHoardTaught:
	.string "Now your Pokémon can\n"
	.string "defend their hoards!$"
@

@

AbilityTutor_EventScript_EventScript_BugCatcherTutor::
	lock
	faceplayer
	msgbox AbilityTutor_Text_BugCatcherTeach, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq AbilityTutor_EventScript_BugCatcherDeclined
	call AbilityTutor_EventScript_CanOnlyBeLearnedOnce
	compare VAR_RESULT, NO
	goto_if_eq AbilityTutor_EventScript_BugCatcherDeclined
	msgbox AbilityTutor_Text_BugCatcherWhichMon, MSGBOX_DEFAULT
	setvar VAR_0x8005, TUTOR_ABILITY_BUG_CATCHER
	call AbilityTutor_EventScript_OpenPartyMenu
	compare VAR_RESULT, 0
	goto_if_eq AbilityTutor_EventScript_BugCatcherDeclined
	goto AbilityTutor_EventScript_BugCatcherTaught
	end

AbilityTutor_EventScript_BugCatcherDeclined::
	msgbox AbilityTutor_Text_BugCatcherDeclined, MSGBOX_DEFAULT
	release
	end

AbilityTutor_EventScript_BugCatcherTaught::
	msgbox AbilityTutor_Text_BugCatcherTaught, MSGBOX_DEFAULT
	release
	end

AbilityTutor_Text_BugCatcherTeach:
	.string "Hey! You there Do you like\n"
	.string "Bug-type Pokémon?\p"
	.string "Bug Pokémon are AMAZING!\n"
	.string "Let me teach you how to catch\l"
	.string "them like a pro!$"

AbilityTutor_Text_BugCatcherDeclined:
	.string "Aww… you don't want to learn\n"
	.string "about Bug Pokémon?.$"

AbilityTutor_Text_BugCatcherWhichMon:
	.string "Buzz-Buzz!\n"
	.string "Which Pokémon should I teach?$"

AbilityTutor_Text_BugCatcherTaught:
	.string "Now your Pokémon can\n"
	.string "catch any Bug!$"
@
