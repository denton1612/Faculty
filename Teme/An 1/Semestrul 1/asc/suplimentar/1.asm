bits 32

global start

extern exit, scanf, printf
import exit msvcrt.dll
import scanf msvcrt.dll
import printf msvcrt.dll

; Sa se citeasca un sir s1 (care contine doar litere mici). Folosind un alfabet (definit in segmentul de date), determinati si afisati sirul s2 obtinut prin substituirea fiecarei litere a sirului s1 cu litera corespunzatoare din alfabetul dat.
; Exemplu:
; Alfabetul: OPQRSTUVWXYZABCDEFGHIJKLMN
; Sirul s1:  anaaremere
; Sirul s2:  OBOOFSASFS

segment data use32 class=data
    alfabetul db 'OPQRSTUVWXYZABCDEFGHIJKLMN', 0
    s1 db 'anaaremere', 0
    len equ $-s1
    s2 resb len
    
segment code use32 class=code
    start:
        mov edi, s2
        mov esi, s1
        mov ecx, len
        
        repeta:
            lodsb
            sub al, 'a'
            push esi
            mov esi, alfabetul
            movzx eax, al
            add esi, eax
            lodsb
            stosb
            pop esi
        loop repeta
    
  