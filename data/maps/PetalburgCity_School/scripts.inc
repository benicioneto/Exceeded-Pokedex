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
	case 8, PetalburgCity_PokemonSchool_EventScript_Night
	case 9, PetalburgCity_PokemonSchool_EventScript_Cancel
PetalburgCity_PokemonSchool_EventScript_Cancel:
    closemessage
    end

PetalburgCity_PokemonSchool_EventScript_Harsh_Sunlight:
    msgbox PetalburgCity_PokemonSchool_Text_Harsh_Sunlight MSGBOX_DEFAULT
    closemessage
	goto PetalburgCity_PokemonSchool_EventScript_Blackboard

PetalburgCity_PokemonSchool_Text_Harsh_Sunlight:
	.string "Increases the power of Fire-type moves\n"
	.string "by 50%.\p"
	.string "Decreases the power of Water-type moves\n"
	.string "by 50%.\p"
	.string "Allows Solar Beam and Solar Blade to be\n"
	.string "used instantly.\p"
	.string "Changes Weather Ball's type and doubles\n"
	.string "its power.\p"
	.string "Causes Growth to raise Attack and\n"
	.string "Special Attack two stages each.\p"
	.string "Synthesis and Morning Sun restore\n"
	.string "more health.\p"
	.string "Moonlight restores less health.\p"
	.string "Lowers accuracy of Thunder, Hurricane,\n"
	.string "Lunar Flare, Crowstorm and Nightfall\l"
	.string "Daze by 50%.\p"
	.string "Halves the power of Midnight Beam.\p"
	.string "Prevents Pokémon from becoming\n"
	.string "Frozen.\p"
	.string "Allows Fire Wall to be used.\p"
	.string "Activated by certain abilities: Drought,\n"
	.string "Desolate Land and Orichalcum Pulse.\p"
	.string "Activates certain abilities: Chlorophyll,\n"
	.string "Dry Skin, Flower Gift, Forecast, Leaf\l"
	.string "Guard, Solar Power, Harvest, Laval\l"
	.string "Body, Cold Blooded, Future Gaze,\l"
	.string "Photosynthesis, Protosynthesis,\l"
	.string "Photovoltaic Frill, Cosmic Energy,\l"
	.string "Misty Escape, Radiant Crystal,\l"
	.string "Phototropism and Desert Flower.\p"
	.string "Pokémon with Mega Sol ability behaves\n"
	.string "as though the weather were harsh\l"
	.string "sunlight, regardless of actual weather.\p"
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
	.string "But it also causes Water-type moves\n"
	.string "to fail if used.\p"
	.string "Activates certain abilities: Desolate\n"
	.string "Land.$"

PetalburgCity_PokemonSchool_EventScript_Rain:
    msgbox PetalburgCity_PokemonSchool_Text_Rain MSGBOX_DEFAULT
    closemessage
	goto PetalburgCity_PokemonSchool_EventScript_Blackboard

PetalburgCity_PokemonSchool_Text_Rain:
	.string "Increases the power of Water-type moves\n"
	.string "by 50%.\p"
	.string "Decreases the power of Fire-type moves\n"
	.string "by 50%.\p"
	.string "Allows Electro Shot to be used\n"
	.string "instantly.\p"
	.string "Allows Thunder, Hurricane and Wildbolt\n"
	.string "Storm to bypass the accuracy check.\p"
	.string "Changes Weather Ball's type and doubles\n"
	.string "its power.\p"
	.string "Halves the power of Solar Beam and\n"
	.string "Solar Blade.\p"
	.string "Moonlight, Synthesis and Morning Sun\n"
	.string "restore less health.\p"
	.string "Activated by certain abilities: Drizzle,\n"
	.string "Primordial Sea and Sea Guardian.\p"
	.string "Activates certain abilities: Dry Skin,\n"
	.string "Forecast, Hydration, Rain Dish and\l"
	.string "Sea Guardian.$"

PetalburgCity_PokemonSchool_EventScript_Heavy_Rain:
    msgbox PetalburgCity_PokemonSchool_Text_Heavy_Rain MSGBOX_DEFAULT
    closemessage
	goto PetalburgCity_PokemonSchool_EventScript_Blackboard

PetalburgCity_PokemonSchool_Text_Heavy_Rain:
	.string "Same effects of Rain.\p"
	.string "But it also causes Fire-type moves\n"
	.string "to fail if used.\p"
	.string "Activates certain abilities: Primordial\n"
	.string "Sea.$"

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
	.string "Sand Veil, Magic Guard, Impenetrable,\l"
	.string "Overcoat or Soot Veil, or is\l"
	.string "holding Safety Goggles.\p"
	.string "The damage is doubled if there is\n"
	.string "a Pokémon with Ranging Storm on\l"
	.string "the battlefield.\p"
	.string "Allows Sandsear Storm to bypass the\n"
	.string "accuracy check.\p"
	.string "Raises the Special Defense of Rock-\n"
	.string "type Pokémon.\p"
	.string "Changes Weather Ball's type and doubles\n"
	.string "its power.\p"
	.string "Halves the power of Solar Beam, Solar\n"
	.string "Blade and Midnight Beam.\p"
	.string "Moonlight, Synthesis and Morning Sun\n"
	.string "restore less health.\p"
	.string "Shore Up restores more health.\p"
	.string "Activated by certain abilities: Sand\n"
	.string "Stream and Sand Spit.\p"
	.string "Activates certain abilities: Sand\n"
	.string "Force, Sand Rush, Sand Veil, Wind\l"
	.string "Power, Wind Rider, Clay Vessel and\l"
	.string "Sand Glider.$"

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
	.string "If it would inflict Frostbite on\n"
	.string "an already frosbited Pokémon, it will\l"
	.string "become Frozen instead but with 1/10\l"
	.string "of the chance.\p"
	.string "Raises the Defense stat of Ice-type\n"
	.string "Pokémon.\p"
	.string "Allows Ice Burn and Freeze Shock to\n"
	.string "be used instantly.\p"
	.string "Changes Weather Ball's type and doubles\n"
	.string "its power.\p"
	.string "Allows Blizzard to bypass the\n"
	.string "accuracy check.\p"
	.string "Halves the power of Solar Beam, Solar\n"
	.string "Blade and Midnight Beam.\p"
	.string "Moonlight, Synthesis and Morning Sun\n"
	.string "restore less health.\p"
	.string "Allows Aurora Veil to be used.\p"
	.string "Allows Aurora Dance to be used once.\p"
	.string "Activates certain abilities: Snow\n"
	.string "Warming and Polar Current.\p"
	.string "Activates certain abilities: Ice\n"
	.string "Body, Forecast, Snow Cloak, Slush\l"
	.string "Rush, Aurora Guard, Christmas Spirit,\l"
	.string "Hoarfrost Skin, Yuki Onna, Arctic Force,\l"
	.string "Cold Blooded and Ice Face.$"

PetalburgCity_PokemonSchool_EventScript_Fog:
    msgbox PetalburgCity_PokemonSchool_Text_Fog MSGBOX_DEFAULT
    closemessage
	goto PetalburgCity_PokemonSchool_EventScript_Blackboard

PetalburgCity_PokemonSchool_Text_Fog:
	.string "The accuracy of all moves are lowered\n"
	.string "by 40%.\p"
	.string "Pokémon that has Keen Eye, Compound\n"
	.string "Eyes, Infiltrator, Mind's Eye,\l"
	.string "Vulture Eye, Falcon Eye, Owl Eye,\l"
	.string "Echolocation, Hawk Eye and Eagle Eye\l"
	.string "are unaffected.\p"
	.string "Roost restores more health.\p"
	.string "Halves the power of Solar Beam, Solar\n"
	.string "Blade and Midnight Beam.\p"
	.string "Moonlight, Synthesis and Morning Sun\n"
	.string "restore less health.$"

PetalburgCity_PokemonSchool_EventScript_Strong_Winds:
    msgbox PetalburgCity_PokemonSchool_Text_Strong_Winds MSGBOX_DEFAULT
    closemessage
	goto PetalburgCity_PokemonSchool_EventScript_Blackboard

PetalburgCity_PokemonSchool_Text_Strong_Winds:
	.string "Cause moves that would be super\n"
	.string "effective against pure Flying-type\l"
	.string "Pokémon to only be normally effective.\p"
	.string "Activates certain abilities: Delta\n"
	.string "Stream.$"

PetalburgCity_PokemonSchool_EventScript_Night:
    msgbox PetalburgCity_PokemonSchool_Text_Night MSGBOX_DEFAULT
    closemessage
	goto PetalburgCity_PokemonSchool_EventScript_Blackboard

PetalburgCity_PokemonSchool_Text_Night:
	.string "Increases the power of Dark-type moves\n"
	.string "by 50%.\p"
	@.string "Decreases the power of Fairy-type moves\n"
	@.string "by 50%.\p"
	.string "Allows Midnight Beam to be used\n"
	.string "instantly.\p"
	.string "Allows Nightfall Daze, Crowstorm and\n"
	.string "Lunar Flare to bypass the accuracy\l"
	.string "check.\p"
	.string "Changes Weather Ball's type and doubles\n"
	.string "its power.\p"
	.string "Halves the power of Solar Beam and\n"
	.string "Solar Blade.\p"
	.string "Moonlight restores more health.\p"
	.string "Synthesis and Morning Sun\n"
	.string "restore less health.\p"
	.string "Activated by certain abilities: Umbral\n"
	.string "Dominion.\p"
	.string "Activates certain abilities: Nocturnal,\n"
	.string "Forecast, Dark Bribe, Maleficent, Moon\l"
	.string "Guard and Night Synthesis.\p"
	.string "Pokémon with Full Moon ability behaves\n"
	.string "as though the weather were gloom\l"
	.string "moonlight, regardless of actual weather.$"
	
