
extern ExitProcess : proc
extern CreateFileA : proc
extern ReadFile : proc
extern WriteFile : proc
extern GetStdHandle : proc

.data
FD QWORD ?
read QWORD ?
charsRead QWORD 0
charsWritten QWORD ?

inputFile BYTE "input.txt",0
outputFile BYTE "output.txt",0
fileSize QWORD 4096
buffer WORD 4096 DUP (0)

writeOutputCode QWORD ?

successOutput BYTE "Writing to file ended successfully"
successOutputLen EQU $ - successOutput

failedOutput BYTE "Writing to file failed :(", 0
failedOutputLen EQU $ - failedOutput

.code

_main PROC

	sub rsp, 10h ; rbp + return
	sub rsp, 18h ; parameters
	sub rsp, 20h ; shadow space

	; Opening input file

	lea rcx, inputFile ; address of the file name
	mov rdx, 80000000h ; file is read only, so use constant for GENERIC_READ
	xor r8, r8 ; share mode 0
	xor r9, r9 ; security attributes

	mov QWORD PTR [rsp + 48h - 28h], 3 ; open existing
	mov QWORD PTR [rsp + 48h - 20h], 80h ; normal file attrubute
	mov QWORD PTR [rsp + 48h - 18h], 0 ; template file (none)
	call CreateFileA
	mov FD, rax

	; Reading input file

	mov rcx, FD
	lea rdx, buffer
	mov r8, fileSize
	lea r9, charsRead
	mov QWORD PTR [rsp + 48h - 28h], 0
	call ReadFile
	mov read, rax

	; Opening output file

	lea rcx, outputFile ; address of the file name
	mov rdx, 0C0000000h ; File needs to now be read/write
	xor r8, r8 ; share mode 0
	xor r9, r9 ; security attributes

	mov QWORD PTR [rsp + 48h - 28h], 2 ; CREATE_ALWAYS (using always create to override any previous runs of the program)
	mov QWORD PTR [rsp + 48h - 20h], 80h ; normal file attrubute
	mov QWORD PTR [rsp + 48h - 18h], 0 ; template file (none)
	call CreateFileA
	mov FD, rax

	; write input file to output file
	mov rcx, FD ; file stream
	lea rdx, buffer ; move 
	mov r8, charsRead ; number of characters to write to the stream
	lea r9, charsWritten ; get number of characters successfully written
	mov QWORD PTR [rsp + 48h - 28h], 0 ; no overlap
	call WriteFile
	mov writeOutputCode, rax

	; Write message to console to display if writing was successful

	mov rcx, -11
	call GetStdHandle
	mov rcx, rax

	cmp rax, 0 ; return value is non-0 if successful
	jnz success ; if rax - 0 != 0, writing was successful

	; rax was 0, writing failed
	lea rdx, failedOutput
	mov r8, failedOutputLen
	lea r9, charsWritten
	call WriteFile

	jmp cleanup

success:
	lea rdx, successOutput
	mov r8, successOutputLen
	lea r9, charsWritten
	call WriteFile

	jmp cleanup

cleanup:
	xor rcx, rcx
	call ExitProcess
_main ENDP

END