bits 32

global start
extern exit
import exit msvcrt.dll

segment data use32 class=data
    ; a-byte; b-doubleword; c-qword
    a db 10
    b dd -100
    c dq 1500
    
segment code use32 class=code
    start
    ; c+(a*a-b+7)/(2+a)
    mov ebx, [c]
    mov ecx, [c+4]
    mov al, [a]
    imul byte [a]
    cwde 
    sub eax, [b]
    add eax, 7
    push eax
    mov al, [a]
    cbw 
    add ax, 2
    mov bx, ax
    pop eax
    idiv bx
    cwde
    cdq
    add eax, ebx
    adc edx, ecx
    
    