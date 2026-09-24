.set LOCALID_NURSE, 1

PetalburgCity_PokemonCenter_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, PetalburgCity_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

PetalburgCity_PokemonCenter_1F_OnTransition:
	setrespawn HEAL_LOCATION_PETALBURG_CITY
	call Common_EventScript_UpdateBrineyLocation
	end

PetalburgCity_PokemonCenter_1F_EventScript_Nurse::
	setvar VAR_0x800B, LOCALID_NURSE
	goto_if_set FLAG_RECEIVED_PETALBURG_EGG, PetalburgCity_PokemonCenter_1F_EventScript_NurseAlreadyGiveEgg
	lock
	faceplayer
	msgbox PetalburgCity_Text_HaveEggWillYouTakeIt, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq PetalburgCity_EventScript_DeclineEgg
	getpartysize
	compare VAR_RESULT, PARTY_SIZE
	goto_if_eq LavaridgeTown_EventScript_NoRoomForEgg
	msgbox LavaridgeTown_Text_HopeYoullWalkPlentyWithEgg, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_PETALBURG_EGG
	playfanfare MUS_OBTAIN_ITEM
	message LavaridgeTown_Text_ReceivedTheEgg
	waitfanfare
	giveeggsimple SPECIES_TOGEPI, MOVE_DIZZY_PUNCH, MOVE_LUCKY_CHANT, MOVE_CHARM, MOVE_SAFEGUARD
	release
	end

PetalburgCity_EventScript_DeclineEgg:
    msgbox gText_WouldYouLikeToRestYourPkmn2, MSGBOX_YESNO
    compare VAR_RESULT, YES
	goto_if_eq PetalburgCity_EventScript_DeclineEggHeal
    compare VAR_RESULT, NO
    goto_if_eq EventScript_PkmnCenterNurse_Goodbye2
	waitmessage
	waitbuttonpress
	release
	end

EventScript_PkmnCenterNurse_Goodbye2::
    message gText_WeHopeToSeeYouAgain
	waitmessage
	waitbuttonpress
	release
	end

PetalburgCity_EventScript_DeclineEggHeal:
	setvar VAR_0x800B, LOCALID_NURSE
	call Common_EventScript_PkmnCenterNursePetalbug
	waitmessage
	waitbuttonpress
	release
	end

Common_EventScript_PkmnCenterNursePetalbug:
	specialvar VAR_RESULT, IsPokecenterBlockedChallengeActivated
	compare VAR_RESULT, TRUE
    goto_if_eq EventScript_PkmnCenterNurse_PkmnCenterChallenge_NoVisits
    setvar VAR_0x8004, 0
    specialvar VAR_RESULT, CountPlayerTrainerStars
    compare VAR_RESULT, 4
    goto_if_eq EventScript_PkmnCenterNurse_GoldCard
    goto EventScript_PkmnCenterNurse_HealPkmn
    end

PetalburgCity_PokemonCenter_1F_EventScript_NurseAlreadyGiveEgg:
	setvar VAR_0x800B, LOCALID_NURSE
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

PetalburgCity_PokemonCenter_1F_EventScript_FatMan::
	msgbox PetalburgCity_PokemonCenter_1F_Text_PCStorageSystem, MSGBOX_NPC
	end

PetalburgCity_PokemonCenter_1F_EventScript_Youngster::
	msgbox PetalburgCity_PokemonCenter_1F_Text_OranBerryRegainedHP, MSGBOX_NPC
	end

PetalburgCity_PokemonCenter_1F_EventScript_Woman::
	lock
	faceplayer
	msgbox PetalburgCity_PokemonCenter_1F_Text_ManyTypesOfPokemon, MSGBOX_DEFAULT
	specialvar VAR_RESULT, IsStarterInParty
	compare VAR_RESULT, TRUE
	goto_if_eq PetalburgCity_PokemonCenter_1F_EventScript_SayStarterTypeInfo
	release
	end

PetalburgCity_PokemonCenter_1F_EventScript_SayStarterTypeInfo::
	compare VAR_STARTER_MON, 0
	call_if_eq PetalburgCity_PokemonCenter_1F_EventScript_SayTreeckoType
	compare VAR_STARTER_MON, 1
	call_if_eq PetalburgCity_PokemonCenter_1F_EventScript_SayTorchicType
	compare VAR_STARTER_MON, 2
	call_if_eq PetalburgCity_PokemonCenter_1F_EventScript_SayMudkipType
	release
	end

PetalburgCity_PokemonCenter_1F_EventScript_SayTreeckoType::
	msgbox PetalburgCity_PokemonCenter_1F_Text_TreeckoIsGrassType, MSGBOX_DEFAULT
	return

PetalburgCity_PokemonCenter_1F_EventScript_SayTorchicType::
	msgbox PetalburgCity_PokemonCenter_1F_Text_TorchicIsFireType, MSGBOX_DEFAULT
	return

PetalburgCity_PokemonCenter_1F_EventScript_SayMudkipType::
	msgbox PetalburgCity_PokemonCenter_1F_Text_MudkipIsWaterType, MSGBOX_DEFAULT
	return

PetalburgCity_PokemonCenter_1F_Text_PCStorageSystem:
	.string "That PC-based Pokémon Storage\n"
	.string "System…\p"
	.string "Whoever made it must be some kind\n"
	.string "of a scientific wizard!$"

PetalburgCity_PokemonCenter_1F_Text_OranBerryRegainedHP:
	.string "When my Pokémon ate an\n"
	.string "Oran Berry, it regained HP!$"

PetalburgCity_PokemonCenter_1F_Text_ManyTypesOfPokemon:
	.string "There are many types of Pokémon.\p"
	.string "All types have their strengths and\n"
	.string "weaknesses against other types.\p"
	.string "Depending on the types of Pokémon,\n"
	.string "a battle could be easy or hard.$"

PetalburgCity_PokemonCenter_1F_Text_TreeckoIsGrassType:
	.string "For example, your Rowlet\n"
	.string "is a Grass type.\p"
	.string "It's strong against the Water and\n"
	.string "Ground types.\p"
	.string "But, it's weak against Fire-type\n"
	.string "Pokémon.$"

PetalburgCity_PokemonCenter_1F_Text_TorchicIsFireType:
	.string "For example, your Charmander\n"
	.string "is a Fire type.\p"
	.string "It's strong against the Grass and\n"
	.string "Bug types.\p"
	.string "But, it's weak against Water-type\n"
	.string "Pokémon.$"

PetalburgCity_PokemonCenter_1F_Text_MudkipIsWaterType:
	.string "For example, your Totodile\n"
	.string "is a Water type.\p"
	.string "It's strong against the Fire type.\p"
	.string "But, it's weak against Grass-type\n"
	.string "and Electric-type Pokémon.$"

PetalburgCity_Text_HaveEggWillYouTakeIt:
    .string "Hello, and welcome to the\n"
	.string "Pokémon Center.\p"
	.string "We restore your tired Pokémon\n"
	.string "to full health.\p"
	.string "But today, I have something\n"
	.string "a little different to ask of you.\p"
	.string "You see, someone recently left\n"
	.string "this Pokémon Egg in our care.\p"
	.string "It hasn't hatched yet, but…\n"
	.string "I can feel something special inside.\p"
	.string "It seems that a Pokémon will hatch\n"
	.string "from it when you keep it in your party\l"
	.string "of Pokémon.\p"
	.string "I'd love to care for it myself,\n"
	.string "but I can't leave this Pokémon Center.\p"
	.string "There are always Trainers and Pokémon\n"
	.string "here who need my help.\p"
	.string "Since you're already on a journey,\n"
	.string "would you take the Egg with you?$"

gText_WouldYouLikeToRestYourPkmn2::
    .string "Then…\n"
    .string "Would you like to rest your Pokémon?$"

PetalburgCity_Text_HopeYoullWalkPlentyWithEgg:
	.string "Thank you! Please take good care\n"
	.string "of this little Egg.\p"
	.string "Give it plenty of love, and walk\n"
	.string "with it wherever your journey takes you.\p"
	.string "Who knows? Before long, you may\n"
	.string "be welcoming a new friend!$"
