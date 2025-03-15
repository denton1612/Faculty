bits 32

global start
extern exit
import exit msvcrt.dll

segment data use32 class=data
    ; Se dau cuvintele A si B. Sa se obtina dublucuvantul C:
    a dw 0010_1100_1010_0101b
    b dw 1111_0000_1101_0011b
    c resd 1 ; c = 0010_1100_1010_0101_0000_1111_1110_0101 (dupa rulare)
   
segment code use32 class=code
    ; bitii 0-4 ai lui C coincid cu bitii 11-15 ai lui A
    ; bitii 5-11 ai lui C au valoarea 1
    ; bitii 12-15 ai lui C coincid cu bitii 8-11 ai lui B
    ; bitii 16-31 ai lui C coincid cu bitii lui A
    start:
    mov dx, [a] ; 16-31 C = A
    mov ax, [a]
    and ax, 1111100000000000b ; ax = 11-15 A
    mov cl, 11
    ror ax, cl
    or ax, 0000111111100000b ; 5-11 C = 1
    mov bx, [b]
    and bx, 0000111100000000b
    mov cl, 4
    rol bx, cl
    or ax, bx 
    push dx
    push ax
    pop eax
    mov [c], eax
        
        push dword 0
        call [exit]
    
    
    