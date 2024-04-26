SlateportCity_PokemonFanClub_EventScript_SwaggerTutor::
	lock
	faceplayer
	msgbox MoveTutor_Text_SwaggerTeach, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq MoveTutor_EventScript_SwaggerDeclined
	call MoveTutor_EventScript_CanOnlyBeLearnedOnce
	compare VAR_RESULT, NO
	goto_if_eq MoveTutor_EventScript_SwaggerDeclined
	msgbox MoveTutor_Text_SwaggerWhichMon, MSGBOX_DEFAULT
	setvar VAR_0x8005, TUTOR_MOVE_SWAGGER
	call MoveTutor_EventScript_OpenPartyMenu
	compare VAR_RESULT, 0
	goto_if_eq MoveTutor_EventScript_SwaggerDeclined
	goto MoveTutor_EventScript_SwaggerTaught
	end

MoveTutor_EventScript_SwaggerDeclined::
	msgbox MoveTutor_Text_SwaggerDeclined, MSGBOX_DEFAULT
	release
	end

MoveTutor_EventScript_SwaggerTaught::
	msgbox MoveTutor_Text_SwaggerTaught, MSGBOX_DEFAULT
	release
	end

MauvilleCity_EventScript_RolloutTutor::
	lock
	faceplayer
	msgbox MoveTutor_Text_RolloutTeach, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq MoveTutor_EventScript_RolloutDeclined
	call MoveTutor_EventScript_CanOnlyBeLearnedOnce
	compare VAR_RESULT, NO
	goto_if_eq MoveTutor_EventScript_RolloutDeclined
	msgbox MoveTutor_Text_RolloutWhichMon, MSGBOX_DEFAULT
	setvar VAR_0x8005, TUTOR_MOVE_ROLLOUT
	call MoveTutor_EventScript_OpenPartyMenu
	compare VAR_RESULT, 0
	goto_if_eq MoveTutor_EventScript_RolloutDeclined
	goto MoveTutor_EventScript_RolloutTaught
	end

MoveTutor_EventScript_RolloutDeclined::
	msgbox MoveTutor_Text_RolloutDeclined, MSGBOX_DEFAULT
	release
	end

MoveTutor_EventScript_RolloutTaught::
	msgbox MoveTutor_Text_RolloutTaught, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_PokemonCenter_1F_EventScript_FuryCutterTutor::
	lock
	faceplayer
	msgbox MoveTutor_Text_FuryCutterTeach, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq MoveTutor_EventScript_FuryCutterDeclined
	call MoveTutor_EventScript_CanOnlyBeLearnedOnce
	compare VAR_RESULT, NO
	goto_if_eq MoveTutor_EventScript_FuryCutterDeclined
	msgbox MoveTutor_Text_FuryCutterWhichMon, MSGBOX_DEFAULT
	setvar VAR_0x8005, TUTOR_MOVE_FURY_CUTTER
	call MoveTutor_EventScript_OpenPartyMenu
	compare VAR_RESULT, 0
	goto_if_eq MoveTutor_EventScript_FuryCutterDeclined
	goto MoveTutor_EventScript_FuryCutterTaught
	end

MoveTutor_EventScript_FuryCutterDeclined::
	msgbox MoveTutor_Text_FuryCutterDeclined, MSGBOX_DEFAULT
	release
	end

MoveTutor_EventScript_FuryCutterTaught::
	msgbox MoveTutor_Text_FuryCutterTaught, MSGBOX_DEFAULT
	release
	end

LavaridgeTown_House_EventScript_MimicTutor::
	lock
	faceplayer
	msgbox MoveTutor_MimicTeach, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq MoveTutor_EventScript_MimicDeclined
	call MoveTutor_EventScript_CanOnlyBeLearnedOnce
	compare VAR_RESULT, NO
	goto_if_eq MoveTutor_EventScript_MimicDeclined
	msgbox MoveTutor_Text_MimicWhichMon, MSGBOX_DEFAULT
	setvar VAR_0x8005, TUTOR_MOVE_MIMIC
	call MoveTutor_EventScript_OpenPartyMenu
	compare VAR_RESULT, 0
	goto_if_eq MoveTutor_EventScript_MimicDeclined
	goto MoveTutor_EventScript_MimicTaught
	end

MoveTutor_EventScript_MimicDeclined::
	msgbox MoveTutor_MimicDeclined, MSGBOX_DEFAULT
	release
	end

MoveTutor_EventScript_MimicTaught::
	msgbox MoveTutor_Text_MimicTaught, MSGBOX_DEFAULT
	release
	end

FallarborTown_Mart_EventScript_MetronomeTutor::
	lock
	faceplayer
	msgbox MoveTutor_Text_MetronomeTeach, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq MoveTutor_EventScript_MetronomeDeclined
	call MoveTutor_EventScript_CanOnlyBeLearnedOnce
	compare VAR_RESULT, NO
	goto_if_eq MoveTutor_EventScript_MetronomeDeclined
	msgbox MoveTutor_Text_MetronomeWhichMon, MSGBOX_DEFAULT
	setvar VAR_0x8005, TUTOR_MOVE_METRONOME
	call MoveTutor_EventScript_OpenPartyMenu
	compare VAR_RESULT, 0
	goto_if_eq MoveTutor_EventScript_MetronomeDeclined
	goto MoveTutor_EventScript_MetronomeTaught
	end

MoveTutor_EventScript_MetronomeDeclined::
	msgbox MoveTutor_Text_MetronomeDeclined, MSGBOX_DEFAULT
	release
	end

MoveTutor_EventScript_MetronomeTaught::
	msgbox MoveTutor_Text_MetronomeTaught, MSGBOX_DEFAULT
	release
	end

FortreeCity_House2_EventScript_SleepTalkTutor::
	lock
	faceplayer
	msgbox MoveTutor_Text_SleepTalkTeach, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq MoveTutor_EventScript_SleepTalkDeclined
	call MoveTutor_EventScript_CanOnlyBeLearnedOnce
	compare VAR_RESULT, NO
	goto_if_eq MoveTutor_EventScript_SleepTalkDeclined
	msgbox MoveTutor_Text_SleepTalkWhichMon, MSGBOX_DEFAULT
	setvar VAR_0x8005, TUTOR_MOVE_SLEEP_TALK
	call MoveTutor_EventScript_OpenPartyMenu
	compare VAR_RESULT, 0
	goto_if_eq MoveTutor_EventScript_SleepTalkDeclined
	goto MoveTutor_EventScript_SleepTalkTaught
	end

MoveTutor_EventScript_SleepTalkDeclined::
	msgbox MoveTutor_Text_SleepTalkDeclined, MSGBOX_DEFAULT
	release
	end

MoveTutor_EventScript_SleepTalkTaught::
	msgbox MoveTutor_Text_SleepTalkTaught, MSGBOX_DEFAULT
	release
	end

LilycoveCity_DepartmentStoreRooftop_EventScript_SubstituteTutor::
	lock
	faceplayer
	msgbox MoveTutor_Text_SubstituteTeach, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq MoveTutor_EventScript_SubstituteDeclined
	call MoveTutor_EventScript_CanOnlyBeLearnedOnce
	compare VAR_RESULT, NO
	goto_if_eq MoveTutor_EventScript_SubstituteDeclined
	msgbox MoveTutor_Text_SubstituteWhichMon, MSGBOX_DEFAULT
	setvar VAR_0x8005, TUTOR_MOVE_SUBSTITUTE
	call MoveTutor_EventScript_OpenPartyMenu
	compare VAR_RESULT, 0
	goto_if_eq MoveTutor_EventScript_SubstituteDeclined
	goto MoveTutor_EventScript_SubstituteTaught
	end

MoveTutor_EventScript_SubstituteDeclined::
	msgbox MoveTutor_Text_SubstituteDeclined, MSGBOX_DEFAULT
	release
	end

MoveTutor_EventScript_SubstituteTaught::
	msgbox MoveTutor_Text_SubstituteTaught, MSGBOX_DEFAULT
	release
	end

MossdeepCity_EventScript_DynamicPunchTutor::
	lock
	faceplayer
	msgbox MoveTutor_Text_DynamicPunchTeach, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq MoveTutor_EventScript_DynamicPunchDeclined
	call MoveTutor_EventScript_CanOnlyBeLearnedOnce
	compare VAR_RESULT, NO
	goto_if_eq MoveTutor_EventScript_DynamicPunchDeclined
	msgbox MoveTutor_Text_DynamicPunchWhichMon, MSGBOX_DEFAULT
	setvar VAR_0x8005, TUTOR_MOVE_DYNAMIC_PUNCH
	call MoveTutor_EventScript_OpenPartyMenu
	compare VAR_RESULT, 0
	goto_if_eq MoveTutor_EventScript_DynamicPunchDeclined
	goto MoveTutor_EventScript_DynamicPunchTaught
	end

MoveTutor_EventScript_DynamicPunchDeclined::
	msgbox MoveTutor_Text_DynamicPunchDeclined, MSGBOX_DEFAULT
	release
	end

MoveTutor_EventScript_DynamicPunchTaught::
	msgbox MoveTutor_Text_DynamicPunchTaught, MSGBOX_DEFAULT
	release
	end

SootopolisCity_PokemonCenter_1F_EventScript_DoubleEdgeTutor::
	lock
	faceplayer
	msgbox MoveTutor_Text_DoubleEdgeTeach, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq MoveTutor_EventScript_DoubleEdgeDeclined
	call MoveTutor_EventScript_CanOnlyBeLearnedOnce
	compare VAR_RESULT, NO
	goto_if_eq MoveTutor_EventScript_DoubleEdgeDeclined
	msgbox MoveTutor_Text_DoubleEdgeWhichMon, MSGBOX_DEFAULT
	setvar VAR_0x8005, TUTOR_MOVE_DOUBLE_EDGE
	call MoveTutor_EventScript_OpenPartyMenu
	compare VAR_RESULT, 0
	goto_if_eq MoveTutor_EventScript_DoubleEdgeDeclined
	goto MoveTutor_EventScript_DoubleEdgeTaught
	end

MoveTutor_EventScript_DoubleEdgeDeclined::
	msgbox MoveTutor_Text_DoubleEdgeDeclined, MSGBOX_DEFAULT
	release
	end

MoveTutor_EventScript_DoubleEdgeTaught::
	msgbox MoveTutor_Text_DoubleEdgeTaught, MSGBOX_DEFAULT
	release
	end

PacifidlogTown_PokemonCenter_1F_EventScript_ExplosionTutor::
	lock
	faceplayer
	msgbox MoveTutor_Text_ExplosionTeach, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq MoveTutor_EventScript_ExplosionDeclined
	call MoveTutor_EventScript_CanOnlyBeLearnedOnce
	compare VAR_RESULT, NO
	goto_if_eq MoveTutor_EventScript_ExplosionDeclined
	msgbox MoveTutor_Text_ExplosionWhichMon, MSGBOX_DEFAULT
	setvar VAR_0x8005, TUTOR_MOVE_EXPLOSION
	call MoveTutor_EventScript_OpenPartyMenu
	compare VAR_RESULT, 0
	goto_if_eq MoveTutor_EventScript_ExplosionDeclined
	goto MoveTutor_EventScript_ExplosionTaught
	end

MoveTutor_EventScript_ExplosionDeclined::
	msgbox MoveTutor_Text_ExplosionDeclined, MSGBOX_DEFAULT
	release
	end

MoveTutor_EventScript_ExplosionTaught::
	msgbox MoveTutor_Text_ExplosionTaught, MSGBOX_DEFAULT
	release
	end

MoveTutor_EventScript_OpenPartyMenu::
	special ChooseMonForMoveTutor
	waitstate
	lock
	faceplayer
	return

MoveTutor_EventScript_CanOnlyBeLearnedOnce::
	msgbox MoveTutor_Text_ThisMoveCanOnlyBeLearnedOnce, MSGBOX_YESNO
	return

@@ new code

RustoboroCity_House2_EventScript_AncientePowerTutor::
	lock
	faceplayer
	msgbox MoveTutor_Text_AncientePowerTeach, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq MoveTutor_EventScript_AncientePowerDeclined
	call MoveTutor_EventScript_CanOnlyBeLearnedOnce
	compare VAR_RESULT, NO
	goto_if_eq MoveTutor_EventScript_AncientePowerDeclined
	msgbox MoveTutor_Text_AncientePowerWhichMon, MSGBOX_DEFAULT
	setvar VAR_0x8005, TUTOR_MOVE_ANCIENT_POWER
	call MoveTutor_EventScript_OpenPartyMenu
	compare VAR_RESULT, 0
	goto_if_eq MoveTutor_EventScript_AncientePowerDeclined
	goto MoveTutor_EventScript_AncientePowerTaught
	end

MoveTutor_EventScript_AncientePowerDeclined::
	msgbox MoveTutor_Text_AncientePowerDeclined, MSGBOX_DEFAULT
	release
	end

MoveTutor_EventScript_AncientePowerTaught::
	msgbox MoveTutor_Text_AncientePowerTaught, MSGBOX_DEFAULT
	release
	end

RustboroCity_DevonCorp_2F_EventScript_SignalBeamTutor::
	lock
	faceplayer
	msgbox MoveTutor_Text_SignalBeamTeach, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq MoveTutor_EventScript_SignalBeamDeclined
	call MoveTutor_EventScript_CanOnlyBeLearnedOnce
	compare VAR_RESULT, NO
	goto_if_eq MoveTutor_EventScript_SignalBeamDeclined
	msgbox MoveTutor_Text_SignalBeamWhichMon, MSGBOX_DEFAULT
	setvar VAR_0x8005, TUTOR_MOVE_SIGNAL_BEAM
	call MoveTutor_EventScript_OpenPartyMenu
	compare VAR_RESULT, 0
	goto_if_eq MoveTutor_EventScript_SignalBeamDeclined
	goto MoveTutor_EventScript_SignalBeamTaught
	end

MoveTutor_EventScript_SignalBeamDeclined::
	msgbox MoveTutor_Text_SignalBeamDeclined, MSGBOX_DEFAULT
	release
	end

MoveTutor_EventScript_SignalBeamTaught::
	msgbox MoveTutor_Text_SignalBeamTaught, MSGBOX_DEFAULT
	release
	end

MtChimney_PokemonCenter_EventScript_BurnUpTutor::
	lock
	faceplayer
	msgbox MoveTutor_Text_BurnUpTeach, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq MoveTutor_EventScript_BurnUpDeclined
	call MoveTutor_EventScript_CanOnlyBeLearnedOnce
	compare VAR_RESULT, NO
	goto_if_eq MoveTutor_EventScript_BurnUpDeclined
	msgbox MoveTutor_Text_BurnUpWhichMon, MSGBOX_DEFAULT
	setvar VAR_0x8005, TUTOR_MOVE_BURN_UP
	call MoveTutor_EventScript_OpenPartyMenu
	compare VAR_RESULT, 0
	goto_if_eq MoveTutor_EventScript_BurnUpDeclined
	goto MoveTutor_EventScript_BurnUpTaught
	end

MoveTutor_EventScript_BurnUpDeclined::
	msgbox MoveTutor_Text_BurnUpDeclined, MSGBOX_DEFAULT
	release
	end

MoveTutor_EventScript_BurnUpTaught::
	msgbox MoveTutor_Text_BurnUpTaught, MSGBOX_DEFAULT
	release
	end

SootopolisCity_House2_EventScript_DracoMeteorTutor::
	lock
	faceplayer
	msgbox MoveTutor_Text_DracoMeteorTeach, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq MoveTutor_EventScript_DracoMeteorDeclined
	call MoveTutor_EventScript_CanOnlyBeLearnedOnce
	compare VAR_RESULT, NO
	goto_if_eq MoveTutor_EventScript_DracoMeteorDeclined
	msgbox MoveTutor_Text_DracoMeteorWhichMon, MSGBOX_DEFAULT
	setvar VAR_0x8005, TUTOR_MOVE_DRACO_METEOR
	call MoveTutor_EventScript_OpenPartyMenu
	compare VAR_RESULT, 0
	goto_if_eq MoveTutor_EventScript_DracoMeteorDeclined
	goto MoveTutor_EventScript_DracoMeteorTaught
	end

MoveTutor_EventScript_DracoMeteorDeclined::
	msgbox MoveTutor_Text_DracoMeteorDeclined, MSGBOX_DEFAULT
	release
	end

MoveTutor_EventScript_DracoMeteorTaught::
	msgbox MoveTutor_Text_DracoMeteorTaught, MSGBOX_DEFAULT
	release
	end

@
MoveTutor_EventScript_EventScript_BlazeKickTutor::
	lock
	faceplayer
	msgbox MoveTutor_Text_BlazeKickTeach, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq MoveTutor_EventScript_BlazeKickDeclined
	call MoveTutor_EventScript_CanOnlyBeLearnedOnce
	compare VAR_RESULT, NO
	goto_if_eq MoveTutor_EventScript_BlazeKickDeclined
	msgbox MoveTutor_Text_BlazeKickWhichMon, MSGBOX_DEFAULT
	setvar VAR_0x8005, TUTOR_MOVE_BLAZE_KICK
	call MoveTutor_EventScript_OpenPartyMenu
	compare VAR_RESULT, 0
	goto_if_eq MoveTutor_EventScript_BlazeKickDeclined
	goto MoveTutor_EventScript_BlazeKickTaught
	end

MoveTutor_EventScript_BlazeKickDeclined::
	msgbox MoveTutor_Text_BlazeKickDeclined, MSGBOX_DEFAULT
	release
	end

MoveTutor_EventScript_BlazeKickTaught::
	msgbox MoveTutor_Text_BlazeKickTaught, MSGBOX_DEFAULT
	release
	end

MoveTutor_Text_BlazeKickTeach:
	.string "I can't do this anymore!\p"
	.string "It's utterly hopeless!\p"
	.string "I'm a Fighting-type Trainer,\n"
	.string "so I can't win at the Mossdeep Gym\l"
	.string "no matter how hard I try!\p"
	.string "Argh! Kick! Kick! Kick!\n"
	.string "Kick! Kick! Kick!\p"
	.string "What, don't look at me that way!\n"
	.string "I'm only hitting the ground!\p"
	.string "Or do you want me to teach your\n"
	.string "Pokémon Blaze Kick?$"

MoveTutor_Text_BlazeKickDeclined:
	.string "Darn! You're even making fun of me?\n"
	.string "Kick! Kick! Kick!$"

MoveTutor_Text_BlazeKickWhichMon:
	.string "What? You do? You're a strong person!\n"
	.string "Which Pokémon should I teach?$"

MoveTutor_Text_BlazeKickTaught:
	.string "I want you to win at the Mossdeep Gym\n"
	.string "using that Blaze Kick!$"
@

MoveTutor_EventScript_EventScript_WaterBallTutor::
	lock
	faceplayer
	msgbox MoveTutor_Text_WaterBallTeach, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq MoveTutor_EventScript_WaterBallDeclined
	call MoveTutor_EventScript_CanOnlyBeLearnedOnce
	compare VAR_RESULT, NO
	goto_if_eq MoveTutor_EventScript_WaterBallDeclined
	msgbox MoveTutor_Text_WaterBallWhichMon, MSGBOX_DEFAULT
	setvar VAR_0x8005, TUTOR_MOVE_WATER_BALL
	call MoveTutor_EventScript_OpenPartyMenu
	compare VAR_RESULT, 0
	goto_if_eq MoveTutor_EventScript_WaterBallDeclined
	goto MoveTutor_EventScript_WaterBallTaught
	end

MoveTutor_EventScript_WaterBallDeclined::
	msgbox MoveTutor_Text_WaterBallDeclined, MSGBOX_DEFAULT
	release
	end

MoveTutor_EventScript_WaterBallTaught::
	msgbox MoveTutor_Text_WaterBallTaught, MSGBOX_DEFAULT
	release
	end

MoveTutor_Text_WaterBallTeach:
	.string "Just fill your hand with\n"
	.string "water and hit your friend!\p"
	.string "Do you want me to teach your\n"
	.string "Pokémon Water Ball?$"

MoveTutor_Text_WaterBallDeclined:
	.string "Too bad. There's always room for\n"
	.string "one more to play!$"

MoveTutor_Text_WaterBallWhichMon:
	.string "What? Seriouly?\n"
	.string "Which Pokémon should I teach?$"

MoveTutor_Text_WaterBallTaught:
	.string "Now play with your Pokémon!$"
@

MoveTutor_EventScript_EventScript_DoubleLariatTutor::
	lock
	faceplayer
	msgbox MoveTutor_Text_DoubleLariatTeach, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq MoveTutor_EventScript_DoubleLariatDeclined
	call MoveTutor_EventScript_CanOnlyBeLearnedOnce
	compare VAR_RESULT, NO
	goto_if_eq MoveTutor_EventScript_DoubleLariatDeclined
	msgbox MoveTutor_Text_DoubleLariatWhichMon, MSGBOX_DEFAULT
	setvar VAR_0x8005, TUTOR_MOVE_DOUBLE_LARIAT
	call MoveTutor_EventScript_OpenPartyMenu
	compare VAR_RESULT, 0
	goto_if_eq MoveTutor_EventScript_DoubleLariatDeclined
	goto MoveTutor_EventScript_DoubleLariatTaught
	end

MoveTutor_EventScript_DoubleLariatDeclined::
	msgbox MoveTutor_Text_DoubleLariatDeclined, MSGBOX_DEFAULT
	release
	end

MoveTutor_EventScript_DoubleLariatTaught::
	msgbox MoveTutor_Text_DoubleLariatTaught, MSGBOX_DEFAULT
	release
	end

MoveTutor_Text_DoubleLariatTeach:
	.string "It is a move to be executed\n"
	.string "with your partner.\p"
	.string "Do you want me to teach your\n"
	.string "Pokémon Double Lariat?$"

MoveTutor_Text_DoubleLariatDeclined:
	.string "That's not the spirit.$"

MoveTutor_Text_DoubleLariatWhichMon:
	.string "Let's do it!\n"
	.string "Which Pokémon should I teach?$"

MoveTutor_Text_DoubleLariatTaught:
	.string "Now choose a partner to\n"
	.string "teach Double Lariat!$"
@
