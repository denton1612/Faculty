bits 32

global start

extern exit, fopen, fread, fclose, printf
import exit msvcrt.dll
import fopen msvcrt.dll
import fread msvcrt.dll
import fclose msvcrt.dll
import printf msvcrt.dll

; Se da in segmentul de date numele unui fisier. Acesta contine cifre separate prin spatiu (in baza 16). Sa se afiseze fiecare cifra din fisier si numarul de biti de 1 din reprezentarea binara a acesteia.

segment data use32 class=data
    nume_fisier db 'continut.txt', 0
    descriptior_fisier dd -1
    caracter dd 0
    spatiu equ ' '
    formatp db '%c - %u', 10, 0
    mod_acces db 'r', 0
    
segment code use32 class=code
    
    ; 'subprogram' pentru numararea bitilor de 1 ai reprezentarii binare stocate in dl (conventia stdcall - 'apelatul' curata stiva)
    
    numarare_biti_1:
        mov dl, [esp+4]
        mov ecx, 8
        mov eax, 0
        repeta:
            shr dl, 1
            adc eax, 0
        loop repeta
        ret 4
    
    ; main:
    
    start:
    
        push dword mod_acces
        push dword nume_fisier
        call [fopen]
        add esp, 4*2
        
        cmp eax, 0
        je sfarsit
        mov [descriptior_fisier], eax
        
        citire_caracter:
        
        push dword [descriptior_fisier]
        push 1
        push 1
        push caracter
        call [fread]
        add esp, 4*4
        
        cmp eax, 0
        je sfarsit
        
        cmp byte [caracter], spatiu
        je citire_caracter
        
        cmp byte [caracter], '9'
        jg litera
        mov al, [caracter]
        sub al, '0'
        jmp afisare
        litera:
        mov al, [caracter]
        sub al, 'A'
        add al, 10
        afisare:
        movzx eax, al
        push eax
        call numarare_biti_1   
        
        push eax
        push dword [caracter]
        push formatp
        call [printf]
        add esp, 4*3
        
        jmp citire_caracter
        
        sfarsit:
        push dword [descriptior_fisier]
        call [fclose]
        add esp, 4
        
        push dword 0
        call [exit]
        