; Assignment 7-1
; Compare two strings
; Determind if strings are exactly the same, same to an index
; or completely different (start with different character)

; Must handly all 3 scenarios

.data
string1 BYTE "Try harder"
string1Len EQU $-string1
string2 BYTE "Try harder still"
string2Len EQU $-string2
string3 BYTE "Stop trying harder now please"
string3Len EQU $-string3
string4 BYTE "Try harder"
string4Len EQU $-string4

.code

extern ExitProcess : proc

_main PROC
sub rsp, 28h ; Windows 11 is weird

; load the two strings to compare into rsi and rdi registers
lea rsi, string1
lea rdi, string3 ; string to compare against. only change this
mov rcx, string1Len

cld
repe cmpsb

; if the two strings are equal
je stringsEqual ; if ZF is 1, strings were equal

; if rcx == length of string, then the strings differed at the first character
cmp rcx, (string1Len - 1) 
je completelyDifferent

; other two conditions were not true, therefore it must have differed somewhere in the middle
jmp differInMiddle


;if the two strings start differently


;if the two stings are partially different


stringsEqual:
mov rax, 1
jmp endCode

completelyDifferent:
mov rax, 2
jmp endCode

differInMiddle:
mov rax, 3
jmp endCode


endCode:

xor rcx, rcx 
call ExitProcess 
_main ENDP 

END

