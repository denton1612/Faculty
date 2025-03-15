bits 32

global start
extern exit, scanf, printf
import exit msvcrt.dll
import scanf msvcrt.dll
import printf msvcrt.dll

; Sa se citeasca de la tastatura un octet si un cuvant. Sa se afiseze pe ecran daca bitii octetului citit se regasesc consecutiv printre bitii cuvantului

segment data use32 class=data
    a resd 1
    b resd 1
    formats db '%d%d', 0
    mesaj1 db 'da', 0
    mesaj0 db 'nu', 0
    formatp db '%s', 0
    d dw 100h
    
segment code use32 class=code
    start:
    push dword b
    push dword a
    push dword formats
    call [scanf]
    add esp, 4*3

    mov ecx, 8
    repeta:
        mov ax, word [b]
        mov bl, byte [a]
        movzx bx, bl
        sub ax, bx
        mov dx, 0
        div word [d]
        cmp dx, 0
        je da
        shr word [b], 1
    loop repeta
    jmp nu
    da:
        push dword mesaj1
        push formatp
        call [printf]
        add esp, 4*2
    jmp sfarsit
    nu:
        push dword mesaj0
        push formatp
        call [printf]
        add esp, 4*2
    sfarsit:
        push dword 0
        call [exit]