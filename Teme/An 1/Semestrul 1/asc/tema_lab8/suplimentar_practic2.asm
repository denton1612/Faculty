bits 32

global start

extern exit, scanf, printf
import exit msvcrt.dll
import scanf msvcrt.dll
import printf msvcrt.dll

; Sa se citeasca de la tastatura doua numere a si b (in baza 10) si sa se calculeze a/b. Catul impartirii se va salva in memorie in variabila "rezultat" (definita in segmentul de date). Valorile se considera cu semn.

segment data use32 class=data
    a dd 0
    b dd 0
    format db '%d%d', 0, 0
    format1 db '%d', 0, 0, 0
    rezultat dw 0
    
segment code use32 class=code
    start:
        push dword b
        push dword a
        push dword format
        call [scanf]
        add esp, 4*3
        
        mov eax, [a]
        cdq
        idiv dword [b]
        mov [rezultat], eax

        push dword [rezultat]
        push dword format1
        call [printf]
        add esp, 4*2