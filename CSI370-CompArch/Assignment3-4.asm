; Assignment 3.4 - Challenge Assignment
; Compute (A + B) - (C + D) 
; Store the result
; Create a string to accompany the result

extern ExitProcess : proc

.DATA ; Start data section
sum1 QWORD ? ; Allocate memory to store (A + B), dont init value
sum2 QWORD ? ; Allocate memory to store (C + D), dont init value
result QWORD ? ; Allocate memory to store final result
resultString BYTE "The result of your operation is: ",0 ; Prepare string for displaying result
resultStringLen EQU $ - resultString ; Get the length of this string as a constant


.CODE ; Start code section

_main PROC ; Entry-point
sub rsp, 28h

; Variable initialization
mov rax, 10 ; Store 10 to the rax register
mov rbx, 25 ; Store 25 to the rbx register
mov rcx, 7 ; Store 7 to the rcx register
mov rdx, 8 ; Store 8 to the rdx register

; (A + B) / (10 + 25)
add rax, rbx ; Add value of B to rax register, rax now holds 35
mov sum1, rax ; Store (A + B) in sum1, sum1 now holds 35

; (C + D) / (7 + 8)
add rcx, rdx ; Add D to rax register, rax now holds 15
mov sum2, rcx ; Move rax to sum2, sum2 now holds 15

; (A + B) - (C + D) / (10 + 25) - (7 + 8)
mov rax, sum1 ; Move sum1 to rax register, rax now holds 35
sub rax, sum2 ; Subtract sum2 from rax, rax now holds 20
mov result, rax	; Move rax into result, result now holds 20

mov rax, resultStringLen ; move the Result Strings Length into RAX. 
						; Ensures the length is correct and also to see
						; The constant functioning properly in the disassembler

xor rcx, rcx ; Clear the rcx register by xoring it against itself
call ExitProcess ; call ExitProcess, fairly self explanitory
_main ENDP ; endpoint of main function

END