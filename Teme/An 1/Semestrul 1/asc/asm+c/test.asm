bits 32
global start


segment data use32 class=data
    a1 dw 14, 10
    a2 dd 1000h, $-a1
segment code use32 class=code
    start:
        mov eax, 0
    