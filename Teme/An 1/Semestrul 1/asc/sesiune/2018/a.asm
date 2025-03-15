bits 32
global start

extern exit, printf
import exit msvcrt.dll
import printf msvcrt.dll

extern maxim
global len

segment data public data use32
    sir dd 1234a678h, 12345678h, 1ac3b47dh, 0fedc9876h
    len equ ($-$$)/4
    rez times len db 0
    rank db 0
    sum dd 0
    format db '%d', 0
    
segment code public code use32
    start:
        push rez
        push sir
        call maxim
        add esp, 8
        
        mov [sum], eax
        push dword [sum]
        push format
        call [printf]
        add esp, 8
    
    push dword 0
    call [exit]