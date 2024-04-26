.set LOCALID_TEACHER, 1

MauvilleCity_School_MapScripts::
	.byte 0

MauvilleCity_PokemonSchool_EventScript_Lass::
	msgbox MauvilleCity_PokemonSchool_Text_ConfusedPokemonAttacksItself, MSGBOX_NPC
	end

MauvilleCity_PokemonSchool_Text_ConfusedPokemonAttacksItself:
	.string "If the Pokémon has the same type\n"
	.string "of used move, its power is boosted\l"
	.string "by 25%!\p" 
	.string "I wonder if the Pokémon\n"
	.string "that has two types has advantage\l"
	.string "over Pokémon that has only one type.$"

MauvilleCity_PokemonSchool_EventScript_Lass2::
	msgbox MauvilleCity_PokemonSchool_Text_ConfusedPokemonAttacksItself2, MSGBOX_NPC
	end

MauvilleCity_PokemonSchool_Text_ConfusedPokemonAttacksItself2:
	.string "Some Pokémon Trainers use weather\n"
	.string "and terrain to their advantage\l"
	.string "to be victorious.$"

MauvilleCity_PokemonSchool_EventScript_Lass3::
	msgbox MauvilleCity_PokemonSchool_Text_ConfusedPokemonAttacksItself3, MSGBOX_NPC
	end

MauvilleCity_PokemonSchool_Text_ConfusedPokemonAttacksItself3:
	.string "Cursed Terrain is perfect to my Ghost-\n"
	.string "type Pokémon team!$"

MauvilleCity_PokemonSchool_EventScript_Lass4::
	msgbox MauvilleCity_PokemonSchool_Text_ConfusedPokemonAttacksItself4, MSGBOX_NPC
	end

MauvilleCity_PokemonSchool_Text_ConfusedPokemonAttacksItself4:
	.string "I will use my Psychic Terrain to\n"
	.string "counter his terrain!$"

MauvilleCity_PokemonSchool_EventScript_Lass5::
	msgbox MauvilleCity_PokemonSchool_Text_ConfusedPokemonAttacksItself5, MSGBOX_NPC
	end

MauvilleCity_PokemonSchool_Text_ConfusedPokemonAttacksItself5:
	.string "Like weather, the terrain lasts for\n"
	.string "five turns and can be replaced by\l"
	.string "using other terrain.$"

MauvilleCity_PokemonSchool_EventScript_Teacher::
	lock
	faceplayer
	delay 16
	applymovement LOCALID_TEACHER, Common_Movement_FaceUp
	waitmovement 0
	delay 16
	delay 16
	faceplayer
	delay 16
	msgbox MauvilleCity_PokemonSchool_Text_Teacher, MSGBOX_DEFAULT
	goto_if_set FLAG_RECEIVED_TERRAIN_EXTENDER, MauvilleCity_PokemonSchool_EventScript_TeacherEnd
	setflag FLAG_RECEIVED_TERRAIN_EXTENDER
	msgbox MauvilleCity_PokemonSchool_Text_TeacherGiveTerrainExtended, MSGBOX_DEFAULT
	giveitem ITEM_TERRAIN_EXTENDER
	msgbox MauvilleCity_PokemonSchool_Text_TeacherExplainTerrainExtended, MSGBOX_DEFAULT
MauvilleCity_PokemonSchool_EventScript_TeacherEnd:
	release
	end

MauvilleCity_PokemonSchool_Text_TeacherExplainTerrainExtended:
	.string "Terrains usually lasts for five turn.\p"
	.string "But if the Pokémon is holding\n"
	.string "Terrain Extended, the terrain will\l"
	.string "lasts eight turns instead.$"

MauvilleCity_PokemonSchool_Text_TeacherGiveTerrainExtended:
	.string "Hey! Since this is your first\n"
	.string "lesson here, takes this!$"

MauvilleCity_PokemonSchool_Text_Teacher:
	.string "Today the lesson is about terrains.\p"
	.string "You can see the summary on the\n"
	.string "Blackboard.$"

MauvilleCity_PokemonSchool_EventScript_Blackboard::
	message Common_PokemonSchool_Text_ReadWhichTopic
	waitmessage
	setvar VAR_0x8004, SCROLL_MULTI_MAUVILLE_SCHOOL
	special ShowScrollableMultichoice
	waitstate	
	switch VAR_RESULT
	case 0, MauvilleCity_PokemonSchool_EventScript_ElectricTerrain
	case 1, MauvilleCity_PokemonSchool_EventScript_GrassyTerrain
	case 2, MauvilleCity_PokemonSchool_EventScript_MistyTerrain
	case 3, MauvilleCity_PokemonSchool_EventScript_PsychicTerrain
	case 4, MauvilleCity_PokemonSchool_EventScript_FrozenTerrain
	case 5, MauvilleCity_PokemonSchool_EventScript_CursedTerrain
	case 6, MauvilleCity_PokemonSchool_EventScript_RavineTerrain
	case 7, MauvilleCity_PokemonSchool_EventScript_BurningTerrain
	case 8, MauvilleCity_PokemonSchool_EventScript_SandyTerrain
	case 9, MauvilleCity_PokemonSchool_EventScript_SwampTerrain
	case 10, MauvilleCity_PokemonSchool_EventScript_VenomousTerrain
	case 11, MauvilleCity_PokemonSchool_EventScript_Cancel
MauvilleCity_PokemonSchool_EventScript_Cancel:
    closemessage
    end

MauvilleCity_PokemonSchool_EventScript_ElectricTerrain:
    msgbox MauvilleCity_PokemonSchool_Text_ElectricTerrain MSGBOX_DEFAULT
    closemessage
	goto MauvilleCity_PokemonSchool_EventScript_Blackboard

MauvilleCity_PokemonSchool_Text_ElectricTerrain:
	.string "Increases the power of Electric-type\n"
	.string "moves by 30% of Pokémon on the ground.\p"
	.string "Prevents Pokémon on the ground from\n"
	.string "falling asleep and being afflicted by\l"
	.string "Yawn.\p"
	.string "Doubles the power of Rising Voltage\n"
	.string "when the target is on the ground.\p"
	.string "Changes Terrain Pulse's type to\n"
	.string "Electric and doubles its power.\p"
	.string "Electric Seed is consumed and increases\n"
	.string "Defense stat by one stage.\p"
	.string "Activates certain abilities: Surge\n"
	.string "Surfer and Mimicry.$"

MauvilleCity_PokemonSchool_EventScript_GrassyTerrain:
    msgbox MauvilleCity_PokemonSchool_Text_GrassyTerrain MSGBOX_DEFAULT
    closemessage
	goto MauvilleCity_PokemonSchool_EventScript_Blackboard

MauvilleCity_PokemonSchool_Text_GrassyTerrain:
	.string "Increases the power of Grass-type\n"
	.string "moves by 30% of Pokémon on the ground.\p"
	.string "Restores HP by 1/16 of maximum HP to\n"
	.string "all Pokémon on the ground each turn.\p"
	.string "Halves the damage taken from Bulldoze,\n"
	.string "Earthquake and Magnetude.\p"
	.string "Changes Terrain Pulse's type to\n"
	.string "Grass and doubles its power.\p"
	.string "Floral Healing restores more health.\p"
	.string "Grassy Seed is consumed and increases\n"
	.string "Defense stat by one stage.\p"
	.string "Activates certain abilities: Grass\n"
	.string "Pelt and Mimicry.$"

MauvilleCity_PokemonSchool_EventScript_MistyTerrain:
    msgbox MauvilleCity_PokemonSchool_Text_MistyTerrain MSGBOX_DEFAULT
    closemessage
	goto MauvilleCity_PokemonSchool_EventScript_Blackboard

MauvilleCity_PokemonSchool_Text_MistyTerrain:
	.string "Halves the damage taken by Pokémon on\n"
	.string "the ground from Dragon-type moves.\p"
	.string "Prevents Pokémon on the ground from\n"
	.string "being afflicted with status conditions\l"
	.string "and confusion.\p"
	.string "Changes Terrain Pulse's type to\n"
	.string "Fairy and doubles its power.\p"
	.string "Misty Explosion's power is increased\n"
	.string "by 50%.\p"
	.string "Misty Seed is consumed and increases\n"
	.string "Special Defense stat by one stage.\p"
	.string "Activates certain abilities: Mimicry.$"

MauvilleCity_PokemonSchool_EventScript_PsychicTerrain:
    msgbox MauvilleCity_PokemonSchool_Text_PsychicTerrain MSGBOX_DEFAULT
    closemessage
	goto MauvilleCity_PokemonSchool_EventScript_Blackboard

MauvilleCity_PokemonSchool_Text_PsychicTerrain:
	.string "Increases the power of Psychic-type\n"
	.string "moves by 30% of Pokémon on the ground.\p"
	.string "Prevents Pokémon on the ground from\n"
	.string "being hit by moves with increased\l"
	.string "priority.\p"
	.string "Changes Terrain Pulse's type to\n"
	.string "Psychic and doubles its power.\p"
	.string "Expanding Force's power is increased\n"
	.string "by 50% and hits all opposing Pokémon.\p"
	.string "Psychic Seed is consumed and increases\n"
	.string "Special Defense stat by one stage.\p"
	.string "Activates certain abilities: Mimicry.$"

MauvilleCity_PokemonSchool_EventScript_FrozenTerrain:
    msgbox MauvilleCity_PokemonSchool_Text_FrozenTerrain MSGBOX_DEFAULT
    closemessage
	goto MauvilleCity_PokemonSchool_EventScript_Blackboard

MauvilleCity_PokemonSchool_Text_FrozenTerrain:
	.string "Increases the power of Ice-type moves\n"
	.string "by 30% of Pokémon on the ground.\p"
	.string "Pokémon on the ground has 33% chance\n"
	.string "to slip on ice and hit obstacles\l"
	.string "instead executing the move.\l"
	.string "Ice-type Pokémon or Pokémon with\l"
	.string "Slush Rush ability are unaffected.\p"
	.string "Changes Terrain Pulse's type to\n"
	.string "Ice and doubles its power.\p"
	.string "Artic Glide's priority is increased\n"
	.string "by one.\p"
	.string "Activates certain abilities: Mimicry\n"
	.string "and Slush Rush.$"

MauvilleCity_PokemonSchool_EventScript_CursedTerrain:
    msgbox MauvilleCity_PokemonSchool_Text_CursedTerrain MSGBOX_DEFAULT
    closemessage
	goto MauvilleCity_PokemonSchool_EventScript_Blackboard

MauvilleCity_PokemonSchool_Text_CursedTerrain:
	.string "Increases the power of Ghost-type\n"
	.string "moves by 30% of Pokémon on the ground.\p"
	.string "Prevents the healing effects of\n"
	.string "Pokémon on the ground, unless it is\l"
	.string "Ghost- or Dark-type.\p"
	.string "Changes Terrain Pulse's type to\n"
	.string "Ghost and doubles its power.\p"
	.string "Shadow Force, Phantom Force and\n"
	.string "Phantom Ambush are executed\l"
	.string "immediately.\p"
	.string "Activates certain abilities: Mimicry,\n"
	.string "Livid Shadow and Maleficent.$"

MauvilleCity_PokemonSchool_EventScript_RavineTerrain:
    msgbox MauvilleCity_PokemonSchool_Text_RavineTerrain MSGBOX_DEFAULT
    closemessage
	goto MauvilleCity_PokemonSchool_EventScript_Blackboard

MauvilleCity_PokemonSchool_Text_RavineTerrain:
	.string "Increases the power of Flying-type\n"
	.string "moves by 30% of Pokémon on the ground.\p"
	.string "Flying-type Pokémon that are in air\n"
	.string "takes 25% less damage from super\l"
	.string "effective damage.\p"
	.string "Expand the duration of Tailwind to\n"
	.string "six turns.\p"
	.string "Changes Terrain Pulse's type to\n"
	.string "Flying and doubles its power.\p"
	.string "Razor Wind does not need to\n"
	.string "charge the first turn.\p"
	.string "Activates certain abilities: Mimicry.$"

MauvilleCity_PokemonSchool_EventScript_BurningTerrain:
    msgbox MauvilleCity_PokemonSchool_Text_BurningTerrain MSGBOX_DEFAULT
    closemessage
	goto MauvilleCity_PokemonSchool_EventScript_Blackboard

MauvilleCity_PokemonSchool_Text_BurningTerrain:
	.string "Increases the power of Fire-type moves\n"
	.string "by 30% of Pokémon on the ground.\p"
	.string "Damages equal 1/8 of maximum HP to\n"
	.string "all Pokémon on the ground each turn.\p"
	.string "Prevents Pokémon on the ground from\n"
	.string "falling asleep and being afflicted by\l"
	.string "Yawn.\p"
	.string "Changes Terrain Pulse's type to\n"
	.string "Fire and doubles its power.\p"
	.string "Activates certain abilities: Mimicry.$"

MauvilleCity_PokemonSchool_EventScript_SandyTerrain:
    msgbox MauvilleCity_PokemonSchool_Text_SandyTerrain MSGBOX_DEFAULT
    closemessage
	goto MauvilleCity_PokemonSchool_EventScript_Blackboard

MauvilleCity_PokemonSchool_Text_SandyTerrain:
	.string "Increases the power of Ground-type\n"
	.string "moves by 30% of Pokémon on the ground.\p"
	.string "Pokémon on the ground have their evasion\n"
	.string "reduced by 33%, unless it is Ground-,\l"
	.string "Rock-, Steel-type, or has Sand Veil,\l"
	.string "Sand Force or Sand Rush.\p"
	.string "Changes Terrain Pulse's type to\n"
	.string "Ground and doubles its power.\p"
	.string "Increase the HP healing of\n"
	.string "Shore Up.\p"
	.string "Activates certain abilities: Mimicry,\n"
	.string "Sand Veil, Sand Force and Sand Rush.$"

MauvilleCity_PokemonSchool_EventScript_SwampTerrain:
    msgbox MauvilleCity_PokemonSchool_Text_SwampTerrain MSGBOX_DEFAULT
    closemessage
	goto MauvilleCity_PokemonSchool_EventScript_Blackboard

MauvilleCity_PokemonSchool_Text_SwampTerrain:
	.string "Increases the power of Water-type\n"
	.string "and Mud moves by 30% of Pokémon\l"
	.string "on the ground.\p"
	.string "Pokémon on the ground have their Speed\n"
	.string "reduced by 25%, unless it is Water-\l"
	.string "type, or has Dry Skin or Swift Swim.\p"
	.string "Changes Terrain Pulse's type to\n"
	.string "Water and doubles its power.\p"
	.string "Halves the damage taken from Bulldoze,\n"
	.string "Earthquake and Magnetude.\p"
	.string "Activates certain abilities: Mimicry,\n"
	.string "Dry Skin, Swift Swim, Amphibious and\l"
	.string "Antartic Bird.$"

MauvilleCity_PokemonSchool_EventScript_VenomousTerrain:
    msgbox MauvilleCity_PokemonSchool_Text_VenomousTerrain MSGBOX_DEFAULT
    closemessage
	goto MauvilleCity_PokemonSchool_EventScript_Blackboard

MauvilleCity_PokemonSchool_Text_VenomousTerrain:
	.string "Increases the power of Poison-type\n"
	.string "moves by 30% of Pokémon on the ground.\p"
	.string "Prevents non-Poison-type Pokémon on\n"
	.string "the ground from eating berries.\p"
	.string "At the end of each turn, inflict\n"
	.string "poison status to all Pokémon on\l"
	.string "the ground.\p"
	.string "Changes Terrain Pulse's type to\n"
	.string "Poison and doubles its power.\p"
	.string "Activates certain abilities: Mimicry.$"
