PUBLIC ?getCardValue@@YAHUCard@@@Z
PUBLIC  ?getCardValueString@@YADUCard@@@Z

sCard STRUCT
	value BYTE 0
	suit WORD ?
sCard ENDS

.data

card sCard < ?, ? >

.code

; int getCardValue(Card card)
?getCardValue@@YAHUCard@@@Z PROC
	push rbp
	push rbx
	sub rsp, 20h
	lea rbp, [rsp + 20h]
	
	; Move rcx into the card structure
    mov byte ptr [card], cl       ; Store the lowest byte (value) into card.value

	cmp card.value, 10
	mov rax, 10
	movzx rax, BYTE PTR [card]

	lea rsp, [rbp]
	pop rbx
	pop rbp
	ret
?getCardValue@@YAHUCard@@@Z ENDP

; char getCardValueString(Card card)
 ?getCardValueString@@YADUCard@@@Z PROC
	push rbp
	push rbx
	sub rsp, 20h
	lea rbp, [rsp + 20h]

	; Move rcx into the card structure
    mov byte ptr [card], cl       ; Store the lowest byte (value) into card.value

	; Compare card.value to get the proper 
	cmp card.value, 13
	je returnKingCharacter
	cmp card.value, 12
	je returnQueenCharacter
	cmp card.value, 11
	je returnJackCharacter
	cmp card.value, 10
	je returnTenCharacter
	
	; defauly number, convert to ascii
	movzx rbx, BYTE PTR [card]
	add rbx, 30h
	mov rax, rbx
	jmp endCardCharacter


returnTenCharacter:
	mov rax, 41h
	jmp endCardCharacter

returnJackCharacter:
	mov rax, 4Ah
	jmp endCardCharacter

returnQueenCharacter:
	mov rax, 51h
	jmp endCardCharacter

returnKingCharacter:
	mov rax, 4Bh
	jmp endCardCharacter

endCardCharacter:
	lea rsp, [rbp]
	pop rbx
	pop rbp
	ret
 ?getCardValueString@@YADUCard@@@Z ENDP

END