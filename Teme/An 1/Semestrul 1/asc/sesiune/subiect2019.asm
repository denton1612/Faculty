bits 32

global start
extern exit, printf
import exit msvcrt.dll
import printf msvcrt.dll

segment data use32 class=data
    sir_dwords dd 12341234h, 42314231h, 12345678h, 56232356h
    len1 equ ($-sir_dwords)/4
    sir_words times len1 dw 0
    suma dd 0
    mesaj db 'Suma este: %d', 0
    
segment code use32 class=code
    start:
        cld
        mov ecx, len1
        mov edi, sir_words
        mov esi, sir_dwords+1
        push ecx
        repeta:
            movsb
            inc esi
            movsb
            inc esi
        loop repeta
        pop ecx
        mov esi, sir_words
        aduna:
            lodsw
            push ecx
            mov ecx, 16
            muta:
                shr ax, 1
                adc dword [suma], 0
            loop muta
            pop ecx
        loop aduna
        push dword [suma]
        push mesaj
        call [printf]
        add esp, 8