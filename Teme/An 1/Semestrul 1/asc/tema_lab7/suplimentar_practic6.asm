bits 32

global start

extern exit
import exit msvcrt.dll

; Se da un sir de dublucuvinte. Sa se obtina sirul format din octetii superiori ai
;cuvitelor superioare din elementele sirului de dublucuvinte care sunt divizibili cu 3.

segment data use32 class=data
    s dd 12345678h, 212B3C4Dh, 0FE98DC76h
    ls db ($-s)/4
    trei equ 3
    d db 0 
    
segment code use32 class=code
    start:
        cld
        mov ecx, ls
        mov esi, s+3
        mov edi, d
        repeta:
            lodsb
            add esi, 3
            mov bl, al
            movzx ax, al
            div byte [trei]
            cmp ah, 0
            jnz nu_divide_3
            mov al, bl
            stosb
            nu_divide_3:
        loop repeta