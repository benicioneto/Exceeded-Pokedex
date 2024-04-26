PetalburgCity_House2_MapScripts::
	.byte 0

@PetalburgCity_House2_EventScript_Woman::
@	msgbox PetalburgCity_House2_Text_NormanBecameGymLeader, MSGBOX_NPC
@	end

PetalburgCity_House2_EventScript_SchoolKid::
	msgbox PetalburgCity_House2_Text_BattledNormanOnce, MSGBOX_NPC
	end

@PetalburgCity_House2_Text_NormanBecameGymLeader:
@	.string "Norman became our town's new\n"
@	.string "Gym Leader.\p"
@	.string "I think he called his family over from\n"
@	.string "somewhere far away.$"

PetalburgCity_House2_Text_BattledNormanOnce:
	.string "I battled Norman once, but, whew,\n"
	.string "he was way too strong.\p"
	.string "How would I put it?\p"
	.string "I just got the feeling that he\n"
	.string "lives for Pokémon.$"

@@@@@@@@@@@@@@@@@@@
@		New Code
@@@@@@@@@@@@@@@@@@@

PetalburgCity_House2_EventScript_Woman::
    lock
    faceplayer
	goto_if_set FLAG_DAILY_PETALBURG_CITY_RECEIVED_MINT, Common_EventScript_ReceivedMint
    call Common_EventScript_GiveOneMint
	compare VAR_RESULT, FALSE
	goto_if_eq Common_EventScript_ShowBagIsFull
	setflag FLAG_DAILY_PETALBURG_CITY_RECEIVED_MINT
	release
	end