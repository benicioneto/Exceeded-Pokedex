.set LOCALID_MART_EMPLOYEE, 2
.set LOCALID_FOOTPRINTS_MAN, 3
.set LOCALID_RIVAL, 4
.set LOCALID_BILL, 6
.set LOCALID_CELL, 7
.set LOCALID_MAY, 8
.set LOCALID_BRENDAN, 9

OldaleTown_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, OldaleTown_OnTransition
	.byte 0

OldaleTown_OnTransition:
	call OldaleTown_EventScript_TryHideOrShowSpiritombWisps
	call Common_EventScript_SetupRivalGfxId
	setflag FLAG_VISITED_OLDALE_TOWN
	call_if_unset FLAG_ADVENTURE_STARTED, OldaleTown_EventScript_BlockWestEntrance
	call_if_unset FLAG_RECEIVED_POTION_OLDALE, OldaleTown_EventScript_MoveMartEmployee
	call_if_set FLAG_ADVENTURE_STARTED, OldaleTown_EventScript_SetOldaleState
	end

OldaleTown_EventScript_TryHideOrShowSpiritombWisps:
	gettimeofday
	compare VAR_0x8000, 2
	goto_if_eq OldaleTown_EventScript_TryShowWisps
	goto OldaleTown_EventScript_HideWisps
	end

OldaleTown_EventScript_TryShowWisps:
	goto_if_unset FLAG_RECEIVED_WISPS_17, OldaleTown_EventScript_ShowWisp
	return

OldaleTown_EventScript_ShowWisp:
	clearflag FLAG_HIDE_WISPS_17
	return

OldaleTown_EventScript_HideWisps:
	setflag FLAG_HIDE_WISPS_17
	return

@ This script seems pointless because nothing uses VAR_OLDALE_TOWN_STATE
OldaleTown_EventScript_SetOldaleState::
	setvar VAR_OLDALE_TOWN_STATE, 1
	return

OldaleTown_EventScript_BlockWestEntrance::
	setobjectxyperm LOCALID_FOOTPRINTS_MAN, 1, 11
	setobjectmovementtype LOCALID_FOOTPRINTS_MAN, MOVEMENT_TYPE_FACE_LEFT
	return

OldaleTown_EventScript_MoveMartEmployee::
	setobjectxyperm LOCALID_MART_EMPLOYEE, 13, 14
	setobjectmovementtype LOCALID_MART_EMPLOYEE, MOVEMENT_TYPE_FACE_DOWN
	return

OldaleTown_EventScript_CitySign::
	msgbox OldaleTown_Text_CitySign, MSGBOX_SIGN
	end

OldaleTown_EventScript_LagoonSign::
	msgbox OldaleTown_Text_LagoonSign, MSGBOX_SIGN
	end

OldaleTown_EventScript_Girl::
	msgbox OldaleTown_Text_SavingMyProgress, MSGBOX_NPC
	end

OldaleTown_EventScript_MartEmployee::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_POTION_OLDALE, OldaleTown_EventScript_ExplainPotion
	goto_if_set FLAG_TEMP_1, OldaleTown_EventScript_ExplainPotion
	setflag FLAG_TEMP_1
	playbgm MUS_FOLLOW_ME, FALSE
	msgbox OldaleTown_Text_IWorkAtPokemonMart, MSGBOX_DEFAULT
	closemessage
	switch VAR_FACING
	case DIR_SOUTH, OldaleTown_EventScript_GoToMartSouth
	case DIR_NORTH, OldaleTown_EventScript_GoToMartNorth
	case DIR_EAST, OldaleTown_EventScript_GoToMartEast
	end

OldaleTown_EventScript_GoToMartSouth::
	applymovement LOCALID_MART_EMPLOYEE, OldaleTown_Movement_EmployeeSouth
	applymovement OBJ_EVENT_ID_PLAYER, OldaleTown_Movement_PlayerSouth
	waitmovement 0
	goto OldaleTown_EventScript_ExplainPokemonMart
	end

OldaleTown_EventScript_GoToMartNorth::
	applymovement LOCALID_MART_EMPLOYEE, OldaleTown_Movement_EmployeeNorth
	applymovement OBJ_EVENT_ID_PLAYER, OldaleTown_Movement_PlayerNorth
	waitmovement 0
	goto OldaleTown_EventScript_ExplainPokemonMart
	end

OldaleTown_EventScript_GoToMartEast::
	applymovement OBJ_EVENT_ID_PLAYER, OldaleTown_Movement_PlayerEast
	applymovement LOCALID_MART_EMPLOYEE, OldaleTown_Movement_EmployeeEast
	waitmovement 0
	goto OldaleTown_EventScript_ExplainPokemonMart
	end

OldaleTown_EventScript_ExplainPokemonMart::
	msgbox OldaleTown_Text_ThisIsAPokemonMart, MSGBOX_DEFAULT
	giveitem ITEM_POTION
	compare VAR_RESULT, FALSE
	goto_if_eq OldaleTown_EventScript_BagIsFull
	msgbox OldaleTown_Text_PotionExplanation, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_POTION_OLDALE
	fadedefaultbgm
	release
	end

OldaleTown_EventScript_ExplainPotion::
	msgbox OldaleTown_Text_PotionExplanation, MSGBOX_DEFAULT
	release
	end

OldaleTown_EventScript_BagIsFull::
	msgbox gText_TooBadBagIsFull, MSGBOX_DEFAULT
	fadedefaultbgm
	release
	end

OldaleTown_Movement_EmployeeEast:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_in_place_fastest_down
	step_end

OldaleTown_Movement_EmployeeSouth:
	walk_left
	walk_up
	walk_up
	walk_right
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_in_place_fastest_down
	step_end

OldaleTown_Movement_EmployeeNorth:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_in_place_fastest_down
	step_end

OldaleTown_Movement_Unknown1:
	walk_up
	walk_up
	walk_right
	walk_right
	walk_right
	walk_right
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	delay_8
	walk_in_place_fastest_down
	step_end

OldaleTown_Movement_PlayerEast:
	walk_right
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

OldaleTown_Movement_PlayerSouth:
	delay_16
	delay_16
	delay_16
	delay_16
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

OldaleTown_Movement_PlayerNorth:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

OldaleTown_Movement_Unknown2:
	walk_left
	walk_up
	walk_up
	walk_right
	walk_right
	walk_right
	walk_right
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

OldaleTown_EventScript_FootprintsMan::
	lock
	faceplayer
	goto_if_set FLAG_ADVENTURE_STARTED, OldaleTown_EventScript_NotBlockingPath
	msgbox OldaleTown_Text_DiscoveredFootprints, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_FOOTPRINTS_MAN, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

OldaleTown_EventScript_BlockedPath::
	lockall
	applymovement OBJ_EVENT_ID_PLAYER, OldaleTown_Movement_PlayerStepBack
	applymovement LOCALID_FOOTPRINTS_MAN, OldaleTown_Movement_BackUp
	waitmovement 0
	msgbox OldaleTown_Text_WaitDontComeInHere, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_FOOTPRINTS_MAN, OldaleTown_Movement_ReturnToOriginalPosition
	waitmovement 0
	releaseall
	end

OldaleTown_EventScript_NotBlockingPath::
	msgbox OldaleTown_Text_FinishedSketchingFootprints, MSGBOX_DEFAULT
	release
	end

OldaleTown_EventScript_Rival::
	lockall
	applymovement LOCALID_RIVAL, Common_Movement_FacePlayer
	waitmovement 0
	setvar VAR_0x8009, 0
	goto OldaleTown_EventScript_ShowRivalMessage
	end

OldaleTown_EventScript_RivalTrigger1::
	lockall
	applymovement LOCALID_RIVAL, OldaleTown_Movement_RivalApproachPlayer1
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFastestRight
	waitmovement 0
	setvar VAR_0x8009, 1
	goto OldaleTown_EventScript_ShowRivalMessage
	end

OldaleTown_EventScript_RivalTrigger2::
	lockall
	applymovement LOCALID_RIVAL, OldaleTown_Movement_RivalApproachPlayer2
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFastestRight
	waitmovement 0
	setvar VAR_0x8009, 1
	goto OldaleTown_EventScript_ShowRivalMessage
	end

OldaleTown_EventScript_RivalTrigger3::
	lockall
	applymovement LOCALID_RIVAL, OldaleTown_Movement_RivalApproachPlayer3
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFastestRight
	waitmovement 0
	setvar VAR_0x8009, 1
	goto OldaleTown_EventScript_ShowRivalMessage
	end

OldaleTown_EventScript_ShowRivalMessage::
	checkplayergender
	compare VAR_RESULT, MALE
	goto_if_eq OldaleTown_EventScript_ShowMayMessage
	compare VAR_RESULT, FEMALE
	goto_if_eq OldaleTown_EventScript_ShowBrendanMessage
	end

OldaleTown_EventScript_ShowMayMessage::
	msgbox OldaleTown_Text_MayLetsGoBack, MSGBOX_DEFAULT
	goto OldaleTown_EventScript_RivalFinish
	end

OldaleTown_EventScript_ShowBrendanMessage::
	msgbox OldaleTown_Text_BrendanLetsGoBack, MSGBOX_DEFAULT
	goto OldaleTown_EventScript_RivalFinish
	end

OldaleTown_EventScript_RivalFinish::
	closemessage
	compare VAR_0x8009, 0
	call_if_eq OldaleTown_EventScript_DoExitMovement1
	compare VAR_0x8009, 1
	call_if_eq OldaleTown_EventScript_DoExitMovement2
	applymovement LOCALID_RIVAL, OldaleTown_Movement_RivalExit
	waitmovement 0
	removeobject LOCALID_RIVAL
	setvar VAR_OLDALE_RIVAL_STATE, 2
	setflag FLAG_HIDE_OLDALE_TOWN_RIVAL
	releaseall
	end

OldaleTown_EventScript_DoExitMovement1::
	compare VAR_FACING, DIR_SOUTH
	goto_if_ne OldaleTown_EventScript_DoExitMovement2
	applymovement LOCALID_RIVAL, OldaleTown_Movement_RivalExit
	waitmovement 0
	return

OldaleTown_EventScript_DoExitMovement2::
	applymovement OBJ_EVENT_ID_PLAYER, OldaleTown_Movement_WatchRivalExit
	applymovement LOCALID_RIVAL, OldaleTown_Movement_RivalExit
	waitmovement 0
	return

OldaleTown_Movement_RivalApproachPlayer1:
	walk_left
	walk_left
	step_end

OldaleTown_Movement_RivalApproachPlayer2:
	walk_left
	step_end

OldaleTown_Movement_RivalApproachPlayer3:
	face_left
	step_end

OldaleTown_Movement_RivalExit:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

OldaleTown_Movement_WatchRivalExit:
	delay_8
	delay_4
	walk_in_place_fastest_down
	step_end

OldaleTown_Movement_PlayerStepBack:
	delay_8
	walk_right
	step_end

OldaleTown_Movement_BackUp:
	walk_fast_up
	walk_in_place_fastest_left
	lock_facing_direction
	walk_right
	unlock_facing_direction
	step_end

OldaleTown_Movement_ReturnToOriginalPosition:
	walk_down
	walk_left
	step_end

OldaleTown_Text_SavingMyProgress:
	.string "I want to take a rest, so I'm saving my\n"
	.string "progress.$"

OldaleTown_Text_IWorkAtPokemonMart:
	.string "Hi!\n"
	.string "I work at a Pokémon Mart.\p"
	.string "Can I get you to come with me?$"

OldaleTown_Text_ThisIsAPokemonMart:
	.string "This is a Pokémon Mart.\n"
	.string "Just look for our blue roof.\p"
	.string "We sell a variety of goods including\n"
	.string "Poké Balls for catching Pokémon.\p"
	.string "Here, I'd like you to have this as\n"
	.string "a promotional item.$"

OldaleTown_Text_PotionExplanation:
	.string "A Potion can be used anytime, so it's\n"
	.string "even more useful than a Pokémon Center\l"
	.string "in certain situations.$"

OldaleTown_Text_WaitDontComeInHere:
	.string "Aaaaah! Wait!\n"
	.string "Please don't come in here.\p"
	.string "I just discovered the footprints of\n"
	.string "a rare Pokémon!\p"
	.string "Wait until I finish sketching\n"
	.string "them, okay?$"

OldaleTown_Text_DiscoveredFootprints:
	.string "I just discovered the footprints of\n"
	.string "a rare Pokémon!\p"
	.string "Wait until I finish sketching\n"
	.string "them, okay?$"

OldaleTown_Text_FinishedSketchingFootprints:
	.string "I finished sketching the footprints of\n"
	.string "a rare Pokémon.\p"
	.string "But it turns out they were only my\n"
	.string "own footprints…$"

OldaleTown_Text_MayLetsGoBack:
	.string "{RIVAL}: {PLAYER}{KUN}!\n"
	.string "Over here!\l"
	.string "Let's hurry home!$"

OldaleTown_Text_BrendanLetsGoBack:
	.string "{RIVAL}: I'm heading back to\n"
	.string "Prof. Birch's Lab now.\l"
	.string "{PLAYER}, you should hustle back, too.$"

OldaleTown_Text_CitySign:
	.string "Oldale Town\n"
	.string "“Where things start off scarce.”$"

OldaleTown_Text_LagoonSign:
	.string "Lagoon of Fury$"

OldaleTown_EventScript_BillTrigger1:: 
	lockall
	applymovement LOCALID_BILL, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_BILL, Common_Movement_FaceLeft
	applymovement LOCALID_BRENDAN, Common_Movement_FaceDown
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceRight
	waitmovement 0
	setvar VAR_BILL_STATE, 1
	goto OldaleTown_EventScript_BillMain
	end

OldaleTown_EventScript_BillTrigger3:: 
	lockall
	applymovement LOCALID_BILL, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_BILL, Common_Movement_FaceRight
	applymovement LOCALID_MAY, Common_Movement_FaceDown
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceLeft
	waitmovement 0
	setvar VAR_BILL_STATE, 3
	goto OldaleTown_EventScript_BillMain
	end

OldaleTown_EventScript_BillTrigger4:: 
	lockall
	applymovement LOCALID_BILL, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_BILL, Common_Movement_FaceRight
	waitmovement 0
	delay 40
	applymovement OBJ_EVENT_ID_PLAYER, Movement_Walk_Left
	waitmovement 0
	delay 16
	applymovement LOCALID_MAY, Common_Movement_FaceDown
	waitmovement 0
	setvar VAR_BILL_STATE, 4
	goto OldaleTown_EventScript_BillMain
	end

Movement_Walk_Left:
	walk_left
	step_end

OldaleTown_EventScript_Bill::
	lockall
	faceplayer
	setvar VAR_BILL_STATE, 2
	applymovement LOCALID_BILL, Common_Movement_ExclamationMark
	applymovement LOCALID_BRENDAN, Common_Movement_FaceDown
	applymovement LOCALID_MAY, Common_Movement_FaceDown
	waitmovement 0
OldaleTown_EventScript_BillMain:
	msgbox OldaleTown_Text_Billtalk, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_BILL Common_Movement_FaceUp
	waitmovement 0
	delay 30
	removeobject LOCALID_CELL
	compare VAR_BILL_STATE, 1
	call_if_eq EventScript_Bill_Look_Left
	compare VAR_BILL_STATE, 2
	call_if_eq EventScript_Bill_Look_Down
	compare VAR_BILL_STATE, 3
	call_if_eq EventScript_Bill_Look_Right
	compare VAR_BILL_STATE, 4
	call_if_eq EventScript_Bill_Look_Right
	delay 30
	showmonpic SPECIES_ZYGARDE_CELL, 1, 4
	msgbox OldaleTown_Text_BilltalkAskHelp, MSGBOX_YESNO
	hidemonpic
	compare VAR_RESULT, YES
	goto_if_eq OldaleTown_Bill_EventScript_AgreeToCollect
	compare VAR_RESULT, NO
	goto_if_eq OldaleTown_Bill_EventScript_DeclineToCollect
	end

EventScript_Bill_Look_Left:
	applymovement LOCALID_BILL Common_Movement_FaceLeft
	waitmovement 0
	return

EventScript_Bill_Look_Down:
	applymovement LOCALID_BILL Common_Movement_FaceDown
	waitmovement 0
	return

EventScript_Bill_Look_Right:
	applymovement LOCALID_BILL Common_Movement_FaceRight
	waitmovement 0
	return

OldaleTown_Text_Billtalk:
	.string "I'm Bill! I'm a Pokémon\n"
	.string "Researcher from Kanto!\p"
	.string "I'm here in Hoenn to research climate\n"
	.string "change and its impact on Pokémon!\l"
	.string "And this is a Pokémon that I'm\l"
	.string "studying!$"

OldaleTown_Text_BilltalkAskHelp:
	.string "Bill: It appears to have cells spreaded\n"
	.string "all over the Hoenn and they come to\l"
	.string "protect nature when it is threatened.\p"
	.string "Please, for my research I need to\n"
	.string "collect these Pokémon cells as much\l"
	.string "as possible, can you do that for me?$"

OldaleTown_Bill_EventScript_AgreeToCollect:
	msgbox OldaleTown_Text_BilltalkAgree, MSGBOX_DEFAULT
	giveitem ITEM_ZYGARDE_CUBE
	msgbox OldaleTown_Text_BilltalkExplain, MSGBOX_DEFAULT
	goto OldaleTown_EventScript_FlyAway
	end

OldaleTown_Bill_EventScript_DeclineToCollect:
	msgbox OldaleTown_Text_BilltalkDecline, MSGBOX_DEFAULT
	goto OldaleTown_EventScript_FlyAway
	end

OldaleTown_EventScript_FlyAway:
	closemessage
	applymovement LOCALID_BILL, Common_Movement_WalkInPlaceFastestDown
	waitmovement 0
	delay 50
	setfieldeffectarg 0, 1
	dofieldeffect FLDEFF_NPCFLY_OUT
	delay 15
	removeobject LOCALID_BILL
	waitfieldeffect FLDEFF_NPCFLY_OUT
	savebgm MUS_DUMMY
	fadedefaultbgm
	delay 40
	setflag FLAG_OLDALE_BILL_EVENT
	compare VAR_BILL_STATE, 1
	call_if_eq EventScript_Brothers_Event1
	compare VAR_BILL_STATE, 2
	call_if_eq EventScript_Brothers_Event2
	compare VAR_BILL_STATE, 3
	call_if_eq EventScript_Brothers_Event3
	compare VAR_BILL_STATE, 4
	call_if_eq EventScript_Brothers_Event4
	end

EventScript_Brothers_Event1:
	applymovement LOCALID_BRENDAN, Common_Movement_FaceDown
	applymovement LOCALID_MAY, Movement_Approach1
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceRight
	waitmovement 0
	msgbox OldaleTown_Text_MayTalk, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceUp
	waitmovement 0
	applymovement LOCALID_BRENDAN, Common_Movement_WalkInPlaceFastestDown
	waitmovement 0
	msgbox OldaleTown_Text_BrendanTalk, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_BRENDAN, Movement_Exit_Brendan1
	applymovement LOCALID_MAY, Movement_Exit_May1
	waitmovement 0
	removeobject LOCALID_MAY
	removeobject LOCALID_BRENDAN
	releaseall
	end

Movement_Approach1:
	walk_left
	walk_down
	face_left
	step_end

EventScript_Brothers_Event2:
	applymovement LOCALID_MAY, Movement_Approach2
	applymovement LOCALID_BRENDAN, Movement_Approach3
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceUp
	waitmovement 0
	msgbox OldaleTown_Text_MayTalk, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_BRENDAN, Common_Movement_WalkInPlaceFastestRight
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceLeft
	waitmovement 0
	msgbox OldaleTown_Text_BrendanTalk, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_BRENDAN, Movement_Exit_Brendan2
	applymovement LOCALID_MAY, Movement_Exit_May2
	waitmovement 0
	removeobject LOCALID_MAY
	removeobject LOCALID_BRENDAN
	releaseall
	end

Movement_Approach2:
	walk_left
	walk_down
	step_end

Movement_Approach3:
	walk_down
	walk_down
	face_right
	step_end

Movement_Exit_May2:
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

Movement_Exit_Brendan2:
	delay_16
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

EventScript_Brothers_Event3:
EventScript_Brothers_Event4:
	applymovement LOCALID_BRENDAN, Movement_Approach4
	applymovement LOCALID_MAY, Common_Movement_FaceDown
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceUp
	waitmovement 0
	msgbox OldaleTown_Text_MayTalk, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_BRENDAN, Common_Movement_WalkInPlaceFastestRight
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceLeft
	waitmovement 0
	msgbox OldaleTown_Text_BrendanTalk, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_BRENDAN, Movement_Exit_Brendan3
	applymovement LOCALID_MAY, Movement_Exit_May3
	waitmovement 0
	removeobject LOCALID_MAY
	removeobject LOCALID_BRENDAN
	releaseall
	end

Movement_Exit_May3:
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

Movement_Exit_Brendan3:
	delay_16
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

Movement_Approach4:
	walk_right
	walk_down
	face_right
	step_end

Movement_Exit_Brendan1:
	walk_right
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

Movement_Exit_May1:
	delay_16
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

OldaleTown_Text_BrendanTalk:
	.string "Brendan: I cannot waste my time\n"
	.string "collecting these cells…\p"
	.string "I'm going to be the Champion of\n"
	.string "Hoenn to make my Dad proud!\p"
	.string "Oh… If you are searching for\n"
	.string "{RIVAL}, just go straight up!\p"
	.string "Come, May! Let keep going!$"

OldaleTown_Text_MayTalk:
	.string "May: Oh… Our first quest as\n"
	.string "Pokémon Trainer!\p"
	.string "I hope I could travel around\n"
	.string "all Hoenn to help him!$"

OldaleTown_Text_BilltalkAgree:
	.string "Bill: Thanks! Here, you will need this!$"

OldaleTown_Text_BilltalkExplain:
	.string "Bill: My lab is in Mossdeep City!\n"
	.string "You can give the cells you find\l"
	.string "to me there!\p"
	.string "I'm leaving this to you guys!$"

OldaleTown_Text_BilltalkDecline:
	.string "Bill: Oh… too bad…\n"
	.string "My lab is in Mossdeep City if you\l"
	.string "change your mind!$"
