@EventScript_UseFlash::
@	animateflash 1
@	setflashradius 1
@	end

EventScript_UseFlash::
	lockall
	bufferpartymonnick 0, VAR_0x8004
	buffermovename 1, MOVE_FLASH
	setflag FLAG_SYS_USE_FLASH
	msgbox Text_MonUsedFieldMove, MSGBOX_DEFAULT
	closemessage
	animateflash 0
	setflashradius 0
	releaseall
	end
