bits 32

global start

extern exit
import exit msvcrt.dll

; Se dau doua siruri s1 si s2 de octeti (nr naturale). Sa se construiasca sirul d astfel incat acesta sa contina pozitia elementului s2 de pe poz corespunzatoare in sirul s1 (0 daca acesta nu este in s1)

segment data use32 class=data
    s1 db 7, 33, 55, 19, 46
    ls1 db $ - s1
    s2 db 33, 21, 7, 13, 27, 19, 55, 1, 46 
    ls2 db $ - s2
    poz db 0, 0
    d db 0


segment code use32 class=code
    start:
        cld
        mov ecx, [ls2]
        mov esi, s2
        mov edi, d
        repeta1:
            push edi
            mov edi, s1
            lodsb
            verifica:
                inc byte [poz]
                mov dl, [poz]
                cmp dl, [ls1]
                ja nu_exista 
                scasb
                jnz verifica
            mov al, [poz]
            nu_exista:
                mov byte [poz], 0
            cmp dl, [ls1]
            jbe final
            mov al, [poz]
            final:
                pop edi
                stosb
        loop repeta1