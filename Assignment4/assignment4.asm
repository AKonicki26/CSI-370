; Assignment 4.2
; Compute final percentage based on the following scores
; Result is stored as a whole number
; 25 / 30
; 89 / 100
; 49 / 50
; 80 / 150

.data ; start data section
score1 DWORD ? ; Create 4 score variables to store results 
score2 DWORD ? ; (Not needed, just to see results stored in memory instead of registers)
score3 DWORD ?
score4 DWORD ?


.code ; start code section

extern ExitProcess : proc ; declare exit process

_main PROC ; start of main method
sub rsp, 28h ; Windows 11 is weird

mov edx, 0 ; clear dx register 
mov eax, 2500 ; move 25 into ax register (always the dividend)
mov ecx, 30 ; move 30 into cx register 
div ecx ; divide ax register by cx register (25 / 30)

; Moving result into these registers is not needed, mainly used
; to see the value of the al register after each calulation
mov score1, eax ; move result of division into score1 variable

mov edx, 0 ; clear dx register 
mov eax, 8900 ; move 89 into ax register (always the dividend)
mov ecx, 100 ; move 100 into bx register 
div ecx ; divide ax register by bx register (89 / 100)

mov score2, eax ; move result of division into score1 variable

mov edx, 0 ; clear dx register 
mov eax, 4900 ; move 49 into ax register (always the dividend)
mov ecx, 50 ; move 30 into cx register 
div ecx ; divide ax by cx (49 / 50)

mov score3, eax ; move result of division into score1 variable

mov edx, 0 ; clear dx register 
mov eax, 8000 ; move 80 into ax register (always the dividend)
mov ecx, 150 ; mov 150 into cx register
div ecx ; divide ax by bx (80 / 150)

mov score4, eax ; move result of division into score1 variable

xor rcx, rcx ; clear rcx register
call ExitProcess ; call ExitProcess
_main ENDP ; Endpoint of main function

END ; endpoint of assembly code