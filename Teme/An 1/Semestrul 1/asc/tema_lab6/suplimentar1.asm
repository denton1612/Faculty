bits 32

global start
extern exit
import exit msvcrt.dll

segment data use32 class=data
    ; Se da octetul A. Sa se obtina numarul intreg n reprezentat de bitii 2-4 ai lui A. Sa se obtina apoi in B octetul rezultat prin rotirea spre dreapta a lui A cu n pozitii. Sa se obtina dublucuvantul C:
    ; bitii 8-15 ai lui C sunt 0
    ; bitii 16-23 ai lui C coincid cu bitii lui B
    ; bitii 24-31 ai lui C coincid cu bitii lui A
    ; bitii 0-7 ai lui C sunt 1
    a db 00001111b
    b resb 1
    n resb 1
    c resd 1
    
segment code use32 class=code
    start
    mov al, [a]
    mov [n], byte 0
    and al, 00011100b
    ror al, 2
    or [n], al
    mov cl, [n]
    mov al, [a]
    ror al, cl
    mov [b], al
    mov edx, 0
    or dl, 11111111b
    and dh, 00000000b
    mov cx, 0
    mov cl, [b]
    mov ch, [a]
    push cx
    push dx
    pop edx
    mov [c], edx
    
    
    