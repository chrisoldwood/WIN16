	PUBLIC	CLEARMONO
CLEARMONO	PROC FAR
; Line 78
	mov	ax,DGROUP
	enter	4,0
	push	si
	push	ds
	mov	ds,ax
;	lpDisplay = -4
;	register cx = iLoop
; Line 82
	mov	ax,WORD PTR _lpMonoMem
	mov	dx,WORD PTR _lpMonoMem+2
	mov	bx,ax
	mov	WORD PTR [bp-2],dx
; Line 83
	mov	cx,2000	;07d0H
; Line 85
	jmp	SHORT $L1418
$FC1335:
; Line 86
	mov	es,WORD PTR [bp-2]
	mov	si,bx
	add	bx,2
	mov	WORD PTR es:[si],0
$L1418:
	mov	ax,cx
	dec	cx
	or	ax,ax
	jne	$FC1335
; Line 87
	pop	ds
	pop	si
	leave	
	ret	
CLEARMONO	ENDP

	PUBLIC	PLOTCHAR
PLOTCHAR	PROC FAR
; Line 94
	mov	ax,DGROUP
	push	bp
	mov	bp,sp
	push	si
	push	ds
	mov	ds,ax
;	cStyle = 6
;	lpDisplay = -4
;	iX = 12
;	iY = 10
;	cChar = 8
; Line 98
	imul	bx,WORD PTR [bp+10],80	;0050H	;iY
	add	bx,WORD PTR [bp+12]	;iX
	shl	bx,1
	les	si,DWORD PTR _lpMonoMem
	mov	al,BYTE PTR [bp+8]	;cChar
	cbw	
	mov	ch,BYTE PTR [bp+6]	;cStyle
	sub	cl,cl
	add	cx,ax
	mov	WORD PTR es:[bx][si],cx
; Line 99
	pop	ds
	pop	si
	leave	
	ret	8
	nop	
PLOTCHAR	ENDP

	PUBLIC	HORIZLINE
HORIZLINE	PROC FAR
; Line 106
	mov	ax,DGROUP
	enter	8,0
	push	di
	push	si
	push	ds
	mov	ds,ax
;	iSX = 14
;	iDX = 12
;	iY = 10
;	cChar = 8
;	cStyle = 6
;	lpDisplay = -6
;	iLoop = -2
	mov	di,WORD PTR [bp+14]	;iSX
; Line 110
	imul	ax,WORD PTR [bp+10],80	;0050H	;iY
	add	ax,di
	shl	ax,1
	add	ax,WORD PTR _lpMonoMem
	mov	dx,WORD PTR _lpMonoMem+2
	mov	si,ax
	mov	WORD PTR [bp-4],dx
; Line 111
	sub	di,WORD PTR [bp+12]	;iDX
	neg	di
	inc	di
	mov	al,BYTE PTR [bp+8]	;cChar
	cbw	
	mov	ch,BYTE PTR [bp+6]	;cStyle
	sub	cl,cl
	add	cx,ax
	mov	WORD PTR [bp-8],cx
	mov	cx,di
; Line 113
	jmp	SHORT $L1419
$FC1361:
; Line 114
	mov	ax,WORD PTR [bp-8]
	mov	es,WORD PTR [bp-4]
	mov	bx,si
	add	si,2
	mov	WORD PTR es:[bx],ax
$L1419:
	mov	ax,cx
	dec	cx
	or	ax,ax
	jne	$FC1361
; Line 115
	pop	ds
	pop	si
	pop	di
	leave	
	ret	10	;000aH
HORIZLINE	ENDP

	PUBLIC	VERTLINE
VERTLINE	PROC FAR
; Line 122
	mov	ax,DGROUP
	enter	8,0
	push	di
	push	si
	push	ds
	mov	ds,ax
;	iX = 14
;	iSY = 12
;	iDY = 10
;	cChar = 8
;	cStyle = 6
;	lpDisplay = -6
;	iLoop = -2
	mov	di,WORD PTR [bp+12]	;iSY
; Line 126
	imul	ax,di,80	;0050H
	add	ax,WORD PTR [bp+14]	;iX
	shl	ax,1
	add	ax,WORD PTR _lpMonoMem
	mov	dx,WORD PTR _lpMonoMem+2
	mov	si,ax
	mov	WORD PTR [bp-4],dx
; Line 127
	sub	di,WORD PTR [bp+10]	;iDY
	neg	di
	inc	di
	mov	al,BYTE PTR [bp+8]	;cChar
	cbw	
	mov	ch,BYTE PTR [bp+6]	;cStyle
	sub	cl,cl
	add	cx,ax
	mov	WORD PTR [bp-8],cx
	mov	cx,di
; Line 129
	jmp	SHORT $L1420
$FC1377:
; Line 131
	mov	ax,WORD PTR [bp-8]
	mov	es,WORD PTR [bp-4]
	mov	bx,si
	add	si,160	;00a0H
	mov	WORD PTR es:[bx],ax
; Line 133
$L1420:
	mov	ax,cx
	dec	cx
	or	ax,ax
	jne	$FC1377
; Line 134
	pop	ds
	pop	si
	pop	di
	leave	
	ret	10	;000aH
	nop	
VERTLINE	ENDP

	PUBLIC	PLOTSTRING
PLOTSTRING	PROC FAR
; Line 141
	mov	ax,DGROUP
	enter	4,0
	push	di
	push	si
	push	ds
	mov	ds,ax
;	iX = 14
;	iY = 12
;	lpString = 8
;	cStyle = 6
;	lpDisplay = -4
	mov	di,WORD PTR [bp+8]	;lpString
; Line 144
	imul	ax,WORD PTR [bp+12],80	;0050H	;iY
	add	ax,WORD PTR [bp+14]	;iX
	shl	ax,1
	add	ax,WORD PTR _lpMonoMem
	mov	dx,WORD PTR _lpMonoMem+2
	mov	si,ax
	mov	WORD PTR [bp-2],dx
; Line 145
	mov	es,WORD PTR [bp+10]
	cmp	BYTE PTR es:[di],0
	je	$EX1387
$FC1390:
; Line 147
	mov	al,BYTE PTR es:[di]
	mov	es,dx
	mov	BYTE PTR es:[si],al
; Line 148
	mov	al,BYTE PTR [bp+6]	;cStyle
	mov	es,WORD PTR [bp-2]
	inc	si
	mov	BYTE PTR es:[si],al
	mov	ax,si
	mov	dx,es
	inc	ax
	mov	si,ax
	mov	WORD PTR [bp-2],dx
; Line 149
	mov	es,WORD PTR [bp+10]
	inc	di
	cmp	BYTE PTR es:[di],0
	jne	$FC1390
; Line 150
$EX1387:
	pop	ds
	pop	si
	pop	di
	leave	
	ret	10	;000aH
	nop	
PLOTSTRING	ENDP

