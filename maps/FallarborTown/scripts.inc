.set LOCALID_FALLARBOR_TOWN_GRUNT, 6

FallarborTown_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, FallarborTown_OnTransition
	.byte 0

FallarborTown_OnTransition:
	call FallarborTown_EventScript_TryHideOrShowSpiritombWisps
	setflag FLAG_VISITED_FALLARBOR_TOWN
	setvar VAR_CONTEST_HALL_STATE, 0
	end

FallarborTown_EventScript_TryHideOrShowSpiritombWisps:
	gettimeofday
	compare VAR_0x8000, 2
	goto_if_eq FallarborTown_EventScript_TryShowWisps
	goto FallarborTown_EventScript_HideWisps
	end

FallarborTown_EventScript_TryShowWisps:
	goto_if_unset FLAG_RECEIVED_WISPS_15, FallarborTown_EventScript_ShowWisp
	return

FallarborTown_EventScript_ShowWisp:
	clearflag FLAG_HIDE_WISPS_15
	return

FallarborTown_EventScript_HideWisps:
	setflag FLAG_HIDE_WISPS_15
	return

FallarborTown_EventScript_ExpertM::
	lock
	faceplayer
	goto_if_set FLAG_HIDE_VILLAINS_IN_METEOR_FALLS_AND_FALLARBOR_TOWN, FallarborTown_EventScript_ExpertMNormal
	msgbox FallarborTown_Text_ShadyCharactersCozmosHome, MSGBOX_DEFAULT
	release
	end

FallarborTown_EventScript_ExpertMNormal::
	msgbox FallarborTown_Text_RegionKnownForMeteors, MSGBOX_DEFAULT
	release
	end

FallarborTown_EventScript_Girl::
	lock
	faceplayer
	goto_if_unset FLAG_HIDE_VILLAINS_IN_METEOR_FALLS_AND_FALLARBOR_TOWN, FallarborTown_EventScript_GirlEvilTeam
	msgbox FallarborTown_Text_MyPreciousAzurill, MSGBOX_NPC
	end

FallarborTown_EventScript_GirlEvilTeam:
	msgbox FallarborTown_Text_EvilTeam, MSGBOX_DEFAULT
	release
	end


FallarborTown_EventScript_Gentleman::
	msgbox FallarborTown_Text_HaveYouChallengedFlannery, MSGBOX_NPC
	end

FallarborTown_EventScript_Azurill::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_AZURILL, 0
	msgbox FallarborTown_Text_Azurill, MSGBOX_DEFAULT
	waitmoncry
	release
	end

FallarborTown_EventScript_BattleTentSign::
	msgbox FallarborTown_Text_BattleTentSign, MSGBOX_SIGN
	end

FallarborTown_EventScript_TownSign::
	msgbox FallarborTown_Text_TownSign, MSGBOX_SIGN
	end

FallarborTown_EventScript_MoveTutorSign::
	msgbox FallarborTown_Text_MoveTutorSign, MSGBOX_SIGN
	end

FallarborTown_Text_ShadyCharactersCozmosHome:
	.string "Something's happening,\n"
	.string "and I don't like it!\p"
	.string "I've seen shady characters wandering\n"
	.string "in and out of Prof. Cozmo's home…$"

FallarborTown_Text_RegionKnownForMeteors:
	.string "This region's been known for meteors\n"
	.string "since the olden days.\p"
	.string "They say Meteor Falls was gouged out\n"
	.string "by a falling meteorite long ago.$"

FallarborTown_Text_EvilTeam:
	.string "There's a lot of weird people\n"
	.string "walking around Falllabor Town…$"

FallarborTown_Text_MyPreciousAzurill:
	.string "See! Take a look!\n"
	.string "This is my precious Azurill!\p"
	.string "It's slick and smooth and plushy, too!$"

FallarborTown_Text_Azurill:
	.string "Azurill: Rooreelooo.$"

FallarborTown_Text_HaveYouChallengedFlannery:
	.string "Have you already challenged Flannery,\n"
	.string "the Leader of Lavaridge Gym?\p"
	.string "The girl's grandfather was famous.\n"
	.string "He was one of the Elite Four in the\l"
	.string "Pokémon League at one point.\p"
	.string "It wouldn't surprise me to see Flannery\n"
	.string "become a great Trainer in her own\l"
	.string "right.$"

FallarborTown_Text_BattleTentSign:
	.string "Battle Tent Fallarbor Site\n"
	.string "“May the Greatest Teams Gather!”$"

FallarborTown_Text_TownSign:
	.string "Fallarbor Town\n"
	.string "“A farm community with small gardens.”$"

FallarborTown_Text_MoveTutorSign:
	.string "Move Reminder's House\n"
	.string "“New moves taught to Pokémon.”$"

@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
FallarborTown_EventScript_TeamGalacticGrunt1::
	msgbox FallarborTown_Text_TeamGalacticGrunt1, MSGBOX_NPC
	end
FallarborTown_Text_TeamGalacticGrunt1:
	.string "Boss told us to stand here…$"

FallarborTown_EventScript_TeamGalacticGrunt2::
	msgbox FallarborTown_Text_TeamGalacticGrunt2, MSGBOX_NPC
	end
FallarborTown_Text_TeamGalacticGrunt2:
	.string "We are working with\n"
	.string "Team Rocket because they\l"
	.string "took control of Kanto!$"

FallarborTown_EventScript_TeamGalacticGrunt3::
	msgbox FallarborTown_Text_TeamGalacticGrunt3, MSGBOX_NPC
	end
FallarborTown_Text_TeamGalacticGrunt3:
	.string "We helped Team Magma by giving them\n"
	.string "a meteorite that we found…$"

@
FallarborTown_EventScript_TeamRocketGruntF2::
	msgbox FallarborTown_Text_TeamRocketGruntF2, MSGBOX_NPC
	end
FallarborTown_Text_TeamRocketGruntF2:
    .string "Boss said he'll take this town\n"
    .string "in the name of Team Rocket\l"
    .string "and Team Galactic!$"

FallarborTown_EventScript_TeamRocketGruntM1::
	msgbox FallarborTown_Text_TeamRocketGruntM1, MSGBOX_NPC
	end
FallarborTown_Text_TeamRocketGruntM1:
    .string "Since there hasn't been any\n"
	.string "snooping kids like you in Kanto,\l"
	.string "we, the Team Rocket, have dominated\l"
	.string "Kanto and are now expanding our\l"
	.string "activity to Hoenn!$"

FallarborTown_EventScript_TeamRocketGruntF1::
	lock
	faceplayer
	goto_if_set FLAG_BEAT_ROCKET_GRUNT_FALLARBOR_TOWN, FallarborTown_EventScript_TeamRocketGruntF1Defeated
	msgbox FallarborTown_Text_TeamRocketGruntBattle, MSGBOX_DEFAULT
	closemessage
	trainerbattle_no_intro TRAINER_ROCKET_GRUNT_FALLARBORTOWN, FallarborTown_EventScript_Text_GruntDefeat
	setflag FLAG_BEAT_ROCKET_GRUNT_FALLARBOR_TOWN
	applymovement LOCALID_FALLARBOR_TOWN_GRUNT, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

FallarborTown_EventScript_TeamRocketGruntF1Defeated:
	msgbox FallarborTown_Text_TeamRocketGruntBattleGetOff, MSGBOX_DEFAULT
	applymovement LOCALID_FALLARBOR_TOWN_GRUNT, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

FallarborTown_Text_TeamRocketGruntBattleGetOff:
    .string "What do you want?\n"
    .string "Get lost!$"

FallarborTown_Text_TeamRocketGruntBattle:
    .string "Don't get defiant!\n"
    .string "Or I'll have to hurt you!$"

FallarborTown_EventScript_Text_GruntDefeat:
	.string "No way you can stop us!$"
