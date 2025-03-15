bits 32

global start
extern exit
import exit msvcrt.dll

;Se dau doua siruri de octeti S1 si S2. Sa se construiasca sirul D prin concatenarea elementelor din sirul S1 1uate de la stanga spre dreapta si a elementelor din sirul S2 luate de la dreapta spre stanga.

segment data use32 class=data
    s1 db 1, 2, 3, 4
    l1 equ $ - s1 ; l1=lungimea sirului s1
    s2 db 5, 6, 7 
    l2 equ $-s2 ; l2 = lungimea sirului s2
    l equ l1+l2 ; l = lungimea sirului d
    d times l db 0
    
segment code use32 class=code
    start:
        mov ecx, l1 ; loop ul repeta1 se va executa de l1 ori (va parcurge fiecare element al sirului s1)
        mov esi, 0 ; 
        jecxz sfarsit
        repeta1:
            mov al, [s1+esi]
            mov [d+esi], al
            inc esi
        loop repeta1
        sfarsit
        
        mov ecx, l2
        mov esi, l1
        mov edi, l2-1
        jecxz final
        repeta2:
            mov al, [s2+edi]
            mov [d+esi], al
            dec edi
            inc esi
        loop repeta2
        final
        
        