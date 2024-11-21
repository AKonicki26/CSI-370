; Assignment 8.4 Normalizing Vectors
; Write assembly program that defines a 2d vector
; and a 3d vector, then normalizes both vectors


; vector 3d container
vector3d STRUCT
	x REAL8 ?
	y REAL8 ?
	z REAL8 ?
vector3d ENDS

; vector 2d container
vector2d STRUCT
	x REAL8 ?
	y REAL8 ?
vector2d ENDS

.data ; start data section
vector1 vector3d <2.757, 5.567, 7.546>
vector2 vector2d <7.353, 10.3467>

normalizedVector1 vector3d <?, ?, ?>
normalizedVector2 vector2d <?, ?>

.code ; start code section

extern ExitProcess : proc ; declare exit process

_main PROC ; start of main method
sub rsp, 28h ; Windows 11 is weird

; normalize vector1 (vector3d)
lea rax, vector1

vmovups ymm0, YMMWORD PTR [rax]

vmulps ymm1, ymm0, ymm0 ; square all values
vhaddps ymm2, ymm1, ymm1 ; add squared values together
vsqrtps ymm3, ymm2 ; take the square root of sum
vdivps ymm4, ymm0, ymm3 ; divide values by square root

lea rax, normalizedVector1
vmovups YMMWORD PTR [rax], ymm4 ; store result


; normalize vector2 (vector2d)
lea rax, vector2
vmovups ymm0, YMMWORD PTR [rax]

vmulps ymm1, ymm0, ymm0 ; square all values
vhaddps ymm2, ymm1, ymm1 ; add squared values together
vsqrtps ymm3, ymm2 ; take the square root of sum
vdivps ymm4, ymm0, ymm3 ; divide values by square root

lea rax, normalizedVector2
vmovups YMMWORD PTR [rax], ymm4 ; store result

xor rcx, rcx ; clear rcx register
call ExitProcess ; call ExitProcess
_main ENDP ; Endpoint of main function

END ; endpoint of assembly code