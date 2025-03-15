bits 32

global start

extern exit, scanf, printf
import exit msvcrt.dll
import scanf msvcrt.dll
import printf msvcrt.dll

; Sa se citeasca de la tastatura un numar in baza 10 si sa se afiseze valoarea acelui numar in baza 16.

segment data use32 class=data
    a resd 1
    formats db '%d'
    formatp db 'Numarul %d in baza 10 este %x in baza 16'
    
segment code use32 class=code
    start:
        push dword a
        push formats
        call [scanf]
        add esp, 4*2
        
        push dword [a]
        push dword [a]
        push formatp
        call [printf]
        add esp, 4*3
        
        push dword 0
        call [exit]