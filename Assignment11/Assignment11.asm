
extern ExitProcess : proc

.data


.code

_main PROC
sub rsp, 28h ; Windows 11 is weird


xor rcx, rcx
call ExitProcess
_main ENDP

END