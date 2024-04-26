#include "constants/global.h"
#include "constants/battle.h"
#include "constants/pokemon.h"
#include "constants/battle_script_commands.h"
#include "constants/battle_anim.h"
#include "constants/battle_string_ids.h"
#include "constants/abilities.h"
#include "constants/hold_effects.h"
#include "constants/moves.h"
#include "constants/songs.h"
#include "constants/game_stat.h"
#include "constants/trainers.h"
#include "constants/battle_config.h"
#include "constants/species.h"
#include "constants/flags.h"
	.include "asm/macros.inc"
	.include "asm/macros/battle_script.inc"
	.include "constants/constants.inc"

	.section script_data, "aw", %progbits
	
.align 2
gBattleScriptsForMoveEffects::
	.4byte BattleScript_EffectHit                     @ EFFECT_HIT
	.4byte BattleScript_EffectSleep                   @ EFFECT_TARGET_SLEEP
	.4byte BattleScript_EffectPoisonHit               @ EFFECT_TARGET_POISON_ON_HIT
	.4byte BattleScript_EffectAbsorb                  @ EFFECT_USER_DRAIN_100_ON_HIT
	.4byte BattleScript_EffectBurnHit                 @ EFFECT_TARGET_BURN_ON_HIT
	.4byte BattleScript_EffectFreezeHit               @ EFFECT_TARGET_FREEZE_ON_HIT
	.4byte BattleScript_EffectParalyzeHit             @ EFFECT_TARGET_PARALYZE_ON_HIT
	.4byte BattleScript_EffectExplosion               @ EFFECT_USER_FAINT
	.4byte BattleScript_EffectDreamEater              @ EFFECT_DREAM_EATER
	.4byte BattleScript_EffectMirrorMove              @ EFFECT_USER_REPEAT_LAST_MOVE
	.4byte BattleScript_EffectAttackUp                @ EFFECT_USER_ATTACK_UP_1
	.4byte BattleScript_EffectDefenseUp               @ EFFECT_USER_DEFENSE_UP_1
	.4byte BattleScript_EffectSpeedUp                 @ EFFECT_USER_SPEED_UP_1
	.4byte BattleScript_EffectSpecialAttackUp         @ EFFECT_USER_SPECIAL_ATTACK_UP_1
	.4byte BattleScript_EffectSpecialDefenseUp        @ EFFECT_USER_SPECIAL_DEFENSE_UP_1
	.4byte BattleScript_EffectAccuracyUp              @ EFFECT_USER_ACCURACY_UP_1
	.4byte BattleScript_EffectEvasionUp               @ EFFECT_USER_EVASION_UP_1
	.4byte BattleScript_EffectSpecialAttackUp3        @ EFFECT_USER_SPECIAL_ATTACK_UP_3
	.4byte BattleScript_EffectAttackDown              @ EFFECT_TARGET_ATTACK_DOWN_1
	.4byte BattleScript_EffectDefenseDown             @ EFFECT_TARGET_DEFENSE_DOWN_1
	.4byte BattleScript_EffectSpeedDown               @ EFFECT_TARGET_SPEED_DOWN_1
	.4byte BattleScript_EffectSpecialAttackDown       @ EFFECT_TARGET_SPECIAL_ATTACK_DOWN_1
	.4byte BattleScript_EffectSpecialDefenseDown      @ EFFECT_TARGET_SPECIAL_DEFENSE_DOWN_1
	.4byte BattleScript_EffectAccuracyDown            @ EFFECT_TARGET_ACCURACY_DOWN_1
	.4byte BattleScript_EffectEvasionDown             @ EFFECT_TARGET_EVASION_DOWN_1
	.4byte BattleScript_EffectHaze                    @ EFFECT_ALL_RESET_STAT_STAGES
	.4byte BattleScript_EffectBide                    @ EFFECT_USER_REFLECT_DAMAGE_2_TURNS
	.4byte BattleScript_EffectRampage                 @ EFFECT_USER_RAMPAGE
	.4byte BattleScript_EffectRoar                    @ EFFECT_TARGET_FORCED_SWITCH_OUT
	.4byte BattleScript_EffectMultiHit                @ EFFECT_TARGET_MULTI_HIT
	.4byte BattleScript_EffectConversion              @ EFFECT_USER_CHANGE_TYPE_TO_FIRST_MOVE
	.4byte BattleScript_EffectFlinchHit               @ EFFECT_TARGET_FLINCH_ON_HIT
	.4byte BattleScript_EffectRestoreHp               @ EFFECT_USER_RESTORE_50_HP
	.4byte BattleScript_EffectToxic                   @ EFFECT_TARGET_BADLY_POISON
	.4byte BattleScript_EffectPayDay                  @ EFFECT_USER_RECEIVE_MONEY
	.4byte BattleScript_EffectLightScreen             @ EFFECT_USER_SIDE_SPECIAL_DAMAGE_WALL
	.4byte BattleScript_EffectTriAttack               @ EFFECT_TARGET_FIRE_ELECTRIC_ICE_HIT
	.4byte BattleScript_EffectRest                    @ EFFECT_USER_RESTORE_FULL_HP_AND_SLEEP
	.4byte BattleScript_EffectLegendPower             @ EFFECT_LEGEND_POWER
	.4byte BattleScript_EffectHit                     @ EFFECT_TARGET_FUSION_COMBO
	.4byte BattleScript_EffectSuperFang               @ EFFECT_TARGET_REDUCE_50_HP
	.4byte BattleScript_EffectDragonRage              @ EFFECT_TARGET_DAMAGE_SCALE_WITH_BASE_ATK_SPATK
	.4byte BattleScript_EffectTrap                    @ EFFECT_TARGET_PREVENT_ESCAPE_AND_HURT_EACH_TURN
	.4byte BattleScript_EffectHealBlock               @ EFFECT_TARGET_HEAL_BLOCK
	.4byte BattleScript_EffectDoubleHit               @ EFFECT_TARGET_DOUBLE_HIT
	.4byte BattleScript_EffectRecoilIfMiss            @ EFFECT_USER_REDUCE_50_HP_IF_MISS
	.4byte BattleScript_EffectMist                    @ EFFECT_MIST
	.4byte BattleScript_EffectFocusEnergy             @ EFFECT_USER_CRITICAL_HIT_STAGE_2
	.4byte BattleScript_EffectRecoil25                @ EFFECT_USER_RECOIL_25
	.4byte BattleScript_EffectConfuse                 @ EFFECT_TARGET_CONFUSE
	.4byte BattleScript_EffectAttackUp2               @ EFFECT_USER_ATTACK_UP_2
	.4byte BattleScript_EffectDefenseUp2              @ EFFECT_USER_DEFENSE_UP_2
	.4byte BattleScript_EffectSpeedUp2                @ EFFECT_USER_SPEED_UP_2
	.4byte BattleScript_EffectSpecialAttackUp2        @ EFFECT_USER_SPECIAL_ATTACK_UP_2
	.4byte BattleScript_EffectSpecialDefenseUp2       @ EFFECT_USER_SPECIAL_DEFENSE_UP_2
	.4byte BattleScript_EffectAccuracyUp2             @ EFFECT_USER_ACCURACY_UP_2
	.4byte BattleScript_EffectEvasionUp2              @ EFFECT_USER_EVASION_UP_2
	.4byte BattleScript_EffectTransform               @ EFFECT_USER_TRANSFORM
	.4byte BattleScript_EffectAttackDown2             @ EFFECT_TARGET_ATTACK_DOWN_2
	.4byte BattleScript_EffectDefenseDown2            @ EFFECT_TARGET_DEFENSE_DOWN_2
	.4byte BattleScript_EffectSpeedDown2              @ EFFECT_TARGET_SPEED_DOWN_2
	.4byte BattleScript_EffectSpecialAttackDown2      @ EFFECT_TARGET_SPECIAL_ATTACK_DOWN_2
	.4byte BattleScript_EffectSpecialDefenseDown2     @ EFFECT_TARGET_SPECIAL_DEFENSE_DOWN_2
	.4byte BattleScript_EffectAccuracyDown2           @ EFFECT_TARGET_ACCURACY_DOWN_2
	.4byte BattleScript_EffectEvasionDown2            @ EFFECT_TARGET_EVASION_DOWN_2
	.4byte BattleScript_EffectReflect                 @ EFFECT_USER_SIDE_PHYSICAL_DAMAGE_WALL
	.4byte BattleScript_EffectPoison                  @ EFFECT_TARGET_POISON
	.4byte BattleScript_EffectParalyze                @ EFFECT_TARGET_PARALYZE
	.4byte BattleScript_EffectAttackDownHit           @ EFFECT_TARGET_ATTACK_DOWN_1_ON_HIT
	.4byte BattleScript_EffectDefenseDownHit          @ EFFECT_TARGET_DEFENSE_DOWN_1_ON_HIT
	.4byte BattleScript_EffectSpeedDownHit            @ EFFECT_TARGET_SPEED_DOWN_1_ON_HIT
	.4byte BattleScript_EffectSpecialAttackDownHit    @ EFFECT_TARGET_SPECIAL_ATTACK_DOWN_1_ON_HIT
	.4byte BattleScript_EffectSpecialDefenseDownHit   @ EFFECT_TARGET_SPECIAL_DEFENSE_DOWN_1_ON_HIT
	.4byte BattleScript_EffectAccuracyDownHit         @ EFFECT_TARGET_ACCURACY_DOWN_1_ON_HIT
	.4byte BattleScript_EffectHit                     @ EFFECT_TARGET_EVASION_DOWN_1_ON_HIT
	.4byte BattleScript_EffectTwoTurnsAttack          @ EFFECT_USER_FIRST_TURN_PREPARE_SECOND_TURN_ATTACK
	.4byte BattleScript_EffectConfuseHit              @ EFFECT_TARGET_CONFUSE_ON_HIT
	.4byte BattleScript_EffectTwineedle               @ EFFECT_TARGET_DOUBLE_HIT_AND_POISON_ON_HIT
	.4byte BattleScript_EffectHit                     @ EFFECT_VITAL_THROW
	.4byte BattleScript_EffectSubstitute              @ EFFECT_USER_REDUCE_25_HP_AND_SUBSTITUTE
	.4byte BattleScript_EffectRecharge                @ EFFECT_USER_RECHARGE
	.4byte BattleScript_EffectRage                    @ EFFECT_USER_ATTACK_UP_1_ON_BEING_HIT
	.4byte BattleScript_EffectMimic                   @ EFFECT_USER_COPY_LAST_MOVE
	.4byte BattleScript_EffectMetronome               @ EFFECT_USER_CALL_RANDOM_MOVE
	.4byte BattleScript_EffectLeechSeed               @ EFFECT_TARGET_DRAIN_HP_EACH_TURN
	.4byte BattleScript_EffectDoNothing               @ EFFECT_USER_DO_NOTHING
	.4byte BattleScript_EffectDisable                 @ EFFECT_TARGET_DISABLE_LAST_MOVE
	.4byte BattleScript_EffectLevelDamage             @ EFFECT_TARGET_DAMAGE_SCALE_WITH_BASE_ATK
	.4byte BattleScript_EffectPsywave                 @ EFFECT_TARGET_DAMAGE_SCALE_WITH_BASE_SPATK
	.4byte BattleScript_EffectCounter                 @ EFFECT_USER_REFLECT_PHYSICAL_DAMAGE
	.4byte BattleScript_EffectEncore                  @ EFFECT_TARGET_FORCED_REPEAT_LAST_MOVE
	.4byte BattleScript_EffectPainSplit               @ EFFECT_USER_TARGET_EQUALLY_SHARE_HP
	.4byte BattleScript_EffectSnore                   @ EFFECT_CAN_BE_USED_ASLEEP_AND_TARGET_FLINCH_ON_HIT
	.4byte BattleScript_EffectConversion2             @ EFFECT_USER_CHANGE_TYPE_TO_RESIST_LAST_MOVE
	.4byte BattleScript_EffectLockOn                  @ EFFECT_USER_BOOST_NEXT_MOVE_ON_TARGET
	.4byte BattleScript_EffectSketch                  @ EFFECT_USER_PERMANENTLY_COPY_LAST_MOVE
	.4byte BattleScript_EffectHammerArm               @ EFFECT_USER_SPEED_DOWN_1_ON_HIT
	.4byte BattleScript_EffectSleepTalk               @ EFFECT_USER_RANDOMLY_MOVE_ASLEEP
	.4byte BattleScript_EffectDestinyBond             @ EFFECT_TARGET_FAINT_IF_USER_FAINT
	.4byte BattleScript_EffectHit                     @ EFFECT_USER_LESS_HP_MORE_DAMAGE
	.4byte BattleScript_EffectSpite                   @ EFFECT_TARGET_LAST_MOVE_MINUS_4_PP
	.4byte BattleScript_EffectHit                     @ EFFECT_TARGET_SURVIVE_1_HP_ON_HIT
	.4byte BattleScript_EffectHealBell                @ EFFECT_USER_HEAL_PARTY_STATUS_CONDITION
	.4byte BattleScript_EffectHit                     @ EFFECT_USER_ALWAYS_CRITICAL_ON_HIT
	.4byte BattleScript_EffectTripleKick              @ EFFECT_TARGET_TRIPLE_HIT_MORE_DAMAGE_EACH_HIT
	.4byte BattleScript_EffectThief                   @ EFFECT_USER_STEAL_TARGET_ITEM_ON_HIT
	.4byte BattleScript_EffectMeanLook                @ EFFECT_TARGET_PREVENT_ESCAPE
	.4byte BattleScript_EffectNightmare               @ EFFECT_TARGET_REDUCE_25_HP_EACH_TURN_ASLEEP
	.4byte BattleScript_EffectMinimize                @ EFFECT_USER_EVASION_UP_2_AND_REDUCE_SIZE
	.4byte BattleScript_EffectCurse                   @ EFFECT_TARGET_CURSE_OR_USER_ATTACK_DEFENSE_UP_1_SPEED_DOWN_1
	.4byte BattleScript_EffectHealingWish             @ EFFECT_USER_FAINT_NEXT_MON_RESTORE_FULL_HP
	.4byte BattleScript_EffectProtect                 @ EFFECT_USER_PREVENT_MOVE
	.4byte BattleScript_EffectSpikes                  @ EFFECT_TARGET_SIDE_SPIKES
	.4byte BattleScript_EffectForesight               @ EFFECT_USER_BYPASS_EVASION_AND_GHOST_TYPE
	.4byte BattleScript_EffectPerishSong              @ EFFECT_ALL_FAINT_THREE_TURNS
	.4byte BattleScript_EffectSandstorm               @ EFFECT_SANDSTORM
	.4byte BattleScript_EffectEndure                  @ EFFECT_USER_SURVIVE_1_HP
	.4byte BattleScript_EffectRollout                 @ EFFECT_USER_FIVE_TURNS_DOUBLE_DAMAGE_EACH_TURN_ON_HIT
	.4byte BattleScript_EffectSwagger                 @ EFFECT_TARGET_CONFUSE_AND_ATTACK_UP_2
	.4byte BattleScript_EffectFuryCutter              @ EFFECT_USER_DOUBLE_DAMAGE_EACH_TURN_ON_HIT
	.4byte BattleScript_EffectAttract                 @ EFFECT_TARGET_ATTRACT
	.4byte BattleScript_EffectHit                     @ EFFECT_USER_MORE_HAPINESS_MORE_DAMAGE
	.4byte BattleScript_EffectPresent                 @ EFFECT_PRESENT
	.4byte BattleScript_EffectHit                     @ EFFECT_USER_LESS_HAPINESS_MORE_DAMAGE
	.4byte BattleScript_EffectSafeguard               @ EFFECT_USER_SIDE_STATUS_CONDITION_WALL
	.4byte BattleScript_EffectHit                     @ EFFECT_UNUSED_125
	.4byte BattleScript_EffectMagnitude               @ EFFECT_MAGNITUDE
	.4byte BattleScript_EffectBatonPass               @ EFFECT_BATON_PASS
	.4byte BattleScript_EffectHit                     @ EFFECT_HIT_BEFORE_SWITCH_OUT
	.4byte BattleScript_EffectRapidSpin               @ EFFECT_SPEED_UP_1_AND_CLEAR_USER
	.4byte BattleScript_EffectSonicboom               @ EFFECT_SCALE_WITH_BASE_SPEED
	.4byte BattleScript_EffectCaptivate               @ EFFECT_OPPOSITE_GENDER_SPECIAL_ATTACK_DOWN_2
	.4byte BattleScript_EffectMorningSun              @ EFFECT_MORNING_SUN
	.4byte BattleScript_EffectSynthesis               @ EFFECT_SYNTHESIS
	.4byte BattleScript_EffectMoonlight               @ EFFECT_MOONLIGHT
	.4byte BattleScript_EffectHit                     @ EFFECT_TYPE_DEPENDS_ON_IV
	.4byte BattleScript_EffectRainDance               @ EFFECT_RAIN_DANCE
	.4byte BattleScript_EffectSunnyDay                @ EFFECT_SUNNY_DAY
	.4byte BattleScript_EffectDefenseUpHit            @ EFFECT_DEFENSE_UP_1_ON_HIT
	.4byte BattleScript_EffectAttackUpHit             @ EFFECT_ATTACK_UP_1_ON_HIT
	.4byte BattleScript_EffectAllStatsUpHit           @ EFFECT_ALL_STATS_UP_1_ON_HIT
	.4byte BattleScript_EffectHit                     @ EFFECT_ATTACK_UP_3_WHEN_FAINTING
	.4byte BattleScript_EffectBellyDrum               @ EFFECT_MAXIMIZE_ATTACK_HALF_HP_COST
	.4byte BattleScript_EffectPsychUp                 @ EFFECT_COPY_STATS_STAGES
	.4byte BattleScript_EffectMirrorCoat              @ EFFECT_REFLECT_SPECIAL_DAMAGE
	.4byte BattleScript_EffectGatlingGulpMissile   	  @ EFFECT_GATLING_GULP_MISSILE
	.4byte BattleScript_EffectTwister                 @ EFFECT_TWISTER
	.4byte BattleScript_EffectEarthquake              @ EFFECT_EARTHQUAKE
	.4byte BattleScript_EffectFutureSight             @ EFFECT_FUTURE_SIGHT
	.4byte BattleScript_EffectGust                    @ EFFECT_GUST
	.4byte BattleScript_EffectStomp                   @ EFFECT_FLINCH_MINIMIZE_HIT
	.4byte BattleScript_EffectHit                     @ EFFECT_SOLAR_BEAM
	.4byte BattleScript_EffectThunder                 @ EFFECT_THUNDER
	.4byte BattleScript_EffectTeleport                @ EFFECT_TELEPORT
	.4byte BattleScript_EffectBeatUp                  @ EFFECT_BEAT_UP
	.4byte BattleScript_EffectSemiInvulnerable        @ EFFECT_SEMI_INVULNERABLE
	.4byte BattleScript_EffectDefenseCurl             @ EFFECT_DEFENSE_CURL
	.4byte BattleScript_EffectSoftboiled              @ EFFECT_SOFTBOILED
	.4byte BattleScript_EffectFakeOut                 @ EFFECT_FAKE_OUT
	.4byte BattleScript_EffectUproar                  @ EFFECT_UPROAR
	.4byte BattleScript_EffectStockpile               @ EFFECT_STOCKPILE
	.4byte BattleScript_EffectSpitUp                  @ EFFECT_SPIT_UP
	.4byte BattleScript_EffectSwallow                 @ EFFECT_SWALLOW
	.4byte BattleScript_EffectWorrySeed               @ EFFECT_WORRY_SEED
	.4byte BattleScript_EffectHail                    @ EFFECT_HAIL
	.4byte BattleScript_EffectTorment                 @ EFFECT_TORMENT
	.4byte BattleScript_EffectFlatter                 @ EFFECT_FLATTER
	.4byte BattleScript_EffectWillOWisp               @ EFFECT_WILL_O_WISP
	.4byte BattleScript_EffectMemento                 @ EFFECT_MEMENTO
	.4byte BattleScript_EffectHit                     @ EFFECT_FACADE
	.4byte BattleScript_EffectFocusPunch              @ EFFECT_FOCUS_PUNCH
	.4byte BattleScript_EffectSmellingsalt            @ EFFECT_SMELLINGSALT
	.4byte BattleScript_EffectFollowMe                @ EFFECT_FOLLOW_ME
	.4byte BattleScript_EffectNaturePower             @ EFFECT_NATURE_POWER
	.4byte BattleScript_EffectCharge                  @ EFFECT_CHARGE
	.4byte BattleScript_EffectTaunt                   @ EFFECT_TAUNT
	.4byte BattleScript_EffectHelpingHand             @ EFFECT_HELPING_HAND
	.4byte BattleScript_EffectTrick                   @ EFFECT_TRICK
	.4byte BattleScript_EffectRolePlay                @ EFFECT_ROLE_PLAY
	.4byte BattleScript_EffectWish                    @ EFFECT_WISH
	.4byte BattleScript_EffectAssist                  @ EFFECT_ASSIST
	.4byte BattleScript_EffectIngrain                 @ EFFECT_INGRAIN
	.4byte BattleScript_EffectSuperpower              @ EFFECT_SUPERPOWER
	.4byte BattleScript_EffectMagicCoat               @ EFFECT_MAGIC_COAT
	.4byte BattleScript_EffectRecycle                 @ EFFECT_RECYCLE
	.4byte BattleScript_EffectHit                     @ EFFECT_REVENGE
	.4byte BattleScript_EffectBrickBreak              @ EFFECT_BRICK_BREAK
	.4byte BattleScript_EffectYawn                    @ EFFECT_YAWN
	.4byte BattleScript_EffectKnockOff                @ EFFECT_KNOCK_OFF
	.4byte BattleScript_EffectEndeavor                @ EFFECT_ENDEAVOR
	.4byte BattleScript_EffectHit                     @ EFFECT_ERUPTION
	.4byte BattleScript_EffectSkillSwap               @ EFFECT_SKILL_SWAP
	.4byte BattleScript_EffectImprison                @ EFFECT_IMPRISON
	.4byte BattleScript_EffectRefresh                 @ EFFECT_REFRESH
	.4byte BattleScript_EffectGrudge                  @ EFFECT_GRUDGE
	.4byte BattleScript_EffectSnatch                  @ EFFECT_SNATCH
	.4byte BattleScript_EffectHit                     @ EFFECT_LOW_KICK
	.4byte BattleScript_EffectSecretPower             @ EFFECT_SECRET_POWER
	.4byte BattleScript_EffectRecoil33                @ EFFECT_USER_RECOIL_33
	.4byte BattleScript_EffectTeeterDance             @ EFFECT_TEETER_DANCE
	.4byte BattleScript_EffectHitEscape               @ EFFECT_USER_FORCED_SWITCH_OUT_ON_HIT
	.4byte BattleScript_EffectMudSport                @ EFFECT_MUD_SPORT
	.4byte BattleScript_EffectPoisonFang              @ EFFECT_TARGET_BADLY_POISON_ON_HIT
	.4byte BattleScript_EffectHit                     @ EFFECT_WEATHER_BALL
	.4byte BattleScript_EffectOverheat                @ EFFECT_OVERHEAT
	.4byte BattleScript_EffectTickle                  @ EFFECT_TICKLE
	.4byte BattleScript_EffectCosmicPower             @ EFFECT_COSMIC_POWER
	.4byte BattleScript_EffectSkyUppercut             @ EFFECT_SKY_UPPERCUT
	.4byte BattleScript_EffectBulkUp                  @ EFFECT_USER_ATTACK_DEFENSE_UP_1
	.4byte BattleScript_EffectPlaceholder             @ EFFECT_PLACEHOLDER
	.4byte BattleScript_EffectWaterSport              @ EFFECT_WATER_SPORT
	.4byte BattleScript_EffectCalmMind                @ EFFECT_USER_SPECIAL_ATTACK_SPECIAL_DEFENSE_UP_1
	.4byte BattleScript_EffectDragonDance             @ EFFECT_DRAGON_DANCE
	.4byte BattleScript_EffectCamouflage              @ EFFECT_CAMOUFLAGE
	.4byte BattleScript_EffectPledge                  @ EFFECT_PLEDGE
	.4byte BattleScript_EffectFling                   @ EFFECT_FLING
	.4byte BattleScript_EffectNaturalGift             @ EFFECT_NATURAL_GIFT
	.4byte BattleScript_EffectWakeUpSlap              @ EFFECT_WAKE_UP_SLAP
	.4byte BattleScript_EffectHit                     @ EFFECT_WRING_OUT
	.4byte BattleScript_EffectHit                     @ EFFECT_HEX
	.4byte BattleScript_EffectHit                     @ EFFECT_ASSURANCE
	.4byte BattleScript_EffectHit                     @ EFFECT_TRUMP_CARD
	.4byte BattleScript_EffectHit                     @ EFFECT_ACROBATICS
	.4byte BattleScript_EffectHit                     @ EFFECT_HEAT_CRASH
	.4byte BattleScript_EffectHit                     @ EFFECT_PUNISHMENT
	.4byte BattleScript_EffectHit                     @ EFFECT_STORED_POWER
	.4byte BattleScript_EffectHit                     @ EFFECT_ELECTRO_BALL
	.4byte BattleScript_EffectHit                     @ EFFECT_GYRO_BALL
	.4byte BattleScript_EffectHit                     @ EFFECT_ECHOED_VOICE
	.4byte BattleScript_EffectHit                     @ EFFECT_PAYBACK
	.4byte BattleScript_EffectRound                   @ EFFECT_ROUND
	.4byte BattleScript_EffectHit                     @ EFFECT_BRINE
	.4byte BattleScript_EffectHit                     @ EFFECT_VENOSHOCK
	.4byte BattleScript_EffectHit                     @ EFFECT_RETALIATE
	.4byte BattleScript_EffectBulldoze                @ EFFECT_BULLDOZE
	.4byte BattleScript_EffectHit                     @ EFFECT_FOUL_PLAY
	.4byte BattleScript_EffectHit                     @ EFFECT_PSYSHOCK
	.4byte BattleScript_EffectRoost                   @ EFFECT_ROOST
	.4byte BattleScript_EffectGravity                 @ EFFECT_GRAVITY
	.4byte BattleScript_EffectMircleEye               @ EFFECT_MIRACLE_EYE
	.4byte BattleScript_EffectTailwind                @ EFFECT_TAILWIND
	.4byte BattleScript_EffectEmbargo                 @ EFFECT_EMBARGO
	.4byte BattleScript_EffectAquaRing                @ EFFECT_AQUA_RING
	.4byte BattleScript_EffectTrickRoom               @ EFFECT_TRICK_ROOM
	.4byte BattleScript_EffectWonderRoom              @ EFFECT_WONDER_ROOM
	.4byte BattleScript_EffectMagicRoom               @ EFFECT_MAGIC_ROOM
	.4byte BattleScript_EffectMagnetRise              @ EFFECT_MAGNET_RISE
	.4byte BattleScript_EffectToxicSpikes             @ EFFECT_TOXIC_SPIKES
	.4byte BattleScript_EffectGastroAcid              @ EFFECT_GASTRO_ACID
	.4byte BattleScript_EffectStealthRock             @ EFFECT_STEALTH_ROCK
	.4byte BattleScript_EffectTelekinesis             @ EFFECT_TELEKINESIS
	.4byte BattleScript_EffectPowerSwap               @ EFFECT_POWER_SWAP
	.4byte BattleScript_EffectGuardSwap               @ EFFECT_GUARD_SWAP
	.4byte BattleScript_EffectHeartSwap               @ EFFECT_HEART_SWAP
	.4byte BattleScript_EffectPowerSplit              @ EFFECT_POWER_SPLIT
	.4byte BattleScript_EffectGuardSplit              @ EFFECT_GUARD_SPLIT
	.4byte BattleScript_EffectStickyWeb               @ EFFECT_STICKY_WEB
	.4byte BattleScript_EffectMetalBurst              @ EFFECT_METAL_BURST
	.4byte BattleScript_EffectLuckyChant              @ EFFECT_LUCKY_CHANT
	.4byte BattleScript_EffectSuckerPunch             @ EFFECT_SUCKER_PUNCH
	.4byte BattleScript_EffectSpecialDefenseDownHit2  @ EFFECT_TARGET_SPECIAL_DEFENSE_DOWN_2_ON_HIT
	.4byte BattleScript_EffectSimpleBeam              @ EFFECT_SIMPLE_BEAM
	.4byte BattleScript_EffectEntrainment             @ EFFECT_ENTRAINMENT
	.4byte BattleScript_EffectHealPulse               @ EFFECT_HEAL_PULSE
	.4byte BattleScript_EffectQuash                   @ EFFECT_QUASH
	.4byte BattleScript_EffectIonDeluge               @ EFFECT_ION_DELUGE
	.4byte BattleScript_EffectFreezeHit               @ EFFECT_FREEZE_DRY
	.4byte BattleScript_EffectTopsyTurvy              @ EFFECT_TOPSY_TURVY
	.4byte BattleScript_EffectMistyTerrain            @ EFFECT_MISTY_TERRAIN
	.4byte BattleScript_EffectGrassyTerrain           @ EFFECT_GRASSY_TERRAIN
	.4byte BattleScript_EffectElectricTerrain         @ EFFECT_ELECTRIC_TERRAIN
	.4byte BattleScript_EffectPsychicTerrain          @ EFFECT_PSYCHIC_TERRAIN
	.4byte BattleScript_EffectAttackAccUp             @ EFFECT_USER_ATTACK_ACCURACY_UP_1
	.4byte BattleScript_EffectAttackSpAttackUp        @ EFFECT_USER_ATTACK_SPECIAL_ATTACK_UP_1
	.4byte BattleScript_EffectHurricane               @ EFFECT_HURRICANE
	.4byte BattleScript_EffectHit                     @ EFFECT_TWO_TYPED_MOVE
	.4byte BattleScript_EffectMeFirst                 @ EFFECT_ME_FIRST
	.4byte BattleScript_EffectSpeedUpHit              @ EFFECT_USER_SPEED_UP_1_ON_HIT
	.4byte BattleScript_EffectQuiverDance             @ EFFECT_USER_SPECIAL_ATTACK_SPECIAL_DEFENSE_SPEED_UP_1
	.4byte BattleScript_EffectCoil                    @ EFFECT_COIL
	.4byte BattleScript_EffectElectrify               @ EFFECT_ELECTRIFY
	.4byte BattleScript_EffectBurnHit                 @ EFFECT_SCALD
	.4byte BattleScript_EffectReflectType             @ EFFECT_REFLECT_TYPE
	.4byte BattleScript_EffectSoak                    @ EFFECT_SET_TYPE
	.4byte BattleScript_EffectGrowth                  @ EFFECT_GROWTH
	.4byte BattleScript_EffectCloseCombat             @ EFFECT_CLOSE_COMBAT
	.4byte BattleScript_EffectLastResort              @ EFFECT_LAST_RESORT
	.4byte BattleScript_EffectRecoil33WithStatus      @ EFFECT_USER_RECOIL_33_STATUS
	.4byte BattleScript_EffectFlinchWithStatus        @ EFFECT_FLINCH_STATUS
	.4byte BattleScript_EffectRecoil50                @ EFFECT_USER_RECOIL_50
	.4byte BattleScript_EffectShellSmash              @ EFFECT_SHELL_SMASH
	.4byte BattleScript_EffectShiftGear               @ EFFECT_SHIFT_GEAR
	.4byte BattleScript_EffectDefenseUp3              @ EFFECT_USER_DEFENSE_UP_3
	.4byte BattleScript_EffectNobleRoar               @ EFFECT_NOBLE_ROAR
	.4byte BattleScript_EffectVenomDrench             @ EFFECT_VENOM_DRENCH
	.4byte BattleScript_EffectToxicThread             @ EFFECT_TOXIC_THREAD
	.4byte BattleScript_EffectClearSmog               @ EFFECT_CLEAR_SMOG
	.4byte BattleScript_EffectHitSwitchTarget         @ EFFECT_TARGET_FORCED_SWITCH_OUT_ON_HIT
	.4byte BattleScript_EffectFinalGambit             @ EFFECT_FINAL_GAMBIT
	.4byte BattleScript_EffectHit                     @ EFFECT_CHANGE_TYPE_ON_ITEM
	.4byte BattleScript_EffectAutotomize              @ EFFECT_AUTOTOMIZE
	.4byte BattleScript_EffectCopycat                 @ EFFECT_COPYCAT
	.4byte BattleScript_EffectDefog                   @ EFFECT_DEFOG
	.4byte BattleScript_EffectHitEnemyHealAlly        @ EFFECT_DAMAGE_ENEMY_OR_HEAL_ALLY
	.4byte BattleScript_EffectSmackDown               @ EFFECT_KNOCK_FLYING_TARGET_DOWN
	.4byte BattleScript_EffectHit            		  @ EFFECT_SYNCHRONOISE
	.4byte BattleScript_EffectPsychoShift             @ EFFECT_PSYCHO_SHIFT
	.4byte BattleScript_EffectPowerTrick              @ EFFECT_POWER_TRICK
	.4byte BattleScript_EffectFlameBurst              @ EFFECT_FLAME_BURST
	.4byte BattleScript_EffectAfterYou                @ EFFECT_AFTER_YOU
	.4byte BattleScript_EffectBestow                  @ EFFECT_BESTOW
	.4byte BattleScript_EffectRototiller              @ EFFECT_ROTOTILLER
	.4byte BattleScript_EffectFlowerShield            @ EFFECT_FLOWER_SHIELD
	.4byte BattleScript_EffectHitPreventEscape        @ EFFECT_TARGET_PREVENT_ESCAPE_ON_HIT
	.4byte BattleScript_EffectSpeedSwap               @ EFFECT_SPEED_SWAP
	.4byte BattleScript_EffectDefenseUp2Hit           @ EFFECT_USER_DEFENSE_UP_2_ON_HIT
	.4byte BattleScript_EffectHit                     @ EFFECT_MATCH_USER_FIRST_TYPE
	.4byte BattleScript_EffectAuroraVeil              @ EFFECT_USER_SIDE_BOTH_PHYSICAL_SPECIAL_WALL
	.4byte BattleScript_EffectThirdType               @ EFFECT_ADD_TYPE
	.4byte BattleScript_EffectFeint                   @ EFFECT_TARGET_REMOVE_PROTECTION_ON_HIT
	.4byte BattleScript_EffectSparklingAria           @ EFFECT_TARGET_CURE_SPECIFIC_STATUS
	.4byte BattleScript_EffectAcupressure             @ EFFECT_ACUPRESSURE
	.4byte BattleScript_EffectAromaticMist            @ EFFECT_AROMATIC_MIST
	.4byte BattleScript_EffectPowder                  @ EFFECT_POWDER
	.4byte BattleScript_EffectSpAtkUpHit              @ EFFECT_USER_SPECIAL_ATTACK_UP_1_ON_HIT
	.4byte BattleScript_EffectHit                     @ EFFECT_BELCH
	.4byte BattleScript_EffectPartingShot             @ EFFECT_PARTING_SHOT
	.4byte BattleScript_EffectSpectralThief           @ EFFECT_SPECTRAL_THIEF
	.4byte BattleScript_EffectVCreate                 @ EFFECT_V_CREATE
	.4byte BattleScript_EffectMatBlock                @ EFFECT_MAT_BLOCK
	.4byte BattleScript_EffectHit                     @ EFFECT_STOMPING_TANTRUM
	.4byte BattleScript_EffectCoreEnforcer            @ EFFECT_CORE_ENFORCER
	.4byte BattleScript_EffectInstruct                @ EFFECT_INSTRUCT
	.4byte BattleScript_EffectThroatChop              @ EFFECT_THROAT_CHOP
	.4byte BattleScript_EffectLaserFocus              @ EFFECT_LASER_FOCUS
	.4byte BattleScript_EffectMagneticFlux            @ EFFECT_MAGNETIC_FLUX
	.4byte BattleScript_EffectGearUp                  @ EFFECT_GEAR_UP
	.4byte BattleScript_EffectIncinerate              @ EFFECT_INCINERATE
	.4byte BattleScript_EffectBugBite                 @ EFFECT_BUG_BITE
	.4byte BattleScript_EffectStrengthSap             @ EFFECT_STRENGTH_SAP
	.4byte BattleScript_EffectMindBlown               @ EFFECT_MIND_BLOWN
	.4byte BattleScript_EffectPurify                  @ EFFECT_PURIFY
	.4byte BattleScript_EffectBurnUp                  @ EFFECT_BURN_UP
	.4byte BattleScript_EffectShoreUp                 @ EFFECT_SHORE_UP
	.4byte BattleScript_EffectGeomancy                @ EFFECT_GEOMANCY
	.4byte BattleScript_EffectFairyLock               @ EFFECT_FAIRY_LOCK
	.4byte BattleScript_EffectAllySwitch              @ EFFECT_ALLY_SWITCH
	.4byte BattleScript_EffectSleepHit                @ EFFECT_TARGET_SLEEP_ON_HIT
	.4byte BattleScript_EffectAttackerDefenseDownHit  @ EFFECT_ATTACKER_DEFENSE_DOWN_HIT
	.4byte BattleScript_EffectHit                     @ EFFECT_BODY_PRESS
	.4byte BattleScript_EffectEerieSpell              @ EFFECT_EERIE_SPELL
	.4byte BattleScript_EffectJungleHealing           @ EFFECT_JUNGLE_HEALING
	.4byte BattleScript_EffectCoaching                @ EFFECT_COACHING
	.4byte BattleScript_EffectHit                     @ EFFECT_LASH_OUT
	.4byte BattleScript_EffectHit             		  @ EFFECT_GRASSY_GLIDE
	.4byte BattleScript_EffectRemoveTerrain           @ EFFECT_REMOVE_TERRAIN
	.4byte BattleScript_EffectHit                     @ EFFECT_DYNAMAX_DOUBLE_DMG
	.4byte BattleScript_EffectDecorate                @ EFFECT_DECORATE
	.4byte BattleScript_EffectHit                     @ EFFECT_SNIPE_SHOT
	.4byte BattleScript_EffectTripleHit               @ EFFECT_TRIPLE_HIT
	.4byte BattleScript_EffectRecoilHP25              @ EFFECT_USER_RECOIL_25_HP
	.4byte BattleScript_EffectStuffCheeks             @ EFFECT_STUFF_CHEEKS
	.4byte BattleScript_EffectDefenseDownHit          @ EFFECT_GRAV_APPLE
	.4byte BattleScript_EffectEvasionUpHit            @ EFFECT_USER_EVASION_UP_1_ON_HIT
	.4byte BattleScript_EffectDoubleIronBash          @ EFFECT_DOUBLE_IRON_BASH
	.4byte BattleScript_EffectGlitzyGlow              @ EFFECT_GLITZY_GLOW
	.4byte BattleScript_EffectBaddyBad                @ EFFECT_BADDY_BAD
	.4byte BattleScript_EffectSappySeed               @ EFFECT_SAPPY_SEED
	.4byte BattleScript_EffectFreezyFrost             @ EFFECT_FREEZY_FROST
	.4byte BattleScript_EffectSparklySwirl            @ EFFECT_SPARKLY_SWIRL
	.4byte BattleScript_EffectPlasmaFists             @ EFFECT_PLASMA_FISTS
	.4byte BattleScript_EffectHyperspaceFury          @ EFFECT_HYPERSPACE_FURY
	.4byte BattleScript_EffectExtrasensory            @ EFFECT_EXTRASENSORY
	.4byte BattleScript_EffectAxeKick                 @ EFFECT_AXE_KICK
	.4byte BattleScript_EffectMeditate                @ EFFECT_MEDITATE
	.4byte BattleScript_EffectKinesis                 @ EFFECT_KINESIS
	.4byte BattleScript_EffectSweetkiss               @ EFFECT_SWEET_KISS
	.4byte BattleScript_EffectFeatherdance            @ EFFECT_FEATHER_DANCE
	.4byte BattleScript_EffectAuraWheel               @ EFFECT_AURA_WHEEL
	.4byte BattleScript_EffectPhotonGeyser            @ EFFECT_PHOTON_GEYSER
	.4byte BattleScript_EffectShellSideArm            @ EFFECT_SHELL_SIDE_ARM
	.4byte BattleScript_EffectHit                     @ EFFECT_TERRAIN_PULSE
	.4byte BattleScript_EffectJawLock                 @ EFFECT_JAW_LOCK
	.4byte BattleScript_EffectNoRetreat               @ EFFECT_NO_RETREAT
	.4byte BattleScript_EffectTarShot                 @ EFFECT_TAR_SHOT
	.4byte BattleScript_EffectPoltergeist             @ EFFECT_POLTERGEIST
	.4byte BattleScript_EffectOctolock                @ EFFECT_OCTOLOCK
	.4byte BattleScript_EffectClangorousSoul          @ EFFECT_CLANGOROUS_SOUL
	.4byte BattleScript_EffectHit                     @ EFFECT_BOLT_BEAK
	.4byte BattleScript_EffectSkyDrop                 @ EFFECT_SKY_DROP
	.4byte BattleScript_EffectHit              		  @ EFFECT_METEOR_BEAM
	.4byte BattleScript_EffectScaleShot               @ EFFECT_SCALE_SHOT
	.4byte BattleScript_EffectHit                     @ EFFECT_EXPANDING_FORCE
	.4byte BattleScript_EffectShellTrap               @ EFFECT_SHELL_TRAP
	.4byte BattleScript_EffectCourtChange             @ EFFECT_COURT_CHANGE
	.4byte BattleScript_EffectHit                     @ EFFECT_RISING_VOLTAGE
	.4byte BattleScript_EffectCorrosiveGas			  @ EFFECT_CORROSIVE_GAS
	.4byte BattleScript_EffectHit                     @ EFFECT_BEAK_BLAST
	.4byte BattleScript_EffectSteelBeam               @ EFFECT_STEEL_BEAM
	.4byte BattleScript_EffectMortalSpin              @ EFFECT_MORTAL_SPIN
	.4byte BattleScript_EffectSaltCure                @ EFFECT_SALT_CURE
	.4byte BattleScript_EffectMatchaGotcha            @ EFFECT_MATCHA_GOTCHA
	.4byte BattleScript_EffectSyrupBomb               @ EFFECT_SYRUP_BOMB
	.4byte BattleScript_EffectHit                     @ EFFECT_IVY_CUDGEL
	.4byte BattleScript_EffectMaxMove                 @ EFFECT_MAX_MOVE
	.4byte BattleScript_EffectMakeItRain              @ EFFECT_MAKE_IT_RAIN
	.4byte BattleScript_EffectHit                     @ EFFECT_PSYBLADE
	.4byte BattleScript_EffectHit                     @ EFFECT_HYDRO_STEAM
	.4byte BattleScript_EffectSpinOut                 @ EFFECT_SPIN_OUT
	.4byte BattleScript_EffectHit            	      @ EFFECT_LAST_RESPECTS
	.4byte BattleScript_EffectSpicyExtract            @ EFFECT_SPICY_EXTRACT
	.4byte BattleScript_EffectGlaiveRush              @ EFFECT_GLAIVE_RUSH
	.4byte BattleScript_EffectDoodle                  @ EFFECT_DOODLE
	.4byte BattleScript_EffectChillyReception         @ EFFECT_CHILLY_RECEPTION
	.4byte BattleScript_EffectTidyUp                  @ EFFECT_TIDY_UP
	.4byte BattleScript_EffectAttackUpUserAlly        @ EFFECT_ATTACK_UP_USER_ALLY
	.4byte BattleScript_EffectOrderUp                 @ EFFECT_ORDER_UP
	@@@@@ Custom Moves @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
	.4byte BattleScript_EffectFrozenTerrain								@ EFFECT_FROZEN_TERRAIN
	.4byte BattleScript_EffectCursedTerrain								@ EFFECT_CURSED_TERRAIN
	.4byte BattleScript_EffectRavineTerrain								@ EFFECT_RAVINE_TERRAIN
	.4byte BattleScript_EffectBurningTerrain							@ EFFECT_BURNING_TERRAIN
	.4byte BattleScript_EffectSandyTerrain								@ EFFECT_SANDY_TERRAIN
	.4byte BattleScript_EffectSwampTerrain								@ EFFECT_SWAMP_TERRAIN
	.4byte BattleScript_EffectVenomousTerrain							@ EFFECT_VENOMOUS_TERRAIN
	.4byte BattleScript_EffectHit										@ EFFECT_DRACO_IMPACT
	.4byte BattleScript_EffectWarmUp									@ EFFECT_WARM_UP
	.4byte BattleScript_EffectRoseWhip									@ EFFECT_ROSE_WHIP
	.4byte BattleScript_EffectChristmasSpirit							@ EFFECT_CHRISTMAS_GIFT
	.4byte BattleScript_EffectHit										@ EFFECT_ARTIC_GLIDE
	.4byte BattleScript_EffectCoinShower								@ EFFECT_COIN_SHOWER
	.4byte BattleScript_EffectBerryBellyFlop							@ EFFECT_BERRY_BELLY_FLOP
	.4byte BattleScript_EffectRingsUnbound								@ EFFECT_RINGS_UNBOUND
	.4byte BattleScript_EffectBlissAssistance							@ EFFECT_BLISS_ASSISTANCE
	.4byte BattleScript_EffectRecoil33SpeedUpWithStatus					@ EFFECT_USER_RECOIL_33_SPEED_UP_WITH_STATUS
	.4byte BattleScript_EffectPopulationBomb							@ EFFECT_POPULATION_BOMB
	.4byte BattleScript_EffectBarrageBlow								@ EFFECT_BARRAGE_BLOW
	.4byte BattleScript_EffectFrostbiteHit								@ EFFECT_TARGET_FROSTBITE_ON_HIT
	.4byte BattleScript_EffectWithdraw									@ EFFECT_WITHDRAW
	.4byte BattleScript_EffectInkJet									@ EFFECT_INK_JET
	.4byte BattleScript_EffectHit										@ EFFECT_VACUUM_WAVE
	.4byte BattleScript_EffectConfusion									@ EFFECT_CONFUSION
	.4byte BattleScript_EffectRelicSong									@ EFFECT_RELIC_SONG
	.4byte BattleScript_EffectSacredFire								@ EFFECT_SACRED_FIRE
	.4byte BattleScript_EffectHit										@ EFFECT_AQUA_TORNADO more damage if super effective
	.4byte BattleScript_EffectTyrannicalRampage							@ EFFECT_TYRANNICAL_RAMPAGE
	.4byte BattleScript_EffectThunderstorm								@ EFFECT_THUNDERSTORM
	.4byte BattleScript_EffectPhantomForest								@ EFFECT_PHANTOM_FOREST
	.4byte BattleScript_EffectRevolvingRuin								@ EFFECT_REVOLVING_RUIN
	.4byte BattleScript_EffectRubbleRouser								@ EFFECT_RUBBLE_ROUSER
	.4byte BattleScript_EffectSnowGlobe									@ EFFECT_SNOW_GLOBE
	.4byte BattleScript_EffectDamageMissingHP							@ EFFECT_DAMAGE_MISSING_HP
	.4byte BattleScript_EffectFancifulFireworks							@ EFFECT_FANCIFUL_FIREWORKS
	.4byte BattleScript_EffectRockPolish								@ EFFECT_ROCK_POLISH
	.4byte BattleScript_EffectDarkBargain								@ EFFECT_DARK_BARGAIN
	.4byte BattleScript_EffectBloodPact									@ EFFECT_BLOOD_PACT
	.4byte BattleScript_EffectClangingScales							@ EFFECT_CLANGING_SCALES
	.4byte BattleScript_EffectSpicyBreath								@ EFFECT_SPICY_BREATH
	.4byte BattleScript_EffectExtremeEvoboost							@ EFFECT_EXTREME_EVOBOOST
	.4byte BattleScript_EffectTerrainHit								@ EFFECT_HIT_SET_REMOVE_TERRAIN
	.4byte BattleScript_EffectDarkVoid									@ EFFECT_DARK_VOID
	.4byte BattleScript_EffectDireClaw									@ EFFECT_DIRE_CLAW
	.4byte BattleScript_EffectRecoil33SpeedUp							@ EFFECT_USER_RECOIL_33_SPEED_UP
	.4byte BattleScript_EffectStoneAxe									@ EFFECT_EFFECT_STONE_AXE
	.4byte BattleScript_EffectPoisonHit									@ EFFECT_BARB_BARRAGE
	.4byte BattleScript_EffectTripleArrows								@ EFFECT_TRIPLE_ARROWS
	.4byte BattleScript_EffectBurnHit									@ EFFECT_INFERNAL_PARADE
	.4byte BattleScript_EffectCeaselessEdge								@ EFFECT_CEASELESS_EDGE
	.4byte BattleScript_EffectTeatime									@ EFFECT_TEATIME
	.4byte BattleScript_EffectFog										@ EFFECT_FOG
	.4byte BattleScript_EffectHit										@ EFFECT_RAZOR_WIND
	.4byte BattleScript_EffectNeurotoxin								@ EFFECT_NEUROTOXIN
	.4byte BattleScript_EffectToughItOut								@ EFFECT_TOUGH_IT_OUT
	.4byte BattleScript_EffectRecklessSwing								@ EFFECT_RECKLESS_SWING
	.4byte BattleScript_EffectUndertow									@ EFFECT_UNDERTOW
	.4byte BattleScript_EffectRevive									@ EFFECT_REVIVE
	.4byte BattleScript_EffectDoubleShock								@ EFFECT_DOUBLE_SHOCK
	.4byte BattleScript_EffectHit										@ EFFECT_RAGE_FIST
	.4byte BattleScript_EffectBrickBreak								@ EFFECT_RAGING_BULL
	.4byte BattleScript_EffectShedTail									@ EFFECT_SHED_TAIL
	.4byte BattleScript_EffectJudgment									@ EFFECT_JUDGMENT
	.4byte BattleScript_EffectHit										@ EFFECT_FOREST_FURY
	.4byte BattleScript_EffectCraftyClothes								@ EFFECT_CRAFTY_CLOTHES
	.4byte BattleScript_EffectSpellFistAffected							@ EFFECT_SPELL_FIST_USER_ATTACK_UP_1_ON_HIT
	.4byte BattleScript_EffectHit										@ EFFECT_KI_EXPLOSION
	.4byte BattleScript_EffectDragonCombo								@ EFFECT_DRAGON_COMBO
	.4byte BattleScript_EffectHellGate									@ EFFECT_HELL_GATE
	.4byte BattleScript_EffectCordyceps									@ EFFECT_CORDYCEPS
	.4byte BattleScript_EffectBloomsday									@ EFFECT_BLOOMSDAY
	.4byte BattleScript_EffectHellblaze									@ EFFECT_HELLBLAZE
	.4byte BattleScript_EffectFallingStars								@ EFFECT_FALLING_STARS
	.4byte BattleScript_EffectMoonfall									@ EFFECT_MOONFALL
	.4byte BattleScript_EffectTrash										@ EFFECT_TRASH
	.4byte BattleScript_EffectHeatSiphon								@ EFFECT_HEAT_SIPHON
	.4byte BattleScript_EffectMockingShout								@ EFFECT_MOCKING_SHOUT
	.4byte BattleScript_EffectAuroraDance								@ EFFECT_AURORA_DANCE
	.4byte BattleScript_EffectAbsoluteZero								@ EFFECT_ABSOLUTE_ZERO
	.4byte BattleScript_EffectForceHealing								@ EFFECT_FORCE_HEALING
	.4byte BattleScript_EffectSupersonic								@ EFFECT_SUPERSONIC
	.4byte BattleScript_EffectHit										@ EFFECT_BLACK_MAGIC
	.4byte BattleScript_EffectConvergence								@ EFFECT_CONVERGENCE
	.4byte BattleScript_EffectTwinBite									@ EFFECT_TWIN_BITE
	.4byte BattleScript_EffectRecoilIfMiss								@ EFFECT_PUNISHING_KICK
	.4byte BattleScript_EffectHit										@ EFFECT_STAR_ICON
	.4byte BattleScript_EffectAbsorb50									@ EFFECT_USER_DRAIN_50_ON_HIT
	.4byte BattleScript_EffectAbsorb75									@ EFFECT_USER_DRAIN_75_ON_HIT
	.4byte BattleScript_EffectEerieTune									@ EFFECT_EERIE_TUNE
	.4byte BattleScript_EffectHalloween									@ EFFECT_HALLOWEEN
	.4byte BattleScript_EffectBackStab									@ EFFECT_BACK_STAB
	.4byte BattleScript_EffectThornTrap									@ EFFECT_THORN_TRAP
	.4byte BattleScript_EffectZantetsuken								@ EFFECT_ZANTETSUKEN
	.4byte BattleScript_EffectDropWeights								@ EFFECT_DROP_WEIGHTS
	.4byte BattleScript_EffectComputeAndCrash							@ EFFECT_COMPUTE_AND_CRUSH
	.4byte BattleScript_EffectChaosGlower								@ EFFECT_CHAOS_GLOWER
	.4byte BattleScript_EffectMoonlightPrance							@ EFFECT_MOONLIGHT_PRANCE
	.4byte BattleScript_EffectDreepAndDestroy							@ EFFECT_DREEP_AND_DESTROY
	.4byte BattleScript_EffectInfinitePsyburn							@ EFFECT_INFINITE_PSYBURN
	.4byte BattleScript_EffectAzureSpyVision							@ EFFECT_AZURE_SPY_VISION
	.4byte BattleScript_EffectMysticalMirage							@ EFFECT_MYSTICAL_MIRAGE
	.4byte BattleScript_EffectSlowbeam									@ EFFECT_SLOWBEAM
	.4byte BattleScript_EffectHit										@ EFFECT_NIGHTFALL_DAZE
	.4byte BattleScript_EffectNight										@ EFFECT_NIGHT
	.4byte BattleScript_EffectSpinningFlameKick							@ EFFECT_ATTACK_UP_1_AND_CLEAR_USER
	.4byte BattleScript_EffectGlacialStage								@ EFFECT_GLACIAL_STAGE
	.4byte BattleScript_EffectLaprasExpress								@ EFFECT_LAPRAS_EXPRESS
	.4byte BattleScript_EffectGrassyTerrain								@ EFFECT_FLOWERY_FIELDS_FOREVER
	.4byte BattleScript_EffectIllusionDive								@ EFFECT_ILLUSION_DIVE
	.4byte BattleScript_EffectEbonFirst									@ EFFECT_EBON_FIST
	.4byte BattleScript_EffectFlowingFists								@ EFFECT_FLOWING_FISTS
	.4byte BattleScript_EffectShowtime									@ EFFECT_SHOWTIME
	.4byte BattleScript_EffectPsyshield									@ EFFECT_PSYSHIELD
	.4byte BattleScript_EffectHit										@ EFFECT_POWER_GEM

BattleScript_EffectPsyshield:
	attackcanceler
	ppreduce
	attackstring
	waitstate
	jumpifstatus2 BS_ATTACKER, STATUS2_SUBSTITUTE, BattleScript_AlreadyHasSubstitute
	jumpifstatus2 BS_ATTACKER, STATUS2_PSYSHIELD, BattleScript_AlreadyHasPsyshield
	setpsyshield BS_ATTACKER
	attackanimation
	waitanimation
	printfromtable gSubstituteUsedStringIds
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd
BattleScript_AlreadyHasPsyshield::
	setalreadystatusedmoveattempt BS_ATTACKER
	pause B_WAIT_TIME_SHORT
	printstring STRINGID_PKMNHASPSYSHIELD
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_EffectSpinningFlameKick:
	attackcanceler
	accuracycheck BattleScript_PrintMoveMissed, ACC_CURR_MOVE
	attackstring
	ppreduce
	call BattleScript_EffectDamage_Ret
	jumpifhalfword CMP_COMMON_BITS, gMoveResultFlags, MOVE_RESULT_DOESNT_AFFECT_FOE, BattleScript_MoveEnd
	setmoveeffect MOVE_EFFECT_RAPIDSPIN | MOVE_EFFECT_AFFECTS_ATTACKER | MOVE_EFFECT_CERTAIN
	seteffectwithchance
	setstatchanger STAT_ATK, 1, FALSE
	goto BattleScript_RapidSpinSecondaryEffect

BattleScript_EffectChaosGlower:
	attackcanceler
	jumpifnotfirstturn BattleScript_ChaosGlowerSpeedDown
	setmoveeffect MOVE_EFFECT_FLINCH
	goto BattleScript_HitFromAccCheck
BattleScript_ChaosGlowerSpeedDown:
	setmoveeffect MOVE_EFFECT_SPD_MINUS_1
	goto BattleScript_HitFromAccCheck

BattleScript_EffectShowtime:
	attackcanceler
	attackstring
	ppreduce
	setbyte gBattlerTarget, 0
BattleScript_ShowtimeLoop::
	movevaluescleanup
	setmoveeffect MOVE_EFFECT_FLINCH
	jumpifbyteequal gBattlerAttacker, gBattlerTarget, BattleScript_ShowtimeLoopIncrement
	jumpifabilityorinnate BS_TARGET, ABILITY_INNER_FOCUS, BattleScript_ShowtimeLoopIncrement
	jumpifsubstituteblocks BattleScript_ShowtimeLoopIncrement
	jumpifhasnohp BS_TARGET, BattleScript_ShowtimeLoopIncrement
	accuracycheck BattleScript_ShowtimeMissed, ACC_CURR_MOVE
	attackanimation
	waitanimation
	seteffectprimary
	resultmessage
	waitmessage B_WAIT_TIME_LONG
BattleScript_ShowtimeDoMoveEndIncrement::
	moveendto MOVEEND_NEXT_TARGET
BattleScript_ShowtimeLoopIncrement::
	addbyte gBattlerTarget, 1
	jumpifbytenotequal gBattlerTarget, gBattlersCount, BattleScript_ShowtimeLoop
	end

BattleScript_ShowtimeMissed::
	resultmessage
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_TeeterDanceDoMoveEndIncrement

BattleScript_EffectPsychicSolaire:
	attackcanceler
	accuracycheck BattleScript_PrintMoveMissed, NO_ACC_CALC_CHECK_LOCK_ON
	attackstring
	ppreduce
	settelekinesis BattleScript_ButItFailed
	attackanimation
	waitanimation
	printstring STRINGID_HURLEDINTOTHEAIR
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_EffectFlowingFists:
	attackcanceler
	attackstring
	ppreduce
	jumpiffollowup BS_ATTACKER, BattleScript_ButItFailed
	accuracycheck BattleScript_MoveMissedPause, ACC_CURR_MOVE
	setmultihitcounter 5
	initmultihitstring
	sethword sMULTIHIT_EFFECT, MOVE_EFFECT_FLINCH
	goto BattleScript_MultiHitLoop

BattleScript_EffectEbonFirst:
	attackcanceler
	attackstring
	ppreduce
	jumpiffollowup BS_ATTACKER, BattleScript_ButItFailed
	accuracycheck BattleScript_MoveMissedPause, ACC_CURR_MOVE
	setmoveeffect MOVE_EFFECT_FLINCH
	goto BattleScript_HitFromCritCalc

BattleScript_EffectIllusionDive:
	jumpifwrongcolor BS_ATTACKER, BattleScript_EffectHit
	setmoveeffect MOVE_EFFECT_EVS_PLUS_1 | MOVE_EFFECT_AFFECTS_ATTACKER
	goto BattleScript_EffectHit

BattleScript_EffectLaprasExpress:
	setmoveeffect MOVE_EFFECT_LAPRAS_EXPRESS
	goto BattleScript_EffectHit

BattleScript_EffectGlacialStage:
	attackcanceler
	attackstring
	ppreduce
	setterrain BattleScript_ButItFailed
	attackanimation
	waitanimation
	printfromtable gTerrainStringIds
	waitmessage B_WAIT_TIME_LONG
	playanimation BS_ATTACKER, B_ANIM_RESTORE_BG, NULL
	call BattleScript_TerrainFormChanges
	call BattleScript_TerrainSeedLoop
	goto BattleScript_TryToEscape

BattleScript_EffectNight:
	attackcanceler
	attackstring
	ppreduce
	jumpifhalfword CMP_COMMON_BITS, gBattleWeather, WEATHER_SUN_PRIMAL, BattleScript_ExtremelyHarshSunlightWasNotLessened
	jumpifhalfword CMP_COMMON_BITS, gBattleWeather, WEATHER_RAIN_PRIMAL, BattleScript_NoReliefFromHeavyRain
	jumpifhalfword CMP_COMMON_BITS, gBattleWeather, WEATHER_STRONG_WINDS, BattleScript_MysteriousAirCurrentBlowsOn
	setnight TRUE, BattleScript_MoveWeatherChange
	goto BattleScript_MoveWeatherChange

BattleScript_EffectSlowbeam:
	setmoveeffect MOVE_EFFECT_SLOWBEAM | MOVE_EFFECT_CERTAIN
	goto BattleScript_EffectHit

BattleScript_EffectMysticalMirage:
	attackcanceler
	attackstring
	ppreduce
	attackanimation
	waitanimation
	printstring STRINGID_ABILITYVANISH
	waitmessage B_WAIT_TIME_LONG
	setsemiinvulnerablebit
	setsemiinvulnerablehelper BS_ATTACKER, 2
	jumpifbattletype BATTLE_TYPE_DOUBLE, BattleScript_MysticalMiragePartner
	goto BattleScript_MoveEnd
BattleScript_MysticalMiragePartner:
	saveattacker
	setbattlerto BS_ATTACKER, BS_ATTACKER_PARTNER
	attackanimation
	waitanimation
	printstring STRINGID_ABILITYVANISH
	waitmessage B_WAIT_TIME_LONG
	setsemiinvulnerablebit
	setsemiinvulnerablehelper BS_ATTACKER, 1
	restoreattacker
	goto BattleScript_MoveEnd

BattleScript_EffectAzureSpyVision:
	attackcanceler
	attackstring
	ppreduce
	jumpifabilityorinnate BS_ATTACKER, ABILITY_SLOTTED_SHELL, BattleScript_AzureSpyVisionLoadSpecialBullet
	goto BattleScript_ButItFailed
BattleScript_AzureSpyVisionLoadSpecialBullet:
	setspecialbullet
	attackanimation
	waitanimation
	printstring STRINGID_LOADEDSPECIALBULLET
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_EffectInfinitePsyburn:
	setmoveeffect MOVE_EFFECT_INFINITE_PSYBURN | MOVE_EFFECT_CERTAIN
	goto BattleScript_EffectHit

BattleScript_EffectDreepAndDestroy::
	attackcanceler
	accuracycheck BattleScript_PrintMoveMissed, ACC_CURR_MOVE
	attackstring
	ppreduce
	setmultihitcounter 2
	initmultihitstring
	sethword sMULTIHIT_EFFECT, MOVE_EFFECT_DAMAGE_MISSING_HP | MOVE_EFFECT_CERTAIN
	goto BattleScript_MultiHitLoop

BattleScript_EffectMoonlightPrance::
	attackcanceler
	accuracycheck BattleScript_PrintMoveMissed, ACC_CURR_MOVE
	attackstring
	ppreduce
	trystealpositiveeffects
	goto BattleScript_HitFromCritCalc

BattleScript_EffectComputeAndCrash::
	attackcanceler
	attackstring
	ppreduce
	jumpifstat BS_ATTACKER, CMP_LESS_THAN, STAT_ATK, MAX_STAT_STAGE, BattleScript_ComputeAndCrashDoMoveAnim
	jumpifstat BS_ATTACKER, CMP_LESS_THAN, STAT_SPEED, MAX_STAT_STAGE, BattleScript_CantRaiseMultipleStats
	jumpifstat BS_ATTACKER, CMP_EQUAL, STAT_ACC, MAX_STAT_STAGE, BattleScript_CantRaiseMultipleStats
BattleScript_ComputeAndCrashDoMoveAnim::
	attackanimation
	waitanimation
	setbyte sSTAT_ANIM_PLAYED, FALSE
	playstatchangeanimation BS_ATTACKER, BIT_ATK | BIT_SPEED | BIT_ACC, 0
	setstatchanger STAT_ATK, 1, FALSE
	statbuffchange MOVE_EFFECT_AFFECTS_ATTACKER | STAT_CHANGE_ALLOW_PTR, BattleScript_ComputeAndCrashTrySpeed
	jumpifbyte CMP_EQUAL, cMULTISTRING_CHOOSER, B_MSG_STAT_WONT_INCREASE, BattleScript_ComputeAndCrashTrySpeed
	printfromtable gStatUpStringIds
	waitmessage B_WAIT_TIME_LONG
BattleScript_ComputeAndCrashTrySpeed::
	setstatchanger STAT_SPEED, 1, FALSE
	statbuffchange MOVE_EFFECT_AFFECTS_ATTACKER | STAT_CHANGE_ALLOW_PTR, BattleScript_ComputeAndCrashTryAcc
	jumpifbyte CMP_EQUAL, cMULTISTRING_CHOOSER, B_MSG_STAT_WONT_INCREASE, BattleScript_ComputeAndCrashTryAcc
	printfromtable gStatUpStringIds
	waitmessage B_WAIT_TIME_LONG
BattleScript_ComputeAndCrashTryAcc::
	setstatchanger STAT_ACC, 1, FALSE
	statbuffchange MOVE_EFFECT_AFFECTS_ATTACKER | STAT_CHANGE_ALLOW_PTR, BattleScript_ComputeAndCrashEnd
	jumpifbyte CMP_EQUAL, cMULTISTRING_CHOOSER, B_MSG_STAT_WONT_INCREASE, BattleScript_ComputeAndCrashEnd
	printfromtable gStatUpStringIds
	waitmessage B_WAIT_TIME_LONG
BattleScript_ComputeAndCrashEnd::
	goto BattleScript_MoveEnd

BattleScript_EffectDropWeights::
	attackcanceler
	attackstring
	ppreduce
	jumpifcannotloseanyitem BS_TARGET, BattleScript_ButItFailed
	attackanimation
	waitanimation
	dropitem BS_TARGET, 0
	dropitem BS_TARGET, 1
	dropitem BS_TARGET, 2
	jumpifbyteequal sSAVED_STAT_CHANGER, sZero, BattleScript_DropWeightsEnd
	copybyte sSTATCHANGER, sSAVED_STAT_CHANGER
	statbuffchange MOVE_EFFECT_CERTAIN | STAT_BUFF_NOT_PROTECT_AFFECTED, BattleScript_DropWeightsEnd
	jumpifbyte CMP_EQUAL, cMULTISTRING_CHOOSER, B_MSG_STAT_WONT_INCREASE, BattleScript_DropWeightsEnd
	setgraphicalstatchangevalues
	playanimation BS_TARGET, B_ANIM_STATS_CHANGE, sB_ANIM_ARG1
	printfromtable gStatUpStringIds
	waitmessage B_WAIT_TIME_LONG
BattleScript_DropWeightsEnd::
	goto BattleScript_MoveEnd

BattleScript_Dropitem_Ret::
	printstring STRINGID_TARGETDROPPEDITEM
	waitmessage B_WAIT_TIME_LONG
	return

BattleScript_AttackerStolenPositiveEffects::
	printstring STRINGID_ATTACKERSTOLENTARGETPOSITIVE
	waitmessage B_WAIT_TIME_LONG
	return

BattleScript_EffectZantetsuken::
	attackcanceler
	attackstring
	ppreduce
	jumpifcantuselastresort BS_ATTACKER, BattleScript_ButItFailed
	accuracycheck BattleScript_MoveMissedPause, ACC_CURR_MOVE
	setmoveeffect MOVE_EFFECT_EXECUTION | MOVE_EFFECT_CERTAIN
	goto BattleScript_HitFromCritCalc

BattleScript_EffectOrderUp::
	setmoveeffect MOVE_EFFECT_ORDER_UP | MOVE_EFFECT_AFFECTS_ATTACKER | MOVE_EFFECT_CERTAIN
	goto BattleScript_EffectHit

BattleScript_EffectThornTrap::
	getthorntraptarget
	attackcanceler
	accuracycheck BattleScript_PrintMoveMissed, ACC_CURR_MOVE
	attackstring
	jumpifhasnohp BS_TARGET, BattleScript_ButItFailed
	jumpifstatus2 BS_ATTACKER, STATUS2_MULTIPLETURNS, BattleScript_EffectThornTrapNoPPReduce
	ppreduce
BattleScript_EffectThornTrapNoPPReduce:
	thorntrapmoveeffect
	goto BattleScript_HitFromCritCalc

BattleScript_EffectBackStab::
	jumpifstatus3 BS_ATTACKER, STATUS3_PHANTOM_FORCE, BattleScript_DoBackStab
	attackcanceler
	jumpifnotfirstturn BattleScript_FailedFromAtkString
	setmoveeffect MOVE_EFFECT_FLINCH
	goto BattleScript_EffectHit
BattleScript_DoBackStab:
	attackcanceler
	setmoveeffect MOVE_EFFECT_FLINCH
	goto BattleScript_EffectHit

BattleScript_EffectPledge::
	attackcanceler
	setpledge BattleScript_HitFromAccCheck
	attackstring
	pause B_WAIT_TIME_MED
	ppreduce
	printstring STRINGID_WAITINGFORPARTNERSMOVE
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_EffectCombinedPledge_Water::
	call BattleScript_EffectHit_Pledge
	setpledgestatus BS_ATTACKER, SIDE_STATUS_RAINBOW
	pause B_WAIT_TIME_SHORTEST
	printstring STRINGID_ARAINBOWAPPEAREDONSIDE
	waitmessage B_WAIT_TIME_LONG
	playanimation BS_ATTACKER, B_ANIM_RAINBOW, NULL
	waitanimation
	goto BattleScript_MoveEnd

BattleScript_TheRainbowDisappeared::
	printstring STRINGID_THERAINBOWDISAPPEARED
	waitmessage B_WAIT_TIME_LONG
	end2

BattleScript_EffectCombinedPledge_Fire::
	call BattleScript_EffectHit_Pledge
	setpledgestatus BS_TARGET, SIDE_STATUS_SEA_OF_FIRE
	pause B_WAIT_TIME_SHORTEST
	printstring STRINGID_SEAOFFIREENVELOPEDSIDE
	waitmessage B_WAIT_TIME_LONG
	playanimation BS_TARGET, B_ANIM_SEA_OF_FIRE, NULL
	waitanimation
	goto BattleScript_MoveEnd

BattleScript_HurtByTheSeaOfFire::
	printstring STRINGID_HURTBYTHESEAOFFIRE
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_DoTurnDmg

BattleScript_TheSeaOfFireDisappeared::
	printstring STRINGID_THESEAOFFIREDISAPPEARED
	waitmessage B_WAIT_TIME_LONG
	end2

BattleScript_EffectCombinedPledge_Grass::
	call BattleScript_EffectHit_Pledge
	setpledgestatus BS_TARGET, SIDE_STATUS_SWAMP
	pause B_WAIT_TIME_SHORTEST
	printstring STRINGID_SWAMPENVELOPEDSIDE
	waitmessage B_WAIT_TIME_LONG
	playanimation BS_TARGET, B_ANIM_SWAMP, NULL
	waitanimation
	goto BattleScript_MoveEnd

BattleScript_TheSwampDisappeared::
	printstring STRINGID_THESWAMPDISAPPEARED
	waitmessage B_WAIT_TIME_LONG
	end2

BattleScript_EffectHit_Pledge::
	pause B_WAIT_TIME_MED
	printstring STRINGID_THETWOMOVESBECOMEONE
	waitmessage B_WAIT_TIME_LONG
	accuracycheck BattleScript_PrintMoveMissed, ACC_CURR_MOVE
	ppreduce
	call BattleScript_EffectDamage_Ret
	seteffectwithchance
	tryfaintmon BS_TARGET, FALSE, NULL
	return

BattleScript_EffectRound::
	setmoveeffect MOVE_EFFECT_ROUND
	goto BattleScript_EffectHit

BattleScript_EffectTwinBite::
	attackcanceler
	accuracycheck BattleScript_PrintMoveMissed, ACC_CURR_MOVE
	attackstring
	ppreduce
	setmultihitcounter 2
	initmultihitstring
	sethword sMULTIHIT_EFFECT, MOVE_EFFECT_DEF_MINUS_1
	setbyte sB_ANIM_TURN, 0
BattleScript_TwinBiteLoop::
	jumpifhasnohp BS_ATTACKER, BattleScript_TwinBiteEnd
	jumpifhasnohp BS_TARGET, BattleScript_TwinBitePrintStrings
	jumpifhalfword CMP_EQUAL, gChosenMove, MOVE_SLEEP_TALK, BattleScript_DoTwinBite
	jumpifstatus BS_ATTACKER, STATUS1_SLEEP, BattleScript_TwinBitePrintStrings
BattleScript_DoTwinBite::
	movevaluescleanup
	copyhword sMOVE_EFFECT, sMULTIHIT_EFFECT
	critcalc
	damagecalc
	jumpifmovehadnoeffect BattleScript_TwinBiteNoMoreHits
	adjustdamage
	attackanimation
	waitanimation
	effectivenesssound
	hitanimation BS_TARGET
	waitstate
	healthbarupdate BS_TARGET
	datahpupdate BS_TARGET
	critmessage
	waitmessage B_WAIT_TIME_LONG
	multihitresultmessage
	printstring STRINGID_EMPTYSTRING3
	waitmessage 1
	seteffectwithchance
	addbyte sMULTIHIT_STRING + 4, 1
	moveendto MOVEEND_NEXT_TARGET
	jumpifbyte CMP_COMMON_BITS, gMoveResultFlags, MOVE_RESULT_FOE_ENDURED, BattleScript_TwinBitePrintStrings
	decrementmultihit BattleScript_TwinBiteSpDefLower
	goto BattleScript_TwinBitePrintStrings
BattleScript_TwinBiteNoMoreHits::
	pause B_WAIT_TIME_SHORT
BattleScript_TwinBitePrintStrings::
	resultmessage
	waitmessage B_WAIT_TIME_LONG
	jumpifmovehadnoeffect BattleScript_TwinBiteEnd
	copyarray gBattleTextBuff1, sMULTIHIT_STRING, 6
	printstring STRINGID_HITXTIMES
	waitmessage B_WAIT_TIME_LONG
BattleScript_TwinBiteEnd::
	tryfaintmon BS_TARGET, FALSE, NULL
	moveendcase MOVEEND_SYNCHRONIZE_TARGET
	moveendfrom MOVEEND_STATUS_IMMUNITY_ABILITIES
	end
BattleScript_TwinBiteSpDefLower::
	sethword sMULTIHIT_EFFECT, MOVE_EFFECT_SP_DEF_MINUS_1
	setbyte sB_ANIM_TURN, 1
	goto BattleScript_TwinBiteLoop

BattleScript_EffectConvergence:
	attackcanceler
	attackstring
	ppreduce
	jumpifstat BS_ATTACKER, CMP_LESS_THAN, STAT_DEF, MAX_STAT_STAGE, BattleScript_ConvergenceDoMoveAnim
	jumpifstat BS_ATTACKER, CMP_LESS_THAN, STAT_SPATK, MAX_STAT_STAGE, BattleScript_ConvergenceDoMoveAnim
	jumpifstat BS_ATTACKER, CMP_EQUAL, STAT_SPDEF, MAX_STAT_STAGE, BattleScript_CantRaiseMultipleStats
BattleScript_ConvergenceDoMoveAnim::
	attackanimation
	waitanimation
	setbyte sSTAT_ANIM_PLAYED, FALSE
	playstatchangeanimation BS_ATTACKER, BIT_DEF | BIT_SPATK | BIT_SPDEF, 0
	setstatchanger STAT_DEF, 1, FALSE
	statbuffchange MOVE_EFFECT_AFFECTS_ATTACKER | STAT_CHANGE_ALLOW_PTR, BattleScript_ConvergenceTrySpAtk
	jumpifbyte CMP_EQUAL, cMULTISTRING_CHOOSER, B_MSG_STAT_WONT_INCREASE, BattleScript_ConvergenceTrySpAtk
	printfromtable gStatUpStringIds
	waitmessage B_WAIT_TIME_LONG
BattleScript_ConvergenceTrySpAtk::
	setstatchanger STAT_SPATK, 1, FALSE
	statbuffchange MOVE_EFFECT_AFFECTS_ATTACKER | STAT_CHANGE_ALLOW_PTR, BattleScript_ConvergenceTrySpDef
	jumpifbyte CMP_EQUAL, cMULTISTRING_CHOOSER, B_MSG_STAT_WONT_INCREASE, BattleScript_ConvergenceTrySpDef
	printfromtable gStatUpStringIds
	waitmessage B_WAIT_TIME_LONG
BattleScript_ConvergenceTrySpDef::
	setstatchanger STAT_SPDEF, 1, FALSE
	statbuffchange MOVE_EFFECT_AFFECTS_ATTACKER | STAT_CHANGE_ALLOW_PTR, BattleScript_ConvergenceEnd
	jumpifbyte CMP_EQUAL, cMULTISTRING_CHOOSER, B_MSG_STAT_WONT_INCREASE, BattleScript_ConvergenceEnd
	printfromtable gStatUpStringIds
	waitmessage B_WAIT_TIME_LONG
BattleScript_ConvergenceEnd::
	goto BattleScript_MoveEnd

BattleScript_EffectAttackUpUserAlly:
	jumpifnoally BS_ATTACKER, BattleScript_EffectAttackUp
	attackcanceler
	attackstring
	ppreduce
	jumpifstat BS_ATTACKER, CMP_NOT_EQUAL, STAT_ATK, MAX_STAT_STAGE, BattleScript_EffectAttackUpUserAlly_Works
	jumpifstat BS_ATTACKER_PARTNER, CMP_EQUAL, STAT_ATK, MAX_STAT_STAGE, BattleScript_ButItFailed
BattleScript_EffectAttackUpUserAlly_Works:
	attackanimation
	waitanimation
	setstatchanger STAT_ATK, 1, FALSE
	statbuffchange MOVE_EFFECT_AFFECTS_ATTACKER | STAT_CHANGE_ALLOW_PTR, BattleScript_EffectAttackUpUserAlly_TryAlly
	jumpifbyte CMP_EQUAL, cMULTISTRING_CHOOSER, B_MSG_STAT_WONT_INCREASE, BattleScript_EffectAttackUpUserAllyUser_PrintString
	setgraphicalstatchangevalues
	playanimation BS_ATTACKER, B_ANIM_STATS_CHANGE, sB_ANIM_ARG1
BattleScript_EffectAttackUpUserAllyUser_PrintString:
	printfromtable gStatUpStringIds
	waitmessage B_WAIT_TIME_LONG
BattleScript_EffectAttackUpUserAlly_TryAlly:
	setallytonexttarget BattleScript_EffectAttackUpUserAlly_TryAlly_
BattleScript_EffectAttackUpUserAlly_End:
	goto BattleScript_MoveEnd
BattleScript_EffectAttackUpUserAlly_TryAlly_:
	setstatchanger STAT_ATK, 1, FALSE
	statbuffchange STAT_CHANGE_ALLOW_PTR, BattleScript_EffectAttackUpUserAlly_End
	jumpifbyte CMP_NOT_EQUAL, cMULTISTRING_CHOOSER, B_MSG_STAT_WONT_INCREASE, BattleScript_EffectAttackUpUserAlly_AllyAnim
	pause B_WAIT_TIME_SHORTEST
	printstring STRINGID_TARGETSTATWONTGOHIGHER
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_EffectAttackUpUserAlly_End
BattleScript_EffectAttackUpUserAlly_AllyAnim:
	setgraphicalstatchangevalues
	playanimation BS_TARGET, B_ANIM_STATS_CHANGE, sB_ANIM_ARG1
	printfromtable gStatUpStringIds
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_EffectAttackUpUserAlly_End

BattleScript_EffectTidyUp::
	attackcanceler
	attackstring
	ppreduce
	setbyte gBattleCommunication, 0
	jumpifsatkishigher BattleScript_TidyUpTrySatk
	jumpifstat BS_ATTACKER, CMP_LESS_THAN, STAT_ATK, MAX_STAT_STAGE, BattleScript_TidyUpDoMoveAnim
	jumpifstat BS_ATTACKER, CMP_EQUAL, STAT_SPEED, MAX_STAT_STAGE, BattleScript_CantRaiseMultipleStats
BattleScript_TidyUpDoMoveAnim::
	attackanimation
	waitanimation
	tidyupfree
	setbyte sSTAT_ANIM_PLAYED, FALSE
	playstatchangeanimation BS_ATTACKER, BIT_ATK | BIT_SPEED, 0
	setstatchanger STAT_ATK, 1, FALSE
	statbuffchange MOVE_EFFECT_AFFECTS_ATTACKER | STAT_CHANGE_ALLOW_PTR, BattleScript_TidyUpTrySpeed
	jumpifbyte CMP_EQUAL, cMULTISTRING_CHOOSER, B_MSG_STAT_WONT_INCREASE, BattleScript_TidyUpTrySpeed
	printfromtable gStatUpStringIds
	waitmessage B_WAIT_TIME_LONG
BattleScript_TidyUpTrySpeed::
	setstatchanger STAT_SPEED, 1, FALSE
	statbuffchange MOVE_EFFECT_AFFECTS_ATTACKER | STAT_CHANGE_ALLOW_PTR, BattleScript_TidyUpEnd
	jumpifbyte CMP_EQUAL, cMULTISTRING_CHOOSER, B_MSG_STAT_WONT_INCREASE, BattleScript_TidyUpEnd
	printfromtable gStatUpStringIds
	waitmessage B_WAIT_TIME_LONG
BattleScript_TidyUpEnd::
	goto BattleScript_MoveEnd

BattleScript_TidyUpTrySatk:
	jumpifstat BS_ATTACKER, CMP_LESS_THAN, STAT_SPATK, MAX_STAT_STAGE, BattleScript_TidyUpDoMoveAnimSatk
	jumpifstat BS_ATTACKER, CMP_EQUAL, STAT_SPEED, MAX_STAT_STAGE, BattleScript_CantRaiseMultipleStats
BattleScript_TidyUpDoMoveAnimSatk::
	attackanimation
	waitanimation
	tidyupfree
	setbyte sSTAT_ANIM_PLAYED, FALSE
	playstatchangeanimation BS_ATTACKER, BIT_SPATK | BIT_SPEED, 0
	setstatchanger STAT_SPATK, 1, FALSE
	statbuffchange MOVE_EFFECT_AFFECTS_ATTACKER | STAT_CHANGE_ALLOW_PTR, BattleScript_TidyUpTrySpeed
	jumpifbyte CMP_EQUAL, cMULTISTRING_CHOOSER, B_MSG_STAT_WONT_INCREASE, BattleScript_TidyUpTrySpeed
	printfromtable gStatUpStringIds
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_TidyUpTrySpeed

BattleScript_EffectDoodle::
	attackcanceler
	attackstring
	ppreduce
	trycopyability BattleScript_ButItFailed
	attackanimation
	waitanimation
	call BattleScript_AbilityPopUp
	printstring STRINGID_PKMNCOPIEDFOE
	waitmessage B_WAIT_TIME_LONG
	jumpifbattletype BATTLE_TYPE_DOUBLE, BattleScript_DoodleTryCopyAbilityToAlly
	goto BattleScript_MoveEnd
BattleScript_DoodleTryCopyAbilityToAlly:
	saveattacker
	setbattlerto BS_ATTACKER, BS_ATTACKER_PARTNER
	trycopyability BattleScript_DoodleEnd
	call BattleScript_AbilityPopUp
	printstring STRINGID_PKMNCOPIEDFOE
	waitmessage B_WAIT_TIME_LONG
BattleScript_DoodleEnd:
	restoreattacker
	goto BattleScript_MoveEnd

BattleScript_EffectChillyReception::
	attackcanceler
	attackstring
	ppreduce
	jumpifhalfword CMP_COMMON_BITS, gBattleWeather, WEATHER_SUN_PRIMAL, BattleScript_ExtremelyHarshSunlightWasNotLessened
	jumpifhalfword CMP_COMMON_BITS, gBattleWeather, WEATHER_RAIN_PRIMAL, BattleScript_NoReliefFromHeavyRain
	jumpifhalfword CMP_COMMON_BITS, gBattleWeather, WEATHER_STRONG_WINDS, BattleScript_MysteriousAirCurrentBlowsOn
	sethail
	attackanimation
	waitanimation
	printfromtable gMoveWeatherChangeStringIds
	waitmessage B_WAIT_TIME_LONG
	call BattleScript_WeatherFormChanges
	goto BattleScript_TryToEscape

BattleScript_EffectGlaiveRush::
	call BattleScript_EffectHit_Ret
	setbattlerstatus BS_ATTACKER, 4, STATUS4_GLAIVE_RUSH, BattleScript_GlaiveRushEnd
BattleScript_GlaiveRushEnd:
	tryfaintmon BS_TARGET, FALSE, NULL
	goto BattleScript_MoveEnd

BattleScript_EffectSpicyExtract::
	attackcanceler
	attackstring
	ppreduce
	jumpifstat BS_TARGET, CMP_LESS_THAN, STAT_ATK, MAX_STAT_STAGE, BattleScript_SpicyExtractDoMoveAnim
	jumpifstat BS_TARGET, CMP_EQUAL, STAT_DEF, MIN_STAT_STAGE, BattleScript_ButItFailed
BattleScript_SpicyExtractDoMoveAnim::
	accuracycheck BattleScript_ButItFailed, ACC_CURR_MOVE
	attackanimation
	waitanimation
	setstatchanger STAT_DEF, 2, TRUE
	statbuffchange STAT_CHANGE_ALLOW_PTR, BattleScript_SpicyExtractTryAttack
	jumpifbyte CMP_EQUAL, cMULTISTRING_CHOOSER, B_MSG_STAT_WONT_DECREASE, BattleScript_SpicyExtractTryAttack
	setgraphicalstatchangevalues
	playanimation BS_TARGET, B_ANIM_STATS_CHANGE, sB_ANIM_ARG1
	printfromtable gStatDownStringIds
	waitmessage B_WAIT_TIME_LONG
BattleScript_SpicyExtractTryAttack::
	setstatchanger STAT_ATK, 2, FALSE
	statbuffchange STAT_CHANGE_ALLOW_PTR, BattleScript_SpicyExtractEnd
	jumpifbyte CMP_EQUAL, cMULTISTRING_CHOOSER, B_MSG_STAT_WONT_INCREASE, BattleScript_SpicyExtractEnd
	setgraphicalstatchangevalues
	playanimation BS_TARGET, B_ANIM_STATS_CHANGE, sB_ANIM_ARG1
	printfromtable gStatUpStringIds
	waitmessage B_WAIT_TIME_LONG
BattleScript_SpicyExtractEnd::
	goto BattleScript_MoveEnd

BattleScript_EffectSpinOut::
	setmoveeffect MOVE_EFFECT_SPD_MINUS_2 | MOVE_EFFECT_AFFECTS_ATTACKER | MOVE_EFFECT_CERTAIN
	goto BattleScript_EffectHit

BattleScript_EffectMakeItRain:
	jumpifbattletype BATTLE_TYPE_DOUBLE, BattleScript_MakeItRainDoubles
BattleScript_MakeItRainContinuous:
	setmoveeffect MOVE_EFFECT_PAYDAY
	call BattleScript_EffectHit_Ret
	seteffectwithchance
	tryfaintmon BS_TARGET, FALSE, NULL
	setmoveeffect MOVE_EFFECT_SP_ATK_MINUS_1 | MOVE_EFFECT_AFFECTS_ATTACKER | MOVE_EFFECT_CERTAIN
	seteffectprimary
	goto BattleScript_MoveEnd
BattleScript_MakeItRainDoubles:
	jumpifword CMP_NO_COMMON_BITS, gHitMarker, HITMARKER_NO_ATTACKSTRING | HITMARKER_NO_PPDEDUCT, BattleScript_NoMoveEffect
	goto BattleScript_MakeItRainContinuous
BattleScript_NoMoveEffect:
	setmoveeffect 0
	goto BattleScript_EffectHit

BattleScript_EffectMaxMove::
	goto BattleScript_EffectHit

BattleScript_EffectSyrupBomb::
	setmoveeffect MOVE_EFFECT_SYRUP_BOMB
	goto BattleScript_EffectHit

BattleScript_SyrupBombActivates::
	printstring STRINGID_TARGETCOVEREDINSTICKYCANDYSYRUP
	waitmessage B_WAIT_TIME_LONG
	return

BattleScript_SyrupBombEndTurn::
	printstring STRINGID_EMPTYSTRING3
	waitmessage 1
	playanimation BS_ATTACKER, B_ANIM_SYRUP_BOMB_SPEED_DROP, NULL
	setstatchanger STAT_SPEED, 1, TRUE
	statbuffchange STAT_CHANGE_ALLOW_PTR | STAT_BUFF_NOT_PROTECT_AFFECTED, BattleScript_SyrupBombTurnDmgEnd
	printfromtable gStatDownStringIds
	waitmessage B_WAIT_TIME_LONG
BattleScript_SyrupBombTurnDmgEnd:
	end2

BattleScript_EffectMatchaGotcha::
	setmoveeffect MOVE_EFFECT_BURN
	goto BattleScript_EffectAbsorb

BattleScript_EffectSaltCure:
	call BattleScript_EffectHit_Ret
	tryfaintmon BS_TARGET, FALSE, NULL
	jumpiffainted BS_TARGET, TRUE, BattleScript_EffectSaltCure_End
	applysaltcure BS_TARGET
	printstring STRINGID_TARGETISBEINGSALTCURED
	waitmessage B_WAIT_TIME_LONG
BattleScript_EffectSaltCure_End:
	goto BattleScript_MoveEnd

BattleScript_SaltCureExtraDamage::
	playanimation BS_TARGET, B_ANIM_SALT_CURE_DAMAGE, NULL
	waitanimation
	call BattleScript_HurtTarget_NoString
	printstring STRINGID_TARGETISHURTBYSALTCURE
	waitmessage B_WAIT_TIME_LONG
	end2

BattleScript_HurtTarget_NoString:
	orword gHitMarker, HITMARKER_IGNORE_SUBSTITUTE | HITMARKER_PASSIVE_DAMAGE
	healthbarupdate BS_TARGET
	datahpupdate BS_TARGET
	tryfaintmon BS_TARGET, FALSE, NULL
	return

BattleScript_EffectMortalSpin:
	call BattleScript_EffectHit_Ret
	rapidspinfree
	setmoveeffect MOVE_EFFECT_POISON
	seteffectwithchance
	tryfaintmon BS_TARGET, FALSE, NULL
	moveendall
	end

BattleScript_EffectSupersonic:
	setstatchanger STAT_EVASION, 1, TRUE
	attackcanceler
	jumpifsubstituteblocks BattleScript_FailedFromAtkString
	jumpifstat BS_TARGET, CMP_NOT_EQUAL, STAT_EVASION, MIN_STAT_STAGE, BattleScript_SupersonicWorks
	jumpifstatus BS_TARGET, STATUS1_PSN_ANY, BattleScript_FailedFromAtkString
	jumpifabilityorinnate BS_TARGET, ABILITY_OWN_TEMPO, BattleScript_InnateOwnTempoPrevents
	jumpifstatus2 BS_TARGET, STATUS2_CONFUSION, BattleScript_AlreadyConfused
	jumpifterrainaffected BS_TARGET, STATUS_FIELD_MISTY_TERRAIN, BattleScript_MistyTerrainPrevents
	jumpifsafeguard BattleScript_SafeguardProtected
	jumpifkingsgrace BattleScript_KingsGraceProtected
BattleScript_SupersonicWorks:
	accuracycheck BattleScript_PrintMoveMissed, ACC_CURR_MOVE
	attackstring
	ppreduce
	statbuffchange STAT_CHANGE_ALLOW_PTR, BattleScript_SupersonicTryConfuse
	jumpifbyte CMP_LESS_THAN, cMULTISTRING_CHOOSER, B_MSG_STAT_WONT_DECREASE, BattleScript_SupersonicDoAnim
	jumpifbyte CMP_EQUAL, cMULTISTRING_CHOOSER, B_MSG_STAT_FELL_EMPTY, BattleScript_SupersonicTryConfuse
	pause B_WAIT_TIME_SHORT
	goto BattleScript_SupersonicPrintString
BattleScript_SupersonicDoAnim::
	attackanimation
	waitanimation
	setgraphicalstatchangevalues
	playanimation BS_TARGET, B_ANIM_STATS_CHANGE, sB_ANIM_ARG1
BattleScript_SupersonicPrintString::
	printfromtable gStatDownStringIds
	waitmessage B_WAIT_TIME_LONG
BattleScript_SupersonicTryConfuse::
	setmoveeffect MOVE_EFFECT_CONFUSE
	seteffectprimary
	resultmessage
	waitmessage B_WAIT_TIME_LONG
BattleScript_SupersonicEnd:
	goto BattleScript_MoveEnd

BattleScript_EffectAbsoluteZero::
	attackcanceler
	attackstring
	ppreduce
	copybyte gBattlerTarget, gBattlerAttacker
	attackanimation
	waitanimation
BattleScript_EffectAbsoluteZeroLoop::
	movevaluescleanup
	accuracycheck BattleScript_EffectAbsoluteZeroMissed, ACC_CURR_MOVE
	setmoveeffect MOVE_EFFECT_FREEZE
	seteffectprimary
	resultmessage
	waitmessage B_WAIT_TIME_LONG
	moveendto MOVEEND_NEXT_TARGET
BattleScript_EffectAbsoluteZeroNextTarget:
	setnextmoontargetexceptattacker BattleScript_EffectAbsoluteZeroLoop
BattleScript_EffectAbsoluteZeroEnd:
	moveendcase MOVEEND_CLEAR_BITS
	end
BattleScript_EffectAbsoluteZeroMissed::
	attackstring
	pause B_WAIT_TIME_SHORT
	effectivenesssound
	resultmessage
	waitmessage B_WAIT_TIME_LONG
	moveendto MOVEEND_NEXT_TARGET
	goto BattleScript_EffectAbsoluteZeroNextTarget

BattleScript_EffectMockingShout::
	attackcanceler
	attackstring
	ppreduce
	jumpifstat BS_TARGET, CMP_GREATER_THAN, STAT_ATK, MIN_STAT_STAGE, BattleScript_MockingShoutDoMoveAnim
	jumpifstat BS_TARGET, CMP_EQUAL, STAT_SPEED, MIN_STAT_STAGE, BattleScript_CantLowerMultipleStats
BattleScript_MockingShoutDoMoveAnim::
	accuracycheck BattleScript_ButItFailed, ACC_CURR_MOVE
	attackanimation
	waitanimation
	setbyte sSTAT_ANIM_PLAYED, FALSE
	playstatchangeanimation BS_TARGET, BIT_ATK | BIT_SPEED, STAT_CHANGE_NEGATIVE | STAT_CHANGE_MULTIPLE_STATS
	playstatchangeanimation BS_TARGET, BIT_ATK, STAT_CHANGE_NEGATIVE
	setstatchanger STAT_ATK, 1, TRUE
	statbuffchange STAT_CHANGE_ALLOW_PTR, BattleScript_MockingShoutTryLowerSpd
	jumpifbyte CMP_EQUAL, cMULTISTRING_CHOOSER, B_MSG_STAT_WONT_DECREASE, BattleScript_MockingShoutTryLowerSpd
	printfromtable gStatDownStringIds
	waitmessage B_WAIT_TIME_LONG
BattleScript_MockingShoutTryLowerSpd::
	playstatchangeanimation BS_TARGET, BIT_SPEED, STAT_CHANGE_NEGATIVE
	setstatchanger STAT_SPEED, 1, TRUE
	statbuffchange STAT_CHANGE_ALLOW_PTR, BattleScript_MockingShoutEnd
	jumpifbyte CMP_EQUAL, cMULTISTRING_CHOOSER, B_MSG_STAT_WONT_DECREASE, BattleScript_MockingShoutEnd
	printfromtable gStatDownStringIds
	waitmessage B_WAIT_TIME_LONG
BattleScript_MockingShoutEnd::
	goto BattleScript_MoveEnd

BattleScript_EffectHeatSiphon::
	setmoveeffect MOVE_EFFECT_ABSORB_50 | MOVE_EFFECT_CERTAIN
	setbyte cMULTISTRING_CHOOSER, B_MSG_ABSORB_HEAT
	call BattleScript_EffectHit_Ret
	seteffectwithchance
	jumpifnottype BS_TARGET, TYPE_FIRE, BattleScript_HeatSiphonTryFainting
	losetype BS_TARGET, TYPE_FIRE
	printstring STRINGID_TARGETLOSTFIRETYPE
	waitmessage B_WAIT_TIME_LONG
BattleScript_HeatSiphonTryFainting::
	tryfaintmon BS_TARGET, FALSE, NULL
	goto BattleScript_MoveEnd

BattleScript_EffectTrash::
	setmoveeffect MOVE_EFFECT_TRASH | MOVE_EFFECT_CERTAIN
	goto BattleScript_EffectHit

BattleScript_EffectMoonfall::
	attackcanceler
	attackstring
	ppreduce
	copybyte gBattlerTarget, gBattlerAttacker
	attackanimation
	waitanimation
BattleScript_EffectMoonfallLoop::
	movevaluescleanup
	accuracycheck BattleScript_EffectMoonfallMissed, ACC_CURR_MOVE
	critcalc
	damagecalc
	adjustdamage
	effectivenesssound
	hitanimation BS_TARGET
	waitstate
	healthbarupdate BS_TARGET
	datahpupdate BS_TARGET
	critmessage
	waitmessage B_WAIT_TIME_LONG
	resultmessage
	waitmessage B_WAIT_TIME_LONG
	seteffectwithchance
	tryfaintmon BS_TARGET, FALSE, NULL
	moveendto MOVEEND_NEXT_TARGET
BattleScript_EffectMoonfallNextTarget:
	setnextmoontargetexceptattacker BattleScript_EffectMoonfallLoop
BattleScript_EffectMoonfallEnd:
	moveendcase MOVEEND_CLEAR_BITS
	end
BattleScript_EffectMoonfallMissed::
	attackstring
	pause B_WAIT_TIME_SHORT
	effectivenesssound
	resultmessage
	waitmessage B_WAIT_TIME_LONG
	moveendto MOVEEND_NEXT_TARGET
	goto BattleScript_EffectMoonfallNextTarget

BattleScript_EffectFallingStars::
	attackcanceler
	attackstring
	ppreduce
	attackanimation
	waitanimation
	setmultihitcounter 10
	initmultihitstring
	sethword sMULTIHIT_EFFECT, 0
BattleScript_EffectFallingStarsNextTarget:
	setnextstartarget BattleScript_EffectFallingStarsNoMoreHits
	jumpifhasnohp BS_TARGET, BattleScript_EffectFallingStarsNextTarget
BattleScript_EffectFallingStarsHit::
	movevaluescleanup
	copyhword sMOVE_EFFECT, sMULTIHIT_EFFECT
	accuracycheck BattleScript_EffectFallingStarsMissed, ACC_CURR_MOVE
	setbyte sB_ANIM_TURN, 1
	critcalc
	damagecalc
	adjustdamage
	attackanimation
	waitanimation
	effectivenesssound
	hitanimation BS_TARGET
	waitstate
	healthbarupdate BS_TARGET
	datahpupdate BS_TARGET
	critmessage
	waitmessage B_WAIT_TIME_LONG
	multihitresultmessage
	printstring STRINGID_EMPTYSTRING3
	waitmessage 1
	addbyte sMULTIHIT_STRING + 4, 1
	moveendto MOVEEND_NEXT_TARGET
BattleScript_EffectFallingStarsLoop::
	decrementmultihit BattleScript_EffectFallingStarsNextTarget
	goto BattleScript_EffectFallingStarsPrintStrings
BattleScript_EffectFallingStarsNoMoreHits::
	pause B_WAIT_TIME_SHORT
BattleScript_EffectFallingStarsPrintStrings::
	resultmessage
	waitmessage B_WAIT_TIME_LONG
	copyarray gBattleTextBuff1, sMULTIHIT_STRING, 6
	printstring STRINGID_HITXTIMES
	waitmessage B_WAIT_TIME_LONG
BattleScript_EffectFallingStarsEnd::
	tryfaintmon BS_TARGET, FALSE, NULL
	moveendcase MOVEEND_SYNCHRONIZE_TARGET
	moveendfrom MOVEEND_STATUS_IMMUNITY_ABILITIES
	end
BattleScript_EffectFallingStarsMissed:
	attackstring
	pause B_WAIT_TIME_SHORT
	effectivenesssound
	resultmessage
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_EffectFallingStarsLoop

BattleScript_EffectHellblaze::
	setmoveeffect MOVE_EFFECT_PREVENT_REVIVE | MOVE_EFFECT_CERTAIN
	goto BattleScript_EffectHit

BattleScript_EffectBloomsday::
	attackcanceler
	attackstring
	ppreduce
	jumpifhalfword CMP_COMMON_BITS, gBattleWeather, B_WEATHER_SUN, BattleScript_ButItFailed
	jumpifhalfword CMP_COMMON_BITS, gBattleWeather, WEATHER_RAIN_PRIMAL, BattleScript_NoReliefFromHeavyRain
	jumpifhalfword CMP_COMMON_BITS, gBattleWeather, WEATHER_STRONG_WINDS, BattleScript_MysteriousAirCurrentBlowsOn
	setsunny
	attackanimation
	waitanimation
	printfromtable gMoveWeatherChangeStringIds
	waitmessage B_WAIT_TIME_LONG
	call BattleScript_WeatherFormChanges
	jumpifstat BS_ATTACKER, CMP_LESS_THAN, STAT_ATK, MAX_STAT_STAGE, BattleScript_BloomsdayTryAtk
	jumpifstat BS_ATTACKER, CMP_EQUAL, STAT_SPATK, MAX_STAT_STAGE, BattleScript_MoveEnd
BattleScript_BloomsdayTryAtk::
	setbyte sSTAT_ANIM_PLAYED, FALSE
	playstatchangeanimation BS_ATTACKER, BIT_ATK | BIT_SPATK, 0
	setstatchanger STAT_ATK, 1, FALSE
	statbuffchange MOVE_EFFECT_AFFECTS_ATTACKER | STAT_CHANGE_ALLOW_PTR, BattleScript_BloomsdayTrySpAtk
	jumpifbyte CMP_EQUAL, cMULTISTRING_CHOOSER, B_MSG_STAT_WONT_INCREASE, BattleScript_BloomsdayTrySpAtk
	printfromtable gStatUpStringIds
	waitmessage B_WAIT_TIME_LONG
BattleScript_BloomsdayTrySpAtk::
	setstatchanger STAT_SPATK, 1, FALSE
	statbuffchange MOVE_EFFECT_AFFECTS_ATTACKER | STAT_CHANGE_ALLOW_PTR, BattleScript_MoveEnd
	jumpifbyte CMP_EQUAL, cMULTISTRING_CHOOSER, B_MSG_STAT_WONT_INCREASE, BattleScript_MoveEnd
	printfromtable gStatUpStringIds
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_EffectHellGate::
	attackcanceler
	accuracycheck BattleScript_PrintMoveMissed, ACC_CURR_MOVE
	attackstring
	ppreduce
	typecalc
	bichalfword gMoveResultFlags, MOVE_RESULT_SUPER_EFFECTIVE | MOVE_RESULT_NOT_VERY_EFFECTIVE
	dmgattackermissinghp
	adjustdamage
	goto BattleScript_HitFromAtkAnimation

BattleScript_EffectCordyceps::
	attackcanceler
	attackstring
	pause B_WAIT_TIME_SHORT
	ppreduce
	jumpifsubstituteblocks BattleScript_ButItFailed
	accuracycheck BattleScript_DoCordyceps, ACC_CURR_MOVE
BattleScript_DoCordyceps::
	setcordyceps
	attackanimation
	waitanimation
	printfromtable gCordycepsStringIds
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_EffectDragonCombo::
	setmoveeffect MOVE_EFFECT_FLINCH
	attackcanceler
	accuracycheck BattleScript_PrintMoveMissed, ACC_CURR_MOVE
	attackstring
	ppreduce
	damagewithbattlerhp BS_ATTACKER, FALSE
	healthbarupdate BS_ATTACKER
	datahpupdate BS_ATTACKER
	critcalc
	damagecalc
	damagewithbattlerhp BS_ATTACKER, TRUE
	adjustdamage
	attackanimation
	waitanimation
	effectivenesssound
	hitanimation BS_TARGET
	waitstate
	healthbarupdate BS_TARGET
	datahpupdate BS_TARGET
	critmessage
	waitmessage B_WAIT_TIME_LONG
	resultmessage
	waitmessage B_WAIT_TIME_LONG
	seteffectwithchance
	tryfaintmon BS_TARGET, FALSE, NULL
	moveendall
	end

BattleScript_EffectSpellFistAffected::
	jumpifabilityorinnate BS_ATTACKER, ABILITY_SPELL_FIST, BattleScript_EffectSpAtkUpHit
	goto BattleScript_EffectAttackUpHit

BattleScript_EffectLegendPower::
BattleScript_EffectJudgment::
	legendplatecheck
	goto BattleScript_EffectHit

BattleScript_EffectShedTail::
	attackcanceler
	ppreduce
	attackstring
	waitstate
	jumpifbattletype BATTLE_TYPE_ARENA, BattleScript_ButItFailed
	jumpifcantswitch SWITCH_IGNORE_ESCAPE_PREVENTION | BS_ATTACKER, BattleScript_ButItFailed
	jumpifstatus2 BS_ATTACKER, STATUS2_SUBSTITUTE, BattleScript_AlreadyHasSubstitute
	jumpifstatus2 BS_ATTACKER, STATUS2_PSYSHIELD, BattleScript_AlreadyHasPsyshield
	setsubstitute
	jumpifbyte CMP_NOT_EQUAL, cMULTISTRING_CHOOSER, B_MSG_SUBSTITUTE_FAILED, BattleScript_ShedTailAnim
	pause B_WAIT_TIME_SHORT
	goto BattleScript_ButItFailed
BattleScript_ShedTailAnim::
	attackanimation
	waitanimation
	healthbarupdate BS_ATTACKER
	datahpupdate BS_ATTACKER
	printfromtable gSubstituteUsedStringIds
	waitmessage B_WAIT_TIME_LONG
	moveendall
BattleScript_ShedTailSwitchOut::
	openpartyscreen BS_ATTACKER, BattleScript_ButItFailed
	switchoutabilitiesorinnates BS_ATTACKER, 0
	switchoutabilitiesorinnates BS_ATTACKER, 1
	switchoutabilitiesorinnates BS_ATTACKER, 2
	switchoutabilitiesorinnates BS_ATTACKER, 3
	swithchoutrevolvingruin BS_ATTACKER
	waitstate
	switchhandleorder BS_ATTACKER, 2
	returntoball BS_ATTACKER
	getswitchedmondata BS_ATTACKER
	switchindataupdate BS_ATTACKER
	hpthresholds BS_ATTACKER
	trytoclearprimalweather
	printstring STRINGID_EMPTYSTRING3
	waitmessage 1
	printstring STRINGID_SWITCHINMON
	switchinanim BS_ATTACKER, TRUE
	waitstate
	switchineffects BS_ATTACKER
	goto BattleScript_MoveEnd

BattleScript_EffectDoubleShock::
	attackcanceler
	attackstring
	ppreduce
	jumpiftype BS_ATTACKER, TYPE_ELECTRIC, BattleScript_DoubleShockWorks
	goto BattleScript_ButItFailed
BattleScript_DoubleShockWorks:
	accuracycheck BattleScript_MoveMissedPause, ACC_CURR_MOVE
	call BattleScript_EffectDamage_Ret
	losetype BS_ATTACKER, TYPE_ELECTRIC
	printstring STRINGID_ATTACKERLOSTELECTRICTYPE
	waitmessage B_WAIT_TIME_LONG
	tryfaintmon BS_TARGET, FALSE, NULL
	goto BattleScript_MoveEnd

BattleScript_EffectRevive::
	attackcanceler
	jumpifnorevivaltarget BS_ATTACKER, BattleScript_FailedFromAtkString
	attackstring
	ppreduce
	attackanimation
	waitanimation
	openpartyscreen BS_REVIVE_BATTLER, BattleScript_EffectReviveEnd
	printstring STRINGID_ATTACKERREVIVEDALLY
	waitmessage B_WAIT_TIME_LONG
BattleScript_EffectReviveEnd:
	moveendall
	end

BattleScript_EffectUndertow::
	attackcanceler
	accuracycheck BattleScript_PrintMoveMissed, ACC_CURR_MOVE
	attackstring
	ppreduce
	call BattleScript_EffectDamage_Ret
	setmoveeffect MOVE_EFFECT_DEF_MINUS_1
	seteffectwithchance
	setmoveeffect MOVE_EFFECT_SPD_MINUS_1
	seteffectwithchance
	tryfaintmon BS_TARGET, FALSE, NULL
	moveendall
	end

BattleScript_EffectToughItOut::
	attackcanceler
	ppreduce
	attackstring
	waitstate
	jumpifstatus2 BS_ATTACKER, STATUS2_SUBSTITUTE, BattleScript_AlreadyHasSubstitute
	jumpifstatus2 BS_ATTACKER, STATUS2_PSYSHIELD, BattleScript_AlreadyHasPsyshield
	setsubstitute
	jumpifbyte CMP_NOT_EQUAL, cMULTISTRING_CHOOSER, B_MSG_SUBSTITUTE_FAILED, BattleScript_ToughItOutAnim
	pause B_WAIT_TIME_SHORT
	goto BattleScript_ToughItOutString
BattleScript_ToughItOutAnim::
	attackanimation
	waitanimation
	healthbarupdate BS_ATTACKER
	datahpupdate BS_ATTACKER
BattleScript_ToughItOutString::
	printfromtable gSubstituteUsedStringIds
	waitmessage B_WAIT_TIME_LONG
	jumpifstat BS_TARGET, CMP_EQUAL, STAT_SPEED, MAX_STAT_STAGE, BattleScript_MoveEnd
	setstatchanger STAT_SPEED, 1, FALSE
	statbuffchange STAT_BUFF_NOT_PROTECT_AFFECTED | MOVE_EFFECT_CERTAIN | STAT_CHANGE_ALLOW_PTR, BattleScript_MoveEnd
	setgraphicalstatchangevalues
	playanimation BS_TARGET, B_ANIM_STATS_CHANGE, sB_ANIM_ARG1
	printfromtable gStatUpStringIds
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_EffectRecklessSwing::
	attackcanceler
	accuracycheck BattleScript_PrintMoveMissed, ACC_CURR_MOVE
	attackstring
	ppreduce
	damagewithbattlerhp BS_ATTACKER, FALSE
	healthbarupdate BS_ATTACKER
	datahpupdate BS_ATTACKER
	critcalc
	damagecalc
	damagewithbattlerhp BS_ATTACKER, TRUE
	adjustdamage
	attackanimation
	waitanimation
	effectivenesssound
	hitanimation BS_TARGET
	waitstate
	healthbarupdate BS_TARGET
	datahpupdate BS_TARGET
	critmessage
	waitmessage B_WAIT_TIME_LONG
	resultmessage
	waitmessage B_WAIT_TIME_LONG
	seteffectwithchance
	tryfaintmon BS_TARGET, FALSE, NULL
	moveendall
	end

BattleScript_EffectNeurotoxin::
	jumpifsubstituteblocks BattleScript_EffectHit
	setmoveeffect MOVE_EFFECT_NEUROTOXIN | MOVE_EFFECT_CERTAIN
	goto BattleScript_EffectHit

BattleScript_EffectTeatime::
	attackcanceler
	attackstring
	ppreduce
	jumpifteanoberry BattleScript_ButItFailed
@ at least one battler is affected 
	attackanimation
	waitanimation
BattleScript_TeatimeLoop:
	jumpifteainvulnerable BS_TARGET, BattleScript_Teatimevul
	jumpifrodaffected BS_TARGET, BattleScript_Teatimerod
	jumpifabsorbaffected BS_TARGET, BattleScript_Teatimesorb
	jumpifmotoraffected BS_TARGET, BattleScript_Teatimemotor
	orword gHitMarker, HITMARKER_DISABLE_ANIMATION | HITMARKER_IGNORE_SUBSTITUTE | HITMARKER_IGNORE_DISGUISE
	setbyte sBERRY_OVERRIDE, TRUE   @ override the requirements for eating berries
	consumeberry BS_TARGET, TRUE  @ consume the berry, then restore the item from changedItems
	bicword gHitMarker, HITMARKER_DISABLE_ANIMATION | HITMARKER_IGNORE_SUBSTITUTE | HITMARKER_IGNORE_DISGUISE
	setbyte sBERRY_OVERRIDE, FALSE
	removeitem BS_TARGET
	moveendto MOVEEND_NEXT_TARGET
	jumpifnexttargetvalid BattleScript_TeatimeLoop
	moveendcase MOVEEND_CLEAR_BITS
	goto BattleScript_MoveEnd
BattleScript_Teatimevul:
	moveendto MOVEEND_NEXT_TARGET
	jumpifnexttargetvalid BattleScript_TeatimeLoop
	moveendcase MOVEEND_CLEAR_BITS
	goto BattleScript_MoveEnd
BattleScript_Teatimesorb:
	copybyte gBattlerAbility, gBattlerTarget
	call BattleScript_AbilityPopUp
	moveendto MOVEEND_NEXT_TARGET
	jumpifnexttargetvalid BattleScript_TeatimeLoop
	moveendcase MOVEEND_CLEAR_BITS
	goto BattleScript_MoveEnd
BattleScript_Teatimerod:
	copybyte gBattlerAbility, gBattlerTarget
	call BattleScript_AbilityPopUp
	playstatchangeanimation BS_TARGET, BIT_SPATK, STAT_CHANGE_BY_TWO
	setstatchanger STAT_SPATK, 1, FALSE
	statbuffchange STAT_CHANGE_ALLOW_PTR, BattleScript_TeatimeBuffer
	jumpifbyte CMP_EQUAL, cMULTISTRING_CHOOSER, 0x2, BattleScript_TeatimeBuffer
	printfromtable gStatUpStringIds
	waitmessage 0x40
	moveendto MOVEEND_NEXT_TARGET
	jumpifnexttargetvalid BattleScript_TeatimeLoop
	moveendcase MOVEEND_CLEAR_BITS
	goto BattleScript_MoveEnd
BattleScript_Teatimemotor:
	copybyte gBattlerAbility, gBattlerTarget
	call BattleScript_AbilityPopUp
	playstatchangeanimation BS_TARGET, BIT_SPEED, STAT_CHANGE_BY_TWO
	setstatchanger STAT_SPEED, 1, FALSE
	statbuffchange STAT_CHANGE_ALLOW_PTR, BattleScript_TeatimeBuffer
	jumpifbyte CMP_EQUAL, cMULTISTRING_CHOOSER, 0x2, BattleScript_TeatimeBuffer
	printfromtable gStatUpStringIds
	waitmessage 0x40
	moveendto MOVEEND_NEXT_TARGET
	jumpifnexttargetvalid BattleScript_TeatimeLoop
	moveendcase MOVEEND_CLEAR_BITS
	goto BattleScript_MoveEnd
BattleScript_TeatimeBuffer:
	moveendto MOVEEND_NEXT_TARGET
	jumpifnexttargetvalid BattleScript_TeatimeLoop
	moveendcase MOVEEND_CLEAR_BITS
	goto BattleScript_MoveEnd

BattleScript_EffectAxeKick::
	attackcanceler
	accuracycheck BattleScript_MoveMissedDoDamage, ACC_CURR_MOVE
	typecalc
	jumpifhalfword CMP_COMMON_BITS, gMoveResultFlags, MOVE_RESULT_DOESNT_AFFECT_FOE, BattleScript_MoveMissedDoDamage
	setmoveeffect MOVE_EFFECT_CONFUSE
	goto BattleScript_HitFromAtkString

BattleScript_EffectDarkVoid::
	jumpifspecies BS_ATTACKER, SPECIES_DARKRAI, BattleScript_EffectSleep
	goto BattleScript_PokemonCantUseTheMove

BattleScript_PokemonCantUseTheMove::
	attackstring
	ppreduce
	pause B_WAIT_TIME_SHORT
	printstring STRINGID_BUTPOKEMONCANTUSETHEMOVE
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_EffectDireClaw::
	setmoveeffect MOVE_EFFECT_DIRE_CLAW
	goto BattleScript_EffectHit

BattleScript_EffectCeaselessEdge::
	attackcanceler
	accuracycheck BattleScript_PrintMoveMissed, ACC_CURR_MOVE
	attackstring
	ppreduce
	call BattleScript_EffectDamage_Ret
	seteffectwithchance
	trysetspikes BattleScript_EffectCeaselessEdgeFailed
	printstring STRINGID_SPIKESSCATTERED
BattleScript_EffectCeaselessEdgeFailed:
	tryfaintmon BS_TARGET, FALSE, NULL
	moveendall
	end

BattleScript_EffectStoneAxe::
	attackcanceler
	accuracycheck BattleScript_PrintMoveMissed, ACC_CURR_MOVE
	attackstring
	ppreduce
	call BattleScript_EffectDamage_Ret
	seteffectwithchance
	setstealthrock BattleScript_EffectStoneAxeFailed
	printstring STRINGID_POINTEDSTONESFLOAT
BattleScript_EffectStoneAxeFailed:
	tryfaintmon BS_TARGET, FALSE, NULL
	moveendall
	end

BattleScript_EffectTripleArrows::
	setmoveeffect MOVE_EFFECT_TRIPLE_ARROWS
	goto BattleScript_EffectHit

BattleScript_EffectRecoil33SpeedUp::
	setmoveeffect MOVE_EFFECT_RECOIL_33_SPEED_UP | MOVE_EFFECT_AFFECTS_ATTACKER | MOVE_EFFECT_CERTAIN
	goto BattleScript_EffectHit

BattleScript_EffectExtremeEvoboost::
	attackcanceler
	attackstring
	ppreduce
	jumpifstat BS_ATTACKER, CMP_LESS_THAN, STAT_ATK, MAX_STAT_STAGE, BattleScript_ExtremeEvoboostAnim
	jumpifstat BS_ATTACKER, CMP_LESS_THAN, STAT_DEF, MAX_STAT_STAGE, BattleScript_ExtremeEvoboostAnim
	jumpifstat BS_ATTACKER, CMP_LESS_THAN, STAT_SPEED, MAX_STAT_STAGE, BattleScript_ExtremeEvoboostAnim
	jumpifstat BS_ATTACKER, CMP_LESS_THAN, STAT_SPATK, MAX_STAT_STAGE, BattleScript_ExtremeEvoboostAnim
	jumpifstat BS_ATTACKER, CMP_LESS_THAN, STAT_SPDEF, MAX_STAT_STAGE, BattleScript_ExtremeEvoboostAnim
	goto BattleScript_ButItFailed
BattleScript_ExtremeEvoboostAnim:
	attackanimation
	waitanimation
BattleScript_ExtremeEvoboostAtk::
	setbyte sSTAT_ANIM_PLAYED, FALSE
	playstatchangeanimation BS_ATTACKER, BIT_ATK | BIT_DEF | BIT_SPEED | BIT_SPATK | BIT_SPDEF, 0x0
	setstatchanger STAT_ATK, 2, FALSE
	statbuffchange MOVE_EFFECT_AFFECTS_ATTACKER | STAT_CHANGE_ALLOW_PTR, BattleScript_ExtremeEvoboostDef
	printfromtable gStatUpStringIds
	waitmessage B_WAIT_TIME_LONG
BattleScript_ExtremeEvoboostDef::
	setstatchanger STAT_DEF, 2, FALSE
	statbuffchange MOVE_EFFECT_AFFECTS_ATTACKER | STAT_CHANGE_ALLOW_PTR, BattleScript_ExtremeEvoboostSpeed
	printfromtable gStatUpStringIds
	waitmessage B_WAIT_TIME_LONG
BattleScript_ExtremeEvoboostSpeed::
	setstatchanger STAT_SPEED, 2, FALSE
	statbuffchange MOVE_EFFECT_AFFECTS_ATTACKER | STAT_CHANGE_ALLOW_PTR, BattleScript_ExtremeEvoboostSpAtk
	printfromtable gStatUpStringIds
	waitmessage B_WAIT_TIME_LONG
BattleScript_ExtremeEvoboostSpAtk::
	setstatchanger STAT_SPATK, 2, FALSE
	statbuffchange MOVE_EFFECT_AFFECTS_ATTACKER | STAT_CHANGE_ALLOW_PTR, BattleScript_ExtremeEvoboostSpDef
	printfromtable gStatUpStringIds
	waitmessage B_WAIT_TIME_LONG
BattleScript_ExtremeEvoboostSpDef::
	setstatchanger STAT_SPDEF, 2, FALSE
	statbuffchange MOVE_EFFECT_AFFECTS_ATTACKER | STAT_CHANGE_ALLOW_PTR, BattleScript_ExtremeEvoboostEnd
	printfromtable gStatUpStringIds
	waitmessage B_WAIT_TIME_LONG
BattleScript_ExtremeEvoboostEnd::
	goto BattleScript_MoveEnd

BattleScript_EffectTerrainHit:
	attackcanceler
	accuracycheck BattleScript_PrintMoveMissed, ACC_CURR_MOVE
	attackstring
	ppreduce
	call BattleScript_EffectDamage_Ret
	setterrain BattleScript_TryFaint
	playanimation BS_ATTACKER, B_ANIM_RESTORE_BG, NULL
	printfromtable gTerrainStringIds
BattleScript_TryFaint:
	tryfaintmon BS_TARGET, FALSE, NULL
	goto BattleScript_MoveEnd

BattleScript_EffectSpicyBreath::
	attackcanceler
	accuracycheck BattleScript_PrintMoveMissed, ACC_CURR_MOVE
	attackstring
	ppreduce
	call BattleScript_EffectDamage_Ret
	argumenttomoveeffect
	seteffectwithchance
	tryfaintmon BS_TARGET, FALSE, NULL
	moveendall
	end

BattleScript_EffectClangingScales::
	attackcanceler
	accuracycheck BattleScript_PrintMoveMissed, ACC_CURR_MOVE
	attackstring
	pause B_WAIT_TIME_LONG
	ppreduce
	setmoveeffect MOVE_EFFECT_DEF_MINUS_1 | MOVE_EFFECT_AFFECTS_ATTACKER | MOVE_EFFECT_CERTAIN
	goto BattleScript_HitFromCritCalc

BattleScript_EffectDarkBargain::
	attackcanceler
	attackstring
	ppreduce
	trycurseself BattleScript_ButItFailed
	attackanimation
	waitanimation
	call BattleScript_AllStatsUp
	goto BattleScript_MoveEnd

BattleScript_EffectBloodPact::
	attackcanceler
	attackstring
	ppreduce
	cuthalfhpraisestats BattleScript_ButItFailed
	jumpifstat BS_ATTACKER, CMP_LESS_THAN, STAT_ATK, MAX_STAT_STAGE, BattleScript_DarkBargainTryAttack
	jumpifstat BS_ATTACKER, CMP_LESS_THAN, STAT_SPATK, MAX_STAT_STAGE, BattleScript_DarkBargainTryAttack
	jumpifstat BS_ATTACKER, CMP_EQUAL, STAT_SPEED, MAX_STAT_STAGE, BattleScript_ButItFailed
BattleScript_DarkBargainTryAttack::
	orword gHitMarker, HITMARKER_IGNORE_SUBSTITUTE | HITMARKER_SKIP_DMG_TRACK | HITMARKER_PASSIVE_DAMAGE | HITMARKER_IGNORE_DISGUISE
	attackanimation
	waitanimation
	healthbarupdate BS_ATTACKER
	datahpupdate BS_ATTACKER
	setbyte sSTAT_ANIM_PLAYED, FALSE
	playstatchangeanimation BS_ATTACKER, BIT_SPATK | BIT_ATK | BIT_SPEED, STAT_CHANGE_BY_TWO
	setstatchanger STAT_ATK, 2, FALSE
	statbuffchange MOVE_EFFECT_AFFECTS_ATTACKER | STAT_CHANGE_ALLOW_PTR, BattleScript_DarkBargainTrySpAtk
	jumpifbyte CMP_EQUAL, cMULTISTRING_CHOOSER, B_MSG_STAT_WONT_INCREASE, BattleScript_DarkBargainTrySpAtk
	printfromtable gStatUpStringIds
	waitmessage B_WAIT_TIME_LONG
BattleScript_DarkBargainTrySpAtk:
	setstatchanger STAT_SPATK, 2, FALSE
	statbuffchange MOVE_EFFECT_AFFECTS_ATTACKER | STAT_CHANGE_ALLOW_PTR, BattleScript_DarkBargainTrySpeed
	jumpifbyte CMP_EQUAL, cMULTISTRING_CHOOSER, B_MSG_STAT_WONT_INCREASE, BattleScript_DarkBargainTrySpeed
	printfromtable gStatUpStringIds
	waitmessage B_WAIT_TIME_LONG
BattleScript_DarkBargainTrySpeed:
	setstatchanger STAT_SPEED, 2, FALSE
	statbuffchange MOVE_EFFECT_AFFECTS_ATTACKER | STAT_CHANGE_ALLOW_PTR, BattleScript_DarkBargainEnd
	jumpifbyte CMP_EQUAL, cMULTISTRING_CHOOSER, B_MSG_STAT_WONT_INCREASE, BattleScript_DarkBargainEnd
	printfromtable gStatUpStringIds
	waitmessage B_WAIT_TIME_LONG
BattleScript_DarkBargainEnd:
	goto BattleScript_MoveEnd

BattleScript_EffectRockPolish::
	attackcanceler
	attackstring
	ppreduce
	jumpifstat BS_ATTACKER, CMP_LESS_THAN, STAT_SPEED, MAX_STAT_STAGE, BattleScript_RockPolishDoMoveAnim
	jumpifstat BS_ATTACKER, CMP_EQUAL, STAT_SPDEF, MAX_STAT_STAGE, BattleScript_CantRaiseMultipleStats
BattleScript_RockPolishDoMoveAnim::
	setbyte sSTAT_ANIM_PLAYED, FALSE
	playstatchangeanimation BS_ATTACKER, BIT_SPEED | BIT_SPDEF, 0
	setstatchanger STAT_SPEED, 2, FALSE
	statbuffchange MOVE_EFFECT_AFFECTS_ATTACKER | STAT_CHANGE_ALLOW_PTR, BattleScript_RockPolishTrySpDef
	jumpifbyte CMP_EQUAL, cMULTISTRING_CHOOSER, B_MSG_STAT_WONT_INCREASE, BattleScript_RockPolishTrySpDef
	printfromtable gStatUpStringIds
	waitmessage B_WAIT_TIME_LONG
BattleScript_RockPolishTrySpDef:
	setstatchanger STAT_SPDEF, 1, FALSE
	statbuffchange MOVE_EFFECT_AFFECTS_ATTACKER | STAT_CHANGE_ALLOW_PTR, BattleScript_RockPolishEnd
	jumpifbyte CMP_EQUAL, cMULTISTRING_CHOOSER, B_MSG_STAT_WONT_INCREASE, BattleScript_RockPolishEnd
	printfromtable gStatUpStringIds
	waitmessage B_WAIT_TIME_LONG
BattleScript_RockPolishEnd:
	goto BattleScript_MoveEnd

BattleScript_EffectThunderstorm::
	attackcanceler
	attackstring
	ppreduce
	trysetthunderstorm BattleScript_ButItFailed
	attackanimation
	waitanimation
	printfromtable gThunderstormStringIds
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_EffectPhantomForest::
	attackcanceler
	attackstring
	ppreduce
	trysetphantomforest BattleScript_ButItFailed
	attackanimation
	waitanimation
	printstring STRINGID_PHANTOMFOREST
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_EffectRevolvingRuin::
	attackcanceler
	accuracycheck BattleScript_PrintMoveMissed, ACC_CURR_MOVE
	attackstring
	ppreduce
	call BattleScript_EffectDamage_Ret
	seteffectwithchance
	tryfaintmon BS_TARGET, FALSE, NULL
	trysetrevolvingruin BattleScript_EffectRevolvingRuinEnd
	printstring STRINGID_PKMNFIRERING
	waitmessage B_WAIT_TIME_LONG
BattleScript_EffectRevolvingRuinEnd:
	moveendall
	end

BattleScript_EffectRubbleRouser::
	attackcanceler
	accuracycheck BattleScript_PrintMoveMissed, ACC_CURR_MOVE
	attackstring
	ppreduce
	call BattleScript_EffectDamage_Ret
	seteffectwithchance
	tryfaintmon BS_TARGET, FALSE, NULL
	trysetrubblerouser BattleScript_EffectRubbleRouserEnd
	playmoveanimation BS_ATTACKER, MOVE_PSYSHIELD
	waitanimation
	printstring STRINGID_PKMNCREATEDASHIELD
	waitmessage B_WAIT_TIME_LONG
	healthbarupdate BS_ATTACKER
	datahpupdate BS_ATTACKER
BattleScript_EffectRubbleRouserEnd:
	moveendall
	end

BattleScript_EffectSnowGlobe::
	attackcanceler
	accuracycheck BattleScript_PrintMoveMissed, ACC_CURR_MOVE
	attackstring
	ppreduce
	call BattleScript_EffectDamage_Ret
	setmoveeffect MOVE_EFFECT_SPD_MINUS_1
	seteffectwithchance
	setmoveeffect MOVE_EFFECT_FROSTBITE
	seteffectwithchance
	tryfaintmon BS_TARGET, FALSE, NULL
	moveendall
	end

BattleScript_EffectDamageMissingHP::
	setmoveeffect MOVE_EFFECT_DAMAGE_MISSING_HP | MOVE_EFFECT_CERTAIN
	goto BattleScript_EffectHit

BattleScript_EffectFancifulFireworks::
	attackcanceler
	accuracycheck BattleScript_PrintMoveMissed, ACC_CURR_MOVE
	attackstring
	ppreduce
	call BattleScript_EffectDamage_Ret
	seteffectwithchance
	trysetfancifulfireworks BattleScript_EffectFancifulFireworksEnd
	printstring STRINGID_PKMNFIREWORKS
	waitmessage B_WAIT_TIME_LONG
BattleScript_EffectFancifulFireworksEnd:
	tryfaintmon BS_TARGET, FALSE, NULL
	moveendall
	end

BattleScript_EffectAquaTornado:
	attackcanceler
	accuracycheck BattleScript_PrintMoveMissed, ACC_CURR_MOVE
	attackstring
	ppreduce
	call BattleScript_EffectDamage_Ret
	tryfaintmon BS_TARGET, FALSE, NULL
	jumpifhalfword CMP_COMMON_BITS, gBattleWeather, WEATHER_SUN_PRIMAL, BattleScript_AquaTornadoNoRain
	jumpifhalfword CMP_COMMON_BITS, gBattleWeather, WEATHER_RAIN_PRIMAL, BattleScript_AquaTornadoNoRain
	jumpifhalfword CMP_COMMON_BITS, gBattleWeather, WEATHER_STRONG_WINDS, BattleScript_AquaTornadoNoRain
	setrain
	printfromtable gMoveWeatherChangeStringIds
	waitmessage B_WAIT_TIME_LONG
	call BattleScript_WeatherFormChanges
BattleScript_AquaTornadoNoRain:
	moveendall
	end

BattleScript_EffectSacredFire:
	jumpiftargetally BattleScript_EffectSacredFireHealAlly
	setmoveeffect MOVE_EFFECT_BURN
	goto BattleScript_EffectHit

BattleScript_EffectSacredFireHealAlly:
	attackcanceler
	attackstring
	ppreduce
	accuracycheck BattleScript_ButItFailed, NO_ACC_CALC_CHECK_LOCK_ON
	jumpifsubstituteblocks BattleScript_ButItFailed
	tryhealpulse BS_TARGET, BattleScript_AlreadyAtFullHp
	healstatuscondition BS_TARGET, 1
	attackanimation
	waitanimation
	healthbarupdate BS_TARGET
	datahpupdate BS_TARGET
	updatestatusicon BS_TARGET
	printstring STRINGID_PKMNREGAINEDHEALTH
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_EffectConfusion:
	setmoveeffect MOVE_EFFECT_CONFUSION | MOVE_EFFECT_CERTAIN
	goto BattleScript_EffectHit

BattleScript_EffectInkJet:
	attackcanceler
	attackstring
	ppreduce
	jumpifstat BS_TARGET, CMP_EQUAL, STAT_ACC, MIN_STAT_STAGE, BattleScript_EffectInkJetSwitch
BattleScript_EffectInkJetTryAtk:
	accuracycheck BattleScript_PrintMoveMissed, ACC_CURR_MOVE	
	attackanimation
	waitanimation
	setstatchanger STAT_ACC, 1, TRUE
	statbuffchange STAT_CHANGE_ALLOW_PTR, BattleScript_EffectInkJetSwitch
	jumpifbyte CMP_EQUAL, cMULTISTRING_CHOOSER, B_MSG_STAT_WONT_DECREASE, BattleScript_EffectInkJetSwitch
	jumpifbyte CMP_EQUAL, cMULTISTRING_CHOOSER, B_MSG_STAT_FELL_EMPTY, BattleScript_EffectInkJetSwitch
	setgraphicalstatchangevalues
	playanimation BS_TARGET, B_ANIM_STATS_CHANGE, sB_ANIM_ARG1
	printfromtable gStatDownStringIds
	waitmessage B_WAIT_TIME_LONG
BattleScript_EffectInkJetSwitch:	
	moveendall
	jumpifbattletype BATTLE_TYPE_ARENA, BattleScript_InkJetEnd
	jumpifcantswitch SWITCH_IGNORE_ESCAPE_PREVENTION | BS_ATTACKER, BattleScript_InkJetEnd
	openpartyscreen BS_ATTACKER, BattleScript_InkJetEnd
	switchoutabilitiesorinnates BS_ATTACKER, 0
	switchoutabilitiesorinnates BS_ATTACKER, 1
	switchoutabilitiesorinnates BS_ATTACKER, 2
	switchoutabilitiesorinnates BS_ATTACKER, 3
	swithchoutrevolvingruin BS_ATTACKER
	waitstate
	switchhandleorder BS_ATTACKER, 2
	returntoball BS_ATTACKER
	getswitchedmondata BS_ATTACKER
	switchindataupdate BS_ATTACKER
	hpthresholds BS_ATTACKER
	trytoclearprimalweather
	printstring STRINGID_EMPTYSTRING3
	waitmessage 1
	printstring STRINGID_SWITCHINMON
	switchinanim BS_ATTACKER, TRUE
	waitstate
	switchineffects BS_ATTACKER
BattleScript_InkJetEnd:
	end

BattleScript_EffectWithdraw:
	attackcanceler
	attackstring
	ppreduce
	jumpifstat BS_ATTACKER, CMP_LESS_THAN, STAT_DEF, MAX_STAT_STAGE BattleScript_WithdrawTryDef
	jumpifstat BS_ATTACKER, CMP_LESS_THAN, STAT_SPDEF, MAX_STAT_STAGE BattleScript_WithdrawTryDef
	jumpifstat BS_ATTACKER, CMP_GREATER_THAN, STAT_ATK, MIN_STAT_STAGE, BattleScript_WithdrawTryDef
	jumpifstat BS_ATTACKER, CMP_GREATER_THAN, STAT_SPATK, MIN_STAT_STAGE, BattleScript_WithdrawTryDef
	jumpifstat BS_ATTACKER, CMP_EQUAL, STAT_SPEED, MIN_STAT_STAGE, BattleScript_ButItFailed
BattleScript_WithdrawTryDef::
	attackanimation
	waitanimation
	setbyte sSTAT_ANIM_PLAYED, FALSE
	playstatchangeanimation BS_ATTACKER, BIT_DEF | BIT_SPDEF, STAT_CHANGE_BY_TWO
	setstatchanger STAT_DEF, 2, FALSE
	statbuffchange MOVE_EFFECT_AFFECTS_ATTACKER | STAT_CHANGE_ALLOW_PTR, BattleScript_WithdrawTrySpDef
	jumpifbyte CMP_EQUAL, cMULTISTRING_CHOOSER, B_MSG_STAT_WONT_INCREASE, BattleScript_WithdrawTrySpDef
	printfromtable gStatUpStringIds
	waitmessage B_WAIT_TIME_LONG
BattleScript_WithdrawTrySpDef:
	setstatchanger STAT_SPDEF, 2, FALSE
	statbuffchange MOVE_EFFECT_AFFECTS_ATTACKER | STAT_CHANGE_ALLOW_PTR, BattleScript_WithdrawTryAttack
	jumpifbyte CMP_EQUAL, cMULTISTRING_CHOOSER, B_MSG_STAT_WONT_INCREASE, BattleScript_WithdrawTryAttack
	printfromtable gStatUpStringIds
	waitmessage B_WAIT_TIME_LONG
BattleScript_WithdrawTryAttack:
	setbyte sSTAT_ANIM_PLAYED, FALSE
	playstatchangeanimation BS_ATTACKER, BIT_SPATK | BIT_ATK | BIT_SPEED, STAT_CHANGE_NEGATIVE | STAT_CHANGE_CANT_PREVENT
	setstatchanger STAT_ATK, 1, TRUE
	statbuffchange MOVE_EFFECT_AFFECTS_ATTACKER | STAT_CHANGE_ALLOW_PTR | MOVE_EFFECT_CERTAIN, BattleScript_WithdrawTrySpAtk
	jumpifbyte CMP_EQUAL, cMULTISTRING_CHOOSER, B_MSG_STAT_WONT_INCREASE, BattleScript_WithdrawTrySpAtk
	printfromtable gStatUpStringIds
	waitmessage B_WAIT_TIME_LONG
BattleScript_WithdrawTrySpAtk:
	setstatchanger STAT_SPATK, 1, TRUE
	statbuffchange MOVE_EFFECT_AFFECTS_ATTACKER | STAT_CHANGE_ALLOW_PTR | MOVE_EFFECT_CERTAIN, BattleScript_WithdrawTrySpeed
	jumpifbyte CMP_EQUAL, cMULTISTRING_CHOOSER, B_MSG_STAT_WONT_INCREASE, BattleScript_WithdrawTrySpeed
	printfromtable gStatUpStringIds
	waitmessage B_WAIT_TIME_LONG
BattleScript_WithdrawTrySpeed:
	setstatchanger STAT_SPEED, 1, TRUE
	statbuffchange MOVE_EFFECT_AFFECTS_ATTACKER | STAT_CHANGE_ALLOW_PTR | MOVE_EFFECT_CERTAIN, BattleScript_WithdrawEnd
	jumpifbyte CMP_EQUAL, cMULTISTRING_CHOOSER, B_MSG_STAT_WONT_INCREASE, BattleScript_WithdrawEnd
	printfromtable gStatUpStringIds
	waitmessage B_WAIT_TIME_LONG
BattleScript_WithdrawEnd:
	goto BattleScript_MoveEnd

BattleScript_EffectBarrageBlow:
	attackcanceler
	accuracycheck BattleScript_PrintMoveMissed, ACC_CURR_MOVE
	attackstring
	ppreduce
	call BattleScript_EffectDamage_Ret
	setmoveeffect MOVE_EFFECT_DEF_SPDEF_DOWN | MOVE_EFFECT_AFFECTS_ATTACKER | MOVE_EFFECT_CERTAIN
	seteffectwithchance
	setmoveeffect MOVE_EFFECT_ATK_PLUS_1 | MOVE_EFFECT_AFFECTS_ATTACKER | MOVE_EFFECT_CERTAIN
	seteffectwithchance
	tryfaintmon BS_TARGET, FALSE, NULL
	moveendall
	end

BattleScript_EffectRingsUnbound:
	attackcanceler
	attackstring
	ppreduce
	jumpifspecies BS_ATTACKER, SPECIES_HOOPA, BattleScript_EffectRingsUnboundContinue
	printstring STRINGID_BUTPOKEMONCANTUSETHEMOVE
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd
BattleScript_EffectRingsUnboundContinue:
	attackanimation
	waitanimation
	changespeciesto BS_ATTACKER SPECIES_HOOPA_UNBOUND
	handleformchange BS_ATTACKER, 0
	handleformchange BS_ATTACKER, 1
	playanimation BS_ATTACKER, B_ANIM_FORM_CHANGE, NULL
	waitanimation
	copybyte sBATTLER, gBattlerAttacker
	printstring STRINGID_PKMNTRANSFORMED
	waitmessage B_WAIT_TIME_LONG
	handleformchange BS_ATTACKER, 2
	handleformchange BS_ATTACKER, 3
	jumpifstat BS_ATTACKER, CMP_LESS_THAN, STAT_ATK, MAX_STAT_STAGE, BattleScript_EffectRingsUnboundUpAtk
	jumpifstat BS_ATTACKER, CMP_LESS_THAN, STAT_SPEED, MAX_STAT_STAGE, BattleScript_EffectRingsUnboundUpAtk
	jumpifstat BS_ATTACKER, CMP_LESS_THAN, STAT_SPATK, MAX_STAT_STAGE, BattleScript_EffectRingsUnboundUpAtk
	jumpifstat BS_ATTACKER, CMP_EQUAL, STAT_SPDEF, MAX_STAT_STAGE, BattleScript_MoveEnd
BattleScript_EffectRingsUnboundUpAtk::
	setbyte sSTAT_ANIM_PLAYED, FALSE
	playstatchangeanimation BS_ATTACKER, BIT_ATK | BIT_SPEED | BIT_SPATK | BIT_SPDEF, 0
	setstatchanger STAT_ATK, 1, FALSE
	statbuffchange MOVE_EFFECT_AFFECTS_ATTACKER | STAT_CHANGE_ALLOW_PTR, BattleScript_EffectRingsUnboundUpSpeed
	printfromtable gStatUpStringIds
	waitmessage B_WAIT_TIME_LONG
BattleScript_EffectRingsUnboundUpSpeed::
	setstatchanger STAT_SPEED, 1, FALSE
	statbuffchange MOVE_EFFECT_AFFECTS_ATTACKER | STAT_CHANGE_ALLOW_PTR, BattleScript_EffectRingsUnboundUpSpAtk
	printfromtable gStatUpStringIds
	waitmessage B_WAIT_TIME_LONG
BattleScript_EffectRingsUnboundUpSpAtk::
	setstatchanger STAT_SPATK, 1, FALSE
	statbuffchange MOVE_EFFECT_AFFECTS_ATTACKER | STAT_CHANGE_ALLOW_PTR, BattleScript_EffectRingsUnboundUpSpDef
	printfromtable gStatUpStringIds
	waitmessage B_WAIT_TIME_LONG
BattleScript_EffectRingsUnboundUpSpDef::
	setstatchanger STAT_SPDEF, 1, FALSE
	statbuffchange MOVE_EFFECT_AFFECTS_ATTACKER | STAT_CHANGE_ALLOW_PTR, BattleScript_MoveEnd
	printfromtable gStatUpStringIds
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_EffectRecoil33SpeedUpWithStatus:
	setmoveeffect MOVE_EFFECT_RECOIL_33_SPEED_UP_WITH_STATUS | MOVE_EFFECT_AFFECTS_ATTACKER | MOVE_EFFECT_CERTAIN
	goto BattleScript_EffectHit

BattleScript_EffectBlissAssistance:
	goto BattleScript_EffectHit

BattleScript_EffectBerryBellyFlop:
	attackcanceler
	tryeatoranberry BS_ATTACKER
	setbyte sBERRY_OVERRIDE, TRUE   @ override the requirements for eating berries
	savetarget
	consumeberry BS_ATTACKER, FALSE  @ consume the berry, but don't replace gLastUsedItem
	setbyte sBERRY_OVERRIDE, FALSE
	restoretarget
	goto BattleScript_HitFromAccCheck

BattleScript_EffectCoinShower::
	attackcanceler
	accuracycheck BattleScript_PrintMoveMissed, ACC_CURR_MOVE
	attackstring
	ppreduce
	call BattleScript_EffectDamage_Ret
	setmoveeffect MOVE_EFFECT_PAYDAY | MOVE_EFFECT_CERTAIN
	seteffectwithchance
	setmoveeffect MOVE_EFFECT_FLINCH
	seteffectwithchance
	tryfaintmon BS_TARGET, FALSE, NULL
	goto BattleScript_MoveEnd

BattleScript_EffectChristmasSpirit:
	attackcanceler
	attackstring
	ppreduce
	jumpifhalfword CMP_COMMON_BITS, gBattleWeather, WEATHER_SUN_PRIMAL, BattleScript_EffectChristmasSpiritHailFailedTryTerrain
	jumpifhalfword CMP_COMMON_BITS, gBattleWeather, WEATHER_RAIN_PRIMAL, BattleScript_EffectChristmasSpiritHailFailedTryTerrain
	jumpifhalfword CMP_COMMON_BITS, gBattleWeather, WEATHER_STRONG_WINDS, BattleScript_EffectChristmasSpiritHailFailedTryTerrain
	sethail
	attackanimation
	waitanimation
	printfromtable gMoveWeatherChangeStringIds
	waitmessage B_WAIT_TIME_LONG
	call BattleScript_WeatherFormChanges
BattleScript_EffectChristmasSpiritHailSucessTryTerrain:
	setterrain BattleScript_MoveEnd
	printfromtable gTerrainStringIds
	waitmessage B_WAIT_TIME_LONG
	playanimation BS_ATTACKER, B_ANIM_RESTORE_BG, NULL
	call BattleScript_TerrainFormChanges
	call BattleScript_TerrainSeedLoop
	goto BattleScript_MoveEnd

BattleScript_EffectChristmasSpiritHailFailedTryTerrain:
	setterrain BattleScript_ButItFailed
	attackanimation
	waitanimation
	printfromtable gTerrainStringIds
	waitmessage B_WAIT_TIME_LONG
	playanimation BS_ATTACKER, B_ANIM_RESTORE_BG, NULL
	call BattleScript_TerrainFormChanges
	call BattleScript_TerrainSeedLoop
	goto BattleScript_MoveEnd

BattleScript_EffectRoseWhip:
	setmoveeffect MOVE_EFFECT_DEF_MINUS_1
	attackcanceler
	accuracycheck BattleScript_PrintMoveMissed, ACC_CURR_MOVE
	attackstring
	ppreduce
	call BattleScript_EffectDamage_Ret
	seteffectwithchance
	trysetrosewhip BS_TARGET, BattleScript_EffectRoseWhipEnd
	seteffectwithchance
BattleScript_EffectRoseWhipEnd:
	tryfaintmon BS_TARGET, FALSE, NULL
	moveendall
	end

BattleScript_EffectWarmUp:
	attackcanceler
	attackstring
	ppreduce
	tryhealhalfhealth BattleScript_AlreadyAtFullHp, BS_ATTACKER
	attackanimation
	waitanimation
	orword gHitMarker, HITMARKER_IGNORE_SUBSTITUTE
	healthbarupdate BS_ATTACKER
	datahpupdate BS_ATTACKER
	printstring STRINGID_PKMNREGAINEDHEALTH
	waitmessage B_WAIT_TIME_LONG
	jumpifabilityorinnate BS_TARGET, ABILITY_MULTITYPE, BattleScript_MoveEnd
	jumpifabilityorinnate BS_TARGET, ABILITY_RKS_SYSTEM, BattleScript_MoveEnd
	trysetthirdtype BS_TARGET, BattleScript_MoveEnd
	printstring STRINGID_THIRDTYPEADDED
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_EffectFling:
	jumpifstatus3 BS_ATTACKER, STATUS3_EMBARGO, BattleScript_FailedFromAtkString
	jumpifword CMP_COMMON_BITS, gFieldStatuses, STATUS_FIELD_MAGIC_ROOM, BattleScript_FailedFromAtkString
	jumpifcantfling BS_ATTACKER, BattleScript_FailedFromAtkString, BattleScript_EffectFlingItem0, BattleScript_EffectFlingItem1, BattleScript_EffectFlingItem2
	goto BattleScript_FailedFromAtkString

BattleScript_EffectFlingItem0:
	setlastuseditem BS_ATTACKER, 0
	removeitem BS_ATTACKER, 0
	call BattleScript_EffectFlingDamageStep
	jumpiflastuseditemholdeffect BS_ATTACKER, HOLD_EFFECT_FLAME_ORB, BattleScript_FlingFlameOrb
	jumpiflastuseditemholdeffect BS_ATTACKER, HOLD_EFFECT_FROST_ORB, BattleScript_FlingFrostOrb
	jumpiflastuseditemholdeffect BS_ATTACKER, HOLD_EFFECT_FLINCH, BattleScript_FlingFlinch
	jumpiflastuseditemholdeffect BS_ATTACKER, HOLD_EFFECT_TOXIC_ORB, BattleScript_FlingToxicOrb
	jumpiflastuseditemholdeffect BS_ATTACKER, HOLD_EFFECT_BIG_ROOT, BattleScript_FlingBigRoot
	jumpiflastuseditemholdeffect BS_ATTACKER, HOLD_EFFECT_PARALYZE_ORB, BattleScript_FlingLightBall
	jumpiflastuseditemholdeffect BS_ATTACKER, HOLD_EFFECT_CONFUSE_ORB, BattleScript_FlingConfuseOrb
	jumpiflastuseditemholdeffect BS_ATTACKER, HOLD_EFFECT_MUSHROOM, BattleScript_FlingConfuseOrb @Tiny and Big Mushroom
	jumpiflastuseditemholdeffect BS_ATTACKER, HOLD_EFFECT_IRON_BALL, BattleScript_FlingIronBall
	goto BattleScript_FlingEnd

BattleScript_EffectFlingItem1:
	setlastuseditem BS_ATTACKER, 1
	removeitem BS_ATTACKER, 1
	call BattleScript_EffectFlingDamageStep
	jumpiflastuseditemberry BattleScript_EffectFlingConsumeBerry
	jumpiflastuseditemholdeffect BS_ATTACKER, HOLD_EFFECT_SNOWBALL, BattleScript_FlingSnowball
	jumpiflastuseditemholdeffect BS_ATTACKER, HOLD_EFFECT_MENTAL_HERB, BattleScript_FlingMentalHerb
	jumpiflastuseditemholdeffect BS_ATTACKER, HOLD_EFFECT_RESTORE_STATS, BattleScript_FlingWhiteHerb
	goto BattleScript_FlingEnd

BattleScript_EffectFlingItem2:
	setlastuseditem BS_ATTACKER, 2
	removeitem BS_ATTACKER, 2
	call BattleScript_EffectFlingDamageStep
	jumpiflastuseditemholdeffect BS_ATTACKER, HOLD_EFFECT_LIGHT_BALL, BattleScript_FlingLightBall
	jumpiflastuseditemholdeffect BS_ATTACKER, HOLD_EFFECT_POISON_POWER, BattleScript_FlingPoisonBarb
	jumpiflastuseditemholdeffect BS_ATTACKER, HOLD_EFFECT_GRASS_POWER, BattleScript_FlingMiracleSeed @Rose Incense
	jumpiflastuseditemholdeffect BS_ATTACKER, HOLD_EFFECT_GROUND_POWER, BattleScript_FlingSoftSand
	jumpiflastuseditemholdeffect BS_ATTACKER, HOLD_EFFECT_BUG_POWER, BattleScript_FlingSoftSand @silver Powder
	jumpiflastuseditemholdeffect BS_ATTACKER, HOLD_EFFECT_CAN_ALWAYS_RUN, BattleScript_FlingSoftSand @Smoke Ball
	jumpiflastuseditemholdeffect BS_ATTACKER, HOLD_EFFECT_ROCK_POWER, BattleScript_FlingHardStone
	goto BattleScript_FlingEnd

BattleScript_EffectFlingDamageStep:
	attackcanceler
	accuracycheck BattleScript_PrintMoveMissed, ACC_CURR_MOVE
	attackstring
	pause B_WAIT_TIME_SHORT
	printstring STRINGID_PKMNFLUNG
	waitmessage B_WAIT_TIME_SHORT
	ppreduce
	critcalc
	damagecalc
	adjustdamage
	attackanimation
	waitanimation
	effectivenesssound
	healthbarupdate BS_TARGET
	datahpupdate BS_TARGET
	critmessage
	waitmessage B_WAIT_TIME_MED
	resultmessage
	waitmessage B_WAIT_TIME_MED
	return

BattleScript_EffectFlingConsumeBerry:
	savebattleritem BS_TARGET, 1
	battleritemtolastuseditem BS_TARGET
	setbyte sBERRY_OVERRIDE, TRUE @ override the requirements for eating berries
	orword gHitMarker, HITMARKER_DISABLE_ANIMATION
	consumeberry BS_TARGET, TRUE
	bicword gHitMarker, HITMARKER_DISABLE_ANIMATION
	setbyte sBERRY_OVERRIDE, FALSE
	restorebattleritem BS_TARGET, 1
BattleScript_FlingEnd:
	tryfaintmon BS_TARGET, FALSE, NULL
	goto BattleScript_MoveEnd
BattleScript_FlingSnowball:
	setmoveeffect MOVE_EFFECT_FROSTBITE | MOVE_EFFECT_CERTAIN
	seteffectwithchance
	goto BattleScript_FlingEnd
BattleScript_FlingFlameOrb:
	setmoveeffect MOVE_EFFECT_BURN | MOVE_EFFECT_CERTAIN
	seteffectwithchance
	goto BattleScript_FlingEnd
BattleScript_FlingFrostOrb:
	setmoveeffect MOVE_EFFECT_FROSTBITE | MOVE_EFFECT_CERTAIN
	seteffectwithchance
	goto BattleScript_FlingEnd
BattleScript_FlingFlinch:
	setmoveeffect MOVE_EFFECT_FLINCH | MOVE_EFFECT_CERTAIN
	seteffectwithchance
	goto BattleScript_FlingEnd
BattleScript_FlingLightBall:
	setmoveeffect MOVE_EFFECT_PARALYSIS | MOVE_EFFECT_CERTAIN
	seteffectwithchance
	goto BattleScript_FlingEnd
BattleScript_FlingConfuseOrb:
	setmoveeffect MOVE_EFFECT_CONFUSE | MOVE_EFFECT_CERTAIN
	seteffectwithchance
	goto BattleScript_FlingEnd
BattleScript_FlingMentalHerb:
	curecertainstatuses BS_TARGET
	savetarget
	copybyte gBattlerAttacker, gBattlerTarget
	playanimation BS_ATTACKER, B_ANIM_HELD_ITEM_EFFECT, NULL
	printfromtable gMentalHerbCureStringIds
	waitmessage B_WAIT_TIME_LONG
	updatestatusicon BS_ATTACKER
	restoretarget
	goto BattleScript_FlingEnd
BattleScript_FlingPoisonBarb:
	setmoveeffect MOVE_EFFECT_POISON | MOVE_EFFECT_CERTAIN
	seteffectwithchance
	goto BattleScript_FlingEnd
BattleScript_FlingToxicOrb:
	setmoveeffect MOVE_EFFECT_TOXIC | MOVE_EFFECT_CERTAIN
	seteffectwithchance
	goto BattleScript_FlingEnd
BattleScript_FlingWhiteHerb:
	tryresetnegativestatstages BS_TARGET
	swapattackerwithtarget
	printstring STRINGID_PKMNSTATUSNORMAL
	waitmessage B_WAIT_TIME_MED
	swapattackerwithtarget
	goto BattleScript_FlingEnd
BattleScript_FlingBigRoot:
	setmoveeffect MOVE_EFFECT_ABSORB | MOVE_EFFECT_CERTAIN
	setbyte cMULTISTRING_CHOOSER, B_MSG_ABSORB
	seteffectwithchance
	goto BattleScript_FlingEnd
BattleScript_FlingMiracleSeed:
	jumpifstatus3 BS_TARGET, STATUS3_LEECHSEED, BattleScript_FlingEnd
	jumpifhasnohp BS_TARGET, BattleScript_FlingEnd
	setseeded
	printfromtable gLeechSeedStringIds
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_FlingEnd
BattleScript_FlingSoftSand:
	setmoveeffect MOVE_EFFECT_ACC_MINUS_2 | MOVE_EFFECT_CERTAIN
	seteffectwithchance
	goto BattleScript_FlingEnd
BattleScript_FlingHardStone:
	setmoveeffect MOVE_EFFECT_SMACK_DOWN | MOVE_EFFECT_CERTAIN
	seteffectwithchance
	goto BattleScript_FlingEnd
BattleScript_FlingIronBall:
	setmoveeffect MOVE_EFFECT_SPD_MINUS_2 | MOVE_EFFECT_CERTAIN
	seteffectwithchance
	goto BattleScript_FlingEnd

BattleScript_EffectSteelBeam::
	attackcanceler
	attackstring
	ppreduce
	accuracycheck BattleScript_SteelBeamMiss, ACC_CURR_MOVE
	call BattleScript_EffectDamage_Ret
	seteffectwithchance
	jumpifmagicguarded BS_ATTACKER, BattleScript_SteelBeamAfterSelfDamage
	call BattleScript_SteelBeamSelfDamage
BattleScript_SteelBeamAfterSelfDamage::
	waitstate
	tryfaintmon BS_ATTACKER, FALSE, NULL
	tryfaintmon BS_TARGET, FALSE, NULL
	goto BattleScript_MoveEnd
BattleScript_SteelBeamMiss::
	pause B_WAIT_TIME_SHORT
	effectivenesssound
	resultmessage
	waitmessage B_WAIT_TIME_LONG
	jumpifmagicguarded BS_ATTACKER, BattleScript_MoveEnd
	bichalfword gMoveResultFlags, MOVE_RESULT_MISSED
	call BattleScript_SteelBeamSelfDamage
	orhalfword gMoveResultFlags, MOVE_RESULT_MISSED
	goto BattleScript_SteelBeamAfterSelfDamage

BattleScript_SteelBeamSelfDamage::
	dmg_1_2_attackerhp
	healthbarupdate BS_ATTACKER
	datahpupdate BS_ATTACKER
	return

BattleScript_EffectCourtChange::
	attackcanceler
	accuracycheck BattleScript_PrintMoveMissed, ACC_CURR_MOVE
	attackstring
	ppreduce
	swapsidestatuses
	attackanimation
	waitanimation
	printstring STRINGID_COURTCHANGE
	waitmessage 0x40
	goto BattleScript_MoveEnd

BattleScript_BeakBlastSetUp::
	setbeakblast BS_ATTACKER
	printstring STRINGID_EMPTYSTRING3
	waitmessage 0x1
	playanimation BS_ATTACKER, B_ANIM_BEAK_BLAST_SETUP, NULL	
	printstring STRINGID_HEATUPBEAK
	waitmessage 0x40
	end2

BattleScript_BeakBlastBurn::
	setbyte cMULTISTRING_CHOOSER, 0
	copybyte gEffectBattler, gBattlerAttacker
	statusanimation BS_EFFECT_BATTLER
	printfromtable gGotBurnedStringIds
	waitmessage B_WAIT_TIME_LONG
	updatestatusicon BS_ATTACKER
	waitstate
	return
	
BattleScript_EffectCorrosiveGas::
	attackcanceler
	accuracycheck BattleScript_PrintMoveMissed, NO_ACC_CALC_CHECK_LOCK_ON
	attackstring 
	ppreduce
	jumpifstatus2 BS_TARGET, STATUS2_SUBSTITUTION_ANY, BattleScript_PrintMoveMissed
	trysetcorrosivegas BS_TARGET, BattleScript_ButItFailed
	attackanimation
	waitanimation
	printstring STRINGID_ITEMMELTED
	waitmessage 0x40
	goto BattleScript_MoveEnd

BattleScript_MeltedItem::
	printstring STRINGID_ITEMMELTED
	waitmessage 0x40
	return

BattleScript_FocusPunchSetUp::
	printstring STRINGID_EMPTYSTRING3
	waitmessage 1
	playanimation BS_ATTACKER, B_ANIM_FOCUS_PUNCH_SETUP, NULL
	printstring STRINGID_PKMNTIGHTENINGFOCUS
	waitmessage B_WAIT_TIME_LONG
	end2

BattleScript_EffectFocusPunch::
	attackcanceler
	jumpifnodamage BattleScript_HitFromAccCheck
	ppreduce
	printstring STRINGID_PKMNLOSTFOCUS
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_ShellTrapSetUp::
	printstring STRINGID_EMPTYSTRING3
	waitmessage 0x1
	playanimation BS_ATTACKER, B_ANIM_SHELL_TRAP_SETUP, NULL	
	printstring STRINGID_PREPARESHELLTRAP
	waitmessage B_WAIT_TIME_LONG
	end2

BattleScript_EffectShellTrap::
	attackcanceler
	jumpifshelltrap BS_ATTACKER, BattleScript_HitFromAccCheck
	jumpifword CMP_COMMON_BITS, gHitMarker, HITMARKER_NO_ATTACKSTRING | HITMARKER_NO_PPDEDUCT, BattleScript_MoveEnd
	ppreduce
	printstring STRINGID_SHELLTRAPDIDNTWORK
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_EffectClangorousSoul:
	attackcanceler
	attackstring
	ppreduce
	cutonethirdhpraisestats BattleScript_ButItFailed
	orword gHitMarker, HITMARKER_IGNORE_SUBSTITUTE | HITMARKER_SKIP_DMG_TRACK | HITMARKER_PASSIVE_DAMAGE | HITMARKER_IGNORE_DISGUISE
	attackanimation
	waitanimation
	healthbarupdate BS_ATTACKER
	datahpupdate BS_ATTACKER
	call BattleScript_AllStatsUp
	goto BattleScript_MoveEnd

BattleScript_EffectOctolock:
	attackcanceler
	jumpifsubstituteblocks BattleScript_FailedFromAtkString
	accuracycheck BattleScript_PrintMoveMissed, ACC_CURR_MOVE
	attackstring
	ppreduce
	setoctolock BS_TARGET, BattleScript_ButItFailed
	attackanimation
	waitanimation
	printstring STRINGID_CANTESCAPEBECAUSEOFCURRENTMOVE
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_OctolockEndTurn::
	setbyte sSTAT_ANIM_PLAYED, FALSE
	jumpifstat BS_TARGET, CMP_GREATER_THAN, STAT_DEF, MIN_STAT_STAGE, BattleScript_OctolockLowerDef
	jumpifstat BS_TARGET, CMP_GREATER_THAN, STAT_SPDEF, MIN_STAT_STAGE, BattleScript_OctolockTryLowerSpDef
	goto BattleScript_OctolockEnd2
BattleScript_OctolockLowerDef:
	playstatchangeanimation BS_ATTACKER, BIT_DEF | BIT_SPDEF, STAT_CHANGE_NEGATIVE
	setbyte sSTAT_ANIM_PLAYED, TRUE
	setstatchanger STAT_DEF, 1, TRUE
	statbuffchange STAT_CHANGE_ALLOW_PTR, BattleScript_OctolockTryLowerSpDef
	jumpifbyte CMP_EQUAL, cMULTISTRING_CHOOSER, B_MSG_STAT_WONT_DECREASE, BattleScript_OctolockTryLowerSpDef
	printfromtable gStatUpStringIds
	waitmessage B_WAIT_TIME_LONG
BattleScript_OctolockTryLowerSpDef:
	jumpifbyte CMP_EQUAL, sSTAT_ANIM_PLAYED, TRUE, BattleScript_OctolockSkipSpDefAnim
	playstatchangeanimation BS_ATTACKER, BIT_SPDEF, STAT_CHANGE_NEGATIVE
BattleScript_OctolockSkipSpDefAnim:
	setstatchanger STAT_SPDEF, 1, TRUE
	statbuffchange STAT_CHANGE_ALLOW_PTR, BattleScript_OctolockEnd2
	jumpifbyte CMP_EQUAL, cMULTISTRING_CHOOSER, B_MSG_STAT_WONT_DECREASE, BattleScript_OctolockEnd2
	printfromtable gStatUpStringIds
	waitmessage B_WAIT_TIME_LONG
BattleScript_OctolockEnd2::
	end2

BattleScript_EffectPoltergeist:
	attackcanceler
	attackstring
	ppreduce
	checkpoltergeist BS_TARGET, BattleScript_ButItFailed
	printstring STRINGID_ABOUTTOUSEPOLTERGEIST
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_HitFromCritCalc

BattleScript_EffectTarShot:
	attackcanceler
	attackstring
	ppreduce
	accuracycheck BattleScript_PrintMoveMissed, ACC_CURR_MOVE
	call BattleScript_EffectDamage_Ret
	setmoveeffect MOVE_EFFECT_SMACK_DOWN
	seteffectwithchance
	setstatchanger STAT_SPEED, 1, TRUE
	statbuffchange STAT_CHANGE_ALLOW_PTR, BattleScript_TryTarShot
	setgraphicalstatchangevalues
	playanimation BS_TARGET, B_ANIM_STATS_CHANGE, sB_ANIM_ARG1
	printfromtable gStatDownStringIds
	waitmessage B_WAIT_TIME_LONG
BattleScript_TryTarShot:
	trytarshot BS_TARGET, BattleScript_TarShotEnd
	printstring STRINGID_PKMNBECAMEWEAKERTOFIRE
	waitmessage B_WAIT_TIME_LONG
BattleScript_TarShotEnd:
	tryfaintmon BS_TARGET, FALSE, NULL
	goto BattleScript_MoveEnd

BattleScript_EffectNoRetreat:
	attackcanceler
	accuracycheck BattleScript_PrintMoveMissed, ACC_CURR_MOVE
	attackstring
	ppreduce
	trynoretreat BS_TARGET, BattleScript_ButItFailed
	attackanimation
	waitanimation
	call BattleScript_AllStatsUp
	jumpifstatus2 BS_TARGET, STATUS2_ESCAPE_PREVENTION, BattleScript_MoveEnd
	setmoveeffect MOVE_EFFECT_PREVENT_ESCAPE
	seteffectprimary
	printstring STRINGID_CANTESCAPEDUETOUSEDMOVE
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_EffectJawLock:
	setmoveeffect MOVE_EFFECT_TRAP_BOTH | MOVE_EFFECT_CERTAIN
	goto BattleScript_EffectHit

BattleScript_BothCanNoLongerEscape::
	printstring STRINGID_BOTHCANNOLONGERESCAPE
	waitmessage B_WAIT_TIME_LONG
	return

BattleScript_EffectShellSideArm:
	shellsidearmcheck
	setmoveeffect MOVE_EFFECT_POISON
	goto BattleScript_EffectHit

BattleScript_EffectPhotonGeyser:
	attackcanceler
	accuracycheck BattleScript_PrintMoveMissed, ACC_CURR_MOVE
	attackstring
	ppreduce
	critcalc
	damagecalc
	adjustdamage
	photongeysercheck
	attackanimation
	waitanimation
	effectivenesssound
	hitanimation BS_TARGET
	waitstate
	healthbarupdate BS_TARGET
	datahpupdate BS_TARGET
	critmessage
	waitmessage B_WAIT_TIME_LONG
	resultmessage
	waitmessage B_WAIT_TIME_LONG
	seteffectwithchance
	tryfaintmon BS_TARGET, FALSE, NULL
	goto BattleScript_MoveEnd

BattleScript_EffectAuraWheel: @ Aura Wheel can only be used by Morpeko
	jumpifspecies BS_ATTACKER, SPECIES_MORPEKO, BattleScript_EffectSpeedUpHit
	jumpifspecies BS_ATTACKER, SPECIES_MORPEKO_HANGRY, BattleScript_EffectSpeedUpHit
	printstring STRINGID_BUTPOKEMONCANTUSETHEMOVE
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_EffectScaleShot::
	attackcanceler
	accuracycheck BattleScript_PrintMoveMissed, ACC_CURR_MOVE
	attackstring
	ppreduce
	setmultihitcounter 0
	initmultihitstring
	sethword sMULTIHIT_EFFECT, 0x0
BattleScript_ScaleShotLoop::
	jumpifhasnohp BS_ATTACKER, BattleScript_ScaleShotEnd
	jumpifhasnohp BS_TARGET, BattleScript_ScaleShotPrintStrings
	jumpifhalfword CMP_EQUAL, gChosenMove, MOVE_SLEEP_TALK, BattleScript_ScaleShotDoMultiHit
	jumpifstatus BS_ATTACKER, STATUS1_SLEEP, BattleScript_ScaleShotPrintStrings
BattleScript_ScaleShotDoMultiHit::
	movevaluescleanup
	copyhword sMOVE_EFFECT, sMULTIHIT_EFFECT
	critcalc
	damagecalc
	jumpifmovehadnoeffect BattleScript_ScaleShotMultiHitNoMoreHits
	adjustdamage
	attackanimation
	waitanimation
	effectivenesssound
	hitanimation BS_TARGET
	waitstate
	healthbarupdate BS_TARGET
	datahpupdate BS_TARGET
	critmessage
	waitmessage 0x40
	multihitresultmessage
	printstring STRINGID_EMPTYSTRING3
	waitmessage 0x1
	addbyte sMULTIHIT_STRING + 4, 0x1
	moveendto MOVEEND_NEXT_TARGET
	jumpifbyte CMP_COMMON_BITS, gMoveResultFlags, MOVE_RESULT_FOE_ENDURED, BattleScript_ScaleShotPrintStrings
	decrementmultihit BattleScript_ScaleShotLoop
	goto BattleScript_ScaleShotPrintStrings
BattleScript_ScaleShotMultiHitNoMoreHits::
	pause B_WAIT_TIME_SHORT
BattleScript_ScaleShotPrintStrings::
	resultmessage
	waitmessage 0x40
	jumpifmovehadnoeffect BattleScript_ScaleShotEnd
	copyarray gBattleTextBuff1, sMULTIHIT_STRING, 0x6
	printstring STRINGID_HITXTIMES
	waitmessage 0x40
BattleScript_ScaleShotEnd::
	setmoveeffect MOVE_EFFECT_SCALE_SHOT | MOVE_EFFECT_AFFECTS_ATTACKER | MOVE_EFFECT_CERTAIN
	seteffectwithchance
	tryfaintmon BS_TARGET, FALSE, NULL
	moveendcase MOVEEND_SYNCHRONIZE_TARGET
	moveendfrom MOVEEND_STATUS_IMMUNITY_ABILITIES
	end

BattleScript_EffectTwoTurnsAttack:
	jumpifnochargingturn BattleScript_TwoTurnsAttackNoChargingTurn
BattleScript_TwoTurnsAttackDecideTurn:
	jumpifstatus2 BS_ATTACKER, STATUS2_MULTIPLETURNS, BattleScript_TwoTurnMovesSecondTurn
	jumpifword CMP_COMMON_BITS, gHitMarker, HITMARKER_NO_ATTACKSTRING, BattleScript_TwoTurnMovesSecondTurn
	jumpifmove MOVE_SKY_ATTACK, BattleScript_FirstTurnSkyAttack
	jumpifmove MOVE_RAZOR_WIND, BattleScript_FirstTurnRazorWind
	jumpifmove MOVE_SKULL_BASH, BattleScript_FirstTurnSkullBash
	jumpifmove MOVE_METEOR_BEAM, BattleScript_FirstTurnMeteorBeam
	jumpifmove MOVE_SOVEREIGN_SWORD, BattleScript_FirstTurnSovereignSword
	jumpifmove MOVE_MIDNIGHT_BEAM, BattleScript_FirstTurnNightfallDaze
	jumpifmove MOVE_ELECTRO_SHOT, BattleScript_FirstTurnElectroShot
	setbyte sTWOTURN_STRINGID, B_MSG_TURN1_DRACO_IMPACT
	goto BattleScript_FirstTurnChargingEffect
BattleScript_FirstTurnElectroShot:
	setbyte sTWOTURN_STRINGID, B_MSG_TURN1_ELECTRO_SHOT
	goto BattleScript_FirstTurnChargingEffect
BattleScript_FirstTurnNightfallDaze:
	setbyte sTWOTURN_STRINGID, B_MSG_TURN1_NIGHTFALL_DAZE
	goto BattleScript_FirstTurnChargingEffect
BattleScript_FirstTurnSovereignSword:
	setbyte sTWOTURN_STRINGID, B_MSG_TURN1_SOVEREIGN_SWORD
	goto BattleScript_FirstTurnChargingEffect
BattleScript_FirstTurnMeteorBeam:
	setbyte sTWOTURN_STRINGID, B_MSG_TURN1_METEOR_BEAM
	goto BattleScript_FirstTurnChargingEffect
BattleScript_FirstTurnSkullBash:
	setbyte sTWOTURN_STRINGID, B_MSG_TURN1_SKULL_BASH
	goto BattleScript_FirstTurnChargingEffect
BattleScript_FirstTurnRazorWind:
	setbyte sTWOTURN_STRINGID, B_MSG_TURN1_RAZOR_WIND
	goto BattleScript_FirstTurnChargingEffect
BattleScript_FirstTurnSkyAttack:
	setbyte sTWOTURN_STRINGID, B_MSG_TURN1_SKY_ATTACK
BattleScript_FirstTurnChargingEffect:
	call BattleScriptFirstChargingTurn
	jumpifcanexecutemove BattleScript_TwoTurnMovesSecondTurn
	jumpifabilityorinnate BS_ATTACKER, ABILITY_SHALLOW_DIVER, BattleScript_ShallowDiver
	jumpifnoholdeffect BS_ATTACKER, HOLD_EFFECT_POWER_HERB, BattleScript_MoveEnd
	call BattleScript_PowerHerbActivation
	goto BattleScript_TwoTurnMovesSecondTurn

BattleScriptFirstChargingTurn::
	attackcanceler
	printstring STRINGID_EMPTYSTRING3
	ppreduce
	attackstring
BattleScriptFirstChargingTurnAfterAttackString:
	pause B_WAIT_TIME_LONG
	setbyte sB_ANIM_TURN, 0
	copybyte cMULTISTRING_CHOOSER, sTWOTURN_STRINGID
	printfromtable gFirstTurnOfTwoStringIds
	waitmessage B_WAIT_TIME_LONG
	attackanimation
	waitanimation
	orword gHitMarker, HITMARKER_CHARGING
	setmoveeffect MOVE_EFFECT_CHARGING | MOVE_EFFECT_AFFECTS_ATTACKER
	seteffectprimary
	setfirstturnstatboost BS_ATTACKER
	seteffectsecondary
	return

BattleScript_TwoTurnMovesSecondTurn::
	attackcanceler
	setmoveeffect MOVE_EFFECT_CHARGING
	setbyte sB_ANIM_TURN, 1
	clearstatusfromeffect BS_ATTACKER
	orword gHitMarker, HITMARKER_NO_PPDEDUCT
	argument2tomoveeffect
	goto BattleScript_HitFromAccCheck

BattleScript_ShallowDiver:
	sethword sABILITY_OVERWRITE, ABILITY_SHALLOW_DIVER
	pause B_WAIT_TIME_SHORT
	call BattleScript_AbilityPopUp
	goto BattleScript_TwoTurnMovesSecondTurn

BattleScript_TwoTurnsAttackNoChargingTurn:
	orword gHitMarker, HITMARKER_CHARGING
	setmoveeffect MOVE_EFFECT_CHARGING | MOVE_EFFECT_AFFECTS_ATTACKER
	seteffectprimary
	ppreduce
	goto BattleScript_TwoTurnMovesSecondTurn

BattleScript_EffectSkyDrop:
	jumpifstatus2 BS_ATTACKER, STATUS2_MULTIPLETURNS, BattleScript_SkyDropTurn2
	attackcanceler
	ppreduce
	accuracycheck BattleScript_PrintMoveMissed, ACC_CURR_MOVE
	attackstring
	jumpifsubstituteblocks BattleScript_ButItFailed
	jumpiftargetally BattleScript_ButItFailed
	jumpifunder200 BS_TARGET, BattleScript_SkyDropWork
	pause B_WAIT_TIME_SHORT
	printstring STRINGID_TARGETTOOHEAVY
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_SkyDropWork:
	setskydrop
	setbyte sTWOTURN_STRINGID, B_MSG_TURN1_SKY_DROP
	setsemiinvulnerablebit
	call BattleScriptFirstChargingTurnAfterAttackString
	goto BattleScript_MoveEnd
BattleScript_SkyDropTurn2:
	attackcanceler
	setmoveeffect MOVE_EFFECT_CHARGING
	setbyte sB_ANIM_TURN, 0x1
	clearstatusfromeffect BS_ATTACKER
	orword gHitMarker, HITMARKER_NO_PPDEDUCT
	argumenttomoveeffect
	clearsemiinvulnerablebit
	attackstring
	clearskydrop BattleScript_SkyDropChangedTarget
	jumpiftype BS_TARGET, TYPE_FLYING, BattleScript_SkyDropFlyingType
	goto BattleScript_HitFromCritCalc
BattleScript_SkyDropFlyingType:
	makevisible BS_TARGET
	printstring STRINGID_ITDOESNTAFFECT
	waitmessage B_WAIT_TIME_LONG
	makevisible BS_ATTACKER
	jumpifstatus2 BS_TARGET, STATUS2_CONFUSION, BattleScript_SkyDropFlyingAlreadyConfused
	jumpifstatus2 BS_TARGET, STATUS2_LOCK_CONFUSE, BattleScript_SkyDropFlyingConfuseLock
	goto BattleScript_MoveEnd
BattleScript_SkyDropChangedTarget:
	pause B_WAIT_TIME_SHORT
	orhalfword gMoveResultFlags, MOVE_RESULT_FAILED
	resultmessage
	waitmessage B_WAIT_TIME_LONG
	makevisible BS_ATTACKER
	goto BattleScript_MoveEnd

BattleScript_SkyDropFlyingConfuseLock:
	setmoveeffect MOVE_EFFECT_CONFUSE
	seteffectprimary
BattleScript_SkyDropFlyingAlreadyConfused:
	setmoveeffect MOVE_EFFECT_THRASH
	clearstatusfromeffect BS_TARGET
	jumpifstatus2 BS_TARGET, STATUS2_CONFUSION, BattleScript_MoveEnd
	setbyte BS_ATTACKER, BS_TARGET
	goto BattleScript_ThrashConfuses

BattleScript_EffectFeatherdance:
	attackcanceler
	attackstring
	ppreduce
	jumpifstat BS_ATTACKER, CMP_LESS_THAN, STAT_ATK, MAX_STAT_STAGE, BattleScript_FeatherdanceDoMoveAnim
	jumpifstat BS_ATTACKER, CMP_LESS_THAN, STAT_DEF, MAX_STAT_STAGE, BattleScript_FeatherdanceDoMoveAnim
	jumpifstat BS_ATTACKER, CMP_EQUAL, STAT_SPEED, MAX_STAT_STAGE, BattleScript_CantRaiseMultipleStats
BattleScript_FeatherdanceDoMoveAnim::
	attackanimation
	waitanimation
	setbyte sSTAT_ANIM_PLAYED, FALSE
	playstatchangeanimation BS_ATTACKER, BIT_ATK | BIT_DEF | BIT_SPEED, 0
	setstatchanger STAT_ATK, 1, FALSE
	statbuffchange MOVE_EFFECT_AFFECTS_ATTACKER | STAT_CHANGE_ALLOW_PTR, BattleScript_FeatherdanceTrySpDef
	jumpifbyte CMP_EQUAL, cMULTISTRING_CHOOSER, B_MSG_STAT_WONT_INCREASE, BattleScript_FeatherdanceTrySpDef
	printfromtable gStatUpStringIds
	waitmessage B_WAIT_TIME_LONG
BattleScript_FeatherdanceTrySpDef::
	setstatchanger STAT_DEF, 1, FALSE
	statbuffchange MOVE_EFFECT_AFFECTS_ATTACKER | STAT_CHANGE_ALLOW_PTR, BattleScript_FeatherdanceTrySpeed
	jumpifbyte CMP_EQUAL, cMULTISTRING_CHOOSER, B_MSG_STAT_WONT_INCREASE, BattleScript_FeatherdanceTrySpeed
	printfromtable gStatUpStringIds
	waitmessage B_WAIT_TIME_LONG
BattleScript_FeatherdanceTrySpeed::
	setstatchanger STAT_SPEED, 1, FALSE
	statbuffchange MOVE_EFFECT_AFFECTS_ATTACKER | STAT_CHANGE_ALLOW_PTR, BattleScript_FeatherdanceEnd
	jumpifbyte CMP_EQUAL, cMULTISTRING_CHOOSER, B_MSG_STAT_WONT_INCREASE, BattleScript_FeatherdanceEnd
	printfromtable gStatUpStringIds
	waitmessage B_WAIT_TIME_LONG
BattleScript_FeatherdanceEnd::
	goto BattleScript_MoveEnd

BattleScript_EffectSweetkiss::
	attackcanceler
	attackstring
	ppreduce
	accuracycheck BattleScript_MoveMissedPause, ACC_CURR_MOVE
	tryinfatuating BattleScript_HitFromCritCalc
	goto BattleScript_HitFromCritCalc

BattleScript_EffectKinesis::
	attackcanceler
	attackstring
	ppreduce
	jumpifstat BS_TARGET, CMP_NOT_EQUAL, STAT_ACC, MIN_STAT_STAGE, BattleScript_KinesisDoMoveAnim
	jumpifstat BS_ATTACKER, CMP_EQUAL, STAT_SPATK, MAX_STAT_STAGE, BattleScript_CantRaiseMultipleStats
BattleScript_KinesisDoMoveAnim:
	attackanimation
	waitanimation
	jumpifsubstituteblocks BattleScript_KinesisSpAttack
	accuracycheck BattleScript_KinesisSpAttack, ACC_CURR_MOVE	
	setstatchanger STAT_ACC, 1, TRUE
	statbuffchange STAT_CHANGE_ALLOW_PTR, BattleScript_KinesisSpAttack
	jumpifbyte CMP_LESS_THAN, cMULTISTRING_CHOOSER, B_MSG_STAT_WONT_DECREASE, BattleScript_KinesisStatDownDoAnim
	jumpifbyte CMP_EQUAL, cMULTISTRING_CHOOSER, B_MSG_STAT_FELL_EMPTY, BattleScript_KinesisSpAttack
	pause B_WAIT_TIME_SHORT
	goto BattleScript_KinesisStatDownPrintString
BattleScript_KinesisStatDownDoAnim::
	setgraphicalstatchangevalues
	playanimation BS_TARGET, B_ANIM_STATS_CHANGE, sB_ANIM_ARG1
BattleScript_KinesisStatDownPrintString:
	printfromtable gStatDownStringIds
	waitmessage B_WAIT_TIME_LONG
BattleScript_KinesisSpAttack:
	jumpifstat BS_ATTACKER, CMP_EQUAL, STAT_SPATK, MAX_STAT_STAGE, BattleScript_KinesisEnd
	setstatchanger STAT_SPATK, 2, FALSE
	statbuffchange MOVE_EFFECT_AFFECTS_ATTACKER | STAT_CHANGE_ALLOW_PTR, BattleScript_KinesisEnd
	jumpifbyte CMP_EQUAL, cMULTISTRING_CHOOSER, B_MSG_STAT_WONT_INCREASE, BattleScript_KinesisEnd
	setgraphicalstatchangevalues
	playanimation BS_ATTACKER, B_ANIM_STATS_CHANGE, sB_ANIM_ARG1
	printfromtable gStatUpStringIds
	waitmessage B_WAIT_TIME_LONG
BattleScript_KinesisEnd:
	goto BattleScript_MoveEnd

BattleScript_EffectMeditate::
	attackcanceler
	attackstring
	ppreduce
	jumpifstat BS_ATTACKER, CMP_LESS_THAN, STAT_ATK, MAX_STAT_STAGE, BattleScript_MeditateDoMoveAnim
	jumpifstat BS_ATTACKER, CMP_LESS_THAN, STAT_SPATK, MAX_STAT_STAGE, BattleScript_MeditateDoMoveAnim
	jumpifstat BS_ATTACKER, CMP_EQUAL, STAT_SPDEF, MAX_STAT_STAGE, BattleScript_CantRaiseMultipleStats
BattleScript_MeditateDoMoveAnim::
	attackanimation
	waitanimation
	setbyte sSTAT_ANIM_PLAYED, FALSE
	playstatchangeanimation BS_ATTACKER, BIT_ATK | BIT_SPATK |BIT_SPDEF, 0
	setstatchanger STAT_ATK, 1, FALSE
	statbuffchange MOVE_EFFECT_AFFECTS_ATTACKER | STAT_CHANGE_ALLOW_PTR, BattleScript_MeditateTrySpAtk
	jumpifbyte CMP_EQUAL, cMULTISTRING_CHOOSER, B_MSG_STAT_WONT_INCREASE, BattleScript_MeditateTrySpAtk
	printfromtable gStatUpStringIds
	waitmessage B_WAIT_TIME_LONG
BattleScript_MeditateTrySpAtk::
	setstatchanger STAT_SPATK, 1, FALSE
	statbuffchange MOVE_EFFECT_AFFECTS_ATTACKER | STAT_CHANGE_ALLOW_PTR, BattleScript_MeditateTrySpDef
	jumpifbyte CMP_EQUAL, cMULTISTRING_CHOOSER, B_MSG_STAT_WONT_INCREASE, BattleScript_MeditateTrySpDef
	printfromtable gStatUpStringIds
	waitmessage B_WAIT_TIME_LONG
BattleScript_MeditateTrySpDef::
	setstatchanger STAT_SPDEF, 2, FALSE
	statbuffchange MOVE_EFFECT_AFFECTS_ATTACKER | STAT_CHANGE_ALLOW_PTR, BattleScript_MeditateEnd
	jumpifbyte CMP_EQUAL, cMULTISTRING_CHOOSER, B_MSG_STAT_WONT_INCREASE, BattleScript_MeditateEnd
	printfromtable gStatUpStringIds
	waitmessage B_WAIT_TIME_LONG
BattleScript_MeditateEnd::
	goto BattleScript_MoveEnd

BattleScript_EffectExtrasensory:
	setmoveeffect MOVE_EFFECT_FLINCH
	attackcanceler
	accuracycheck BattleScript_PrintMoveMissed, ACC_CURR_MOVE
	attackstring
	ppreduce
	call BattleScript_EffectDamage_Ret
	seteffectwithchance
	tryfaintmon BS_TARGET, FALSE, NULL
	savemove
	trysetfutureattack BattleScript_ExtrasensoryEnd
	attackanimation
	waitanimation
	printfromtable gFutureMoveUsedStringIds
	waitmessage B_WAIT_TIME_LONG
BattleScript_ExtrasensoryEnd:
	restoremove
	goto BattleScript_MoveEnd

BattleScript_EffectHyperspaceFury:
	jumpifspecies BS_ATTACKER, SPECIES_HOOPA_UNBOUND, BattleScript_EffectHyperspaceFuryUnbound
	jumpifspecies BS_ATTACKER, SPECIES_HOOPA, BattleScript_ButHoopaCantUseIt
	printstring STRINGID_BUTPOKEMONCANTUSETHEMOVE
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_EffectHyperspaceFuryUnbound::
	attackcanceler
	accuracycheck BattleScript_PrintMoveMissed, ACC_CURR_MOVE
	attackstring
	pause B_WAIT_TIME_LONG
	ppreduce
	setmoveeffect MOVE_EFFECT_FEINT
	seteffectwithchance
	setmoveeffect MOVE_EFFECT_DEF_MINUS_1 | MOVE_EFFECT_AFFECTS_ATTACKER | MOVE_EFFECT_CERTAIN
	goto BattleScript_HitFromCritCalc

BattleScript_ButHoopaCantUseIt:
	printstring STRINGID_BUTHOOPACANTUSEIT
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_HyperspaceFuryRemoveProtect::
	printstring STRINGID_BROKETHROUGHPROTECTION
	waitmessage B_WAIT_TIME_LONG
	return

BattleScript_EffectPlasmaFists:
	attackcanceler
	accuracycheck BattleScript_PrintMoveMissed, ACC_CURR_MOVE
	attackstring
	ppreduce
	call BattleScript_EffectDamage_Ret
	seteffectwithchance
	tryfaintmon BS_TARGET, FALSE, NULL
	applyplasmafists
	printstring STRINGID_IONDELUGEON
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_EffectSparklySwirl:
	attackcanceler
	accuracycheck BattleScript_PrintMoveMissed, ACC_CURR_MOVE
	attackstring
	ppreduce
	call BattleScript_EffectDamage_Ret
	tryfaintmon BS_TARGET, FALSE, NULL
	healpartystatus
	waitstate
	updatestatusicon BS_ATTACKER_WITH_PARTNER
	waitstate
	goto BattleScript_MoveEnd

BattleScript_EffectFreezyFrost:
	attackcanceler
	accuracycheck BattleScript_PrintMoveMissed, ACC_CURR_MOVE
	attackstring
	ppreduce
	call BattleScript_EffectDamage_Ret
	tryfaintmon BS_TARGET, FALSE, NULL
	normalisebuffs
	printstring STRINGID_STATCHANGESGONE
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_EffectSappySeed:
	jumpifstatus3 BS_TARGET, STATUS3_LEECHSEED, BattleScript_EffectHit
	attackcanceler
	accuracycheck BattleScript_PrintMoveMissed, ACC_CURR_MOVE
	attackstring
	ppreduce
	call BattleScript_EffectDamage_Ret
	tryfaintmon BS_TARGET, FALSE, NULL
	jumpifhasnohp BS_TARGET, BattleScript_MoveEnd
	setseeded
	printfromtable gLeechSeedStringIds
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_EffectBaddyBad:
	jumpifsideaffecting BS_ATTACKER, SIDE_STATUS_REFLECT, BattleScript_EffectHit
	attackcanceler
	accuracycheck BattleScript_PrintMoveMissed, ACC_CURR_MOVE
	attackstring
	ppreduce
	call BattleScript_EffectDamage_Ret
	tryfaintmon BS_TARGET, FALSE, NULL
	setreflect
	printfromtable gReflectLightScreenSafeguardStringIds
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_EffectGlitzyGlow:
	jumpifsideaffecting BS_ATTACKER, SIDE_STATUS_LIGHTSCREEN, BattleScript_EffectHit
	attackcanceler
	accuracycheck BattleScript_PrintMoveMissed, ACC_CURR_MOVE
	attackstring
	ppreduce
	call BattleScript_EffectDamage_Ret
	tryfaintmon BS_TARGET, FALSE, NULL
	setlightscreen
	printfromtable gReflectLightScreenSafeguardStringIds
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_EffectDoubleIronBash:
	attackcanceler
	accuracycheck BattleScript_PrintMoveMissed, ACC_CURR_MOVE
	attackstring
	ppreduce
	setmultihitcounter 2
	initmultihitstring
	sethword sMULTIHIT_EFFECT, MOVE_EFFECT_FLINCH
	goto BattleScript_MultiHitLoop

BattleScript_EffectEvasionUpHit:
	setmoveeffect MOVE_EFFECT_EVS_PLUS_1 | MOVE_EFFECT_AFFECTS_ATTACKER
	goto BattleScript_EffectHit

BattleScript_EffectStuffCheeks::
	attackcanceler
	attackstring
	ppreduce
	jumpifnotberry BS_ATTACKER, BattleScript_ButItFailed
	attackanimation
	waitanimation
BattleScript_StuffCheeksEatBerry:
	setbyte sBERRY_OVERRIDE, TRUE
	orword gHitMarker, HITMARKER_DISABLE_ANIMATION
	consumeberry BS_ATTACKER, TRUE
	bicword gHitMarker, HITMARKER_DISABLE_ANIMATION
	setbyte sBERRY_OVERRIDE, FALSE
	removeitem BS_ATTACKER, 1
	setstatchanger STAT_DEF, 2, FALSE
	statbuffchange MOVE_EFFECT_AFFECTS_ATTACKER | STAT_CHANGE_ALLOW_PTR, BattleScript_StuffCheeksEnd
	setgraphicalstatchangevalues
	jumpifbyte CMP_EQUAL, cMULTISTRING_CHOOSER, B_MSG_STAT_WONT_INCREASE, BattleScript_StuffCheeksEnd @ cant raise def
	playanimation BS_ATTACKER, B_ANIM_STATS_CHANGE, sB_ANIM_ARG1
	printfromtable gStatUpStringIds
	waitmessage B_WAIT_TIME_LONG
BattleScript_StuffCheeksEnd:
	goto BattleScript_MoveEnd

BattleScript_EffectDecorate:
	attackcanceler
	accuracycheck BattleScript_PrintMoveMissed, ACC_CURR_MOVE
	attackstring
	ppreduce
	jumpifstat BS_TARGET, CMP_NOT_EQUAL, STAT_ATK, 12, BattleScript_DecorateBoost
	jumpifstat BS_TARGET, CMP_NOT_EQUAL, STAT_SPATK, 12, BattleScript_DecorateBoost
	goto BattleScript_ButItFailed
BattleScript_DecorateBoost:
	attackanimation
	waitanimation
	setbyte sSTAT_ANIM_PLAYED, FALSE
	playstatchangeanimation BS_TARGET, BIT_ATK | BIT_SPATK, 0x0
	setstatchanger STAT_ATK, 2, FALSE
	statbuffchange STAT_CHANGE_ALLOW_PTR | STAT_BUFF_NOT_PROTECT_AFFECTED, BattleScript_DecorateBoostSpAtk
	jumpifbyte CMP_EQUAL, cMULTISTRING_CHOOSER, 0x2, BattleScript_DecorateBoostSpAtk
	printfromtable gStatUpStringIds
	waitmessage B_WAIT_TIME_LONG
BattleScript_DecorateBoostSpAtk:
	setstatchanger STAT_SPATK, 2, FALSE
	statbuffchange STAT_CHANGE_ALLOW_PTR | STAT_BUFF_NOT_PROTECT_AFFECTED, BattleScript_MoveEnd
	jumpifbyte CMP_EQUAL, cMULTISTRING_CHOOSER, 0x2, BattleScript_MoveEnd
	printfromtable gStatUpStringIds
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_EffectRemoveTerrain:
	attackcanceler
	attackstring
	ppreduce
	call BattleScript_EffectDamage_Ret
	removeterrain
	jumpifbyte CMP_EQUAL, cMULTISTRING_CHOOSER, 4, BattleScript_MoveEnd
	printfromtable gTerrainEndingStringIds
	waitmessage B_WAIT_TIME_LONG
	playanimation BS_ATTACKER, B_ANIM_RESTORE_BG, NULL
	tryfaintmon BS_TARGET, FALSE, NULL
	goto BattleScript_MoveEnd

BattleScript_EffectCoaching:
	attackcanceler
	attackstring
	ppreduce
	jumpifnoally BS_ATTACKER, BattleScript_ButItFailed
	copybyte gBattlerTarget, gBattlerAttacker
	setallytonexttarget EffectCoaching_CheckAllyStats
	goto BattleScript_ButItFailed
EffectCoaching_CheckAllyStats:
	jumpifstat BS_TARGET, CMP_NOT_EQUAL, STAT_ATK, MAX_STAT_STAGE, BattleScript_CoachingWorks
	jumpifstat BS_TARGET, CMP_NOT_EQUAL, STAT_DEF, MAX_STAT_STAGE, BattleScript_CoachingWorks
	goto BattleScript_ButItFailed	@ ally at max atk, def
BattleScript_CoachingWorks:
	attackanimation
	waitanimation
	setbyte sSTAT_ANIM_PLAYED, FALSE
	playstatchangeanimation BS_TARGET, BIT_ATK | BIT_DEF, 0x0
	setstatchanger STAT_ATK, 1, FALSE
	statbuffchange STAT_CHANGE_ALLOW_PTR | STAT_BUFF_NOT_PROTECT_AFFECTED, BattleScript_CoachingBoostDef
	jumpifbyte CMP_EQUAL, cMULTISTRING_CHOOSER, 0x2, BattleScript_CoachingBoostDef
	printfromtable gStatUpStringIds
	waitmessage B_WAIT_TIME_LONG
BattleScript_CoachingBoostDef:
	setstatchanger STAT_DEF, 1, FALSE
	statbuffchange STAT_CHANGE_ALLOW_PTR | STAT_BUFF_NOT_PROTECT_AFFECTED, BattleScript_MoveEnd
	jumpifbyte CMP_EQUAL, cMULTISTRING_CHOOSER, 0x2, BattleScript_MoveEnd
	printfromtable gStatUpStringIds
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_EffectJungleHealing:
	attackcanceler
	attackstring
	ppreduce
	jumpifmove MOVE_WONDER_WISH, BattleScript_JungleHealingAnimation
	jumpifteamhealthy BS_ATTACKER, BattleScript_ButItFailed
BattleScript_JungleHealingAnimation:
	attackanimation
	waitanimation
	copybyte gBattlerTarget, gBattlerAttacker
	setbyte gBattleCommunication, 0
JungleHealing_RestoreTargetHealth:
	copybyte gBattlerAttacker, gBattlerTarget
	tryhealquarterhealth BS_TARGET, BattleScript_JungleHealing_TryCureStatus
	orword gHitMarker, HITMARKER_IGNORE_SUBSTITUTE
	healthbarupdate BS_TARGET
	datahpupdate BS_TARGET
	printstring STRINGID_PKMNREGAINEDHEALTH
	waitmessage B_WAIT_TIME_LONG
BattleScript_JungleHealing_TryCureStatus:
	jumpifmove MOVE_LIFE_DEW, BattleScript_JungleHealingTryRestoreAlly	@ life dew only heals
	jumpifmove MOVE_WONDER_WISH, BattleScript_JungleHealingTryRestoreAlly
	jumpifstatus BS_TARGET, STATUS1_ANY, BattleScript_JungleHealingCureStatus
	goto BattleScript_JungleHealingTryRestoreAlly
BattleScript_JungleHealingCureStatus:
	curestatus BS_TARGET
	updatestatusicon BS_TARGET
	printstring STRINGID_PKMNSTATUSNORMAL
	waitmessage B_WAIT_TIME_LONG
BattleScript_JungleHealingTryRestoreAlly:
	jumpifbyte CMP_NOT_EQUAL, gBattleCommunication, 0x0, BattleScript_JungleHealingEnd
	addbyte gBattleCommunication, 1
	jumpifnoally BS_TARGET, BattleScript_JungleHealingEnd
	setallytonexttarget JungleHealing_RestoreTargetHealth
BattleScript_JungleHealingEnd:
	jumpifmove MOVE_WONDER_WISH, BattleScript_WonderWishEffect
	goto BattleScript_MoveEnd

BattleScript_WonderWishEffect:
	setbyte sB_ANIM_TURN, 0
	setbyte sB_ANIM_TARGETS_HIT, 0
	metronome

BattleScript_EffectAttackerDefenseDownHit:
	setmoveeffect MOVE_EFFECT_DEF_MINUS_1 | MOVE_EFFECT_AFFECTS_ATTACKER | MOVE_EFFECT_CERTAIN
	goto BattleScript_EffectHit

BattleScript_EffectSleepHit:
	setmoveeffect MOVE_EFFECT_SLEEP
	goto BattleScript_EffectHit

BattleScript_EffectRelicSong:
	setmoveeffect MOVE_EFFECT_RELIC_SONG | MOVE_EFFECT_AFFECTS_ATTACKER | MOVE_EFFECT_CERTAIN
	attackcanceler
	accuracycheck BattleScript_PrintMoveMissed, ACC_CURR_MOVE
	attackstring
	ppreduce
	call BattleScript_EffectDamage_Ret
	seteffectwithchance
	argumenttomoveeffect
	seteffectwithchance
	tryfaintmon BS_TARGET, FALSE, NULL
	goto BattleScript_MoveEnd
	
BattleScript_EffectAllySwitch:
	attackcanceler
	accuracycheck BattleScript_PrintMoveMissed, ACC_CURR_MOVE
	attackstring
	ppreduce
	jumpifnoally BS_ATTACKER, BattleScript_ButItFailed
	allyswitchfailchance BattleScript_ButItFailed
	attackanimation
	waitanimation
	@ The actual data/gfx swap happens in the move animation. Here it's just the gBattlerAttacker / scripting battler change
	allyswitchswapbattlers
	printstring STRINGID_ALLYSWITCHPOSITION
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd
	
BattleScript_EffectFairyLock:
	attackcanceler
	accuracycheck BattleScript_PrintMoveMissed, ACC_CURR_MOVE
	attackstring
	ppreduce
	trysetfairylock BattleScript_ButItFailed
	attackanimation
	waitanimation
	printstring STRINGID_NOONEWILLBEABLETORUNAWAY
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd
	
BattleScript_EffectBurnUp:
	attackcanceler
	attackstring
	ppreduce
	jumpiftype BS_ATTACKER, TYPE_FIRE, BattleScript_BurnUpWorks
	goto BattleScript_ButItFailed
BattleScript_BurnUpWorks:
	accuracycheck BattleScript_MoveMissedPause, ACC_CURR_MOVE
	call BattleScript_EffectDamage_Ret
	losetype BS_ATTACKER, TYPE_FIRE
	printstring STRINGID_ATTACKERLOSTFIRETYPE
	waitmessage B_WAIT_TIME_LONG
	tryfaintmon BS_TARGET, FALSE, NULL
	goto BattleScript_MoveEnd

BattleScript_DefDown::
	modifybattlerstatstage BS_TARGET, STAT_DEF, DECREASE, 1, BattleScript_DefDown_Ret, ANIM_ON
BattleScript_DefDown_Ret:
	return
	
BattleScript_EffectPurify:
	attackcanceler
	attackstring
	ppreduce
	accuracycheck BattleScript_ButItFailed, NO_ACC_CALC_CHECK_LOCK_ON
	jumpifstatus BS_TARGET, STATUS1_ANY, BattleScript_PurifyWorks
	goto BattleScript_ButItFailed
BattleScript_PurifyWorks:
	attackanimation
	waitanimation
	curestatus BS_TARGET
	updatestatusicon BS_TARGET
	printstring STRINGID_ATTACKERCUREDTARGETSTATUS
	waitmessage B_WAIT_TIME_LONG
	tryhealhalfhealth BattleScript_AlreadyAtFullHp, BS_ATTACKER
	goto BattleScript_RestoreHp
	
BattleScript_EffectStrengthSap:
	setstatchanger STAT_ATK, 1, TRUE
	attackcanceler
	jumpifsubstituteblocks BattleScript_FailedFromAtkString
	accuracycheck BattleScript_PrintMoveMissed, ACC_CURR_MOVE
	attackstring
	ppreduce
	jumpifstat BS_TARGET, CMP_NOT_EQUAL, STAT_ATK, MIN_STAT_STAGE, BattleScript_StrengthSapTryLower
	pause B_WAIT_TIME_SHORT
	statbuffchange STAT_CHANGE_ALLOW_PTR, BattleScript_MoveEnd
	printfromtable gStatDownStringIds
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd
BattleScript_StrengthSapTryLower:
	getstatvalue BS_TARGET, STAT_ATK
	jumpiffullhp BS_ATTACKER, BattleScript_StrengthSapMustLower
	attackanimation
	waitanimation
	statbuffchange STAT_CHANGE_ALLOW_PTR, BattleScript_StrengthSapHp
	jumpifbyte CMP_EQUAL, cMULTISTRING_CHOOSER, B_MSG_STAT_FELL_EMPTY, BattleScript_StrengthSapHp
BattleScript_StrengthSapLower:
	setgraphicalstatchangevalues
	playanimation BS_TARGET, B_ANIM_STATS_CHANGE, sB_ANIM_ARG1
	printfromtable gStatDownStringIds
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_StrengthSapHp
@ Drain HP without lowering a stat
BattleScript_StrengthSapTryHp:
	jumpiffullhp BS_ATTACKER, BattleScript_ButItFailed
	attackanimation
	waitanimation
BattleScript_StrengthSapHp:
	jumpiffullhp BS_ATTACKER, BattleScript_MoveEnd
	manipulatedamage DMG_BIG_ROOT
	healthbarupdate BS_ATTACKER
	datahpupdate BS_ATTACKER
	printstring STRINGID_PKMNENERGYDRAINED
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd
BattleScript_StrengthSapMustLower:
	statbuffchange STAT_CHANGE_ALLOW_PTR, BattleScript_MoveEnd
	jumpifbyte CMP_EQUAL, cMULTISTRING_CHOOSER, B_MSG_STAT_FELL_EMPTY, BattleScript_MoveEnd
	attackanimation
	waitanimation
	goto BattleScript_StrengthSapLower

BattleScript_EffectEerieTune::
	setstatchanger STAT_SPATK, 1, TRUE
	attackcanceler
	jumpifsubstituteblocks BattleScript_FailedFromAtkString
	accuracycheck BattleScript_PrintMoveMissed, ACC_CURR_MOVE
	attackstring
	ppreduce
	jumpifstat BS_TARGET, CMP_NOT_EQUAL, STAT_SPATK, MIN_STAT_STAGE, BattleScript_EerieTuneTryLower
	pause B_WAIT_TIME_SHORT
	statbuffchange STAT_CHANGE_ALLOW_PTR, BattleScript_MoveEnd
	printfromtable gStatDownStringIds
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd
BattleScript_EerieTuneTryLower:
	getstatvalue BS_TARGET, STAT_SPATK
	jumpiffullhp BS_ATTACKER, BattleScript_StrengthSapMustLower
	attackanimation
	waitanimation
	statbuffchange STAT_CHANGE_ALLOW_PTR, BattleScript_StrengthSapHp
	jumpifbyte CMP_EQUAL, cMULTISTRING_CHOOSER, B_MSG_STAT_FELL_EMPTY, BattleScript_StrengthSapHp
	goto BattleScript_StrengthSapLower

BattleScript_EffectBugBite:
	setmoveeffect MOVE_EFFECT_BUG_BITE | MOVE_EFFECT_CERTAIN
	goto BattleScript_EffectHit

BattleScript_EffectIncinerate:
	setmoveeffect MOVE_EFFECT_INCINERATE | MOVE_EFFECT_CERTAIN
	goto BattleScript_EffectHit

BattleScript_MoveEffectIncinerate::
	printstring STRINGID_INCINERATEBURN
	waitmessage B_WAIT_TIME_LONG
	return

BattleScript_MoveEffectBugBite::
	printstring STRINGID_BUGBITE
	waitmessage B_WAIT_TIME_LONG
	orword gHitMarker, HITMARKER_DISABLE_ANIMATION
	setbyte sBERRY_OVERRIDE, TRUE   @ override the requirements for eating berries
	savetarget
	consumeberry BS_ATTACKER, FALSE  @ consume the berry, but don't replace gLastUsedItem
	bicword gHitMarker, HITMARKER_DISABLE_ANIMATION
	setbyte sBERRY_OVERRIDE, FALSE
	restoretarget
	return

BattleScript_EffectCoreEnforcer:
	setmoveeffect MOVE_EFFECT_CORE_ENFORCER | MOVE_EFFECT_CERTAIN
	goto BattleScript_EffectHit

BattleScript_MoveEffectCoreEnforcer::
	setgastroacid BattleScript_CoreEnforcerRet
	printstring STRINGID_PKMNSABILITYSUPPRESSED
	waitmessage B_WAIT_TIME_LONG
	trytoclearprimalweather
	printstring STRINGID_EMPTYSTRING3
	waitmessage 1
BattleScript_CoreEnforcerRet:
	return

BattleScript_EffectLaserFocus:
	attackcanceler
	attackstring
	ppreduce
	setbattlerstatus BS_ATTACKER, 3, STATUS3_LASER_FOCUS, BattleScript_ButItFailed
	attackanimation
	waitanimation
	printstring STRINGID_LASERFOCUS
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_EffectVCreate:
	setmoveeffect MOVE_EFFECT_V_CREATE | MOVE_EFFECT_AFFECTS_ATTACKER
	goto BattleScript_EffectHit

BattleScript_VCreateStatLoss::
	jumpifstat BS_ATTACKER, CMP_GREATER_THAN, STAT_DEF, MIN_STAT_STAGE, BattleScript_VCreateStatAnim
	jumpifstat BS_ATTACKER, CMP_GREATER_THAN, STAT_SPDEF, MIN_STAT_STAGE, BattleScript_VCreateStatAnim
	jumpifstat BS_ATTACKER, CMP_EQUAL, STAT_SPEED, MIN_STAT_STAGE, BattleScript_VCreateStatLossRet
BattleScript_VCreateStatAnim:
	setbyte sSTAT_ANIM_PLAYED, FALSE
	playstatchangeanimation BS_ATTACKER, BIT_DEF | BIT_SPDEF | BIT_SPEED, STAT_CHANGE_NEGATIVE | STAT_CHANGE_CANT_PREVENT
	setstatchanger STAT_DEF, 1, TRUE
	statbuffchange MOVE_EFFECT_AFFECTS_ATTACKER | STAT_BUFF_NOT_PROTECT_AFFECTED | MOVE_EFFECT_CERTAIN, BattleScript_VCreateTrySpDef
	jumpifbyte CMP_EQUAL, cMULTISTRING_CHOOSER, B_MSG_STAT_WONT_INCREASE, BattleScript_VCreateTrySpDef
	printfromtable gStatUpStringIds
	waitmessage B_WAIT_TIME_LONG
BattleScript_VCreateTrySpDef:
	setstatchanger STAT_SPDEF, 1, TRUE
	statbuffchange MOVE_EFFECT_AFFECTS_ATTACKER | STAT_BUFF_NOT_PROTECT_AFFECTED | MOVE_EFFECT_CERTAIN, BattleScript_VCreateTrySpeed
	jumpifbyte CMP_EQUAL, cMULTISTRING_CHOOSER, B_MSG_STAT_WONT_INCREASE, BattleScript_VCreateTrySpeed
	printfromtable gStatUpStringIds
	waitmessage B_WAIT_TIME_LONG
BattleScript_VCreateTrySpeed:
	setstatchanger STAT_SPEED, 1, TRUE
	statbuffchange MOVE_EFFECT_AFFECTS_ATTACKER | STAT_BUFF_NOT_PROTECT_AFFECTED | MOVE_EFFECT_CERTAIN, BattleScript_VCreateStatLossRet
	jumpifbyte CMP_EQUAL, cMULTISTRING_CHOOSER, B_MSG_STAT_WONT_INCREASE, BattleScript_VCreateStatLossRet
	printfromtable gStatUpStringIds
	waitmessage B_WAIT_TIME_LONG
BattleScript_VCreateStatLossRet:
	return

BattleScript_SpectralThiefSteal::
	printstring STRINGID_SPECTRALTHIEFSTEAL
	waitmessage B_WAIT_TIME_LONG
	setbyte sB_ANIM_ARG2, 0
	playanimation BS_ATTACKER, B_ANIM_STATS_CHANGE, sB_ANIM_ARG1
	spectralthiefprintstats
	return

BattleScript_EffectSpectralThief:
	setmoveeffect MOVE_EFFECT_SPECTRAL_THIEF
	goto BattleScript_EffectHit

BattleScript_EffectPartingShot::
	attackcanceler
	attackstring
	ppreduce
	jumpifstat BS_TARGET, CMP_GREATER_THAN, STAT_ATK, MIN_STAT_STAGE, BattleScript_EffectPartingShotTryAtk
	jumpifstat BS_TARGET, CMP_EQUAL, STAT_SPATK, MIN_STAT_STAGE, BattleScript_CantLowerMultipleStats
BattleScript_EffectPartingShotTryAtk:
	accuracycheck BattleScript_PrintMoveMissed, ACC_CURR_MOVE	
	attackanimation
	waitanimation
	setbyte sSTAT_ANIM_PLAYED, FALSE
	playstatchangeanimation BS_TARGET, BIT_ATK | BIT_SPATK, STAT_CHANGE_NEGATIVE | STAT_CHANGE_MULTIPLE_STATS
	playstatchangeanimation BS_TARGET, BIT_ATK, STAT_CHANGE_NEGATIVE
	setstatchanger STAT_ATK, 1, TRUE
	statbuffchange STAT_CHANGE_ALLOW_PTR, BattleScript_EffectPartingShotTrySpAtk
	printfromtable gStatDownStringIds
	waitmessage B_WAIT_TIME_LONG
BattleScript_EffectPartingShotTrySpAtk:
	playstatchangeanimation BS_TARGET, BIT_SPATK, STAT_CHANGE_NEGATIVE
	setstatchanger STAT_SPATK, 1, TRUE
	statbuffchange STAT_CHANGE_ALLOW_PTR, BattleScript_EffectPartingShotSwitch
	printfromtable gStatDownStringIds
	waitmessage B_WAIT_TIME_LONG
BattleScript_EffectPartingShotSwitch:	
	moveendall
	jumpifbattletype BATTLE_TYPE_ARENA, BattleScript_PartingShotEnd
	jumpifcantswitch SWITCH_IGNORE_ESCAPE_PREVENTION | BS_ATTACKER, BattleScript_PartingShotEnd
	openpartyscreen BS_ATTACKER, BattleScript_PartingShotEnd
	switchoutabilitiesorinnates BS_ATTACKER, 0
	switchoutabilitiesorinnates BS_ATTACKER, 1
	switchoutabilitiesorinnates BS_ATTACKER, 2
	switchoutabilitiesorinnates BS_ATTACKER, 3
	swithchoutrevolvingruin BS_ATTACKER
	waitstate
	switchhandleorder BS_ATTACKER, 2
	returntoball BS_ATTACKER
	getswitchedmondata BS_ATTACKER
	switchindataupdate BS_ATTACKER
	hpthresholds BS_ATTACKER
	trytoclearprimalweather
	printstring STRINGID_EMPTYSTRING3
	waitmessage 1
	printstring STRINGID_SWITCHINMON
	switchinanim BS_ATTACKER, TRUE
	waitstate
	switchineffects BS_ATTACKER
BattleScript_PartingShotEnd:
	end

BattleScript_EffectSpAtkUpHit:
	setmoveeffect MOVE_EFFECT_SP_ATK_PLUS_1 | MOVE_EFFECT_AFFECTS_ATTACKER
	goto BattleScript_EffectHit

BattleScript_EffectPowder:
	attackcanceler
	accuracycheck BattleScript_PrintMoveMissed, NO_ACC_CALC_CHECK_LOCK_ON
	attackstring
	ppreduce
	jumpifstatus2 BS_TARGET, STATUS2_POWDER, BattleScript_ButItFailed
	setpowder BS_TARGET
	attackanimation
	waitanimation
	printstring STRINGID_COVEREDINPOWDER
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_EffectAromaticMist:
	attackcanceler
	attackstring
	ppreduce
	jumpifbyteequal gBattlerTarget, gBattlerAttacker, BattleScript_ButItFailed
	jumpiftargetally BattleScript_EffectAromaticMistWorks
	goto BattleScript_ButItFailed
BattleScript_EffectAromaticMistWorks:
	setstatchanger STAT_SPDEF, 1, FALSE
	statbuffchange STAT_CHANGE_ALLOW_PTR, BattleScript_EffectAromaticMistEnd
	jumpifbyte CMP_NOT_EQUAL, cMULTISTRING_CHOOSER, B_MSG_STAT_WONT_INCREASE, BattleScript_AromaticMistAnim
	pause B_WAIT_TIME_SHORTEST
	printstring STRINGID_TARGETSTATWONTGOHIGHER
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_EffectAromaticMistEnd
BattleScript_AromaticMistAnim:
	attackanimation
	waitanimation
	setgraphicalstatchangevalues
	playanimation BS_TARGET, B_ANIM_STATS_CHANGE, sB_ANIM_ARG1
	printfromtable gStatUpStringIds
	waitmessage B_WAIT_TIME_LONG
BattleScript_EffectAromaticMistEnd:
	goto BattleScript_MoveEnd

BattleScript_EffectMagneticFlux::
	attackcanceler
	attackstring
	ppreduce
	copybyte gBattlerTarget, gBattlerAttacker
	setbyte gBattleCommunication, 0
BattleScript_EffectMagneticFluxStart:
	jumpifabilityorinnate BS_TARGET, ABILITY_MINUS, BattleScript_EffectMagneticFluxCheckStats
	jumpifabilityorinnate BS_TARGET, ABILITY_PLUS, BattleScript_EffectMagneticFluxCheckStats
	goto BattleScript_EffectMagneticFluxLoop
BattleScript_EffectMagneticFluxCheckStats:
	jumpifstat BS_TARGET, CMP_LESS_THAN, STAT_DEF, MAX_STAT_STAGE, BattleScript_EffectMagneticFluxTryDef
	jumpifstat BS_TARGET, CMP_EQUAL, STAT_SPDEF, MAX_STAT_STAGE, BattleScript_EffectMagneticFluxLoop
BattleScript_EffectMagneticFluxTryDef:
	jumpifbyte CMP_NOT_EQUAL, gBattleCommunication, 0, BattleScript_EffectMagneticFluxSkipAnim
	attackanimation
	waitanimation
BattleScript_EffectMagneticFluxSkipAnim:
	setbyte sSTAT_ANIM_PLAYED, FALSE
	playstatchangeanimation BS_TARGET, BIT_DEF | BIT_SPDEF, 0
	setstatchanger STAT_DEF, 1, FALSE
	statbuffchange STAT_CHANGE_ALLOW_PTR, BattleScript_EffectMagneticFluxTrySpDef
	jumpifbyte CMP_EQUAL, cMULTISTRING_CHOOSER, B_MSG_STAT_WONT_INCREASE, BattleScript_EffectMagneticFluxTrySpDef
	addbyte gBattleCommunication, 1
	printfromtable gStatUpStringIds
	waitmessage B_WAIT_TIME_LONG
BattleScript_EffectMagneticFluxTrySpDef:
	setstatchanger STAT_SPDEF, 1, FALSE
	statbuffchange STAT_CHANGE_ALLOW_PTR, BattleScript_EffectMagneticFluxLoop
	jumpifbyte CMP_EQUAL, cMULTISTRING_CHOOSER, B_MSG_STAT_WONT_INCREASE, BattleScript_EffectMagneticFluxLoop
	addbyte gBattleCommunication, 1
	printfromtable gStatUpStringIds
	waitmessage B_WAIT_TIME_LONG
BattleScript_EffectMagneticFluxLoop:
	jumpifbytenotequal gBattlerTarget, gBattlerAttacker, BattleScript_EffectMagneticFluxEnd
	setallytonexttarget BattleScript_EffectMagneticFluxStart
BattleScript_EffectMagneticFluxEnd:
	jumpifbyte CMP_NOT_EQUAL, gBattleCommunication, 0, BattleScript_MoveEnd
	goto BattleScript_ButItFailed

BattleScript_EffectGearUp::
	attackcanceler
	attackstring
	ppreduce
	copybyte gBattlerTarget, gBattlerAttacker
	setbyte gBattleCommunication, 0
BattleScript_EffectGearUpStart:
	jumpifabilityorinnate BS_TARGET, ABILITY_MINUS, BattleScript_EffectGearUpCheckStats
	jumpifabilityorinnate BS_TARGET, ABILITY_PLUS, BattleScript_EffectGearUpCheckStats
	goto BattleScript_EffectGearUpLoop
BattleScript_EffectGearUpCheckStats:
	jumpifstat BS_TARGET, CMP_LESS_THAN, STAT_ATK, MAX_STAT_STAGE, BattleScript_EffectGearUpTryAtk
	jumpifstat BS_TARGET, CMP_EQUAL, STAT_SPATK, MAX_STAT_STAGE, BattleScript_EffectGearUpLoop
BattleScript_EffectGearUpTryAtk:
	jumpifbyte CMP_NOT_EQUAL, gBattleCommunication, 0, BattleScript_EffectGearUpSkipAnim
	attackanimation
	waitanimation
BattleScript_EffectGearUpSkipAnim:
	setbyte sSTAT_ANIM_PLAYED, FALSE
	playstatchangeanimation BS_TARGET, BIT_ATK | BIT_SPATK, 0
	setstatchanger STAT_ATK, 1, FALSE
	statbuffchange STAT_CHANGE_ALLOW_PTR, BattleScript_EffectGearUpTrySpAtk
	jumpifbyte CMP_EQUAL, cMULTISTRING_CHOOSER, B_MSG_STAT_WONT_INCREASE, BattleScript_EffectGearUpTrySpAtk
	addbyte gBattleCommunication, 1
	printfromtable gStatUpStringIds
	waitmessage B_WAIT_TIME_LONG
BattleScript_EffectGearUpTrySpAtk:
	setstatchanger STAT_SPATK, 1, FALSE
	statbuffchange STAT_CHANGE_ALLOW_PTR, BattleScript_EffectGearUpLoop
	jumpifbyte CMP_EQUAL, cMULTISTRING_CHOOSER, B_MSG_STAT_WONT_INCREASE, BattleScript_EffectGearUpLoop
	addbyte gBattleCommunication, 1
	printfromtable gStatUpStringIds
	waitmessage B_WAIT_TIME_LONG
BattleScript_EffectGearUpLoop:
	jumpifbytenotequal gBattlerTarget, gBattlerAttacker, BattleScript_EffectGearUpEnd
	setallytonexttarget BattleScript_EffectGearUpStart
BattleScript_EffectGearUpEnd:
	jumpifbyte CMP_NOT_EQUAL, gBattleCommunication, 0, BattleScript_MoveEnd
	goto BattleScript_ButItFailed

BattleScript_EffectCraftyClothes::
	attackcanceler
	attackstring
	ppreduce
	copybyte gBattlerTarget, gBattlerAttacker
	setbyte gBattleCommunication, 0
BattleScript_EffectCraftyClothesCheckStats:
	jumpifstat BS_TARGET, CMP_EQUAL, STAT_DEF, MAX_STAT_STAGE, BattleScript_EffectCraftyClothesLoop
BattleScript_EffectCraftyClothesTryDef:
	jumpifbyte CMP_NOT_EQUAL, gBattleCommunication, 0, BattleScript_EffectCraftyClothesSkipAnim
	attackanimation
	waitanimation
BattleScript_EffectCraftyClothesSkipAnim:
	setstatchanger STAT_DEF, 2, FALSE
	statbuffchange STAT_CHANGE_ALLOW_PTR, BattleScript_EffectCraftyClothesLoop
	jumpifbyte CMP_EQUAL, cMULTISTRING_CHOOSER, B_MSG_STAT_WONT_INCREASE, BattleScript_EffectCraftyClothesLoop @ cant raise def
	pause B_WAIT_TIME_SHORT
	setgraphicalstatchangevalues
	playanimation BS_TARGET, B_ANIM_STATS_CHANGE, sB_ANIM_ARG1
	addbyte gBattleCommunication, 1
	printfromtable gStatUpStringIds
	waitmessage B_WAIT_TIME_LONG
BattleScript_EffectCraftyClothesLoop:
	jumpifbytenotequal gBattlerTarget, gBattlerAttacker, BattleScript_EffectCraftyClothesEnd
	trysettargetallyasnexttarget BattleScript_EffectCraftyClothesCheckStats, BattleScript_EffectCraftyClothesEnd
BattleScript_EffectCraftyClothesEnd:
	jumpifbyte CMP_NOT_EQUAL, gBattleCommunication, 0, BattleScript_MoveEnd
	goto BattleScript_ButItFailed

BattleScript_EffectAcupressure:
	attackcanceler
	jumpifbyteequal gBattlerTarget, gBattlerAttacker, BattleScript_EffectAcupressureTry
	jumpifstatus2 BS_TARGET, STATUS2_SUBSTITUTION_ANY, BattleScript_PrintMoveMissed
BattleScript_EffectAcupressureTry:
	attackstring
	ppreduce
	tryaccupressure BS_TARGET, BattleScript_ButItFailed
	attackanimation
	waitanimation
	setgraphicalstatchangevalues
	playanimation BS_TARGET, B_ANIM_STATS_CHANGE, sB_ANIM_ARG1
	statbuffchange MOVE_EFFECT_CERTAIN, BattleScript_MoveEnd
	printstring STRINGID_DEFENDERSSTATROSE
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_MoveEffectFeint::
	printstring STRINGID_FELLFORFEINT
	waitmessage B_WAIT_TIME_LONG
	return

BattleScript_MoveEffectPreventRevive::
	printstring STRINGID_CANNOTBEREVIVED
	waitmessage B_WAIT_TIME_LONG
	return

BattleScript_BecomeSlowed::
	printstring STRINGID_BECOMESLOWED
	waitmessage B_WAIT_TIME_LONG
	return

BattleScript_MoveEffectAdditionalDamage::
	printfromtable gAdditionalDamageStringIds
	waitmessage B_WAIT_TIME_LONG
	healthbarupdate BS_EFFECT_BATTLER
	datahpupdate BS_EFFECT_BATTLER
	return

BattleScript_TrashActivates::
	printstring STRINGID_TRASH
	waitmessage B_WAIT_TIME_LONG
	return

BattleScript_EffectFeint:
	setmoveeffect MOVE_EFFECT_FEINT
	goto BattleScript_EffectHit

BattleScript_EffectThirdType:
	attackcanceler
	accuracycheck BattleScript_PrintMoveMissed, ACC_CURR_MOVE
	attackstring
	ppreduce
	trysetthirdtype BS_TARGET, BattleScript_ButItFailed
	attackanimation
	waitanimation
	printstring STRINGID_THIRDTYPEADDED
	waitmessage B_WAIT_TIME_LONG
	healthbarupdate BS_ATTACKER
	datahpupdate BS_ATTACKER
	tryfaintmon BS_ATTACKER, FALSE, NULL
	goto BattleScript_MoveEnd

BattleScript_EffectDefenseUp2Hit:
	setmoveeffect MOVE_EFFECT_DEF_PLUS_2 | MOVE_EFFECT_AFFECTS_ATTACKER
	goto BattleScript_EffectHit

BattleScript_EffectFlowerShield:
	attackcanceler
	attackstring
	ppreduce
	selectfirstvalidtarget
BattleScript_FlowerShieldIsAnyGrass:
	jumpiftype BS_TARGET, TYPE_GRASS, BattleScript_FlowerShieldLoopStart
	jumpifnexttargetvalid BattleScript_FlowerShieldIsAnyGrass
	goto BattleScript_ButItFailed
BattleScript_FlowerShieldLoopStart:
	selectfirstvalidtarget
BattleScript_FlowerShieldLoop:
	movevaluescleanup
	jumpiftype BS_TARGET, TYPE_GRASS, BattleScript_FlowerShieldLoop2
	goto BattleScript_FlowerShieldMoveTargetEnd
BattleScript_FlowerShieldLoop2:
	setstatchanger STAT_DEF, 1, FALSE
	statbuffchange STAT_CHANGE_ALLOW_PTR, BattleScript_FlowerShieldMoveTargetEnd
	jumpifbyte CMP_LESS_THAN, cMULTISTRING_CHOOSER, B_MSG_STAT_WONT_INCREASE, BattleScript_FlowerShieldDoAnim
	jumpifbyte CMP_EQUAL, cMULTISTRING_CHOOSER, B_MSG_STAT_ROSE_EMPTY, BattleScript_FlowerShieldMoveTargetEnd
	pause 21
	goto BattleScript_FlowerShieldString
BattleScript_FlowerShieldDoAnim:
	attackanimation
	waitanimation
	setgraphicalstatchangevalues
	playanimation BS_TARGET, B_ANIM_STATS_CHANGE, sB_ANIM_ARG1
BattleScript_FlowerShieldString:
	printfromtable gStatUpStringIds
	waitmessage B_WAIT_TIME_LONG
BattleScript_FlowerShieldMoveTargetEnd:
	moveendto MOVEEND_NEXT_TARGET
	jumpifnexttargetvalid BattleScript_FlowerShieldLoop
	end
	
BattleScript_EffectRototiller:
	attackcanceler
	attackstring
	ppreduce
	getrototillertargets BattleScript_ButItFailed
	@ at least one battler is affected
	attackanimation
	waitanimation
	savetarget
	setbyte gBattlerTarget, 0
BattleScript_RototillerLoop:
	movevaluescleanup
	jumpifstat BS_TARGET, CMP_LESS_THAN, STAT_ATK, MAX_STAT_STAGE, BattleScript_RototillerCheckAffected
	jumpifstat BS_TARGET, CMP_EQUAL, STAT_SPATK, MAX_STAT_STAGE, BattleScript_RototillerCantRaiseMultipleStats
BattleScript_RototillerCheckAffected:
	jumpifnotrototilleraffected BS_TARGET, BattleScript_RototillerNoEffect
BattleScript_RototillerAffected:
	setbyte sSTAT_ANIM_PLAYED, FALSE
	playstatchangeanimation BS_TARGET, BIT_ATK | BIT_SPATK, 0
	setstatchanger STAT_ATK, 1, FALSE
	statbuffchange STAT_CHANGE_ALLOW_PTR, BattleScript_RototillerTrySpAtk
	jumpifbyte CMP_EQUAL, cMULTISTRING_CHOOSER, B_MSG_STAT_WONT_INCREASE, BattleScript_RototillerTrySpAtk
	printfromtable gStatUpStringIds
	waitmessage B_WAIT_TIME_LONG
BattleScript_RototillerTrySpAtk::
	setstatchanger STAT_SPATK, 1, FALSE
	statbuffchange STAT_CHANGE_ALLOW_PTR, BattleScript_RototillerMoveTargetEnd
	jumpifbyte CMP_EQUAL, cMULTISTRING_CHOOSER, B_MSG_STAT_WONT_INCREASE, BattleScript_RototillerMoveTargetEnd
	printfromtable gStatUpStringIds
	waitmessage B_WAIT_TIME_LONG
BattleScript_RototillerMoveTargetEnd:
	moveendto MOVEEND_NEXT_TARGET
	addbyte gBattlerTarget, 1
	jumpifbytenotequal gBattlerTarget, gBattlersCount, BattleScript_RototillerLoop
	end

BattleScript_RototillerCantRaiseMultipleStats:
	copybyte gBattlerAttacker, gBattlerTarget
	printstring STRINGID_STATSWONTINCREASE2
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_RototillerMoveTargetEnd

BattleScript_RototillerNoEffect:
	pause B_WAIT_TIME_SHORT
	printstring STRINGID_NOEFFECTONTARGET
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_RototillerMoveTargetEnd

BattleScript_EffectBestow:
	attackcanceler
	accuracycheck BattleScript_PrintMoveMissed, NO_ACC_CALC_CHECK_LOCK_ON
	attackstring
	ppreduce
	jumpifsubstituteblocks BattleScript_ButItFailed
	trybestow 0, BattleScript_EffectBestowFirstFail
	attackanimation
	waitanimation
	printstring STRINGID_BESTOWITEMGIVING
	waitmessage B_WAIT_TIME_LONG
	trybestow 1, BattleScript_EffectBestowEquip3
	attackanimation
	waitanimation
	printstring STRINGID_BESTOWITEMGIVING
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_EffectBestowEquip3

BattleScript_EffectBestowFirstFail:
	trybestow 1, BattleScript_EffectBestowSecondFail
	attackanimation
	waitanimation
	printstring STRINGID_BESTOWITEMGIVING
	waitmessage B_WAIT_TIME_LONG
BattleScript_EffectBestowEquip3:
	trybestow 2, BattleScript_MoveEnd
	attackanimation
	waitanimation
	printstring STRINGID_BESTOWITEMGIVING
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_EffectBestowSecondFail:
	trybestow 2, BattleScript_ButItFailed
	attackanimation
	waitanimation
	printstring STRINGID_BESTOWITEMGIVING
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_EffectAfterYou:
	attackcanceler
	accuracycheck BattleScript_PrintMoveMissed, ACC_CURR_MOVE
	attackstring
	ppreduce
	tryafteryou BattleScript_ButItFailed
	attackanimation
	waitanimation
	printstring STRINGID_KINDOFFER
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_EffectFlameBurst:
	setmoveeffect MOVE_EFFECT_FLAME_BURST | MOVE_EFFECT_AFFECTS_ATTACKER
	goto BattleScript_EffectHit

BattleScript_MoveEffectFlameBurst::
	tryfaintmon BS_TARGET, FALSE, NULL
	copybyte sBATTLER, sSAVED_BATTLER
	printstring STRINGID_BURSTINGFLAMESHIT
	waitmessage B_WAIT_TIME_LONG
	savetarget
	copybyte gBattlerTarget, sSAVED_BATTLER
	healthbarupdate BS_TARGET
	datahpupdate BS_TARGET
	tryfaintmon BS_TARGET, FALSE, NULL
	restoretarget
	goto BattleScript_MoveEnd

BattleScript_EffectPowerTrick:
	attackcanceler
	accuracycheck BattleScript_PrintMoveMissed, ACC_CURR_MOVE
	attackstring
	ppreduce
	powertrick BS_ATTACKER
	attackanimation
	waitanimation
	printstring STRINGID_PKMNSWITCHEDATKANDDEF
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_EffectPsychoShift:
	attackcanceler
	accuracycheck BattleScript_PrintMoveMissed, ACC_CURR_MOVE
	attackstring
	ppreduce
	jumpifstatus BS_ATTACKER, STATUS1_ANY, BattleScript_EffectPsychoShiftCanWork
	goto BattleScript_ButItFailed
BattleScript_EffectPsychoShiftCanWork:
	jumpifstatus BS_TARGET, STATUS1_ANY, BattleScript_ButItFailed
	jumpifsafeguard BattleScript_SafeguardProtected
	jumpifkingsgrace BattleScript_KingsGraceProtected
	trypsychoshift BattleScript_MoveEnd
	attackanimation
	waitanimation
	copybyte gEffectBattler, gBattlerTarget
	printfromtable gStatusConditionsStringIds
	waitmessage B_WAIT_TIME_LONG
	statusanimation BS_TARGET
	updatestatusicon BS_TARGET
	curestatus BS_ATTACKER
	printstring STRINGID_PKMNSTATUSNORMAL
	waitmessage B_WAIT_TIME_LONG
	updatestatusicon BS_ATTACKER
	goto BattleScript_MoveEnd

BattleScript_EffectSynchronoise:
	attackcanceler
	attackstring
	ppreduce
	selectfirstvalidtarget
BattleScript_SynchronoiseLoop:
	movevaluescleanup
	jumpifcantusesynchronoise BattleScript_SynchronoiseNoEffect
	accuracycheck BattleScript_SynchronoiseMissed, ACC_CURR_MOVE
	call BattleScript_EffectDamage_Ret
	printstring STRINGID_EMPTYSTRING3
	waitmessage 1
	tryfaintmon BS_TARGET, FALSE, NULL
BattleScript_SynchronoiseMoveTargetEnd:
	moveendto MOVEEND_NEXT_TARGET
	jumpifnexttargetvalid BattleScript_SynchronoiseLoop
	end
BattleScript_SynchronoiseMissed:
	pause B_WAIT_TIME_SHORT
	resultmessage
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_SynchronoiseMoveTargetEnd
BattleScript_SynchronoiseNoEffect:
	pause B_WAIT_TIME_SHORT
	printstring STRINGID_NOEFFECTONTARGET
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_SynchronoiseMoveTargetEnd

BattleScript_EffectSmackDown:
	setmoveeffect MOVE_EFFECT_SMACK_DOWN
	goto BattleScript_EffectHit

BattleScript_MoveEffectSmackDown::
	tryfaintmon BS_TARGET, FALSE, NULL
	printstring STRINGID_FELLSTRAIGHTDOWN
	waitmessage B_WAIT_TIME_LONG
	healthbarupdate BS_TARGET
	datahpupdate BS_TARGET
	tryfaintmon BS_TARGET, FALSE, NULL
	return

BattleScript_EffectHitEnemyHealAlly:
	jumpiftargetally BattleScript_EffectHealPulse
	goto BattleScript_EffectHit

BattleScript_EffectDefog:
	setstatchanger STAT_EVASION, 1, TRUE
	attackcanceler
	jumpifsubstituteblocks BattleScript_DefogIfCanClearHazards
	jumpifstat BS_TARGET, CMP_NOT_EQUAL, STAT_EVASION, MIN_STAT_STAGE, BattleScript_DefogWorks
BattleScript_DefogIfCanClearHazards:
	defogclear BS_ATTACKER, FALSE, BattleScript_FailedFromAtkString
BattleScript_DefogWorks:
	accuracycheck BattleScript_PrintMoveMissed, ACC_CURR_MOVE
	attackstring
	ppreduce
	statbuffchange STAT_CHANGE_ALLOW_PTR, BattleScript_DefogTryHazardsWithAnim
	jumpifbyte CMP_LESS_THAN, cMULTISTRING_CHOOSER, B_MSG_STAT_WONT_DECREASE, BattleScript_DefogDoAnim
	jumpifbyte CMP_EQUAL, cMULTISTRING_CHOOSER, B_MSG_STAT_FELL_EMPTY, BattleScript_DefogTryHazardsWithAnim
	pause B_WAIT_TIME_SHORT
	goto BattleScript_DefogPrintString
BattleScript_DefogDoAnim::
	attackanimation
	waitanimation
	setgraphicalstatchangevalues
	playanimation BS_TARGET, B_ANIM_STATS_CHANGE, sB_ANIM_ARG1
BattleScript_DefogPrintString::
	printfromtable gStatDownStringIds
	waitmessage B_WAIT_TIME_LONG
BattleScript_DefogTryHazards::
	copybyte gEffectBattler, gBattlerAttacker
	defogclear BS_ATTACKER, TRUE, NULL
	copybyte gBattlerAttacker, gEffectBattler
	goto BattleScript_MoveEnd
BattleScript_DefogTryHazardsWithAnim:
	attackanimation
	waitanimation
	goto BattleScript_DefogTryHazards

BattleScript_EffectCopycat:
	attackcanceler
	attackstring
	pause 5
	trycopycat BattleScript_CopycatFail
	attackanimation
	waitanimation
	jumptocalledmove TRUE
BattleScript_CopycatFail:
	ppreduce
	goto BattleScript_ButItFailed

BattleScript_EffectInstruct:
	attackcanceler
	attackstring
	ppreduce
	pause 5
	tryinstruct BattleScript_ButItFailed
	attackanimation
	waitanimation
	printstring STRINGID_USEDINSTRUCTEDMOVE
	waitmessage B_WAIT_TIME_LONG
	setbyte sB_ANIM_TURN, 0
	setbyte sB_ANIM_TARGETS_HIT, 0
	jumptocalledmove TRUE

BattleScript_EffectAutotomize:
	attackcanceler
	attackstring
	ppreduce
	tryautotomize BS_ATTACKER, BattleScript_ButItFailed
	attackanimation
	waitanimation
	printstring STRINGID_BECAMENIMBLE
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_EffectAutotomizeBackUp:
	setstatchanger STAT_SPEED, 2, FALSE
	attackcanceler
	attackstring
	ppreduce
	statbuffchange MOVE_EFFECT_AFFECTS_ATTACKER | STAT_CHANGE_ALLOW_PTR, BattleScript_AutotomizeWeightLoss
	jumpifbyte CMP_NOT_EQUAL, cMULTISTRING_CHOOSER, B_MSG_STAT_WONT_INCREASE, BattleScript_AutotomizeAttackAnim
	pause B_WAIT_TIME_SHORT
	goto BattleScript_AutotomizePrintString
BattleScript_AutotomizeAttackAnim::
	attackanimation
	waitanimation
BattleScript_AutotomizeDoAnim::
	setgraphicalstatchangevalues
	playanimation BS_ATTACKER, B_ANIM_STATS_CHANGE, sB_ANIM_ARG1
BattleScript_AutotomizePrintString::
	printfromtable gStatUpStringIds
	waitmessage B_WAIT_TIME_LONG
BattleScript_AutotomizeWeightLoss::
	jumpifmovehadnoeffect BattleScript_MoveEnd
	tryautotomize BS_ATTACKER, BattleScript_MoveEnd
	printstring STRINGID_BECAMENIMBLE
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_EffectFinalGambit:
	attackcanceler
	accuracycheck BattleScript_PrintMoveMissed, ACC_CURR_MOVE
	attackstring
	ppreduce
	critcalc
	typecalc
	bichalfword gMoveResultFlags, MOVE_RESULT_SUPER_EFFECTIVE | MOVE_RESULT_NOT_VERY_EFFECTIVE
	dmgtocurrattackerhp
	adjustdamage
	attackanimation
	waitanimation
	effectivenesssound
	hitanimation BS_TARGET
	waitstate
	healthbarupdate BS_TARGET
	datahpupdate BS_TARGET
	resultmessage
	waitmessage B_WAIT_TIME_LONG
	dmgtocurrattackerhp
	healthbarupdate BS_ATTACKER
	datahpupdate BS_ATTACKER
	seteffectwithchance
	tryfaintmon BS_ATTACKER, FALSE, NULL
	tryfaintmon BS_TARGET, FALSE, NULL
	jumpifmovehadnoeffect BattleScript_MoveEnd
	goto BattleScript_MoveEnd

BattleScript_EffectHitSwitchTarget:
	attackcanceler
	accuracycheck BattleScript_PrintMoveMissed, ACC_CURR_MOVE
	attackstring
	ppreduce
	call BattleScript_EffectDamage_Ret
	tryfaintmon BS_TARGET, FALSE, NULL
	jumpifabilityorinnate BS_TARGET, ABILITY_SUCTION_CUPS, BattleScript_AbilityPreventsPhasingOut
	jumpifstatus3 BS_TARGET, STATUS3_ROOTED, BattleScript_PrintMonIsRooted
	jumpifnoholdeffect BS_TARGET, HOLD_EFFECT_STRONG_SHIELD, BattleScript_EffectHitSwitchTargetContinue
	goto BattleScript_MoveEnd
BattleScript_EffectHitSwitchTargetContinue:
	tryhitswitchtarget BattleScript_EffectHitSwitchTargetMoveEnd
BattleScript_EffectHitSwitchTargetMoveEnd:
	moveendall
	end

BattleScript_EffectClearSmog:
	setmoveeffect MOVE_EFFECT_CLEAR_SMOG
	goto BattleScript_EffectHit

BattleScript_EffectToxicThread:
	setstatchanger STAT_SPEED, 1, TRUE
	attackcanceler
	jumpifsubstituteblocks BattleScript_FailedFromAtkString
	jumpifstat BS_TARGET, CMP_NOT_EQUAL, STAT_SPEED, MIN_STAT_STAGE, BattleScript_ToxicThreadWorks
	jumpifstatus BS_TARGET, STATUS1_PSN_ANY, BattleScript_FailedFromAtkString
BattleScript_ToxicThreadWorks:
	accuracycheck BattleScript_PrintMoveMissed, ACC_CURR_MOVE
	attackstring
	ppreduce
	statbuffchange STAT_CHANGE_ALLOW_PTR, BattleScript_ToxicThreadTryPsn
	jumpifbyte CMP_LESS_THAN, cMULTISTRING_CHOOSER, B_MSG_STAT_WONT_DECREASE, BattleScript_ToxicThreadDoAnim
	jumpifbyte CMP_EQUAL, cMULTISTRING_CHOOSER, B_MSG_STAT_FELL_EMPTY, BattleScript_ToxicThreadTryPsn
	pause B_WAIT_TIME_SHORT
	goto BattleScript_ToxicThreadPrintString
BattleScript_ToxicThreadDoAnim::
	attackanimation
	waitanimation
	setgraphicalstatchangevalues
	playanimation BS_TARGET, B_ANIM_STATS_CHANGE, sB_ANIM_ARG1
BattleScript_ToxicThreadPrintString::
	printfromtable gStatDownStringIds
	waitmessage B_WAIT_TIME_LONG
BattleScript_ToxicThreadTryPsn::
	setmoveeffect MOVE_EFFECT_POISON
	seteffectprimary
	settoxicspikes BattleScript_ToxicThreadToxicSpikes
	printstring STRINGID_POISONSPIKESSCATTERED
	waitmessage B_WAIT_TIME_LONG
BattleScript_ToxicThreadToxicSpikes:
	setstickyweb BattleScript_ToxicThreadStickyWeb
	printstring STRINGID_STICKYWEBUSED
	waitmessage B_WAIT_TIME_LONG
BattleScript_ToxicThreadStickyWeb:
	goto BattleScript_MoveEnd

BattleScript_EffectVenomDrench:
	jumpifstatus BS_TARGET, STATUS1_PSN_ANY, BattleScript_EffectVenomDrenchCanBeUsed
	goto BattleScript_EffectPoison
BattleScript_EffectVenomDrenchCanBeUsed:
	attackcanceler
	attackstring
	ppreduce
	jumpifstat BS_TARGET, CMP_GREATER_THAN, STAT_ATK, MIN_STAT_STAGE, BattleScript_VenomDrenchDoMoveAnim
	jumpifstat BS_TARGET, CMP_GREATER_THAN, STAT_SPATK, MIN_STAT_STAGE, BattleScript_VenomDrenchDoMoveAnim
	jumpifstat BS_TARGET, CMP_EQUAL, STAT_SPEED, MIN_STAT_STAGE, BattleScript_CantLowerMultipleStats
BattleScript_VenomDrenchDoMoveAnim::
	accuracycheck BattleScript_ButItFailed, ACC_CURR_MOVE
	attackanimation
	waitanimation
	setbyte sSTAT_ANIM_PLAYED, FALSE
	playstatchangeanimation BS_TARGET, BIT_ATK | BIT_SPATK | BIT_SPEED, STAT_CHANGE_NEGATIVE | STAT_CHANGE_MULTIPLE_STATS
	playstatchangeanimation BS_TARGET, BIT_ATK, STAT_CHANGE_NEGATIVE
	setstatchanger STAT_ATK, 1, TRUE
	statbuffchange STAT_CHANGE_ALLOW_PTR, BattleScript_VenomDrenchTryLowerSpAtk
	jumpifbyte CMP_EQUAL, cMULTISTRING_CHOOSER, B_MSG_STAT_WONT_DECREASE, BattleScript_VenomDrenchTryLowerSpAtk
	printfromtable gStatDownStringIds
	waitmessage B_WAIT_TIME_LONG
BattleScript_VenomDrenchTryLowerSpAtk::
	playstatchangeanimation BS_TARGET, BIT_SPATK, STAT_CHANGE_NEGATIVE
	setstatchanger STAT_SPATK, 1, TRUE
	statbuffchange STAT_CHANGE_ALLOW_PTR, BattleScript_VenomDrenchTryLowerSpeed
	jumpifbyte CMP_EQUAL, cMULTISTRING_CHOOSER, B_MSG_STAT_WONT_DECREASE, BattleScript_VenomDrenchTryLowerSpeed
	printfromtable gStatDownStringIds
	waitmessage B_WAIT_TIME_LONG
BattleScript_VenomDrenchTryLowerSpeed::
	playstatchangeanimation BS_TARGET, BIT_SPEED, STAT_CHANGE_NEGATIVE
	setstatchanger STAT_SPEED, 1, TRUE
	statbuffchange STAT_CHANGE_ALLOW_PTR, BattleScript_VenomDrenchEnd
	jumpifbyte CMP_EQUAL, cMULTISTRING_CHOOSER, B_MSG_STAT_WONT_DECREASE, BattleScript_VenomDrenchEnd
	printfromtable gStatDownStringIds
	waitmessage B_WAIT_TIME_LONG
BattleScript_VenomDrenchEnd::
	goto BattleScript_MoveEnd

BattleScript_EffectNobleRoar:
	attackcanceler
	attackstring
	ppreduce
	jumpifstat BS_TARGET, CMP_GREATER_THAN, STAT_ATK, MIN_STAT_STAGE, BattleScript_NobleRoarDoMoveAnim
	jumpifstat BS_TARGET, CMP_EQUAL, STAT_SPATK, MIN_STAT_STAGE, BattleScript_CantLowerMultipleStats
BattleScript_NobleRoarDoMoveAnim::
	accuracycheck BattleScript_ButItFailed, ACC_CURR_MOVE
	attackanimation
	waitanimation
	setbyte sSTAT_ANIM_PLAYED, FALSE
	playstatchangeanimation BS_TARGET, BIT_ATK | BIT_SPATK, STAT_CHANGE_NEGATIVE | STAT_CHANGE_MULTIPLE_STATS
	playstatchangeanimation BS_TARGET, BIT_ATK, STAT_CHANGE_NEGATIVE
	setstatchanger STAT_ATK, 1, TRUE
	statbuffchange STAT_CHANGE_ALLOW_PTR, BattleScript_NobleRoarTryLowerSpAtk
	jumpifbyte CMP_EQUAL, cMULTISTRING_CHOOSER, B_MSG_STAT_WONT_DECREASE, BattleScript_NobleRoarTryLowerSpAtk
	printfromtable gStatDownStringIds
	waitmessage B_WAIT_TIME_LONG
BattleScript_NobleRoarTryLowerSpAtk::
	playstatchangeanimation BS_TARGET, BIT_SPATK, STAT_CHANGE_NEGATIVE
	setstatchanger STAT_SPATK, 1, TRUE
	statbuffchange STAT_CHANGE_ALLOW_PTR, BattleScript_NobleRoarEnd
	jumpifbyte CMP_EQUAL, cMULTISTRING_CHOOSER, B_MSG_STAT_WONT_DECREASE, BattleScript_NobleRoarEnd
	printfromtable gStatDownStringIds
	waitmessage B_WAIT_TIME_LONG
BattleScript_NobleRoarEnd::
	goto BattleScript_MoveEnd

BattleScript_EffectShellSmash:
	attackcanceler
	attackstring
	ppreduce
	jumpifshieldsdown BS_ATTACKER, BattleScript_ShieldsDownShellSmash
	jumpifstat BS_ATTACKER, CMP_LESS_THAN, STAT_ATK, MAX_STAT_STAGE, BattleScript_ShellSmashTryDef
	jumpifstat BS_ATTACKER, CMP_LESS_THAN, STAT_SPATK, MAX_STAT_STAGE, BattleScript_ShellSmashTryDef
	jumpifstat BS_ATTACKER, CMP_LESS_THAN, STAT_SPEED, MAX_STAT_STAGE, BattleScript_ShellSmashTryDef
	jumpifstat BS_ATTACKER, CMP_GREATER_THAN, STAT_DEF, MIN_STAT_STAGE, BattleScript_ShellSmashTryDef
	jumpifstat BS_ATTACKER, CMP_EQUAL, STAT_SPDEF, MIN_STAT_STAGE, BattleScript_ButItFailed
BattleScript_ShellSmashTryDef::
	attackanimation
	waitanimation
	setbyte sSTAT_ANIM_PLAYED, FALSE
	playstatchangeanimation BS_ATTACKER, BIT_DEF | BIT_SPDEF, STAT_CHANGE_NEGATIVE | STAT_CHANGE_CANT_PREVENT
	setstatchanger STAT_DEF, 1, TRUE
	statbuffchange MOVE_EFFECT_AFFECTS_ATTACKER | STAT_CHANGE_ALLOW_PTR | MOVE_EFFECT_CERTAIN, BattleScript_ShellSmashTrySpDef
	jumpifbyte CMP_EQUAL, cMULTISTRING_CHOOSER, B_MSG_STAT_WONT_INCREASE, BattleScript_ShellSmashTrySpDef
	printfromtable gStatUpStringIds
	waitmessage B_WAIT_TIME_LONG
BattleScript_ShellSmashTrySpDef:
	setstatchanger STAT_SPDEF, 1, TRUE
	statbuffchange MOVE_EFFECT_AFFECTS_ATTACKER | STAT_CHANGE_ALLOW_PTR | MOVE_EFFECT_CERTAIN, BattleScript_ShellSmashTryAttack
	jumpifbyte CMP_EQUAL, cMULTISTRING_CHOOSER, B_MSG_STAT_WONT_INCREASE, BattleScript_ShellSmashTryAttack
	printfromtable gStatUpStringIds
	waitmessage B_WAIT_TIME_LONG
BattleScript_ShellSmashTryAttack:
	setbyte sSTAT_ANIM_PLAYED, FALSE
	playstatchangeanimation BS_ATTACKER, BIT_SPATK | BIT_ATK | BIT_SPEED, STAT_CHANGE_BY_TWO
	setstatchanger STAT_ATK, 2, FALSE
	statbuffchange MOVE_EFFECT_AFFECTS_ATTACKER | STAT_CHANGE_ALLOW_PTR, BattleScript_ShellSmashTrySpAtk
	jumpifbyte CMP_EQUAL, cMULTISTRING_CHOOSER, B_MSG_STAT_WONT_INCREASE, BattleScript_ShellSmashTrySpAtk
	printfromtable gStatUpStringIds
	waitmessage B_WAIT_TIME_LONG
BattleScript_ShellSmashTrySpAtk:
	setstatchanger STAT_SPATK, 2, FALSE
	statbuffchange MOVE_EFFECT_AFFECTS_ATTACKER | STAT_CHANGE_ALLOW_PTR, BattleScript_ShellSmashTrySpeed
	jumpifbyte CMP_EQUAL, cMULTISTRING_CHOOSER, B_MSG_STAT_WONT_INCREASE, BattleScript_ShellSmashTrySpeed
	printfromtable gStatUpStringIds
	waitmessage B_WAIT_TIME_LONG
BattleScript_ShellSmashTrySpeed:
	setstatchanger STAT_SPEED, 2, FALSE
	statbuffchange MOVE_EFFECT_AFFECTS_ATTACKER | STAT_CHANGE_ALLOW_PTR, BattleScript_ShellSmashEnd
	jumpifbyte CMP_EQUAL, cMULTISTRING_CHOOSER, B_MSG_STAT_WONT_INCREASE, BattleScript_ShellSmashEnd
	printfromtable gStatUpStringIds
	waitmessage B_WAIT_TIME_LONG
BattleScript_ShellSmashEnd:
	goto BattleScript_MoveEnd

BattleScript_ShieldsDownShellSmash::
	jumpifstat BS_ATTACKER, CMP_LESS_THAN, STAT_ATK, MAX_STAT_STAGE, BattleScript_ShieldsDownShellSmashTryAttack
	jumpifstat BS_ATTACKER, CMP_LESS_THAN, STAT_SPATK, MAX_STAT_STAGE, BattleScript_ShieldsDownShellSmashTryAttack
	jumpifstat BS_ATTACKER, CMP_EQUAL, STAT_SPEED, MAX_STAT_STAGE, BattleScript_ButItFailed
BattleScript_ShieldsDownShellSmashTryAttack::
	attackanimation
	waitanimation
	tryremoveshieldsdown
	setbyte sSTAT_ANIM_PLAYED, FALSE
	playstatchangeanimation BS_ATTACKER, BIT_SPATK | BIT_ATK | BIT_SPEED, STAT_CHANGE_BY_TWO
	setstatchanger STAT_ATK, 2, FALSE
	statbuffchange MOVE_EFFECT_AFFECTS_ATTACKER | STAT_CHANGE_ALLOW_PTR, BattleScript_ShieldsDownShellSmashTrySpAtk
	jumpifbyte CMP_EQUAL, cMULTISTRING_CHOOSER, B_MSG_STAT_WONT_INCREASE, BattleScript_ShieldsDownShellSmashTrySpAtk
	printfromtable gStatUpStringIds
	waitmessage B_WAIT_TIME_LONG
BattleScript_ShieldsDownShellSmashTrySpAtk:
	setstatchanger STAT_SPATK, 2, FALSE
	statbuffchange MOVE_EFFECT_AFFECTS_ATTACKER | STAT_CHANGE_ALLOW_PTR, BattleScript_ShieldsDownShellSmashTrySpeed
	jumpifbyte CMP_EQUAL, cMULTISTRING_CHOOSER, B_MSG_STAT_WONT_INCREASE, BattleScript_ShieldsDownShellSmashTrySpeed
	printfromtable gStatUpStringIds
	waitmessage B_WAIT_TIME_LONG
BattleScript_ShieldsDownShellSmashTrySpeed:
	setstatchanger STAT_SPEED, 2, FALSE
	statbuffchange MOVE_EFFECT_AFFECTS_ATTACKER | STAT_CHANGE_ALLOW_PTR, BattleScript_ShieldsDownShellSmashEnd
	jumpifbyte CMP_EQUAL, cMULTISTRING_CHOOSER, B_MSG_STAT_WONT_INCREASE, BattleScript_ShieldsDownShellSmashEnd
	printfromtable gStatUpStringIds
	waitmessage B_WAIT_TIME_LONG
BattleScript_ShieldsDownShellSmashEnd:
	goto BattleScript_MoveEnd

BattleScript_EffectLastResort:
	attackcanceler
	attackstring
	ppreduce
	jumpifcantuselastresort BS_ATTACKER, BattleScript_ButItFailed
	accuracycheck BattleScript_PrintMoveMissed, ACC_CURR_MOVE
	goto BattleScript_HitFromCritCalc

BattleScript_EffectGrowth:
	attackcanceler
	attackstring
	ppreduce
	jumpifstat BS_ATTACKER, CMP_LESS_THAN, STAT_ATK, MAX_STAT_STAGE, BattleScript_GrowthDoMoveAnim
	jumpifstat BS_ATTACKER, CMP_EQUAL, STAT_SPATK, MAX_STAT_STAGE, BattleScript_CantRaiseMultipleStats
BattleScript_GrowthDoMoveAnim::
	attackanimation
	waitanimation
	setbyte sSTAT_ANIM_PLAYED, FALSE
	playstatchangeanimation BS_ATTACKER, BIT_ATK | BIT_SPATK, 0
	jumpifweatheraffected BS_ATTACKER, B_WEATHER_SUN, BattleScript_GrowthAtk2
	setstatchanger STAT_ATK, 1, FALSE
	goto BattleScript_GrowthAtk
BattleScript_GrowthAtk2:
	setstatchanger STAT_ATK, 2, FALSE
BattleScript_GrowthAtk:
	statbuffchange MOVE_EFFECT_AFFECTS_ATTACKER | STAT_CHANGE_ALLOW_PTR, BattleScript_GrowthTrySpAtk
	jumpifbyte CMP_EQUAL, cMULTISTRING_CHOOSER, B_MSG_STAT_WONT_INCREASE, BattleScript_GrowthTrySpAtk
	printfromtable gStatUpStringIds
	waitmessage B_WAIT_TIME_LONG
BattleScript_GrowthTrySpAtk::
	jumpifweatheraffected BS_ATTACKER, B_WEATHER_SUN, BattleScript_GrowthSpAtk2
	setstatchanger STAT_SPATK, 1, FALSE
	goto BattleScript_GrowthSpAtk
BattleScript_GrowthSpAtk2:
	setstatchanger STAT_SPATK, 2, FALSE
BattleScript_GrowthSpAtk:
	statbuffchange MOVE_EFFECT_AFFECTS_ATTACKER | STAT_CHANGE_ALLOW_PTR, BattleScript_GrowthEnd
	jumpifbyte CMP_EQUAL, cMULTISTRING_CHOOSER, B_MSG_STAT_WONT_INCREASE, BattleScript_GrowthEnd
	printfromtable gStatUpStringIds
	waitmessage B_WAIT_TIME_LONG
BattleScript_GrowthEnd:
	goto BattleScript_MoveEnd

BattleScript_EffectSoak:
	attackcanceler
	accuracycheck BattleScript_PrintMoveMissed, ACC_CURR_MOVE
	attackstring
	ppreduce
	jumpifabilityorinnate BS_TARGET, ABILITY_MULTITYPE, BattleScript_ButItFailed
	jumpifabilityorinnate BS_TARGET, ABILITY_RKS_SYSTEM, BattleScript_ButItFailed
	jumpifsubstituteblocks BattleScript_ButItFailed
	attackanimation
	waitanimation
	trysoak BattleScript_ButItFailed
	printstring STRINGID_TRANSFORMEDINTOWATERTYPE
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_EffectReflectType:
	attackcanceler
	accuracycheck BattleScript_PrintMoveMissed, ACC_CURR_MOVE
	attackstring
	ppreduce
	tryreflecttype BattleScript_ButItFailed
	attackanimation
	waitanimation
	printstring STRINGID_REFLECTTARGETSTYPE
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_EffectElectrify:
	attackcanceler
	accuracycheck BattleScript_PrintMoveMissed, ACC_CURR_MOVE
	attackstring
	ppreduce
	tryelectrify BattleScript_ButItFailed
	attackanimation
	waitanimation
	printstring STRINGID_TARGETELECTRIFIED
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_EffectShiftGear:
	attackcanceler
	attackstring
	ppreduce
	jumpifstat BS_ATTACKER, CMP_LESS_THAN, STAT_SPEED, MAX_STAT_STAGE, BattleScript_ShiftGearDoMoveAnim
	jumpifstat BS_ATTACKER, CMP_EQUAL, STAT_ATK, MAX_STAT_STAGE, BattleScript_CantRaiseMultipleStats
BattleScript_ShiftGearDoMoveAnim:
	attackanimation
	waitanimation
	setbyte sSTAT_ANIM_PLAYED, FALSE
	jumpifstat BS_ATTACKER, CMP_GREATER_THAN, STAT_SPEED, 10, BattleScript_ShiftGearSpeedBy1
	playstatchangeanimation BS_ATTACKER, BIT_SPEED | BIT_ATK, STAT_CHANGE_BY_TWO
	setstatchanger STAT_SPEED, 2, FALSE
	goto BattleScript_ShiftGearDoSpeed
BattleScript_ShiftGearSpeedBy1:
	playstatchangeanimation BS_ATTACKER, BIT_SPEED | BIT_ATK, 0
	setstatchanger STAT_SPEED, 1, FALSE
BattleScript_ShiftGearDoSpeed:
	statbuffchange MOVE_EFFECT_AFFECTS_ATTACKER | STAT_CHANGE_ALLOW_PTR, BattleScript_ShiftGearTryAtk
	jumpifbyte CMP_EQUAL, cMULTISTRING_CHOOSER, B_MSG_STAT_WONT_INCREASE, BattleScript_ShiftGearTryAtk
	printfromtable gStatUpStringIds
	waitmessage B_WAIT_TIME_LONG
BattleScript_ShiftGearTryAtk:
	setstatchanger STAT_ATK, 1, FALSE
	statbuffchange MOVE_EFFECT_AFFECTS_ATTACKER | STAT_CHANGE_ALLOW_PTR, BattleScript_ShiftGearEnd
	jumpifbyte CMP_EQUAL, cMULTISTRING_CHOOSER, B_MSG_STAT_WONT_INCREASE, BattleScript_ShiftGearEnd
	printfromtable gStatUpStringIds
	waitmessage B_WAIT_TIME_LONG
BattleScript_ShiftGearEnd:
	goto BattleScript_MoveEnd

BattleScript_EffectCoil:
	attackcanceler
	attackstring
	ppreduce
	setcoil
	jumpifstat BS_ATTACKER, CMP_LESS_THAN, STAT_ATK, MAX_STAT_STAGE, BattleScript_CoilDoMoveAnim
	jumpifstat BS_ATTACKER, CMP_LESS_THAN, STAT_DEF, MAX_STAT_STAGE, BattleScript_CoilDoMoveAnim
	jumpifstat BS_ATTACKER, CMP_EQUAL, STAT_ACC, MAX_STAT_STAGE, BattleScript_CantRaiseMultipleStats
BattleScript_CoilDoMoveAnim:
	attackanimation
	waitanimation
	setbyte sSTAT_ANIM_PLAYED, FALSE
	playstatchangeanimation BS_ATTACKER, BIT_ATK | BIT_DEF | BIT_ACC, 0
	setstatchanger STAT_ATK, 1, FALSE
	statbuffchange MOVE_EFFECT_AFFECTS_ATTACKER | STAT_CHANGE_ALLOW_PTR, BattleScript_CoilTryDef
	jumpifbyte CMP_EQUAL, cMULTISTRING_CHOOSER, B_MSG_STAT_WONT_INCREASE, BattleScript_CoilTryDef
	printfromtable gStatUpStringIds
	waitmessage B_WAIT_TIME_LONG
BattleScript_CoilTryDef:
	setstatchanger STAT_DEF, 1, FALSE
	statbuffchange MOVE_EFFECT_AFFECTS_ATTACKER | STAT_CHANGE_ALLOW_PTR, BattleScript_CoilTryAcc
	jumpifbyte CMP_EQUAL, cMULTISTRING_CHOOSER, B_MSG_STAT_WONT_INCREASE, BattleScript_CoilTryAcc
	printfromtable gStatUpStringIds
	waitmessage B_WAIT_TIME_LONG
BattleScript_CoilTryAcc:
	setstatchanger STAT_ACC, 1, FALSE
	statbuffchange MOVE_EFFECT_AFFECTS_ATTACKER | STAT_CHANGE_ALLOW_PTR, BattleScript_CoilEnd
	jumpifbyte CMP_EQUAL, cMULTISTRING_CHOOSER, B_MSG_STAT_WONT_INCREASE, BattleScript_CoilEnd
	printfromtable gStatUpStringIds
	waitmessage B_WAIT_TIME_LONG
BattleScript_CoilEnd:
	goto BattleScript_MoveEnd

BattleScript_EffectQuiverDance:
	attackcanceler
	attackstring
	ppreduce
	jumpifstat BS_ATTACKER, CMP_LESS_THAN, STAT_SPATK, MAX_STAT_STAGE, BattleScript_QuiverDanceDoMoveAnim
	jumpifstat BS_ATTACKER, CMP_LESS_THAN, STAT_SPDEF, MAX_STAT_STAGE, BattleScript_QuiverDanceDoMoveAnim
	jumpifstat BS_ATTACKER, CMP_EQUAL, STAT_SPEED, MAX_STAT_STAGE, BattleScript_CantRaiseMultipleStats
BattleScript_QuiverDanceDoMoveAnim::
	attackanimation
	waitanimation
	setbyte sSTAT_ANIM_PLAYED, FALSE
	playstatchangeanimation BS_ATTACKER, BIT_SPATK | BIT_SPDEF | BIT_SPEED, 0
	setstatchanger STAT_SPATK, 1, FALSE
	statbuffchange MOVE_EFFECT_AFFECTS_ATTACKER | STAT_CHANGE_ALLOW_PTR, BattleScript_QuiverDanceTrySpDef
	jumpifbyte CMP_EQUAL, cMULTISTRING_CHOOSER, B_MSG_STAT_WONT_INCREASE, BattleScript_QuiverDanceTrySpDef
	printfromtable gStatUpStringIds
	waitmessage B_WAIT_TIME_LONG
BattleScript_QuiverDanceTrySpDef::
	setstatchanger STAT_SPDEF, 1, FALSE
	statbuffchange MOVE_EFFECT_AFFECTS_ATTACKER | STAT_CHANGE_ALLOW_PTR, BattleScript_QuiverDanceTrySpeed
	jumpifbyte CMP_EQUAL, cMULTISTRING_CHOOSER, B_MSG_STAT_WONT_INCREASE, BattleScript_QuiverDanceTrySpeed
	printfromtable gStatUpStringIds
	waitmessage B_WAIT_TIME_LONG
BattleScript_QuiverDanceTrySpeed::
	setstatchanger STAT_SPEED, 1, FALSE
	statbuffchange MOVE_EFFECT_AFFECTS_ATTACKER | STAT_CHANGE_ALLOW_PTR, BattleScript_QuiverDanceEnd
	jumpifbyte CMP_EQUAL, cMULTISTRING_CHOOSER, B_MSG_STAT_WONT_INCREASE, BattleScript_QuiverDanceEnd
	printfromtable gStatUpStringIds
	waitmessage B_WAIT_TIME_LONG
BattleScript_QuiverDanceEnd::
	goto BattleScript_MoveEnd

BattleScript_EffectSpeedUpHit:
	setmoveeffect MOVE_EFFECT_SPD_PLUS_1 | MOVE_EFFECT_AFFECTS_ATTACKER
	goto BattleScript_EffectHit

BattleScript_EffectMeFirst:
	attackcanceler
	attackstring
	trymefirst BattleScript_FailedFromPpReduce
	attackanimation
	waitanimation
	setbyte sB_ANIM_TURN, 0
	setbyte sB_ANIM_TARGETS_HIT, 0
	jumptocalledmove TRUE

BattleScript_EffectAttackSpAttackUp:
	attackcanceler
	attackstring
	ppreduce
	jumpifstat BS_ATTACKER, CMP_LESS_THAN, STAT_ATK, MAX_STAT_STAGE, BattleScript_AttackSpAttackUpDoMoveAnim
	jumpifstat BS_ATTACKER, CMP_EQUAL, STAT_SPATK, MAX_STAT_STAGE, BattleScript_CantRaiseMultipleStats
BattleScript_AttackSpAttackUpDoMoveAnim::
	attackanimation
	waitanimation
	setbyte sSTAT_ANIM_PLAYED, FALSE
	playstatchangeanimation BS_ATTACKER, BIT_ATK | BIT_SPATK, 0
	setstatchanger STAT_ATK, 1, FALSE
	statbuffchange MOVE_EFFECT_AFFECTS_ATTACKER | STAT_CHANGE_ALLOW_PTR, BattleScript_AttackSpAttackUpTrySpAtk
	jumpifbyte CMP_EQUAL, cMULTISTRING_CHOOSER, B_MSG_STAT_WONT_INCREASE, BattleScript_AttackSpAttackUpTrySpAtk
	printfromtable gStatUpStringIds
	waitmessage B_WAIT_TIME_LONG
BattleScript_AttackSpAttackUpTrySpAtk::
	setstatchanger STAT_SPATK, 1, FALSE
	statbuffchange MOVE_EFFECT_AFFECTS_ATTACKER | STAT_CHANGE_ALLOW_PTR, BattleScript_AttackSpAttackUpEnd
	jumpifbyte CMP_EQUAL, cMULTISTRING_CHOOSER, B_MSG_STAT_WONT_INCREASE, BattleScript_AttackSpAttackUpEnd
	printfromtable gStatUpStringIds
	waitmessage B_WAIT_TIME_LONG
BattleScript_AttackSpAttackUpEnd:
	goto BattleScript_MoveEnd

BattleScript_EffectAttackAccUp:
	attackcanceler
	attackstring
	ppreduce
	setbattlerstatus BS_ATTACKER, 4, STATUS4_HONE_CLAWS, BattleScript_AttackAccUpContinue
BattleScript_AttackAccUpContinue:
	jumpifstat BS_ATTACKER, CMP_LESS_THAN, STAT_ATK, MAX_STAT_STAGE, BattleScript_AttackAccUpDoMoveAnim
	jumpifstat BS_ATTACKER, CMP_EQUAL, STAT_ACC, MAX_STAT_STAGE, BattleScript_CantRaiseMultipleStats
BattleScript_AttackAccUpDoMoveAnim::
	attackanimation
	waitanimation
	setbyte sSTAT_ANIM_PLAYED, FALSE
	playstatchangeanimation BS_ATTACKER, BIT_SPATK | BIT_SPDEF, 0
	setstatchanger STAT_ATK, 1, FALSE
	statbuffchange MOVE_EFFECT_AFFECTS_ATTACKER | STAT_CHANGE_ALLOW_PTR, BattleScript_AttackAccUpTrySpDef
	jumpifbyte CMP_EQUAL, cMULTISTRING_CHOOSER, B_MSG_STAT_WONT_INCREASE, BattleScript_AttackAccUpTrySpDef
	printfromtable gStatUpStringIds
	waitmessage B_WAIT_TIME_LONG
BattleScript_AttackAccUpTrySpDef::
	setstatchanger STAT_ACC, 1, FALSE
	statbuffchange MOVE_EFFECT_AFFECTS_ATTACKER | STAT_CHANGE_ALLOW_PTR, BattleScript_AttackAccUpEnd
	jumpifbyte CMP_EQUAL, cMULTISTRING_CHOOSER, B_MSG_STAT_WONT_INCREASE, BattleScript_AttackAccUpEnd
	printfromtable gStatUpStringIds
	waitmessage B_WAIT_TIME_LONG
BattleScript_AttackAccUpEnd:
	goto BattleScript_MoveEnd

BattleScript_EffectCursedTerrain:
BattleScript_EffectRavineTerrain:
BattleScript_EffectBurningTerrain:
BattleScript_EffectSandyTerrain:
BattleScript_EffectSwampTerrain:
BattleScript_EffectVenomousTerrain:
BattleScript_EffectFrozenTerrain:
BattleScript_EffectMistyTerrain:
BattleScript_EffectGrassyTerrain:
BattleScript_EffectElectricTerrain:
BattleScript_EffectPsychicTerrain:
	attackcanceler
	attackstring
	ppreduce
	setterrain BattleScript_ButItFailed
	attackanimation
	waitanimation
	printfromtable gTerrainStringIds
	waitmessage B_WAIT_TIME_LONG
	playanimation BS_ATTACKER, B_ANIM_RESTORE_BG, NULL
	call BattleScript_TerrainFormChanges
	call BattleScript_TerrainSeedLoop
	goto BattleScript_MoveEnd

BattleScript_EffectTopsyTurvy:
	attackcanceler
	attackstring
	ppreduce
	accuracycheck BattleScript_ButItFailed, NO_ACC_CALC_CHECK_LOCK_ON
	jumpifstat BS_TARGET, CMP_NOT_EQUAL, STAT_ATK, 6, BattleScript_EffectTopsyTurvyWorks
	jumpifstat BS_TARGET, CMP_NOT_EQUAL, STAT_DEF, 6, BattleScript_EffectTopsyTurvyWorks
	jumpifstat BS_TARGET, CMP_NOT_EQUAL, STAT_SPATK, 6, BattleScript_EffectTopsyTurvyWorks
	jumpifstat BS_TARGET, CMP_NOT_EQUAL, STAT_SPDEF, 6, BattleScript_EffectTopsyTurvyWorks
	jumpifstat BS_TARGET, CMP_NOT_EQUAL, STAT_SPEED, 6, BattleScript_EffectTopsyTurvyWorks
	jumpifstat BS_TARGET, CMP_NOT_EQUAL, STAT_ACC, 6, BattleScript_EffectTopsyTurvyWorks
	jumpifstat BS_TARGET, CMP_EQUAL, STAT_EVASION, 6, BattleScript_ButItFailed
BattleScript_EffectTopsyTurvyWorks:
	attackanimation
	waitanimation
	invertstatstages BS_TARGET
	printstring STRINGID_TOPSYTURVYSWITCHEDSTATS
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_EffectIonDeluge:
	attackcanceler
	accuracycheck BattleScript_PrintMoveMissed, ACC_CURR_MOVE
	attackstring
	ppreduce
	orword gFieldStatuses, STATUS_FIELD_ION_DELUGE
	attackanimation
	waitanimation
	printstring STRINGID_IONDELUGEON
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_EffectQuash:
	attackcanceler
	accuracycheck BattleScript_PrintMoveMissed, ACC_CURR_MOVE
	attackstring
	ppreduce
	tryquash BattleScript_ButItFailed
	attackanimation
	waitanimation
	printstring STRINGID_QUASHSUCCESS
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_EffectHealPulse:
	attackcanceler
	attackstring
	ppreduce
	accuracycheck BattleScript_ButItFailed, NO_ACC_CALC_CHECK_LOCK_ON
	jumpifsubstituteblocks BattleScript_ButItFailed
	tryhealpulse BS_TARGET, BattleScript_AlreadyAtFullHp
	attackanimation
	waitanimation
	healthbarupdate BS_TARGET
	datahpupdate BS_TARGET
	printstring STRINGID_PKMNREGAINEDHEALTH
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_EffectEntrainment:
	attackcanceler
	accuracycheck BattleScript_PrintMoveMissed, ACC_CURR_MOVE
	attackstring
	ppreduce
	tryentrainment BattleScript_ButItFailed
	attackanimation
	waitanimation
	setlastusedability BS_TARGET
	printstring STRINGID_PKMNACQUIREDABILITY
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_EffectSimpleBeam:
	attackcanceler
	accuracycheck BattleScript_PrintMoveMissed, ACC_CURR_MOVE
	attackstring
	ppreduce
	setabilitysimple BS_TARGET, BattleScript_ButItFailed
	attackanimation
	waitanimation
	printstring STRINGID_PKMNACQUIREDSIMPLE
	waitmessage B_WAIT_TIME_LONG
	trytoclearprimalweather
	printstring STRINGID_EMPTYSTRING3
	waitmessage 1
	tryendneutralizinggas BS_TARGET
	goto BattleScript_MoveEnd

BattleScript_EffectSuckerPunch:
	attackcanceler
	suckerpunchcheck BattleScript_FailedFromAtkString
	accuracycheck BattleScript_PrintMoveMissed, ACC_CURR_MOVE
	goto BattleScript_HitFromAtkString

BattleScript_EffectLuckyChant:
	attackcanceler
	attackstring
	ppreduce
	setluckychant BS_ATTACKER, BattleScript_ButItFailed
	attackanimation
	waitanimation
	printstring STRINGID_SHIELDEDFROMCRITICALHITS
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_EffectMetalBurst:
	attackcanceler
	metalburstdamagecalculator BattleScript_FailedFromAtkString
	accuracycheck BattleScript_PrintMoveMissed, ACC_CURR_MOVE
	attackstring
	ppreduce
	typecalc
	bichalfword gMoveResultFlags, MOVE_RESULT_NOT_VERY_EFFECTIVE | MOVE_RESULT_SUPER_EFFECTIVE
	adjustdamage
	goto BattleScript_HitFromAtkAnimation

BattleScript_EffectHealingWish:
	attackcanceler
	jumpifcantswitch SWITCH_IGNORE_ESCAPE_PREVENTION | BS_ATTACKER, BattleScript_FailedFromAtkString
	attackstring
	ppreduce
	attackanimation
	waitanimation
	instanthpdrop BS_ATTACKER
	setatkhptozero
	tryfaintmon BS_ATTACKER, FALSE, NULL
	openpartyscreen BS_ATTACKER, BattleScript_EffectHealingWishEnd
	switchoutabilitiesorinnates BS_ATTACKER, 0
	switchoutabilitiesorinnates BS_ATTACKER, 1
	switchoutabilitiesorinnates BS_ATTACKER, 2
	switchoutabilitiesorinnates BS_ATTACKER, 3
	swithchoutrevolvingruin BS_ATTACKER
	waitstate
	switchhandleorder BS_ATTACKER, 2
	returnatktoball
	getswitchedmondata BS_ATTACKER
	switchindataupdate BS_ATTACKER
	hpthresholds BS_ATTACKER
	trytoclearprimalweather
	printstring STRINGID_EMPTYSTRING3
	waitmessage 1
	printstring STRINGID_SWITCHINMON
	switchinanim BS_ATTACKER, TRUE
	waitstate
	setbyte cMULTISTRING_CHOOSER 0
	jumpifnotchosenmove MOVE_LUNAR_DANCE BattleScript_EffectHealingWishNewMon
	setbyte cMULTISTRING_CHOOSER 1
	restorepp BS_ATTACKER
BattleScript_EffectHealingWishNewMon:
	printfromtable gHealingWishStringIds
	waitmessage B_WAIT_TIME_LONG
	playanimation BS_ATTACKER, B_ANIM_WISH_HEAL, NULL
	waitanimation
	dmgtomaxattackerhp
	manipulatedamage DMG_CHANGE_SIGN
	healthbarupdate BS_ATTACKER
	datahpupdate BS_ATTACKER
	clearstatus BS_ATTACKER
	waitstate
	updatestatusicon BS_ATTACKER
	waitstate
	printstring STRINGID_HEALINGWISHHEALED
	waitmessage B_WAIT_TIME_LONG
	switchineffects BS_ATTACKER
BattleScript_EffectHealingWishEnd:
	moveendall
	end

BattleScript_EffectWorrySeed:
	attackcanceler
	accuracycheck BattleScript_PrintMoveMissed, ACC_CURR_MOVE
	attackstring
	ppreduce
	tryworryseed BattleScript_ButItFailed
	attackanimation
	waitanimation
	printstring STRINGID_PKMNACQUIREDABILITY
	waitmessage B_WAIT_TIME_LONG
	trytoclearprimalweather
	printstring STRINGID_EMPTYSTRING3
	waitmessage 1
	goto BattleScript_MoveEnd

BattleScript_EffectPowerSplit:
	attackcanceler
	attackstring
	ppreduce
	accuracycheck BattleScript_ButItFailed, NO_ACC_CALC_CHECK_LOCK_ON
	averagestats STAT_ATK
	averagestats STAT_SPATK
	attackanimation
	waitanimation
	printstring STRINGID_SHAREDITSPOWER
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_EffectGuardSplit:
	attackcanceler
	attackstring
	ppreduce
	accuracycheck BattleScript_ButItFailed, NO_ACC_CALC_CHECK_LOCK_ON
	averagestats STAT_DEF
	averagestats STAT_SPDEF
	attackanimation
	waitanimation
	printstring STRINGID_SHAREDITSGUARD
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_EffectHeartSwap:
	attackcanceler
	attackstring
	ppreduce
	accuracycheck BattleScript_ButItFailed, NO_ACC_CALC_CHECK_LOCK_ON
	swapstatstages STAT_ATK
	swapstatstages STAT_DEF
	swapstatstages STAT_SPEED
	swapstatstages STAT_SPATK
	swapstatstages STAT_SPDEF
	swapstatstages STAT_EVASION
	swapstatstages STAT_ACC
	attackanimation
	waitanimation
	printstring STRINGID_PKMNSWITCHEDSTATCHANGES
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_EffectPowerSwap:
	attackcanceler
	attackstring
	ppreduce
	accuracycheck BattleScript_ButItFailed, NO_ACC_CALC_CHECK_LOCK_ON
	swapstatstages STAT_ATK
	swapstatstages STAT_SPATK
	attackanimation
	waitanimation
	printstring STRINGID_PKMNSWITCHEDSTATCHANGES
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_EffectGuardSwap:
	attackcanceler
	attackstring
	ppreduce
	accuracycheck BattleScript_ButItFailed, NO_ACC_CALC_CHECK_LOCK_ON
	swapstatstages STAT_DEF
	swapstatstages STAT_SPDEF
	attackanimation
	waitanimation
	printstring STRINGID_PKMNSWITCHEDSTATCHANGES
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_EffectSpeedSwap:
	attackcanceler
	attackstring
	ppreduce
	accuracycheck BattleScript_ButItFailed, NO_ACC_CALC_CHECK_LOCK_ON
	swapstatstages STAT_SPEED
	attackanimation
	waitanimation
	printstring STRINGID_PKMNSWITCHEDSTATCHANGES
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_EffectTelekinesis:
	attackcanceler
	accuracycheck BattleScript_PrintMoveMissed, NO_ACC_CALC_CHECK_LOCK_ON
	attackstring
	ppreduce
	settelekinesis BattleScript_ButItFailed
	attackanimation
	waitanimation
	printstring STRINGID_HURLEDINTOTHEAIR
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_EffectStealthRock:
	attackcanceler
	attackstring
	ppreduce
	setstealthrock BattleScript_ButItFailed
	attackanimation
	waitanimation
	printstring STRINGID_POINTEDSTONESFLOAT
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_EffectStickyWeb:
	attackcanceler
	attackstring
	ppreduce
	setstickyweb BattleScript_ButItFailed
	attackanimation
	waitanimation
	printstring STRINGID_STICKYWEBUSED
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_EffectGastroAcid:
	attackcanceler
	accuracycheck BattleScript_PrintMoveMissed, ACC_CURR_MOVE
	attackstring
	ppreduce
	setgastroacid BattleScript_ButItFailed
	attackanimation
	waitanimation
	printstring STRINGID_PKMNSABILITYSUPPRESSED
	waitmessage B_WAIT_TIME_LONG
	trytoclearprimalweather
	printstring STRINGID_EMPTYSTRING3
	waitmessage 1
	tryendneutralizinggas BS_TARGET
	goto BattleScript_MoveEnd

BattleScript_EffectToxicSpikes:
	attackcanceler
	attackstring
	ppreduce
	settoxicspikes BattleScript_ButItFailed
	attackanimation
	waitanimation
	printstring STRINGID_POISONSPIKESSCATTERED
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_EffectMagnetRise:
	attackcanceler
	attackstring
	ppreduce
	setbattlerstatus BS_ATTACKER, 3, STATUS3_MAGNET_RISE, BattleScript_ButItFailed
	attackanimation
	waitanimation
	printstring STRINGID_PKMNLEVITATEDONELECTROMAGNETISM
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_EffectTrickRoom:
	attackcanceler
	attackstring
	ppreduce
	setroom
	attackanimation
	waitanimation
	printfromtable gRoomsStringIds
	waitmessage B_WAIT_TIME_LONG
	savetarget
	setbyte gBattlerTarget, 0
BattleScript_RoomServiceLoop:
	copybyte sBATTLER, gBattlerTarget
	tryroomservice BS_TARGET, BattleScript_RoomServiceLoop_NextBattler
	removeitem BS_TARGET, 1
BattleScript_RoomServiceLoop_NextBattler:
	addbyte gBattlerTarget, 0x1
	jumpifbytenotequal gBattlerTarget, gBattlersCount, BattleScript_RoomServiceLoop
	restoretarget
	goto BattleScript_MoveEnd
	
BattleScript_EffectWonderRoom:
BattleScript_EffectMagicRoom:
	attackcanceler
	attackstring
	ppreduce
	setroom
	attackanimation
	waitanimation
	printfromtable gRoomsStringIds
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_EffectAquaRing:
	attackcanceler
	attackstring
	ppreduce
	setbattlerstatus BS_ATTACKER, 3, STATUS3_AQUA_RING, BattleScript_ButItFailed
	attackanimation
	waitanimation
	printstring STRINGID_PKMNSURROUNDEDWITHVEILOFWATER
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_EffectEmbargo:
	attackcanceler
	accuracycheck BattleScript_PrintMoveMissed, ACC_CURR_MOVE
	attackstring
	ppreduce
	setembargo BattleScript_ButItFailed
	attackanimation
	waitanimation
	printstring STRINGID_PKMNCANTUSEITEMSANYMORE
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_EffectTailwind:
	attackcanceler
	attackstring
	ppreduce
	settailwind BattleScript_ButItFailed
	attackanimation
	waitanimation
	printstring STRINGID_TAILWINDBLEW
	waitmessage B_WAIT_TIME_LONG
	call BattleScript_WeatherFormChanges
	goto BattleScript_MoveEnd

BattleScript_EffectMircleEye:
	attackcanceler
	accuracycheck BattleScript_PrintMoveMissed, ACC_CURR_MOVE
	attackstring
	ppreduce
	setmiracleeye BattleScript_ButItFailed
	goto BattleScript_IdentifiedFoe

BattleScript_EffectGravity:
	attackcanceler
	attackstring
	ppreduce
	setgravity BattleScript_ButItFailed
	attackanimation
	waitanimation
	printstring STRINGID_GRAVITYINTENSIFIED 
	waitmessage B_WAIT_TIME_LONG
	selectfirstvalidtarget
BattleScript_GravityLoop:
	movevaluescleanup
	jumpifstatus3 BS_TARGET, STATUS3_ON_AIR | STATUS3_MAGNET_RISE | STATUS3_TELEKINESIS, BattleScript_GravityLoopDrop
	goto BattleScript_GravityLoopEnd
BattleScript_GravityLoopDrop:
	bringdownairbornebattler BS_TARGET
	printstring STRINGID_GRAVITYGROUNDING 
	waitmessage B_WAIT_TIME_LONG
BattleScript_GravityLoopEnd:	
	moveendto MOVEEND_NEXT_TARGET
	jumpifnexttargetvalid BattleScript_GravityLoop
	end

BattleScript_EffectRoost:
	attackcanceler
	attackstring
	ppreduce
	tryhealhalfhealth BattleScript_AlreadyAtFullHp, BS_TARGET
	setroost
	goto BattleScript_PresentHealTarget

BattleScript_EffectCaptivate:
	setstatchanger STAT_SPATK, 2, TRUE
	attackcanceler
	jumpifsubstituteblocks BattleScript_FailedFromAtkString
	jumpifoppositegenders BattleScript_CaptivateCheckAcc
	goto BattleScript_FailedFromAtkString
BattleScript_CaptivateCheckAcc:
	accuracycheck BattleScript_PrintMoveMissed, ACC_CURR_MOVE
	goto BattleScript_StatDownFromAttackString

BattleScript_EffectHealBlock:
	attackcanceler
	accuracycheck BattleScript_PrintMoveMissed, ACC_CURR_MOVE
	attackstring
	ppreduce
	jumpifabilityorinnate BS_TARGET_SIDE, ABILITY_AROMA_VEIL, BattleScript_AromaVeilProtects
	sethealblock BattleScript_ButItFailed
	attackanimation
	waitanimation
	printstring STRINGID_PKMNPREVENTEDFROMHEALING
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_EffectThroatChop:
	jumpifsubstituteblocks BattleScript_EffectHit
	setmoveeffect MOVE_EFFECT_THROAT_CHOP | MOVE_EFFECT_CERTAIN
	goto BattleScript_EffectHit

BattleScript_EffectHitEscape:
	attackcanceler
	accuracycheck BattleScript_PrintMoveMissed, ACC_CURR_MOVE
	attackstring
	ppreduce
	call BattleScript_EffectDamage_Ret
	jumpifmovehadnoeffect BattleScript_MoveEnd
	jumpifabilityorinnate BS_TARGET, ABILITY_GUARD_DOG, BattleScript_MoveEnd
	seteffectwithchance
	tryfaintmon BS_TARGET, FALSE, NULL
BattleScript_TryToEscape:
	moveendto MOVEEND_ATTACKER_VISIBLE
	moveendfrom MOVEEND_TARGET_VISIBLE
	jumpifbattleend BattleScript_HitEscapeEnd
	jumpifbyte CMP_NOT_EQUAL gBattleOutcome 0, BattleScript_HitEscapeEnd
	jumpifbattletype BATTLE_TYPE_ARENA, BattleScript_HitEscapeEnd
	jumpifcantswitch SWITCH_IGNORE_ESCAPE_PREVENTION | BS_ATTACKER, BattleScript_HitEscapeEnd
	openpartyscreen BS_ATTACKER, BattleScript_HitEscapeEnd
	switchoutabilitiesorinnates BS_ATTACKER, 0
	switchoutabilitiesorinnates BS_ATTACKER, 1
	switchoutabilitiesorinnates BS_ATTACKER, 2
	switchoutabilitiesorinnates BS_ATTACKER, 3
	swithchoutrevolvingruin BS_ATTACKER
	waitstate
	switchhandleorder BS_ATTACKER, 2
	returntoball BS_ATTACKER
	getswitchedmondata BS_ATTACKER
	switchindataupdate BS_ATTACKER
	hpthresholds BS_ATTACKER
	trytoclearprimalweather
	printstring STRINGID_EMPTYSTRING3
	waitmessage 1
	printstring STRINGID_SWITCHINMON
	switchinanim BS_ATTACKER, TRUE
	waitstate
	switchineffects BS_ATTACKER
BattleScript_HitEscapeEnd:
	end

BattleScript_EffectPlaceholder:
	attackcanceler
	attackstring
	ppreduce
	pause 5
	printstring STRINGID_NOTDONEYET
	goto BattleScript_MoveEnd

BattleScript_EffectHit::
BattleScript_HitFromAtkCanceler::
	attackcanceler
BattleScript_HitFromAccCheck::
	accuracycheck BattleScript_PrintMoveMissed, ACC_CURR_MOVE
BattleScript_HitFromAtkString::
	attackstring
	ppreduce
BattleScript_HitFromCritCalc::
	critcalc
	damagecalc
	adjustdamage
BattleScript_HitFromAtkAnimation::
	attackanimation
	waitanimation
	effectivenesssound
	hitanimation BS_TARGET
	waitstate
	healthbarupdate BS_TARGET
	datahpupdate BS_TARGET
	critmessage
	waitmessage B_WAIT_TIME_LONG
	resultmessage
	waitmessage B_WAIT_TIME_LONG
	seteffectwithchance
	tryfaintmon BS_TARGET, FALSE, NULL
BattleScript_MoveEnd::
	moveendall
	end

BattleScript_EffectHit_Ret::
	attackcanceler
	accuracycheck BattleScript_PrintMoveMissed, ACC_CURR_MOVE
BattleScript_EffectAtkString_Ret::
	attackstring
	ppreduce
BattleScript_EffectDamage_Ret::
	critcalc
	damagecalc
	adjustdamage
	attackanimation
	waitanimation
	effectivenesssound
	hitanimation BS_TARGET
	waitstate
	healthbarupdate BS_TARGET
	datahpupdate BS_TARGET
	critmessage
	waitmessage B_WAIT_TIME_LONG
	resultmessage
	waitmessage B_WAIT_TIME_LONG
	return

BattleScript_EffectNaturalGift:
	attackcanceler
	attackstring
	ppreduce
	jumpifnotberry BS_ATTACKER, BattleScript_ButItFailed
	jumpifword CMP_COMMON_BITS, gFieldStatuses, STATUS_FIELD_MAGIC_ROOM, BattleScript_ButItFailed
	jumpifabilityorinnate BS_ATTACKER, ABILITY_KLUTZ, BattleScript_ButItFailed
	jumpifabilityorinnate BS_ATTACKER, ABILITY_OLD_SCHOOL, BattleScript_ButItFailed
	jumpifstatus3 BS_ATTACKER, STATUS3_EMBARGO, BattleScript_ButItFailed
	accuracycheck BattleScript_MoveMissedPause, ACC_CURR_MOVE
	call BattleScript_EffectDamage_Ret
	seteffectwithchance
	jumpifmovehadnoeffect BattleScript_EffectNaturalGiftEnd
	removeitem BS_ATTACKER, 1
BattleScript_EffectNaturalGiftEnd:
	tryfaintmon BS_TARGET, FALSE, NULL
	goto BattleScript_MoveEnd

BattleScript_MakeMoveMissed::
	orhalfword gMoveResultFlags, MOVE_RESULT_MISSED
BattleScript_PrintMoveMissed::
	attackstring
	ppreduce
BattleScript_MoveMissedPause::
	pause B_WAIT_TIME_SHORT
BattleScript_MoveMissed::
	effectivenesssound
	resultmessage
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_EffectSleep::
	attackcanceler
	attackstring
	ppreduce
	jumpifsubstituteblocks BattleScript_ButItFailed
	jumpifstatus BS_TARGET, STATUS1_SLEEP, BattleScript_AlreadyAsleep
	jumpifcantmakeasleep BattleScript_CantMakeAsleep
	jumpifabilityorinnate BS_TARGET, ABILITY_COMATOSE, BattleScript_LeafGuardProtects
	jumpifabilityorinnate BS_TARGET, ABILITY_PURIFYING_SALT, BattleScript_LeafGuardProtects
	jumpifflowerveil BattleScript_FlowerVeilProtects
	jumpifabilityorinnate BS_TARGET_SIDE, ABILITY_SWEET_VEIL, BattleScript_SweetVeilProtects
	jumpifleafguardprotected BS_TARGET, BattleScript_LeafGuardProtects
	jumpifshieldsdown BS_TARGET, BattleScript_LeafGuardProtects
	jumpifstatus BS_TARGET, STATUS1_ANY, BattleScript_ButItFailed
	jumpifterrainaffected BS_TARGET, STATUS_FIELD_ELECTRIC_TERRAIN, BattleScript_ElectricTerrainPrevents
	jumpifterrainaffected BS_TARGET, STATUS_FIELD_BURNING_TERRAIN, BattleScript_BurningTerrainPrevents
	jumpifterrainaffected BS_TARGET, STATUS_FIELD_MISTY_TERRAIN, BattleScript_MistyTerrainPrevents
	accuracycheck BattleScript_ButItFailed, ACC_CURR_MOVE
	jumpifsafeguard BattleScript_SafeguardProtected
	jumpifkingsgrace BattleScript_KingsGraceProtected
	attackanimation
	waitanimation
	setmoveeffect MOVE_EFFECT_SLEEP
	seteffectprimary
	goto BattleScript_MoveEnd
	
BattleScript_TerrainPreventsEnd2::
	pause B_WAIT_TIME_SHORT
	printfromtable gTerrainPreventsStringIds
	waitmessage B_WAIT_TIME_LONG
	end2
	
BattleScript_BurningTerrainPrevents::
	pause B_WAIT_TIME_SHORT
	printstring STRINGID_BURNINGTERRAINPREVENTS
	waitmessage B_WAIT_TIME_LONG
	orhalfword gMoveResultFlags, MOVE_RESULT_FAILED
	goto BattleScript_MoveEnd
	
BattleScript_ElectricTerrainPrevents::
	pause B_WAIT_TIME_SHORT
	printstring STRINGID_ELECTRICTERRAINPREVENTS
	waitmessage B_WAIT_TIME_LONG
	orhalfword gMoveResultFlags, MOVE_RESULT_FAILED
	goto BattleScript_MoveEnd

BattleScript_MistyTerrainPrevents::
	pause B_WAIT_TIME_SHORT
	printstring STRINGID_MISTYTERRAINPREVENTS
	waitmessage B_WAIT_TIME_LONG
	orhalfword gMoveResultFlags, MOVE_RESULT_FAILED
	goto BattleScript_MoveEnd

BattleScript_FlowerVeilProtectsRet::
	pause B_WAIT_TIME_SHORT
	call BattleScript_AbilityPopUp
	printstring STRINGID_FLOWERVEILPROTECTED
	waitmessage B_WAIT_TIME_LONG
	return

BattleScript_FlowerVeilProtects:
	call BattleScript_FlowerVeilProtectsRet
	orhalfword gMoveResultFlags, MOVE_RESULT_FAILED
	goto BattleScript_MoveEnd

BattleScript_SweetVeilProtectsRet::
	pause B_WAIT_TIME_SHORT
	call BattleScript_AbilityPopUp
	printstring STRINGID_FLOWERVEILPROTECTED
	waitmessage B_WAIT_TIME_LONG
	return

BattleScript_SweetVeilProtects:
	call BattleScript_SweetVeilProtectsRet
	orhalfword gMoveResultFlags, MOVE_RESULT_FAILED
	goto BattleScript_MoveEnd

BattleScript_AromaVeilProtectsRet::
	pause B_WAIT_TIME_SHORT
	call BattleScript_AbilityPopUp
	printstring STRINGID_AROMAVEILPROTECTED
	waitmessage B_WAIT_TIME_LONG
	return

BattleScript_AromaVeilProtects:
	call BattleScript_AromaVeilProtectsRet
	orhalfword gMoveResultFlags, MOVE_RESULT_FAILED
	goto BattleScript_MoveEnd

BattleScript_GoodAsGoldActivates::
	attackstring
	ppreduce
	call BattleScript_AbilityPopUp
	pause B_WAIT_TIME_SHORT
	printstring STRINGID_ITDOESNTAFFECT
	waitmessage B_WAIT_TIME_MED
	goto BattleScript_MoveEnd

BattleScript_RuinAbilityActivates::
	call BattleScript_AbilityPopUp
	printstring STRINGID_ABILITYWEAKENEDFSURROUNDINGMONSSTAT
	waitmessage B_WAIT_TIME_LONG
	end3

BattleScript_CostarActivates::
	pause B_WAIT_TIME_SHORT
	call BattleScript_AbilityPopUp
	printstring STRINGID_PKMNCOPIEDSTATCHANGES
	waitmessage B_WAIT_TIME_LONG
	end3

BattleScript_ZeroToHeroActivates::
	pause B_WAIT_TIME_SHORT
	call BattleScript_AbilityPopUp
	printstring STRINGID_ZEROTOHEROTRANSFORMATION
	waitmessage B_WAIT_TIME_LONG
	end3

@ remove the mirror herb, do totem loop
BattleScript_MirrorHerbCopyStatChangeEnd2::
	call BattleScript_MirrorHerbCopyStatChange
	end2

BattleScript_MirrorHerbCopyStatChange::
	playanimation BS_SCRIPTING, B_ANIM_HELD_ITEM_EFFECT, NULL
	printstring STRINGID_MIRRORHERBCOPIED
	waitmessage B_WAIT_TIME_LONG
	removeitem BS_SCRIPTING
	call BattleScript_TotemVar_Ret
	copybyte gBattlerAttacker, sSAVED_BATTLER	@ restore the original attacker just to be safe
	return

BattleScript_OpportunistCopyStatChange::
	call BattleScript_AbilityPopUp
	printstring STRINGID_OPPORTUNISTCOPIED
	waitmessage B_WAIT_TIME_LONG
	call BattleScript_TotemVar_Ret
	copybyte gBattlerAttacker, sSAVED_BATTLER	@ restore the original attacker just to be safe
	end3

BattleScript_TotemVar::
	call BattleScript_TotemVar_Ret
	end2

BattleScript_TotemVar_Ret::
	gettotemboost BattleScript_ApplyTotemVarBoost
BattleScript_TotemVarEnd:
	return
BattleScript_ApplyTotemVarBoost:
	statbuffchange STAT_CHANGE_ALLOW_PTR, BattleScript_TotemVarEnd
	setgraphicalstatchangevalues
	playanimation BS_SCRIPTING, B_ANIM_STATS_CHANGE, sB_ANIM_ARG1
	printfromtable gStatUpStringIds
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_TotemVar_Ret  @loop until stats bitfield is empty

BattleScript_SeedSowerActivates::
	pause B_WAIT_TIME_SHORT
	call BattleScript_AbilityPopUp
	printstring STRINGID_TERRAINBECOMESGRASSY
	waitmessage B_WAIT_TIME_LONG
	playanimation BS_SCRIPTING, B_ANIM_RESTORE_BG, NULL
	call BattleScript_TerrainFormChanges
	return

BattleScript_AngerShellActivates::
	call BattleScript_AbilityPopUp
	jumpifstat BS_TARGET, CMP_LESS_THAN, STAT_ATK, MAX_STAT_STAGE, BattleScript_AngerShellTryDef
	jumpifstat BS_TARGET, CMP_LESS_THAN, STAT_SPATK, MAX_STAT_STAGE, BattleScript_AngerShellTryDef
	jumpifstat BS_TARGET, CMP_LESS_THAN, STAT_SPEED, MAX_STAT_STAGE, BattleScript_AngerShellTryDef
	jumpifstat BS_TARGET, CMP_GREATER_THAN, STAT_DEF, MIN_STAT_STAGE, BattleScript_AngerShellTryDef
	jumpifstat BS_TARGET, CMP_EQUAL, STAT_SPDEF, MIN_STAT_STAGE, BattleScript_ButItFailed
BattleScript_AngerShellTryDef::
	setbyte sSTAT_ANIM_PLAYED, FALSE
	playstatchangeanimation BS_ATTACKER, BIT_DEF | BIT_SPDEF, STAT_CHANGE_NEGATIVE | STAT_CHANGE_CANT_PREVENT
	setstatchanger STAT_DEF, 1, TRUE
	statbuffchange MOVE_EFFECT_AFFECTS_ATTACKER | STAT_CHANGE_ALLOW_PTR | MOVE_EFFECT_CERTAIN, BattleScript_AngerShellTrySpDef
	jumpifbyte CMP_EQUAL, cMULTISTRING_CHOOSER, B_MSG_STAT_WONT_INCREASE, BattleScript_AngerShellTrySpDef
	printfromtable gStatUpStringIds
	waitmessage B_WAIT_TIME_LONG
BattleScript_AngerShellTrySpDef:
	setstatchanger STAT_SPDEF, 1, TRUE
	statbuffchange MOVE_EFFECT_AFFECTS_ATTACKER | STAT_CHANGE_ALLOW_PTR | MOVE_EFFECT_CERTAIN, BattleScript_AngerShellTryAttack
	jumpifbyte CMP_EQUAL, cMULTISTRING_CHOOSER, B_MSG_STAT_WONT_INCREASE, BattleScript_AngerShellTryAttack
	printfromtable gStatUpStringIds
	waitmessage B_WAIT_TIME_LONG
BattleScript_AngerShellTryAttack:
	setbyte sSTAT_ANIM_PLAYED, FALSE
	playstatchangeanimation BS_ATTACKER, BIT_SPATK | BIT_ATK | BIT_SPEED, 0
	setstatchanger STAT_ATK, 1, FALSE
	statbuffchange MOVE_EFFECT_AFFECTS_ATTACKER | STAT_CHANGE_ALLOW_PTR, BattleScript_AngerShellTrySpAtk
	jumpifbyte CMP_EQUAL, cMULTISTRING_CHOOSER, B_MSG_STAT_WONT_INCREASE, BattleScript_AngerShellTrySpAtk
	printfromtable gStatUpStringIds
	waitmessage B_WAIT_TIME_LONG
BattleScript_AngerShellTrySpAtk:
	setstatchanger STAT_SPATK, 1, FALSE
	statbuffchange MOVE_EFFECT_AFFECTS_ATTACKER | STAT_CHANGE_ALLOW_PTR, BattleScript_AngerShellTrySpeed
	jumpifbyte CMP_EQUAL, cMULTISTRING_CHOOSER, B_MSG_STAT_WONT_INCREASE, BattleScript_AngerShellTrySpeed
	printfromtable gStatUpStringIds
	waitmessage B_WAIT_TIME_LONG
BattleScript_AngerShellTrySpeed:
	setstatchanger STAT_SPEED, 1, FALSE
	statbuffchange MOVE_EFFECT_AFFECTS_ATTACKER | STAT_CHANGE_ALLOW_PTR, BattleScript_AngerShellRet
	jumpifbyte CMP_EQUAL, cMULTISTRING_CHOOSER, B_MSG_STAT_WONT_INCREASE, BattleScript_AngerShellRet
	printfromtable gStatUpStringIds
	waitmessage B_WAIT_TIME_LONG
BattleScript_AngerShellRet:
	return

BattleScript_WindPowerActivates::
	call BattleScript_AbilityPopUp
	setcharge BS_TARGET
	printstring STRINGID_BEINGHITCHARGEDPKMNWITHPOWER
	waitmessage B_WAIT_TIME_LONG
BattleScript_WindPowerActivates_Ret:
	return

BattleScript_ToxicDebrisActivates::
	call BattleScript_AbilityPopUp
	pause B_WAIT_TIME_SHORT
	settoxicspikes BattleScript_ToxicDebrisRet
	printstring STRINGID_POISONSPIKESSCATTERED
	waitmessage B_WAIT_TIME_LONG
BattleScript_ToxicDebrisRet:
	return

BattleScript_PastelVeilActivates::
	setbyte gBattleCommunication, 0
	setbyte gBattleCommunication + 1, 0
BattleScript_PastelVeil_TryCurePoison:
	jumpifstatus BS_TARGET, STATUS1_POISON | STATUS1_TOXIC_POISON, BattleScript_PastelVeilCurePoison
	goto BattleScript_PastelVeilLoopIncrement
BattleScript_PastelVeilCurePoison:
	jumpifbyte CMP_NOT_EQUAL, gBattleCommunication + 1, 0x0, BattleScript_PastelVeilCurePoisonNoPopUp
	call BattleScript_AbilityPopUp
	setbyte gBattleCommunication + 1, 1
BattleScript_PastelVeilCurePoisonNoPopUp: @ Only show Pastel Veil pop up once if it cures two mons
	printfromtable gSwitchInAbilityStringIds
	waitmessage B_WAIT_TIME_LONG
	curestatus BS_TARGET
	updatestatusicon BS_TARGET
BattleScript_PastelVeilLoopIncrement:
	jumpifbyte CMP_NOT_EQUAL, gBattleCommunication, 0x0, BattleScript_PastelVeilEnd
	addbyte gBattleCommunication, 1
	jumpifnoally BS_TARGET, BattleScript_PastelVeilEnd
	setallytonexttarget BattleScript_PastelVeil_TryCurePoison
	goto BattleScript_PastelVeilEnd
BattleScript_PastelVeilEnd:
	end3

BattleScript_PastelVeilProtectsRet::
	pause B_WAIT_TIME_SHORT
	call BattleScript_AbilityPopUp
	printstring STRINGID_PASTELVEILPROTECTED
	waitmessage B_WAIT_TIME_LONG
	return

BattleScript_PastelVeilProtects:
	call BattleScript_PastelVeilProtectsRet
	orhalfword gMoveResultFlags, MOVE_RESULT_FAILED
	goto BattleScript_MoveEnd

BattleScript_LeafGuardProtectsRet::
	pause B_WAIT_TIME_SHORT
	call BattleScript_AbilityPopUp
	printstring STRINGID_ITDOESNTAFFECT
	waitmessage B_WAIT_TIME_LONG
	return

BattleScript_LeafGuardProtects:
	call BattleScript_LeafGuardProtectsRet
	orhalfword gMoveResultFlags, MOVE_RESULT_FAILED
	goto BattleScript_MoveEnd

BattleScript_AlreadyAsleep::
	setalreadystatusedmoveattempt BS_ATTACKER
	pause B_WAIT_TIME_SHORT
	printstring STRINGID_PKMNALREADYASLEEP
	waitmessage B_WAIT_TIME_LONG
	orhalfword gMoveResultFlags, MOVE_RESULT_FAILED
	goto BattleScript_MoveEnd

BattleScript_WasntAffected::
	pause B_WAIT_TIME_SHORT
	printstring STRINGID_PKMNWASNTAFFECTED
	waitmessage B_WAIT_TIME_LONG
	orhalfword gMoveResultFlags, MOVE_RESULT_FAILED
	goto BattleScript_MoveEnd

BattleScript_CantMakeAsleep::
	pause B_WAIT_TIME_SHORT
	printfromtable gUproarAwakeStringIds
	waitmessage B_WAIT_TIME_LONG
	orhalfword gMoveResultFlags, MOVE_RESULT_FAILED
	goto BattleScript_MoveEnd

BattleScript_EffectPoisonHit:
	setmoveeffect MOVE_EFFECT_POISON
	goto BattleScript_EffectHit

BattleScript_EffectAbsorb::
	setmoveeffect MOVE_EFFECT_ABSORB | MOVE_EFFECT_CERTAIN
	setbyte cMULTISTRING_CHOOSER, B_MSG_ABSORB
BattleScript_AbsorbEnd:
	call BattleScript_EffectHit_Ret
	seteffectwithchance
	tryfaintmon BS_TARGET, FALSE, NULL
	goto BattleScript_MoveEnd

BattleScript_EffectAbsorb50::
	setmoveeffect MOVE_EFFECT_ABSORB_50 | MOVE_EFFECT_CERTAIN
	setbyte cMULTISTRING_CHOOSER, B_MSG_ABSORB
	goto BattleScript_AbsorbEnd

BattleScript_EffectAbsorb75::
	setmoveeffect MOVE_EFFECT_ABSORB_75 | MOVE_EFFECT_CERTAIN
	setbyte cMULTISTRING_CHOOSER, B_MSG_ABSORB
	goto BattleScript_AbsorbEnd

BattleScript_MoveEffectAbsorb::
	jumpifstatus3 BS_ATTACKER, STATUS3_HEAL_BLOCK, BattleScript_AbsorbHealBlock
	manipulatedamage DMG_BIG_ROOT
	orword gHitMarker, HITMARKER_IGNORE_SUBSTITUTE | HITMARKER_IGNORE_DISGUISE
	jumpifabilityorinnate BS_TARGET, ABILITY_LIQUID_OOZE, BattleScript_AbsorbLiquidOoze
	jumpifabilityorinnate BS_TARGET, ABILITY_ROUGH_SKIN, BattleScript_NegateRoughSkin
BattleScript_AbsorbUpdateHp::
	healthbarupdate BS_ATTACKER
	datahpupdate BS_ATTACKER
	jumpifmovehadnoeffect BattleScript_AbsorbTryFainting
	printfromtable gAbsorbDrainStringIds
	waitmessage B_WAIT_TIME_LONG
BattleScript_AbsorbTryFainting::
	tryfaintmon BS_ATTACKER, FALSE, NULL
BattleScript_AbsorbHealBlock::
	return

BattleScript_NegateRoughSkin:
	copybyte gBattlerAbility, gBattlerTarget
	sethword sABILITY_OVERWRITE, ABILITY_ROUGH_SKIN
	call BattleScript_AbilityPopUp
	manipulatedamage DMG_NEGATE
	setbyte cMULTISTRING_CHOOSER, B_MSG_ABSORB_NEGATED
	goto BattleScript_AbsorbUpdateHp

BattleScript_AbsorbLiquidOoze::
	copybyte gBattlerAbility, gBattlerTarget	
	sethword sABILITY_OVERWRITE, ABILITY_LIQUID_OOZE
	call BattleScript_AbilityPopUp
	manipulatedamage DMG_LIQUID_OOZE
	setbyte cMULTISTRING_CHOOSER, B_MSG_ABSORB_OOZE
	goto BattleScript_AbsorbUpdateHp

BattleScript_EffectBurnHit::
	setmoveeffect MOVE_EFFECT_BURN
	goto BattleScript_EffectHit

BattleScript_EffectFreezeHit::
	setmoveeffect MOVE_EFFECT_FROSTBITE
	goto BattleScript_EffectHit

BattleScript_EffectParalyzeHit::
	setmoveeffect MOVE_EFFECT_PARALYSIS
	goto BattleScript_EffectHit

BattleScript_EffectFrostbiteHit::
	setmoveeffect MOVE_EFFECT_FROSTBITE
	goto BattleScript_EffectHit

BattleScript_EffectExplosion::
	attackcanceler
	attackstring
	ppreduce
	faintifabilitynotdamp
	setatkhptozero
	waitstate
	jumpifbyte CMP_NO_COMMON_BITS, gMoveResultFlags, MOVE_RESULT_MISSED, BattleScript_ExplosionDoAnimStartLoop
	call BattleScript_PreserveMissedBitDoMoveAnim
	goto BattleScript_ExplosionLoop
BattleScript_ExplosionDoAnimStartLoop:
	attackanimation
	waitanimation
BattleScript_ExplosionLoop:
	movevaluescleanup
	critcalc
	damagecalc
	adjustdamage
	accuracycheck BattleScript_ExplosionMissed, ACC_CURR_MOVE
	effectivenesssound
	hitanimation BS_TARGET
	waitstate
	healthbarupdate BS_TARGET
	datahpupdate BS_TARGET
	critmessage
	waitmessage B_WAIT_TIME_LONG
	resultmessage
	waitmessage B_WAIT_TIME_LONG
	tryfaintmon BS_TARGET, FALSE, NULL
	moveendto MOVEEND_NEXT_TARGET
	jumpifnexttargetvalid BattleScript_ExplosionLoop
	tryfaintmon BS_ATTACKER, FALSE, NULL
	moveendcase MOVEEND_CLEAR_BITS
	end
BattleScript_ExplosionMissed:
	effectivenesssound
	resultmessage
	waitmessage B_WAIT_TIME_LONG
	moveendto MOVEEND_NEXT_TARGET
	jumpifnexttargetvalid BattleScript_ExplosionLoop
	tryfaintmon BS_ATTACKER, FALSE, NULL
	end

BattleScript_EffectMindBlown::
	attackcanceler
	attackstring
	ppreduce
	jumpifabilityorinnatepresent ABILITY_DAMP, BattleScript_MindBlownDamp
	jumpifbyte CMP_NO_COMMON_BITS, gMoveResultFlags, MOVE_RESULT_MISSED, BattleScript_MindBlownDoAnimStartLoop
	call BattleScript_PreserveMissedBitDoMoveAnim
	goto BattleScript_MindBlownLoop
BattleScript_MindBlownDoAnimStartLoop:
	attackanimation
	waitanimation
BattleScript_MindBlownLoop:
	movevaluescleanup
	critcalc
	damagecalc
	adjustdamage
	accuracycheck BattleScript_MindBlownMissed, ACC_CURR_MOVE
	effectivenesssound
	hitanimation BS_TARGET
	waitstate
	healthbarupdate BS_TARGET
	datahpupdate BS_TARGET
	critmessage
	waitmessage B_WAIT_TIME_LONG
	resultmessage
	waitmessage B_WAIT_TIME_LONG
	tryfaintmon BS_TARGET, FALSE, NULL
	moveendto MOVEEND_NEXT_TARGET
	jumpifnexttargetvalid BattleScript_MindBlownLoop
	jumpifmagicguarded BS_ATTACKER, BattleScript_MindBlownEnd
	dmg_1_2_attackerhp
	healthbarupdate BS_ATTACKER
	datahpupdate BS_ATTACKER
	waitstate
	tryfaintmon BS_ATTACKER, FALSE, NULL
BattleScript_MindBlownEnd:
	moveendcase MOVEEND_CLEAR_BITS
	end
BattleScript_MindBlownMissed:
	effectivenesssound
	resultmessage
	waitmessage B_WAIT_TIME_LONG
	moveendto MOVEEND_NEXT_TARGET
	jumpifnexttargetvalid BattleScript_MindBlownLoop
	tryfaintmon BS_ATTACKER, FALSE, NULL
	end
BattleScript_MindBlownDamp:
	copybyte gBattlerTarget, gBattlerAbility
	goto BattleScript_DampStopsExplosion

BattleScript_PreserveMissedBitDoMoveAnim:
	bichalfword gMoveResultFlags, MOVE_RESULT_MISSED
	attackanimation
	waitanimation
	orhalfword gMoveResultFlags, MOVE_RESULT_MISSED
	return

BattleScript_EffectDreamEater::
	setmoveeffect MOVE_EFFECT_ABSORB_50 | MOVE_EFFECT_CERTAIN
	setbyte cMULTISTRING_CHOOSER, B_MSG_DREAMEATEN
	goto BattleScript_AbsorbEnd

BattleScript_EffectMirrorMove::
	attackcanceler
	attackstring
	pause B_WAIT_TIME_LONG
	trymirrormove
	ppreduce
	orhalfword gMoveResultFlags, MOVE_RESULT_FAILED
	printstring STRINGID_MIRRORMOVEFAILED
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_EffectAttackUp::
	setstatchanger STAT_ATK, 1, FALSE
	goto BattleScript_EffectStatUp

BattleScript_EffectDefenseUp::
	setstatchanger STAT_DEF, 1, FALSE
	goto BattleScript_EffectStatUp

BattleScript_EffectSpecialAttackUp::
	setstatchanger STAT_SPATK, 1, FALSE
	goto BattleScript_EffectStatUp

BattleScript_EffectSpeedUp:
	setstatchanger STAT_SPEED, 1, FALSE
	goto BattleScript_EffectStatUp

BattleScript_EffectSpecialDefenseUp:
	setstatchanger STAT_SPDEF, 1, FALSE
	goto BattleScript_EffectStatUp

BattleScript_EffectAccuracyUp:
	setstatchanger STAT_ACC, 1, FALSE
	goto BattleScript_EffectStatUp

BattleScript_EffectEvasionUp::
	setstatchanger STAT_EVASION, 1, FALSE
	setdoubleteam
BattleScript_EffectStatUp::
	attackcanceler
BattleScript_EffectStatUpAfterAtkCanceler::
	attackstring
	ppreduce
	statbuffchange MOVE_EFFECT_AFFECTS_ATTACKER | STAT_CHANGE_ALLOW_PTR, BattleScript_StatUpEnd
	jumpifbyte CMP_NOT_EQUAL, cMULTISTRING_CHOOSER, B_MSG_STAT_WONT_INCREASE, BattleScript_StatUpAttackAnim
	pause B_WAIT_TIME_SHORT
	goto BattleScript_StatUpPrintString
BattleScript_StatUpAttackAnim::
	attackanimation
	waitanimation
BattleScript_StatUpDoAnim::
	setgraphicalstatchangevalues
	playanimation BS_ATTACKER, B_ANIM_STATS_CHANGE, sB_ANIM_ARG1
BattleScript_StatUpPrintString::
	printfromtable gStatUpStringIds
	waitmessage B_WAIT_TIME_LONG
BattleScript_StatUpEnd::
	goto BattleScript_MoveEnd

BattleScript_StatUp::
	playanimation BS_EFFECT_BATTLER, B_ANIM_STATS_CHANGE, sB_ANIM_ARG1
BattleScript_StatUpMsg::
	printfromtable gStatUpStringIds
	waitmessage B_WAIT_TIME_LONG
	return

BattleScript_EffectAttackDown:
	setstatchanger STAT_ATK, 1, TRUE
	goto BattleScript_EffectStatDown

BattleScript_EffectDefenseDown:
	setstatchanger STAT_DEF, 1, TRUE
	goto BattleScript_EffectStatDown

BattleScript_EffectSpeedDown:
	setstatchanger STAT_SPEED, 1, TRUE
	goto BattleScript_EffectStatDown

BattleScript_EffectAccuracyDown:
	setstatchanger STAT_ACC, 1, TRUE
	goto BattleScript_EffectStatDown

BattleScript_EffectSpecialAttackDown:
	setstatchanger STAT_SPATK, 1, TRUE
	goto BattleScript_EffectStatDown

BattleScript_EffectSpecialDefenseDown:
	setstatchanger STAT_SPDEF, 1, TRUE
	goto BattleScript_EffectStatDown

BattleScript_EffectEvasionDown:
	setstatchanger STAT_EVASION, 1, TRUE
BattleScript_EffectStatDown:
	attackcanceler
	jumpifsubstituteblocks BattleScript_FailedFromAtkString
	accuracycheck BattleScript_PrintMoveMissed, ACC_CURR_MOVE
BattleScript_StatDownFromAttackString:
	attackstring
	ppreduce
	statbuffchange STAT_CHANGE_ALLOW_PTR, BattleScript_StatDownEnd
	jumpifbyte CMP_LESS_THAN, cMULTISTRING_CHOOSER, B_MSG_STAT_WONT_DECREASE, BattleScript_StatDownDoAnim
	jumpifbyte CMP_EQUAL, cMULTISTRING_CHOOSER, B_MSG_STAT_FELL_EMPTY, BattleScript_StatDownEnd
	pause B_WAIT_TIME_SHORT
	goto BattleScript_StatDownPrintString
BattleScript_StatDownDoAnim::
	attackanimation
	waitanimation
	setgraphicalstatchangevalues
	playanimation BS_TARGET, B_ANIM_STATS_CHANGE, sB_ANIM_ARG1
BattleScript_StatDownPrintString::
	printfromtable gStatDownStringIds
	waitmessage B_WAIT_TIME_LONG
BattleScript_StatDownEnd::
	goto BattleScript_MoveEnd

BattleScript_MirrorArmorReflect::
	pause B_WAIT_TIME_SHORT
	call BattleScript_AbilityPopUp
	jumpifsubstituteblocks BattleScript_AbilityNoSpecificStatLoss
BattleScript_MirrorArmorReflectStatLoss:
	statbuffchange MOVE_EFFECT_AFFECTS_ATTACKER | STAT_BUFF_NOT_PROTECT_AFFECTED | STAT_CHANGE_ALLOW_PTR, BattleScript_MirrorArmorReflectEnd
	jumpifbyte CMP_LESS_THAN, cMULTISTRING_CHOOSER, B_MSG_STAT_WONT_DECREASE, BattleScript_MirrorArmorReflectAnim
	goto BattleScript_MirrorArmorReflectWontFall
BattleScript_MirrorArmorReflectAnim:
	setgraphicalstatchangevalues
	playanimation BS_ATTACKER, B_ANIM_STATS_CHANGE, sB_ANIM_ARG1
BattleScript_MirrorArmorReflectPrintString:
	printfromtable gStatDownStringIds
	waitmessage B_WAIT_TIME_LONG
BattleScript_MirrorArmorReflectEnd:
	return

BattleScript_MirrorArmorReflectWontFall:
	copybyte gBattlerTarget, gBattlerAttacker   @ STRINGID_STATSWONTDECREASE uses target
	goto BattleScript_MirrorArmorReflectPrintString

@ gBattlerTarget is battler with Mirror Armor
BattleScript_MirrorArmorReflectStickyWeb:
	call BattleScript_AbilityPopUp
	setattackertostickywebuser
	jumpifbyteequal gBattlerAttacker, gBattlerTarget, BattleScript_StickyWebOnSwitchInEnd   @ Sticky web user not on field -> no stat loss
	goto BattleScript_MirrorArmorReflectStatLoss

BattleScript_StatDown::
	playanimation BS_EFFECT_BATTLER, B_ANIM_STATS_CHANGE, sB_ANIM_ARG1
	printfromtable gStatDownStringIds
	waitmessage B_WAIT_TIME_LONG
	return

BattleScript_EffectHaze::
	attackcanceler
	attackstring
	ppreduce
	attackanimation
	waitanimation
	normalisebuffs
	printstring STRINGID_STATCHANGESGONE
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_EffectBide::
	attackcanceler
	attackstring
	ppreduce
	attackanimation
	waitanimation
	orword gHitMarker, HITMARKER_CHARGING
	setbide
	goto BattleScript_MoveEnd

BattleScript_EffectRampage::
	attackcanceler
	accuracycheck BattleScript_PrintMoveMissed, ACC_CURR_MOVE
	attackstring
	jumpifstatus2 BS_ATTACKER, STATUS2_MULTIPLETURNS, BattleScript_EffectRampageNoPPReduce
	ppreduce
BattleScript_EffectRampageNoPPReduce:
	confuseifrepeatingattackends
	goto BattleScript_HitFromCritCalc

BattleScript_EffectTyrannicalRampage::
	attackcanceler
	accuracycheck BattleScript_PrintMoveMissed, ACC_CURR_MOVE
	attackstring
	jumpifstatus2 BS_ATTACKER, STATUS2_MULTIPLETURNS, BattleScript_EffectTyrannicalRampageNoPPReduce
	ppreduce
BattleScript_EffectTyrannicalRampageNoPPReduce:
	confuseifrepeatingattackends
	call BattleScript_EffectDamage_Ret
	seteffectwithchance
	setmoveeffect MOVE_EFFECT_EXECUTION | MOVE_EFFECT_CERTAIN
	seteffectwithchance
	tryfaintmon BS_TARGET, FALSE, NULL
	moveendall
	end

BattleScript_EffectRoar::
	attackcanceler
	attackstring
	ppreduce
	jumpifroarfails BattleScript_ButItFailed
	jumpifabilityorinnate BS_TARGET, ABILITY_SUCTION_CUPS, BattleScript_AbilityPreventsPhasingOut
	jumpifabilityorinnate BS_TARGET, ABILITY_GUARD_DOG, BattleScript_MoveEnd
	jumpifstatus3 BS_TARGET, STATUS3_ROOTED, BattleScript_PrintMonIsRooted
	jumpifnoholdeffect BS_TARGET, HOLD_EFFECT_STRONG_SHIELD, BattleScript_EffectRoarContinue
	goto BattleScript_MoveEnd
BattleScript_EffectRoarContinue:
	accuracycheck BattleScript_ButItFailed, NO_ACC_CALC_CHECK_LOCK_ON
	accuracycheck BattleScript_MoveMissedPause, ACC_CURR_MOVE
	jumpifbattletype BATTLE_TYPE_ARENA, BattleScript_ButItFailed
BattleScript_ForceRandomSwitch::
	forcerandomswitch BattleScript_ButItFailed

BattleScript_EffectMultiHit::
	attackcanceler
	accuracycheck BattleScript_PrintMoveMissed, ACC_CURR_MOVE
	attackstring
	ppreduce
	setmultihitcounter 0
	initmultihitstring
	sethword sMULTIHIT_EFFECT, 0
BattleScript_MultiHitLoop::
	jumpifhasnohp BS_ATTACKER, BattleScript_MultiHitEnd
	jumpifhasnohp BS_TARGET, BattleScript_MultiHitPrintStrings
	jumpifhalfword CMP_EQUAL, gChosenMove, MOVE_SLEEP_TALK, BattleScript_DoMultiHit
	jumpifstatus BS_ATTACKER, STATUS1_SLEEP, BattleScript_MultiHitPrintStrings
BattleScript_DoMultiHit::
	movevaluescleanup
	copyhword sMOVE_EFFECT, sMULTIHIT_EFFECT
	critcalc
	damagecalc
	jumpifmovehadnoeffect BattleScript_MultiHitNoMoreHits
	adjustdamage
	attackanimation
	waitanimation
	effectivenesssound
	hitanimation BS_TARGET
	waitstate
	healthbarupdate BS_TARGET
	datahpupdate BS_TARGET
	critmessage
	waitmessage B_WAIT_TIME_LONG
	multihitresultmessage
	printstring STRINGID_EMPTYSTRING3
	waitmessage 1
	seteffectwithchance
	addbyte sMULTIHIT_STRING + 4, 1
	moveendto MOVEEND_NEXT_TARGET
	jumpifbyte CMP_COMMON_BITS, gMoveResultFlags, MOVE_RESULT_FOE_ENDURED, BattleScript_MultiHitPrintStrings
	decrementmultihit BattleScript_MultiHitLoop
	goto BattleScript_MultiHitPrintStrings
BattleScript_MultiHitNoMoreHits::
	pause B_WAIT_TIME_SHORT
BattleScript_MultiHitPrintStrings::
	resultmessage
	waitmessage B_WAIT_TIME_LONG
	jumpifmovehadnoeffect BattleScript_MultiHitEnd
	copyarray gBattleTextBuff1, sMULTIHIT_STRING, 6
	printstring STRINGID_HITXTIMES
	waitmessage B_WAIT_TIME_LONG
BattleScript_MultiHitEnd::
	tryfaintmon BS_TARGET, FALSE, NULL
	moveendcase MOVEEND_SYNCHRONIZE_TARGET
	moveendfrom MOVEEND_STATUS_IMMUNITY_ABILITIES
	end

BattleScript_EffectGatlingGulpMissile::
	attackcanceler
	attackstring
	ppreduce
	setmultihitcounter 10
	initmultihitstring
	movevaluescleanup
BattleScript_GatlingGulpMissileLoop::
	jumpifhasnohp BS_ATTACKER, BattleScript_GatlingGulpMissileEnd
	jumpifhasnohp BS_TARGET, BattleScript_GatlingGulpMissilePrintStrings
	jumpifhalfword CMP_EQUAL, gChosenMove, MOVE_SLEEP_TALK, BattleScript_DoGatlingGulpMissileHit
	jumpifstatus BS_ATTACKER, STATUS1_SLEEP, BattleScript_GatlingGulpMissilePrintStrings
BattleScript_DoGatlingGulpMissileHit::
	accuracycheck BattleScript_GatlingGulpMissileNoMoreHits, ACC_CURR_MOVE
BattleScript_DoGatlingGulpMissileAttackWithoutAccCheck:
	movevaluescleanup
	setgatlinggulpmissibleeffect
	critcalc
	damagecalc
	jumpifmovehadnoeffect BattleScript_GatlingGulpMissileNoMoreHits
	adjustdamage
	attackanimation
	waitanimation
	effectivenesssound
	hitanimation BS_TARGET
	waitstate
	healthbarupdate BS_TARGET
	datahpupdate BS_TARGET
	critmessage
	waitmessage B_WAIT_TIME_LONG
	multihitresultmessage
	printstring STRINGID_EMPTYSTRING3
	waitmessage 1
	seteffectwithchance
	addbyte sMULTIHIT_STRING + 4, 1
	moveendto MOVEEND_NEXT_TARGET
	jumpifbyte CMP_COMMON_BITS, gMoveResultFlags, MOVE_RESULT_FOE_ENDURED, BattleScript_GatlingGulpMissilePrintStrings
	decrementmultihit BattleScript_GatlingGulpMissileLoop, BattleScript_GatlingGulpMissileLoadedDiceLoop
	goto BattleScript_GatlingGulpMissilePrintStrings
BattleScript_GatlingGulpMissileNoMoreHits::
	pause B_WAIT_TIME_SHORT
BattleScript_GatlingGulpMissilePrintStrings::
	resultmessage
	waitmessage B_WAIT_TIME_LONG
	jumpifhalfword CMP_COMMON_BITS, gMoveResultFlags, MOVE_RESULT_DOESNT_AFFECT_FOE, BattleScript_GatlingGulpMissileEnd
	copyarray gBattleTextBuff1, sMULTIHIT_STRING, 6
	printstring STRINGID_HITXTIMES
	waitmessage B_WAIT_TIME_LONG
BattleScript_GatlingGulpMissileEnd::
	tryfaintmon BS_TARGET, FALSE, NULL
	moveendcase MOVEEND_SYNCHRONIZE_TARGET
	moveendfrom MOVEEND_STATUS_IMMUNITY_ABILITIES
	end

BattleScript_GatlingGulpMissileLoadedDiceLoop::
	jumpifhasnohp BS_ATTACKER, BattleScript_GatlingGulpMissileEnd
	jumpifhasnohp BS_TARGET, BattleScript_GatlingGulpMissileNoMoreHits
	jumpifhalfword CMP_EQUAL, gChosenMove, MOVE_SLEEP_TALK, BattleScript_DoGatlingGulpMissileAttackWithoutAccCheck
	jumpifstatus BS_ATTACKER, STATUS1_SLEEP, BattleScript_GatlingGulpMissileNoMoreHits
	goto BattleScript_DoGatlingGulpMissileAttackWithoutAccCheck

BattleScript_EffectPopulationBomb::
	attackcanceler
	attackstring
	ppreduce
	setmultihitcounter 10
	initmultihitstring
	sethword sMULTIHIT_EFFECT, 0
	movevaluescleanup
BattleScript_PopulationBombLoop::
	jumpifhasnohp BS_ATTACKER, BattleScript_PopulationBombEnd
	jumpifhasnohp BS_TARGET, BattleScript_PopulationBombPrintStrings
	jumpifhalfword CMP_EQUAL, gChosenMove, MOVE_SLEEP_TALK, BattleScript_DoPopulationBombHit
	jumpifstatus BS_ATTACKER, STATUS1_SLEEP, BattleScript_PopulationBombPrintStrings
BattleScript_DoPopulationBombHit::
	accuracycheck BattleScript_PopulationBombNoMoreHits, ACC_CURR_MOVE
BattleScript_DoPopulationBombAttackWithoutAccCheck:
	movevaluescleanup
	copyhword sMOVE_EFFECT, sMULTIHIT_EFFECT
	critcalc
	damagecalc
	jumpifmovehadnoeffect BattleScript_PopulationBombNoMoreHits
	adjustdamage
	attackanimation
	waitanimation
	effectivenesssound
	hitanimation BS_TARGET
	waitstate
	healthbarupdate BS_TARGET
	datahpupdate BS_TARGET
	critmessage
	waitmessage B_WAIT_TIME_LONG
	multihitresultmessage
	printstring STRINGID_EMPTYSTRING3
	waitmessage 1
	addbyte sMULTIHIT_STRING + 4, 1
	moveendto MOVEEND_NEXT_TARGET
	jumpifbyte CMP_COMMON_BITS, gMoveResultFlags, MOVE_RESULT_FOE_ENDURED, BattleScript_PopulationBombPrintStrings
	decrementmultihit BattleScript_PopulationBombLoop, BattleScript_PopulationBombLoadedDiceLoop
	goto BattleScript_PopulationBombPrintStrings
BattleScript_PopulationBombNoMoreHits::
	pause B_WAIT_TIME_SHORT
BattleScript_PopulationBombPrintStrings::
	resultmessage
	waitmessage B_WAIT_TIME_LONG
	jumpifhalfword CMP_COMMON_BITS, gMoveResultFlags, MOVE_RESULT_DOESNT_AFFECT_FOE, BattleScript_PopulationBombEnd
	copyarray gBattleTextBuff1, sMULTIHIT_STRING, 6
	printstring STRINGID_HITXTIMES
	waitmessage B_WAIT_TIME_LONG
BattleScript_PopulationBombEnd::
	tryfaintmon BS_TARGET, FALSE, NULL
	moveendcase MOVEEND_SYNCHRONIZE_TARGET
	moveendfrom MOVEEND_STATUS_IMMUNITY_ABILITIES
	end

BattleScript_PopulationBombLoadedDiceLoop::
	jumpifhasnohp BS_ATTACKER, BattleScript_PopulationBombEnd
	jumpifhasnohp BS_TARGET, BattleScript_PopulationBombNoMoreHits
	jumpifhalfword CMP_EQUAL, gChosenMove, MOVE_SLEEP_TALK, BattleScript_DoPopulationBombAttackWithoutAccCheck
	jumpifstatus BS_ATTACKER, STATUS1_SLEEP, BattleScript_PopulationBombNoMoreHits
	goto BattleScript_DoPopulationBombAttackWithoutAccCheck

BattleScript_EffectConversion::
	attackcanceler
	attackstring
	ppreduce
	tryconversiontypechange BattleScript_ButItFailed
	attackanimation
	waitanimation
	printstring STRINGID_PKMNCHANGEDTYPE
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_EffectFlinchHit::
	setmoveeffect MOVE_EFFECT_FLINCH
	goto BattleScript_EffectHit

BattleScript_EffectFlinchWithStatus:
	attackcanceler
	accuracycheck BattleScript_PrintMoveMissed, ACC_CURR_MOVE
	attackstring
	ppreduce
	call BattleScript_EffectDamage_Ret
	setmoveeffect MOVE_EFFECT_FLINCH
	seteffectwithchance
	argumenttomoveeffect
	seteffectwithchance
	tryfaintmon BS_TARGET, FALSE, NULL
	goto BattleScript_MoveEnd

BattleScript_EffectRestoreHp::
	attackcanceler
	attackstring
	ppreduce
	tryhealhalfhealth BattleScript_AlreadyAtFullHp, BS_ATTACKER
	attackanimation
	waitanimation
BattleScript_RestoreHp:
	orword gHitMarker, HITMARKER_IGNORE_SUBSTITUTE
	healthbarupdate BS_ATTACKER
	datahpupdate BS_ATTACKER
	printstring STRINGID_PKMNREGAINEDHEALTH
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_EffectForceHealing::
	attackcanceler
	attackstring
	ppreduce
	tryhealhalfhealth BattleScript_AlreadyAtFullHp, BS_ATTACKER
	attackanimation
	waitanimation
	orword gHitMarker, HITMARKER_IGNORE_SUBSTITUTE
	healthbarupdate BS_ATTACKER
	datahpupdate BS_ATTACKER
	printstring STRINGID_PKMNREGAINEDHEALTH
	waitmessage B_WAIT_TIME_LONG
	jumpifabilityorinnate BS_ATTACKER, ABILITY_LORD_SITH, BattleScript_EffectForceHealingStatus
	goto BattleScript_MoveEnd
BattleScript_EffectForceHealingStatus:
	cureifburnedparalysedorpoisoned BattleScript_MoveEnd
	updatestatusicon BS_ATTACKER
	goto BattleScript_MoveEnd

BattleScript_EffectToxic::
	attackcanceler
	attackstring
	ppreduce
	jumpifabilityorinnate BS_TARGET, ABILITY_IMMUNITY, BattleScript_ImmunityProtected
	jumpifabilityorinnate BS_TARGET, ABILITY_PYROCLASTIC, BattleScript_PyroclasticProtected
	jumpifabilityorinnate BS_TARGET, ABILITY_COMATOSE, BattleScript_LeafGuardProtects
	jumpifabilityorinnate BS_TARGET, ABILITY_PURIFYING_SALT, BattleScript_LeafGuardProtects
	jumpifabilityorinnate BS_TARGET_SIDE, ABILITY_PASTEL_VEIL, BattleScript_PastelVeilProtects
	jumpifflowerveil BattleScript_FlowerVeilProtects
	jumpifleafguardprotected BS_TARGET, BattleScript_LeafGuardProtects
	jumpifshieldsdown BS_TARGET, BattleScript_LeafGuardProtects
	jumpifsubstituteblocks BattleScript_ButItFailed
	jumpifstatus BS_TARGET, STATUS1_POISON | STATUS1_TOXIC_POISON, BattleScript_AlreadyPoisoned
	jumpifstatus BS_TARGET, STATUS1_ANY, BattleScript_ButItFailed
	jumpifterrainaffected BS_TARGET, STATUS_FIELD_MISTY_TERRAIN, BattleScript_MistyTerrainPrevents
	trypoisontype BS_ATTACKER, BS_TARGET, BattleScript_NotAffected
	accuracycheck BattleScript_ButItFailed, ACC_CURR_MOVE
	jumpifsafeguard BattleScript_SafeguardProtected
	jumpifkingsgrace BattleScript_KingsGraceProtected
	attackanimation
	waitanimation
	setmoveeffect MOVE_EFFECT_TOXIC
	seteffectprimary
	resultmessage
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_AlreadyPoisoned::
	setalreadystatusedmoveattempt BS_ATTACKER
	pause B_WAIT_TIME_LONG
	printstring STRINGID_PKMNALREADYPOISONED
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_ImmunityProtected::
	copybyte gEffectBattler, gBattlerTarget
	sethword sABILITY_OVERWRITE, ABILITY_IMMUNITY
	changelastusedability ABILITY_IMMUNITY
	setbyte cMULTISTRING_CHOOSER, B_MSG_ABILITY_PREVENTS_MOVE_STATUS
	call BattleScript_AbilityPSNPrevention
	goto BattleScript_MoveEnd

BattleScript_PyroclasticProtected::
	copybyte gEffectBattler, gBattlerTarget
	sethword sABILITY_OVERWRITE, ABILITY_PYROCLASTIC
	changelastusedability ABILITY_PYROCLASTIC
	setbyte cMULTISTRING_CHOOSER, B_MSG_ABILITY_PREVENTS_MOVE_STATUS
	call BattleScript_AbilityPSNPrevention
	goto BattleScript_MoveEnd

BattleScript_EffectPayDay::
	setmoveeffect MOVE_EFFECT_PAYDAY
	goto BattleScript_EffectHit

BattleScript_EffectAuroraDance::
	attackcanceler
	attackstring
	ppreduce
	jumpifweatheraffected BS_ATTACKER, B_WEATHER_HAIL, BattleScript_AuroraDanceOmniBoost
	goto BattleScript_ButItFailed
BattleScript_AuroraDanceOmniBoost:
	attackanimation
	waitanimation
	call BattleScript_AllStatsUp
	goto BattleScript_MoveEnd

BattleScript_EffectHalloween::
	attackcanceler
	attackstring
	ppreduce
	jumpifterrainaffected BS_ATTACKER, STATUS_FIELD_CURSED_TERRAIN, BattleScript_AuroraDanceOmniBoost
	goto BattleScript_ButItFailed

BattleScript_EffectAuroraVeil:
	attackcanceler
	attackstring
	ppreduce
	setauroraveil BS_ATTACKER
	goto BattleScript_PrintReflectLightScreenSafeguardString

BattleScript_EffectLightScreen::
	attackcanceler
	attackstring
	ppreduce
	setlightscreen
	goto BattleScript_PrintReflectLightScreenSafeguardString

BattleScript_EffectTriAttack::
	attackcanceler
	accuracycheck BattleScript_PrintMoveMissed, ACC_CURR_MOVE
	attackstring
	ppreduce
BattleScript_EffectTriAttackFireType:
	critcalc
	customdamagecalculation MOVE_TRI_ATTACK, TYPE_FIRE, 0, TRUE, TRUE
	adjustdamage
	attackanimation
	waitanimation
	effectivenesssound
	hitanimation BS_TARGET
	waitstate
	healthbarupdate BS_TARGET
	datahpupdate BS_TARGET
	critmessage
	waitmessage B_WAIT_TIME_LONG
	resultmessage
	waitmessage B_WAIT_TIME_LONG
	jumpifhasnohp BS_TARGET, BattleScript_EffectTriAttackEnd
	setmoveeffect MOVE_EFFECT_BURN
	seteffectwithchance
BattleScript_EffectTriAttackElectricType:
	critcalc
	customdamagecalculation MOVE_TRI_ATTACK, TYPE_ELECTRIC, 0, TRUE, TRUE
	adjustdamage
	effectivenesssound
	hitanimation BS_TARGET
	waitstate
	healthbarupdate BS_TARGET
	datahpupdate BS_TARGET
	critmessage
	waitmessage B_WAIT_TIME_LONG
	resultmessage
	waitmessage B_WAIT_TIME_LONG
	jumpifhasnohp BS_TARGET, BattleScript_EffectTriAttackEnd
	setmoveeffect MOVE_EFFECT_PARALYSIS
	seteffectwithchance
BattleScript_EffectTriAttackIceType:
	critcalc
	customdamagecalculation MOVE_TRI_ATTACK, TYPE_ICE, 0, TRUE, TRUE
	adjustdamage
	effectivenesssound
	hitanimation BS_TARGET
	waitstate
	healthbarupdate BS_TARGET
	datahpupdate BS_TARGET
	critmessage
	waitmessage B_WAIT_TIME_LONG
	resultmessage
	waitmessage B_WAIT_TIME_LONG
	jumpifhasnohp BS_TARGET, BattleScript_EffectTriAttackEnd
	setmoveeffect MOVE_EFFECT_FROSTBITE
	seteffectwithchance
BattleScript_EffectTriAttackEnd:
	tryfaintmon BS_TARGET, FALSE, NULL
	moveendall
	end

BattleScript_EffectRest::
	attackcanceler
	attackstring
	ppreduce
	jumpifstatus BS_ATTACKER, STATUS1_SLEEP, BattleScript_RestIsAlreadyAsleep
	jumpifabilityorinnate BS_ATTACKER, ABILITY_COMATOSE, BattleScript_RestIsAlreadyAsleep
	jumpifcantmakeasleep BattleScript_RestCantSleep
	trysetrest BattleScript_AlreadyAtFullHp
	pause B_WAIT_TIME_SHORT
	printfromtable gRestUsedStringIds
	waitmessage B_WAIT_TIME_LONG
	updatestatusicon BS_ATTACKER
	waitstate
	goto BattleScript_PresentHealTarget

BattleScript_RestCantSleep::
	pause B_WAIT_TIME_LONG
	printfromtable gUproarAwakeStringIds
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_RestIsAlreadyAsleep::
	setalreadystatusedmoveattempt BS_ATTACKER
	pause B_WAIT_TIME_SHORT
	printstring STRINGID_PKMNALREADYASLEEP2
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_EffectSuperFang::
	attackcanceler
	accuracycheck BattleScript_PrintMoveMissed, ACC_CURR_MOVE
	attackstring
	ppreduce
	typecalc
	bichalfword gMoveResultFlags, MOVE_RESULT_SUPER_EFFECTIVE | MOVE_RESULT_NOT_VERY_EFFECTIVE
	damagetohalftargethp
	goto BattleScript_HitFromAtkAnimation

BattleScript_EffectDragonRage::
	attackcanceler
	accuracycheck BattleScript_PrintMoveMissed, ACC_CURR_MOVE
	attackstring
	ppreduce
	typecalc
	bichalfword gMoveResultFlags, MOVE_RESULT_SUPER_EFFECTIVE | MOVE_RESULT_NOT_VERY_EFFECTIVE
	dmgtolevel
	adjustdamage
	goto BattleScript_HitFromAtkAnimation

BattleScript_EffectTrap::
	setmoveeffect MOVE_EFFECT_WRAP
	goto BattleScript_EffectHit

BattleScript_EffectTripleHit::
	attackcanceler
	accuracycheck BattleScript_PrintMoveMissed, ACC_CURR_MOVE
	attackstring
	ppreduce
	setmultihitcounter 3
	initmultihitstring
	sethword sMULTIHIT_EFFECT, 0
	goto BattleScript_MultiHitLoop

BattleScript_EffectDoubleHit::
	attackcanceler
	accuracycheck BattleScript_PrintMoveMissed, ACC_CURR_MOVE
	attackstring
	ppreduce
	setmultihitcounter 2
	initmultihitstring
	sethword sMULTIHIT_EFFECT, 0
	goto BattleScript_MultiHitLoop

BattleScript_EffectRecoilIfMiss::
	attackcanceler
	accuracycheck BattleScript_MoveMissedDoDamage, ACC_CURR_MOVE
	typecalc
	jumpifhalfword CMP_COMMON_BITS, gMoveResultFlags, MOVE_RESULT_DOESNT_AFFECT_FOE, BattleScript_MoveMissedDoDamage
	goto BattleScript_HitFromAtkString
BattleScript_MoveMissedDoDamage::
	jumpifmagicguarded BS_ATTACKER, BattleScript_PrintMoveMissed
	attackstring
	ppreduce
	pause B_WAIT_TIME_LONG
	resultmessage
	waitmessage B_WAIT_TIME_LONG
	printstring STRINGID_PKMNCRASHED
	waitmessage B_WAIT_TIME_LONG
	damagecalc
	typecalc
	adjustdamage
	manipulatedamage DMG_RECOIL_FROM_MISS
	bichalfword gMoveResultFlags, MOVE_RESULT_MISSED | MOVE_RESULT_DOESNT_AFFECT_FOE
	orword gHitMarker, HITMARKER_IGNORE_SUBSTITUTE | HITMARKER_IGNORE_DISGUISE
	healthbarupdate BS_ATTACKER
	datahpupdate BS_ATTACKER
	tryfaintmon BS_ATTACKER, FALSE, NULL
	orhalfword gMoveResultFlags, MOVE_RESULT_MISSED | MOVE_RESULT_DOESNT_AFFECT_FOE
	goto BattleScript_MoveEnd

BattleScript_EffectMist::
	attackcanceler
	attackstring
	ppreduce
	setmist
	attackanimation
	waitanimation
	printfromtable gMistUsedStringIds
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_EffectFocusEnergy:
	attackcanceler
	attackstring
	ppreduce
	jumpifstatus2 BS_ATTACKER, STATUS2_FOCUS_ENERGY, BattleScript_ButItFailed
	setfocusenergy
	attackanimation
	waitanimation
	printfromtable gFocusEnergyUsedStringIds
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_EffectConfuse:
	attackcanceler
	attackstring
	ppreduce
	jumpifabilityorinnate BS_TARGET, ABILITY_OWN_TEMPO, BattleScript_InnateOwnTempoPrevents
	jumpifsubstituteblocks BattleScript_ButItFailed
	jumpifstatus2 BS_TARGET, STATUS2_CONFUSION, BattleScript_AlreadyConfused
	jumpifterrainaffected BS_TARGET, STATUS_FIELD_MISTY_TERRAIN, BattleScript_MistyTerrainPrevents
	accuracycheck BattleScript_ButItFailed, ACC_CURR_MOVE
	jumpifsafeguard BattleScript_SafeguardProtected
	jumpifkingsgrace BattleScript_KingsGraceProtected
	attackanimation
	waitanimation
	setmoveeffect MOVE_EFFECT_CONFUSE
	seteffectprimary
	resultmessage
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_InnateOwnTempoPrevents:
	copybyte gBattlerAbility, gBattlerTarget
	sethword sABILITY_OVERWRITE, ABILITY_OWN_TEMPO
	goto BattleScript_OwnTempoPrevents

BattleScript_AlreadyConfused::
	setalreadystatusedmoveattempt BS_ATTACKER
	pause B_WAIT_TIME_SHORT
	printstring STRINGID_PKMNALREADYCONFUSED
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_EffectAttackUp2::
	setstatchanger STAT_ATK, 2, FALSE
	goto BattleScript_EffectStatUp

BattleScript_EffectDefenseUp2::
	setstatchanger STAT_DEF, 2, FALSE
	goto BattleScript_EffectStatUp

BattleScript_EffectDefenseUp3:
	setstatchanger STAT_DEF, 3, FALSE
	goto BattleScript_EffectStatUp

BattleScript_EffectSpeedUp2::
	setstatchanger STAT_SPEED, 2, FALSE
	goto BattleScript_EffectStatUp

BattleScript_EffectSpecialAttackUp2::
	setstatchanger STAT_SPATK, 2, FALSE
	goto BattleScript_EffectStatUp

BattleScript_EffectSpecialAttackUp3::
	setstatchanger STAT_SPATK, 3, FALSE
	goto BattleScript_EffectStatUp

BattleScript_EffectSpecialDefenseUp2::
	setstatchanger STAT_SPDEF, 2, FALSE
	goto BattleScript_EffectStatUp

BattleScript_EffectAccuracyUp2:
	setstatchanger STAT_ACC, 2, FALSE
	goto BattleScript_EffectStatUp

BattleScript_EffectEvasionUp2:
	setstatchanger STAT_EVASION, 2, FALSE
	goto BattleScript_EffectStatUp

BattleScript_EffectTransform::
	attackcanceler
	attackstring
	ppreduce
	trytoclearprimalweather
	printstring STRINGID_EMPTYSTRING3
	waitmessage 1
	transformdataexecution
	attackanimation
	waitanimation
	printfromtable gTransformUsedStringIds
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_EffectAttackDown2:
	setstatchanger STAT_ATK, 2, TRUE
	goto BattleScript_EffectStatDown

BattleScript_EffectDefenseDown2:
	setstatchanger STAT_DEF, 2, TRUE
	goto BattleScript_EffectStatDown

BattleScript_EffectSpeedDown2:
	setstatchanger STAT_SPEED, 2, TRUE
	goto BattleScript_EffectStatDown

BattleScript_EffectSpecialDefenseDown2:
	setstatchanger STAT_SPDEF, 2, TRUE
	goto BattleScript_EffectStatDown

BattleScript_EffectSpecialAttackDown2:
	setstatchanger STAT_SPATK, 2, TRUE
	goto BattleScript_EffectStatDown

BattleScript_EffectAccuracyDown2:
	setstatchanger STAT_ACC, 2, TRUE
	goto BattleScript_EffectStatDown

BattleScript_EffectEvasionDown2:
	setstatchanger STAT_EVASION, 2, TRUE
	goto BattleScript_EffectStatDown

BattleScript_EffectReflect::
	attackcanceler
	attackstring
	ppreduce
	setreflect
BattleScript_PrintReflectLightScreenSafeguardString::
	attackanimation
	waitanimation
	printfromtable gReflectLightScreenSafeguardStringIds
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_EffectPoison::
	attackcanceler
	attackstring
	ppreduce
	jumpifabilityorinnate BS_TARGET, ABILITY_IMMUNITY, BattleScript_ImmunityProtected
	jumpifabilityorinnate BS_TARGET, ABILITY_PYROCLASTIC, BattleScript_PyroclasticProtected
	jumpifabilityorinnate BS_TARGET, ABILITY_COMATOSE, BattleScript_LeafGuardProtects
	jumpifabilityorinnate BS_TARGET, ABILITY_PURIFYING_SALT, BattleScript_LeafGuardProtects
	jumpifabilityorinnate BS_TARGET_SIDE, ABILITY_PASTEL_VEIL, BattleScript_PastelVeilProtects
	jumpifflowerveil BattleScript_FlowerVeilProtects
	jumpifleafguardprotected BS_TARGET, BattleScript_LeafGuardProtects
	jumpifshieldsdown BS_TARGET, BattleScript_LeafGuardProtects
	jumpifsubstituteblocks BattleScript_ButItFailed
	jumpifstatus BS_TARGET, STATUS1_POISON, BattleScript_AlreadyPoisoned
	jumpifstatus BS_TARGET, STATUS1_TOXIC_POISON, BattleScript_AlreadyPoisoned
	trypoisontype BS_ATTACKER, BS_TARGET, BattleScript_NotAffected
	jumpifstatus BS_TARGET, STATUS1_ANY, BattleScript_ButItFailed
	jumpifterrainaffected BS_TARGET, STATUS_FIELD_MISTY_TERRAIN, BattleScript_MistyTerrainPrevents
	accuracycheck BattleScript_ButItFailed, ACC_CURR_MOVE
	jumpifsafeguard BattleScript_SafeguardProtected
	jumpifkingsgrace BattleScript_KingsGraceProtected
	attackanimation
	waitanimation
	setmoveeffect MOVE_EFFECT_POISON
	seteffectprimary
	resultmessage
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_EffectParalyze:
	attackcanceler
	attackstring
	ppreduce
	jumpifabilityorinnate BS_TARGET, ABILITY_LIMBER, BattleScript_LimberProtected
	jumpifabilityorinnate BS_TARGET, ABILITY_COMATOSE, BattleScript_LeafGuardProtects
	jumpifabilityorinnate BS_TARGET, ABILITY_PURIFYING_SALT, BattleScript_LeafGuardProtects
	jumpifflowerveil BattleScript_FlowerVeilProtects
	jumpifleafguardprotected BS_TARGET, BattleScript_LeafGuardProtects
	jumpifshieldsdown BS_TARGET, BattleScript_LeafGuardProtects
	jumpifsubstituteblocks BattleScript_ButItFailed
.if B_GLARE_GHOST >= GEN_4
	jumpifmove MOVE_GLARE, BattleScript_BattleScript_EffectParalyzeNoTypeCalc
.endif
	typecalc
BattleScript_BattleScript_EffectParalyzeNoTypeCalc:
	jumpifmovehadnoeffect BattleScript_ButItFailed
	jumpifstatus BS_TARGET, STATUS1_PARALYSIS, BattleScript_AlreadyParalyzed
	@tryparalyzetype BS_ATTACKER, BS_TARGET, BattleScript_NotAffected
	jumpifstatus BS_TARGET, STATUS1_ANY, BattleScript_ButItFailed
	jumpifterrainaffected BS_TARGET, STATUS_FIELD_MISTY_TERRAIN, BattleScript_MistyTerrainPrevents
	accuracycheck BattleScript_ButItFailed, ACC_CURR_MOVE
	jumpifsafeguard BattleScript_SafeguardProtected
	jumpifkingsgrace BattleScript_KingsGraceProtected
	bichalfword gMoveResultFlags, MOVE_RESULT_SUPER_EFFECTIVE | MOVE_RESULT_NOT_VERY_EFFECTIVE
	attackanimation
	waitanimation
	setmoveeffect MOVE_EFFECT_PARALYSIS
	seteffectprimary
	resultmessage
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_AlreadyParalyzed:
	setalreadystatusedmoveattempt BS_ATTACKER
	pause B_WAIT_TIME_SHORT
	printstring STRINGID_PKMNISALREADYPARALYZED
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_LimberProtected::
	copybyte gEffectBattler, gBattlerTarget
	sethword sABILITY_OVERWRITE, ABILITY_LIMBER
	changelastusedability ABILITY_LIMBER
	setbyte cMULTISTRING_CHOOSER, B_MSG_ABILITY_PREVENTS_MOVE_STATUS
	call BattleScript_AbilityPRLZPrevention
	goto BattleScript_MoveEnd

BattleScript_EffectAttackDownHit::
	setmoveeffect MOVE_EFFECT_ATK_MINUS_1
	goto BattleScript_EffectHit

BattleScript_EffectDefenseDownHit::
	setmoveeffect MOVE_EFFECT_DEF_MINUS_1
	goto BattleScript_EffectHit

BattleScript_EffectSpeedDownHit::
	setmoveeffect MOVE_EFFECT_SPD_MINUS_1
	goto BattleScript_EffectHit

BattleScript_EffectSpecialAttackDownHit::
	setmoveeffect MOVE_EFFECT_SP_ATK_MINUS_1
	goto BattleScript_EffectHit

BattleScript_EffectSpecialDefenseDownHit::
	setmoveeffect MOVE_EFFECT_SP_DEF_MINUS_1
	goto BattleScript_EffectHit

BattleScript_EffectSpecialDefenseDownHit2::
	setmoveeffect MOVE_EFFECT_SP_DEF_MINUS_2
	goto BattleScript_EffectHit

BattleScript_EffectAccuracyDownHit::
	setmoveeffect MOVE_EFFECT_ACC_MINUS_1
	goto BattleScript_EffectHit
	
BattleScript_PowerHerbActivation:
	playanimation BS_ATTACKER, B_ANIM_HELD_ITEM_EFFECT, NULL
	printstring STRINGID_POWERHERB
	waitmessage B_WAIT_TIME_LONG
	removeitem BS_ATTACKER, 1
	return
	
BattleScript_EffectGeomancy:
	jumpifstatus2 BS_ATTACKER, STATUS2_MULTIPLETURNS, BattleScript_GeomancySecondTurn
	jumpifword CMP_COMMON_BITS, gHitMarker, HITMARKER_NO_ATTACKSTRING, BattleScript_GeomancySecondTurn
	setbyte sTWOTURN_STRINGID, B_MSG_TURN1_GEOMANCY
	call BattleScriptFirstChargingTurn
	jumpifnoholdeffect BS_ATTACKER, HOLD_EFFECT_POWER_HERB, BattleScript_MoveEnd
	call BattleScript_PowerHerbActivation
BattleScript_GeomancySecondTurn:
	attackcanceler
	setmoveeffect MOVE_EFFECT_CHARGING
	setbyte sB_ANIM_TURN, 1
	clearstatusfromeffect BS_ATTACKER
	orword gHitMarker, HITMARKER_NO_PPDEDUCT
	attackstring
	jumpifstat BS_ATTACKER, CMP_LESS_THAN, STAT_SPATK, MAX_STAT_STAGE, BattleScript_GeomancyDoMoveAnim
	jumpifstat BS_ATTACKER, CMP_LESS_THAN, STAT_SPDEF, MAX_STAT_STAGE, BattleScript_GeomancyDoMoveAnim
	jumpifstat BS_ATTACKER, CMP_EQUAL, STAT_SPEED, MAX_STAT_STAGE, BattleScript_CantRaiseMultipleStats
BattleScript_GeomancyDoMoveAnim::
	attackanimation
	waitanimation
	setbyte sSTAT_ANIM_PLAYED, FALSE
	playstatchangeanimation BS_ATTACKER, BIT_SPATK | BIT_SPDEF | BIT_SPEED, 0
	setstatchanger STAT_SPATK, 2, FALSE
	statbuffchange MOVE_EFFECT_AFFECTS_ATTACKER | STAT_CHANGE_ALLOW_PTR, BattleScript_GeomancyTrySpDef
	jumpifbyte CMP_EQUAL, cMULTISTRING_CHOOSER, B_MSG_STAT_WONT_INCREASE, BattleScript_GeomancyTrySpDef
	printfromtable gStatUpStringIds
	waitmessage B_WAIT_TIME_LONG
BattleScript_GeomancyTrySpDef::
	setstatchanger STAT_SPDEF, 2, FALSE
	statbuffchange MOVE_EFFECT_AFFECTS_ATTACKER | STAT_CHANGE_ALLOW_PTR, BattleScript_GeomancyTrySpeed
	jumpifbyte CMP_EQUAL, cMULTISTRING_CHOOSER, B_MSG_STAT_WONT_INCREASE, BattleScript_GeomancyTrySpeed
	printfromtable gStatUpStringIds
	waitmessage B_WAIT_TIME_LONG
BattleScript_GeomancyTrySpeed::
	setstatchanger STAT_SPEED, 2, FALSE
	statbuffchange MOVE_EFFECT_AFFECTS_ATTACKER | STAT_CHANGE_ALLOW_PTR, BattleScript_GeomancyEnd
	jumpifbyte CMP_EQUAL, cMULTISTRING_CHOOSER, B_MSG_STAT_WONT_INCREASE, BattleScript_GeomancyEnd
	printfromtable gStatUpStringIds
	waitmessage B_WAIT_TIME_LONG
BattleScript_GeomancyEnd::
	goto BattleScript_MoveEnd

BattleScript_EffectConfuseHit::
	setmoveeffect MOVE_EFFECT_CONFUSE
	goto BattleScript_EffectHit

BattleScript_EffectTwineedle::
	attackcanceler
	accuracycheck BattleScript_PrintMoveMissed, ACC_CURR_MOVE
	sethword sMULTIHIT_EFFECT, MOVE_EFFECT_POISON
	attackstring
	ppreduce
	setmultihitcounter 2
	initmultihitstring
	goto BattleScript_MultiHitLoop

BattleScript_EffectSubstitute::
	attackcanceler
	ppreduce
	attackstring
	waitstate
	jumpifstatus2 BS_ATTACKER, STATUS2_SUBSTITUTE, BattleScript_AlreadyHasSubstitute
	jumpifstatus2 BS_ATTACKER, STATUS2_PSYSHIELD, BattleScript_AlreadyHasPsyshield
	setsubstitute
	jumpifbyte CMP_NOT_EQUAL, cMULTISTRING_CHOOSER, B_MSG_SUBSTITUTE_FAILED, BattleScript_SubstituteAnim
	pause B_WAIT_TIME_SHORT
	goto BattleScript_SubstituteString
BattleScript_SubstituteAnim::
	attackanimation
	waitanimation
	healthbarupdate BS_ATTACKER
	datahpupdate BS_ATTACKER
BattleScript_SubstituteString::
	printfromtable gSubstituteUsedStringIds
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd
BattleScript_AlreadyHasSubstitute::
	setalreadystatusedmoveattempt BS_ATTACKER
	pause B_WAIT_TIME_SHORT
	printstring STRINGID_PKMNHASSUBSTITUTE
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_EffectRecharge::
	attackcanceler
	accuracycheck BattleScript_PrintMoveMissed, ACC_CURR_MOVE
	setmoveeffect MOVE_EFFECT_RECHARGE | MOVE_EFFECT_AFFECTS_ATTACKER | MOVE_EFFECT_CERTAIN
	goto BattleScript_HitFromAtkString

BattleScript_MoveUsedMustRecharge::
	printstring STRINGID_PKMNMUSTRECHARGE
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_EffectRage::
	attackcanceler
	accuracycheck BattleScript_RageMiss, ACC_CURR_MOVE
	setmoveeffect MOVE_EFFECT_RAGE
	seteffectprimary
	setmoveeffect 0
	goto BattleScript_HitFromAtkString
BattleScript_RageMiss::
	setmoveeffect MOVE_EFFECT_RAGE
	clearstatusfromeffect BS_ATTACKER
	goto BattleScript_PrintMoveMissed

BattleScript_EffectMimic::
	attackcanceler
	attackstring
	ppreduce
	jumpifsubstituteblocks BattleScript_ButItFailed
	accuracycheck BattleScript_ButItFailed, NO_ACC_CALC_CHECK_LOCK_ON
	mimicattackcopy BattleScript_ButItFailed
	attackanimation
	waitanimation
	printstring STRINGID_PKMNLEARNEDMOVE2
	waitmessage B_WAIT_TIME_LONG
	jumptocalledmove TRUE

BattleScript_EffectMetronome::
	attackcanceler
	attackstring
	pause B_WAIT_TIME_SHORT
	attackanimation
	waitanimation
	setbyte sB_ANIM_TURN, 0
	setbyte sB_ANIM_TARGETS_HIT, 0
	metronome

BattleScript_EffectLeechSeed::
	attackcanceler
	attackstring
	pause B_WAIT_TIME_SHORT
	ppreduce
	jumpifsubstituteblocks BattleScript_ButItFailed
	accuracycheck BattleScript_DoLeechSeed, ACC_CURR_MOVE
BattleScript_DoLeechSeed::
	setseeded
	attackanimation
	waitanimation
	printfromtable gLeechSeedStringIds
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_EffectDoNothing::
	attackcanceler
	attackstring
	ppreduce
	jumpifmove MOVE_HOLD_HANDS, BattleScript_EffectHoldHands
	attackanimation
	waitanimation
	jumpifmove MOVE_CELEBRATE, BattleScript_EffectCelebrate
	jumpifmove MOVE_HAPPY_HOUR, BattleScript_EffectHappyHour
	incrementgamestat GAME_STAT_USED_SPLASH
	printstring STRINGID_BUTNOTHINGHAPPENED
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd
BattleScript_EffectHoldHands:
	jumpifsideaffecting BS_TARGET, SIDE_STATUS_CRAFTY_SHIELD, BattleScript_ButItFailed
	jumpifbyteequal gBattlerTarget, gBattlerAttacker, BattleScript_ButItFailed
	attackanimation
	waitanimation
	goto BattleScript_MoveEnd
BattleScript_EffectCelebrate:
	printstring STRINGID_CELEBRATEMESSAGE
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd
BattleScript_EffectHappyHour:
	setmoveeffect MOVE_EFFECT_HAPPY_HOUR
	seteffectprimary
	goto BattleScript_MoveEnd

BattleScript_EffectDisable::
	attackcanceler
	attackstring
	ppreduce
	jumpifabilityorinnate BS_TARGET_SIDE, ABILITY_AROMA_VEIL, BattleScript_AromaVeilProtects
	accuracycheck BattleScript_ButItFailed, ACC_CURR_MOVE
	disablelastusedattack BattleScript_ButItFailed
	attackanimation
	waitanimation
	printstring STRINGID_PKMNMOVEWASDISABLED
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_EffectLevelDamage::
	attackcanceler
	accuracycheck BattleScript_PrintMoveMissed, ACC_CURR_MOVE
	attackstring
	ppreduce
	typecalc
	bichalfword gMoveResultFlags, MOVE_RESULT_SUPER_EFFECTIVE | MOVE_RESULT_NOT_VERY_EFFECTIVE
	dmgtolevel
	adjustdamage
	goto BattleScript_HitFromAtkAnimation

BattleScript_EffectPsywave::
	attackcanceler
	accuracycheck BattleScript_PrintMoveMissed, ACC_CURR_MOVE
	attackstring
	ppreduce
	typecalc
	bichalfword gMoveResultFlags, MOVE_RESULT_SUPER_EFFECTIVE | MOVE_RESULT_NOT_VERY_EFFECTIVE
	dmgtolevel
	adjustdamage
	goto BattleScript_HitFromAtkAnimation

BattleScript_EffectCounter::
	attackcanceler
	counterdamagecalculator BattleScript_FailedFromAtkString
	accuracycheck BattleScript_PrintMoveMissed, ACC_CURR_MOVE
	attackstring
	ppreduce
	typecalc
	bichalfword gMoveResultFlags, MOVE_RESULT_NOT_VERY_EFFECTIVE | MOVE_RESULT_SUPER_EFFECTIVE
	adjustdamage
	goto BattleScript_HitFromAtkAnimation

BattleScript_EffectEncore::
	attackcanceler
	accuracycheck BattleScript_PrintMoveMissed, ACC_CURR_MOVE
	attackstring
	ppreduce
	jumpifabilityorinnate BS_TARGET_SIDE, ABILITY_AROMA_VEIL, BattleScript_AromaVeilProtects
	trysetencore BattleScript_ButItFailed
	attackanimation
	waitanimation
	printstring STRINGID_PKMNGOTENCORE
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_EffectPainSplit::
	attackcanceler
	attackstring
	ppreduce
	accuracycheck BattleScript_ButItFailed, NO_ACC_CALC_CHECK_LOCK_ON
	painsplitdmgcalc BattleScript_ButItFailed
	attackanimation
	waitanimation
	orword gHitMarker, HITMARKER_IGNORE_SUBSTITUTE
	healthbarupdate BS_ATTACKER
	datahpupdate BS_ATTACKER
	copyword gBattleMoveDamage, sPAINSPLIT_HP
	healthbarupdate BS_TARGET
	datahpupdate BS_TARGET
	printstring STRINGID_SHAREDPAIN
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_EffectSnore::
	attackcanceler
	jumpifabilityorinnate BS_ATTACKER, ABILITY_COMATOSE, BattleScript_SnoreIsAsleep
	jumpifstatus BS_ATTACKER, STATUS1_SLEEP, BattleScript_SnoreIsAsleep
	goto BattleScript_DoSnore
BattleScript_SnoreIsAsleep::
	jumpifhalfword CMP_EQUAL, gChosenMove, MOVE_SLEEP_TALK, BattleScript_DoSnore
	printstring STRINGID_PKMNFASTASLEEP
	waitmessage B_WAIT_TIME_LONG
	statusanimation BS_ATTACKER
BattleScript_DoSnore::
	attackstring
	ppreduce
	accuracycheck BattleScript_MoveMissedPause, ACC_CURR_MOVE
	setmoveeffect MOVE_EFFECT_FLINCH
	goto BattleScript_HitFromCritCalc

BattleScript_EffectConversion2::
	attackcanceler
	attackstring
	ppreduce
	settypetorandomresistance BattleScript_ButItFailed
	attackanimation
	waitanimation
	printstring STRINGID_PKMNCHANGEDTYPE
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_EffectLockOn::
	attackcanceler
	attackstring
	ppreduce
	jumpifsubstituteblocks BattleScript_ButItFailed
	accuracycheck BattleScript_ButItFailed, ACC_CURR_MOVE
	setalwayshitflag
	attackanimation
	waitanimation
	printstring STRINGID_PKMNTOOKAIM
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_EffectSketch::
	attackcanceler
	attackstring
	ppreduce
	copymovepermanently BattleScript_ButItFailed
	attackanimation
	waitanimation
	printstring STRINGID_PKMNSKETCHEDMOVE
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_EffectSleepTalk::
	attackcanceler
	jumpifabilityorinnate BS_ATTACKER, ABILITY_COMATOSE, BattleScript_SleepTalkIsAsleep
	jumpifstatus BS_ATTACKER, STATUS1_SLEEP, BattleScript_SleepTalkIsAsleep
	attackstring
	ppreduce
	goto BattleScript_ButItFailed
BattleScript_SleepTalkIsAsleep::
	printstring STRINGID_PKMNFASTASLEEP
	waitmessage B_WAIT_TIME_LONG
	statusanimation BS_ATTACKER
	attackstring
	ppreduce
	orword gHitMarker, HITMARKER_NO_PPDEDUCT
	trychoosesleeptalkmove BattleScript_SleepTalkUsingMove
	pause B_WAIT_TIME_LONG
	goto BattleScript_ButItFailed
BattleScript_SleepTalkUsingMove::
	attackanimation
	waitanimation
	setbyte sB_ANIM_TURN, 0
	setbyte sB_ANIM_TARGETS_HIT, 0
	jumptocalledmove TRUE

BattleScript_EffectDestinyBond::
	attackcanceler
	attackstring
	ppreduce
	setdestinybond
	attackanimation
	waitanimation
	printstring STRINGID_PKMNTRYINGTOTAKEFOE
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_EffectEerieSpell::
	attackcanceler
	attackstring
	ppreduce
	accuracycheck BattleScript_ButItFailed, ACC_CURR_MOVE
	attackstring
	call BattleScript_EffectDamage_Ret
	tryfaintmon BS_TARGET, FALSE, NULL
	eeriespellppreduce BattleScript_MoveEnd
	printstring STRINGID_PKMNREDUCEDPP
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_EffectSpite::
	attackcanceler
	attackstring
	ppreduce
	accuracycheck BattleScript_ButItFailed, ACC_CURR_MOVE
	tryspiteppreduce BattleScript_ButItFailed
	attackanimation
	waitanimation
	printstring STRINGID_PKMNREDUCEDPP
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_EffectHealBell::
	attackcanceler
	attackstring
	ppreduce
	healpartystatus
	waitstate
	attackanimation
	waitanimation
	printfromtable gPartyStatusHealStringIds
	waitmessage B_WAIT_TIME_LONG
	jumpifnotmove MOVE_HEAL_BELL, BattleScript_PartyHealEnd
	jumpifbyte CMP_NO_COMMON_BITS, cMULTISTRING_CHOOSER, B_MSG_BELL_SOUNDPROOF_ATTACKER, BattleScript_CheckHealBellMon2Unaffected
	printstring STRINGID_PKMNSXBLOCKSY
	waitmessage B_WAIT_TIME_LONG
BattleScript_CheckHealBellMon2Unaffected::
	jumpifbyte CMP_NO_COMMON_BITS, cMULTISTRING_CHOOSER, B_MSG_BELL_SOUNDPROOF_PARTNER, BattleScript_PartyHealEnd
	printstring STRINGID_PKMNSXBLOCKSY2
	waitmessage B_WAIT_TIME_LONG
BattleScript_PartyHealEnd::
	updatestatusicon BS_ATTACKER_WITH_PARTNER
	waitstate
	goto BattleScript_MoveEnd

BattleScript_EffectTripleKick::
	attackcanceler
	attackstring
	ppreduce
	initmultihitstring
	setmultihit 3
	movevaluescleanup
BattleScript_TripleKickLoop::
	jumpifhasnohp BS_ATTACKER, BattleScript_TripleKickEnd
	jumpifhasnohp BS_TARGET, BattleScript_TripleKickNoMoreHits
	jumpifhalfword CMP_EQUAL, gChosenMove, MOVE_SLEEP_TALK, BattleScript_DoTripleKickAttack
	jumpifstatus BS_ATTACKER, STATUS1_SLEEP, BattleScript_TripleKickNoMoreHits
BattleScript_DoTripleKickAttack::
	accuracycheck BattleScript_TripleKickNoMoreHits, ACC_CURR_MOVE
BattleScript_DoTripleKickAttackWithoutAccCheck::
	movevaluescleanup
	addbyte sMULTIHIT_STRING + 4, 1
	critcalc
	damagecalc
	adjustdamage
	jumpifmovehadnoeffect BattleScript_TripleKickNoMoreHits
	attackanimation
	waitanimation
	effectivenesssound
	hitanimation BS_TARGET
	waitstate
	healthbarupdate BS_TARGET
	datahpupdate BS_TARGET
	critmessage
	waitmessage B_WAIT_TIME_LONG
	printstring STRINGID_EMPTYSTRING3
	waitmessage 1
	moveendto MOVEEND_NEXT_TARGET
	jumpifbyte CMP_COMMON_BITS, gMoveResultFlags, MOVE_RESULT_FOE_ENDURED, BattleScript_TripleKickPrintStrings
	decrementmultihit BattleScript_TripleKickLoop, BattleScript_TripleKickLoadedDiceLoop
	goto BattleScript_TripleKickPrintStrings
BattleScript_TripleKickNoMoreHits::
	pause B_WAIT_TIME_SHORT
	jumpifbyte CMP_EQUAL, sMULTIHIT_STRING + 4, 0, BattleScript_TripleKickPrintStrings
	bichalfword gMoveResultFlags, MOVE_RESULT_MISSED
BattleScript_TripleKickPrintStrings::
	resultmessage
	waitmessage B_WAIT_TIME_LONG
	jumpifbyte CMP_EQUAL, sMULTIHIT_STRING + 4, 0, BattleScript_TripleKickEnd
	jumpifhalfword CMP_COMMON_BITS, gMoveResultFlags, MOVE_RESULT_DOESNT_AFFECT_FOE, BattleScript_TripleKickEnd
	copyarray gBattleTextBuff1, sMULTIHIT_STRING, 6
	printstring STRINGID_HITXTIMES
	waitmessage B_WAIT_TIME_LONG
BattleScript_TripleKickEnd::
	seteffectwithchance
	tryfaintmon BS_TARGET, FALSE, NULL
	moveendfrom MOVEEND_UPDATE_LAST_MOVES
	end

BattleScript_TripleKickLoadedDiceLoop::
	jumpifhasnohp BS_ATTACKER, BattleScript_TripleKickEnd
	jumpifhasnohp BS_TARGET, BattleScript_TripleKickNoMoreHits
	jumpifhalfword CMP_EQUAL, gChosenMove, MOVE_SLEEP_TALK, BattleScript_DoTripleKickAttackWithoutAccCheck
	jumpifstatus BS_ATTACKER, STATUS1_SLEEP, BattleScript_TripleKickNoMoreHits
	goto BattleScript_DoTripleKickAttackWithoutAccCheck

BattleScript_EffectThief::
	setmoveeffect MOVE_EFFECT_STEAL_ITEM
	goto BattleScript_EffectHit

BattleScript_EffectHitPreventEscape:
	setmoveeffect MOVE_EFFECT_PREVENT_ESCAPE
	goto BattleScript_EffectHit

BattleScript_EffectMeanLook::
	attackcanceler
	attackstring
	ppreduce
	accuracycheck BattleScript_ButItFailed, NO_ACC_CALC_CHECK_LOCK_ON
	jumpifstatus2 BS_TARGET, STATUS2_ESCAPE_PREVENTION, BattleScript_ButItFailed
	jumpifsubstituteblocks BattleScript_ButItFailed
.if B_GHOSTS_ESCAPE >= GEN_6
	jumpiftype BS_TARGET, TYPE_GHOST, BattleScript_ButItFailed
.endif
	attackanimation
	waitanimation
	setmoveeffect MOVE_EFFECT_PREVENT_ESCAPE
	seteffectprimary
	printstring STRINGID_TARGETCANTESCAPENOW
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_EffectNightmare::
	attackcanceler
	attackstring
	ppreduce
	jumpifsubstituteblocks BattleScript_ButItFailed
	jumpifstatus2 BS_TARGET, STATUS2_NIGHTMARE, BattleScript_ButItFailed
	jumpifstatus BS_TARGET, STATUS1_SLEEP, BattleScript_NightmareWorked
	jumpifabilityorinnate BS_TARGET, ABILITY_COMATOSE, BattleScript_NightmareWorked
	goto BattleScript_ButItFailed
BattleScript_NightmareWorked::
	attackanimation
	waitanimation
	setmoveeffect MOVE_EFFECT_NIGHTMARE
	seteffectprimary
	printstring STRINGID_PKMNFELLINTONIGHTMARE
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_EffectMinimize::
	attackcanceler
	setminimize
.if B_MINIMIZE_EVASION >= GEN_5
	setstatchanger STAT_EVASION, 2, FALSE
.else
	setstatchanger STAT_EVASION, 1, FALSE
.endif
	goto BattleScript_EffectStatUpAfterAtkCanceler

BattleScript_EffectCurse::
	jumpiftype BS_ATTACKER, TYPE_GHOST, BattleScript_GhostCurse
	attackcanceler
	attackstring
	ppreduce
	jumpifstat BS_ATTACKER, CMP_GREATER_THAN, STAT_SPEED, MIN_STAT_STAGE, BattleScript_CurseTrySpeed
	jumpifstat BS_ATTACKER, CMP_NOT_EQUAL, STAT_ATK, MAX_STAT_STAGE, BattleScript_CurseTrySpeed
	jumpifstat BS_ATTACKER, CMP_EQUAL, STAT_DEF, MAX_STAT_STAGE, BattleScript_ButItFailed
BattleScript_CurseTrySpeed::
	copybyte gBattlerTarget, gBattlerAttacker
	setbyte sB_ANIM_TURN, 1
	attackanimation
	waitanimation
	setstatchanger STAT_SPEED, 1, TRUE
	statbuffchange MOVE_EFFECT_AFFECTS_ATTACKER | STAT_CHANGE_ALLOW_PTR, BattleScript_CurseTryAttack
	printfromtable gStatDownStringIds
	waitmessage B_WAIT_TIME_LONG
BattleScript_CurseTryAttack::
	setstatchanger STAT_ATK, 1, FALSE
	statbuffchange MOVE_EFFECT_AFFECTS_ATTACKER | STAT_CHANGE_ALLOW_PTR, BattleScript_CurseTryDefense
	printfromtable gStatUpStringIds
	waitmessage B_WAIT_TIME_LONG
BattleScript_CurseTryDefense::
	setstatchanger STAT_DEF, 1, FALSE
	statbuffchange MOVE_EFFECT_AFFECTS_ATTACKER | STAT_CHANGE_ALLOW_PTR, BattleScript_CurseEnd
	printfromtable gStatUpStringIds
	waitmessage B_WAIT_TIME_LONG
BattleScript_CurseEnd::
	goto BattleScript_MoveEnd
BattleScript_GhostCurse::
	jumpifbytenotequal gBattlerAttacker, gBattlerTarget, BattleScript_DoGhostCurse
	getmovetarget BS_ATTACKER
BattleScript_DoGhostCurse::
	attackcanceler
	attackstring
	ppreduce
	accuracycheck BattleScript_ButItFailed, NO_ACC_CALC_CHECK_LOCK_ON
	cursetarget BattleScript_ButItFailed
	orword gHitMarker, HITMARKER_IGNORE_SUBSTITUTE
	setbyte sB_ANIM_TURN, 0
	attackanimation
	waitanimation
	healthbarupdate BS_ATTACKER
	datahpupdate BS_ATTACKER
	printstring STRINGID_PKMNLAIDCURSE
	waitmessage B_WAIT_TIME_LONG
	tryfaintmon BS_ATTACKER, FALSE, NULL
	goto BattleScript_MoveEnd

BattleScript_EffectMatBlock::
	attackcanceler
	jumpifnotfirstturn BattleScript_FailedFromAtkString
	goto BattleScript_ProtectLikeAtkString

BattleScript_EffectProtect::
BattleScript_EffectEndure::
	attackcanceler
BattleScript_ProtectLikeAtkString:
	attackstring
	ppreduce
	setprotectlike
	attackanimation
	waitanimation
	printfromtable gProtectLikeUsedStringIds
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_EffectSpikes::
	attackcanceler
	trysetspikes BattleScript_FailedFromAtkString
	attackstring
	ppreduce
	attackanimation
	waitanimation
	printstring STRINGID_SPIKESSCATTERED
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_EffectForesight:
	attackcanceler
	attackstring
	ppreduce
	accuracycheck BattleScript_ButItFailed, NO_ACC_CALC_CHECK_LOCK_ON
	jumpifstatus2 BS_TARGET, STATUS2_FORESIGHT, BattleScript_ButItFailed
	setforesight
BattleScript_IdentifiedFoe:
	attackanimation
	waitanimation
	printstring STRINGID_PKMNIDENTIFIED
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_EffectPerishSong::
	attackcanceler
	attackstring
	ppreduce
	trysetperishsong BattleScript_ButItFailed
	attackanimation
	waitanimation
	printstring STRINGID_FAINTINTHREE
	waitmessage B_WAIT_TIME_LONG
	setbyte gBattlerTarget, 0
BattleScript_PerishSongLoop::
	jumpifabilityorinnate BS_TARGET, ABILITY_SOUNDPROOF, BattleScript_PerishSongBlocked
	jumpifpranksterblocked BS_TARGET, BattleScript_PerishSongNotAffected
BattleScript_PerishSongLoopIncrement::
	addbyte gBattlerTarget, 1
	jumpifbytenotequal gBattlerTarget, gBattlersCount, BattleScript_PerishSongLoop
	goto BattleScript_MoveEnd

BattleScript_PerishSongBlocked::
	copybyte sBATTLER, gBattlerTarget
	printstring STRINGID_PKMNSXBLOCKSY2
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_PerishSongLoopIncrement

BattleScript_PerishSongNotAffected:
	printstring STRINGID_ITDOESNTAFFECT
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_PerishSongLoopIncrement	

BattleScript_EffectSandstorm::
	attackcanceler
	attackstring
	ppreduce
	jumpifhalfword CMP_COMMON_BITS, gBattleWeather, WEATHER_SUN_PRIMAL, BattleScript_ExtremelyHarshSunlightWasNotLessened
	jumpifhalfword CMP_COMMON_BITS, gBattleWeather, WEATHER_RAIN_PRIMAL, BattleScript_NoReliefFromHeavyRain
	jumpifhalfword CMP_COMMON_BITS, gBattleWeather, WEATHER_STRONG_WINDS, BattleScript_MysteriousAirCurrentBlowsOn
	setsandstorm
	goto BattleScript_MoveWeatherChange

BattleScript_EffectRollout::
	attackcanceler
	attackstring
	jumpifstatus2 BS_ATTACKER, STATUS2_MULTIPLETURNS, BattleScript_RolloutCheckAccuracy
	ppreduce
BattleScript_RolloutCheckAccuracy::
	accuracycheck BattleScript_RolloutHit, ACC_CURR_MOVE
BattleScript_RolloutHit::
	typecalc
	handlerollout
	call BattleScript_EffectDamage_Ret
	jumpifhalfword CMP_COMMON_BITS, gMoveResultFlags, MOVE_RESULT_DOESNT_AFFECT_FOE, BattleScript_MoveEnd
	setmoveeffect MOVE_EFFECT_RAPIDSPIN | MOVE_EFFECT_AFFECTS_ATTACKER | MOVE_EFFECT_CERTAIN
	seteffectwithchance
	setstatchanger STAT_SPEED, 1, FALSE
	statbuffchange MOVE_EFFECT_AFFECTS_ATTACKER | STAT_CHANGE_ALLOW_PTR, BattleScript_EffectRolloutEnd
	jumpifbyte CMP_EQUAL, cMULTISTRING_CHOOSER, B_MSG_STAT_WONT_INCREASE, BattleScript_EffectRolloutEnd
	setgraphicalstatchangevalues
	playanimation BS_ATTACKER, B_ANIM_STATS_CHANGE, sB_ANIM_ARG1
	printfromtable gStatUpStringIds
	waitmessage B_WAIT_TIME_LONG
BattleScript_EffectRolloutEnd::
	tryfaintmon BS_TARGET, FALSE, NULL
	moveendall
	end

BattleScript_EffectSwagger::
	attackcanceler
	jumpifsubstituteblocks BattleScript_MakeMoveMissed
	accuracycheck BattleScript_PrintMoveMissed, ACC_CURR_MOVE
	attackstring
	ppreduce
	jumpifconfusedandstatmaxed STAT_ATK, BattleScript_ButItFailed
	attackanimation
	waitanimation
	setstatchanger STAT_ATK, 2, FALSE
	statbuffchange STAT_CHANGE_ALLOW_PTR, BattleScript_SwaggerTryConfuse
	jumpifbyte CMP_EQUAL, cMULTISTRING_CHOOSER, B_MSG_STAT_WONT_INCREASE, BattleScript_SwaggerTryConfuse
	setgraphicalstatchangevalues
	playanimation BS_TARGET, B_ANIM_STATS_CHANGE, sB_ANIM_ARG1
	printfromtable gStatUpStringIds
	waitmessage B_WAIT_TIME_LONG
BattleScript_SwaggerTryConfuse:
	jumpifabilityorinnate BS_TARGET, ABILITY_OWN_TEMPO, BattleScript_InnateOwnTempoPrevents
	jumpifsafeguard BattleScript_SafeguardProtected
	jumpifkingsgrace BattleScript_KingsGraceProtected
	setmoveeffect MOVE_EFFECT_CONFUSE
	seteffectprimary
	goto BattleScript_MoveEnd

BattleScript_EffectFuryCutter:
	attackcanceler
	attackstring
	ppreduce
	accuracycheck BattleScript_FuryCutterHit, ACC_CURR_MOVE
BattleScript_FuryCutterHit:
	handlefurycutter
	critcalc
	damagecalc
	jumpifmovehadnoeffect BattleScript_FuryCutterHit
	adjustdamage
	goto BattleScript_HitFromAtkAnimation
	
BattleScript_TryDestinyKnotTarget:
	jumpifnoholdeffect BS_ATTACKER, HOLD_EFFECT_DESTINY_KNOT, BattleScript_TryDestinyKnotTargetRet
	infatuatewithbattler BS_TARGET, BS_ATTACKER
	playanimation BS_ATTACKER, B_ANIM_HELD_ITEM_EFFECT, NULL
	waitanimation
	status2animation BS_TARGET, STATUS2_INFATUATION
	waitanimation
	printstring STRINGID_DESTINYKNOTACTIVATES
	waitmessage B_WAIT_TIME_LONG
BattleScript_TryDestinyKnotTargetRet:
	return
	
BattleScript_TryDestinyKnotAttacker:
	jumpifnoholdeffect BS_TARGET, HOLD_EFFECT_DESTINY_KNOT, BattleScript_TryDestinyKnotAttackerRet
	infatuatewithbattler BS_ATTACKER, BS_TARGET
	playanimation BS_TARGET, B_ANIM_HELD_ITEM_EFFECT, NULL
	waitanimation
	status2animation BS_ATTACKER, STATUS2_INFATUATION
	waitanimation
	printstring STRINGID_DESTINYKNOTACTIVATES
	waitmessage B_WAIT_TIME_LONG
BattleScript_TryDestinyKnotAttackerRet:
	return

BattleScript_EffectAttract::
	attackcanceler
	attackstring
	ppreduce
	accuracycheck BattleScript_ButItFailed, ACC_CURR_MOVE
	jumpifabilityorinnate BS_TARGET_SIDE, ABILITY_AROMA_VEIL, BattleScript_AromaVeilProtects
	tryinfatuating BattleScript_ButItFailed
	attackanimation
	waitanimation
	printstring STRINGID_PKMNFELLINLOVE
	waitmessage B_WAIT_TIME_LONG
	call BattleScript_TryDestinyKnotAttacker
	goto BattleScript_MoveEnd

BattleScript_EffectPresent::
	attackcanceler
	accuracycheck BattleScript_PrintMoveMissed, ACC_CURR_MOVE
	attackstring
	ppreduce
	typecalc
	presentdamagecalculation

BattleScript_EffectSafeguard::
	attackcanceler
	attackstring
	ppreduce
	setsafeguard
	goto BattleScript_PrintReflectLightScreenSafeguardString

BattleScript_EffectMagnitude::
	jumpifword CMP_COMMON_BITS, gHitMarker, HITMARKER_NO_ATTACKSTRING | HITMARKER_NO_PPDEDUCT, BattleScript_EffectMagnitudeTarget 
	attackcanceler
	attackstring
	ppreduce
	magnitudedamagecalculation
	pause B_WAIT_TIME_SHORT
	printstring STRINGID_MAGNITUDESTRENGTH
	waitmessage B_WAIT_TIME_LONG
BattleScript_EffectMagnitudeTarget:
	accuracycheck BattleScript_MoveMissedPause, ACC_CURR_MOVE
	goto BattleScript_HitFromCritCalc

BattleScript_EffectBatonPass::
	attackcanceler
	attackstring
	ppreduce
	jumpifbattletype BATTLE_TYPE_ARENA, BattleScript_ButItFailed
	jumpifcantswitch SWITCH_IGNORE_ESCAPE_PREVENTION | BS_ATTACKER, BattleScript_ButItFailed
	attackanimation
	waitanimation
	openpartyscreen BS_ATTACKER, BattleScript_ButItFailed
	switchoutabilitiesorinnates BS_ATTACKER, 0
	switchoutabilitiesorinnates BS_ATTACKER, 1
	switchoutabilitiesorinnates BS_ATTACKER, 2
	switchoutabilitiesorinnates BS_ATTACKER, 3
	swithchoutrevolvingruin BS_ATTACKER
	waitstate
	switchhandleorder BS_ATTACKER, 2
	returntoball BS_ATTACKER
	getswitchedmondata BS_ATTACKER
	switchindataupdate BS_ATTACKER
	hpthresholds BS_ATTACKER
	trytoclearprimalweather
	printstring STRINGID_EMPTYSTRING3
	waitmessage 1
	printstring STRINGID_SWITCHINMON
	switchinanim BS_ATTACKER, TRUE
	waitstate
	switchineffects BS_ATTACKER
	goto BattleScript_MoveEnd

BattleScript_EffectRapidSpin::
	attackcanceler
	accuracycheck BattleScript_PrintMoveMissed, ACC_CURR_MOVE
	attackstring
	ppreduce
	call BattleScript_EffectDamage_Ret
	jumpifhalfword CMP_COMMON_BITS, gMoveResultFlags, MOVE_RESULT_DOESNT_AFFECT_FOE, BattleScript_MoveEnd
	setmoveeffect MOVE_EFFECT_RAPIDSPIN | MOVE_EFFECT_AFFECTS_ATTACKER | MOVE_EFFECT_CERTAIN
	seteffectwithchance
	setstatchanger STAT_SPEED, 1, FALSE
BattleScript_RapidSpinSecondaryEffect:
	statbuffchange MOVE_EFFECT_AFFECTS_ATTACKER | STAT_CHANGE_ALLOW_PTR, BattleScript_RapidSpinEnd
	jumpifbyte CMP_EQUAL, cMULTISTRING_CHOOSER, B_MSG_STAT_WONT_INCREASE, BattleScript_RapidSpinEnd
	setgraphicalstatchangevalues
	playanimation BS_ATTACKER, B_ANIM_STATS_CHANGE, sB_ANIM_ARG1
	printfromtable gStatUpStringIds
	waitmessage B_WAIT_TIME_LONG
BattleScript_RapidSpinEnd::
	argumenttomoveeffect
	seteffectwithchance
	tryfaintmon BS_TARGET, FALSE, NULL
	moveendall
	end

BattleScript_EffectSonicboom::
	attackcanceler
	accuracycheck BattleScript_PrintMoveMissed, ACC_CURR_MOVE
	attackstring
	ppreduce
	typecalc
	bichalfword gMoveResultFlags, MOVE_RESULT_SUPER_EFFECTIVE | MOVE_RESULT_NOT_VERY_EFFECTIVE
	dmgtolevel
	adjustdamage
	goto BattleScript_HitFromAtkAnimation

BattleScript_EffectMorningSun::
BattleScript_EffectSynthesis::
BattleScript_EffectMoonlight::
BattleScript_EffectShoreUp::
	attackcanceler
	attackstring
	ppreduce
	recoverbasedonsunlight BattleScript_AlreadyAtFullHp
	goto BattleScript_PresentHealTarget

BattleScript_EffectRainDance::
	attackcanceler
	attackstring
	ppreduce
	jumpifhalfword CMP_COMMON_BITS, gBattleWeather, WEATHER_SUN_PRIMAL, BattleScript_ExtremelyHarshSunlightWasNotLessened
	jumpifhalfword CMP_COMMON_BITS, gBattleWeather, WEATHER_RAIN_PRIMAL, BattleScript_NoReliefFromHeavyRain
	jumpifhalfword CMP_COMMON_BITS, gBattleWeather, WEATHER_STRONG_WINDS, BattleScript_MysteriousAirCurrentBlowsOn
	setrain
BattleScript_MoveWeatherChange::
	attackanimation
	waitanimation
	printfromtable gMoveWeatherChangeStringIds
	waitmessage B_WAIT_TIME_LONG
	call BattleScript_WeatherFormChanges
	goto BattleScript_MoveEnd

BattleScript_EffectSunnyDay::
	attackcanceler
	attackstring
	ppreduce
	jumpifhalfword CMP_COMMON_BITS, gBattleWeather, WEATHER_SUN_PRIMAL, BattleScript_ExtremelyHarshSunlightWasNotLessened
	jumpifhalfword CMP_COMMON_BITS, gBattleWeather, WEATHER_RAIN_PRIMAL, BattleScript_NoReliefFromHeavyRain
	jumpifhalfword CMP_COMMON_BITS, gBattleWeather, WEATHER_STRONG_WINDS, BattleScript_MysteriousAirCurrentBlowsOn
	setsunny
	goto BattleScript_MoveWeatherChange

BattleScript_EffectFog::
	attackcanceler
	attackstring
	ppreduce
	jumpifhalfword CMP_COMMON_BITS, gBattleWeather, WEATHER_SUN_PRIMAL, BattleScript_ExtremelyHarshSunlightWasNotLessened
	jumpifhalfword CMP_COMMON_BITS, gBattleWeather, WEATHER_RAIN_PRIMAL, BattleScript_NoReliefFromHeavyRain
	jumpifhalfword CMP_COMMON_BITS, gBattleWeather, WEATHER_STRONG_WINDS, BattleScript_MysteriousAirCurrentBlowsOn
	setfog
	goto BattleScript_MoveWeatherChange

BattleScript_ExtremelyHarshSunlightWasNotLessened:
	pause B_WAIT_TIME_SHORT
	printstring STRINGID_EXTREMELYHARSHSUNLIGHTWASNOTLESSENED
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_ExtremelyHarshSunlightWasNotLessenedEnd3:
	pause B_WAIT_TIME_SHORT
	printstring STRINGID_EXTREMELYHARSHSUNLIGHTWASNOTLESSENED
	waitmessage B_WAIT_TIME_LONG
	end3

BattleScript_ExtremelyHarshSunlightWasNotLessenedRet:
	pause B_WAIT_TIME_SHORT
	printstring STRINGID_EXTREMELYHARSHSUNLIGHTWASNOTLESSENED
	waitmessage B_WAIT_TIME_LONG
	return

BattleScript_NoReliefFromHeavyRain:
	pause B_WAIT_TIME_SHORT
	printstring STRINGID_NORELIEFROMHEAVYRAIN
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_NoReliefFromHeavyRainEnd3:
	pause B_WAIT_TIME_SHORT
	printstring STRINGID_NORELIEFROMHEAVYRAIN
	waitmessage B_WAIT_TIME_LONG
	end3

BattleScript_NoReliefFromHeavyRainRet:
	pause B_WAIT_TIME_SHORT
	printstring STRINGID_NORELIEFROMHEAVYRAIN
	waitmessage B_WAIT_TIME_LONG
	return

BattleScript_MysteriousAirCurrentBlowsOn:
	pause B_WAIT_TIME_SHORT
	printstring STRINGID_MYSTERIOUSAIRCURRENTBLOWSON
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_MysteriousAirCurrentBlowsOnEnd3:
	pause B_WAIT_TIME_SHORT
	printstring STRINGID_MYSTERIOUSAIRCURRENTBLOWSON
	waitmessage B_WAIT_TIME_LONG
	end3

BattleScript_MysteriousAirCurrentBlowsOnRet:
	pause B_WAIT_TIME_SHORT
	printstring STRINGID_MYSTERIOUSAIRCURRENTBLOWSON
	waitmessage B_WAIT_TIME_LONG
	return

BattleScript_BlockedByPrimalWeatherEnd3::
	call BattleScript_AbilityPopUp
	jumpifhalfword CMP_COMMON_BITS, gBattleWeather, WEATHER_SUN_PRIMAL, BattleScript_ExtremelyHarshSunlightWasNotLessenedEnd3
	jumpifhalfword CMP_COMMON_BITS, gBattleWeather, WEATHER_RAIN_PRIMAL, BattleScript_NoReliefFromHeavyRainEnd3
	jumpifhalfword CMP_COMMON_BITS, gBattleWeather, WEATHER_STRONG_WINDS, BattleScript_MysteriousAirCurrentBlowsOnEnd3
	end3

BattleScript_BlockedByPrimalWeatherRet::
	call BattleScript_AbilityPopUp
	jumpifhalfword CMP_COMMON_BITS, gBattleWeather, WEATHER_SUN_PRIMAL, BattleScript_ExtremelyHarshSunlightWasNotLessenedRet
	jumpifhalfword CMP_COMMON_BITS, gBattleWeather, WEATHER_RAIN_PRIMAL, BattleScript_NoReliefFromHeavyRainRet
	jumpifhalfword CMP_COMMON_BITS, gBattleWeather, WEATHER_STRONG_WINDS, BattleScript_MysteriousAirCurrentBlowsOnRet
	return

BattleScript_EffectDefenseUpHit::
	setmoveeffect MOVE_EFFECT_DEF_PLUS_1 | MOVE_EFFECT_AFFECTS_ATTACKER
	goto BattleScript_EffectHit

BattleScript_EffectAttackUpHit::
	setmoveeffect MOVE_EFFECT_ATK_PLUS_1 | MOVE_EFFECT_AFFECTS_ATTACKER
	goto BattleScript_EffectHit

BattleScript_EffectAllStatsUpHit::
	setmoveeffect MOVE_EFFECT_ALL_STATS_UP | MOVE_EFFECT_AFFECTS_ATTACKER
	goto BattleScript_EffectHit

BattleScript_EffectBellyDrum::
	attackcanceler
	attackstring
	ppreduce
	maxattackhalvehp BattleScript_ButItFailed
	orword gHitMarker, HITMARKER_IGNORE_SUBSTITUTE
	attackanimation
	waitanimation
	healthbarupdate BS_ATTACKER
	datahpupdate BS_ATTACKER
	printstring STRINGID_PKMNCUTHPMAXEDATTACK
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_EffectPsychUp::
	attackcanceler
	attackstring
	ppreduce
	copyfoestats BattleScript_ButItFailed
	attackanimation
	waitanimation
	printstring STRINGID_PKMNCOPIEDSTATCHANGES
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_EffectMirrorCoat::
	attackcanceler
	mirrorcoatdamagecalculator BattleScript_FailedFromAtkString
	accuracycheck BattleScript_PrintMoveMissed, ACC_CURR_MOVE
	attackstring
	ppreduce
	typecalc
	bichalfword gMoveResultFlags, MOVE_RESULT_NOT_VERY_EFFECTIVE | MOVE_RESULT_SUPER_EFFECTIVE
	adjustdamage
	goto BattleScript_HitFromAtkAnimation

BattleScript_EffectTwister:
BattleScript_FlinchEffect:
BattleScript_EffectStomp:
	setmoveeffect MOVE_EFFECT_FLINCH
	goto BattleScript_EffectHit

BattleScript_EffectBulldoze:
	setmoveeffect MOVE_EFFECT_SPD_MINUS_1
BattleScript_EffectEarthquake:
	goto BattleScript_EffectHit

BattleScript_EffectFutureSight::
	attackcanceler
	attackstring
	ppreduce
	trysetfutureattack BattleScript_ButItFailed
	attackanimation
	waitanimation
	printfromtable gFutureMoveUsedStringIds
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_EffectGust::
	goto BattleScript_EffectHit

BattleScript_EffectThunder:
	setmoveeffect MOVE_EFFECT_PARALYSIS
	goto BattleScript_EffectHit

BattleScript_EffectHurricane:
	setmoveeffect MOVE_EFFECT_CONFUSE
	goto BattleScript_EffectHit

BattleScript_EffectTeleport:
	jumpifbattletype BATTLE_TYPE_TRAINER, BattleScript_EffectBatonPass
	jumpifside BS_ATTACKER, B_SIDE_PLAYER, BattleScript_EffectBatonPass
BattleScript_EffectTeleportTryToRunAway:
	attackcanceler
	attackstring
	ppreduce
	getifcantrunfrombattle BS_ATTACKER
	jumpifbyte CMP_EQUAL, gBattleCommunication, 1, BattleScript_ButItFailed
	jumpifbyte CMP_EQUAL, gBattleCommunication, 2, BattleScript_PrintAbilityMadeIneffective
	attackanimation
	waitanimation
	printstring STRINGID_PKMNFLEDFROMBATTLE
	waitmessage B_WAIT_TIME_LONG
	setoutcomeonteleport BS_ATTACKER
	goto BattleScript_MoveEnd

BattleScript_EffectBeatUp::
	attackcanceler
	accuracycheck BattleScript_PrintMoveMissed, ACC_CURR_MOVE
	attackstring
	pause B_WAIT_TIME_SHORT
	ppreduce
	setbyte gBattleCommunication, 0
BattleScript_BeatUpLoop::
	movevaluescleanup
	trydobeatup BattleScript_BeatUpEnd, BattleScript_ButItFailed
	printstring STRINGID_PKMNATTACK
	critcalc
	jumpifbyte CMP_NOT_EQUAL, gIsCriticalHit, TRUE, BattleScript_BeatUpAttack
	@manipulatedamage DMG_CRITICAL_FACTOR
BattleScript_BeatUpAttack::
	adjustdamage
	attackanimation
	waitanimation
	effectivenesssound
	hitanimation BS_TARGET
	waitstate
	healthbarupdate BS_TARGET
	datahpupdate BS_TARGET
	critmessage
	waitmessage B_WAIT_TIME_LONG
	resultmessage
	waitmessage B_WAIT_TIME_LONG
	tryfaintmon BS_TARGET, FALSE, NULL
	moveendto MOVEEND_NEXT_TARGET
	goto BattleScript_BeatUpLoop
BattleScript_BeatUpEnd::
	end

BattleScript_EffectSemiInvulnerable::
	jumpifready
	jumpifstatus2 BS_ATTACKER, STATUS2_MULTIPLETURNS, BattleScript_SecondTurnSemiInvulnerable
	jumpifword CMP_COMMON_BITS, gHitMarker, HITMARKER_NO_ATTACKSTRING, BattleScript_SecondTurnSemiInvulnerable
	jumpifmove MOVE_FLY, BattleScript_FirstTurnFly
	jumpifmove MOVE_DIVE, BattleScript_FirstTurnDive
	jumpifmove MOVE_DRAGON_CURRENT, BattleScript_FirstTurnDive
	jumpifmove MOVE_BOUNCE, BattleScript_FirstTurnBounce
	jumpifmove MOVE_PHANTOM_FORCE, BattleScript_FirstTurnPhantomForce
	jumpifmove MOVE_SHADOW_FORCE, BattleScript_FirstTurnPhantomForce
	jumpifmove MOVE_PHANTOM_AMBUSH, BattleScript_FirstTurnPhantomForce
	jumpifmove MOVE_COTTON_CLOUD_CRASH, BattleScript_FirstTurnCottonCloudCrash
	jumpifmove MOVE_EMERALD_TWO_STEP, BattleScript_FirstTurnEmeraldTwoStep
	setbyte sTWOTURN_STRINGID, B_MSG_TURN1_DIG
	goto BattleScript_FirstTurnSemiInvulnerable
BattleScript_FirstTurnBounce::
	setbyte sTWOTURN_STRINGID, B_MSG_TURN1_BOUNCE
	goto BattleScript_FirstTurnSemiInvulnerable
BattleScript_FirstTurnDive::
	setbyte sTWOTURN_STRINGID, B_MSG_TURN1_DIVE
	goto BattleScript_FirstTurnSemiInvulnerable
BattleScript_FirstTurnPhantomForce:
	setbyte sTWOTURN_STRINGID, B_MSG_TURN1_PHANTOM_FORCE
	goto BattleScript_FirstTurnSemiInvulnerable
BattleScript_FirstTurnCottonCloudCrash:
	setbyte sTWOTURN_STRINGID, B_MSG_TURN1_COTTON_CLOUD_CRASH
	goto BattleScript_FirstTurnSemiInvulnerable
BattleScript_FirstTurnEmeraldTwoStep:
	setbyte sTWOTURN_STRINGID, B_MSG_TURN1_EMERALD_TWO_STEP
	goto BattleScript_FirstTurnSemiInvulnerable
BattleScript_FirstTurnFly::
	setbyte sTWOTURN_STRINGID, B_MSG_TURN1_FLY
BattleScript_FirstTurnSemiInvulnerable::
	call BattleScriptFirstChargingTurn
	setsemiinvulnerablebit
	jumpifcanexecutemove BattleScript_SecondTurnSemiInvulnerable
	jumpifabilityorinnate BS_ATTACKER, ABILITY_SHALLOW_DIVER, BattleScript_ShallowDiver2
	jumpifnoholdeffect BS_ATTACKER, HOLD_EFFECT_POWER_HERB, BattleScript_MoveEnd
	call BattleScript_PowerHerbActivation
BattleScript_SecondTurnSemiInvulnerable::
	attackcanceler
	setbyte sB_ANIM_TURN, 1
	setmoveeffect MOVE_EFFECT_CHARGING
	clearstatusfromeffect BS_ATTACKER
	orword gHitMarker, HITMARKER_NO_PPDEDUCT
	accuracycheck BattleScript_SemiInvulnerableMiss, ACC_CURR_MOVE
	clearsemiinvulnerablebit
	call BattleScript_EffectAtkString_Ret
	seteffectwithchance
	argument2tomoveeffect
	seteffectwithchance
	tryfaintmon BS_TARGET, FALSE, NULL
	moveendall
	end

BattleScript_ShallowDiver2:
	sethword sABILITY_OVERWRITE, ABILITY_SHALLOW_DIVER	
	pause B_WAIT_TIME_SHORT
	call BattleScript_AbilityPopUp
	goto BattleScript_SecondTurnSemiInvulnerable

BattleScript_SemiInvulnerableMiss::
	clearsemiinvulnerablebit
	goto BattleScript_PrintMoveMissed

BattleScript_EffectDefenseCurl::
	attackcanceler
	attackstring
	ppreduce
	setdefensecurlbit
	setstatchanger STAT_DEF, 1, FALSE
	statbuffchange MOVE_EFFECT_AFFECTS_ATTACKER | STAT_CHANGE_ALLOW_PTR, BattleScript_DefenseCurlDoStatUpAnim
	jumpifbyte CMP_EQUAL, cMULTISTRING_CHOOSER, B_MSG_STAT_WONT_INCREASE, BattleScript_StatUpPrintString
	attackanimation
	waitanimation
BattleScript_DefenseCurlDoStatUpAnim::
	goto BattleScript_StatUpDoAnim

BattleScript_EffectSoftboiled::
	attackcanceler
	attackstring
	ppreduce
	tryhealhalfhealth BattleScript_AlreadyAtFullHp, BS_TARGET
BattleScript_PresentHealTarget::
	attackanimation
	waitanimation
	orword gHitMarker, HITMARKER_IGNORE_SUBSTITUTE
	healthbarupdate BS_TARGET
	datahpupdate BS_TARGET
	printstring STRINGID_PKMNREGAINEDHEALTH
	waitmessage B_WAIT_TIME_LONG	
	updatestatusicon BS_TARGET
	goto BattleScript_MoveEnd

BattleScript_PresentHPdamage::
	attackanimation
	waitanimation
	hitanimation BS_TARGET
	waitstate
	healthbarupdate BS_TARGET
	datahpupdate BS_TARGET
	resultmessage
	waitmessage B_WAIT_TIME_LONG
	tryfaintmon BS_TARGET, FALSE, NULL
	goto BattleScript_MoveEnd

BattleScript_AlreadyAtFullHp::
	pause B_WAIT_TIME_SHORT
	printstring STRINGID_PKMNHPFULL
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_NoHealTargetAfterHealBlock::
	pause B_WAIT_TIME_SHORT
	setbyte gBattleOutcome, 0
	printstring STRINGID_PKMNCOULDNOTREGAINEDHEALTH
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_EffectFakeOut::
	attackcanceler
	jumpifnotfirstturn BattleScript_FailedFromAtkString
	setmoveeffect MOVE_EFFECT_FLINCH
	goto BattleScript_HitFromAccCheck

BattleScript_FailedFromAtkCanceler::
	attackcanceler
BattleScript_FailedFromAtkString::
	attackstring
BattleScript_FailedFromPpReduce::
	ppreduce
BattleScript_ButItFailed::
	pause B_WAIT_TIME_SHORT
	orhalfword gMoveResultFlags, MOVE_RESULT_FAILED
	resultmessage
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_NotAffected::
	pause B_WAIT_TIME_SHORT
	orhalfword gMoveResultFlags, MOVE_RESULT_DOESNT_AFFECT_FOE
	resultmessage
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_NotAffectedAbilityPopUp::
	copybyte gBattlerAbility, gBattlerTarget
	pause B_WAIT_TIME_SHORT
	call BattleScript_AbilityPopUp
	orhalfword gMoveResultFlags, MOVE_RESULT_DOESNT_AFFECT_FOE
	resultmessage
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_EffectUproar::
	attackcanceler
	accuracycheck BattleScript_PrintMoveMissed, ACC_CURR_MOVE
	setmoveeffect MOVE_EFFECT_UPROAR | MOVE_EFFECT_AFFECTS_ATTACKER
	attackstring
	jumpifstatus2 BS_ATTACKER, STATUS2_MULTIPLETURNS, BattleScript_UproarHit
	ppreduce
BattleScript_UproarHit::
	goto BattleScript_HitFromCritCalc

BattleScript_EffectStockpile::
	attackcanceler
	attackstring
	ppreduce
	stockpile 0
	attackanimation
	waitanimation
	printfromtable gStockpileUsedStringIds
	waitmessage B_WAIT_TIME_LONG
	jumpifmovehadnoeffect BattleScript_EffectStockpileEnd
	jumpifstat BS_ATTACKER, CMP_LESS_THAN, STAT_DEF, MAX_STAT_STAGE, BattleScript_EffectStockpileDef
	jumpifstat BS_ATTACKER, CMP_EQUAL, STAT_SPDEF, MAX_STAT_STAGE, BattleScript_EffectStockpileEnd
BattleScript_EffectStockpileDef:
	setbyte sSTAT_ANIM_PLAYED, FALSE
	playstatchangeanimation BS_ATTACKER, BIT_DEF | BIT_SPDEF, 0
	setstatchanger STAT_DEF, 1, FALSE
	statbuffchange MOVE_EFFECT_AFFECTS_ATTACKER | STAT_CHANGE_ALLOW_PTR, BattleScript_EffectStockpileSpDef
	jumpifbyte CMP_EQUAL, cMULTISTRING_CHOOSER, B_MSG_STAT_WONT_INCREASE, BattleScript_EffectStockpileSpDef
	printfromtable gStatUpStringIds
	waitmessage B_WAIT_TIME_LONG
BattleScript_EffectStockpileSpDef::
	setstatchanger STAT_SPDEF, 1, FALSE
	statbuffchange MOVE_EFFECT_AFFECTS_ATTACKER | STAT_CHANGE_ALLOW_PTR, BattleScript_EffectStockpileEnd
	jumpifbyte CMP_EQUAL, cMULTISTRING_CHOOSER, B_MSG_STAT_WONT_INCREASE, BattleScript_EffectStockpileEnd
	printfromtable gStatUpStringIds
	waitmessage B_WAIT_TIME_LONG
BattleScript_EffectStockpileEnd:
	stockpile 1
	goto BattleScript_MoveEnd

BattleScript_EffectSpitUp::
	attackcanceler
	jumpifbyte CMP_EQUAL, cMISS_TYPE, B_MSG_PROTECTED, BattleScript_SpitUpFailProtect
	attackstring
	ppreduce
	accuracycheck BattleScript_PrintMoveMissed, ACC_CURR_MOVE
	setbyte gIsCriticalHit, FALSE
	damagecalc
	adjustdamage
	stockpiletobasedamage BattleScript_SpitUpFail
	goto BattleScript_HitFromAtkAnimation
BattleScript_SpitUpFail::
	pause B_WAIT_TIME_SHORT
	printstring STRINGID_FAILEDTOSPITUP
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_SpitUpFailProtect::
	attackstring
	ppreduce
	pause B_WAIT_TIME_LONG
	stockpiletobasedamage BattleScript_SpitUpFail
	resultmessage
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_EffectSwallow::
	attackcanceler
	attackstring
	ppreduce
	stockpiletohpheal BattleScript_SwallowFail
	goto BattleScript_PresentHealTarget

BattleScript_SwallowFail::
	pause B_WAIT_TIME_SHORT
	printfromtable gSwallowFailStringIds
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_EffectHail::
	attackcanceler
	attackstring
	ppreduce
	jumpifhalfword CMP_COMMON_BITS, gBattleWeather, WEATHER_SUN_PRIMAL, BattleScript_ExtremelyHarshSunlightWasNotLessened
	jumpifhalfword CMP_COMMON_BITS, gBattleWeather, WEATHER_RAIN_PRIMAL, BattleScript_NoReliefFromHeavyRain
	jumpifhalfword CMP_COMMON_BITS, gBattleWeather, WEATHER_STRONG_WINDS, BattleScript_MysteriousAirCurrentBlowsOn
	sethail
	goto BattleScript_MoveWeatherChange

BattleScript_EffectTorment::
	attackcanceler
	attackstring
	ppreduce
	accuracycheck BattleScript_ButItFailed, ACC_CURR_MOVE
	jumpifabilityorinnate BS_TARGET_SIDE, ABILITY_AROMA_VEIL, BattleScript_AromaVeilProtects
	settorment BattleScript_ButItFailed
	attackanimation
	waitanimation
	printstring STRINGID_PKMNSUBJECTEDTOTORMENT
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_EffectFlatter::
	attackcanceler
	jumpifsubstituteblocks BattleScript_MakeMoveMissed
	accuracycheck BattleScript_PrintMoveMissed, ACC_CURR_MOVE
	attackstring
	ppreduce
	jumpifconfusedandstatmaxed STAT_SPATK, BattleScript_ButItFailed
	attackanimation
	waitanimation
	setstatchanger STAT_SPATK, 1, FALSE
	statbuffchange STAT_CHANGE_ALLOW_PTR, BattleScript_FlatterTryConfuse
	jumpifbyte CMP_EQUAL, cMULTISTRING_CHOOSER, B_MSG_STAT_WONT_INCREASE, BattleScript_FlatterTryConfuse
	setgraphicalstatchangevalues
	playanimation BS_TARGET, B_ANIM_STATS_CHANGE, sB_ANIM_ARG1
	printfromtable gStatUpStringIds
	waitmessage B_WAIT_TIME_LONG
BattleScript_FlatterTryConfuse::
	jumpifabilityorinnate BS_TARGET, ABILITY_OWN_TEMPO, BattleScript_InnateOwnTempoPrevents
	jumpifsafeguard BattleScript_SafeguardProtected
	jumpifkingsgrace BattleScript_KingsGraceProtected
	setmoveeffect MOVE_EFFECT_CONFUSE
	seteffectprimary
	goto BattleScript_MoveEnd

BattleScript_EffectWillOWisp::
	attackcanceler
	attackstring
	ppreduce
	jumpifsubstituteblocks BattleScript_ButItFailed
	jumpifstatus BS_TARGET, STATUS1_BURN, BattleScript_AlreadyBurned
	@jumpiftype BS_TARGET, TYPE_FIRE, BattleScript_NotAffected
	jumpifabilityorinnate BS_TARGET, ABILITY_WATER_VEIL, BattleScript_WaterVeilPrevents
	jumpifabilityorinnate BS_TARGET, ABILITY_WATER_BUBBLE, BattleScript_WaterBubblePrevents
	jumpifabilityorinnate BS_TARGET, ABILITY_PYROCLASTIC, BattleScript_PyroclasticPrevents
	jumpifabilityorinnate BS_TARGET, ABILITY_COMATOSE, BattleScript_LeafGuardProtects
	jumpifabilityorinnate BS_TARGET, ABILITY_PURIFYING_SALT, BattleScript_LeafGuardProtects
	jumpifflowerveil BattleScript_FlowerVeilProtects
	jumpifleafguardprotected BS_TARGET, BattleScript_LeafGuardProtects
	jumpifshieldsdown BS_TARGET, BattleScript_LeafGuardProtects
	jumpifstatus BS_TARGET, STATUS1_ANY, BattleScript_ButItFailed
	jumpifterrainaffected BS_TARGET, STATUS_FIELD_MISTY_TERRAIN, BattleScript_MistyTerrainPrevents
	accuracycheck BattleScript_ButItFailed, ACC_CURR_MOVE
	jumpifsafeguard BattleScript_SafeguardProtected
	jumpifkingsgrace BattleScript_KingsGraceProtected
	attackanimation
	waitanimation
	setmoveeffect MOVE_EFFECT_BURN
	seteffectprimary
	goto BattleScript_MoveEnd

BattleScript_WaterVeilPrevents::
	copybyte gEffectBattler, gBattlerTarget
	sethword sABILITY_OVERWRITE, ABILITY_WATER_VEIL
	changelastusedability ABILITY_WATER_VEIL
	setbyte cMULTISTRING_CHOOSER, B_MSG_ABILITY_PREVENTS_MOVE_STATUS
	call BattleScript_AbilityBRNPrevention
	goto BattleScript_MoveEnd

BattleScript_WaterBubblePrevents::
	copybyte gEffectBattler, gBattlerTarget
	sethword sABILITY_OVERWRITE, ABILITY_WATER_BUBBLE
	changelastusedability ABILITY_WATER_BUBBLE
	setbyte cMULTISTRING_CHOOSER, B_MSG_ABILITY_PREVENTS_MOVE_STATUS
	call BattleScript_AbilityBRNPrevention
	goto BattleScript_MoveEnd

BattleScript_PyroclasticPrevents::
	copybyte gEffectBattler, gBattlerTarget
	sethword sABILITY_OVERWRITE, ABILITY_PYROCLASTIC
	changelastusedability ABILITY_PYROCLASTIC
	setbyte cMULTISTRING_CHOOSER, B_MSG_ABILITY_PREVENTS_MOVE_STATUS
	call BattleScript_AbilityBRNPrevention
	goto BattleScript_MoveEnd

BattleScript_AlreadyBurned::
	setalreadystatusedmoveattempt BS_ATTACKER
	pause B_WAIT_TIME_SHORT
	printstring STRINGID_PKMNALREADYHASBURN
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_EffectMemento::
	attackcanceler
	jumpifbyte CMP_EQUAL, cMISS_TYPE, B_MSG_PROTECTED, BattleScript_MementoFailProtect
	attackstring
	ppreduce
	jumpifattackandspecialattackcannotfall BattleScript_ButItFailed
	setatkhptozero
	attackanimation
	waitanimation
	jumpifsubstituteblocks BattleScript_EffectMementoPrintNoEffect
	setbyte sSTAT_ANIM_PLAYED, FALSE
	playstatchangeanimation BS_TARGET, BIT_ATK | BIT_SPATK, STAT_CHANGE_NEGATIVE | STAT_CHANGE_BY_TWO | STAT_CHANGE_MULTIPLE_STATS
	playstatchangeanimation BS_TARGET, BIT_ATK, STAT_CHANGE_NEGATIVE | STAT_CHANGE_BY_TWO
	setstatchanger STAT_ATK, 2, TRUE
	statbuffchange STAT_CHANGE_ALLOW_PTR, BattleScript_EffectMementoTrySpAtk
	@ Greater than STAT_FELL is checking if the stat cannot decrease
	jumpifbyte CMP_GREATER_THAN, cMULTISTRING_CHOOSER, B_MSG_DEFENDER_STAT_FELL, BattleScript_EffectMementoTrySpAtk
	printfromtable gStatDownStringIds
	waitmessage B_WAIT_TIME_LONG
BattleScript_EffectMementoTrySpAtk:
	playstatchangeanimation BS_TARGET, BIT_SPATK, STAT_CHANGE_NEGATIVE | STAT_CHANGE_BY_TWO
	setstatchanger STAT_SPATK, 2, TRUE
	statbuffchange STAT_CHANGE_ALLOW_PTR, BattleScript_EffectMementoTryFaint
	@ Greater than STAT_FELL is checking if the stat cannot decrease
	jumpifbyte CMP_GREATER_THAN, cMULTISTRING_CHOOSER, B_MSG_DEFENDER_STAT_FELL, BattleScript_EffectMementoTryFaint
	printfromtable gStatDownStringIds
	waitmessage B_WAIT_TIME_LONG
BattleScript_EffectMementoTryFaint:
	tryfaintmon BS_ATTACKER, FALSE, NULL
	goto BattleScript_MoveEnd
BattleScript_EffectMementoPrintNoEffect:
	printstring STRINGID_BUTNOEFFECT
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_EffectMementoTryFaint
BattleScript_MementoFailProtect:
	attackstring
	ppreduce
	jumpifattackandspecialattackcannotfall BattleScript_MementoFailEnd
BattleScript_MementoFailEnd:
	setatkhptozero
	pause B_WAIT_TIME_LONG
	effectivenesssound
	resultmessage
	waitmessage B_WAIT_TIME_LONG
	tryfaintmon BS_ATTACKER, FALSE, NULL
	goto BattleScript_MoveEnd

BattleScript_EffectSmellingsalt:
BattleScript_EffectWakeUpSlap:
BattleScript_EffectSparklingAria:
	jumpifsubstituteblocks BattleScript_EffectHit
	setmoveeffect MOVE_EFFECT_REMOVE_STATUS | MOVE_EFFECT_CERTAIN
	goto BattleScript_EffectHit

BattleScript_EffectFollowMe::
	attackcanceler
	attackstring
	ppreduce
	setforcedtarget
	attackanimation
	waitanimation
	printstring STRINGID_PKMNCENTERATTENTION
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_EffectNaturePower::
	attackcanceler
	attackstring
	pause B_WAIT_TIME_SHORT
	callterrainattack
	printstring STRINGID_NATUREPOWERTURNEDINTO
	waitmessage B_WAIT_TIME_LONG
	return

BattleScript_EffectCharge::
	attackcanceler
	attackstring
	ppreduce
	setcharge BS_ATTACKER
	attackanimation
	waitanimation
	setbyte sSTAT_ANIM_PLAYED, FALSE
	playstatchangeanimation BS_ATTACKER, BIT_SPDEF | BIT_SPEED, 0
	setstatchanger STAT_SPDEF, 1, FALSE
	statbuffchange MOVE_EFFECT_AFFECTS_ATTACKER | STAT_CHANGE_ALLOW_PTR, BattleScript_EffectChargeString
	jumpifbyte CMP_EQUAL, cMULTISTRING_CHOOSER, B_MSG_STAT_WONT_INCREASE, BattleScript_EffectChargeString
	printfromtable gStatUpStringIds
	waitmessage B_WAIT_TIME_LONG
@BattleScript_ChargeTrySpeed::
@	setstatchanger STAT_SPEED, 1, FALSE
@	statbuffchange MOVE_EFFECT_AFFECTS_ATTACKER | STAT_CHANGE_ALLOW_PTR, BattleScript_EffectChargeString
@	jumpifbyte CMP_EQUAL, cMULTISTRING_CHOOSER, B_MSG_STAT_WONT_INCREASE, BattleScript_EffectChargeString
@	printfromtable gStatUpStringIds
@	waitmessage B_WAIT_TIME_LONG
BattleScript_EffectChargeString:
	printstring STRINGID_PKMNCHARGINGPOWER
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_EffectTaunt::
	attackcanceler
	attackstring
	ppreduce
	jumpifabilityorinnate BS_TARGET_SIDE, ABILITY_AROMA_VEIL, BattleScript_AromaVeilProtects
	accuracycheck BattleScript_ButItFailed, ACC_CURR_MOVE
	settaunt BattleScript_ButItFailed
	attackanimation
	waitanimation
	printstring STRINGID_PKMNFELLFORTAUNT
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_EffectHelpingHand::
	attackcanceler
	attackstring
	ppreduce
	trysethelpinghand BattleScript_ButItFailed
	attackanimation
	waitanimation
	printstring STRINGID_PKMNREADYTOHELP
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_EffectTrick::
	attackcanceler
	attackstring
	ppreduce
	jumpifsubstituteblocks BattleScript_ButItFailed
	accuracycheck BattleScript_ButItFailed, ACC_CURR_MOVE
	tryswapitems 0, BattleScript_EffectTrickFirstFail
	attackanimation
	waitanimation
	printstring STRINGID_PKMNSWITCHEDITEMS
	waitmessage B_WAIT_TIME_LONG
	printfromtable gItemSwapStringIds
	waitmessage B_WAIT_TIME_LONG
	tryswapitems 1, BattleScript_EffectTrickEquip2
	printfromtable gItemSwapStringIds
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_EffectTrickEquip2

BattleScript_EffectTrickFirstFail:
	tryswapitems 1, BattleScript_EffectTrickSecondFail
	attackanimation
	waitanimation
	printstring STRINGID_PKMNSWITCHEDITEMS
	waitmessage B_WAIT_TIME_LONG
	printfromtable gItemSwapStringIds
	waitmessage B_WAIT_TIME_LONG
BattleScript_EffectTrickEquip2:
	tryswapitems 2, BattleScript_MoveEnd
	printfromtable gItemSwapStringIds
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_EffectTrickSecondFail:
	tryswapitems 2, BattleScript_ButItFailed
	attackanimation
	waitanimation
	printstring STRINGID_PKMNSWITCHEDITEMS
	waitmessage B_WAIT_TIME_LONG
	printfromtable gItemSwapStringIds
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_EffectRolePlay::
	attackcanceler
	attackstring
	ppreduce
	accuracycheck BattleScript_ButItFailed, NO_ACC_CALC_CHECK_LOCK_ON
	trycopyability BattleScript_ButItFailed
	attackanimation
	waitanimation
	printstring STRINGID_PKMNCOPIEDFOE
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_EffectWish::
	attackcanceler
	attackstring
	ppreduce
	trywish 0, BattleScript_ButItFailed
	attackanimation
	waitanimation
	goto BattleScript_MoveEnd

BattleScript_EffectAssist:
	attackcanceler
	attackstring
	assistattackselect BattleScript_FailedFromPpReduce
	attackanimation
	waitanimation
	setbyte sB_ANIM_TURN, 0
	setbyte sB_ANIM_TARGETS_HIT, 0
	jumptocalledmove TRUE

BattleScript_EffectIngrain:
	attackcanceler
	attackstring
	ppreduce
	setbattlerstatus BS_ATTACKER, 3, STATUS3_ROOTED, BattleScript_ButItFailed
	attackanimation
	waitanimation
	printstring STRINGID_PKMNPLANTEDROOTS
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_EffectSuperpower:
	setmoveeffect MOVE_EFFECT_ATK_DEF_DOWN | MOVE_EFFECT_AFFECTS_ATTACKER | MOVE_EFFECT_CERTAIN
	goto BattleScript_EffectHit

BattleScript_EffectCloseCombat:
	setmoveeffect MOVE_EFFECT_DEF_SPDEF_DOWN | MOVE_EFFECT_AFFECTS_ATTACKER | MOVE_EFFECT_CERTAIN
	goto BattleScript_EffectHit

BattleScript_EffectMagicCoat:
	attackcanceler
	trysetmagiccoat BattleScript_FailedFromAtkString
	attackstring
	ppreduce
	attackanimation
	waitanimation
	printstring STRINGID_PKMNSHROUDEDITSELF
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_EffectRecycle::
	attackcanceler
	attackstring
	ppreduce
	tryrecycleitem BattleScript_ButItFailed
	attackanimation
	waitanimation
	printstring STRINGID_XFOUNDONEY
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_EffectBrickBreak::
	attackcanceler
	accuracycheck BattleScript_PrintMoveMissed, ACC_CURR_MOVE
	attackstring
	ppreduce
	removelightscreenreflect
	critcalc
	damagecalc
	adjustdamage
	jumpifbyte CMP_EQUAL, sB_ANIM_TURN, 0, BattleScript_BrickBreakAnim
	bichalfword gMoveResultFlags, MOVE_RESULT_MISSED | MOVE_RESULT_DOESNT_AFFECT_FOE
BattleScript_BrickBreakAnim::
	attackanimation
	waitanimation
	jumpifbyte CMP_LESS_THAN, sB_ANIM_TURN, 2, BattleScript_BrickBreakDoHit
	printstring STRINGID_THEWALLSHATTERED
	waitmessage B_WAIT_TIME_LONG
BattleScript_BrickBreakDoHit::
	typecalc
	effectivenesssound
	hitanimation BS_TARGET
	waitstate
	healthbarupdate BS_TARGET
	datahpupdate BS_TARGET
	critmessage
	waitmessage B_WAIT_TIME_LONG
	resultmessage
	waitmessage B_WAIT_TIME_LONG
	seteffectwithchance
	tryfaintmon BS_TARGET, FALSE, NULL
	goto BattleScript_MoveEnd

BattleScript_EffectYawn::
	attackcanceler
	attackstring
	ppreduce
	jumpifabilityorinnate BS_TARGET, ABILITY_VITAL_SPIRIT, BattleScript_PrintBankVitalSpiritMadeIneffective
	jumpifabilityorinnate BS_TARGET, ABILITY_INSOMNIA, BattleScript_PrintBankInsomniaMadeIneffective
	jumpifabilityorinnate BS_TARGET, ABILITY_COMATOSE, BattleScript_PrintBankAbilityMadeIneffective
	jumpifabilityorinnate BS_TARGET, ABILITY_PURIFYING_SALT, BattleScript_PrintBankAbilityMadeIneffective
	jumpifflowerveil BattleScript_FlowerVeilProtects
	jumpifleafguardprotected BS_TARGET, BattleScript_LeafGuardProtects
	jumpifshieldsdown BS_TARGET, BattleScript_LeafGuardProtects
	jumpifsubstituteblocks BattleScript_ButItFailed
	jumpifsafeguard BattleScript_SafeguardProtected
	jumpifkingsgrace BattleScript_KingsGraceProtected
	accuracycheck BattleScript_ButItFailed, NO_ACC_CALC_CHECK_LOCK_ON
	jumpifcantmakeasleep BattleScript_ButItFailed
	setyawn BattleScript_ButItFailed
	attackanimation
	waitanimation
	printstring STRINGID_PKMNWASMADEDROWSY
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd
BattleScript_PrintBankAbilityMadeIneffective::
	copybyte sBATTLER, gBattlerAbility
BattleScript_PrintAbilityMadeIneffective::
	pause B_WAIT_TIME_SHORT
	call BattleScript_AbilityPopUp
	printstring STRINGID_PKMNSXMADEITINEFFECTIVE
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_PrintBankInnateMadeIneffective:
	call BattleScript_AbilityPopUp
	pause B_WAIT_TIME_SHORT
	printstring STRINGID_PKMNSXMADEITINEFFECTIVE
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_PrintBankInsomniaMadeIneffective:
	changelastusedability ABILITY_INSOMNIA
	sethword sABILITY_OVERWRITE, ABILITY_INSOMNIA
	goto BattleScript_PrintBankInnateMadeIneffective
	
BattleScript_PrintBankVitalSpiritMadeIneffective:
	changelastusedability ABILITY_VITAL_SPIRIT
	sethword sABILITY_OVERWRITE, ABILITY_VITAL_SPIRIT
	goto BattleScript_PrintBankInnateMadeIneffective

BattleScript_EffectKnockOff::
	setmoveeffect MOVE_EFFECT_KNOCK_OFF
	goto BattleScript_EffectHit

BattleScript_EffectEndeavor::
	attackcanceler
	attackstring
	ppreduce
	setdamagetohealthdifference BattleScript_ButItFailed
	copyword gHpDealt, gBattleMoveDamage
	accuracycheck BattleScript_MoveMissedPause, ACC_CURR_MOVE
	typecalc
	jumpifmovehadnoeffect BattleScript_HitFromAtkAnimation
	bichalfword gMoveResultFlags, MOVE_RESULT_SUPER_EFFECTIVE | MOVE_RESULT_NOT_VERY_EFFECTIVE
	copyword gBattleMoveDamage, gHpDealt
	adjustdamage
	goto BattleScript_HitFromAtkAnimation

BattleScript_EffectSkillSwap:
	attackcanceler
	attackstring
	ppreduce
	accuracycheck BattleScript_ButItFailed, NO_ACC_CALC_CHECK_LOCK_ON
	tryswapabilities BattleScript_ButItFailed
	attackanimation
	waitanimation
.if B_ABILITY_POP_UP == TRUE
	copybyte gBattlerAbility, gBattlerTarget
	call BattleScript_AbilityPopUp
	pause 20
	copybyte gBattlerAbility, gBattlerAttacker
	call BattleScript_AbilityPopUp
.endif
	printstring STRINGID_PKMNSWAPPEDABILITIES
	waitmessage B_WAIT_TIME_LONG
.if B_SKILL_SWAP >= GEN_4
	switchinabilities BS_ATTACKER
	switchinabilities BS_TARGET
.endif
	goto BattleScript_MoveEnd

BattleScript_EffectImprison::
	attackcanceler
	attackstring
	ppreduce
	tryimprison BattleScript_ButItFailed
	attackanimation
	waitanimation
	printstring STRINGID_PKMNSEALEDOPPONENTMOVE
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_EffectRefresh:
	attackcanceler
	attackstring
	ppreduce
	cureifburnedparalysedorpoisoned BattleScript_ButItFailed
	attackanimation
	waitanimation
	printstring STRINGID_PKMNSTATUSNORMAL
	waitmessage B_WAIT_TIME_LONG
	updatestatusicon BS_ATTACKER
	goto BattleScript_MoveEnd

BattleScript_EffectGrudge:
	attackcanceler
	attackstring
	ppreduce
	setbattlerstatus BS_ATTACKER, 3, STATUS3_GRUDGE, BattleScript_ButItFailed
	attackanimation
	waitanimation
	printstring STRINGID_PKMNWANTSGRUDGE
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_EffectSnatch:
	attackcanceler
	trysetsnatch BattleScript_FailedFromAtkString
	attackstring
	ppreduce
	attackanimation
	waitanimation
	pause B_WAIT_TIME_SHORT
	printstring STRINGID_PKMNWAITSFORTARGET
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_EffectSecretPower::
	getsecretpowereffect
	goto BattleScript_EffectHit

BattleScript_EffectRecoil25:
	setmoveeffect MOVE_EFFECT_RECOIL_25 | MOVE_EFFECT_AFFECTS_ATTACKER | MOVE_EFFECT_CERTAIN
	goto BattleScript_EffectHit

BattleScript_EffectRecoil33::
	setmoveeffect MOVE_EFFECT_RECOIL_33 | MOVE_EFFECT_AFFECTS_ATTACKER | MOVE_EFFECT_CERTAIN
	goto BattleScript_EffectHit

BattleScript_EffectRecoil33WithStatus:
	setmoveeffect MOVE_EFFECT_RECOIL_33_STATUS | MOVE_EFFECT_AFFECTS_ATTACKER | MOVE_EFFECT_CERTAIN
	goto BattleScript_EffectHit

BattleScript_EffectRecoil50:
	setmoveeffect MOVE_EFFECT_RECOIL_50 | MOVE_EFFECT_AFFECTS_ATTACKER | MOVE_EFFECT_CERTAIN
	goto BattleScript_EffectHit

BattleScript_EffectRecoilHP25:
	setmoveeffect MOVE_EFFECT_RECOIL_HP_25 | MOVE_EFFECT_AFFECTS_ATTACKER | MOVE_EFFECT_CERTAIN
	jumpifnotmove MOVE_STRUGGLE, BattleScript_EffectHit
	incrementgamestat GAME_STAT_USED_STRUGGLE
	goto BattleScript_EffectHit

BattleScript_EffectTeeterDance::
	attackcanceler
	attackstring
	ppreduce
	setbyte gBattlerTarget, 0
BattleScript_TeeterDanceLoop::
	movevaluescleanup
	setmoveeffect MOVE_EFFECT_CONFUSE
	jumpifbyteequal gBattlerAttacker, gBattlerTarget, BattleScript_TeeterDanceLoopIncrement
	jumpifabilityorinnate BS_TARGET, ABILITY_OWN_TEMPO, BattleScript_TeeterDanceInnateOwnTempoPrevents
	jumpifsubstituteblocks BattleScript_TeeterDanceSubstitutePrevents
	jumpifstatus2 BS_TARGET, STATUS2_CONFUSION, BattleScript_TeeterDanceAlreadyConfused
	jumpifhasnohp BS_TARGET, BattleScript_TeeterDanceLoopIncrement
	accuracycheck BattleScript_TeeterDanceMissed, ACC_CURR_MOVE
	jumpifsafeguard BattleScript_TeeterDanceSafeguardProtected
	jumpifkingsgrace BattleScript_TeeterDanceKingsGraceProtected
	attackanimation
	waitanimation
	seteffectprimary
	resultmessage
	waitmessage B_WAIT_TIME_LONG
BattleScript_TeeterDanceDoMoveEndIncrement::
	moveendto MOVEEND_NEXT_TARGET
BattleScript_TeeterDanceLoopIncrement::
	addbyte gBattlerTarget, 1
	jumpifbytenotequal gBattlerTarget, gBattlersCount, BattleScript_TeeterDanceLoop
	end

BattleScript_TeeterDanceInnateOwnTempoPrevents:
	copybyte gBattlerAbility, gBattlerTarget
	sethword sABILITY_OVERWRITE, ABILITY_OWN_TEMPO
	goto BattleScript_TeeterDanceOwnTempoPrevents

BattleScript_TeeterDanceOwnTempoPrevents::
	pause B_WAIT_TIME_SHORT
	printstring STRINGID_PKMNPREVENTSCONFUSIONWITH
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_TeeterDanceDoMoveEndIncrement

BattleScript_TeeterDanceSafeguardProtected::
	pause B_WAIT_TIME_SHORT
	printstring STRINGID_PKMNUSEDSAFEGUARD
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_TeeterDanceDoMoveEndIncrement

BattleScript_TeeterDanceKingsGraceProtected::
	pause B_WAIT_TIME_SHORT
	printstring STRINGID_PKMNUSEDKINGSGRACE
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_TeeterDanceDoMoveEndIncrement

BattleScript_TeeterDanceSubstitutePrevents::
	pause B_WAIT_TIME_SHORT
	printstring STRINGID_BUTITFAILED
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_TeeterDanceDoMoveEndIncrement

BattleScript_TeeterDanceAlreadyConfused::
	setalreadystatusedmoveattempt BS_ATTACKER
	pause B_WAIT_TIME_SHORT
	printstring STRINGID_PKMNALREADYCONFUSED
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_TeeterDanceDoMoveEndIncrement

BattleScript_TeeterDanceMissed::
	resultmessage
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_TeeterDanceDoMoveEndIncrement

BattleScript_EffectMudSport::
BattleScript_EffectWaterSport::
	attackcanceler
	attackstring
	ppreduce
	settypebasedhalvers BattleScript_ButItFailed
	attackanimation
	waitanimation
	printfromtable gSportsUsedStringIds
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_EffectPoisonFang::
	setmoveeffect MOVE_EFFECT_TOXIC
	goto BattleScript_EffectHit

BattleScript_EffectOverheat::
	setmoveeffect MOVE_EFFECT_SP_ATK_TWO_DOWN | MOVE_EFFECT_AFFECTS_ATTACKER | MOVE_EFFECT_CERTAIN
	goto BattleScript_EffectHit

BattleScript_EffectHammerArm::
	setmoveeffect MOVE_EFFECT_SPD_MINUS_1 | MOVE_EFFECT_AFFECTS_ATTACKER | MOVE_EFFECT_CERTAIN
	goto BattleScript_EffectHit

BattleScript_EffectTickle::
	attackcanceler
	attackstring
	ppreduce
	jumpifstat BS_TARGET, CMP_GREATER_THAN, STAT_ATK, MIN_STAT_STAGE, BattleScript_TickleDoMoveAnim
	jumpifstat BS_TARGET, CMP_EQUAL, STAT_DEF, MIN_STAT_STAGE, BattleScript_CantLowerMultipleStats
BattleScript_TickleDoMoveAnim::
	accuracycheck BattleScript_ButItFailed, ACC_CURR_MOVE
	attackanimation
	waitanimation
	setbyte sSTAT_ANIM_PLAYED, FALSE
	playstatchangeanimation BS_TARGET, BIT_ATK | BIT_DEF, STAT_CHANGE_NEGATIVE | STAT_CHANGE_MULTIPLE_STATS
	playstatchangeanimation BS_TARGET, BIT_ATK, STAT_CHANGE_NEGATIVE
	setstatchanger STAT_ATK, 1, TRUE
	statbuffchange STAT_CHANGE_ALLOW_PTR, BattleScript_TickleTryLowerDef
	jumpifbyte CMP_EQUAL, cMULTISTRING_CHOOSER, B_MSG_STAT_WONT_DECREASE, BattleScript_TickleTryLowerDef
	printfromtable gStatDownStringIds
	waitmessage B_WAIT_TIME_LONG
BattleScript_TickleTryLowerDef::
	playstatchangeanimation BS_TARGET, BIT_DEF, STAT_CHANGE_NEGATIVE
	setstatchanger STAT_DEF, 1, TRUE
	statbuffchange STAT_CHANGE_ALLOW_PTR, BattleScript_TickleEnd
	jumpifbyte CMP_EQUAL, cMULTISTRING_CHOOSER, B_MSG_STAT_WONT_DECREASE, BattleScript_TickleEnd
	printfromtable gStatDownStringIds
	waitmessage B_WAIT_TIME_LONG
BattleScript_TickleEnd::
	goto BattleScript_MoveEnd

BattleScript_CantLowerMultipleStats::
	pause B_WAIT_TIME_SHORT
	orhalfword gMoveResultFlags, MOVE_RESULT_FAILED
	printstring STRINGID_STATSWONTDECREASE2
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_EffectCosmicPower::
	attackcanceler
	attackstring
	ppreduce
	jumpifstat BS_ATTACKER, CMP_LESS_THAN, STAT_DEF, MAX_STAT_STAGE, BattleScript_CosmicPowerDoMoveAnim
	jumpifstat BS_ATTACKER, CMP_EQUAL, STAT_SPDEF, MAX_STAT_STAGE, BattleScript_CantRaiseMultipleStats
BattleScript_CosmicPowerDoMoveAnim::
	attackanimation
	waitanimation
	setbyte sSTAT_ANIM_PLAYED, FALSE
	playstatchangeanimation BS_ATTACKER, BIT_DEF | BIT_SPDEF, 0
	setstatchanger STAT_DEF, 1, FALSE
	statbuffchange MOVE_EFFECT_AFFECTS_ATTACKER | STAT_CHANGE_ALLOW_PTR, BattleScript_CosmicPowerTrySpDef
	jumpifbyte CMP_EQUAL, cMULTISTRING_CHOOSER, B_MSG_STAT_WONT_INCREASE, BattleScript_CosmicPowerTrySpDef
	printfromtable gStatUpStringIds
	waitmessage B_WAIT_TIME_LONG
BattleScript_CosmicPowerTrySpDef::
	setstatchanger STAT_SPDEF, 1, FALSE
	statbuffchange MOVE_EFFECT_AFFECTS_ATTACKER | STAT_CHANGE_ALLOW_PTR, BattleScript_CosmicPowerEnd
	jumpifbyte CMP_EQUAL, cMULTISTRING_CHOOSER, B_MSG_STAT_WONT_INCREASE, BattleScript_CosmicPowerEnd
	printfromtable gStatUpStringIds
	waitmessage B_WAIT_TIME_LONG
BattleScript_CosmicPowerEnd::
	goto BattleScript_MoveEnd

BattleScript_EffectSkyUppercut::
	goto BattleScript_EffectHit

BattleScript_EffectBulkUp::
	attackcanceler
	attackstring
	ppreduce
	jumpifstat BS_ATTACKER, CMP_LESS_THAN, STAT_ATK, MAX_STAT_STAGE, BattleScript_BulkUpDoMoveAnim
	jumpifstat BS_ATTACKER, CMP_EQUAL, STAT_DEF, MAX_STAT_STAGE, BattleScript_CantRaiseMultipleStats
BattleScript_BulkUpDoMoveAnim::
	attackanimation
	waitanimation
	setbyte sSTAT_ANIM_PLAYED, FALSE
	playstatchangeanimation BS_ATTACKER, BIT_ATK | BIT_DEF, 0
	setstatchanger STAT_ATK, 1, FALSE
	statbuffchange MOVE_EFFECT_AFFECTS_ATTACKER | STAT_CHANGE_ALLOW_PTR, BattleScript_BulkUpTryDef
	jumpifbyte CMP_EQUAL, cMULTISTRING_CHOOSER, B_MSG_STAT_WONT_INCREASE, BattleScript_BulkUpTryDef
	printfromtable gStatUpStringIds
	waitmessage B_WAIT_TIME_LONG
BattleScript_BulkUpTryDef::
	setstatchanger STAT_DEF, 1, FALSE
	statbuffchange MOVE_EFFECT_AFFECTS_ATTACKER | STAT_CHANGE_ALLOW_PTR, BattleScript_BulkUpEnd
	jumpifbyte CMP_EQUAL, cMULTISTRING_CHOOSER, B_MSG_STAT_WONT_INCREASE, BattleScript_BulkUpEnd
	printfromtable gStatUpStringIds
	waitmessage B_WAIT_TIME_LONG
BattleScript_BulkUpEnd::
	goto BattleScript_MoveEnd

BattleScript_EffectCalmMind::
	attackcanceler
	attackstring
	ppreduce
	jumpifstat BS_ATTACKER, CMP_LESS_THAN, STAT_SPATK, MAX_STAT_STAGE, BattleScript_CalmMindDoMoveAnim
	jumpifstat BS_ATTACKER, CMP_EQUAL, STAT_SPDEF, MAX_STAT_STAGE, BattleScript_CantRaiseMultipleStats
BattleScript_CalmMindDoMoveAnim::
	attackanimation
	waitanimation
	setbyte sSTAT_ANIM_PLAYED, FALSE
	playstatchangeanimation BS_ATTACKER, BIT_SPATK | BIT_SPDEF, 0
	setstatchanger STAT_SPATK, 1, FALSE
	statbuffchange MOVE_EFFECT_AFFECTS_ATTACKER | STAT_CHANGE_ALLOW_PTR, BattleScript_CalmMindTrySpDef
	jumpifbyte CMP_EQUAL, cMULTISTRING_CHOOSER, B_MSG_STAT_WONT_INCREASE, BattleScript_CalmMindTrySpDef
	printfromtable gStatUpStringIds
	waitmessage B_WAIT_TIME_LONG
BattleScript_CalmMindTrySpDef::
	setstatchanger STAT_SPDEF, 1, FALSE
	statbuffchange MOVE_EFFECT_AFFECTS_ATTACKER | STAT_CHANGE_ALLOW_PTR, BattleScript_CalmMindEnd
	jumpifbyte CMP_EQUAL, cMULTISTRING_CHOOSER, B_MSG_STAT_WONT_INCREASE, BattleScript_CalmMindEnd
	printfromtable gStatUpStringIds
	waitmessage B_WAIT_TIME_LONG
BattleScript_CalmMindEnd::
	goto BattleScript_MoveEnd

BattleScript_CantRaiseMultipleStats::
	pause B_WAIT_TIME_SHORT
	orhalfword gMoveResultFlags, MOVE_RESULT_FAILED
	printstring STRINGID_STATSWONTINCREASE2
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_EffectDragonDance::
	attackcanceler
	attackstring
	ppreduce
	jumpifsatkishigher BattleScript_EffectDragonDanceTrySatk
	jumpifstat BS_ATTACKER, CMP_LESS_THAN, STAT_ATK, MAX_STAT_STAGE, BattleScript_DragonDanceDoMoveAnim
	jumpifstat BS_ATTACKER, CMP_EQUAL, STAT_SPEED, MAX_STAT_STAGE, BattleScript_CantRaiseMultipleStats
BattleScript_DragonDanceDoMoveAnim::
	attackanimation
	waitanimation
	setbyte sSTAT_ANIM_PLAYED, FALSE
	playstatchangeanimation BS_ATTACKER, BIT_ATK | BIT_SPEED, 0
	setstatchanger STAT_ATK, 1, FALSE
	statbuffchange MOVE_EFFECT_AFFECTS_ATTACKER | STAT_CHANGE_ALLOW_PTR, BattleScript_DragonDanceTrySpeed
	jumpifbyte CMP_EQUAL, cMULTISTRING_CHOOSER, B_MSG_STAT_WONT_INCREASE, BattleScript_DragonDanceTrySpeed
	printfromtable gStatUpStringIds
	waitmessage B_WAIT_TIME_LONG
BattleScript_DragonDanceTrySpeed::
	setstatchanger STAT_SPEED, 1, FALSE
	statbuffchange MOVE_EFFECT_AFFECTS_ATTACKER | STAT_CHANGE_ALLOW_PTR, BattleScript_DragonDanceEnd
	jumpifbyte CMP_EQUAL, cMULTISTRING_CHOOSER, B_MSG_STAT_WONT_INCREASE, BattleScript_DragonDanceEnd
	printfromtable gStatUpStringIds
	waitmessage B_WAIT_TIME_LONG
BattleScript_DragonDanceEnd::
	goto BattleScript_MoveEnd

BattleScript_EffectDragonDanceTrySatk:
	jumpifstat BS_ATTACKER, CMP_LESS_THAN, STAT_SPATK, MAX_STAT_STAGE, BattleScript_DragonDanceDoMoveAnimSatk
	jumpifstat BS_ATTACKER, CMP_EQUAL, STAT_SPEED, MAX_STAT_STAGE, BattleScript_CantRaiseMultipleStats
BattleScript_DragonDanceDoMoveAnimSatk::
	attackanimation
	waitanimation
	setbyte sSTAT_ANIM_PLAYED, FALSE
	playstatchangeanimation BS_ATTACKER, BIT_SPATK | BIT_SPEED, 0
	setstatchanger STAT_SPATK, 1, FALSE
	statbuffchange MOVE_EFFECT_AFFECTS_ATTACKER | STAT_CHANGE_ALLOW_PTR, BattleScript_DragonDanceTrySpeed
	jumpifbyte CMP_EQUAL, cMULTISTRING_CHOOSER, B_MSG_STAT_WONT_INCREASE, BattleScript_DragonDanceTrySpeed
	printfromtable gStatUpStringIds
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_DragonDanceTrySpeed

BattleScript_EffectCamouflage::
	attackcanceler
	attackstring
	ppreduce
	settypetoterrain BattleScript_ButItFailed
	attackanimation
	waitanimation
	printstring STRINGID_PKMNCHANGEDTYPE
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_FaintAttacker::
	tryillusionoff BS_ATTACKER
	playfaintcry BS_ATTACKER
	pause B_WAIT_TIME_LONG
	dofaintanimation BS_ATTACKER
	printstring STRINGID_ATTACKERFAINTED
	cleareffectsonfaint BS_ATTACKER
	tryactivatesoulheart
	tryactivatesouleater
	tryactivateabilitiesorinnatesonfaint BS_ATTACKER, 0
	tryactivateabilitiesorinnatesonfaint BS_ATTACKER, 1
	tryactivateabilitiesorinnatesonfaint BS_ATTACKER, 2
	tryactivateabilitiesorinnatesonfaint BS_ATTACKER, 3
	tryactivateabilitiesorinnatesonpartnerfaint BS_ATTACKER, 0
	tryactivateabilitiesorinnatesonpartnerfaint BS_ATTACKER, 1
	tryactivateabilitiesorinnatesonpartnerfaint BS_ATTACKER, 2
	tryactivateabilitiesorinnatesonpartnerfaint BS_ATTACKER, 3
	trytrainerslidefirstdownmsg BS_ATTACKER
	return

BattleScript_FaintTarget::
	tryillusionoff BS_TARGET
	playfaintcry BS_TARGET
	pause B_WAIT_TIME_LONG
	dofaintanimation BS_TARGET
	printstring STRINGID_TARGETFAINTED
	cleareffectsonfaint BS_TARGET
	tryactivatemoveeffect BS_ATTACKER
	tryactivateitemeffect BS_ATTACKER, 0
	tryactivatesoulheart
	tryactivatesouleater
	tryactivateabilitiesorinnatesonfaint BS_TARGET, 0
	tryactivateabilitiesorinnatesonfaint BS_TARGET, 1
	tryactivateabilitiesorinnatesonfaint BS_TARGET, 2
	tryactivateabilitiesorinnatesonfaint BS_TARGET, 3
	tryactivateabilitiesorinnatesonpartnerfaint BS_TARGET, 0
	tryactivateabilitiesorinnatesonpartnerfaint BS_TARGET, 1
	tryactivateabilitiesorinnatesonpartnerfaint BS_TARGET, 2
	tryactivateabilitiesorinnatesonpartnerfaint BS_TARGET, 3
	tryactivateattackerabilitiesorinnatesonfaint 0
	tryactivateattackerabilitiesorinnatesonfaint 1
	tryactivateattackerabilitiesorinnatesonfaint 2
	tryactivateattackerabilitiesorinnatesonfaint 3
	tryactivatebattlebond BS_ATTACKER
	trytrainerslidefirstdownmsg BS_TARGET
	return

BattleScript_GiveExp::
	setbyte sGIVEEXP_STATE, 0
	getexp BS_TARGET
	end2

BattleScript_HandleFaintedMon::
	setbyte sSHIFT_SWITCHED, 0
	atk24 BattleScript_HandleFaintedMonMultiple
	jumpifbyte CMP_NOT_EQUAL, gBattleOutcome, 0, BattleScript_FaintedMonEnd
	jumpifbattletype BATTLE_TYPE_TRAINER | BATTLE_TYPE_DOUBLE, BattleScript_FaintedMonTryChooseAnother
	jumpifword CMP_NO_COMMON_BITS, gHitMarker, HITMARKER_PLAYER_FAINTED, BattleScript_FaintedMonTryChooseAnother
	printstring STRINGID_USENEXTPKMN
	setbyte gBattleCommunication, 0
	yesnobox
	jumpifbyte CMP_EQUAL, gBattleCommunication + 1, 0, BattleScript_FaintedMonTryChooseAnother
	jumpifplayerran BattleScript_FaintedMonEnd
	printstring STRINGID_CANTESCAPE2
BattleScript_FaintedMonTryChooseAnother:
	openpartyscreen BS_FAINTED, BattleScript_FaintedMonEnd
	switchhandleorder BS_FAINTED, 2
	jumpifnotbattletype BATTLE_TYPE_TRAINER, BattleScript_FaintedMonChooseAnother
	jumpifbattletype BATTLE_TYPE_LINK, BattleScript_FaintedMonChooseAnother
	jumpifbattletype BATTLE_TYPE_RECORDED_LINK, BattleScript_FaintedMonChooseAnother
	jumpifbattletype BATTLE_TYPE_FRONTIER, BattleScript_FaintedMonChooseAnother
	jumpifbattletype BATTLE_TYPE_DOUBLE, BattleScript_FaintedMonChooseAnother
	jumpifword CMP_COMMON_BITS, gHitMarker, HITMARKER_PLAYER_FAINTED, BattleScript_FaintedMonChooseAnother
	jumpifbyte CMP_EQUAL, sBATTLE_STYLE, OPTIONS_BATTLE_STYLE_SET, BattleScript_FaintedMonChooseAnother
	jumpifcantswitch BS_PLAYER1, BattleScript_FaintedMonChooseAnother
	setbyte sILLUSION_NICK_HACK, 1
	printstring STRINGID_ENEMYABOUTTOSWITCHPKMN
	setbyte gBattleCommunication, 0
	yesnobox
	jumpifbyte CMP_EQUAL, gBattleCommunication + 1, 1, BattleScript_FaintedMonChooseAnother
	setatktoplayer0
	openpartyscreen BS_ATTACKER | PARTY_SCREEN_OPTIONAL, BattleScript_FaintedMonChooseAnother
	switchhandleorder BS_ATTACKER, 2
	jumpifbyte CMP_EQUAL, gBattleCommunication, PARTY_SIZE, BattleScript_FaintedMonChooseAnother
	atknameinbuff1
	resetintimidatetracebits BS_ATTACKER
	hpthresholds2 BS_ATTACKER
	printstring STRINGID_RETURNMON
	switchoutabilitiesorinnates BS_ATTACKER, 0
	switchoutabilitiesorinnates BS_ATTACKER, 1
	switchoutabilitiesorinnates BS_ATTACKER, 2
	switchoutabilitiesorinnates BS_ATTACKER, 3
	swithchoutrevolvingruin BS_ATTACKER
	waitstate
	returnatktoball
	waitstate
	drawpartystatussummary BS_ATTACKER
	getswitchedmondata BS_ATTACKER
	switchindataupdate BS_ATTACKER
	hpthresholds BS_ATTACKER
	trytoclearprimalweather
	printstring STRINGID_EMPTYSTRING3
	waitmessage 1
	printstring STRINGID_SWITCHINMON
	hidepartystatussummary BS_ATTACKER
	switchinanim BS_ATTACKER, 0
	waitstate
	setbyte sSHIFT_SWITCHED, 1
BattleScript_FaintedMonChooseAnother:
	drawpartystatussummary BS_FAINTED
	getswitchedmondata BS_FAINTED
	switchindataupdate BS_FAINTED
	hpthresholds BS_FAINTED
	trytoclearprimalweather
	printstring STRINGID_EMPTYSTRING3
	waitmessage 1
	printstring STRINGID_SWITCHINMON
	hidepartystatussummary BS_FAINTED
	switchinanim BS_FAINTED, FALSE
	waitstate
	various7 BS_ATTACKER
	trytrainerslideacemonmsg BS_FAINTED
	tryuseitemonacemon BS_FAINTED
	jumpifbytenotequal sSHIFT_SWITCHED, sZero, BattleScript_FaintedMonShiftSwitched
BattleScript_FaintedMonChooseAnotherEnd:
	switchineffects BS_FAINTED
	jumpifbattletype BATTLE_TYPE_DOUBLE, BattleScript_FaintedMonEnd
	cancelallactions
BattleScript_FaintedMonEnd::
	end2
BattleScript_FaintedMonShiftSwitched:
	copybyte sSAVED_BATTLER, gBattlerTarget
	switchineffects BS_ATTACKER
	resetsentmonsvalue
	copybyte gBattlerTarget, sSAVED_BATTLER
	goto BattleScript_FaintedMonChooseAnotherEnd

BattleScript_HandleFaintedMonMultiple::
	openpartyscreen BS_FAINTED_LINK_MULTIPLE_1, BattleScript_HandleFaintedMonMultipleStart
BattleScript_HandleFaintedMonMultipleStart::
	switchhandleorder BS_FAINTED, 0
	openpartyscreen BS_FAINTED_LINK_MULTIPLE_2, BattleScript_HandleFaintedMonMultipleEnd
	switchhandleorder BS_FAINTED, 0
BattleScript_HandleFaintedMonLoop::
	switchhandleorder BS_FAINTED, 3
	drawpartystatussummary BS_FAINTED
	getswitchedmondata BS_FAINTED
	switchindataupdate BS_FAINTED
	hpthresholds BS_FAINTED
	trytoclearprimalweather
	printstring STRINGID_EMPTYSTRING3
	waitmessage 1
	printstring STRINGID_SWITCHINMON
	hidepartystatussummary BS_FAINTED
	switchinanim BS_FAINTED, FALSE
	waitstate
	switchineffects 5
	jumpifbytenotequal gBattlerFainted, gBattlersCount, BattleScript_HandleFaintedMonLoop
BattleScript_HandleFaintedMonMultipleEnd::
	end2

BattleScript_LocalTrainerBattleWon::
	jumpifbattletype BATTLE_TYPE_TWO_OPPONENTS, BattleScript_LocalTwoTrainersDefeated
	printstring STRINGID_PLAYERDEFEATEDTRAINER1
	goto BattleScript_LocalBattleWonLoseTexts
BattleScript_LocalTwoTrainersDefeated::
	printstring STRINGID_TWOENEMIESDEFEATED
BattleScript_LocalBattleWonLoseTexts::
	trainerslidein BS_ATTACKER
	waitstate
	printstring STRINGID_TRAINER1LOSETEXT
	jumpifnotbattletype BATTLE_TYPE_TWO_OPPONENTS, BattleScript_LocalBattleWonReward
	trainerslideout B_POSITION_OPPONENT_LEFT
	waitstate
	trainerslidein BS_FAINTED
	waitstate
	printstring STRINGID_TRAINER2LOSETEXT
BattleScript_LocalBattleWonReward::
	getmoneyreward
	printstring STRINGID_PLAYERGOTMONEY
	waitmessage B_WAIT_TIME_LONG
BattleScript_PayDayMoneyAndPickUpItems::
	givepaydaymoney
	pickup
	end2

BattleScript_LocalBattleLost::
	jumpifbattletype BATTLE_TYPE_DOME, BattleScript_CheckDomeDrew
	jumpifbattletype BATTLE_TYPE_FRONTIER, BattleScript_LocalBattleLostPrintTrainersWinText
	jumpifbattletype BATTLE_TYPE_TRAINER_HILL, BattleScript_LocalBattleLostPrintTrainersWinText
	jumpifbattletype BATTLE_TYPE_EREADER_TRAINER, BattleScript_LocalBattleLostEnd
	jumpifhalfword CMP_EQUAL, gTrainerBattleOpponent_A, TRAINER_SECRET_BASE, BattleScript_LocalBattleLostEnd
	jumpifflagisset FLAG_NO_WHITEOUT_BATTLE, BattleScript_LocalBattleLostNoMoneyPrizeEnd
BattleScript_LocalBattleLostPrintWhiteOut::
	jumpifbattletype BATTLE_TYPE_TRAINER, BattleScript_LocalBattleLostEnd
	printstring STRINGID_PLAYERWHITEOUT
	waitmessage B_WAIT_TIME_LONG
	getmoneyreward
	printstring STRINGID_PLAYERWHITEOUT2
	waitmessage B_WAIT_TIME_LONG
	end2
BattleScript_LocalBattleLostEnd::
	printstring STRINGID_PLAYERLOSTAGAINSTENEMYTRAINER
	waitmessage 0x40
	getmoneyreward
	printstring STRINGID_PLAYERPAIDPRIZEMONEY
	waitmessage 0x40
	end2
BattleScript_LocalBattleLostNoMoneyPrizeEnd::
	printstring STRINGID_PLAYERLOSTAGAINSTENEMYTRAINER
	waitmessage 0x40
	end2
BattleScript_CheckDomeDrew::
	jumpifbyte CMP_EQUAL, gBattleOutcome, B_OUTCOME_DREW, BattleScript_LocalBattleLostEnd_
BattleScript_LocalBattleLostPrintTrainersWinText::
	jumpifnotbattletype BATTLE_TYPE_TRAINER, BattleScript_LocalBattleLostPrintWhiteOut
	returnopponentmon1toball BS_ATTACKER
	waitstate
	returnopponentmon2toball BS_ATTACKER
	waitstate
	trainerslidein BS_ATTACKER
	waitstate
	printstring STRINGID_TRAINER1WINTEXT
	jumpifbattletype BATTLE_TYPE_TOWER_LINK_MULTI, BattleScript_LocalBattleLostDoTrainer2WinText
	jumpifnotbattletype BATTLE_TYPE_TWO_OPPONENTS, BattleScript_LocalBattleLostEnd_
BattleScript_LocalBattleLostDoTrainer2WinText::
	trainerslideout B_POSITION_OPPONENT_LEFT
	waitstate
	trainerslidein BS_FAINTED
	waitstate
	printstring STRINGID_TRAINER2WINTEXT
BattleScript_LocalBattleLostEnd_::
	end2

BattleScript_FrontierLinkBattleLost::
	returnopponentmon1toball BS_ATTACKER
	waitstate
	returnopponentmon2toball BS_ATTACKER
	waitstate
	trainerslidein BS_ATTACKER
	waitstate
	printstring STRINGID_TRAINER1WINTEXT
	trainerslideout B_POSITION_OPPONENT_LEFT
	waitstate
	trainerslidein BS_FAINTED
	waitstate
	printstring STRINGID_TRAINER2WINTEXT
	jumpifbattletype BATTLE_TYPE_RECORDED, BattleScript_FrontierLinkBattleLostEnd
	endlinkbattle
BattleScript_FrontierLinkBattleLostEnd::
	waitmessage B_WAIT_TIME_LONG
	end2

BattleScript_LinkBattleWonOrLost::
	jumpifbattletype BATTLE_TYPE_BATTLE_TOWER, BattleScript_TowerLinkBattleWon
	printstring STRINGID_BATTLEEND
	waitmessage B_WAIT_TIME_LONG
	jumpifbattletype BATTLE_TYPE_RECORDED, BattleScript_LinkBattleWonOrLostWaitEnd
	endlinkbattle
BattleScript_LinkBattleWonOrLostWaitEnd::
	waitmessage B_WAIT_TIME_LONG
	end2

BattleScript_TowerLinkBattleWon::
	playtrainerdefeatbgm BS_ATTACKER
	printstring STRINGID_BATTLEEND
	waitmessage B_WAIT_TIME_LONG
	trainerslidein BS_ATTACKER
	waitstate
	printstring STRINGID_TRAINER1LOSETEXT
	trainerslideout B_POSITION_OPPONENT_LEFT
	waitstate
	trainerslidein BS_FAINTED
	waitstate
	printstring STRINGID_TRAINER2LOSETEXT
	jumpifbattletype BATTLE_TYPE_RECORDED, BattleScript_TowerLinkBattleWonEnd
	endlinkbattle
BattleScript_TowerLinkBattleWonEnd::
	waitmessage B_WAIT_TIME_LONG
	end2

BattleScript_FrontierTrainerBattleWon::
	jumpifnotbattletype BATTLE_TYPE_TRAINER, BattleScript_PayDayMoneyAndPickUpItems
	jumpifbattletype BATTLE_TYPE_TWO_OPPONENTS, BattleScript_FrontierTrainerBattleWon_TwoDefeated
	printstring STRINGID_PLAYERDEFEATEDTRAINER1
	goto BattleScript_FrontierTrainerBattleWon_LoseTexts
BattleScript_FrontierTrainerBattleWon_TwoDefeated:
	printstring STRINGID_TWOENEMIESDEFEATED
BattleScript_FrontierTrainerBattleWon_LoseTexts:
	trainerslidein BS_ATTACKER
	waitstate
	printstring STRINGID_TRAINER1LOSETEXT
	jumpifnotbattletype BATTLE_TYPE_TWO_OPPONENTS, BattleScript_TryPickUpItems
	trainerslideout B_POSITION_OPPONENT_LEFT
	waitstate
	trainerslidein BS_FAINTED
	waitstate
	printstring STRINGID_TRAINER2LOSETEXT
BattleScript_TryPickUpItems:
	jumpifnotbattletype BATTLE_TYPE_PYRAMID, BattleScript_FrontierTrainerBattleWon_End
	pickup
BattleScript_FrontierTrainerBattleWon_End:
	end2

BattleScript_SmokeBallEscape::
	playanimation BS_ATTACKER, B_ANIM_SMOKEBALL_ESCAPE, NULL
	printstring STRINGID_PKMNFLEDUSINGITS
	waitmessage B_WAIT_TIME_LONG
	end2

BattleScript_RanAwayUsingMonAbility::
	printstring STRINGID_PKMNFLEDUSING
	waitmessage B_WAIT_TIME_LONG
	end2

BattleScript_GotAwaySafely::
	printstring STRINGID_GOTAWAYSAFELY
	waitmessage B_WAIT_TIME_LONG
	end2

BattleScript_WildMonFled::
	printstring STRINGID_WILDPKMNFLED
	waitmessage B_WAIT_TIME_LONG
	end2

BattleScript_PrintCantRunFromTrainer::
	printstring STRINGID_NORUNNINGFROMTRAINERS
	end2

BattleScript_PrintFailedToRunString::
	printfromtable gNoEscapeStringIds
	waitmessage B_WAIT_TIME_LONG
	end2

BattleScript_PrintCantEscapeFromBattle::
	printselectionstringfromtable gNoEscapeStringIds
	endselectionscript

BattleScript_PrintFullBox::
	printselectionstring STRINGID_BOXISFULL
	endselectionscript

BattleScript_ActionSwitch::
	hpthresholds2 BS_ATTACKER
	printstring STRINGID_RETURNMON
	jumpifbattletype BATTLE_TYPE_DOUBLE, BattleScript_PursuitSwitchDmgSetMultihit
	setmultihit 1
	goto BattleScript_PursuitSwitchDmgLoop
BattleScript_PursuitSwitchDmgSetMultihit::
	setmultihit 2
BattleScript_PursuitSwitchDmgLoop::
	jumpifnopursuitswitchdmg BattleScript_DoSwitchOut
	swapattackerwithtarget
	trysetdestinybondtohappen
	call BattleScript_PursuitDmgOnSwitchOut
	swapattackerwithtarget
BattleScript_DoSwitchOut::
	decrementmultihit BattleScript_PursuitSwitchDmgLoop
	switchoutabilitiesorinnates BS_ATTACKER, 0
	switchoutabilitiesorinnates BS_ATTACKER, 1
	switchoutabilitiesorinnates BS_ATTACKER, 2
	switchoutabilitiesorinnates BS_ATTACKER, 3
	swithchoutrevolvingruin BS_ATTACKER
	waitstate
	returnatktoball
	waitstate
	drawpartystatussummary BS_ATTACKER
	switchhandleorder BS_ATTACKER, 1
	getswitchedmondata BS_ATTACKER
	switchindataupdate BS_ATTACKER
	hpthresholds BS_ATTACKER
	trytoclearprimalweather
	printstring STRINGID_EMPTYSTRING3
	waitmessage 1
	printstring STRINGID_SWITCHINMON
	hidepartystatussummary BS_ATTACKER
	switchinanim BS_ATTACKER, FALSE
	waitstate
	jumpifcantreverttoprimal BattleScript_DoSwitchOut2
	call BattleScript_PrimalReversionRet
BattleScript_DoSwitchOut2:
	switchineffects BS_ATTACKER
	moveendcase MOVEEND_STATUS_IMMUNITY_ABILITIES
	moveendcase MOVEEND_MIRROR_MOVE
	end2

BattleScript_PursuitDmgOnSwitchOut::
	pause B_WAIT_TIME_SHORT
	attackstring
	ppreduce
	call BattleScript_EffectDamage_Ret
	tryfaintmon BS_TARGET, FALSE, NULL
	moveendfromto MOVEEND_RUBBLE_ROUSER, MOVEEND_CHOICE_MOVE
	getbattlerfainted BS_TARGET
	jumpifbyte CMP_EQUAL, gBattleCommunication, FALSE, BattleScript_PursuitDmgOnSwitchOutRet
	setbyte sGIVEEXP_STATE, 0
	getexp BS_TARGET
BattleScript_PursuitDmgOnSwitchOutRet:
	return

BattleScript_Pausex20::
	pause B_WAIT_TIME_SHORT
	return

BattleScript_LevelUp::
	fanfare MUS_LEVEL_UP
	printstring STRINGID_PKMNGREWTOLV
	setbyte sLVLBOX_STATE, 0
	drawlvlupbox
	handlelearnnewmove BattleScript_LearnedNewMove, BattleScript_LearnAbility, TRUE
	goto BattleScript_AskToLearnMove
BattleScript_TryLearnMoveLoop::
	handlelearnnewmove BattleScript_LearnedNewMove, BattleScript_LearnAbility, FALSE
BattleScript_AskToLearnMove::
	buffermovetolearn
	printstring STRINGID_TRYTOLEARNMOVE1
	printstring STRINGID_TRYTOLEARNMOVE2
	printstring STRINGID_TRYTOLEARNMOVE3
	waitstate
	setbyte sLEARNMOVE_STATE, 0
	yesnoboxlearnmove BattleScript_ForgotAndLearnedNewMove
	printstring STRINGID_STOPLEARNINGMOVE
	waitstate
	setbyte sLEARNMOVE_STATE, 0
	yesnoboxstoplearningmove BattleScript_AskToLearnMove
	printstring STRINGID_DIDNOTLEARNMOVE
	goto BattleScript_TryLearnMoveLoop
BattleScript_ForgotAndLearnedNewMove::
	printstring STRINGID_123POOF
	printstring STRINGID_PKMNFORGOTMOVE
	printstring STRINGID_ANDELLIPSIS
BattleScript_LearnedNewMove::
	buffermovetolearn
	fanfare MUS_LEVEL_UP
	printstring STRINGID_PKMNLEARNEDMOVE
	waitmessage B_WAIT_TIME_LONG
	updatechoicemoveonlvlup BS_ATTACKER
	goto BattleScript_TryLearnMoveLoop
BattleScript_LearnAbility::
	handlelearnnewability BattleScript_LearnedNewAbility, BattleScript_LearnAbilityReturn, TRUE
	goto BattleScript_AskToLearnAbility
BattleScript_TryLearnAbilityLoop::
	handlelearnnewability BattleScript_LearnedNewAbility, BattleScript_LearnAbilityReturn, FALSE
BattleScript_AskToLearnAbility::
	bufferabilitytolearn
	printstring STRINGID_TRYTOLEARNMOVE1
	printstring STRINGID_TRYTOLEARNABILITY2
	printstring STRINGID_TRYTOLEARNABILITY3
	waitstate
	setbyte sLEARNMOVE_STATE, 0
	yesnoboxlearnability BattleScript_ForgotAndLearnedNewAbility
	printstring STRINGID_STOPLEARNINGMOVE
	waitstate
	setbyte sLEARNMOVE_STATE, 0
	yesnoboxstoplearningmove BattleScript_AskToLearnAbility @ no problem
	printstring STRINGID_DIDNOTLEARNMOVE
	goto BattleScript_TryLearnAbilityLoop
BattleScript_ForgotAndLearnedNewAbility::
	printstring STRINGID_123POOF
	printstring STRINGID_PKMNFORGOTMOVE
	printstring STRINGID_ANDELLIPSIS
BattleScript_LearnedNewAbility::
	bufferabilitytolearn
	fanfare MUS_LEVEL_UP
	printstring STRINGID_PKMNLEARNEDMOVE
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_TryLearnAbilityLoop
BattleScript_LearnAbilityReturn::
	return

BattleScript_RainContinuesOrEnds::
	printfromtable gRainContinuesStringIds
	waitmessage B_WAIT_TIME_LONG
	jumpifbyte CMP_EQUAL, cMULTISTRING_CHOOSER, B_MSG_RAIN_STOPPED, BattleScript_RainContinuesOrEndsEnd
	playanimation BS_ATTACKER, B_ANIM_RAIN_CONTINUES, NULL
BattleScript_RainContinuesOrEndsEnd::
	call BattleScript_WeatherFormChanges
	end2

BattleScript_DamagingWeatherContinues::
	printfromtable gSandStormHailContinuesStringIds
	waitmessage B_WAIT_TIME_LONG
	playanimation2 BS_ATTACKER, sB_ANIM_ARG1, NULL
	setbyte gBattleCommunication, 0
BattleScript_DamagingWeatherLoop::
	copyarraywithindex gBattlerAttacker, gBattlerByTurnOrder, gBattleCommunication, 1
	weatherdamage
	jumpifword CMP_EQUAL, gBattleMoveDamage, 0, BattleScript_DamagingWeatherLoopIncrement
	jumpifword CMP_COMMON_BITS gBattleMoveDamage, 1 << 31, BattleScript_DamagingWeatherHeal
	printfromtable gSandStormHailDmgStringIds
	waitmessage B_WAIT_TIME_LONG
	effectivenesssound
	hitanimation BS_ATTACKER
	goto BattleScript_DamagingWeatherHpChange
BattleScript_DamagingWeatherHeal:
	call BattleScript_AbilityPopUp
	printstring STRINGID_ICEBODYHPGAIN
	waitmessage B_WAIT_TIME_LONG
BattleScript_DamagingWeatherHpChange:
	orword gHitMarker, HITMARKER_SKIP_DMG_TRACK | HITMARKER_IGNORE_SUBSTITUTE | HITMARKER_PASSIVE_DAMAGE | HITMARKER_GRUDGE
	healthbarupdate BS_ATTACKER
	datahpupdate BS_ATTACKER
	tryfaintmon BS_ATTACKER, FALSE, NULL
	atk24 BattleScript_DamagingWeatherLoopIncrement
BattleScript_DamagingWeatherLoopIncrement::
	jumpifbyte CMP_NOT_EQUAL, gBattleOutcome, 0, BattleScript_DamagingWeatherContinuesEnd
	addbyte gBattleCommunication, 1
	jumpifbytenotequal gBattleCommunication, gBattlersCount, BattleScript_DamagingWeatherLoop
BattleScript_DamagingWeatherContinuesEnd::
	bicword gHitMarker, HITMARKER_SKIP_DMG_TRACK | HITMARKER_IGNORE_SUBSTITUTE | HITMARKER_PASSIVE_DAMAGE | HITMARKER_GRUDGE
	end2

BattleScript_SandStormHailEnds::
	printfromtable gSandStormHailEndStringIds
	waitmessage B_WAIT_TIME_LONG
	call BattleScript_WeatherFormChanges
	end2

BattleScript_SunlightContinues::
	printstring STRINGID_SUNLIGHTSTRONG
	waitmessage B_WAIT_TIME_LONG
	playanimation BS_ATTACKER, B_ANIM_SUN_CONTINUES, NULL
	end2

BattleScript_SunlightFaded::
	printstring STRINGID_SUNLIGHTFADED
	waitmessage B_WAIT_TIME_LONG
	call BattleScript_WeatherFormChanges
	end2

BattleScript_FogContinues::
	printstring STRINGID_FOGCONTINUES
	waitmessage B_WAIT_TIME_LONG
	playanimation BS_ATTACKER, B_ANIM_FOG_CONTINUES, NULL
	end2

BattleScript_NightContinues::
	printstring STRINGID_NIGHTCONTINUES
	waitmessage B_WAIT_TIME_LONG
	playanimation BS_ATTACKER, B_ANIM_NIGHT_CONTINUES, NULL
	end2

BattleScript_FogEnds::
	printstring STRINGID_FOGSTOPPED
	waitmessage B_WAIT_TIME_LONG
	call BattleScript_WeatherFormChanges
	end2

BattleScript_NightEnds::
	printstring STRINGID_NIGHTSTOPPED
	waitmessage B_WAIT_TIME_LONG
	call BattleScript_WeatherFormChanges
	end2

BattleScript_OverworldWeatherStarts::
	printfromtable gWeatherStartsStringIds
	waitmessage B_WAIT_TIME_LONG
	playanimation2 BS_ATTACKER, sB_ANIM_ARG1, NULL
	call BattleScript_WeatherFormChanges
	end3

BattleScript_OverworldTerrain::
	printfromtable gTerrainStringIds
	waitmessage B_WAIT_TIME_LONG
	playanimation BS_SCRIPTING, B_ANIM_RESTORE_BG, NULL
	call BattleScript_TerrainFormChanges
	call BattleScript_TerrainSeedLoop
	end3

BattleScript_EternalLifeRevival::
	printstring STRINGID_ETERNAL_LIFE_REVIVAL
	waitmessage B_WAIT_TIME_LONG
	end2

BattleScript_SideStatusWoreOff::
	printstring STRINGID_PKMNSXWOREOFF
	waitmessage B_WAIT_TIME_LONG
	end2

BattleScript_SideStatusWoreOffReturn::
	printstring STRINGID_PKMNSXWOREOFF
	waitmessage B_WAIT_TIME_LONG
	return

BattleScript_LuckyChantEnds::
	printstring STRINGID_LUCKYCHANTENDS
	waitmessage B_WAIT_TIME_LONG
	end2

BattleScript_TailwindEnds::
	printstring STRINGID_TAILWINDENDS
	waitmessage B_WAIT_TIME_LONG
	end2

BattleScript_TrickRoomEnds::
	printstring STRINGID_TRICKROOMENDS
	waitmessage B_WAIT_TIME_LONG
	end2

BattleScript_WonderRoomEnds::
	printstring STRINGID_WONDERROOMENDS
	waitmessage B_WAIT_TIME_LONG
	end2

BattleScript_MagicRoomEnds::
	printstring STRINGID_MAGICROOMENDS
	waitmessage B_WAIT_TIME_LONG
	end2

BattleScript_ElectricTerrainEnds::
	printstring STRINGID_ELECTRICTERRAINENDS
	waitmessage B_WAIT_TIME_LONG
	playanimation BS_ATTACKER, B_ANIM_RESTORE_BG, NULL
	call BattleScript_TerrainFormChanges
	end2

BattleScript_MistyTerrainEnds::
	printstring STRINGID_MISTYTERRAINENDS
	waitmessage B_WAIT_TIME_LONG
	playanimation BS_ATTACKER, B_ANIM_RESTORE_BG, NULL
	call BattleScript_TerrainFormChanges
	end2

BattleScript_GrassyTerrainEnds::
	printstring STRINGID_GRASSYTERRAINENDS
	waitmessage B_WAIT_TIME_LONG
	playanimation BS_ATTACKER, B_ANIM_RESTORE_BG, NULL
	call BattleScript_TerrainFormChanges
	end2

BattleScript_PsychicTerrainEnds::
	printstring STRINGID_PSYCHICTERRAINENDS
	waitmessage B_WAIT_TIME_LONG
	playanimation BS_ATTACKER, B_ANIM_RESTORE_BG, NULL
	call BattleScript_TerrainFormChanges
	end2

BattleScript_FrozenTerrainEnds::
	printstring STRINGID_FROZENTERRAINENDS
	waitmessage B_WAIT_TIME_LONG
	playanimation BS_ATTACKER, B_ANIM_RESTORE_BG, NULL
	call BattleScript_TerrainFormChanges
	end2

BattleScript_CursedTerrainEnds::
	printstring STRINGID_CURSEDTERRAINENDS
	waitmessage B_WAIT_TIME_LONG
	playanimation BS_ATTACKER, B_ANIM_RESTORE_BG, NULL
	call BattleScript_TerrainFormChanges
	end2

BattleScript_BurningTerrainEnds::
	printstring STRINGID_BURNINGTERRAINENDS
	waitmessage B_WAIT_TIME_LONG
	playanimation BS_ATTACKER, B_ANIM_RESTORE_BG, NULL
	call BattleScript_TerrainFormChanges
	end2

BattleScript_SandyTerrainEnds::
	printstring STRINGID_SANDYTERRAINENDS
	waitmessage B_WAIT_TIME_LONG
	playanimation BS_ATTACKER, B_ANIM_RESTORE_BG, NULL
	call BattleScript_TerrainFormChanges
	end2

BattleScript_RavineTerrainEnds::
	printstring STRINGID_RAVINETERRAINENDS
	waitmessage B_WAIT_TIME_LONG
	playanimation BS_ATTACKER, B_ANIM_RESTORE_BG, NULL
	call BattleScript_TerrainFormChanges
	end2

BattleScript_SwampTerrainEnds::
	printstring STRINGID_SWAMPTERRAINENDS
	waitmessage B_WAIT_TIME_LONG
	playanimation BS_ATTACKER, B_ANIM_RESTORE_BG, NULL
	call BattleScript_TerrainFormChanges
	end2

BattleScript_VenomousTerrainEnds::
	printstring STRINGID_VENOMOUSTERRAINENDS
	waitmessage B_WAIT_TIME_LONG
	playanimation BS_ATTACKER, B_ANIM_RESTORE_BG, NULL
	call BattleScript_TerrainFormChanges
	end2

BattleScript_RevolvingRuinEnds::
	printstring STRINGID_RINGOFFIREENDS
	waitmessage B_WAIT_TIME_LONG
	end2

BattleScript_MudSportEnds::
	printstring STRINGID_MUDSPORTENDS
	waitmessage B_WAIT_TIME_LONG
	end2

BattleScript_WaterSportEnds::
	printstring STRINGID_WATERSPORTENDS
	waitmessage B_WAIT_TIME_LONG
	end2

BattleScript_GravityEnds::
	printstring STRINGID_GRAVITYENDS
	waitmessage B_WAIT_TIME_LONG
	end2

BattleScript_SafeguardProtected::
	pause B_WAIT_TIME_SHORT
	printstring STRINGID_PKMNUSEDSAFEGUARD
	waitmessage B_WAIT_TIME_LONG
	end2

BattleScript_KingsGraceProtected::
	pause B_WAIT_TIME_SHORT
	printstring STRINGID_PKMNUSEDKINGSGRACE
	waitmessage B_WAIT_TIME_LONG
	end2

BattleScript_SafeguardEnds::
	pause B_WAIT_TIME_SHORT
	printstring STRINGID_PKMNSAFEGUARDEXPIRED
	waitmessage B_WAIT_TIME_LONG
	end2

BattleScript_KingsGraceEnds::
	pause B_WAIT_TIME_SHORT
	printstring STRINGID_PKMNKINGSGRACEEXPIRED
	waitmessage B_WAIT_TIME_LONG
	end2

BattleScript_LeechSeedTurnDrain::
	playanimation BS_ATTACKER, B_ANIM_LEECH_SEED_DRAIN, sB_ANIM_ARG1
	orword gHitMarker, HITMARKER_IGNORE_SUBSTITUTE | HITMARKER_PASSIVE_DAMAGE
	healthbarupdate BS_ATTACKER
	datahpupdate BS_ATTACKER
	copyword gBattleMoveDamage, gHpDealt
	jumpifabilityorinnate BS_ATTACKER, ABILITY_LIQUID_OOZE, BattleScript_LeechSeedTurnPrintLiquidOoze
	setbyte cMULTISTRING_CHOOSER, B_MSG_LEECH_SEED_DRAIN
	jumpifstatus3 BS_TARGET, STATUS3_HEAL_BLOCK, BattleScript_LeechSeedHealBlock
	jumpifcursedterrainblocked BS_TARGET, BattleScript_LeechSeedHealBlock
	manipulatedamage DMG_BIG_ROOT
	goto BattleScript_LeechSeedTurnPrintAndUpdateHp
BattleScript_LeechSeedTurnPrintLiquidOoze::
	copybyte gBattlerAbility, gBattlerAttacker
	sethword sABILITY_OVERWRITE, ABILITY_LIQUID_OOZE
	pause B_WAIT_TIME_SHORT
	call BattleScript_AbilityPopUp
	setbyte cMULTISTRING_CHOOSER, B_MSG_LEECH_SEED_OOZE
BattleScript_LeechSeedTurnPrintAndUpdateHp::
	orword gHitMarker, HITMARKER_IGNORE_SUBSTITUTE | HITMARKER_PASSIVE_DAMAGE
	healthbarupdate BS_TARGET
	datahpupdate BS_TARGET
	printfromtable gLeechSeedStringIds
	waitmessage B_WAIT_TIME_LONG
	tryfaintmon BS_ATTACKER, FALSE, NULL
	tryfaintmon BS_TARGET, FALSE, NULL
	end2
BattleScript_LeechSeedHealBlock:
	setword gBattleMoveDamage, 0
	goto BattleScript_LeechSeedTurnPrintAndUpdateHp

BattleScript_CordycepsTurnDrain::
	playanimation BS_ATTACKER, B_ANIM_LEECH_SEED_DRAIN, sB_ANIM_ARG1
	orword gHitMarker, HITMARKER_IGNORE_SUBSTITUTE | HITMARKER_PASSIVE_DAMAGE
	healthbarupdate BS_ATTACKER
	datahpupdate BS_ATTACKER
	copyword gBattleMoveDamage, gHpDealt
	jumpifabilityorinnate BS_ATTACKER, ABILITY_LIQUID_OOZE, BattleScript_CordycepsTurnPrintLiquidOoze
	setbyte cMULTISTRING_CHOOSER, B_MSG_CORDYCEPS_DRAIN
	jumpifstatus3 BS_TARGET, STATUS3_HEAL_BLOCK, BattleScript_CordycepsHealBlock
	jumpifcursedterrainblocked BS_TARGET, BattleScript_CordycepsHealBlock
	manipulatedamage DMG_BIG_ROOT
	goto BattleScript_CordycepsTurnPrintAndUpdateHp
BattleScript_CordycepsTurnPrintLiquidOoze::
	copybyte gBattlerAbility, gBattlerAttacker
	sethword sABILITY_OVERWRITE, ABILITY_LIQUID_OOZE
	pause B_WAIT_TIME_SHORT
	call BattleScript_AbilityPopUp
	setbyte cMULTISTRING_CHOOSER, B_MSG_CORDYCEPS_DRAIN
BattleScript_CordycepsTurnPrintAndUpdateHp::
	orword gHitMarker, HITMARKER_IGNORE_SUBSTITUTE | HITMARKER_PASSIVE_DAMAGE
	healthbarupdate BS_TARGET
	datahpupdate BS_TARGET
	printfromtable gCordycepsStringIds
	waitmessage B_WAIT_TIME_LONG
	tryfaintmon BS_ATTACKER, FALSE, NULL
	tryfaintmon BS_TARGET, FALSE, NULL
	end2
BattleScript_CordycepsHealBlock:
	setword gBattleMoveDamage, 0
	goto BattleScript_LeechSeedTurnPrintAndUpdateHp

BattleScript_BideStoringEnergy::
	printstring STRINGID_PKMNSTORINGENERGY
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_BideAttack::
	attackcanceler
	setmoveeffect MOVE_EFFECT_CHARGING
	clearstatusfromeffect BS_ATTACKER
	printstring STRINGID_PKMNUNLEASHEDENERGY
	waitmessage B_WAIT_TIME_LONG
	accuracycheck BattleScript_MoveMissed, ACC_CURR_MOVE
	typecalc
	bichalfword gMoveResultFlags, MOVE_RESULT_SUPER_EFFECTIVE | MOVE_RESULT_NOT_VERY_EFFECTIVE
	copyword gBattleMoveDamage, sBIDE_DMG
	adjustdamage
	setbyte sB_ANIM_TURN, 1
	attackanimation
	waitanimation
	effectivenesssound
	hitanimation BS_TARGET
	waitstate
	healthbarupdate BS_TARGET
	datahpupdate BS_TARGET
	resultmessage
	waitmessage B_WAIT_TIME_LONG
	tryfaintmon BS_TARGET, FALSE, NULL
	goto BattleScript_MoveEnd

BattleScript_BideNoEnergyToAttack::
	attackcanceler
	setmoveeffect MOVE_EFFECT_CHARGING
	clearstatusfromeffect BS_ATTACKER
	printstring STRINGID_PKMNUNLEASHEDENERGY
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_ButItFailed

BattleScript_RoarSuccessSwitch::
	call BattleScript_RoarSuccessRet
	getswitchedmondata BS_TARGET
	switchindataupdate BS_TARGET
	trytoclearprimalweather
	printstring STRINGID_EMPTYSTRING3
	waitmessage 1
	switchinanim BS_TARGET, FALSE
	waitstate
	printstring STRINGID_PKMNWASDRAGGEDOUT
	switchineffects BS_TARGET
	jumpifbyte CMP_EQUAL, sSWITCH_CASE, B_SWITCH_RED_CARD, BattleScript_RoarSuccessSwitch_Ret
	setbyte sSWITCH_CASE, B_SWITCH_NORMAL
	goto BattleScript_MoveEnd
BattleScript_RoarSuccessSwitch_Ret:
	swapattackerwithtarget	@ continuation of RedCardActivates
	restoretarget
	removeitem BS_TARGET, 1
	setbyte sSWITCH_CASE, B_SWITCH_NORMAL
	return

BattleScript_RoarSuccessEndBattle::
	call BattleScript_RoarSuccessRet
	setbyte sSWITCH_CASE, B_SWITCH_NORMAL
	setoutcomeonteleport BS_ATTACKER
	finishaction

BattleScript_RoarSuccessRet:
	jumpifbyte CMP_EQUAL, sSWITCH_CASE, B_SWITCH_HIT, BattleScript_RoarSuccessRet_Ret
	jumpifbyte CMP_EQUAL, sSWITCH_CASE, B_SWITCH_RED_CARD, BattleScript_RoarSuccessRet_Ret
	attackanimation
	waitanimation
BattleScript_RoarSuccessRet_Ret:
	switchoutabilitiesorinnates BS_TARGET, 0
	switchoutabilitiesorinnates BS_TARGET, 1
	switchoutabilitiesorinnates BS_TARGET, 2
	switchoutabilitiesorinnates BS_TARGET, 3
	swithchoutrevolvingruin BS_TARGET
	returntoball BS_TARGET
	waitstate
	return

BattleScript_WeaknessPolicy::
	copybyte sBATTLER, gBattlerTarget
	jumpifstat BS_TARGET, CMP_LESS_THAN, STAT_ATK, MAX_STAT_STAGE, BattleScript_WeaknessPolicyAtk
	jumpifstat BS_TARGET, CMP_EQUAL, STAT_SPATK, MAX_STAT_STAGE, BattleScript_WeaknessPolicyEnd
BattleScript_WeaknessPolicyAtk:
	playanimation BS_TARGET, B_ANIM_HELD_ITEM_EFFECT, NULL
	waitanimation
	setbyte sSTAT_ANIM_PLAYED, FALSE
	playstatchangeanimation BS_TARGET, BIT_ATK | BIT_SPATK, STAT_CHANGE_BY_TWO
	setstatchanger STAT_ATK, 2, FALSE
	statbuffchange STAT_CHANGE_ALLOW_PTR, BattleScript_WeaknessPolicySpAtk
	jumpifbyte CMP_EQUAL, cMULTISTRING_CHOOSER, B_MSG_STAT_WONT_INCREASE, BattleScript_WeaknessPolicySpAtk
	printstring STRINGID_USINGITEMSTATOFPKMNROSE
	waitmessage B_WAIT_TIME_LONG
BattleScript_WeaknessPolicySpAtk:
	setstatchanger STAT_SPATK, 2, FALSE
	statbuffchange STAT_CHANGE_ALLOW_PTR, BattleScript_WeaknessPolicyRemoveItem
	jumpifbyte CMP_EQUAL, cMULTISTRING_CHOOSER, B_MSG_STAT_WONT_INCREASE, BattleScript_WeaknessPolicyRemoveItem
	printstring STRINGID_USINGITEMSTATOFPKMNROSE
	waitmessage B_WAIT_TIME_LONG
BattleScript_WeaknessPolicyRemoveItem:
	removeitem BS_TARGET, 1
BattleScript_WeaknessPolicyEnd:
	return

BattleScript_TargetItemStatRaise::
	copybyte sBATTLER, gBattlerTarget
	statbuffchange 0, BattleScript_TargetItemStatRaiseRemoveItemRet
	jumpifbyte CMP_EQUAL, cMULTISTRING_CHOOSER, B_MSG_STAT_WONT_INCREASE, BattleScript_TargetItemStatRaiseRemoveItemRet
	playanimation BS_TARGET, B_ANIM_HELD_ITEM_EFFECT, NULL
	waitanimation
	setgraphicalstatchangevalues
	playanimation BS_TARGET, B_ANIM_STATS_CHANGE, sB_ANIM_ARG1
	waitanimation
	printstring STRINGID_USINGITEMSTATOFPKMNROSE
	waitmessage B_WAIT_TIME_LONG
	removeitem BS_TARGET, 1
BattleScript_TargetItemStatRaiseRemoveItemRet:
	return
	
BattleScript_AttackerItemStatRaise::
	copybyte sBATTLER, gBattlerAttacker
	statbuffchange MOVE_EFFECT_AFFECTS_ATTACKER, BattleScript_AttackerItemStatRaiseRet
	jumpifbyte CMP_EQUAL, cMULTISTRING_CHOOSER, 0x2, BattleScript_AttackerItemStatRaiseRet
	playanimation BS_ATTACKER, B_ANIM_HELD_ITEM_EFFECT, NULL
	waitanimation
	setgraphicalstatchangevalues
	playanimation BS_ATTACKER, B_ANIM_STATS_CHANGE, sB_ANIM_ARG1
	waitanimation
	printstring STRINGID_USINGITEMSTATOFPKMNROSE
	waitmessage 0x40
	removeitem BS_ATTACKER, 1
BattleScript_AttackerItemStatRaiseRet:
	return

BattleScript_MistProtected::
	pause B_WAIT_TIME_SHORT
	printstring STRINGID_PKMNPROTECTEDBYMIST
	waitmessage B_WAIT_TIME_LONG
	return

BattleScript_RageIsBuilding::
	printstring STRINGID_PKMNRAGEBUILDING
	waitmessage B_WAIT_TIME_LONG
	return

BattleScript_MoveUsedIsDisabled::
	printstring STRINGID_PKMNMOVEISDISABLED
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_SelectingDisabledMove::
	printselectionstring STRINGID_PKMNMOVEISDISABLED
	endselectionscript

BattleScript_DisabledNoMore::
	printstring STRINGID_PKMNMOVEDISABLEDNOMORE
	waitmessage B_WAIT_TIME_LONG
	end2

BattleScript_SelectingDisabledMoveInPalace::
	printstring STRINGID_PKMNMOVEISDISABLED
BattleScript_SelectingUnusableMoveInPalace::
	moveendto MOVEEND_NEXT_TARGET
	end

BattleScript_EncoredNoMore::
	printstring STRINGID_PKMNENCOREENDED
	waitmessage B_WAIT_TIME_LONG
	end2

BattleScript_DestinyBondTakesLife::
	printstring STRINGID_PKMNTOOKFOE
	waitmessage B_WAIT_TIME_LONG
	orword gHitMarker, HITMARKER_IGNORE_SUBSTITUTE | HITMARKER_PASSIVE_DAMAGE
	healthbarupdate BS_ATTACKER
	datahpupdate BS_ATTACKER
	tryfaintmon BS_ATTACKER, FALSE, NULL
	return

BattleScript_DmgHazardsOnAttacker::
	orword gHitMarker, HITMARKER_IGNORE_SUBSTITUTE | HITMARKER_PASSIVE_DAMAGE
	healthbarupdate BS_ATTACKER
	datahpupdate BS_ATTACKER
	call BattleScript_PrintHurtByDmgHazards
	tryfaintmon BS_ATTACKER, FALSE, NULL
	tryfaintmon BS_ATTACKER, TRUE, BattleScript_DmgHazardsOnAttackerFainted
	return

BattleScript_DmgHazardsOnAttackerFainted::
	setbyte sGIVEEXP_STATE, 0
	getexp BS_ATTACKER
	moveendall
	goto BattleScript_HandleFaintedMon

BattleScript_DmgHazardsOnTarget::
	orword gHitMarker, HITMARKER_IGNORE_SUBSTITUTE | HITMARKER_PASSIVE_DAMAGE
	healthbarupdate BS_TARGET
	datahpupdate BS_TARGET
	call BattleScript_PrintHurtByDmgHazards
	tryfaintmon BS_TARGET, FALSE, NULL
	tryfaintmon BS_TARGET, TRUE, BattleScript_DmgHazardsOnTargetFainted
	return

BattleScript_DmgHazardsOnTargetFainted::
	setbyte sGIVEEXP_STATE, 0
	getexp BS_TARGET
	moveendall
	goto BattleScript_HandleFaintedMon

BattleScript_DmgHazardsOnFaintedBattler::
	orword gHitMarker, HITMARKER_IGNORE_SUBSTITUTE | HITMARKER_PASSIVE_DAMAGE
	healthbarupdate BS_FAINTED
	datahpupdate BS_FAINTED
	call BattleScript_PrintHurtByDmgHazards
	tryfaintmon BS_FAINTED, FALSE, NULL
	tryfaintmon BS_FAINTED, TRUE, BattleScript_DmgHazardsOnFaintedBattlerFainted
	return

BattleScript_DmgHazardsOnFaintedBattlerFainted::
	setbyte sGIVEEXP_STATE, 0
	getexp BS_FAINTED
	moveendall
	goto BattleScript_HandleFaintedMon

BattleScript_PrintHurtByDmgHazards::
	printfromtable gDmgHazardsStringIds
	waitmessage B_WAIT_TIME_LONG
	return

BattleScript_ToxicSpikesAbsorbed::
	printstring STRINGID_TOXICSPIKESABSORBED
	waitmessage B_WAIT_TIME_LONG
	return

BattleScript_ToxicSpikesPoisoned::
	printstring STRINGID_TOXICSPIKESPOISONED
	waitmessage B_WAIT_TIME_LONG
	statusanimation BS_SCRIPTING
	updatestatusicon BS_SCRIPTING
	waitstate
	return

BattleScript_HighFlight::
	call BattleScript_AbilityPopUp
	playmoveanimation BS_ATTACKER, MOVE_FLY
	waitanimation
	printstring STRINGID_ABILITYFLIGHT
	waitmessage B_WAIT_TIME_LONG
	setbattlerstatus BS_ATTACKER, 3, STATUS3_ON_AIR, BattleScript_End3
	setsemiinvulnerablehelper BS_ATTACKER, 1
	end3

BattleScript_Digging::
	call BattleScript_AbilityPopUp
	playmoveanimation BS_ATTACKER, MOVE_DIG
	waitanimation
	printstring STRINGID_ABILITYDIGGING
	waitmessage B_WAIT_TIME_LONG
	setbattlerstatus BS_ATTACKER, 3, STATUS3_UNDERGROUND, BattleScript_End3
	setsemiinvulnerablehelper BS_ATTACKER, 1
	end3

BattleScript_Stealth_Ret::
	call BattleScript_AbilityPopUp
	playmoveanimation BS_ATTACKER, MOVE_MYSTICAL_MIRAGE
	waitanimation
	printstring STRINGID_ABILITYVANISH
	waitmessage B_WAIT_TIME_LONG
	setbattlerstatus BS_ATTACKER, 3, STATUS3_PHANTOM_FORCE, BattleScript_Return
	setsemiinvulnerablehelper BS_ATTACKER, 2
BattleScript_Return:
	return

BattleScript_Stealth_End3::
	call BattleScript_Stealth_Ret
	setsemiinvulnerablehelper BS_ATTACKER, 1
	end3

BattleScript_Grimtooth::
	call BattleScript_AbilityPopUp
	playmoveanimation BS_ATTACKER, MOVE_CAMOUFLAGE
	waitanimation
	printstring STRINGID_ABILITYGRIMTOOTH
	waitmessage B_WAIT_TIME_LONG
	end3

BattleScript_Camouflage::
	call BattleScript_AbilityPopUp
	playmoveanimation BS_ATTACKER, MOVE_CAMOUFLAGE
	waitanimation
	printstring STRINGID_PKMNCHANGEDTYPE
	waitmessage B_WAIT_TIME_LONG
	end3

BattleScript_AbyssalVoyager::
	call BattleScript_AbilityPopUp
	playmoveanimation BS_ATTACKER, MOVE_DIVE
	waitanimation
	printstring STRINGID_ABILITYDIVING
	waitmessage B_WAIT_TIME_LONG
	setbattlerstatus BS_ATTACKER, 3, STATUS3_UNDERWATER, BattleScript_End3
	setsemiinvulnerablehelper BS_ATTACKER, 1
BattleScript_End3:
	end3

BattleScript_LitteringAbsorbHazards::
	copybyte gBattlerAbility, gBattlerAttacker
	call BattleScript_AbilityPopUp
	printstring STRINGID_LITTERINGABSORB
	waitmessage B_WAIT_TIME_LONG
	statbuffchange MOVE_EFFECT_AFFECTS_ATTACKER | STAT_BUFF_NOT_PROTECT_AFFECTED | MOVE_EFFECT_CERTAIN, NULL
	setgraphicalstatchangevalues
	playanimation BS_ATTACKER, B_ANIM_STATS_CHANGE, sB_ANIM_ARG1
	waitanimation
	printstring STRINGID_LITTERINGSTATINCREASE
	waitmessage B_WAIT_TIME_LONG
	return

BattleScript_PickUpClearHazards::
	call BattleScript_AbilityPopUp
	printstring STRINGID_PICKUPHAZARDS
	waitmessage B_WAIT_TIME_LONG
	return

BattleScript_StickyWebOnSwitchIn::
	savetarget
	copybyte gBattlerTarget, sBATTLER
	printstring STRINGID_STICKYWEBSWITCHIN
	waitmessage B_WAIT_TIME_LONG
	statbuffchange STAT_CHANGE_ALLOW_PTR, BattleScript_StickyWebOnSwitchInEnd
	jumpifbyte CMP_LESS_THAN, cMULTISTRING_CHOOSER, B_MSG_STAT_WONT_DECREASE, BattleScript_StickyWebOnSwitchInStatAnim
	jumpifbyte CMP_EQUAL, cMULTISTRING_CHOOSER, B_MSG_STAT_FELL_EMPTY, BattleScript_StickyWebOnSwitchInEnd
	pause B_WAIT_TIME_SHORT
	goto BattleScript_StickyWebOnSwitchInPrintStatMsg
BattleScript_StickyWebOnSwitchInStatAnim:
	setgraphicalstatchangevalues
	playanimation BS_TARGET, B_ANIM_STATS_CHANGE, sB_ANIM_ARG1
BattleScript_StickyWebOnSwitchInPrintStatMsg:
	printfromtable gStatDownStringIds
	waitmessage B_WAIT_TIME_LONG
BattleScript_StickyWebOnSwitchInEnd:
	restoretarget
	return

BattleScript_PerishSongTakesLife::
	printstring STRINGID_PKMNPERISHCOUNTFELL
	waitmessage B_WAIT_TIME_LONG
	orword gHitMarker, HITMARKER_IGNORE_SUBSTITUTE | HITMARKER_PASSIVE_DAMAGE
	healthbarupdate BS_ATTACKER
	datahpupdate BS_ATTACKER
	tryfaintmon BS_ATTACKER, FALSE, NULL
	end2

BattleScript_PerishBodyActivates::
	call BattleScript_AbilityPopUp
	printstring STRINGID_PKMNSWILLPERISHIN3TURNS
	waitmessage B_WAIT_TIME_LONG
	orword gHitMarker, HITMARKER_IGNORE_SUBSTITUTE | HITMARKER_PASSIVE_DAMAGE
	return

BattleScript_GulpMissileGorging::
	call BattleScript_AbilityPopUp
	playanimation BS_ATTACKER, B_ANIM_GULP_MISSILE, NULL
	waitanimation
	orword gHitMarker, HITMARKER_IGNORE_SUBSTITUTE | HITMARKER_PASSIVE_DAMAGE
	effectivenesssound
	hitanimation BS_ATTACKER
	waitstate
	jumpifmagicguarded BS_ATTACKER, BattleScript_GulpMissileNoDmgGorging
	healthbarupdate BS_ATTACKER
	datahpupdate BS_ATTACKER
	tryfaintmon BS_ATTACKER, FALSE, NULL
	getbattlerfainted BS_ATTACKER
	jumpifbyte CMP_EQUAL, gBattleCommunication, TRUE, BattleScript_GulpMissileNoSecondEffectGorging
BattleScript_GulpMissileNoDmgGorging:
	handleformchange BS_TARGET, 0
	playanimation BS_TARGET, B_ANIM_FORM_CHANGE, NULL
	waitanimation
	swapattackerwithtarget
	setmoveeffect MOVE_EFFECT_PARALYSIS
	seteffectprimary
	swapattackerwithtarget
	return
BattleScript_GulpMissileNoSecondEffectGorging:
	handleformchange BS_TARGET, 0
	playanimation BS_TARGET, B_ANIM_FORM_CHANGE, NULL
	waitanimation
	return

BattleScript_GulpMissileGulping::
	call BattleScript_AbilityPopUp
	playanimation BS_ATTACKER, B_ANIM_GULP_MISSILE, NULL
	waitanimation
	orword gHitMarker, HITMARKER_IGNORE_SUBSTITUTE | HITMARKER_PASSIVE_DAMAGE
	effectivenesssound
	hitanimation BS_ATTACKER
	waitstate
	jumpifmagicguarded BS_ATTACKER, BattleScript_GulpMissileNoDmgGulping
	healthbarupdate BS_ATTACKER
	datahpupdate BS_ATTACKER
	tryfaintmon BS_ATTACKER, FALSE, NULL
	getbattlerfainted BS_ATTACKER
	jumpifbyte CMP_EQUAL, gBattleCommunication, TRUE, BattleScript_GulpMissileNoSecondEffectGulping
	jumpifabilitypreventedstatreduction BS_ATTACKER, STAT_DEF, BattleScript_GulpMissileNoSecondEffectGulping
	jumpifflowerveilattacker BattleScript_GulpMissileNoSecondEffectGulping
BattleScript_GulpMissileNoDmgGulping:
	handleformchange BS_TARGET, 0
	playanimation BS_TARGET, B_ANIM_FORM_CHANGE, NULL
	waitanimation
	swapattackerwithtarget @ to make gStatDownStringIds down below print the right battler
	setbyte sSTAT_ANIM_PLAYED, FALSE
	playstatchangeanimation BS_TARGET, BIT_DEF | BIT_SPDEF, STAT_CHANGE_NEGATIVE | STAT_CHANGE_MULTIPLE_STATS
	playstatchangeanimation BS_TARGET, BIT_DEF, STAT_CHANGE_NEGATIVE
	setstatchanger STAT_DEF, 1, TRUE
	statbuffchange STAT_BUFF_NOT_PROTECT_AFFECTED, BattleScript_GulpMissileGorgingTargetSpecialDefenseLower
	jumpifbyte CMP_EQUAL, cMULTISTRING_CHOOSER, B_MSG_STAT_WONT_DECREASE, BattleScript_GulpMissileGorgingTargetSpecialDefenseLower
	printfromtable gStatDownStringIds
	waitmessage B_WAIT_TIME_LONG
BattleScript_GulpMissileGorgingTargetSpecialDefenseLower:
	setstatchanger STAT_SPDEF, 1, TRUE
	statbuffchange STAT_BUFF_NOT_PROTECT_AFFECTED, BattleScript_GulpMissileGorgingReturn
	jumpifbyte CMP_EQUAL, cMULTISTRING_CHOOSER, B_MSG_STAT_WONT_DECREASE, BattleScript_GulpMissileGorgingReturn
	printfromtable gStatDownStringIds
	waitmessage B_WAIT_TIME_LONG
BattleScript_GulpMissileGorgingReturn:
	swapattackerwithtarget @ restore the battlers, just in case
	return

BattleScript_GulpMissileNoSecondEffectGulping:
	handleformchange BS_TARGET, 0
	playanimation BS_TARGET, B_ANIM_FORM_CHANGE, NULL
	waitanimation
	return

BattleScript_PerishSongCountGoesDown::
	printstring STRINGID_PKMNPERISHCOUNTFELL
	waitmessage B_WAIT_TIME_LONG
	end2

BattleScript_AllStatsUp::
	jumpifstat BS_ATTACKER, CMP_LESS_THAN, STAT_ATK, MAX_STAT_STAGE, BattleScript_AllStatsUpAtk
	jumpifstat BS_ATTACKER, CMP_LESS_THAN, STAT_DEF, MAX_STAT_STAGE, BattleScript_AllStatsUpAtk
	jumpifstat BS_ATTACKER, CMP_LESS_THAN, STAT_SPEED, MAX_STAT_STAGE, BattleScript_AllStatsUpAtk
	jumpifstat BS_ATTACKER, CMP_LESS_THAN, STAT_SPATK, MAX_STAT_STAGE, BattleScript_AllStatsUpAtk
	jumpifstat BS_ATTACKER, CMP_EQUAL, STAT_SPDEF, MAX_STAT_STAGE, BattleScript_AllStatsUpRet
BattleScript_AllStatsUpAtk::
	setbyte sSTAT_ANIM_PLAYED, FALSE
	playstatchangeanimation BS_ATTACKER, BIT_ATK | BIT_DEF | BIT_SPEED | BIT_SPATK | BIT_SPDEF, 0
	setstatchanger STAT_ATK, 1, FALSE
	statbuffchange MOVE_EFFECT_AFFECTS_ATTACKER | STAT_CHANGE_ALLOW_PTR, BattleScript_AllStatsUpDef
	printfromtable gStatUpStringIds
	waitmessage B_WAIT_TIME_LONG
BattleScript_AllStatsUpDef::
	setstatchanger STAT_DEF, 1, FALSE
	statbuffchange MOVE_EFFECT_AFFECTS_ATTACKER | STAT_CHANGE_ALLOW_PTR, BattleScript_AllStatsUpSpeed
	printfromtable gStatUpStringIds
	waitmessage B_WAIT_TIME_LONG
BattleScript_AllStatsUpSpeed::
	setstatchanger STAT_SPEED, 1, FALSE
	statbuffchange MOVE_EFFECT_AFFECTS_ATTACKER | STAT_CHANGE_ALLOW_PTR, BattleScript_AllStatsUpSpAtk
	printfromtable gStatUpStringIds
	waitmessage B_WAIT_TIME_LONG
BattleScript_AllStatsUpSpAtk::
	setstatchanger STAT_SPATK, 1, FALSE
	statbuffchange MOVE_EFFECT_AFFECTS_ATTACKER | STAT_CHANGE_ALLOW_PTR, BattleScript_AllStatsUpSpDef
	printfromtable gStatUpStringIds
	waitmessage B_WAIT_TIME_LONG
BattleScript_AllStatsUpSpDef::
	setstatchanger STAT_SPDEF, 1, FALSE
	statbuffchange MOVE_EFFECT_AFFECTS_ATTACKER | STAT_CHANGE_ALLOW_PTR, BattleScript_AllStatsUpRet
	printfromtable gStatUpStringIds
	waitmessage B_WAIT_TIME_LONG
BattleScript_AllStatsUpRet::
	return

BattleScript_AllStatsUpTwice::
	jumpifstat BS_ATTACKER, CMP_LESS_THAN, STAT_ATK, MAX_STAT_STAGE, BattleScript_AllStatsUpTwiceAtk
	jumpifstat BS_ATTACKER, CMP_LESS_THAN, STAT_DEF, MAX_STAT_STAGE, BattleScript_AllStatsUpTwiceAtk
	jumpifstat BS_ATTACKER, CMP_LESS_THAN, STAT_SPEED, MAX_STAT_STAGE, BattleScript_AllStatsUpTwiceAtk
	jumpifstat BS_ATTACKER, CMP_LESS_THAN, STAT_SPATK, MAX_STAT_STAGE, BattleScript_AllStatsUpTwiceAtk
	jumpifstat BS_ATTACKER, CMP_EQUAL, STAT_SPDEF, MAX_STAT_STAGE, BattleScript_AllStatsUpTwiceRet
BattleScript_AllStatsUpTwiceAtk::
	setbyte sSTAT_ANIM_PLAYED, FALSE
	playstatchangeanimation BS_ATTACKER, BIT_ATK | BIT_DEF | BIT_SPEED | BIT_SPATK | BIT_SPDEF, 0
	setstatchanger STAT_ATK, 2, FALSE
	statbuffchange MOVE_EFFECT_AFFECTS_ATTACKER | STAT_CHANGE_ALLOW_PTR, BattleScript_AllStatsUpTwiceDef
	printfromtable gStatUpStringIds
	waitmessage B_WAIT_TIME_LONG
BattleScript_AllStatsUpTwiceDef::
	setstatchanger STAT_DEF, 2, FALSE
	statbuffchange MOVE_EFFECT_AFFECTS_ATTACKER | STAT_CHANGE_ALLOW_PTR, BattleScript_AllStatsUpTwiceSpeed
	printfromtable gStatUpStringIds
	waitmessage B_WAIT_TIME_LONG
BattleScript_AllStatsUpTwiceSpeed::
	setstatchanger STAT_SPEED, 2, FALSE
	statbuffchange MOVE_EFFECT_AFFECTS_ATTACKER | STAT_CHANGE_ALLOW_PTR, BattleScript_AllStatsUpTwiceSpAtk
	printfromtable gStatUpStringIds
	waitmessage B_WAIT_TIME_LONG
BattleScript_AllStatsUpTwiceSpAtk::
	setstatchanger STAT_SPATK, 2, FALSE
	statbuffchange MOVE_EFFECT_AFFECTS_ATTACKER | STAT_CHANGE_ALLOW_PTR, BattleScript_AllStatsUpTwiceSpDef
	printfromtable gStatUpStringIds
	waitmessage B_WAIT_TIME_LONG
BattleScript_AllStatsUpTwiceSpDef::
	setstatchanger STAT_SPDEF, 2, FALSE
	statbuffchange MOVE_EFFECT_AFFECTS_ATTACKER | STAT_CHANGE_ALLOW_PTR, BattleScript_AllStatsUpTwiceRet
	printfromtable gStatUpStringIds
	waitmessage B_WAIT_TIME_LONG
BattleScript_AllStatsUpTwiceRet::
	return

BattleScript_RapidSpinAway::
	rapidspinfree
	return

BattleScript_WrapFree::
	printstring STRINGID_PKMNGOTFREE
	waitmessage B_WAIT_TIME_LONG
	copybyte gBattlerTarget, sBATTLER
	return

BattleScript_LeechSeedFree::
	printstring STRINGID_PKMNSHEDLEECHSEED
	waitmessage B_WAIT_TIME_LONG
	return

BattleScript_CordycepsFree::
	printstring STRINGID_PKMNSHEDCORDYCEPS
	waitmessage B_WAIT_TIME_LONG
	return

BattleScript_SpikesFree::
	printstring STRINGID_PKMNBLEWAWAYSPIKES
	waitmessage B_WAIT_TIME_LONG
	return

BattleScript_ToxicSpikesFree::
	printstring STRINGID_PKMNBLEWAWAYTOXICSPIKES
	waitmessage B_WAIT_TIME_LONG
	return

BattleScript_StickyWebFree::
	printstring STRINGID_PKMNBLEWAWAYSTICKYWEB
	waitmessage B_WAIT_TIME_LONG
	return

BattleScript_StealthRockFree::
	printstring STRINGID_PKMNBLEWAWAYSTEALTHROCK
	waitmessage B_WAIT_TIME_LONG
	return

BattleScript_MonTookFutureAttack::
	printstring STRINGID_PKMNTOOKATTACK
	waitmessage B_WAIT_TIME_LONG
	jumpifbyte CMP_EQUAL, cMULTISTRING_CHOOSER, B_MSG_DOOM_DESIRE, BattleScript_CheckDoomDesireMiss
	jumpifbyte CMP_EQUAL, cMULTISTRING_CHOOSER, B_MSG_FIRE_IN_THE_HOLE, BattleScript_CheckFireInTheHoleMiss
	accuracycheck BattleScript_FutureAttackMiss, MOVE_FUTURE_SIGHT
	goto BattleScript_FutureAttackAnimate
BattleScript_CheckFireInTheHoleMiss::
	accuracycheck BattleScript_FutureAttackMiss, MOVE_FIRE_IN_THE_HOLE
	setmoveeffect MOVE_EFFECT_BURN
	goto BattleScript_FutureAttackAnimate
BattleScript_CheckDoomDesireMiss::
	accuracycheck BattleScript_FutureAttackMiss, MOVE_DOOM_DESIRE
BattleScript_FutureAttackAnimate::
	critcalc
	damagecalc
	adjustdamage
	jumpifmovehadnoeffect BattleScript_DoFutureAttackResult
	jumpifbyte CMP_EQUAL, cMULTISTRING_CHOOSER, B_MSG_DOOM_DESIRE, BattleScript_FutureHitAnimDoomDesire
	jumpifbyte CMP_EQUAL, cMULTISTRING_CHOOSER, B_MSG_FAIRY_SINGULARITY, BattleScript_FutureHitAnimFairySingularity
	jumpifbyte CMP_EQUAL, cMULTISTRING_CHOOSER, B_MSG_FIRE_IN_THE_HOLE, BattleScript_FutureHitAnimFireInTheHole
	playanimation BS_ATTACKER, B_ANIM_FUTURE_SIGHT_HIT, NULL
	goto BattleScript_DoFutureAttackHit
BattleScript_FutureHitAnimFireInTheHole::
	playanimation BS_TARGET, B_ANIM_IRON_FIST_TECHNIQUE, NULL
	goto BattleScript_DoFutureAttackHit
BattleScript_FutureHitAnimFairySingularity::
	playanimation BS_ATTACKER, B_ANIM_FAIRY_SINGULARITY_HIT, NULL
	goto BattleScript_DoFutureAttackHit
BattleScript_FutureHitAnimDoomDesire::
	playanimation BS_ATTACKER, B_ANIM_DOOM_DESIRE_HIT, NULL
BattleScript_DoFutureAttackHit::
	effectivenesssound
	hitanimation BS_TARGET
	waitstate
	healthbarupdate BS_TARGET
	datahpupdate BS_TARGET
	critmessage
	waitmessage B_WAIT_TIME_LONG
BattleScript_DoFutureAttackResult:
	resultmessage
	waitmessage B_WAIT_TIME_LONG
	seteffectwithchance
	tryfaintmon BS_TARGET, FALSE, NULL
	atk24 BattleScript_FutureAttackEnd
BattleScript_FutureAttackEnd::
	moveendcase MOVEEND_RAGE
	moveendfromto MOVEEND_ITEM_EFFECTS_ALL_0, MOVEEND_UPDATE_LAST_MOVES
	setbyte gMoveResultFlags, 0
	end2
BattleScript_FutureAttackMiss::
	pause B_WAIT_TIME_SHORT
	sethword gMoveResultFlags, MOVE_RESULT_FAILED
	resultmessage
	waitmessage B_WAIT_TIME_LONG
	sethword gMoveResultFlags, 0
	end2

BattleScript_NoMovesLeft::
	printselectionstring STRINGID_PKMNHASNOMOVESLEFT
	endselectionscript

BattleScript_SelectingMoveWithNoPP::
	printselectionstring STRINGID_NOPPLEFT
	endselectionscript

BattleScript_NoPPForMove::
	attackstring
	pause B_WAIT_TIME_SHORT
	printstring STRINGID_BUTNOPPLEFT
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_SelectingMoveCannotBeUsedConsecutively::
	printselectionstring STRINGID_PKMNCANTUSEMOVECONSECUTIVELY
	endselectionscript

BattleScript_SelectingTormentedMove::
	printselectionstring STRINGID_PKMNCANTUSEMOVETORMENT
	endselectionscript

BattleScript_MoveUsedIsTormented::
	printstring STRINGID_PKMNCANTUSEMOVETORMENT
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_SelectingTormentedMoveInPalace::
	printstring STRINGID_PKMNCANTUSEMOVETORMENT
	goto BattleScript_SelectingUnusableMoveInPalace

BattleScript_SelectingNotAllowedMoveTaunt::
	printselectionstring STRINGID_PKMNCANTUSEMOVETAUNT
	endselectionscript

BattleScript_MoveUsedIsTaunted::
	printstring STRINGID_PKMNCANTUSEMOVETAUNT
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_SelectingNotAllowedMoveTauntInPalace::
	printstring STRINGID_PKMNCANTUSEMOVETAUNT
	goto BattleScript_SelectingUnusableMoveInPalace

BattleScript_SelectingNotAllowedMoveNeurotoxin::
	printselectionstring STRINGID_PKMNCANTUSEMOVENEUROTOXIN
	endselectionscript

BattleScript_MoveUsedIsNeurotoxinPrevented::
	printstring STRINGID_PKMNCANTUSEMOVENEUROTOXIN
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_NeurotoxinEndTurn::
	printstring STRINGID_NEUROTOXINENDS
	waitmessage B_WAIT_TIME_LONG
	end2

BattleScript_SelectingNotAllowedMoveThroatChop::
	printselectionstring STRINGID_PKMNCANTUSEMOVETHROATCHOP
	endselectionscript

BattleScript_MoveUsedIsThroatChopPrevented::
	printstring STRINGID_PKMNCANTUSEMOVETHROATCHOP
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_SelectingNotAllowedMoveThroatChopInPalace::
	printstring STRINGID_PKMNCANTUSEMOVETHROATCHOP
	goto BattleScript_SelectingUnusableMoveInPalace

BattleScript_ThroatChopEndTurn::
	printstring STRINGID_THROATCHOPENDS
	waitmessage B_WAIT_TIME_LONG
	end2
	
BattleScript_SlowStartEnds::
	pause 5
	copybyte gBattlerAbility, gBattlerAttacker
	call BattleScript_AbilityPopUp
	printstring STRINGID_SLOWSTARTEND
	waitmessage B_WAIT_TIME_LONG
	end2

BattleScript_SelectingNotAllowedMoveGravity::
	printselectionstring STRINGID_GRAVITYPREVENTSUSAGE
	endselectionscript

BattleScript_SelectingNotAllowedStuffCheeks::
	printselectionstring STRINGID_STUFFCHEEKSCANTSELECT
	endselectionscript

BattleScript_SelectingNotAllowedBelch::
	printselectionstring STRINGID_BELCHCANTSELECT
	endselectionscript

BattleScript_SelectingNotAllowedBelchInPalace::
	printstring STRINGID_BELCHCANTSELECT
	goto BattleScript_SelectingUnusableMoveInPalace

BattleScript_MoveUsedGravityPrevents::
	printstring STRINGID_GRAVITYPREVENTSUSAGE
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_SelectingNotAllowedMoveGravityInPalace::
	printstring STRINGID_GRAVITYPREVENTSUSAGE
	goto BattleScript_SelectingUnusableMoveInPalace

BattleScript_SelectingNotAllowedMoveHealBlock::
	printselectionstring STRINGID_HEALBLOCKPREVENTSUSAGE
	endselectionscript

BattleScript_MoveUsedHealBlockPrevents::
	printstring STRINGID_HEALBLOCKPREVENTSUSAGE
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_SelectingNotAllowedMoveHealBlockInPalace::
	printstring STRINGID_HEALBLOCKPREVENTSUSAGE
	goto BattleScript_SelectingUnusableMoveInPalace

BattleScript_WishComesTrue::
	trywish 1, BattleScript_WishButFullHp
	playanimation BS_TARGET, B_ANIM_WISH_HEAL, NULL
	printstring STRINGID_PKMNWISHCAMETRUE
	waitmessage B_WAIT_TIME_LONG
	orword gHitMarker, HITMARKER_IGNORE_SUBSTITUTE
	healthbarupdate BS_TARGET
	datahpupdate BS_TARGET
	printstring STRINGID_PKMNREGAINEDHEALTH
	waitmessage B_WAIT_TIME_LONG
	end2

BattleScript_WishButFullHp::
	printstring STRINGID_PKMNWISHCAMETRUE
	waitmessage B_WAIT_TIME_LONG
	pause B_WAIT_TIME_SHORT
	printstring STRINGID_PKMNHPFULL
	waitmessage B_WAIT_TIME_LONG
	end2

BattleScript_IngrainTurnHeal::
	playanimation BS_ATTACKER, B_ANIM_INGRAIN_HEAL, NULL
	printstring STRINGID_PKMNABSORBEDNUTRIENTS
BattleScript_TurnHeal:
	waitmessage B_WAIT_TIME_LONG
	orword gHitMarker, HITMARKER_IGNORE_SUBSTITUTE
	healthbarupdate BS_ATTACKER
	datahpupdate BS_ATTACKER
	updatestatusicon BS_ATTACKER
	end2

BattleScript_AquaRingHeal::
	playmoveanimation BS_ATTACKER, MOVE_AQUA_RING
	printstring STRINGID_AQUARINGHEAL
	goto BattleScript_TurnHeal

BattleScript_ForceHealingHeal::
	printstring STRINGID_BUFF1RESTOREHP
	goto BattleScript_TurnHeal

BattleScript_PrintMonIsRooted::
	pause B_WAIT_TIME_SHORT
	printstring STRINGID_PKMNANCHOREDITSELF
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_AtkDefDown::
	setbyte sSTAT_ANIM_PLAYED, FALSE
	playstatchangeanimation BS_ATTACKER, BIT_DEF | BIT_ATK, STAT_CHANGE_CANT_PREVENT | STAT_CHANGE_NEGATIVE | STAT_CHANGE_MULTIPLE_STATS
	playstatchangeanimation BS_ATTACKER, BIT_ATK, STAT_CHANGE_CANT_PREVENT | STAT_CHANGE_NEGATIVE
	setstatchanger STAT_ATK, 1, TRUE
	statbuffchange MOVE_EFFECT_AFFECTS_ATTACKER | MOVE_EFFECT_CERTAIN | STAT_CHANGE_ALLOW_PTR, BattleScript_AtkDefDownTryDef
	jumpifbyte CMP_EQUAL, cMULTISTRING_CHOOSER, B_MSG_STAT_WONT_DECREASE, BattleScript_AtkDefDownTryDef
	printfromtable gStatDownStringIds
	waitmessage B_WAIT_TIME_LONG
BattleScript_AtkDefDownTryDef:
	playstatchangeanimation BS_ATTACKER, BIT_DEF, STAT_CHANGE_CANT_PREVENT | STAT_CHANGE_NEGATIVE
	setstatchanger STAT_DEF, 1, TRUE
	statbuffchange MOVE_EFFECT_AFFECTS_ATTACKER | MOVE_EFFECT_CERTAIN | STAT_CHANGE_ALLOW_PTR, BattleScript_AtkDefDownRet
	jumpifbyte CMP_EQUAL, cMULTISTRING_CHOOSER, B_MSG_STAT_WONT_DECREASE, BattleScript_AtkDefDownRet
	printfromtable gStatDownStringIds
	waitmessage B_WAIT_TIME_LONG
BattleScript_AtkDefDownRet:
	return

BattleScript_DefSpDefDown::
	setbyte sSTAT_ANIM_PLAYED, FALSE
	playstatchangeanimation BS_ATTACKER, BIT_DEF | BIT_SPDEF, STAT_CHANGE_CANT_PREVENT | STAT_CHANGE_NEGATIVE | STAT_CHANGE_MULTIPLE_STATS
	playstatchangeanimation BS_ATTACKER, BIT_DEF, STAT_CHANGE_CANT_PREVENT | STAT_CHANGE_NEGATIVE
	setstatchanger STAT_DEF, 1, TRUE
	statbuffchange MOVE_EFFECT_AFFECTS_ATTACKER | MOVE_EFFECT_CERTAIN | STAT_CHANGE_ALLOW_PTR, BattleScript_DefSpDefDownTrySpDef
	jumpifbyte CMP_EQUAL, cMULTISTRING_CHOOSER, B_MSG_STAT_WONT_DECREASE, BattleScript_DefSpDefDownTrySpDef
	printfromtable gStatDownStringIds
	waitmessage B_WAIT_TIME_LONG
BattleScript_DefSpDefDownTrySpDef::
	playstatchangeanimation BS_ATTACKER, BIT_SPDEF, STAT_CHANGE_CANT_PREVENT | STAT_CHANGE_NEGATIVE
	setstatchanger STAT_SPDEF, 1, TRUE
	statbuffchange MOVE_EFFECT_AFFECTS_ATTACKER | MOVE_EFFECT_CERTAIN | STAT_CHANGE_ALLOW_PTR, BattleScript_DefSpDefDownRet
	jumpifbyte CMP_EQUAL, cMULTISTRING_CHOOSER, B_MSG_STAT_WONT_DECREASE, BattleScript_DefSpDefDownRet
	printfromtable gStatDownStringIds
	waitmessage B_WAIT_TIME_LONG
BattleScript_DefSpDefDownRet::
	return
	
BattleScript_DefDownSpeedUp::
	jumpifstat BS_ATTACKER, CMP_GREATER_THAN, STAT_DEF, MIN_STAT_STAGE, BattleScript_DefDownSpeedUpTryDef
	jumpifstat BS_ATTACKER, CMP_EQUAL, STAT_SPEED, MAX_STAT_STAGE, BattleScript_DefDownSpeedUpRet
BattleScript_DefDownSpeedUpTryDef::
	playstatchangeanimation BS_ATTACKER, BIT_DEF, STAT_CHANGE_NEGATIVE | STAT_CHANGE_CANT_PREVENT
	setstatchanger STAT_DEF, 1, TRUE
	statbuffchange MOVE_EFFECT_AFFECTS_ATTACKER | STAT_CHANGE_ALLOW_PTR | MOVE_EFFECT_CERTAIN, BattleScript_DefDownSpeedUpTrySpeed
	jumpifbyte CMP_EQUAL, cMULTISTRING_CHOOSER, B_MSG_STAT_WONT_INCREASE, BattleScript_DefDownSpeedUpTrySpeed
	printfromtable gStatUpStringIds
	waitmessage B_WAIT_TIME_LONG
BattleScript_DefDownSpeedUpTrySpeed:
	playstatchangeanimation BS_ATTACKER, BIT_SPEED, 0
	setstatchanger STAT_SPEED, 1, FALSE
	statbuffchange MOVE_EFFECT_AFFECTS_ATTACKER | STAT_CHANGE_ALLOW_PTR | MOVE_EFFECT_CERTAIN, BattleScript_DefDownSpeedUpRet
	jumpifbyte CMP_EQUAL, cMULTISTRING_CHOOSER, B_MSG_STAT_WONT_INCREASE, BattleScript_DefDownSpeedUpRet
	printfromtable gStatUpStringIds
	waitmessage B_WAIT_TIME_LONG
BattleScript_DefDownSpeedUpRet::
	return

BattleScript_KnockedOff::
	playanimation BS_TARGET, B_ANIM_ITEM_KNOCKOFF, NULL
	printstring STRINGID_PKMNKNOCKEDOFF
	waitmessage B_WAIT_TIME_LONG
	return

BattleScript_MoveUsedIsImprisoned::
	printstring STRINGID_PKMNCANTUSEMOVESEALED
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_SelectingImprisonedMove::
	printselectionstring STRINGID_PKMNCANTUSEMOVESEALED
	endselectionscript

BattleScript_SelectingImprisonedMoveInPalace::
	printstring STRINGID_PKMNCANTUSEMOVESEALED
	goto BattleScript_SelectingUnusableMoveInPalace

BattleScript_GrudgeTakesPp::
	printstring STRINGID_PKMNLOSTPPGRUDGE
	waitmessage B_WAIT_TIME_LONG
	return

BattleScript_MagicCoatBounce::
	attackstring
	ppreduce
	pause B_WAIT_TIME_SHORT
	jumpifbyte CMP_EQUAL, cMULTISTRING_CHOOSER, 0, BattleScript_MagicCoatBounce_Print
	call BattleScript_AbilityPopUp
BattleScript_MagicCoatBounce_Print:
	printfromtable gMagicCoatBounceStringIds
	waitmessage B_WAIT_TIME_LONG
	orword gHitMarker, HITMARKER_ATTACKSTRING_PRINTED | HITMARKER_NO_PPDEDUCT | HITMARKER_x800000
	setmagiccoattarget BS_ATTACKER
	return

BattleScript_MagicCoatBouncePrankster::
	attackstring
	ppreduce
	pause B_WAIT_TIME_SHORT
	printfromtable gMagicCoatBounceStringIds
	waitmessage B_WAIT_TIME_LONG
	printstring STRINGID_ITDOESNTAFFECT
	waitmessage B_WAIT_TIME_LONG
	orhalfword gMoveResultFlags, MOVE_RESULT_NO_EFFECT
	goto BattleScript_MoveEnd
	
BattleScript_SnatchedMove::
	attackstring
	ppreduce
	snatchsetbattlers
	playanimation BS_TARGET, B_ANIM_SNATCH_MOVE, NULL
	printstring STRINGID_PKMNSNATCHEDMOVE
	waitmessage B_WAIT_TIME_LONG
	orword gHitMarker, HITMARKER_ATTACKSTRING_PRINTED | HITMARKER_NO_PPDEDUCT | HITMARKER_x800000
	swapattackerwithtarget
	return

BattleScript_EnduredMsg::
	printstring STRINGID_PKMNENDUREDHIT
	waitmessage B_WAIT_TIME_LONG
	return

BattleScript_SturdiedMsg::
	copybyte gBattlerAbility, gBattlerTarget
	pause B_WAIT_TIME_SHORTEST
	call BattleScript_AbilityPopUp
	printstring STRINGID_ENDUREDSTURDY
	waitmessage B_WAIT_TIME_LONG
	return

BattleScript_ShededSkinMsg::
	copybyte gBattlerAbility, gBattlerTarget
	pause B_WAIT_TIME_SHORTEST
	call BattleScript_AbilityPopUp
	printstring STRINGID_ENDUREDSHEDSKIN
	waitmessage B_WAIT_TIME_LONG
	updatestatusicon BS_TARGET
	return

BattleScript_ShockAbsortionMsg::
	copybyte gBattlerAbility, gBattlerTarget
	pause B_WAIT_TIME_SHORTEST
	call BattleScript_AbilityPopUp
	printstring STRINGID_SHOCK_ABSORTION
	waitmessage B_WAIT_TIME_LONG
	return

BattleScript_DefensiveManeuverMsg::
	copybyte gBattlerAbility, gBattlerTarget
	pause B_WAIT_TIME_SHORTEST
	call BattleScript_AbilityPopUp
	printstring STRINGID_DEFENSIVE_MANEUVER
	waitmessage B_WAIT_TIME_LONG
	return

BattleScript_ExoskeletonMsg::
	copybyte gBattlerAbility, gBattlerTarget
	pause B_WAIT_TIME_SHORTEST
	call BattleScript_AbilityPopUp
	printstring STRINGID_EXOSKELETON
	waitmessage B_WAIT_TIME_LONG
	return

BattleScript_BlademasterMsg::
	copybyte gBattlerAbility, gBattlerTarget
	pause B_WAIT_TIME_SHORTEST
	call BattleScript_AbilityPopUp
	printstring STRINGID_BLADEMASTER_PARRY
	waitmessage B_WAIT_TIME_LONG
	return

BattleScript_PeekABooMsg::
	copybyte gBattlerAbility, gBattlerTarget
	pause B_WAIT_TIME_SHORTEST
	call BattleScript_AbilityPopUp
	printstring STRINGID_PEEK_A_BOO_GUARD
	waitmessage B_WAIT_TIME_LONG
	return

BattleScript_OneHitKOMsg::
	printstring STRINGID_ONEHITKO
	waitmessage B_WAIT_TIME_LONG
	return

BattleScript_SAtkDown2::
	setbyte sSTAT_ANIM_PLAYED, FALSE
	playstatchangeanimation BS_ATTACKER, BIT_SPATK, STAT_CHANGE_CANT_PREVENT | STAT_CHANGE_NEGATIVE | STAT_CHANGE_BY_TWO
	setstatchanger STAT_SPATK, 2, TRUE
	statbuffchange MOVE_EFFECT_AFFECTS_ATTACKER | MOVE_EFFECT_CERTAIN | STAT_CHANGE_ALLOW_PTR, BattleScript_SAtkDown2End
	jumpifbyte CMP_EQUAL, cMULTISTRING_CHOOSER, B_MSG_STAT_WONT_DECREASE, BattleScript_SAtkDown2End
	printfromtable gStatDownStringIds
	waitmessage B_WAIT_TIME_LONG
BattleScript_SAtkDown2End::
	return

BattleScript_OrderUpStatIncrease::
	statbuffchange MOVE_EFFECT_AFFECTS_ATTACKER | STAT_BUFF_NOT_PROTECT_AFFECTED | MOVE_EFFECT_CERTAIN, NULL
	setgraphicalstatchangevalues
	playanimation BS_ATTACKER, B_ANIM_STATS_CHANGE, sB_ANIM_ARG1
	waitanimation
	printfromtable gStatUpStringIds
	waitmessage B_WAIT_TIME_LONG
	return

BattleScript_MoveEffectClearSmog::
	printstring STRINGID_RESETSTARGETSSTATLEVELS
	waitmessage B_WAIT_TIME_LONG
	return

BattleScript_MegaEvolution::
	printstring STRINGID_MEGAEVOREACTING
	waitmessage B_WAIT_TIME_LONG
	setbyte gIsCriticalHit, 0
	handlemegaevo BS_ATTACKER, 0
	handlemegaevo BS_ATTACKER, 1
	playanimation BS_ATTACKER, B_ANIM_MEGA_EVOLUTION, NULL
	waitanimation
	handlemegaevo BS_ATTACKER, 2
	printstring STRINGID_MEGAEVOEVOLVED
	waitmessage B_WAIT_TIME_LONG
	switchinabilities BS_ATTACKER
	end2

BattleScript_WishMegaEvolution::
	printstring STRINGID_FERVENTWISHREACHED
	waitmessage B_WAIT_TIME_LONG
	setbyte gIsCriticalHit, 0
	handlemegaevo BS_ATTACKER, 0
	handlemegaevo BS_ATTACKER, 1
	playanimation BS_ATTACKER, B_ANIM_MEGA_EVOLUTION, NULL
	waitanimation
	handlemegaevo BS_ATTACKER, 2
	printstring STRINGID_MEGAEVOEVOLVED
	waitmessage B_WAIT_TIME_LONG
	switchinabilities BS_ATTACKER
	end2

BattleScript_PrimalReversion::
	printstring STRINGID_EMPTYSTRING3
	waitmessage 1
	setbyte gIsCriticalHit, 0
	handleprimalreversion BS_ATTACKER, 0
	handleprimalreversion BS_ATTACKER, 1
	playanimation BS_ATTACKER, B_ANIM_PRIMAL_REVERSION, NULL
	waitanimation
	handleprimalreversion BS_ATTACKER, 2
	printstring STRINGID_PKMNREVERTEDTOPRIMAL
	waitmessage B_WAIT_TIME_LONG
	switchinabilities BS_ATTACKER
	end2

BattleScript_PrimalReversionRet::
	printstring STRINGID_EMPTYSTRING3
	waitmessage 1
	setbyte gIsCriticalHit, 0
	handleprimalreversion BS_ATTACKER, 0
	handleprimalreversion BS_ATTACKER, 1
	playanimation BS_ATTACKER, B_ANIM_PRIMAL_REVERSION, NULL
	waitanimation
	handleprimalreversion BS_ATTACKER, 2
	printstring STRINGID_PKMNREVERTEDTOPRIMAL
	waitmessage B_WAIT_TIME_LONG
	return

BattleScript_DeoxysFormChangeWhileAttacking::
	pause 5
	printstring STRINGID_EMPTYSTRING3
	waitmessage 1
	handleformchange BS_ATTACKER, 0
	handleformchange BS_ATTACKER, 1
	playanimation BS_ATTACKER, B_ANIM_FORM_CHANGE, NULL
	waitanimation
	handleformchange BS_ATTACKER, 2 
	printfromtable gDeoxysFormChangeStringIds
	waitmessage 1
	return

BattleScript_DeoxysFormChangeWhileDefending::
	pause 5
	printstring STRINGID_EMPTYSTRING3
	waitmessage 1
	handleformchange BS_TARGET, 0
	handleformchange BS_TARGET, 1
	playanimation BS_TARGET, B_ANIM_FORM_CHANGE, NULL
	waitanimation
	handleformchange BS_TARGET, 2 
	printfromtable gDeoxysFormChangeStringIds
	waitmessage 1
	return

BattleScript_AttackerFormChangeReturn::
	pause 5
	copybyte gBattlerAbility, gBattlerAttacker
	call BattleScript_AbilityPopUp
	printstring STRINGID_EMPTYSTRING3
	waitmessage 1
	handleformchange BS_ATTACKER, 0
	handleformchange BS_ATTACKER, 1
	playanimation BS_ATTACKER, B_ANIM_FORM_CHANGE, NULL
	waitanimation
	handleformchange BS_ATTACKER, 2
	trystockingprey 0
	trystockingprey 1
	trystockingprey 2
	trystockingprey 3
	return

BattleScript_DefenderFormChangeReturn::
	pause 5
	copybyte gBattlerAbility, gBattlerTarget
	call BattleScript_AbilityPopUp
	printstring STRINGID_EMPTYSTRING3
	waitmessage 1
	handleformchange BS_TARGET, 0
	handleformchange BS_TARGET, 1
	playanimation BS_TARGET, B_ANIM_FORM_CHANGE, NULL
	waitanimation
	handleformchange BS_TARGET, 2 
	return

BattleScript_MorpekoEatBerrySeed::
	pause 5
	copybyte gBattlerAbility, gBattlerAttacker
	call BattleScript_AbilityPopUp
	playanimation BS_ATTACKER, B_ANIM_HELD_ITEM_EFFECT, NULL
	printstring STRINGID_MORPEKOEATBERRYSEED
	waitmessage B_WAIT_TIME_LONG	
	orword gHitMarker, HITMARKER_SKIP_DMG_TRACK | HITMARKER_IGNORE_SUBSTITUTE | HITMARKER_PASSIVE_DAMAGE
	healthbarupdate BS_ATTACKER
	datahpupdate BS_ATTACKER
	handleformchange BS_ATTACKER, 0
	handleformchange BS_ATTACKER, 1
	playanimation BS_ATTACKER, B_ANIM_FORM_CHANGE, NULL
	waitanimation
	handleformchange BS_ATTACKER, 2 
	end3

BattleScript_HoOhBurstOfFlames::
	pause 5
	copybyte gBattlerAbility, gBattlerAttacker
	call BattleScript_AbilityPopUp
	printstring STRINGID_EMPTYSTRING3
	waitmessage 1
	handleformchange BS_ATTACKER, 0
	handleformchange BS_ATTACKER, 1
	playanimation BS_ATTACKER, B_ANIM_FORM_CHANGE, NULL
	waitanimation
	handleformchange BS_ATTACKER, 2
	playanimation BS_ATTACKER, B_ANIM_BURST_OF_FLAMES, NULL
	waitanimation
	printstring STRINGID_SKY_GUARDIAN_BURST
	waitmessage B_WAIT_TIME_LONG
	tryskyguardianburst
	end3

BattleScript_AttackerFormChangeEnd3::
	call BattleScript_AttackerFormChangeReturn
	end3

BattleScript_AttackerFormChangeMoveEffect::
	waitmessage 1
	handleformchange BS_ATTACKER, 0
	handleformchange BS_ATTACKER, 1
	playanimation BS_ATTACKER, B_ANIM_FORM_CHANGE, NULL
	waitanimation
	copybyte sBATTLER, gBattlerAttacker
	printstring STRINGID_PKMNTRANSFORMED
	waitmessage B_WAIT_TIME_LONG
	handleformchange BS_ATTACKER, 2
	end3

BattleScript_BallFetch::
	call BattleScript_AbilityPopUp
	printstring STRINGID_FETCHEDPOKEBALL
	waitmessage B_WAIT_TIME_LONG
	end3

BattleScript_CudChewActivates::
	pause B_WAIT_TIME_SHORTEST
	call BattleScript_AbilityPopUp
	setbyte sBERRY_OVERRIDE, TRUE @ override the requirements for eating berries
	consumeberry BS_TARGET, FALSE
	orword gHitMarker, HITMARKER_SKIP_DMG_TRACK | HITMARKER_IGNORE_SUBSTITUTE | HITMARKER_PASSIVE_DAMAGE
	healthbarupdate BS_ATTACKER
	datahpupdate BS_ATTACKER
	setbyte sBERRY_OVERRIDE, FALSE
	end3

BattleScript_AbilityChangedTypeBeforeHit::
	copybyte gBattlerAbility, gBattlerTarget
	call BattleScript_AbilityPopUp
	printstring STRINGID_CHANGED_TYPE
	waitmessage B_WAIT_TIME_LONG
	return

BattleScript_TargetFormChange::
	pause 5
	copybyte gBattlerAbility, gBattlerTarget
	call BattleScript_AbilityPopUp
	printstring STRINGID_EMPTYSTRING3
	waitmessage 1
	handleformchange BS_TARGET, 0
	handleformchange BS_TARGET, 1
	playanimation BS_TARGET, B_ANIM_FORM_CHANGE, NULL
	waitanimation
	handleformchange BS_TARGET, 2 
	return

BattleScript_IllusionOff::
	spriteignore0hp TRUE
	playanimation BS_TARGET, B_ANIM_ILLUSION_OFF, NULL
	waitanimation
	updatenick BS_TARGET
	waitstate
	spriteignore0hp FALSE
	printstring STRINGID_ILLUSIONWOREOFF
	waitmessage B_WAIT_TIME_LONG
	return

BattleScript_CottonDownActivates::
	setbyte sFIXED_ABILITY_POPUP, TRUE
	call BattleScript_AbilityPopUp
	copybyte gEffectBattler, gBattlerTarget
	saveattacker
	savetarget
	swapattackerwithtarget
	setbyte gBattlerTarget, 0
BattleScript_CottonDownLoop:
	getbattlerfainted BS_TARGET
	jumpifbyte CMP_EQUAL, gBattleCommunication, TRUE, BattleScript_CottonDownLoopIncrement
	setstatchanger STAT_SPEED, 1, TRUE
	jumpifbyteequal gBattlerTarget, gEffectBattler, BattleScript_CottonDownLoopIncrement
	statbuffchange STAT_BUFF_NOT_PROTECT_AFFECTED, BattleScript_CottonDownTargetSpeedCantGoLower
	setgraphicalstatchangevalues
	playanimation BS_TARGET, B_ANIM_STATS_CHANGE, sB_ANIM_ARG1
	printfromtable gStatDownStringIds
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_CottonDownLoopIncrement
BattleScript_CottonDownTargetSpeedCantGoLower:
	printstring STRINGID_STATSWONTDECREASE
	waitmessage B_WAIT_TIME_LONG
BattleScript_CottonDownLoopIncrement:
	addbyte gBattlerTarget, 1
	jumpifbytenotequal gBattlerTarget, gBattlersCount, BattleScript_CottonDownLoop
BattleScript_CottonDownReturn:
	restoreattacker
	restoretarget
	destroyabilitypopup
	return

BattleScript_AnticipationActivates::
	pause 5
	call BattleScript_AbilityPopUp
	printstring STRINGID_ANTICIPATIONACTIVATES
	waitmessage B_WAIT_TIME_LONG
	return

BattleScript_InnardsOutDmg:: 
	pause B_WAIT_TIME_SHORT
	call BattleScript_AbilityPopUp
	orword gHitMarker, HITMARKER_IGNORE_SUBSTITUTE | HITMARKER_PASSIVE_DAMAGE
	healthbarupdate BS_ATTACKER
	datahpupdate BS_ATTACKER
	printstring STRINGID_AFTERMATHDMG
	waitmessage B_WAIT_TIME_LONG
	tryfaintmon BS_ATTACKER, FALSE, NULL
	return

BattleScript_LoosingQuillsToxicSpikes::
	call BattleScript_AbilityPopUp
	playanimation BS_TARGET, B_ANIM_LOOSING_QUILLS_TOXIC, NULL
	printstring STRINGID_POISONSPIKESSCATTERED
	waitmessage B_WAIT_TIME_LONG
	waitanimation
	return

BattleScript_LoosingQuillsSpikes::
	call BattleScript_AbilityPopUp
	playanimation BS_TARGET, B_ANIM_LOOSING_QUILLS_SPIKES, NULL
	printstring STRINGID_SPIKESSCATTERED
	waitmessage B_WAIT_TIME_LONG
	waitanimation
	return

BattleScript_WatchdogCounterBite::
	swapattackerwithtarget
	call BattleScript_AbilityPopUp
	playmoveanimation BS_TARGET, MOVE_BITE
	customdamagecalculation MOVE_BITE, TYPE_DARK, 25, FALSE, FALSE
	orword gHitMarker, HITMARKER_IGNORE_SUBSTITUTE | HITMARKER_PASSIVE_DAMAGE
	hitanimation BS_TARGET
	healthbarupdate BS_TARGET
	datahpupdate BS_TARGET
	printstring STRINGID_WATCHDOG_BITE
	waitmessage B_WAIT_TIME_LONG
	tryfaintmon BS_TARGET, FALSE, NULL
	swapattackerwithtarget
BattleScript_WatchdogReturn:
	restoretarget
	return

BattleScript_BlademasterCounter::
	swapattackerwithtarget
	call BattleScript_AbilityPopUp
	playmoveanimation BS_TARGET, MOVE_CUT
	customdamagecalculation MOVE_SLASH, TYPE_NORMAL, 25, FALSE, FALSE
	orword gHitMarker, HITMARKER_IGNORE_SUBSTITUTE | HITMARKER_PASSIVE_DAMAGE
	hitanimation BS_TARGET
	healthbarupdate BS_TARGET
	datahpupdate BS_TARGET
	printstring STRINGID_BLADEMASTER_SWIFT_SLASH
	waitmessage B_WAIT_TIME_LONG
	tryfaintmon BS_TARGET, FALSE, NULL
	swapattackerwithtarget
BattleScript_BlademasterReturn:
	return

BattleScript_PeekABooStrikesBack::
	swapattackerwithtarget
	call BattleScript_AbilityPopUp
	playmoveanimation BS_TARGET, MOVE_MACH_PUNCH
	customdamagecalculation MOVE_MACH_PUNCH, TYPE_FIGHTING, 25, FALSE, FALSE
	orword gHitMarker, HITMARKER_IGNORE_SUBSTITUTE | HITMARKER_PASSIVE_DAMAGE
	hitanimation BS_TARGET
	healthbarupdate BS_TARGET
	datahpupdate BS_TARGET
	printstring STRINGID_PEEK_A_BOO_STRIKES_BACK
	waitmessage B_WAIT_TIME_LONG
	tryfaintmon BS_TARGET, FALSE, NULL
	swapattackerwithtarget
BattleScript_PeekABooReturn:
	return

BattleScript_MuscleGaugeActivates::
	call BattleScript_AbilityPopUp
	printstring STRINGID_MUSCLE_GAUGE_ACTIVATES
	waitmessage B_WAIT_TIME_LONG
	return
BattleScript_MuscleGaugeCounters::
	call BattleScript_AbilityPopUp
	printstring STRINGID_MUSCLE_GAUGE_COUNTERS
	waitmessage B_WAIT_TIME_LONG
	return

BattleScript_RedHotChiliPeppersActivates::
	customdamagecalculation MOVE_LEAFAGE, TYPE_GRASS, 40, FALSE, FALSE
	call BattleScript_AbilityPopUp
	orword gHitMarker, HITMARKER_PASSIVE_DAMAGE
	hitanimation BS_TARGET
	healthbarupdate BS_TARGET
	datahpupdate BS_TARGET
	tryfaintmon BS_TARGET, FALSE, NULL
	return

BattleScript_AftershockActivates::
	customdamagecalculation MOVE_SONIC_BOOM, TYPE_FLYING, 0xFFFF, FALSE, FALSE
	call BattleScript_AbilityPopUp
	playmoveanimation BS_TARGET, MOVE_SONIC_BOOM
	orword gHitMarker, HITMARKER_IGNORE_SUBSTITUTE | HITMARKER_PASSIVE_DAMAGE
	hitanimation BS_TARGET
	healthbarupdate BS_TARGET
	datahpupdate BS_TARGET
	printstring STRINGID_EMIT_SHOCKWAVE
	waitmessage B_WAIT_TIME_LONG
	tryfaintmon BS_TARGET, FALSE, NULL
	return

BattleScript_AftermathDmgSelfDestruct::
	setbyte sFIXED_ABILITY_POPUP, TRUE
	call BattleScript_AbilityPopUp
	playanimation BS_TARGET, B_ANIM_AFTERMATH, NULL
	copybyte gEffectBattler, gBattlerTarget
	savetarget
	setbyte gBattlerTarget, 0
BattleScript_AftermathLoop:
	getbattlerfainted BS_TARGET
	jumpifbyte CMP_EQUAL, gBattleCommunication, TRUE, BattleScript_AftermathLoopIncrement
	jumpifbyteequal gBattlerTarget, gEffectBattler, BattleScript_AftermathLoopIncrement
	getAftermathDMG BattleScript_AftermathLoopIncrement
	orword gHitMarker, HITMARKER_IGNORE_SUBSTITUTE | HITMARKER_PASSIVE_DAMAGE
	hitanimation BS_TARGET
	healthbarupdate BS_TARGET
	datahpupdate BS_TARGET
	printstring STRINGID_AFTERMATHDMGSELFDESTRUCT
	waitmessage B_WAIT_TIME_LONG
	tryfaintmon BS_TARGET, FALSE, NULL
BattleScript_AftermathLoopIncrement:
	addbyte gBattlerTarget, 1
	jumpifbytenotequal gBattlerTarget, gBattlersCount, BattleScript_AftermathLoop
BattleScript_AftermathReturn:
	restoretarget
	destroyabilitypopup
	return

BattleScript_MoveUsedIsAsleep::
	printstring STRINGID_PKMNFASTASLEEP
	waitmessage B_WAIT_TIME_LONG
	statusanimation BS_ATTACKER
	goto BattleScript_MoveEnd

BattleScript_MoveUsedIsHibernating::
	printstring STRINGID_PKMNFASTASLEEP
	waitmessage B_WAIT_TIME_LONG
	statusanimation BS_ATTACKER	
	call BattleScript_AbilityHpHeal
	goto BattleScript_MoveEnd

BattleScript_MoveUsedWokeUp::
	bicword gHitMarker, HITMARKER_x10
	printfromtable gWokeUpStringIds
	waitmessage B_WAIT_TIME_LONG
	updatestatusicon BS_ATTACKER
	return

BattleScript_MoveUsedWokeUpWithEarlyBird::
	bicword gHitMarker, HITMARKER_x10
	printfromtable gWokeUpStringIds
	waitmessage B_WAIT_TIME_LONG
	updatestatusicon BS_ATTACKER
	setstatchanger STAT_SPEED, 1, FALSE
	statbuffchange MOVE_EFFECT_AFFECTS_ATTACKER | STAT_CHANGE_ALLOW_PTR, BattleScript_MoveUsedWokeUpWithEarlyBirdEnd
	jumpifbyte CMP_EQUAL, cMULTISTRING_CHOOSER, B_MSG_STAT_WONT_INCREASE, BattleScript_MoveUsedWokeUpWithEarlyBirdEnd
	copybyte gBattlerAbility, gBattlerAttacker
	sethword sABILITY_OVERWRITE, ABILITY_EARLY_BIRD
	call BattleScript_AbilityPopUp
	setgraphicalstatchangevalues
	playanimation BS_ATTACKER, B_ANIM_STATS_CHANGE, sB_ANIM_ARG1
	printfromtable gStatUpStringIds
	waitmessage B_WAIT_TIME_LONG
BattleScript_MoveUsedWokeUpWithEarlyBirdEnd:
	return

BattleScript_MoveUsedIsHibernatingRet::
	printstring STRINGID_PKMNFASTASLEEP
	waitmessage B_WAIT_TIME_LONG
	statusanimation BS_ATTACKER	
	call BattleScript_AbilityHpHeal
	return

BattleScript_MonWokeUpInUproar::
	printstring STRINGID_PKMNWOKEUPINUPROAR
	waitmessage B_WAIT_TIME_LONG
	updatestatusicon BS_ATTACKER
	end2

BattleScript_PoisonTurnDmg::
	printstring STRINGID_PKMNHURTBYPOISON
	waitmessage B_WAIT_TIME_LONG
BattleScript_DoStatusTurnDmg::
	statusanimation BS_ATTACKER
BattleScript_DoTurnDmg:
	orword gHitMarker, HITMARKER_IGNORE_SUBSTITUTE | HITMARKER_PASSIVE_DAMAGE
	healthbarupdate BS_ATTACKER
	datahpupdate BS_ATTACKER
	tryfaintmon BS_ATTACKER, FALSE, NULL
	atk24 BattleScript_DoTurnDmgEnd
BattleScript_DoTurnDmgEnd:
	end2

BattleScript_PoisonHealActivates::
	copybyte gBattlerAbility, gBattlerAttacker
	call BattleScript_AbilityPopUp
	printstring STRINGID_POISONHEALHPUP
	waitmessage B_WAIT_TIME_LONG
	recordability BS_ATTACKER
	statusanimation BS_ATTACKER
	orword gHitMarker, HITMARKER_IGNORE_SUBSTITUTE | HITMARKER_PASSIVE_DAMAGE
	healthbarupdate BS_ATTACKER
	datahpupdate BS_ATTACKER
	end2

BattleScript_BurnTurnDmg::
	printstring STRINGID_PKMNHURTBYBURN
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_DoStatusTurnDmg

BattleScript_FrostbiteTurnDmg::
	printstring STRINGID_PKMNHURTBYFROSTBITE
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_DoStatusTurnDmg

BattleScript_MoveUsedIsFrozen::
	printstring STRINGID_PKMNISFROZEN
	waitmessage B_WAIT_TIME_LONG
	statusanimation BS_ATTACKER
	goto BattleScript_MoveEnd

BattleScript_MoveUsedUnfroze::
	printfromtable gGotDefrostedStringIds
	waitmessage B_WAIT_TIME_LONG
	updatestatusicon BS_ATTACKER
	return

BattleScript_DefrostedViaFireMove::
	printstring STRINGID_PKMNWASDEFROSTED
	waitmessage B_WAIT_TIME_LONG
	updatestatusicon BS_TARGET
	return

BattleScript_MoveUsedIsParalyzed::
	printstring STRINGID_PKMNISPARALYZED
	waitmessage B_WAIT_TIME_LONG
	statusanimation BS_ATTACKER
	cancelmultiturnmoves BS_ATTACKER
	goto BattleScript_MoveEnd

BattleScript_PowderMoveNoEffect::
	attackstring
	ppreduce
	pause B_WAIT_TIME_SHORT
	jumpiftype BS_TARGET, TYPE_GRASS, BattleScript_PowderMoveNoEffectPrint
	jumpifabilityorinnate BS_TARGET, ABILITY_OVERCOAT, BattleScript_PowderMoveNoEffectInnateOvercoat
	printstring STRINGID_SAFETYGOGGLESPROTECTED
	goto BattleScript_PowderMoveNoEffectWaitMsg
BattleScript_PowderMoveNoEffectOvercoat:
	call BattleScript_AbilityPopUp
BattleScript_PowderMoveNoEffectPrint:
	printstring STRINGID_ITDOESNTAFFECT
BattleScript_PowderMoveNoEffectWaitMsg:
	waitmessage B_WAIT_TIME_LONG
	cancelmultiturnmoves BS_ATTACKER
	sethword gMoveResultFlags, MOVE_RESULT_FAILED
	goto BattleScript_MoveEnd

BattleScript_PowderMoveNoEffectInnateOvercoat:
	copybyte gBattlerAbility, gBattlerTarget
	sethword sABILITY_OVERWRITE, ABILITY_OVERCOAT
	goto BattleScript_PowderMoveNoEffectOvercoat

BattleScript_MoveUsedDevolvedForgot::
	printstring STRINGID_POKEMONFORGOTMOVE
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_MoveUsedFlinched::
	printstring STRINGID_PKMNFLINCHED
	waitmessage B_WAIT_TIME_LONG
	jumpifabilityorinnate BS_ATTACKER ABILITY_STEADFAST BattleScript_TryActivateSteadFast
BattleScript_MoveUsedFlinchedEnd:
	goto BattleScript_MoveEnd
BattleScript_TryActivateSteadFast:
	setstatchanger STAT_SPEED, 1, FALSE
	statbuffchange MOVE_EFFECT_AFFECTS_ATTACKER | STAT_CHANGE_ALLOW_PTR, BattleScript_MoveUsedFlinchedEnd
	jumpifbyte CMP_EQUAL, cMULTISTRING_CHOOSER, B_MSG_STAT_WONT_INCREASE, BattleScript_MoveUsedFlinchedEnd
	copybyte gBattlerAbility, gBattlerAttacker
	call BattleScript_AbilityPopUp
	setgraphicalstatchangevalues
	playanimation BS_ATTACKER, B_ANIM_STATS_CHANGE, sB_ANIM_ARG1
	setbyte gBattleCommunication STAT_SPEED
	stattextbuffer BS_ATTACKER
	printstring STRINGID_ATTACKERABILITYSTATRAISE
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveUsedFlinchedEnd

BattleScript_PrintUproarOverTurns::
	printfromtable gUproarOverTurnStringIds
	waitmessage B_WAIT_TIME_LONG
	end2

BattleScript_ThrashConfuses::
	chosenstatus2animation BS_ATTACKER, STATUS2_CONFUSION
	printstring STRINGID_PKMNFATIGUECONFUSION
	waitmessage B_WAIT_TIME_LONG
	end2

BattleScript_AttackedPartnerDueCordyceps::
	cancelmultiturnmoves BS_ATTACKER
	adjustdamage
	printstring STRINGID_ALLY_BITE
	waitmessage B_WAIT_TIME_LONG
	effectivenesssound
	playmoveanimation BS_TARGET, MOVE_BITE
	orword gHitMarker, HITMARKER_PASSIVE_DAMAGE
	healthbarupdate BS_TARGET
	datahpupdate BS_TARGET
	setcordycepsbypartner
	jumpifbyte CMP_NOT_EQUAL, cMULTISTRING_CHOOSER, B_MSG_CORDYCEPS_SET, BattleScript_AttackedPartnerDueCordycepsEnd
	printfromtable gCordycepsStringIds
	waitmessage B_WAIT_TIME_LONG
BattleScript_AttackedPartnerDueCordycepsEnd:
	tryfaintmon BS_TARGET, FALSE, NULL
	goto BattleScript_MoveEnd

BattleScript_MoveUsedIsConfused::
	printstring STRINGID_PKMNISCONFUSED
	waitmessage B_WAIT_TIME_LONG
	status2animation BS_ATTACKER, STATUS2_CONFUSION
	jumpifbyte CMP_EQUAL, cMULTISTRING_CHOOSER, FALSE, BattleScript_MoveUsedIsConfusedRet
	jumpifabilityorinnate BS_ATTACKER, ABILITY_TANGLED_FEET, BattleScript_AbilityProtect
	jumpifabilityorinnate BS_ATTACKER, ABILITY_HEADACHE, BattleScript_AbilityProtect
BattleScript_DoSelfConfusionDmg::
	cancelmultiturnmoves BS_ATTACKER
	adjustdamage
	printstring STRINGID_ITHURTCONFUSION
	waitmessage B_WAIT_TIME_LONG
	effectivenesssound
	hitanimation BS_ATTACKER
	waitstate
	orword gHitMarker, HITMARKER_IGNORE_SUBSTITUTE | HITMARKER_PASSIVE_DAMAGE
	healthbarupdate BS_ATTACKER
	datahpupdate BS_ATTACKER
	resultmessage
	waitmessage B_WAIT_TIME_LONG
	tryfaintmon BS_ATTACKER, FALSE, NULL
	goto BattleScript_MoveEnd
BattleScript_MoveUsedIsConfusedRet::
	return

BattleScript_MoveUsedSlippedOnIce::
	cancelmultiturnmoves BS_ATTACKER
	adjustdamage
	printstring STRINGID_ITHURTFROZENTERRAIN
	waitmessage B_WAIT_TIME_LONG
	effectivenesssound
	hitanimation BS_ATTACKER
	waitstate
	orword gHitMarker, HITMARKER_IGNORE_SUBSTITUTE | HITMARKER_PASSIVE_DAMAGE
	healthbarupdate BS_ATTACKER
	datahpupdate BS_ATTACKER
	resultmessage
	waitmessage B_WAIT_TIME_LONG
	tryfaintmon BS_ATTACKER, FALSE, NULL
	goto BattleScript_MoveEnd

BattleScript_AbilityProtect::
	printstring STRINGID_UNABLEDUECONFUSION
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_MoveUsedPowder::
	bicword gHitMarker, HITMARKER_NO_ATTACKSTRING | HITMARKER_ATTACKSTRING_PRINTED
	attackstring
	ppreduce
	pause B_WAIT_TIME_SHORT
	cancelmultiturnmoves BS_ATTACKER
	status2animation BS_ATTACKER, STATUS2_POWDER
	waitanimation
	effectivenesssound
	hitanimation BS_ATTACKER
	waitstate
	orword gHitMarker, HITMARKER_IGNORE_SUBSTITUTE | HITMARKER_PASSIVE_DAMAGE
	healthbarupdate BS_ATTACKER
	datahpupdate BS_ATTACKER
	printstring STRINGID_POWDEREXPLODES
	waitmessage B_WAIT_TIME_LONG
	tryfaintmon BS_ATTACKER, FALSE, NULL
	goto BattleScript_MoveEnd

BattleScript_MoveUsedIsConfusedNoMore::
	printstring STRINGID_PKMNHEALEDCONFUSION
	waitmessage B_WAIT_TIME_LONG
	return

BattleScript_PrintPayDayMoneyString::
	printstring STRINGID_PLAYERPICKEDUPMONEY
	waitmessage B_WAIT_TIME_LONG
	return

BattleScript_WrapTurnDmg::
	jumpifmagicguarded BS_ATTACKER, BattleScript_DoTurnDmgEnd
	playanimation BS_ATTACKER, B_ANIM_TURN_TRAP, sB_ANIM_ARG1
	printstring STRINGID_PKMNHURTBY
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_DoTurnDmg

BattleScript_WrapEnds::
	printstring STRINGID_PKMNFREEDFROM
	waitmessage B_WAIT_TIME_LONG
	end2

BattleScript_MoveUsedIsInLove::
	printstring STRINGID_PKMNINLOVE
	waitmessage B_WAIT_TIME_LONG
	status2animation BS_ATTACKER, STATUS2_INFATUATION
	return

BattleScript_MoveUsedIsInLoveCantAttack::
	printstring STRINGID_PKMNIMMOBILIZEDBYLOVE
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_VoodooDollEnd::
	printstring STRINGID_VOODOODOLLENDED
	waitmessage B_WAIT_TIME_LONG
	end2

BattleScript_NightmareTurnDmg::
	printstring STRINGID_PKMNLOCKEDINNIGHTMARE
	waitmessage B_WAIT_TIME_LONG
	status2animation BS_ATTACKER, STATUS2_NIGHTMARE
	goto BattleScript_DoTurnDmg

BattleScript_CurseTurnDmg::
	printstring STRINGID_PKMNAFFLICTEDBYCURSE
	waitmessage B_WAIT_TIME_LONG
	status2animation BS_ATTACKER, STATUS2_CURSED
	goto BattleScript_DoTurnDmg

BattleScript_TargetPRLZHeal::
	printstring STRINGID_PKMNHEALEDPARALYSIS
	waitmessage B_WAIT_TIME_LONG
	updatestatusicon BS_TARGET
	return

BattleScript_TargetWokeUp::
	printstring STRINGID_TARGETWOKEUP
	waitmessage B_WAIT_TIME_LONG
	updatestatusicon BS_TARGET
	return

BattleScript_TargetBurnHeal::
	printstring STRINGID_PKMNBURNHEALED
	waitmessage B_WAIT_TIME_LONG
	updatestatusicon BS_TARGET
	return

BattleScript_TargetFrostbiteHeal::
	printstring STRINGID_PKMNFROSTBITEHEALED
	waitmessage B_WAIT_TIME_LONG
	updatestatusicon BS_TARGET
	return

BattleScript_MoveEffectSleep::
	statusanimation BS_EFFECT_BATTLER
	printfromtable gFellAsleepStringIds
	waitmessage B_WAIT_TIME_LONG
BattleScript_UpdateEffectStatusIconRet::
	updatestatusicon BS_EFFECT_BATTLER
	waitstate
	tryactivateattackerabilitiesonstatusinflict 0
	tryactivateattackerabilitiesonstatusinflict 1
	tryactivateattackerabilitiesonstatusinflict 2
	tryactivateattackerabilitiesonstatusinflict 3
	return

BattleScript_YawnMakesAsleep::
	statusanimation BS_EFFECT_BATTLER
	printstring STRINGID_PKMNFELLASLEEP
	waitmessage B_WAIT_TIME_LONG
	updatestatusicon BS_EFFECT_BATTLER
	waitstate
	jumpifstatus3 BS_EFFECT_BATTLER, STATUS3_SKY_DROPPED, BattleScript_YawnEnd
	makevisible BS_EFFECT_BATTLER
	skydropyawn
BattleScript_YawnEnd:
	end2

BattleScript_EmbargoEndTurn::
	printstring STRINGID_EMBARGOENDS
	waitmessage B_WAIT_TIME_LONG
	end2

BattleScript_SlowbeamEndTurn::
	printstring STRINGID_SLOWBEAMENDS
	waitmessage B_WAIT_TIME_LONG
	end2

BattleScript_TelekinesisEndTurn::
	jumpifmagicguarded BS_ATTACKER, BattleScript_DoTurnDmgEnd
	printstring STRINGID_TELEKINESISENDS
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_DoTurnDmg

BattleScript_BufferEndTurn::
	printstring STRINGID_BUFFERENDS
	waitmessage B_WAIT_TIME_LONG
	end2

BattleScript_ToxicOrb::
	setbyte cMULTISTRING_CHOOSER, 0
	copybyte gEffectBattler, gBattlerAttacker
	call BattleScript_MoveEffectToxic
	end2

BattleScript_FlameOrb::
	setbyte cMULTISTRING_CHOOSER, 0
	copybyte gEffectBattler, gBattlerAttacker
	call BattleScript_MoveEffectBurn
	end2

BattleScript_FrostbiteOrb::
	setbyte cMULTISTRING_CHOOSER, 0
	copybyte gEffectBattler, gBattlerAttacker
	call BattleScript_MoveEffectFrostbite
	end2

BattleScript_ParalyzeOrb::
	setbyte cMULTISTRING_CHOOSER, 0
	copybyte gEffectBattler, gBattlerAttacker
	call BattleScript_MoveEffectParalysis
	end2

BattleScript_ConfuseOrb::
	setbyte cMULTISTRING_CHOOSER, 0
	copybyte gEffectBattler, gBattlerAttacker
	call BattleScript_MoveEffectConfusion
	end2

BattleScript_MoveEffectPoison::
	statusanimation BS_EFFECT_BATTLER
	printfromtable gGotPoisonedStringIds
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_UpdateEffectStatusIconRet

BattleScript_MoveEffectBurn::
	statusanimation BS_EFFECT_BATTLER
	printfromtable gGotBurnedStringIds
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_UpdateEffectStatusIconRet

BattleScript_MoveEffectFreeze::
	statusanimation BS_EFFECT_BATTLER
	printfromtable gGotFrozenStringIds
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_UpdateEffectStatusIconRet

BattleScript_MoveEffectFrostbite::
	statusanimation BS_EFFECT_BATTLER
	printfromtable gGotFrostbiteStringIds
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_UpdateEffectStatusIconRet

BattleScript_MoveEffectParalysis::
	statusanimation BS_EFFECT_BATTLER
	printfromtable gGotParalyzedStringIds
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_UpdateEffectStatusIconRet

BattleScript_MoveEffectUproar::
	printstring STRINGID_PKMNCAUSEDUPROAR
	waitmessage B_WAIT_TIME_LONG
	return

BattleScript_MoveEffectToxic::
	statusanimation BS_EFFECT_BATTLER
	printstring STRINGID_PKMNBADLYPOISONED
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_UpdateEffectStatusIconRet

BattleScript_MoveEffectPayDay::
	printstring STRINGID_COINSSCATTERED
	waitmessage B_WAIT_TIME_LONG
	return

BattleScript_MoveEffectWrap::
	printfromtable gWrappedStringIds
	waitmessage B_WAIT_TIME_LONG
	return

BattleScript_MoveEffectConfusion::
	chosenstatus2animation BS_EFFECT_BATTLER, STATUS2_CONFUSION
	printstring STRINGID_PKMNWASCONFUSED
	waitmessage B_WAIT_TIME_LONG
	return

BattleScript_MoveEffectRecoilWithStatus::
	argumenttomoveeffect
	seteffectwithchance
BattleScript_MoveEffectRecoil::
	jumpifmove MOVE_STRUGGLE, BattleScript_DoRecoil
	jumpifabilityorinnate BS_ATTACKER, ABILITY_ROCK_HEAD, BattleScript_RecoilEnd
	jumpifmagicguarded BS_ATTACKER, BattleScript_RecoilEnd
	jumpifrecklessprevented BattleScript_RecoilEnd
	jumpifspecies BS_ATTACKER, SPECIES_EISCUE, BattleScript_IceFaceShattered
	@jumpifnoholdeffect BS_ATTACKER, HOLD_EFFECT_SAFETY_HELMET, BattleScript_DoRecoilModifiers
	@goto BattleScript_RecoilEnd	@Holding Safety Helmet
BattleScript_DoRecoilModifiers:
	manipulatedamage DMG_RECOIL_MODIFIERS
BattleScript_DoRecoil::
	orword gHitMarker, HITMARKER_IGNORE_SUBSTITUTE | HITMARKER_PASSIVE_DAMAGE | HITMARKER_IGNORE_DISGUISE
	healthbarupdate BS_ATTACKER
	datahpupdate BS_ATTACKER
	printstring STRINGID_PKMNHITWITHRECOIL
	waitmessage B_WAIT_TIME_LONG
	tryfaintmon BS_ATTACKER, FALSE, NULL
BattleScript_RecoilEnd::
	return

BattleScript_MoveEffectRecoilSpeedUpWithStatus::
	call BattleScript_MoveEffectRecoilWithStatus
	setstatchanger STAT_SPEED, 1, FALSE
	statbuffchange MOVE_EFFECT_AFFECTS_ATTACKER | STAT_CHANGE_ALLOW_PTR, BattleScript_MoveEffectRecoilSpeedUpWithStatusReturn
	jumpifbyte CMP_EQUAL, cMULTISTRING_CHOOSER, B_MSG_STAT_WONT_INCREASE, BattleScript_MoveEffectRecoilSpeedUpWithStatusReturn
	setgraphicalstatchangevalues
	playanimation BS_ATTACKER, B_ANIM_STATS_CHANGE, sB_ANIM_ARG1
	printfromtable gStatUpStringIds
	waitmessage B_WAIT_TIME_LONG
BattleScript_MoveEffectRecoilSpeedUpWithStatusReturn::
	return

BattleScript_MoveEffectRecoilSpeedUp::
	call BattleScript_MoveEffectRecoilWithStatus
	setstatchanger STAT_SPEED, 1, FALSE
	statbuffchange MOVE_EFFECT_AFFECTS_ATTACKER | STAT_CHANGE_ALLOW_PTR, BattleScript_MoveEffectRecoilSpeedUpReturn
	jumpifbyte CMP_EQUAL, cMULTISTRING_CHOOSER, B_MSG_STAT_WONT_INCREASE, BattleScript_MoveEffectRecoilSpeedUpReturn
	setgraphicalstatchangevalues
	playanimation BS_ATTACKER, B_ANIM_STATS_CHANGE, sB_ANIM_ARG1
	printfromtable gStatUpStringIds
	waitmessage B_WAIT_TIME_LONG
BattleScript_MoveEffectRecoilSpeedUpReturn::
	return

BattleScript_IceFaceShattered:
	copybyte gBattlerAbility, gBattlerAttacker
	call BattleScript_AbilityPopUp
	printstring STRINGID_ICEFACESHATTERED
	waitstate
	changespeciesto BS_ABILITY_BATTLER SPECIES_EISCUE_NOICE_FACE
	handleformchange BS_ABILITY_BATTLER, 0
	handleformchange BS_ABILITY_BATTLER, 1
	playanimation BS_ABILITY_BATTLER, B_ANIM_FORM_CHANGE, NULL
	waitanimation
	handleformchange BS_ABILITY_BATTLER, 2
	return

BattleScript_ItemSteal::
	playanimation BS_TARGET, B_ANIM_ITEM_STEAL, NULL
	printstring STRINGID_PKMNSTOLEITEM
	waitmessage B_WAIT_TIME_LONG
	return

BattleScript_DrizzleActivates::
	pause B_WAIT_TIME_SHORT
	call BattleScript_AbilityPopUp
	printstring STRINGID_PKMNMADEITRAIN
	waitstate
	playanimation BS_BATTLER_0, B_ANIM_RAIN_CONTINUES, NULL
	call BattleScript_WeatherFormChanges
	end3

BattleScript_AirBlowerActivates::
	pause B_WAIT_TIME_SHORT
	call BattleScript_AbilityPopUp
	printstring STRINGID_TAILWINDBLEW
	waitstate
	playmoveanimation BS_ATTACKER, MOVE_TAILWIND
	end3

BattleScript_DefiantActivates::
	pause B_WAIT_TIME_SHORT
	call BattleScript_AbilityPopUp
	statbuffchange 0, NULL
	setgraphicalstatchangevalues
	playanimation BS_ABILITY_BATTLER, B_ANIM_STATS_CHANGE, sB_ANIM_ARG1
	printstring STRINGID_DEFENDERSSTATROSE
	waitmessage B_WAIT_TIME_LONG
	return

BattleScript_MonstrosityFusionActivates::
	pause B_WAIT_TIME_SHORT
	call BattleScript_AbilityPopUp
	jumpifbyteequal sSTATCHANGER, sZero, BattleScript_MonstrosityFusionSecondRaise
	statbuffchange 0, NULL
	jumpifbyte CMP_GREATER_THAN, cMULTISTRING_CHOOSER, B_MSG_DEFENDER_STAT_FELL, BattleScript_MonstrosityFusionSecondRaise
	setgraphicalstatchangevalues
	playanimation BS_ABILITY_BATTLER, B_ANIM_STATS_CHANGE, sB_ANIM_ARG1
	waitanimation
	printstring STRINGID_DEFENDERSSTATROSE
	waitmessage B_WAIT_TIME_LONG
BattleScript_MonstrosityFusionSecondRaise:
	jumpifbyteequal sSAVED_STAT_CHANGER, sZero, BattleScript_MonstrosityFusionEnd
	copybyte sSTATCHANGER, sSAVED_STAT_CHANGER
	statbuffchange 0, NULL
	jumpifbyte CMP_GREATER_THAN, cMULTISTRING_CHOOSER, B_MSG_DEFENDER_STAT_FELL, BattleScript_MonstrosityFusionEnd
	setgraphicalstatchangevalues
	playanimation BS_ABILITY_BATTLER, B_ANIM_STATS_CHANGE, sB_ANIM_ARG1
	printfromtable STRINGID_DEFENDERSSTATROSE
	waitmessage B_WAIT_TIME_LONG
BattleScript_MonstrosityFusionEnd:
	updatestatusicon BS_ABILITY_BATTLER
	return

BattleScript_AbilityPopUp:
	.if B_ABILITY_POP_UP == TRUE
	showabilitypopup BS_ABILITY_BATTLER
	recordability BS_ABILITY_BATTLER
	pause B_WAIT_TIME_LONG
	.endif
	sethword sABILITY_OVERWRITE, 0
	return

BattleScript_SpeedBoostActivates::
	call BattleScript_AbilityPopUp
	playanimation BS_ATTACKER, B_ANIM_STATS_CHANGE, sB_ANIM_ARG1
	printstring STRINGID_PKMNRAISEDSPEED
	waitmessage B_WAIT_TIME_LONG
	end3

BattleScript_RoyalJellyActivates_End2::
	call BattleScript_RoyalJellyActivates_Ret
	removeitem BS_ATTACKER, 1
	end2

BattleScript_RoyalJellyActivates_End3::
	call BattleScript_AbilityPopUp
	call BattleScript_RoyalJellyActivates_Ret
	end3

BattleScript_RoyalJellyActivates_Ret::
	playanimation BS_ATTACKER, B_ANIM_HELD_ITEM_EFFECT, NULL
	printstring STRINGID_PKMNSEATSOMEHONEY
	waitmessage B_WAIT_TIME_LONG
	orword gHitMarker, HITMARKER_IGNORE_SUBSTITUTE
	healthbarupdate BS_ATTACKER
	datahpupdate BS_ATTACKER
	statbuffchange MOVE_EFFECT_AFFECTS_ATTACKER | STAT_BUFF_NOT_PROTECT_AFFECTED | MOVE_EFFECT_CERTAIN, NULL
	setgraphicalstatchangevalues
	playanimation BS_ATTACKER, B_ANIM_STATS_CHANGE, sB_ANIM_ARG1
	waitanimation
	printstring STRINGID_PKMNSSTATWASRAISED
	waitmessage B_WAIT_TIME_LONG
	return

BattleScript_EatSomeHoney::
	call BattleScript_AbilityPopUp
	playanimation BS_ATTACKER, B_ANIM_HELD_ITEM_EFFECT, NULL
	printstring STRINGID_PKMNSEATSOMEHONEY
	waitmessage B_WAIT_TIME_LONG
	orword gHitMarker, HITMARKER_IGNORE_SUBSTITUTE
	healthbarupdate BS_ATTACKER
	datahpupdate BS_ATTACKER
	end3

BattleScript_DrinkSomeMilk::
	call BattleScript_AbilityPopUp
	playanimation BS_ATTACKER, B_ANIM_HELD_ITEM_EFFECT, NULL
	printstring STRINGID_PKMNSDRINKSOMEMILK
	waitmessage B_WAIT_TIME_LONG
	orword gHitMarker, HITMARKER_IGNORE_SUBSTITUTE
	healthbarupdate BS_ATTACKER
	datahpupdate BS_ATTACKER
	end3

@ Can't compare directly to a value, have to compare to value at pointer
sZero:
.byte 0
	
BattleScript_MoodyActivates::
	call BattleScript_AbilityPopUp
	jumpifbyteequal sSTATCHANGER, sZero, BattleScript_MoodyLower
	statbuffchange MOVE_EFFECT_AFFECTS_ATTACKER | MOVE_EFFECT_CERTAIN | STAT_BUFF_NOT_PROTECT_AFFECTED, BattleScript_MoodyLower
	jumpifbyte CMP_GREATER_THAN, cMULTISTRING_CHOOSER, B_MSG_DEFENDER_STAT_ROSE, BattleScript_MoodyLower
	setgraphicalstatchangevalues
	playanimation BS_ATTACKER, B_ANIM_STATS_CHANGE, sB_ANIM_ARG1
	printfromtable gStatUpStringIds
	waitmessage B_WAIT_TIME_LONG
BattleScript_MoodyLower:
	jumpifbyteequal sSAVED_STAT_CHANGER, sZero, BattleScript_MoodyEnd
	copybyte sSTATCHANGER, sSAVED_STAT_CHANGER
	statbuffchange MOVE_EFFECT_AFFECTS_ATTACKER | MOVE_EFFECT_CERTAIN | STAT_BUFF_NOT_PROTECT_AFFECTED, BattleScript_MoodyEnd
	jumpifbyte CMP_GREATER_THAN, cMULTISTRING_CHOOSER, B_MSG_DEFENDER_STAT_FELL, BattleScript_MoodyEnd
	setgraphicalstatchangevalues
	playanimation BS_ATTACKER, B_ANIM_STATS_CHANGE, sB_ANIM_ARG1
	printfromtable gStatDownStringIds
	waitmessage B_WAIT_TIME_LONG
BattleScript_MoodyEnd:
	end3

BattleScript_EmergencyExit::
	pause 5
	call BattleScript_AbilityPopUp
	pause B_WAIT_TIME_LONG
BattleScript_EmergencyExitNoPopUp::
	playanimation BS_TARGET, B_ANIM_SLIDE_OFFSCREEN, NULL
	waitanimation
	openpartyscreen BS_TARGET, BattleScript_EmergencyExitRet
	switchoutabilitiesorinnates BS_TARGET, 0
	switchoutabilitiesorinnates BS_TARGET, 1
	switchoutabilitiesorinnates BS_TARGET, 2
	switchoutabilitiesorinnates BS_TARGET, 3
	swithchoutrevolvingruin BS_TARGET
	waitstate
	switchhandleorder BS_TARGET, 2
	returntoball BS_TARGET
	getswitchedmondata BS_TARGET
	switchindataupdate BS_TARGET
	hpthresholds BS_TARGET
	printstring STRINGID_SWITCHINMON
	switchinanim BS_TARGET, TRUE
	waitstate
	switchineffects BS_TARGET
BattleScript_EmergencyExitRet:
	return
	
BattleScript_EmergencyExitWild::
	pause 5
	call BattleScript_AbilityPopUp
	pause B_WAIT_TIME_LONG
BattleScript_EmergencyExitWildNoPopUp::
	playanimation BS_TARGET, B_ANIM_SLIDE_OFFSCREEN, NULL
	waitanimation
	setoutcomeonteleport BS_TARGET
	finishaction
	return

BattleScript_TraceActivates::
	pause B_WAIT_TIME_SHORT
	call BattleScript_AbilityPopUp
	printstring STRINGID_PKMNTRACED
	waitmessage B_WAIT_TIME_LONG
	switchinabilities BS_SCRIPTING
	return

BattleScript_TraceActivatesEnd3::
	call BattleScript_TraceActivates
	end3

BattleScript_ReceiverActivates::
	call BattleScript_AbilityPopUp
	printstring STRINGID_RECEIVERABILITYTAKEOVER
	waitmessage B_WAIT_TIME_LONG
	return
	
BattleScript_AbilityHpHeal:
	call BattleScript_AbilityPopUp
	printstring STRINGID_PKMNSXRESTOREDHPALITTLE2
	waitmessage B_WAIT_TIME_LONG
	orword gHitMarker, HITMARKER_IGNORE_SUBSTITUTE
	healthbarupdate BS_ATTACKER
	datahpupdate BS_ATTACKER
	return

BattleScript_RainDishActivates::
	call BattleScript_AbilityHpHeal
	end3

BattleScript_KingsGraceActivates::
	call BattleScript_AbilityPopUp
	playanimation BS_ATTACKER, B_ANIM_KINGS_GRACE, NULL
	printstring STRINGID_PKMNUSEDKINGSGRACE
	waitmessage B_WAIT_TIME_LONG
	end3
	
BattleScript_CheekPouchActivates::
	copybyte sSAVED_BATTLER, gBattlerAttacker
	copybyte gBattlerAttacker, gBattlerAbility
	call BattleScript_AbilityHpHeal
	jumpifabilityorinnate BS_ABILITY_BATTLER, ABILITY_SUGAR_RUSH, BattleScript_SugarRushActivatesAfterCheekPouch
	copybyte gBattlerAttacker, sSAVED_BATTLER
	return

BattleScript_SugarRushActivatesAfterCheekPouch:
	jumpifstat BS_ATTACKER, CMP_EQUAL, STAT_SPEED, MAX_STAT_STAGE, BattleScript_SugarRushActivatesAfterCheekPouchReturn
	sethword sABILITY_OVERWRITE, ABILITY_SUGAR_RUSH
	changelastusedability ABILITY_SUGAR_RUSH
	call BattleScript_AbilityPopUp
	setstatchanger STAT_SPEED, 2, FALSE
	statbuffchange MOVE_EFFECT_AFFECTS_ATTACKER | STAT_BUFF_NOT_PROTECT_AFFECTED | MOVE_EFFECT_CERTAIN, NULL
	setgraphicalstatchangevalues
	playanimation BS_ATTACKER, B_ANIM_STATS_CHANGE, sB_ANIM_ARG1
	waitanimation
	printstring STRINGID_BATTLERABILITYRAISEDSTAT
	waitmessage B_WAIT_TIME_LONG
BattleScript_SugarRushActivatesAfterCheekPouchReturn:
	copybyte gBattlerAttacker, sSAVED_BATTLER
	return

BattleScript_SugarRushActivates::
	copybyte sSAVED_BATTLER, gBattlerAttacker
	copybyte gBattlerAttacker, gBattlerAbility
	call BattleScript_AbilityPopUp
	statbuffchange MOVE_EFFECT_AFFECTS_ATTACKER | STAT_BUFF_NOT_PROTECT_AFFECTED | MOVE_EFFECT_CERTAIN, NULL
	setgraphicalstatchangevalues
	playanimation BS_ATTACKER, B_ANIM_STATS_CHANGE, sB_ANIM_ARG1
	waitanimation
	printstring STRINGID_BATTLERABILITYRAISEDSTAT
	waitmessage B_WAIT_TIME_LONG
	copybyte gBattlerAttacker, sSAVED_BATTLER
	return

BattleScript_HibernateActivates::
	copybyte sSAVED_BATTLER, gBattlerTarget
	copybyte gBattlerTarget, gBattlerAbility
	jumpifstatus BS_TARGET, STATUS1_SLEEP, BattleScript_HibernateReturn
	jumpifabilityorinnate BS_TARGET, ABILITY_COMATOSE, BattleScript_HibernateReturn
	jumpifcantmakeasleep BattleScript_HibernateReturn
	tryhibernate BattleScript_HibernateReturn
	pause B_WAIT_TIME_SHORT
	call BattleScript_AbilityPopUp
	printstring STRINGID_PKMNHIBERNATED
	updatestatusicon BS_TARGET
	waitstate
	playmoveanimation BS_TARGET, MOVE_REST
	orword gHitMarker, HITMARKER_IGNORE_SUBSTITUTE
	healthbarupdate BS_TARGET
	datahpupdate BS_TARGET
	printstring STRINGID_PKMNREGAINEDHEALTH
	waitmessage B_WAIT_TIME_LONG
BattleScript_HibernateReturn:
	copybyte gBattlerTarget, sSAVED_BATTLER
	return

BattleScript_HarvestActivates::
	pause 5
	tryrecycleitem BattleScript_HarvestActivatesEnd
	call BattleScript_AbilityPopUp
	printstring STRINGID_HARVESTBERRY
	waitmessage B_WAIT_TIME_LONG
BattleScript_HarvestActivatesEnd:
	end3

BattleScript_CheekPouchOranBerryActivates::
	pause 5
	call BattleScript_AbilityPopUp
	printstring STRINGID_CHEEKPOUCHORANBERRY
	waitmessage B_WAIT_TIME_LONG
	end3

BattleScript_GemHoarderActivates::
	pause 5
	call BattleScript_AbilityPopUp
	printstring STRINGID_GEMHOARDERACTIVATES
	waitmessage B_WAIT_TIME_LONG
	end3

BattleScript_HoneyGatherActivates::
	pause 5
	call BattleScript_AbilityPopUp
	printstring STRINGID_HONEYGATHER
	waitmessage B_WAIT_TIME_LONG
	end3

BattleScript_SolarPowerActivates::
	orword gHitMarker, HITMARKER_IGNORE_SUBSTITUTE | HITMARKER_PASSIVE_DAMAGE
	call BattleScript_AbilityPopUp
	healthbarupdate BS_ATTACKER
	datahpupdate BS_ATTACKER
	printstring STRINGID_SOLARPOWERHPDROP
	waitmessage B_WAIT_TIME_LONG
	tryfaintmon BS_ATTACKER, FALSE, NULL
	end3

BattleScript_DevourerCantStockpileEnd3::
	call BattleScript_DevourerCantStockpileReturn
	end3

BattleScript_DevourerCantStockpileReturn::
	orword gHitMarker, HITMARKER_IGNORE_SUBSTITUTE | HITMARKER_PASSIVE_DAMAGE
	call BattleScript_AbilityPopUp
	healthbarupdate BS_ATTACKER
	datahpupdate BS_ATTACKER
	printstring STRINGID_DEVOURERHPDROP
	waitmessage B_WAIT_TIME_LONG
	tryfaintmon BS_ATTACKER, FALSE, NULL
	return

BattleScript_DevourerStockpileEnd3::
	call BattleScript_DevourerStockpileReturn
	end3
	
BattleScript_DevourerStockpileReturn::
	stockpile 0
	call BattleScript_AbilityPopUp
	printfromtable gStockpileUsedStringIds
	waitmessage B_WAIT_TIME_LONG
	jumpifstat BS_ATTACKER, CMP_LESS_THAN, STAT_DEF, MAX_STAT_STAGE, BattleScript_DevourerDef
	jumpifstat BS_ATTACKER, CMP_EQUAL, STAT_SPDEF, MAX_STAT_STAGE, BattleScript_DevourerEnd
BattleScript_DevourerDef:
	setbyte sSTAT_ANIM_PLAYED, FALSE
	playstatchangeanimation BS_ATTACKER, BIT_DEF | BIT_SPDEF, 0
	setstatchanger STAT_DEF, 1, FALSE
	statbuffchange MOVE_EFFECT_AFFECTS_ATTACKER | STAT_CHANGE_ALLOW_PTR, BattleScript_DevourerSpDef
	jumpifbyte CMP_EQUAL, cMULTISTRING_CHOOSER, B_MSG_STAT_WONT_INCREASE, BattleScript_DevourerSpDef
	printfromtable gStatUpStringIds
	waitmessage B_WAIT_TIME_LONG
BattleScript_DevourerSpDef::
	setstatchanger STAT_SPDEF, 1, FALSE
	statbuffchange MOVE_EFFECT_AFFECTS_ATTACKER | STAT_CHANGE_ALLOW_PTR, BattleScript_DevourerEnd
	jumpifbyte CMP_EQUAL, cMULTISTRING_CHOOSER, B_MSG_STAT_WONT_INCREASE, BattleScript_DevourerEnd
	printfromtable gStatUpStringIds
	waitmessage B_WAIT_TIME_LONG
BattleScript_DevourerEnd:
	stockpile 2
	return

BattleScript_HealerActivates::
	call BattleScript_AbilityPopUp
	curestatus BS_SCRIPTING
	updatestatusicon BS_SCRIPTING
	printstring STRINGID_HEALERCURE
	waitmessage B_WAIT_TIME_LONG
	end3

BattleScript_SandstreamActivates::
	pause B_WAIT_TIME_SHORT
	call BattleScript_AbilityPopUp
	printstring STRINGID_PKMNSXWHIPPEDUPSANDSTORM
	waitstate
	playanimation BS_BATTLER_0, B_ANIM_SANDSTORM_CONTINUES, NULL
	call BattleScript_WeatherFormChanges
	end3

BattleScript_GloomyNightActivates::
	pause B_WAIT_TIME_SHORT
	call BattleScript_AbilityPopUp
	printstring STRINGID_PKMNSXGLOOMYNIGHT
	waitstate
	playanimation BS_BATTLER_0, B_ANIM_NIGHT_CONTINUES, NULL
	call BattleScript_WeatherFormChanges
	end3

BattleScript_SandSpitActivates::
	pause B_WAIT_TIME_SHORT
	call BattleScript_AbilityPopUp
	printstring STRINGID_ASANDSTORMKICKEDUP
	waitstate
	playanimation BS_BATTLER_0, B_ANIM_SANDSTORM_CONTINUES, NULL
	call BattleScript_WeatherFormChanges
	return

BattleScript_ShedSkinActivates::
	call BattleScript_AbilityPopUp
	printstring STRINGID_PKMNSXCUREDYPROBLEM
	waitmessage B_WAIT_TIME_LONG
	orword gHitMarker, HITMARKER_IGNORE_SUBSTITUTE
	healthbarupdate BS_ATTACKER
	datahpupdate BS_ATTACKER
	updatestatusicon BS_ATTACKER
	end3

BattleScript_WeatherFormChanges::
	setbyte sBATTLER, 0
BattleScript_WeatherFormChangesLoop::
	tryweatherdatachange
	addbyte sBATTLER, 1
	jumpifbytenotequal sBATTLER, gBattlersCount, BattleScript_WeatherFormChangesLoop
	return

BattleScript_WeatherFormChangeEnd3::
	call BattleScript_WeatherFormChangeReturn
	end3

BattleScript_WeatherFormChangeReturn::
	copybyte gBattlerAbility, sBATTLER
	call BattleScript_AbilityPopUp
	printstring STRINGID_PKMNTRANSFORMED
	waitmessage 1
	handleformchange BS_ABILITY_BATTLER, 0
	handleformchange BS_ABILITY_BATTLER, 1
	playanimation BS_ABILITY_BATTLER, B_ANIM_FORM_CHANGE, NULL
	waitanimation
	handleformchange BS_ABILITY_BATTLER, 2 
	return

BattleScript_TerrainFormChanges::
	setbyte sBATTLER, 0
BattleScript_TerrainFormChangesLoop::
	tryterraindatachange
	addbyte sBATTLER, 1
	jumpifbytenotequal sBATTLER, gBattlersCount, BattleScript_TerrainFormChangesLoop
	return
	
BattleScript_TryAdrenalineOrb:
	jumpifnoholdeffect BS_TARGET, HOLD_EFFECT_ADRENALINE_ORB, BattleScript_TryAdrenalineOrbRet
	jumpifstat BS_TARGET, CMP_EQUAL, STAT_SPEED, MAX_STAT_STAGE, BattleScript_TryAdrenalineOrbRet
	setstatchanger STAT_SPEED, 1, FALSE
	statbuffchange STAT_BUFF_NOT_PROTECT_AFFECTED | MOVE_EFFECT_CERTAIN | STAT_CHANGE_ALLOW_PTR, BattleScript_TryAdrenalineOrbRet
	playanimation BS_TARGET, B_ANIM_HELD_ITEM_EFFECT, NULL
	setgraphicalstatchangevalues
	playanimation BS_TARGET, B_ANIM_STATS_CHANGE, sB_ANIM_ARG1
	copybyte sBATTLER, gBattlerTarget
	setlastuseditem BS_TARGET, 1
	printstring STRINGID_USINGITEMSTATOFPKMNROSE
	waitmessage B_WAIT_TIME_LONG
	removeitem BS_TARGET, 1
BattleScript_TryAdrenalineOrbRet:
	return

BattleScript_PetrifyingGazeActivatesEnd3::
	call BattleScript_PausePetrifyingGazeActivates
	end3

BattleScript_PausePetrifyingGazeActivates:
	pause B_WAIT_TIME_SHORT
BattleScript_PetrifyingGazeActivates::
	setbyte gBattlerTarget, 0
	sethword sABILITY_OVERWRITE, ABILITY_PETRIFYING_GAZE
	pause B_WAIT_TIME_SHORT
	call BattleScript_AbilityPopUp
BattleScript_PetrifyingGazeActivatesLoop:
	trygetintimidatetarget BattleScript_PetrifyingGazeActivatesReturn
	tryparalyzebattler BS_TARGET, BattleScript_PetrifyingGazeActivatesLoopIncrement
	statusanimation BS_TARGET
	printfromtable gGotParalyzedStringIds
	waitmessage B_WAIT_TIME_LONG
	updatestatusicon BS_TARGET
	waitstate
	waitmessage B_WAIT_TIME_LONG 
	call BattleScript_TryAdrenalineOrb
BattleScript_PetrifyingGazeActivatesLoopIncrement:
	addbyte gBattlerTarget, 1
	goto BattleScript_PetrifyingGazeActivatesLoop
BattleScript_PetrifyingGazeActivatesReturn:
	return

BattleScript_FrightenActivatesEnd3::
	call BattleScript_PauseFrightenActivates
	end3

BattleScript_PauseFrightenActivates:
	pause B_WAIT_TIME_SHORT
BattleScript_FrightenActivates::
	setbyte gBattlerTarget, 0
	sethword sABILITY_OVERWRITE, ABILITY_FRIGHTEN
	pause B_WAIT_TIME_SHORT
	call BattleScript_AbilityPopUp
BattleScript_FrightenActivatesLoop:
	setstatchanger STAT_SPATK, 1, TRUE
	trygetintimidatetarget BattleScript_FrightenActivatesReturn
	jumpifstatus2 BS_TARGET, STATUS2_SUBSTITUTION_ANY, BattleScript_FrightenActivatesLoopIncrement
	jumpifabilitypreventedstatreduction BS_TARGET, STAT_SPATK, BattleScript_FrightenPrevented
	jumpifintimidateblocked BS_TARGET, BattleScript_FrightenPrevented
	jumpifabilityorinnate BS_TARGET, ABILITY_GUARD_DOG, BattleScript_FrightenInReverse
	statbuffchange STAT_BUFF_NOT_PROTECT_AFFECTED | STAT_CHANGE_ALLOW_PTR, BattleScript_FrightenActivatesLoopIncrement
	jumpifbyte CMP_GREATER_THAN, cMULTISTRING_CHOOSER, 1, BattleScript_FrightenActivatesLoopIncrement
	setgraphicalstatchangevalues
	playanimation BS_TARGET, B_ANIM_STATS_CHANGE, sB_ANIM_ARG1
	printstring STRINGID_PKMNCUTSSPECIALATTACKWITH
	waitmessage B_WAIT_TIME_LONG 
	call BattleScript_TryAdrenalineOrb
BattleScript_FrightenActivatesLoopIncrement:
	addbyte gBattlerTarget, 1
	goto BattleScript_FrightenActivatesLoop
BattleScript_FrightenActivatesReturn:
	return
BattleScript_FrightenPrevented:
	pause B_WAIT_TIME_SHORT
	call BattleScript_AbilityPopUp
	setbyte gBattleCommunication STAT_SPATK
	stattextbuffer BS_ATTACKER
	printstring STRINGID_STATWASNOTLOWERED
	waitmessage B_WAIT_TIME_LONG
	call BattleScript_TryAdrenalineOrb
	goto BattleScript_FrightenActivatesLoopIncrement

BattleScript_IntimidateActivatesEnd3::
	call BattleScript_PauseIntimidateActivates
	end3

BattleScript_PauseIntimidateActivates:
	pause B_WAIT_TIME_SHORT
BattleScript_IntimidateActivates::
	setbyte gBattlerTarget, 0
	sethword sABILITY_OVERWRITE, ABILITY_INTIMIDATE
	call BattleScript_AbilityPopUp
BattleScript_IntimidateActivatesLoop:
	setstatchanger STAT_ATK, 1, TRUE
	trygetintimidatetarget BattleScript_IntimidateActivatesReturn
	jumpifstatus2 BS_TARGET, STATUS2_SUBSTITUTION_ANY, BattleScript_IntimidateActivatesLoopIncrement
	jumpifabilitypreventedstatreduction BS_TARGET, STAT_ATK, BattleScript_IntimidatePrevented
	jumpifintimidateblocked BS_TARGET, BattleScript_IntimidatePrevented
	jumpifabilityorinnate BS_TARGET, ABILITY_GUARD_DOG, BattleScript_IntimidateInReverse
	statbuffchange STAT_BUFF_NOT_PROTECT_AFFECTED | STAT_CHANGE_ALLOW_PTR, BattleScript_IntimidateActivatesLoopIncrement
	jumpifbyte CMP_GREATER_THAN, cMULTISTRING_CHOOSER, 1, BattleScript_IntimidateActivatesLoopIncrement
	setgraphicalstatchangevalues
	playanimation BS_TARGET, B_ANIM_STATS_CHANGE, sB_ANIM_ARG1
	printstring STRINGID_PKMNCUTSATTACKWITH
	waitmessage B_WAIT_TIME_LONG 
	call BattleScript_TryAdrenalineOrb
BattleScript_IntimidateActivatesLoopIncrement:
	addbyte gBattlerTarget, 1
	goto BattleScript_IntimidateActivatesLoop
BattleScript_IntimidateActivatesReturn:
	return
BattleScript_IntimidatePrevented:
	pause B_WAIT_TIME_SHORT
	call BattleScript_AbilityPopUp
	setbyte gBattleCommunication STAT_ATK
	stattextbuffer BS_ATTACKER
	printstring STRINGID_STATWASNOTLOWERED
	waitmessage B_WAIT_TIME_LONG
	call BattleScript_TryAdrenalineOrb
	goto BattleScript_IntimidateActivatesLoopIncrement

BattleScript_IntimidateInReverse:
	copybyte gEffectBattler, gBattlerTarget
	copybyte sBATTLER, gBattlerTarget
	call BattleScript_AbilityPopUp
	pause B_WAIT_TIME_SHORT
	setstatchanger STAT_ATK, 1, FALSE
	statbuffchange MOVE_EFFECT_AFFECTS_ATTACKER | STAT_BUFF_NOT_PROTECT_AFFECTED | MOVE_EFFECT_CERTAIN, NULL
	setgraphicalstatchangevalues
	playanimation BS_TARGET, B_ANIM_STATS_CHANGE, sB_ANIM_ARG1
	printfromtable gStatUpStringIds
	waitmessage B_WAIT_TIME_LONG
	call BattleScript_TryAdrenalineOrb
	goto BattleScript_IntimidateActivatesLoopIncrement

BattleScript_FrightenInReverse:
	copybyte gEffectBattler, gBattlerTarget
	copybyte sBATTLER, gBattlerTarget
	call BattleScript_AbilityPopUp
	pause B_WAIT_TIME_SHORT
	setstatchanger STAT_ATK, 1, FALSE
	statbuffchange MOVE_EFFECT_AFFECTS_ATTACKER | STAT_BUFF_NOT_PROTECT_AFFECTED | MOVE_EFFECT_CERTAIN, NULL
	setgraphicalstatchangevalues
	playanimation BS_TARGET, B_ANIM_STATS_CHANGE, sB_ANIM_ARG1
	printfromtable gStatUpStringIds
	waitmessage B_WAIT_TIME_LONG
	call BattleScript_TryAdrenalineOrb
	goto BattleScript_FrightenActivatesLoopIncrement

BattleScript_IlluminateActivatesEnd3::
	call BattleScript_PauseIlluminateActivates
	end3

BattleScript_PauseIlluminateActivates:
	pause B_WAIT_TIME_SHORT
BattleScript_IlluminateActivates::
	setbyte gBattlerTarget, 0
	sethword sABILITY_OVERWRITE, ABILITY_ILLUMINATE
	call BattleScript_AbilityPopUp
BattleScript_IlluminateActivatesLoop:
	setstatchanger STAT_ACC, 1, TRUE
	trygetIntimidatetarget BattleScript_IlluminateActivatesReturn
	jumpifstatus2 BS_TARGET, STATUS2_SUBSTITUTION_ANY, BattleScript_IlluminateActivatesLoopIncrement
	jumpifabilitypreventedstatreduction BS_TARGET, STAT_ACC, BattleScript_IlluminatePrevented
	statbuffchange STAT_BUFF_NOT_PROTECT_AFFECTED | STAT_CHANGE_ALLOW_PTR, BattleScript_IlluminateActivatesLoopIncrement
	jumpifbyte CMP_GREATER_THAN, cMULTISTRING_CHOOSER, 1, BattleScript_IlluminateActivatesLoopIncrement
	setgraphicalstatchangevalues
	playanimation BS_TARGET, B_ANIM_STATS_CHANGE, sB_ANIM_ARG1
	printstring STRINGID_PKMNCUTSACCURACYWITH
	waitmessage B_WAIT_TIME_LONG 
	tryillusionoff BS_TARGET
BattleScript_IlluminateActivatesLoopIncrement:
	addbyte gBattlerTarget, 1
	goto BattleScript_IlluminateActivatesLoop
BattleScript_IlluminateActivatesReturn:
	return
BattleScript_IlluminatePrevented:
	pause B_WAIT_TIME_SHORT
	call BattleScript_AbilityPopUp
	setbyte gBattleCommunication STAT_ACC
	stattextbuffer BS_ATTACKER
	printstring STRINGID_STATWASNOTLOWERED
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_IlluminateActivatesLoopIncrement

BattleScript_SupersweetSyrupActivatesEnd3::
	call BattleScript_PauseSupersweetSyrupActivates
	end3

BattleScript_PauseSupersweetSyrupActivates:
	pause B_WAIT_TIME_SHORT
BattleScript_SupersweetSyrupActivates::
	setbyte gBattlerTarget, 0
	sethword sABILITY_OVERWRITE, ABILITY_SUPERSWEET_SYRUP
	call BattleScript_AbilityPopUp
BattleScript_SupersweetSyrupActivatesLoop:
	setstatchanger STAT_EVASION, 1, TRUE
	trygetIntimidatetarget BattleScript_SupersweetSyrupActivatesReturn
	jumpifstatus2 BS_TARGET, STATUS2_SUBSTITUTION_ANY, BattleScript_SupersweetSyrupActivatesLoopIncrement
	jumpifabilitypreventedstatreduction BS_TARGET, STAT_EVASION, BattleScript_SupersweetSyrupPrevented
	statbuffchange STAT_BUFF_NOT_PROTECT_AFFECTED | STAT_CHANGE_ALLOW_PTR, BattleScript_SupersweetSyrupActivatesLoopIncrement
	jumpifbyte CMP_GREATER_THAN, cMULTISTRING_CHOOSER, 1, BattleScript_SupersweetSyrupActivatesLoopIncrement
	setgraphicalstatchangevalues
	playanimation BS_TARGET, B_ANIM_STATS_CHANGE, sB_ANIM_ARG1
	printstring STRINGID_PKMNCUTSEVASIONWITH
	waitmessage B_WAIT_TIME_LONG 
	tryillusionoff BS_TARGET
BattleScript_SupersweetSyrupActivatesLoopIncrement:
	addbyte gBattlerTarget, 1
	goto BattleScript_SupersweetSyrupActivatesLoop
BattleScript_SupersweetSyrupActivatesReturn:
	return
BattleScript_SupersweetSyrupPrevented:
	pause B_WAIT_TIME_SHORT
	call BattleScript_AbilityPopUp
	setbyte gBattleCommunication STAT_EVASION
	stattextbuffer BS_ATTACKER
	printstring STRINGID_STATWASNOTLOWERED
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_SupersweetSyrupActivatesLoopIncrement

BattleScript_DroughtActivates::
	pause B_WAIT_TIME_SHORT
	call BattleScript_AbilityPopUp
	printstring STRINGID_PKMNSXINTENSIFIEDSUN
	waitstate
	playanimation BS_BATTLER_0, B_ANIM_SUN_CONTINUES, NULL
	call BattleScript_WeatherFormChanges
	end3

BattleScript_DesolateLandActivates::
	pause B_WAIT_TIME_SHORT
	call BattleScript_AbilityPopUp
	printstring STRINGID_EXTREMELYHARSHSUNLIGHT
	waitstate
	playanimation BS_BATTLER_0, B_ANIM_SUN_CONTINUES, NULL
	call BattleScript_WeatherFormChanges
	end3

BattleScript_DesolateLandEvaporatesWaterTypeMoves::
	accuracycheck BattleScript_PrintMoveMissed, ACC_CURR_MOVE
	attackstring
	pause B_WAIT_TIME_SHORT
	ppreduce
	printstring STRINGID_MOVEEVAPORATEDINTHEHARSHSUNLIGHT
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_PrimordialSeaActivates::
	pause B_WAIT_TIME_SHORT
	call BattleScript_AbilityPopUp
	printstring STRINGID_HEAVYRAIN
	waitstate
	playanimation BS_BATTLER_0, B_ANIM_RAIN_CONTINUES, NULL
	call BattleScript_WeatherFormChanges
	end3

BattleScript_PrimordialSeaFizzlesOutFireTypeMoves::
	accuracycheck BattleScript_PrintMoveMissed, ACC_CURR_MOVE
	attackstring
	pause B_WAIT_TIME_SHORT
	ppreduce
	printstring STRINGID_MOVEFIZZLEDOUTINTHEHEAVYRAIN
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_DeltaStreamActivates::
	pause B_WAIT_TIME_SHORT
	call BattleScript_AbilityPopUp
	printstring STRINGID_MYSTERIOUSAIRCURRENT
	waitstate
	playanimation BS_ATTACKER, B_ANIM_STRONG_WINDS, NULL
	end3

BattleScript_AttackWeakenedByStrongWinds::
	pause B_WAIT_TIME_SHORT
	printstring STRINGID_ATTACKWEAKENEDBSTRONGWINDS
	waitmessage B_WAIT_TIME_LONG
	return

BattleScript_AttackWeakenedByAbility::
	pause B_WAIT_TIME_SHORT
	call BattleScript_AbilityPopUp
	printstring STRINGID_ATTACKWEAKENEDBYABILITY
	waitmessage B_WAIT_TIME_LONG
	return

BattleScript_SnowWarningActivates::
	pause B_WAIT_TIME_SHORT
	call BattleScript_AbilityPopUp
	printstring STRINGID_SNOWWARNINGHAIL
	waitstate
	playanimation BS_BATTLER_0, B_ANIM_HAIL_CONTINUES, NULL
	call BattleScript_WeatherFormChanges
	end3
	
BattleScript_TerrainSeedLoop:	
	savetarget
	setbyte gBattlerTarget, 0
BattleScript_TerrainSeedLoopIter:
	copybyte sBATTLER, gBattlerTarget
	doterrainseed BS_TARGET, BattleScript_TerrainSeedLoop_NextBattler
	removeitem BS_TARGET, 1
BattleScript_TerrainSeedLoop_NextBattler:
	addbyte gBattlerTarget, 0x1
	jumpifbytenotequal gBattlerTarget, gBattlersCount, BattleScript_TerrainSeedLoopIter
	restoretarget
	return

BattleScript_ElectricSurgeActivates::
	pause B_WAIT_TIME_SHORT
	call BattleScript_AbilityPopUp
	printstring STRINGID_TERRAINBECOMESELECTRIC
	waitmessage B_WAIT_TIME_LONG
	playanimation BS_SCRIPTING, B_ANIM_RESTORE_BG, NULL
	call BattleScript_TerrainFormChanges
	call BattleScript_TerrainSeedLoop
	end3

BattleScript_MistySurgeActivates::
	pause B_WAIT_TIME_SHORT
	call BattleScript_AbilityPopUp
	printstring STRINGID_TERRAINBECOMESMISTY
	waitmessage B_WAIT_TIME_LONG
	playanimation BS_SCRIPTING, B_ANIM_RESTORE_BG, NULL
	call BattleScript_TerrainFormChanges
	call BattleScript_TerrainSeedLoop
	end3

BattleScript_GrassySurgeActivates::
	pause B_WAIT_TIME_SHORT
	call BattleScript_AbilityPopUp
	printstring STRINGID_TERRAINBECOMESGRASSY
	waitmessage B_WAIT_TIME_LONG
	playanimation BS_SCRIPTING, B_ANIM_RESTORE_BG, NULL
	call BattleScript_TerrainFormChanges
	call BattleScript_TerrainSeedLoop
	end3

BattleScript_PsychicSurgeActivates::
	pause B_WAIT_TIME_SHORT
	call BattleScript_AbilityPopUp
	printstring STRINGID_TERRAINBECOMESPSYCHIC
	waitmessage B_WAIT_TIME_LONG
	playanimation BS_SCRIPTING, B_ANIM_RESTORE_BG, NULL
	call BattleScript_TerrainFormChanges
	call BattleScript_TerrainSeedLoop
	end3

BattleScript_RavineSurgeActivates::
	pause B_WAIT_TIME_SHORT
	call BattleScript_AbilityPopUp
	printstring STRINGID_TERRAINBECOMESRAVINE
	waitmessage B_WAIT_TIME_LONG
	playanimation BS_SCRIPTING, B_ANIM_RESTORE_BG, NULL
	call BattleScript_TerrainFormChanges
	call BattleScript_TerrainSeedLoop
	end3

BattleScript_BurningSurgeActivatesReturn::
	pause B_WAIT_TIME_SHORT
	call BattleScript_AbilityPopUp
	printstring STRINGID_TERRAINBECOMESBURNING
	waitmessage B_WAIT_TIME_LONG
	playanimation BS_SCRIPTING, B_ANIM_RESTORE_BG, NULL
	call BattleScript_TerrainFormChanges
	call BattleScript_TerrainSeedLoop
	return

BattleScript_BurningSurgeActivatesEnd3::
	call BattleScript_BurningSurgeActivatesReturn
	end3

BattleScript_CurseSurgeActivates::
	pause B_WAIT_TIME_SHORT
	call BattleScript_AbilityPopUp
	printstring STRINGID_TERRAINBECOMESCURSED
	waitmessage B_WAIT_TIME_LONG
	playanimation BS_SCRIPTING, B_ANIM_RESTORE_BG, NULL
	call BattleScript_TerrainFormChanges
	call BattleScript_TerrainSeedLoop
	end3

BattleScript_SandySurgeActivates::
	pause B_WAIT_TIME_SHORT
	call BattleScript_AbilityPopUp
	printstring STRINGID_TERRAINBECOMESSANDY
	waitmessage B_WAIT_TIME_LONG
	playanimation BS_SCRIPTING, B_ANIM_RESTORE_BG, NULL
	call BattleScript_TerrainFormChanges
	call BattleScript_TerrainSeedLoop
	end3

BattleScript_SwampSurgeActivates::
	pause B_WAIT_TIME_SHORT
	call BattleScript_AbilityPopUp
	printstring STRINGID_TERRAINBECOMESSWAMP
	waitmessage B_WAIT_TIME_LONG
	playanimation BS_SCRIPTING, B_ANIM_RESTORE_BG, NULL
	call BattleScript_TerrainFormChanges
	call BattleScript_TerrainSeedLoop
	end3

BattleScript_VenomousSurgeActivates::
	pause B_WAIT_TIME_SHORT
	call BattleScript_AbilityPopUp
	printstring STRINGID_TERRAINBECOMESVENOMOUS
	waitmessage B_WAIT_TIME_LONG
	playanimation BS_SCRIPTING, B_ANIM_RESTORE_BG, NULL
	call BattleScript_TerrainFormChanges
	call BattleScript_TerrainSeedLoop
	end3

BattleScript_FrozenSurgeActivates::
	pause B_WAIT_TIME_SHORT
	call BattleScript_AbilityPopUp
	printstring STRINGID_TERRAINBECOMESFROZEN
	waitmessage B_WAIT_TIME_LONG
	playanimation BS_SCRIPTING, B_ANIM_RESTORE_BG, NULL
	call BattleScript_TerrainFormChanges
	call BattleScript_TerrainSeedLoop
	end3

BattleScript_SweetDreamsActivates::
	setbyte gBattlerTarget, 0
	call BattleScript_AbilityPopUp
BattleScript_SweetDreamsLoop:
	trygetsweetdreamstarget BattleScript_SweetDreamsEnd
	dmg_1_8_targethp
	manipulatedamage DMG_CHANGE_SIGN
	orword gHitMarker, HITMARKER_IGNORE_SUBSTITUTE | HITMARKER_PASSIVE_DAMAGE
	printstring STRINGID_BADDREAMSDMG
	waitmessage B_WAIT_TIME_LONG
	healthbarupdate BS_TARGET
	datahpupdate BS_TARGET
	tryfaintmon BS_TARGET, FALSE, NULL
	atk24 BattleScript_SweetDreamsIncrement
BattleScript_SweetDreamsIncrement:
	addbyte gBattlerTarget, 1
	goto BattleScript_SweetDreamsLoop
BattleScript_SweetDreamsEnd:
	end3

BattleScript_BadDreamsActivates::
	setbyte gBattlerTarget, 0
	call BattleScript_AbilityPopUp
BattleScript_BadDreamsLoop:
	trygetbaddreamstarget BattleScript_BadDreamsEnd
	dmg_1_8_targethp
	orword gHitMarker, HITMARKER_IGNORE_SUBSTITUTE | HITMARKER_PASSIVE_DAMAGE
	printstring STRINGID_BADDREAMSDMG
	waitmessage B_WAIT_TIME_LONG
	jumpifmagicguarded BS_TARGET, BattleScript_BadDreamsIncrement
	healthbarupdate BS_TARGET
	datahpupdate BS_TARGET
	tryfaintmon BS_TARGET, FALSE, NULL
	atk24 BattleScript_BadDreamsIncrement
BattleScript_BadDreamsIncrement:
	addbyte gBattlerTarget, 1
	goto BattleScript_BadDreamsLoop
BattleScript_BadDreamsEnd:
	end3

BattleScript_SpatialDistortionActivates::
	setbyte gBattlerTarget, 0
	call BattleScript_AbilityPopUp
BattleScript_SpatialDistortionLoop:
	trygetspatialdistortiontarget BattleScript_SpatialDistortionEnd
	orword gHitMarker, HITMARKER_IGNORE_SUBSTITUTE | HITMARKER_PASSIVE_DAMAGE
	printstring STRINGID_BADDREAMSDMG
	waitmessage B_WAIT_TIME_LONG
	jumpifmagicguarded BS_TARGET, BattleScript_SpatialDistortionIncrement
	healthbarupdate BS_TARGET
	datahpupdate BS_TARGET
	tryfaintmon BS_TARGET, FALSE, NULL
	goto BattleScript_SpatialDistortionIncrement
BattleScript_SpatialDistortionIncrement:
	addbyte gBattlerTarget, 1
	goto BattleScript_SpatialDistortionLoop
BattleScript_SpatialDistortionEnd:
	end3

BattleScript_TookAttack::
	attackstring
	pause B_WAIT_TIME_SHORT
	printstring STRINGID_PKMNSXTOOKATTACK
	waitmessage B_WAIT_TIME_LONG
	orword gHitMarker, HITMARKER_ATTACKSTRING_PRINTED
	return

BattleScript_SturdyPreventsOHKO::
	pause B_WAIT_TIME_SHORT
	call BattleScript_AbilityPopUp
	printstring STRINGID_PKMNPROTECTEDBY
	pause B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_DampStopsExplosion::
	pause B_WAIT_TIME_SHORT
	copybyte gBattlerAbility, gBattlerTarget
	call BattleScript_AbilityPopUp
	printstring STRINGID_PKMNPREVENTSUSAGE
	pause B_WAIT_TIME_LONG
	moveendto MOVEEND_NEXT_TARGET
	moveendcase MOVEEND_CLEAR_BITS
	end

BattleScript_MoveHPDrain_PPLoss::
	ppreduce
BattleScript_MoveHPDrain::
	attackstring
	pause B_WAIT_TIME_SHORT
	call BattleScript_AbilityPopUp
	orword gHitMarker, HITMARKER_IGNORE_SUBSTITUTE
	healthbarupdate BS_TARGET
	datahpupdate BS_TARGET
	printstring STRINGID_PKMNRESTOREDHPUSING
	waitmessage B_WAIT_TIME_LONG
	orhalfword gMoveResultFlags, MOVE_RESULT_DOESNT_AFFECT_FOE
	goto BattleScript_MoveEnd

BattleScript_MoveStatDrain_PPLoss::
	ppreduce
BattleScript_MoveStatDrain::
	attackstring
	pause B_WAIT_TIME_SHORT
	call BattleScript_AbilityPopUp
	setgraphicalstatchangevalues
	playanimation BS_TARGET, B_ANIM_STATS_CHANGE, sB_ANIM_ARG1
	waitanimation
	printstring STRINGID_TARGETABILITYSTATRAISE
	waitmessage B_WAIT_TIME_LONG
	clearsemiinvulnerablebit
	tryfaintmon BS_ATTACKER, FALSE, NULL
	goto BattleScript_MoveEnd

BattleScript_MonMadeMoveUseless_PPLoss::
	ppreduce
BattleScript_MonMadeMoveUseless::
	attackstring
	pause B_WAIT_TIME_SHORT
	call BattleScript_AbilityPopUp
	printstring STRINGID_PKMNSXMADEYUSELESS
	waitmessage B_WAIT_TIME_LONG
	tryfaintmon BS_ATTACKER, FALSE, NULL
	orhalfword gMoveResultFlags, MOVE_RESULT_DOESNT_AFFECT_FOE
	goto BattleScript_MoveEnd

BattleScript_FlashFireBoost_PPLoss::
	ppreduce
BattleScript_FlashFireBoost::
	attackstring
	pause B_WAIT_TIME_SHORT
	call BattleScript_AbilityPopUp
	printfromtable gFlashFireStringIds
	waitmessage B_WAIT_TIME_LONG
	tryfaintmon BS_ATTACKER, FALSE, NULL
	goto BattleScript_MoveEnd

BattleScript_AbilityPreventsPhasingOut::
	pause B_WAIT_TIME_SHORT
	call BattleScript_AbilityPopUp
	printstring STRINGID_PKMNANCHORSITSELFWITH
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_AbilityNoStatLoss::
	pause B_WAIT_TIME_SHORT
	call BattleScript_AbilityPopUp
	printstring STRINGID_PKMNPREVENTSSTATLOSSWITH
	waitmessage B_WAIT_TIME_LONG
	return

BattleScript_BRNPrevention::
	pause B_WAIT_TIME_SHORT
	printfromtable gBRNPreventionStringIds
	waitmessage B_WAIT_TIME_LONG
	return

BattleScript_AbilityBRNPrevention::
	pause B_WAIT_TIME_SHORT
	call BattleScript_AbilityPopUp
	printfromtable gBRNPreventionStringIds
	waitmessage B_WAIT_TIME_LONG
	return

BattleScript_FBTPrevention::
	pause B_WAIT_TIME_SHORT
	printfromtable gFBTPreventionStringIds
	waitmessage B_WAIT_TIME_LONG
	return

BattleScript_AbilityFBTPrevention::
	pause B_WAIT_TIME_SHORT
	call BattleScript_AbilityPopUp
	printfromtable gFBTPreventionStringIds
	waitmessage B_WAIT_TIME_LONG
	return

BattleScript_PRLZPrevention::
	pause B_WAIT_TIME_SHORT
	printfromtable gPRLZPreventionStringIds
	waitmessage B_WAIT_TIME_LONG
	return

BattleScript_AbilityPRLZPrevention::
	pause B_WAIT_TIME_SHORT
	call BattleScript_AbilityPopUp
	printfromtable gPRLZPreventionStringIds
	waitmessage B_WAIT_TIME_LONG
	return

BattleScript_PSNPrevention::
	pause B_WAIT_TIME_SHORT
	printfromtable gPSNPreventionStringIds
	waitmessage B_WAIT_TIME_LONG
	return

BattleScript_AbilityPSNPrevention::
	pause B_WAIT_TIME_SHORT
	call BattleScript_AbilityPopUp
	printfromtable gPSNPreventionStringIds
	waitmessage B_WAIT_TIME_LONG
	return

BattleScript_ObliviousPreventsAttraction::
	pause B_WAIT_TIME_SHORT
	call BattleScript_AbilityPopUp
	printstring STRINGID_PKMNPREVENTSROMANCEWITH
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_OwnTempoPrevents::
	pause B_WAIT_TIME_SHORT
	call BattleScript_AbilityPopUp
	printstring STRINGID_PKMNPREVENTSCONFUSIONWITH
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_SoundproofProtected::
	attackstring
	ppreduce
	pause B_WAIT_TIME_SHORT
	call BattleScript_AbilityPopUp
	printstring STRINGID_PKMNSXBLOCKSY
	waitmessage B_WAIT_TIME_LONG
	orhalfword gMoveResultFlags, MOVE_RESULT_DOESNT_AFFECT_FOE
	goto BattleScript_MoveEnd

BattleScript_DazzlingProtected::
	attackstring
	ppreduce
	pause B_WAIT_TIME_SHORT
	call BattleScript_AbilityPopUp
	printstring STRINGID_POKEMONCANNOTUSEMOVE
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_MoveUsedPsychicTerrainPrevents::
	printstring STRINGID_POKEMONCANNOTUSEMOVE
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_GrassyTerrainHeals::
	setbyte gBattleCommunication, 0
BattleScript_GrassyTerrainLoop:
	copyarraywithindex gBattlerAttacker, gBattlerByTurnOrder, gBattleCommunication, 1
	checkgrassyterrainheal BS_ATTACKER, BattleScript_GrassyTerrainLoopIncrement
	printstring STRINGID_GRASSYTERRAINHEALS
	waitmessage B_WAIT_TIME_LONG
BattleScript_GrassyTerrainHpChange:
	orword gHitMarker, HITMARKER_SKIP_DMG_TRACK | HITMARKER_IGNORE_SUBSTITUTE | HITMARKER_PASSIVE_DAMAGE
	healthbarupdate BS_ATTACKER
	datahpupdate BS_ATTACKER
BattleScript_GrassyTerrainLoopIncrement::
	addbyte gBattleCommunication, 1
	jumpifbytenotequal gBattleCommunication, gBattlersCount, BattleScript_GrassyTerrainLoop
BattleScript_GrassyTerrainLoopEnd::
	bicword gHitMarker, HITMARKER_SKIP_DMG_TRACK | HITMARKER_IGNORE_SUBSTITUTE | HITMARKER_PASSIVE_DAMAGE
	jumpifword CMP_COMMON_BITS, gFieldStatuses, STATUS_FIELD_TERRAIN_PERMANENT, BattleScript_GrassyTerrainHealEnd
	jumpifbyte CMP_EQUAL, gFieldTimers + 5, 0, BattleScript_GrassyTerrainEnds
BattleScript_GrassyTerrainHealEnd:
	end2

BattleScript_PhantomForestDamage::
	setbyte gBattleCommunication, 0
BattleScript_PhantomForestLoop:
	copyarraywithindex gBattlerAttacker, gBattlerByTurnOrder, gBattleCommunication, 1
	checkphantomforestdamage BS_ATTACKER, BattleScript_PhantomForestLoopIncrement
	playanimation BS_ATTACKER, B_ANIM_LEECH_SEED_DRAIN, sB_ANIM_ARG1
	orword gHitMarker, HITMARKER_IGNORE_SUBSTITUTE | HITMARKER_PASSIVE_DAMAGE
	healthbarupdate BS_ATTACKER
	datahpupdate BS_ATTACKER
	copyword gBattleMoveDamage, gHpDealt
	jumpifstatus3 BS_TARGET, STATUS3_HEAL_BLOCK, BattleScript_PhantomForestLoopIncrement
	jumpifcursedterrainblocked BS_TARGET, BattleScript_PhantomForestLoopIncrement
	swapattackerwithtarget
	manipulatedamage DMG_BIG_ROOT
	swapattackerwithtarget
BattleScript_PhantomForestTurnPrintAndUpdateHp:
	orword gHitMarker, HITMARKER_IGNORE_SUBSTITUTE | HITMARKER_PASSIVE_DAMAGE
	healthbarupdate BS_TARGET
	datahpupdate BS_TARGET
	printstring STRINGID_PHANTOM_FOREST_DRAIN
	waitmessage B_WAIT_TIME_LONG
	tryfaintmon BS_ATTACKER, FALSE, NULL
BattleScript_PhantomForestLoopIncrement::
	addbyte gBattleCommunication, 1
	jumpifbytenotequal gBattleCommunication, gBattlersCount, BattleScript_PhantomForestLoop
	bicword gHitMarker, HITMARKER_SKIP_DMG_TRACK | HITMARKER_PASSIVE_DAMAGE
BattleScript_PhantomForestHealEnd:
	end2

BattleScript_PhantomForestHealBlock:
	setword gBattleMoveDamage, 0
	goto BattleScript_PhantomForestTurnPrintAndUpdateHp


BattleScript_FancifulFireworksDamage::
	setbyte gBattleCommunication, 0
BattleScript_FancifulFireworksLoop:
	copyarraywithindex gBattlerAttacker, gBattlerByTurnOrder, gBattleCommunication, 1
	checkiffancifulfireworksdamage BS_ATTACKER, BattleScript_FancifulFireworksLoopIncrement
	playanimation BS_ATTACKER, B_ANIM_FANCIFUL_FIREWORKS, NULL
	waitanimation
	printstring STRINGID_FANCIFULFIREWORKSEXPLOSION
	waitmessage B_WAIT_TIME_LONG
	orword gHitMarker, HITMARKER_IGNORE_SUBSTITUTE | HITMARKER_PASSIVE_DAMAGE
	healthbarupdate BS_ATTACKER
	datahpupdate BS_ATTACKER
	tryfaintmon BS_ATTACKER, FALSE, NULL
BattleScript_FancifulFireworksLoopIncrement::
	addbyte gBattleCommunication, 1
	jumpifbytenotequal gBattleCommunication, gBattlersCount, BattleScript_FancifulFireworksLoop
	bicword gHitMarker, HITMARKER_SKIP_DMG_TRACK | HITMARKER_PASSIVE_DAMAGE
BattleScript_FancifulFireworksHealEnd:
	end2

BattleScript_ThunderstormDamage::
	setbyte gBattleCommunication, 0
BattleScript_ThunderstormLoop:
	copyarraywithindex gBattlerAttacker, gBattlerByTurnOrder, gBattleCommunication, 1
	checkthunderstormdamage BS_ATTACKER, BattleScript_ThunderstormLoopIncrement
	playanimation BS_ATTACKER, B_ANIM_THUNDERSTORM, NULL
	waitanimation
	orword gHitMarker, HITMARKER_SKIP_DMG_TRACK | HITMARKER_PASSIVE_DAMAGE
	healthbarupdate BS_ATTACKER
	datahpupdate BS_ATTACKER
	printstring STRINGID_THUNDERSTORMSTRIKE
	waitmessage B_WAIT_TIME_LONG
	tryfaintmon BS_ATTACKER, FALSE, NULL
BattleScript_ThunderstormLoopIncrement::
	addbyte gBattleCommunication, 1
	jumpifbytenotequal gBattleCommunication, gBattlersCount, BattleScript_ThunderstormLoop
	bicword gHitMarker, HITMARKER_SKIP_DMG_TRACK | HITMARKER_PASSIVE_DAMAGE
BattleScript_ThunderstormHealEnd:
	end2

BattleScript_ThunderstormEnds::
	printstring STRINGID_THUNDERSTORMENDS
	waitmessage B_WAIT_TIME_LONG
	end2

BattleScript_BurningTerrainDamage::
	setbyte gBattleCommunication, 0
BattleScript_BurningTerrainLoop:
	copyarraywithindex gBattlerAttacker, gBattlerByTurnOrder, gBattleCommunication, 1
	checkburningterraindamage BS_ATTACKER, BattleScript_BurningTerrainLoopIncrement
	playanimation BS_ATTACKER, B_ANIM_BURNING_TERRAIN, NULL
	printstring STRINGID_BURNINGTERRAINDAMAGE
	waitmessage B_WAIT_TIME_LONG
BattleScript_BurningTerrainHpChange:
	orword gHitMarker, HITMARKER_SKIP_DMG_TRACK | HITMARKER_IGNORE_SUBSTITUTE | HITMARKER_PASSIVE_DAMAGE
	healthbarupdate BS_ATTACKER
	datahpupdate BS_ATTACKER
	tryfaintmon BS_ATTACKER, FALSE, NULL
BattleScript_BurningTerrainLoopIncrement::
	addbyte gBattleCommunication, 1
	jumpifbytenotequal gBattleCommunication, gBattlersCount, BattleScript_BurningTerrainLoop
BattleScript_BurningTerrainLoopEnd::
	bicword gHitMarker, HITMARKER_SKIP_DMG_TRACK | HITMARKER_IGNORE_SUBSTITUTE | HITMARKER_PASSIVE_DAMAGE
	jumpifword CMP_COMMON_BITS, gFieldStatuses, STATUS_FIELD_TERRAIN_PERMANENT, BattleScript_BurningTerrainDamageEnd
	jumpifbyte CMP_EQUAL, gFieldTimers + 5, 0, BattleScript_BurningTerrainEnds
BattleScript_BurningTerrainDamageEnd:
	end2

BattleScript_VenomousTerrainPoison::
	setbyte gBattleCommunication, 0
BattleScript_VenomousTerrainLoop:
	copyarraywithindex gBattlerAttacker, gBattlerByTurnOrder, gBattleCommunication, 1
	checkvenomousterrainpoison BS_ATTACKER, BattleScript_VenomousTerrainLoopIncrement
BattleScript_VenomousTerrainPoisonStatus:
	statusanimation BS_ATTACKER
	printstring STRINGID_VENOMOUSTERRAINPOISON
	waitmessage B_WAIT_TIME_LONG
	updatestatusicon BS_ATTACKER
	waitstate
BattleScript_VenomousTerrainLoopIncrement::
	addbyte gBattleCommunication, 1
	jumpifbytenotequal gBattleCommunication, gBattlersCount, BattleScript_VenomousTerrainLoop
BattleScript_VenomousTerrainLoopEnd::
	jumpifword CMP_COMMON_BITS, gFieldStatuses, STATUS_FIELD_TERRAIN_PERMANENT, BattleScript_VenomousTerrainDamageEnd
	jumpifbyte CMP_EQUAL, gFieldTimers + 5, 0, BattleScript_VenomousTerrainEnds
BattleScript_VenomousTerrainDamageEnd:
	end2

BattleScript_KingsGraceHeals::
	setbyte gBattleCommunication, 0
BattleScript_KingsGraceLoop:
	copyarraywithindex gBattlerAttacker, gBattlerByTurnOrder, gBattleCommunication, 1
	checkKingsGraceheal BS_ATTACKER, BattleScript_KingsGraceLoopIncrement
	printstring STRINGID_KINGSGRACEHEALS
	waitmessage B_WAIT_TIME_LONG
BattleScript_KingsGraceHpChange:
	orword gHitMarker, HITMARKER_SKIP_DMG_TRACK | HITMARKER_IGNORE_SUBSTITUTE | HITMARKER_PASSIVE_DAMAGE
	healthbarupdate BS_ATTACKER
	datahpupdate BS_ATTACKER
BattleScript_KingsGraceLoopIncrement::
	addbyte gBattleCommunication, 1
	jumpifbytenotequal gBattleCommunication, gBattlersCount, BattleScript_KingsGraceLoop
BattleScript_KingsGraceLoopEnd::
	bicword gHitMarker, HITMARKER_SKIP_DMG_TRACK | HITMARKER_IGNORE_SUBSTITUTE | HITMARKER_PASSIVE_DAMAGE
BattleScript_KingsGraceHealEnd:
	end2

BattleScript_AbilityNoSpecificStatLoss::
	pause B_WAIT_TIME_SHORT
	call BattleScript_AbilityPopUp
	printstring STRINGID_PKMNSXPREVENTSYLOSS
	waitmessage B_WAIT_TIME_LONG
	setbyte cMULTISTRING_CHOOSER, B_MSG_STAT_FELL_EMPTY
	orhalfword gMoveResultFlags, MOVE_RESULT_NO_EFFECT
	return

BattleScript_StickyHoldActivates::
	pause B_WAIT_TIME_SHORT
	call BattleScript_AbilityPopUp
	printstring STRINGID_INNATEMADEINEFFECTIVE
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_MoveEnd

BattleScript_ColorChangeActivates::
	call BattleScript_AbilityPopUp
	printstring STRINGID_PKMNCHANGEDTYPEWITH
	waitmessage B_WAIT_TIME_LONG
	return

BattleScript_MimicryActivatesEnd3::
	call BattleScript_MimicryActivatesReturn
	end3

BattleScript_MimicryActivatesReturn::
	pause B_WAIT_TIME_SHORT
	call BattleScript_AbilityPopUp
	printstring STRINGID_BATTLERTYPECHANGEDTO
	waitmessage B_WAIT_TIME_LONG
	return

BattleScript_ProteanActivates::
	call BattleScript_AbilityPopUp
	printstring STRINGID_PKMNCHANGEDTYPE
	waitmessage B_WAIT_TIME_LONG
	return

BattleScript_LegendPowerActivates::
	pause 5
	printstring STRINGID_MOVECHANGEDTYPE
	waitmessage B_WAIT_TIME_LONG
	return

BattleScript_LegendPlateActivates::
	pause 5
	printstring STRINGID_EMPTYSTRING3
	waitmessage 1
	handleformchange BS_ATTACKER, 0
	playanimation BS_ATTACKER, B_ANIM_FORM_CHANGE, NULL
	waitanimation
	printstring STRINGID_PKMNCHANGEDTYPE
	waitmessage B_WAIT_TIME_LONG
	return

BattleScript_CursedBodyActivates::
	call BattleScript_AbilityPopUp
	printstring STRINGID_CUSEDBODYDISABLED
	waitmessage B_WAIT_TIME_LONG
	return

BattleScript_HauntedSpiritActivates::
	call BattleScript_AbilityPopUp
	printstring STRINGID_HAUNTED_SPIRIT_CURSE
	waitmessage B_WAIT_TIME_LONG
	return

BattleScript_PandemicInfection::
	call BattleScript_AbilityPopUp
	printfromtable gCordycepsStringIds
	waitmessage B_WAIT_TIME_LONG
	return

BattleScript_GrimtoothActivates::
	call BattleScript_AbilityPopUp
	printstring STRINGID_CLOAK_REMOVED
	waitmessage B_WAIT_TIME_LONG
	return

BattleScript_MummyActivates::
	call BattleScript_AbilityPopUp
	printstring STRINGID_ATTACKERACQUIREDABILITY
	waitmessage B_WAIT_TIME_LONG
	return

BattleScript_WanderingSpiritActivates::
.if B_ABILITY_POP_UP == TRUE
	setbyte sFIXED_ABILITY_POPUP, TRUE
	sethword sABILITY_OVERWRITE, ABILITY_WANDERING_SPIRIT
	showabilitypopup BS_TARGET
	pause 60
	sethword sABILITY_OVERWRITE, 0
	updateabilitypopup BS_TARGET
	pause 20
	destroyabilitypopup
	pause 40
	
	setbyte sFIXED_ABILITY_POPUP, TRUE
	copyhword sABILITY_OVERWRITE, gLastUsedAbility
	showabilitypopup BS_ATTACKER
	pause 60
	sethword sABILITY_OVERWRITE, 0
	updateabilitypopup BS_ATTACKER
	pause 20
	destroyabilitypopup
	pause 40
.endif
	printstring STRINGID_SWAPPEDABILITIES
	waitmessage B_WAIT_TIME_LONG
	switchinabilities BS_ATTACKER
	switchinabilities BS_TARGET
	return

BattleScript_TargetsStatWasMaxedOut::
	call BattleScript_AbilityPopUp
	statbuffchange STAT_BUFF_NOT_PROTECT_AFFECTED | MOVE_EFFECT_CERTAIN, NULL
	setgraphicalstatchangevalues
	playanimation BS_TARGET, B_ANIM_STATS_CHANGE, sB_ANIM_ARG1
	printstring STRINGID_TARGETSSTATWASMAXEDOUT
	waitmessage B_WAIT_TIME_LONG
	return

BattleScript_BattlerAbilityStatRaiseOnSwitchIn::
	copybyte gBattlerAbility, gBattlerAttacker
	call BattleScript_AbilityPopUp
	statbuffchange MOVE_EFFECT_AFFECTS_ATTACKER | STAT_BUFF_NOT_PROTECT_AFFECTED | MOVE_EFFECT_CERTAIN, NULL
	setgraphicalstatchangevalues
	playanimation BS_ATTACKER, B_ANIM_STATS_CHANGE, sB_ANIM_ARG1
	waitanimation
	printstring STRINGID_BATTLERABILITYRAISEDSTAT
	waitmessage B_WAIT_TIME_LONG
	end3

BattleScript_EvoboostSyncRaiseStat::
	statbuffchange MOVE_EFFECT_AFFECTS_ATTACKER | STAT_BUFF_NOT_PROTECT_AFFECTED | MOVE_EFFECT_CERTAIN, NULL
	setgraphicalstatchangevalues
	playanimation BS_ATTACKER, B_ANIM_STATS_CHANGE, sB_ANIM_ARG1
	waitanimation
	printstring STRINGID_BATTLERABILITYRAISEDSTAT
	waitmessage B_WAIT_TIME_LONG
	return

BattleScript_HeroInTrainingActivates::
	call BattleScript_HeroInTrainingIntro
	setstatchanger STAT_ATK, 1, FALSE
	statbuffchange MOVE_EFFECT_AFFECTS_ATTACKER | STAT_BUFF_NOT_PROTECT_AFFECTED | MOVE_EFFECT_CERTAIN, NULL
	setgraphicalstatchangevalues
	playanimation BS_ATTACKER, B_ANIM_STATS_CHANGE, sB_ANIM_ARG1
	printfromtable gStatUpStringIds
	waitmessage B_WAIT_TIME_LONG
	end3

BattleScript_HeroInTrainingActivatesNoBoost::
	call BattleScript_HeroInTrainingIntro
	end3

BattleScript_HeroInTrainingIntro:
	copybyte gBattlerAbility, gBattlerAttacker
	call BattleScript_AbilityPopUp
	printstring STRINGID_HERO_IN_TRAINING
	waitmessage B_WAIT_TIME_LONG
	handleformchange BS_ATTACKER, 4
	handleformchange BS_ATTACKER, 2
	return

BattleScript_TargetAbilityStatRaiseOnMoveEnd::
	call BattleScript_AbilityPopUp
	statbuffchange STAT_BUFF_NOT_PROTECT_AFFECTED | MOVE_EFFECT_CERTAIN, NULL
	setgraphicalstatchangevalues
	playanimation BS_TARGET, B_ANIM_STATS_CHANGE, sB_ANIM_ARG1
	waitanimation
	printstring STRINGID_BATTLERABILITYRAISEDSTAT2
	waitmessage B_WAIT_TIME_LONG
	return

BattleScript_RagnarokActivates::
	call BattleScript_AbilityPopUp
	printstring STRINGID_ACTIVATESRAGNAROK
	waitmessage B_WAIT_TIME_LONG
	return

BattleScript_AttackerAbilityLoweredTargetStatOnMoveEnd::
	call BattleScript_AbilityPopUp
	statbuffchange STAT_BUFF_NOT_PROTECT_AFFECTED, NULL
	setgraphicalstatchangevalues
	playanimation BS_TARGET, B_ANIM_STATS_CHANGE, sB_ANIM_ARG1
	waitanimation
	printstring STRINGID_BATTLERABILITYLOWEREDSTAT
	waitmessage B_WAIT_TIME_LONG
	return

BattleScript_AttackerAbilityLoweredTargetTwoStatsOnMoveEnd::
	call BattleScript_AbilityPopUp
	jumpifbyteequal sSTATCHANGER, sZero, BattleScript_SecondLower
	statbuffchange STAT_BUFF_NOT_PROTECT_AFFECTED, BattleScript_SecondLower
	jumpifbyte CMP_GREATER_THAN, cMULTISTRING_CHOOSER, B_MSG_DEFENDER_STAT_FELL, BattleScript_SecondRaise
	setgraphicalstatchangevalues
	playanimation BS_TARGET, B_ANIM_STATS_CHANGE, sB_ANIM_ARG1
	waitanimation
	printstring STRINGID_BATTLERABILITYLOWEREDSTAT
	waitmessage B_WAIT_TIME_LONG
BattleScript_SecondLower:
	jumpifbyteequal sSAVED_STAT_CHANGER, sZero, BattleScript_AbilityLowerEnd
	copybyte sSTATCHANGER, sSAVED_STAT_CHANGER
	statbuffchange STAT_BUFF_NOT_PROTECT_AFFECTED, BattleScript_AbilityLowerEnd
	jumpifbyte CMP_GREATER_THAN, cMULTISTRING_CHOOSER, B_MSG_DEFENDER_STAT_FELL, BattleScript_AbilityLowerEnd
	setgraphicalstatchangevalues
	playanimation BS_TARGET, B_ANIM_STATS_CHANGE, sB_ANIM_ARG1
	printfromtable gStatDownStringIds
	waitmessage B_WAIT_TIME_LONG
BattleScript_AbilityLowerEnd:
	updatestatusicon BS_TARGET
	return

BattleScript_TargetAbilityTwoStatsRaiseOnMoveEnd::
	call BattleScript_AbilityPopUp
	jumpifbyteequal sSTATCHANGER, sZero, BattleScript_SecondRaise
	statbuffchange MOVE_EFFECT_CERTAIN | STAT_BUFF_NOT_PROTECT_AFFECTED, BattleScript_SecondRaise
	jumpifbyte CMP_GREATER_THAN, cMULTISTRING_CHOOSER, B_MSG_DEFENDER_STAT_ROSE, BattleScript_SecondRaise
	setgraphicalstatchangevalues
	playanimation BS_TARGET, B_ANIM_STATS_CHANGE, sB_ANIM_ARG1
	printfromtable gStatUpStringIds
	waitmessage B_WAIT_TIME_LONG
BattleScript_SecondRaise:
	jumpifbyteequal sSAVED_STAT_CHANGER, sZero, BattleScript_AbilityRaiseEnd
	copybyte sSTATCHANGER, sSAVED_STAT_CHANGER
	statbuffchange MOVE_EFFECT_CERTAIN | STAT_BUFF_NOT_PROTECT_AFFECTED, BattleScript_AbilityRaiseEnd
	jumpifbyte CMP_GREATER_THAN, cMULTISTRING_CHOOSER, B_MSG_DEFENDER_STAT_ROSE, BattleScript_AbilityRaiseEnd
	setgraphicalstatchangevalues
	playanimation BS_TARGET, B_ANIM_STATS_CHANGE, sB_ANIM_ARG1
	printfromtable gStatUpStringIds
	waitmessage B_WAIT_TIME_LONG
BattleScript_AbilityRaiseEnd:
	updatestatusicon BS_TARGET
	return

BattleScript_UltimateShowndownActivate::
	call BattleScript_AbilityPopUp
	swapattackerwithtarget
	call BattleScript_AllStatsUp
	swapattackerwithtarget
	return

BattleScript_ScriptingAbilitySoulAbsorbed::
	copybyte gBattlerAbility, sBATTLER
	call BattleScript_AbilityPopUp
	copybyte sSAVED_DMG, gBattlerAttacker
	copybyte gBattlerAttacker, sBATTLER
	healthbarupdate BS_ATTACKER
	datahpupdate BS_ATTACKER
	printstring STRINGID_SOUL_ABSORBED
	waitmessage B_WAIT_TIME_LONG
	copybyte gBattlerAttacker, sSAVED_DMG
	return

BattleScript_ScriptingAbilityStatRaise::
	copybyte gBattlerAbility, sBATTLER
	call BattleScript_AbilityPopUp
	copybyte sSAVED_DMG, gBattlerAttacker
	copybyte gBattlerAttacker, sBATTLER
	statbuffchange STAT_BUFF_NOT_PROTECT_AFFECTED | MOVE_EFFECT_CERTAIN, NULL
	setgraphicalstatchangevalues
	playanimation BS_SCRIPTING, B_ANIM_STATS_CHANGE, sB_ANIM_ARG1
	waitanimation
	printstring STRINGID_ATTACKERABILITYSTATRAISE
	waitmessage B_WAIT_TIME_LONG
	copybyte gBattlerAttacker, sSAVED_DMG
	return

BattleScript_ScriptingStatusCondition::
	copybyte sSAVED_DMG, gBattlerAttacker
	copybyte gBattlerAttacker, sBATTLER
	setbyte cMULTISTRING_CHOOSER, 0
	copybyte gEffectBattler, gBattlerAttacker
	orword gHitMarker, HITMARKER_PASSIVE_DAMAGE
	healthbarupdate BS_EFFECT_BATTLER
	datahpupdate BS_EFFECT_BATTLER
	tryfaintmon BS_EFFECT_BATTLER, FALSE, NULL
	statusanimation BS_EFFECT_BATTLER
	printfromtable gGotBurnedStringIds
	waitmessage B_WAIT_TIME_LONG
	updatestatusicon BS_EFFECT_BATTLER
	waitstate
	copybyte gBattlerAttacker, sSAVED_DMG
	return

BattleScript_ForestWitchActivates::
	call BattleScript_AbilityPopUp
BattleScript_ForestWitchTryAtk:
	setbyte sSTAT_ANIM_PLAYED, FALSE
	playstatchangeanimation BS_TARGET, BIT_ATK | BIT_SPATK | BIT_SPDEF, 0
	setstatchanger STAT_ATK, 1, FALSE
	statbuffchange STAT_CHANGE_ALLOW_PTR, BattleScript_ForestWitchTrySpAtk
	jumpifbyte CMP_EQUAL, cMULTISTRING_CHOOSER, B_MSG_STAT_WONT_INCREASE, BattleScript_ForestWitchTrySpAtk
	printfromtable gStatUpStringIds
	waitmessage B_WAIT_TIME_LONG
BattleScript_ForestWitchTrySpAtk:
	setstatchanger STAT_SPATK, 1, FALSE
	statbuffchange STAT_CHANGE_ALLOW_PTR, BattleScript_ForestWitchTrySpDef
	jumpifbyte CMP_EQUAL, cMULTISTRING_CHOOSER, B_MSG_STAT_WONT_INCREASE, BattleScript_ForestWitchTrySpDef
	printfromtable gStatUpStringIds
	waitmessage B_WAIT_TIME_LONG
BattleScript_ForestWitchTrySpDef:
	setstatchanger STAT_SPDEF, 1, FALSE
	statbuffchange STAT_CHANGE_ALLOW_PTR, BattleScript_ForestWitchActivatesEnd
	jumpifbyte CMP_EQUAL, cMULTISTRING_CHOOSER, B_MSG_STAT_WONT_INCREASE, BattleScript_ForestWitchActivatesEnd
	printfromtable gStatUpStringIds
	waitmessage B_WAIT_TIME_LONG
BattleScript_ForestWitchActivatesEnd:
	return

BattleScript_WeakArmorActivates::
	call BattleScript_AbilityPopUp
	setbyte sSTAT_ANIM_PLAYED, FALSE
	playstatchangeanimation BS_TARGET, BIT_DEF | BIT_SPDEF, STAT_CHANGE_NEGATIVE
	setstatchanger STAT_DEF, 1, TRUE
	statbuffchange STAT_CHANGE_ALLOW_PTR, BattleScript_WeakArmorTrySpDef
	jumpifbyte CMP_EQUAL, cMULTISTRING_CHOOSER, B_MSG_STAT_WONT_DECREASE, BattleScript_WeakArmorTrySpDef
	printfromtable gStatDownStringIds
	waitmessage B_WAIT_TIME_LONG
BattleScript_WeakArmorTrySpDef:
	setstatchanger STAT_SPDEF, 1, TRUE
	statbuffchange STAT_CHANGE_ALLOW_PTR, BattleScript_WeakArmorTrySpeed
	jumpifbyte CMP_EQUAL, cMULTISTRING_CHOOSER, B_MSG_STAT_WONT_DECREASE, BattleScript_WeakArmorTrySpeed
	printfromtable gStatUpStringIds
	waitmessage B_WAIT_TIME_LONG
BattleScript_WeakArmorTrySpeed:
	setbyte sSTAT_ANIM_PLAYED, FALSE
	playstatchangeanimation BS_TARGET, BIT_SPEED | BIT_ATK | BIT_SPATK, 0
	setstatchanger STAT_SPEED, 1, FALSE
	statbuffchange STAT_CHANGE_ALLOW_PTR, BattleScript_WeakArmorTryAtk
	jumpifbyte CMP_EQUAL, cMULTISTRING_CHOOSER, B_MSG_STAT_WONT_INCREASE, BattleScript_WeakArmorTryAtk
	printfromtable gStatDownStringIds
	waitmessage B_WAIT_TIME_LONG
BattleScript_WeakArmorTryAtk:
	setstatchanger STAT_ATK, 1, FALSE
	statbuffchange STAT_CHANGE_ALLOW_PTR, BattleScript_WeakArmorTrySpAtk
	jumpifbyte CMP_EQUAL, cMULTISTRING_CHOOSER, B_MSG_STAT_WONT_INCREASE, BattleScript_WeakArmorTrySpAtk
	printfromtable gStatUpStringIds
	waitmessage B_WAIT_TIME_LONG
BattleScript_WeakArmorTrySpAtk:
	setstatchanger STAT_SPATK, 1, FALSE
	statbuffchange STAT_CHANGE_ALLOW_PTR, BattleScript_WeakArmorActivatesEnd
	jumpifbyte CMP_EQUAL, cMULTISTRING_CHOOSER, B_MSG_STAT_WONT_INCREASE, BattleScript_WeakArmorActivatesEnd
	printfromtable gStatUpStringIds
	waitmessage B_WAIT_TIME_LONG
BattleScript_WeakArmorActivatesEnd:
	return

BattleScript_CosmicEnergyActivatesReturn::
	copybyte gBattlerAbility, gBattlerAttacker
	call BattleScript_AbilityPopUp
	cosmicenergy BS_ATTACKER, 0, BattleScript_CosmicEnergyCantStore
	printfromtable gCosmicEnergyUsedStringIds
	waitmessage B_WAIT_TIME_LONG
	jumpifstat BS_ATTACKER, CMP_LESS_THAN, STAT_ATK, MAX_STAT_STAGE, BattleScript_CosmicEnergyTryAtk
	jumpifstat BS_ATTACKER, CMP_LESS_THAN, STAT_SPATK, MAX_STAT_STAGE, BattleScript_CosmicEnergyTryAtk
	jumpifstat BS_ATTACKER, CMP_EQUAL, STAT_SPEED, MAX_STAT_STAGE, BattleScript_CosmicEnergyEnd
BattleScript_CosmicEnergyTryAtk:
	setbyte sSTAT_ANIM_PLAYED, FALSE
	playstatchangeanimation BS_ATTACKER, BIT_ATK | BIT_SPATK | BIT_SPEED, 0
	setstatchanger STAT_ATK, 1, FALSE
	statbuffchange MOVE_EFFECT_AFFECTS_ATTACKER | STAT_CHANGE_ALLOW_PTR, BattleScript_CosmicEnergyTrySpAtk
	jumpifbyte CMP_EQUAL, cMULTISTRING_CHOOSER, B_MSG_STAT_WONT_INCREASE, BattleScript_CosmicEnergyTrySpAtk
	printfromtable gStatUpStringIds
	waitmessage B_WAIT_TIME_LONG
BattleScript_CosmicEnergyTrySpAtk:
	setstatchanger STAT_SPATK, 1, FALSE
	statbuffchange MOVE_EFFECT_AFFECTS_ATTACKER | STAT_CHANGE_ALLOW_PTR, BattleScript_CosmicEnergyTrySpd
	jumpifbyte CMP_EQUAL, cMULTISTRING_CHOOSER, B_MSG_STAT_WONT_INCREASE, BattleScript_CosmicEnergyTrySpd
	printfromtable gStatUpStringIds
	waitmessage B_WAIT_TIME_LONG
BattleScript_CosmicEnergyTrySpd:
	setstatchanger STAT_SPEED, 1, FALSE
	statbuffchange MOVE_EFFECT_AFFECTS_ATTACKER | STAT_CHANGE_ALLOW_PTR, BattleScript_CosmicEnergyEnd
	jumpifbyte CMP_EQUAL, cMULTISTRING_CHOOSER, B_MSG_STAT_WONT_INCREASE, BattleScript_CosmicEnergyEnd
	printfromtable gStatUpStringIds
	waitmessage B_WAIT_TIME_LONG
BattleScript_CosmicEnergyEnd:
	cosmicenergy BS_ATTACKER, 1, BattleScript_CosmicEnergyEnd
	return

BattleScript_CosmicEnergyCantStore:
	printfromtable gCosmicEnergyUsedStringIds
	waitmessage B_WAIT_TIME_LONG
	return

BattleScript_CosmicEnergyActivatesEnd3::
	call BattleScript_CosmicEnergyActivatesReturn
	end3

BattleScript_CosmicEnergyReleaseReturn::
	cosmicenergy BS_ATTACKER, 2, BattleScript_CosmicEnergyReleaseEnd
	copybyte gBattlerAbility, gBattlerAttacker
	call BattleScript_AbilityPopUp
	printfromtable gCosmicEnergyUsedStringIds
	waitmessage B_WAIT_TIME_LONG
BattleScript_CosmicEnergyReleaseEnd:
	return

BattleScript_RaiseStatOnFaintingTarget::
	copybyte gBattlerAbility, gBattlerAttacker
	call BattleScript_AbilityPopUp
	setgraphicalstatchangevalues
	playanimation BS_ATTACKER, B_ANIM_STATS_CHANGE, sB_ANIM_ARG1
	waitanimation
	printstring STRINGID_LASTABILITYRAISEDSTAT
	waitmessage B_WAIT_TIME_LONG
	return	

BattleScript_HealOnFaintingTarget::
	copybyte gBattlerAbility, gBattlerAttacker
	call BattleScript_AbilityPopUp
	healthbarupdate BS_ATTACKER
	datahpupdate BS_ATTACKER
	printstring STRINGID_PKMNSXRESTOREDHPALITTLE2
	waitmessage B_WAIT_TIME_LONG
	return

BattleScript_DisplayFrictionManeCount::
	call BattleScript_AbilityPopUp
	printstring STRINGID_ATTACKERFRICTIONCHARGECOUNT
	waitmessage B_WAIT_TIME_LONG
	return

BattleScript_AttackerAbilityStatRaise::
	statbuffchange MOVE_EFFECT_AFFECTS_ATTACKER | STAT_CHANGE_ALLOW_PTR, BattleScript_AttackerAbilityStatRaiseEnd
	jumpifbyte CMP_GREATER_THAN, cMULTISTRING_CHOOSER, B_MSG_DEFENDER_STAT_ROSE, BattleScript_AttackerAbilityStatRaiseEnd
	copybyte gBattlerAbility, gBattlerAttacker
	call BattleScript_AbilityPopUp
	setgraphicalstatchangevalues
	playanimation BS_ATTACKER, B_ANIM_STATS_CHANGE, sB_ANIM_ARG1
	waitanimation
	printstring STRINGID_ATTACKERABILITYSTATRAISE
	waitmessage B_WAIT_TIME_LONG
BattleScript_AttackerAbilityStatRaiseEnd:
	return

BattleScript_TargetAbilityAttackerStatLower::
	copybyte gBattlerAbility, gBattlerTarget
	call BattleScript_AbilityPopUp
	setgraphicalstatchangevalues
	playanimation BS_ATTACKER, B_ANIM_STATS_CHANGE, sB_ANIM_ARG1
	waitanimation
	printstring STRINGID_ATTACKERABILITYSTATLOWER
	waitmessage B_WAIT_TIME_LONG
	return

BattleScript_FellStingerRaisesStat::
	statbuffchange MOVE_EFFECT_AFFECTS_ATTACKER | STAT_CHANGE_ALLOW_PTR, BattleScript_FellStingerRaisesAtkEnd
	jumpifbyte CMP_GREATER_THAN, cMULTISTRING_CHOOSER, B_MSG_DEFENDER_STAT_ROSE, BattleScript_FellStingerRaisesAtkEnd
	setgraphicalstatchangevalues
	playanimation BS_ATTACKER, B_ANIM_STATS_CHANGE, sB_ANIM_ARG1
	printfromtable gStatUpStringIds
	waitmessage B_WAIT_TIME_LONG
BattleScript_FellStingerRaisesAtkEnd:
	return

BattleScript_RecklessSwingHeal::
	healthbarupdate BS_ATTACKER
	datahpupdate BS_ATTACKER
	printstring STRINGID_PKMNSMOVEXRESTOREDHPALITTLE
	waitmessage B_WAIT_TIME_LONG
	return

BattleScript_BoneWandSetEffect::
	playanimation BS_ATTACKER, B_ANIM_HELD_ITEM_EFFECT, NULL
	healthbarupdate BS_ATTACKER
	datahpupdate BS_ATTACKER
	printstring STRINGID_PKMNSITEMXRESTOREDHPALITTLE
	waitmessage B_WAIT_TIME_LONG
	return

BattleScript_AttackerAbilityStatRaiseEnd3::
	call BattleScript_AttackerAbilityStatRaise
	end3

BattleScript_WaterVeilActivates::
	call BattleScript_AbilityPopUp
	playmoveanimation BS_ATTACKER, MOVE_AQUA_RING
	waitanimation
	printstring STRINGID_PKMNSURROUNDEDWITHVEILOFWATER
	waitmessage B_WAIT_TIME_LONG
	end3	

BattleScript_LetItRipActivates::
	call BattleScript_AbilityPopUp
	playmoveanimation BS_ATTACKER, MOVE_DEFENSE_CURL
	waitanimation
	statbuffchange MOVE_EFFECT_AFFECTS_ATTACKER | STAT_BUFF_NOT_PROTECT_AFFECTED | MOVE_EFFECT_CERTAIN, NULL
	setgraphicalstatchangevalues
	playanimation BS_ATTACKER, B_ANIM_STATS_CHANGE, sB_ANIM_ARG1
	waitanimation
	printstring STRINGID_PKMNENTEREDINDEFENSECURL
	waitmessage B_WAIT_TIME_LONG
	end3

BattleScript_SoilRootActivates::
	call BattleScript_AbilityPopUp
	playmoveanimation BS_ATTACKER, MOVE_INGRAIN
	waitanimation
	printstring STRINGID_PKMNPLANTEDROOTS
	waitmessage B_WAIT_TIME_LONG
	end3

BattleScript_NorthWindActivates::
	call BattleScript_AbilityPopUp	
	playmoveanimation BS_ATTACKER, MOVE_AURORA_VEIL
	waitanimation
	printstring STRINGID_PKMNSURROUNDEDWITHAURORAVEIL
	waitmessage B_WAIT_TIME_LONG
	end3	

BattleScript_PsychicBarrierActivates::
	jumpifstatus2 BS_ATTACKER, STATUS2_SUBSTITUTION_ANY, BattleScript_PsychicBarrierEnd
	setpsychicbarrier BS_ATTACKER
	jumpifbyte CMP_EQUAL, cMULTISTRING_CHOOSER, B_MSG_SUBSTITUTE_FAILED, BattleScript_PsychicBarrierEnd
	call BattleScript_AbilityPopUp	
	printstring STRINGID_PKMNPSYCHICBARRIER
	waitmessage B_WAIT_TIME_LONG
	playmoveanimation BS_ATTACKER, MOVE_PSYSHIELD
	waitanimation
	healthbarupdate BS_ATTACKER
	datahpupdate BS_ATTACKER
BattleScript_PsychicBarrierEnd:
	end3

BattleScript_BullsEyeBerserk::
	call BattleScript_AbilityPopUp
	swapattackerwithtarget
	playanimation BS_ATTACKER, B_ANIM_BULLS_EYE, NULL
	printstring STRINGID_BULLS_EYE
	waitmessage B_WAIT_TIME_LONG
	statbuffchange MOVE_EFFECT_AFFECTS_ATTACKER | STAT_BUFF_NOT_PROTECT_AFFECTED | MOVE_EFFECT_CERTAIN, NULL
	setgraphicalstatchangevalues
	playanimation BS_ATTACKER, B_ANIM_STATS_CHANGE, sB_ANIM_ARG1
	waitanimation
	printstring STRINGID_BULLS_EYE_STAT_CHANGE
	waitmessage B_WAIT_TIME_LONG
	copybyte gEffectBattler, gBattlerAttacker
	chosenstatus2animation BS_ATTACKER, STATUS2_CONFUSION
	printstring STRINGID_PKMNWASCONFUSED
	waitmessage B_WAIT_TIME_LONG
	swapattackerwithtarget
	end3

BattleScript_BullsEyeBerserkUser::
	call BattleScript_AbilityPopUp
	playanimation BS_ATTACKER, B_ANIM_BULLS_EYE, NULL
	printstring STRINGID_BULLS_EYE
	waitmessage B_WAIT_TIME_LONG
	statbuffchange  MOVE_EFFECT_AFFECTS_ATTACKER | STAT_BUFF_NOT_PROTECT_AFFECTED | MOVE_EFFECT_CERTAIN, NULL
	setgraphicalstatchangevalues
	playanimation BS_ATTACKER, B_ANIM_STATS_CHANGE, sB_ANIM_ARG1
	waitanimation
	printstring STRINGID_BULLS_EYE_STAT_CHANGE
	waitmessage B_WAIT_TIME_LONG
	copybyte gEffectBattler, gBattlerAttacker
	chosenstatus2animation BS_ATTACKER, STATUS2_CONFUSION
	printstring STRINGID_PKMNWASCONFUSED
	waitmessage B_WAIT_TIME_LONG
	end3

BattleScript_TatsugiriEntersDondozoMouth::
	call BattleScript_AbilityPopUp
	playmoveanimation BS_TARGET, MOVE_DONDOZO_BITE
	waitanimation
	printstring STRINGID_TATSUGIRI_SWALLOWED
	waitmessage B_WAIT_TIME_LONG
	call BattleScript_AllStatsUpTwice
	tatsugiriinvulnerable BS_TARGET, TRUE
	end3

BattleScript_TatsugiriExitsDondozoMouth::
	makevisible BS_SCRIPTING
	restoreactive
	end2

BattleScript_Bewitching::
	call BattleScript_AbilityPopUp
	status2animation BS_ATTACKER, STATUS2_INFATUATION
	printstring STRINGID_PKMNSXINFATUATEDY
	waitmessage B_WAIT_TIME_LONG
	end3

BattleScript_BewitchingUser::
	call BattleScript_AbilityPopUp
	swapattackerwithtarget
	status2animation BS_ATTACKER, STATUS2_INFATUATION
	printstring STRINGID_PKMNSXINFATUATEDY
	waitmessage B_WAIT_TIME_LONG
	swapattackerwithtarget
	end3

BattleScript_YukiOnnaCurse::
	call BattleScript_AbilityPopUp
	status2animation BS_ATTACKER, STATUS2_CURSED
	printstring STRINGID_HAUNTED_SPIRIT_CURSE
	waitmessage B_WAIT_TIME_LONG
	end3

BattleScript_YukiOnnaCurseUser::
	call BattleScript_AbilityPopUp
	swapattackerwithtarget
	status2animation BS_ATTACKER, STATUS2_CURSED
	printstring STRINGID_HAUNTED_SPIRIT_CURSE
	waitmessage B_WAIT_TIME_LONG
	swapattackerwithtarget
	end3

BattleScript_ThundercloudsActivates::
	call BattleScript_AbilityPopUp
	playanimation BS_ATTACKER, B_ANIM_THUNDERCLOUDS, NULL
	waitanimation
	printstring STRINGID_SUMMONED_THUNDERCLOUDS
	waitmessage B_WAIT_TIME_LONG
	end3

BattleScript_HospitalityActivates::
	call BattleScript_AbilityPopUp
	printstring STRINGID_HOSPITALITY_HEAL
	waitmessage B_WAIT_TIME_LONG
	orword gHitMarker, HITMARKER_IGNORE_SUBSTITUTE
	healthbarupdate BS_TARGET
	datahpupdate BS_TARGET
	end3

BattleScript_SwitchInAbilityMsg::
	call BattleScript_SwitchInAbilityMsgRet
	end3

BattleScript_SwitchInAbilityMsgRet::
	call BattleScript_AbilityPopUp
	printfromtable gSwitchInAbilityStringIds
	waitmessage B_WAIT_TIME_LONG
	return

BattleScript_EvoboostSyncActivates::
	call BattleScript_AbilityPopUp
	tryevoboostsync
	end3

BattleScript_CleansingChimeActivates::
	call BattleScript_AbilityPopUp
	printstring STRINGID_CLEANSINGCHIMEACTIVATES
	waitmessage B_WAIT_TIME_LONG
	healpartystatus
	waitstate
	updatestatusicon BS_ATTACKER_WITH_PARTNER
	waitstate
	end3

BattleScript_SwitchInAbilitySetRoomMsg::
	setroom
	call BattleScript_AbilityPopUp
	playmoveanimation BS_ATTACKER, MOVE_TRICK_ROOM
	waitanimation
	printfromtable gRoomsStringIds
	waitmessage B_WAIT_TIME_LONG
	savetarget
	setbyte gBattlerTarget, 0
BattleScript_RoomServiceLoop2:
	copybyte sBATTLER, gBattlerTarget
	tryroomservice BS_TARGET, BattleScript_RoomServiceLoop_NextBattler2
	removeitem BS_TARGET, 1
BattleScript_RoomServiceLoop_NextBattler2:
	addbyte gBattlerTarget, 0x1
	jumpifbytenotequal gBattlerTarget, gBattlersCount, BattleScript_RoomServiceLoop2
	restoretarget
	end3

BattleScript_SwitchInAbilitySetGravityMsg::
	setgravity BattleScript_GravityEnd2
	call BattleScript_AbilityPopUp
	playmoveanimation BS_ATTACKER, MOVE_GRAVITY
	waitanimation
	printstring STRINGID_GRAVITYINTENSIFIED 
	waitmessage B_WAIT_TIME_LONG
	savetarget
	setbyte gBattlerTarget, 0
BattleScript_GravityLoop2:
	jumpifstatus3 BS_TARGET, STATUS3_ON_AIR | STATUS3_MAGNET_RISE | STATUS3_TELEKINESIS, BattleScript_GravityLoopDrop2
	goto BattleScript_GravityLoopEnd2
BattleScript_GravityLoopDrop2:
	bringdownairbornebattler BS_TARGET
	printstring STRINGID_GRAVITYGROUNDING 
	waitmessage B_WAIT_TIME_LONG
BattleScript_GravityLoopEnd2:
	addbyte gBattlerTarget, 0x1
	jumpifbytenotequal gBattlerTarget, gBattlersCount, BattleScript_GravityLoop2
BattleScript_GravityEnd2:
	restoretarget
	end3

BattleScript_LunarVeilActivates::
	call BattleScript_AbilityPopUp
BattleScript_LunarVeilLoop:
	lunarveilheal
	printstring STRINGID_LUNAR_VEIL
	waitmessage B_WAIT_TIME_LONG
	orword gHitMarker, HITMARKER_IGNORE_SUBSTITUTE
	healthbarupdate BS_TARGET
	datahpupdate BS_TARGET
	updatestatusicon BS_TARGET
	end3

BattleScript_NightfallLullabyActivates::
	setbyte gBattlerTarget, 0
	call BattleScript_AbilityPopUp
BattleScript_NightfallLullabyLoop:
	puttargetasleep BattleScript_NightfallLullabyIncrement
	printstring STRINGID_NIGHTFALL_LULLABY
	waitmessage B_WAIT_TIME_LONG
	updatestatusicon BS_TARGET
BattleScript_NightfallLullabyIncrement::
	addbyte gBattlerTarget, 1
	jumpifbytenotequal gBattlerTarget, gBattlersCount, BattleScript_NightfallLullabyLoop
BattleScript_NightfallLullabyEnd:
	end3

BattleScript_ActivateAsOne::
	call BattleScript_AbilityPopUp
	printfromtable gSwitchInAbilityStringIds
	waitmessage B_WAIT_TIME_LONG
	@ show unnerve
	sethword sABILITY_OVERWRITE, ABILITY_UNNERVE
	setbyte cMULTISTRING_CHOOSER, B_MSG_SWITCHIN_UNNERVE
	call BattleScript_AbilityPopUp
	printfromtable gSwitchInAbilityStringIds
	waitmessage B_WAIT_TIME_LONG
	end3
	
BattleScript_FriskMsgWithPopup::
	copybyte gBattlerAbility, gBattlerAttacker
	call BattleScript_AbilityPopUp
BattleScript_FriskMsg::
	@printstring STRINGID_FRISKACTIVATES
	printfromtable gFriskStringIds
	waitmessage B_WAIT_TIME_LONG
	return

BattleScript_FriskActivates::
	tryfriskmsg BS_ATTACKER
	end3

BattleScript_MachineLearningActivates::
	copybyte gBattlerAbility, gBattlerAttacker
	call BattleScript_AbilityPopUp
	printfromtable gMachineLearningStringIds
	waitmessage B_WAIT_TIME_LONG
	return

BattleScript_MasterOfMimicActivates::
	copybyte gBattlerAbility, gBattlerAttacker
	call BattleScript_AbilityPopUp
	printfromtable gMasterOfMimicStringIds
	waitmessage B_WAIT_TIME_LONG
	return

BattleScript_ImposterActivates::
	transformdataexecution
	call BattleScript_AbilityPopUp
	playmoveanimation BS_ATTACKER, MOVE_TRANSFORM
	waitanimation
	printstring STRINGID_IMPOSTERTRANSFORM
	waitmessage B_WAIT_TIME_LONG
	end3

BattleScript_HurtAttacker:
	orword gHitMarker, HITMARKER_IGNORE_SUBSTITUTE | HITMARKER_PASSIVE_DAMAGE | HITMARKER_IGNORE_DISGUISE
	healthbarupdate BS_ATTACKER
	datahpupdate BS_ATTACKER
	printstring STRINGID_PKMNHURTSWITH
	waitmessage B_WAIT_TIME_LONG
	tryfaintmon BS_ATTACKER, FALSE, NULL
	return

BattleScript_RoughSkinActivates::
	call BattleScript_AbilityPopUp
	call BattleScript_HurtAttacker
	return

BattleScript_FrictionManeActivates::
	swapattackerwithtarget
	call BattleScript_AbilityPopUp
	playanimation BS_TARGET, B_ANIM_FRICTION_SHOCK, NULL
	orword gHitMarker, HITMARKER_IGNORE_SUBSTITUTE | HITMARKER_PASSIVE_DAMAGE
	hitanimation BS_TARGET
	healthbarupdate BS_TARGET
	datahpupdate BS_TARGET
	printstring STRINGID_FRICTION_SHOCK
	waitmessage B_WAIT_TIME_LONG
	tryfaintmon BS_TARGET, FALSE, NULL
	swapattackerwithtarget
	return

BattleScript_AliShuffleActivates::
	jumpifabsent BS_ATTACKER, BattleScript_SpikyShieldRet
	orword gHitMarker, HITMARKER_IGNORE_SUBSTITUTE | HITMARKER_PASSIVE_DAMAGE
	bichalfword gMoveResultFlags, MOVE_RESULT_NO_EFFECT
	playmoveanimation BS_ATTACKER, MOVE_MACH_PUNCH
	healthbarupdate BS_ATTACKER
	datahpupdate BS_ATTACKER
	printstring STRINGID_PKMNHURTSWITHALISHUFFLE
	waitmessage B_WAIT_TIME_LONG
	tryfaintmon BS_ATTACKER, FALSE, NULL
	return

BattleScript_RubbleRouserActivates::
	orword gHitMarker, HITMARKER_IGNORE_SUBSTITUTE | HITMARKER_PASSIVE_DAMAGE
	healthbarupdate BS_ATTACKER
	datahpupdate BS_ATTACKER
	printstring STRINGID_PKMNHURTSWITHRUBBLEROUSER
	waitmessage B_WAIT_TIME_LONG
	tryfaintmon BS_ATTACKER, FALSE, NULL
	return

BattleScript_CorrosionActivates::
	call BattleScript_AbilityPopUp
	call BattleScript_HurtTarget
	return

BattleScript_IronFistTechnique::
	call BattleScript_AbilityPopUp	
	playanimation BS_TARGET, B_ANIM_IRON_FIST_TECHNIQUE, NULL
	orword gHitMarker, HITMARKER_PASSIVE_DAMAGE
	healthbarupdate BS_TARGET
	datahpupdate BS_TARGET
	printstring STRINGID_IRONFISTTECHNIQUE
	waitmessage B_WAIT_TIME_LONG
	tryfaintmon BS_TARGET, FALSE, NULL
	return

BattleScript_PoisonPointHurtsTarget::
	call BattleScript_AbilityPopUp
	call BattleScript_HurtTarget	
	waitstate
	seteffectsecondary
	return

BattleScript_PoisonPointHurtsAttacker::
	call BattleScript_AbilityPopUp
	call BattleScript_HurtAttacker	
	waitstate
	seteffectsecondary
	return

BattleScript_HurtTarget:
	orword gHitMarker, HITMARKER_IGNORE_SUBSTITUTE | HITMARKER_PASSIVE_DAMAGE | HITMARKER_IGNORE_DISGUISE
	healthbarupdate BS_TARGET
	datahpupdate BS_TARGET
	printstring STRINGID_PKMNHURTSWITH2
	waitmessage B_WAIT_TIME_LONG
	tryfaintmon BS_TARGET, FALSE, NULL
	return

BattleScript_RockyHelmetActivates::
	@ don't play the animation for a fainted mon
	jumpifabsent BS_TARGET, BattleScript_RockyHelmetActivatesDmg
	playanimation BS_TARGET, B_ANIM_HELD_ITEM_EFFECT, NULL
	waitanimation
BattleScript_RockyHelmetActivatesDmg:
	call BattleScript_HurtAttacker
	return

BattleScript_SpikyShieldEffect::
	jumpifabsent BS_ATTACKER, BattleScript_SpikyShieldRet
	orword gHitMarker, HITMARKER_IGNORE_SUBSTITUTE | HITMARKER_PASSIVE_DAMAGE
	bichalfword gMoveResultFlags, MOVE_RESULT_NO_EFFECT
	healthbarupdate BS_ATTACKER
	datahpupdate BS_ATTACKER
	printstring STRINGID_PKMNHURTSWITH
	waitmessage B_WAIT_TIME_LONG
	tryfaintmon BS_ATTACKER, FALSE, NULL
BattleScript_SpikyShieldRet::
	return

BattleScript_KingsShieldEffect::
	orword gHitMarker, HITMARKER_IGNORE_SUBSTITUTE | HITMARKER_PASSIVE_DAMAGE
	bichalfword gMoveResultFlags, MOVE_RESULT_NO_EFFECT
	seteffectsecondary
	setmoveeffect 0
	copybyte sBATTLER, gBattlerTarget
	copybyte gBattlerTarget, gBattlerAttacker
	copybyte gBattlerAttacker, sBATTLER
	return

BattleScript_BanefulBunkerEffect::
	orword gHitMarker, HITMARKER_IGNORE_SUBSTITUTE | HITMARKER_IGNORE_SAFEGUARD | HITMARKER_PASSIVE_DAMAGE
	bichalfword gMoveResultFlags, MOVE_RESULT_NO_EFFECT
	seteffectsecondary
	setmoveeffect 0
	return

BattleScript_CuteCharmActivates::
	call BattleScript_AbilityPopUp
	status2animation BS_ATTACKER, STATUS2_INFATUATION
	printstring STRINGID_PKMNSXINFATUATEDY
	waitmessage B_WAIT_TIME_LONG
	call BattleScript_TryDestinyKnotTarget
	return

BattleScript_CuteCharmActivates2::
	call BattleScript_AbilityPopUp
	status2animation BS_TARGET, STATUS2_INFATUATION
	printstring STRINGID_PKMNSYINFATUATEDX
	waitmessage B_WAIT_TIME_LONG
	call BattleScript_TryDestinyKnotAttacker
	return

BattleScript_GooeyActivates::
	waitstate
	call BattleScript_AbilityPopUp
	swapattackerwithtarget  @ for defiant, mirror armor
	seteffectsecondary
	swapattackerwithtarget
	return

BattleScript_AbilityStatusEffect::
	waitstate
	call BattleScript_AbilityPopUp
	seteffectsecondary
	return

BattleScript_IncendiaryShellActivates::
	waitstate
	seteffectsecondary
	waitmessage B_WAIT_TIME_LONG
BattleScript_SlottedShellActivates::
	reloadshell BS_ATTACKER
	call BattleScript_AbilityPopUp
	printstring STRINGID_SLOTTED_SHELL
	waitmessage B_WAIT_TIME_LONG
	return

BattleScript_ShrapnelShellActivates::
	waitstate
	savetarget
	setbyte sBATTLER, 0
BattleScript_ShrapnelShellLoop::
	shrapnelshelldamage BS_SCRIPTING, BattleScript_ShrapnelShellGoNextTarget
	printstring STRINGID_FRAGMENT_DAMAGE
	waitmessage B_WAIT_TIME_LONG
	orword gHitMarker, HITMARKER_PASSIVE_DAMAGE
	healthbarupdate BS_SCRIPTING
	datahpupdate BS_SCRIPTING
	tryfaintmon BS_SCRIPTING, FALSE, NULL
BattleScript_ShrapnelShellGoNextTarget:
	addbyte sBATTLER, 1
	jumpifbytenotequal sBATTLER, gBattlersCount, BattleScript_ShrapnelShellLoop
	restoretarget
	call BattleScript_SlottedShellActivates
	return

BattleScript_TopSpinActivates::
	waitstate
	call BattleScript_AbilityPopUp
	setmoveeffect MOVE_EFFECT_RAPIDSPIN | MOVE_EFFECT_AFFECTS_ATTACKER | MOVE_EFFECT_CERTAIN
	seteffectwithchance
	setstatchanger STAT_SPEED, 1, FALSE
	statbuffchange MOVE_EFFECT_AFFECTS_ATTACKER | STAT_CHANGE_ALLOW_PTR, BattleScript_TopSpinEnd
	jumpifbyte CMP_EQUAL, cMULTISTRING_CHOOSER, B_MSG_STAT_WONT_INCREASE, BattleScript_TopSpinEnd
	setgraphicalstatchangevalues
	playanimation BS_ATTACKER, B_ANIM_STATS_CHANGE, sB_ANIM_ARG1
	printfromtable gStatUpStringIds
	waitmessage B_WAIT_TIME_LONG
BattleScript_TopSpinEnd:
	return

BattleScript_TopSpinActivatesNoSpeed::
	waitstate
	call BattleScript_AbilityPopUp
	setmoveeffect MOVE_EFFECT_RAPIDSPIN | MOVE_EFFECT_AFFECTS_ATTACKER | MOVE_EFFECT_CERTAIN
	seteffectwithchance
	return

BattleScript_ChangeAttackerType::
	waitstate
	call BattleScript_AbilityPopUp
	playmoveanimation BS_ATTACKER, MOVE_MAGIC_POWDER
	swapattackerwithtarget
	printstring STRINGID_BATTLERTYPECHANGEDTO
	waitmessage B_WAIT_TIME_LONG
	swapattackerwithtarget
	return

BattleScript_AbilityTrappingOnhit::
	waitstate
	call BattleScript_AbilityPopUp
	printfromtable gWrappedStringIds
	waitmessage B_WAIT_TIME_LONG
	return

BattleScript_LeechFangsActivates::
	waitstate
	manipulatedamage DMG_BIG_ROOT
	call BattleScript_AbilityPopUp
	printstring STRINGID_LEECHFANGSDRAIN
	waitmessage B_WAIT_TIME_LONG
	orword gHitMarker, HITMARKER_IGNORE_SUBSTITUTE
	healthbarupdate BS_ATTACKER
	datahpupdate BS_ATTACKER
	return

BattleScript_BerserkerRageActivates::
	waitstate
	manipulatedamage DMG_BIG_ROOT
	call BattleScript_AbilityPopUp
	printstring STRINGID_BERSERKERRAGEHEAL
	waitmessage B_WAIT_TIME_LONG
	orword gHitMarker, HITMARKER_IGNORE_SUBSTITUTE
	healthbarupdate BS_ATTACKER
	datahpupdate BS_ATTACKER
	return

BattleScript_MomentumActivates::
	waitstate
	call BattleScript_AbilityPopUp
	printstring STRINGID_PKMNHITWITHRECOIL
	waitmessage B_WAIT_TIME_LONG
	orword gHitMarker, HITMARKER_IGNORE_SUBSTITUTE
	healthbarupdate BS_ATTACKER
	datahpupdate BS_ATTACKER
	tryfaintmon BS_ATTACKER, FALSE, NULL
	return

BattleScript_TrampleActivates::
	waitstate
	savetarget
	call BattleScript_AbilityPopUp
	setbyte sBATTLER, 0
BattleScript_TrampleLoop::
	trampledamage BS_SCRIPTING, BattleScript_TrampleGoNextTarget
	printstring STRINGID_TRAMPLE_DAMAGE
	waitmessage B_WAIT_TIME_LONG
	orword gHitMarker, HITMARKER_PASSIVE_DAMAGE
	healthbarupdate BS_SCRIPTING
	datahpupdate BS_SCRIPTING
	tryfaintmon BS_SCRIPTING, FALSE, NULL
BattleScript_TrampleGoNextTarget:
	addbyte sBATTLER, 1
	jumpifbytenotequal sBATTLER, gBattlersCount, BattleScript_TrampleLoop
	restoretarget
	return

BattleScript_DeathlyEmbraceActivates::
	call BattleScript_AbilityPopUp
	printstring STRINGID_DEATHLY_EMBRACE
	waitmessage B_WAIT_TIME_LONG
	orword gHitMarker, HITMARKER_IGNORE_SUBSTITUTE
	healthbarupdate BS_TARGET
	datahpupdate BS_TARGET
	tryfaintmon BS_TARGET, FALSE, NULL
	return

BattleScript_ProvokingFeudsActivates::
	call BattleScript_AbilityPopUp
	printstring STRINGID_PROVOKING_FEUDS
	waitmessage B_WAIT_TIME_LONG
	return

BattleScript_WatchdogGrowl::
	waitstate
	copybyte gBattlerAbility, sBATTLER
	call BattleScript_AbilityPopUp
	pause B_WAIT_TIME_LONG
	playmoveanimation BS_TARGET, MOVE_GROWL
	waitanimation
	setstatchanger STAT_ATK, 1, TRUE
	statbuffchange MOVE_EFFECT_AFFECTS_ATTACKER | STAT_CHANGE_ALLOW_PTR, BattleScript_WatchdogGrowlReturn
	setgraphicalstatchangevalues
	jumpifbyte CMP_EQUAL, cMULTISTRING_CHOOSER, B_MSG_STAT_WONT_INCREASE, BattleScript_WatchdogGrowlReturn @ cant raise def
	playanimation BS_ATTACKER, B_ANIM_STATS_CHANGE, sB_ANIM_ARG1
	printfromtable gStatUpStringIds
	waitmessage B_WAIT_TIME_LONG
BattleScript_WatchdogGrowlReturn:
	return

BattleScript_CommensalismHelpingHand::
	waitstate
	copybyte gBattlerAbility, sBATTLER
	call BattleScript_AbilityPopUp
	pause B_WAIT_TIME_LONG
	handleformchange BS_ABILITY_BATTLER, 0
	handleformchange BS_ABILITY_BATTLER, 1
	playanimation BS_ABILITY_BATTLER, B_ANIM_FORM_CHANGE, NULL
	waitanimation
	playanimation BS_ATTACKER, B_ANIM_COMMENSALISM, NULL
	waitanimation
	changespeciesto BS_ATTACKER SPECIES_MANTINE
	handleformchange BS_ABILITY_BATTLER, 0
	handleformchange BS_ABILITY_BATTLER, 1
	playanimation BS_ABILITY_BATTLER, B_ANIM_FORM_CHANGE, NULL
	waitanimation
	goto BattleScript_CommensalismReturn

BattleScript_CommensalismActivates::
	waitstate
	copybyte gBattlerAbility, sBATTLER
	call BattleScript_AbilityPopUp
	pause B_WAIT_TIME_LONG
	handleformchange BS_ABILITY_BATTLER, 0
	handleformchange BS_ABILITY_BATTLER, 1
	playanimation BS_ABILITY_BATTLER, B_ANIM_FORM_CHANGE, NULL
	waitanimation
	getCommensalismDMG
	printstring STRINGID_REMORAIDUSEDMOVE
	waitmessage B_WAIT_TIME_LONG
	hitanimation BS_TARGET
	waitstate
	changespeciesto BS_ATTACKER SPECIES_MANTINE
	handleformchange BS_ABILITY_BATTLER, 0
	handleformchange BS_ABILITY_BATTLER, 1
	playanimation BS_ABILITY_BATTLER, B_ANIM_FORM_CHANGE, NULL
	waitanimation
	healthbarupdate BS_TARGET
	datahpupdate BS_TARGET
	tryfaintmon BS_TARGET, FALSE, NULL
BattleScript_CommensalismReturn:
	return

BattleScript_DoFormChangeOnFaint::
	restorefullhp BS_EFFECT_BATTLER
	handleformchange BS_EFFECT_BATTLER, 0
	handleformchange BS_EFFECT_BATTLER, 1
	playanimation BS_EFFECT_BATTLER, B_ANIM_FORM_CHANGE, NULL
	waitanimation
	printfromtable gFormChangeOnFaintStringIds
	waitmessage B_WAIT_TIME_LONG
	handleformchange BS_EFFECT_BATTLER, 2
	handleformchange BS_EFFECT_BATTLER, 3
	healstatuscondition BS_EFFECT_BATTLER, 0
	updatestatusicon BS_EFFECT_BATTLER
	return

BattleScript_DoRewindOnFaint::
	pause 5
	copybyte gBattlerAbility, gEffectBattler
	call BattleScript_AbilityPopUp
	orword gHitMarker, HITMARKER_IGNORE_SUBSTITUTE | HITMARKER_PASSIVE_DAMAGE
	printstring STRINGID_REWINDACTIVATED
	waitmessage B_WAIT_TIME_LONG
	healthbarupdate BS_EFFECT_BATTLER
	datahpupdate BS_EFFECT_BATTLER
	updatestatusicon BS_EFFECT_BATTLER
	return

BattleScript_DoYveltalFormChangeOnFaint::
	saveattacker
	savetarget
	copybyte gBattlerAttacker, sBATTLER
	restore1hp BS_EFFECT_BATTLER
	handleformchange BS_EFFECT_BATTLER, 0
	handleformchange BS_EFFECT_BATTLER, 1
	playanimation BS_EFFECT_BATTLER, B_ANIM_FORM_CHANGE, NULL
	waitanimation
	printfromtable gFormChangeOnFaintStringIds
	waitmessage B_WAIT_TIME_LONG
	handleformchange BS_EFFECT_BATTLER, 2
	handleformchange BS_EFFECT_BATTLER, 3
	healstatuscondition BS_EFFECT_BATTLER, 0
	updatestatusicon BS_EFFECT_BATTLER
	playanimation BS_ATTACKER, B_ANIM_STATS_ABSORB, NULL
	waitanimation
	trydestructioncocoonstealhp
	trydestructioncocoonstealhpfromparty
	restoreattacker
	restoretarget
	return

BattleScript_CocoonDestructionStealHPFromParty::
	printstring STRINGID_COCOON_STOLEN_PARTY_ENERGY
	waitmessage B_WAIT_TIME_LONG
	manipulatedamage DMG_BIG_ROOT
	healthbarupdate BS_ATTACKER
	datahpupdate BS_ATTACKER
	return

BattleScript_DamageAllEnemyPartyAndPartner::
	healthbarupdate BS_EFFECT_BATTLER
	datahpupdate BS_EFFECT_BATTLER
	tryfaintmon BS_EFFECT_BATTLER, FALSE, NULL
BattleScript_DamageAllEnemyParty::
	printstring STRINGID_DAMAGE_ALL_PARTY
	waitmessage B_WAIT_TIME_LONG
	return

BattleScript_ScriptingCocoonDestructionStealHP::
	playanimation BS_TARGET, B_ANIM_LEECH_SEED_DRAIN, sB_ANIM_ARG1
	orword gHitMarker, HITMARKER_IGNORE_SUBSTITUTE | HITMARKER_PASSIVE_DAMAGE
	healthbarupdate BS_TARGET
	datahpupdate BS_TARGET
	printstring STRINGID_COCOON_STOLEN_TARGET_ENERGY
	waitmessage B_WAIT_TIME_LONG
	copyword gBattleMoveDamage, sSAVED_DMG
	manipulatedamage DMG_BIG_ROOT
	healthbarupdate BS_ATTACKER
	datahpupdate BS_ATTACKER
	trydestructioncocoonstealstats
	tryfaintmon BS_TARGET, FALSE, NULL
	tryfaintmon BS_ATTACKER, FALSE, NULL
	return

BattleScript_YveltalAwakens::
	pause 5
	copybyte gBattlerAbility, gBattlerAttacker
	call BattleScript_AbilityPopUp
	printstring STRINGID_EMPTYSTRING3
	waitmessage 1
	handleformchange BS_ATTACKER, 0
	handleformchange BS_ATTACKER, 1
	playanimation BS_ATTACKER, B_ANIM_FORM_CHANGE, NULL
	waitanimation
	handleformchange BS_ATTACKER, 2
	printstring STRINGID_YVELTAL_AWAKENS
	waitmessage B_WAIT_TIME_LONG
	end3

BattleScript_BenjaminButterfreeDevolution::
	updatepokemondevolution BS_EFFECT_BATTLER
	playfaintcry BS_EFFECT_BATTLER
	handleformchange BS_EFFECT_BATTLER, 0
	handleformchange BS_EFFECT_BATTLER, 1
	playanimation BS_EFFECT_BATTLER, B_ANIM_FORM_CHANGE, NULL
	waitanimation
	printstring STRINGID_PKMNDEVOLVED
	waitmessage B_WAIT_TIME_LONG
	handleformchange BS_EFFECT_BATTLER, 2
	healstatuscondition BS_EFFECT_BATTLER, 0
	updatestatusicon BS_EFFECT_BATTLER
	return

BattleScript_CrashDamage::
	call BattleScript_AbilityPopUp
	printstring STRINGID_PKMNCRASHED
	waitmessage B_WAIT_TIME_LONG
	manipulatedamage DMG_RECOIL_FROM_MISS
	bichalfword gMoveResultFlags, MOVE_RESULT_MISSED | MOVE_RESULT_DOESNT_AFFECT_FOE
	orword gHitMarker, HITMARKER_IGNORE_SUBSTITUTE | HITMARKER_IGNORE_DISGUISE
	hitanimation BS_ATTACKER
	healthbarupdate BS_ATTACKER
	datahpupdate BS_ATTACKER
	tryfaintmon BS_ATTACKER, FALSE, NULL
	return

BattleScript_AirbourneDoubleHitDamage::
	call BattleScript_AbilityPopUp
	attackstring
	setmultihitcounter 1
	initmultihitstring
	sethword sMULTIHIT_EFFECT, 0
	addbyte sMULTIHIT_STRING + 4, 1
BattleScript_AirbourneMultiHitLoop::
	jumpifhasnohp BS_ATTACKER, BattleScript_AirbourneMultiHitEnd
	jumpifhasnohp BS_TARGET, BattleScript_AirbourneMultiHitPrintStrings
	jumpifhalfword CMP_EQUAL, gChosenMove, MOVE_SLEEP_TALK, BattleScript_AirbourneDoMultiHit
	jumpifstatus BS_ATTACKER, STATUS1_SLEEP, BattleScript_AirbourneMultiHitPrintStrings
BattleScript_AirbourneDoMultiHit::
	movevaluescleanup
	copyhword sMOVE_EFFECT, sMULTIHIT_EFFECT
	critcalc
	damagecalc
	jumpifmovehadnoeffect BattleScript_AirbourneMultiHitNoMoreHits
	adjustdamage
	attackanimation
	waitanimation
	effectivenesssound
	hitanimation BS_TARGET
	waitstate
	healthbarupdate BS_TARGET
	datahpupdate BS_TARGET
	critmessage
	waitmessage B_WAIT_TIME_LONG
	multihitresultmessage
	printstring STRINGID_EMPTYSTRING3
	waitmessage 1
	seteffectwithchance
	addbyte sMULTIHIT_STRING + 4, 1
	moveendto MOVEEND_NEXT_TARGET
	jumpifbyte CMP_COMMON_BITS, gMoveResultFlags, MOVE_RESULT_FOE_ENDURED, BattleScript_AirbourneMultiHitPrintStrings
	decrementmultihit BattleScript_AirbourneMultiHitLoop
	goto BattleScript_AirbourneMultiHitPrintStrings
BattleScript_AirbourneMultiHitNoMoreHits::
	pause B_WAIT_TIME_SHORT
BattleScript_AirbourneMultiHitPrintStrings::
	resultmessage
	waitmessage B_WAIT_TIME_LONG
	jumpifmovehadnoeffect BattleScript_AirbourneMultiHitEnd
	copyarray gBattleTextBuff1, sMULTIHIT_STRING, 6
	printstring STRINGID_HITXTIMES
	waitmessage B_WAIT_TIME_LONG
BattleScript_AirbourneMultiHitEnd::
	tryfaintmon BS_TARGET, FALSE, NULL
	moveendcase MOVEEND_SYNCHRONIZE_TARGET
	moveendfrom MOVEEND_STATUS_IMMUNITY_ABILITIES
	end

BattleScript_ParentalBondActivates::
	call BattleScript_AbilityPopUp
	attackstring
	initmultihitstring
	sethword sMULTIHIT_EFFECT, 0
	addbyte sMULTIHIT_STRING + 4, 1
BattleScript_ParentalBondMultiHitLoop::
	jumpifhasnohp BS_ATTACKER, BattleScript_ParentalBondMultiHitEnd
	jumpifhasnohp BS_TARGET, BattleScript_ParentalBondMultiHitPrintStrings
	jumpifhalfword CMP_EQUAL, gChosenMove, MOVE_SLEEP_TALK, BattleScript_ParentalBondDoMultiHit
	jumpifstatus BS_ATTACKER, STATUS1_SLEEP, BattleScript_ParentalBondMultiHitPrintStrings
BattleScript_ParentalBondDoMultiHit::
	movevaluescleanup
	copyhword sMOVE_EFFECT, sSAVED_MOVE_EFFECT
	critcalc	
	damagecalc
	jumpifmovehadnoeffect BattleScript_ParentalBondMultiHitNoMoreHits
	adjustdamage
	effectivenesssound
	hitanimation BS_TARGET
	waitstate
	healthbarupdate BS_TARGET
	datahpupdate BS_TARGET
	critmessage
	waitmessage B_WAIT_TIME_LONG
	multihitresultmessage
	printstring STRINGID_EMPTYSTRING3
	waitmessage 1
	seteffectwithchance
	addbyte sMULTIHIT_STRING + 4, 1
	moveendto MOVEEND_NEXT_TARGET
	jumpifbyte CMP_COMMON_BITS, gMoveResultFlags, MOVE_RESULT_FOE_ENDURED, BattleScript_ParentalBondMultiHitPrintStrings
	decrementmultihit BattleScript_ParentalBondMultiHitLoop
	goto BattleScript_ParentalBondMultiHitPrintStrings
BattleScript_ParentalBondMultiHitNoMoreHits::
	pause B_WAIT_TIME_SHORT
BattleScript_ParentalBondMultiHitPrintStrings::
	resultmessage
	waitmessage B_WAIT_TIME_LONG
	jumpifmovehadnoeffect BattleScript_ParentalBondMultiHitEnd
	copyarray gBattleTextBuff1, sMULTIHIT_STRING, 6
	printstring STRINGID_HITXTIMES
	waitmessage B_WAIT_TIME_LONG
BattleScript_ParentalBondMultiHitEnd::
	tryfaintmon BS_TARGET, FALSE, NULL
	moveendcase MOVEEND_SYNCHRONIZE_TARGET
	moveendfrom MOVEEND_STATUS_IMMUNITY_ABILITIES
	end

BattleScript_MultiLimbsActivates::
	call BattleScript_AbilityPopUp
	attackstring
	initmultihitstring
	sethword sMULTIHIT_EFFECT, 0
	addbyte sMULTIHIT_STRING + 4, 1
BattleScript_MultiLimbsMultiHitLoop::
	jumpifhasnohp BS_ATTACKER, BattleScript_MultiLimbsMultiHitEnd
	jumpifhasnohp BS_TARGET, BattleScript_MultiLimbsMultiHitPrintStrings
	jumpifhalfword CMP_EQUAL, gChosenMove, MOVE_SLEEP_TALK, BattleScript_MultiLimbsDoMultiHit
	jumpifstatus BS_ATTACKER, STATUS1_SLEEP, BattleScript_MultiLimbsMultiHitPrintStrings
BattleScript_MultiLimbsDoMultiHit::
	movevaluescleanup
	copyhword sMOVE_EFFECT, sSAVED_MOVE_EFFECT
	critcalc	
	damagecalc
	jumpifmovehadnoeffect BattleScript_MultiLimbsMultiHitNoMoreHits
	adjustdamage
	playmoveanimation BS_TARGET, MOVE_COMET_PUNCH
	waitanimation
	effectivenesssound
	hitanimation BS_TARGET
	waitstate
	healthbarupdate BS_TARGET
	datahpupdate BS_TARGET
	critmessage
	waitmessage B_WAIT_TIME_LONG
	multihitresultmessage
	printstring STRINGID_EMPTYSTRING3
	waitmessage 1
	seteffectwithchance
	addbyte sMULTIHIT_STRING + 4, 1
	moveendto MOVEEND_NEXT_TARGET
	jumpifbyte CMP_COMMON_BITS, gMoveResultFlags, MOVE_RESULT_FOE_ENDURED, BattleScript_MultiLimbsMultiHitPrintStrings
	decrementmultihit BattleScript_MultiLimbsMultiHitLoop
	goto BattleScript_MultiLimbsMultiHitPrintStrings
BattleScript_MultiLimbsMultiHitNoMoreHits::
	pause B_WAIT_TIME_SHORT
BattleScript_MultiLimbsMultiHitPrintStrings::
	resultmessage
	waitmessage B_WAIT_TIME_LONG
	jumpifmovehadnoeffect BattleScript_MultiLimbsMultiHitEnd
	copyarray gBattleTextBuff1, sMULTIHIT_STRING, 6
	printstring STRINGID_HITXTIMES
	waitmessage B_WAIT_TIME_LONG
BattleScript_MultiLimbsMultiHitEnd::
	tryfaintmon BS_TARGET, FALSE, NULL
	moveendcase MOVEEND_SYNCHRONIZE_TARGET
	moveendfrom MOVEEND_STATUS_IMMUNITY_ABILITIES
	end

BattleScript_MultiHeadedActivates::
	call BattleScript_AbilityPopUp
	attackstring
	initmultihitstring
	addbyte sMULTIHIT_STRING + 4, 1
BattleScript_MultiHeadedMultiHitLoop::
	jumpifhasnohp BS_ATTACKER, BattleScript_MultiHeadedMultiHitEnd
	jumpifhasnohp BS_TARGET, BattleScript_MultiHeadedMultiHitPrintStrings
	jumpifhalfword CMP_EQUAL, gChosenMove, MOVE_SLEEP_TALK, BattleScript_MultiHeadedDoMultiHit
	jumpifstatus BS_ATTACKER, STATUS1_SLEEP, BattleScript_MultiHeadedMultiHitPrintStrings
BattleScript_MultiHeadedDoMultiHit::
	movevaluescleanup
	copyhword sMOVE_EFFECT, sSAVED_MOVE_EFFECT
	critcalc	
	damagecalc
	jumpifmovehadnoeffect BattleScript_MultiHeadedMultiHitNoMoreHits
	adjustdamage
	@attackanimation
	@waitanimation
	effectivenesssound
	hitanimation BS_TARGET
	waitstate
	healthbarupdate BS_TARGET
	datahpupdate BS_TARGET
	critmessage
	waitmessage B_WAIT_TIME_LONG
	multihitresultmessage
	printstring STRINGID_EMPTYSTRING3
	waitmessage 1
	seteffectwithchance
	addbyte sMULTIHIT_STRING + 4, 1
	moveendto MOVEEND_NEXT_TARGET
	jumpifbyte CMP_COMMON_BITS, gMoveResultFlags, MOVE_RESULT_FOE_ENDURED, BattleScript_MultiHeadedMultiHitPrintStrings
	decrementmultihit BattleScript_MultiHeadedMultiHitLoop
	goto BattleScript_MultiHeadedMultiHitPrintStrings
BattleScript_MultiHeadedMultiHitNoMoreHits::
	pause B_WAIT_TIME_SHORT
BattleScript_MultiHeadedMultiHitPrintStrings::
	resultmessage
	waitmessage B_WAIT_TIME_LONG
	jumpifmovehadnoeffect BattleScript_MultiHeadedMultiHitEnd
	copyarray gBattleTextBuff1, sMULTIHIT_STRING, 6
	printstring STRINGID_HITXTIMES
	waitmessage B_WAIT_TIME_LONG
BattleScript_MultiHeadedMultiHitEnd::
	tryfaintmon BS_TARGET, FALSE, NULL
	moveendcase MOVEEND_SYNCHRONIZE_TARGET
	moveendfrom MOVEEND_STATUS_IMMUNITY_ABILITIES
	end

BattleScript_BattleBondActivatesOnMoveEndAttacker::
	pause 5
	copybyte gBattlerAbility, gBattlerAttacker
	call BattleScript_AbilityPopUp
	printstring STRINGID_ATTACKERBECAMEFULLYCHARGED
	handleformchange BS_ATTACKER, 0
	handleformchange BS_ATTACKER, 1
	playanimation BS_ATTACKER, B_ANIM_FORM_CHANGE, NULL
	waitanimation
	handleformchange BS_ATTACKER, 2
	printstring STRINGID_ATTACKERBECAMEASHSPECIES
	return

BattleScript_DancerActivates::
	call BattleScript_AbilityPopUp
	waitmessage B_WAIT_TIME_SHORT
	setbyte sB_ANIM_TURN, 0
	setbyte sB_ANIM_TARGETS_HIT, 0
	orword gHitMarker, HITMARKER_x800000
	jumptocalledmove TRUE

BattleScript_SynchronizeActivates::
	waitstate
	call BattleScript_AbilityPopUp
	seteffectprimary
	return

BattleScript_NoItemSteal::
	call BattleScript_AbilityPopUp
	pause B_WAIT_TIME_SHORT
	printstring STRINGID_INNATEMADEINEFFECTIVE
	waitmessage B_WAIT_TIME_LONG
	return

BattleScript_AbilityCuredStatus::
	call BattleScript_AbilityPopUp
	printstring STRINGID_PKMNSXCUREDITSYPROBLEM
	waitmessage B_WAIT_TIME_LONG
	updatestatusicon BS_SCRIPTING
	return

BattleScript_BattlerShookOffTaunt::
	call BattleScript_AbilityPopUp
	printstring STRINGID_PKMNSHOOKOFFTHETAUNT
	waitmessage B_WAIT_TIME_LONG
	return

BattleScript_BattlerGotOverItsInfatuation::
	call BattleScript_AbilityPopUp
	printstring STRINGID_PKMNGOTOVERITSINFATUATION
	waitmessage B_WAIT_TIME_LONG
	return

BattleScript_IgnoresWhileAsleep::
	printstring STRINGID_PKMNIGNORESASLEEP
	waitmessage B_WAIT_TIME_LONG
	moveendto MOVEEND_NEXT_TARGET
	end

BattleScript_IgnoresAndUsesRandomMove::
	printstring STRINGID_PKMNIGNOREDORDERS
	waitmessage B_WAIT_TIME_LONG
	jumptocalledmove FALSE

BattleScript_MoveUsedLoafingAround::
	jumpifbyte CMP_EQUAL, cMULTISTRING_CHOOSER, B_MSG_LOAFING, BattleScript_MoveUsedLoafingAroundMsg
	jumpifbyte CMP_NOT_EQUAL, cMULTISTRING_CHOOSER, B_MSG_INCAPABLE_OF_POWER, BattleScript_MoveUsedLoafingAroundMsg
	setbyte gBattleCommunication, 0
	various24 BS_ATTACKER
	setbyte cMULTISTRING_CHOOSER, B_MSG_INCAPABLE_OF_POWER
BattleScript_MoveUsedLoafingAroundMsg::
	printfromtable gInobedientStringIds
	waitmessage B_WAIT_TIME_LONG
	moveendto MOVEEND_NEXT_TARGET
	end	
BattleScript_TruantLoafingAround::
	call BattleScript_AbilityPopUp
	goto BattleScript_MoveUsedLoafingAroundMsg

BattleScript_TruantLoafingAroundHibernating::
	printfromtable gInobedientStringIds
	waitmessage B_WAIT_TIME_LONG
	call BattleScript_AbilityPopUp
	printstring STRINGID_PKMNSXRESTOREDHPALITTLE2
	waitmessage B_WAIT_TIME_LONG
	orword gHitMarker, HITMARKER_IGNORE_SUBSTITUTE | HITMARKER_PASSIVE_DAMAGE
	healthbarupdate BS_ATTACKER
	datahpupdate BS_ATTACKER
	moveendto MOVEEND_NEXT_TARGET
	end	

BattleScript_IgnoresAndFallsAsleep::
	printstring STRINGID_PKMNBEGANTONAP
	waitmessage B_WAIT_TIME_LONG
	setmoveeffect MOVE_EFFECT_SLEEP | MOVE_EFFECT_AFFECTS_ATTACKER
	seteffectprimary
	moveendto MOVEEND_NEXT_TARGET
	end

BattleScript_IgnoresAndHitsItself::
	printstring STRINGID_PKMNWONTOBEY
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_DoSelfConfusionDmg

BattleScript_SubstituteFade::
	playanimation BS_TARGET, B_ANIM_SUBSTITUTE_FADE, NULL
	printfromtable gSubstitutionStringIds
	return

BattleScript_ShieldFadeUpdateHP::
	playanimation BS_TARGET, B_ANIM_SUBSTITUTE_FADE, NULL
	printfromtable gSubstitutionStringIds
	healthbarupdate BS_TARGET
	datahpupdate BS_TARGET
	return

BattleScript_TidyUpPlayerTeam::
	printstring STRINGID_HAZARDDISAPPEAREDPLAYERTEAM
	return

BattleScript_TidyUpOpposingTeam::
	printstring STRINGID_HAZARDDISAPPEAREDOPPOSINGTEAM
	return

BattleScript_TidyUpComplete::
	printstring STRINGID_TIDYUPCOMPLETE
	return

BattleScript_BerryCurePrlzEnd2::
	call BattleScript_BerryCureParRet
	end2

BattleScript_BerryCureParRet::
	playanimation BS_SCRIPTING, B_ANIM_HELD_ITEM_EFFECT, NULL
	printstring STRINGID_PKMNSITEMCUREDPARALYSIS
	waitmessage B_WAIT_TIME_LONG
	updatestatusicon BS_SCRIPTING
	removeitem BS_SCRIPTING, 1
	return

BattleScript_BerryCurePsnEnd2::
	call BattleScript_BerryCurePsnRet
	end2

BattleScript_BerryCurePsnRet::
	playanimation BS_SCRIPTING, B_ANIM_HELD_ITEM_EFFECT, NULL
	printstring STRINGID_PKMNSITEMCUREDPOISON
	waitmessage B_WAIT_TIME_LONG
	updatestatusicon BS_SCRIPTING
	removeitem BS_SCRIPTING, 1
	return

BattleScript_BerryCureBrnEnd2::
	call BattleScript_BerryCureBrnRet
	end2

BattleScript_BerryCureBrnRet::
	playanimation BS_SCRIPTING, B_ANIM_HELD_ITEM_EFFECT, NULL
	printstring STRINGID_PKMNSITEMHEALEDBURN
	waitmessage B_WAIT_TIME_LONG
	updatestatusicon BS_SCRIPTING
	removeitem BS_SCRIPTING, 1
	return

BattleScript_BerryCureFrzEnd2::
	call BattleScript_BerryCureFrzRet
	end2

BattleScript_BerryCureFrzRet::
	playanimation BS_SCRIPTING, B_ANIM_HELD_ITEM_EFFECT, NULL
	printstring STRINGID_PKMNSITEMDEFROSTEDIT
	waitmessage B_WAIT_TIME_LONG
	updatestatusicon BS_SCRIPTING
	removeitem BS_SCRIPTING, 1
	return

BattleScript_BerryCureSlpEnd2::
	call BattleScript_BerryCureSlpRet
	end2

BattleScript_BerryCureSlpRet::
	playanimation BS_SCRIPTING, B_ANIM_HELD_ITEM_EFFECT, NULL
	printstring STRINGID_PKMNSITEMWOKEIT
	waitmessage B_WAIT_TIME_LONG
	updatestatusicon BS_SCRIPTING
	removeitem BS_SCRIPTING, 1
	return

BattleScript_GemActivates::
	playanimation BS_ATTACKER, B_ANIM_HELD_ITEM_EFFECT, NULL
	waitanimation
	printstring STRINGID_GEMACTIVATES
	waitmessage B_WAIT_TIME_LONG
	removeitem BS_ATTACKER, 1
	return

BattleScript_BerryReduceDmg::
	playanimation BS_TARGET, B_ANIM_HELD_ITEM_EFFECT, NULL
	waitanimation
	printstring STRINGID_TARGETATEITEM
	waitmessage B_WAIT_TIME_LONG
	removeitem BS_TARGET, 1
	return

BattleScript_PrintBerryReduceString::
	waitmessage B_WAIT_TIME_LONG
	printstring STRINGID_BERRYDMGREDUCES
	waitmessage B_WAIT_TIME_LONG
	return

BattleScript_BerryCureConfusionEnd2::
	call BattleScript_BerryCureConfusionRet
	end2

BattleScript_BerryCureConfusionRet::
	playanimation BS_SCRIPTING, B_ANIM_HELD_ITEM_EFFECT, NULL
	printstring STRINGID_PKMNSITEMSNAPPEDOUT
	waitmessage B_WAIT_TIME_LONG
	removeitem BS_SCRIPTING, 1
	return

BattleScript_BerryCureChosenStatusEnd2::
	call BattleScript_BerryCureChosenStatusRet
	end2

BattleScript_BerryCureChosenStatusRet::
	playanimation BS_SCRIPTING, B_ANIM_HELD_ITEM_EFFECT, NULL
	printfromtable gBerryEffectStringIds
	waitmessage B_WAIT_TIME_LONG
	updatestatusicon BS_SCRIPTING
	removeitem BS_SCRIPTING, 1
	return

BattleScript_MentalHerbCureRet::
	playanimation BS_ATTACKER, B_ANIM_HELD_ITEM_EFFECT, NULL
	printfromtable gMentalHerbCureStringIds
	waitmessage B_WAIT_TIME_LONG
	updatestatusicon BS_SCRIPTING
	removeitem BS_SCRIPTING, 1
	copybyte gBattlerAttacker, sSAVED_BATTLER	@ restore the original attacker just to be safe
	return
	
BattleScript_MentalHerbCureEnd2::
	call BattleScript_MentalHerbCureRet
	end2

BattleScript_WhiteHerbEnd2::
	call BattleScript_WhiteHerbRet
	end2

BattleScript_WhiteHerbRet::
	playanimation BS_SCRIPTING, B_ANIM_HELD_ITEM_EFFECT, NULL
	printstring STRINGID_PKMNSITEMRESTOREDSTATUS
	waitmessage B_WAIT_TIME_LONG
	removeitem BS_SCRIPTING, 1
	return
	
BattleScript_ItemHealHP_RemoveItemRet::
	jumpifabilityorinnate BS_SCRIPTING, ABILITY_RIPEN, BattleScript_ItemHealHP_RemoveItemRet_AbilityPopUp
	goto BattleScript_ItemHealHP_RemoveItemRet_Anim
BattleScript_ItemHealHP_RemoveItemRet_AbilityPopUp:
	call BattleScript_AbilityPopUp
BattleScript_ItemHealHP_RemoveItemRet_Anim:
	playanimation BS_SCRIPTING, B_ANIM_HELD_ITEM_EFFECT, NULL
	printstring STRINGID_PKMNSITEMRESTOREDHEALTH
	waitmessage B_WAIT_TIME_LONG
	orword gHitMarker, HITMARKER_SKIP_DMG_TRACK | HITMARKER_IGNORE_SUBSTITUTE | HITMARKER_PASSIVE_DAMAGE
	healthbarupdate BS_SCRIPTING
	datahpupdate BS_SCRIPTING
	removeitem BS_SCRIPTING, 1
	return

BattleScript_ItemHealHP_RemoveItemEnd2::
	jumpifabilityorinnate BS_ATTACKER, ABILITY_RIPEN, BattleScript_ItemHealHP_RemoveItemEnd2_AbilityPopUp
	goto BattleScript_ItemHealHP_RemoveItemEnd2_Anim
BattleScript_ItemHealHP_RemoveItemEnd2_AbilityPopUp:
	call BattleScript_AbilityPopUp
BattleScript_ItemHealHP_RemoveItemEnd2_Anim:
	playanimation BS_ATTACKER, B_ANIM_HELD_ITEM_EFFECT, NULL
	printstring STRINGID_PKMNSITEMRESTOREDHEALTH
	waitmessage B_WAIT_TIME_LONG
	orword gHitMarker, HITMARKER_SKIP_DMG_TRACK | HITMARKER_IGNORE_SUBSTITUTE | HITMARKER_PASSIVE_DAMAGE
	healthbarupdate BS_ATTACKER
	datahpupdate BS_ATTACKER
	removeitem BS_ATTACKER, 1
	end2

BattleScript_BerryPPHealRet::
	jumpifabilityorinnate BS_ATTACKER, ABILITY_RIPEN, BattleScript_BerryPPHeal_AbilityPopup
	goto BattleScript_BerryPPHeal_Anim
BattleScript_BerryPPHeal_AbilityPopup:
	call BattleScript_AbilityPopUp
BattleScript_BerryPPHeal_Anim:
	playanimation BS_ATTACKER, B_ANIM_HELD_ITEM_EFFECT, NULL
	printstring STRINGID_PKMNSITEMRESTOREDPP
	waitmessage B_WAIT_TIME_LONG
	removeitem BS_ATTACKER, 1
	return

BattleScript_BerryPPHealEnd2::
	call BattleScript_BerryPPHealRet
	end2

BattleScript_ItemHealHP_End2::
	call BattleScript_ItemHealHP_Ret
	end2

BattleScript_ItemHealHPOnConsume_End2::
	call BattleScript_ItemHealHPOnConsume_Ret
	end2

BattleScript_AirBaloonMsgIn::
	printstring STRINGID_AIRBALLOONFLOAT
	waitmessage B_WAIT_TIME_LONG
	end3

BattleScript_AirBaloonMsgPop::
	printstring STRINGID_AIRBALLOONPOP
	waitmessage B_WAIT_TIME_LONG
	removeitem BS_TARGET
	return

BattleScript_ItemHurtWithMoveEffectOnTargetRet::
	call BattleScript_ItemHurtOnTargetRet
	call BattleScript_ApplyMoveEffect_Ret
	return

BattleScript_ItemHurtOnTargetRet::
	playanimation BS_TARGET, B_ANIM_MON_HIT, NULL
	waitanimation
	healthbarupdate BS_TARGET
	datahpupdate BS_TARGET
	printstring STRINGID_HURTTARGETBYITEM
	waitmessage B_WAIT_TIME_LONG
	tryfaintmon BS_TARGET, FALSE, NULL
	return

BattleScript_ItemHurtRet::
	orword gHitMarker, HITMARKER_IGNORE_SUBSTITUTE | HITMARKER_PASSIVE_DAMAGE | HITMARKER_IGNORE_DISGUISE
	healthbarupdate BS_ATTACKER
	datahpupdate BS_ATTACKER
	printstring STRINGID_HURTBYITEM
	waitmessage B_WAIT_TIME_LONG
	tryfaintmon BS_ATTACKER, FALSE, NULL
	return

BattleScript_ItemCursedRet::
	playanimation BS_ATTACKER, B_ANIM_MON_HIT, NULL
	waitanimation
	status2animation BS_ATTACKER, STATUS2_CURSED
	printstring STRINGID_CURSEDBYITEM
	waitmessage B_WAIT_TIME_LONG
	return

BattleScript_ItemHurtEnd2::
	playanimation BS_ATTACKER, B_ANIM_MON_HIT, NULL
	waitanimation
	call BattleScript_ItemHurtRet
	end2

BattleScript_ApplyItemEffect_Ret::
	playanimation BS_ATTACKER, B_ANIM_HELD_ITEM_EFFECT, NULL
BattleScript_ApplyMoveEffect_Ret::
	seteffectwithchance
	waitstate
	return
	
BattleScript_ItemHealHP_Ret::
	playanimation BS_ATTACKER, B_ANIM_HELD_ITEM_EFFECT, NULL
	printstring STRINGID_PKMNSITEMRESTOREDHPALITTLE
	waitmessage B_WAIT_TIME_LONG
	orword gHitMarker, HITMARKER_SKIP_DMG_TRACK | HITMARKER_IGNORE_SUBSTITUTE | HITMARKER_IGNORE_DISGUISE | HITMARKER_PASSIVE_DAMAGE
	healthbarupdate BS_ATTACKER
	datahpupdate BS_ATTACKER
	return

BattleScript_ItemHealHPOnConsume_Ret::
	playanimation BS_ATTACKER, B_ANIM_HELD_ITEM_EFFECT, NULL
	printstring STRINGID_PKMNSITEMRESTOREDHPALITTLE
	waitmessage B_WAIT_TIME_LONG
	orword gHitMarker, HITMARKER_SKIP_DMG_TRACK | HITMARKER_IGNORE_SUBSTITUTE | HITMARKER_IGNORE_DISGUISE | HITMARKER_PASSIVE_DAMAGE
	healthbarupdate BS_ATTACKER
	datahpupdate BS_ATTACKER
	removeitem BS_ATTACKER, 1
	return

BattleScript_SelectingNotAllowedMoveChoiceItem::
	printselectionstring STRINGID_ITEMALLOWSONLYYMOVE
	endselectionscript

BattleScript_SelectingNotAllowedMoveChoiceItemInPalace::
	printstring STRINGID_ITEMALLOWSONLYYMOVE
	goto BattleScript_SelectingUnusableMoveInPalace

BattleScript_SelectingNotAllowedMoveGorillaTactics::
	printselectionstring STRINGID_ABILITYALLOWSONLYMOVE
	endselectionscript

BattleScript_SelectingNotAllowedMoveGorillaTacticsInPalace::
	printstring STRINGID_ABILITYALLOWSONLYMOVE
	goto BattleScript_SelectingUnusableMoveInPalace

BattleScript_SelectingNotAllowedMoveAssaultVest::
	printselectionstring STRINGID_ASSAULTVESTDOESNTALLOW
	endselectionscript

BattleScript_SelectingNotAllowedMoveAssaultVestInPalace::
	printstring STRINGID_ASSAULTVESTDOESNTALLOW
	goto BattleScript_SelectingUnusableMoveInPalace

BattleScript_HangedOnMsg::
	playanimation BS_TARGET, B_ANIM_HANGED_ON, NULL
	printstring STRINGID_PKMNHUNGONWITHX
	waitmessage B_WAIT_TIME_LONG
	jumpifnoholdeffect BS_TARGET, HOLD_EFFECT_FOCUS_SASH, BattleScript_HangedOnMsgRet
	removeitem BS_TARGET
BattleScript_HangedOnMsgRet:
	return

BattleScript_BerryConfuseHealEnd2::
	jumpifabilityorinnate BS_SCRIPTING, ABILITY_RIPEN, BattleScript_BerryConfuseHealEnd2_AbilityPopup
	goto BattleScript_BerryConfuseHealEnd2_Anim
BattleScript_BerryConfuseHealEnd2_AbilityPopup:
	call BattleScript_AbilityPopUp
BattleScript_BerryConfuseHealEnd2_Anim:
	playanimation BS_SCRIPTING, B_ANIM_HELD_ITEM_EFFECT, NULL
	printstring STRINGID_PKMNSITEMRESTOREDHEALTH
	waitmessage B_WAIT_TIME_LONG
	orword gHitMarker, HITMARKER_SKIP_DMG_TRACK | HITMARKER_IGNORE_SUBSTITUTE | HITMARKER_PASSIVE_DAMAGE
	healthbarupdate BS_SCRIPTING
	datahpupdate BS_SCRIPTING
	printstring STRINGID_FORXCOMMAYZ
	waitmessage B_WAIT_TIME_LONG
	setmoveeffect MOVE_EFFECT_CONFUSE | MOVE_EFFECT_AFFECTS_ATTACKER
	seteffectprimary
	removeitem BS_SCRIPTING, 1
	end2

BattleScript_BerryConfuseHealRet::
	jumpifabilityorinnate BS_SCRIPTING, ABILITY_RIPEN, BattleScript_BerryConfuseHealRet_AbilityPopup
	goto BattleScript_BerryConfuseHealRet_Anim
BattleScript_BerryConfuseHealRet_AbilityPopup:
	call BattleScript_AbilityPopUp
BattleScript_BerryConfuseHealRet_Anim:
	playanimation BS_SCRIPTING, B_ANIM_HELD_ITEM_EFFECT, NULL
	printstring STRINGID_PKMNSITEMRESTOREDHEALTH
	waitmessage B_WAIT_TIME_LONG
	orword gHitMarker, HITMARKER_SKIP_DMG_TRACK | HITMARKER_IGNORE_SUBSTITUTE | HITMARKER_PASSIVE_DAMAGE
	healthbarupdate BS_SCRIPTING
	datahpupdate BS_SCRIPTING
	printstring STRINGID_FORXCOMMAYZ
	waitmessage B_WAIT_TIME_LONG
	setmoveeffect MOVE_EFFECT_CONFUSE | MOVE_EFFECT_CERTAIN
	seteffectprimary
	removeitem BS_TARGET, 1
	return

BattleScript_BerryStatRaiseEnd2::
	jumpifabilityorinnate BS_ATTACKER, ABILITY_RIPEN, BattleScript_BerryStatRaiseEnd2_AbilityPopup
	goto BattleScript_BerryStatRaiseEnd2_Anim
BattleScript_BerryStatRaiseEnd2_AbilityPopup:
	call BattleScript_AbilityPopUp
BattleScript_BerryStatRaiseEnd2_Anim:
	statbuffchange STAT_CHANGE_ALLOW_PTR, BattleScript_BerryStatRaiseEnd2_End
	setgraphicalstatchangevalues
	playanimation BS_ATTACKER, B_ANIM_HELD_ITEM_EFFECT, sB_ANIM_ARG1
	setbyte cMULTISTRING_CHOOSER, B_MSG_STAT_ROSE_ITEM
	call BattleScript_StatUp
	removeitem BS_ATTACKER, 1
BattleScript_BerryStatRaiseEnd2_End::
	end2

BattleScript_BerryStatRaiseRet::
	jumpifabilityorinnate BS_SCRIPTING, ABILITY_RIPEN, BattleScript_BerryStatRaiseRet_AbilityPopup
	goto BattleScript_BerryStatRaiseRet_Anim
BattleScript_BerryStatRaiseRet_AbilityPopup:
	call BattleScript_AbilityPopUp
BattleScript_BerryStatRaiseRet_Anim:
	statbuffchange STAT_CHANGE_ALLOW_PTR, BattleScript_BerryStatRaiseRet_End
	setgraphicalstatchangevalues
	playanimation BS_SCRIPTING, B_ANIM_HELD_ITEM_EFFECT, sB_ANIM_ARG1
	setbyte cMULTISTRING_CHOOSER, B_MSG_STAT_ROSE_ITEM
	call BattleScript_StatUp
	removeitem BS_SCRIPTING, 1
BattleScript_BerryStatRaiseRet_End:
	return

BattleScript_BerryFocusEnergyRet::
	playanimation BS_SCRIPTING, B_ANIM_HELD_ITEM_EFFECT, NULL
	printstring STRINGID_PKMNUSEDXTOGETPUMPED
	waitmessage B_WAIT_TIME_LONG
	removeitem BS_SCRIPTING, 1
	return

BattleScript_BerryFocusEnergyEnd2::
	call BattleScript_BerryFocusEnergyRet
	end2

BattleScript_BerserkGeneEnd2::
	playanimation BS_ATTACKER, B_ANIM_HELD_ITEM_EFFECT, NULL
	printstring STRINGID_PKMNUSEDXTOBECOMEBERSERK
	waitmessage B_WAIT_TIME_LONG
	removeitem BS_ATTACKER, 1
	end2

BattleScript_BoosterEnergyEnd2::
	playanimation BS_ATTACKER, B_ANIM_HELD_ITEM_EFFECT, NULL
	waitanimation
	call BattleScript_AbilityPopUp
	printstring STRINGID_PKMNUSEDXTOACTIVATEABILITY
	waitmessage B_WAIT_TIME_MED
	printstring STRINGID_STATWASHEIGHTENED
	waitmessage B_WAIT_TIME_MED
	removeitem BS_ATTACKER, 1
	end2

BattleScript_ActionSelectionItemsCantBeUsed::
	printselectionstring STRINGID_ITEMSCANTBEUSEDNOW
	endselectionscript

BattleScript_FlushMessageBox::
	printstring STRINGID_EMPTYSTRING3
	return

BattleScript_PalacePrintFlavorText::
	setbyte gBattleCommunication + 1, 0
BattleScript_PalaceTryBattlerFlavorText::
	palaceflavortext BS_ATTACKER @ BS_ATTACKER here overwritten by gBattleCommunication + 1
	jumpifbyte CMP_NOT_EQUAL, gBattleCommunication, TRUE, BattleScript_PalaceEndFlavorText
	printfromtable gBattlePalaceFlavorTextTable
	waitmessage B_WAIT_TIME_LONG
BattleScript_PalaceEndFlavorText::
	addbyte gBattleCommunication + 1, 1
	jumpifbytenotequal gBattleCommunication + 1, gBattlersCount, BattleScript_PalaceTryBattlerFlavorText
	setbyte gBattleCommunication, 0
	setbyte gBattleCommunication + 1, 0
	end2

BattleScript_ArenaTurnBeginning::
	waitcry BS_ATTACKER
	volumedown
	playse SE_ARENA_TIMEUP1
	pause 8
	playse SE_ARENA_TIMEUP1
	various14 BS_ATTACKER
	arenajudgmentstring B_MSG_REF_COMMENCE_BATTLE
	arenawaitmessage B_MSG_REF_COMMENCE_BATTLE
	pause B_WAIT_TIME_LONG
	various15 BS_ATTACKER
	volumeup
	end2

@ Unused
BattleScript_ArenaNothingDecided::
	playse SE_DING_DONG
	various14 BS_ATTACKER
	arenajudgmentstring B_MSG_REF_NOTHING_IS_DECIDED
	arenawaitmessage B_MSG_REF_NOTHING_IS_DECIDED
	pause B_WAIT_TIME_LONG
	various15 BS_ATTACKER
	end2

BattleScript_ArenaDoJudgment::
	makevisible BS_PLAYER1
	waitstate
	makevisible BS_OPPONENT1
	waitstate
	volumedown
	playse SE_ARENA_TIMEUP1
	pause 8
	playse SE_ARENA_TIMEUP1
	pause B_WAIT_TIME_LONG
	various14 BS_ATTACKER
	arenajudgmentstring B_MSG_REF_THATS_IT
	arenawaitmessage B_MSG_REF_THATS_IT
	pause B_WAIT_TIME_LONG
	setbyte gBattleCommunication, 0
	arenajudgmentwindow
	pause B_WAIT_TIME_LONG
	arenajudgmentwindow
	arenajudgmentstring B_MSG_REF_JUDGE_MIND
	arenawaitmessage B_MSG_REF_JUDGE_MIND
	arenajudgmentwindow
	arenajudgmentstring B_MSG_REF_JUDGE_SKILL
	arenawaitmessage B_MSG_REF_JUDGE_SKILL
	arenajudgmentwindow
	arenajudgmentstring B_MSG_REF_JUDGE_BODY
	arenawaitmessage B_MSG_REF_JUDGE_BODY
	arenajudgmentwindow
	jumpifbyte CMP_EQUAL, gBattleCommunication + 1, 3, BattleScript_ArenaJudgmentPlayerLoses
	jumpifbyte CMP_EQUAL, gBattleCommunication + 1, 4, BattleScript_ArenaJudgmentDraw
	arenajudgmentstring B_MSG_REF_PLAYER_WON
	arenawaitmessage B_MSG_REF_PLAYER_WON
	arenajudgmentwindow
	various15 BS_ATTACKER
	printstring STRINGID_DEFEATEDOPPONENTBYREFEREE
	waitmessage B_WAIT_TIME_LONG
	playfaintcry BS_OPPONENT1
	waitcry BS_ATTACKER
	dofaintanimation BS_OPPONENT1
	cleareffectsonfaint BS_OPPONENT1
	arenaopponentmonlost
	end2

BattleScript_ArenaJudgmentPlayerLoses:
	arenajudgmentstring B_MSG_REF_OPPONENT_WON
	arenawaitmessage B_MSG_REF_OPPONENT_WON
	arenajudgmentwindow
	various15 BS_ATTACKER
	printstring STRINGID_LOSTTOOPPONENTBYREFEREE
	waitmessage B_WAIT_TIME_LONG
	playfaintcry BS_PLAYER1
	waitcry BS_ATTACKER
	dofaintanimation BS_PLAYER1
	cleareffectsonfaint BS_PLAYER1
	arenaplayermonlost
	end2

BattleScript_ArenaJudgmentDraw:
	arenajudgmentstring B_MSG_REF_DRAW
	arenawaitmessage B_MSG_REF_DRAW
	arenajudgmentwindow
	various15 BS_ATTACKER
	printstring STRINGID_TIEDOPPONENTBYREFEREE
	waitmessage B_WAIT_TIME_LONG
	playfaintcry BS_PLAYER1
	waitcry BS_ATTACKER
	dofaintanimation BS_PLAYER1
	cleareffectsonfaint BS_PLAYER1
	playfaintcry BS_OPPONENT1
	waitcry BS_ATTACKER
	dofaintanimation BS_OPPONENT1
	cleareffectsonfaint BS_OPPONENT1
	arenabothmonlost
	end2

BattleScript_AskIfWantsToForfeitMatch::
	printselectionstring STRINGID_QUESTIONFORFEITMATCH
	forfeityesnobox BS_ATTACKER
	endselectionscript

BattleScript_PrintPlayerForfeited::
	printstring STRINGID_FORFEITEDMATCH
	waitmessage B_WAIT_TIME_LONG
	end2

BattleScript_PrintPlayerForfeitedLinkBattle::
	printstring STRINGID_FORFEITEDMATCH
	waitmessage B_WAIT_TIME_LONG
	endlinkbattle
	waitmessage B_WAIT_TIME_LONG
	end2

BattleScript_Safari_OneTypeChallengeCaptureBlocked::
	printselectionstring STRINGID_ONETYPECAPTUREBLOCKED
	endselectionscript

BattleScript_Safari_NuzlockeCaptureBlocked::
	printselectionstring STRINGID_NUZLOCKECAPTUREBLOCKED
	endselectionscript

BattleScript_Safari_EvolineClauseCaptureBlocked::
	printselectionstring STRINGID_EVOLINECLAUSECAPTUREBLOCKED
	endselectionscript

BattleScript_Safari_SpeciesClauseCaptureBlocked::
	printselectionstring STRINGID_SPECIESCLAUSECAPTUREBLOCKED
	endselectionscript

BattleScript_CantThrowPokeBall_TwoMons::
	printselectionstring STRINGID_CANTTHROWBALL_TWOMONS
	endselectionscript

BattleScript_CantThrowPokeBall_BoxFull::
	printselectionstring STRINGID_CANTTHROWBALL_BOXFULL
	endselectionscript

BattleScript_CantThrowPokeBall_SemiIvulnerable::
	printselectionstring STRINGID_CANTTHROWBALL_SEMIINVULNERABLE
	endselectionscript

BattleScript_Safari_ItemUsageBlocked::
	printselectionstring STRINGID_ITEMUSAGEBLOCKED
	endselectionscript

BattleScript_TotemFlaredToLife::
	playanimation BS_ATTACKER, B_ANIM_TOTEM_FLARE, NULL
	printstring STRINGID_AURAFLAREDTOLIFE
	waitmessage B_WAIT_TIME_LONG
	goto BattleScript_ApplyTotemVarBoost

BattleScript_AnnounceAirLockCloudNine::
	call BattleScript_AbilityPopUp
	printstring STRINGID_AIRLOCKACTIVATES
	waitmessage B_WAIT_TIME_LONG
	call BattleScript_WeatherFormChanges
	end3

BattleScript_QuickClawActivation::
	printstring STRINGID_EMPTYSTRING3
	waitmessage 1
	playanimation BS_ATTACKER, B_ANIM_HELD_ITEM_EFFECT, NULL
	waitanimation
	printstring STRINGID_CANACTFASTERTHANKSTO
	waitmessage B_WAIT_TIME_LONG
	end2

BattleScript_QuickDrawActivation::
	printstring STRINGID_EMPTYSTRING3
	waitmessage 1
	call BattleScript_AbilityPopUp
	printstring STRINGID_CANACTFASTERTHANKSTO
	waitmessage B_WAIT_TIME_LONG
	end2

BattleScript_CustapBerryActivation::
	printstring STRINGID_EMPTYSTRING3
	waitmessage 1
	playanimation BS_ATTACKER, B_ANIM_HELD_ITEM_EFFECT, NULL
	waitanimation
	printstring STRINGID_CANACTFASTERTHANKSTO
	waitmessage B_WAIT_TIME_LONG
	removeitem BS_ATTACKER, 1
	end2

BattleScript_MicleBerryActivateEnd2::
	jumpifabilityorinnate BS_ATTACKER, ABILITY_RIPEN, BattleScript_MicleBerryActivateEnd2_Ripen
	goto BattleScript_MicleBerryActivateEnd2_Anim
BattleScript_MicleBerryActivateEnd2_Ripen:
	call BattleScript_AbilityPopUp
BattleScript_MicleBerryActivateEnd2_Anim:
	playanimation BS_ATTACKER, B_ANIM_HELD_ITEM_EFFECT, NULL
	printstring STRINGID_MICLEBERRYACTIVATES
	waitmessage B_WAIT_TIME_LONG
	removeitem BS_ATTACKER, 1
	end2

BattleScript_MicleBerryActivateRet::
	jumpifabilityorinnate BS_SCRIPTING, ABILITY_RIPEN, BattleScript_MicleBerryActivateRet_Ripen
	goto BattleScript_MicleBerryActivateRet_Anim
BattleScript_MicleBerryActivateRet_Ripen:
	call BattleScript_AbilityPopUp
BattleScript_MicleBerryActivateRet_Anim:
	playanimation BS_SCRIPTING, B_ANIM_HELD_ITEM_EFFECT, NULL
	printstring STRINGID_MICLEBERRYACTIVATES
	waitmessage B_WAIT_TIME_LONG
	removeitem BS_SCRIPTING, 1
	return

BattleScript_JabocaRowapBerryActivates::
	jumpifabilityorinnate BS_TARGET, ABILITY_RIPEN, BattleScript_JabocaRowapBerryActivate_Ripen
	goto BattleScript_JabocaRowapBerryActivate_Anim
BattleScript_JabocaRowapBerryActivate_Ripen:
	call BattleScript_AbilityPopUp
BattleScript_JabocaRowapBerryActivate_Anim:
	jumpifabsent BS_TARGET, BattleScript_JabocaRowapBerryActivate_Dmg	@ dont play the animation for a fainted target
	playanimation BS_TARGET, B_ANIM_HELD_ITEM_EFFECT, NULL
	waitanimation
BattleScript_JabocaRowapBerryActivate_Dmg:
	call BattleScript_HurtAttacker
	removeitem BS_TARGET, 1
	return

BattleScript_Pickpocket::
	call BattleScript_AbilityPopUp
	jumpifabilityorinnate BS_ATTACKER, ABILITY_STICKY_HOLD, BattleScript_PickpocketPrevented
	swapattackerwithtarget
	call BattleScript_ItemSteal
	swapattackerwithtarget
	activateitemeffects BS_TARGET
	return

BattleScript_PickpocketPrevented:
	sethword sABILITY_OVERWRITE, ABILITY_STICKY_HOLD
	pause B_WAIT_TIME_SHORT
	copybyte gBattlerAbility, gBattlerAttacker
	call BattleScript_AbilityPopUp
	printstring STRINGID_ITEMCANNOTBEREMOVED
	waitmessage B_WAIT_TIME_LONG
	return

BattleScript_StickyBarbTransfer::
	playanimation BS_TARGET, B_ANIM_ITEM_STEAL, NULL
	printstring STRINGID_STICKYBARBTRANSFER
	waitmessage B_WAIT_TIME_LONG
	removeitem BS_TARGET
	return

BattleScript_RedCardActivates::
	playanimation BS_SCRIPTING, B_ANIM_HELD_ITEM_EFFECT, NULL
	printstring STRINGID_REDCARDACTIVATE
	waitmessage 0x40
	swapattackerwithtarget
	jumpifstatus3 BS_EFFECT_BATTLER, STATUS3_ROOTED, BattleScript_RedCardIngrain
	jumpifabilityorinnate BS_EFFECT_BATTLER, ABILITY_SUCTION_CUPS, BattleScript_RedCardSuctionCups
	jumpifnoholdeffect BS_EFFECT_BATTLER, HOLD_EFFECT_STRONG_SHIELD, BattleScript_RedCardContinue
	goto BattleScript_RedCardEnd
BattleScript_RedCardContinue:
	setbyte sSWITCH_CASE, B_SWITCH_RED_CARD
	forcerandomswitch BattleScript_RedCardEnd
	@ changes the current battle script. the rest happens in BattleScript_RoarSuccessSwitch_Ret, if switch is successful
BattleScript_RedCardEnd:
	swapattackerwithtarget
	return
BattleScript_RedCardIngrain:
	printstring STRINGID_PKMNANCHOREDITSELF
	waitmessage 0x40
	removeitem BS_SCRIPTING, 1
	goto BattleScript_RedCardEnd
BattleScript_RedCardSuctionCups:
	printstring STRINGID_PKMNANCHORSITSELFWITH	
	waitmessage 0x40
	removeitem BS_SCRIPTING, 1
	goto BattleScript_RedCardEnd

BattleScript_StenchActivates::	
	call BattleScript_AbilityPopUp
	printstring STRINGID_STENCHACTIVATE
	waitmessage 0x40
BattleScript_StenchSwitchBattlers:
	swapattackerwithtarget
	jumpifstatus3 BS_TARGET, STATUS3_ROOTED, BattleScript_StenchIngrain
	jumpifabilityorinnate BS_TARGET, ABILITY_SUCTION_CUPS, BattleScript_StenchSuctionCups
	jumpifnoholdeffect BS_TARGET, HOLD_EFFECT_STRONG_SHIELD, BattleScript_StenchContinue
	goto BattleScript_StenchEnd
BattleScript_StenchContinue:
	setbyte sSWITCH_CASE, B_SWITCH_RED_CARD
	forcerandomswitch BattleScript_StenchEnd
BattleScript_StenchEnd:
	swapattackerwithtarget
	tryfaintmon BS_TARGET, FALSE, NULL
	return
BattleScript_StenchIngrain:
	printstring STRINGID_PKMNANCHOREDITSELF
	waitmessage 0x40
	goto BattleScript_StenchEnd
BattleScript_StenchSuctionCups:
	printstring STRINGID_PKMNANCHORSITSELFWITH	
	waitmessage 0x40
	goto BattleScript_StenchEnd

BattleScript_TacticalRetreatActivates::
	call BattleScript_AbilityPopUp
	printstring STRINGID_TACTICALRETREATACTIVATE
	waitmessage 0x40
	goto BattleScript_StenchSwitchBattlers

BattleScript_EjectButtonActivates::
	makevisible BS_ATTACKER
	playanimation BS_SCRIPTING, B_ANIM_HELD_ITEM_EFFECT, NULL
	printstring STRINGID_EJECTBUTTONACTIVATE
	waitmessage 0x40
	removeitem BS_SCRIPTING, 1
	makeinvisible BS_SCRIPTING
	openpartyscreen BS_SCRIPTING, BattleScript_EjectButtonEnd
	switchoutabilitiesorinnates BS_SCRIPTING, 0
	switchoutabilitiesorinnates BS_SCRIPTING, 1
	switchoutabilitiesorinnates BS_SCRIPTING, 2
	switchoutabilitiesorinnates BS_SCRIPTING, 3
	swithchoutrevolvingruin BS_SCRIPTING
	waitstate
	switchhandleorder BS_SCRIPTING 0x2
	returntoball BS_SCRIPTING
	getswitchedmondata BS_SCRIPTING
	switchindataupdate BS_SCRIPTING
	hpthresholds BS_SCRIPTING
	trytoclearprimalweather
	printstring STRINGID_EMPTYSTRING3
	waitmessage 1
	printstring 0x3
	switchinanim BS_SCRIPTING 0x1
	waitstate
	switchineffects BS_SCRIPTING
BattleScript_EjectButtonEnd:
	return

BattleScript_EjectPackActivate_Ret::
	goto BattleScript_EjectButtonActivates

BattleScript_EjectPackActivate_End2::
	call BattleScript_EjectPackActivate_Ret
	end2

BattleScript_EjectPackActivates::
	jumpifcantswitch BS_SCRIPTING, BattleScript_EjectButtonEnd
	goto BattleScript_EjectPackActivate_Ret

BattleScript_DarkTypePreventsPrankster::
	attackstring
	ppreduce
	pause B_WAIT_TIME_SHORT
	printstring STRINGID_ITDOESNTAFFECT
	waitmessage B_WAIT_TIME_LONG
	orhalfword gMoveResultFlags, MOVE_RESULT_NO_EFFECT
	goto BattleScript_MoveEnd


BattleScript_NeutralizingGasExits::
	savetarget
	pause B_WAIT_TIME_SHORT
	printstring STRINGID_NEUTRALIZINGGASOVER
	waitmessage B_WAIT_TIME_LONG
	setbyte gBattlerTarget, 0
BattleScript_NeutralizingGasExitsLoop:
	switchinabilities BS_TARGET
	addbyte gBattlerTarget, 1
	jumpifbytenotequal gBattlerTarget, gBattlersCount, BattleScript_NeutralizingGasExitsLoop	@ SOMEHOW, comparing to gBattlersCount is problematic.
	restoretarget
	restoreneutralizinggasactivebattler
	return

BattleScript_MagicianActivates::
	call BattleScript_AbilityPopUp
	call BattleScript_ItemSteal
	return

@ z moves / effects
BattleScript_ZMoveActivateDamaging::
	printstring STRINGID_ZPOWERSURROUNDS
	playanimation BS_ATTACKER, B_ANIM_ZMOVE_ACTIVATE, NULL
	printstring STRINGID_ZMOVEUNLEASHED
	waitmessage B_WAIT_TIME_LONG
	return

BattleScript_ZMoveActivateStatus::
	savetarget
	printstring STRINGID_ZPOWERSURROUNDS
	playanimation BS_ATTACKER, B_ANIM_ZMOVE_ACTIVATE, NULL
	setzeffect
	restoretarget
	copybyte sSTATCHANGER, sSAVED_STAT_CHANGER
	return

BattleScript_ZEffectPrintString::
	printfromtable gZEffectStringIds
	waitmessage B_WAIT_TIME_LONG
	return

BattleScript_RecoverHPZMove::
	healthbarupdate BS_SCRIPTING
	datahpupdate BS_SCRIPTING
	printfromtable gZEffectStringIds
	waitmessage B_WAIT_TIME_LONG
	return

BattleScript_StatUpZMove::
	statbuffchange MOVE_EFFECT_AFFECTS_ATTACKER | STAT_CHANGE_ALLOW_PTR, BattleScript_StatUpZMoveEnd
	jumpifbyte CMP_EQUAL, cMULTISTRING_CHOOSER, B_MSG_STAT_WONT_INCREASE, BattleScript_StatUpZMoveEnd
	setgraphicalstatchangevalues
	playanimation BS_ATTACKER, B_ANIM_STATS_CHANGE, sB_ANIM_ARG1
	printstring STRINGID_ZMOVESTATUP
	waitmessage B_WAIT_TIME_LONG
	printfromtable gStatUpStringIds
	waitmessage B_WAIT_TIME_LONG
BattleScript_StatUpZMoveEnd:
	return

BattleScript_HealReplacementZMove::
	playanimation BS_SCRIPTING B_ANIM_WISH_HEAL 0x0
	printfromtable gZEffectStringIds
	waitmessage B_WAIT_TIME_LONG
	healthbarupdate BS_SCRIPTING
	datahpupdate BS_SCRIPTING
	return

BattleScript_MysticalHornHealing::
	playanimation BS_SCRIPTING B_ANIM_WISH_HEAL 0x0
	printstring STRINGID_MYSTICAL_HORN_HEALING
	waitmessage B_WAIT_TIME_LONG
	orword gHitMarker, HITMARKER_IGNORE_SUBSTITUTE
	healthbarupdate BS_SCRIPTING
	datahpupdate BS_SCRIPTING
	healstatuscondition BS_SCRIPTING, 1
	updatestatusicon BS_SCRIPTING
	return

BattleScript_BlackMagicCurseActivated::
	status2animation BS_SCRIPTING, STATUS2_CURSED
	printstring STRINGID_BLACK_MAGIC_CURSE
	waitmessage B_WAIT_TIME_LONG
	return
BattleScript_BlackMagicCurseFailed::
	printstring STRINGID_BLACK_MAGIC_FAILED
	waitmessage B_WAIT_TIME_LONG
	return

BattleScript_ProtosynthesisActivates::
	call BattleScript_AbilityPopUp
	printstring STRINGID_SUNLIGHTACTIVATEDABILITY
	waitmessage B_WAIT_TIME_MED
	printstring STRINGID_STATWASHEIGHTENED
	waitmessage B_WAIT_TIME_MED
	end3

BattleScript_QuarkDriveActivates::
	call BattleScript_AbilityPopUp
	printstring STRINGID_ELECTRICTERRAINACTIVATEDABILITY
	waitmessage B_WAIT_TIME_MED
	printstring STRINGID_STATWASHEIGHTENED
	waitmessage B_WAIT_TIME_MED
	end3
