bits 32

global start
extern exit
import exit msvcrt.dll

segment data use32 class=data
    ;Se da un sir de octeti S de lungime l. Sa se construiasca sirul D de lungime l-1 astfel incat elementele din D sa reprezinte produsul dintre fiecare 2 elemente consecutive S(i) si S(i+1) din S
    s db 10, 20, 30, 40; declararea si initializarea sirului initial
    l equ $-s ; l = lungimea lui s
    d times l-1 dw 0 ; declaram si initializam (cu 0) sirul d
    
segment code use32 class=code
    start:
        mov ecx, l-1 ; punem lungimea lui d in ecx pentru a realiza loop ul de l-1 ori
        mov esi, 0 ; cu esi ne vom deplasa prin sirul s (s+esi - pozitia actuala din memorie)
        mov ebx, 0 ; cu ebx ne vom deplasa prin sirul d (d+esi - pozitia actuala din memorie)
        jecxz sfarsit
        Repeta:
            mov al, [s+esi]
            mul byte [s+esi+1]
            mov [d+ebx], ax
            inc esi
            add ebx, 2 ; incrementam cu 2 ebx, deoarece fiecare numar din d este stocat intr-un cuvant (2 octeti)
        loop Repeta
        sfarsit:
    
        push dword 0
        call [exit]
    