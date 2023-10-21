.set LOCALID_NECROZMA, 2

Meteor_NecrozmaHome_MapScripts::
	.byte 0

Meteor_NecrozmaHome_EventScript_IntoTheVoid::
	setflag FLAG_HIDE_MAP_NAME_POPUP
	warp MAP_METEOR_NECROZMA_HOME, 255, 19, 46
	waitstate
	end

Meteor_NecrozmaHome_EventScript_Necrozma::
	lock
	faceplayer
	playbgm MUS_RG_ENCOUNTER_DEOXYS, FALSE
	waitse
	playmoncry SPECIES_NECROZMA, 2
	delay 40
	waitmoncry
	setvar VAR_LAST_TALKED, LOCALID_NECROZMA
	setvar VAR_0x8004, SPECIES_NECROZMA
	setvar VAR_0x8005, 70 @ level
	setvar VAR_0x8006, ITEM_NONE
	special CreateEventLegalEnemyMon
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	special BattleSetup_StartLegendaryBattle
	waitstate
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq Meteor_NecrozmaHome_EventScript_DefeatedNecrozma
	compare VAR_RESULT, B_OUTCOME_CAUGHT
	goto_if_eq Meteor_NecrozmaHome_EventScript_DefeatedNecrozma
	release
	end

Meteor_NecrozmaHome_EventScript_DefeatedNecrozma:
	setvar VAR_END_OF_THE_WORLD, 3
    delay B_WAIT_TIME_SHORT
    fadescreen FADE_TO_BLACK
    msgbox Meteor_NecrozmaHome_Text_Shadow_UsedDragonAscent, MSGBOX_DEFAULT
	closemessage
	playse SE_M_FLY
	waitse
	playse SE_M_EXPLOSION
    msgbox Meteor_NecrozmaHome_Text_Shadow_Etc, MSGBOX_AUTOCLOSE
	waitse
	playse SE_M_EXPLOSION
    msgbox Meteor_NecrozmaHome_Text_Shadow_Etc, MSGBOX_AUTOCLOSE
	waitse
	playse SE_M_EXPLOSION
    msgbox Meteor_NecrozmaHome_Text_Shadow_MeteorWasDestroyed, MSGBOX_AUTOCLOSE
	waitse
    delay B_WAIT_TIME_SHORT
	setflag FLAG_HIDE_MAP_NAME_POPUP
	clearflag FLAG_HIDE_CELEBI
	warpsilent MAP_METEOR_FALLS_DRACONID_TRIBE, 255, 18, 17
	waitstate
	end

Meteor_NecrozmaHome_Text_Shadow_UsedDragonAscent:
	.string "Rayquaza used Dragon Ascent!$"

Meteor_NecrozmaHome_Text_Shadow_Etc:
	.string "…$"

Meteor_NecrozmaHome_Text_Shadow_MeteorWasDestroyed:
	.string "The meteor was destroyed!$"
