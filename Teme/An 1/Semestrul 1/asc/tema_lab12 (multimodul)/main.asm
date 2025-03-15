bits 32

global start

extern exit, printf
import exit msvcrt.dll
import printf msvcrt.dll
%include "\\Mac\Home\Desktop\facultate teme\asc\tema_lab12 (multimodul)\permutare_circulara.asm"

; Se da un numar a reprezentat pe 32 biti fara semn. Se cere sa se afiseze reprezentarea in baza 16 a lui a, precum si rezultatul permutarilor circulare ale cifrelor sale. 

segment data use32 class = data
    a dd 0ffffaaaah
    format db 'Numarul in baza 16: %x', 10, 0
    format_permutare db 'Permutarea %u: %x, %s', 10, 0
    ciclu dd 4
    permutare dd 1
    permutare_circulara_in_baza_2 times 32 db -1, 0
    permutare_circulara_in_baza_16 dd 0
    
segment code use32 class = code
    start:
        ; apelez functia printf pentru a afisa reprezentarea in baza 16 a valorii a
        push dword [a]
        push format
        call [printf]
        add esp, 4*2
        
        repeta:
            push dword [ciclu]
            push dword [a]
            call permutare_circulara
            add esp, 4*2
            mov [permutare_circulara_in_baza_16], eax
            mov ebx, eax
            mov al, 0
            mov edi, permutare_circulara_in_baza_2
            mov ecx, 32
            roteste:
                rcl ebx, 1
                adc al, 0
                add al, '0'
                stosb
                xor al, al
            loop roteste
            push dword permutare_circulara_in_baza_2
            push dword [permutare_circulara_in_baza_16]
            push dword [permutare]
            push format_permutare
            call [printf]
            add esp, 4*2
            add dword [ciclu], 4
            inc dword [permutare]
            cmp dword [ciclu], 31
            ja final
        jmp repeta
        
    final:
        push dword 0
        call [exit]
            
        
        
