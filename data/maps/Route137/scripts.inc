
Route137_MapScripts::
	@map_script MAP_SCRIPT_ON_RESUME, Route137_OnResume
	@map_script MAP_SCRIPT_ON_TRANSITION, Route137_OnTransition
	.byte 0

Route137_OnResume:
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, Route119_EventScript_TryRemoveKecleon
	end

Route137_OnTransition:
	special SetRoute119Weather
	end
