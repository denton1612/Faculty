bits 32
global start

extern exit, scanf, printf
import exit msvcrt.dll
import scanf msvcrt.dll
import printf msvcrt.dll

segment data use32 class=data
    ; Sa se citeasca de la tastatura doua numere (in baza 10) si sa se calculeze produsul lor. Rezultatul inmultirii se va salva in memorie in variabila "rezultat" (definita in segmentul de date).
    a dd 0
    b dd 0
    mesaj db 'Produsul numerelor este %u', 0
    format_a db '%u', 0
    format_b db '%u', 0
    rezultat dq 0
    
    
segment code use32 class=code
    start:
    ; citim de la tastatura un numar in baza 10 pe care il salvam la offset ul a
        push dword a
        push format_a
        call [scanf]
        add esp, 4*2
        mov eax, [a]
        
        push eax
    ; citim de la tastatura un numar in baza 10 pe care il salvam la offset ul a   
        push dword b
        push format_b
        call [scanf]
        add esp, 4*2
        mov ebx, [b]
    ; salvez in rezultat produsul ax*bx = a*b   
        pop eax
        mul ebx
        mov [rezultat], eax
        mov [rezultat+4], edx 
        
    ; optional! afisez valoarea rezultatului (dword)    
        push dword [rezultat]
        push mesaj
        call [printf]
        add esp, 4*2
        
        push dword 0
        call [exit]