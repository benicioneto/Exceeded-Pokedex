.set LOCALID_POLICE_3, 4
.set LOCALID_SHACKLES, 11
.set LOCALID_TEAM_ROCKET, 12
.set LOCALID_GROWLITHE, 6

LilycoveCity_PoliceStation_MapScripts::
	.byte 0

LilycoveCity_PoliceStation_PoliceAttendant::
	lock
	faceplayer
	msgbox LilycoveCity_PoliceStation_Text_PoliceAttendant, MSGBOX_DEFAULT
	waitmessage
	compare VAR_LILYCOVE_TEAM_ROCKET_STEAL, 0
	goto_if_gt LilycoveCity_PoliceStation_PoliceAttendantEnd
	goto_if_set FLAG_SUSPECIOUS_TEAM_ROCKET, LilycoveCity_PoliceStation_PoliceAttendantReport
LilycoveCity_PoliceStation_PoliceAttendantEnd:
	release
	end

LilycoveCity_PoliceStation_PoliceAttendantReport:
	msgbox LilycoveCity_PoliceStation_Text_Report, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq LilycoveCity_PoliceStation_PoliceAttendantAreYouSure
	goto LilycoveCity_PoliceStation_PoliceAttendantEnd

LilycoveCity_PoliceStation_PoliceAttendantAreYouSure:
	msgbox LilycoveCity_PoliceStation_Text_AreYouSure, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq LilycoveCity_PoliceStation_PoliceAttendantArrestTeamRocket
	goto LilycoveCity_PoliceStation_PoliceAttendantEnd

LilycoveCity_PoliceStation_PoliceAttendantArrestTeamRocket:
	msgbox LilycoveCity_PoliceStation_Text_PoliceAttendantSentPatrol, MSGBOX_DEFAULT
	waitmessage
	closemessage
	fadescreen FADE_TO_BLACK
	setflag FLAG_LILYCOVE_TEAM_ROCKET 
	clearflag FLAG_TEAM_ROCKET_IN_PRISON
	addobject LOCALID_TEAM_ROCKET
	setvar VAR_LILYCOVE_TEAM_ROCKET_STEAL, 0
	delay 30
	msgbox LilycoveCity_PoliceStation_Text_PoliceAttendantArrent, MSGBOX_DEFAULT
	waitmessage
	closemessage
	fadescreen FADE_FROM_BLACK
	msgbox LilycoveCity_PoliceStation_Text_PoliceAttendantGiveGrowlithe, MSGBOX_DEFAULT
	waitmessage
	setflag FLAG_HIDE_HISUIAN_GROWLITHE
	removeobject LOCALID_GROWLITHE
	bufferspeciesname 0, SPECIES_GROWLITHE_HISUIAN
	setvar VAR_TEMP_1, SPECIES_GROWLITHE_HISUIAN
    givemon SPECIES_GROWLITHE_HISUIAN, 25
    switch VAR_RESULT
    case 0, EventScript_SendGrowlitheHisuianToParty
    case 1, EventScript_SendGrowlitheHisuianToPC
    case 2, Common_EventScript_NoMoreRoomForPokemon @"There's no more room for any more\..."
    end

EventScript_SendGrowlitheHisuianToParty:
    call GrowlitheHisuianPayFor
    msgbox gText_NicknameThisPokemon, MSGBOX_YESNO @"Do you want to give a nickname to\..."
    compare VAR_RESULT, 0
    goto_if_eq EventScript_ReceivedGrowlitheHisuian
    call Common_EventScript_GetGiftMonPartySlot
	call Common_EventScript_NameReceivedPartyMon
    goto EventScript_ReceivedGrowlitheHisuian
	end

EventScript_SendGrowlitheHisuianToPC:
    call ElementalMonkeyPayFor
    msgbox gText_NicknameThisPokemon, MSGBOX_YESNO @"Do you want to give a nickname to\..."
    compare VAR_RESULT, 0
    goto_if_eq EventScript_GrowlitheHisuianTransferredToPC
    call Common_EventScript_NameReceivedBoxMon
    goto EventScript_GrowlitheHisuianTransferredToPC
	end

EventScript_ReceivedGrowlitheHisuian:    
	msgbox GrowlitheHisuianReward, MSGBOX_NPC
	clearflag FLAG_SUSPECIOUS_TEAM_ROCKET
    release
    end

GrowlitheHisuianPayFor:
	playfanfare MUS_OBTAIN_ITEM
	message GrowlitheHisuianPayed
	waitmessage
	waitfanfare
	return

EventScript_GrowlitheHisuianTransferredToPC:
    call Common_EventScript_TransferredToPC
    goto EventScript_ReceivedGrowlitheHisuian
    end

LilycoveCity_PoliceStation_Police1::
	msgbox LilycoveCity_PoliceStation_Text_Police1, MSGBOX_NPC
	end

LilycoveCity_PoliceStation_Police2::
	msgbox LilycoveCity_PoliceStation_Text_Police2, MSGBOX_NPC
	end

LilycoveCity_PoliceStation_Police3::
	msgbox LilycoveCity_PoliceStation_Text_Police3, MSGBOX_NPC
	applymovement LOCALID_POLICE_3, Common_Movement_FaceDown
	end

LilycoveCity_PoliceStation_Prisioner::
	goto_if_set FLAG_GOT_ARRESTED, LilycoveCity_PoliceStation_PrisionerSecondTime
	msgbox LilycoveCity_PoliceStation_Text_Prisioner, MSGBOX_NPC
	end

LilycoveCity_PoliceStation_PrisionerSecondTime:
	msgbox LilycoveCity_PoliceStation_Text_PrisionerSecondTime, MSGBOX_NPC
	end

LilycoveCity_PoliceStation_HisuianGrowlithe::
	lock
	faceplayer
	playmoncry SPECIES_GROWLITHE_HISUIAN, 0
	msgbox LilycoveCity_PoliceStation_Text_HisuianGrowlithe, MSGBOX_DEFAULT
	waitmoncry
	release
	end

PoliceStation_EventScript_Bed::
	lockall
	setvar VAR_LILYCOVE_TEAM_ROCKET_STEAL, 9
	setflag FLAG_HIDE_LILYCOVE_POLICE
	msgbox PoliceStation_Text_TakeRestOnBed, MSGBOX_DEFAULT
	closemessage
	fadescreen FADE_TO_BLACK
	playfanfare MUS_HEAL
	waitfanfare
	@special HealPlayerParty
	@fadescreen FADE_FROM_BLACK
	warp MAP_LILYCOVE_CITY, 255, 18, 15
	waitstate
	end

PoliceStation_EventScript_Shackles::
	lock
	giveitem ITEM_SHACKLES
	setflag FLAG_RECEIVED_SHACKLES
	removeobject LOCALID_SHACKLES
	release
	end

PoliceStation_Text_TakeRestOnBed:
	.string "There's a bed…\n"
	.string "Let's take a rest.$"

LilycoveCity_PoliceStation_Text_PoliceAttendant:
	.string "Welcome to the Lilycove Police Station!\p"
	.string "If you find anything suspicious,\n"
	.string "just call us.$"

LilycoveCity_PoliceStation_Text_HisuianGrowlithe:
	.string "Groo-wl!$"

LilycoveCity_PoliceStation_Text_Police1:
	.string "At the International Police base,\n"
	.string "a search for the location of the\l"
	.string "Team Rocket Boss Giovanni is\l"
	.string "underway…\p"
	.string "Team Rocket had taken over the Kanto\n"
	.string "region's underworld, and is supected\l"
	.string "that their operations of illegal\l"
	.string "poaching and Pokémon traffick\l"
	.string "reached Hoenn region too…$"

LilycoveCity_PoliceStation_Text_Police2:
	.string "It's said that agent Looker and the\n"
	.string "International Police storm the\l"
	.string "Viridian Gym, but couldn't handle\l"
	.string "a single Pokémon from Giovanni…\p"
	.string "He took care of all International\n"
	.string "agents at once.\p"
	.string "Who'd imagine that Giovanni would\n"
	.string "have such a powerful Pokémon\l"
	.string "in his hands…$"

LilycoveCity_PoliceStation_Text_Police3:
	.string "I have to be vigilant to prevent\n"
	.string "any prisioner from escaping.\l"
	.string "Especially the prisioners in the\l"
	.string "last cell…\p"
	.string "They are extremely dangerous…$"

LilycoveCity_PoliceStation_Text_Prisioner:
	.string "I don't want to spend ¥100 per night\n"
	.string "in Lilycove Motel so I do anything\l"
	.string "wrong to sleep here…\p"
	.string "I'm smart, do I?$"

LilycoveCity_PoliceStation_Text_PrisionerSecondTime:
	.string "I knew you liked my idea!\n"
	.string "You end up saving a lot\l"
	.string "of money sleeping here.$"

LilycoveCity_PoliceStation_Text_Report:
	.string "Do you want to report a crime?$"

LilycoveCity_PoliceStation_Text_AreYouSure:
	.string "Are you sure?\n"
	.string "You can't play with the police.$"

LilycoveCity_PoliceStation_Text_PoliceAttendantSentPatrol:
	.string "I'll open a case for an\n"
	.string "investigation.$"

LilycoveCity_PoliceStation_Text_PoliceAttendantArrent:
	.string "Police found an suspicious\n"
	.string "Team Rocket member.\l"
	.string "He confessed willing to steal.$"

LilycoveCity_PoliceStation_Text_PoliceAttendantGiveGrowlithe:
	.string "{PLAYER}, your report was correct!\n"
	.string "We arrested a Team Rocket member.\l"
	.string "He was trying to steal a painting$"
	.string "from Lilycove Museum.\p"
	.string "As a compensation, I will give you\n"
	.string "our mascot!$"

GrowlitheHisuianPayed:
	.string "{PLAYER} received the {STR_VAR_1}!$"

GrowlitheHisuianReward:
	.string "This Pokémon is from another region!$"
