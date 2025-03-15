bits 32

global start

extern exit,scanf

import exit msvcrt.dll
import scanf msvcrt.dll

segment data use32 class=data
    n dd 0
    s1 times 100 dd 0
    s2 times 100 db 0
    format_citire db '%d', 0
    suma_cifre_pare db 0
    nr_elemnete dd 0
    zece dw 10
    
segment code use32 class=code
    start:
        push n
        push format_citire
        call [scanf]
        add esp, 8
        
        mov ecx, [n]
        mov [nr_elemnete], ecx
        
        mov esi, s1
        citeste:
            push esi
            push format_citire
            call [scanf]
            add esp, 8
            add esi, 4
            dec dword [n]
            cmp dword [n], 0
            je gata
        jmp citeste
        gata:
        
        ; avem format string ul de n dd citite de la tastatura
        
        mov ecx, [nr_elemnete]
        cld
        mov esi, s1
        mov edi, s2
        repeta:
            lodsd
            push eax
            pop ax
            pop dx ; in dx:ax avem un dd din s1
            imparte:
                div word [zece] ; dx = rest (cifra), ax = cat (cifrele ramase) - baza 10
                test dl, 1
                jnz impar
                add [suma_cifre_pare], dl
                impar:
                mov dx, 0
                cmp ax, 0
                je urmatorul
                jmp imparte
            urmatorul:
                mov al, [suma_cifre_pare]
                stosb
                mov byte [suma_cifre_pare], 0
        loop repeta
        