MeteorFalls_ZinniaHouse_MapScripts::
	.byte 0

MeteorFalls_ZinniaHouse_EventScript_Zinnia::
	lock
	faceplayer
	compare VAR_END_OF_THE_WORLD, 4
	goto_if_ge MeteorFalls_ZinniaHouse_EventScript_WeAreSafe
	compare VAR_TEMP_0, 1
	goto_if_eq MeteorFalls_ZinniaHouse_EventScript_BringRayquazaHere
	compare VAR_TEMP_0, 2
	goto_if_eq MeteorFalls_ZinniaHouse_EventScript_TeachDragonAscent
	compare VAR_TEMP_0, 3
	goto_if_eq MoveTutor_EventScript_DragonAscentTaught
	msgbox MeteorFalls_ZinniaHouse_Text_TeachDragonAscent, MSGBOX_DEFAULT
	closemessage
	special CheckRayquazaInParty
	compare VAR_RESULT, TRUE
	goto_if_eq MeteorFalls_ZinniaHouse_EventScript_TeachDragonAscent
	goto MeteorFalls_ZinniaHouse_EventScript_BringRayquazaHere
	end

MeteorFalls_ZinniaHouse_EventScript_WeAreSafe:
	msgbox MeteorFalls_ZinniaHouse_Text_WeAreSafe, MSGBOX_DEFAULT
	closemessage
	special CheckRayquazaInParty
	compare VAR_RESULT, TRUE
	goto_if_eq MeteorFalls_ZinniaHouse_EventScript_TeachDragonAscent2
	release
	end

MeteorFalls_ZinniaHouse_EventScript_BringRayquazaHere:
	msgbox MeteorFalls_ZinniaHouse_Text_BringRayquaza, MSGBOX_DEFAULT
	setvar VAR_TEMP_0, 1
	release
	end

MeteorFalls_ZinniaHouse_EventScript_TeachDragonAscent:
	delay 20
	msgbox MeteorFalls_ZinniaHouse_Text_ExplainDragonAscent, MSGBOX_DEFAULT
	closemessage
	setvar VAR_0x8005, TUTOR_MOVE_DRAGON_ASCENT
	call MoveTutor_EventScript_OpenPartyMenu
	compare VAR_RESULT, 0
	goto_if_eq MoveTutor_EventScript_DragonAscentDeclined
	goto MoveTutor_EventScript_DragonAscentTaught
	end

MoveTutor_EventScript_DragonAscentTaught::
	msgbox MoveTutor_Text_DragonAscentTaught, MSGBOX_DEFAULT
	setvar VAR_TEMP_0, 3
	release
	end

MoveTutor_EventScript_DragonAscentDeclined:
	msgbox MoveTutor_Text_DragonAscentDeclined, MSGBOX_DEFAULT
	setvar VAR_TEMP_0, 2
	release
	end

MeteorFalls_ZinniaHouse_EventScript_TeachDragonAscent2:
	delay 20
	msgbox MeteorFalls_ZinniaHouse_Text_ExplainDragonAscent2, MSGBOX_DEFAULT
	closemessage
	setvar VAR_0x8005, TUTOR_MOVE_DRAGON_ASCENT
	call MoveTutor_EventScript_OpenPartyMenu
	release
	end

MeteorFalls_ZinniaHouse_Text_WeAreSafe:
	.string "Zinnia: You're the hero from\n"
	.string "that saved us from meteor!\p"
	.string "I can freely teach your\n"
	.string "Rayquaza our tribe's move!$"

MeteorFalls_ZinniaHouse_Text_BringRayquaza:
	.string "Zinnia: You must challenge Rayquaza\n"
	.string "and bring him here.$"

MeteorFalls_ZinniaHouse_Text_TeachDragonAscent:
	.string "Zinnia: You're a time travel…\p"
	.string "…\p"
	.string "I feel the bless of the time\n"
	.string "guardian in you…\p"
	.string "…\p"
	.string "…\p"
	.string "A meteor is coming?\p"
	.string "…\p"
	.string "Hmm… There was a legend from the\n"
	.string "Draconid Tribe that this day\l"
	.string "would come.\p"
	.string "And only the legendary dragon\n"
	.string "from the Sky Pillar could save us.$"

MeteorFalls_ZinniaHouse_Text_ExplainDragonAscent:
	.string "Zinnia: Now let teach Dragon Ascent\n"
	.string "to Rayquaza.\p"
	.string "This secret move is being passed down\n"
	.string "to every descendent of Draconid tribe.\p"
	.string "Rayquaza can only achieve its true power\n"
	.string "with it!\p"
	.string "With this ultimate move, Rayquaza\n"
	.string "will be able to destroy the meteor.$"

MeteorFalls_ZinniaHouse_Text_ExplainDragonAscent2:
	.string "Zinnia: Now let teach Dragon Ascent\n"
	.string "to Rayquaza.\p"
	.string "This secret move is being passed down\n"
	.string "to every descendent of Draconid tribe.\p"
	.string "Rayquaza can only achieve its true power\n"
	.string "with it!$"

MoveTutor_Text_DragonAscentDeclined:
	.string "Zinnia: You should rush, we don't\n"
	.string "have much time to stop the meteor!$"

MoveTutor_Text_DragonAscentTaught:
	.string "Zinnia: Good! Now you should use\n"
	.string "Dragon Ascent to go to space.$"
