MossdeepCity_Bills_House_MapScripts::
	.byte 0

MossdeepCity_BillsHouse_EventScript_Bill::
	lockall
	faceplayer
	checkitem ITEM_ZYGARDE_CUBE, 1
	compare VAR_RESULT, FALSE
	goto_if_eq MossdeepCity_BillsHouse_EventScript_TryGiveZygardeCube
	getzygardescript
	compare VAR_0x8004, 7
	goto_if_eq General_EventScript_GiveZygardeCell
	compare VAR_0x8004, 8
	goto_if_eq General_EventScript_GiveZygardeCore
	compare VAR_0x8004, 1
	goto_if_eq General_EventScript_GiveZygarde10
	compare VAR_0x8004, 2
	goto_if_eq General_EventScript_TurnZygarde50
	compare VAR_0x8004, 3
	goto_if_eq General_EventScript_EnablePowerConstruct
	goto_if_set FLAG_ZYGARDE_MOVE_TUTOR_ENABLED, MossdeepCity_BillsHouse_EventScript_MoveTutor
	goto_if_set FLAG_COLLECTED_50_PERCENT, MossdeepCity_BillsHouse_EventScript_State1
	goto_if_set FLAG_COLLECTED_10_PERCENT, MossdeepCity_BillsHouse_EventScript_State2
	msgbox MossdeepCity_BillsHouse_Text_NotHaveZygardeYet, MSGBOX_DEFAULT
	releaseall
	end

MossdeepCity_BillsHouse_EventScript_State1:
	compare VAR_BILL_STATE, 6
	goto_if_ge MossdeepCity_BillsHouse_EventScript_State5
	msgbox MossdeepCity_BillsHouse_Text_Zygarde50, MSGBOX_DEFAULT
	setvar VAR_BILL_STATE, 6
	goto MossdeepCity_BillsHouse_EventScript_State5

MossdeepCity_BillsHouse_EventScript_State2:
	compare VAR_BILL_STATE, 5
	goto_if_ge MossdeepCity_BillsHouse_EventScript_State5
	msgbox MossdeepCity_BillsHouse_Text_Zygarde10, MSGBOX_DEFAULT
	setvar VAR_BILL_STATE, 5
MossdeepCity_BillsHouse_EventScript_State5:
	msgbox MossdeepCity_BillsHouse_Text_CollectMore, MSGBOX_DEFAULT
	releaseall
	end

MossdeepCity_BillsHouse_EventScript_MoveTutor:
	compare VAR_BILL_STATE, 7
	goto_if_ge MossdeepCity_BillsHouse_EventScript_State7
	msgbox MossdeepCity_BillsHouse_Text_ExplainZygardeSignatureMoves, MSGBOX_DEFAULT
	setvar VAR_BILL_STATE, 7
MossdeepCity_BillsHouse_EventScript_State7:
	message MossdeepCity_BillsHouse_Text_MoveTutor
	multichoice 19, 2, MULTI_ZYGARDE_MOVE_TUTOR, FALSE
	switch VAR_RESULT
	case 0, MossdeepCity_BillsHouse_EventScript_Teach_LandWrath
	case 1, MossdeepCity_BillsHouse_EventScript_Teach_ThousandArrows
	case 2, MossdeepCity_BillsHouse_EventScript_Teach_ThousandWaves
	case 3, MossdeepCity_BillsHouse_EventScript_Teach_CoreEnforcer
	case MULTI_B_PRESSED, MossdeepCity_BillsHouse_EventScript_ExitMoveTutor
	end

MossdeepCity_BillsHouse_EventScript_Teach_LandWrath:
	setvar VAR_0x8005, TUTOR_MOVE_LANDS_WRATH
	goto MossdeepCity_BillsHouse_EventScript_MoveTutorContinue

MossdeepCity_BillsHouse_EventScript_Teach_ThousandArrows:
	setvar VAR_0x8005, TUTOR_MOVE_THOUSAND_ARROWS
	goto MossdeepCity_BillsHouse_EventScript_MoveTutorContinue

MossdeepCity_BillsHouse_EventScript_Teach_ThousandWaves:
	setvar VAR_0x8005, TUTOR_MOVE_THOUSAND_WAVES
	goto MossdeepCity_BillsHouse_EventScript_MoveTutorContinue

MossdeepCity_BillsHouse_EventScript_Teach_CoreEnforcer:
	setvar VAR_0x8005, TUTOR_MOVE_CORE_ENFORCER
MossdeepCity_BillsHouse_EventScript_MoveTutorContinue:
	msgbox MossdeepCity_BillsHouse_Text_WhichMon, MSGBOX_DEFAULT
	call MoveTutor_EventScript_OpenPartyMenu
	compare VAR_RESULT, 0
	goto_if_eq MossdeepCity_BillsHouse_EventScript_ExitMoveTutor
	msgbox MossdeepCity_BillsHouse_MoveLearned, MSGBOX_DEFAULT
	releaseall
	end

MossdeepCity_BillsHouse_EventScript_ExitMoveTutor:
	msgbox MossdeepCity_BillsHouse_Text_ExitrMoveTutor, MSGBOX_DEFAULT
	releaseall
	end

MossdeepCity_BillsHouse_EventScript_TryGiveZygardeCube:
	setvar VAR_BILL_STATE, 2
	setflag FLAG_OLDALE_BILL_EVENT
	msgbox MossdeepCity_BillsHouse_Text_TryGiveZygardeCube, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq MossdeepCity_BillsHouse_EventScript_AgreeToCollect
	compare VAR_RESULT, NO
	goto_if_eq MossdeepCity_BillsHouse_EventScript_DeclineToCollect
	end

MossdeepCity_BillsHouse_EventScript_AgreeToCollect:
	msgbox MossdeepCity_BillsHouse_Text_BilltalkAgree, MSGBOX_DEFAULT
	giveitem ITEM_ZYGARDE_CUBE
	msgbox MossdeepCity_BillsHouse_Text_BilltalkExplain, MSGBOX_DEFAULT
	releaseall
	end

MossdeepCity_BillsHouse_EventScript_DeclineToCollect:
	msgbox MossdeepCity_BillsHouse_Text_BilltalkDecline, MSGBOX_DEFAULT
	releaseall
	end

MossdeepCity_BillsLab_EventScript_Machine::
	msgbox MossdeepCity_BillsLab_Text_SeriousLookingMachine, MSGBOX_SIGN
	end

MossdeepCity_BillsLab_Text_SeriousLookingMachine:
	.string "It's a serious-looking machine.\n"
	.string "Bill must use this for research.$"

MossdeepCity_BillsHouse_Text_NotHaveZygardeYet:
	.string "Bill: If you collect enough Cells\n"
	.string "and at least one Core, I think\l"
	.string "they can form a powerful Pokémon!$"

MossdeepCity_BillsHouse_MoveLearned:
	.string "Bill: Zygarde learned its!\n"
	.string "ultimate move!$"

MossdeepCity_BillsHouse_Text_WhichMon:
	.string "Which Pokémon should I teach?$"

MossdeepCity_BillsHouse_Text_ExitrMoveTutor:
	.string "Bill: Oh… Too bad!\n"
	.string "Zygarde can reach unimaginable power!$"

MossdeepCity_BillsHouse_Text_ExplainZygardeSignatureMoves:
	.string "Bill: After a long time of research,\n"
	.string "I discovered that Zygarde in this\l"
	.string "form can use four powerful\l"
	.string "signature moves!$"

MossdeepCity_BillsHouse_Text_MoveTutor:
	.string "Bill: Which signature move do you\n"
	.string "want to teach to Zygarde?$"

MossdeepCity_BillsHouse_Text_CollectMore:
	.string "Bill: Oh… I think there are much more\n"
	.string "to study about Zygarde Cells!\l"
	.string "Could you continue collecting them?$"

MossdeepCity_BillsHouse_Text_Zygarde50:
	.string "Bill: Oh… insteresting! You manage\n"
	.string "to collect enough Cores and Cells\l"
	.string "to stabilize Zygarde at 50% form!\p"
	.string "I knew you could do that!!$"

MossdeepCity_BillsHouse_Text_Zygarde10:
	.string "Bill: Oh… insteresting! You manage\n"
	.string "to collect enough Cores and Cells\l"
	.string "to stabilize Zygarde at 10% form!\p"
	.string "I knew you could do that!!$"

MossdeepCity_BillsHouse_Text_TryGiveZygardeCube:
	.string "Bill: It appears to have cells spreaded\n"
	.string "all over the Hoenn and they come to\l"
	.string "protect nature when it is threatened.\p"
	.string "Please, for my research I need to\n"
	.string "collect these Pokémon cells as much\l"
	.string "as possible, can you do that for me?$"

MossdeepCity_BillsHouse_Text_BilltalkAgree:
	.string "Bill: After all this adventure you've\n"
	.string "been through, do you still want to\l"
	.string "accept my quest? Haha\p"
	.string "Don't worry…\p"
	.string "Here, take this!$"

MossdeepCity_BillsHouse_Text_BilltalkExplain:
	.string "Bill: You can collect any Zygarde\n"
	.string "part and store in the Zygarde Cube\l"
	.string "now!$"

MossdeepCity_BillsHouse_Text_BilltalkDecline:
	.string "Bill: Oh… too bad…$"

