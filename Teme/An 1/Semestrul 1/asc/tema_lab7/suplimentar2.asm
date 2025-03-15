bits 32

global start
extern exit
import exit msvcrt.dll

; Se dau doua siruri de octeti S1 si S2 de aceeasi lungime. Sa se construiasca sirul D astfel: fiecare element de pe pozitiile pare din D este suma elementelor de pe pozitiile corespunzatoare din S1 si S2, iar fiecare element de pe pozitiile impare are ca si valoare diferenta elementelor de pe pozitiile corespunzatoare din S1 si S2.

segment data use32 class=data
    s1 db 1, 2, 3, 4
    s2 db 5, 6, 7, 8
    l equ $-s2
    d times l db 0
    doi dw 2
segment code use32 class=code
    start:
        mov ecx, l
        mov esi, 0 ; esi va reprezenta indexul sirului, cu el vom parcurge sirurile s1, s2, d
        jecxz sfarsit
        repeta:
            mov eax, esi 
            push eax
            pop ax
            pop dx
            div word [doi] ; imapartim eax la 2 pentru a-i afla paritatea
            cmp dx, 0
            jz poz_para ; daca restul a fost 0, eax (indexul actual) este par
            mov bl, [s1+esi] ; tratam cazul index actual - impar
            sub bl, [s2+esi]
            mov [d+esi], bl
            jnz poz_impara
            poz_para: ; tratam cazul index actual - par
                mov bl, [s1+esi]
                add bl, [s2+esi]
                mov [d+esi], bl
            poz_impara
            inc esi
        loop repeta
        sfarsit
    
        