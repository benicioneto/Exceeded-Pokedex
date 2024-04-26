EventScript_PC::
	lockall
	setvar VAR_0x8004, 0
	special DoPCTurnOnEffect
	playse SE_PC_ON
	msgbox Text_BootUpPC, MSGBOX_DEFAULT
	goto EventScript_PCMainMenu
	end

EventScript_PCMainMenu::
	message gText_WhichPCShouldBeAccessed
	waitmessage
	special ScriptMenu_CreatePCMultichoice
	waitstate
	goto EventScript_AccessPC
	end

EventScript_AccessPC::
	switch VAR_RESULT
	case 0, EventScript_AccessPokemonStorage
	case 1, EventScript_AccessPlayersPC
	case 2, EventScript_AccessHallOfFame
	case 3, EventScript_TurnOffPC
	case MULTI_B_PRESSED, EventScript_TurnOffPC
	end

EventScript_AccessPlayersPC::
#ifdef FREE_PC_ITEMS
	goto_if_set FLAG_SYS_GAME_CLEAR, EventScript_AccessHallOfFame_Access2
	goto EventScript_TurnOffPC
#endif
	playse SE_PC_LOGIN
	msgbox gText_AccessedPlayersPC, MSGBOX_DEFAULT
	special PlayerPC
	waitstate
	goto EventScript_PCMainMenu
	end

EventScript_AccessPokemonStorage::
	playse SE_PC_LOGIN
	call_if_unset FLAG_SYS_PC_LANETTE, EventScript_AccessSomeonesPC
	call_if_set FLAG_SYS_PC_LANETTE, EventScript_AccessLanettesPC
	msgbox gText_StorageSystemOpened, MSGBOX_DEFAULT
	special ShowPokemonStorageSystemPC
	waitstate
	goto EventScript_PCMainMenu
	end

EventScript_AccessSomeonesPC::
	msgbox gText_AccessedSomeonesPC, MSGBOX_DEFAULT
	return

EventScript_AccessLanettesPC::
	msgbox gText_AccessedLanettesPC, MSGBOX_DEFAULT
	return

EventScript_TurnOffPC::
	setvar VAR_0x8004, 0
	playse SE_PC_OFF
	special DoPCTurnOffEffect
	releaseall
	end

EventScript_AccessHallOfFame::
#ifdef FREE_PC_ITEMS
	goto EventScript_TurnOffPC
#endif
	goto_if_unset FLAG_SYS_GAME_CLEAR, EventScript_TurnOffPC
EventScript_AccessHallOfFame_Access2:
	playse SE_PC_LOGIN
	special AccessHallOfFamePC
	waitstate
	goto EventScript_AccessPC
	end

@@ Sandbox Menu

Eventscript_PC_SandboxMenu::
	lockall
	setvar VAR_0x8004, 0
	playse SE_PC_ON
	msgbox Text_BootUpPC, MSGBOX_DEFAULT
	goto EventScript_PCMainMenu_SandboxMenu
	end

EventScript_PCMainMenu_SandboxMenu::
	message gText_WhichPCShouldBeAccessed
	waitmessage
	special ScriptMenu_CreatePCMultichoice
	waitstate
	goto EventScript_AccessPC_SandboxMenu
	end

EventScript_AccessPC_SandboxMenu::
	switch VAR_RESULT
	case 0, EventScript_AccessPokemonStorage_SandboxMenu
	case 1, EventScript_AccessPlayersPC_SandboxMenu
	case 2, EventScript_AccessHallOfFame_SandboxMenu
	case 3, EventScript_TurnOffPC_SandboxMenu
	case MULTI_B_PRESSED, EventScript_TurnOffPC_SandboxMenu
	end

EventScript_AccessPokemonStorage_SandboxMenu::
	playse SE_PC_LOGIN
	call_if_unset FLAG_SYS_PC_LANETTE, EventScript_AccessSomeonesPC
	call_if_set FLAG_SYS_PC_LANETTE, EventScript_AccessLanettesPC
	msgbox gText_StorageSystemOpened, MSGBOX_DEFAULT
	special ShowPokemonStorageSystemPC
	waitstate
	goto EventScript_PCMainMenu_SandboxMenu
	end

EventScript_AccessPlayersPC_SandboxMenu::
#ifdef FREE_PC_ITEMS
	goto_if_set FLAG_SYS_GAME_CLEAR, EventScript_AccessHallOfFame_SandboxMenu_Access2
	goto EventScript_TurnOffPC_SandboxMenu
#endif
	playse SE_PC_LOGIN
	msgbox gText_AccessedPlayersPC, MSGBOX_DEFAULT
	special PlayerPC
	waitstate
	goto EventScript_PCMainMenu_SandboxMenu
	end

EventScript_AccessHallOfFame_SandboxMenu::
#ifdef FREE_PC_ITEMS
	goto EventScript_TurnOffPC_SandboxMenu
#endif
	goto_if_unset FLAG_SYS_GAME_CLEAR, EventScript_TurnOffPC_SandboxMenu
EventScript_AccessHallOfFame_SandboxMenu_Access2:
	playse SE_PC_LOGIN
	special AccessHallOfFamePC
	waitstate
	goto EventScript_AccessPC_SandboxMenu
	end

EventScript_TurnOffPC_SandboxMenu::
	setvar VAR_0x8004, 0
	playse SE_PC_OFF
	releaseall
	end
