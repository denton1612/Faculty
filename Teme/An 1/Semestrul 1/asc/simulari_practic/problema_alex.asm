bits 32

global start
extern exit, scanf, printf
import exit msvcrt.dll
import scanf msvcrt.dll
import printf msvcrt.dll

; Se citesc mai multe numere de la tastatura, in baza 2. Sa se afiseze aceste numere in baza 8.

segment data use32 class=data
    baza_2 resb 32
    formats db '%s', 0
    baza_8 resb 32
    formatp db '%o', 0
    zece dw 10
segment code use32 class=code
    start:  
        push baza_2
        push formats
        call [scanf]
        add esp, 8
       
        cld
        mov ecx, 32
        mov ebx, 0
        
        repeta:
            mov esi, baza_2
            lodsb
            sub al, '0'
            shr al, 1
            rcl ebx, 1
        loop repeta
        
        push ebx
        push formatp
        call [printf]
        add esp, 8