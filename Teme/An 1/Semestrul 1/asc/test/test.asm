bits 32

global start

extern exit
import exit msvcrt.dll

segment data use32 class=data
    a dw 10
segment code use32 class=code
start:
    mov ax, 3344h
    cld
    mov edi, a
    push ax
    mov ax, [esp+2]
    stosw
    lea edi, [edi-2]
    add esp, 4