bits 32

global start
extern exit, printf, suma

import exit msvcrt.dll
import printf msvcrt.dll

segment data use32 public data
    s1 dd -1, 123456, 0abcdeffh, 0abcdeffh, 0cbcdeffh, 0dbcdeffh, 0111010101b
    l equ ($-s1)/4
    s2 resb l
    ok db 0
    format db '%x', 0
    
segment code use32 public code
    start:
        push l
        push s2
        push s1
        call suma
        add esp, 12
        
        ; avem format sirul s2 de bytes continand sumele cifrelor dd in hexa din sirul de dd s1
        
        ; vom parcurge sirul s2, incepand cu elem de pe poz 0  (0..l-2) si parcurgem restul sirului cat timp secventa curenta este strict crescatoare;
        ; cand gasim 2 elem care nu sunt ordonate coresp, ne oprim din parcurgere, tiparim dd din sirul s1 (hexa) de pe poz 0, 1, ..., i (secventa crescatoare)
        ; si apoi reluam parcurgerea in sirul s2, incepand cu elem de pe poz i+1 si repetam procesul pana cand ajungem la i = l-1
        
        mov esi, s2
        mov edi, s2+1
        mov ebx, esi
        mov byte [ok], 1
        push edi
        compara:
            pop edi ; restituire edi
            cmpsb
            jb cr
            mov byte [ok], 0
            cr:
            cmp byte [ok], 1
            je compara
            push edi
            sub ebx, s2 ; ebx = indicile de inceput al secventei
            sub edi, 2
            sub edi, s2 ; edi = indicile de sfarsit al secventei
            afiseaza:
                push dword [s1+4 * ebx]
                push format
                call [printf]
                add esp, 8
                inc ebx
                cmp ebx, edi
                ja compara
            jmp afiseaza
            
            
            
        