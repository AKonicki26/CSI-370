getNumber PROTO
printNumber PROTO

.data

.code

asmMain PROC
push rbp
push rbx
sub rsp, 20h
lea rbp, [rsp + 20h]

; Call the getNumber function twice to get two numbers
; Numbers will be stored in eax
call getNumber
mov ebx, eax

call getNumber
mov ecx, eax ; moving into ecx because first parameter register to use later

; Add numbers together and print the result
add ecx, ebx
call printNumber


lea rsp, [rbp]
pop rbx
pop rbp
ret
asmMain ENDP
END