Route135_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, Route135_OnLoad
	.byte 0

Route135_OnLoad:
	call_if_unset FLAG_REGI_DOORS_OPENED, Route135_CloseRegiEntrance
	end

Route135_CloseRegiEntrance::
	setmetatile 44, 33, METATILE_General_RockWall_RockBase, 1
	setmetatile 44, 34, METATILE_General_RockWall_SandBase, 1
	return
