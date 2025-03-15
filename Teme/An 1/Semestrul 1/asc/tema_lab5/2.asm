bits 32

global start
extern exit
import exit msvcrt.dll

segment data use32 class=data
    ; a - byte, b - word, c - double word, d - qword - Interpretare cu semn
    a db 10
    b dw 20
    c dd 100
    d dq 500
    
segment code use32 class=code
    start
    ; (c+b+a)-(d+d)
    mov ebx, [d]
    add ebx, [d]
    mov ecx, [d+4]
    adc ecx, 0
    add ecx, [d+4] ; ecx:ebx = d+d
    mov al, [a]
    cbw ; ax = a
    add ax, [b]
    cwd ; 
    add dx, 0 ; dx:ax = b+a
    add ax, [c]
    adc dx, [c+2] ; dx:ax = c+b+a
    push dx
    push ax
    pop eax ; eax = c+b+a
    cdq ; edx:eax = c+b+a
    sub eax, ebx
    sbb edx, ecx ; edx:eax = (c+b+a)-(d+d) 
    ; !!!! - sub sau sbb la linia 34????
    