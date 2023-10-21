.set LOCALID_TEACHER, 1

PetalburgCity_School_MapScripts::
	.byte 0

PetalburgCity_PokemonSchool_EventScript_Lass::
	msgbox PetalburgCity_PokemonSchool_Text_ConfusedPokemonAttacksItself, MSGBOX_NPC
	end

PetalburgCity_PokemonSchool_Text_ConfusedPokemonAttacksItself:
	.string "Do you know that Pokémon has up to\n"
	.string "three Innates?\p"
	.string "Innates interacts with Mold Breaker\n"
	.string "like abilities and Gastro Acid, but\l"
	.string "Neutralizing Gas doesn't affects it.$"

PetalburgCity_PokemonSchool_EventScript_Lass2::
	msgbox PetalburgCity_PokemonSchool_Text_ConfusedPokemonAttacksItself2, MSGBOX_NPC
	end

PetalburgCity_PokemonSchool_Text_ConfusedPokemonAttacksItself2:
	.string "Pokémon ability may varies depending\n"
	.string "on the individual, and you can it with\l"
	.string "Ability Capsules or Ability Patches!\p"
	.string "But Innates varies with species,\n"
	.string "althrough Pokémon can gain new Innates\l"
	.string "through leveling, evolving, etc.$"

PetalburgCity_PokemonSchool_EventScript_Teacher::
	lock
	faceplayer
	delay 16
	applymovement LOCALID_TEACHER, Common_Movement_FaceUp
	waitmovement 0
	delay 16
	delay 16
	faceplayer
	delay 16
	msgbox PetalburgCity_PokemonSchool_Text_Teacher, MSGBOX_DEFAULT
	release
	end

PetalburgCity_PokemonSchool_Text_Teacher:
	.string "Today the lesson is about the weather.\p"
	.string "You can see the summary on the\n"
	.string "Blackboard.$"

PetalburgCity_PokemonSchool_EventScript_Blackboard::
	message Common_PokemonSchool_Text_ReadWhichTopic
	waitmessage
	setvar VAR_0x8004, SCROLL_MULTI_PETALBURG_SCHOOL
	special ShowScrollableMultichoice
	waitstate	
	switch VAR_RESULT
	case 0, PetalburgCity_PokemonSchool_EventScript_Harsh_Sunlight
	case 1, PetalburgCity_PokemonSchool_EventScript_Extremely_Harsh_Sunlight
	case 2, PetalburgCity_PokemonSchool_EventScript_Rain
	case 3, PetalburgCity_PokemonSchool_EventScript_Heavy_Rain
	case 4, PetalburgCity_PokemonSchool_EventScript_Sandstorm
	case 5, PetalburgCity_PokemonSchool_EventScript_Hailstorm
	case 6, PetalburgCity_PokemonSchool_EventScript_Fog
	case 7, PetalburgCity_PokemonSchool_EventScript_Strong_Winds
	case 8, PetalburgCity_PokemonSchool_EventScript_Cancel
PetalburgCity_PokemonSchool_EventScript_Cancel:
    closemessage
    end

PetalburgCity_PokemonSchool_EventScript_Harsh_Sunlight:
    msgbox PetalburgCity_PokemonSchool_Text_Harsh_Sunlight MSGBOX_DEFAULT
    closemessage
	goto PetalburgCity_PokemonSchool_EventScript_Blackboard

PetalburgCity_PokemonSchool_Text_Harsh_Sunlight:
	.string "Increases the Speed stat of Grass-type\n"
	.string "Pokémon by 33%.\p"
	.string "If the Pokémon has Chlorophyll ability,\n"
	.string "increases that stat by 50% instead.\p"
	.string "Allows Solar Beam and Solar Blade to be\n"
	.string "used instantly.\p"
	.string "Changes Weather Ball's type and doubles\n"
	.string "its power.\p"
	.string "Causes Growth to raise Attack and\n"
	.string "Special Attack two stages each.\p"
	.string "Moonlight, Synthesis and Morning Sun\n"
	.string "restore more health.\p"
	.string "Lowers accuracy of Thunder and\n"
	.string "Hurricane by 50%.\p"
	.string "Prevents Pokémon from becoming\n"
	.string "Frozen.\p"
	.string "Activates certain abilities: Chlorophyll,\n"
	.string "Dry Skin, Flower Gift, Forecast, Leaf\l"
	.string "Guard, Solar Power, Harvest and Laval\l"
	.string "Body.\p"
	.string "Pokémon with Big Leaves ability can\n"
	.string "absorb poor sunlight even without\l"
	.string "Harsh Sunlight, gaining these\l"
	.string "effect. But cannot absorb sunlight\l"
	.string "under other weather.$"

PetalburgCity_PokemonSchool_EventScript_Extremely_Harsh_Sunlight:
    msgbox PetalburgCity_PokemonSchool_Text_Extremely_Harsh_Sunlight MSGBOX_DEFAULT
    closemessage
	goto PetalburgCity_PokemonSchool_EventScript_Blackboard

PetalburgCity_PokemonSchool_Text_Extremely_Harsh_Sunlight:
	.string "Same effects of Harsh Sunlight.\p"
	.string "But it also increases the power of\n"
	.string "Fire-type moves by 50% and causes\l"
	.string "Water-type moves to fail if used.$"

PetalburgCity_PokemonSchool_EventScript_Rain:
    msgbox PetalburgCity_PokemonSchool_Text_Rain MSGBOX_DEFAULT
    closemessage
	goto PetalburgCity_PokemonSchool_EventScript_Blackboard

PetalburgCity_PokemonSchool_Text_Rain:
	.string "Decreases the power of Fire-type\n"
	.string "moves by 25%.\p"
	.string "Allows Thunder and Hurricane to\n"
	.string "bypass the accuracy check.\p"
	.string "Changes Weather Ball's type and doubles\n"
	.string "its power.\p"
	.string "Halves the power of Solar Beam and\n"
	.string "Solar Blade.\p"
	.string "Moonlight, Synthesis and Morning Sun\n"
	.string "restore less health.\p"
	.string "Activates certain abilities: Dry Skin,\n"
	.string "Forecast, Hydration, Rain Dish and\l"
	.string "Sea Guardian.$"

PetalburgCity_PokemonSchool_EventScript_Heavy_Rain:
    msgbox PetalburgCity_PokemonSchool_Text_Heavy_Rain MSGBOX_DEFAULT
    closemessage
	goto PetalburgCity_PokemonSchool_EventScript_Blackboard

PetalburgCity_PokemonSchool_Text_Heavy_Rain:
	.string "Same effects of Rain.\p"
	.string "But it also increases the power of\n"
	.string "Water-type moves by 50% and causes\l"
	.string "Fire-type moves to fail if used.$"

PetalburgCity_PokemonSchool_EventScript_Sandstorm:
    msgbox PetalburgCity_PokemonSchool_Text_Sandstorm MSGBOX_DEFAULT
    closemessage
	goto PetalburgCity_PokemonSchool_EventScript_Blackboard

PetalburgCity_PokemonSchool_Text_Sandstorm:
	.string "At the end of each turn, damages\n"
	.string "each Pokémon for 1/16 of its\l"
	.string "maximum HP, unless it is Rock-,\l"
	.string "Steel-, Ground-type or has one\l"
	.string "of the abilities: Sand Force,\l"
	.string "Sand Rush, Sand Veil, Magic Guard,\l"
	.string "Impenetrable or Overcoat, or is\l"
	.string "holding Safety Goggles.\p"
	.string "The damage is doubled if there is\n"
	.string "a Pokémon with Ranging Storm on\l"
	.string "the battlefield.\p"
	.string "Raises the Special Defense of Rock-\n"
	.string "type Pokémon.\p"
	.string "Changes Weather Ball's type and doubles\n"
	.string "its power.\p"
	.string "Halves the power of Solar Beam and\n"
	.string "Solar Blade.\p"
	.string "Moonlight, Synthesis and Morning Sun\n"
	.string "restore less health.\p"
	.string "Shore Up restore more health.\p"
	.string "Activates certain abilities: Sand\n"
	.string "Force, Sand Rush and Sand Veil.$"

PetalburgCity_PokemonSchool_EventScript_Hailstorm:
    msgbox PetalburgCity_PokemonSchool_Text_Hailstorm MSGBOX_DEFAULT
    closemessage
	goto PetalburgCity_PokemonSchool_EventScript_Blackboard

PetalburgCity_PokemonSchool_Text_Hailstorm:
	.string "At the end of each turn, damages\n"
	.string "each Pokémon for 1/16 of its\l"
	.string "maximum HP, unless it is Ice-\l"
	.string "type or has one of the abilities:\l"
	.string "Ice Body, Snow Cloak, Magic Guard,\l"
	.string "Impenetrable, Aurora Borealis or\l"
	.string "Overcoat, or is holding Safety\l"
	.string "Goggles.\p"
	.string "The damage is doubled if there is\n"
	.string "a Pokémon with Ranging Storm on\l"
	.string "the battlefield.\p"
	.string "Raises the Defense stat of Ice-type\n"
	.string "Pokémon.\p"
	.string "Changes Weather Ball's type and doubles\n"
	.string "its power.\p"
	.string "Allows Blizzard to bypass the\n"
	.string "accuracy check.\p"
	.string "Halves the power of Solar Beam and\n"
	.string "Solar Blade.\p"
	.string "Moonlight, Synthesis and Morning Sun\n"
	.string "restore less health.\p"
	.string "Allows Aurora Veil to be used.\p"
	.string "Activates certain abilities: Ice\n"
	.string "Body, Forecast, Snow Cloak and\l"
	.string "Slush Rush.$"

PetalburgCity_PokemonSchool_EventScript_Fog:
    msgbox PetalburgCity_PokemonSchool_Text_Fog MSGBOX_DEFAULT
    closemessage
	goto PetalburgCity_PokemonSchool_EventScript_Blackboard

PetalburgCity_PokemonSchool_Text_Fog:
	.string "The accuracy of all moves are lowered.\n"
	.string "by 40%.\p"
	.string "Pokémon that has Keen Eye, Compound Eyes\n"
	.string "or Infiltrator are unaffected.\p"
	.string "Halves the power of Solar Beam and\n"
	.string "Solar Blade.\p"
	.string "Moonlight, Synthesis and Morning Sun\n"
	.string "restore less health.$"

PetalburgCity_PokemonSchool_EventScript_Strong_Winds:
    msgbox PetalburgCity_PokemonSchool_Text_Strong_Winds MSGBOX_DEFAULT
    closemessage
	goto PetalburgCity_PokemonSchool_EventScript_Blackboard

PetalburgCity_PokemonSchool_Text_Strong_Winds:
	.string "Cause moves that would be super\n"
	.string "effective against pure Flying-type\l"
	.string "Pokémon to only be normally effective.$"
