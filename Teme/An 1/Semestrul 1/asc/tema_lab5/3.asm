bits 32

global start
extern exit
import exit msvcrt.dll

segment data use32 class=data
    ; a-byte; b-doubleword; c-qword
    a db 10
    b dd 150
    c dq 1200
    
segment code use32 class=code
    ; c+(a*a-b+7)/(2+a) (fara semn)
    start
    mov ebx, [c]
    mov ecx, [c+4]
    mov eax, 0
    mov edx, 0
    mov al, [a]
    mul byte [a]
    sub eax, [b]
    add eax, 7
    mov bl, [a]
    mov bh, 0
    add bl, 2
    adc bh, 0
    div bx
    push ax
    mov eax, 0
    pop ax
    add eax, ebx
    adc edx, ecx
    