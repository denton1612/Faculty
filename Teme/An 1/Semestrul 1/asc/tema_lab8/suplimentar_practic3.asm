bits 32

global start
extern exit, printf
import exit msvcrt.dll
import printf msvcrt.dll

; Se dau doua numere naturale a si b (a, b: dword, definite in segmentul de date). Sa se calculeze suma lor si sa se afiseze in urmatorul format: "<a> + <b> = <result>"
; Exemplu: "1 + 2 = 3"
; Valorile vor fi afisate in format decimal (baza 10) cu semn.

segment data use32 class=data
    a dd 10
    b dd -100
    suma resd 1
    formats dd '%d%d'
    formatp dd '%d + %d = %d'
    
segment code use32 class=code
    start:
        mov eax, [a]
        add eax, [b]
        mov [suma], eax
        
        push dword [suma]
        push dword [b]
        push dword [a]
        push formatp
        call [printf]
        add esp, 4*4