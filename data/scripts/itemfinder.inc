EventScript_ItemfinderDigUpUnderfootItem::
	lockall
	waitse
	call EventScript_PickUpHiddenItem
	compare VAR_0x8007, 1
	goto_if_eq EventScript_DigUpItemPutInPocket
	compare VAR_0x8007, 0
	goto_if_eq EventScript_DigUpItemBagIsFull
	end

EventScript_DigUpItemPutInPocket::
	message Text_DugUpItemFromGround
	waitfanfare
	waitmessage
	delay 60
	msgbox Text_PutItemAway
	special SetHiddenItemFlag
	releaseall
	end

EventScript_DigUpItemBagIsFull::
	msgbox Text_DugUpItemFromGround
	msgbox gText_TooBadBagIsFull
	setvar VAR_RESULT, 0
	releaseall
	end

Text_DugUpItemFromGround::
	.string "{PLAYER} dug up one {STR_VAR_2}\n"
	.string "from deep in the ground.$"

Text_PutItemAway::
	.string "{PLAYER} put the {STR_VAR_2}\n"
	.string "in the {STR_VAR_3}.$"
