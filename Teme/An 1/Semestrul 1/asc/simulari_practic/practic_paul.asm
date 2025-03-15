bits 32

global start
extern exit, scanf, printf
import exit msvcrt.dll
import scanf msvcrt.dll
import printf msvcrt.dll

; Se citeste un mesaj de la tastatura (maxim 20 caractere) si un numar natural. Mesajul este codificat in felul urmator:
; - daca nr citit este par, atunci la fiecare caracter din mesaj se adauga n%20
; - daca nr citit este impar, atunci dupa fiecare consoana se adauga 'p'+consoana

segment data use32 class=data
    citire_mesaj db 'Introduceti mesajul: ', 0
    citire_numar db 'Introduceti un numar natural: ', 0
    format_c_m db '%s', 0
    format_c_n db '%u', 0
    afisare db 'Mesajul codificat: %s', 0
    mesaj_citit times 20 db 0, 0
    numar_citit dd 0
    mesaj_codificat times 60 db 0, 0
    vocale db 'aeiou'
    len equ $-vocale
    este_consoana dd 0
    zero dd 0
    
    
segment code use32 class=code
    start:
        cld
        push dword citire_mesaj
        call [printf]
        add esp, 4
        
        push mesaj_citit
        push format_c_m
        call [scanf]
        add esp, 8
        
        push dword citire_numar
        call [printf]
        add esp, 4
        
        push numar_citit
        push format_c_n
        call [scanf]
        add esp, 8
        
        test dword [numar_citit], 1h
        mov esi, mesaj_citit
        mov edi, mesaj_codificat
        jz nr_par
        repeta:
            mov dword [este_consoana], 1
            lodsb
            cmp al, 0
            je afisare_mesaj_codificat
            cmp al, 'a'
            jb repeta
            cmp al, 'z'
            ja repeta
            stosb
            push edi
            mov ecx, len
            mov ebx, 1
            verifica 
                mov edi, vocale
                scasb
                cmovz ebx, [zero]
            loop verifica
            mov [este_consoana], ebx
            pop edi
            cmp dword [este_consoana], 0
            jz repeta
            mov bl, al
            mov al, 'p'
            stosb
            mov al, bl
            stosb
        jmp repeta
        
        nr_par:
            mov dx, word [numar_citit+2]
            mov ax, word [numar_citit]
            mov bx, 20
            div bx
            repeta_par:
                lodsb
                cmp al, 0
                je afisare_mesaj_codificat
                add al, dl
                stosb
            jmp repeta_par
           
        afisare_mesaj_codificat:
            push mesaj_codificat
            push afisare
            call [printf]
            add esp, 8
            
        push dword 0
        call [exit]