bits 32

global start

extern exit, scanf, printf
import exit msvcrt.dll
import scanf msvcrt.dll
import printf msvcrt.dll

; Sa se citeasca un sir de numere intregi s1 (reprezentate pe dublucuvinte) in baza 10. Sa se determine si sa se afiseze sirul s2 compus din cifrele aflate pe poziţia sutelor în fiecare numar intreg din sirul s1.
; Exemplu:
; Sirul s1: 5892, 456, 33, 7, 245
; Sirul s2: 8, 4, 0, 0, 2

segment data use32 class=data
    numar_curent dd 0
    sir_cifra_sutelor resb 100
    suta dw 100
    zece db 10
    formats db '%d', 0
    formatp db 'Cifrele sutelor sunt: %s'
    
segment code use32 class=code
    cifra_sutelor:
        mov eax, [esp+4]
        push eax
        pop ax
        pop dx
        idiv word [suta]
        idiv byte [zece]
        movzx eax, ah
        ret
    start:
        mov edi, sir_cifra_sutelor
        repeta:
            push dword numar_curent
            push dword formats
            call [scanf]
            add esp, 4*2
            cmp dword [numar_curent], 0
            je final
            push dword [numar_curent]
            call cifra_sutelor
            add esp, 4
            stosb
        jmp repeta
        final:
        push dword 0
        call [exit]