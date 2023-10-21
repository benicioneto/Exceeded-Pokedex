.set LOCALID_TWIN, 2

VerdanturfTown_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, VerdanturfTown_OnTransition
	.byte 0

VerdanturfTown_OnTransition:
	call VerdanturfTown_EventScript_TryHideOrShowSpiritombWisps
	setflag FLAG_VISITED_VERDANTURF_TOWN
	setvar VAR_CONTEST_HALL_STATE, 0
	end

VerdanturfTown_EventScript_TryHideOrShowSpiritombWisps:
	gettimeofday
	compare VAR_0x8000, 2
	goto_if_eq VerdanturfTown_EventScript_TryShowWisps
	goto VerdanturfTown_EventScript_HideWisps
	end

VerdanturfTown_EventScript_TryShowWisps:
	goto_if_unset FLAG_RECEIVED_WISPS_14, VerdanturfTown_EventScript_ShowWisp
	return

VerdanturfTown_EventScript_ShowWisp:
	clearflag FLAG_HIDE_WISPS_14
	return

VerdanturfTown_EventScript_HideWisps:
	setflag FLAG_HIDE_WISPS_14
	return

VerdanturfTown_EventScript_Twin::
	lock
	faceplayer
	goto_if_set FLAG_RUSTURF_TUNNEL_OPENED, VerdanturfTown_EventScript_TwinTunnelOpen
	msgbox VerdanturfTown_Text_ManTryingToDigTunnel, MSGBOX_DEFAULT
	applymovement LOCALID_TWIN, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

VerdanturfTown_EventScript_TwinTunnelOpen::
	msgbox VerdanturfTown_Text_ManDugTunnelForLove, MSGBOX_DEFAULT
	applymovement LOCALID_TWIN, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

VerdanturfTown_EventScript_Man::
	msgbox VerdanturfTown_Text_AirCleanHere, MSGBOX_NPC
	end

VerdanturfTown_EventScript_Camper::
	msgbox VerdanturfTown_Text_MakeBattleTentDebut, MSGBOX_NPC
	end

VerdanturfTown_EventScript_Boy::
	lock
	faceplayer
	goto_if_set FLAG_RUSTURF_TUNNEL_OPENED, VerdanturfTown_EventScript_BoyTunnelOpen
	msgbox VerdanturfTown_Text_GuyTryingToBustThroughCave, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_EventScript_BoyTunnelOpen::
	msgbox VerdanturfTown_Text_EasyToGetToRustboroNow, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_EventScript_TownSign::
	msgbox VerdanturfTown_Text_TownSign, MSGBOX_SIGN
	goto_if_set FLAG_SCHROOMISH_SEARCH, VerdanturfTown_EventScript_SchroomishWasFound
	end

VerdanturfTown_EventScript_SchroomishWasFound:
	goto_if_unset FLAG_SCHROOMISH_FIND, VerdanturfTown_EventScript_SchroomishWasFound2
	end

VerdanturfTown_EventScript_SchroomishWasFound2:
	lock
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
	waitmovement 0
	msgbox VerdanturfTown_Text_SchroomishWasFound, MSGBOX_DEFAULT
	closemessage
	setflag FLAG_SCHROOMISH_FIND
	release
	end

VerdanturfTown_Text_SchroomishWasFound:
	.string "Schroomish was found\n"
	.string "behind the sign!$"


VerdanturfTown_EventScript_WandasHouseSign::
	msgbox VerdanturfTown_Text_WandasHouse, MSGBOX_SIGN
	end

VerdanturfTown_EventScript_BattleTentSign::
	msgbox VerdanturfTown_Text_BattleTentSign, MSGBOX_SIGN
	end

VerdanturfTown_EventScript_RusturfTunnelSign::
	msgbox VerdanturfTown_Text_RusturfTunnelSign, MSGBOX_SIGN
	end

VerdanturfTown_Text_ManTryingToDigTunnel:
	.string "My papa told me.\p"
	.string "He says this tunnel is full of\n"
	.string "timid Pokémon.\p"
	.string "They get all scared of loud noise and\n"
	.string "make a big uproar.\p"
	.string "So they had to stop the big tunnel\n"
	.string "project.\p"
	.string "But there's one man. He's trying to dig\n"
	.string "the tunnel by himself!$"

VerdanturfTown_Text_ManDugTunnelForLove:
	.string "There was a man who dug a tunnel for\n"
	.string "a lady he loved.\p"
	.string "I don't really get it, but hey!$"

VerdanturfTown_Text_AirCleanHere:
	.string "The way the winds blow, volcanic ash\n"
	.string "is never blown in this direction.\p"
	.string "The air is clean and delicious here.\n"
	.string "Living here should do wonders for even\l"
	.string "frail and sickly people.$"

VerdanturfTown_Text_MakeBattleTentDebut:
	.string "My Pokémon and I, we've been riding\n"
	.string "a hot winning streak.\p"
	.string "So I decided to make my Battle Tent\n"
	.string "debut in this town.$"

VerdanturfTown_Text_GuyTryingToBustThroughCave:
	.string "Did you see the cave next to the\n"
	.string "Pokémon Mart?\p"
	.string "There's a guy in there who's trying to\n"
	.string "bust up boulders so he can bust out\l"
	.string "through to the other side.\p"
	.string "It'd be great if we could go through…\n"
	.string "It'll make it easy to visit Rustboro.$"

VerdanturfTown_Text_EasyToGetToRustboroNow:
	.string "That cave next to the Pokémon Mart\n"
	.string "is now a tunnel to the other side.\p"
	.string "It's great--it's easy to go shop for\n"
	.string "new Devon products in Rustboro now.$"

VerdanturfTown_Text_TownSign:
	.string "Verdanturf Town\p"
	.string "“The windswept highlands with the\n"
	.string "sweet fragrance of grass.”$"

VerdanturfTown_Text_WandasHouse:
	.string "Wanda's House$"

VerdanturfTown_Text_BattleTentSign:
	.string "Battle Tent Verdanturf Site\n"
	.string "“Feast Your Eyes on Battles!”$"

VerdanturfTown_Text_RusturfTunnelSign:
	.string "Rusturf Tunnel\n"
	.string "“Linking Rustboro and Verdanturf\p"
	.string "“The tunnel project has been\n"
	.string "canceled.”$"

VerdanturfTown_EventScript_GirlLostSchroomish::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_INTRIGUING_STONE, VerdanturfTown_EventScript_GirlThanks2
	goto_if_set FLAG_SCHROOMISH_FIND, VerdanturfTown_EventScript_GirlThanks
	msgbox VerdanturfTown_Text_FindMySchroomish, MSGBOX_DEFAULT
	setflag FLAG_SCHROOMISH_SEARCH
	release
	end

VerdanturfTown_EventScript_GirlThanks:
	msgbox VerdanturfTown_Text_GirlThanks, MSGBOX_DEFAULT
	giveitem ITEM_INTRIGUING_STONE
	setflag FLAG_RECEIVED_INTRIGUING_STONE
	release
	end

VerdanturfTown_EventScript_GirlThanks2:
	msgbox VerdanturfTown_Text_GirlThanks2, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_Text_GirlThanks2:
	.string "Thank you!$"

VerdanturfTown_Text_GirlThanks:
	.string "Ah! Mushew!\p"
	.string "Thank you for finding\n"
	.string "my Schroomish!\p"
	.string "I'll give you this. I just found it.\n"
	.string "It has a strange shape and\l"
	.string "it looks amazing.$"

VerdanturfTown_Text_FindMySchroomish:
	.string "My Schroomish got lost…\p"
	.string "Where did it go?$"

