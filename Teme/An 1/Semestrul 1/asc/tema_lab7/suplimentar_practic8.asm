bits 32

global start

extern exit
import exit msvcrt.dll

; Se da un sir A de cuvinte. Construiti doua siruri de octeti  
; - B1: contine ca elemente partea superioara a cuvintelor din A
; - B2: contine ca elemente partea inferioara a cuvintelor din A

segment data use32 class=data
    a dw 1122h, 3344h, 5566h, 7788h, 9912h
    la db ($-a) / 2
    b1 resb ($-a) / 2 
    b2 resb ($-b1)
    

segment code use32 class=code
start:
    mov ecx, [la]
    mov esi, a
    mov edi, b2
    repeta1:
        lodsw
        stosb
    loop repeta1
    mov ecx, [la]
    mov esi, a
    mov edi, b1
    repeta2:
        lodsw
        mov al, ah
        stosb
    loop repeta2