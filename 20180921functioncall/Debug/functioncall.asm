; Listing generated by Microsoft (R) Optimizing Compiler Version 19.14.26430.0 

	TITLE	G:\Users\Administrator\Desktop\sys_programming\2015440159������\20180921functioncall\functioncall.cpp
	.686P
	.XMM
	include listing.inc
	.model	flat

INCLUDELIB MSVCRTD
INCLUDELIB OLDNAMES

PUBLIC	?sum@@YAHHH@Z					; sum
PUBLIC	?wsum@@YGHHH@Z					; wsum
PUBLIC	_main
EXTRN	__RTC_CheckEsp:PROC
EXTRN	__RTC_InitBase:PROC
EXTRN	__RTC_Shutdown:PROC
;	COMDAT rtc$TMZ
rtc$TMZ	SEGMENT
__RTC_Shutdown.rtc$TMZ DD FLAT:__RTC_Shutdown
rtc$TMZ	ENDS
;	COMDAT rtc$IMZ
rtc$IMZ	SEGMENT
__RTC_InitBase.rtc$IMZ DD FLAT:__RTC_InitBase
rtc$IMZ	ENDS
; Function compile flags: /Odtp /RTCsu /ZI
; File g:\users\administrator\desktop\sys_programming\2015440159������\20180921functioncall\functioncall.cpp
;	COMDAT _main
_TEXT	SEGMENT
_c$ = -32						; size = 4
_b$ = -20						; size = 4
_a$ = -8						; size = 4
_main	PROC						; COMDAT

; 6    : int main(void) {

	push	ebp
	mov	ebp, esp
	sub	esp, 228				; 000000e4H
	push	ebx
	push	esi
	push	edi
	lea	edi, DWORD PTR [ebp-228]
	mov	ecx, 57					; 00000039H
	mov	eax, -858993460				; ccccccccH
	rep stosd

; 7    : 
; 8    : 	int a, b, c;
; 9    : 	a = 10;

	mov	DWORD PTR _a$[ebp], 10			; 0000000aH

; 10   : 	b = 20;

	mov	DWORD PTR _b$[ebp], 20			; 00000014H

; 11   : 	c = a + b;

	mov	eax, DWORD PTR _a$[ebp]
	add	eax, DWORD PTR _b$[ebp]
	mov	DWORD PTR _c$[ebp], eax

; 12   : 	c = sum(a, b);

	mov	eax, DWORD PTR _b$[ebp]
	push	eax
	mov	ecx, DWORD PTR _a$[ebp]
	push	ecx
	call	?sum@@YAHHH@Z				; sum
	add	esp, 8
	mov	DWORD PTR _c$[ebp], eax

; 13   : 	c = wsum(a, b);

	mov	eax, DWORD PTR _b$[ebp]
	push	eax
	mov	ecx, DWORD PTR _a$[ebp]
	push	ecx
	call	?wsum@@YGHHH@Z				; wsum
	mov	DWORD PTR _c$[ebp], eax

; 14   : 
; 15   : 	return 0;

	xor	eax, eax

; 16   : }

	pop	edi
	pop	esi
	pop	ebx
	add	esp, 228				; 000000e4H
	cmp	ebp, esp
	call	__RTC_CheckEsp
	mov	esp, ebp
	pop	ebp
	ret	0
_main	ENDP
_TEXT	ENDS
; Function compile flags: /Odtp /RTCsu /ZI
; File g:\users\administrator\desktop\sys_programming\2015440159������\20180921functioncall\functioncall.cpp
;	COMDAT ?wsum@@YGHHH@Z
_TEXT	SEGMENT
_z$ = -8						; size = 4
_x$ = 8							; size = 4
_y$ = 12						; size = 4
?wsum@@YGHHH@Z PROC					; wsum, COMDAT

; 24   : int WINAPI wsum(int x, int y) {

	push	ebp
	mov	ebp, esp
	sub	esp, 204				; 000000ccH
	push	ebx
	push	esi
	push	edi
	lea	edi, DWORD PTR [ebp-204]
	mov	ecx, 51					; 00000033H
	mov	eax, -858993460				; ccccccccH
	rep stosd

; 25   : 	int z;
; 26   : 	z = x + y;

	mov	eax, DWORD PTR _x$[ebp]
	add	eax, DWORD PTR _y$[ebp]
	mov	DWORD PTR _z$[ebp], eax

; 27   : 	return z;

	mov	eax, DWORD PTR _z$[ebp]

; 28   : }

	pop	edi
	pop	esi
	pop	ebx
	mov	esp, ebp
	pop	ebp
	ret	8
?wsum@@YGHHH@Z ENDP					; wsum
_TEXT	ENDS
; Function compile flags: /Odtp /RTCsu /ZI
; File g:\users\administrator\desktop\sys_programming\2015440159������\20180921functioncall\functioncall.cpp
;	COMDAT ?sum@@YAHHH@Z
_TEXT	SEGMENT
_z$ = -8						; size = 4
_x$ = 8							; size = 4
_y$ = 12						; size = 4
?sum@@YAHHH@Z PROC					; sum, COMDAT

; 18   : int sum(int x, int y) {

	push	ebp
	mov	ebp, esp
	sub	esp, 204				; 000000ccH
	push	ebx
	push	esi
	push	edi
	lea	edi, DWORD PTR [ebp-204]
	mov	ecx, 51					; 00000033H
	mov	eax, -858993460				; ccccccccH
	rep stosd

; 19   : 	int z;
; 20   : 	z = x + y;

	mov	eax, DWORD PTR _x$[ebp]
	add	eax, DWORD PTR _y$[ebp]
	mov	DWORD PTR _z$[ebp], eax

; 21   : 	return z;

	mov	eax, DWORD PTR _z$[ebp]

; 22   : }

	pop	edi
	pop	esi
	pop	ebx
	mov	esp, ebp
	pop	ebp
	ret	0
?sum@@YAHHH@Z ENDP					; sum
_TEXT	ENDS
END
