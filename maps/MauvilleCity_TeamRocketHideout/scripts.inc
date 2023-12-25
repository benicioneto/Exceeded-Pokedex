MauvilleCity_TeamRocketHideout_MapScripts::
	.byte 0

MauvilleCity_TeamRocketHideout_Voltorb0::
	setwildbattle SPECIES_VOLTORB, 24, ITEM_NONE
	dowildbattle
	setvar VAR_TEMP_0, 1
	end

MauvilleCity_TeamRocketHideout_Electrode0::
	setwildbattle SPECIES_ELECTRODE, 30, ITEM_NONE
	dowildbattle
	setvar VAR_TEMP_0, 1
	end

MauvilleCity_TeamRocketHideout_Grimer1::
	setwildbattle SPECIES_GRIMER, 24, ITEM_NONE
	dowildbattle
	setvar VAR_TEMP_1, 1
	end

MauvilleCity_TeamRocketHideout_Muk1::
	setwildbattle SPECIES_MUK, 30, ITEM_NONE
	dowildbattle
	setvar VAR_TEMP_1, 1
	end

MauvilleCity_TeamRocketHideout_Magnemite2::
	setwildbattle SPECIES_MAGNEMITE, 24, ITEM_NONE
	dowildbattle
	setvar VAR_TEMP_2, 1
	end

MauvilleCity_TeamRocketHideout_Magneton2::
	setwildbattle SPECIES_MAGNETON, 30, ITEM_NONE
	dowildbattle
	setvar VAR_TEMP_2, 1
	end

MauvilleCity_TeamRocketHideout_Koffing3::
	setwildbattle SPECIES_KOFFING, 24, ITEM_NONE
	dowildbattle
	setvar VAR_TEMP_3, 1
	end

MauvilleCity_TeamRocketHideout_Weezing3::
	setwildbattle SPECIES_WEEZING, 30, ITEM_NONE
	dowildbattle
	setvar VAR_TEMP_3, 1
	end

MauvilleCity_TeamRocketHideout_Grimer4::
	setwildbattle SPECIES_GRIMER, 24, ITEM_NONE
	dowildbattle
	setvar VAR_TEMP_4, 1
	end

MauvilleCity_TeamRocketHideout_Muk4::
	setwildbattle SPECIES_MUK, 30, ITEM_NONE
	dowildbattle
	setvar VAR_TEMP_4, 1
	end

MauvilleCity_TeamRocketHideout_Geodude5::
	setwildbattle SPECIES_GEODUDE, 24, ITEM_NONE
	dowildbattle
	setvar VAR_TEMP_5, 1
	end

MauvilleCity_TeamRocketHideout_Graveler5::
	setwildbattle SPECIES_GRAVELER, 30, ITEM_NONE
	dowildbattle
	setvar VAR_TEMP_5, 1
	end

@@@ Trainers 

MauvilleCity_TeamRocketHideout_EventScript_RocketMember1::
	trainerbattle_single TRAINER_HIDEOUT_ROCKET1, MauvilleCity_TeamRocketHideout_Text_Rocket1Intro, MauvilleCity_TeamRocketHideout_Text_Rocket1Defeat, EventScript_RocketEdition_TryStealPokemon_Releaseall
	msgbox MauvilleCity_TeamRocketHideout_Text_Rocket1PostBattle, MSGBOX_AUTOCLOSE
	end

MauvilleCity_TeamRocketHideout_Text_Rocket1Intro:
    .string "This area's strictly off-limits!\n"
    .string "Out, out!$"

MauvilleCity_TeamRocketHideout_Text_Rocket1Defeat:
    .string "Is this for real?$"

MauvilleCity_TeamRocketHideout_Text_Rocket1PostBattle:
    .string "You don't have any business here!\n"
    .string "Go home!$"

MauvilleCity_TeamRocketHideout_EventScript_RocketMember2::
	trainerbattle_single TRAINER_HIDEOUT_ROCKET2, MauvilleCity_TeamRocketHideout_Text_Rocket2Intro, MauvilleCity_TeamRocketHideout_Text_Rocket2Defeat, EventScript_RocketEdition_TryStealPokemon_Releaseall
	msgbox MauvilleCity_TeamRocketHideout_Text_Rocket2PostBattle, MSGBOX_AUTOCLOSE
	end

MauvilleCity_TeamRocketHideout_Text_Rocket2Intro:
    .string "We, Team Rocket, are Pokémon\n"
    .string "gangsters!\l"
    .string "We strike fear with our strength!$"

MauvilleCity_TeamRocketHideout_Text_Rocket2Defeat:
    .string "I blew it!$"

MauvilleCity_TeamRocketHideout_Text_Rocket2PostBattle:
    .string "Darn it all!\n"
    .string "My associates won't stand for this!$"

MauvilleCity_TeamRocketHideout_EventScript_RocketMember3::
	trainerbattle_single TRAINER_HIDEOUT_ROCKET3, MauvilleCity_TeamRocketHideout_Text_Rocket3Intro, MauvilleCity_TeamRocketHideout_Text_Rocket3Defeat, EventScript_RocketEdition_TryStealPokemon_Releaseall
	msgbox MauvilleCity_TeamRocketHideout_Text_Rocket3PostBattle, MSGBOX_AUTOCLOSE
	end

MauvilleCity_TeamRocketHideout_Text_Rocket3Intro:
    .string "We're pulling a big job here!\n"
    .string "Get lost, kid!$"

MauvilleCity_TeamRocketHideout_Text_Rocket3Defeat:
    .string "So, you are good…$"

MauvilleCity_TeamRocketHideout_Text_Rocket3PostBattle:
    .string "If you find a rare Pokémon, give it to\n"
    .string "me and scram!$"

MauvilleCity_TeamRocketHideout_EventScript_RocketMember4::
	trainerbattle_single TRAINER_HIDEOUT_ROCKET4, MauvilleCity_TeamRocketHideout_Text_Rocket4Intro, MauvilleCity_TeamRocketHideout_Text_Rocket4Defeat, EventScript_RocketEdition_TryStealPokemon_Releaseall
	msgbox MauvilleCity_TeamRocketHideout_Text_Rocket4PostBattle, MSGBOX_AUTOCLOSE
	end

MauvilleCity_TeamRocketHideout_Text_Rocket4Intro:
    .string "We're pulling a big job here!\n"
    .string "Get lost, kid!$"

MauvilleCity_TeamRocketHideout_Text_Rocket4Defeat:
    .string "So, you are good…$"

MauvilleCity_TeamRocketHideout_Text_Rocket4PostBattle:
    .string "If you find a rare Pokémon, give it to\n"
    .string "me and scram!$"

MauvilleCity_TeamRocketHideout_EventScript_RocketMember5::
	trainerbattle_single TRAINER_HIDEOUT_ROCKET5, MauvilleCity_TeamRocketHideout_Text_Rocket5Intro, MauvilleCity_TeamRocketHideout_Text_Rocket5Defeat, EventScript_RocketEdition_TryStealPokemon_Releaseall
	msgbox MauvilleCity_TeamRocketHideout_Text_Rocket5PostBattle, MSGBOX_AUTOCLOSE
	end

MauvilleCity_TeamRocketHideout_Text_Rocket5Intro:
    .string "Little kids shouldn't be messing\n"
    .string "around with grown-ups!\p"
    .string "It could be bad news!$"

MauvilleCity_TeamRocketHideout_Text_Rocket5Defeat:
    .string "I'm steamed!$"

MauvilleCity_TeamRocketHideout_Text_Rocket5PostBattle:
    .string "If I had started as a Trainer at\n"
    .string "your age…$"
