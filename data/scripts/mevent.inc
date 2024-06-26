EventScript_Questionnaire::
	lockall
	msgbox Mevent_Text_FillOutQuestionnaire, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq Mevent_EventScript_Release
	setvar VAR_0x8004, EASY_CHAT_TYPE_QUESTIONNAIRE
	call Common_ShowEasyChatScreen
	lock
	faceplayer
	specialvar VAR_0x8008, GetMartEmployeeObjectEventId
	compare VAR_0x8004, 1
	goto_if_eq Mevent_EventScript_PlayerInputMysteryEventPhrase
	compare VAR_0x8004, 2
	goto_if_eq Mevent_EventScript_PlayerInputMysteryGiftPhrase
	compare VAR_RESULT, 0
	goto_if_eq Mevent_EventScript_Release
	compare VAR_RESULT, 1
	goto_if_eq Mevent_EventScript_QuestionnaireThankYou
	end

Mevent_EventScript_PlayerInputMysteryEventPhrase::
	goto_if_unset FLAG_SYS_POKEDEX_GET, Mevent_EventScript_QuestionnaireThankYou
	@goto_if_set FLAG_SYS_MYSTERY_EVENT_ENABLE, Mevent_EventScript_QuestionnaireThankYou
	goto_if_set FLAG_PHIONE_EGG_MYSTERY_GIFT, Mevent_EventScript_QuestionnaireThankYou
	applymovement VAR_0x8008, Common_Movement_FaceDown
	waitmovement 0
	playse SE_PIN
	applymovement VAR_0x8008, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement VAR_0x8008, Common_Movement_Delay48
	waitmovement 0
	msgbox Mevent_Text_YouKnowThoseWordsEvent, MSGBOX_DEFAULT
	@setflag FLAG_SYS_MYSTERY_EVENT_ENABLE
	setflag FLAG_PHIONE_EGG_MYSTERY_GIFT
	msgbox Mevent_Text_YouCanAccessMysteryEvent, MSGBOX_DEFAULT
	giveegg SPECIES_PHIONE
	releaseall
	end

Mevent_EventScript_PlayerInputMysteryGiftPhrase::
	goto_if_unset FLAG_SYS_POKEDEX_GET, Mevent_EventScript_QuestionnaireThankYou
	goto_if_set FLAG_SYS_MYSTERY_GIFT_ENABLE, Mevent_EventScript_QuestionnaireThankYou
	applymovement VAR_0x8008, Common_Movement_FaceDown
	waitmovement 0
	playse SE_PIN
	applymovement VAR_0x8008, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement VAR_0x8008, Common_Movement_Delay48
	waitmovement 0
	msgbox Mevent_Text_YouKnowThoseWordsGift, MSGBOX_DEFAULT
	setflag FLAG_SYS_MYSTERY_GIFT_ENABLE
	msgbox Mevent_Text_YouCanAccessMysteryGift, MSGBOX_DEFAULT
	releaseall
	end

Mevent_EventScript_Release::
	releaseall
	end

Mevent_EventScript_QuestionnaireThankYou::
	applymovement VAR_0x8008, Common_Movement_FaceDown
	waitmovement 0
	msgbox Mevent_Text_QuestionnaireThankYou, MSGBOX_DEFAULT
	releaseall
	end
