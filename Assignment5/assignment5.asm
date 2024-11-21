; Assignment 5.1
; Use loops to calculate number in the fibonacchi sequence
; Between 0 - 1,000,000
; Fibonaccchi sequence:
; Fib(n) = Fib(n-1) + Fib(n-2)


.data ; start data section

.code ; start code section

extern ExitProcess : proc ; declare exit process

_main PROC ; start of main method
sub rsp, 28h ; Windows 11 is weird

; initial values needed to start doing the fibonacchi sequencee
mov rax, 1 ; rax used to store current value Fib(n)
mov rbx, 1 ; rbx to store Fib(n-1)
mov rcx, 0 ; rcx to store Fib(n-2)

fibonacchi: ; label for the fibonacchi sequence to jump back to
cmp rax, 1000000 ; compare rax to 1,000,000
ja post_fibonacchi ; if rax > 1,000,000, jump to post_fibonacchi

; Fibbonachi sequencee:
; trying to find fib(n)
; rax currently stores fib(n-1)
; rbx currently stores fib(n-2)
; rcx currently stores fib(n-3)

mov rcx, rbx ; mov n-1 into n-2
mov rbx, rax ; mov n into n-1

; Now just need to sum rbx and rcx, then store in rax
mov rax, rcx ; moving rcx (n-2) into rax
add rax, rbx ; add rbx (n-1) with rax (currently storing rcx (n-2))
jmp fibonacchi ; fib(n) has been calculated, jump back to start of loop

post_fibonacchi: ; label for after fibonacchi

xor rcx, rcx ; clear rcx register
call ExitProcess ; call ExitProcess
_main ENDP ; Endpoint of main function

END ; endpoint of assembly code