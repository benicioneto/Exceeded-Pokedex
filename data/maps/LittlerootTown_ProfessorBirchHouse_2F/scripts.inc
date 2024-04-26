
.set LOCALID_BRENDAN, 1
.set LOCALID_MAY, 2

LittlerootTown_ProfessorBirchHouse_2F_MapScripts::
	.byte 0

LittlerootTown_ProfessorBirchHouse_EventScript_May::
	lock
	faceplayer
	msgbox ProfessorBirchHouse_Text_May, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_MAY, Common_Movement_FaceOriginalDirection
	release
	end

LittlerootTown_ProfessorBirchHouse_EventScript_Brendan::
	lock
	faceplayer
	msgbox ProfessorBirchHouse_Text_Brendan, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_BRENDAN, Common_Movement_FaceOriginalDirection
	release
	end

LittlerootTown_ProfessorBirchHouse_EventScript_Torchic::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_TORCHIC, 0
	msgbox ProfessorBirchHouse_Text_Torchic, MSGBOX_DEFAULT
	waitmoncry
	release
	end

LittlerootTown_ProfessorBirchHouse_EventScript_Mudkip::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_MUDKIP, 0
	msgbox ProfessorBirchHouse_Text_Mudkip, MSGBOX_DEFAULT
	waitmoncry
	release
	end

LittlerootTown_ProfessorBirchHouse_EventScript_ItemTM52::
	finditem ITEM_TM52_WORK_UP
	end
