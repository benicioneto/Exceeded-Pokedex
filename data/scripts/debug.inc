Debug_ShowFieldMessageStringVar4::
	special ShowFieldMessageStringVar4
	waitmessage
	waitbuttonpress
	releaseall
	end

Debug_CheckWeekDay_Text:
	.string "Aaaaah, yes!\l"
	.string "{STR_VAR_1}s are made for dads!\l"
	.string "And dad's car!$"

Debug_CheatStart::
	lockall
	setflag FLAG_SYS_POKEMON_GET
	setflag FLAG_ADVENTURE_STARTED
	setflag FLAG_RESCUED_BIRCH
	setflag FLAG_HIDE_ROUTE_101_BIRCH_ZIGZAGOON_BATTLE
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_BIRCHS_LAB_BIRCH
	setflag FLAG_HIDE_ROUTE_101_BIRCH_STARTERS_BAG
	setflag FLAG_HIDE_ROUTE_101_ZIGZAGOON
	setvar VAR_BIRCH_LAB_STATE, 2
	setvar VAR_ROUTE101_STATE, 3
	givemon SPECIES_TREECKO, 20, ITEM_SCEPTILITE
	givemon SPECIES_TORCHIC, 20, ITEM_BLAZIKENITE
	givemon SPECIES_MUDKIP, 20, ITEM_SWAMPERTITE
	givemonsimple SPECIES_MEWTWO, 100, ITEM_MEWTWONITE_Y, ITEM_NONE, ITEM_NONE, MOVE_RECOVER, MOVE_PSYSTRIKE, MOVE_AURA_SPHERE, MOVE_FIRE_BLAST
	givemonsimple SPECIES_LUGIA, 100, ITEM_SILVER_WING, ITEM_LIFE_ORB, ITEM_LEFTOVERS, MOVE_RECOVER, MOVE_AQUA_TORNADO, MOVE_AEROBLAST, MOVE_PSYCHIC
	givemonsimple SPECIES_HO_OH, 100, ITEM_RAINBOW_WING, ITEM_NONE, ITEM_NONE, MOVE_PHOENIX_DOWN, MOVE_BRAVE_BIRD, MOVE_SACRED_FIRE, MOVE_PLAY_ROUGH
	setflag FLAG_SYS_POKEDEX_GET
	special SetUnlockedPokedexFlags
	setflag FLAG_RECEIVED_POKEDEX_FROM_BIRCH
	setvar VAR_CABLE_CLUB_TUTORIAL_STATE, 1
	setflag FLAG_SYS_NATIONAL_DEX
	special EnableNationalPokedex
	setflag FLAG_RECEIVED_RUNNING_SHOES
	additem ITEM_RUNNING_SHOES, 1
	setflag FLAG_SYS_B_DASH
	setvar VAR_LITTLEROOT_TOWN_STATE, 4 @ 4: Received Running Shoes
	setvar VAR_LITTLEROOT_INTRO_STATE, 7 @ 7: Told to go meet rival
	setvar VAR_LITTLEROOT_HOUSES_STATE_BRENDAN, 2 @ 2: Met Rival's Mom (and is corresponding gender)
	setvar VAR_LITTLEROOT_HOUSES_STATE_MAY, 2 @ 2: Met Rival's Mom (and is corresponding gender)
	setvar VAR_LITTLEROOT_RIVAL_STATE, 4 @ 4: Received Pokedex
	setflag FLAG_RECEIVED_BIKE
	additem ITEM_ACRO_BIKE
	additem ITEM_MACH_BIKE
	additem ITEM_MEGA_BRACELET
	additem ITEM_Z_RING
	additem ITEM_ITEMFINDER
	setvar VAR_BRINEY_HOUSE_STATE, 1
	setvar VAR_ROUTE116_STATE, 2
	setflag FLAG_HIDE_ROUTE_116_MR_BRINEY
	clearflag FLAG_HIDE_BRINEYS_HOUSE_MR_BRINEY
	clearflag FLAG_HIDE_BRINEYS_HOUSE_PEEKO
	additem ITEM_MAX_REPEL, 50
	additem ITEM_RARE_CANDY, 50
	additem ITEM_ABILITY_CAPSULE, 50
	additem ITEM_ABILITY_PATCH, 50
	additem ITEM_FULL_RESTORE, 50
	additem ITEM_MAX_REVIVE, 50
	additem ITEM_MASTER_BALL, 50
	additem ITEM_HP_UP, 50
	additem ITEM_PROTEIN, 50
	additem ITEM_IRON, 50
	additem ITEM_CARBOS, 50
	additem ITEM_CALCIUM, 50
	additem ITEM_ZINC, 50
	additem ITEM_PP_MAX, 50
	additem ITEM_HEART_SCALE, 50
	additem ITEM_BIG_MUSHROOM, 50
	@ giveitem ITEM_EON_TICKET
	@ setflag FLAG_SYS_HAS_EON_TICKET
	@ setvar VAR_DISTRIBUTE_EON_TICKET, 0
	@ giveitem ITEM_MYSTIC_TICKET
	@ setflag FLAG_ENABLE_SHIP_NAVEL_ROCK
	@ setflag FLAG_RECEIVED_MYSTIC_TICKET
	@ giveitem ITEM_AURORA_TICKET
	@ setflag FLAG_ENABLE_SHIP_BIRTH_ISLAND
	@ setflag FLAG_RECEIVED_AURORA_TICKET
	@ setflag FLAG_BADGE06_GET @ Badge for flying filed move
	@ setweather WEATHER_VOLCANIC_ASH
	@ doweather
	closemessage
	release
	end

Debug_FlagsNotSetOverworldConfigMessage::
	lockall
	message Debug_FlagsNotSetOverworldConfigMessage_Text
	waitmessage
	waitbuttonpress
	releaseall
	end

Debug_FlagsNotSetOverworldConfigMessage_Text:
	.string "Feature unavailable!\n"
	.string "Please define a usable flag in:\l"
	.string "'include/config/overworld.h'!$"

Debug_FlagsNotSetBattleConfigMessage::
	lockall
	message Debug_FlagsNotSetBattleConfigMessage_Text
	waitmessage
	waitbuttonpress
	releaseall
	end

Debug_FlagsNotSetBattleConfigMessage_Text:
	.string "Feature unavailable!\n"
	.string "Please define a usable flag in:\l"
	.string "'include/config/battle.h'!$"

@ debug scripts test
Debug_Script_1::
	setwildbattle SPECIES_GREEDENT, 100, ITEM_LIECHI_BERRY
	dowildbattle
	@trainerbattle_single TRAINER_SHELLY_WEATHER_INSTITUTE, Route119_WeatherInstitute_2F_Text_ShellyIntro, Route119_WeatherInstitute_2F_Text_ShellyDefeat, Route119_WeatherInstitute_2F_EventScript_ShellyDefeated
	@msgbox Route119_WeatherInstitute_2F_Text_ShellyPostBattle, MSGBOX_AUTOCLOSE
	end

Debug_Script_2::
	setwildbattle SPECIES_THIEVUL, 50, ITEM_LEFTOVERS
	dowildbattle
	end

Debug_Script_3::
	setwildbattle SPECIES_GIRATINA, 50, ITEM_LEFTOVERS
	dowildbattle
	end

Debug_Script_4::
	setwildbattle SPECIES_CASTFORM, 50, ITEM_NONE
	dowildbattle
	end

Debug_Script_5::
	clearflag FLAG_DAILY_BLACKSMITH_FORGE
	setflag FLAG_HIDE_VILLAINS_IN_METEOR_FALLS_AND_FALLARBOR_TOWN
	end

Debug_Script_6::
	additem ITEM_METAL_COAT, 100
	additem ITEM_NUGGET, 100
	additem ITEM_BRIGHT_POWDER, 100
	additem ITEM_RAZOR_CLAW, 100
	additem ITEM_ICE_STONE, 100
	additem ITEM_FIRE_STONE, 100
	additem ITEM_ICY_ROCK, 100
	additem ITEM_HEAT_ROCK, 100
	additem ITEM_HARD_STONE, 100
	end

Debug_Script_7::
	setflag FLAG_MR_BRINEY_SAILING_INTRO
	setflag FLAG_DELIVERED_STEVEN_LETTER
	setflag FLAG_DELIVERED_DEVON_GOODS
	end

Debug_Script_8::
	@setflag FLAG_BENJAMIN_BUTTERFREE_BATTLE
	@setflag FLAG_HIDE_LILYCOVE_POLICE
	@clearflag FLAG_LILYCOVE_TEAM_ROCKET
	goto Route119_WeatherInstitute_2F_EventScript_Shelly
	end
