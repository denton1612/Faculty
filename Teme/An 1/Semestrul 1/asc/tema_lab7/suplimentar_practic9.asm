bits 32

global start

extern exit
import exit msvcrt.dll

; Se da un sir S de dublucuvinte.
; Sa se obtina sirul D format din octetii dublucuvintelor din sirul S sortati in ordine crescatoare in interpretarea fara semn.

segment data use32 class=data
    s dd 12345607h, 1A2B3C15h
    l equ $-s
    ordonat db 0
    d db 0
    
segment code use32 class=code
    ; pentru a sorta crescator octetii dublucuvintelor din s, voi folosi bubble sort

    start:
        mov ecx, l
        sub ecx, 1
        repeta:
            mov byte [ordonat], 1
            mov ecx, l
            sub ecx, 1
            mov esi, s
            mov edi, s+1
            repeta1:
                cmpsb
                jbe ok
                mov al, [esi-1]
                mov bl, [edi-1]
                mov [esi-1], bl
                mov [edi-1], al
                mov byte [ordonat], 0
                ok:
            loop repeta1
            cmp byte [ordonat], 1
            je gata
        jmp repeta
        gata:
        mov esi, s
        mov edi, d
        mov ecx, l
        muta:
            movsb
        loop muta
    push dword 0
    call [exit]
        
        