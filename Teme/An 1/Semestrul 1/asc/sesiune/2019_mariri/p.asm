bits 32

global start
extern exit, printf

import exit msvcrt.dll
import printf msvcrt.dll

segment data use32 class=data
    s1 dd 1234a678h, 12785634h, 1a4d3c26h
    len equ ($-s1) / 4
    s2 times len resw 1
    nr_biti_1 dd 0
    format db 'Numarul de biti de 1 este: %d', 0
    
segment code use32 class=code
    calculeaza: ; primeste parametrul in registrul ax si returneaza nr de biti de 1 in edx
        push ecx
        xor edx, edx
        mov ecx, 16
        repeta:
            shr ax, 1
            adc edx, 0
        loop repeta
        pop ecx
        ret
    
    start:
        cld
        mov ecx, len
        mov ebx, s1
        mov edx, 0
        mov edi, s2
        muta:
            mov al, [ebx+4*edx+1]
            stosb
            mov al, [ebx+4*edx+3]
            stosb
            inc edx
        loop muta
        
        ; in urma loop ului avem construit sirul s2 de word uri format din octetii superiori din cuvintele dd urilor din sirul s1 (sir dat)
        
        mov ecx, len
        mov esi, s2
        aduna:
            lodsw
            call calculeaza
            add [nr_biti_1], edx
        loop aduna
        
        push dword [nr_biti_1]
        push format
        call [printf]
        add esp, 4*2
        
        push dword 0
        call [exit]