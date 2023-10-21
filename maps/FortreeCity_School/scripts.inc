FortreeCity_School_MapScripts::
	.byte 0

FortreeCity_PokemonSchool_EventScript_Lass::
	msgbox FortreeCity_PokemonSchool_Text_ConfusedPokemonAttacksItself, MSGBOX_NPC
	end

FortreeCity_PokemonSchool_EventScript_LittleGirl::
	goto_if_unset FLAG_RECEIVED_TM65_FOG, FortreeCity_PokemonSchool_EventScript_LittleGirlGiveTMFog
	msgbox FortreeCity_PokemonSchool_Text_ExplainGym, MSGBOX_NPC
	end

FortreeCity_PokemonSchool_EventScript_LittleGirlGiveTMFog:
	lock
	faceplayer
	msgbox FortreeCity_PokemonSchool_Text_CannotSeeFog, MSGBOX_DEFAULT
	waitmessage
	giveitem ITEM_TM65_FOG
	compare VAR_RESULT, FALSE
	goto_if_eq Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_TM65_FOG
	msgbox FortreeCity_PokemonSchool_Text_ExplainFog, MSGBOX_DEFAULT
	waitmessage
	release
	end

FortreeCity_PokemonSchool_Text_ConfusedPokemonAttacksItself:
	.string "Damaging moves typically vary in\n"
	.string "effectiveness depending on the\l"
	.string "move's type and the types of its\l"
	.string "target.\p"
	.string "Supereffective moves deals x2 damage,\n"
	.string "or even x2.5 or x3 if the target\l"
	.string "has multiple types.\p"
	.string "Or can be not very effective, dealing\n"
	.string "x0.5, x0.4 or x0.3 less damage.\p"
	.string "Or ineffective, dealing no damage\n"
	.string "at all.$"

FortreeCity_PokemonSchool_EventScript_Teacher::
	lock
	faceplayer
	delay 16
	applymovement LOCALID_TEACHER, Common_Movement_FaceUp
	waitmovement 0
	delay 16
	delay 16
	faceplayer
	delay 16
	msgbox FortreeCity_PokemonSchool_Text_Teacher, MSGBOX_DEFAULT
	release
	end

FortreeCity_PokemonSchool_Text_Teacher:
	.string "Today the lesson is about the\n"
	.string "classification of moves.\p"
	.string "You can see the summary on the\n"
	.string "Blackboard.$"

FortreeCity_PokemonSchool_EventScript_Blackboard::
	message Common_PokemonSchool_Text_ReadWhichTopic
	waitmessage
	setvar VAR_0x8004, SCROLL_MULTI_FORTREE_SCHOOL
	special ShowScrollableMultichoice
	waitstate	
	switch VAR_RESULT
	case 0, FortreeCity_PokemonSchool_EventScript_Acid
	case 1, FortreeCity_PokemonSchool_EventScript_AirbourneStyle
	case 2, FortreeCity_PokemonSchool_EventScript_Ballistic
	case 3, FortreeCity_PokemonSchool_EventScript_Biting
	case 4, FortreeCity_PokemonSchool_EventScript_Crash
	case 5, FortreeCity_PokemonSchool_EventScript_Dance
	case 6, FortreeCity_PokemonSchool_EventScript_Fang
	case 7, FortreeCity_PokemonSchool_EventScript_Field
	case 8, FortreeCity_PokemonSchool_EventScript_HitFlyingType
	case 9, FortreeCity_PokemonSchool_EventScript_HitMinimize
	case 10, FortreeCity_PokemonSchool_EventScript_HitSemiInvulnerable
	case 11, FortreeCity_PokemonSchool_EventScript_IgnoreAbilities
	case 12, FortreeCity_PokemonSchool_EventScript_IgnoreDefense
	case 13, FortreeCity_PokemonSchool_EventScript_IgnoreEvasion
	case 14, FortreeCity_PokemonSchool_EventScript_Launcher
	case 15, FortreeCity_PokemonSchool_EventScript_Magnet
FortreeCity_PokemonSchool_EventScript_Cancel:
    closemessage
    end

FortreeCity_PokemonSchool_EventScript_Blackboard2::
	message Common_PokemonSchool_Text_ReadWhichTopic
	waitmessage
	setvar VAR_0x8004, SCROLL_MULTI_FORTREE_SCHOOL2
	special ShowScrollableMultichoice
	waitstate	
	switch VAR_RESULT
	case 0, FortreeCity_PokemonSchool_EventScript_Mud
	case 1, FortreeCity_PokemonSchool_EventScript_Powder
	case 2, FortreeCity_PokemonSchool_EventScript_Punching
	case 3, FortreeCity_PokemonSchool_EventScript_Recoil
	case 4, FortreeCity_PokemonSchool_EventScript_Slicing
	case 5, FortreeCity_PokemonSchool_EventScript_Sound
	case 6, FortreeCity_PokemonSchool_EventScript_Thaw
	case 7, FortreeCity_PokemonSchool_EventScript_Wave
	case 8, FortreeCity_PokemonSchool_EventScript_WeatherRelated
	case 9, FortreeCity_PokemonSchool_EventScript_Wind
	case 10, FortreeCity_PokemonSchool_EventScript_Wing
	goto FortreeCity_PokemonSchool_EventScript_Cancel

FortreeCity_PokemonSchool_EventScript_Acid:
    msgbox FortreeCity_PokemonSchool_Text_Acid MSGBOX_DEFAULT
    closemessage
	goto FortreeCity_PokemonSchool_EventScript_Blackboard

FortreeCity_PokemonSchool_Text_Acid:
	.string "Acid, Acid Spray, Apple Acid\n"
	.string "and Acid Downpour.\p"
	.string "Special effect: deals super\n"
	.string "effective on Steel-type.\p"
	.string "Abilities that interacts with:\n"
	.string "None.$"

FortreeCity_PokemonSchool_EventScript_AirbourneStyle:
    msgbox FortreeCity_PokemonSchool_Text_AirbourneStyle MSGBOX_DEFAULT
    closemessage
	goto FortreeCity_PokemonSchool_EventScript_Blackboard

FortreeCity_PokemonSchool_Text_AirbourneStyle:
	.string "Mega Kick, Rolling Kick, Low Kick,\n"
	.string "Blaze Kick, Trop Kick and\l"
	.string "Thunderous Kick.\p"
	.string "Abilities that interacts with:\n"
	.string "Airbourne Style.$"

FortreeCity_PokemonSchool_EventScript_Ballistic:
    msgbox FortreeCity_PokemonSchool_Text_Ballistic MSGBOX_DEFAULT
    closemessage
	goto FortreeCity_PokemonSchool_EventScript_Blackboard

FortreeCity_PokemonSchool_Text_Ballistic:
	.string "Acid Spray, Aura Sphere, Barrage,\n"
	.string "Beak Blast, Bullet Seed, Egg Bomb,\l"
	.string "Electro Ball, Energy Ball, Focus Blast,\l"
	.string "Gyro Ball, Ice Ball, Magnet Bomb, Mist\l"
	.string "Ball, Mud Bomb, Octazooka, Polen Puff,\l"
	.string "Pyro Ball, Rock Blast, Rock Wrecker,\l"
	.string "Searing Shot, Seed Bomb, Shadow Ball,\l"
	.string "Sludge Bomb, Weather Ball, Zap Cannon\l"
	.string "and Aura Cannon.\p"
	.string "Abilities that interacts with:\n"
	.string "Bulletproof.$"

FortreeCity_PokemonSchool_EventScript_Biting:
    msgbox FortreeCity_PokemonSchool_Text_Biting MSGBOX_DEFAULT
    closemessage
	goto FortreeCity_PokemonSchool_EventScript_Blackboard

FortreeCity_PokemonSchool_Text_Biting:
	.string "Bite, Crunch, Fire Fang, Fishious\n"
	.string "Rend, Hyper Fang, Ice Fang, Jaw Lock,\l"
	.string "Poison Fang, Psychic Fangs,\l"
	.string "Thunder Fang, Bug Bite, Aqua Fang,\l"
	.string "Deathroll and Undeground Bite.\p"
	.string "Abilities that interacts with:\n"
	.string "Strong Jaw, Leech Fangs and\l"
	.string "Solenoglyphs.$"

FortreeCity_PokemonSchool_EventScript_Crash:
    msgbox FortreeCity_PokemonSchool_Text_Crash MSGBOX_DEFAULT
    closemessage
	goto FortreeCity_PokemonSchool_EventScript_Blackboard

FortreeCity_PokemonSchool_Text_Crash:
	.string "High Jump Kick, Jump Kick and\n"
	.string "Axe Kick.\p"
	.string "Special effect: If the move\n"
	.string "misses, the user takes damage\l"
	.string "equal to half of its maximum\l"
	.string "HP.\p"
	.string "Abilities that interacts with:\n"
	.string "Reckless and Limber.$"

FortreeCity_PokemonSchool_EventScript_Dance:
    msgbox FortreeCity_PokemonSchool_Text_Dance MSGBOX_DEFAULT
    closemessage
	goto FortreeCity_PokemonSchool_EventScript_Blackboard

FortreeCity_PokemonSchool_Text_Dance:
	.string "Feather Dance, Fiery Dance, Dragon\n"
	.string "Dance, Lunar Dance, Petal Dance,\l"
	.string "Revelation Dance, Quiver Dance,\l"
	.string "Swords Dance and Teeter Dance.\p"
	.string "Abilities that interacts with:\n"
	.string "Dancer.$"

FortreeCity_PokemonSchool_EventScript_Fang:
    msgbox FortreeCity_PokemonSchool_Text_Fang MSGBOX_DEFAULT
    closemessage
	goto FortreeCity_PokemonSchool_EventScript_Blackboard

FortreeCity_PokemonSchool_Text_Fang:
	.string "Hyper Fang, Super Fang, Poison Fang,\n"
	.string "Thunder Fang, Fire Fang, Ice Fang,\l"
	.string "Aqua Fang and Psychic Fangs.\p"
	.string "Abilities that interacts with:\n"
	.string "Growing Tooth.$"

FortreeCity_PokemonSchool_EventScript_Field:
    msgbox FortreeCity_PokemonSchool_Text_Field MSGBOX_DEFAULT
    closemessage
	goto FortreeCity_PokemonSchool_EventScript_Blackboard

FortreeCity_PokemonSchool_Text_Field:
	.string "Cut, Fly, Surf, Strength, Flash,\n"
	.string "Dig, Whirlpool, Waterfall, Rock Smash,\l"
	.string "Headbutt, Dive, Secret Power,\l"
	.string "Rock Climb and Chatter.\p"
	.string "Abilities that interacts with:\n"
	.string "Field Explorer.$"

FortreeCity_PokemonSchool_EventScript_HitFlyingType:
    msgbox FortreeCity_PokemonSchool_Text_HitFlyingType MSGBOX_DEFAULT
    closemessage
	goto FortreeCity_PokemonSchool_EventScript_Blackboard

FortreeCity_PokemonSchool_Text_HitFlyingType:
	.string "Bone Club, Bonemerang, Bone Rush,\n"
	.string "Barrage, Octazooka, Drill Run,\l"
	.string "Thousand Arrows and High Horsepower.\p"
	.string "Special effect: can hit Flying-type\n"
	.string "Pokémon or Pokémon in air.\p"
	.string "Abilities that interacts with:\n"
	.string "Levitate.$"

FortreeCity_PokemonSchool_EventScript_HitMinimize:
    msgbox FortreeCity_PokemonSchool_Text_HitMinimize MSGBOX_DEFAULT
    closemessage
	goto FortreeCity_PokemonSchool_EventScript_Blackboard

FortreeCity_PokemonSchool_Text_HitMinimize:
	.string "Stomp, Body Slam, Needle Arm, Astonish,\n"
	.string "Extrasensory, Dragon Rush, Shadow Force,\l"
	.string "Heavy Slam, Heat Crash, Steamroller,\l"
	.string "Flying Press, Phantom Force and Double\l"
	.string "Iron Bash.\p"
	.string "Special effect: deals double\n"
	.string "damage to minimized Pokémon.\p"
	.string "Special effect 2: bypass accuracy\n"
	.string "check against minimized Pokémon.\p"
	.string "Abilities that interacts with:\n"
	.string "None.$"

FortreeCity_PokemonSchool_EventScript_HitSemiInvulnerable:
    msgbox FortreeCity_PokemonSchool_Text_HitSemiInvulnerable MSGBOX_DEFAULT
    closemessage
	goto FortreeCity_PokemonSchool_EventScript_Blackboard

FortreeCity_PokemonSchool_Text_HitSemiInvulnerable:
	.string "Gust, Hurricane, Sky Uppercut,\n"
	.string "Smack Down, Thousand Arrows,\l"
	.string "Thunder, Twister and Whirlwind.\p"
	.string "Special effect: Gust and Twister\n"
	.string "deals double damage to targets\l"
	.string "in air.\p"
	.string "Abilities that interacts with:\n"
	.string "Birds of Prey.\p"
	.string "Earthquake, Fissure, Bulldoze and\n"
	.string "Geogeyser.\p"
	.string "Special effect: deals double\n"
	.string "damage to underground targets.\p"
	.string "Abilities that interacts with:\n"
	.string "Subterranean.\p"
	.string "Surf and Whirlpool.\p"
	.string "Special effect: deals double\n"
	.string "damage to underwater targets.\p"
	.string "Abilities that interacts with:\n"
	.string "Abyssal Voyager.$"

FortreeCity_PokemonSchool_EventScript_IgnoreAbilities:
    msgbox FortreeCity_PokemonSchool_Text_IgnoreAbilities MSGBOX_DEFAULT
    closemessage
	goto FortreeCity_PokemonSchool_EventScript_Blackboard

FortreeCity_PokemonSchool_Text_IgnoreAbilities:
	.string "Horn Drill, Sunsteel Strike, \n"
	.string "Moongeist Beam and Photon Geyser.\p"
	.string "Abilities that interacts with:\n"
	.string "None.$"

FortreeCity_PokemonSchool_EventScript_IgnoreDefense:
    msgbox FortreeCity_PokemonSchool_Text_IgnoreDefense MSGBOX_DEFAULT
    closemessage
	goto FortreeCity_PokemonSchool_EventScript_Blackboard

FortreeCity_PokemonSchool_Text_IgnoreDefense:
	.string "Horn Attack, Horn Drill, Megahorn,\n"
	.string "Horn Leech, Chip Away, Sacred Sword,\l"
	.string "Darkest Lariat and Deathroll.\p"
	.string "Abilities that interacts with:\n"
	.string "None.$"

FortreeCity_PokemonSchool_EventScript_IgnoreEvasion:
    msgbox FortreeCity_PokemonSchool_Text_IgnoreEvasion MSGBOX_DEFAULT
    closemessage
	goto FortreeCity_PokemonSchool_EventScript_Blackboard

FortreeCity_PokemonSchool_Text_IgnoreEvasion:
	.string "Chip Away, Sacred Sword,\n"
	.string "Darkest Lariat and Deathroll.\p"
	.string "Abilities that interacts with:\n"
	.string "None.$"

FortreeCity_PokemonSchool_EventScript_Launcher:
    msgbox FortreeCity_PokemonSchool_Text_Launcher MSGBOX_DEFAULT
    closemessage
	goto FortreeCity_PokemonSchool_EventScript_Blackboard

FortreeCity_PokemonSchool_Text_Launcher:
	.string "Water Gun, Hydro Pump, Ice Beam,\n"
	.string "Psybeam, Bubble Beam, Aurora Beam,\l"
	.string "Hyper Beam, Solar Beam, Spikes\l"
	.string "Cannon, Octazooka, Zap Cannon,\l"
	.string "Hydro Cannon, Signal Beam, Water\l"
	.string "Pulse, Aura Sphere, Dark Pulse,\l"
	.string "Dragon Pulse, Flash Cannon,\l"
	.string "String Shot, Mud Shot, Mirror\l"
	.string "Shot, Gunk Shot, Charge Beam,\l"
	.string "Heal Pulse, Searing Shot, Origin\l"
	.string "Pulse, Anchor Shot, Fleur Cannon,\l"
	.string "Moongeist Beam, Dynamax Cannon,\l"
	.string "Snipe Shot, Tar Shot, Eternabeam,\l"
	.string "Steel Beam, Scale Shot, Meteor\l"
	.string "Beam, Terrain Pulse, Feather\l"
	.string "Shot.\p"
	.string "Abilities that interacts with:\n"
	.string "Mega Launcher, Artillery and\l"
	.string "Refraction.$"

FortreeCity_PokemonSchool_EventScript_Magnet:
    msgbox FortreeCity_PokemonSchool_Text_Magnet MSGBOX_DEFAULT
    closemessage
	goto FortreeCity_PokemonSchool_EventScript_Blackboard

FortreeCity_PokemonSchool_Text_Magnet:
	.string "Charge, Gear Up, Magnet Rise, Magnet\n"
	.string "Bomb, Magnet Flux and Shift Gear.\p"
	.string "Abilities that interacts with:\n"
	.string "Minus and Plus.$"

@@@@@ second blackboard @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

FortreeCity_PokemonSchool_EventScript_Mud:
    msgbox FortreeCity_PokemonSchool_Text_Mud MSGBOX_DEFAULT
    closemessage
	goto FortreeCity_PokemonSchool_EventScript_Blackboard2

FortreeCity_PokemonSchool_Text_Mud:
	.string "Mud-Slap, Muddy Water, Mud Shot\n"
	.string "and Mud Bomb.\p"
	.string "Special effect: can hit Flying-type\n"
	.string "Pokémon or Pokémon in air.\p"
	.string "Special effect 2: Water-type\n"
	.string "Pokémon gain same-type attack\l"
	.string "bonus regardless.\p"
	.string "Abilities that interacts with:\n"
	.string "None.$"

FortreeCity_PokemonSchool_EventScript_Powder:
    msgbox FortreeCity_PokemonSchool_Text_Powder MSGBOX_DEFAULT
    closemessage
	goto FortreeCity_PokemonSchool_EventScript_Blackboard2

FortreeCity_PokemonSchool_Text_Powder:
	.string "Cotton Spore, Magic Powder, Poison\n"
	.string "Powder, Powder, Rage Powder, Sleep\l"
	.string "Powder, Spore, Stun Spore and Cordyceps.\p"
	.string "Special effect: Grass-type Pokémon\n"
	.string "are unaffected.\p"
	.string "Items that interacts with:\n"
	.string "Safety Goggles.\p"
	.string "Abilities that interacts with:\n"
	.string "Overcoat.$"

FortreeCity_PokemonSchool_EventScript_Punching:
    msgbox FortreeCity_PokemonSchool_Text_Punching MSGBOX_DEFAULT
    closemessage
	goto FortreeCity_PokemonSchool_EventScript_Blackboard2

FortreeCity_PokemonSchool_Text_Punching:
	.string "Bullet Punch, Comet Punch, Dizzy\n"
	.string "Punch, Double Iron Bash, Drain\l"
	.string "Punch, Dynamic Punch, Fire Punch,\l"
	.string "Focus Punch, Hammer Arm, Ice\l"
	.string "Hammer, Ice Punch, Mach Punch,\l"
	.string "Mega Punch, Power-Up Punch,\l"
	.string "Shadow Punch, Sky Uppercut,\l"
	.string "Thunder Punch, Meteor Mash,\l"
	.string "Plasma Fists, Surging Strikes,\l"
	.string "Sucker Punch, Wicked Blow,\l"
	.string "Jet Punch, Dragon Combo and\l"
	.string "Ki Explosion.\p"
	.string "Items that interacts with:\n"
	.string "Punching Gloves.\p"
	.string "Abilities that interacts with:\n"
	.string "Nimble Fist, Iron Fist, Precise\l"
	.string "Fist and Multi-Limbs.$"

FortreeCity_PokemonSchool_EventScript_Recoil:
    msgbox FortreeCity_PokemonSchool_Text_Recoil MSGBOX_DEFAULT
    closemessage
	goto FortreeCity_PokemonSchool_EventScript_Blackboard2

FortreeCity_PokemonSchool_Text_Recoil:
	.string "Double-Edge, Flare Blitz, Head\n"
	.string "Smash, Submission, Take Down,\l"
	.string "Wood Hammer, Brave Bird, Head\l"
	.string "Charge, Light of Ruins, Volt\l"
	.string "Tackle, Wave Crash, Wild Charge\l"
	.string "and Flame Sweep.\p"
	.string "Special effect: cause the user\n"
	.string "to take damage proportional to\l"
	.string "the damage dealt.\p"
	.string "Abilities that interacts with:\n"
	.string "Rock Head, Reckless and Ice Face.$"

FortreeCity_PokemonSchool_EventScript_Slicing:
    msgbox FortreeCity_PokemonSchool_Text_Slicing MSGBOX_DEFAULT
    closemessage
	goto FortreeCity_PokemonSchool_EventScript_Blackboard2

FortreeCity_PokemonSchool_Text_Slicing:
	.string "Swords Dance, Cut, Slash, False Swipe,\n"
	.string "Fury Cutter, Air Cutter, Aerial Ace,\l"
	.string "Leaf Blade, Night Slash, Air Slash,\l"
	.string "X-Scissor, Psycho Cut, Sacred Sword,\l"
	.string "Razor Shell, Secret Sword, Solar Blade,\l"
	.string "Behemoth Blade, Stone Axe, Ceaseless\l"
	.string "Edge, Population Bomb, Kowtow Cleave,\l"
	.string "Bitter Blade, Aqua Cutter, Excalibur\l"
	.string "and Midnight Slash.\p"
	.string "Items that interacts with:\n"
	.string "Muramasa.\p"
	.string "Abilities that interacts with:\n"
	.string "Blademaster, Dual Wielding, Sharpness,\l"
	.string "Sharp Blades, Hiten Mitsurugi and\l"
	.string "Ryutsuisen.$"

FortreeCity_PokemonSchool_EventScript_Sound:
    msgbox FortreeCity_PokemonSchool_Text_Sound MSGBOX_DEFAULT
    closemessage
	goto FortreeCity_PokemonSchool_EventScript_Blackboard2

FortreeCity_PokemonSchool_Text_Sound:
	.string "Boomburst, Bug Buzz, Chatter,\n"
	.string "Clanging Scales, Clangorous Soul,\l"
	.string "Confide, Disarming Voice, Echoed\l"
	.string "Voice, Eerie Spell, Grass Whistle,\l"
	.string "Growl, Heal Bell, Howl, Hyper Voice,\l"
	.string "Metal Sound, Noble Roar, Overdrive,\l"
	.string "Parting Shot, Perish Song, Relic Song,\l"
	.string "Roar, Round, Screech, Sing, Snarl,\l"
	.string "Snore, Sparkling Aria, Supersonic\l"
	.string "and Uproar.\p"
	.string "Special effect: can hit Pokémon\n"
	.string "behind a Substitute.\p"
	.string "Special effect 2: Pokémon affected\n"
	.string "by Throat Chop cannot use.\p"
	.string "Items that interacts with:\n"
	.string "Throat Spray.\p"
	.string "Abilities that interacts with:\n"
	.string "Soundproof, Liquid Voice, Amplifier,\l"
	.string "Desert Spirit and Loud Bang.$"

FortreeCity_PokemonSchool_EventScript_Thaw:
    msgbox FortreeCity_PokemonSchool_Text_Thaw MSGBOX_DEFAULT
    closemessage
	goto FortreeCity_PokemonSchool_EventScript_Blackboard2

FortreeCity_PokemonSchool_Text_Thaw:
	.string "Flame Wheel, Sacred Fire, Flare Blitz,\n"
	.string "Fusion Flare, Scald, Steam Eruption,\l"
	.string "Burn Up, Pyro Ball and Schorching Sands.\p"
	.string "Special effect: will thaw the user,\n"
	.string "then execute normally.\p"
	.string "Abilities that interacts with:\n"
	.string "None.$"

FortreeCity_PokemonSchool_EventScript_Wave:
    msgbox FortreeCity_PokemonSchool_Text_Wave MSGBOX_DEFAULT
    closemessage
	goto FortreeCity_PokemonSchool_EventScript_Blackboard2

FortreeCity_PokemonSchool_Text_Wave:
	.string "Surf, Whirlpool, Muddy Water and\n"
	.string "Sludge Wave.\p"
	.string "Abilities that interacts with:\n"
	.string "Wave Surf.$"

FortreeCity_PokemonSchool_EventScript_WeatherRelated:
    msgbox FortreeCity_PokemonSchool_Text_WeatherRelated MSGBOX_DEFAULT
    closemessage
	goto FortreeCity_PokemonSchool_EventScript_Blackboard2

FortreeCity_PokemonSchool_Text_WeatherRelated:
	.string "Blizzard, Solar Beam, Thunder,\n"
	.string "Morning Sun, Synthesis, Moonlight,\l"
	.string "Weather Ball, Hurricane, Solar Blade\l"
	.string "and Aurora Veil.\p"
	.string "Items that interacts with:\n"
	.string "Utility Umbrella.\p"
	.string "Abilities that interacts with:\n"
	.string "Weather Control.$"

FortreeCity_PokemonSchool_EventScript_Wind:
    msgbox FortreeCity_PokemonSchool_Text_Wind MSGBOX_DEFAULT
    closemessage
	goto FortreeCity_PokemonSchool_EventScript_Blackboard2

FortreeCity_PokemonSchool_Text_Wind:
	.string "Razor Wind, Icy wind, Twister, Heat Wave,\n"
	.string "Air Cutter, Silver Wind, Air Slash,\l"
	.string "Ominous Wind, Hurricane, Fairy Wind,\l"
	.string "Bleakwind Storm, Petal Blizzard,\l"
	.string "Sandsear Storm, Springtide Storm,\l"
	.string "Tailwind, Whirlwind, Wildbolt Storm\l"
	.string "and Aeroblast.\p"
	.string "Special effect: Gust, Twister,\n"
	.string "Hurricane and Aeroblast will activate\l"
	.string "entry hazards on the target, even if\l"
	.string "it wouldn't be normally affected.\p"
	.string "Abilities that interacts with:\n"
	.string "Giant Wings, Wind Power and Wind Rider.$"

FortreeCity_PokemonSchool_EventScript_Wing:
    msgbox FortreeCity_PokemonSchool_Text_Wing MSGBOX_DEFAULT
    closemessage
	goto FortreeCity_PokemonSchool_EventScript_Blackboard2

FortreeCity_PokemonSchool_Text_Wing:
	.string "Wing Attack, Steel Wing, Oblivion Wing,\n"
	.string "Dual Wingbeat and Esper Wing.\p"
	.string "Abilities that interacts with:\n"
	.string "Giant Wings.$"

FortreeCity_PokemonSchool_Text_CannotSeeFog:
	.string "You and your Pokémon cannot\n"
	.string "see throught a dense fog!\p"
	.string "Here, take this!$"

FortreeCity_PokemonSchool_Text_ExplainGym:
	.string "Winona's Gym is covered by a\n"
	.string "dense fog!\p"
	.string "Beware that your Pokémon will\n"
	.string "miss their attacks very often!$"

FortreeCity_PokemonSchool_Text_ExplainFog:
	.string "The Fog reduce the accuracy of\n"
	.string "Pokémon by 40%.\p"
	.string "Althought most birds and some\n"
	.string "insects are unaffected by the fog!$"
