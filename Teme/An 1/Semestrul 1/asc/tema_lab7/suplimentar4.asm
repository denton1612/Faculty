bits 32

global start
extern exit
import exit msvcrt.dll

 ; Se da un sir de octeti S. Sa se construiasca un sir D1 care sa contina toate numerele pozitive si un sir D2 care sa contina toate numerele negative din S.

segment data use32 class=data
    s db 1, 3, -2, -5, 3, -8, 5, 0
    ls equ $-s
    d1 times ls db 0
    d2 times ls db 0
    
segment code use32 class=code
    start:
        mov ecx, ls ; numar de loop uri (vom parcurge fiecare numar din s
        jecxz sfarsit
        mov esi, 0 ; poz curenta in s
        mov edi, 0 ; poz curenta in d1
        mov ebx, 0 ; poz curenta in d2
        repeta:
            cmp byte [s+esi], 0
            js nr_negativ ; verificam daca numarul curent din s este negativ (sf = 1)
            ; tratam cazul nr_pozitiv
            mov al, [s+esi]
            mov [d1+edi], al
            inc edi
            jns nr_pozitiv
            ; tratam cazul nr_negativ
            nr_negativ:
                mov al, [s+esi]
                mov [d2+ebx], al
                inc ebx 
            ; finalizam cazul nr_pozitiv
            nr_pozitiv:
                inc esi
        loop repeta
        sfarsit
            
            push dword 0
            call [exit]