; Syntax Translation - masm
.DATA

DWORD letter, 1
DWORD r ?
DWORD s ?
DWORD t ?
DWORD x ?
DWORD y ?
DWORD z ?

.CODE

extern ExitProcess : proc

_main PROC

;movb $0x77, letter
;movl $0x5, r
;movl $0x2, s
;movw $0xa, x
;movw $0x4, y
mov letter, 077h
mov r, 05h
mov s, 02h
mov x, 0ah
mov y, 04h

;movw x, %ax
;addw y, %ax
;movw %ax, z
mov ax, x
add ax, y
mov z, ax

;movw x, %ax
;subw y, %ax
;movw %ax, z
mov ax, x
sub ax, y
mov z, ax

;movl $0x0, %edx
;movl r, %eax
;movl s, %ecx
;divl %ecx
;movl %eax, t
mov edx, 0h
mov eax, r
mov ecx, s
div ecx
mov t, eax

;movl $0x0, %edx
;movl r, %eax
;movl s, %ecx
;divl %ecx
;movl %edx, t
mov edx, 0h
mov eax, r
mov ecx, s
div ecx
mov t, edx

;pushl $0
;subl $4, %esp
;movl $1, %eax
;int $0x80
;.end
push 0
sub esp, 4
mov eax, 1
xor rcx, rcx
call ExitProcess
_main ENDP

END