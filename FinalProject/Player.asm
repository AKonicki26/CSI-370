printYourHandText PROTO
printDealerHandText PROTO
printInputPrompt PROTO
getInput PROTO
printCard PROTO
printHandValue PROTO

?getCardValue@@YAHUCard@@@Z PROTO

PUBLIC ?takeTurn@Player@@QEAAHXZ
PUBLIC ?dealerTurn@Player@@QEAAHXZ
PUBLIC ?getHandValue@Player@@QEAAHXZ
PUBLIC ?displayHand@Player@@QEAAXXZ

sPlayerCard STRUCT
	value BYTE 0
	suit WORD ?
sPlayerCard ENDS

.data 

thisPointer QWORD ?
loopCounter QWORD ?
handValue QWORD ?

playerCard sPlayerCard < ?, ? >

MAX_HAND_SIZE EQU 9
CARD_DATA_SIZE EQU 4

.code

; int takeTurn()
; return 0 if pass, non-0 if draw card
?takeTurn@Player@@QEAAHXZ PROC
	push rbp
	push rbx
	sub rsp, 20h
	lea rbp, [rsp + 20h]

	mov thisPointer, rcx

	call printYourHandText
	mov rcx, thisPointer
	call ?displayHand@Player@@QEAAXXZ

	mov rcx, thisPointer
	call ?getHandValue@Player@@QEAAHXZ
	cmp rax, 21
	jge playerDoesntPlay

	; get player input on playing. 

	call printInputPrompt
	call getInput
	cmp rax, 1 ; compare input to 1 (play)
	jne playerDoesntPlay
	
	mov rax, 1
	jmp endPlayerTurn


playerDoesntPlay:
	mov rax, 0
	jmp endPlayerTurn

endPlayerTurn:

	lea rsp, [rbp]
	pop rbx
	pop rbp
	ret
?takeTurn@Player@@QEAAHXZ ENDP

; int dealerTurn()
; return 0 if pass, non-0 if draw card
?dealerTurn@Player@@QEAAHXZ PROC
	push rbp
	push rbx
	sub rsp, 20h
	lea rbp, [rsp + 20h]

	mov thisPointer, rcx
	mov byte ptr [playerCard], cl

	call printDealerHandText
	mov rcx, thisPointer
	call ?displayHand@Player@@QEAAXXZ

	mov rcx, thisPointer
	call ?getHandValue@Player@@QEAAHXZ
	cmp rax, 16
	jge dealerPassTurn

	mov rax, 1
	jmp endDealerTurn

dealerPassTurn:
	mov rax, 0
	jmp endDealerTurn

endDealerTurn:

	lea rsp, [rbp]
	pop rbx
	pop rbp
	ret
?dealerTurn@Player@@QEAAHXZ ENDP

; int getHandValue() 
; return sum of the value of all cards in the players hand
?getHandValue@Player@@QEAAHXZ PROC
	push rbp
	push rbx
	sub rsp, 20h
	lea rbp, [rsp + 20h]

	mov thisPointer, rcx

	; store address of player object, which also serves as start of cards array
	mov rbx, rcx
	xor rdi, rdi ; loop counter

	mov handValue, 0

	; sum values of cards
	mov rcx, MAX_HAND_SIZE
sumLoopStart:
test rcx, rcx
	jz sumLoopEnd
	; push rcx into variable to store for later
	mov loopCounter, rcx

	; get card value, add to sum
	mov rcx, [rbx + rdi]
	call ?getCardValue@@YAHUCard@@@Z
	add handValue, rax

	add rdi, CARD_DATA_SIZE

	; mov rcx back to do loop counting
	mov rcx, loopCounter
	loop sumLoopStart


sumLoopEnd:

	mov rax, handValue
	
	lea rsp, [rbp]
	pop rbx
	pop rbp
	ret
?getHandValue@Player@@QEAAHXZ ENDP

; void displayHand()
; display the players hand to console (calls extern methods since the console calls are complex)
?displayHand@Player@@QEAAXXZ PROC
	push rbp
	push rbx
	sub rsp, 20h
	lea rbp, [rsp + 20h]

	mov thisPointer, rcx

	; store address of player object, which also serves as start of cards array
	mov rbx, rcx
	xor rdi, rdi ; loop counter

	mov rcx, MAX_HAND_SIZE
printLoopStart:
	test rcx, rcx
	jz endPrintLoop
	; push rcx onto stack to store for later
	mov loopCounter, rcx

	mov rbx, thisPointer
	mov rcx, [rbx + rdi]
	call printCard

	add rdi, CARD_DATA_SIZE
	; pop rcx back to do loop counting
	mov rcx, loopCounter
	loop printLoopStart

endPrintLoop:

	mov rcx, thisPointer
	call ?getHandValue@Player@@QEAAHXZ
	mov rcx, rax
	call printHandValue

	lea rsp, [rbp]
	pop rbx
	pop rbp
	ret
?displayHand@Player@@QEAAXXZ ENDP

END