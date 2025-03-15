bits 32

global start
extern exit, scanf, printf
import exit msvcrt.dll
import scanf msvcrt.dll
import printf msvcrt.dll

; Sa se citeasca de la tastatura un numar n reprezentat pe doubleword. Apoi sa se citeasca un sir de n numere (doubleword), sa se stocheze in memorie si sa se
; construiasca un nou sir de bytes, unde fiecare element reprezinta valoarea sumei cifrelor pare a numarului din sirul de doublewords de pe poz coresp (in baza 10).

segment data use32 class=data
    n dd 0
    sir_numere resd 100
    sir_suma_cifre_pare resb 100
    suma_cifre_pare_nr_curent db 0
    format1 db 'Introduceti un numar: ', 10, 0
    format2 db '%d', 0
    format3 db 'Introduceti un sir de %u numere: ', 10, 0
    zece dw 10
    format4 db '%d', 10, 0
   
segment code use32 class=code
    suma_cifrelor_pare:
        mov dx, [esp+2]
        mov ax, [esp+4]
        mov byte [suma_cifre_pare_nr_curent], 0
        div word [zece]
        imparte:
            cmp ax, 0
            je gata
            test dl, 1h
            jnz impar
            add [suma_cifre_pare_nr_curent], dl
            impar:
            mov dx, 0
            div word [zece]
        jmp imparte
        gata:
            mov al, [suma_cifre_pare_nr_curent]
            movzx eax, al
            ret
    start:
        cld
        push format1
        call [printf]
        add esp, 4
        
        push n
        push format2
        call [scanf]
        add esp, 8
        
        push dword [n]
        push format3
        call [printf]
        add esp, 8
        
        push dword [n]
        
        mov edi, sir_numere
        citeste:
            push edi
            push format2
            call [scanf]
            add esp, 8
            add edi, 4
            dec dword [n]
            cmp dword [n], 0
        ja citeste
        
        pop dword [n]
        mov esi, sir_numere
        mov edi, sir_suma_cifre_pare
        repeta:
            lodsd
            push eax
            call suma_cifrelor_pare
            push eax
            push format4
            call [printf]
            add esp, 8
            stosb
            dec dword [n]
            cmp dword [n], 0
        ja repeta
        
        
        
        push dword 0
        call [exit]