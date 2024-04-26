PacifidlogTown_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, PacifidlogTown_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, PacifidlogTown_OnResume
	.byte 0

PacifidlogTown_OnTransition:
	call PacifidlogTown_EventScript_TryHideOrShowSpiritombWisps
	setflag FLAG_VISITED_PACIFIDLOG_TOWN
	end

PacifidlogTown_EventScript_TryHideOrShowSpiritombWisps:
	gettimeofday
	compare VAR_0x8000, 2
	goto_if_eq PacifidlogTown_EventScript_TryShowWisps
	goto PacifidlogTown_EventScript_HideWisps
	end

PacifidlogTown_EventScript_TryShowWisps:
	goto_if_unset FLAG_RECEIVED_WISPS_13, PacifidlogTown_EventScript_ShowWisp
	return

PacifidlogTown_EventScript_ShowWisp:
	clearflag FLAG_HIDE_WISPS_13
	return

PacifidlogTown_EventScript_HideWisps:
	setflag FLAG_HIDE_WISPS_13
	return

PacifidlogTown_OnResume:
	setstepcallback STEP_CB_PACIFIDLOG_BRIDGE
	end

PacifidlogTown_EventScript_NinjaBoy::
	msgbox PacifidlogTown_Text_NeatHousesOnWater, MSGBOX_NPC
	end

PacifidlogTown_EventScript_Girl::
	msgbox PacifidlogTown_Text_FastRunningCurrent, MSGBOX_NPC
	end

PacifidlogTown_EventScript_Fisherman::
	msgbox PacifidlogTown_Text_SkyPillarTooScary, MSGBOX_NPC
	end

PacifidlogTown_EventScript_TownSign::
	msgbox PacifidlogTown_Text_TownSign, MSGBOX_SIGN
	end

PacifidlogTown_Text_FastRunningCurrent:
	.string "The sea between Pacifidlog and\n"
	.string "Slateport has a fast-running tide.\p"
	.string "If you decide to Surf, you could end\n"
	.string "up swept away somewhere else.$"

PacifidlogTown_Text_NeatHousesOnWater:
	.string "See, isn't it neat?\n"
	.string "These houses are on water!\p"
	.string "I was born here!$"

PacifidlogTown_Text_SkyPillarTooScary:
	.string "The Sky Pillar?\p"
	.string "…Oh, you must mean that tall, tall\n"
	.string "tower a little further out.\p"
	.string "If you asked me, I wouldn't climb it.\n"
	.string "It's too scary to get up that high.\p"
	.string "Life at sea level in Pacifidlog,\n"
	.string "that suits me fine.$"

PacifidlogTown_Text_TownSign:
	.string "Pacifidlog Town\p"
	.string "“Where the morning sun smiles upon\n"
	.string "the waters.”$"

