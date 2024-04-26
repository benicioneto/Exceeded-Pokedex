.set LOCALID_RED_GYARADOS, 2
Route136_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route136_OnTransition
	.byte 0

Route136_OnTransition:
	call Route136_EventScript_SetWeather
	end

Route136_EventScript_SetWeather:
	goto_if_unset FLAG_HIDE_RED_GYARADOS, Route136_EventScript_TrySetRainyWeather
    return

Route136_EventScript_TrySetRainyWeather:
	setweather WEATHER_RAIN
	return

EventScript_RedGyarados::
    lock
	faceplayer
	setflag FLAG_SHINY_CREATION
    playmoncry SPECIES_GYARADOS, 0 
    waitmoncry
    msgbox RedGyarados_Battle, MSGBOX_DEFAULT
	setwildbattle SPECIES_GYARADOS, 40, ITEM_NONE
	dowildbattle
	setweather WEATHER_NONE
    setflag FLAG_HIDE_RED_GYARADOS
    removeobject LOCALID_RED_GYARADOS
    @giveitem ITEM_RED_SCALE
    release
    end

RedGyarados_Battle:
	.string "Gro-ooooooowl!$"
