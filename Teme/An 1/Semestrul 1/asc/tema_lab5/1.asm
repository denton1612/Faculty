bits 32

global start
extern exit
import exit msvcrt.dll

segment data use32 class=data
    a dw 0abcdh, 0fedch
    
segment code use32 class=code
    start:
        mov al, 255
        ror al, 15
        