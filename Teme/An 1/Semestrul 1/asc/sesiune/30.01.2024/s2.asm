bits 32

global start
extern exit, printf
import exit msvcrt.dll
import printf msvcrt.dll

segment data use32 class=data
    s1 dq 1234617812345678h, 3412567878561234h, 4567871234218967h
    l1 equ ($-s1) / 8
    s2 resd l1
    sir_vocale db 'aeiouAEIOU', 0
    zece db 10
    nr_vocale dd 0
    format db '%d', 0
   
segment code use32 class=code
    vocale:
        cld
        mov ebx, [esp+4] ; adresa sirului s2
        mov ecx, l1
        mov edx, 0
        mov esi, sir_vocale
        repeta:
            mov edi, sir_vocale
            mov al, [ebx+edx*4+1]
            verifica:
                scasb
                je ok
                push edi
                sub edi, esi
                cmp edi, 9
                ja bad
                pop edi
            jmp verifica
            ok:
                inc dword [nr_vocale]
            bad:
                add edx, 4
        loop repeta
        ret 4
        
    start:
        cld
        mov ecx, l1
        mov esi, s1 ; pentru parcurgerea sirului s1
        mov edi, s2
        parcurge:
            lodsd
            lodsd ; avem nevoie de dd high din fiecare dq, deci dupa doua lodsd vom avea in eax dd high
            mov bx, ax ; cuvantul low din dd high
            shr eax, 16; ax = cuvnatul high din dd high
            cmp ax, bx
            jng mai_departe
            shl eax, 16
            mov ax, bx ; reconstituim dd high in eax pentru a l salva in s2
            stosd
            mai_departe:
        loop parcurge
        
        push dword s2
        call vocale
        
        push dword [nr_vocale]
        push format
        call [printf]
        add esp, 4*2
        
        
       