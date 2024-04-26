EventScript_UseSurf::
    bufferpartymonnick 0, VAR_0x8004
	buffermovename 1, MOVE_SURF	
	compare VAR_0x8004, PARTY_SIZE
	goto_if_eq EventScript_EndUseSurf	
	setfieldeffectarg 0, VAR_0x8004
	lockall
	msgbox gText_WantToUseSurf, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq EventScript_ReleaseUseSurf
	msgbox gText_PlayerUsedSurf, MSGBOX_DEFAULT
	special IsFollowerOnVar8004 @ skip pose if so
	dofieldeffect FLDEFF_USE_SURF
EventScript_ReleaseUseSurf::
	releaseall
EventScript_EndUseSurf::
	end

