PUBLIC ?addToNumber@Test@@QEAAXH@Z
PUBLIC ?setEnumVal@Test@@QEAAXW4TestEnum@@@Z

.data 

.code

; public void Test::addToNumber(int)
?addToNumber@Test@@QEAAXH@Z PROC
; prologue
	push rbp
	push rbx
	sub rsp, 20h
	lea rbp, [rsp + 20h]
; end prologue
	
; add rdc (first paramter)
	mov rax, [rcx]
	add rax, rdx
	mov [rcx], rax

; epilogue
	lea rsp, [rbp]
	pop rbx
	pop rbp
	ret
; end epilogue
?addToNumber@Test@@QEAAXH@Z ENDP

; public void Test::setEnumVal(TestEnum)
?setEnumVal@Test@@QEAAXW4TestEnum@@@Z PROC
; prologue
	push rbp
	push rbx
	sub rsp, 20h
	lea rbp, [rsp + 20h]
; end prologue

	mov [rcx + 04h], rdx

; epilogue
	lea rsp, [rbp]
	pop rbx
	pop rbp
	ret
; end epilogue
?setEnumVal@Test@@QEAAXW4TestEnum@@@Z ENDP

END