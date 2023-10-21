LavaridgeTown_Blacksmith_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, LavaridgeTown_Blacksmith_MapScripts_MAP_SCRIPT_ON_LOAD
	map_script MAP_SCRIPT_ON_TRANSITION, LavaridgeTown_Blacksmith_MAP_SCRIPT_ON_TRANSITION
	map_script MAP_SCRIPT_ON_FRAME_TABLE, LavaridgeTown_Blacksmith_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

LavaridgeTown_Blacksmith_MapScripts_MAP_SCRIPT_ON_LOAD:
	call_if_unset FLAG_LAVARIDGE_BLACKSMITH, LavaridgeTown_Blacksmith_MapScripts_RemoveLava
	return

LavaridgeTown_Blacksmith_MAP_SCRIPT_ON_TRANSITION:
	compare VAR_BLACKSMITH_FORGE_STATE, 1
	call_if_eq LavaridgeTown_Blacksmith_EventScript_SetForgeReady
	end

LavaridgeTown_Blacksmith_EventScript_SetForgeReady::
	call_if_unset FLAG_DAILY_BLACKSMITH_FORGE, LavaridgeTown_Blacksmith_EventScript_SetForgeReady_for_sure
	return

LavaridgeTown_Blacksmith_EventScript_SetForgeReady_for_sure:
	setvar VAR_BLACKSMITH_FORGE_STATE, 2
	return

LavaridgeTown_Blacksmith_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
	map_script_2 VAR_TEMP_0, 0, LavaridgeTown_Blacksmith_MapScripts_Earthquake
	.2byte 0

LavaridgeTown_Blacksmith_MapScripts_RemoveLava:
	setmetatile 0, 6, METATILE_Lavaridge_NoLavaEdge, TRUE
	setmetatile 1, 6, METATILE_Lavaridge_NoLavaEdge, TRUE
	setmetatile 2, 6, METATILE_Lavaridge_NoLavaEdge, TRUE
	setmetatile 3, 6, METATILE_Lavaridge_NoLavaEdge, TRUE
	setmetatile 4, 6, METATILE_Lavaridge_NoLavaEdge, TRUE
	setmetatile 5, 6, METATILE_Lavaridge_NoLavaEdge, TRUE
	setmetatile 6, 6, METATILE_Lavaridge_NoLavaEdge, TRUE
	setmetatile 7, 6, METATILE_Lavaridge_NoLavaEdge, TRUE
	setmetatile 8, 6, METATILE_Lavaridge_NoLavaEdge, TRUE
	setmetatile 9, 6, METATILE_Lavaridge_NoLavaEdge, TRUE
	setmetatile 10, 6, METATILE_Lavaridge_NoLavaEdge, TRUE
	setmetatile 11, 6, METATILE_Lavaridge_NoLavaEdge, TRUE
	setmetatile 12, 6, METATILE_Lavaridge_NoLavaEdge, TRUE
	setmetatile 13, 6, METATILE_Lavaridge_NoLavaEdge, TRUE
	setmetatile 14, 6, METATILE_Lavaridge_NoLavaEdge, TRUE
	setmetatile 15, 6, METATILE_Lavaridge_NoLavaEdge, TRUE
	setmetatile 16, 6, METATILE_Lavaridge_NoLavaEdge, TRUE
	setmetatile 17, 6, METATILE_Lavaridge_NoLavaEdge, TRUE
	setmetatile 18, 6, METATILE_Lavaridge_NoLavaEdge, TRUE
	setmetatile 19, 6, METATILE_Lavaridge_NoLavaEdge, TRUE
	setmetatile 0, 5, METATILE_Lavaridge_No_Lava, FALSE
	setmetatile 1, 5, METATILE_Lavaridge_No_Lava, FALSE
	setmetatile 2, 5, METATILE_Lavaridge_No_Lava, FALSE
	setmetatile 3, 5, METATILE_Lavaridge_No_Lava, FALSE
	setmetatile 4, 5, METATILE_Lavaridge_No_Lava, FALSE
	setmetatile 5, 5, METATILE_Lavaridge_No_Lava, FALSE
	setmetatile 6, 5, METATILE_Lavaridge_No_Lava, FALSE
	setmetatile 7, 5, METATILE_Lavaridge_No_Lava, FALSE
	setmetatile 8, 5, METATILE_Lavaridge_No_Lava, FALSE
	setmetatile 9, 5, METATILE_Lavaridge_No_Lava, FALSE
	setmetatile 10, 5, METATILE_Lavaridge_No_Lava, FALSE
	setmetatile 11, 5, METATILE_Lavaridge_No_Lava, FALSE
	setmetatile 12, 5, METATILE_Lavaridge_No_Lava, FALSE
	setmetatile 13, 5, METATILE_Lavaridge_No_Lava, FALSE
	setmetatile 14, 5, METATILE_Lavaridge_No_Lava, FALSE
	setmetatile 15, 5, METATILE_Lavaridge_No_Lava, FALSE
	setmetatile 16, 5, METATILE_Lavaridge_No_Lava, FALSE
	setmetatile 17, 5, METATILE_Lavaridge_No_Lava, FALSE
	setmetatile 18, 5, METATILE_Lavaridge_No_Lava, FALSE
	setmetatile 19, 5, METATILE_Lavaridge_No_Lava, FALSE
	setmetatile 0, 4, METATILE_Lavaridge_No_Lava, FALSE
	setmetatile 1, 4, METATILE_Lavaridge_No_Lava, FALSE
	setmetatile 2, 4, METATILE_Lavaridge_No_Lava, FALSE
	setmetatile 3, 4, METATILE_Lavaridge_No_Lava, FALSE
	setmetatile 4, 4, METATILE_Lavaridge_No_Lava, FALSE
	setmetatile 5, 4, METATILE_Lavaridge_No_Lava, FALSE
	setmetatile 6, 4, METATILE_Lavaridge_No_Lava, FALSE
	setmetatile 7, 4, METATILE_Lavaridge_No_Lava, FALSE
	setmetatile 8, 4, METATILE_Lavaridge_No_Lava, FALSE
	setmetatile 9, 4, METATILE_Lavaridge_No_Lava, FALSE
	setmetatile 10, 4, METATILE_Lavaridge_No_Lava, FALSE
	setmetatile 11, 4, METATILE_Lavaridge_No_Lava, FALSE
	setmetatile 12, 4, METATILE_Lavaridge_No_Lava, FALSE
	setmetatile 13, 4, METATILE_Lavaridge_No_Lava, FALSE
	setmetatile 14, 4, METATILE_Lavaridge_No_Lava, FALSE
	setmetatile 15, 4, METATILE_Lavaridge_No_Lava, FALSE
	setmetatile 16, 4, METATILE_Lavaridge_No_Lava, FALSE
	setmetatile 17, 4, METATILE_Lavaridge_No_Lava, FALSE
	setmetatile 18, 4, METATILE_Lavaridge_No_Lava, FALSE
	setmetatile 19, 4, METATILE_Lavaridge_No_Lava, FALSE
	setmetatile 19, 4, METATILE_Lavaridge_No_Lava, FALSE
	return

LavaridgeTown_Blacksmith_MapScripts_Earthquake:
	call_if_unset FLAG_LAVARIDGE_EARTHQUAKE, LavaridgeTown_Blacksmith_MapScripts_DoEarthquake
	setvar VAR_TEMP_0, 1
	return

LavaridgeTown_Blacksmith_MapScripts_DoEarthquake:
	lockall
	setvar VAR_0x8004, 1
	setvar VAR_0x8005, 1
	setvar VAR_0x8006, 20
	setvar VAR_0x8007, 3
	special ShakeCamera
	waitstate
	playse SE_PIN
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_Delay48
	waitmovement 0
	delay 4
	setvar VAR_0x8004, 2
	setvar VAR_0x8005, 2
	setvar VAR_0x8006, 20
	setvar VAR_0x8007, 3
	special ShakeCamera
	waitstate
	delay 30
	setflag FLAG_LAVARIDGE_EARTHQUAKE
	releaseall
	return

LavaridgeTown_Blacksmith_EventScript_Blacksmith::
	lockall
	faceplayer
	compare VAR_BLACKSMITH_FORGE_STATE, 2
	goto_if_eq LavaridgeTown_Blacksmith_EventScript_ForgedItemIsReady
	compare VAR_BLACKSMITH_FORGE_STATE, 1
	goto_if_eq LavaridgeTown_Blacksmith_EventScript_StillForging
	goto_if_set FLAG_LAVARIDGE_BLACKSMITH, LavaridgeTown_Blacksmith_EventScript_ReadyForge
	msgbox LavaridgeTown_Blacksmith_Text_NoForge, MSGBOX_DEFAULT
	releaseall
	end

LavaridgeTown_Blacksmith_EventScript_ReadyForge:
	goto_if_set FLAG_TEMP_1, LavaridgeTown_Blacksmith_EventScript_ForgeWhichItem
	msgbox LavaridgeTown_Blacksmith_Text_ThankYou, MSGBOX_DEFAULT
	setflag FLAG_TEMP_1
	goto LavaridgeTown_Blacksmith_EventScript_ForgeWhichItem

LavaridgeTown_Blacksmith_EventScript_ForgeWhichItem:
	msgbox LavaridgeTown_Blacksmith_Text_WhichItem, MSGBOX_DEFAULT
	waitmessage
LavaridgeTown_Blacksmith_EventScript_ReturnToChooseItem:
	setvar VAR_0x8004, SCROLL_MULTI_BLACKSMITH
	special ShowFrontierExchangeCornerItemIconWindow
	special ShowScrollableMultichoice
	waitstate
	special CloseFrontierExchangeCornerItemIconWindow
	switch VAR_RESULT
	case 0, LavaridgeTown_Blacksmith_EventScript_Masamune
	case 1, LavaridgeTown_Blacksmith_EventScript_Muramasa
	case 2, LavaridgeTown_Blacksmith_EventScript_Fireblender
	case 3, LavaridgeTown_Blacksmith_EventScript_IceFalchion
	case 4, LavaridgeTown_Blacksmith_EventScript_StrongShield
	case 5, LavaridgeTown_Blacksmith_EventScript_GoldenHammer
	case 6, LavaridgeTown_Blacksmith_EventScript_CancelPokemonSelect
	case MULTI_B_PRESSED, LavaridgeTown_Blacksmith_EventScript_CancelPokemonSelect
	goto LavaridgeTown_Blacksmith_EventScript_CancelPokemonSelect
	end

LavaridgeTown_Blacksmith_EventScript_Masamune:
	setvar VAR_TEMP_1, 1
	bufferitemname 0, ITEM_MASAMUNE
	msgbox LavaridgeTown_Blacksmith_Text_MasamuneMaterials, MSGBOX_DEFAULT
	waitmessage
	goto LavaridgeTown_Blacksmith_EventScript_ConfirmForge

LavaridgeTown_Blacksmith_EventScript_Muramasa:
	setvar VAR_TEMP_1, 2
	bufferitemname 0, ITEM_MURAMASA
	msgbox LavaridgeTown_Blacksmith_Text_MuramasaMaterials, MSGBOX_DEFAULT
	waitmessage
	goto LavaridgeTown_Blacksmith_EventScript_ConfirmForge

LavaridgeTown_Blacksmith_EventScript_Fireblender:
	setvar VAR_TEMP_1, 3
	bufferitemname 0, ITEM_FIREBLENDER
	msgbox LavaridgeTown_Blacksmith_Text_FireblenderMaterials, MSGBOX_DEFAULT
	waitmessage
	goto LavaridgeTown_Blacksmith_EventScript_ConfirmForge

LavaridgeTown_Blacksmith_EventScript_IceFalchion:
	setvar VAR_TEMP_1, 4
	bufferitemname 0, ITEM_ICE_FALCHION
	msgbox LavaridgeTown_Blacksmith_Text_IceFalchionMaterials, MSGBOX_DEFAULT
	waitmessage
	goto LavaridgeTown_Blacksmith_EventScript_ConfirmForge

LavaridgeTown_Blacksmith_EventScript_StrongShield:
	setvar VAR_TEMP_1, 5
	bufferitemname 0, ITEM_STRONG_SHIELD
	msgbox LavaridgeTown_Blacksmith_Text_StrongShieldMaterials, MSGBOX_DEFAULT
	waitmessage
	goto LavaridgeTown_Blacksmith_EventScript_ConfirmForge

LavaridgeTown_Blacksmith_EventScript_GoldenHammer:
	setvar VAR_TEMP_1, 6
	bufferitemname 0, ITEM_GOLDEN_HAMMER
	msgbox LavaridgeTown_Blacksmith_Text_GoldenHammerMaterials, MSGBOX_DEFAULT
	waitmessage
	goto LavaridgeTown_Blacksmith_EventScript_ConfirmForge

LavaridgeTown_Blacksmith_EventScript_ConfirmForge:
	msgbox LavaridgeTown_Blacksmith_Text_SoYourChoiceIsTheItemX, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq LavaridgeTown_Blacksmith_EventScript_ReturnToChooseItem
	switch VAR_TEMP_1
	case 1, LavaridgeTown_Blacksmith_EventScript_Masamune_Forge
	case 2, LavaridgeTown_Blacksmith_EventScript_Muramasa_Forge
	case 3, LavaridgeTown_Blacksmith_EventScript_Fireblender_Forge
	case 4, LavaridgeTown_Blacksmith_EventScript_IceFalchion_Forge
	case 5, LavaridgeTown_Blacksmith_EventScript_StrongShield_Forge
	case 6, LavaridgeTown_Blacksmith_EventScript_GoldenHammer_Forge
	end

LavaridgeTown_Blacksmith_EventScript_Masamune_Forge:
	checkitem ITEM_METAL_COAT, 1
	compare VAR_RESULT, FALSE
	goto_if_eq LavaridgeTown_Blacksmith_EventScript_NoMaterial
	checkitem ITEM_BRIGHT_POWDER, 1
	compare VAR_RESULT, FALSE
	goto_if_eq LavaridgeTown_Blacksmith_EventScript_NoMaterial
	checkitem ITEM_NUGGET, 1
	compare VAR_RESULT, FALSE
	goto_if_eq LavaridgeTown_Blacksmith_EventScript_NoMaterial
	removeitem ITEM_METAL_COAT, 1
	removeitem ITEM_BRIGHT_POWDER, 1
	removeitem ITEM_NUGGET, 1
	setvar VAR_WHICH_ITEM_FORGED, 1
	goto LavaridgeTown_Blacksmith_EventScript_StartForge
	end

LavaridgeTown_Blacksmith_EventScript_Muramasa_Forge:
	checkitem ITEM_METAL_COAT, 1
	compare VAR_RESULT, FALSE
	goto_if_eq LavaridgeTown_Blacksmith_EventScript_NoMaterial
	checkitem ITEM_RAZOR_CLAW, 1
	compare VAR_RESULT, FALSE
	goto_if_eq LavaridgeTown_Blacksmith_EventScript_NoMaterial
	checkitem ITEM_NUGGET, 1
	compare VAR_RESULT, FALSE
	goto_if_eq LavaridgeTown_Blacksmith_EventScript_NoMaterial
	removeitem ITEM_METAL_COAT, 1
	removeitem ITEM_RAZOR_CLAW, 1
	removeitem ITEM_NUGGET, 1
	setvar VAR_WHICH_ITEM_FORGED, 2
	goto LavaridgeTown_Blacksmith_EventScript_StartForge

LavaridgeTown_Blacksmith_EventScript_Fireblender_Forge:
	checkitem ITEM_METAL_COAT, 1
	compare VAR_RESULT, FALSE
	goto_if_eq LavaridgeTown_Blacksmith_EventScript_NoMaterial
	checkitem ITEM_FIRE_STONE, 1
	compare VAR_RESULT, FALSE
	goto_if_eq LavaridgeTown_Blacksmith_EventScript_NoMaterial
	checkitem ITEM_NUGGET, 1
	compare VAR_RESULT, FALSE
	goto_if_eq LavaridgeTown_Blacksmith_EventScript_NoMaterial
	removeitem ITEM_METAL_COAT, 1
	removeitem ITEM_FIRE_STONE, 1
	removeitem ITEM_NUGGET, 1
	setvar VAR_WHICH_ITEM_FORGED, 3
	goto LavaridgeTown_Blacksmith_EventScript_StartForge

LavaridgeTown_Blacksmith_EventScript_IceFalchion_Forge:
	checkitem ITEM_METAL_COAT, 1
	compare VAR_RESULT, FALSE
	goto_if_eq LavaridgeTown_Blacksmith_EventScript_NoMaterial
	checkitem ITEM_ICE_STONE, 1
	compare VAR_RESULT, FALSE
	goto_if_eq LavaridgeTown_Blacksmith_EventScript_NoMaterial
	checkitem ITEM_NUGGET, 1
	compare VAR_RESULT, FALSE
	goto_if_eq LavaridgeTown_Blacksmith_EventScript_NoMaterial
	removeitem ITEM_METAL_COAT, 1
	removeitem ITEM_ICE_STONE, 1
	removeitem ITEM_NUGGET, 1
	setvar VAR_WHICH_ITEM_FORGED, 4
	goto LavaridgeTown_Blacksmith_EventScript_StartForge

LavaridgeTown_Blacksmith_EventScript_StrongShield_Forge:
	checkitem ITEM_METAL_COAT, 3
	compare VAR_RESULT, FALSE
	goto_if_eq LavaridgeTown_Blacksmith_EventScript_NoMaterial
	checkitem ITEM_HARD_STONE, 1
	compare VAR_RESULT, FALSE
	goto_if_eq LavaridgeTown_Blacksmith_EventScript_NoMaterial
	removeitem ITEM_METAL_COAT, 3
	removeitem ITEM_HARD_STONE, 1
	setvar VAR_WHICH_ITEM_FORGED, 5
	goto LavaridgeTown_Blacksmith_EventScript_StartForge

LavaridgeTown_Blacksmith_EventScript_GoldenHammer_Forge:
	checkitem ITEM_NUGGET, 5
	compare VAR_RESULT, FALSE
	goto_if_eq LavaridgeTown_Blacksmith_EventScript_NoMaterial
	removeitem ITEM_NUGGET, 5
	setvar VAR_WHICH_ITEM_FORGED, 6
	goto LavaridgeTown_Blacksmith_EventScript_StartForge

LavaridgeTown_Blacksmith_EventScript_StartForge:
	playse SE_SHOP
	setvar VAR_BLACKSMITH_FORGE_STATE, 1
	setflag FLAG_DAILY_BLACKSMITH_FORGE
	msgbox LavaridgeTown_Blacksmith_Text_HereYouGo, MSGBOX_DEFAULT
	release
	end

LavaridgeTown_Blacksmith_EventScript_CancelPokemonSelect:
	msgbox LavaridgeTown_Blacksmith_Text_Cancel, MSGBOX_DEFAULT
	releaseall
	end

LavaridgeTown_Blacksmith_EventScript_NoMaterial:
	msgbox LavaridgeTown_Blacksmith_Text_NoMaterial, MSGBOX_DEFAULT
	release
	end

LavaridgeTown_Blacksmith_Text_WhichItem:
	.string "Which item do you want me\n"
	.string "to forge?$"

LavaridgeTown_Blacksmith_Text_Cancel:
	.string "Don't worry, you can come any time.$"

LavaridgeTown_Blacksmith_Text_ThankYou:
	.string "So It was you that reestablished the\n"
	.string "lava flow coming from My. Chimney,\l"
	.string "right?\p"
	.string "I'm in great debt to you!\p"
	.string "Since you saved my career as Blacksmith,\n"
	.string "I won't charge the labor cost to forge\l"
	.string "an item.\p"
	.string "I still need the necessary materials,\n"
	.string "unfortunately.$"

LavaridgeTown_Blacksmith_Text_NoForge:
	.string "Hello, kid! I'm the best blacksmith\n"
	.string "in Lavaridge Town, but since the\l"
	.string "earthquake the lava flow has ceased.\p"
	.string "Unfortunately, I need the magma so\n"
	.string "I won't be able to forge any of\l"
	.string "my specialities for you…\p"
	.string "…\p"
	.string "I'll have to retire soon.$"

LavaridgeTown_Blacksmith_Text_MasamuneMaterials:
	.string "Materials:\n"
	.string "1 Metal Coat,\l"
	.string "1 Bright Powder,\l"
	.string "1 Nugget.$"

LavaridgeTown_Blacksmith_Text_MuramasaMaterials:
	.string "Materials:\n"
	.string "1 Metal Coat,\l"
	.string "1 Razor Claw,\l"
	.string "1 Nugget.$"

LavaridgeTown_Blacksmith_Text_FireblenderMaterials:
	.string "Materials:\n"
	.string "1 Metal Coat,\l"
	.string "1 Fire Stone,\l"
	.string "1 Nugget.$"

LavaridgeTown_Blacksmith_Text_IceFalchionMaterials:
	.string "Materials:\n"
	.string "1 Metal Coat,\l"
	.string "1 Ice Stone,\l"
	.string "1 Nugget.$"

LavaridgeTown_Blacksmith_Text_StrongShieldMaterials:
	.string "Materials:\n"
	.string "3 Metal Coat,\l"
	.string "1 Hard Stone.$"

LavaridgeTown_Blacksmith_Text_GoldenHammerMaterials:
	.string "Materials:\n"
	.string "5 Nugget.$"

LavaridgeTown_Blacksmith_Text_SoYourChoiceIsTheItemX:
	.string "So you want me to\n"
	.string "forge the {STR_VAR_1}?$"

LavaridgeTown_Blacksmith_Text_NoMaterial:
	.string "Seems that you don't have enough\n"
	.string "materials for the forge…$"

LavaridgeTown_Blacksmith_Text_HereYouGo:
	.string "Excellent!\p"
	.string "Now I'll need some time to forge\n"
	.string "using these materials.\p"
	.string "{PLAYER} handed the materials.$"

@ Forge Ready

LavaridgeTown_Blacksmith_EventScript_ForgedItemIsReady:
	compare VAR_WHICH_ITEM_FORGED, 1
	goto_if_eq LavaridgeTown_Blacksmith_EventScript_MasamuneReady
	compare VAR_WHICH_ITEM_FORGED, 2
	goto_if_eq LavaridgeTown_Blacksmith_EventScript_MuramasaReady
	compare VAR_WHICH_ITEM_FORGED, 3
	goto_if_eq LavaridgeTown_Blacksmith_EventScript_FireBlenderReady
	compare VAR_WHICH_ITEM_FORGED, 4
	goto_if_eq LavaridgeTown_Blacksmith_EventScript_IceFalchionReady
	compare VAR_WHICH_ITEM_FORGED, 5
	goto_if_eq LavaridgeTown_Blacksmith_EventScript_StrongShieldReady
	compare VAR_WHICH_ITEM_FORGED, 6
	goto_if_eq LavaridgeTown_Blacksmith_EventScript_GoldenHammerReady
	end

LavaridgeTown_Blacksmith_EventScript_MasamuneReady:
	setvar VAR_TEMP_1, ITEM_MASAMUNE
	bufferitemname 0, ITEM_MASAMUNE
	msgbox LavaridgeTown_Blacksmith_Text_ForgedItemIsReady, MSGBOX_DEFAULT
	goto LavaridgeTown_Blacksmith_EventScript_ReceiveForgedItem
	end

LavaridgeTown_Blacksmith_EventScript_MuramasaReady:
	setvar VAR_TEMP_1, ITEM_MURAMASA
	bufferitemname 0, ITEM_MURAMASA
	msgbox LavaridgeTown_Blacksmith_Text_ForgedItemIsReady, MSGBOX_DEFAULT
	goto LavaridgeTown_Blacksmith_EventScript_ReceiveForgedItem
	end

LavaridgeTown_Blacksmith_EventScript_FireBlenderReady:
	setvar VAR_TEMP_1, ITEM_FIREBLENDER
	bufferitemname 0, ITEM_FIREBLENDER
	msgbox LavaridgeTown_Blacksmith_Text_ForgedItemIsReady, MSGBOX_DEFAULT
	goto LavaridgeTown_Blacksmith_EventScript_ReceiveForgedItem
	end

LavaridgeTown_Blacksmith_EventScript_IceFalchionReady:
	setvar VAR_TEMP_1, ITEM_ICE_FALCHION
	bufferitemname 0, ITEM_ICE_FALCHION
	msgbox LavaridgeTown_Blacksmith_Text_ForgedItemIsReady, MSGBOX_DEFAULT
	goto LavaridgeTown_Blacksmith_EventScript_ReceiveForgedItem
	end

LavaridgeTown_Blacksmith_EventScript_StrongShieldReady:
	setvar VAR_TEMP_1, ITEM_STRONG_SHIELD
	bufferitemname 0, ITEM_STRONG_SHIELD
	msgbox LavaridgeTown_Blacksmith_Text_ForgedItemIsReady, MSGBOX_DEFAULT
	goto LavaridgeTown_Blacksmith_EventScript_ReceiveForgedItem
	end

LavaridgeTown_Blacksmith_EventScript_GoldenHammerReady:
	setvar VAR_TEMP_1, ITEM_GOLDEN_HAMMER
	bufferitemname 0, ITEM_GOLDEN_HAMMER
	msgbox LavaridgeTown_Blacksmith_Text_ForgedItemIsReady, MSGBOX_DEFAULT
	goto LavaridgeTown_Blacksmith_EventScript_ReceiveForgedItem
	end

LavaridgeTown_Blacksmith_EventScript_ReceiveForgedItem:
	giveitem VAR_TEMP_1
	compare VAR_RESULT, FALSE
	goto_if_eq BattleFrontier_ExchangeServiceCorner_EventScript_BagFull
	setvar VAR_BLACKSMITH_FORGE_STATE, 0
	setflag FLAG_TEMP_1
	release
	end

LavaridgeTown_Blacksmith_Text_ForgedItemIsReady:
	.string "Thanks for waiting!\p"
	.string "Your item has been forged\n"
	.string "with great success!\p"
	.string "Here, take your {STR_VAR_1}!$"


LavaridgeTown_Blacksmith_EventScript_StillForging::
	msgbox LavaridgeTown_Blacksmith_Text_StillForging, MSGBOX_DEFAULT
	release
	end

LavaridgeTown_Blacksmith_Text_StillForging:
	.string "My technique is magnificent!\p"
	.string "But old methods take a long time\n"
	.string "to forge.\p"
	.string "So, uh… How about you go play\n"
	.string "outside for a while?$"

