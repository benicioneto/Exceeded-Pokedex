.set LOCALID_JUDGE, 1
.set LOCALID_LITTLEBOY, 2
.set LOCALID_FATMAN, 4
.set LOCALID_OLDMAN, 5
.set LOCALID_BLACK_BELT, 6
.set LOCALID_TEPIG, 7

DewfordTown_Dojo_MapScripts::
	.byte 0

DewfordTown_Dojo_EventScript_OldMan::
	msgbox DewfordTown_Dojo_Text_OldMan, MSGBOX_NPC
	end

DewfordTown_Dojo_EventScript_LittleBoy::
	msgbox DewfordTown_Dojo_Text_LittleBoy, MSGBOX_NPC
	end

DewfordTown_Dojo_EventScript_LittleGirl::
	msgbox DewfordTown_Dojo_Text_LittleGirl, MSGBOX_NPC
	end

DewfordTown_Dojo_EventScript_Fatman::
	msgbox DewfordTown_Dojo_Text_Fatman, MSGBOX_NPC
	end

DewfordTown_Dojo_EventScript_BlackBelt::
	msgbox DewfordTown_Dojo_Text_BlackBelt, MSGBOX_NPC
	end

DewfordTown_Dojo_EventScript_TEPIG::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_TEPIG, 0
	msgbox DewfordTown_Dojo_Text_TEPIG, MSGBOX_DEFAULT
	waitmoncry
	release
	end

DewfordTown_Dojo_Text_TEPIG:
	.string "Te-pig!$"

DewfordTown_Dojo_Text_OldMan:
	.string "If you want to train your body and\n"
	.string "mind, you came to the right place.\p"
	.string "But if you want to train your\n"
	.string "Pokémon, Trainer Hill might be."
	.string "better.$"

DewfordTown_Dojo_Text_LittleBoy:
	.string "I can't wait to see the next fight\n"
	.string "between Brawly and Bruno this weekend!$"

DewfordTown_Dojo_Text_LittleGirl:
	.string "Everyone in this tiny island comes\n"
	.string "here to train.\p"
	.string "Brawly and Bruno woouldn't be elite\n"
	.string "Trainers if they didn't train their\l"
	.string "body and mind here!$"

DewfordTown_Dojo_Text_Fatman:
	.string "I'm one of the best fighters\n"
	.string "here!\p"
	.string "Are you laughing on me?$"

DewfordTown_Dojo_Text_BlackBelt:
	.string "Bruno is undefeated here!\n"
	.string "Not even Brawly could win\l"
	.string "against him!\p"
	.string "He comes here on the weekend\n"
	.string "to train with Brawly.$"

@@@@@ Dojo Fight @@@@@

DewfordTown_Dojo_EventScript_Judge::
	lock
	faceplayer
	msgbox DewfordTown_Dojo_Text_AskForFight, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq DewfordTown_Dojo_EventScript_AcceptedFight
	msgbox DewfordTown_Dojo_Text_DeclinedFight, MSGBOX_DEFAULT
	applymovement LOCALID_JUDGE, Common_Movement_FaceDown
	waitmovement 0
	release
	end

DewfordTown_Dojo_EventScript_AcceptedFight:
	playbgm MUS_VS_TRAINER, FALSE
	msgbox DewfordTown_Dojo_Text_GoToPlace, MSGBOX_DEFAULT
	waitmessage
	closemessage
    switch VAR_DEWFORD_DOJO_STATE
    case 0, DewfordTown_Dojo_EventScript_LittleBoyFight
    case 1, DewfordTown_Dojo_EventScript_FatManFight
    case 2, DewfordTown_Dojo_EventScript_BlackBeltFight
    case 3, DewfordTown_Dojo_EventScript_OldManFight
	goto DewfordTown_Dojo_EventScript_OldManFight

@ VAR_TEMP_0 = number of rounds
@ VAR_TEMP_1 = opponent local id
@ VAR_TEMP_2 = Player's HP
@ VAR_TEMP_3 = Opponent's HP
@ VAR_TEMP_4 = Player's moveset
@ VAR_TEMP_5 = Player's move
@ VAR_TEMP_6 = Opponent's move
@ VAR_TEMP_7 = Player's special move gauge
@ VAR_TEMP_8 = Opponent's special move gauge
@ VAR_TEMP_9 = Moves Result
@ VAR_TEMP_A = Player missed the Opponent
@ VAR_TEMP_B = Opponent missed the Player
@ VAR_TEMP_C = Battle State
@ VAR_TEMP_D =
@ VAR_TEMP_E =
@ VAR_TEMP_F =
DewfordTown_Dojo_EventScript_LittleBoyFight:
	setvar VAR_TEMP_0, 1
	setvar VAR_TEMP_1, LOCALID_LITTLEBOY
	callfunc ScrFunc_SetPlayerHP
	setvar VAR_TEMP_3, 6
	@ VAR_TEMP_4 player's moveset is set after
	@ VAR_TEMP_5 player's move is set after
	@ VAR_TEMP_6 opponent's move is set after
	setvar VAR_TEMP_7, 0
	setvar VAR_TEMP_8, 0
	goto DewfordTown_Dojo_EventScript_BeginFight

DewfordTown_Dojo_EventScript_FatManFight:
	setvar VAR_TEMP_0, 1
	setvar VAR_TEMP_1, LOCALID_FATMAN
	callfunc ScrFunc_SetPlayerHP
	setvar VAR_TEMP_3, 16
	@ VAR_TEMP_4 player's moveset is set after
	@ VAR_TEMP_5 player's move is set after
	@ VAR_TEMP_6 opponent's move is set after
	setvar VAR_TEMP_7, 0
	setvar VAR_TEMP_8, 0
	goto DewfordTown_Dojo_EventScript_BeginFight

DewfordTown_Dojo_EventScript_BlackBeltFight:
	setvar VAR_TEMP_0, 1
	setvar VAR_TEMP_1, LOCALID_BLACK_BELT
	callfunc ScrFunc_SetPlayerHP
	setvar VAR_TEMP_3, 13
	@ VAR_TEMP_4 player's moveset is set after
	@ VAR_TEMP_5 player's move is set after
	@ VAR_TEMP_6 opponent's move is set after
	setvar VAR_TEMP_7, 0
	setvar VAR_TEMP_8, 0
	goto DewfordTown_Dojo_EventScript_BeginFight

DewfordTown_Dojo_EventScript_OldManFight:
	setvar VAR_TEMP_0, 1
	setvar VAR_TEMP_1, LOCALID_OLDMAN
	callfunc ScrFunc_SetPlayerHP
	setvar VAR_TEMP_3, 10
	@ VAR_TEMP_4 player's moveset is set after
	@ VAR_TEMP_5 player's move is set after
	@ VAR_TEMP_6 opponent's move is set after
	setvar VAR_TEMP_7, 0
	setvar VAR_TEMP_8, 5
	goto DewfordTown_Dojo_EventScript_BeginFight

DewfordTown_Dojo_EventScript_BeginFight:
	call DewfordTown_Dojo_EventScript_PlaceFightersInPlaceForFight
DewfordTown_Dojo_EventScript_BattleContinues:
	call DewfordTown_Dojo_EventScript_PreparePlayerMoves
	call DewfordTown_Dojo_EventScript_SelectOpponentMoveAndCalculations
	call DewfordTown_Dojo_EventScript_PlayerMovement
	call DewfordTown_Dojo_EventScript_OpponentMovement
	call DewfordTown_Dojo_EventScript_PlayerCounter
	callfunc ScrFunc_WhatNext
	compare VAR_TEMP_C, 0
    goto_if_eq DewfordTown_Dojo_EventScript_BattleContinues
	compare VAR_TEMP_C, 1
    goto_if_eq DewfordTown_Dojo_EventScript_OpponentWon
	compare VAR_TEMP_C, 2
    goto_if_eq DewfordTown_Dojo_EventScript_PlayerWon
	release
	end

DewfordTown_Dojo_EventScript_OpponentWon:
	playbgm MUS_B_ARENA, FALSE
    msgbox DewfordTown_Dojo_Text_TooBad, MSGBOX_DEFAULT
    closemessage
	call DewfordTown_Dojo_EventScript_ExitArena
	release
	end

DewfordTown_Dojo_EventScript_PlayerWon:
	playbgm MUS_B_ARENA, FALSE
    msgbox DewfordTown_Dojo_Text_Congratulations, MSGBOX_DEFAULT
    closemessage
	call DewfordTown_Dojo_EventScript_ExitArena
	addvar VAR_DEWFORD_DOJO_STATE, 1
	compare VAR_DEWFORD_DOJO_STATE, 1
    goto_if_eq DewfordTown_Dojo_EventScript_GiveTepig	@ Little Kid
	compare VAR_DEWFORD_DOJO_STATE, 2
    goto_if_eq DewfordTown_Dojo_EventScript_GiveRareCandy @ Fat man
	compare VAR_DEWFORD_DOJO_STATE, 3
    goto_if_eq DewfordTown_Dojo_EventScript_GivePunchingGloves @ Black Belt / Judge
	compare VAR_DEWFORD_DOJO_STATE, 4
    goto_if_eq DewfordTown_Dojo_EventScript_GiveKubfu @ Old Man 
	goto DewfordTown_Dojo_EventScript_GiveNothing

DewfordTown_Dojo_EventScript_GiveNothing:
    msgbox DewfordTown_Dojo_Text_PlayerWonRepeat, MSGBOX_DEFAULT
	release
	end

DewfordTown_Dojo_EventScript_GiveRareCandy:
    msgbox DewfordTown_Dojo_Text_PlayerWonFatMan, MSGBOX_DEFAULT
    closemessage
	giveitem ITEM_RARE_CANDY
	release
	end

DewfordTown_Dojo_EventScript_GivePunchingGloves:
    msgbox DewfordTown_Dojo_Text_HereTakeYourPrize, MSGBOX_DEFAULT
    closemessage
	giveitem ITEM_PUNCHING_GLOVE
	release
	end

DewfordTown_Dojo_EventScript_GiveKubfu:
    msgbox DewfordTown_Dojo_Text_HereTakeYourPrize, MSGBOX_DEFAULT
    closemessage
	givemon SPECIES_KUBFU, 12, ITEM_BLACK_BELT
	bufferspeciesname 0, SPECIES_KUBFU
	setvar VAR_TEMP_1, SPECIES_KUBFU
	goto DewfordTown_Dojo_EventScript_GiveMon

DewfordTown_Dojo_EventScript_GiveTepig:
    msgbox DewfordTown_Dojo_Text_PlayerWonLittleBoy, MSGBOX_DEFAULT
    closemessage
	removeobject LOCALID_TEPIG
	setflag FLAG_DEWFORD_DOJO_TEPIG
	givemon SPECIES_TEPIG, 8, ITEM_CHARCOAL
	bufferspeciesname 0, SPECIES_TEPIG
	setvar VAR_TEMP_1, SPECIES_TEPIG
	goto DewfordTown_Dojo_EventScript_GiveMon

DewfordTown_Dojo_EventScript_GiveMon:
	compare VAR_RESULT, 0
	goto_if_eq DewfordTown_Dojo_EventScript_SendKubfuToParty
	compare VAR_RESULT, 1
	goto_if_eq DewfordTown_Dojo_EventScript_SendKubfuToPC
	goto Common_EventScript_NoMoreRoomForPokemon

DewfordTown_Dojo_EventScript_SendKubfuToParty:
	call DewfordTown_Dojo_EventScript_ReceivedKubfu
    msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
    compare VAR_RESULT, 0
    goto_if_eq DewfordTown_Dojo_EventScript_KubfuEnd
	call Common_EventScript_GetGiftMonPartySlot
	call Common_EventScript_NameReceivedPartyMon
	goto DewfordTown_Dojo_EventScript_KubfuEnd

DewfordTown_Dojo_EventScript_SendKubfuToPC:
	call DewfordTown_Dojo_EventScript_ReceivedKubfu
    msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
    compare VAR_RESULT, 0
    goto_if_eq DewfordTown_Dojo_EventScript_KubfuTransferredToPC
    call Common_EventScript_NameReceivedBoxMon
	goto DewfordTown_Dojo_EventScript_KubfuTransferredToPC
	end

DewfordTown_Dojo_EventScript_KubfuTransferredToPC:
    call Common_EventScript_TransferredToPC
DewfordTown_Dojo_EventScript_KubfuEnd:
    release
    end

DewfordTown_Dojo_EventScript_ReceivedKubfu:
	playfanfare MUS_OBTAIN_ITEM
	message DewfordTown_Dojo_Text_ReceivedKubfu
	waitmessage
	waitfanfare
	return

DewfordTown_Dojo_EventScript_ExitArena:
    fadescreen FADE_TO_BLACK
	@ Player (need to applymovement because of camera)
	applymovement OBJ_EVENT_ID_PLAYER, DewfordTown_Dojo_Movement_PlayerExitArena
	waitmovement 0
	@ LittleBoy
    setobjectxy LOCALID_LITTLEBOY, 15, 9
	applymovement LOCALID_LITTLEBOY, Common_Movement_FaceLeft
	waitmovement 0
	@ Judge
    setobjectxy LOCALID_JUDGE, 11, 14
	applymovement LOCALID_JUDGE, Common_Movement_FaceDown
	waitmovement 0
	@ Fatman
    setobjectxy LOCALID_FATMAN, 4, 11
	applymovement LOCALID_FATMAN, Common_Movement_FaceRight
	waitmovement 0
	@ Black Belt
    setobjectxy LOCALID_BLACK_BELT, 8, 7
	applymovement LOCALID_BLACK_BELT, Common_Movement_FaceDown
	waitmovement 0
	@ OldMan
    setobjectxy LOCALID_OLDMAN, 2, 17
	waitmovement 0
    fadescreen FADE_FROM_BLACK
	delay 6
	return

DewfordTown_Dojo_EventScript_PlaceFightersInPlaceForFight:
    fadescreen FADE_TO_BLACK
	@ Player (need to applymovement because of camera)
	applymovement OBJ_EVENT_ID_PLAYER, DewfordTown_Dojo_Movement_PlayerGetsInPlace
	waitmovement 0
	@ Opponent
    setobjectxy VAR_TEMP_1, 11, 11
	applymovement VAR_TEMP_1, Common_Movement_FaceLeft
	waitmovement 0
	@ Judge
    setobjectxy LOCALID_JUDGE, 10, 13
	applymovement LOCALID_JUDGE, Common_Movement_FaceUp
	waitmovement 0
    fadescreen FADE_FROM_BLACK
	delay 6
	msgbox DewfordTown_Dojo_Text_Round1Fight, MSGBOX_DEFAULT
	waitmessage
	return

DewfordTown_Dojo_EventScript_PreparePlayerMoves:
	callfunc ScrFunc_ShowBattlersHP
    msgbox DewfordTown_Dojo_Text_WhichMove, MSGBOX_DEFAULT
    closemessage
	callfunc ScrFunc_PreparePlayerMoves @store moves name in gStringVars, choice opponent move, and handles variables
    compare VAR_TEMP_4, 0
    call_if_eq DewfordTown_Dojo_EventScript_Option1ForMoves
    compare VAR_TEMP_4, 1
    call_if_eq DewfordTown_Dojo_EventScript_Option2ForMoves
    compare VAR_TEMP_4, 2
    call_if_eq DewfordTown_Dojo_EventScript_Option3ForMoves
    compare VAR_TEMP_4, 3
    call_if_eq DewfordTown_Dojo_EventScript_Option4ForMoves
	return

DewfordTown_Dojo_EventScript_SelectOpponentMoveAndCalculations:
	callfunc ScrFunc_PrepareOpponentMove
	callfunc ScrFunc_BattleCalculations
	return

DewfordTown_Dojo_EventScript_PlayerMovement:
	callfunc ScrFunc_SetPlayerMoveInString
	compare VAR_TEMP_5, 0
    call_if_eq DewfordTown_Dojo_EventScript_PlayerUsedPunch
	compare VAR_TEMP_5, 1
    call_if_eq DewfordTown_Dojo_EventScript_PlayerUsedKick
	compare VAR_TEMP_5, 5
    call_if_eq DewfordTown_Dojo_EventScript_PlayerUsedSuperPunch
	compare VAR_TEMP_5, 6
    call_if_eq DewfordTown_Dojo_EventScript_PlayerUsedSuperKick
	compare VAR_TEMP_5, 8
    call_if_eq DewfordTown_Dojo_EventScript_PlayerUsedOnePunch
	return

DewfordTown_Dojo_EventScript_PlayerCounter:
	callfunc ScrFunc_SetPlayerMoveInString
	compare VAR_TEMP_5, 4
    call_if_eq DewfordTown_Dojo_EventScript_PlayerUsedCounter
	return

DewfordTown_Dojo_EventScript_OpponentMovement:
	callfunc ScrFunc_SetOpponentMoveInString
	compare VAR_TEMP_6, 0
    call_if_eq DewfordTown_Dojo_EventScript_OpponentUsedPunch
	compare VAR_TEMP_6, 1
    call_if_eq DewfordTown_Dojo_EventScript_OpponentUsedKick
	compare VAR_TEMP_6, 4
    call_if_eq DewfordTown_Dojo_EventScript_OpponentUsedCounter
	compare VAR_TEMP_6, 5
    call_if_eq DewfordTown_Dojo_EventScript_OpponentUsedSuperPunch
	compare VAR_TEMP_6, 6
    call_if_eq DewfordTown_Dojo_EventScript_OpponentUsedSuperKick
	compare VAR_TEMP_6, 8
    call_if_eq DewfordTown_Dojo_EventScript_OpponentUsedOnePunch
	compare VAR_TEMP_6, 9
    call_if_eq DewfordTown_Dojo_EventScript_OpponentUsedSlap
	compare VAR_TEMP_6, 10
    call_if_eq DewfordTown_Dojo_EventScript_OpponentUsedBelly
	return

DewfordTown_Dojo_EventScript_PlayerUsedPunch:
DewfordTown_Dojo_EventScript_PlayerUsedKick:
DewfordTown_Dojo_EventScript_PlayerUsedCounter:
DewfordTown_Dojo_EventScript_PlayerUsedSuperPunch:
DewfordTown_Dojo_EventScript_PlayerUsedSuperKick:
DewfordTown_Dojo_EventScript_PlayerUsedOnePunch:
	callfunc ScrFunc_SetPlayerMoveInString
    msgbox DewfordTown_Dojo_Text_PlayerUsed, MSGBOX_DEFAULT
	waitmessage
    closemessage
	compare VAR_TEMP_A, 1 @Player missed
	call_if_eq DewfordTown_Dojo_EventScript_OpponentDodge
	applymovement OBJ_EVENT_ID_PLAYER, DewfordTown_Dojo_Movement_PlayerPunch
	waitmovement 0
	playse SE_M_MEGA_KICK2
	applymovement OBJ_EVENT_ID_PLAYER, DewfordTown_Dojo_Movement_PlayerReturn
	waitmovement 0
	callfunc ScrFunc_OpponentWasDefeated
	compare VAR_TEMP_C, 1
    goto_if_eq DewfordTown_Dojo_EventScript_PlayerWon
	compare VAR_TEMP_A, 1 @Player missed
	goto_if_eq DewfordTown_Dojo_EventScript_ButItMissed
	compare VAR_TEMP_6, 3 @ DOJO_GUARD
	goto_if_eq DewfordTown_Dojo_EventScript_ButItGuarded
	compare VAR_TEMP_6, 7 @ DOJO_SUPER_GUARD
	goto_if_eq DewfordTown_Dojo_EventScript_ButItSuperGuarded
	return

DewfordTown_Dojo_EventScript_OpponentUsedPunch:
DewfordTown_Dojo_EventScript_OpponentUsedKick:
DewfordTown_Dojo_EventScript_OpponentUsedCounter:
DewfordTown_Dojo_EventScript_OpponentUsedSuperPunch:
DewfordTown_Dojo_EventScript_OpponentUsedSuperKick:
DewfordTown_Dojo_EventScript_OpponentUsedOnePunch:
DewfordTown_Dojo_EventScript_OpponentUsedSlap:
DewfordTown_Dojo_EventScript_OpponentUsedBelly:
	callfunc ScrFunc_SetOpponentMoveInString
    msgbox DewfordTown_Dojo_Text_OpponentUsed, MSGBOX_DEFAULT
	waitmessage
    closemessage
	compare VAR_TEMP_B, 1 @Opponent missed
	call_if_eq DewfordTown_Dojo_EventScript_PlayerDodge
	applymovement VAR_TEMP_1, DewfordTown_Dojo_Movement_OpponentPunch
	waitmovement 0
	playse SE_M_MEGA_KICK2
	applymovement VAR_TEMP_1, DewfordTown_Dojo_Movement_OpponentReturn
	waitmovement 0
	callfunc ScrFunc_PlayerWasDefeated
	compare VAR_TEMP_C, 1
    goto_if_eq DewfordTown_Dojo_EventScript_OpponentWon
	compare VAR_TEMP_B, 1 @Opponent missed
	goto_if_eq DewfordTown_Dojo_EventScript_ButItMissed
	compare VAR_TEMP_5, 3 @ DOJO_GUARD
	goto_if_eq DewfordTown_Dojo_EventScript_ButItGuarded
	compare VAR_TEMP_5, 7 @ DOJO_SUPER_GUARD
	goto_if_eq DewfordTown_Dojo_EventScript_ButItSuperGuarded
	return

DewfordTown_Dojo_EventScript_OpponentDodge:
	applymovement VAR_TEMP_1, DewfordTown_Dojo_Movement_OpponentDodge
	return

DewfordTown_Dojo_EventScript_PlayerDodge:
	applymovement OBJ_EVENT_ID_PLAYER, DewfordTown_Dojo_Movement_PlayerDodge
	return

DewfordTown_Dojo_EventScript_ButItMissed:
    msgbox DewfordTown_Dojo_Text_ButItMissed, MSGBOX_DEFAULT
	waitmessage
    closemessage
	return

DewfordTown_Dojo_EventScript_ButItGuarded:
    msgbox DewfordTown_Dojo_Text_ButItGuarded, MSGBOX_DEFAULT
	waitmessage
    closemessage
	return

DewfordTown_Dojo_EventScript_ButItSuperGuarded:
    msgbox DewfordTown_Dojo_Text_ButItSuperGuarded, MSGBOX_DEFAULT
	waitmessage
    closemessage
	return

DewfordTown_Dojo_EventScript_Option1ForMoves:
    multichoice 0, 0, MULTI_DYNAMIC_MULTICHOICE_4, TRUE, FALSE
	callfunc ScrFunc_GetPlayerMove
	return

DewfordTown_Dojo_EventScript_Option2ForMoves:
    multichoice 0, 0, MULTI_DYNAMIC_MULTICHOICE_5, TRUE, FALSE
	callfunc ScrFunc_GetPlayerMove
	return

DewfordTown_Dojo_EventScript_Option3ForMoves:
    multichoice 0, 0, MULTI_DYNAMIC_MULTICHOICE_7, TRUE, FALSE
	callfunc ScrFunc_GetPlayerMove
	return

DewfordTown_Dojo_EventScript_Option4ForMoves:
    multichoice 0, 0, MULTI_DYNAMIC_MULTICHOICE_6, TRUE, FALSE
	callfunc ScrFunc_GetPlayerMove
	return


DewfordTown_Dojo_Movement_PlayerPunch:
	walk_fast_right
	walk_fast_right
	walk_fast_right
	step_end

DewfordTown_Dojo_Movement_PlayerReturn:
	lock_facing_direction
	walk_left
	walk_left
	walk_left
	unlock_facing_direction
	step_end

DewfordTown_Dojo_Movement_OpponentPunch:
	walk_fast_left
	walk_fast_left
	walk_fast_left
	step_end

DewfordTown_Dojo_Movement_OpponentReturn:
	lock_facing_direction
	walk_right
	walk_right
	walk_right
	unlock_facing_direction
	step_end

DewfordTown_Dojo_Movement_OpponentDodge:
	lock_facing_direction
	walk_up
	walk_up
	walk_down
	walk_down
	unlock_facing_direction
	step_end

DewfordTown_Dojo_Movement_PlayerDodge:
	lock_facing_direction
	walk_down
	walk_down
	walk_up
	walk_up
	unlock_facing_direction
	step_end

DewfordTown_Dojo_Movement_PlayerGetsInPlace:
	walk_fastest_up
	walk_fastest_up
	walk_fastest_up
	walk_fastest_up
	walk_fastest_left
	walk_fastest_left
	walk_fastest_left
	face_right
	step_end

DewfordTown_Dojo_Movement_PlayerExitArena:
	walk_fastest_down
	walk_fastest_down
	walk_fastest_down
	walk_fastest_down
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	face_up
	step_end

DewfordTown_Dojo_Text_AskForFight:
	.string "This is the Fighting Dojo where\n"
	.string "you may join fights with many\l"
	.string "Trainers.\p"
	.string "Would you like to challenge the\n"
	.string "waiting Trainers?$"

DewfordTown_Dojo_Text_DeclinedFight:
	.string "Please do visit us again!$"

DewfordTown_Dojo_Text_GoToPlace:
	.string "Please, get in your position!$"

DewfordTown_Dojo_Text_Round1Fight:
	.string "Ready?!…\p"
	.string "Fight!$"

DewfordTown_Dojo_Text_PlayerUsed:
    .string "{PLAYER} used {STR_VAR_1}!$"

DewfordTown_Dojo_Text_OpponentUsed:
    .string "Opponent used {STR_VAR_2}!$"

DewfordTown_Dojo_Text_ButItMissed:
	.string "… But It missed!$"

DewfordTown_Dojo_Text_ButItGuarded:
	.string "… But It was guarded!$"

DewfordTown_Dojo_Text_ButItSuperGuarded:
	.string "… But It was super guarded!$"

DewfordTown_Dojo_Text_WhichMove:
    .string "Use which move?\n"
    .string "{PLAYER}'s HP: {STR_VAR_1} / Opponent's HP: {STR_VAR_2}$"

DewfordTown_Dojo_Text_TooBad:
    .string "Too bad…\n"
    .string "Good luck next time!$"

DewfordTown_Dojo_Text_Congratulations:
    .string "Congratulations!\n"
    .string "Let's get down from Arena to\l"
    .string "get your reward.$"
DewfordTown_Dojo_Text_HereTakeYourPrize:
    .string "Here, take your prize!$"

DewfordTown_Dojo_Text_ReceivedKubfu:
	.string "{PLAYER} received the {STR_VAR_1}\n"
	.string "from Black Belt!$"

DewfordTown_Dojo_Text_PlayerWonLittleBoy:
	.string "I never thought that you would\n"
	.string "hit a little kid…\p"
	.string "But damn, that was brutal!\p"
	.string "Here, you can take your reward!\n"
	.string "But please don't be a bully\l"
	.string "anymore!$"

DewfordTown_Dojo_Text_PlayerWonFatMan:
	.string "That fight was a piece of\n"
	.string "cake, right?\p"
	.string "Here, take your reward!$"

DewfordTown_Dojo_Text_PlayerWonRepeat:
	.string "Come here again for more\n"
	.string "fights!$"
