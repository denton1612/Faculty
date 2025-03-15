bits 32

global start
extern exit, fopen, fread, fclose, printf
import exit msvcrt.dll
import fopen msvcrt.dll
import fread msvcrt.dll
import fclose msvcrt.dll
import printf msvcrt.dll

segment data use32 class=data
    nume_fisier db 'input.txt', 0
    mod_deschidere db 'r', 0
    punct equ '.'
    spatiu equ ' '
    formatr db '%c', 0
    formatp db 'Propozitia %u: %s, Nr. cuvinte: %u, Primul cuvant %s are %u litere', 10, 0
    prop resb 100
    index dd 1
    descriptor_fisier resb 4
    nr_spatii dd 0
    nr_litere dd 0
    primul_cuvant resb 10
    
segment code use32 class=code
    start:
        push mod_deschidere
        push nume_fisier
        call [fopen]
        add esp, 4*2
        
        cmp eax, 0
        je sfarsit
        
        mov [descriptor_fisier], eax
        citire_fisier:
            mov esi, prop
            mov dword [nr_spatii], 0
            mov dword [nr_litere], 0
            citire_prop:
                push dword [descriptor_fisier]
                push dword 1
                push dword 1
                push esi
                call [fread]
                cmp eax, 0
                je sfarsit
                lodsb
            cmp al, spatiu
            jne nu_este_spatiu
            inc dword [nr_spatii]
            nu_este_spatiu:
            cmp dword [nr_spatii], 0
            ja nu_este_primul_cuvant
            inc dword [nr_litere]
            nu_este_primul_cuvant:
            cmp al, punct
            je sf_prop
            jmp citire_prop
            sf_prop:
                mov al, 0
                mov edi, esi
                stosb
                mov esi, prop
                add esi, [nr_litere]
                sub esi, 1
                mov edi, primul_cuvant
                mov ecx, [nr_litere]
                inverseaza:
                    std
                    lodsb
                    cld
                    stosb
                loop inverseaza
                mov al, 0
                stosb
                inc dword [nr_spatii]
                push dword [nr_litere]
                push primul_cuvant
                push dword [nr_spatii]
                push prop
                push dword [index]
                push formatp
                call [printf]
                add esp, 4*6
                inc dword [index]
            jmp citire_fisier
    sfarsit:
        push dword [descriptor_fisier]
        call [fclose]
        add esp, 4*1
        