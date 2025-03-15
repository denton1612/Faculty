bits 32

global start

extern exit
import exit msvcrt.dll

; Se da un sir de octeti s. Sa se construiasca sirul de octeti d, care contine pe fiecare pozitie numarul de biti 1 ai octetului de pe pozitia corespunzatoare din s.

segment data use32 class=data
    s db 5, 25, 55, 127, 4
    l db $ - s
    nr_biti_1 db 0
    d resb $ - s
    
    
segment code use32 class=code
    start:
        cld
        mov esi, s
        mov edi, d
        mov ecx, [l]
        repeta:
            mov [nr_biti_1], byte 0
            lodsb
            cmp al, 0
            jz sfarsit
            nr_1:
                shl al, 1
                adc byte [nr_biti_1], 0
                cmp al, 0
            jnz nr_1
            sfarsit:
                mov al, [nr_biti_1]
                stosb
        loop repeta
    
    