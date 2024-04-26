.set LOCALID_GRUNT_1, 10
.set LOCALID_GRUNT_2, 11
.set LOCALID_GRUNT_3, 12
.set LOCALID_GRUNT_4, 13
.set LOCALID_MAXIE, 14
.set LOCALID_SCOTT, 16
.set LOCALID_BRENDAN, 18
.set LOCALID_MAY, 19

MossdeepCity_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, MossdeepCity_OnTransition
	.byte 0

MossdeepCity_OnTransition:
	@clearflag FLAG_MOSSDEEP_GYM_SWITCH_1
	clearflag FLAG_MOSSDEEP_GYM_SWITCH_2
	clearflag FLAG_MOSSDEEP_GYM_SWITCH_3
	clearflag FLAG_MOSSDEEP_GYM_SWITCH_4
	call_if_set FLAG_SYS_WEATHER_CTRL, Common_EventScript_SetAbnormalWeather
	end

MossdeepCity_EventScript_PokefanF::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_HM08, MossdeepCity_EventScript_PokefanFMagmaGone
	msgbox MossdeepCity_Text_SpaceCenterReceivedLetter, MSGBOX_DEFAULT
	release
	end

MossdeepCity_EventScript_PokefanFMagmaGone::
	msgbox MossdeepCity_Text_SpaceCenterLaunchingRockets, MSGBOX_DEFAULT
	release
	end

MossdeepCity_EventScript_Sailor::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_HM08, MossdeepCity_EventScript_SailorMagmaGone
	msgbox MossdeepCity_Text_MossdeepTargetedByMagma, MSGBOX_DEFAULT
	release
	end

MossdeepCity_EventScript_SailorMagmaGone::
	msgbox MossdeepCity_Text_FeelReliefOnLand, MSGBOX_DEFAULT
	release
	end

MossdeepCity_EventScript_NinjaBoy::
	msgbox MossdeepCity_Text_WailmerWatching, MSGBOX_NPC
	end

MossdeepCity_EventScript_ExpertM::
	msgbox MossdeepCity_Text_LifeNeedsSeaToLive, MSGBOX_NPC
	end

MossdeepCity_EventScript_Girl::
	msgbox MossdeepCity_Text_NiceIfWorldCoveredByFlowers, MSGBOX_NPC
	end

MossdeepCity_EventScript_Woman::
	msgbox MossdeepCity_Text_SpecialSpaceCenterRock, MSGBOX_NPC
	end

MossdeepCity_EventScript_WhiteRock::
	msgbox MossdeepCity_Text_ItsAWhiteRock, MSGBOX_SIGN
	end

MossdeepCity_EventScript_GymSign::
	msgbox MossdeepCity_Text_GymSign, MSGBOX_SIGN
	end

MossdeepCity_EventScript_CitySign::
	msgbox MossdeepCity_Text_CitySign, MSGBOX_SIGN
	end

MossdeepCity_EventScript_BillSign::
	msgbox MossdeepCity_Text_BillSign, MSGBOX_SIGN
	end

MossdeepCity_EventScript_SpaceCenterSign::
	msgbox MossdeepCity_Text_SpaceCenterSign, MSGBOX_SIGN
	end

MossdeepCity_EventScript_VisitedMossdeep::
	setflag FLAG_VISITED_MOSSDEEP_CITY
	setvar VAR_TEMP_1, 1
	end

MossdeepCity_EventScript_TeamMagmaEnterSpaceCenter::
	lockall
	applymovement LOCALID_MAXIE, MossdeepCity_Movement_MaxieGestureToSpaceCenter
	waitmovement 0
	applymovement LOCALID_GRUNT_1, MossdeepCity_Movement_GruntFaceSpaceCenter
	applymovement LOCALID_GRUNT_2, MossdeepCity_Movement_GruntFaceSpaceCenter
	applymovement LOCALID_GRUNT_3, MossdeepCity_Movement_GruntFaceSpaceCenter
	applymovement LOCALID_GRUNT_4, MossdeepCity_Movement_GruntFaceSpaceCenter
	waitmovement 0
	applymovement LOCALID_MAXIE, MossdeepCity_Movement_MaxieEnterSpaceCenter
	applymovement LOCALID_GRUNT_1, MossdeepCity_Movement_Grunt1EnterSpaceCenter
	applymovement LOCALID_GRUNT_2, MossdeepCity_Movement_Grunt2EnterSpaceCenter
	applymovement LOCALID_GRUNT_3, MossdeepCity_Movement_Grunt3EnterSpaceCenter
	applymovement LOCALID_GRUNT_4, MossdeepCity_Movement_Grunt4EnterSpaceCenter
	waitmovement 0
	removeobject LOCALID_MAXIE
	removeobject LOCALID_GRUNT_1
	removeobject LOCALID_GRUNT_2
	removeobject LOCALID_GRUNT_3
	removeobject LOCALID_GRUNT_4
	delay 30
	setvar VAR_MOSSDEEP_CITY_STATE, 2
	setflag FLAG_HIDE_MOSSDEEP_CITY_TEAM_MAGMA
	releaseall
	end

MossdeepCity_Movement_MaxieGestureToSpaceCenter:
	delay_16
	face_right
	delay_16
	delay_16
	delay_16
	delay_16
	face_left
	delay_16
	delay_16
	step_end

MossdeepCity_Movement_GruntFaceSpaceCenter:
	face_right
	delay_16
	delay_16
	delay_16
	step_end

MossdeepCity_Movement_MaxieEnterSpaceCenter:
	walk_down
	walk_right
	walk_right
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

MossdeepCity_Movement_Grunt1EnterSpaceCenter:
	delay_16
	delay_8
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

MossdeepCity_Movement_Grunt2EnterSpaceCenter:
	delay_16
	delay_8
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

MossdeepCity_Movement_Grunt3EnterSpaceCenter:
	delay_16
	delay_8
	walk_down
	walk_right
	walk_right
	walk_right
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

MossdeepCity_Movement_Grunt4EnterSpaceCenter:
	delay_16
	delay_8
	walk_right
	walk_right
	walk_right
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

MossdeepCity_EventScript_Man::
	lock
	faceplayer
	msgbox MossdeepCity_Text_SurfExhilarating, MSGBOX_DEFAULT
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

MossdeepCity_EventScript_KingsRockBoy::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_KINGS_ROCK, MossdeepCity_EventScript_ReceivedKingsRock
	msgbox MossdeepCity_Text_WantKingsRockStevenGaveMe, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq MossdeepCity_EventScript_DeclineKingsRock
	msgbox MossdeepCity_Text_YouCanKeepIt, MSGBOX_DEFAULT
	giveitem ITEM_KINGS_ROCK
	compare VAR_RESULT, FALSE
	goto_if_eq Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_KINGS_ROCK
	release
	end

MossdeepCity_EventScript_ReceivedKingsRock::
	msgbox MossdeepCity_Text_StevensHouseOverThere, MSGBOX_DEFAULT
	release
	end

MossdeepCity_EventScript_DeclineKingsRock::
	msgbox MossdeepCity_Text_WhatToDoWithWeirdRock, MSGBOX_DEFAULT
	release
	end

MossdeepCity_EventScript_BlackBelt::
	msgbox MossdeepCity_Text_SootopolisNewGymLeader, MSGBOX_NPC
	end

MossdeepCity_EventScript_Scott::
	lock
	faceplayer
	msgbox MossdeepCity_Text_ScottSomethingWrongWithTown, MSGBOX_DEFAULT
	closemessage
	compare VAR_FACING, DIR_NORTH
	call_if_eq MossdeepCity_EventScript_ScottExitNorth
	compare VAR_FACING, DIR_EAST
	call_if_eq MossdeepCity_EventScript_ScottExitEast
	addvar VAR_SCOTT_STATE, 1
	removeobject LOCALID_SCOTT
	release
	end

MossdeepCity_EventScript_ScottExitNorth::
	applymovement OBJ_EVENT_ID_PLAYER, MossdeepCity_Movement_PlayerWatchScottExit
	applymovement LOCALID_SCOTT, MossdeepCity_Movement_ScottExitNorth
	waitmovement 0
	return

MossdeepCity_EventScript_ScottExitEast::
	applymovement OBJ_EVENT_ID_PLAYER, MossdeepCity_Movement_PlayerWatchScottExit
	applymovement LOCALID_SCOTT, MossdeepCity_Movement_ScottExitEast
	waitmovement 0
	return

MossdeepCity_Movement_PlayerWatchScottExit:
	delay_16
	delay_16
	walk_in_place_fastest_left
	step_end

MossdeepCity_Movement_ScottExitNorth:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

MossdeepCity_Movement_ScottExitEast:
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

MossdeepCity_Text_WantKingsRockStevenGaveMe:
	.string "I got this from Steven, but I don't\n"
	.string "know what it's good for.\p"
	.string "I think it's called King's Rock.\n"
	.string "Do you want it?$"

MossdeepCity_Text_YouCanKeepIt:
	.string "Why would you want it?\n"
	.string "You're weird.\p"
	.string "You can keep it, but keep it a secret\n"
	.string "from Steven.$"

MossdeepCity_Text_StevensHouseOverThere:
	.string "Steven's house is right over there!$"

MossdeepCity_Text_WhatToDoWithWeirdRock:
	.string "Yeah, you think so, too! What are you\n"
	.string "supposed to do with some weird rock?$"

MossdeepCity_Text_WailmerWatching:
	.string "Around Mossdeep, you can see wild\n"
	.string "Wailmer.\p"
	.string "It's called, uh…\n"
	.string "What was it now…\p"
	.string "WAI, WAI, WAI…\p"
	.string "Wailmer watching!$"

MossdeepCity_Text_SpaceCenterReceivedLetter:
	.string "The island's Space Center has been\n"
	.string "launching huge rockets.\p"
	.string "There's been some kind of an uproar\n"
	.string "over a letter they received recently.$"

MossdeepCity_Text_SpaceCenterLaunchingRockets:
	.string "The island's Space Center has been\n"
	.string "launching huge rockets.$"

MossdeepCity_Text_MossdeepTargetedByMagma:
	.string "I heard from a Sailor buddy that\n"
	.string "Team Aqua set up shop in Lilycove.\p"
	.string "I also heard that someone came along\n"
	.string "and wiped the floor with them!\p"
	.string "But Mossdeep here's been targeted\n"
	.string "by that Team Magma.\p"
	.string "If you want to know what they're up to,\n"
	.string "go visit the Space Center.$"

MossdeepCity_Text_FeelReliefOnLand:
	.string "I'm a Sailor, so the sea's obviously\n"
	.string "more important to me.\p"
	.string "But you know? When I get back on land\n"
	.string "after a long voyage, I do feel relief!$"

MossdeepCity_Text_NiceIfWorldCoveredByFlowers:
	.string "Wouldn't it be nice?\p"
	.string "If the whole world was covered in\n"
	.string "plants and flowers like this island?$"

MossdeepCity_Text_LifeNeedsSeaToLive:
	.string "The guardian of the seas swims\n"
	.string "all around the world…\p"
	.string "…\p"
	.string "…\p"
	.string "No, I'm not talking about the\n"
	.string "legendary Kyogre…\p"
	.string "I'm talking about a sea dragon\n"
	.string "Pokémon.\p"
	.string "This Pokémon travels around the world\n"
	.string "sailing the seas.\p"
	.string "Once a year, this Pokémon passes\n"
	.string "through the sea of Hoenn, and\l"
	.string "sometimes disputes territory with\l"
	.string "Kyogre!\p"
	.string "After these disputes, he rests in\n"
	.string "submerged caves near Mossdeep City!$"

MossdeepCity_Text_SurfExhilarating:
	.string "A voyage on a ship is fine.\p"
	.string "But crossing the sea with Pokémon\n"
	.string "using Surf…\p"
	.string "Now that's an exhilarating trip!\n"
	.string "Wouldn't you agree, youngster?$"

MossdeepCity_Text_SpecialSpaceCenterRock:
	.string "This rock has a special meaning to\n"
	.string "the people at the Space Center.\p"
	.string "They put it here as their wish for\n"
	.string "their rockets to fly safely.\p"
	.string "When you make a wish, what do you use?\n"
	.string "Do you wish upon a star?\p"
	.string "I use a wish tag to make it happen.\n"
	.string "That's what I do.$"

MossdeepCity_Text_ItsAWhiteRock:
	.string "It's a white rock.$"

MossdeepCity_Text_GymSign:
	.string "Mossdeep City Pokémon Gym\n"
	.string "Leaders: Liza & Tate\p"
	.string "“The mystic power!”$"

MossdeepCity_Text_CitySign:
	.string "Mossdeep City\n"
	.string "“Our slogan: Cherish Pokémon!”$"

MossdeepCity_Text_BillSign:
	.string "Bill's House!$"

MossdeepCity_Text_SpaceCenterSign:
	.string "Mossdeep Space Center\n"
	.string "“The closest place to space.”$"

MossdeepCity_Text_ScottSomethingWrongWithTown:
	.string "Scott: {PLAYER}{KUN}, feeling good?\n"
	.string "I'm doing great!\p"
	.string "I'd heard Mossdeep's Gym Leader is\n"
	.string "pretty strong and mystical energy\l"
	.string "around it… I heard that Pokémon\l"
	.string "devolve in battle! So I decided to come\l"
	.string "take a look-see for myself.\p"
	.string "But there's something wrong about\n"
	.string "this town.\p"
	.string "People are going on about a warning\n"
	.string "letter and the Space Center…\p"
	.string "I don't think it concerns me in any\n"
	.string "way, though.$"

MossdeepCity_Text_SootopolisNewGymLeader:
	.string "Ahh… It feels great letting the waves\n"
	.string "wash over my feet…\p"
	.string "Speaking of the waves, you know that\n"
	.string "island city Sootopolis?\p"
	.string "I think the Gym there had a new\n"
	.string "Leader come in.\p"
	.string "People tell me the new Leader was\n"
	.string "mentored by Juan.$"

@ VAR_BRENDAN_MAY_STATE

MossdeepCity_EventScript_VisitedMossdeepBrendanAndMayBattle1::
	lock
	setflag FLAG_VISITED_MOSSDEEP_CITY
	setvar VAR_0x8008, 1
	addobject LOCALID_BRENDAN
	addobject LOCALID_MAY
	goto MossdeepCity_EventScript_BrendanMayApproach

MossdeepCity_EventScript_VisitedMossdeepBrendanAndMayBattle2::
	lock
	setflag FLAG_VISITED_MOSSDEEP_CITY
	setvar VAR_0x8008, 2
	addobject LOCALID_BRENDAN
	addobject LOCALID_MAY
	goto MossdeepCity_EventScript_BrendanMayApproach

MossdeepCity_EventScript_VisitedMossdeepBrendanAndMayBattle3::
	lock
	setflag FLAG_VISITED_MOSSDEEP_CITY
	setvar VAR_0x8008, 3
	addobject LOCALID_BRENDAN
	addobject LOCALID_MAY
	setobjectxy LOCALID_BRENDAN, 32, 21
	setobjectxy LOCALID_MAY, 33, 21
	goto MossdeepCity_EventScript_BrendanMayApproach

MossdeepCity_EventScript_VisitedMossdeepBrendanAndMayBattle4::
	lock
	setflag FLAG_VISITED_MOSSDEEP_CITY
	setvar VAR_0x8008, 4
	addobject LOCALID_BRENDAN
	addobject LOCALID_MAY
	setobjectxy LOCALID_BRENDAN, 32, 21
	setobjectxy LOCALID_MAY, 33, 21
	goto MossdeepCity_EventScript_BrendanMayApproach

MossdeepCity_EventScript_BrendanMayApproach:
	applymovement LOCALID_BRENDAN, MossdeepCity_Movement_BrendanMayApproach
	applymovement LOCALID_MAY, MossdeepCity_Movement_BrendanMayApproach
	waitmovement 0
	msgbox MossdeepCity_Text_MayaskFeeling, MSGBOX_DEFAULT
	applymovement LOCALID_BRENDAN, Common_Movement_WalkInPlaceFastestDown
	waitmovement 0
	msgbox MossdeepCity_Text_BrendanExplainGym, MSGBOX_DEFAULT
	closemessage
	multi_1_vs_2 TRAINER_BRENDAN_MOSSDEEP_CITY, BrendanDefeatText, TRAINER_MAY_MOSSDEEP_CITY, MayDefeatText
	specialvar VAR_RESULT, GetBattleOutcome
    compare VAR_RESULT, B_OUTCOME_LOST
    goto_if_eq MossdeepCity_EventScript_EventScript_PlayerLostTheFight
	msgbox MossdeepCity_Text_PlayerWonBattle, MSGBOX_DEFAULT
	closemessage
	checkitem ITEM_ZYGARDE_CUBE, 1
	compare VAR_RESULT, FALSE
	goto_if_eq MossdeepCity_EventScript_NoZygardeCube	
	playfanfare MUS_OBTAIN_ITEM
	TryGiveRandomZygardePieces
	msgbox MossdeepCity_Text_GiveZygarde, MSGBOX_DEFAULT
	waitfanfare
	closemessage
	goto MossdeepCity_EventScript_EventScript_AfterBattle

MossdeepCity_EventScript_NoZygardeCube:
	msgbox MossdeepCity_Text_NoZygardeCube, MSGBOX_DEFAULT

MossdeepCity_EventScript_EventScript_PlayerLostTheFight:
	@fadescreen FADE_TO_BLACK
	@special SetCB2WhiteOut
	@waitstate
	special HealPlayerParty
	msgbox MossdeepCity_Text_PlayerLostBattle, MSGBOX_DEFAULT
	closemessage
	goto MossdeepCity_EventScript_EventScript_AfterBattle

MossdeepCity_EventScript_EventScript_AfterBattle:
	msgbox MossdeepCity_Text_VisitBill, MSGBOX_DEFAULT
	closemessage
	compare VAR_0x8008, 1
	call_if_eq MossdeepCity_EventScript_ExitFromRight
	compare VAR_0x8008, 3
	call_if_eq MossdeepCity_EventScript_ExitFromRight
	compare VAR_0x8008, 2
	call_if_eq MossdeepCity_EventScript_ExitFromLeft
	compare VAR_0x8008, 4
	call_if_eq MossdeepCity_EventScript_ExitFromLeft
	removeobject LOCALID_BRENDAN
	removeobject LOCALID_MAY
	setvar VAR_BRENDAN_MAY_STATE, 1
	release
	end

MossdeepCity_EventScript_ExitFromLeft:
	applymovement LOCALID_BRENDAN, MossdeepCity_Movement_DownExit
	applymovement LOCALID_MAY, MossdeepCity_Movement_LeftExit
	waitmovement 0
	return

MossdeepCity_EventScript_ExitFromRight:
	applymovement LOCALID_BRENDAN, MossdeepCity_Movement_RightExit
	applymovement LOCALID_MAY, MossdeepCity_Movement_DownExit
	waitmovement 0
	return

MossdeepCity_Movement_LeftExit:
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

MossdeepCity_Movement_RightExit:
	walk_right
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

MossdeepCity_Movement_DownExit:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

MossdeepCity_Movement_BrendanMayApproach:
	walk_down
	walk_down
	emote_exclamation_mark
	delay_16
	walk_down
	walk_down
	walk_down
	step_end

MossdeepCity_Text_PlayerLostBattle:
	.string "Brendan & May: Better train\n"
	.string "your Pokémon before entering\l"
	.string "the Mossdeep Gym!$"

MossdeepCity_Text_PlayerWonBattle:
	.string "Brendan: Your Pokémon\n"
	.string "grew a lot since our last\l"
	.string "encounter!\p"
	.string "May: Since you won, we will\n"
	.string "give you these Zygarde pieces\l"
	.string "we collected!$"

MossdeepCity_Text_MayaskFeeling:
	.string "May: {PLAYER}{KUN}, feeling good?\n"
	.string "I've got sick when traveling\l"
	.string "across the sea too…$"

MossdeepCity_Text_BrendanExplainGym:
	.string "Brendan: Forget about it, {PLAYER}{KUN}!\p"
	.string "What is sick is the mystical power\n"
	.string "inside the Gym. I've never seen\l"
	.string "something like that in my life!\p"
	.string "But I won't make your life easier!\n"
	.string "I'll let you find out for yourself.\p"
	.string "It's been a while, right?\n"
	.string "So let's battle?$"

MossdeepCity_Text_NoZygardeCube:
	.string "May: Seems that you don't have\n"
	.string "Zygarde Cube…$"

MossdeepCity_Text_GiveZygarde:
	.string "{PLAYER}{KUN} receive {STR_VAR_1} Zygarde Cores\n"
	.string "and {STR_VAR_2} Zygarde Cells!$"

MossdeepCity_Text_VisitBill:
	.string "Brendan & May: Since you are here,\n"
	.string "you should visit Bill to let him\l"
	.string "look at the Zygarde pieces you\l"
	.string "collected!\p"
	.string "Farewell, {PLAYER}{KUN}!$"
