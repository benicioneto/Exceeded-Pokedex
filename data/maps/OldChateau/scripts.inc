OldChateau_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, OldChateau_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

OldChateau_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
	map_script_2 VAR_OLD_CHATEAU, 0, OldChateau_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_1
	.2byte 0

OldChateau_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_1:
	lockall
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFastestUp
	waitmovement 0
	msgbox OldChateau_Text_StrangePresence, MSGBOX_DEFAULT	
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_Delay48
	waitmovement 0
	setvar VAR_OLD_CHATEAU, 1
	releaseall
	return

OldChateau_MimikyuEncounter::
	lockall
    playmoncry SPECIES_MIMIKYU, 0 
    waitmoncry
	setwildbattle SPECIES_MIMIKYU, 30, ITEM_NONE
	dowildbattle
    setvar VAR_OLD_CHATEAU, 2
    releaseall
    end

OldChateau_Text_StrangePresence:
	.string "{PLAYER} is sensing a strange presence…$"
