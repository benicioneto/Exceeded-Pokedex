.set LOCALID_DHELMISE, 1

AbandonedShip_Underwater2_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, AbandonedShip_Underwater2_OnResume
	.byte 0

AbandonedShip_Underwater2_OnResume:
	setdivewarp MAP_ABANDONED_SHIP_ROOMS_B1F, 255, 13, 7
	end

AbandonedShip_Underwater2_EventScript_Dhelmise::
	lockall
	addobject LOCALID_DHELMISE
	playse SE_PIN
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
	waitmovement 0
	msgbox AbandonedShip_Underwater2_Text_SomethingUnderwater, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_DHELMISE, AbandonedShip_Underwater2_Movement_DhelmiseEnter
	waitmovement 0
	setwildbattle SPECIES_DHELMISE, 40, ITEM_METAL_COAT
	waitse
	playmoncry SPECIES_DHELMISE, 0
	delay 90
	waitmoncry
	dowildbattle
	setvar VAR_UNDERWATER_DHELMISE, 1
	removeobject LOCALID_DHELMISE
	releaseall
	end

AbandonedShip_Underwater2_Text_SomethingUnderwater:
	.string "There is something underwater…$"

AbandonedShip_Underwater2_Movement_DhelmiseEnter:
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
