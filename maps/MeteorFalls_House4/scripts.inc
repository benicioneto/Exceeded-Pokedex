MeteorFalls_House4_MapScripts::
	.byte 0

MeteorFalls_DraconidHouse_EventScript_DraconidRelic::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_DRAGON_BREATH, MeteorFalls_DraconidHouse_EventScript_OurHero
	compare VAR_END_OF_THE_WORLD, 4
	goto_if_ge MeteorFalls_DraconidHouse_EventScript_GiveDragonBreath
	msgbox MeteorFalls_DraconidHouse_Text_Normal, MSGBOX_DEFAULT
	release
	end

MeteorFalls_DraconidHouse_EventScript_OurHero:
	msgbox MeteorFalls_DraconidHouse_Text_OurHero, MSGBOX_DEFAULT
	release
	end

MeteorFalls_DraconidHouse_EventScript_GiveDragonBreath:
	msgbox MeteorFalls_DraconidHouse_Text_GiveRelic, MSGBOX_DEFAULT
	removeobject 2
	giveitem ITEM_DRAGON_BREATH
	setflag FLAG_RECEIVED_DRAGON_BREATH
	release
	end

MeteorFalls_DraconidHouse_EventScript_Relic::
	msgbox MeteorFalls_DraconidHouse_Text_Relic, MSGBOX_DEFAULT
	release
	end

MeteorFalls_DraconidHouse_Text_Normal:
	.string "Once in the past, the hero\n"
	.string "challenged and subjugated\l"
	.string "Rayquaza, and used its power\l"
	.string "to save the world!$"

MeteorFalls_DraconidHouse_Text_Relic:
	.string "It seems to be a ancient relic.\n"
	.string "Better not touch it.$"

MeteorFalls_DraconidHouse_Text_GiveRelic:
	.string "Oh! You saved use from\n"
	.string "the meteor!\p"
	.string "You must worn it since this\n"
	.string "relic is from an ancient!\l"
	.string "hero of Draconids!$"

MeteorFalls_DraconidHouse_Text_OurHero:
	.string "Please, use as you wish!\n"
	.string "Hero.$"
