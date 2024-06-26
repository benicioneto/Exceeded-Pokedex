const struct BattleMove gBattleMoves[MOVES_COUNT_DYNAMAX] =
{
    [MOVE_NONE] =
    {
        .effect = EFFECT_HIT,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 0,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = 0,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_NONE_SPECIAL] =
    {
        .effect = EFFECT_HIT,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 0,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = 0,
        .split = SPLIT_SPECIAL,
    },

    [MOVE_POUND] =
    {
        .effect = EFFECT_HIT,
        .power = 40,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 35,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .flags2 = FLAG_SCENT_MARK_AFFECTED,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 100,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_KARATE_CHOP] =
    {
        .effect = EFFECT_HIT,
        .power = 70,
        .type = TYPE_FIGHTING,
        .accuracy = 100,
        .pp = 20,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_HIGH_CRITICAL_HIT_RATIO,
        .flags2 = FLAG_SCENT_MARK_AFFECTED,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 140,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_DOUBLE_SLAP] =
    {
        .effect = EFFECT_TARGET_MULTI_HIT,
        .power = 25,
        .type = TYPE_FAIRY,
        .accuracy = 90,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 100,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_COMET_PUNCH] =
    {
        .effect = EFFECT_TARGET_MULTI_HIT,
        .power = 15,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 15,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 1,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_PUNCHING_MOVE,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 100,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_MEGA_PUNCH] =
    {
        .effect = EFFECT_TARGET_FLINCH_ON_HIT,
        .power = 80,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 15,
        .secondaryEffectChance = 30,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_PUNCHING_MOVE,
        .flags2 = FLAG_SCENT_MARK_AFFECTED,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 160,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_PAY_DAY] =
    {
        .effect = EFFECT_USER_RECEIVE_MONEY,
        .power = 60,
        .type = TYPE_STEEL,
        .accuracy = 100,
        .pp = 20,
        .secondaryEffectChance = 100,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 120,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_FIRE_PUNCH] =
    {
        .effect = EFFECT_TARGET_BURN_ON_HIT,
        .power = 75,
        .type = TYPE_FIRE,
        .accuracy = 100,
        .pp = 15,
        .secondaryEffectChance = 10,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_PUNCHING_MOVE | FLAG_HAS_SECONDARY_EFFECT,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 140,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_ICE_PUNCH] =
    {
        .effect = EFFECT_TARGET_FROSTBITE_ON_HIT,
        .power = 75,
        .type = TYPE_ICE,
        .accuracy = 100,
        .pp = 15,
        .secondaryEffectChance = 10,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_PUNCHING_MOVE | FLAG_HAS_SECONDARY_EFFECT,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 140,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_THUNDER_PUNCH] =
    {
        .effect = EFFECT_TARGET_PARALYZE_ON_HIT,
        .power = 75,
        .type = TYPE_ELECTRIC,
        .accuracy = 100,
        .pp = 15,
        .secondaryEffectChance = 10,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_PUNCHING_MOVE | FLAG_HAS_SECONDARY_EFFECT,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 140,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_SCRATCH] =
    {
        .effect = EFFECT_HIT,
        .power = 40,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 35,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .flags2 = FLAG_SCENT_MARK_AFFECTED,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 100,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_VISE_GRIP] =
    {
        .effect = EFFECT_HIT,
        .power = 70,
        .type = TYPE_BUG,
        .accuracy = 100,
        .pp = 20,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_HIGH_CRITICAL_HIT_RATIO,
        .flags2 = FLAG_SCENT_MARK_AFFECTED,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 140,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_GUILLOTINE] =
    {
        .effect = EFFECT_HIT,
        .power = 120,
        .type = TYPE_BUG,
        .accuracy = 70,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_HIGH_CRITICAL_HIT_RATIO,
        .flags2 = FLAG_SCENT_MARK_AFFECTED,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 190,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_RAZOR_WIND] =
    {
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_HIGH_CRITICAL_HIT_RATIO,
        .flags2 = FLAG_WIND_MOVE,
        .effect = EFFECT_USER_FIRST_TURN_PREPARE_SECOND_TURN_ATTACK,
        .power = 90,
        .type = TYPE_FLYING,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_BOTH,
        .priority = 0,
        .split = SPLIT_SPECIAL,
        .zMovePower = 175,
        .zMoveEffect = Z_EFFECT_NONE,
        .argument = STAT_SPEED,
    },

    [MOVE_SWORDS_DANCE] =
    {
        .pp = 20,
        .effect = EFFECT_USER_ATTACK_UP_2,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .flags = FLAG_SNATCH_AFFECTED | FLAG_DANCING_MOVE,
        .flags2 = FLAG_SLICING_MOVE,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_RESET_STATS,
    },

    [MOVE_CUT] =
    {
        .effect = EFFECT_HIT,
        .power = 50,
        .type = TYPE_NORMAL,
        .accuracy = 95,
        .pp = 20,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .flags2 = FLAG_SLICING_MOVE | FLAG_SCENT_MARK_AFFECTED | FLAG_ALWAYS_CRITICAL_HIT,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 100,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_GUST] =
    {
        .effect = EFFECT_GUST,
        .power = 60,
        .type = TYPE_FLYING,
        .accuracy = 100,
        .pp = 25,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_DOUBLE_DAMAGE_ON_FLYING_TARGET,
        .flags2 = FLAG_LIFT_ENTRY_HAZARDS | FLAG_WIND_MOVE,
        .split = SPLIT_SPECIAL,
        .zMovePower = 120,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_WING_ATTACK] =
    {
        .effect = EFFECT_HIT,
        .power = 60,
        .type = TYPE_FLYING,
        .accuracy = 100,
        .pp = 35,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .flags2 = FLAG_WING_MOVE| FLAG_SCENT_MARK_AFFECTED,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 120,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_WHIRLWIND] =
    {
        .accuracy = 0,
        .flags = FLAG_MAGIC_COAT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        .flags2 = FLAG_WIND_MOVE,
        .effect = EFFECT_TARGET_FORCED_SWITCH_OUT,
        .power = 0,
        .type = TYPE_NORMAL,
        .pp = 20,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = -6,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_SPDEF_UP_1,
    },

    [MOVE_FLY] =
    {
        .power = 90,
        .zMovePower = 175,
        .effect = EFFECT_SEMI_INVULNERABLE,
        .type = TYPE_FLYING,
        .accuracy = 95,
        .pp = 15,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_BIND] =
    {
        .accuracy = 90,
        .effect = EFFECT_TARGET_PREVENT_ESCAPE_AND_HURT_EACH_TURN,
        .power = 50,
        .type = TYPE_NORMAL,
        .pp = 10,
        .secondaryEffectChance = 100,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 100,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_SLAM] =
    {
        .effect = EFFECT_HIT,
        .power = 80,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 20,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .flags2 = FLAG_SCENT_MARK_AFFECTED,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 160,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_VINE_WHIP] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_6
            .power = 45,
            .pp = 25,
        #elif B_UPDATED_MOVE_DATA == GEN_4 || B_UPDATED_MOVE_DATA == GEN_5
            .power = 35,
            .pp = 15,
        #else
            .power = 35,
            .pp = 10,
        #endif
        .effect = EFFECT_HIT,
        .type = TYPE_GRASS,
        .accuracy = 100,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .flags2 = FLAG_SCENT_MARK_AFFECTED,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 100,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_STOMP] =
    {
        .effect = EFFECT_TARGET_FLINCH_ON_HIT,
        .power = 65,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 20,
        .secondaryEffectChance = 30,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_HAS_SECONDARY_EFFECT | FLAG_DOUBLE_DAMAGE_ON_MINIMIZED_TARGET,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 120,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_DOUBLE_KICK] =
    {
        .effect = EFFECT_TARGET_DOUBLE_HIT,
        .power = 30,
        .type = TYPE_FIGHTING,
        .accuracy = 100,
        .pp = 30,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_TWO_STRIKES,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 100,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_MEGA_KICK] =
    {
        .effect = EFFECT_TARGET_FLINCH_ON_HIT,
        .power = 120,
        .type = TYPE_NORMAL,
        .accuracy = 75,
        .pp = 5,
        .secondaryEffectChance = 30,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .flags2 = FLAG_AIRBOURNE_STYLE_BOOST | FLAG_SCENT_MARK_AFFECTED,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 190,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_JUMP_KICK] =
    {
        .power = 100,
        .pp = 10,
        .zMovePower = 180,
        .effect = EFFECT_USER_REDUCE_50_HP_IF_MISS,
        .type = TYPE_FIGHTING,
        .accuracy = 95,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_CRASH_DAMAGE_IF_MISS,
        .split = SPLIT_PHYSICAL,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_ROLLING_KICK] =
    {
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        .flags2 = FLAG_AIRBOURNE_STYLE_BOOST,
        .effect = EFFECT_SPEED_UP_1_AND_CLEAR_USER,
        .power = 50,
        .type = TYPE_FIGHTING,
        .accuracy = 100,
        .pp = 40,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 100,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_SAND_ATTACK] =
    {
        .effect = EFFECT_TARGET_ACCURACY_DOWN_1,
        .power = 0,
        .type = TYPE_GROUND,
        .accuracy = 100,
        .pp = 15,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MAGIC_COAT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_EVSN_UP_1,
    },

    [MOVE_HEADBUTT] =
    {
        .effect = EFFECT_TARGET_FLINCH_ON_HIT,
        .power = 70,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 15,
        .secondaryEffectChance = 30,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_HAS_SECONDARY_EFFECT,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 140,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_HORN_ATTACK] =
    {
        .effect = EFFECT_MATCH_USER_FIRST_TYPE,
        .power = 65,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 25,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .flags2 = FLAG_IGNORE_TARGET_DEFENSE_STAGES | FLAG_SCENT_MARK_AFFECTED,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 120,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_FURY_ATTACK] =
    {
        .effect = EFFECT_TARGET_MULTI_HIT,
        .power = 25,
        .type = TYPE_FLYING,
        .accuracy = 90,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 100,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_HORN_DRILL] =
    {
        .effect = EFFECT_MATCH_USER_FIRST_TYPE,
        .power = 120,
        .type = TYPE_NORMAL,
        .accuracy = 70,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_IGNORE_TARGET_ABILITIES,
        .flags2 = FLAG_IGNORE_TARGET_DEFENSE_STAGES | FLAG_SCENT_MARK_AFFECTED,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 190,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_TACKLE] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_7
            .power = 40,
            .accuracy = 100,
        #elif B_UPDATED_MOVE_DATA == GEN_5 || B_UPDATED_MOVE_DATA == GEN_6
            .power = 50,
            .accuracy = 100,
        #else
            .power = 35,
            .accuracy = 95,
        #endif
        .effect = EFFECT_HIT,
        .type = TYPE_NORMAL,
        .pp = 35,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .flags2 = FLAG_SCENT_MARK_AFFECTED,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 100,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_BODY_SLAM] =
    {
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_HAS_SECONDARY_EFFECT | FLAG_DOUBLE_DAMAGE_ON_MINIMIZED_TARGET,
        .effect = EFFECT_TARGET_PARALYZE_ON_HIT,
        .power = 85,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 15,
        .secondaryEffectChance = 30,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 160,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_WRAP] =
    {
        .accuracy = 90,
        .effect = EFFECT_TARGET_PREVENT_ESCAPE_AND_HURT_EACH_TURN,
        .power = 50,
        .type = TYPE_NORMAL,
        .pp = 10,
        .secondaryEffectChance = 100,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 100,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_TAKE_DOWN] =
    {
        .effect = EFFECT_USER_RECOIL_25,
        .power = 90,
        .type = TYPE_NORMAL,
        .accuracy = 85,
        .pp = 20,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_RECOIL_DAMAGE,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 175,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_THRASH] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_5
            .power = 120,
            .pp = 10,
            .zMovePower = 190,
        #else
            .power = 90,
            .pp = 20,
            .zMovePower = 175,
        #endif
        .effect = EFFECT_USER_RAMPAGE,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .secondaryEffectChance = 100,
        .target = MOVE_TARGET_RANDOM,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_DOUBLE_EDGE] =
    {
        .effect = EFFECT_USER_RECOIL_33,
        .power = 120,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 15,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_RECOIL_DAMAGE,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 190,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_TAIL_WHIP] =
    {
        .effect = EFFECT_TARGET_DEFENSE_DOWN_1,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 30,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_BOTH,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MAGIC_COAT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        .flags2 = FLAG_TAIL_MOVE,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_ATK_UP_1,
    },

    [MOVE_POISON_STING] =
    {
        .effect = EFFECT_TARGET_POISON_ON_HIT,
        .power = 15,
        .type = TYPE_POISON,
        .accuracy = 100,
        .pp = 35,
        .secondaryEffectChance = 30,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_HAS_SECONDARY_EFFECT,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 100,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_TWINEEDLE] =
    {
        .effect = EFFECT_TARGET_DOUBLE_HIT_AND_POISON_ON_HIT,
        .power = 50,
        .type = TYPE_BUG,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 20,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_HAS_SECONDARY_EFFECT | FLAG_TWO_STRIKES,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 100,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_PIN_MISSILE] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_6
            .power = 25,
            .accuracy = 95,
        #else
            .power = 14,
            .accuracy = 85,
        #endif
        .effect = EFFECT_TARGET_MULTI_HIT,
        .type = TYPE_BUG,
        .pp = 20,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 100,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_LEER] =
    {
        .effect = EFFECT_TARGET_DEFENSE_DOWN_1,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 30,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_BOTH,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MAGIC_COAT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_ATK_UP_1,
    },

    [MOVE_BITE] =
    {
        .effect = EFFECT_TARGET_FLINCH_ON_HIT,
        .power = 60,
        .type = TYPE_DARK,
        .accuracy = 100,
        .pp = 25,
        .secondaryEffectChance = 30,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_HAS_SECONDARY_EFFECT | FLAG_BITING_MOVE,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 120,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_GROWL] =
    {
        .effect = EFFECT_TARGET_ATTACK_DOWN_1,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 40,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_BOTH,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MAGIC_COAT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_SOUND_BASED_MOVE,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_DEF_UP_1,
    },

    [MOVE_ROAR] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_6
            .accuracy = 0,
            .flags = FLAG_MIRROR_MOVE_AFFECTED | FLAG_SOUND_BASED_MOVE | FLAG_MAGIC_COAT_AFFECTED,
        #elif B_UPDATED_MOVE_DATA == GEN_5
            .accuracy = 100,
            .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_SOUND_BASED_MOVE | FLAG_MAGIC_COAT_AFFECTED,
        #else
            .accuracy = 100,
            .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_SOUND_BASED_MOVE,
        #endif
        .effect = EFFECT_TARGET_FORCED_SWITCH_OUT,
        .power = 0,
        .type = TYPE_NORMAL,
        .pp = 20,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = -6,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_DEF_UP_1,
    },

    [MOVE_SING] =
    {
        .effect = EFFECT_TARGET_SLEEP,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 55,
        .pp = 15,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MAGIC_COAT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_SOUND_BASED_MOVE,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_SPD_UP_1,
    },

    [MOVE_SUPERSONIC] =
    {
        .effect = EFFECT_SUPERSONIC,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 95,
        .pp = 20,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MAGIC_COAT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_SOUND_BASED_MOVE,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_SPD_UP_1,
    },

    [MOVE_SONIC_BOOM] =
    {
        .effect = EFFECT_SCALE_WITH_BASE_SPEED,
        .power = 1,
        .type = TYPE_FLYING,
        .accuracy = 90,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .split = SPLIT_SPECIAL,
        .zMovePower = 100,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_DISABLE] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_5
            .accuracy = 100,
            .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_MAGIC_COAT_AFFECTED,
        #elif B_UPDATED_MOVE_DATA == GEN_4
            .accuracy = 80,
            .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        #else
            .accuracy = 55,
            .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        #endif
        .effect = EFFECT_TARGET_DISABLE_LAST_MOVE,
        .power = 0,
        .type = TYPE_NORMAL,
        .pp = 20,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_RESET_STATS,
    },

    [MOVE_ACID] =
    {
        .effect = EFFECT_TARGET_SPECIAL_DEFENSE_DOWN_1_ON_HIT,
        .power = 40,
        .type = TYPE_POISON,
        .accuracy = 100,
        .pp = 30,
        .secondaryEffectChance = 10,
        .target = MOVE_TARGET_BOTH,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_HAS_SECONDARY_EFFECT,
        .flags2 = FLAG_ACID_MOVE,
        .split = SPLIT_SPECIAL,
        .zMovePower = 100,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_EMBER] =
    {
        .effect = EFFECT_TARGET_BURN_ON_HIT,
        .power = 40,
        .type = TYPE_FIRE,
        .accuracy = 100,
        .pp = 25,
        .secondaryEffectChance = 10,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_HAS_SECONDARY_EFFECT,
        .split = SPLIT_SPECIAL,
        .zMovePower = 100,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_FLAMETHROWER] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_6
            .power = 90,
        #else
            .power = 95,
        #endif
        .effect = EFFECT_TARGET_BURN_ON_HIT,
        .type = TYPE_FIRE,
        .accuracy = 100,
        .pp = 15,
        .secondaryEffectChance = 10,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_HAS_SECONDARY_EFFECT,
        .split = SPLIT_SPECIAL,
        .zMovePower = 175,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_MIST] =
    {
        .effect = EFFECT_MIST,
        .power = 0,
        .type = TYPE_ICE,
        .accuracy = 0,
        .pp = 30,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .flags = FLAG_SNATCH_AFFECTED,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_RECOVER_HP,
    },

    [MOVE_WATER_GUN] =
    {
        .effect = EFFECT_HIT,
        .power = 40,
        .type = TYPE_WATER,
        .accuracy = 100,
        .pp = 25,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_AURA_BEAM_CANNON_GUN_PULSE_PUMP_SHOT_AND_ZOOKA_MOVE,
        .flags2 = FLAG_SLOTTED_SHELL_MOVE | FLAG_SCENT_MARK_AFFECTED,
        .split = SPLIT_SPECIAL,
        .zMovePower = 100,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_HYDRO_PUMP] =
    {
        .power = 110,
        .zMovePower = 185,
        .effect = EFFECT_HIT,
        .type = TYPE_WATER,
        .accuracy = 80,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_AURA_BEAM_CANNON_GUN_PULSE_PUMP_SHOT_AND_ZOOKA_MOVE,
        .flags2 = FLAG_SCENT_MARK_AFFECTED,
        .split = SPLIT_SPECIAL,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_SURF] =
    {
        .power = 90,
        .target = MOVE_TARGET_FOES_AND_ALLY,
        .effect = EFFECT_HIT,
        .type = TYPE_WATER,
        .accuracy = 100,
        .pp = 15,
        .secondaryEffectChance = 0,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_DAMAGE_ON_UNDERWATER_TARGET,
        .flags2 = FLAG_WAVE_SURF_AFFECTED,
        .split = SPLIT_SPECIAL,
        .zMovePower = 175,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_ICE_BEAM] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_6
            .power = 90,
        #else
            .power = 95,
        #endif
        .effect = EFFECT_TARGET_FROSTBITE_ON_HIT,
        .type = TYPE_ICE,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 20,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_HAS_SECONDARY_EFFECT | FLAG_AURA_BEAM_CANNON_GUN_PULSE_PUMP_SHOT_AND_ZOOKA_MOVE,
        .split = SPLIT_SPECIAL,
        .zMovePower = 175,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_BLIZZARD] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_6
            .power = 110,
            .zMovePower = 185,
        #else
            .power = 120,
            .zMovePower = 190,
        #endif
        .effect = EFFECT_TARGET_FROSTBITE_ON_HIT,
        .type = TYPE_ICE,
        .accuracy = 70,
        .pp = 5,
        .secondaryEffectChance = 30,
        .target = MOVE_TARGET_BOTH,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_HAS_SECONDARY_EFFECT,
        .flags2 = FLAG_WEATHER_RELATED_MOVE | FLAG_WIND_MOVE,
        .split = SPLIT_SPECIAL,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_PSYBEAM] =
    {
        .effect = EFFECT_TARGET_CONFUSE_ON_HIT,
        .power = 75,
        .type = TYPE_PSYCHIC,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 30,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_HAS_SECONDARY_EFFECT | FLAG_AURA_BEAM_CANNON_GUN_PULSE_PUMP_SHOT_AND_ZOOKA_MOVE,
        .split = SPLIT_SPECIAL,
        .zMovePower = 140,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_BUBBLE_BEAM] =
    {
        .effect = EFFECT_TARGET_SPEED_DOWN_1_ON_HIT,
        .power = 75,
        .type = TYPE_WATER,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 100,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_HAS_SECONDARY_EFFECT | FLAG_AURA_BEAM_CANNON_GUN_PULSE_PUMP_SHOT_AND_ZOOKA_MOVE,
        .split = SPLIT_SPECIAL,
        .zMovePower = 140,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_AURORA_BEAM] =
    {
        .effect = EFFECT_TARGET_ATTACK_DOWN_1_ON_HIT,
        .power = 75,
        .type = TYPE_ICE,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 100,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_HAS_SECONDARY_EFFECT | FLAG_AURA_BEAM_CANNON_GUN_PULSE_PUMP_SHOT_AND_ZOOKA_MOVE,
        .flags2 = FLAG_COSMIC_ENERGYZED_MOVE,
        .split = SPLIT_SPECIAL,
        .zMovePower = 140,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_HYPER_BEAM] =
    {
        .effect = EFFECT_USER_RECHARGE,
        .power = 150,
        .type = TYPE_NORMAL,
        .accuracy = 90,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_AURA_BEAM_CANNON_GUN_PULSE_PUMP_SHOT_AND_ZOOKA_MOVE,
        .split = SPLIT_SPECIAL,
        .zMovePower = 200,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_PECK] =
    {
        .effect = EFFECT_HIT,
        .power = 35,
        .type = TYPE_FLYING,
        .accuracy = 100,
        .pp = 35,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .flags2 = FLAG_SCENT_MARK_AFFECTED,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 100,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_DRILL_PECK] =
    {
        .effect = EFFECT_HIT,
        .power = 80,
        .type = TYPE_FLYING,
        .accuracy = 100,
        .pp = 15,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_HIGH_CRITICAL_HIT_RATIO,
        .flags2 = FLAG_SCENT_MARK_AFFECTED,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 160,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_SUBMISSION] =
    {
        .pp = 5,
        .effect = EFFECT_USER_RECOIL_50,
        .power = 150,
        .type = TYPE_FIGHTING,
        .accuracy = 80,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_RECOIL_DAMAGE,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 200,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_LOW_KICK] =
    {
        .effect = EFFECT_LOW_KICK,
        .power = 1,
        .type = TYPE_FIGHTING,
        .accuracy = 100,
        .pp = 20,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .flags2 = FLAG_AIRBOURNE_STYLE_BOOST | FLAG_SCENT_MARK_AFFECTED,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 100,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_COUNTER] =
    {
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED,
        .effect = EFFECT_USER_REFLECT_PHYSICAL_DAMAGE,
        .power = 1,
        .type = TYPE_FIGHTING,
        .accuracy = 100,
        .pp = 20,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_DEPENDS,
        .priority = -5,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 100,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_SEISMIC_TOSS] =
    {
        .effect = EFFECT_TARGET_DAMAGE_SCALE_WITH_BASE_ATK,
        .power = 1,
        .type = TYPE_FIGHTING,
        .accuracy = 90,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 100,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_STRENGTH] =
    {
        .effect = EFFECT_HIT,
        .power = 80,
        .type = TYPE_FIGHTING,
        .accuracy = 100,
        .pp = 15,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .flags2 = FLAG_SCENT_MARK_AFFECTED,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 160,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_ABSORB] =
    {
        .pp = 25,
        .effect = EFFECT_USER_DRAIN_50_ON_HIT,
        .power = 20,
        .type = TYPE_GRASS,
        .accuracy = 100,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        .split = SPLIT_SPECIAL,
        .zMovePower = 100,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_MEGA_DRAIN] =
    {
        .pp = 15,
        .effect = EFFECT_USER_DRAIN_50_ON_HIT,
        .power = 40,
        .type = TYPE_GRASS,
        .accuracy = 100,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        .split = SPLIT_SPECIAL,
        .zMovePower = 120,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_LEECH_SEED] =
    {
        .effect = EFFECT_TARGET_DRAIN_HP_EACH_TURN,
        .power = 0,
        .type = TYPE_GRASS,
        .accuracy = 90,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MAGIC_COAT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_RESET_STATS,
    },

    [MOVE_GROWTH] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_6
            .pp = 20,
        #else
            .pp = 40,
        #endif
        .effect = EFFECT_GROWTH,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .flags = FLAG_SNATCH_AFFECTED,
        .flags2 = FLAG_WEATHER_RELATED_MOVE,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_SPATK_UP_1,
    },

    [MOVE_RAZOR_LEAF] =
    {
        .effect = EFFECT_HIT,
        .power = 55,
        .type = TYPE_GRASS,
        .accuracy = 95,
        .pp = 25,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_BOTH,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_HIGH_CRITICAL_HIT_RATIO,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 100,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_SOLAR_BEAM] =
    {
        .effect = EFFECT_USER_FIRST_TURN_PREPARE_SECOND_TURN_ATTACK,
        .power = 120,
        .type = TYPE_GRASS,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_AURA_BEAM_CANNON_GUN_PULSE_PUMP_SHOT_AND_ZOOKA_MOVE,
        .flags2 = FLAG_WEATHER_RELATED_MOVE | FLAG_COSMIC_ENERGYZED_MOVE,
        .split = SPLIT_SPECIAL,
        .zMovePower = 190,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_POISON_POWDER] =
    {
        .effect = EFFECT_TARGET_POISON,
        .power = 0,
        .type = TYPE_POISON,
        .accuracy = 75,
        .pp = 35,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MAGIC_COAT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_POWDER_AND_SPORE_MOVE,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_DEF_UP_1,
    },

    [MOVE_STUN_SPORE] =
    {
        .effect = EFFECT_TARGET_PARALYZE,
        .power = 0,
        .type = TYPE_GRASS,
        .accuracy = 75,
        .pp = 30,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MAGIC_COAT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_POWDER_AND_SPORE_MOVE,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_SPDEF_UP_1,
    },

    [MOVE_SLEEP_POWDER] =
    {
        .effect = EFFECT_TARGET_SLEEP,
        .power = 0,
        .type = TYPE_GRASS,
        .accuracy = 75,
        .pp = 15,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MAGIC_COAT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_POWDER_AND_SPORE_MOVE,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_SPD_UP_1,
    },

    [MOVE_PETAL_DANCE] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_5
            .power = 120,
            .pp = 10,
            .zMovePower = 190,
        #elif B_UPDATED_MOVE_DATA == GEN_4
            .power = 90,
            .pp = 20,
            .zMovePower = 175,
        #else
            .power = 70,
            .pp = 20,
            .zMovePower = 140,
        #endif
        .effect = EFFECT_USER_RAMPAGE,
        .type = TYPE_GRASS,
        .accuracy = 100,
        .secondaryEffectChance = 100,
        .target = MOVE_TARGET_RANDOM,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_DANCING_MOVE,
        .split = SPLIT_SPECIAL,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_STRING_SHOT] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_6
            .effect = EFFECT_TARGET_SPEED_DOWN_2,
        #else
            .effect = EFFECT_TARGET_SPEED_DOWN_1,
        #endif
        .power = 0,
        .type = TYPE_BUG,
        .accuracy = 95,
        .pp = 40,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_BOTH,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MAGIC_COAT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_AURA_BEAM_CANNON_GUN_PULSE_PUMP_SHOT_AND_ZOOKA_MOVE,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_SPD_UP_1,
    },

    [MOVE_DRAGON_RAGE] =
    {
        .effect = EFFECT_TARGET_DAMAGE_SCALE_WITH_BASE_ATK_SPATK,
        .power = 1,
        .type = TYPE_DRAGON,
        .accuracy = 90,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .flags2 = FLAG_EMOTION_MOVE,
        .split = SPLIT_SPECIAL,
        .zMovePower = 100,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_FIRE_SPIN] =
    {
        .power = 80,
        .accuracy = 85,
        .effect = EFFECT_TARGET_PREVENT_ESCAPE_AND_HURT_EACH_TURN,
        .type = TYPE_FIRE,
        .pp = 10,
        .secondaryEffectChance = 100,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .split = SPLIT_SPECIAL,
        .zMovePower = 100,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_THUNDER_SHOCK] =
    {
        .effect = EFFECT_TARGET_PARALYZE_ON_HIT,
        .power = 40,
        .type = TYPE_ELECTRIC,
        .accuracy = 100,
        .pp = 30,
        .secondaryEffectChance = 10,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_HAS_SECONDARY_EFFECT,
        .split = SPLIT_SPECIAL,
        .zMovePower = 100,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_THUNDERBOLT] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_6
            .power = 90,
        #else
            .power = 95,
        #endif
        .effect = EFFECT_TARGET_PARALYZE_ON_HIT,
        .type = TYPE_ELECTRIC,
        .accuracy = 100,
        .pp = 15,
        .secondaryEffectChance = 10,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_HAS_SECONDARY_EFFECT,
        .split = SPLIT_SPECIAL,
        .zMovePower = 175,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_THUNDER_WAVE] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_7
            .accuracy = 90,
        #else
            .accuracy = 100,
        #endif
        .effect = EFFECT_TARGET_PARALYZE,
        .power = 0,
        .type = TYPE_ELECTRIC,
        .pp = 20,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MAGIC_COAT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_SPDEF_UP_1,
    },

    [MOVE_THUNDER] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_6
            .power = 110,
            .zMovePower = 185,
        #else
            .power = 120,
            .zMovePower = 190,
        #endif
        .effect = EFFECT_THUNDER,
        .type = TYPE_ELECTRIC,
        .accuracy = 70,
        .pp = 10,
        .secondaryEffectChance = 30,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_HAS_SECONDARY_EFFECT | FLAG_DAMAGE_ON_FLYING_TARGET,
        .flags2 = FLAG_WEATHER_RELATED_MOVE,
        .split = SPLIT_SPECIAL,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_ROCK_THROW] =
    {
        .effect = EFFECT_HIT,
        .power = 50,
        .type = TYPE_ROCK,
        .accuracy = 90,
        .pp = 15,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .flags2 = FLAG_SCENT_MARK_AFFECTED,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 100,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_EARTHQUAKE] =
    {
        .effect = EFFECT_EARTHQUAKE,
        .power = 100,
        .type = TYPE_GROUND,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_FOES_AND_ALLY,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_DAMAGE_ON_UNDERGROUND_TARGET,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 180,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_FISSURE] =
    {
        .effect = EFFECT_KNOCK_OFF,
        .power = 120,
        .type = TYPE_GROUND,
        .accuracy = 70,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_DAMAGE_ON_UNDERGROUND_TARGET,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 180,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_DIG] =
    {
        .power = 80,
        .zMovePower = 160,
        .effect = EFFECT_SEMI_INVULNERABLE,
        .type = TYPE_GROUND,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_TOXIC] =
    {
        .accuracy = 90,
        .effect = EFFECT_TARGET_BADLY_POISON,
        .power = 0,
        .type = TYPE_POISON,
        .pp = 10,
        .secondaryEffectChance = 100,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MAGIC_COAT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_DEF_UP_1,
    },

    [MOVE_CONFUSION] =
    {
        .effect = EFFECT_CONFUSION,
        .power = 50,
        .type = TYPE_PSYCHIC,
        .accuracy = 100,
        .pp = 25,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_HAS_SECONDARY_EFFECT,
        .flags2 = FLAG_EMOTION_MOVE,
        .split = SPLIT_SPECIAL,
        .zMovePower = 100,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_PSYCHIC] =
    {
        .effect = EFFECT_TARGET_SPECIAL_DEFENSE_DOWN_1_ON_HIT,
        .power = 90,
        .type = TYPE_PSYCHIC,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 10,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_HAS_SECONDARY_EFFECT,
        .split = SPLIT_SPECIAL,
        .zMovePower = 175,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_HYPNOSIS] =
    {
        .effect = EFFECT_TARGET_SLEEP,
        .power = 0,
        .type = TYPE_PSYCHIC,
        .accuracy = 60,
        .pp = 20,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MAGIC_COAT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_SPD_UP_1,
    },

    [MOVE_MEDITATE] =
    {
        .effect = EFFECT_MEDITATE,
        .power = 0,
        .type = TYPE_PSYCHIC,
        .accuracy = 0,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .flags = FLAG_SNATCH_AFFECTED,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_ATK_UP_1,
    },

    [MOVE_AGILITY] =
    {
        .effect = EFFECT_USER_SPEED_UP_2,
        .power = 0,
        .type = TYPE_PSYCHIC,
        .accuracy = 0,
        .pp = 30,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .flags = FLAG_SNATCH_AFFECTED,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_RESET_STATS,
    },

    [MOVE_QUICK_ATTACK] =
    {
        .effect = EFFECT_HIT,
        .power = 40,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 30,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 1,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .flags2 = FLAG_SCENT_MARK_AFFECTED,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 100,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_RAGE] =
    {
        .effect = EFFECT_USER_ATTACK_UP_1_ON_BEING_HIT,
        .power = 20,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 20,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .flags2 = FLAG_EMOTION_MOVE,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 100,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_TELEPORT] =
    {
        .effect = EFFECT_TELEPORT,
        .power = 0,
        .type = TYPE_PSYCHIC,
        .accuracy = 0,
        .pp = 20,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_USER,
        .priority = -6,
        .flags = 0,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_RECOVER_HP,
    },

    [MOVE_NIGHT_SHADE] =
    {
        .effect = EFFECT_TARGET_DAMAGE_SCALE_WITH_BASE_SPATK,
        .power = 1,
        .type = TYPE_GHOST,
        .accuracy = 90,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .split = SPLIT_SPECIAL,
        .zMovePower = 100,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_MIMIC] =
    {
        .effect = EFFECT_USER_COPY_LAST_MOVE,
        .power = 1,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_ACC_UP_1,
    },

    [MOVE_SCREECH] =
    {
        .effect = EFFECT_TARGET_DEFENSE_DOWN_2,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 85,
        .pp = 40,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MAGIC_COAT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_SOUND_BASED_MOVE,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_ATK_UP_1,
    },

    [MOVE_DOUBLE_TEAM] =
    {
        .effect = EFFECT_USER_EVASION_UP_1,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 15,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .flags = FLAG_SNATCH_AFFECTED,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_RESET_STATS,
    },

    [MOVE_RECOVER] =
    {
        .pp = 5,
        .effect = EFFECT_USER_RESTORE_50_HP,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .flags = FLAG_SNATCH_AFFECTED,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_RESET_STATS,
    },

    [MOVE_HARDEN] =
    {
        .effect = EFFECT_USER_DEFENSE_UP_1,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 30,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .flags = FLAG_SNATCH_AFFECTED,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_DEF_UP_1,
    },

    [MOVE_MINIMIZE] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_6
            .pp = 10,
        #else
            .pp = 20,
        #endif
        .effect = EFFECT_USER_EVASION_UP_2_AND_REDUCE_SIZE,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .flags = FLAG_SNATCH_AFFECTED,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_RESET_STATS,
    },

    [MOVE_SMOKESCREEN] =
    {
        .effect = EFFECT_TARGET_ACCURACY_DOWN_1,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 20,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MAGIC_COAT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_EVSN_UP_1,
    },

    [MOVE_CONFUSE_RAY] =
    {
        .effect = EFFECT_TARGET_CONFUSE,
        .power = 0,
        .type = TYPE_GHOST,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MAGIC_COAT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_SPATK_UP_1,
    },

    [MOVE_WITHDRAW] =
    {
        .effect = EFFECT_WITHDRAW,
        .power = 0,
        .type = TYPE_WATER,
        .accuracy = 0,
        .pp = 15,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .flags = FLAG_SNATCH_AFFECTED,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_DEF_UP_1,
    },

    [MOVE_DEFENSE_CURL] =
    {
        .effect = EFFECT_DEFENSE_CURL,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 40,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .flags = FLAG_SNATCH_AFFECTED,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_ACC_UP_1,
    },

    [MOVE_BARRIER] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_6
            .pp = 20,
        #else
            .pp = 30,
        #endif
        .effect = EFFECT_USER_DEFENSE_UP_2,
        .power = 0,
        .type = TYPE_PSYCHIC,
        .accuracy = 0,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .flags = FLAG_SNATCH_AFFECTED,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_RESET_STATS,
    },

    [MOVE_LIGHT_SCREEN] =
    {
        .effect = EFFECT_USER_SIDE_SPECIAL_DAMAGE_WALL,
        .power = 0,
        .type = TYPE_PSYCHIC,
        .accuracy = 0,
        .pp = 30,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .flags = FLAG_SNATCH_AFFECTED,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_SPDEF_UP_1,
    },

    [MOVE_HAZE] =
    {
        .effect = EFFECT_ALL_RESET_STAT_STAGES,
        .power = 0,
        .type = TYPE_ICE,
        .accuracy = 0,
        .pp = 30,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_ALL_BATTLERS,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_RECOVER_HP,
    },

    [MOVE_REFLECT] =
    {
        .effect = EFFECT_USER_SIDE_PHYSICAL_DAMAGE_WALL,
        .power = 0,
        .type = TYPE_PSYCHIC,
        .accuracy = 0,
        .pp = 20,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .flags = FLAG_SNATCH_AFFECTED,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_DEF_UP_1,
    },

    [MOVE_FOCUS_ENERGY] =
    {
        .effect = EFFECT_USER_CRITICAL_HIT_STAGE_2,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 30,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .flags = FLAG_SNATCH_AFFECTED,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_ACC_UP_1,
    },

    [MOVE_BIDE] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_4
            .accuracy = 0,
            .priority = 1,
        #else
            .accuracy = 100,
            .priority = 0,
        #endif
        .effect = EFFECT_USER_REFLECT_DAMAGE_2_TURNS,
        .power = 1,
        .type = TYPE_NORMAL,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_USER,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 100,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_METRONOME] =
    {
        .effect = EFFECT_USER_CALL_RANDOM_MOVE,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_DEPENDS,
        .priority = 0,
        .flags = 0,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_MIRROR_MOVE] =
    {
        .effect = EFFECT_USER_REPEAT_LAST_MOVE,
        .power = 1,
        .type = TYPE_FLYING,
        .accuracy = 0,
        .pp = 20,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_DEPENDS,
        .priority = 0,
        .flags = 0,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_ATK_UP_2,
    },

    [MOVE_SELF_DESTRUCT] =
    {
        .effect = EFFECT_USER_FAINT,
        .power = 200,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_FOES_AND_ALLY,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 200,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_EGG_BOMB] =
    {
        .effect = EFFECT_TARGET_BURN_ON_HIT,
        .power = 100,
        .type = TYPE_FIRE,
        .accuracy = 85,
        .pp = 10,
        .secondaryEffectChance = 30,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_BALL_AND_BOMB_MOVE,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 180,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_LICK] =
    {
        .power = 70,
        .effect = EFFECT_TARGET_PARALYZE_ON_HIT,
        .type = TYPE_GHOST,
        .accuracy = 100,
        .pp = 20,
        .secondaryEffectChance = 30,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_HAS_SECONDARY_EFFECT,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 140,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_SMOG] =
    {
        .power = 50,
        .effect = EFFECT_TARGET_BADLY_POISON_ON_HIT,
        .type = TYPE_POISON,
        .accuracy = 0,
        .pp = 15,
        .secondaryEffectChance = 50,
        .target = MOVE_TARGET_BOTH,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_HAS_SECONDARY_EFFECT,
        .split = SPLIT_SPECIAL,
        .zMovePower = 100,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_SLUDGE] =
    {
        .effect = EFFECT_TARGET_POISON_ON_HIT,
        .power = 65,
        .type = TYPE_POISON,
        .accuracy = 100,
        .pp = 20,
        .secondaryEffectChance = 30,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_HAS_SECONDARY_EFFECT,
        .split = SPLIT_SPECIAL,
        .zMovePower = 120,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_BONE_CLUB] =
    {
        .effect = EFFECT_TARGET_FLINCH_ON_HIT,
        .power = 80,
        .type = TYPE_GROUND,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 10,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_HAS_SECONDARY_EFFECT | FLAG_DAMAGE_ON_UNGROUNDED_TARGET,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 160,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_FIRE_BLAST] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_6
            .power = 110,
            .zMovePower = 185,
        #else
            .power = 120,
            .zMovePower = 190,
        #endif
        .effect = EFFECT_TARGET_BURN_ON_HIT,
        .type = TYPE_FIRE,
        .accuracy = 85,
        .pp = 5,
        .secondaryEffectChance = 10,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_HAS_SECONDARY_EFFECT,
        .split = SPLIT_SPECIAL,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_WATERFALL] =
    {
        .effect = EFFECT_TARGET_FLINCH_ON_HIT,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_HAS_SECONDARY_EFFECT,
        .flags2 = FLAG_SCENT_MARK_AFFECTED,
        .power = 80,
        .type = TYPE_WATER,
        .accuracy = 100,
        .pp = 15,
        .secondaryEffectChance = 20,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 160,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_CLAMP] =
    {
        .accuracy = 85,
        .pp = 10,
        .effect = EFFECT_TARGET_PREVENT_ESCAPE_AND_HURT_EACH_TURN,
        .power = 80,
        .type = TYPE_WATER,
        .secondaryEffectChance = 100,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 100,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_SWIFT] =
    {
        .effect = EFFECT_HIT,
        .power = 60,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 20,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_BOTH,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .split = SPLIT_SPECIAL,
        .zMovePower = 120,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_SKULL_BASH] =
    {
        .power = 130,
        .pp = 10,
        .zMovePower = 195,
        .effect = EFFECT_USER_FIRST_TURN_PREPARE_SECOND_TURN_ATTACK,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .argument = STAT_DEF,
        .split = SPLIT_PHYSICAL,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_SPIKE_CANNON] =
    {
        .effect = EFFECT_TARGET_MULTI_HIT,
        .power = 25,
        .type = TYPE_WATER,
        .accuracy = 85,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_AURA_BEAM_CANNON_GUN_PULSE_PUMP_SHOT_AND_ZOOKA_MOVE,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 100,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_CONSTRICT] =
    {
        .effect = EFFECT_TARGET_SPEED_DOWN_1_ON_HIT,
        .power = 55,
        .type = TYPE_NORMAL,
        .accuracy = 95,
        .pp = 15,
        .secondaryEffectChance = 100,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_HAS_SECONDARY_EFFECT,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 100,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_AMNESIA] =
    {
        .effect = EFFECT_USER_SPECIAL_DEFENSE_UP_2,
        .power = 0,
        .type = TYPE_PSYCHIC,
        .accuracy = 0,
        .pp = 20,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .flags = FLAG_SNATCH_AFFECTED,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_RESET_STATS,
    },

    [MOVE_KINESIS] =
    {
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_MAGIC_COAT_AFFECTED,
        .effect = EFFECT_KINESIS,
        .power = 0,
        .type = TYPE_PSYCHIC,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_EVSN_UP_1,
    },

    [MOVE_SOFT_BOILED] =
    {
        .effect = EFFECT_SOFTBOILED,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .flags = FLAG_SNATCH_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_RESET_STATS,
    },

    [MOVE_HIGH_JUMP_KICK] =
    {
        .power = 130,
        .pp = 10,
        .zMovePower = 195,
        .effect = EFFECT_USER_REDUCE_50_HP_IF_MISS,
        .type = TYPE_FIGHTING,
        .accuracy = 90,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_CRASH_DAMAGE_IF_MISS,
        .split = SPLIT_PHYSICAL,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_GLARE] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_6
            .accuracy = 100,
        #elif B_UPDATED_MOVE_DATA == GEN_5
            .accuracy = 90,
        #else
            .accuracy = 75,
        #endif
        .effect = EFFECT_TARGET_PARALYZE,
        .power = 0,
        .type = TYPE_NORMAL,
        .pp = 30,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MAGIC_COAT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_SPDEF_UP_1,
    },

    [MOVE_DREAM_EATER] =
    {
        .effect = EFFECT_DREAM_EATER,
        .power = 60,
        .type = TYPE_PSYCHIC,
        .accuracy = 100,
        .pp = 15,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        .split = SPLIT_SPECIAL,
        .zMovePower = 120,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_POISON_GAS] =
    {
        .accuracy = 0,
        .target = MOVE_TARGET_BOTH,
        .effect = EFFECT_TARGET_BADLY_POISON,
        .power = 0,
        .type = TYPE_POISON,
        .pp = 10,
        .secondaryEffectChance = 0,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MAGIC_COAT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_DEF_UP_1,
    },

    [MOVE_BARRAGE] =
    {
        .effect = EFFECT_TARGET_MULTI_HIT,
        .power = 25,
        .type = TYPE_GROUND,
        .accuracy = 100,
        .pp = 30,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_BALL_AND_BOMB_MOVE | FLAG_DAMAGE_ON_UNGROUNDED_TARGET,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 100,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_LEECH_LIFE] =
    {
        .power = 80,
        .pp = 10,
        .zMovePower = 160,
        .effect = EFFECT_USER_DRAIN_50_ON_HIT,
        .type = TYPE_BUG,
        .accuracy = 100,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        .split = SPLIT_PHYSICAL,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_LOVELY_KISS] =
    {
        .effect = EFFECT_TARGET_SLEEP,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 85,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MAGIC_COAT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        .flags2 = FLAG_EMOTION_MOVE | FLAG_KISSING_MOVE,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_SPD_UP_1,
    },

    [MOVE_SKY_ATTACK] =
    {
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_HAS_SECONDARY_EFFECT | FLAG_HIGH_CRITICAL_HIT_RATIO,
        .effect = EFFECT_USER_FIRST_TURN_PREPARE_SECOND_TURN_ATTACK,
        .power = 140,
        .type = TYPE_FLYING,
        .accuracy = 90,
        .pp = 5,
        .secondaryEffectChance = 30,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .split = SPLIT_PHYSICAL,
        .argument2 = MOVE_EFFECT_FLINCH,
        .zMovePower = 200,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_TRANSFORM] =
    {
        .effect = EFFECT_USER_TRANSFORM,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = 0,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_RECOVER_HP,
    },

    [MOVE_BUBBLE] =
    {
        .power = 40,
        .effect = EFFECT_TARGET_SPEED_DOWN_1_ON_HIT,
        .type = TYPE_WATER,
        .accuracy = 100,
        .pp = 30,
        .secondaryEffectChance = 10,
        .target = MOVE_TARGET_BOTH,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_HAS_SECONDARY_EFFECT,
        .split = SPLIT_SPECIAL,
        .zMovePower = 100,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_DIZZY_PUNCH] =
    {
        .effect = EFFECT_TARGET_CONFUSE_ON_HIT,
        .power = 80,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 20,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_PUNCHING_MOVE | FLAG_HAS_SECONDARY_EFFECT,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 160,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_SPORE] =
    {
        .effect = EFFECT_TARGET_SLEEP,
        .power = 0,
        .type = TYPE_GRASS,
        .accuracy = 100,
        .pp = 15,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MAGIC_COAT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_POWDER_AND_SPORE_MOVE,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_RESET_STATS,
    },

    [MOVE_FLASH] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_4
            .accuracy = 100,
        #else
            .accuracy = 70,
        #endif
        .effect = EFFECT_TARGET_ACCURACY_DOWN_1,
        .power = 0,
        .type = TYPE_NORMAL,
        .pp = 10,
        .secondaryEffectChance = 100,
        .target = MOVE_TARGET_FOES_AND_ALLY,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_HAS_SECONDARY_EFFECT,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_EVSN_UP_1,
    },

    [MOVE_PSYWAVE] =
    {
        .accuracy = 90,
        .effect = EFFECT_TARGET_DAMAGE_SCALE_WITH_BASE_SPATK,
        .power = 1,
        .type = TYPE_PSYCHIC,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .split = SPLIT_SPECIAL,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_SPLASH] =
    {
        .effect = EFFECT_USER_DO_NOTHING,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 40,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .flags = 0,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_ATK_UP_3,
    },

    [MOVE_ACID_ARMOR] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_6
            .pp = 20,
        #else
            .pp = 40,
        #endif
        .effect = EFFECT_USER_DEFENSE_UP_2,
        .power = 0,
        .type = TYPE_POISON,
        .accuracy = 0,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .flags = FLAG_SNATCH_AFFECTED,
        .flags2 = FLAG_ACID_MOVE,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_RESET_STATS,
    },

    [MOVE_CRABHAMMER] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_6
            .power = 100,
            .accuracy = 90,
            .zMovePower = 180,
        #elif B_UPDATED_MOVE_DATA == GEN_5
            .power = 90,
            .accuracy = 90,
            .zMovePower = 175,
        #else
            .power = 90,
            .accuracy = 85,
            .zMovePower = 175,
        #endif
        .effect = EFFECT_HIT,
        .type = TYPE_WATER,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_HIGH_CRITICAL_HIT_RATIO,
        .flags2 = FLAG_SCENT_MARK_AFFECTED,
        .split = SPLIT_PHYSICAL,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_EXPLOSION] =
    {
        .effect = EFFECT_USER_FAINT,
        .power = 250,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_FOES_AND_ALLY,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 200,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_FURY_SWIPES] =
    {
        .effect = EFFECT_TARGET_MULTI_HIT,
        .power = 15,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 15,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_HIGH_CRITICAL_HIT_RATIO,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 100,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_BONEMERANG] =
    {
        .effect = EFFECT_TARGET_DOUBLE_HIT,
        .power = 50,
        .type = TYPE_GROUND,
        .accuracy = 90,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_DAMAGE_ON_UNGROUNDED_TARGET | FLAG_TWO_STRIKES,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 100,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_REST] =
    {
        .effect = EFFECT_USER_RESTORE_FULL_HP_AND_SLEEP,
        .power = 0,
        .type = TYPE_PSYCHIC,
        .accuracy = 0,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .flags = FLAG_SNATCH_AFFECTED,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_RESET_STATS,
    },

    [MOVE_ROCK_SLIDE] =
    {
        .effect = EFFECT_TARGET_FLINCH_ON_HIT,
        .power = 75,
        .type = TYPE_ROCK,
        .accuracy = 90,
        .pp = 10,
        .secondaryEffectChance = 30,
        .target = MOVE_TARGET_BOTH,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_HAS_SECONDARY_EFFECT,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 140,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_HYPER_FANG] =
    {
        .effect = EFFECT_TARGET_FLINCH_ON_HIT,
        .power = 80,
        .type = TYPE_NORMAL,
        .accuracy = 95,
        .pp = 15,
        .secondaryEffectChance = 30,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_BITING_MOVE | FLAG_HAS_SECONDARY_EFFECT,
        .flags2 = FLAG_FANG_MOVE,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 160,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_SHARPEN] =
    {
        .effect = EFFECT_USER_ATTACK_UP_1,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 30,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .flags = FLAG_SNATCH_AFFECTED,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_ATK_UP_1,
    },

    [MOVE_CONVERSION] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_5
            .flags = FLAG_SNATCH_AFFECTED,
        #else
            .flags = 0,
        #endif
        .effect = EFFECT_USER_CHANGE_TYPE_TO_FIRST_MOVE,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 30,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_ALL_STATS_UP_1,
    },

    [MOVE_TRI_ATTACK] =
    {
        .effect = EFFECT_TARGET_FIRE_ELECTRIC_ICE_HIT,
        .power = 30,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 10,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_HAS_SECONDARY_EFFECT,
        .split = SPLIT_SPECIAL,
        .zMovePower = 100,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_SUPER_FANG] =
    {
        .effect = EFFECT_TARGET_REDUCE_50_HP,
        .power = 1,
        .type = TYPE_NORMAL,
        .accuracy = 90,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_BITING_MOVE,
        .flags2 = FLAG_FANG_MOVE,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 100,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_SLASH] =
    {
        .effect = EFFECT_HIT,
        .power = 70,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 20,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_HIGH_CRITICAL_HIT_RATIO,
        .flags2 = FLAG_SLICING_MOVE | FLAG_SCENT_MARK_AFFECTED,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 140,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_SUBSTITUTE] =
    {
        .effect = EFFECT_USER_REDUCE_25_HP_AND_SUBSTITUTE,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .flags = FLAG_SNATCH_AFFECTED,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_RESET_STATS,
    },

    [MOVE_STRUGGLE] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_4
            .accuracy = 0,
            .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
            .effect = EFFECT_USER_RECOIL_25_HP,
        #else
            .accuracy = 100,
            .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
            .effect = EFFECT_USER_RECOIL_25,
        #endif
        .power = 50,
        .type = TYPE_NORMAL,
        .pp = 1,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 100,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_SKETCH] =
    {
        .effect = EFFECT_USER_PERMANENTLY_COPY_LAST_MOVE,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 1,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = 0,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_ALL_STATS_UP_1,
    },

    [MOVE_TRIPLE_KICK] =
    {
        .effect = EFFECT_TARGET_TRIPLE_HIT_MORE_DAMAGE_EACH_HIT,
        .power = 10,
        .type = TYPE_FIGHTING,
        .accuracy = 90,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 100,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_THIEF] =
    {
        .power = 60,
        .pp = 25,
        .zMovePower = 120,
        .effect = EFFECT_USER_STEAL_TARGET_ITEM_ON_HIT,
        .type = TYPE_DARK,
        .accuracy = 100,
        .secondaryEffectChance = 100,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        .split = SPLIT_PHYSICAL,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_SPIDER_WEB] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_6
            .flags = FLAG_MAGIC_COAT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        #else
            .flags = FLAG_PROTECT_AFFECTED | FLAG_MAGIC_COAT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        #endif
        .effect = EFFECT_TARGET_PREVENT_ESCAPE,
        .power = 0,
        .type = TYPE_BUG,
        .accuracy = 0,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_DEF_UP_1,
    },

    [MOVE_MIND_READER] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_4
            .accuracy = 0,
        #else
            .accuracy = 100,
        #endif
        .effect = EFFECT_USER_BOOST_NEXT_MOVE_ON_TARGET,
        .power = 0,
        .type = TYPE_NORMAL,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_SPATK_UP_1,
    },

    [MOVE_NIGHTMARE] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_4
            .accuracy = 100,
        #else
            .accuracy = 0,
        #endif
        .effect = EFFECT_TARGET_REDUCE_25_HP_EACH_TURN_ASLEEP,
        .power = 0,
        .type = TYPE_GHOST,
        .pp = 15,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_SPATK_UP_1,
    },

    [MOVE_FLAME_WHEEL] =
    {
        .effect = EFFECT_TARGET_BURN_ON_HIT,
        .power = 60,
        .type = TYPE_FIRE,
        .accuracy = 100,
        .pp = 25,
        .secondaryEffectChance = 10,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_HAS_SECONDARY_EFFECT | FLAG_THAW_USER,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 120,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_SNORE] =
    {
        .power = 50,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_HAS_SECONDARY_EFFECT | FLAG_SOUND_BASED_MOVE,
        .effect = EFFECT_CAN_BE_USED_ASLEEP_AND_TARGET_FLINCH_ON_HIT,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 15,
        .secondaryEffectChance = 30,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .split = SPLIT_SPECIAL,
        .zMovePower = 100,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_CURSE] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_5
            .type = TYPE_GHOST,
        #else
            .type = TYPE_MYSTERY,
        #endif
        .effect = EFFECT_TARGET_CURSE_OR_USER_ATTACK_DEFENSE_UP_1_SPEED_DOWN_1,
        .power = 0,
        .accuracy = 0,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = 0,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_CURSE,
    },

    [MOVE_FLAIL] =
    {
        .effect = EFFECT_USER_LESS_HP_MORE_DAMAGE,
        .power = 1,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 15,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .flags2 = FLAG_SCENT_MARK_AFFECTED,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 160,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_CONVERSION_2] =
    {
        .effect = EFFECT_USER_CHANGE_TYPE_TO_RESIST_LAST_MOVE,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 30,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .flags = 0,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_RECOVER_HP,
    },

    [MOVE_AEROBLAST] =
    {
        .effect = EFFECT_HIT,
        .power = 100,
        .type = TYPE_FLYING,
        .accuracy = 95,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .flags2 = FLAG_WIND_MOVE | FLAG_LIFT_ENTRY_HAZARDS | FLAG_SCENT_MARK_AFFECTED | FLAG_ALWAYS_CRITICAL_HIT,
        .split = SPLIT_SPECIAL,
        .zMovePower = 180,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_COTTON_SPORE] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_6
            .accuracy = 100,
            .target = MOVE_TARGET_BOTH,
        #elif B_UPDATED_MOVE_DATA == GEN_5
            .accuracy = 100,
            .target = MOVE_TARGET_SELECTED,
        #else
            .accuracy = 85,
            .target = MOVE_TARGET_SELECTED,
        #endif
        .effect = EFFECT_TARGET_SPEED_DOWN_2,
        .power = 0,
        .type = TYPE_GRASS,
        .pp = 40,
        .secondaryEffectChance = 0,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MAGIC_COAT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_POWDER_AND_SPORE_MOVE,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_RESET_STATS,
    },

    [MOVE_REVERSAL] =
    {
        .effect = EFFECT_USER_LESS_HP_MORE_DAMAGE,
        .power = 1,
        .type = TYPE_FIGHTING,
        .accuracy = 100,
        .pp = 15,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .flags2 = FLAG_SCENT_MARK_AFFECTED,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 160,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_SPITE] =
    {
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_MAGIC_COAT_AFFECTED,
        .effect = EFFECT_TARGET_LAST_MOVE_MINUS_4_PP,
        .power = 0,
        .type = TYPE_GHOST,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_RECOVER_HP,
    },

    [MOVE_POWDER_SNOW] =
    {
        .effect = EFFECT_TARGET_FROSTBITE_ON_HIT,
        .power = 40,
        .type = TYPE_ICE,
        .accuracy = 100,
        .pp = 25,
        .secondaryEffectChance = 20,
        .target = MOVE_TARGET_BOTH,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_HAS_SECONDARY_EFFECT,
        .split = SPLIT_SPECIAL,
        .zMovePower = 100,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_PROTECT] =
    {
        .priority = 4,
        .effect = EFFECT_USER_PREVENT_MOVE,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_USER,
        .flags = FLAG_PROTECTION_MOVE,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_RESET_STATS,
    },

    [MOVE_MACH_PUNCH] =
    {
        .effect = EFFECT_HIT,
        .power = 40,
        .type = TYPE_FIGHTING,
        .accuracy = 100,
        .pp = 30,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 1,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_PUNCHING_MOVE,
        .flags2 = FLAG_SCENT_MARK_AFFECTED,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 100,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_SCARY_FACE] =
    {
        .accuracy = 100,
        .effect = EFFECT_TARGET_SPEED_DOWN_2,
        .power = 0,
        .type = TYPE_NORMAL,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MAGIC_COAT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_SPD_UP_1,
    },

    [MOVE_FEINT_ATTACK] =
    {
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .flags2 = FLAG_SCENT_MARK_AFFECTED,
        .effect = EFFECT_HIT,
        .power = 60,
        .type = TYPE_DARK,
        .accuracy = 0,
        .pp = 20,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 120,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_SWEET_KISS] =
    {
        .type = TYPE_FAIRY,
        .effect = EFFECT_SWEET_KISS,
        .power = 50,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        .flags2 = FLAG_KISSING_MOVE,
        .split = SPLIT_SPECIAL,
        .zMovePower = 100,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_BELLY_DRUM] =
    {
        .effect = EFFECT_MAXIMIZE_ATTACK_HALF_HP_COST,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .flags = FLAG_SNATCH_AFFECTED,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_RECOVER_HP,
    },

    [MOVE_SLUDGE_BOMB] =
    {
        .effect = EFFECT_TARGET_POISON_ON_HIT,
        .power = 90,
        .type = TYPE_POISON,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 30,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_HAS_SECONDARY_EFFECT | FLAG_BALL_AND_BOMB_MOVE,
        .split = SPLIT_SPECIAL,
        .zMovePower = 175,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_MUD_SLAP] =
    {
        .effect = EFFECT_TARGET_ACCURACY_DOWN_1_ON_HIT,
        .power = 20,
        .type = TYPE_GROUND,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 100,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_HAS_SECONDARY_EFFECT | FLAG_DAMAGE_ON_UNGROUNDED_TARGET,
        .flags2 = FLAG_MUD_MOVE,
        .split = SPLIT_SPECIAL,
        .zMovePower = 100,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_OCTAZOOKA] =
    {
        .effect = EFFECT_TARGET_ACCURACY_DOWN_1_ON_HIT,
        .power = 100,
        .type = TYPE_GROUND,
        .accuracy = 50,
        .pp = 5,
        .secondaryEffectChance = 100,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_BALL_AND_BOMB_MOVE | FLAG_HAS_SECONDARY_EFFECT | FLAG_DAMAGE_ON_UNGROUNDED_TARGET | FLAG_AURA_BEAM_CANNON_GUN_PULSE_PUMP_SHOT_AND_ZOOKA_MOVE,
        .split = SPLIT_SPECIAL,
        .zMovePower = 120,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_SPIKES] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_5
            .flags = FLAG_MAGIC_COAT_AFFECTED,
        #else
            .flags = 0,
        #endif
        .effect = EFFECT_TARGET_SIDE_SPIKES,
        .power = 0,
        .type = TYPE_GROUND,
        .accuracy = 0,
        .pp = 20,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_OPPONENTS_FIELD,
        .priority = 0,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_DEF_UP_1,
    },

    [MOVE_ZAP_CANNON] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_4
            .power = 120,
            .zMovePower = 190,
        #else
            .power = 100,
            .zMovePower = 180,
        #endif
        .effect = EFFECT_TARGET_PARALYZE_ON_HIT,
        .type = TYPE_ELECTRIC,
        .accuracy = 50,
        .pp = 5,
        .secondaryEffectChance = 100,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_HAS_SECONDARY_EFFECT | FLAG_BALL_AND_BOMB_MOVE | FLAG_AURA_BEAM_CANNON_GUN_PULSE_PUMP_SHOT_AND_ZOOKA_MOVE,
        .split = SPLIT_SPECIAL,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_FORESIGHT] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_5
            .accuracy = 0,
            .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_MAGIC_COAT_AFFECTED,
        #elif B_UPDATED_MOVE_DATA == GEN_4
            .accuracy = 0,
            .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        #else
            .accuracy = 100,
            .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        #endif
        .effect = EFFECT_USER_BYPASS_EVASION_AND_GHOST_TYPE,
        .power = 0,
        .type = TYPE_NORMAL,
        .pp = 40,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_BOOST_CRITS,
    },

    [MOVE_DESTINY_BOND] =
    {
        .effect = EFFECT_TARGET_FAINT_IF_USER_FAINT,
        .power = 0,
        .type = TYPE_GHOST,
        .accuracy = 0,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .flags = 0,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_FOLLOW_ME,
    },

    [MOVE_PERISH_SONG] =
    {
        .effect = EFFECT_ALL_FAINT_THREE_TURNS,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_ALL_BATTLERS,
        .priority = 0,
        .flags = FLAG_SOUND_BASED_MOVE,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_RESET_STATS,
    },

    [MOVE_ICY_WIND] =
    {
        .effect = EFFECT_TARGET_SPEED_DOWN_1_ON_HIT,
        .power = 75,
        .type = TYPE_ICE,
        .accuracy = 95,
        .pp = 10,
        .secondaryEffectChance = 100,
        .target = MOVE_TARGET_BOTH,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_HAS_SECONDARY_EFFECT,
        .flags2 = FLAG_WIND_MOVE,
        .split = SPLIT_SPECIAL,
        .zMovePower = 100,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_DETECT] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_5
            .priority = 4,
        #else
            .priority = 3,
        #endif
        .effect = EFFECT_USER_PREVENT_MOVE,
        .power = 0,
        .type = TYPE_FIGHTING,
        .accuracy = 0,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_USER,
        .flags = FLAG_PROTECTION_MOVE,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_EVSN_UP_1,
    },

    [MOVE_BONE_RUSH] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_5
            .accuracy = 95,
        #else
            .accuracy = 80,
        #endif
        .effect = EFFECT_TARGET_MULTI_HIT,
        .power = 15,
        .type = TYPE_GROUND,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 1,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_DAMAGE_ON_UNGROUNDED_TARGET,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 100,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_LOCK_ON] =
    {
        .accuracy = 0,
        .effect = EFFECT_USER_BOOST_NEXT_MOVE_ON_TARGET,
        .power = 0,
        .type = TYPE_NORMAL,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_SPD_UP_1,
    },

    [MOVE_OUTRAGE] =
    {
        .power = 120,
        .pp = 10,
        .zMovePower = 190,
        .effect = EFFECT_USER_RAMPAGE,
        .type = TYPE_DRAGON,
        .accuracy = 100,
        .secondaryEffectChance = 100,
        .target = MOVE_TARGET_RANDOM,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .flags2 = FLAG_EMOTION_MOVE,
        .split = SPLIT_PHYSICAL,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_SANDSTORM] =
    {
        .effect = EFFECT_SANDSTORM,
        .power = 0,
        .type = TYPE_ROCK,
        .accuracy = 0,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_ALL_BATTLERS,
        .priority = 0,
        .flags2 = FLAG_WEATHER_RELATED_MOVE | FLAG_WIND_MOVE,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_SPD_UP_1,
    },

    [MOVE_GIGA_DRAIN] =
    {
        .power = 75,
        .pp = 10,
        .zMovePower = 140,
        .effect = EFFECT_USER_DRAIN_50_ON_HIT,
        .type = TYPE_GRASS,
        .accuracy = 100,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        .split = SPLIT_SPECIAL,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_ENDURE] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_5
            .priority = 4,
        #else
            .priority = 3,
        #endif
        .effect = EFFECT_USER_SURVIVE_1_HP,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_USER,
        .flags = FLAG_PROTECTION_MOVE,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_RESET_STATS,
    },

    [MOVE_CHARM] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_6
            .type = TYPE_FAIRY,
        #else
            .type = TYPE_NORMAL,
        #endif
        .effect = EFFECT_TARGET_ATTACK_DOWN_2,
        .power = 0,
        .accuracy = 100,
        .pp = 20,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MAGIC_COAT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        .flags2 = FLAG_EMOTION_MOVE,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_DEF_UP_1,
    },

    [MOVE_ROLLOUT] =
    {
        .effect = EFFECT_USER_FIVE_TURNS_DOUBLE_DAMAGE_EACH_TURN_ON_HIT,
        .power = 30,
        .type = TYPE_ROCK,
        .accuracy = 90,
        .pp = 20,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 100,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_FALSE_SWIPE] =
    {
        .effect = EFFECT_TARGET_SURVIVE_1_HP_ON_HIT,
        .power = 40,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 40,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .flags2 = FLAG_SLICING_MOVE | FLAG_SCENT_MARK_AFFECTED,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 100,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_SWAGGER] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_7
            .accuracy = 85,
        #else
            .accuracy = 90,
        #endif
        .effect = EFFECT_TARGET_CONFUSE_AND_ATTACK_UP_2,
        .power = 0,
        .type = TYPE_NORMAL,
        .pp = 15,
        .secondaryEffectChance = 100,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MAGIC_COAT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_RESET_STATS,
    },

    [MOVE_MILK_DRINK] =
    {
        .effect = EFFECT_SOFTBOILED,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_SNATCH_AFFECTED,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_RESET_STATS,
    },

    [MOVE_SPARK] =
    {
        .effect = EFFECT_TARGET_PARALYZE_ON_HIT,
        .power = 65,
        .type = TYPE_ELECTRIC,
        .accuracy = 100,
        .pp = 20,
        .secondaryEffectChance = 30,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_HAS_SECONDARY_EFFECT,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 120,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_FURY_CUTTER] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_6
            .power = 40,
        #elif B_UPDATED_MOVE_DATA == GEN_5
            .power = 20,
        #else
            .power = 10,
        #endif
        .effect = EFFECT_USER_DOUBLE_DAMAGE_EACH_TURN_ON_HIT,
        .type = TYPE_BUG,
        .accuracy = 95,
        .pp = 20,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .flags2 = FLAG_SLICING_MOVE,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 100,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_STEEL_WING] =
    {
        .effect = EFFECT_DEFENSE_UP_1_ON_HIT,
        .power = 80,
        .type = TYPE_STEEL,
        .accuracy = 95,
        .pp = 15,
        .secondaryEffectChance = 20,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_HAS_SECONDARY_EFFECT,
        .flags2 = FLAG_WING_MOVE,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 160,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_MEAN_LOOK] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_6
            .flags = FLAG_MAGIC_COAT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        #else
            .flags = FLAG_PROTECT_AFFECTED | FLAG_MAGIC_COAT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        #endif
        .effect = EFFECT_TARGET_PREVENT_ESCAPE,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_SPDEF_UP_1,
    },

    [MOVE_ATTRACT] =
    {
        .effect = EFFECT_TARGET_ATTRACT,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 15,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MAGIC_COAT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        .flags2 = FLAG_EMOTION_MOVE,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_RESET_STATS,
    },

    [MOVE_SLEEP_TALK] =
    {
        .effect = EFFECT_USER_RANDOMLY_MOVE_ASLEEP,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_DEPENDS,
        .priority = 0,
        .flags = 0,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_BOOST_CRITS,
    },

    [MOVE_HEAL_BELL] =
    {
        .flags = FLAG_SNATCH_AFFECTED | FLAG_SOUND_BASED_MOVE,
        .effect = EFFECT_USER_HEAL_PARTY_STATUS_CONDITION,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_RECOVER_HP,
    },

    [MOVE_RETURN] =
    {
        .effect = EFFECT_USER_MORE_HAPINESS_MORE_DAMAGE,
        .power = 1,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 20,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .flags2 = FLAG_SCENT_MARK_AFFECTED,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 160,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_PRESENT] =
    {
        .effect = EFFECT_PRESENT,
        .power = 1,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 15,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_USER_OR_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MAGIC_COAT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        .split = SPLIT_STATUS,
        .zMovePower = 180,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_FRUSTRATION] =
    {
        .effect = EFFECT_USER_LESS_HAPINESS_MORE_DAMAGE,
        .power = 1,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 20,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .flags2 = FLAG_SCENT_MARK_AFFECTED,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 160,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_SAFEGUARD] =
    {
        .effect = EFFECT_USER_SIDE_STATUS_CONDITION_WALL,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 25,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .flags = FLAG_SNATCH_AFFECTED,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_SPD_UP_1,
    },

    [MOVE_PAIN_SPLIT] =
    {
        .effect = EFFECT_USER_TARGET_EQUALLY_SHARE_HP,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 20,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_DEF_UP_1,
    },

    [MOVE_SACRED_FIRE] =
    {
        .effect = EFFECT_SACRED_FIRE,
        .power = 100,
        .type = TYPE_FIRE,
        .accuracy = 95,
        .pp = 5,
        .secondaryEffectChance = 100,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_HAS_SECONDARY_EFFECT | FLAG_THAW_USER,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 180,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_MAGNITUDE] =
    {
        .effect = EFFECT_MAGNITUDE,
        .power = 1,
        .type = TYPE_GROUND,
        .accuracy = 100,
        .pp = 30,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_FOES_AND_ALLY,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_DAMAGE_ON_UNDERGROUND_TARGET,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 140,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_DYNAMIC_PUNCH] =
    {
        .effect = EFFECT_TARGET_CONFUSE_ON_HIT,
        .power = 100,
        .type = TYPE_FIGHTING,
        .accuracy = 50,
        .pp = 5,
        .secondaryEffectChance = 100,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_PUNCHING_MOVE | FLAG_HAS_SECONDARY_EFFECT,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 180,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_MEGAHORN] =
    {
        .effect = EFFECT_STAR_ICON,
        .power = 120,
        .type = TYPE_BUG,
        .accuracy = 85,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .flags2 = FLAG_IGNORE_TARGET_DEFENSE_STAGES | FLAG_SCENT_MARK_AFFECTED,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 190,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_DRAGON_BREATH] =
    {
        .effect = EFFECT_TARGET_BURN_ON_HIT,
        .power = 70,
        .type = TYPE_FIRE,
        .accuracy = 100,
        .pp = 20,
        .secondaryEffectChance = 20,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_HAS_SECONDARY_EFFECT,
        .split = SPLIT_SPECIAL,
        .zMovePower = 140,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_BATON_PASS] =
    {
        .effect = EFFECT_BATON_PASS,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 40,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .flags = 0,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_RESET_STATS,
    },

    [MOVE_ENCORE] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_5
            .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_MAGIC_COAT_AFFECTED,
        #else
            .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        #endif
        .effect = EFFECT_TARGET_FORCED_REPEAT_LAST_MOVE,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_SPD_UP_1,
    },

    [MOVE_PURSUIT] =
    {
        .effect = EFFECT_HIT_BEFORE_SWITCH_OUT,
        .power = 40,
        .type = TYPE_DARK,
        .accuracy = 100,
        .pp = 20,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        .flags2 = FLAG_SCENT_MARK_AFFECTED,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 100,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_RAPID_SPIN] =
    {
        .power = 50,
        .effect = EFFECT_SPEED_UP_1_AND_CLEAR_USER,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 40,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 100,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_SWEET_SCENT] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_6
            .effect = EFFECT_TARGET_EVASION_DOWN_2,
        #else
            .effect = EFFECT_TARGET_EVASION_DOWN_1,
        #endif
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 20,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_BOTH,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MAGIC_COAT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_ACC_UP_1,
    },

    [MOVE_IRON_TAIL] =
    {
        .effect = EFFECT_TARGET_DEFENSE_DOWN_1_ON_HIT,
        .power = 100,
        .type = TYPE_STEEL,
        .accuracy = 85,
        .pp = 10,
        .secondaryEffectChance = 30,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_HAS_SECONDARY_EFFECT,
        .flags2 = FLAG_TAIL_MOVE,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 180,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_METAL_CLAW] =
    {
        .effect = EFFECT_ATTACK_UP_1_ON_HIT,
        .power = 75,
        .type = TYPE_STEEL,
        .accuracy = 95,
        .pp = 15,
        .secondaryEffectChance = 20,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_HAS_SECONDARY_EFFECT,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 140,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_VITAL_THROW] =
    {
        .effect = EFFECT_HIT,
        .power = 70,
        .type = TYPE_FIGHTING,
        .accuracy = 0,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = -1,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .flags2 = FLAG_SCENT_MARK_AFFECTED,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 140,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_MORNING_SUN] =
    {
        .effect = EFFECT_MORNING_SUN,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .flags = FLAG_SNATCH_AFFECTED,
        .flags2 = FLAG_WEATHER_RELATED_MOVE | FLAG_COSMIC_ENERGYZED_MOVE,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_RESET_STATS,
    },

    [MOVE_SYNTHESIS] =
    {
        .effect = EFFECT_SYNTHESIS,
        .power = 0,
        .type = TYPE_GRASS,
        .accuracy = 0,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .flags = FLAG_SNATCH_AFFECTED,
        .flags2 = FLAG_WEATHER_RELATED_MOVE,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_RESET_STATS,
    },

    [MOVE_MOONLIGHT] =
    {
        .type = TYPE_FAIRY,
        .effect = EFFECT_MOONLIGHT,
        .power = 0,
        .accuracy = 0,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .flags = FLAG_SNATCH_AFFECTED,
        .flags2 = FLAG_WEATHER_RELATED_MOVE | FLAG_COSMIC_ENERGYZED_MOVE,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_RESET_STATS,
    },

    [MOVE_HIDDEN_POWER] =
    {
        .power = 60,
        .effect = EFFECT_TYPE_DEPENDS_ON_IV,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 15,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .flags2 = FLAG_SCENT_MARK_AFFECTED,
        .split = SPLIT_SPECIAL,
        .zMovePower = 120,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_CROSS_CHOP] =
    {
        .effect = EFFECT_HIT,
        .power = 100,
        .type = TYPE_FIGHTING,
        .accuracy = 80,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_HIGH_CRITICAL_HIT_RATIO,
        .flags2 = FLAG_SCENT_MARK_AFFECTED,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 180,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_TWISTER] =
    {
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_HAS_SECONDARY_EFFECT | FLAG_DOUBLE_DAMAGE_ON_FLYING_TARGET,
        .flags2 = FLAG_LIFT_ENTRY_HAZARDS | FLAG_WIND_MOVE,
        .effect = EFFECT_TWISTER,
        .power = 60,
        .type = TYPE_DRAGON,
        .accuracy = 100,
        .pp = 20,
        .secondaryEffectChance = 20,
        .target = MOVE_TARGET_BOTH,
        .priority = 0,
        .split = SPLIT_SPECIAL,
        .zMovePower = 120,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_RAIN_DANCE] =
    {
        .effect = EFFECT_RAIN_DANCE,
        .power = 0,
        .type = TYPE_WATER,
        .accuracy = 0,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_ALL_BATTLERS,
        .priority = 0,
        .flags = 0,
        .flags2 = FLAG_WEATHER_RELATED_MOVE,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_SPD_UP_1,
    },

    [MOVE_SUNNY_DAY] =
    {
        .effect = EFFECT_SUNNY_DAY,
        .power = 0,
        .type = TYPE_FIRE,
        .accuracy = 0,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_ALL_BATTLERS,
        .priority = 0,
        .flags = 0,
        .flags2 = FLAG_WEATHER_RELATED_MOVE | FLAG_COSMIC_ENERGYZED_MOVE,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_SPD_UP_1,
    },

    [MOVE_CRUNCH] =
    {
        .effect = EFFECT_TARGET_DEFENSE_DOWN_1_ON_HIT,
        .power = 80,
        .type = TYPE_DARK,
        .accuracy = 100,
        .pp = 15,
        .secondaryEffectChance = 20,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_HAS_SECONDARY_EFFECT | FLAG_BITING_MOVE,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 160,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_MIRROR_COAT] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_5
            .flags = FLAG_PROTECT_AFFECTED,
        #elif B_UPDATED_MOVE_DATA == GEN_4
            .flags = 0,
        #else
            .flags = FLAG_MIRROR_MOVE_AFFECTED,
        #endif
        .effect = EFFECT_REFLECT_SPECIAL_DAMAGE,
        .power = 1,
        .type = TYPE_PSYCHIC,
        .accuracy = 100,
        .pp = 20,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_DEPENDS,
        .priority = -5,
        .split = SPLIT_SPECIAL,
        .zMovePower = 100,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_PSYCH_UP] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_5
            .flags = 0,
        #else
            .flags = FLAG_SNATCH_AFFECTED,
        #endif
        .effect = EFFECT_COPY_STATS_STAGES,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_RECOVER_HP,
    },

    [MOVE_EXTREME_SPEED] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_5
            .priority = 2,
        #else
            .priority = 1,
        #endif
        .effect = EFFECT_HIT,
        .power = 80,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .flags2 = FLAG_SCENT_MARK_AFFECTED,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 160,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_ANCIENT_POWER] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_4
            .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_HAS_SECONDARY_EFFECT,
        #else
            .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_HAS_SECONDARY_EFFECT,
        #endif
        .effect = EFFECT_ALL_STATS_UP_1_ON_HIT,
        .power = 60,
        .type = TYPE_ROCK,
        .accuracy = 100,
        .pp = 5,
        .secondaryEffectChance = 10,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .split = SPLIT_SPECIAL,
        .zMovePower = 120,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_SHADOW_BALL] =
    {
        .effect = EFFECT_TARGET_SPECIAL_DEFENSE_DOWN_1_ON_HIT,
        .power = 80,
        .type = TYPE_GHOST,
        .accuracy = 100,
        .pp = 15,
        .secondaryEffectChance = 20,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_HAS_SECONDARY_EFFECT | FLAG_BALL_AND_BOMB_MOVE,
        .split = SPLIT_SPECIAL,
        .zMovePower = 160,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_FUTURE_SIGHT] =
    {
        .power = 120,
        .accuracy = 100,
        .pp = 10,
        .zMovePower = 190,
        .effect = EFFECT_FUTURE_SIGHT,
        .type = TYPE_PSYCHIC,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = 0,
        .split = SPLIT_SPECIAL,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_ROCK_SMASH] =
    {
        .power = 40,
        .effect = EFFECT_TARGET_DEFENSE_DOWN_1_ON_HIT,
        .type = TYPE_FIGHTING,
        .accuracy = 100,
        .pp = 15,
        .secondaryEffectChance = 100,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_HAS_SECONDARY_EFFECT,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 100,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_WHIRLPOOL] =
    {
        .power = 80,
        .accuracy = 85,
        .effect = EFFECT_TARGET_PREVENT_ESCAPE_AND_HURT_EACH_TURN,
        .type = TYPE_WATER,
        .pp = 10,
        .secondaryEffectChance = 100,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_DAMAGE_ON_UNDERWATER_TARGET,
        .flags2 = FLAG_WAVE_SURF_AFFECTED,
        .split = SPLIT_SPECIAL,
        .zMovePower = 100,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_BEAT_UP] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_5
            .power = 1,
        #else
            .power = 10,
        #endif
        .effect = EFFECT_BEAT_UP,
        .type = TYPE_DARK,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 100,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_FAKE_OUT] =
    {
        .priority = 3,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_HAS_SECONDARY_EFFECT,
        .effect = EFFECT_FAKE_OUT,
        .power = 40,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 100,
        .target = MOVE_TARGET_SELECTED,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 100,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_UPROAR] =
    {
        .power = 90,
        .zMovePower = 175,
        .effect = EFFECT_UPROAR,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 100,
        .target = MOVE_TARGET_RANDOM,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_SOUND_BASED_MOVE,
        .split = SPLIT_SPECIAL,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_STOCKPILE] =
    {
        .pp = 20,
        .effect = EFFECT_STOCKPILE,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .flags = FLAG_SNATCH_AFFECTED,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_RECOVER_HP,
    },

    [MOVE_SPIT_UP] =
    {
        .power = 1,
        .effect = EFFECT_SPIT_UP,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .split = SPLIT_SPECIAL,
        .zMovePower = 180,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_SWALLOW] =
    {
        .effect = EFFECT_SWALLOW,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .flags = FLAG_SNATCH_AFFECTED,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_RESET_STATS,
    },

    [MOVE_HEAT_WAVE] =
    {
        .power = 95,
        .zMovePower = 175,
        .effect = EFFECT_TARGET_BURN_ON_HIT,
        .type = TYPE_FIRE,
        .accuracy = 90,
        .pp = 10,
        .secondaryEffectChance = 10,
        .target = MOVE_TARGET_BOTH,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_HAS_SECONDARY_EFFECT,
        .flags2 = FLAG_WIND_MOVE,
        .split = SPLIT_SPECIAL,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_HAIL] =
    {
        .effect = EFFECT_HAIL,
        .power = 0,
        .type = TYPE_ICE,
        .accuracy = 0,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_ALL_BATTLERS,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED,
        .flags2 = FLAG_WEATHER_RELATED_MOVE,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_SPD_UP_1,
    },

    [MOVE_TORMENT] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_5
            .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_MAGIC_COAT_AFFECTED,
        #else
            .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        #endif
        .effect = EFFECT_TORMENT,
        .power = 0,
        .type = TYPE_DARK,
        .accuracy = 100,
        .pp = 15,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_DEF_UP_1,
    },

    [MOVE_FLATTER] =
    {
        .effect = EFFECT_FLATTER,
        .power = 0,
        .type = TYPE_DARK,
        .accuracy = 100,
        .pp = 15,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MAGIC_COAT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_SPDEF_UP_1,
    },

    [MOVE_WILL_O_WISP] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_6
            .accuracy = 85,
        #else
            .accuracy = 75,
        #endif
        .effect = EFFECT_WILL_O_WISP,
        .power = 0,
        .type = TYPE_FIRE,
        .pp = 15,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MAGIC_COAT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_ATK_UP_1,
    },

    [MOVE_MEMENTO] =
    {
        .effect = EFFECT_MEMENTO,
        .power = 0,
        .type = TYPE_DARK,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_RESTORE_REPLACEMENT_HP,
    },

    [MOVE_FACADE] =
    {
        .effect = EFFECT_FACADE,
        .power = 70,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 20,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        .flags2 = FLAG_SCENT_MARK_AFFECTED,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 140,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_FOCUS_PUNCH] =
    {
        .effect = EFFECT_FOCUS_PUNCH,
        .power = 150,
        .type = TYPE_FIGHTING,
        .accuracy = 100,
        .pp = 20,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = -3,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_PUNCHING_MOVE,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 200,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_SMELLING_SALTS] =
    {
        .power = 70,
        .zMovePower = 140,
        .effect = EFFECT_SMELLINGSALT,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        .split = SPLIT_PHYSICAL,
        .argument = STATUS1_PARALYSIS,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_FOLLOW_ME] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_6
            .priority = 2,
        #else
            .priority = 3,
        #endif
        .effect = EFFECT_FOLLOW_ME,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 20,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_USER,
        .flags = 0,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_RESET_STATS,
    },

    [MOVE_NATURE_POWER] =
    {
        .effect = EFFECT_NATURE_POWER,
        .power = 1,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 20,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_DEPENDS,
        .priority = 0,
        .flags = 0,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_CHARGE] =
    {
        .effect = EFFECT_CHARGE,
        .power = 0,
        .type = TYPE_ELECTRIC,
        .accuracy = 0,
        .pp = 20,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .flags = FLAG_SNATCH_AFFECTED,
        .flags2 = FLAG_MAGNET_MOVE,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_SPDEF_UP_1,
    },

    [MOVE_TAUNT] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_5
            .flags = FLAG_PROTECT_AFFECTED | FLAG_MAGIC_COAT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        #elif B_UPDATED_MOVE_DATA == GEN_4
            .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        #else
            .flags = FLAG_PROTECT_AFFECTED,
        #endif
        .effect = EFFECT_TAUNT,
        .power = 0,
        .type = TYPE_DARK,
        .accuracy = 100,
        .pp = 20,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_ATK_UP_1,
    },

    [MOVE_HELPING_HAND] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_4
            .target = MOVE_TARGET_ALLY,
        #else
            .target = MOVE_TARGET_USER,
        #endif
        .effect = EFFECT_HELPING_HAND,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 20,
        .secondaryEffectChance = 0,
        .priority = 5,
        .flags = 0,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_RESET_STATS,
    },

    [MOVE_TRICK] =
    {
        .effect = EFFECT_TRICK,
        .power = 0,
        .type = TYPE_PSYCHIC,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_SPD_UP_2,
    },

    [MOVE_ROLE_PLAY] =
    {
        .effect = EFFECT_ROLE_PLAY,
        .power = 0,
        .type = TYPE_PSYCHIC,
        .accuracy = 0,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = 0,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_SPD_UP_1,
    },

    [MOVE_WISH] =
    {
        #if B_UPDATED
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_RESET_STATS,_MOVE_DATA >= GEN_5
            .flags = FLAG_SNATCH_AFFECTED,
        #else
            .flags = 0,
        #endif
        .effect = EFFECT_WISH,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_SPDEF_UP_1,
    },

    [MOVE_ASSIST] =
    {
        .effect = EFFECT_ASSIST,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 20,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_DEPENDS,
        .priority = 0,
        .flags = 0,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_INGRAIN] =
    {
        .effect = EFFECT_INGRAIN,
        .power = 0,
        .type = TYPE_GRASS,
        .accuracy = 100,
        .pp = 20,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .flags = FLAG_SNATCH_AFFECTED,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_SPDEF_UP_1,
    },

    [MOVE_SUPERPOWER] =
    {
        .effect = EFFECT_SUPERPOWER,
        .power = 120,
        .type = TYPE_FIGHTING,
        .accuracy = 100,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 190,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_MAGIC_COAT] =
    {
        .effect = EFFECT_MAGIC_COAT,
        .power = 0,
        .type = TYPE_PSYCHIC,
        .accuracy = 100,
        .pp = 15,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_DEPENDS,
        .priority = 4,
        .flags = 0,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_SPDEF_UP_2,
    },

    [MOVE_RECYCLE] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_5
            .flags = FLAG_SNATCH_AFFECTED,
        #else
            .flags = 0,
        #endif
        .effect = EFFECT_RECYCLE,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_SPD_UP_2,
    },

    [MOVE_REVENGE] =
    {
        .effect = EFFECT_REVENGE,
        .power = 60,
        .type = TYPE_FIGHTING,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = -4,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .flags2 = FLAG_SCENT_MARK_AFFECTED,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 120,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_BRICK_BREAK] =
    {
        .effect = EFFECT_BRICK_BREAK,
        .power = 75,
        .type = TYPE_FIGHTING,
        .accuracy = 100,
        .pp = 15,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 140,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_YAWN] =
    {
        .effect = EFFECT_YAWN,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MAGIC_COAT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_SPD_UP_1,
    },

    [MOVE_KNOCK_OFF] =
    {
        .power = 65,
        .zMovePower = 120,
        .effect = EFFECT_KNOCK_OFF,
        .type = TYPE_DARK,
        .accuracy = 100,
        .pp = 20,
        .secondaryEffectChance = 100,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        .split = SPLIT_PHYSICAL,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_ENDEAVOR] =
    {
        .effect = EFFECT_ENDEAVOR,
        .power = 1,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 160,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_ERUPTION] =
    {
        .effect = EFFECT_ERUPTION,
        .power = 150,
        .type = TYPE_FIRE,
        .accuracy = 100,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_BOTH,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .split = SPLIT_SPECIAL,
        .zMovePower = 200,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_SKILL_SWAP] =
    {
        .effect = EFFECT_SKILL_SWAP,
        .power = 0,
        .type = TYPE_PSYCHIC,
        .accuracy = 0,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_SPD_UP_1,
    },

    [MOVE_IMPRISON] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_5
            .flags = FLAG_PROTECT_AFFECTED | FLAG_SNATCH_AFFECTED,
        #else
            .flags = FLAG_PROTECT_AFFECTED,
        #endif
        .effect = EFFECT_IMPRISON,
        .power = 0,
        .type = TYPE_PSYCHIC,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_SPDEF_UP_2,
    },

    [MOVE_REFRESH] =
    {
        .effect = EFFECT_REFRESH,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 20,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .flags = FLAG_SNATCH_AFFECTED,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_RECOVER_HP,
    },

    [MOVE_GRUDGE] =
    {
        .effect = EFFECT_EERIE_SPELL,
        .power = 80,
        .type = TYPE_GHOST,
        .accuracy = 100,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_HAS_SECONDARY_EFFECT,
        .split = SPLIT_SPECIAL,
        .zMovePower = 160,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_SNATCH] =
    {
        .effect = EFFECT_SNATCH,
        .power = 0,
        .type = TYPE_DARK,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_DEPENDS,
        .priority = 4,
        .flags = FLAG_MIRROR_MOVE_AFFECTED,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_SPD_UP_2,
    },

    [MOVE_SECRET_POWER] =
    {
        .effect = EFFECT_SECRET_POWER,
        .power = 70,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 20,
        .secondaryEffectChance = 30,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_HAS_SECONDARY_EFFECT,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 140,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_DIVE] =
    {
        .power = 80,
        .zMovePower = 160,
        .effect = EFFECT_SEMI_INVULNERABLE,
        .type = TYPE_WATER,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_ARM_THRUST] =
    {
        .effect = EFFECT_TARGET_MULTI_HIT,
        .power = 15,
        .type = TYPE_FIGHTING,
        .accuracy = 100,
        .pp = 20,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_HIGH_CRITICAL_HIT_RATIO,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 100,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_CAMOUFLAGE] =
    {
        .effect = EFFECT_CAMOUFLAGE,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 20,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .flags = FLAG_SNATCH_AFFECTED,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_EVSN_UP_1,
    },

    [MOVE_TAIL_GLOW] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_5
            .effect = EFFECT_USER_SPECIAL_ATTACK_UP_3,
        #else
            .effect = EFFECT_USER_SPECIAL_ATTACK_UP_2,
        #endif
        .power = 0,
        .type = TYPE_BUG,
        .accuracy = 0,
        .pp = 20,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .flags = FLAG_SNATCH_AFFECTED,
        .flags2 = FLAG_TAIL_MOVE,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_RESET_STATS,
    },

    [MOVE_LUSTER_PURGE] =
    {
        .effect = EFFECT_TARGET_SPECIAL_DEFENSE_DOWN_1_ON_HIT,
        .power = 95,
        .type = TYPE_PSYCHIC,
        .accuracy = 100,
        .pp = 5,
        .secondaryEffectChance = 50,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_HAS_SECONDARY_EFFECT,
        .split = SPLIT_SPECIAL,
        .zMovePower = 175,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_MIST_BALL] =
    {
        .effect = EFFECT_TARGET_SPECIAL_ATTACK_DOWN_1_ON_HIT,
        .power = 95,
        .type = TYPE_PSYCHIC,
        .accuracy = 100,
        .pp = 5,
        .secondaryEffectChance = 50,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_BALL_AND_BOMB_MOVE | FLAG_HAS_SECONDARY_EFFECT,
        .split = SPLIT_SPECIAL,
        .zMovePower = 175,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_FEATHER_DANCE] =
    {
        .effect = EFFECT_FEATHER_DANCE,
        .power = 0,
        .type = TYPE_FLYING,
        .accuracy = 0,
        .pp = 20,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .flags = FLAG_SNATCH_AFFECTED | FLAG_DANCING_MOVE,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_RESET_STATS,
    },

    [MOVE_TEETER_DANCE] =
    {
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_DANCING_MOVE,
        .effect = EFFECT_TEETER_DANCE,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 20,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_FOES_AND_ALLY,
        .priority = 0,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_SPATK_UP_1,
    },

    [MOVE_BLAZE_KICK] =
    {
        .effect = EFFECT_TARGET_BURN_ON_HIT,
        .power = 85,
        .type = TYPE_FIRE,
        .accuracy = 90,
        .pp = 10,
        .secondaryEffectChance = 10,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_HIGH_CRITICAL_HIT_RATIO | FLAG_HAS_SECONDARY_EFFECT,
        .flags2 = FLAG_AIRBOURNE_STYLE_BOOST,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 160,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_MUD_SPORT] =
    {
        .effect = EFFECT_MUD_SPORT,
        .power = 0,
        .type = TYPE_GROUND,
        .accuracy = 100,
        .pp = 15,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_ALL_BATTLERS,
        .priority = 0,
        .flags = 0,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_SPDEF_UP_1,
    },

    [MOVE_ICE_BALL] =
    {
        .effect = EFFECT_USER_FIVE_TURNS_DOUBLE_DAMAGE_EACH_TURN_ON_HIT,
        .power = 30,
        .type = TYPE_ICE,
        .accuracy = 90,
        .pp = 20,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_BALL_AND_BOMB_MOVE,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 100,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_NEEDLE_ARM] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_4
            .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_HAS_SECONDARY_EFFECT,
        #else
            .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_HAS_SECONDARY_EFFECT | FLAG_DOUBLE_DAMAGE_ON_MINIMIZED_TARGET,
        #endif
        .effect = EFFECT_TARGET_FLINCH_ON_HIT,
        .power = 90,
        .type = TYPE_GRASS,
        .accuracy = 100,
        .pp = 15,
        .secondaryEffectChance = 30,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 175,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_SLACK_OFF] =
    {
        .effect = EFFECT_USER_RESTORE_50_HP,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .flags = FLAG_SNATCH_AFFECTED,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_RESET_STATS,
    },

    [MOVE_HYPER_VOICE] =
    {
        .effect = EFFECT_HIT,
        .power = 90,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_BOTH,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_SOUND_BASED_MOVE,
        .split = SPLIT_SPECIAL,
        .zMovePower = 175,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_POISON_FANG] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_6
            .secondaryEffectChance = 50,
        #else
            .secondaryEffectChance = 30,
        #endif
        .effect = EFFECT_TARGET_BADLY_POISON_ON_HIT,
        .power = 75,
        .type = TYPE_POISON,
        .accuracy = 100,
        .pp = 10,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_HAS_SECONDARY_EFFECT | FLAG_BITING_MOVE,
        .flags2 = FLAG_FANG_MOVE,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 140,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_CRUSH_CLAW] =
    {
        .effect = EFFECT_TARGET_DEFENSE_DOWN_1_ON_HIT,
        .power = 75,
        .type = TYPE_NORMAL,
        .accuracy = 95,
        .pp = 10,
        .secondaryEffectChance = 50,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_HAS_SECONDARY_EFFECT,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 140,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_BLAST_BURN] =
    {
        .effect = EFFECT_USER_RECHARGE,
        .power = 150,
        .type = TYPE_FIRE,
        .accuracy = 90,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .split = SPLIT_SPECIAL,
        .zMovePower = 200,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_HYDRO_CANNON] =
    {
        .effect = EFFECT_USER_RECHARGE,
        .power = 150,
        .type = TYPE_WATER,
        .accuracy = 90,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_AURA_BEAM_CANNON_GUN_PULSE_PUMP_SHOT_AND_ZOOKA_MOVE,
        .split = SPLIT_SPECIAL,
        .zMovePower = 200,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_METEOR_MASH] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_6
            .power = 90,
            .accuracy = 90,
            .zMovePower = 175,
        #else
            .power = 100,
            .accuracy = 85,
            .zMovePower = 180,
        #endif
        .effect = EFFECT_SPELL_FIST_USER_ATTACK_UP_1_ON_HIT,
        .type = TYPE_STEEL,
        .pp = 10,
        .secondaryEffectChance = 20,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_PUNCHING_MOVE | FLAG_HAS_SECONDARY_EFFECT,
        .split = SPLIT_PHYSICAL,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_ASTONISH] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_4
            .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_HAS_SECONDARY_EFFECT,
        #else
            .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_HAS_SECONDARY_EFFECT | FLAG_DOUBLE_DAMAGE_ON_MINIMIZED_TARGET,
        #endif
        .effect = EFFECT_TARGET_FLINCH_ON_HIT,
        .power = 30,
        .type = TYPE_GHOST,
        .accuracy = 100,
        .pp = 15,
        .secondaryEffectChance = 30,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 100,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_WEATHER_BALL] =
    {
        .effect = EFFECT_WEATHER_BALL,
        .power = 50,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_BALL_AND_BOMB_MOVE,
        .flags2 = FLAG_WEATHER_RELATED_MOVE | FLAG_SCENT_MARK_AFFECTED,
        .split = SPLIT_SPECIAL,
        .zMovePower = 160,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_AROMATHERAPY] =
    {
        .effect = EFFECT_USER_HEAL_PARTY_STATUS_CONDITION,
        .power = 0,
        .type = TYPE_GRASS,
        .accuracy = 0,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .flags = FLAG_SNATCH_AFFECTED,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_RECOVER_HP,
    },

    [MOVE_FAKE_TEARS] =
    {
        .effect = EFFECT_TARGET_SPECIAL_DEFENSE_DOWN_2,
        .power = 0,
        .type = TYPE_DARK,
        .accuracy = 100,
        .pp = 20,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MAGIC_COAT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        .flags2 = FLAG_EMOTION_MOVE,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_SPATK_UP_1,
    },

    [MOVE_AIR_CUTTER] =
    {
        .power = 70,
        .zMovePower = 140,
        .effect = EFFECT_HIT,
        .type = TYPE_FLYING,
        .accuracy = 100,
        .pp = 20,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_HIGH_CRITICAL_HIT_RATIO,
        .flags2 = FLAG_SLICING_MOVE | FLAG_WIND_MOVE | FLAG_SCENT_MARK_AFFECTED,
        .split = SPLIT_PHYSICAL,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_OVERHEAT] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_6
            .power = 130,
            .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
            .zMovePower = 195,
        #elif B_UPDATED_MOVE_DATA == GEN_4 || B_UPDATED_MOVE_DATA == GEN_5
            .power = 140,
            .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
            .zMovePower = 200,
        #else
            .power = 140,
            .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
            .zMovePower = 200,
        #endif
        .effect = EFFECT_OVERHEAT,
        .type = TYPE_FIRE,
        .accuracy = 90,
        .pp = 5,
        .secondaryEffectChance = 100,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .split = SPLIT_SPECIAL,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_ODOR_SLEUTH] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_5
            .accuracy = 0,
            .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_MAGIC_COAT_AFFECTED,
        #elif B_UPDATED_MOVE_DATA == GEN_4
            .accuracy = 0,
            .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        #else
            .accuracy = 100,
            .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        #endif
        .effect = EFFECT_USER_BYPASS_EVASION_AND_GHOST_TYPE,
        .power = 0,
        .type = TYPE_NORMAL,
        .pp = 40,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_ATK_UP_1,
    },

    [MOVE_ROCK_TOMB] =
    {
        .power = 60,
        .accuracy = 95,
        .pp = 15,
        .zMovePower = 120,
        .effect = EFFECT_TARGET_SPEED_DOWN_1_ON_HIT,
        .type = TYPE_ROCK,
        .secondaryEffectChance = 100,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_HAS_SECONDARY_EFFECT,
        .split = SPLIT_PHYSICAL,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_SILVER_WIND] =
    {
        .effect = EFFECT_ALL_STATS_UP_1_ON_HIT,
        .power = 60,
        .type = TYPE_BUG,
        .accuracy = 100,
        .pp = 5,
        .secondaryEffectChance = 10,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_HAS_SECONDARY_EFFECT,
        .flags2 = FLAG_WIND_MOVE,
        .split = SPLIT_SPECIAL,
        .zMovePower = 120,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_METAL_SOUND] =
    {
        .effect = EFFECT_TARGET_SPECIAL_DEFENSE_DOWN_2,
        .power = 0,
        .type = TYPE_STEEL,
        .accuracy = 85,
        .pp = 40,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MAGIC_COAT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_SOUND_BASED_MOVE,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_SPATK_UP_1,
    },

    [MOVE_GRASS_WHISTLE] =
    {
        .effect = EFFECT_TARGET_SLEEP,
        .power = 0,
        .type = TYPE_GRASS,
        .accuracy = 55,
        .pp = 15,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MAGIC_COAT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_SOUND_BASED_MOVE,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_SPD_UP_1,
    },

    [MOVE_TICKLE] =
    {
        .effect = EFFECT_TICKLE,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 20,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MAGIC_COAT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_DEF_UP_1,
    },

    [MOVE_COSMIC_POWER] =
    {
        .effect = EFFECT_COSMIC_POWER,
        .power = 0,
        .type = TYPE_PSYCHIC,
        .accuracy = 0,
        .pp = 20,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .flags = FLAG_SNATCH_AFFECTED,
        .flags2 = FLAG_COSMIC_ENERGYZED_MOVE,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_SPDEF_UP_1,
    },

    [MOVE_WATER_SPOUT] =
    {
        .effect = EFFECT_ERUPTION,
        .power = 150,
        .type = TYPE_WATER,
        .accuracy = 100,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_BOTH,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        .split = SPLIT_SPECIAL,
        .zMovePower = 200,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_SIGNAL_BEAM] =
    {
        .effect = EFFECT_TARGET_CONFUSE_ON_HIT,
        .power = 75,
        .type = TYPE_BUG,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 30,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_HAS_SECONDARY_EFFECT | FLAG_AURA_BEAM_CANNON_GUN_PULSE_PUMP_SHOT_AND_ZOOKA_MOVE,
        .split = SPLIT_SPECIAL,
        .zMovePower = 140,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_SHADOW_PUNCH] =
    {
        .effect = EFFECT_HIT,
        .power = 80,
        .type = TYPE_GHOST,
        .accuracy = 0,
        .pp = 15,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_PUNCHING_MOVE,
        .flags2 = FLAG_SCENT_MARK_AFFECTED,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 160,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_EXTRASENSORY] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_6
            .pp = 20,
            .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_HAS_SECONDARY_EFFECT,
        #elif B_UPDATED_MOVE_DATA == GEN_4 || B_UPDATED_MOVE_DATA == GEN_5
            .pp = 30,
            .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_HAS_SECONDARY_EFFECT,
        #else
            .pp = 30,
            .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_HAS_SECONDARY_EFFECT | FLAG_DOUBLE_DAMAGE_ON_MINIMIZED_TARGET,
        #endif
        .effect = EFFECT_EXTRASENSORY,
        .power = 80,
        .type = TYPE_PSYCHIC,
        .accuracy = 100,
        .secondaryEffectChance = 10,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .split = SPLIT_SPECIAL,
        .zMovePower = 160,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_SKY_UPPERCUT] =
    {
        .effect = EFFECT_SKY_UPPERCUT,
        .power = 85,
        .type = TYPE_FIGHTING,
        .accuracy = 90,
        .pp = 15,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_PUNCHING_MOVE | FLAG_DAMAGE_ON_FLYING_TARGET,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 160,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_SAND_TOMB] =
    {
        .power = 80,
        .accuracy = 85,
        .effect = EFFECT_TARGET_PREVENT_ESCAPE_AND_HURT_EACH_TURN,
        .type = TYPE_GROUND,
        .pp = 10,
        .secondaryEffectChance = 100,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 100,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_SHEER_COLD] =
    {
        .effect = EFFECT_TARGET_FROSTBITE_ON_HIT,
        .power = 120,
        .type = TYPE_ICE,
        .accuracy = 70,
        .pp = 5,
        .secondaryEffectChance = 30,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        .split = SPLIT_SPECIAL,
        .zMovePower = 190,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_MUDDY_WATER] =
    {
        .power = 90,
        .effect = EFFECT_TARGET_SPEED_DOWN_1_ON_HIT,
        .type = TYPE_GROUND,
        .accuracy = 95,
        .pp = 10,
        .secondaryEffectChance = 30,
        .target = MOVE_TARGET_BOTH,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_HAS_SECONDARY_EFFECT | FLAG_DAMAGE_ON_UNGROUNDED_TARGET,
        .flags2 = FLAG_MUD_MOVE | FLAG_WAVE_SURF_AFFECTED,
        .split = SPLIT_SPECIAL,
        .zMovePower = 175,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_BULLET_SEED] =
    {
        .power = 25,
        .effect = EFFECT_TARGET_MULTI_HIT,
        .type = TYPE_GRASS,
        .accuracy = 100,
        .pp = 30,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_BALL_AND_BOMB_MOVE,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 100,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_AERIAL_ACE] =
    {
        .effect = EFFECT_HIT,
        .power = 60,
        .type = TYPE_FLYING,
        .accuracy = 0,
        .pp = 20,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .flags2 = FLAG_SLICING_MOVE | FLAG_SCENT_MARK_AFFECTED,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 120,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_ICICLE_SPEAR] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_5
            .power = 25,
        #else
            .power = 10,
        #endif
        .effect = EFFECT_TARGET_MULTI_HIT,
        .type = TYPE_ICE,
        .accuracy = 100,
        .pp = 30,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 100,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_IRON_DEFENSE] =
    {
        .effect = EFFECT_USER_DEFENSE_UP_2,
        .power = 0,
        .type = TYPE_STEEL,
        .accuracy = 0,
        .pp = 15,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .flags = FLAG_SNATCH_AFFECTED,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_RESET_STATS,
    },

    [MOVE_BLOCK] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_6
            .flags = FLAG_MAGIC_COAT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        #else
            .flags = FLAG_PROTECT_AFFECTED | FLAG_MAGIC_COAT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        #endif
        .effect = EFFECT_TARGET_PREVENT_ESCAPE,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_DEF_UP_1,
    },

    [MOVE_HOWL] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_8
            .flags = FLAG_SNATCH_AFFECTED | FLAG_SOUND_BASED_MOVE,
        #else
            .flags = FLAG_SNATCH_AFFECTED,
        #endif
        .effect = EFFECT_ATTACK_UP_USER_ALLY,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 40,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_ATK_UP_1,
    },

    [MOVE_DRAGON_CLAW] =
    {
        .effect = EFFECT_HIT,
        .power = 80,
        .type = TYPE_DRAGON,
        .accuracy = 100,
        .pp = 15,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .flags2 = FLAG_SCENT_MARK_AFFECTED,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 160,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_FRENZY_PLANT] =
    {
        .effect = EFFECT_USER_RECHARGE,
        .power = 150,
        .type = TYPE_GRASS,
        .accuracy = 90,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .split = SPLIT_SPECIAL,
        .zMovePower = 200,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_BULK_UP] =
    {
        .effect = EFFECT_USER_ATTACK_DEFENSE_UP_1,
        .power = 0,
        .type = TYPE_FIGHTING,
        .accuracy = 0,
        .pp = 20,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .flags = FLAG_SNATCH_AFFECTED,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_ATK_UP_1,
    },

    [MOVE_BOUNCE] =
    {
        .effect = EFFECT_SEMI_INVULNERABLE,
        .power = 85,
        .type = TYPE_FLYING,
        .accuracy = 95,
        .pp = 5,
        .secondaryEffectChance = 30,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_HAS_SECONDARY_EFFECT,
        .split = SPLIT_PHYSICAL,
        .argument2 = MOVE_EFFECT_PARALYSIS,
        .zMovePower = 160,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_MUD_SHOT] =
    {
        .effect = EFFECT_TARGET_SPEED_DOWN_1_ON_HIT,
        .power = 55,
        .type = TYPE_GROUND,
        .accuracy = 95,
        .pp = 15,
        .secondaryEffectChance = 100,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_HAS_SECONDARY_EFFECT | FLAG_DAMAGE_ON_UNGROUNDED_TARGET | FLAG_AURA_BEAM_CANNON_GUN_PULSE_PUMP_SHOT_AND_ZOOKA_MOVE,
        .flags2 = FLAG_MUD_MOVE | FLAG_SLOTTED_SHELL_MOVE,
        .split = SPLIT_SPECIAL,
        .zMovePower = 100,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_POISON_TAIL] =
    {
        .effect = EFFECT_TARGET_POISON_ON_HIT,
        .power = 100,
        .type = TYPE_POISON,
        .accuracy = 85,
        .pp = 10,
        .secondaryEffectChance = 30,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_HIGH_CRITICAL_HIT_RATIO | FLAG_HAS_SECONDARY_EFFECT,
        .flags2 = FLAG_TAIL_MOVE,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 180,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_COVET] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_6
            .power = 60,
            .pp = 25,
            .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        #elif B_UPDATED_MOVE_DATA == GEN_5
            .power = 60,
            .pp = 40,
            .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        #elif B_UPDATED_MOVE_DATA == GEN_4
            .power = 40,
            .pp = 40,
            .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        #else
            .power = 40,
            .pp = 40,
            .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        #endif
        .effect = EFFECT_USER_STEAL_TARGET_ITEM_ON_HIT,
        .type = TYPE_FAIRY,
        .accuracy = 100,
        .secondaryEffectChance = 100,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 120,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_VOLT_TACKLE] =
    {
        .effect = EFFECT_USER_RECOIL_33_STATUS,
        .argument = MOVE_EFFECT_PARALYSIS,
        .power = 120,
        .type = TYPE_ELECTRIC,
        .accuracy = 100,
        .pp = 15,
        .secondaryEffectChance = 10,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_RECOIL_DAMAGE | FLAG_HAS_SECONDARY_EFFECT,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 190,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_MAGICAL_LEAF] =
    {
        .effect = EFFECT_HIT,
        .power = 60,
        .type = TYPE_GRASS,
        .accuracy = 0,
        .pp = 20,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .flags2 = FLAG_SCENT_MARK_AFFECTED,
        .split = SPLIT_SPECIAL,
        .zMovePower = 120,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_WATER_SPORT] =
    {
        .effect = EFFECT_WATER_SPORT,
        .power = 0,
        .type = TYPE_WATER,
        .accuracy = 100,
        .pp = 15,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_ALL_BATTLERS,
        .priority = 0,
        .flags = 0,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_SPDEF_UP_1,
    },

    [MOVE_CALM_MIND] =
    {
        .effect = EFFECT_USER_SPECIAL_ATTACK_SPECIAL_DEFENSE_UP_1,
        .power = 0,
        .type = TYPE_PSYCHIC,
        .accuracy = 0,
        .pp = 20,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .flags = FLAG_SNATCH_AFFECTED,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_RESET_STATS,
    },

    [MOVE_LEAF_BLADE] =
    {
        .power = 90,
        .zMovePower = 175,
        .effect = EFFECT_HIT,
        .type = TYPE_GRASS,
        .accuracy = 100,
        .pp = 15,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_HIGH_CRITICAL_HIT_RATIO,
        .flags2 = FLAG_SLICING_MOVE | FLAG_SCENT_MARK_AFFECTED,
        .split = SPLIT_PHYSICAL,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_DRAGON_DANCE] =
    {
        .effect = EFFECT_DRAGON_DANCE,
        .power = 0,
        .type = TYPE_DRAGON,
        .accuracy = 0,
        .pp = 20,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .flags = FLAG_SNATCH_AFFECTED | FLAG_DANCING_MOVE,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_RESET_STATS,
    },

    [MOVE_ROCK_BLAST] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_7
            .accuracy = 90,
            .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_BALL_AND_BOMB_MOVE,
        #elif B_UPDATED_MOVE_DATA == GEN_5 || B_UPDATED_MOVE_DATA == GEN_6
            .accuracy = 90,
            .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        #else
            .accuracy = 80,
            .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        #endif
        .effect = EFFECT_TARGET_MULTI_HIT,
        .power = 25,
        .type = TYPE_ROCK,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 100,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_SHOCK_WAVE] =
    {
        .effect = EFFECT_HIT,
        .power = 60,
        .type = TYPE_ELECTRIC,
        .accuracy = 0,
        .pp = 20,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .flags2 = FLAG_SCENT_MARK_AFFECTED,
        .split = SPLIT_SPECIAL,
        .zMovePower = 120,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_WATER_PULSE] =
    {
        .effect = EFFECT_TARGET_CONFUSE_ON_HIT,
        .power = 60,
        .type = TYPE_WATER,
        .accuracy = 100,
        .pp = 20,
        .secondaryEffectChance = 20,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_HAS_SECONDARY_EFFECT | FLAG_AURA_BEAM_CANNON_GUN_PULSE_PUMP_SHOT_AND_ZOOKA_MOVE,
        .split = SPLIT_SPECIAL,
        .zMovePower = 120,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_DOOM_DESIRE] =
    {
        .power = 140,
        .accuracy = 100,
        .zMovePower = 200,
        .effect = EFFECT_FUTURE_SIGHT,
        .type = TYPE_STEEL,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = 0,
        .split = SPLIT_SPECIAL,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_PSYCHO_BOOST] =
    {
        .effect = EFFECT_OVERHEAT,
        .power = 140,
        .type = TYPE_PSYCHIC,
        .accuracy = 90,
        .pp = 5,
        .secondaryEffectChance = 100,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .split = SPLIT_SPECIAL,
        .zMovePower = 200,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_ROOST] =
    {
        .effect = EFFECT_ROOST,
        .power = 0,
        .type = TYPE_FLYING,
        .accuracy = 0,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .flags = FLAG_SNATCH_AFFECTED,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_RESET_STATS,
    },

    [MOVE_GRAVITY] =
    {
        .effect = EFFECT_GRAVITY,
        .power = 0,
        .type = TYPE_PSYCHIC,
        .accuracy = 0,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_ALL_BATTLERS,
        .priority = 0,
        .flags = 0,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_SPATK_UP_1,
    },

    [MOVE_MIRACLE_EYE] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_5
            .flags = FLAG_PROTECT_AFFECTED | FLAG_MAGIC_COAT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        #else
            .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        #endif
        .effect = EFFECT_MIRACLE_EYE,
        .power = 0,
        .type = TYPE_PSYCHIC,
        .accuracy = 0,
        .pp = 40,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_SPATK_UP_1,
    },

    [MOVE_WAKE_UP_SLAP] =
    {
        .power = 70,
        .zMovePower = 140,
        .effect = EFFECT_WAKE_UP_SLAP,
        .type = TYPE_FIGHTING,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 100,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
        .argument = STATUS1_SLEEP,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_HAMMER_ARM] =
    {
        .effect = EFFECT_USER_SPEED_DOWN_1_ON_HIT,
        .power = 100,
        .type = TYPE_FIGHTING,
        .accuracy = 90,
        .pp = 10,
        .secondaryEffectChance = 100,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_PUNCHING_MOVE,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 180,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_GYRO_BALL] =
    {
        .effect = EFFECT_GYRO_BALL,
        .power = 1,
        .type = TYPE_STEEL,
        .accuracy = 100,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_BALL_AND_BOMB_MOVE,
        .flags2 = FLAG_SCENT_MARK_AFFECTED,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 160,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_HEALING_WISH] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_5
            .flags = FLAG_SNATCH_AFFECTED,
        #else
            .flags = 0,
        #endif
        .effect = EFFECT_USER_FAINT_NEXT_MON_RESTORE_FULL_HP,
        .power = 0,
        .type = TYPE_PSYCHIC,
        .accuracy = 0,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_BRINE] =
    {
        .effect = EFFECT_BRINE,
        .power = 65,
        .type = TYPE_WATER,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .flags2 = FLAG_SCENT_MARK_AFFECTED,
        .split = SPLIT_SPECIAL,
        .zMovePower = 120,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_NATURAL_GIFT] =
    {
        .effect = EFFECT_NATURAL_GIFT,
        .power = 1,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 15,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 160,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_FEINT] =
    {
        .power = 30,
        .flags = FLAG_MIRROR_MOVE_AFFECTED,
        .effect = EFFECT_TARGET_REMOVE_PROTECTION_ON_HIT,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 100,
        .target = MOVE_TARGET_SELECTED,
        .priority = 2,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 100,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_PLUCK] =
    {
        .effect = EFFECT_BUG_BITE,
        .power = 60,
        .type = TYPE_FLYING,
        .accuracy = 100,
        .pp = 20,
        .secondaryEffectChance = 100,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 120,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_TAILWIND] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_6
            .pp = 15,
        #else
            .pp = 30,
        #endif
        .effect = EFFECT_TAILWIND,
        .power = 0,
        .type = TYPE_FLYING,
        .accuracy = 0,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .flags = FLAG_SNATCH_AFFECTED,
        .flags2 = FLAG_WIND_MOVE,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_BOOST_CRITS,
    },

    [MOVE_ACUPRESSURE] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_5
            .flags = 0,
        #else
            .flags = FLAG_SNATCH_AFFECTED,
        #endif
        .effect = EFFECT_ACUPRESSURE,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 30,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_USER | MOVE_TARGET_ALLY,
        .priority = 0,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_BOOST_CRITS,
    },

    [MOVE_METAL_BURST] =
    {
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        .effect = EFFECT_METAL_BURST,
        .power = 1,
        .type = TYPE_STEEL,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_DEPENDS,
        .priority = 0,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_U_TURN] =
    {
        .effect = EFFECT_USER_FORCED_SWITCH_OUT_ON_HIT,
        .power = 70,
        .type = TYPE_BUG,
        .accuracy = 100,
        .pp = 20,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 140,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_CLOSE_COMBAT] =
    {
        .effect = EFFECT_CLOSE_COMBAT,
        .power = 120,
        .type = TYPE_FIGHTING,
        .accuracy = 100,
        .pp = 5,
        .secondaryEffectChance = 100,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 190,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_PAYBACK] =
    {
        .effect = EFFECT_PAYBACK,
        .power = 50,
        .type = TYPE_DARK,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .flags2 = FLAG_SCENT_MARK_AFFECTED,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 100,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_ASSURANCE] =
    {
        .power = 60,
        .zMovePower = 120,
        .effect = EFFECT_ASSURANCE,
        .type = TYPE_DARK,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .flags2 = FLAG_SCENT_MARK_AFFECTED,
        .split = SPLIT_PHYSICAL,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_EMBARGO] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_5
            .flags = FLAG_PROTECT_AFFECTED | FLAG_MAGIC_COAT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        #else
            .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        #endif
        .effect = EFFECT_EMBARGO,
        .power = 0,
        .type = TYPE_DARK,
        .accuracy = 100,
        .pp = 15,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_SPATK_UP_1,
    },

    [MOVE_FLING] =
    {
        .effect = EFFECT_FLING,
        .power = 1,
        .type = TYPE_DARK,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 100,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_PSYCHO_SHIFT] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_6
            .accuracy = 100,
        #else
            .accuracy = 90,
        #endif
        .effect = EFFECT_PSYCHO_SHIFT,
        .power = 0,
        .type = TYPE_PSYCHIC,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_SPATK_UP_2,
    },

    [MOVE_TRUMP_CARD] =
    {
        .effect = EFFECT_TRUMP_CARD,
        .power = 1,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .flags2 = FLAG_SCENT_MARK_AFFECTED,
        .split = SPLIT_SPECIAL,
        .zMovePower = 100,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_HEAL_BLOCK] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_5
            .flags = FLAG_PROTECT_AFFECTED | FLAG_MAGIC_COAT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        #else
            .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        #endif
        .effect = EFFECT_TARGET_HEAL_BLOCK,
        .power = 0,
        .type = TYPE_PSYCHIC,
        .accuracy = 100,
        .pp = 15,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_SPATK_UP_2,
    },

    [MOVE_WRING_OUT] =
    {
        .effect = EFFECT_WRING_OUT,
        .power = 1,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .flags2 = FLAG_SCENT_MARK_AFFECTED,
        .split = SPLIT_SPECIAL,
    },

    [MOVE_POWER_TRICK] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_5
            .flags = FLAG_SNATCH_AFFECTED,
        #else
            .flags = 0,
        #endif
        .effect = EFFECT_POWER_TRICK,
        .power = 0,
        .type = TYPE_PSYCHIC,
        .accuracy = 0,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_ATK_UP_1,
    },

    [MOVE_GASTRO_ACID] =
    {
        .effect = EFFECT_GASTRO_ACID,
        .power = 0,
        .type = TYPE_POISON,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MAGIC_COAT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        .flags2 = FLAG_ACID_MOVE,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_SPD_UP_1,
    },

    [MOVE_LUCKY_CHANT] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_5
            .flags = FLAG_SNATCH_AFFECTED,
        #else
            .flags = 0,
        #endif
        .effect = EFFECT_LUCKY_CHANT,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 30,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_EVSN_UP_1,
    },

    [MOVE_ME_FIRST] =
    {
        .effect = EFFECT_ME_FIRST,
        .power = 1,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 20,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_SPD_UP_2,
    },

    [MOVE_COPYCAT] =
    {
        .effect = EFFECT_COPYCAT,
        .power = 1,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 20,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_DEPENDS,
        .priority = 0,
        .flags = 0,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_ACC_UP_1,
    },

    [MOVE_POWER_SWAP] =
    {
        .effect = EFFECT_POWER_SWAP,
        .power = 0,
        .type = TYPE_PSYCHIC,
        .accuracy = 0,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_SPD_UP_1,
    },

    [MOVE_GUARD_SWAP] =
    {
        .effect = EFFECT_GUARD_SWAP,
        .power = 0,
        .type = TYPE_PSYCHIC,
        .accuracy = 0,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_SPD_UP_1,
    },

    [MOVE_PUNISHMENT] =
    {
        .effect = EFFECT_PUNISHMENT,
        .power = 60,
        .type = TYPE_DARK,
        .accuracy = 100,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .flags2 = FLAG_SCENT_MARK_AFFECTED,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 120,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_LAST_RESORT] =
    {
        .power = 140,
        .zMovePower = 200,
        .effect = EFFECT_LAST_RESORT,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_WORRY_SEED] =
    {
        .effect = EFFECT_WORRY_SEED,
        .power = 0,
        .type = TYPE_GRASS,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MAGIC_COAT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_SPD_UP_1,
    },

    [MOVE_SUCKER_PUNCH] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_7
            .power = 70,
            .zMovePower = 140,
        #else
            .power = 80,
            .zMovePower = 160,
        #endif
        .effect = EFFECT_SUCKER_PUNCH,
        .type = TYPE_DARK,
        .accuracy = 100,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 1,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_PUNCHING_MOVE,
        .split = SPLIT_PHYSICAL,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_TOXIC_SPIKES] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_5
            .flags = FLAG_MAGIC_COAT_AFFECTED,
        #else
            .flags = 0,
        #endif
        .effect = EFFECT_TOXIC_SPIKES,
        .power = 0,
        .type = TYPE_POISON,
        .accuracy = 0,
        .pp = 20,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_OPPONENTS_FIELD,
        .priority = 0,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_DEF_UP_1,
    },

    [MOVE_HEART_SWAP] =
    {
        .effect = EFFECT_HEART_SWAP,
        .power = 0,
        .type = TYPE_PSYCHIC,
        .accuracy = 0,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_BOOST_CRITS,
    },

    [MOVE_AQUA_RING] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_5
            .flags = FLAG_SNATCH_AFFECTED,
        #else
            .flags = 0,
        #endif
        .effect = EFFECT_AQUA_RING,
        .power = 0,
        .type = TYPE_WATER,
        .accuracy = 0,
        .pp = 20,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_DEF_UP_1,
    },

    [MOVE_MAGNET_RISE] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_5
            .flags = FLAG_SNATCH_AFFECTED,
        #else
            .flags = 0,
        #endif
        .effect = EFFECT_MAGNET_RISE,
        .power = 0,
        .type = TYPE_ELECTRIC,
        .accuracy = 0,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_USER,
        .priority = 1,
        .flags2 = FLAG_MAGNET_MOVE,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_EVSN_UP_1,
    },

    [MOVE_FLARE_BLITZ] =
    {
        .effect = EFFECT_USER_RECOIL_33_STATUS,
        .power = 120,
        .type = TYPE_FIRE,
        .accuracy = 100,
        .pp = 15,
        .secondaryEffectChance = 10,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_HAS_SECONDARY_EFFECT | FLAG_RECOIL_DAMAGE | FLAG_THAW_USER,
        .split = SPLIT_PHYSICAL,
        .argument = MOVE_EFFECT_BURN,
        .zMovePower = 190,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_FORCE_PALM] =
    {
        .effect = EFFECT_TARGET_PARALYZE_ON_HIT,
        .power = 60,
        .type = TYPE_FIGHTING,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 30,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_HAS_SECONDARY_EFFECT,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 120,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_AURA_SPHERE] =
    {
        .power = 80,
        .zMovePower = 160,
        .effect = EFFECT_HIT,
        .type = TYPE_FIGHTING,
        .accuracy = 0,
        .pp = 20,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_AURA_BEAM_CANNON_GUN_PULSE_PUMP_SHOT_AND_ZOOKA_MOVE | FLAG_BALL_AND_BOMB_MOVE,
        .flags2 = FLAG_SCENT_MARK_AFFECTED,
        .split = SPLIT_SPECIAL,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_ROCK_POLISH] =
    {
        .effect = EFFECT_ROCK_POLISH,
        .power = 0,
        .type = TYPE_ROCK,
        .accuracy = 0,
        .pp = 20,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .flags = FLAG_SNATCH_AFFECTED,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_RESET_STATS,
    },

    [MOVE_POISON_JAB] =
    {
        .effect = EFFECT_TARGET_POISON_ON_HIT,
        .power = 80,
        .type = TYPE_POISON,
        .accuracy = 100,
        .pp = 20,
        .secondaryEffectChance = 30,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_HAS_SECONDARY_EFFECT,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 160,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_DARK_PULSE] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_5
            .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_HAS_SECONDARY_EFFECT | FLAG_AURA_BEAM_CANNON_GUN_PULSE_PUMP_SHOT_AND_ZOOKA_MOVE,
        #else
            .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_HAS_SECONDARY_EFFECT | FLAG_AURA_BEAM_CANNON_GUN_PULSE_PUMP_SHOT_AND_ZOOKA_MOVE,
        #endif
        .effect = EFFECT_TARGET_FLINCH_ON_HIT,
        .power = 80,
        .type = TYPE_DARK,
        .accuracy = 100,
        .pp = 15,
        .secondaryEffectChance = 20,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .split = SPLIT_SPECIAL,
        .zMovePower = 160,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_NIGHT_SLASH] =
    {
        .effect = EFFECT_HIT,
        .power = 70,
        .type = TYPE_DARK,
        .accuracy = 100,
        .pp = 15,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_HIGH_CRITICAL_HIT_RATIO,
        .flags2 = FLAG_SLICING_MOVE | FLAG_SCENT_MARK_AFFECTED,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 140,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_AQUA_TAIL] =
    {
        .effect = EFFECT_HIT,
        .power = 90,
        .type = TYPE_WATER,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .flags2 = FLAG_TAIL_MOVE | FLAG_SCENT_MARK_AFFECTED,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 175,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_SEED_BOMB] =
    {
        .effect = EFFECT_HIT,
        .power = 80,
        .type = TYPE_GRASS,
        .accuracy = 100,
        .pp = 15,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_BALL_AND_BOMB_MOVE,
        .flags2 = FLAG_SCENT_MARK_AFFECTED,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 160,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_AIR_SLASH] =
    {
        .pp = 15,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_HAS_SECONDARY_EFFECT,
        .flags2 = FLAG_WIND_MOVE | FLAG_SLICING_MOVE,
        .effect = EFFECT_TARGET_FLINCH_ON_HIT,
        .power = 75,
        .type = TYPE_FLYING,
        .accuracy = 95,
        .secondaryEffectChance = 30,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .split = SPLIT_SPECIAL,
        .zMovePower = 140,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_X_SCISSOR] =
    {
        .effect = EFFECT_HIT,
        .power = 80,
        .type = TYPE_BUG,
        .accuracy = 100,
        .pp = 15,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .flags2 = FLAG_SLICING_MOVE | FLAG_SCENT_MARK_AFFECTED,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 160,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_BUG_BUZZ] =
    {
        .effect = EFFECT_TARGET_SPECIAL_DEFENSE_DOWN_1_ON_HIT,
        .power = 90,
        .type = TYPE_BUG,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 10,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_SOUND_BASED_MOVE | FLAG_HAS_SECONDARY_EFFECT,
        .split = SPLIT_SPECIAL,
        .zMovePower = 175,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_DRAGON_PULSE] =
    {
        .power = 85,
        .zMovePower = 160,
        .effect = EFFECT_HIT,
        .type = TYPE_DRAGON,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_AURA_BEAM_CANNON_GUN_PULSE_PUMP_SHOT_AND_ZOOKA_MOVE,
        .flags2 = FLAG_SCENT_MARK_AFFECTED,
        .split = SPLIT_SPECIAL,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_DRAGON_RUSH] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_6
            .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_HAS_SECONDARY_EFFECT | FLAG_DOUBLE_DAMAGE_ON_MINIMIZED_TARGET,
        #elif B_UPDATED_MOVE_DATA == GEN_5
            .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_HAS_SECONDARY_EFFECT,
        #else
            .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_HAS_SECONDARY_EFFECT,
        #endif
        .effect = EFFECT_TARGET_FLINCH_ON_HIT,
        .power = 100,
        .type = TYPE_DRAGON,
        .accuracy = 85,
        .pp = 10,
        .secondaryEffectChance = 20,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 180,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_POWER_GEM] =
    {
        .power = 80,
        .zMovePower = 160,
        .effect = EFFECT_POWER_GEM,
        .type = TYPE_ROCK,
        .accuracy = 100,
        .pp = 20,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .flags2 = FLAG_SCENT_MARK_AFFECTED,
        .split = SPLIT_SPECIAL,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_DRAIN_PUNCH] =
    {
        .power = 75,
        .pp = 10,
        .zMovePower = 140,
        .effect = EFFECT_USER_DRAIN_50_ON_HIT,
        .type = TYPE_FIGHTING,
        .accuracy = 100,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_PUNCHING_MOVE,
        .split = SPLIT_PHYSICAL,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_VACUUM_WAVE] =
    {
        .effect = EFFECT_VACUUM_WAVE,
        .power = 70,
        .type = TYPE_FIGHTING,
        .accuracy = 100,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 1,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_PUNCHING_MOVE,
        .flags2 = FLAG_SCENT_MARK_AFFECTED,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 140,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_FOCUS_BLAST] =
    {
        .effect = EFFECT_TARGET_SPECIAL_DEFENSE_DOWN_1_ON_HIT,
        .power = 120,
        .type = TYPE_FIGHTING,
        .accuracy = 70,
        .pp = 5,
        .secondaryEffectChance = 10,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_HAS_SECONDARY_EFFECT | FLAG_BALL_AND_BOMB_MOVE,
        .split = SPLIT_SPECIAL,
        .zMovePower = 190,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_ENERGY_BALL] =
    {
        .power = 90,
        .zMovePower = 175,
        .effect = EFFECT_TARGET_SPECIAL_DEFENSE_DOWN_1_ON_HIT,
        .type = TYPE_GRASS,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 10,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_BALL_AND_BOMB_MOVE | FLAG_HAS_SECONDARY_EFFECT,
        .split = SPLIT_SPECIAL,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_BRAVE_BIRD] =
    {
        .effect = EFFECT_USER_RECOIL_33,
        .power = 120,
        .type = TYPE_FLYING,
        .accuracy = 100,
        .pp = 15,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_RECOIL_DAMAGE,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 190,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_EARTH_POWER] =
    {
        .effect = EFFECT_TARGET_SPECIAL_DEFENSE_DOWN_1_ON_HIT,
        .power = 90,
        .type = TYPE_GROUND,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 10,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_HAS_SECONDARY_EFFECT,
        .split = SPLIT_SPECIAL,
        .zMovePower = 175,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_SWITCHEROO] =
    {
        .effect = EFFECT_TRICK,
        .power = 0,
        .type = TYPE_DARK,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_SPD_UP_2,
    },

    [MOVE_GIGA_IMPACT] =
    {
        .effect = EFFECT_USER_RECHARGE,
        .power = 150,
        .type = TYPE_NORMAL,
        .accuracy = 90,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 200,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_NASTY_PLOT] =
    {
        .effect = EFFECT_USER_SPECIAL_ATTACK_UP_2,
        .power = 0,
        .type = TYPE_DARK,
        .accuracy = 0,
        .pp = 20,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .flags = FLAG_SNATCH_AFFECTED,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_RESET_STATS,
    },

    [MOVE_BULLET_PUNCH] =
    {
        .effect = EFFECT_HIT,
        .power = 40,
        .type = TYPE_STEEL,
        .accuracy = 100,
        .pp = 30,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 1,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_PUNCHING_MOVE,
        .flags2 = FLAG_SCENT_MARK_AFFECTED,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 100,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_AVALANCHE] =
    {
        .effect = EFFECT_REVENGE,
        .power = 60,
        .type = TYPE_ICE,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_BOTH,
        .priority = -4,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 120,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_ICE_SHARD] =
    {
        .effect = EFFECT_HIT,
        .power = 40,
        .type = TYPE_ICE,
        .accuracy = 100,
        .pp = 30,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 1,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .flags2 = FLAG_SCENT_MARK_AFFECTED,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 100,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_SHADOW_CLAW] =
    {
        .effect = EFFECT_HIT,
        .power = 70,
        .type = TYPE_GHOST,
        .accuracy = 100,
        .pp = 15,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_HIGH_CRITICAL_HIT_RATIO,
        .flags2 = FLAG_SCENT_MARK_AFFECTED,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 140,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_THUNDER_FANG] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_5
            .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_HAS_SECONDARY_EFFECT | FLAG_BITING_MOVE,
            .flags2 = FLAG_FANG_MOVE,
        #else
            .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_HAS_SECONDARY_EFFECT | FLAG_BITING_MOVE,
        #endif
        .effect = EFFECT_FLINCH_STATUS,
        .power = 65,
        .type = TYPE_ELECTRIC,
        .accuracy = 95,
        .pp = 15,
        .secondaryEffectChance = 10,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .split = SPLIT_PHYSICAL,
        .argument = MOVE_EFFECT_PARALYSIS,
        .zMovePower = 120,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_ICE_FANG] =
    {
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_HAS_SECONDARY_EFFECT | FLAG_BITING_MOVE,
        .flags2 = FLAG_FANG_MOVE,
        .effect = EFFECT_FLINCH_STATUS,
        .power = 65,
        .type = TYPE_ICE,
        .accuracy = 95,
        .pp = 15,
        .secondaryEffectChance = 10,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .split = SPLIT_PHYSICAL,
        .argument = MOVE_EFFECT_FROSTBITE,
        .zMovePower = 120,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_FIRE_FANG] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_5
            .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_HAS_SECONDARY_EFFECT | FLAG_BITING_MOVE,
            .flags2 = FLAG_FANG_MOVE,
        #else
            .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_HAS_SECONDARY_EFFECT | FLAG_BITING_MOVE,
        #endif
        .effect = EFFECT_FLINCH_STATUS,
        .power = 65,
        .type = TYPE_FIRE,
        .accuracy = 95,
        .pp = 15,
        .secondaryEffectChance = 10,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .split = SPLIT_PHYSICAL,
        .argument = MOVE_EFFECT_BURN,
        .zMovePower = 120,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_SHADOW_SNEAK] =
    {
        .effect = EFFECT_HIT,
        .power = 40,
        .type = TYPE_GHOST,
        .accuracy = 100,
        .pp = 30,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 1,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .flags2 = FLAG_SCENT_MARK_AFFECTED,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 100,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_MUD_BOMB] =
    {
        .effect = EFFECT_TARGET_ACCURACY_DOWN_1_ON_HIT,
        .power = 65,
        .type = TYPE_GROUND,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 30,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_HAS_SECONDARY_EFFECT | FLAG_BALL_AND_BOMB_MOVE | FLAG_DAMAGE_ON_UNGROUNDED_TARGET,
        .flags2 = FLAG_MUD_MOVE,
        .split = SPLIT_SPECIAL,
        .zMovePower = 120,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_PSYCHO_CUT] =
    {
        .effect = EFFECT_HIT,
        .power = 70,
        .type = TYPE_PSYCHIC,
        .accuracy = 100,
        .pp = 20,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_HIGH_CRITICAL_HIT_RATIO,
        .flags2 = FLAG_SLICING_MOVE | FLAG_SCENT_MARK_AFFECTED,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 140,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_ZEN_HEADBUTT] =
    {
        .effect = EFFECT_TARGET_FLINCH_ON_HIT,
        .power = 80,
        .type = TYPE_PSYCHIC,
        .accuracy = 90,
        .pp = 15,
        .secondaryEffectChance = 20,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_HAS_SECONDARY_EFFECT,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 160,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_MIRROR_SHOT] =
    {
        .effect = EFFECT_TARGET_ACCURACY_DOWN_1_ON_HIT,
        .power = 65,
        .type = TYPE_STEEL,
        .accuracy = 85,
        .pp = 10,
        .secondaryEffectChance = 30,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_HAS_SECONDARY_EFFECT | FLAG_AURA_BEAM_CANNON_GUN_PULSE_PUMP_SHOT_AND_ZOOKA_MOVE,
        .flags2 = FLAG_SLOTTED_SHELL_MOVE,
        .split = SPLIT_SPECIAL,
        .zMovePower = 120,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_FLASH_CANNON] =
    {
        .effect = EFFECT_TARGET_SPECIAL_DEFENSE_DOWN_1_ON_HIT,
        .power = 80,
        .type = TYPE_STEEL,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 10,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_HAS_SECONDARY_EFFECT | FLAG_AURA_BEAM_CANNON_GUN_PULSE_PUMP_SHOT_AND_ZOOKA_MOVE,
        .split = SPLIT_SPECIAL,
        .zMovePower = 160,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_ROCK_CLIMB] =
    {
        .effect = EFFECT_TARGET_CONFUSE_ON_HIT,
        .power = 90,
        .type = TYPE_ROCK,
        .accuracy = 95,
        .pp = 10,
        .secondaryEffectChance = 20,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_HAS_SECONDARY_EFFECT,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 175,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_DEFOG] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_5
            .flags = FLAG_PROTECT_AFFECTED | FLAG_MAGIC_COAT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        #else
            .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        #endif
        .effect = EFFECT_DEFOG,
        .power = 0,
        .type = TYPE_FLYING,
        .accuracy = 0,
        .pp = 15,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_ACC_UP_1,
    },

    [MOVE_TRICK_ROOM] =
    {
        .effect = EFFECT_TRICK_ROOM,
        .power = 0,
        .type = TYPE_PSYCHIC,
        .accuracy = 0,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_ALL_BATTLERS,
        .priority = -7,
        .flags = FLAG_MIRROR_MOVE_AFFECTED,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_ACC_UP_1,
    },

    [MOVE_DRACO_METEOR] =
    {
        .power = 130,
        .zMovePower = 195,
        .effect = EFFECT_OVERHEAT,
        .type = TYPE_DRAGON,
        .accuracy = 90,
        .pp = 5,
        .secondaryEffectChance = 100,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .split = SPLIT_SPECIAL,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_DISCHARGE] =
    {
        .effect = EFFECT_TARGET_PARALYZE_ON_HIT,
        .power = 80,
        .type = TYPE_ELECTRIC,
        .accuracy = 100,
        .pp = 15,
        .secondaryEffectChance = 30,
        .target = MOVE_TARGET_FOES_AND_ALLY,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_HAS_SECONDARY_EFFECT,
        .split = SPLIT_SPECIAL,
        .zMovePower = 160,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_LAVA_PLUME] =
    {
        .effect = EFFECT_TARGET_BURN_ON_HIT,
        .power = 80,
        .type = TYPE_FIRE,
        .accuracy = 100,
        .pp = 15,
        .secondaryEffectChance = 30,
        .target = MOVE_TARGET_FOES_AND_ALLY,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_HAS_SECONDARY_EFFECT,
        .split = SPLIT_SPECIAL,
        .zMovePower = 160,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_LEAF_STORM] =
    {
        .power = 130,
        .zMovePower = 195,
        .effect = EFFECT_OVERHEAT,
        .type = TYPE_GRASS,
        .accuracy = 90,
        .pp = 5,
        .secondaryEffectChance = 100,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .flags2 = FLAG_WIND_MOVE,
        .split = SPLIT_SPECIAL,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_POWER_WHIP] =
    {
        .effect = EFFECT_HIT,
        .power = 120,
        .type = TYPE_GRASS,
        .accuracy = 85,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .flags2 = FLAG_SCENT_MARK_AFFECTED,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 190,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_ROCK_WRECKER] =
    {
        .effect = EFFECT_USER_RECHARGE,
        .power = 150,
        .type = TYPE_ROCK,
        .accuracy = 90,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_BALL_AND_BOMB_MOVE,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 200,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_CROSS_POISON] =
    {
        .effect = EFFECT_TARGET_DOUBLE_HIT_AND_POISON_ON_HIT,
        .power = 35,
        .type = TYPE_POISON,
        .accuracy = 100,
        .pp = 20,
        .secondaryEffectChance = 10,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_HIGH_CRITICAL_HIT_RATIO | FLAG_HAS_SECONDARY_EFFECT,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 140,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_GUNK_SHOT] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_6
            .accuracy = 80,
        #else
            .accuracy = 70,
        #endif
        .effect = EFFECT_TARGET_POISON_ON_HIT,
        .power = 120,
        .type = TYPE_POISON,
        .pp = 5,
        .secondaryEffectChance = 30,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_HAS_SECONDARY_EFFECT | FLAG_AURA_BEAM_CANNON_GUN_PULSE_PUMP_SHOT_AND_ZOOKA_MOVE,
        .flags2 = FLAG_SLOTTED_SHELL_MOVE,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 190,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_IRON_HEAD] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_5
            .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_HAS_SECONDARY_EFFECT,
        #else
            .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_HAS_SECONDARY_EFFECT,
        #endif
        .effect = EFFECT_TARGET_FLINCH_ON_HIT,
        .power = 80,
        .type = TYPE_STEEL,
        .accuracy = 100,
        .pp = 15,
        .secondaryEffectChance = 30,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 160,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_MAGNET_BOMB] =
    {
        .effect = EFFECT_HIT,
        .power = 60,
        .type = TYPE_STEEL,
        .accuracy = 0,
        .pp = 20,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_BALL_AND_BOMB_MOVE,
        .flags2 = FLAG_MAGNET_MOVE | FLAG_SCENT_MARK_AFFECTED,
        .split = SPLIT_SPECIAL,
        .zMovePower = 120,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_STONE_EDGE] =
    {
        .effect = EFFECT_HIT,
        .power = 100,
        .type = TYPE_ROCK,
        .accuracy = 80,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_HIGH_CRITICAL_HIT_RATIO,
        .flags2 = FLAG_SCENT_MARK_AFFECTED,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 180,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_CAPTIVATE] =
    {
        .effect = EFFECT_OPPOSITE_GENDER_SPECIAL_ATTACK_DOWN_2,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 20,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_BOTH,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MAGIC_COAT_AFFECTED,
        .flags2 = FLAG_EMOTION_MOVE,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_SPDEF_UP_2,
    },

    [MOVE_STEALTH_ROCK] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_5
            .flags = FLAG_MAGIC_COAT_AFFECTED,
        #else
            .flags = 0,
        #endif
        .effect = EFFECT_STEALTH_ROCK,
        .power = 0,
        .type = TYPE_ROCK,
        .accuracy = 0,
        .pp = 20,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_OPPONENTS_FIELD,
        .priority = 0,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_DEF_UP_1,
    },

    [MOVE_GRASS_KNOT] =
    {
        .effect = EFFECT_LOW_KICK,
        .power = 1,
        .type = TYPE_GRASS,
        .accuracy = 100,
        .pp = 20,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .flags2 = FLAG_SCENT_MARK_AFFECTED,
        .split = SPLIT_SPECIAL,
        .zMovePower = 160,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_CHATTER] =
    {
        .power = 65,
        .secondaryEffectChance = 100,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_SOUND_BASED_MOVE | FLAG_HAS_SECONDARY_EFFECT,
        .effect = EFFECT_TARGET_CONFUSE_ON_HIT,
        .type = TYPE_FLYING,
        .accuracy = 100,
        .pp = 20,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .split = SPLIT_SPECIAL,
        .zMovePower = 120,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_JUDGMENT] =
    {
        .effect = EFFECT_JUDGMENT,
        .power = 100,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .split = SPLIT_SPECIAL,
        .argument = HOLD_EFFECT_PLATE,
        .argument2 = EQUIP_SLOT_1,
        .zMovePower = 180,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_BUG_BITE] =
    {
        .effect = EFFECT_BUG_BITE,
        .power = 75,
        .type = TYPE_BUG,
        .accuracy = 100,
        .pp = 15,
        .secondaryEffectChance = 100,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_BITING_MOVE,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 140,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_CHARGE_BEAM] =
    {
        .effect = EFFECT_USER_SPECIAL_ATTACK_UP_1_ON_HIT,
        .power = 50,
        .type = TYPE_ELECTRIC,
        .accuracy = 100,
        .pp = 20,
        .secondaryEffectChance = 100,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_HAS_SECONDARY_EFFECT | FLAG_AURA_BEAM_CANNON_GUN_PULSE_PUMP_SHOT_AND_ZOOKA_MOVE,
        .split = SPLIT_SPECIAL,
        .zMovePower = 100,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_WOOD_HAMMER] =
    {
        .effect = EFFECT_USER_RECOIL_33,
        .power = 120,
        .type = TYPE_GRASS,
        .accuracy = 100,
        .pp = 15,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_RECOIL_DAMAGE,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 190,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_AQUA_JET] =
    {
        .effect = EFFECT_HIT,
        .power = 40,
        .type = TYPE_WATER,
        .accuracy = 100,
        .pp = 20,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 1,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .flags2 = FLAG_SCENT_MARK_AFFECTED,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 100,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_ATTACK_ORDER] =
    {
        .effect = EFFECT_HIT,
        .power = 90,
        .type = TYPE_BUG,
        .accuracy = 100,
        .pp = 15,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_HIGH_CRITICAL_HIT_RATIO,
        .flags2 = FLAG_SCENT_MARK_AFFECTED,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 175,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_DEFEND_ORDER] =
    {
        .effect = EFFECT_COSMIC_POWER,
        .power = 0,
        .type = TYPE_BUG,
        .accuracy = 0,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .flags = FLAG_SNATCH_AFFECTED,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_DEF_UP_1,
    },

    [MOVE_HEAL_ORDER] =
    {
        .effect = EFFECT_USER_RESTORE_50_HP,
        .power = 0,
        .type = TYPE_BUG,
        .accuracy = 0,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .flags = FLAG_SNATCH_AFFECTED,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_RESET_STATS,
    },

    [MOVE_HEAD_SMASH] =
    {
        .effect = EFFECT_USER_RECOIL_50,
        .power = 150,
        .type = TYPE_ROCK,
        .accuracy = 80,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_RECOIL_DAMAGE,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 200,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_DOUBLE_HIT] =
    {
        .effect = EFFECT_TARGET_DOUBLE_HIT,
        .power = 35,
        .type = TYPE_NORMAL,
        .accuracy = 90,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_TWO_STRIKES,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 100,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_ROAR_OF_TIME] =
    {
        .effect = EFFECT_USER_RECHARGE,
        .power = 150,
        .type = TYPE_DRAGON,
        .accuracy = 90,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .split = SPLIT_SPECIAL,
        .zMovePower = 200,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_SPACIAL_REND] =
    {
        .effect = EFFECT_HIT,
        .power = 100,
        .type = TYPE_DRAGON,
        .accuracy = 95,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_HIGH_CRITICAL_HIT_RATIO,
        .flags2 = FLAG_SCENT_MARK_AFFECTED | FLAG_ALWAYS_CRITICAL_HIT,
        .split = SPLIT_SPECIAL,
        .zMovePower = 180,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_LUNAR_DANCE] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_5
            .flags = FLAG_DANCING_MOVE | FLAG_SNATCH_AFFECTED,
        #else
            .flags = FLAG_DANCING_MOVE,
        #endif
        .effect = EFFECT_USER_FAINT_NEXT_MON_RESTORE_FULL_HP,
        .power = 0,
        .type = TYPE_PSYCHIC,
        .accuracy = 0,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_CRUSH_GRIP] =
    {
        .effect = EFFECT_WRING_OUT,
        .power = 1,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .flags2 = FLAG_SCENT_MARK_AFFECTED,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 190,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_MAGMA_STORM] =
    {
        .power = 100,
        .accuracy = 90,
        .zMovePower = 180,
        .effect = EFFECT_TARGET_PREVENT_ESCAPE_AND_HURT_EACH_TURN,
        .type = TYPE_FIRE,
        .pp = 5,
        .secondaryEffectChance = 100,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .split = SPLIT_SPECIAL,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_DARK_VOID] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_7
            .accuracy = 50,
        #else
            .accuracy = 80,
        #endif
        .effect = EFFECT_DARK_VOID,
        .power = 0,
        .type = TYPE_DARK,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_BOTH,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MAGIC_COAT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_RESET_STATS,
    },

    [MOVE_SEED_FLARE] =
    {
        .effect = EFFECT_TARGET_SPECIAL_DEFENSE_DOWN_2_ON_HIT,
        .power = 120,
        .type = TYPE_GRASS,
        .accuracy = 85,
        .pp = 5,
        .secondaryEffectChance = 40,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_HAS_SECONDARY_EFFECT,
        .split = SPLIT_SPECIAL,
        .zMovePower = 190,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_OMINOUS_WIND] =
    {
        .effect = EFFECT_ALL_STATS_UP_1_ON_HIT,
        .power = 60,
        .type = TYPE_GHOST,
        .accuracy = 100,
        .pp = 5,
        .secondaryEffectChance = 10,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_HAS_SECONDARY_EFFECT,
        .flags2 = FLAG_WIND_MOVE,
        .split = SPLIT_SPECIAL,
        .zMovePower = 120,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_SHADOW_FORCE] =
    {
        .flags = FLAG_MAKES_CONTACT | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_DOUBLE_DAMAGE_ON_MINIMIZED_TARGET,
        .effect = EFFECT_SEMI_INVULNERABLE,
        .power = 120,
        .type = TYPE_GHOST,
        .accuracy = 100,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 190,
        .zMoveEffect = Z_EFFECT_NONE,
        .argument2 = MOVE_EFFECT_FEINT,
    },

    [MOVE_HONE_CLAWS] =
    {
        .effect = EFFECT_USER_ATTACK_ACCURACY_UP_1,
        .power = 0,
        .type = TYPE_DARK,
        .accuracy = 0,
        .pp = 15,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .flags = FLAG_SNATCH_AFFECTED,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_ATK_UP_1,
    },

    [MOVE_WIDE_GUARD] =
    {
        .effect = EFFECT_USER_PREVENT_MOVE,
        .power = 0,
        .type = TYPE_ROCK,
        .accuracy = 0,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_USER,
        .priority = 3,
        .flags = FLAG_PROTECTION_MOVE | FLAG_SNATCH_AFFECTED,
        .split = SPLIT_STATUS,
        .argument = TRUE, // Protects the whole side.
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_DEF_UP_1,
    },

    [MOVE_GUARD_SPLIT] =
    {
        .effect = EFFECT_GUARD_SPLIT,
        .power = 0,
        .type = TYPE_PSYCHIC,
        .accuracy = 0,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_SPD_UP_1,
    },

    [MOVE_POWER_SPLIT] =
    {
        .effect = EFFECT_POWER_SPLIT,
        .power = 0,
        .type = TYPE_PSYCHIC,
        .accuracy = 0,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_SPD_UP_1,
    },

    [MOVE_WONDER_ROOM] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_6
            .priority = 0,
        #else
            .priority = -7,
        #endif
        .effect = EFFECT_WONDER_ROOM,
        .power = 0,
        .type = TYPE_PSYCHIC,
        .accuracy = 0,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_ALL_BATTLERS,
        .flags = FLAG_MIRROR_MOVE_AFFECTED,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_SPDEF_UP_1,
    },

    [MOVE_PSYSHOCK] =
    {
        .effect = EFFECT_PSYSHOCK,
        .power = 80,
        .type = TYPE_PSYCHIC,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .flags2 = FLAG_SCENT_MARK_AFFECTED,
        .split = SPLIT_SPECIAL,
        .zMovePower = 160,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_VENOSHOCK] =
    {
        .effect = EFFECT_VENOSHOCK,
        .power = 65,
        .type = TYPE_POISON,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .flags2 = FLAG_SCENT_MARK_AFFECTED,
        .split = SPLIT_SPECIAL,
        .zMovePower = 120,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_AUTOTOMIZE] =
    {
        .effect = EFFECT_AUTOTOMIZE,
        .power = 0,
        .type = TYPE_STEEL,
        .accuracy = 0,
        .pp = 15,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .flags = FLAG_SNATCH_AFFECTED,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_RESET_STATS,
    },

    [MOVE_RAGE_POWDER] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_6
            .priority = 2,
        #else
            .priority = 3,
        #endif
        .effect = EFFECT_FOLLOW_ME,
        .power = 0,
        .type = TYPE_BUG,
        .accuracy = 0,
        .pp = 20,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_USER,
        .flags = FLAG_POWDER_AND_SPORE_MOVE,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_RESET_STATS,
    },

    [MOVE_TELEKINESIS] =
    {
        .effect = EFFECT_TELEKINESIS,
        .power = 0,
        .type = TYPE_PSYCHIC,
        .accuracy = 0,
        .pp = 15,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MAGIC_COAT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_SPATK_UP_1,
    },

    [MOVE_MAGIC_ROOM] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_6
            .priority = 0,
        #else
            .priority = -7,
        #endif
        .effect = EFFECT_MAGIC_ROOM,
        .power = 0,
        .type = TYPE_PSYCHIC,
        .accuracy = 0,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_ALL_BATTLERS,
        .flags = FLAG_MIRROR_MOVE_AFFECTED,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_SPDEF_UP_1,
    },

    [MOVE_SMACK_DOWN] =
    {
        .effect = EFFECT_KNOCK_FLYING_TARGET_DOWN,
        .power = 70,
        .type = TYPE_ROCK,
        .accuracy = 100,
        .pp = 15,
        .secondaryEffectChance = 100,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_DAMAGE_ON_FLYING_TARGET,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 140,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_STORM_THROW] =
    {
        .power = 60,
        .zMovePower = 120,
        .effect = EFFECT_HIT,
        .type = TYPE_FIGHTING,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .flags2 = FLAG_SCENT_MARK_AFFECTED | FLAG_ALWAYS_CRITICAL_HIT,
        .split = SPLIT_PHYSICAL,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_FLAME_BURST] =
    {
        .effect = EFFECT_FLAME_BURST,
        .power = 70,
        .type = TYPE_FIRE,
        .accuracy = 100,
        .pp = 15,
        .secondaryEffectChance = 100,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .split = SPLIT_SPECIAL,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_SLUDGE_WAVE] =
    {
        .effect = EFFECT_TARGET_POISON_ON_HIT,
        .power = 95,
        .type = TYPE_POISON,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 10,
        .target = MOVE_TARGET_FOES_AND_ALLY,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_HAS_SECONDARY_EFFECT,
        .flags2 = FLAG_WAVE_SURF_AFFECTED,
        .split = SPLIT_SPECIAL,
        .zMovePower = 175,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_QUIVER_DANCE] =
    {
        .effect = EFFECT_USER_SPECIAL_ATTACK_SPECIAL_DEFENSE_SPEED_UP_1,
        .power = 0,
        .type = TYPE_BUG,
        .accuracy = 0,
        .pp = 20,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .flags = FLAG_SNATCH_AFFECTED | FLAG_DANCING_MOVE,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_RESET_STATS,
    },

    [MOVE_HEAVY_SLAM] =
    {
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_DOUBLE_DAMAGE_ON_MINIMIZED_TARGET,
        .flags2 = FLAG_SCENT_MARK_AFFECTED,
        .effect = EFFECT_HEAT_CRASH,
        .power = 1,
        .type = TYPE_STEEL,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 160,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_SYNCHRONOISE] =
    {
        .power = 60,
        .pp = 10,
        .zMovePower = 120,
        .effect = EFFECT_STAR_ICON,
        .type = TYPE_PSYCHIC,
        .accuracy = 100,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_FOES_AND_ALLY,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .split = SPLIT_SPECIAL,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_ELECTRO_BALL] =
    {
        .effect = EFFECT_ELECTRO_BALL,
        .power = 1,
        .type = TYPE_ELECTRIC,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_BALL_AND_BOMB_MOVE,
        .flags2 = FLAG_SCENT_MARK_AFFECTED,
        .split = SPLIT_SPECIAL,
        .zMovePower = 160,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_SOAK] =
    {
        .effect = EFFECT_SET_TYPE,
        .power = 0,
        .type = TYPE_WATER,
        .accuracy = 100,
        .pp = 20,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_BOTH,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MAGIC_COAT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        .split = SPLIT_STATUS,
        .argument = TYPE_WATER,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_SPATK_UP_1,
    },

    [MOVE_FLAME_CHARGE] =
    {
        .effect = EFFECT_USER_SPEED_UP_1_ON_HIT,
        .power = 50,
        .type = TYPE_FIRE,
        .accuracy = 100,
        .pp = 20,
        .secondaryEffectChance = 100,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_HAS_SECONDARY_EFFECT,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 100,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_COIL] =
    {
        .effect = EFFECT_COIL,
        .power = 0,
        .type = TYPE_POISON,
        .accuracy = 0,
        .pp = 20,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .flags = FLAG_SNATCH_AFFECTED,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_RESET_STATS,
    },

    [MOVE_LOW_SWEEP] =
    {
        .power = 80,
        .effect = EFFECT_TARGET_SPEED_DOWN_1_ON_HIT,
        .type = TYPE_FIGHTING,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 100,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_HAS_SECONDARY_EFFECT,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 160,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_ACID_SPRAY] =
    {
        .effect = EFFECT_TARGET_SPECIAL_DEFENSE_DOWN_2_ON_HIT,
        .power = 40,
        .type = TYPE_POISON,
        .accuracy = 100,
        .pp = 20,
        .secondaryEffectChance = 100,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_BALL_AND_BOMB_MOVE | FLAG_HAS_SECONDARY_EFFECT,
        .flags2 = FLAG_ACID_MOVE,
        .split = SPLIT_SPECIAL,
        .zMovePower = 100,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_FOUL_PLAY] =
    {
        .effect = EFFECT_FOUL_PLAY,
        .power = 95,
        .type = TYPE_DARK,
        .accuracy = 100,
        .pp = 15,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .flags2 = FLAG_SCENT_MARK_AFFECTED,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 175,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_SIMPLE_BEAM] =
    {
        .effect = EFFECT_SIMPLE_BEAM,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 15,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MAGIC_COAT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_AURA_BEAM_CANNON_GUN_PULSE_PUMP_SHOT_AND_ZOOKA_MOVE,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_SPATK_UP_1,
    },

    [MOVE_ENTRAINMENT] =
    {
        .effect = EFFECT_ENTRAINMENT,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 15,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MAGIC_COAT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_SPDEF_UP_1,
    },

    [MOVE_AFTER_YOU] =
    {
        .effect = EFFECT_AFTER_YOU,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 15,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = 0,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_SPD_UP_1,
    },

    [MOVE_ROUND] =
    {
        .effect = EFFECT_ROUND,
        .power = 60,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 15,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_SOUND_BASED_MOVE,
        .split = SPLIT_SPECIAL,
        .zMovePower = 120,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_ECHOED_VOICE] =
    {
        .effect = EFFECT_ECHOED_VOICE,
        .power = 40,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 15,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_SOUND_BASED_MOVE,
        .flags2 = FLAG_SCENT_MARK_AFFECTED,
        .split = SPLIT_SPECIAL,
        .zMovePower = 100,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_CHIP_AWAY] =
    {
        .effect = EFFECT_STAR_ICON,
        .power = 70,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 20,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_IGNORE_TARGET_STATS_STAGES,
        .flags2 = FLAG_SCENT_MARK_AFFECTED,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 140,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_CLEAR_SMOG] =
    {
        .effect = EFFECT_CLEAR_SMOG,
        .power = 50,
        .type = TYPE_POISON,
        .accuracy = 0,
        .pp = 15,
        .secondaryEffectChance = 100,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .split = SPLIT_SPECIAL,
        .zMovePower = 100,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_STORED_POWER] =
    {
        .effect = EFFECT_STORED_POWER,
        .power = 20,
        .type = TYPE_PSYCHIC,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .flags2 = FLAG_SCENT_MARK_AFFECTED,
        .split = SPLIT_SPECIAL,
        .zMovePower = 100,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_QUICK_GUARD] =
    {
        .effect = EFFECT_USER_PREVENT_MOVE,
        .power = 0,
        .type = TYPE_FIGHTING,
        .accuracy = 0,
        .pp = 15,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_USER,
        .priority = 3,
        .flags = FLAG_PROTECTION_MOVE | FLAG_SNATCH_AFFECTED,
        .split = SPLIT_STATUS,
        .argument = TRUE, // Protects the whole side.
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_DEF_UP_1,
    },

    [MOVE_ALLY_SWITCH] =
    {
        .priority = 2,
        .effect = EFFECT_ALLY_SWITCH,
        .power = 0,
        .type = TYPE_PSYCHIC,
        .accuracy = 0,
        .pp = 15,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_USER,
        .flags = 0,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_SPD_UP_2,
    },

    [MOVE_SCALD] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_6
            .effect = EFFECT_SCALD,
        #else
            .effect = EFFECT_TARGET_BURN_ON_HIT,
        #endif
        .power = 80,
        .type = TYPE_WATER,
        .accuracy = 100,
        .pp = 15,
        .secondaryEffectChance = 30,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_HAS_SECONDARY_EFFECT | FLAG_THAW_USER,
        .split = SPLIT_SPECIAL,
        .zMovePower = 160,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_SHELL_SMASH] =
    {
        .effect = EFFECT_SHELL_SMASH,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 15,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .flags = FLAG_SNATCH_AFFECTED,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_RESET_STATS,
    },

    [MOVE_HEAL_PULSE] =
    {
        .effect = EFFECT_HEAL_PULSE,
        .power = 0,
        .type = TYPE_PSYCHIC,
        .accuracy = 0,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MAGIC_COAT_AFFECTED | FLAG_AURA_BEAM_CANNON_GUN_PULSE_PUMP_SHOT_AND_ZOOKA_MOVE,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_RESET_STATS,
    },

    [MOVE_HEX] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_6
            .power = 65,
        #else
            .power = 50,
        #endif
        .effect = EFFECT_HEX,
        .type = TYPE_GHOST,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .flags2 = FLAG_SCENT_MARK_AFFECTED,
        .split = SPLIT_SPECIAL,
        .zMovePower = 160,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_SKY_DROP] =
    {
        .effect = EFFECT_SKY_DROP,
        .power = 60,
        .type = TYPE_FLYING,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 120,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_SHIFT_GEAR] =
    {
        .effect = EFFECT_SHIFT_GEAR,
        .power = 0,
        .type = TYPE_STEEL,
        .accuracy = 0,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .flags = FLAG_SNATCH_AFFECTED,
        .flags2 = FLAG_MAGNET_MOVE,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_RESET_STATS,
    },

    [MOVE_CIRCLE_THROW] =
    {
        .effect = EFFECT_TARGET_FORCED_SWITCH_OUT_ON_HIT,
        .power = 60,
        .type = TYPE_FIGHTING,
        .accuracy = 90,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = -6,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 120,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_INCINERATE] =
    {
        .power = 60,
        .zMovePower = 120,
        .effect = EFFECT_INCINERATE,
        .type = TYPE_FIRE,
        .accuracy = 100,
        .pp = 15,
        .secondaryEffectChance = 100,
        .target = MOVE_TARGET_BOTH,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .split = SPLIT_SPECIAL,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_QUASH] =
    {
        .effect = EFFECT_QUASH,
        .power = 0,
        .type = TYPE_DARK,
        .accuracy = 100,
        .pp = 15,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MAGIC_COAT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_SPD_UP_1,
    },

    [MOVE_ACROBATICS] =
    {
        .effect = EFFECT_ACROBATICS,
        .power = 50,
        .type = TYPE_FLYING,
        .accuracy = 100,
        .pp = 15,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .flags2 = FLAG_SCENT_MARK_AFFECTED,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 100,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_REFLECT_TYPE] =
    {
        .effect = EFFECT_REFLECT_TYPE,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 15,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_SNATCH_AFFECTED,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_SPATK_UP_1,
    },

    [MOVE_RETALIATE] =
    {
        .effect = EFFECT_RETALIATE,
        .power = 70,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .flags2 = FLAG_SCENT_MARK_AFFECTED,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 140,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_FINAL_GAMBIT] =
    {
        .effect = EFFECT_FINAL_GAMBIT,
        .power = 1,
        .type = TYPE_FIGHTING,
        .accuracy = 100,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .split = SPLIT_SPECIAL,
        .zMovePower = 180,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_BESTOW] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_6
            .flags = FLAG_MIRROR_MOVE_AFFECTED,
        #else
            .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        #endif
        .effect = EFFECT_BESTOW,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 15,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_SPD_UP_2,
    },

    [MOVE_INFERNO] =
    {
        .effect = EFFECT_TARGET_BURN_ON_HIT,
        .power = 100,
        .type = TYPE_FIRE,
        .accuracy = 50,
        .pp = 5,
        .secondaryEffectChance = 100,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_HAS_SECONDARY_EFFECT,
        .split = SPLIT_SPECIAL,
        .zMovePower = 180,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_WATER_PLEDGE] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_6
            .power = 80,
            .zMovePower = 160,
        #else
            .power = 50,
            .zMovePower = 100,
        #endif
        .effect = EFFECT_PLEDGE,
        .type = TYPE_WATER,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .split = SPLIT_SPECIAL,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_FIRE_PLEDGE] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_6
            .power = 80,
            .zMovePower = 160,
        #else
            .power = 50,
            .zMovePower = 100,
        #endif
        .effect = EFFECT_PLEDGE,
        .type = TYPE_FIRE,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .split = SPLIT_SPECIAL,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_GRASS_PLEDGE] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_6
            .power = 80,
            .zMovePower = 160,
        #else
            .power = 50,
            .zMovePower = 100,
        #endif
        .effect = EFFECT_PLEDGE,
        .type = TYPE_GRASS,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .split = SPLIT_SPECIAL,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_VOLT_SWITCH] =
    {
        .effect = EFFECT_USER_FORCED_SWITCH_OUT_ON_HIT,
        .power = 70,
        .type = TYPE_ELECTRIC,
        .accuracy = 100,
        .pp = 20,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .split = SPLIT_SPECIAL,
        .zMovePower = 140,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_STRUGGLE_BUG] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_6
            .power = 50,
        #else
            .power = 30,
        #endif
        .effect = EFFECT_TARGET_SPECIAL_ATTACK_DOWN_1_ON_HIT,
        .type = TYPE_BUG,
        .accuracy = 100,
        .pp = 20,
        .secondaryEffectChance = 100,
        .target = MOVE_TARGET_BOTH,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_HAS_SECONDARY_EFFECT,
        .split = SPLIT_SPECIAL,
        .zMovePower = 100,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_BULLDOZE] =
    {
        .effect = EFFECT_BULLDOZE,
        .power = 60,
        .type = TYPE_GROUND,
        .accuracy = 100,
        .pp = 20,
        .secondaryEffectChance = 100,
        .target = MOVE_TARGET_FOES_AND_ALLY,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_HAS_SECONDARY_EFFECT,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 120,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_FROST_BREATH] =
    {
        .power = 60,
        .zMovePower = 120,
        .effect = EFFECT_HIT,
        .type = TYPE_ICE,
        .accuracy = 90,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .flags2 = FLAG_SCENT_MARK_AFFECTED | FLAG_ALWAYS_CRITICAL_HIT,
        .split = SPLIT_SPECIAL,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_DRAGON_TAIL] =
    {
        .effect = EFFECT_TARGET_FORCED_SWITCH_OUT_ON_HIT,
        .power = 60,
        .type = TYPE_DRAGON,
        .accuracy = 90,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = -6,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        .flags2 = FLAG_TAIL_MOVE,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 120,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_WORK_UP] =
    {
        .effect = EFFECT_USER_ATTACK_SPECIAL_ATTACK_UP_1,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 30,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .flags = FLAG_SNATCH_AFFECTED,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_ATK_UP_1,
    },

    [MOVE_ELECTROWEB] =
    {
        .effect = EFFECT_TARGET_SPEED_DOWN_1_ON_HIT,
        .power = 55,
        .type = TYPE_ELECTRIC,
        .accuracy = 95,
        .pp = 15,
        .secondaryEffectChance = 100,
        .target = MOVE_TARGET_BOTH,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_HAS_SECONDARY_EFFECT,
        .split = SPLIT_SPECIAL,
        .zMovePower = 100,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_WILD_CHARGE] =
    {
        .effect = EFFECT_USER_RECOIL_25,
        .power = 90,
        .type = TYPE_ELECTRIC,
        .accuracy = 100,
        .pp = 15,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_RECOIL_DAMAGE,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 175,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_DRILL_RUN] =
    {
        .effect = EFFECT_HIT,
        .power = 80,
        .type = TYPE_GROUND,
        .accuracy = 95,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_HIGH_CRITICAL_HIT_RATIO | FLAG_DAMAGE_ON_UNGROUNDED_TARGET,
        .flags2 = FLAG_SCENT_MARK_AFFECTED,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 160,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_DUAL_CHOP] =
    {
        .effect = EFFECT_TARGET_DOUBLE_HIT,
        .power = 40,
        .type = TYPE_DRAGON,
        .accuracy = 90,
        .pp = 15,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_HIGH_CRITICAL_HIT_RATIO | FLAG_TWO_STRIKES,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 100,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_HEART_STAMP] =
    {
        .effect = EFFECT_TARGET_FLINCH_ON_HIT,
        .power = 60,
        .type = TYPE_PSYCHIC,
        .accuracy = 100,
        .pp = 25,
        .secondaryEffectChance = 30,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_HAS_SECONDARY_EFFECT,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 120,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_HORN_LEECH] =
    {
        .effect = EFFECT_USER_DRAIN_50_ON_HIT,
        .power = 75,
        .type = TYPE_GRASS,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        .flags2 = FLAG_IGNORE_TARGET_DEFENSE_STAGES,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 140,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_SACRED_SWORD] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_6
            .pp = 15,
        #else
            .pp = 20,
        #endif
        .effect = EFFECT_STAR_ICON,
        .power = 90,
        .type = TYPE_FIGHTING,
        .accuracy = 100,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_IGNORE_TARGET_STATS_STAGES,
        .flags2 = FLAG_SLICING_MOVE | FLAG_SCENT_MARK_AFFECTED,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 175,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_RAZOR_SHELL] =
    {
        .effect = EFFECT_TARGET_DEFENSE_DOWN_1_ON_HIT,
        .power = 75,
        .type = TYPE_WATER,
        .accuracy = 95,
        .pp = 10,
        .secondaryEffectChance = 50,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_HAS_SECONDARY_EFFECT,
        .flags2 = FLAG_SLICING_MOVE,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 140,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_HEAT_CRASH] =
    {
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_DOUBLE_DAMAGE_ON_MINIMIZED_TARGET,
        .flags2 = FLAG_SCENT_MARK_AFFECTED,
        .effect = EFFECT_HEAT_CRASH,
        .power = 1,
        .type = TYPE_FIRE,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 160,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_LEAF_TORNADO] =
    {
        .effect = EFFECT_TARGET_ACCURACY_DOWN_1_ON_HIT,
        .power = 65,
        .type = TYPE_GRASS,
        .accuracy = 90,
        .pp = 10,
        .secondaryEffectChance = 50,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_HAS_SECONDARY_EFFECT,
        .flags2 = FLAG_WIND_MOVE,
        .split = SPLIT_SPECIAL,
        .zMovePower = 120,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_STEAMROLLER] =
    {
        .effect = EFFECT_TARGET_FLINCH_ON_HIT,
        .power = 65,
        .type = TYPE_BUG,
        .accuracy = 100,
        .pp = 20,
        .secondaryEffectChance = 30,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .split = SPLIT_PHYSICAL,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_HAS_SECONDARY_EFFECT | FLAG_DOUBLE_DAMAGE_ON_MINIMIZED_TARGET,
        .zMovePower = 120,
        .zMoveEffect = Z_EFFECT_NONE,
        },

    [MOVE_COTTON_GUARD] =
    {
        .effect = EFFECT_USER_DEFENSE_UP_3,
        .power = 0,
        .type = TYPE_GRASS,
        .accuracy = 0,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .flags = FLAG_SNATCH_AFFECTED,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_RESET_STATS,
    },

    [MOVE_NIGHT_DAZE] =
    {
        .effect = EFFECT_TARGET_ACCURACY_DOWN_1_ON_HIT,
        .power = 85,
        .type = TYPE_DARK,
        .accuracy = 95,
        .pp = 10,
        .secondaryEffectChance = 40,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_HAS_SECONDARY_EFFECT,
        .split = SPLIT_SPECIAL,
        .zMovePower = 160,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_PSYSTRIKE] =
    {
        .effect = EFFECT_PSYSHOCK,
        .power = 100,
        .type = TYPE_PSYCHIC,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .flags2 = FLAG_SCENT_MARK_AFFECTED,
        .split = SPLIT_SPECIAL,
        .zMovePower = 180,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_TAIL_SLAP] =
    {
        .effect = EFFECT_TARGET_MULTI_HIT,
        .power = 25,
        .type = TYPE_NORMAL,
        .accuracy = 90,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .flags2 = FLAG_TAIL_MOVE,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 100,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_HURRICANE] =
    {
        .power = 110,
        .zMovePower = 185,
        .effect = EFFECT_HURRICANE,
        .type = TYPE_FLYING,
        .accuracy = 70,
        .pp = 10,
        .secondaryEffectChance = 30,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_HAS_SECONDARY_EFFECT | FLAG_DAMAGE_ON_FLYING_TARGET,
        .flags2 = FLAG_WEATHER_RELATED_MOVE | FLAG_LIFT_ENTRY_HAZARDS | FLAG_WIND_MOVE,
        .split = SPLIT_SPECIAL,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_HEAD_CHARGE] =
    {
        .effect = EFFECT_USER_RECOIL_25,
        .power = 120,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 15,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_RECOIL_DAMAGE,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 190,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_GEAR_GRIND] =
    {
        .effect = EFFECT_TARGET_DOUBLE_HIT,
        .power = 50,
        .type = TYPE_STEEL,
        .accuracy = 100,
        .pp = 15,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_TWO_STRIKES,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 180,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_SEARING_SHOT] =
    {
        .effect = EFFECT_TARGET_BURN_ON_HIT,
        .power = 100,
        .type = TYPE_FIRE,
        .accuracy = 100,
        .pp = 5,
        .secondaryEffectChance = 30,
        .target = MOVE_TARGET_FOES_AND_ALLY,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_BALL_AND_BOMB_MOVE | FLAG_HAS_SECONDARY_EFFECT | FLAG_AURA_BEAM_CANNON_GUN_PULSE_PUMP_SHOT_AND_ZOOKA_MOVE,
        .flags2 = FLAG_SLOTTED_SHELL_MOVE,
        .split = SPLIT_SPECIAL,
        .zMovePower = 180,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_TECHNO_BLAST] =
    {
        .power = 120,
        .zMovePower = 190,
        .effect = EFFECT_CHANGE_TYPE_ON_ITEM,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .flags2 = FLAG_SCENT_MARK_AFFECTED,
        .split = SPLIT_SPECIAL,
        .argument = HOLD_EFFECT_DRIVE,
        .argument2 = EQUIP_SLOT_3,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_RELIC_SONG] =
    {
        .effect = EFFECT_RELIC_SONG,
        .power = 100,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 5,
        .secondaryEffectChance = 10,
        .target = MOVE_TARGET_BOTH,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_SOUND_BASED_MOVE | FLAG_HAS_SECONDARY_EFFECT,
        .split = SPLIT_SPECIAL,
        .zMovePower = 180,
        .zMoveEffect = Z_EFFECT_NONE,
        .argument = MOVE_EFFECT_SLEEP,
    },

    [MOVE_SECRET_SWORD] =
    {
        .effect = EFFECT_PSYSHOCK,
        .power = 85,
        .type = TYPE_FIGHTING,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .flags2 = FLAG_SLICING_MOVE | FLAG_SCENT_MARK_AFFECTED,
        .split = SPLIT_SPECIAL,
        .zMovePower = 160,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_GLACIATE] =
    {
        .effect = EFFECT_TARGET_SPEED_DOWN_1_ON_HIT,
        .power = 100,
        .type = TYPE_ICE,
        .accuracy = 95,
        .pp = 5,
        .secondaryEffectChance = 100,
        .target = MOVE_TARGET_BOTH,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_HAS_SECONDARY_EFFECT,
        .split = SPLIT_SPECIAL,
        .zMovePower = 180,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_BOLT_STRIKE] =
    {
        .effect = EFFECT_TARGET_PARALYZE_ON_HIT,
        .power = 130,
        .type = TYPE_ELECTRIC,
        .accuracy = 85,
        .pp = 5,
        .secondaryEffectChance = 20,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_HAS_SECONDARY_EFFECT,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 195,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_BLUE_FLARE] =
    {
        .effect = EFFECT_TARGET_BURN_ON_HIT,
        .power = 130,
        .type = TYPE_FIRE,
        .accuracy = 85,
        .pp = 5,
        .secondaryEffectChance = 20,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_HAS_SECONDARY_EFFECT,
        .split = SPLIT_SPECIAL,
        .zMovePower = 195,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_FIERY_DANCE] =
    {
        .effect = EFFECT_USER_SPECIAL_ATTACK_UP_1_ON_HIT,
        .power = 80,
        .type = TYPE_FIRE,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 50,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_DANCING_MOVE | FLAG_HAS_SECONDARY_EFFECT,
        .split = SPLIT_SPECIAL,
        .zMovePower = 160,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_FREEZE_SHOCK] =
    {
        .effect = EFFECT_TARGET_PARALYZE_ON_HIT,
        .power = 130,
        .type = TYPE_ICE,
        .accuracy = 85,
        .pp = 5,
        .secondaryEffectChance = 20,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_HAS_SECONDARY_EFFECT,
        .split = SPLIT_PHYSICAL,
        .argument = MOVE_EFFECT_PARALYSIS,
        .zMovePower = 195,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_ICE_BURN] =
    {
        .effect = EFFECT_TARGET_BURN_ON_HIT,
        .power = 130,
        .type = TYPE_ICE,
        .accuracy = 85,
        .pp = 5,
        .secondaryEffectChance = 20,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_HAS_SECONDARY_EFFECT,
        .split = SPLIT_SPECIAL,
        .zMovePower = 195,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_SNARL] =
    {
        .effect = EFFECT_TARGET_SPECIAL_ATTACK_DOWN_1_ON_HIT,
        .power = 55,
        .type = TYPE_DARK,
        .accuracy = 95,
        .pp = 15,
        .secondaryEffectChance = 100,
        .target = MOVE_TARGET_BOTH,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_HAS_SECONDARY_EFFECT | FLAG_SOUND_BASED_MOVE,
        .split = SPLIT_SPECIAL,
        .zMovePower = 100,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_ICICLE_CRASH] =
    {
        .effect = EFFECT_TARGET_FLINCH_ON_HIT,
        .power = 85,
        .type = TYPE_ICE,
        .accuracy = 90,
        .pp = 10,
        .secondaryEffectChance = 30,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_HAS_SECONDARY_EFFECT,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 160,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_V_CREATE] =
    {
        .effect = EFFECT_V_CREATE,
        .power = 180,
        .type = TYPE_FIRE,
        .accuracy = 95,
        .pp = 5,
        .secondaryEffectChance = 100,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 220,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_FUSION_FLARE] =
    {
        .effect = EFFECT_TARGET_FUSION_COMBO,
        .power = 100,
        .type = TYPE_FIRE,
        .accuracy = 100,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_THAW_USER,
        .flags2 = FLAG_SCENT_MARK_AFFECTED,
        .split = SPLIT_SPECIAL,
        .zMovePower = 180,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_FUSION_BOLT] =
    {
        .effect = EFFECT_TARGET_FUSION_COMBO,
        .power = 100,
        .type = TYPE_ELECTRIC,
        .accuracy = 100,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .flags2 = FLAG_SCENT_MARK_AFFECTED,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 180,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_FLYING_PRESS] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_7
            .power = 100,
        #else
            .power = 80,
        #endif
        .effect = EFFECT_TWO_TYPED_MOVE,
        .type = TYPE_FIGHTING,
        .accuracy = 95,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_DOUBLE_DAMAGE_ON_MINIMIZED_TARGET,
        .flags2 = FLAG_SCENT_MARK_AFFECTED,
        .split = SPLIT_PHYSICAL,
        .argument = TYPE_FLYING,
        .zMovePower = 170,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_MAT_BLOCK] =
    {
        .effect = EFFECT_MAT_BLOCK,
        .power = 0,
        .type = TYPE_FIGHTING,
        .accuracy = 0,
        .pp = 15,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .flags = FLAG_SNATCH_AFFECTED,
        .split = SPLIT_STATUS,
        .argument = TRUE, // Protects the whole side.
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_DEF_UP_1,
    },

    [MOVE_BELCH] =
    {
        .effect = EFFECT_BELCH,
        .power = 120,
        .type = TYPE_POISON,
        .accuracy = 90,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED,
        .flags2 = FLAG_SCENT_MARK_AFFECTED,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 190,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_ROTOTILLER] =
    {
        .effect = EFFECT_ROTOTILLER,
        .power = 0,
        .type = TYPE_GROUND,
        .accuracy = 0,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_ALL_BATTLERS,
        .priority = 0,
        .flags = 0,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_ATK_UP_1,
    },

    [MOVE_STICKY_WEB] =
    {
        .effect = EFFECT_STICKY_WEB,
        .power = 0,
        .type = TYPE_BUG,
        .accuracy = 0,
        .pp = 20,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_OPPONENTS_FIELD,
        .priority = 0,
        .flags = FLAG_MAGIC_COAT_AFFECTED,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_SPD_UP_1,
    },

    [MOVE_FELL_STINGER] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_7
            .power = 50,
        #else
            .power = 30,
        #endif
        .effect = EFFECT_ATTACK_UP_3_WHEN_FAINTING,
        .type = TYPE_BUG,
        .accuracy = 100,
        .pp = 25,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .flags2 = FLAG_SCENT_MARK_AFFECTED,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 100,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_PHANTOM_FORCE] =
    {
        .flags = FLAG_MAKES_CONTACT | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_DOUBLE_DAMAGE_ON_MINIMIZED_TARGET,
        .effect = EFFECT_SEMI_INVULNERABLE,
        .power = 90,
        .type = TYPE_GHOST,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 100,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .split = SPLIT_PHYSICAL,
        .argument2 = MOVE_EFFECT_FEINT,
        .zMovePower = 175,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_TRICK_OR_TREAT] =
    {
        .effect = EFFECT_ADD_TYPE,
        .power = 0,
        .type = TYPE_GHOST,
        .accuracy = 100,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        .split = SPLIT_STATUS,
        .argument = TYPE_GHOST,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_ALL_STATS_UP_1,
    },

    [MOVE_NOBLE_ROAR] =
    {
        .effect = EFFECT_NOBLE_ROAR,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 30,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MAGIC_COAT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_SOUND_BASED_MOVE,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_DEF_UP_1,
    },

    [MOVE_ION_DELUGE] =
    {
        .effect = EFFECT_ION_DELUGE,
        .power = 0,
        .type = TYPE_ELECTRIC,
        .accuracy = 0,
        .pp = 25,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_ALL_BATTLERS,
        .priority = 1,
        .flags = 0,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_SPATK_UP_1,
    },

    [MOVE_PARABOLIC_CHARGE] =
    {
        .power = 65,
        .zMovePower = 120,
        .effect = EFFECT_USER_DRAIN_50_ON_HIT,
        .type = TYPE_ELECTRIC,
        .accuracy = 100,
        .pp = 20,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_FOES_AND_ALLY,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .split = SPLIT_SPECIAL,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_FORESTS_CURSE] =
    {
        .effect = EFFECT_ADD_TYPE,
        .power = 0,
        .type = TYPE_GRASS,
        .accuracy = 100,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        .split = SPLIT_STATUS,
        .argument = TYPE_GRASS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_ALL_STATS_UP_1,
    },

    [MOVE_PETAL_BLIZZARD] =
    {
        .effect = EFFECT_HIT,
        .power = 90,
        .type = TYPE_GRASS,
        .accuracy = 100,
        .pp = 15,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_FOES_AND_ALLY,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .flags2 = FLAG_WIND_MOVE,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 175,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_FREEZE_DRY] =
    {
        .effect = EFFECT_FREEZE_DRY,
        .power = 70,
        .type = TYPE_ICE,
        .accuracy = 100,
        .pp = 20,
        .secondaryEffectChance = 20,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_HAS_SECONDARY_EFFECT,
        .split = SPLIT_SPECIAL,
        .zMovePower = 140,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_DISARMING_VOICE] =
    {
        .effect = EFFECT_HIT,
        .power = 40,
        .type = TYPE_FAIRY,
        .accuracy = 0,
        .pp = 15,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_BOTH,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_SOUND_BASED_MOVE,
        .split = SPLIT_SPECIAL,
        .zMovePower = 100,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_PARTING_SHOT] =
    {
        .effect = EFFECT_PARTING_SHOT,
        .power = 0,
        .type = TYPE_DARK,
        .accuracy = 100,
        .pp = 20,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MAGIC_COAT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_SOUND_BASED_MOVE | FLAG_AURA_BEAM_CANNON_GUN_PULSE_PUMP_SHOT_AND_ZOOKA_MOVE,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_RESTORE_REPLACEMENT_HP,
    },

    [MOVE_TOPSY_TURVY] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_7
            .accuracy = 0,
        #else
            .accuracy = 100,
        #endif
        .effect = EFFECT_TOPSY_TURVY,
        .power = 0,
        .type = TYPE_DARK,
        .pp = 20,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MAGIC_COAT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_ATK_UP_1,
    },

    [MOVE_DRAINING_KISS] =
    {
        .effect = EFFECT_USER_DRAIN_75_ON_HIT,
        .power = 50,
        .type = TYPE_FAIRY,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .flags2 = FLAG_KISSING_MOVE,
        .split = SPLIT_SPECIAL,
        .zMovePower = 100,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_CRAFTY_SHIELD] =
    {
        .effect = EFFECT_USER_PREVENT_MOVE,
        .power = 0,
        .type = TYPE_FAIRY,
        .accuracy = 0,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_USER,
        .priority = 3,
        .flags = 0,
        .split = SPLIT_STATUS,
        .argument = TRUE, // Protects the whole side.
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_SPDEF_UP_1,
    },

    [MOVE_FLOWER_SHIELD] =
    {
        .effect = EFFECT_FLOWER_SHIELD,
        .power = 0,
        .type = TYPE_FAIRY,
        .accuracy = 0,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_ALL_BATTLERS,
        .priority = 0,
        .flags = 0,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_DEF_UP_1,
    },

    [MOVE_GRASSY_TERRAIN] =
    {
        .effect = EFFECT_GRASSY_TERRAIN,
        .power = 0,
        .type = TYPE_GRASS,
        .accuracy = 0,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_ALL_BATTLERS,
        .priority = 0,
        .flags = 0,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_DEF_UP_1,
    },

    [MOVE_MISTY_TERRAIN] =
    {
        .effect = EFFECT_MISTY_TERRAIN,
        .power = 0,
        .type = TYPE_FAIRY,
        .accuracy = 0,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_ALL_BATTLERS,
        .priority = 0,
        .flags = 0,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_SPDEF_UP_1,
    },

    [MOVE_ELECTRIFY] =
    {
        .effect = EFFECT_ELECTRIFY,
        .power = 0,
        .type = TYPE_ELECTRIC,
        .accuracy = 0,
        .pp = 20,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = 0,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_SPATK_UP_1,
    },

    [MOVE_PLAY_ROUGH] =
    {
        .effect = EFFECT_TARGET_ATTACK_DOWN_1_ON_HIT,
        .power = 90,
        .type = TYPE_FAIRY,
        .accuracy = 90,
        .pp = 10,
        .secondaryEffectChance = 10,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_HAS_SECONDARY_EFFECT,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 175,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_FAIRY_WIND] =
    {
        .effect = EFFECT_HIT,
        .power = 40,
        .type = TYPE_FAIRY,
        .accuracy = 100,
        .pp = 30,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .flags2 = FLAG_WIND_MOVE | FLAG_SCENT_MARK_AFFECTED,
        .split = SPLIT_SPECIAL,
        .zMovePower = 100,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_MOONBLAST] =
    {
        .effect = EFFECT_TARGET_SPECIAL_ATTACK_DOWN_1_ON_HIT,
        .power = 95,
        .type = TYPE_FAIRY,
        .accuracy = 100,
        .pp = 15,
        .secondaryEffectChance = 30,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_HAS_SECONDARY_EFFECT,
        .flags2 = FLAG_COSMIC_ENERGYZED_MOVE,
        .split = SPLIT_SPECIAL,
        .zMovePower = 175,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_BOOMBURST] =
    {
        .effect = EFFECT_HIT,
        .power = 140,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_FOES_AND_ALLY,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_SOUND_BASED_MOVE,
        .split = SPLIT_SPECIAL,
        .zMovePower = 200,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_FAIRY_LOCK] =
    {
        .effect = EFFECT_FAIRY_LOCK,
        .power = 0,
        .type = TYPE_FAIRY,
        .accuracy = 0,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_ALL_BATTLERS,
        .priority = 0,
        .flags = FLAG_MIRROR_MOVE_AFFECTED,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_DEF_UP_1,
    },

    [MOVE_KINGS_SHIELD] =
    {
        .effect = EFFECT_USER_PREVENT_MOVE,
        .power = 0,
        .type = TYPE_STEEL,
        .accuracy = 0,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_USER,
        .priority = 4,
        .flags = FLAG_PROTECTION_MOVE,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_RESET_STATS,
    },

    [MOVE_PLAY_NICE] =
    {
        .effect = EFFECT_TARGET_ATTACK_DOWN_1,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 20,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAGIC_COAT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_DEF_UP_1,
    },

    [MOVE_CONFIDE] =
    {
        .effect = EFFECT_TARGET_SPECIAL_ATTACK_DOWN_1,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 20,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAGIC_COAT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_SOUND_BASED_MOVE,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_SPDEF_UP_1,
    },

    [MOVE_DIAMOND_STORM] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_4
            .effect = EFFECT_USER_DEFENSE_UP_2_ON_HIT,
        #else
            .effect = EFFECT_DEFENSE_UP_1_ON_HIT,
        #endif
        .power = 100,
        .type = TYPE_ROCK,
        .accuracy = 95,
        .pp = 5,
        .secondaryEffectChance = 50,
        .target = MOVE_TARGET_BOTH,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_HAS_SECONDARY_EFFECT,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 180,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_STEAM_ERUPTION] =
    {
        .effect = EFFECT_SCALD,
        .power = 110,
        .type = TYPE_WATER,
        .accuracy = 95,
        .pp = 5,
        .secondaryEffectChance = 30,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_HAS_SECONDARY_EFFECT | FLAG_THAW_USER,
        .split = SPLIT_SPECIAL,
        .zMovePower = 185,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_HYPERSPACE_HOLE] =
    {
        .effect = EFFECT_TARGET_REMOVE_PROTECTION_ON_HIT,
        .power = 80,
        .type = TYPE_GHOST,
        .accuracy = 0,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .split = SPLIT_SPECIAL,
        .zMovePower = 160,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_WATER_SHURIKEN] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_7
            .split = SPLIT_SPECIAL,
        #else
            .split = SPLIT_PHYSICAL,
        #endif
        .effect = EFFECT_TARGET_MULTI_HIT,
        .power = 15,
        .type = TYPE_WATER,
        .accuracy = 100,
        .pp = 20,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 1,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .zMovePower = 100,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_MYSTICAL_FIRE] =
    {
        .power = 75,
        .zMovePower = 140,
        .effect = EFFECT_TARGET_SPECIAL_ATTACK_DOWN_1_ON_HIT,
        .type = TYPE_FIRE,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 100,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_HAS_SECONDARY_EFFECT,
        .split = SPLIT_SPECIAL,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_SPIKY_SHIELD] =
    {
        .effect = EFFECT_USER_PREVENT_MOVE,
        .power = 0,
        .type = TYPE_GRASS,
        .accuracy = 0,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_USER,
        .priority = 4,
        .flags = FLAG_PROTECTION_MOVE,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_DEF_UP_1,
    },

    [MOVE_AROMATIC_MIST] =
    {
        .effect = EFFECT_AROMATIC_MIST,
        .power = 0,
        .type = TYPE_FAIRY,
        .accuracy = 0,
        .pp = 20,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_ALLY,
        .priority = 0,
        .flags = 0,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_SPDEF_UP_2,
    },

    [MOVE_EERIE_IMPULSE] =
    {
        .effect = EFFECT_TARGET_SPECIAL_ATTACK_DOWN_2,
        .power = 0,
        .type = TYPE_ELECTRIC,
        .accuracy = 100,
        .pp = 15,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MAGIC_COAT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_SPDEF_UP_1,
    },

    [MOVE_VENOM_DRENCH] =
    {
        .effect = EFFECT_VENOM_DRENCH,
        .power = 0,
        .type = TYPE_POISON,
        .accuracy = 100,
        .pp = 20,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_BOTH,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MAGIC_COAT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_DEF_UP_1,
    },

    [MOVE_POWDER] =
    {
        .effect = EFFECT_POWDER,
        .power = 0,
        .type = TYPE_BUG,
        .accuracy = 100,
        .pp = 20,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 1,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MAGIC_COAT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_POWDER_AND_SPORE_MOVE,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_SPDEF_UP_2,
    },

    [MOVE_GEOMANCY] =
    {
        .effect = EFFECT_GEOMANCY,
        .power = 0,
        .type = TYPE_FAIRY,
        .accuracy = 0,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .flags = 0,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_ALL_STATS_UP_1,
    },

    [MOVE_MAGNETIC_FLUX] =
    {
        .effect = EFFECT_MAGNETIC_FLUX,
        .power = 0,
        .type = TYPE_ELECTRIC,
        .accuracy = 0,
        .pp = 20,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .flags = FLAG_SNATCH_AFFECTED,
        .flags2 = FLAG_MAGNET_MOVE,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_SPDEF_UP_1,
    },

    [MOVE_HAPPY_HOUR] =
    {
        .effect = EFFECT_USER_DO_NOTHING,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 30,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .flags = 0,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_ALL_STATS_UP_1,
    },

    [MOVE_ELECTRIC_TERRAIN] =
    {
        .effect = EFFECT_ELECTRIC_TERRAIN,
        .power = 0,
        .type = TYPE_ELECTRIC,
        .accuracy = 0,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_ALL_BATTLERS,
        .priority = 0,
        .flags = 0,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_SPD_UP_1,
    },

    [MOVE_DAZZLING_GLEAM] =
    {
        .effect = EFFECT_HIT,
        .power = 80,
        .type = TYPE_FAIRY,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_BOTH,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .split = SPLIT_SPECIAL,
        .zMovePower = 160,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_CELEBRATE] =
    {
        .effect = EFFECT_USER_DO_NOTHING,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 40,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .flags = 0,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_ALL_STATS_UP_1,
    },

    [MOVE_HOLD_HANDS] =
    {
        .effect = EFFECT_USER_DO_NOTHING,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 40,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_ALLY,
        .priority = 0,
        .flags = 0,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_ALL_STATS_UP_1,
    },

    [MOVE_BABY_DOLL_EYES] =
    {
        .effect = EFFECT_TARGET_ATTACK_DOWN_1,
        .power = 0,
        .type = TYPE_FAIRY,
        .accuracy = 100,
        .pp = 30,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 1,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MAGIC_COAT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_DEF_UP_1,
    },

    [MOVE_NUZZLE] =
    {
        .effect = EFFECT_TARGET_PARALYZE_ON_HIT,
        .power = 20,
        .type = TYPE_ELECTRIC,
        .accuracy = 100,
        .pp = 20,
        .secondaryEffectChance = 100,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_HAS_SECONDARY_EFFECT,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 100,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_HOLD_BACK] =
    {
        .effect = EFFECT_TARGET_SURVIVE_1_HP_ON_HIT,
        .power = 40,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 40,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .flags2 = FLAG_SCENT_MARK_AFFECTED,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 100,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_INFESTATION] =
    {
        .effect = EFFECT_TARGET_PREVENT_ESCAPE_AND_HURT_EACH_TURN,
        .power = 20,
        .type = TYPE_BUG,
        .accuracy = 100,
        .pp = 20,
        .secondaryEffectChance = 100,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .split = SPLIT_SPECIAL,
        .zMovePower = 100,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_POWER_UP_PUNCH] =
    {
        .effect = EFFECT_SPELL_FIST_USER_ATTACK_UP_1_ON_HIT,
        .power = 40,
        .type = TYPE_FIGHTING,
        .accuracy = 100,
        .pp = 20,
        .secondaryEffectChance = 100,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_PUNCHING_MOVE | FLAG_HAS_SECONDARY_EFFECT,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 100,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_OBLIVION_WING] =
    {
        .effect = EFFECT_USER_DRAIN_75_ON_HIT,
        .power = 80,
        .type = TYPE_FLYING,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .flags2 = FLAG_WING_MOVE,
        .split = SPLIT_SPECIAL,
        .zMovePower = 160,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_THOUSAND_ARROWS] =
    {
        .effect = EFFECT_KNOCK_FLYING_TARGET_DOWN,
        .power = 90,
        .type = TYPE_GROUND,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 100,
        .target = MOVE_TARGET_BOTH,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_DAMAGE_ON_FLYING_TARGET | FLAG_DAMAGE_ON_UNGROUNDED_TARGET,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 175,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_THOUSAND_WAVES] =
    {
        .effect = EFFECT_TARGET_PREVENT_ESCAPE_ON_HIT,
        .power = 90,
        .type = TYPE_GROUND,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 100,
        .target = MOVE_TARGET_BOTH,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 175,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_LANDS_WRATH] =
    {
        .effect = EFFECT_HIT,
        .power = 90,
        .type = TYPE_GROUND,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_BOTH,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 175,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_LIGHT_OF_RUIN] =
    {
        .effect = EFFECT_USER_RECOIL_50,
        .power = 140,
        .type = TYPE_FAIRY,
        .accuracy = 90,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_RECOIL_DAMAGE,
        .split = SPLIT_SPECIAL,
        .zMovePower = 200,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_ORIGIN_PULSE] =
    {
        .effect = EFFECT_HIT,
        .power = 110,
        .type = TYPE_WATER,
        .accuracy = 85,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_BOTH,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_AURA_BEAM_CANNON_GUN_PULSE_PUMP_SHOT_AND_ZOOKA_MOVE,
        .split = SPLIT_SPECIAL,
        .zMovePower = 185,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_PRECIPICE_BLADES] =
    {
        .effect = EFFECT_HIT,
        .power = 120,
        .type = TYPE_GROUND,
        .accuracy = 85,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_BOTH,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 190,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_DRAGON_ASCENT] =
    {
        .effect = EFFECT_CLOSE_COMBAT,
        .power = 120,
        .type = TYPE_FLYING,
        .accuracy = 100,
        .pp = 5,
        .secondaryEffectChance = 100,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 190,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_HYPERSPACE_FURY] =
    {
        .effect = EFFECT_HYPERSPACE_FURY,
        .power = 100,
        .type = TYPE_DARK,
        .accuracy = 0,
        .pp = 5,
        .secondaryEffectChance = 100,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_BYPASS_SUBSTITUTE,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_SHORE_UP] =
    {
        .effect = EFFECT_SHORE_UP,
        .power = 0,
        .type = TYPE_GROUND,
        .accuracy = 0,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .flags = FLAG_SNATCH_AFFECTED,
        .flags2 = FLAG_WEATHER_RELATED_MOVE,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_RESET_STATS,
    },

    [MOVE_FIRST_IMPRESSION] =
    {
        .effect = EFFECT_FAKE_OUT,
        .power = 90,
        .type = TYPE_BUG,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 2,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 175,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_BANEFUL_BUNKER] =
    {
        .effect = EFFECT_USER_PREVENT_MOVE,
        .power = 0,
        .type = TYPE_POISON,
        .accuracy = 0,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_USER,
        .priority = 4,
        .flags = FLAG_PROTECTION_MOVE,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_DEF_UP_1,
    },

    [MOVE_SPIRIT_SHACKLE] =
    {
        .effect = EFFECT_TARGET_PREVENT_ESCAPE_ON_HIT,
        .power = 80,
        .type = TYPE_GHOST,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_HAS_SECONDARY_EFFECT,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 160,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_DARKEST_LARIAT] =
    {
        .effect = EFFECT_STAR_ICON,
        .power = 85,
        .type = TYPE_DARK,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_IGNORE_TARGET_STATS_STAGES,
        .flags2 = FLAG_SCENT_MARK_AFFECTED,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 160,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_SPARKLING_ARIA] =
    {
        .effect = EFFECT_TARGET_CURE_SPECIFIC_STATUS,
        .power = 90,
        .type = TYPE_WATER,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 100,
        .target = MOVE_TARGET_FOES_AND_ALLY,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_SOUND_BASED_MOVE | FLAG_HAS_SECONDARY_EFFECT,
        .split = SPLIT_SPECIAL,
        .argument = STATUS1_BURN,
        .zMovePower = 175,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_ICE_HAMMER] =
    {
        .effect = EFFECT_USER_SPEED_DOWN_1_ON_HIT,
        .power = 100,
        .type = TYPE_ICE,
        .accuracy = 90,
        .pp = 10,
        .secondaryEffectChance = 100,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_PUNCHING_MOVE,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 180,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_FLORAL_HEALING] =
    {
        .effect = EFFECT_HEAL_PULSE,
        .power = 0,
        .type = TYPE_FAIRY,
        .accuracy = 0,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MAGIC_COAT_AFFECTED,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_RESET_STATS,
    },

    [MOVE_HIGH_HORSEPOWER] =
    {
        .effect = EFFECT_HIT,
        .power = 95,
        .type = TYPE_GROUND,
        .accuracy = 95,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_DAMAGE_ON_UNGROUNDED_TARGET,
        .flags2 = FLAG_SCENT_MARK_AFFECTED,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 175,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_STRENGTH_SAP] =
    {
        .effect = EFFECT_STRENGTH_SAP,
        .power = 0,
        .type = TYPE_GRASS,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MAGIC_COAT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_DEF_UP_1,
    },

    [MOVE_SOLAR_BLADE] =
    {
        .effect = EFFECT_USER_FIRST_TURN_PREPARE_SECOND_TURN_ATTACK,
        .power = 125,
        .type = TYPE_GRASS,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .flags2 = FLAG_WEATHER_RELATED_MOVE | FLAG_SLICING_MOVE | FLAG_COSMIC_ENERGYZED_MOVE,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 190,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_LEAFAGE] =
    {
        .effect = EFFECT_HIT,
        .power = 40,
        .type = TYPE_GRASS,
        .accuracy = 100,
        .pp = 40,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .flags2 = FLAG_SCENT_MARK_AFFECTED,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 100,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_SPOTLIGHT] =
    {
        .effect = EFFECT_FOLLOW_ME,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 15,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 3,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MAGIC_COAT_AFFECTED,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_SPDEF_UP_1,
    },

    [MOVE_TOXIC_THREAD] =
    {
        .effect = EFFECT_TOXIC_THREAD,
        .power = 0,
        .type = TYPE_POISON,
        .accuracy = 100,
        .pp = 20,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MAGIC_COAT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_SPD_UP_1,
    },

    [MOVE_LASER_FOCUS] =
    {
        .effect = EFFECT_LASER_FOCUS,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 30,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .flags = FLAG_SNATCH_AFFECTED,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_ATK_UP_1,
    },

    [MOVE_GEAR_UP] =
    {
        .effect = EFFECT_GEAR_UP,
        .power = 0,
        .type = TYPE_STEEL,
        .accuracy = 0,
        .pp = 20,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .flags = FLAG_SNATCH_AFFECTED,
        .flags2 = FLAG_MAGNET_MOVE,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_SPATK_UP_1,
    },

    [MOVE_THROAT_CHOP] =
    {
        .effect = EFFECT_THROAT_CHOP,
        .power = 80,
        .type = TYPE_DARK,
        .accuracy = 100,
        .pp = 15,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_HAS_SECONDARY_EFFECT,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 160,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_POLLEN_PUFF] =
    {
        .effect = EFFECT_DAMAGE_ENEMY_OR_HEAL_ALLY,
        .power = 90,
        .type = TYPE_BUG,
        .accuracy = 100,
        .pp = 15,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_BALL_AND_BOMB_MOVE,
        .split = SPLIT_SPECIAL,
        .zMovePower = 175,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_ANCHOR_SHOT] =
    {
        .effect = EFFECT_TARGET_PREVENT_ESCAPE_ON_HIT,
        .power = 80,
        .type = TYPE_STEEL,
        .accuracy = 100,
        .pp = 20,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED |  FLAG_KINGS_ROCK_AFFECTED | FLAG_HAS_SECONDARY_EFFECT | FLAG_AURA_BEAM_CANNON_GUN_PULSE_PUMP_SHOT_AND_ZOOKA_MOVE,
        .flags2 = FLAG_SLOTTED_SHELL_MOVE,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 160,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_PSYCHIC_TERRAIN] =
    {
        .effect = EFFECT_PSYCHIC_TERRAIN,
        .power = 0,
        .type = TYPE_PSYCHIC,
        .accuracy = 0,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_ALL_BATTLERS,
        .priority = 0,
        .flags = 0,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_SPATK_UP_1,
    },

    [MOVE_LUNGE] =
    {
        .effect = EFFECT_TARGET_ATTACK_DOWN_1_ON_HIT,
        .power = 80,
        .type = TYPE_BUG,
        .accuracy = 100,
        .pp = 15,
        .secondaryEffectChance = 100,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_HAS_SECONDARY_EFFECT,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 160,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_FIRE_LASH] =
    {
        .effect = EFFECT_TARGET_DEFENSE_DOWN_1_ON_HIT,
        .power = 80,
        .type = TYPE_FIRE,
        .accuracy = 100,
        .pp = 15,
        .secondaryEffectChance = 100,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_HAS_SECONDARY_EFFECT,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 160,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_POWER_TRIP] =
    {
        .effect = EFFECT_STORED_POWER,
        .power = 20,
        .type = TYPE_DARK,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .flags2 = FLAG_SCENT_MARK_AFFECTED,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 100,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_BURN_UP] =
    {
        .effect = EFFECT_BURN_UP,
        .power = 130,
        .type = TYPE_FIRE,
        .accuracy = 100,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_THAW_USER,
        .split = SPLIT_SPECIAL,
        .zMovePower = 195,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_SPEED_SWAP] =
    {
        .effect = EFFECT_SPEED_SWAP,
        .power = 0,
        .type = TYPE_PSYCHIC,
        .accuracy = 0,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_SPD_UP_1,
    },

    [MOVE_SMART_STRIKE] =
    {
        .effect = EFFECT_HIT,
        .power = 70,
        .type = TYPE_STEEL,
        .accuracy = 0,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .flags2 = FLAG_SCENT_MARK_AFFECTED,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 140,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_PURIFY] =
    {
        .effect = EFFECT_PURIFY,
        .power = 0,
        .type = TYPE_POISON,
        .accuracy = 0,
        .pp = 20,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MAGIC_COAT_AFFECTED,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_ALL_STATS_UP_1,
    },

    [MOVE_REVELATION_DANCE] =
    {
        .effect = EFFECT_MATCH_USER_FIRST_TYPE,
        .power = 90,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 15,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_DANCING_MOVE,
        .flags2 = FLAG_SCENT_MARK_AFFECTED,
        .split = SPLIT_SPECIAL,
        .zMovePower = 175,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_CORE_ENFORCER] =
    {
        .effect = EFFECT_CORE_ENFORCER,
        .power = 100,
        .type = TYPE_DRAGON,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 140,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_TROP_KICK] =
    {
        .effect = EFFECT_TARGET_ATTACK_DOWN_1_ON_HIT,
        .power = 70,
        .type = TYPE_GRASS,
        .accuracy = 100,
        .pp = 15,
        .secondaryEffectChance = 100,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_HAS_SECONDARY_EFFECT,
        .flags2 = FLAG_AIRBOURNE_STYLE_BOOST,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 140,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_INSTRUCT] =
    {
        .effect = EFFECT_INSTRUCT,
        .power = 0,
        .type = TYPE_PSYCHIC,
        .accuracy = 0,
        .pp = 15,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_SPATK_UP_1,
    },

    [MOVE_BEAK_BLAST] =
    {
        .effect = EFFECT_BEAK_BLAST,
        .power = 100,
        .type = TYPE_FLYING,
        .accuracy = 100,
        .pp = 15,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = -3,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_BALL_AND_BOMB_MOVE,
        .flags2 = FLAG_SCENT_MARK_AFFECTED,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 180,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_CLANGING_SCALES] =
    {
        .effect = EFFECT_CLANGING_SCALES,
        .power = 110,
        .type = TYPE_DRAGON,
        .accuracy = 100,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_BOTH,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_SOUND_BASED_MOVE,
        .split = SPLIT_SPECIAL,
        .zMovePower = 185,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_DRAGON_HAMMER] =
    {
        .effect = EFFECT_HIT,
        .power = 90,
        .type = TYPE_DRAGON,
        .accuracy = 100,
        .pp = 15,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .flags2 = FLAG_SCENT_MARK_AFFECTED,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 175,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_BRUTAL_SWING] =
    {
        .effect = EFFECT_HIT,
        .power = 60,
        .type = TYPE_DARK,
        .accuracy = 100,
        .pp = 20,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_FOES_AND_ALLY,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 120,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_AURORA_VEIL] =
    {
        .effect = EFFECT_USER_SIDE_BOTH_PHYSICAL_SPECIAL_WALL,
        .power = 0,
        .type = TYPE_ICE,
        .accuracy = 0,
        .pp = 20,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .flags = FLAG_SNATCH_AFFECTED,
        .flags2 = FLAG_WEATHER_RELATED_MOVE | FLAG_COSMIC_ENERGYZED_MOVE,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_SPD_UP_1,
    },

    [MOVE_SHELL_TRAP] =
    {
        .effect = EFFECT_SHELL_TRAP,
        .power = 150,
        .type = TYPE_FIRE,
        .accuracy = 100,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_OPPONENTS_FIELD,
        .priority = -3,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .split = SPLIT_SPECIAL,
        .zMovePower = 200,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_FLEUR_CANNON] =
    {
        .effect = EFFECT_OVERHEAT,
        .power = 130,
        .type = TYPE_FAIRY,
        .accuracy = 90,
        .pp = 5,
        .secondaryEffectChance = 100,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_AURA_BEAM_CANNON_GUN_PULSE_PUMP_SHOT_AND_ZOOKA_MOVE,
        .split = SPLIT_SPECIAL,
        .zMovePower = 195,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_PSYCHIC_FANGS] =
    {
        .effect = EFFECT_BRICK_BREAK,
        .power = 85,
        .type = TYPE_PSYCHIC,
        .accuracy = 100,
        .pp = 15,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_BITING_MOVE,
        .flags2 = FLAG_FANG_MOVE,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 140,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_STOMPING_TANTRUM] =
    {
        .effect = EFFECT_STOMPING_TANTRUM,
        .power = 75,
        .type = TYPE_GROUND,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .flags2 = FLAG_SCENT_MARK_AFFECTED,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 140,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_SHADOW_BONE] =
    {
        .effect = EFFECT_TARGET_DEFENSE_DOWN_1_ON_HIT,
        .power = 85,
        .type = TYPE_GHOST,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 20,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_HAS_SECONDARY_EFFECT,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 160,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_ACCELEROCK] =
    {
        .effect = EFFECT_HIT,
        .power = 40,
        .type = TYPE_ROCK,
        .accuracy = 100,
        .pp = 20,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 1,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .flags2 = FLAG_SCENT_MARK_AFFECTED,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 100,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_LIQUIDATION] =
    {
        .effect = EFFECT_TARGET_DEFENSE_DOWN_1_ON_HIT,
        .power = 85,
        .type = TYPE_WATER,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 20,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_HAS_SECONDARY_EFFECT,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 160,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_PRISMATIC_LASER] =
    {
        .effect = EFFECT_USER_RECHARGE,
        .power = 160,
        .type = TYPE_PSYCHIC,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .split = SPLIT_SPECIAL,
        .zMovePower = 200,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_SPECTRAL_THIEF] =
    {
        .effect = EFFECT_SPECTRAL_THIEF,
        .power = 90,
        .type = TYPE_GHOST,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 100,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 175,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_SUNSTEEL_STRIKE] =
    {
        .effect = EFFECT_STAR_ICON,
        .power = 100,
        .type = TYPE_STEEL,
        .accuracy = 100,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_IGNORE_TARGET_ABILITIES,
        .flags2 = FLAG_SCENT_MARK_AFFECTED,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 180,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_MOONGEIST_BEAM] =
    {
        .effect = EFFECT_STAR_ICON,
        .power = 100,
        .type = TYPE_GHOST,
        .accuracy = 100,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_IGNORE_TARGET_ABILITIES | FLAG_AURA_BEAM_CANNON_GUN_PULSE_PUMP_SHOT_AND_ZOOKA_MOVE,
        .flags2 = FLAG_COSMIC_ENERGYZED_MOVE | FLAG_SCENT_MARK_AFFECTED,
        .split = SPLIT_SPECIAL,
        .zMovePower = 180,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_TEARFUL_LOOK] =
    {
        .effect = EFFECT_NOBLE_ROAR,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 20,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAGIC_COAT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_DEF_UP_1,
    },

    [MOVE_ZING_ZAP] =
    {
        .effect = EFFECT_TARGET_FLINCH_ON_HIT,
        .power = 80,
        .type = TYPE_ELECTRIC,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 30,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 160,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_NATURES_MADNESS] =
    {
        .effect = EFFECT_TARGET_REDUCE_50_HP,
        .power = 1,
        .type = TYPE_FAIRY,
        .accuracy = 90,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .split = SPLIT_SPECIAL,
        .zMovePower = 100,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_MULTI_ATTACK] =
    {
        .power = 120,
        .zMovePower = 190,
        .effect = EFFECT_CHANGE_TYPE_ON_ITEM,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .flags2 = FLAG_SCENT_MARK_AFFECTED,
        .split = SPLIT_PHYSICAL,
        .argument = HOLD_EFFECT_MEMORY,
        .argument2 = EQUIP_SLOT_3,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_MIND_BLOWN] =
    {
        .effect = EFFECT_MIND_BLOWN,
        .power = 150,
        .type = TYPE_FIRE,
        .accuracy = 100,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_FOES_AND_ALLY,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .split = SPLIT_SPECIAL,
        .zMovePower = 200,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_PLASMA_FISTS] =
    {
        .effect = EFFECT_PLASMA_FISTS,
        .power = 100,
        .type = TYPE_ELECTRIC,
        .accuracy = 100,
        .pp = 15,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_PUNCHING_MOVE,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 180,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_PHOTON_GEYSER] =
    {
        .effect = EFFECT_PHOTON_GEYSER,
        .power = 100,
        .type = TYPE_PSYCHIC,
        .accuracy = 100,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_IGNORE_TARGET_ABILITIES,
        .flags2 = FLAG_COSMIC_ENERGYZED_MOVE,
        .split = SPLIT_SPECIAL,
        .zMovePower = 180,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_ZIPPY_ZAP] =
    {
        .power = 80,
        .effect = EFFECT_USER_EVASION_UP_1_ON_HIT,
        .pp = 10,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_HAS_SECONDARY_EFFECT,
        .zMovePower = 160,
        .type = TYPE_ELECTRIC,
        .accuracy = 100,
        .secondaryEffectChance = 100,
        .target = MOVE_TARGET_SELECTED,
        .priority = 2,
        .split = SPLIT_PHYSICAL,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_SPLISHY_SPLASH] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_8
            .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_HAS_SECONDARY_EFFECT,
        #else
            .flags = FLAG_PROTECT_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_HAS_SECONDARY_EFFECT,
        #endif
        .effect = EFFECT_TARGET_PARALYZE_ON_HIT,
        .power = 90,
        .type = TYPE_WATER,
        .accuracy = 100,
        .pp = 15,
        .secondaryEffectChance = 30,
        .target = MOVE_TARGET_BOTH,
        .priority = 0,
        .split = SPLIT_SPECIAL,
        .zMovePower = 175,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_FLOATY_FALL] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_8
            .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_HAS_SECONDARY_EFFECT,
        #else
            .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_HAS_SECONDARY_EFFECT,
        #endif
        .effect = EFFECT_TARGET_FLINCH_ON_HIT,
        .power = 90,
        .type = TYPE_FLYING,
        .accuracy = 95,
        .pp = 15,
        .secondaryEffectChance = 30,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 175,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_PIKA_PAPOW] =
    {
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .flags2 = FLAG_SCENT_MARK_AFFECTED,
        .effect = EFFECT_USER_MORE_HAPINESS_MORE_DAMAGE,
        .power = 1,
        .type = TYPE_ELECTRIC,
        .accuracy = 0,
        .pp = 20,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .split = SPLIT_SPECIAL,
        .zMovePower = 160,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_BOUNCY_BUBBLE] =
    {
        .power = 60,
        .pp = 20,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .zMovePower = 120,
        .effect = EFFECT_USER_DRAIN_100_ON_HIT,
        .type = TYPE_WATER,
        .accuracy = 100,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .split = SPLIT_SPECIAL,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_BUZZY_BUZZ] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_8
            .power = 60,
            .pp = 20,
            .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
            .zMovePower = 120,
        #else
            .power = 90,
            .pp = 15,
            .flags = FLAG_PROTECT_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
            .zMovePower = 175,
        #endif
        .effect = EFFECT_TARGET_PARALYZE_ON_HIT,
        .type = TYPE_ELECTRIC,
        .accuracy = 100,
        .secondaryEffectChance = 100,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .split = SPLIT_SPECIAL,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_SIZZLY_SLIDE] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_8
            .power = 60,
            .pp = 20,
            .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_THAW_USER,
            .zMovePower = 120,
        #else
            .power = 90,
            .pp = 15,
            .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_THAW_USER,
            .zMovePower = 175,
        #endif
        .effect = EFFECT_TARGET_BURN_ON_HIT,
        .type = TYPE_FIRE,
        .accuracy = 100,
        .secondaryEffectChance = 100,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .split = SPLIT_PHYSICAL,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_GLITZY_GLOW] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_8
            .power = 80,
            .accuracy = 95,
            .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
            .zMovePower = 160,
        #else
            .power = 90,
            .accuracy = 100,
            .flags = FLAG_PROTECT_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
            .zMovePower = 175,
        #endif
        .effect = EFFECT_GLITZY_GLOW,
        .type = TYPE_PSYCHIC,
        .pp = 15,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .split = SPLIT_SPECIAL,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_BADDY_BAD] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_8
            .power = 80,
            .accuracy = 95,
            .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
            .zMovePower = 160,
        #else
            .power = 90,
            .accuracy = 100,
            .flags = FLAG_PROTECT_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
            .zMovePower = 175,
        #endif
        .effect = EFFECT_BADDY_BAD,
        .type = TYPE_DARK,
        .pp = 15,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .split = SPLIT_SPECIAL,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_SAPPY_SEED] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_8
            .power = 100,
            .accuracy = 90,
            .pp = 10,
            .flags = FLAG_PROTECT_AFFECTED | FLAG_MAGIC_COAT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
            .zMovePower = 180,
        #else
            .power = 90,
            .accuracy = 100,
            .pp = 15,
            .flags = FLAG_PROTECT_AFFECTED | FLAG_MAGIC_COAT_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
            .zMovePower = 175,
        #endif
        .effect = EFFECT_SAPPY_SEED,
        .type = TYPE_GRASS,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .split = SPLIT_PHYSICAL,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_FREEZY_FROST] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_8
            .power = 100,
            .accuracy = 90,
            .pp = 10,
            .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
            .zMovePower = 180,
        #else
            .power = 90,
            .accuracy = 100,
            .pp = 15,
            .flags = FLAG_PROTECT_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
            .zMovePower = 175,
        #endif
        .effect = EFFECT_FREEZY_FROST,
        .type = TYPE_ICE,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .split = SPLIT_SPECIAL,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_SPARKLY_SWIRL] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_8
            .power = 120,
            .accuracy = 85,
            .pp = 5,
            .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
            .zMovePower = 190,
        #else
            .power = 90,
            .accuracy = 100,
            .pp = 15,
            .flags = FLAG_PROTECT_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
            .zMovePower = 175,
        #endif
        .effect = EFFECT_SPARKLY_SWIRL,
        .type = TYPE_FAIRY,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .split = SPLIT_SPECIAL,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_VEEVEE_VOLLEY] =
    {
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .flags2 = FLAG_SCENT_MARK_AFFECTED,
        .effect = EFFECT_USER_MORE_HAPINESS_MORE_DAMAGE,
        .power = 1,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 20,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 160,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_DOUBLE_IRON_BASH] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_8
            .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_PUNCHING_MOVE | FLAG_HAS_SECONDARY_EFFECT | FLAG_TWO_STRIKES,
        #else
            .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_DOUBLE_DAMAGE_ON_MINIMIZED_TARGET | FLAG_PUNCHING_MOVE | FLAG_HAS_SECONDARY_EFFECT | FLAG_TWO_STRIKES,
        #endif
        .effect = EFFECT_DOUBLE_IRON_BASH,
        .power = 60,
        .type = TYPE_STEEL,
        .accuracy = 100,
        .pp = 5,
        .secondaryEffectChance = 30,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 120,
        .zMoveEffect = Z_EFFECT_NONE,
    },
    
    [MOVE_DYNAMAX_CANNON] =
    {
        .effect = EFFECT_DYNAMAX_DOUBLE_DMG,
        .power = 100,
        .type = TYPE_DRAGON,
        .accuracy = 100,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_AURA_BEAM_CANNON_GUN_PULSE_PUMP_SHOT_AND_ZOOKA_MOVE,
        .flags2 = FLAG_SCENT_MARK_AFFECTED,
        .split = SPLIT_SPECIAL,
        .zMovePower = 180,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_SNIPE_SHOT] =
    {
        .effect = EFFECT_SNIPE_SHOT,
        .power = 80,
        .type = TYPE_WATER,
        .accuracy = 100,
        .pp = 15,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_HIGH_CRITICAL_HIT_RATIO | FLAG_AURA_BEAM_CANNON_GUN_PULSE_PUMP_SHOT_AND_ZOOKA_MOVE,
        .flags2 = FLAG_SLOTTED_SHELL_MOVE | FLAG_SCENT_MARK_AFFECTED,
        .split = SPLIT_SPECIAL,
        .zMovePower = 160,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_JAW_LOCK] =
    {
        .effect = EFFECT_JAW_LOCK,
        .power = 80,
        .type = TYPE_ROCK,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_BITING_MOVE,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 160,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_STUFF_CHEEKS] =
    {
        .effect = EFFECT_STUFF_CHEEKS,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .flags = FLAG_SNATCH_AFFECTED,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_NO_RETREAT] =
    {
        .effect = EFFECT_NO_RETREAT,   //TODO
        .power = 0,
        .type = TYPE_FIGHTING,
        .accuracy = 0,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .flags = FLAG_SNATCH_AFFECTED,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_TAR_SHOT] =
    {
        .effect = EFFECT_TAR_SHOT,
        .power = 50,
        .type = TYPE_ROCK,
        .accuracy = 100,
        .pp = 15,
        .secondaryEffectChance = 100,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_AURA_BEAM_CANNON_GUN_PULSE_PUMP_SHOT_AND_ZOOKA_MOVE,
        .flags2 = FLAG_SLOTTED_SHELL_MOVE,
        .split = SPLIT_SPECIAL,
        .zMovePower = 100,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_MAGIC_POWDER] =
    {
        .effect = EFFECT_SET_TYPE,
        .power = 0,
        .type = TYPE_PSYCHIC,
        .accuracy = 100,
        .pp = 20,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MAGIC_COAT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_POWDER_AND_SPORE_MOVE,
        .split = SPLIT_STATUS,
        .argument = TYPE_PSYCHIC,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_DRAGON_DARTS] =
    {
        .effect = EFFECT_TARGET_DOUBLE_HIT, //TODO
        .power = 50,
        .type = TYPE_DRAGON,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_TWO_STRIKES,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 100,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_TEATIME] =
    {
        .effect = EFFECT_TEATIME,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .flags = 0,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_OCTOLOCK] =
    {
        .effect = EFFECT_OCTOLOCK,
        .power = 0,
        .type = TYPE_FIGHTING,
        .accuracy = 100,
        .pp = 15,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_BOLT_BEAK] =
    {
        .effect = EFFECT_BOLT_BEAK,
        .power = 85,
        .type = TYPE_ELECTRIC,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .flags2 = FLAG_SCENT_MARK_AFFECTED,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 160,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_FISHIOUS_REND] =
    {
        .effect = EFFECT_BOLT_BEAK,
        .power = 85,
        .type = TYPE_WATER,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_BITING_MOVE,
        .flags2 = FLAG_SCENT_MARK_AFFECTED,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 160,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_COURT_CHANGE] =
    {
        .effect = EFFECT_COURT_CHANGE,   
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_ALL_BATTLERS,
        .priority = 0,
        .flags = FLAG_MIRROR_MOVE_AFFECTED,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_CLANGOROUS_SOUL] =
    {
        .effect = EFFECT_CLANGOROUS_SOUL,
        .power = 0,
        .type = TYPE_DRAGON,
        .accuracy = 100,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .flags = FLAG_SNATCH_AFFECTED | FLAG_SOUND_BASED_MOVE,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_BODY_PRESS] =
    {
        .effect = EFFECT_BODY_PRESS,
        .power = 80,
        .type = TYPE_FIGHTING,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .flags2 = FLAG_SCENT_MARK_AFFECTED,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 160,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_DECORATE] =
    {
        .effect = EFFECT_DECORATE,
        .power = 0,
        .type = TYPE_FAIRY,
        .accuracy = 0,
        .pp = 15,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = 0,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_DRUM_BEATING] =
    {
        .effect = EFFECT_TARGET_SPEED_DOWN_1_ON_HIT,
        .power = 80,
        .type = TYPE_GRASS,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 100,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_HAS_SECONDARY_EFFECT,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 160,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_SNAP_TRAP] =
    {
        .effect = EFFECT_TARGET_PREVENT_ESCAPE_AND_HURT_EACH_TURN,
        .power = 80,
        .type = TYPE_STEEL,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 100,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_BITING_MOVE,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 100,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_PYRO_BALL] =
    {
        .effect = EFFECT_TARGET_BURN_ON_HIT,
        .power = 120,
        .type = TYPE_FIRE,
        .accuracy = 90,
        .pp = 5,
        .secondaryEffectChance = 10,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_BALL_AND_BOMB_MOVE | FLAG_HAS_SECONDARY_EFFECT | FLAG_THAW_USER,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 190,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_BEHEMOTH_BLADE] =
    {
        .effect = EFFECT_DYNAMAX_DOUBLE_DMG,
        .power = 100,
        .type = TYPE_STEEL,
        .accuracy = 100,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .flags2 = FLAG_SLICING_MOVE | FLAG_SCENT_MARK_AFFECTED,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 180,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_BEHEMOTH_BASH] =
    {
        .effect = EFFECT_DYNAMAX_DOUBLE_DMG,
        .power = 100,
        .type = TYPE_STEEL,
        .accuracy = 100,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .flags2 = FLAG_SCENT_MARK_AFFECTED,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 180,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_AURA_WHEEL] =
    {
        .effect = EFFECT_AURA_WHEEL,
        .power = 110,
        .type = TYPE_ELECTRIC,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 100,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 185,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_BREAKING_SWIPE] =
    {
        .effect = EFFECT_TARGET_ATTACK_DOWN_1_ON_HIT,
        .power = 60,
        .type = TYPE_DRAGON,
        .accuracy = 100,
        .pp = 15,
        .secondaryEffectChance = 100,
        .target = MOVE_TARGET_BOTH,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_HAS_SECONDARY_EFFECT,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 120,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_BRANCH_POKE] =
    {
        .effect = EFFECT_HIT,
        .power = 40,
        .type = TYPE_GRASS,
        .accuracy = 100,
        .pp = 40,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .flags2 = FLAG_SCENT_MARK_AFFECTED,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 100,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_OVERDRIVE] =
    {
        .effect = EFFECT_HIT,
        .power = 80,
        .type = TYPE_ELECTRIC,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_BOTH,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_SOUND_BASED_MOVE,
        .split = SPLIT_SPECIAL,
        .zMovePower = 160,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_APPLE_ACID] =
    {
        .effect = EFFECT_TARGET_SPECIAL_DEFENSE_DOWN_1_ON_HIT,
        .power = 80,
        .type = TYPE_GRASS,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 100,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_HAS_SECONDARY_EFFECT,
        .flags2 = FLAG_ACID_MOVE,
        .split = SPLIT_SPECIAL,
        .zMovePower = 160,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_GRAV_APPLE] =
    {
        .effect = EFFECT_GRAV_APPLE,
        .power = 80,
        .type = TYPE_GRASS,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 100,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_HAS_SECONDARY_EFFECT,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 160,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_SPIRIT_BREAK] =
    {
        .effect = EFFECT_TARGET_SPECIAL_ATTACK_DOWN_1_ON_HIT,
        .power = 75,
        .type = TYPE_FAIRY,
        .accuracy = 100,
        .pp = 15,
        .secondaryEffectChance = 100,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_HAS_SECONDARY_EFFECT,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 140,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_STRANGE_STEAM] =
    {
        .effect = EFFECT_TARGET_CONFUSE_ON_HIT,
        .power = 90,
        .type = TYPE_FAIRY,
        .accuracy = 95,
        .pp = 10,
        .secondaryEffectChance = 20,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_HAS_SECONDARY_EFFECT,
        .split = SPLIT_SPECIAL,
        .zMovePower = 175,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_LIFE_DEW] =
    {
        .effect = EFFECT_JUNGLE_HEALING,
        .power = 0,
        .type = TYPE_WATER,
        .accuracy = 0,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .flags = FLAG_SNATCH_AFFECTED,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_OBSTRUCT] =
    {
        .effect = EFFECT_USER_PREVENT_MOVE,
        .power = 0,
        .type = TYPE_DARK,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_USER,
        .priority = 4,
        .flags = FLAG_PROTECTION_MOVE,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_FALSE_SURRENDER] =
    {
        .effect = EFFECT_HIT,
        .power = 80,
        .type = TYPE_DARK,
        .accuracy = 0,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .flags2 = FLAG_SCENT_MARK_AFFECTED,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 160,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_METEOR_ASSAULT] =
    {
        .effect = EFFECT_USER_RECHARGE,
        .power = 150,
        .type = TYPE_FIGHTING,
        .accuracy = 100,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 200,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_ETERNABEAM] =
    {
        .effect = EFFECT_USER_RECHARGE,
        .power = 160,
        .type = TYPE_DRAGON,
        .accuracy = 90,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_AURA_BEAM_CANNON_GUN_PULSE_PUMP_SHOT_AND_ZOOKA_MOVE,
        .split = SPLIT_SPECIAL,
        .zMovePower = 200,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_STEEL_BEAM] =
    {
        .effect = EFFECT_STEEL_BEAM,
        .power = 140,
        .type = TYPE_STEEL,
        .accuracy = 95,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_AURA_BEAM_CANNON_GUN_PULSE_PUMP_SHOT_AND_ZOOKA_MOVE,
        .split = SPLIT_SPECIAL,
        .zMovePower = 200,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_EXPANDING_FORCE] =
    {
        .effect = EFFECT_EXPANDING_FORCE,   
        .power = 80,
        .type = TYPE_PSYCHIC,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .flags2 = FLAG_SCENT_MARK_AFFECTED,
        .split = SPLIT_SPECIAL,
        .zMovePower = 160,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_STEEL_ROLLER] =
    {
        .effect = EFFECT_REMOVE_TERRAIN,
        .power = 65,
        .type = TYPE_STEEL,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 120,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_SCALE_SHOT] =
    {
        .effect = EFFECT_SCALE_SHOT,
        .power = 25,
        .type = TYPE_DRAGON,
        .accuracy = 90,
        .pp = 20,
        .secondaryEffectChance = 100,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_AURA_BEAM_CANNON_GUN_PULSE_PUMP_SHOT_AND_ZOOKA_MOVE,
        .flags2 = FLAG_SLOTTED_SHELL_MOVE,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 140,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_METEOR_BEAM] =
    {
        .effect = EFFECT_USER_FIRST_TURN_PREPARE_SECOND_TURN_ATTACK,
        .power = 120,
        .type = TYPE_ROCK,
        .accuracy = 90,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_AURA_BEAM_CANNON_GUN_PULSE_PUMP_SHOT_AND_ZOOKA_MOVE,
        .split = SPLIT_SPECIAL,
        .zMovePower = 190,
        .zMoveEffect = Z_EFFECT_NONE,
        .argument = STAT_SPATK,
    },

    [MOVE_SHELL_SIDE_ARM] =
    {
        .effect = EFFECT_SHELL_SIDE_ARM,
        .power = 90,
        .type = TYPE_POISON,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_HAS_SECONDARY_EFFECT,
        .split = SPLIT_SPECIAL,
        .zMovePower = 175,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_MISTY_EXPLOSION] =
    {
        .effect = EFFECT_USER_FAINT,
        .power = 100,
        .type = TYPE_FAIRY,
        .accuracy = 100,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_FOES_AND_ALLY,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .split = SPLIT_SPECIAL,
        .zMovePower = 180,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_GRASSY_GLIDE] =
    {
        .effect = EFFECT_GRASSY_GLIDE,
        .power = 60,
        .type = TYPE_GRASS,
        .accuracy = 100,
        .pp = 20,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .flags2 = FLAG_SCENT_MARK_AFFECTED,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 120,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_RISING_VOLTAGE] =
    {
        .effect = EFFECT_RISING_VOLTAGE,   
        .power = 70,
        .type = TYPE_ELECTRIC,
        .accuracy = 100,
        .pp = 20,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .flags2 = FLAG_SCENT_MARK_AFFECTED,
        .split = SPLIT_SPECIAL,
        .zMovePower = 140,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_TERRAIN_PULSE] =
    {
        .effect = EFFECT_TERRAIN_PULSE,
        .power = 50,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_AURA_BEAM_CANNON_GUN_PULSE_PUMP_SHOT_AND_ZOOKA_MOVE,
        .flags2 = FLAG_SCENT_MARK_AFFECTED,
        .split = SPLIT_SPECIAL,
        .zMovePower = 100,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_SKITTER_SMACK] =
    {
        .effect = EFFECT_TARGET_SPECIAL_ATTACK_DOWN_1_ON_HIT,
        .power = 70,
        .type = TYPE_BUG,
        .accuracy = 90,
        .pp = 10,
        .secondaryEffectChance = 100,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_HAS_SECONDARY_EFFECT,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 140,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_BURNING_JEALOUSY] =
    {
        .effect = EFFECT_TARGET_BURN_ON_HIT,
        .power = 70,
        .type = TYPE_FIRE,
        .accuracy = 100,
        .pp = 5,
        .secondaryEffectChance = 100,
        .target = MOVE_TARGET_BOTH,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_HAS_SECONDARY_EFFECT,
        .split = SPLIT_SPECIAL,
        .zMovePower = 140,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_LASH_OUT] =
    {
        .effect = EFFECT_LASH_OUT,
        .power = 75,
        .type = TYPE_DARK,
        .accuracy = 100,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .flags2 = FLAG_SCENT_MARK_AFFECTED,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 140,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_POLTERGEIST] =
    {
        .effect = EFFECT_POLTERGEIST,
        .power = 110,
        .type = TYPE_GHOST,
        .accuracy = 90,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 185,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_CORROSIVE_GAS] =
    {
        .effect = EFFECT_CORROSIVE_GAS,
        .power = 0,
        .type = TYPE_POISON,
        .accuracy = 100,
        .pp = 40,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_FOES_AND_ALLY,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MAGIC_COAT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_COACHING] =
    {
        .effect = EFFECT_COACHING,
        .power = 0,
        .type = TYPE_FIGHTING,
        .accuracy = 0,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_ALLY,
        .priority = 0,
        .flags = 0,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_FLIP_TURN] =
    {
        .effect = EFFECT_USER_FORCED_SWITCH_OUT_ON_HIT,
        .power = 60,
        .type = TYPE_WATER,
        .accuracy = 100,
        .pp = 20,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 120,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_TRIPLE_AXEL] =
    {
        .effect = EFFECT_TARGET_TRIPLE_HIT_MORE_DAMAGE_EACH_HIT,
        .power = 20,
        .type = TYPE_ICE,
        .accuracy = 90,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 100,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_DUAL_WINGBEAT] =
    {
        .effect = EFFECT_TARGET_DOUBLE_HIT,
        .power = 40,
        .type = TYPE_FLYING,
        .accuracy = 90,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_TWO_STRIKES,
        .flags2 = FLAG_WING_MOVE,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 100,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_SCORCHING_SANDS] =
    {
        .effect = EFFECT_SCALD,
        .power = 70,
        .type = TYPE_GROUND,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 30,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_HAS_SECONDARY_EFFECT | FLAG_THAW_USER,
        .split = SPLIT_SPECIAL,
        .zMovePower = 140,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_JUNGLE_HEALING] =
    {
        .effect = EFFECT_JUNGLE_HEALING,
        .power = 0,
        .type = TYPE_GRASS,
        .accuracy = 0,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_WICKED_BLOW] =
    {
        .effect = EFFECT_HIT,
        .power = 75,
        .type = TYPE_DARK,
        .accuracy = 100,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_PUNCHING_MOVE,
        .flags2 = FLAG_SCENT_MARK_AFFECTED | FLAG_ALWAYS_CRITICAL_HIT,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 160,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_SURGING_STRIKES] =
    {
        .effect = EFFECT_TRIPLE_HIT,
        .power = 25,
        .type = TYPE_WATER,
        .accuracy = 100,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_PUNCHING_MOVE,
        .flags2 = FLAG_ALWAYS_CRITICAL_HIT,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 100,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_THUNDER_CAGE] =
    {
        .effect = EFFECT_TARGET_PREVENT_ESCAPE_AND_HURT_EACH_TURN,
        .power = 80,
        .type = TYPE_ELECTRIC,
        .accuracy = 90,
        .pp = 15,
        .secondaryEffectChance = 100,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .split = SPLIT_SPECIAL,
        .zMovePower = 160,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_DRAGON_ENERGY] =
    {
        .effect = EFFECT_ERUPTION,
        .power = 150,
        .type = TYPE_DRAGON,
        .accuracy = 100,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_BOTH,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .split = SPLIT_SPECIAL,
        .zMovePower = 200,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_FREEZING_GLARE] =
    {
        .power = 90,
        .effect = EFFECT_TARGET_FROSTBITE_ON_HIT,
        .type = TYPE_PSYCHIC,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 20,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_HAS_SECONDARY_EFFECT,
        .split = SPLIT_SPECIAL,
        .zMovePower = 175,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_FIERY_WRATH] =
    {
        .effect = EFFECT_TARGET_FLINCH_ON_HIT,
        .power = 90,
        .type = TYPE_DARK,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 20,
        .target = MOVE_TARGET_BOTH,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        .split = SPLIT_SPECIAL,
        .zMovePower = 175,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_THUNDEROUS_KICK] =
    {
        .effect = EFFECT_TARGET_DEFENSE_DOWN_1_ON_HIT,
        .power = 90,
        .type = TYPE_FIGHTING,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 100,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_HAS_SECONDARY_EFFECT,
        .flags2 = FLAG_AIRBOURNE_STYLE_BOOST,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 175,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_GLACIAL_LANCE] =
    {
        .effect = EFFECT_HIT,
        .power = 120,
        .type = TYPE_ICE,
        .accuracy = 100,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_BOTH,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 195,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_ASTRAL_BARRAGE] =
    {
        .effect = EFFECT_HIT,
        .power = 120,
        .type = TYPE_GHOST,
        .accuracy = 100,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_BOTH,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .split = SPLIT_SPECIAL,
        .zMovePower = 190,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_EERIE_SPELL] =
    {
        .effect = EFFECT_EERIE_SPELL,
        .power = 80,
        .type = TYPE_PSYCHIC,
        .accuracy = 100,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_HAS_SECONDARY_EFFECT | FLAG_SOUND_BASED_MOVE,
        .split = SPLIT_SPECIAL,
        .zMovePower = 160,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_DIRE_CLAW] =
    {
        .effect = EFFECT_DIRE_CLAW,
        .power = 80,
        .type = TYPE_POISON,
        .accuracy = 100,
        .pp = 15,
        .secondaryEffectChance = 50,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 120,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_PSYSHIELD_BASH] =
    {
        .effect = EFFECT_DEFENSE_UP_1_ON_HIT,
        .power = 70,
        .type = TYPE_PSYCHIC,
        .accuracy = 90,
        .pp = 10,
        .secondaryEffectChance = 100,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 140,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_POWER_SHIFT] =
    {
        .effect = EFFECT_PLACEHOLDER, // EFFECT_POWER_SHIFT,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .flags = FLAG_MIRROR_MOVE_AFFECTED,
        .split = SPLIT_STATUS,
        .zMovePower = 100,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_STONE_AXE] =
    {
        .effect = EFFECT_STONE_AXE,
        .power = 65,
        .type = TYPE_ROCK,
        .accuracy = 90,
        .pp = 15,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .flags2 = FLAG_SLICING_MOVE,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 120,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_SPRINGTIDE_STORM] =
    {
        .effect = EFFECT_TARGET_ATTACK_DOWN_1_ON_HIT,
        .power = 100,
        .type = TYPE_FAIRY,
        .accuracy = 80,
        .pp = 5,
        .secondaryEffectChance = 30,
        .target = MOVE_TARGET_BOTH,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        .flags2 = FLAG_WIND_MOVE,
        .split = SPLIT_SPECIAL,
        .zMovePower = 175,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_MYSTICAL_POWER] =
    {
        .effect = EFFECT_USER_SPECIAL_ATTACK_UP_1_ON_HIT,
        .power = 70,
        .type = TYPE_PSYCHIC,
        .accuracy = 90,
        .pp = 10,
        .secondaryEffectChance = 100,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .split = SPLIT_SPECIAL,
        .zMovePower = 140,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_RAGING_FURY] =
    {
        .effect = EFFECT_USER_RAMPAGE,
        .power = 120,
        .type = TYPE_FIRE,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 100,
        .target = MOVE_TARGET_RANDOM,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 175,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_WAVE_CRASH] =
    {
        .effect = EFFECT_USER_RECOIL_33_SPEED_UP,
        .power = 120,
        .type = TYPE_WATER,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 100,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 140,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_CHLOROBLAST] =
    {
        .effect = EFFECT_MIND_BLOWN,
        .power = 150,
        .type = TYPE_GRASS,
        .accuracy = 95,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_FOES_AND_ALLY,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .split = SPLIT_SPECIAL,
        .zMovePower = 200,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_MOUNTAIN_GALE] =
    {
        .effect = EFFECT_TARGET_FLINCH_ON_HIT,
        .power = 100,
        .type = TYPE_ICE,
        .accuracy = 85,
        .pp = 10,
        .secondaryEffectChance = 30,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 180,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_VICTORY_DANCE] =
    {
        .effect = EFFECT_FEATHER_DANCE,
        .power = 0,
        .type = TYPE_FIGHTING,
        .accuracy = 0,
        .pp = 20,
        .secondaryEffectChance = 100,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .flags = FLAG_SNATCH_AFFECTED | FLAG_DANCING_MOVE,
        .split = SPLIT_STATUS,
        .zMovePower = 100,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_HEADLONG_RUSH] =
    {
        .effect = EFFECT_CLOSE_COMBAT,
        .power = 120,
        .type = TYPE_GROUND,
        .accuracy = 100,
        .pp = 5,
        .secondaryEffectChance = 100,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 180,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_BARB_BARRAGE] =
    {
        .effect = EFFECT_BARB_BARRAGE,
        .power = 60,
        .type = TYPE_POISON,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 50,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 120,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_ESPER_WING] =
    {
        .effect = EFFECT_USER_SPEED_UP_1_ON_HIT,
        .power = 80,
        .type = TYPE_PSYCHIC,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 100,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_HIGH_CRITICAL_HIT_RATIO,
        .flags2 = FLAG_WING_MOVE,
        .split = SPLIT_SPECIAL,
        .zMovePower = 140,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_BITTER_MALICE] =
    {
        .effect = EFFECT_TARGET_ATTACK_DOWN_1_ON_HIT,
        .power = 75,
        .type = TYPE_GHOST,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 100,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .split = SPLIT_SPECIAL,
        .zMovePower = 120,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_SHELTER] =
    {
        .effect = EFFECT_USER_DEFENSE_UP_2, // EFFECT_SHELTER,
        .power = 0,
        .type = TYPE_STEEL,
        .accuracy = 0,
        .pp = 10,
        .secondaryEffectChance = 100,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .flags = 0,
        .split = SPLIT_STATUS,
        .zMovePower = 100,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_TRIPLE_ARROWS] =
    {
        .effect = EFFECT_TRIPLE_ARROWS,
        .power = 90,
        .type = TYPE_FIGHTING,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 50,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_HIGH_CRITICAL_HIT_RATIO,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 100,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_INFERNAL_PARADE] =
    {
        .effect = EFFECT_INFERNAL_PARADE,
        .power = 60,
        .type = TYPE_GHOST,
        .accuracy = 100,
        .pp = 15,
        .secondaryEffectChance = 30,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .split = SPLIT_SPECIAL,
        .zMovePower = 120,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_CEASELESS_EDGE] =
    {
        .effect = EFFECT_CEASELESS_EDGE, // EFFECT_CEASELESS_EDGE,
        .power = 65,
        .type = TYPE_DARK,
        .accuracy = 90,
        .pp = 15,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .flags2 = FLAG_SLICING_MOVE,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 120,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_BLEAKWIND_STORM] =
    {
        .effect = EFFECT_TARGET_SPEED_DOWN_1_ON_HIT,
        .power = 100,
        .type = TYPE_FLYING,
        .accuracy = 80,
        .pp = 10,
        .secondaryEffectChance = 30,
        .target = MOVE_TARGET_BOTH,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .flags2 = FLAG_WIND_MOVE,
        .split = SPLIT_SPECIAL,
        .zMovePower = 175,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_WILDBOLT_STORM] =
    {
        .effect = EFFECT_TARGET_PARALYZE_ON_HIT,
        .power = 100,
        .type = TYPE_ELECTRIC,
        .accuracy = 80,
        .pp = 10,
        .secondaryEffectChance = 20,
        .target = MOVE_TARGET_BOTH,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .flags2 = FLAG_WIND_MOVE,
        .split = SPLIT_SPECIAL,
        .zMovePower = 175,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_SANDSEAR_STORM] =
    {
        .effect = EFFECT_TARGET_BURN_ON_HIT,
        .power = 100,
        .type = TYPE_GROUND,
        .accuracy = 80,
        .pp = 10,
        .secondaryEffectChance = 20,
        .target = MOVE_TARGET_BOTH,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .flags2 = FLAG_WIND_MOVE,
        .split = SPLIT_SPECIAL,
        .zMovePower = 175,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_LUNAR_BLESSING] =
    {
        .effect = EFFECT_JUNGLE_HEALING, // EFFECT_LUNAR_BLESSING,
        .power = 0,
        .type = TYPE_PSYCHIC,
        .accuracy = 0,
        .pp = 5,
        .secondaryEffectChance = 100,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .flags = FLAG_SNATCH_AFFECTED,
        .split = SPLIT_STATUS,
        .zMovePower = 100,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_TAKE_HEART] =
    {
        .effect = EFFECT_USER_SPECIAL_ATTACK_SPECIAL_DEFENSE_UP_1, // EFFECT_TAKE_HEART,
        .power = 0,
        .type = TYPE_PSYCHIC,
        .accuracy = 0,
        .pp = 10,
        .secondaryEffectChance = 100,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .flags = FLAG_SNATCH_AFFECTED,
        .split = SPLIT_STATUS,
        .zMovePower = 100,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_TERA_BLAST] =
    {
        .effect = EFFECT_PLACEHOLDER, // EFFECT_TERA_BLAST,
        .power = 80,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .split = SPLIT_SPECIAL,
        .zMovePower = 160,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_SILK_TRAP] =
    {
        .effect = EFFECT_USER_PREVENT_MOVE,
        .power = 0,
        .type = TYPE_BUG,
        .accuracy = 0,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_USER,
        .priority = 4,
        .flags = FLAG_PROTECTION_MOVE,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_RESET_STATS,
    },

    [MOVE_AXE_KICK] =
    {
        .effect = EFFECT_AXE_KICK,
        .power = 120,
        .type = TYPE_FIGHTING,
        .accuracy = 90,
        .pp = 10,
        .secondaryEffectChance = 30,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_CRASH_DAMAGE_IF_MISS,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 190,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_LAST_RESPECTS] =
    {
        .effect = EFFECT_LAST_RESPECTS, 
        .power = 50,
        .type = TYPE_GHOST,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .flags2 = FLAG_SCENT_MARK_AFFECTED,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 100,
        .zMoveEffect = Z_EFFECT_NONE
    },

    [MOVE_LUMINA_CRASH] =
    {
        .effect = EFFECT_TARGET_SPECIAL_DEFENSE_DOWN_2_ON_HIT,
        .power = 80,
        .type = TYPE_PSYCHIC,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 100,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_HAS_SECONDARY_EFFECT,
        .split = SPLIT_SPECIAL,
        .zMovePower = 160,
        .zMoveEffect = Z_EFFECT_NONE
    },

    [MOVE_ORDER_UP] =
    {
        .effect = EFFECT_ORDER_UP,
        .power = 80,
        .type = TYPE_DRAGON,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_HAS_SECONDARY_EFFECT,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 160,
        .zMoveEffect = Z_EFFECT_NONE
    },

    [MOVE_JET_PUNCH] =
    {
        .effect = EFFECT_HIT,
        .power = 60,
        .type = TYPE_WATER,
        .accuracy = 100,
        .pp = 15,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 1,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_PUNCHING_MOVE,
        .flags2 = FLAG_SCENT_MARK_AFFECTED,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 120,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_SPICY_EXTRACT] =
    {
        .effect = EFFECT_SPICY_EXTRACT,
        .power = 0,
        .type = TYPE_GRASS,
        .accuracy = 0,
        .pp = 15,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MAGIC_COAT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_NONE,
        // The datamine master sheet mentions uncopiable by Metronome but that sounds odd? not yet implemented
    },

    [MOVE_SPIN_OUT] =
    {
        .effect = EFFECT_SPIN_OUT,
        .power = 100,
        .type = TYPE_STEEL,
        .accuracy = 100,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 180,
        .zMoveEffect = Z_EFFECT_NONE
    },

    [MOVE_POPULATION_BOMB] =
    {
        .effect = EFFECT_POPULATION_BOMB,
        .power = 20,
        .type = TYPE_NORMAL,
        .accuracy = 90,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .flags2 = FLAG_SLICING_MOVE,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 40,
        .zMoveEffect = Z_EFFECT_NONE,
        //Supposedly uncallable by Metronome? (if so, needs implementation)
    },

    [MOVE_ICE_SPINNER] =
    {
        .effect = EFFECT_HIT_SET_REMOVE_TERRAIN,
        .power = 80,
        .type = TYPE_ICE,
        .accuracy = 100,
        .pp = 15,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 160,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_GLAIVE_RUSH] =
    {
        .effect = EFFECT_GLAIVE_RUSH,
        .power = 120,
        .type = TYPE_DRAGON,
        .accuracy = 100,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 190,
        .zMoveEffect = Z_EFFECT_NONE
    },

    [MOVE_REVIVAL_BLESSING] =
    {
        .effect = EFFECT_REVIVE,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 1,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .flags = 0,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_NONE,
        // Uncallable by Metronome (to be implemented)
    },

    [MOVE_SALT_CURE] =
    {
        .effect = EFFECT_SALT_CURE,
        .power = 40,
        .type = TYPE_ROCK,
        .accuracy = 100,
        .pp = 15,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_HAS_SECONDARY_EFFECT,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 80,
        .zMoveEffect = Z_EFFECT_NONE,
        // Supposedly uncallable by Metronome, but dubious
    },

    [MOVE_TRIPLE_DIVE] =
    {
        .effect = EFFECT_TRIPLE_HIT,
        .power = 30,
        .type = TYPE_WATER,
        .accuracy = 95,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 100,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_MORTAL_SPIN] =
    {
        .effect = EFFECT_SPEED_UP_1_AND_CLEAR_USER,
        .power = 30,
        .type = TYPE_POISON,
        .accuracy = 100,
        .pp = 15,
        .secondaryEffectChance = 100,
        .target = MOVE_TARGET_BOTH,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_HAS_SECONDARY_EFFECT,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 60,
        .zMoveEffect = Z_EFFECT_NONE,
        .argument = MOVE_EFFECT_POISON,
    },

    [MOVE_DOODLE] =
    {
        .effect = EFFECT_DOODLE,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED, // Supposedly unconfirmed?
        .priority = 0,
        .flags = 0, // TO VERIFY
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_NONE,
        // Supposedly uncallable by Metronome (unimplemented)
    },

    [MOVE_FILLET_AWAY] =
    {
        .effect = EFFECT_BLOOD_PACT,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .flags = FLAG_SNATCH_AFFECTED,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_RECOVER_HP,
        // Supposedly uncallable by Metronome (unimplemented)
    },

    [MOVE_KOWTOW_CLEAVE] =
    {
        .effect = EFFECT_HIT,
        .power = 85,
        .type = TYPE_DARK,
        .accuracy = 0,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .flags2 = FLAG_SLICING_MOVE | FLAG_SCENT_MARK_AFFECTED,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 160,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_FLOWER_TRICK] =
    {
        .effect = EFFECT_HIT,
        .power = 70,
        .type = TYPE_GRASS,
        .accuracy = 0,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .flags2 = FLAG_SCENT_MARK_AFFECTED | FLAG_ALWAYS_CRITICAL_HIT,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 140,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_TORCH_SONG] =
    {
        .effect = EFFECT_USER_SPECIAL_ATTACK_UP_1_ON_HIT,
        .power = 80,
        .type = TYPE_FIRE,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 100,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_SOUND_BASED_MOVE | FLAG_HAS_SECONDARY_EFFECT,
        .split = SPLIT_SPECIAL,
        .zMovePower = 160,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_AQUA_STEP] =
    {
        .effect = EFFECT_USER_SPEED_UP_1_ON_HIT,
        .power = 80,
        .type = TYPE_WATER,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 100,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_DANCING_MOVE | FLAG_HAS_SECONDARY_EFFECT,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 160,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_RAGING_BULL] =
    {
        .effect = EFFECT_RAGING_BULL,
        .power = 90,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 175,
        .zMoveEffect = Z_EFFECT_NONE,
        // Uncallable by Metronome (to be implemented)
    },

    [MOVE_MAKE_IT_RAIN] =
    {
        .effect = EFFECT_MAKE_IT_RAIN,
        .power = 120,
        .type = TYPE_STEEL,
        .accuracy = 100,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_BOTH,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .split = SPLIT_SPECIAL,
        .zMovePower = 190,
        .zMoveEffect = Z_EFFECT_NONE,
        // Uncallable by Metronome (to be implemented)
    },

    [MOVE_RUINATION] =
    {
        .effect = EFFECT_TARGET_REDUCE_50_HP,
        .power = 1,
        .type = TYPE_DARK,
        .accuracy = 90,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .split = SPLIT_SPECIAL,
        .zMovePower = 100,
        .zMoveEffect = Z_EFFECT_NONE,
        // Uncallable by Metronome (to be implemented)
    },

    [MOVE_COLLISION_COURSE] =
    {
        .effect = EFFECT_AQUA_TORNADO,
        .power = 100,
        .type = TYPE_FIGHTING,
        .accuracy = 100,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .flags2 = FLAG_SCENT_MARK_AFFECTED,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 180,
        .zMoveEffect = Z_EFFECT_NONE,
        // Uncallable by Metronome (to be implemented)
    },

    [MOVE_ELECTRO_DRIFT] =
    {
        .effect = EFFECT_AQUA_TORNADO,
        .power = 100,
        .type = TYPE_ELECTRIC,
        .accuracy = 100,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .flags2 = FLAG_SCENT_MARK_AFFECTED,
        .split = SPLIT_SPECIAL,
        .zMovePower = 180,
        .zMoveEffect = Z_EFFECT_NONE,
        // Uncallable by Metronome (to be implemented)
    },

    [MOVE_SHED_TAIL] =
    {
        .effect = EFFECT_SHED_TAIL,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .flags = 0,
        .flags2 = FLAG_TAIL_MOVE,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_RESET_STATS,
        // Uncallable by Metronome (to be implemented)
    },

    [MOVE_CHILLY_RECEPTION] =
    {
        .effect = EFFECT_CHILLY_RECEPTION,
        .power = 0,
        .type = TYPE_ICE,
        .accuracy = 0,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_ALL_BATTLERS,
        .priority = 0,
        .flags = 0,
        .flags2 = FLAG_WEATHER_RELATED_MOVE,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_SPD_UP_1,
        // Supposedly uncallable by Metronome? (to be implemented)
    },

    [MOVE_TIDY_UP] =
    {
        .effect = EFFECT_TIDY_UP,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .flags = 0,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_NONE,
        // Supposedly uncallable by Metronome? (to be implemented)
    },

    [MOVE_SNOWSCAPE] =
    {
        .effect = EFFECT_HAIL,
        .power = 0,
        .type = TYPE_ICE,
        .accuracy = 0,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_ALL_BATTLERS,
        .priority = 0,
        .flags = 0,
        .flags2 = FLAG_WEATHER_RELATED_MOVE,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_SPD_UP_1,
        // Currently an exact copy of Hail until we figure out what to do with it
    },

    [MOVE_POUNCE] =
    {
        .effect = EFFECT_TARGET_SPEED_DOWN_1_ON_HIT,
        .power = 50,
        .type = TYPE_BUG,
        .accuracy = 100,
        .pp = 20,
        .secondaryEffectChance = 100,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 100,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_TRAILBLAZE] =
    {
        .effect = EFFECT_USER_SPEED_UP_1_ON_HIT,
        .power = 50,
        .type = TYPE_GRASS,
        .accuracy = 100,
        .pp = 20,
        .secondaryEffectChance = 100,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 100,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_CHILLING_WATER] =
    {
        .effect = EFFECT_TARGET_ATTACK_DOWN_1_ON_HIT,
        .power = 50,
        .type = TYPE_WATER,
        .accuracy = 100,
        .pp = 20,
        .secondaryEffectChance = 100,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .split = SPLIT_SPECIAL,
        .zMovePower = 100,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_HYPER_DRILL] =
    {
        .effect = EFFECT_STAR_ICON,
        .power = 100,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .flags2 = FLAG_SCENT_MARK_AFFECTED,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 180,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_TWIN_BEAM] =
    {
        .effect = EFFECT_TARGET_DOUBLE_HIT,
        .power = 40,
        .type = TYPE_PSYCHIC,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_TWO_STRIKES,
        .split = SPLIT_SPECIAL,
        .zMovePower = 100,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_RAGE_FIST] =
    {
        .effect = EFFECT_RAGE_FIST,
        .power = 50,
        .type = TYPE_GHOST,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_PUNCHING_MOVE | FLAG_KINGS_ROCK_AFFECTED,
        .flags2 = FLAG_EMOTION_MOVE | FLAG_SCENT_MARK_AFFECTED,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 100,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_ARMOR_CANNON] =
    {
        .effect = EFFECT_CLOSE_COMBAT,
        .power = 120,
        .type = TYPE_FIRE,
        .accuracy = 100,
        .pp = 5,
        .secondaryEffectChance = 100,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_AURA_BEAM_CANNON_GUN_PULSE_PUMP_SHOT_AND_ZOOKA_MOVE,
        .split = SPLIT_SPECIAL,
        .zMovePower = 190,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_BITTER_BLADE] =
    {
        .effect = EFFECT_USER_DRAIN_50_ON_HIT,
        .power = 90,
        .type = TYPE_FIRE,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .flags2 = FLAG_SLICING_MOVE,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 160,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_DOUBLE_SHOCK] =
    {
        .effect = EFFECT_DOUBLE_SHOCK,
        .power = 120,
        .type = TYPE_ELECTRIC,
        .accuracy = 100,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 190,
        .zMoveEffect = Z_EFFECT_NONE
    },

    [MOVE_GIGATON_HAMMER] =
    {
        .effect = EFFECT_STAR_ICON,
        .power = 160,
        .type = TYPE_STEEL,
        .accuracy = 100,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .flags2 = FLAG_CANNOT_BE_USED_CONSECUTIVELY | FLAG_SCENT_MARK_AFFECTED,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 200,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_COMEUPPANCE] =
    {
        .effect = EFFECT_METAL_BURST,
        .power = 1,
        .type = TYPE_DARK,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_DEPENDS,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_AQUA_CUTTER] =
    {
        .effect = EFFECT_HIT,
        .power = 70,
        .type = TYPE_WATER,
        .accuracy = 100,
        .pp = 20,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_HIGH_CRITICAL_HIT_RATIO,
        .flags2 = FLAG_SLICING_MOVE | FLAG_SCENT_MARK_AFFECTED,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 140,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_BLAZING_TORQUE] =
    {
        .effect = EFFECT_TARGET_BURN_ON_HIT,
        .power = 80,
        .type = TYPE_FIRE,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 30,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_HAS_SECONDARY_EFFECT,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 160,
        .zMoveEffect = Z_EFFECT_NONE
    },

    [MOVE_WICKED_TORQUE] =
    {
        .effect = EFFECT_TARGET_SLEEP_ON_HIT,
        .power = 80,
        .type = TYPE_DARK,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 10,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_HAS_SECONDARY_EFFECT,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 160,
        .zMoveEffect = Z_EFFECT_NONE
    },

    [MOVE_NOXIOUS_TORQUE] =
    {
        .effect = EFFECT_TARGET_POISON_ON_HIT,
        .power = 100,
        .type = TYPE_POISON,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 30,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_HAS_SECONDARY_EFFECT,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 160,
        .zMoveEffect = Z_EFFECT_NONE
    },

    [MOVE_COMBAT_TORQUE] =
    {
        .effect = EFFECT_TARGET_PARALYZE_ON_HIT,
        .power = 100,
        .type = TYPE_FIGHTING,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 30,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_HAS_SECONDARY_EFFECT,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 160,
        .zMoveEffect = Z_EFFECT_NONE
    },

    [MOVE_MAGICAL_TORQUE] =
    {
        .effect = EFFECT_TARGET_CONFUSE_ON_HIT,
        .power = 100,
        .type = TYPE_FAIRY,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 30,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_HAS_SECONDARY_EFFECT,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 160,
        .zMoveEffect = Z_EFFECT_NONE
    },

    [MOVE_PSYBLADE] =
    {
        .effect = EFFECT_PSYBLADE,
        .power = 80,
        .type = TYPE_PSYCHIC,
        .accuracy = 100,
        .pp = 15,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .split = SPLIT_PHYSICAL,
        .zMoveEffect = Z_EFFECT_NONE,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .flags2 = FLAG_SLICING_MOVE | FLAG_SCENT_MARK_AFFECTED,
    },

    [MOVE_HYDRO_STEAM] =
    {
        .effect = EFFECT_HYDRO_STEAM,
        .power = 80,
        .type = TYPE_WATER,
        .accuracy = 100,
        .pp = 15,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .split = SPLIT_SPECIAL,
        .zMoveEffect = Z_EFFECT_NONE,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_THAW_USER,
        .flags2 = FLAG_SCENT_MARK_AFFECTED,
    },

    [MOVE_BLOOD_MOON] =
    {
        .effect = EFFECT_STAR_ICON,
        .power = 140,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .split = SPLIT_SPECIAL,
        .zMoveEffect = Z_EFFECT_NONE,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .flags2 = FLAG_CANNOT_BE_USED_CONSECUTIVELY | FLAG_SCENT_MARK_AFFECTED,
    },

    [MOVE_MATCHA_GOTCHA] =
    {
        .effect = EFFECT_MATCHA_GOTCHA,
        .power = 80,
        .type = TYPE_GRASS,
        .accuracy = 90,
        .pp = 15,
        .secondaryEffectChance = 20,
        .target = MOVE_TARGET_BOTH,
        .priority = 0,
        .split = SPLIT_SPECIAL,
        .zMoveEffect = Z_EFFECT_NONE,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_THAW_USER,
    },

    [MOVE_SYRUP_BOMB] =
    {
        .effect = EFFECT_SYRUP_BOMB,
        .power = 60,
        .type = TYPE_GRASS,
        .accuracy = 85,
        .pp = 10,
        .secondaryEffectChance = 100, // syrup bomb volatile status
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .split = SPLIT_SPECIAL,
        .zMoveEffect = Z_EFFECT_NONE,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_BALL_AND_BOMB_MOVE,
    },

    [MOVE_IVY_CUDGEL] =
    {
        .effect = EFFECT_IVY_CUDGEL,
        .power = 100,
        .type = TYPE_GRASS,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .split = SPLIT_PHYSICAL,
        .zMoveEffect = Z_EFFECT_NONE,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_HIGH_CRITICAL_HIT_RATIO,
        .flags2 = FLAG_SCENT_MARK_AFFECTED,
    },

    [MOVE_ELECTRO_SHOT] =
    {
        .effect = EFFECT_USER_FIRST_TURN_PREPARE_SECOND_TURN_ATTACK, //EFFECT_ELECTRO_SHOT
        .power = 130,
        .type = TYPE_ELECTRIC,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .split = SPLIT_SPECIAL,
        .argument = STAT_SPATK,
    },

    [MOVE_TERA_STARSTORM] =
    {
        .effect = EFFECT_PLACEHOLDER, //EFFECT_TERA_STARSTORM
        .power = 120,
        .type = TYPE_NORMAL, // Stellar type if used by Terapagos-Stellar
        .accuracy = 100,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED, // MOVE_TARGET_BOTH if used by Terapagos-Stellar
        .priority = 0,
        .split = SPLIT_SPECIAL,
    },

    [MOVE_FICKLE_BEAM] =
    {
        .effect = EFFECT_PLACEHOLDER, //EFFECT_FICKLE_BEAM
        .power = 80,
        .type = TYPE_DRAGON,
        .accuracy = 100,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .split = SPLIT_SPECIAL,
    },

    [MOVE_BURNING_BULWARK] =
    {
        .effect = EFFECT_USER_PREVENT_MOVE, // NEEDS ACTUAL PROTECT SIDE EFFECT
        .power = 0,
        .type = TYPE_FIRE,
        .accuracy = 0,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_USER,
        .priority = 4,
        .flags = FLAG_PROTECTION_MOVE,
        .split = SPLIT_STATUS,
        .zMoveEffect = Z_EFFECT_RESET_STATS,
    },

    [MOVE_THUNDERCLAP] =
    {
        .effect = EFFECT_SUCKER_PUNCH,
        .power = 70,
        .type = TYPE_ELECTRIC,
        .accuracy = 100,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 1,
        .split = SPLIT_SPECIAL,
    },

    [MOVE_MIGHTY_CLEAVE] =
    {
        .effect = EFFECT_TARGET_REMOVE_PROTECTION_ON_HIT,
        .power = 95,
        .type = TYPE_ROCK,
        .accuracy = 100,
        .pp = 5,
        .secondaryEffectChance = 100,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .split = SPLIT_PHYSICAL,
        .flags = FLAG_MAKES_CONTACT,
        .flags2 = FLAG_SLICING_MOVE,
    },

    [MOVE_TACHYON_CUTTER] =
    {
        .effect = EFFECT_TARGET_DOUBLE_HIT,
        .power = 50,
        .type = TYPE_STEEL,
        .accuracy = 0,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .split = SPLIT_SPECIAL,
        .flags2 = FLAG_SLICING_MOVE,
    },

    [MOVE_HARD_PRESS] =
    {
        .effect = EFFECT_WRING_OUT,
        .power = 1,
        .type = TYPE_STEEL,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .split = SPLIT_PHYSICAL,
        .flags = FLAG_MAKES_CONTACT,
    },

    [MOVE_DRAGON_CHEER] =
    {
        .effect = EFFECT_PLACEHOLDER, //EFFECT_DRAGON_CHEER
        .power = 0,
        .type = TYPE_DRAGON,
        .accuracy = 0,
        .pp = 15,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_ALLY,
        .priority = 0,
        .split = SPLIT_STATUS,
    },

    [MOVE_ALLURING_VOICE] =
    {
        .effect = EFFECT_PLACEHOLDER, //EFFECT_ALLURING_VOICE
        .power = 80,
        .type = TYPE_FAIRY,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .split = SPLIT_SPECIAL,
        .flags = FLAG_SOUND_BASED_MOVE,
    },

    [MOVE_TEMPER_FLARE] =
    {
        .effect = EFFECT_STOMPING_TANTRUM,
        .power = 75,
        .type = TYPE_FIRE,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .split = SPLIT_PHYSICAL,
        .flags = FLAG_MAKES_CONTACT,
    },

    [MOVE_SUPERCELL_SLAM] =
    {
        .effect = EFFECT_USER_REDUCE_50_HP_IF_MISS,
        .power = 100,
        .type = TYPE_ELECTRIC,
        .accuracy = 95,
        .pp = 15,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .split = SPLIT_PHYSICAL,
        .flags = FLAG_MAKES_CONTACT,
    },

    [MOVE_PSYCHIC_NOISE] =
    {
        .effect = EFFECT_PLACEHOLDER, //EFFECT_PSYCHIC_NOISE
        .power = 75,
        .type = TYPE_PSYCHIC,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .split = SPLIT_SPECIAL,
        .flags = FLAG_SOUND_BASED_MOVE,
    },

    [MOVE_UPPER_HAND] =
    {
        .effect = EFFECT_PLACEHOLDER, //EFFECT_UPPER_HAND
        .power = 65,
        .type = TYPE_FIGHTING,
        .accuracy = 100,
        .pp = 15,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 3,
        .split = SPLIT_PHYSICAL,
        .flags = FLAG_MAKES_CONTACT,
    },

    [MOVE_MALIGNANT_CHAIN] =
    {
        .effect = EFFECT_TARGET_BADLY_POISON_ON_HIT,
        .power = 100,
        .type = TYPE_POISON,
        .accuracy = 100,
        .pp = 5,
        .secondaryEffectChance = 50,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .split = SPLIT_SPECIAL,
    },

    // Z-Moves
    [MOVE_BREAKNECK_BLITZ] =
    {
        .effect = EFFECT_HIT,
        .power = 1,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 1,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = 0,
        .zMovePower = 0,
        .split = SPLIT_PHYSICAL,    //determined from move type
        .zMoveEffect = 0
    },
    [MOVE_ALL_OUT_PUMMELING] =
    {
        .effect = EFFECT_HIT,
        .power = 1,
        .type = TYPE_FIGHTING,
        .accuracy = 0,
        .pp = 1,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = 0,
        .zMovePower = 0,
        .split = SPLIT_PHYSICAL,
        .zMoveEffect = 0
    },
    [MOVE_SUPERSONIC_SKYSTRIKE] =
    {
        .effect = EFFECT_HIT,
        .power = 1,
        .type = TYPE_FLYING,
        .accuracy = 0,
        .pp = 1,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = 0,
        .zMovePower = 0,
        .split = SPLIT_PHYSICAL,
        .zMoveEffect = 0
    },
    [MOVE_ACID_DOWNPOUR] =
    {
        .effect = EFFECT_HIT,
        .power = 1,
        .type = TYPE_POISON,
        .accuracy = 0,
        .pp = 1,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = 0,
        .flags2 = FLAG_ACID_MOVE,
        .zMovePower = 0,
        .split = SPLIT_PHYSICAL,
        .zMoveEffect = 0
    },
    [MOVE_TECTONIC_RAGE] =
    {
        .effect = EFFECT_HIT,
        .power = 1,
        .type = TYPE_GROUND,
        .accuracy = 0,
        .pp = 1,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = 0,
        .zMovePower = 0,
        .split = SPLIT_PHYSICAL,
        .zMoveEffect = 0
    },
    [MOVE_CONTINENTAL_CRUSH] =
    {
        .effect = EFFECT_HIT,
        .power = 1,
        .type = TYPE_ROCK,
        .accuracy = 0,
        .pp = 1,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = 0,
        .zMovePower = 0,
        .split = SPLIT_PHYSICAL,
        .zMoveEffect = 0
    },
    [MOVE_SAVAGE_SPIN_OUT] =
    {
        .effect = EFFECT_HIT,
        .power = 1,
        .type = TYPE_BUG,
        .accuracy = 0,
        .pp = 1,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = 0,
        .zMovePower = 0,
        .split = SPLIT_PHYSICAL,
        .zMoveEffect = 0
    },
    [MOVE_NEVER_ENDING_NIGHTMARE] =
    {
        .effect = EFFECT_HIT,
        .power = 1,
        .type = TYPE_GHOST,
        .accuracy = 0,
        .pp = 1,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = 0,
        .zMovePower = 0,
        .split = SPLIT_PHYSICAL,
        .zMoveEffect = 0
    },
    [MOVE_CORKSCREW_CRASH] =
    {
        .effect = EFFECT_HIT,
        .power = 1,
        .type = TYPE_STEEL,
        .accuracy = 0,
        .pp = 1,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = 0,
        .zMovePower = 0,
        .split = SPLIT_PHYSICAL,
        .zMoveEffect = 0
    },
    [MOVE_INFERNO_OVERDRIVE] =
    {
        .effect = EFFECT_HIT,
        .power = 1,
        .type = TYPE_FIRE,
        .accuracy = 0,
        .pp = 1,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = 0,
        .zMovePower = 0,
        .split = SPLIT_PHYSICAL,
        .zMoveEffect = 0
    },
    [MOVE_HYDRO_VORTEX] =
    {
        .effect = EFFECT_HIT,
        .power = 1,
        .type = TYPE_WATER,
        .accuracy = 0,
        .pp = 1,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = 0,
        .zMovePower = 0,
        .split = SPLIT_PHYSICAL,
        .zMoveEffect = 0
    },
    [MOVE_BLOOM_DOOM] =
    {
        .effect = EFFECT_HIT,
        .power = 1,
        .type = TYPE_GRASS,
        .accuracy = 0,
        .pp = 1,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = 0,
        .zMovePower = 0,
        .split = SPLIT_PHYSICAL,
        .zMoveEffect = 0
    },
    [MOVE_GIGAVOLT_HAVOC] =
    {
        .effect = EFFECT_HIT,
        .power = 1,
        .type = TYPE_ELECTRIC,
        .accuracy = 0,
        .pp = 1,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = 0,
        .zMovePower = 0,
        .split = SPLIT_PHYSICAL,
        .zMoveEffect = 0
    },
    [MOVE_SHATTERED_PSYCHE] =
    {
        .effect = EFFECT_HIT,
        .power = 1,
        .type = TYPE_PSYCHIC,
        .accuracy = 0,
        .pp = 1,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = 0,
        .zMovePower = 0,
        .split = SPLIT_PHYSICAL,
        .zMoveEffect = 0
    },
    [MOVE_SUBZERO_SLAMMER] =
    {
        .effect = EFFECT_HIT,
        .power = 1,
        .type = TYPE_ICE,
        .accuracy = 0,
        .pp = 1,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = 0,
        .zMovePower = 0,
        .split = SPLIT_PHYSICAL,
        .zMoveEffect = 0
    },
    [MOVE_DEVASTATING_DRAKE] =
    {
        .effect = EFFECT_HIT,
        .power = 1,
        .type = TYPE_DRAGON,
        .accuracy = 0,
        .pp = 1,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = 0,
        .zMovePower = 0,
        .split = SPLIT_PHYSICAL,
        .zMoveEffect = 0
    },
    [MOVE_BLACK_HOLE_ECLIPSE] =
    {
        .effect = EFFECT_HIT,
        .power = 1,
        .type = TYPE_DARK,
        .accuracy = 0,
        .pp = 1,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = 0,
        .zMovePower = 0,
        .split = SPLIT_PHYSICAL,
        .zMoveEffect = 0
    },
    [MOVE_TWINKLE_TACKLE] =
    {
        .effect = EFFECT_HIT,
        .power = 1,
        .type = TYPE_FAIRY,
        .accuracy = 0,
        .pp = 1,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = 0,
        .zMovePower = 0,
        .split = SPLIT_PHYSICAL,
        .zMoveEffect = 0
    },
    [MOVE_CATASTROPIKA] =
    {
        .effect = EFFECT_HIT,
        .power = 210,
        .type = TYPE_ELECTRIC,
        .accuracy = 0,
        .pp = 1,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = 0,
        .zMovePower = 0,
        .split = SPLIT_PHYSICAL,
        .zMoveEffect = 0
    },
    [MOVE_10000000_VOLT_THUNDERBOLT] =
    {
        .effect = EFFECT_HIT,
        .power = 195,
        .type = TYPE_ELECTRIC,
        .accuracy = 0,
        .pp = 1,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_HIGH_CRITICAL_HIT_RATIO,
        .zMovePower = 0,
        .split = SPLIT_SPECIAL,
        .zMoveEffect = 0
    },
    [MOVE_STOKED_SPARKSURFER] =
    {
        .effect = EFFECT_TARGET_PARALYZE_ON_HIT,
        .power = 175,
        .type = TYPE_ELECTRIC,
        .accuracy = 0,
        .pp = 1,
        .secondaryEffectChance = 100,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = 0,
        .zMovePower = 0,
        .split = SPLIT_SPECIAL,
        .zMoveEffect = 0
    },
    [MOVE_EXTREME_EVOBOOST] =
    {
        .effect = EFFECT_EXTREME_EVOBOOST,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 1,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .flags = 0,
        .zMovePower = 0,
        .split = SPLIT_STATUS,
        .zMoveEffect = 0
    },
    [MOVE_PULVERIZING_PANCAKE] =
    {
        .effect = EFFECT_HIT,
        .power = 210,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 1,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = 0,
        .zMovePower = 0,
        .split = SPLIT_PHYSICAL,
        .zMoveEffect = 0
    },
    [MOVE_GENESIS_SUPERNOVA] =
    {
        .effect = EFFECT_HIT_SET_REMOVE_TERRAIN,
        .power = 185,
        .type = TYPE_PSYCHIC,
        .accuracy = 0,
        .pp = 1,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = 0,
        .zMovePower = 0,
        .split = SPLIT_SPECIAL,
        .argument = EFFECT_PSYCHIC_TERRAIN,
        .zMoveEffect = 0
    },
    [MOVE_SINISTER_ARROW_RAID] =
    {
        .effect = EFFECT_HIT,
        .power = 180,
        .type = TYPE_GHOST,
        .accuracy = 0,
        .pp = 1,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = 0,
        .zMovePower = 0,
        .split = SPLIT_PHYSICAL,
        .zMoveEffect = 0
    },
    [MOVE_MALICIOUS_MOONSAULT] =
    {
        .effect = EFFECT_HIT,
        .power = 180,
        .type = TYPE_DARK,
        .accuracy = 0,
        .pp = 1,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = 0,
        .zMovePower = 0,
        .split = SPLIT_PHYSICAL,
        .zMoveEffect = 0
    },
    [MOVE_OCEANIC_OPERETTA] =
    {
        .effect = EFFECT_HIT,
        .power = 195,
        .type = TYPE_WATER,
        .accuracy = 0,
        .pp = 1,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = 0,
        .zMovePower = 0,
        .split = SPLIT_SPECIAL,
        .zMoveEffect = 0
    },
    [MOVE_SPLINTERED_STORMSHARDS] =
    {
        .effect = EFFECT_HIT_SET_REMOVE_TERRAIN,
        .power = 190,
        .type = TYPE_ROCK,
        .accuracy = 0,
        .pp = 1,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = 0,
        .zMovePower = 0,
        .split = SPLIT_PHYSICAL,
        .zMoveEffect = 0
    },
    [MOVE_LETS_SNUGGLE_FOREVER] =
    {
        .effect = EFFECT_HIT,
        .power = 190,
        .type = TYPE_FAIRY,
        .accuracy = 0,
        .pp = 1,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = 0,
        .zMovePower = 0,
        .split = SPLIT_PHYSICAL,
        .zMoveEffect = 0
    },
    [MOVE_CLANGOROUS_SOULBLAZE] =
    {
        .effect = EFFECT_ALL_STATS_UP_1_ON_HIT,
        .power = 185,
        .type = TYPE_DRAGON,
        .accuracy = 0,
        .pp = 1,
        .secondaryEffectChance = 100,
        .target = MOVE_TARGET_BOTH,
        .priority = 0,
        .flags = FLAG_SOUND_BASED_MOVE,
        .zMovePower = 0,
        .split = SPLIT_SPECIAL,
        .zMoveEffect = 0
    },
    [MOVE_GUARDIAN_OF_ALOLA] =
    {
        .effect = EFFECT_TARGET_REDUCE_50_HP,
        .power = 1,
        .type = TYPE_FAIRY,
        .accuracy = 0,
        .pp = 1,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = 0,
        .zMovePower = 0,
        .split = SPLIT_SPECIAL,
        .zMoveEffect = 0
    },
    [MOVE_SEARING_SUNRAZE_SMASH] =
    {
        .effect = EFFECT_HIT,
        .power = 200,
        .type = TYPE_STEEL,
        .accuracy = 0,
        .pp = 1,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = 0,
        .zMovePower = 0,
        .split = SPLIT_PHYSICAL,
        .zMoveEffect = 0
    },
    [MOVE_MENACING_MOONRAZE_MAELSTROM] =
    {
        .effect = EFFECT_HIT,
        .power = 200,
        .type = TYPE_GHOST,
        .accuracy = 0,
        .pp = 1,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = 0,
        .zMovePower = 0,
        .split = SPLIT_SPECIAL,
        .zMoveEffect = 0
    },
    [MOVE_LIGHT_THAT_BURNS_THE_SKY] =
    {
        .effect = EFFECT_HIT,
        .power = 200,
        .type = TYPE_PSYCHIC,
        .accuracy = 0,
        .pp = 1,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = 0,
        .zMovePower = 0,
        .split = SPLIT_SPECIAL,
        .zMoveEffect = 0
    },
    [MOVE_SOUL_STEALING_7_STAR_STRIKE] =
    {
        .effect = EFFECT_HIT,
        .power = 195,
        .type = TYPE_GHOST,
        .accuracy = 0,
        .pp = 1,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = 0,
        .zMovePower = 0,
        .split = SPLIT_PHYSICAL,
        .zMoveEffect = 0
    },

    [MOVE_MAX_GUARD] =
	{
		.effect = EFFECT_USER_PREVENT_MOVE,
		.power = 0,
		.type = TYPE_NORMAL,
		.accuracy = 0,
		.pp = 10,
		.secondaryEffectChance = 0,
		.target = MOVE_TARGET_USER,
		.priority = 4,
		.split = SPLIT_STATUS,
        //.protectionMove = TRUE,
	},

	[MOVE_MAX_FLARE] =
	{
		.effect = EFFECT_MAX_MOVE,
		.power = 1,
		.type = TYPE_FIRE,
		.accuracy = 0,
		.pp = 10,
		.secondaryEffectChance = 100,
		.target = MOVE_TARGET_SELECTED,
		.priority = 0,
		.split = SPLIT_PHYSICAL,
		.argument = MAX_EFFECT_SUN,
	},

	[MOVE_MAX_FLUTTERBY] =
	{
		.effect = EFFECT_MAX_MOVE,
		.power = 1,
		.type = TYPE_BUG,
		.accuracy = 0,
		.pp = 10,
		.secondaryEffectChance = 100,
		.target = MOVE_TARGET_SELECTED,
		.priority = 0,
		.split = SPLIT_PHYSICAL,
		.argument = MAX_EFFECT_LOWER_SP_ATK,
	},

	[MOVE_MAX_LIGHTNING] =
	{
		.effect = EFFECT_MAX_MOVE,
		.power = 1,
		.type = TYPE_ELECTRIC,
		.accuracy = 0,
		.pp = 10,
		.secondaryEffectChance = 100,
		.target = MOVE_TARGET_SELECTED,
		.priority = 0,
		.split = SPLIT_PHYSICAL,
		.argument = MAX_EFFECT_ELECTRIC_TERRAIN,
	},

	[MOVE_MAX_STRIKE] =
	{
		.effect = EFFECT_MAX_MOVE,
		.power = 1,
		.type = TYPE_NORMAL,
		.accuracy = 0,
		.pp = 10,
		.secondaryEffectChance = 100,
		.target = MOVE_TARGET_SELECTED,
		.priority = 0,
		.split = SPLIT_PHYSICAL,
		.argument = MAX_EFFECT_LOWER_SPEED,
	},

	[MOVE_MAX_KNUCKLE] =
	{
		.effect = EFFECT_MAX_MOVE,
		.power = 1,
		.type = TYPE_FIGHTING,
		.accuracy = 0,
		.pp = 10,
		.secondaryEffectChance = 100,
		.target = MOVE_TARGET_SELECTED,
		.priority = 0,
		.split = SPLIT_PHYSICAL,
		.argument = MAX_EFFECT_RAISE_TEAM_ATTACK,
	},

	[MOVE_MAX_PHANTASM] =
	{
		.effect = EFFECT_MAX_MOVE,
		.power = 1,
		.type = TYPE_GHOST,
		.accuracy = 0,
		.pp = 10,
		.secondaryEffectChance = 100,
		.target = MOVE_TARGET_SELECTED,
		.priority = 0,
		.split = SPLIT_PHYSICAL,
		.argument = MAX_EFFECT_LOWER_DEFENSE,
	},

	[MOVE_MAX_HAILSTORM] =
	{
		.effect = EFFECT_MAX_MOVE,
		.power = 1,
		.type = TYPE_ICE,
		.accuracy = 0,
		.pp = 10,
		.secondaryEffectChance = 100,
		.target = MOVE_TARGET_SELECTED,
		.priority = 0,
		.split = SPLIT_PHYSICAL,
		.argument = MAX_EFFECT_HAIL,
	},

	[MOVE_MAX_OOZE] =
	{
		.effect = EFFECT_MAX_MOVE,
		.power = 1,
		.type = TYPE_POISON,
		.accuracy = 0,
		.pp = 10,
		.secondaryEffectChance = 100,
		.target = MOVE_TARGET_SELECTED,
		.priority = 0,
		.split = SPLIT_PHYSICAL,
		.argument = MAX_EFFECT_RAISE_TEAM_SP_ATK,
	},

	[MOVE_MAX_GEYSER] =
	{
		.effect = EFFECT_MAX_MOVE,
		.power = 1,
		.type = TYPE_WATER,
		.accuracy = 0,
		.pp = 10,
		.secondaryEffectChance = 100,
		.target = MOVE_TARGET_SELECTED,
		.priority = 0,
		.split = SPLIT_PHYSICAL,
		.argument = MAX_EFFECT_RAIN,
	},

	[MOVE_MAX_AIRSTREAM] =
	{
		.effect = EFFECT_MAX_MOVE,
		.power = 1,
		.type = TYPE_FLYING,
		.accuracy = 0,
		.pp = 10,
		.secondaryEffectChance = 100,
		.target = MOVE_TARGET_SELECTED,
		.priority = 0,
		.split = SPLIT_PHYSICAL,
		.argument = MAX_EFFECT_RAISE_TEAM_SPEED,
	},

	[MOVE_MAX_STARFALL] =
	{
		.effect = EFFECT_MAX_MOVE,
		.power = 1,
		.type = TYPE_FAIRY,
		.accuracy = 0,
		.pp = 10,
		.secondaryEffectChance = 100,
		.target = MOVE_TARGET_SELECTED,
		.priority = 0,
		.split = SPLIT_PHYSICAL,
		.argument = MAX_EFFECT_MISTY_TERRAIN,
	},

	[MOVE_MAX_WYRMWIND] =
	{
		.effect = EFFECT_MAX_MOVE,
		.power = 1,
		.type = TYPE_DRAGON,
		.accuracy = 0,
		.pp = 10,
		.secondaryEffectChance = 100,
		.target = MOVE_TARGET_SELECTED,
		.priority = 0,
		.split = SPLIT_PHYSICAL,
		.argument = MAX_EFFECT_LOWER_ATTACK,
	},

	[MOVE_MAX_MINDSTORM] =
	{
		.effect = EFFECT_MAX_MOVE,
		.power = 1,
		.type = TYPE_PSYCHIC,
		.accuracy = 0,
		.pp = 10,
		.secondaryEffectChance = 100,
		.target = MOVE_TARGET_SELECTED,
		.priority = 0,
		.split = SPLIT_PHYSICAL,
		.argument = MAX_EFFECT_PSYCHIC_TERRAIN,
	},

	[MOVE_MAX_ROCKFALL] =
	{
		.effect = EFFECT_MAX_MOVE,
		.power = 1,
		.type = TYPE_ROCK,
		.accuracy = 0,
		.pp = 10,
		.secondaryEffectChance = 100,
		.target = MOVE_TARGET_SELECTED,
		.priority = 0,
		.split = SPLIT_PHYSICAL,
		.argument = MAX_EFFECT_SANDSTORM,
	},

	[MOVE_MAX_QUAKE] =
	{
		.effect = EFFECT_MAX_MOVE,
		.power = 1,
		.type = TYPE_GROUND,
		.accuracy = 0,
		.pp = 10,
		.secondaryEffectChance = 100,
		.target = MOVE_TARGET_SELECTED,
		.priority = 0,
		.split = SPLIT_PHYSICAL,
		.argument = MAX_EFFECT_RAISE_TEAM_SP_DEF,
	},

	[MOVE_MAX_DARKNESS] =
	{
		.effect = EFFECT_MAX_MOVE,
		.power = 1,
		.type = TYPE_DARK,
		.accuracy = 0,
		.pp = 10,
		.secondaryEffectChance = 100,
		.target = MOVE_TARGET_SELECTED,
		.priority = 0,
		.split = SPLIT_PHYSICAL,
		.argument = MAX_EFFECT_LOWER_SP_DEF,
	},

	[MOVE_MAX_OVERGROWTH] =
	{
		.effect = EFFECT_MAX_MOVE,
		.power = 10,
		.type = TYPE_GRASS,
		.accuracy = 0,
		.pp = 10,
		.secondaryEffectChance = 100,
		.target = MOVE_TARGET_SELECTED,
		.priority = 0,
		.split = SPLIT_PHYSICAL,
		.argument = MAX_EFFECT_GRASSY_TERRAIN,
	},

	[MOVE_MAX_STEELSPIKE] =
	{
		.effect = EFFECT_MAX_MOVE,
		.power = 10,
		.type = TYPE_STEEL,
		.accuracy = 0,
		.pp = 10,
		.secondaryEffectChance = 100,
		.target = MOVE_TARGET_SELECTED,
		.priority = 0,
		.split = SPLIT_PHYSICAL,
		.argument = MAX_EFFECT_RAISE_TEAM_DEFENSE,
	},

	[MOVE_G_MAX_VINE_LASH] =
	{	//ANIM TODO
		.effect = EFFECT_MAX_MOVE,
		.power = 10,
		.type = TYPE_GRASS,
		.accuracy = 0,
		.pp = 10,
		.secondaryEffectChance = 100,
		.target = MOVE_TARGET_SELECTED,
		.priority = 0,
		.split = SPLIT_PHYSICAL,
		.argument = MAX_EFFECT_VINE_LASH,
	},

	[MOVE_G_MAX_WILDFIRE] =
	{
		.effect = EFFECT_MAX_MOVE,
		.power = 10,
		.type = TYPE_FIRE,
		.accuracy = 0,
		.pp = 10,
		.secondaryEffectChance = 100,
		.target = MOVE_TARGET_SELECTED,
		.priority = 0,
		.split = SPLIT_PHYSICAL,
		.argument = MAX_EFFECT_WILDFIRE,
	},

	[MOVE_G_MAX_CANNONADE] =
	{	//ANIM TODO
		.effect = EFFECT_MAX_MOVE,
		.power = 10,
		.type = TYPE_WATER,
		.accuracy = 0,
		.pp = 10,
		.secondaryEffectChance = 100,
		.target = MOVE_TARGET_SELECTED,
		.priority = 0,
		.split = SPLIT_PHYSICAL,
		.argument = MAX_EFFECT_CANNONADE,
	},

	[MOVE_G_MAX_BEFUDDLE] =
	{
		.effect = EFFECT_MAX_MOVE,
		.power = 10,
		.type = TYPE_BUG,
		.accuracy = 0,
		.pp = 10,
		.secondaryEffectChance = 100,
		.target = MOVE_TARGET_SELECTED,
		.priority = 0,
		.split = SPLIT_PHYSICAL,
		.argument = MAX_EFFECT_EFFECT_SPORE_FOES,
	},

	[MOVE_G_MAX_VOLT_CRASH] =
	{
		.effect = EFFECT_MAX_MOVE,
		.power = 10,
		.type = TYPE_ELECTRIC,
		.accuracy = 0,
		.pp = 10,
		.secondaryEffectChance = 100,
		.target = MOVE_TARGET_SELECTED,
		.priority = 0,
		.split = SPLIT_PHYSICAL,
		.argument = MAX_EFFECT_PARALYZE_FOES,
	},

	[MOVE_G_MAX_GOLD_RUSH] =
	{
		.effect = EFFECT_MAX_MOVE,
		.power = 10,
		.type = TYPE_NORMAL,
		.accuracy = 0,
		.pp = 10,
		.secondaryEffectChance = 100,
		.target = MOVE_TARGET_SELECTED,
		.priority = 0,
		.split = SPLIT_PHYSICAL,
		.argument = MAX_EFFECT_CONFUSE_FOES_PAY_DAY,
	},

	[MOVE_G_MAX_CHI_STRIKE] =
	{
		.effect = EFFECT_MAX_MOVE,
		.power = 10,
		.type = TYPE_FIGHTING,
		.accuracy = 0,
		.pp = 10,
		.secondaryEffectChance = 100,
		.target = MOVE_TARGET_SELECTED,
		.priority = 0,
		.split = SPLIT_PHYSICAL,
		.argument = MAX_EFFECT_CRIT_PLUS,
	},

	[MOVE_G_MAX_TERROR] =
	{
		.effect = EFFECT_MAX_MOVE,
		.power = 10,
		.type = TYPE_GHOST,
		.accuracy = 0,
		.pp = 10,
		.secondaryEffectChance = 100,
		.target = MOVE_TARGET_SELECTED,
		.priority = 0,
		.split = SPLIT_PHYSICAL,
		.argument = MAX_EFFECT_MEAN_LOOK,
	},

	[MOVE_G_MAX_FOAM_BURST] =
	{
		.effect = EFFECT_MAX_MOVE,
		.power = 10,
		.type = TYPE_WATER,
		.accuracy = 0,
		.pp = 10,
		.secondaryEffectChance = 100,
		.target = MOVE_TARGET_SELECTED,
		.priority = 0,
		.split = SPLIT_PHYSICAL,
		.argument = MAX_EFFECT_LOWER_SPEED_2_FOES,
	},

	[MOVE_G_MAX_RESONANCE] =
	{
		.effect = EFFECT_MAX_MOVE,
		.power = 10,
		.type = TYPE_ICE,
		.accuracy = 0,
		.pp = 10,
		.secondaryEffectChance = 100,
		.target = MOVE_TARGET_SELECTED,
		.priority = 0,
		.split = SPLIT_PHYSICAL,
		.argument = MAX_EFFECT_AURORA_VEIL,
	},

	[MOVE_G_MAX_CUDDLE] =
	{
		.effect = EFFECT_MAX_MOVE,
		.power = 10,
		.type = TYPE_NORMAL,
		.accuracy = 0,
		.pp = 10,
		.secondaryEffectChance = 100,
		.target = MOVE_TARGET_SELECTED,
		.priority = 0,
		.split = SPLIT_PHYSICAL,
		.argument = MAX_EFFECT_INFATUATE_FOES,
	},

	[MOVE_G_MAX_REPLENISH] =
	{
		.effect = EFFECT_MAX_MOVE,
		.power = 10,
		.type = TYPE_NORMAL,
		.accuracy = 0,
		.pp = 10,
		.secondaryEffectChance = 100,
		.target = MOVE_TARGET_SELECTED,
		.priority = 0,
		.split = SPLIT_PHYSICAL,
		.argument = MAX_EFFECT_RECYCLE_BERRIES,
	},

	[MOVE_G_MAX_MALODOR] =
	{
		.effect = EFFECT_MAX_MOVE,
		.power = 10,
		.type = TYPE_POISON,
		.accuracy = 0,
		.pp = 10,
		.secondaryEffectChance = 100,
		.target = MOVE_TARGET_SELECTED,
		.priority = 0,
		.split = SPLIT_PHYSICAL,
		.argument = MAX_EFFECT_POISON_FOES,
	},

	[MOVE_G_MAX_MELTDOWN] =
	{
		.effect = EFFECT_MAX_MOVE,
		.power = 10,
		.type = TYPE_STEEL,
		.accuracy = 0,
		.pp = 10,
		.secondaryEffectChance = 100,
		.target = MOVE_TARGET_SELECTED,
		.priority = 0,
		.split = SPLIT_PHYSICAL,
		.argument = MAX_EFFECT_TORMENT_FOES,
	},

	[MOVE_G_MAX_DRUM_SOLO] =
	{	//ANIM TODO
		.effect = EFFECT_MAX_MOVE,
		.power = 10,
		.type = TYPE_GRASS,
		.accuracy = 0,
		.pp = 10,
		.secondaryEffectChance = 100,
		.target = MOVE_TARGET_SELECTED,
		.priority = 0,
		.split = SPLIT_PHYSICAL,
		.argument = MAX_EFFECT_FIXED_POWER, //EFFECT TODO
        //.ignoresTargetAbility = TRUE,
	},

	[MOVE_G_MAX_FIREBALL] =
	{	//ANIM TODO
		.effect = EFFECT_MAX_MOVE,
		.power = 10,
		.type = TYPE_FIRE,
		.accuracy = 0,
		.pp = 10,
		.secondaryEffectChance = 100,
		.target = MOVE_TARGET_SELECTED,
		.priority = 0,
		.split = SPLIT_PHYSICAL,
		.argument = MAX_EFFECT_FIXED_POWER, //EFFECT TODO
        //.ignoresTargetAbility = TRUE,
	},

	[MOVE_G_MAX_HYDROSNIPE] =
	{	//ANIM TODO
		.effect = EFFECT_MAX_MOVE,
		.power = 10,
		.type = TYPE_WATER,
		.accuracy = 0,
		.pp = 10,
		.secondaryEffectChance = 100,
		.target = MOVE_TARGET_SELECTED,
		.priority = 0,
		.split = SPLIT_PHYSICAL,
		.argument = MAX_EFFECT_FIXED_POWER, //EFFECT TODO
        //.ignoresTargetAbility = TRUE,
	},

	[MOVE_G_MAX_WIND_RAGE] =
	{
		.effect = EFFECT_MAX_MOVE,
		.power = 10,
		.type = TYPE_FLYING,
		.accuracy = 0,
		.pp = 10,
		.secondaryEffectChance = 100,
		.target = MOVE_TARGET_SELECTED,
		.priority = 0,
		.split = SPLIT_PHYSICAL,
		.argument = MAX_EFFECT_DEFOG,
	},

	[MOVE_G_MAX_GRAVITAS] =
	{
		.effect = EFFECT_MAX_MOVE,
		.power = 10,
		.type = TYPE_PSYCHIC,
		.accuracy = 0,
		.pp = 10,
		.secondaryEffectChance = 100,
		.target = MOVE_TARGET_SELECTED,
		.priority = 0,
		.split = SPLIT_PHYSICAL,
		.argument = MAX_EFFECT_GRAVITY,
	},

	[MOVE_G_MAX_STONESURGE] =
	{
		.effect = EFFECT_MAX_MOVE,
		.power = 10,
		.type = TYPE_WATER,
		.accuracy = 0,
		.pp = 10,
		.secondaryEffectChance = 100,
		.target = MOVE_TARGET_SELECTED,
		.priority = 0,
		.split = SPLIT_PHYSICAL,
		.argument = MAX_EFFECT_STEALTH_ROCK,
	},

	[MOVE_G_MAX_VOLCALITH] =
	{
		.effect = EFFECT_MAX_MOVE,
		.power = 10,
		.type = TYPE_ROCK,
		.accuracy = 0,
		.pp = 10,
		.secondaryEffectChance = 100,
		.target = MOVE_TARGET_SELECTED,
		.priority = 0,
		.split = SPLIT_PHYSICAL,
		.argument = MAX_EFFECT_VOLCALITH,
	},

	[MOVE_G_MAX_TARTNESS] =
	{
		.effect = EFFECT_MAX_MOVE,
		.power = 10,
		.type = TYPE_GRASS,
		.accuracy = 0,
		.pp = 10,
		.secondaryEffectChance = 100,
		.target = MOVE_TARGET_SELECTED,
		.priority = 0,
		.split = SPLIT_PHYSICAL,
		.argument = MAX_EFFECT_LOWER_EVASIVENESS_FOES,
	},

	[MOVE_G_MAX_SWEETNESS] =
	{
		.effect = EFFECT_MAX_MOVE,
		.power = 10,
		.type = TYPE_GRASS,
		.accuracy = 0,
		.pp = 10,
		.secondaryEffectChance = 100,
		.target = MOVE_TARGET_SELECTED,
		.priority = 0,
		.split = SPLIT_PHYSICAL,
		.argument = MAX_EFFECT_AROMATHERAPY,
	},

	[MOVE_G_MAX_SANDBLAST] =
	{
		.effect = EFFECT_MAX_MOVE,
		.power = 10,
		.type = TYPE_GROUND,
		.accuracy = 0,
		.pp = 10,
		.secondaryEffectChance = 100,
		.target = MOVE_TARGET_SELECTED,
		.priority = 0,
		.split = SPLIT_PHYSICAL,
		.argument = MAX_EFFECT_SANDBLAST_FOES,
	},

	[MOVE_G_MAX_STUN_SHOCK] =
	{
		.effect = EFFECT_MAX_MOVE,
		.power = 10,
		.type = TYPE_ELECTRIC,
		.accuracy = 0,
		.pp = 10,
		.secondaryEffectChance = 100,
		.target = MOVE_TARGET_SELECTED,
		.priority = 0,
		.split = SPLIT_PHYSICAL,
		.argument = MAX_EFFECT_POISON_PARALYZE_FOES,
	},

	[MOVE_G_MAX_CENTIFERNO] =
	{
		.effect = EFFECT_MAX_MOVE,
		.power = 10,
		.type = TYPE_FIRE,
		.accuracy = 0,
		.pp = 10,
		.secondaryEffectChance = 100,
		.target = MOVE_TARGET_SELECTED,
		.priority = 0,
		.split = SPLIT_PHYSICAL,
		.argument = MAX_EFFECT_FIRE_SPIN_FOES,
	},

	[MOVE_G_MAX_SMITE] =
	{
		.effect = EFFECT_MAX_MOVE,
		.power = 10,
		.type = TYPE_FAIRY,
		.accuracy = 0,
		.pp = 10,
		.secondaryEffectChance = 100,
		.target = MOVE_TARGET_SELECTED,
		.priority = 0,
		.split = SPLIT_PHYSICAL,
		.argument = MAX_EFFECT_CONFUSE_FOES,
	},


	[MOVE_G_MAX_SNOOZE] =
	{
		.effect = EFFECT_MAX_MOVE,
		.power = 10,
		.type = TYPE_DARK,
		.accuracy = 0,
		.pp = 10,
		.secondaryEffectChance = 100,
		.target = MOVE_TARGET_SELECTED,
		.priority = 0,
		.split = SPLIT_PHYSICAL,
		.argument = MAX_EFFECT_YAWN_FOE,
	},

	[MOVE_G_MAX_FINALE] =
	{
		.effect = EFFECT_MAX_MOVE,
		.power = 10,
		.type = TYPE_FAIRY,
		.accuracy = 0,
		.pp = 10,
		.secondaryEffectChance = 100,
		.target = MOVE_TARGET_SELECTED,
		.priority = 0,
		.split = SPLIT_PHYSICAL,
		.argument = MAX_EFFECT_HEAL_TEAM,
	},

	[MOVE_G_MAX_STEELSURGE] =
	{
		.effect = EFFECT_MAX_MOVE,
		.power = 10,
		.type = TYPE_STEEL,
		.accuracy = 0,
		.pp = 10,
		.secondaryEffectChance = 100,
		.target = MOVE_TARGET_SELECTED,
		.priority = 0,
		.split = SPLIT_PHYSICAL,
		.argument = MAX_EFFECT_STEELSURGE,
	},

	[MOVE_G_MAX_DEPLETION] =
	{
		.effect = EFFECT_MAX_MOVE,
		.power = 10,
		.type = TYPE_DRAGON,
		.accuracy = 0,
		.pp = 10,
		.secondaryEffectChance = 100,
		.target = MOVE_TARGET_SELECTED,
		.priority = 0,
		.split = SPLIT_PHYSICAL,
		.argument = MAX_EFFECT_TARGET_LAST_MOVE_MINUS_4_PP,
	},

	[MOVE_G_MAX_ONE_BLOW] =
	{
		.effect = EFFECT_MAX_MOVE,
		.power = 10,
		.type = TYPE_DARK,
		.accuracy = 0,
		.pp = 10,
		.secondaryEffectChance = 100,
		.target = MOVE_TARGET_SELECTED,
		.priority = 0,
		.split = SPLIT_PHYSICAL,
		.argument = MAX_EFFECT_BYPASS_PROTECT, //EFFECT TODO
	},

	[MOVE_G_MAX_RAPID_FLOW] =
	{	//ANIM TODO
		.effect = EFFECT_MAX_MOVE,
		.power = 10,
		.type = TYPE_WATER,
		.accuracy = 0,
		.pp = 10,
		.secondaryEffectChance = 100,
		.target = MOVE_TARGET_SELECTED,
		.priority = 0,
		.split = SPLIT_PHYSICAL,
		.argument = MAX_EFFECT_BYPASS_PROTECT, //EFFECT TODO
	},

    // Custom Moves
    [MOVE_KINGS_GRACE] =
    {
        .effect = EFFECT_HIT,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 1,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_ALL_BATTLERS,
        .priority = 0,
        .flags = 0,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_SPD_UP_1,
    },

    [MOVE_FROZEN_TERRAIN] =
    {
        .effect = EFFECT_FROZEN_TERRAIN,
        .power = 0,
        .type = TYPE_ICE,
        .accuracy = 0,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_ALL_BATTLERS,
        .priority = 0,
        .flags = 0,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_SPD_UP_1,
    },

    [MOVE_CURSED_TERRAIN] =
    {
        .effect = EFFECT_CURSED_TERRAIN,
        .power = 0,
        .type = TYPE_GHOST,
        .accuracy = 0,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_ALL_BATTLERS,
        .priority = 0,
        .flags = 0,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_ATK_UP_1,
    },

    [MOVE_RAVINE_TERRAIN] =
    {
        .effect = EFFECT_RAVINE_TERRAIN,
        .power = 0,
        .type = TYPE_FLYING,
        .accuracy = 0,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_ALL_BATTLERS,
        .priority = 0,
        .flags = 0,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_SPDEF_UP_1,
    },

    [MOVE_BURNING_TERRAIN] =
    {
        .effect = EFFECT_BURNING_TERRAIN,
        .power = 0,
        .type = TYPE_FIRE,
        .accuracy = 0,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_ALL_BATTLERS,
        .priority = 0,
        .flags = 0,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_SPATK_UP_1,
    },

    [MOVE_SANDY_TERRAIN] =
    {
        .effect = EFFECT_SANDY_TERRAIN,
        .power = 0,
        .type = TYPE_GROUND,
        .accuracy = 0,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_ALL_BATTLERS,
        .priority = 0,
        .flags = 0,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_DEF_UP_1,
    },

    [MOVE_SWAMP_TERRAIN] =
    {
        .effect = EFFECT_SWAMP_TERRAIN,
        .power = 0,
        .type = TYPE_WATER,
        .accuracy = 0,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_ALL_BATTLERS,
        .priority = 0,
        .flags = 0,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_SPDEF_UP_1,
    },

    [MOVE_VENOMOUS_TERRAIN] =
    {
        .effect = EFFECT_VENOMOUS_TERRAIN,
        .power = 0,
        .type = TYPE_POISON,
        .accuracy = 0,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_ALL_BATTLERS,
        .priority = 0,
        .flags = 0,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_SPDEF_UP_1,
    },

    [MOVE_ROSE_WHIP] =
    {
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_HAS_SECONDARY_EFFECT,
        .effect = EFFECT_ROSE_WHIP,
        .power = 70,
        .type = TYPE_GRASS,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 100,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 140,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_GEOGEYSER] =
    {
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_HAS_SECONDARY_EFFECT | FLAG_DAMAGE_ON_UNDERGROUND_TARGET,
        .effect = EFFECT_TARGET_BURN_ON_HIT,
        .power = 90,
        .type = TYPE_WATER,
        .accuracy = 95,
        .pp = 10,
        .secondaryEffectChance = 30,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .split = SPLIT_SPECIAL,
        .zMovePower = 175,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_FEATHER_SHOT] =
    {
        .effect = EFFECT_TARGET_MULTI_HIT,
        .power = 15,
        .type = TYPE_FLYING,
        .accuracy = 100,
        .pp = 15,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 1,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_HIGH_CRITICAL_HIT_RATIO | FLAG_AURA_BEAM_CANNON_GUN_PULSE_PUMP_SHOT_AND_ZOOKA_MOVE,
        .flags2 = FLAG_SLOTTED_SHELL_MOVE,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 100,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_WITCHCRAFT] =
    {
        .effect = EFFECT_SET_TYPE,
        .power = 0,
        .type = TYPE_FAIRY,
        .accuracy = 100,
        .pp = 20,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MAGIC_COAT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        .split = SPLIT_STATUS,
        .argument = TYPE_DRAGON,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_SPATK_UP_1,
    },

    [MOVE_EXCALIBUR] =
    {
        .effect = EFFECT_HIT,
        .power = 70,
        .type = TYPE_STEEL,
        .accuracy = 100,
        .pp = 20,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_HIGH_CRITICAL_HIT_RATIO,
        .flags2 = FLAG_SLICING_MOVE | FLAG_SCENT_MARK_AFFECTED,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 140,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_SHIELD_BASH] =
    {
        .effect = EFFECT_BODY_PRESS,
        .power = 80,
        .type = TYPE_STEEL,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .flags2 = FLAG_SCENT_MARK_AFFECTED,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 160,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_DRAGON_BONE] =
    {
        .effect = EFFECT_BOLT_BEAK,
        .power = 85,
        .type = TYPE_DRAGON,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .flags2 = FLAG_SCENT_MARK_AFFECTED,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 160,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_DRACO_IMPACT] =
    {
        .effect = EFFECT_USER_FIRST_TURN_PREPARE_SECOND_TURN_ATTACK,
        .power = 130,
        .type = TYPE_DRAGON,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 195,
        .zMoveEffect = Z_EFFECT_NONE,
        .argument = STAT_ATK,
    },

    [MOVE_WARM_UP] =
    {
        .effect = EFFECT_WARM_UP,
        .power = 0,
        .type = TYPE_FIRE,
        .accuracy = 0,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .flags = FLAG_SNATCH_AFFECTED | FLAG_THAW_USER,
        .split = SPLIT_STATUS,
        .argument = TYPE_FIRE,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_RESET_STATS,
    },

    [MOVE_CHRISTMAS_GIFT] =
    {
        .effect = EFFECT_CHRISTMAS_GIFT,
        .power = 0,
        .type = TYPE_ICE,
        .accuracy = 0,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_ALL_BATTLERS,
        .priority = 0,
        .flags = 0,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_FOLLOW_ME,
    },

    [MOVE_ARTIC_GLIDE] =
    {
        .effect = EFFECT_ARTIC_GLIDE,
        .power = 60,
        .type = TYPE_ICE,
        .accuracy = 100,
        .pp = 20,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .flags2 = FLAG_SCENT_MARK_AFFECTED,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 140,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_COIN_SHOWER] =
    {
        .effect = EFFECT_COIN_SHOWER,
        .power = 90,
        .type = TYPE_STEEL,
        .accuracy = 90,
        .pp = 10,
        .secondaryEffectChance = 30,
        .target = MOVE_TARGET_BOTH,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 175,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_MAMMOTH_MASH] =
    {
        .effect = EFFECT_USER_SPEED_DOWN_1_ON_HIT,
        .power = 120,
        .type = TYPE_GROUND,
        .accuracy = 90,
        .pp = 5,
        .secondaryEffectChance = 100,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 190,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_BERRY_BELLY_FLOP] =
    {
        .effect = EFFECT_BERRY_BELLY_FLOP,
        .power = 90,
        .type = TYPE_NORMAL,
        .accuracy = 95,
        .pp = 10,
        .secondaryEffectChance = 100,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 175,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_NAP_SLAM] =
    {
        .power = 50,
        .effect = EFFECT_CAN_BE_USED_ASLEEP_AND_TARGET_FLINCH_ON_HIT,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 15,
        .secondaryEffectChance = 30,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_HAS_SECONDARY_EFFECT,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 100,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_POWER_NAP] =
    {
        .effect = EFFECT_USER_RESTORE_FULL_HP_AND_SLEEP,
        .power = 0,
        .type = TYPE_PSYCHIC,
        .accuracy = 0,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .flags = FLAG_SNATCH_AFFECTED,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_RESET_STATS,
    },

    [MOVE_SEISMIC_SLAM] =
    {
        .effect = EFFECT_SKY_DROP,
        .power = 120,
        .type = TYPE_FLYING,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 175,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_BARRAGE_BLOW] =
    {
        .effect = EFFECT_BARRAGE_BLOW,
        .power = 130,
        .type = TYPE_FIGHTING,
        .accuracy = 100,
        .pp = 5,
        .secondaryEffectChance = 100,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 195,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_QUEEN_ASCENDANT] =
    {
        .effect = EFFECT_USER_DRAIN_75_ON_HIT,
        .power = 100,
        .type = TYPE_GRASS,
        .accuracy = 100,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 180,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_LIVID_OUTRAGE] =
    {
        .power = 130,
        .pp = 10,
        .effect = EFFECT_USER_RAMPAGE,
        .type = TYPE_DRAGON,
        .accuracy = 100,
        .secondaryEffectChance = 100,
        .target = MOVE_TARGET_RANDOM,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .flags2 = FLAG_EMOTION_MOVE,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 195,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_AURA_CANNON] =
    {
        .power = 100,
        .effect = EFFECT_HIT,
        .type = TYPE_FIGHTING,
        .accuracy = 0,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_BALL_AND_BOMB_MOVE,
        .flags2 = FLAG_SCENT_MARK_AFFECTED,
        .split = SPLIT_SPECIAL,
        .zMovePower = 180,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_RINGS_UNBOUND] =
    {
        .effect = EFFECT_RINGS_UNBOUND,
        .power = 0,
        .type = TYPE_PSYCHIC,
        .accuracy = 0,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_ACC_UP_1,
    },

    [MOVE_NOCK_LOCK] =
    {
        .power = 25,
        .effect = EFFECT_TARGET_MULTI_HIT,
        .type = TYPE_GRASS,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 100,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_BLISS_ASSISTANCE] =
    {
        .priority = 2,
        .effect = EFFECT_BLISS_ASSISTANCE,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .flags = 0,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_RECOVER_HP,
    },

    [MOVE_FAIRY_SINGULARITY] =
    {
        .effect = EFFECT_FUTURE_SIGHT,
        .power = 140,
        .type = TYPE_FAIRY,
        .accuracy = 100,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        .split = SPLIT_SPECIAL,
        .zMovePower = 200,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_MIDNIGHT_SLASH] =
    {
        .power = 70,
        .effect = EFFECT_HIT,
        .type = TYPE_DARK,
        .accuracy = 0,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .flags2 = FLAG_SLICING_MOVE | FLAG_SCENT_MARK_AFFECTED | FLAG_ALWAYS_CRITICAL_HIT,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 140,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_PHANTOM_AMBUSH] =
    {
        .effect = EFFECT_SEMI_INVULNERABLE,
        .power = 120,
        .type = TYPE_GHOST,
        .accuracy = 100,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .split = SPLIT_SPECIAL,
        .argument2 = MOVE_EFFECT_FEINT,
        .zMovePower = 190,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_FLAME_SWEEP] =
    {
        .effect = EFFECT_USER_RECOIL_33_SPEED_UP_WITH_STATUS,
        .power = 120,
        .type = TYPE_FIRE,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 10,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_HAS_SECONDARY_EFFECT | FLAG_RECOIL_DAMAGE | FLAG_THAW_USER,
        .split = SPLIT_PHYSICAL,
        .argument = MOVE_EFFECT_BURN,
        .zMovePower = 190,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_WATERBURST_SHURIKEN] =
    {
        .power = 110,
        .effect = EFFECT_TARGET_SPEED_DOWN_1_ON_HIT,
        .type = TYPE_WATER,
        .accuracy = 85,
        .pp = 5,
        .secondaryEffectChance = 100,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .split = SPLIT_SPECIAL,
        .zMovePower = 185,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_GATLING_GULP_MISSILE] =
    {
        .effect = EFFECT_GATLING_GULP_MISSILE,
        .power = 20,
        .type = TYPE_WATER,
        .accuracy = 90,
        .pp = 10,
        .secondaryEffectChance = 10,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_HAS_SECONDARY_EFFECT,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 100,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_DEATHROLL] =
    {
        .effect = EFFECT_STAR_ICON,
        .power = 100,
        .type = TYPE_WATER,
        .accuracy = 80,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_HAS_SECONDARY_EFFECT | FLAG_BITING_MOVE | FLAG_IGNORE_TARGET_STATS_STAGES,
        .flags2 = FLAG_SCENT_MARK_AFFECTED,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 180,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_UNDERGROUND_BITE] =
    {
        .power = 100,
        .effect = EFFECT_SEMI_INVULNERABLE,
        .type = TYPE_GROUND,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_BITING_MOVE,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 180,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_INK_JET] =
    {
        .effect = EFFECT_INK_JET,
        .power = 0,
        .type = TYPE_GROUND,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 1,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MAGIC_COAT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_AURA_BEAM_CANNON_GUN_PULSE_PUMP_SHOT_AND_ZOOKA_MOVE,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_RESTORE_REPLACEMENT_HP,
    },

    [MOVE_AQUA_TORNADO] =
    {
        .power = 100,
        .effect = EFFECT_AQUA_TORNADO,
        .type = TYPE_WATER,
        .accuracy = 100,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .flags2 = FLAG_SCENT_MARK_AFFECTED,
        .split = SPLIT_SPECIAL,
        .zMovePower = 180,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_TYRANNICAL_RAMPAGE] =
    {
        .power = 130,
        .effect = EFFECT_TYRANNICAL_RAMPAGE,
        .type = TYPE_ROCK,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 100,
        .target = MOVE_TARGET_RANDOM,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 195,
        .zMoveEffect = Z_EFFECT_NONE,
        .argument = 10,
    },

    [MOVE_THUNDERSTORM] =
    {
        .power = 30,
        .effect = EFFECT_THUNDERSTORM,
        .type = TYPE_ELECTRIC,
        .accuracy = 0,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_OPPONENTS_FIELD,
        .priority = 0,
        .flags = 0,
        .split = SPLIT_SPECIAL,
        .zMovePower = 210,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_PHANTOM_FOREST] =
    {
        .power = 0,
        .effect = EFFECT_PHANTOM_FOREST,
        .type = TYPE_GHOST,
        .accuracy = 0,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_OPPONENTS_FIELD,
        .priority = 0,
        .flags = 0,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_SPDEF_UP_1,
    },

    [MOVE_REVOLVING_RUIN] =
    {
        .power = 90,
        .effect = EFFECT_REVOLVING_RUIN,
        .type = TYPE_STEEL,
        .accuracy = 0,
        .pp = 10,
        .secondaryEffectChance = 100,
        .target = MOVE_TARGET_FOES_AND_ALLY,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        .split = SPLIT_SPECIAL,
        .zMovePower = 175,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_RUBBLE_ROUSER] =
    {
        .power = 90,
        .effect = EFFECT_RUBBLE_ROUSER,
        .type = TYPE_ROCK,
        .accuracy = 90,
        .pp = 10,
        .secondaryEffectChance = 100,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 175,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_SNOW_GLOBE] =
    {
        .power = 80,
        .effect = EFFECT_SNOW_GLOBE,
        .type = TYPE_ICE,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 30,
        .target = MOVE_TARGET_BOTH,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        .split = SPLIT_SPECIAL,
        .zMovePower = 160,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_HYDRO_TYPHOON] =
    {
        .power = 120,
        .effect = EFFECT_TARGET_FLINCH_ON_HIT,
        .type = TYPE_WATER,
        .accuracy = 90,
        .pp = 5,
        .secondaryEffectChance = 30,
        .target = MOVE_TARGET_FOES_AND_ALLY,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_AURA_BEAM_CANNON_GUN_PULSE_PUMP_SHOT_AND_ZOOKA_MOVE,
        .split = SPLIT_SPECIAL,
        .zMovePower = 190,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_BLAZING_BICYCLE_KICK] =
    {
        .power = 120,
        .effect = EFFECT_DAMAGE_MISSING_HP,
        .type = TYPE_FIRE,
        .accuracy = 80,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        .split = SPLIT_PHYSICAL,
        .argument = 10,
        .zMovePower = 190,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_COUP_DE_GRACE] =
    {
        .power = 120,
        .effect = EFFECT_DAMAGE_MISSING_HP,
        .type = TYPE_STEEL,
        .accuracy = 80,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        .split = SPLIT_PHYSICAL,
        .argument = 10,
        .zMovePower = 190,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_FANCIFUL_FIREWORKS] =
    {
        .power = 90,
        .effect = EFFECT_FANCIFUL_FIREWORKS,
        .type = TYPE_FIRE,
        .accuracy = 95,
        .pp = 10,
        .secondaryEffectChance = 100,
        .target = MOVE_TARGET_BOTH,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        .split = SPLIT_SPECIAL,
        .zMovePower = 175,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_MOCKING_SHOUT] =
    {
        .power = 0,
        .effect = EFFECT_MOCKING_SHOUT,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 15,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_BOTH,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MAGIC_COAT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_SOUND_BASED_MOVE,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_ATK_UP_2,
    },

    [MOVE_STREAM_IMPULSE] =
    {
        .flags = FLAG_SNATCH_AFFECTED,
        .effect = EFFECT_MAGNET_RISE,
        .power = 0,
        .type = TYPE_WATER,
        .accuracy = 0,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_USER,
        .priority = 1,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_EVSN_UP_1,
    },

    [MOVE_SPICY_BREATH] =
    {
        .effect = EFFECT_SPICY_BREATH,
        .power = 60,
        .type = TYPE_FIRE,
        .accuracy = 100,
        .pp = 20,
        .secondaryEffectChance = 20,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED,
        .split = SPLIT_PHYSICAL,
        .argument = MOVE_EFFECT_BURN,
        .zMovePower = 100,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_DARK_BARGAIN] =
    {
        .effect = EFFECT_DARK_BARGAIN,
        .power = 0,
        .type = TYPE_DARK,
        .accuracy = 0,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .flags = FLAG_SNATCH_AFFECTED,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_RECOVER_HP,
    },

    [MOVE_BLOOD_PACT] =
    {
        .effect = EFFECT_BLOOD_PACT,
        .power = 0,
        .type = TYPE_DARK,
        .accuracy = 0,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .flags = FLAG_SNATCH_AFFECTED,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_RECOVER_HP,
    },

    [MOVE_FOG] =
    {
        .effect = EFFECT_FOG,
        .power = 0,
        .type = TYPE_FLYING,
        .accuracy = 0,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_ALL_BATTLERS,
        .priority = 0,
        .flags = 0,
        .flags2 = FLAG_WEATHER_RELATED_MOVE,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_SPD_UP_1,
    },

    [MOVE_NEUROTOXIN] =
    {
        .effect = EFFECT_NEUROTOXIN,
        .power = 50,
        .type = TYPE_POISON,
        .accuracy = 100,
        .pp = 15,
        .secondaryEffectChance = 100,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 100,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_TOUGH_IT_OUT] =
    {
        .effect = EFFECT_TOUGH_IT_OUT,
        .power = 0,
        .type = TYPE_FIGHTING,
        .accuracy = 0,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .flags = FLAG_SNATCH_AFFECTED,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_RESET_STATS,
    },

    [MOVE_RECKLESS_SWING] =
    {
        .effect = EFFECT_RECKLESS_SWING,
        .power = 50,
        .type = TYPE_DARK,
        .accuracy = 100,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
        .argument = 25, // cause X% damage to user and X% as additional damage to target
        .zMovePower = 190,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_UNDERTOW] =
    {
        .effect = EFFECT_UNDERTOW,
        .power = 60,
        .type = TYPE_STEEL,
        .accuracy = 100,
        .pp = 15,
        .secondaryEffectChance = 30,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 120,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_PHOENIX_DOWN] =
    {
        .effect = EFFECT_REVIVE,
        .power = 0,
        .type = TYPE_FAIRY,
        .accuracy = 0,
        .pp = 1,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .flags = 0,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_FOREST_BLESSING] =
    {
        .effect = EFFECT_REVIVE,
        .power = 0,
        .type = TYPE_GRASS,
        .accuracy = 0,
        .pp = 1,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .flags = 0,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_FOREST_FURY] =
    {
        .effect = EFFECT_FOREST_FURY,   
        .power = 70,
        .type = TYPE_GRASS,
        .accuracy = 100,
        .pp = 20,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .flags2 = FLAG_SCENT_MARK_AFFECTED,
        .split = SPLIT_SPECIAL,
        .zMovePower = 140,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_CRAFTY_CLOTHES] =
    {
        .effect = EFFECT_CRAFTY_CLOTHES,
        .power = 0,
        .type = TYPE_GRASS,
        .accuracy = 0,
        .pp = 20,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .flags = FLAG_SNATCH_AFFECTED,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_DRAGON_COMBO] =
    {
        .effect = EFFECT_DRAGON_COMBO,
        .power = 90,
        .type = TYPE_DRAGON,
        .accuracy = 90,
        .pp = 10,
        .secondaryEffectChance = 20,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_PUNCHING_MOVE,
        .split = SPLIT_PHYSICAL,
        .argument = 10, // cause X% damage to user and X% as additional damage to target
        .zMovePower = 175,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_KI_EXPLOSION] =
    {
        .effect = EFFECT_KI_EXPLOSION,
        .power = 50,
        .type = TYPE_PSYCHIC,
        .accuracy = 95,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_PUNCHING_MOVE,
        .flags2 = FLAG_SCENT_MARK_AFFECTED,
        .split = SPLIT_PHYSICAL,
        .argument = 1, // addicional of (Target's Defense) / X in damage calculation
        .zMovePower = 160,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_HELL_GATE] =
    {
        .effect = EFFECT_HELL_GATE,
        .power = 1,
        .type = TYPE_DARK,
        .accuracy = 100,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED,
        .split = SPLIT_SPECIAL,
        .zMovePower = 180,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_CORDYCEPS] =
    {
        .effect = EFFECT_CORDYCEPS,
        .power = 0,
        .type = TYPE_GRASS,
        .accuracy = 90,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MAGIC_COAT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_POWDER_AND_SPORE_MOVE,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_RESET_STATS,
    },

    [MOVE_AQUA_FANG] =
    {
        .effect = EFFECT_FLINCH_STATUS,
        .power = 65,
        .type = TYPE_WATER,
        .accuracy = 95,
        .pp = 15,
        .secondaryEffectChance = 10,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_HAS_SECONDARY_EFFECT | FLAG_BITING_MOVE,
        .flags2 = FLAG_FANG_MOVE,
        .split = SPLIT_PHYSICAL,
        .argument = MOVE_EFFECT_DEF_MINUS_1,
        .zMovePower = 120,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_BLOOMSDAY] =
    {
        .effect = EFFECT_BLOOMSDAY,
        .power = 0,
        .type = TYPE_GRASS,
        .accuracy = 0,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .flags = 0,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_SPD_UP_1,
    },

    [MOVE_QUAKE_HAMMER] =
    {
        .effect = EFFECT_EARTHQUAKE,
        .power = 150,
        .type = TYPE_GROUND,
        .accuracy = 100,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_FOES_AND_ALLY,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_DAMAGE_ON_UNDERGROUND_TARGET,
        .flags2 = FLAG_CANNOT_BE_USED_CONSECUTIVELY,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 200,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_HOME_RUN] =
    {
        .effect = EFFECT_KNOCK_FLYING_TARGET_DOWN,
        .power = 150,
        .type = TYPE_ROCK,
        .accuracy = 95,
        .pp = 5,
        .secondaryEffectChance = 100,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_DAMAGE_ON_FLYING_TARGET,
        .flags2 = FLAG_CANNOT_BE_USED_CONSECUTIVELY,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 200,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_HELLBLAZE] =
    {
        .power = 90,
        .pp = 10,
        .effect = EFFECT_HELLBLAZE,
        .type = TYPE_DARK,
        .accuracy = 100,
        .secondaryEffectChance = 100,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        .split = SPLIT_SPECIAL,
        .zMovePower = 175,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_DIAMOND_DUST] =
    {
        .effect = EFFECT_DEFENSE_UP_1_ON_HIT,
        .power = 90,
        .type = TYPE_ROCK,
        .accuracy = 95,
        .pp = 10,
        .secondaryEffectChance = 50,
        .target = MOVE_TARGET_BOTH,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_HAS_SECONDARY_EFFECT,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 175,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_MOONFALL] =
    {
        .effect = EFFECT_MOONFALL,
        .power = 180,
        .type = TYPE_FAIRY,
        .accuracy = 80,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_ALL_BATTLERS,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .flags2 = FLAG_COSMIC_ENERGYZED_MOVE,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 200,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_FALLING_STARS] =
    {
        .effect = EFFECT_FALLING_STARS,
        .power = 20,
        .type = TYPE_STEEL,
        .accuracy = 90,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_ALL_BATTLERS,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 40,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_ALI_SHUFFLE] =
    {
        .priority = 4,
        .effect = EFFECT_USER_PREVENT_MOVE,
        .power = 0,
        .type = TYPE_FIGHTING,
        .accuracy = 0,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_USER,
        .flags = FLAG_PROTECTION_MOVE,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_EVSN_UP_1,
    },

    [MOVE_ATOMIC_BREATH] =
    {
        .effect = EFFECT_USER_RECHARGE,
        .power = 160,
        .type = TYPE_ELECTRIC,
        .accuracy = 90,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .split = SPLIT_SPECIAL,
        .zMovePower = 200,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_PROTON_SCREAM] =
    {
        .effect = EFFECT_USER_RECHARGE,
        .power = 150,
        .type = TYPE_ELECTRIC,
        .accuracy = 90,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_SOUND_BASED_MOVE,
        .split = SPLIT_SPECIAL,
        .zMovePower = 200,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_FORCE_CHOKE] =
    {
        .effect = EFFECT_THROAT_CHOP,
        .power = 80,
        .type = TYPE_PSYCHIC,
        .accuracy = 100,
        .pp = 15,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_HAS_SECONDARY_EFFECT,
        .split = SPLIT_SPECIAL,
        .zMovePower = 160,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_FORCE_LIGHTNING] =
    {
        .power = 75,
        .zMovePower = 140,
        .effect = EFFECT_TARGET_ATTACK_DOWN_1_ON_HIT,
        .type = TYPE_ELECTRIC,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 100,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_HAS_SECONDARY_EFFECT,
        .split = SPLIT_SPECIAL,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_TRASH] =
    {
        .effect = EFFECT_TRASH,
        .power = 80,
        .type = TYPE_POISON,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 30,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_HAS_SECONDARY_EFFECT | FLAG_BALL_AND_BOMB_MOVE,
        .split = SPLIT_SPECIAL,
        .zMovePower = 160,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_HEAT_SIPHON] =
    {
        .power = 75,
        .pp = 10,
        .zMovePower = 140,
        .effect = EFFECT_HEAT_SIPHON,
        .type = TYPE_ICE,
        .accuracy = 100,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        .split = SPLIT_SPECIAL,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_DESPAIR_KISS] =
    {
        .effect = EFFECT_USER_DRAIN_75_ON_HIT,
        .power = 50,
        .type = TYPE_DARK,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .flags2 = FLAG_KISSING_MOVE,
        .split = SPLIT_SPECIAL,
        .zMovePower = 100,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_AURORA_DANCE] =
    {
        .effect = EFFECT_AURORA_DANCE,
        .power = 0,
        .type = TYPE_ICE,
        .accuracy = 0,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .flags = FLAG_SNATCH_AFFECTED | FLAG_DANCING_MOVE,
        .flags2 = FLAG_COSMIC_ENERGYZED_MOVE,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_RESET_STATS,
    },

    [MOVE_MUSTARD_GAS] =
    {
        .power = 50,
        .effect = EFFECT_TARGET_BURN_ON_HIT,
        .type = TYPE_FIRE,
        .accuracy = 0,
        .pp = 15,
        .secondaryEffectChance = 50,
        .target = MOVE_TARGET_BOTH,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_HAS_SECONDARY_EFFECT,
        .split = SPLIT_SPECIAL,
        .zMovePower = 100,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_ABSOLUTE_ZERO] =
    {
        .power = 0,
        .effect = EFFECT_ABSOLUTE_ZERO,
        .type = TYPE_ICE,
        .accuracy = 50,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_ALL_BATTLERS,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MAGIC_COAT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_RESET_STATS,
    },

    [MOVE_FIRE_IN_THE_HOLE] =
    {
        .power = 140,
        .effect = EFFECT_FUTURE_SIGHT,
        .type = TYPE_WATER,
        .accuracy = 100,
        .pp = 5,
        .secondaryEffectChance = 100,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = 0,
        .split = SPLIT_SPECIAL,
        .zMovePower = 200,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_BAD_BREATH] =
    {
        .power = 80,
        .effect = EFFECT_SPICY_BREATH,
        .type = TYPE_DRAGON,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 20,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED,
        .split = SPLIT_SPECIAL,
        .argument = MOVE_EFFECT_PARALYSIS,
        .zMovePower = 160,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_WATER_BALL] =
    {
        .effect = EFFECT_POPULATION_BOMB,
        .power = 20,
        .type = TYPE_WATER,
        .accuracy = 90,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .split = SPLIT_SPECIAL,
        .zMovePower = 40,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_DRAGON_FANG] =
    {
        .effect = EFFECT_ATTACK_UP_1_ON_HIT,
        .power = 75,
        .type = TYPE_DRAGON,
        .accuracy = 95,
        .pp = 15,
        .secondaryEffectChance = 20,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_HAS_SECONDARY_EFFECT | FLAG_BITING_MOVE,
        .flags2 = FLAG_FANG_MOVE,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 140,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_BELLY_BASH] =
    {
        .effect = EFFECT_DRAGON_COMBO,
        .power = 50,
        .type = TYPE_WATER,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 1,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        .split = SPLIT_PHYSICAL,
        .argument = 5, // cause X% damage to user and X% as additional damage to target
        .zMovePower = 100,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_FORCE_HEALING] =
    {
        .pp = 5,
        .effect = EFFECT_USER_RESTORE_50_HP,
        .power = 0,
        .type = TYPE_PSYCHIC,
        .accuracy = 0,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .flags = FLAG_SNATCH_AFFECTED,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_RESET_STATS,
    },

    [MOVE_SHADOW_STORM] =
    {
        .effect = EFFECT_HIT,
        .power = 110,
        .type = TYPE_WATER,
        .accuracy = 80,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .flags2 = FLAG_SHADOW_MOVE | FLAG_SCENT_MARK_AFFECTED,
        .split = SPLIT_SPECIAL,
        .zMovePower = 185,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_SHADOW_FIRE] =
    {
        .power = 90,
        .effect = EFFECT_TARGET_BURN_ON_HIT,
        .type = TYPE_FIRE,
        .accuracy = 100,
        .pp = 15,
        .secondaryEffectChance = 10,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_HAS_SECONDARY_EFFECT,
        .flags2 = FLAG_SHADOW_MOVE,
        .split = SPLIT_SPECIAL,
        .zMovePower = 175,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_SHADOW_BOLT] =
    {
        .power = 90,
        .effect = EFFECT_TARGET_PARALYZE_ON_HIT,
        .type = TYPE_ELECTRIC,
        .accuracy = 100,
        .pp = 15,
        .secondaryEffectChance = 10,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_HAS_SECONDARY_EFFECT,
        .flags2 = FLAG_SHADOW_MOVE,
        .split = SPLIT_SPECIAL,
        .zMovePower = 175,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_SHADOW_CHILL] =
    {
        .power = 90,
        .effect = EFFECT_TARGET_FROSTBITE_ON_HIT,
        .type = TYPE_ICE,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 20,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_HAS_SECONDARY_EFFECT,
        .flags2 = FLAG_SHADOW_MOVE,
        .split = SPLIT_SPECIAL,
        .zMovePower = 175,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_SHADOW_BLAST] =
    {
        .effect = EFFECT_HIT,
        .power = 100,
        .type = TYPE_FLYING,
        .accuracy = 95,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .flags2 = FLAG_WIND_MOVE | FLAG_LIFT_ENTRY_HAZARDS | FLAG_SHADOW_MOVE | FLAG_SCENT_MARK_AFFECTED | FLAG_ALWAYS_CRITICAL_HIT,
        .split = SPLIT_SPECIAL,
        .zMovePower = 180,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_SHADOW_END] =
    {
        .effect = EFFECT_PHOTON_GEYSER,
        .power = 100,
        .type = TYPE_DARK,
        .accuracy = 100,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_IGNORE_TARGET_ABILITIES,
        .flags2 = FLAG_SHADOW_MOVE,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 180,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_DARK_HARVEST] =
    {
        .power = 50,
        .effect = EFFECT_ATTACK_UP_3_WHEN_FAINTING,
        .type = TYPE_GHOST,
        .accuracy = 100,
        .pp = 25,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .flags2 = FLAG_SCENT_MARK_AFFECTED,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 100,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_BLACK_MAGIC] =
    {
        .effect = EFFECT_BLACK_MAGIC,
        .power = 90,
        .type = TYPE_GHOST,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .flags2 = FLAG_SCENT_MARK_AFFECTED,
        .split = SPLIT_SPECIAL,
        .zMovePower = 175,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_JUSTICE_KICK] =
    {
        .priority = 1,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        .effect = EFFECT_FAKE_OUT,
        .power = 130,
        .type = TYPE_WATER,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 195,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_SOUL_BLADES] =
    {
        .effect = EFFECT_KI_EXPLOSION,
        .power = 50,
        .type = TYPE_GHOST,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .flags2 = FLAG_SLICING_MOVE | FLAG_SCENT_MARK_AFFECTED,
        .split = SPLIT_PHYSICAL,
        .argument = 1, // addicional of (Target's Defense) / X in damage calculation
        .zMovePower = 160,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_CONVERGENCE] =
    {
        .effect = EFFECT_CONVERGENCE,
        .power = 0,
        .type = TYPE_PSYCHIC,
        .accuracy = 0,
        .pp = 20,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .flags = FLAG_SNATCH_AFFECTED,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_RESET_STATS,
    },

    [MOVE_TWIN_BITE] =
    {
        .effect = EFFECT_TWIN_BITE,
        .power = 40,
        .type = TYPE_DARK,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 20,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_HAS_SECONDARY_EFFECT | FLAG_BITING_MOVE | FLAG_TWO_STRIKES,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 100,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_PUNISHING_KICK] =
    {
        .effect = EFFECT_PUNISHING_KICK,
        .power = 1,
        .type = TYPE_DARK,
        .accuracy = 95,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_CRASH_DAMAGE_IF_MISS,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 195,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_FLYING_SIDE_KICK] =
    {
        .effect = EFFECT_USER_REDUCE_50_HP_IF_MISS,
        .power = 90,
        .type = TYPE_FLYING,
        .accuracy = 95,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_CRASH_DAMAGE_IF_MISS,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 175,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_SOUL_ENERGY] =
    {
        .effect = EFFECT_MIND_BLOWN,
        .power = 150,
        .type = TYPE_GHOST,
        .accuracy = 95,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_FOES_AND_ALLY,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .split = SPLIT_SPECIAL,
        .zMovePower = 200,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_JACK_O_LANTERN] =
    {
        .effect = EFFECT_TARGET_SPEED_DOWN_1_ON_HIT,
        .power = 85,
        .type = TYPE_FIRE,
        .accuracy = 95,
        .pp = 10,
        .secondaryEffectChance = 100,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 180,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_EERIE_TUNE] =
    {
        .effect = EFFECT_EERIE_TUNE,
        .power = 0,
        .type = TYPE_GHOST,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MAGIC_COAT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_SOUND_BASED_MOVE,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_DEF_UP_1,
    },

    [MOVE_HALLOWEEN] =
    {
        .effect = EFFECT_HALLOWEEN,
        .power = 0,
        .type = TYPE_GHOST,
        .accuracy = 0,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .flags = FLAG_SNATCH_AFFECTED,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_RESET_STATS,
    },

    [MOVE_DOUBLE_LARIAT] =
    {
        .effect = EFFECT_ROUND,
        .power = 60,
        .type = TYPE_FIGHTING,
        .accuracy = 100,
        .pp = 15,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 120,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_WONDER_WISH] =
    {
        .effect = EFFECT_JUNGLE_HEALING,
        .power = 0,
        .type = TYPE_FAIRY,
        .accuracy = 0,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_DEPENDS,
        .priority = 0,
        .flags = 0,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_BACK_STAB] =
    {
        .priority = 3,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_HAS_SECONDARY_EFFECT,
        .flags2 = FLAG_SLICING_MOVE,
        .effect = EFFECT_BACK_STAB,
        .power = 40,
        .type = TYPE_DARK,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 100,
        .target = MOVE_TARGET_SELECTED,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 100,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_THORN_TRAP] =
    {
        .power = 90,
        .pp = 10,
        .zMovePower = 175,
        .effect = EFFECT_THORN_TRAP,
        .type = TYPE_GRASS,
        .accuracy = 100,
        .secondaryEffectChance = 100,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_PLAY_WITH_ME] =
    {
        .power = 90,
        .pp = 10,
        .zMovePower = 175,
        .effect = EFFECT_THORN_TRAP,
        .type = TYPE_FAIRY,
        .accuracy = 100,
        .secondaryEffectChance = 100,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_ZANTETSUKEN] =
    {
        .effect = EFFECT_ZANTETSUKEN,
        .power = 130,
        .type = TYPE_STEEL,
        .accuracy = 0,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .flags2 = FLAG_SLICING_MOVE,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 195,
        .zMoveEffect = Z_EFFECT_NONE,
        .argument = 10,
    },

    [MOVE_DROP_WEIGHTS] =
    {
        .pp = 20,
        .effect = EFFECT_DROP_WEIGHTS,
        .power = 0,
        .type = TYPE_FIGHTING,
        .accuracy = 0,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .flags = 0,
        .flags2 = 0,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_RESET_STATS,
    },

    [MOVE_COMPUTE_AND_CRUSH] =
    {
        .effect = EFFECT_COMPUTE_AND_CRUSH,
        .power = 0,
        .type = TYPE_STEEL,
        .accuracy = 0,
        .pp = 20,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .flags = FLAG_SNATCH_AFFECTED,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_RESET_STATS,
    },

    [MOVE_IGNITE_MIDNIGHT] =
    {
        .power = 120,
        .pp = 10,
        .zMovePower = 190,
        .effect = EFFECT_USER_RAMPAGE,
        .type = TYPE_FIRE,
        .accuracy = 100,
        .secondaryEffectChance = 100,
        .target = MOVE_TARGET_RANDOM,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .split = SPLIT_SPECIAL,
        .zMoveEffect = Z_EFFECT_NONE,
        .argument = 1, //Won't be confuse
    },

    [MOVE_COTTON_CLOUD_CRASH] =
    {
        .power = 120,
        .zMovePower = 190,
        .effect = EFFECT_SEMI_INVULNERABLE,
        .type = TYPE_GRASS,
        .accuracy = 95,
        .pp = 10,
        .secondaryEffectChance = 100,
        .target = MOVE_TARGET_BOTH,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_HAS_SECONDARY_EFFECT,
        .split = SPLIT_SPECIAL,
        .zMoveEffect = Z_EFFECT_NONE,
        .argument2 = MOVE_EFFECT_SPD_MINUS_1,
    },

    [MOVE_MOONLIGHT_PRANCE] =
    {
        .power = 90,
        .zMovePower = 175,
        .effect = EFFECT_MOONLIGHT_PRANCE,
        .type = TYPE_DARK,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .split = SPLIT_SPECIAL,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_TRIPLE_TRAMPLE] =
    {
        .effect = EFFECT_TARGET_TRIPLE_HIT_MORE_DAMAGE_EACH_HIT,
        .power = 25,
        .type = TYPE_NORMAL,
        .accuracy = 90,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 100,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_DREEP_AND_DESTROY] =
    {
        .effect = EFFECT_DREEP_AND_DESTROY,
        .power = 50,
        .type = TYPE_DRAGON,
        .accuracy = 0,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_TWO_STRIKES,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 100,
        .zMoveEffect = Z_EFFECT_NONE,
        .argument = 5,
    },

    [MOVE_INFINITE_PSYBURN] =
    {
        .effect = EFFECT_INFINITE_PSYBURN,
        .power = 100,
        .type = TYPE_PSYCHIC,
        .accuracy = 0,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = 0,
        .flags2 = FLAG_IGNORE_TARGET_TYPES_IMMUNITY,
        .split = SPLIT_SPECIAL,
        .zMovePower = 185,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_SOVEREIGN_SWORD] =
    {
        .effect = EFFECT_USER_FIRST_TURN_PREPARE_SECOND_TURN_ATTACK,
        .power = 130,
        .type = TYPE_STEEL,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 195,
        .zMoveEffect = Z_EFFECT_NONE,
        .argument = STAT_ATK,
    },

    [MOVE_AZURE_SPY_VISION] =
    {
        .accuracy = 0,
        .effect = EFFECT_AZURE_SPY_VISION,
        .power = 0,
        .type = TYPE_WATER,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .flags = 0,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_SPD_UP_1,
    },

    [MOVE_MYSTICAL_MIRAGE] =
    {
        .accuracy = 0,
        .effect = EFFECT_MYSTICAL_MIRAGE,
        .power = 0,
        .type = TYPE_PSYCHIC,
        .pp = 1,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .flags = 0,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_SPD_UP_1,
    },

    [MOVE_SLOWBEAM] =
    {
        .effect = EFFECT_SLOWBEAM,
        .power = 70,
        .type = TYPE_PSYCHIC,
        .accuracy = 100,
        .pp = 15,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_AURA_BEAM_CANNON_GUN_PULSE_PUMP_SHOT_AND_ZOOKA_MOVE,
        .split = SPLIT_SPECIAL,
        .zMovePower = 140,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_NIGHTFALL_DAZE] =
    {
        .effect = EFFECT_USER_FIRST_TURN_PREPARE_SECOND_TURN_ATTACK,
        .power = 120,
        .type = TYPE_DARK,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .flags2 = FLAG_WEATHER_RELATED_MOVE | FLAG_COSMIC_ENERGYZED_MOVE,
        .split = SPLIT_SPECIAL,
        .zMovePower = 190,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_MOONY_NIGHT] =
    {
        .effect = EFFECT_NIGHT,
        .power = 0,
        .type = TYPE_FAIRY,
        .accuracy = 0,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_ALL_BATTLERS,
        .priority = 0,
        .flags = 0,
        .flags2 = FLAG_WEATHER_RELATED_MOVE | FLAG_COSMIC_ENERGYZED_MOVE,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_SPD_UP_1,
    },

    [MOVE_SPINNING_FLAME_FIST] =
    {
        .power = 50,
        .effect = EFFECT_SPEED_UP_1_AND_CLEAR_USER,
        .type = TYPE_FIRE,
        .accuracy = 100,
        .pp = 15,
        .secondaryEffectChance = 20,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_HAS_SECONDARY_EFFECT | FLAG_PUNCHING_MOVE,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 100,
        .zMoveEffect = Z_EFFECT_NONE,
        .argument = MOVE_EFFECT_BURN,
    },

    [MOVE_SPINNING_FLAME_KICK] =
    {
        .effect = EFFECT_ATTACK_UP_1_AND_CLEAR_USER,
        .power = 50,
        .type = TYPE_FIRE,
        .accuracy = 100,
        .pp = 15,
        .secondaryEffectChance = 20,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_HAS_SECONDARY_EFFECT,
        .flags2 = FLAG_AIRBOURNE_STYLE_BOOST,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 100,
        .zMoveEffect = Z_EFFECT_NONE,
        .argument = MOVE_EFFECT_BURN,
    },

    [MOVE_GLACIAL_STAGE] =
    {
        .effect = EFFECT_GLACIAL_STAGE,
        .power = 0,
        .type = TYPE_ICE,
        .accuracy = 0,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_ALL_BATTLERS,
        .priority = 0,
        .flags = 0,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_SPD_UP_1,
    },

    [MOVE_LAPRAS_EXPRESS] =
    {
        .power = 90,
        .target = MOVE_TARGET_SELECTED,
        .effect = EFFECT_LAPRAS_EXPRESS,
        .type = TYPE_WATER,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 0,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .split = SPLIT_SPECIAL,
        .zMovePower = 175,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_FLOWERY_FIELDS_FOREVER] =
    {
        .effect = EFFECT_FLOWERY_FIELDS_FOREVER,
        .power = 0,
        .type = TYPE_GRASS,
        .accuracy = 0,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_ALL_BATTLERS,
        .priority = 0,
        .flags = 0,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_DEF_UP_1,
    },

    [MOVE_GREEN_ILLUSION_DIVE] =
    {
        .effect = EFFECT_ILLUSION_DIVE,
        .power = 40,
        .type = TYPE_BUG,
        .accuracy = 100,
        .pp = 20,
        .secondaryEffectChance = 100,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_HAS_SECONDARY_EFFECT,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 100,
        .zMoveEffect = Z_EFFECT_NONE,
        .argument = BODY_COLOR_GREEN,
    },

    [MOVE_RED_ILLUSION_DIVE] =
    {
        .effect = EFFECT_ILLUSION_DIVE,
        .power = 40,
        .type = TYPE_STEEL,
        .accuracy = 100,
        .pp = 20,
        .secondaryEffectChance = 100,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_HAS_SECONDARY_EFFECT,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 100,
        .zMoveEffect = Z_EFFECT_NONE,
        .argument = BODY_COLOR_RED,
    },

    [MOVE_EMERALD_TWO_STEP] =
    {
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_HAS_SECONDARY_EFFECT,
        .effect = EFFECT_SEMI_INVULNERABLE,
        .power = 100,
        .type = TYPE_GRASS,
        .accuracy = 100,
        .pp = 5,
        .secondaryEffectChance = 50,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .split = SPLIT_PHYSICAL,
        .argument2 = MOVE_EFFECT_PARALYSIS,
        .zMovePower = 180,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_FAIRY_FROLIC] =
    {
        .priority = 0,
        .effect = EFFECT_USER_PREVENT_MOVE,
        .power = 0,
        .type = TYPE_FAIRY,
        .accuracy = 0,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_USER,
        .flags = FLAG_PROTECTION_MOVE,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_RESET_STATS,
    },

    [MOVE_EBON_FIST] =
    {
        .effect = EFFECT_EBON_FIST,
        .power = 100,
        .type = TYPE_FIGHTING,
        .accuracy = 100,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_PUNCHING_MOVE,
        .flags2 = FLAG_ALWAYS_CRITICAL_HIT,
        .split = SPLIT_PHYSICAL,
        .argument = MOVE_WICKED_BLOW,
        .zMovePower = 200,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_FLOWING_FISTS] =
    {
        .effect = EFFECT_FLOWING_FISTS,
        .power = 20,
        .type = TYPE_FIGHTING,
        .accuracy = 100,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_PUNCHING_MOVE,
        .flags2 = FLAG_ALWAYS_CRITICAL_HIT,
        .split = SPLIT_PHYSICAL,
        .argument = MOVE_SURGING_STRIKES,
        .zMovePower = 200,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_PSYCHIC_SOLAIRE] =
    {
        .effect = EFFECT_TELEKINESIS,
        .power = 0,
        .type = TYPE_PSYCHIC,
        .accuracy = 0,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_BOTH,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MAGIC_COAT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_SPATK_UP_1,
    },

    [MOVE_RIGHT_AS_RAIN] =
    {
        .effect = EFFECT_RAIN_DANCE,
        .power = 0,
        .type = TYPE_WATER,
        .accuracy = 0,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_ALL_BATTLERS,
        .priority = 0,
        .flags = 0,
        .flags2 = FLAG_WEATHER_RELATED_MOVE,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_SPD_UP_1,
    },

    [MOVE_SHOWTIME] =
    {
        .flags = FLAG_SNATCH_AFFECTED,
        .effect = EFFECT_SHOWTIME,
        .power = 0,
        .type = TYPE_FAIRY,
        .accuracy = 100,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_FOES_AND_ALLY,
        .priority = 0,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_SPATK_UP_1,
    },

    [MOVE_PLASMA_GALE] =
    {
        .effect = EFFECT_HIT_SET_REMOVE_TERRAIN,
        .power = 110,
        .type = TYPE_ELECTRIC,
        .accuracy = 85,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .split = SPLIT_SPECIAL,
        .zMovePower = 180,
        .zMoveEffect = Z_EFFECT_NONE,
        .argument = EFFECT_ELECTRIC_TERRAIN,
    },

    [MOVE_CHAOS_GLOWER] =
    {
        .effect = EFFECT_CHAOS_GLOWER,
        .power = 40,
        .type = TYPE_DARK,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 100,
        .target = MOVE_TARGET_SELECTED,
        .priority = 3,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .split = SPLIT_SPECIAL,
        .zMovePower = 100,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_STARLIGHT_RECITAL] =
    {
        .effect = EFFECT_JUNGLE_HEALING,
        .power = 0,
        .type = TYPE_FAIRY,
        .accuracy = 0,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .flags = FLAG_SNATCH_AFFECTED | FLAG_SOUND_BASED_MOVE,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_FLORAL_FLOURISH] =
    {
        .power = 120,
        .pp = 10,
        .zMovePower = 190,
        .effect = EFFECT_USER_RAMPAGE,
        .type = TYPE_GRASS,
        .accuracy = 100,
        .secondaryEffectChance = 100,
        .target = MOVE_TARGET_RANDOM,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
        .zMoveEffect = Z_EFFECT_NONE,
        .argument = 1,
    },

    [MOVE_LEGEND_POWER] =
    {
        .power = 60,
        .effect = EFFECT_LEGEND_POWER,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .split = SPLIT_SPECIAL,
        .zMovePower = 120,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_DRAGON_CURRENT] =
    {
        .effect = EFFECT_SEMI_INVULNERABLE,
        .power = 120,
        .type = TYPE_WATER,
        .accuracy = 85,
        .pp = 5,
        .secondaryEffectChance = 100,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
        .argument2 = MOVE_EFFECT_WRAP,
        .zMovePower = 190,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_PSYSHIELD] =
    {
        .effect = EFFECT_PSYSHIELD,
        .power = 0,
        .type = TYPE_PSYCHIC,
        .accuracy = 0,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .flags = FLAG_SNATCH_AFFECTED,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_RESET_STATS,
    },
};
