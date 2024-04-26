ProfBirch_EventScript_UpdateLocation::
	compare VAR_PETALBURG_GYM_STATE, 0
	goto_if_eq Common_EventScript_NopReturn
	goto_if_set FLAG_SYS_GAME_CLEAR, ProfBirch_EventScript_MoveToLab
	compare VAR_BIRCH_STATE, 0
	call_if_eq ProfBirch_EventScript_MoveToLab
	compare VAR_BIRCH_STATE, 1
	call_if_eq ProfBirch_EventScript_MoveToLab
	compare VAR_BIRCH_STATE, 2
	call_if_eq ProfBirch_EventScript_MoveToRoute101
	compare VAR_BIRCH_STATE, 3
	call_if_eq ProfBirch_EventScript_MoveToRoute101
	compare VAR_BIRCH_STATE, 4
	call_if_eq ProfBirch_EventScript_MoveToRoute103
	compare VAR_BIRCH_STATE, 5
	call_if_eq ProfBirch_EventScript_MoveToRoute103
	compare VAR_BIRCH_STATE, 6
	call_if_eq ProfBirch_EventScript_MoveToLab
	compare VAR_BIRCH_STATE, 7
	call_if_eq ProfBirch_EventScript_MoveToLab
	return

ProfBirch_EventScript_MoveToLab::
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_BIRCHS_LAB_BIRCH
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_BIRCHS_LAB_UNKNOWN_0x380
	setflag FLAG_HIDE_ROUTE_101_BIRCH
	setflag FLAG_HIDE_ROUTE_103_BIRCH
	return

ProfBirch_EventScript_MoveToRoute101::
	clearflag FLAG_HIDE_ROUTE_101_BIRCH
	setflag FLAG_HIDE_LITTLEROOT_TOWN_BIRCHS_LAB_BIRCH
	setflag FLAG_HIDE_LITTLEROOT_TOWN_BIRCHS_LAB_UNKNOWN_0x380
	setflag FLAG_HIDE_ROUTE_103_BIRCH
	return

ProfBirch_EventScript_MoveToRoute103::
	clearflag FLAG_HIDE_ROUTE_103_BIRCH
	setflag FLAG_HIDE_ROUTE_101_BIRCH
	setflag FLAG_HIDE_LITTLEROOT_TOWN_BIRCHS_LAB_BIRCH
	setflag FLAG_HIDE_LITTLEROOT_TOWN_BIRCHS_LAB_UNKNOWN_0x380
	return

ProfBirch_EventScript_RatePokedexOrRegister::
	lock
	faceplayer
	compare VAR_END_OF_THE_WORLD, 2
	goto_if_eq LittlerootTown_ProfessorBirchsLab_EventScript_FromFuture
	compare VAR_PROF_BIRCH_NEW_STARTER_STAGE, 1
	goto_if_eq LittlerootTown_ProfessorBirchsLab_EventScript_AllowNewStarter
	compare VAR_PROF_BIRCH_NEW_STARTER_STAGE, 3
	goto_if_eq LittlerootTown_ProfessorBirchsLab_EventScript_AllowNewStarter
	compare VAR_PROF_BIRCH_NEW_STARTER_STAGE, 5
	goto_if_eq LittlerootTown_ProfessorBirchsLab_EventScript_AllowNewStarter
	compare VAR_PROF_BIRCH_NEW_STARTER_STAGE, 7
	goto_if_eq LittlerootTown_ProfessorBirchsLab_EventScript_AllowNewStarter
	compare VAR_PROF_BIRCH_NEW_STARTER_STAGE, 9
	goto_if_eq LittlerootTown_ProfessorBirchsLab_EventScript_AllowNewStarter
	compare VAR_PROF_BIRCH_NEW_STARTER_STAGE, 11
	goto_if_eq LittlerootTown_ProfessorBirchsLab_EventScript_AllowNewStarter
	goto_if_unset FLAG_HAS_MATCH_CALL, ProfBirch_EventScript_AskRatePokedex
	goto_if_unset FLAG_ENABLE_PROF_BIRCH_MATCH_CALL, EventScript_RegisterProfBirch
	goto_if_unset FLAG_RECEIVED_ROTOM_CATALOG, EventScript_TryToGiveRotomCatalogOutLab
ProfBirch_EventScript_AskRatePokedex::
	msgbox gBirchDexRatingText_AreYouCurious, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq ProfBirch_EventScript_DeclineRating
	call ProfBirch_EventScript_RatePokedex
	release
	end

EventScript_TryToGiveRotomCatalogOutLab::
	goto_if_set FLAG_CAPTURED_ROTOM, EventScript_GiveRotomCatalog
	goto ProfBirch_EventScript_AskRatePokedex
	end

ProfBirch_EventScript_DeclineRating::
	msgbox gBirchDexRatingText_Cancel, MSGBOX_DEFAULT
	release
	end

ProfBirch_EventScript_ShowRatingMessage::
	copyvar VAR_0x8004, VAR_0x8009
	special ShowPokedexRatingMessage
	waitmessage
	waitbuttonpress
	return

ProfBirch_EventScript_RatePokedex::
	setvar VAR_0x8004, 0
	specialvar VAR_RESULT, ScriptGetPokedexInfo
	copyvar VAR_0x8008, VAR_0x8005
	copyvar VAR_0x8009, VAR_0x8006
	copyvar VAR_0x800A, VAR_RESULT
	buffernumberstring 0, VAR_0x8008  @ Num Hoenn seen
	buffernumberstring 1, VAR_0x8009  @ Num Hoenn caught
	msgbox gBirchDexRatingText_SoYouveSeenAndCaught, MSGBOX_DEFAULT
	call ProfBirch_EventScript_ShowRatingMessage
	compare VAR_0x800A, 0
	goto_if_eq Common_EventScript_NopReturn  @ National dex not enabled
	setvar VAR_0x8004, 1
	specialvar VAR_RESULT, ScriptGetPokedexInfo
	copyvar VAR_0x8008, VAR_0x8005
	copyvar VAR_0x8009, VAR_0x8006
	buffernumberstring 0, VAR_0x8008  @ Num National seen
	buffernumberstring 1, VAR_0x8009  @ Num National caught
	msgbox gBirchDexRatingText_OnANationwideBasis, MSGBOX_DEFAULT
	return
