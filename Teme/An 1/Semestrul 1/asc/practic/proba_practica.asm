bits 32

global start
extern exit, scanf, printf, fopen, fprintf, fclose
import exit msvcrt.dll
import scanf msvcrt.dll
import printf msvcrt.dll
import fopen msvcrt.dll
import fprintf msvcrt.dll
import fclose msvcrt.dll

; Sa se citeasca de la tastatura mai multe numere pana la citirea valorii 0. Sa se scrie intr-un fisier, separate de spatii, doar acele numere pozitive care au numar par de biti 0 (cu valoarea 0).

segment data use32 class=data
    numar_curent dd 0
    nr_biti_1 db 0
    citire db 'Introduceti un numar intreg: ', 0
    formats db '%d', 0
    formatp db '%u ', 0
    nume_fisier db '\\Mac\Home\Desktop\facultate teme\asc\practic\rezultat.txt', 0
    mod_acces db 'w', 0
    descriptor_fisier dd -1
    
segment code use32 class=code
    start:
        push dword mod_acces
        push dword nume_fisier
        call [fopen]
        add esp, 4*2
        cmp eax, 0
        je sfarsit
        mov [descriptor_fisier], eax
        
        repeta:
            push dword citire
            call [printf]
            add esp, 4
            
            mov byte [nr_biti_1], 0
            push dword numar_curent
            push dword formats
            call [scanf]
            add esp, 4*2
            cmp dword [numar_curent], 0
            jl repeta
            je final
            mov eax, [numar_curent]
            mov ecx, 32
            roteste:
                rcl eax, 1
                adc byte [nr_biti_1], 0
            loop roteste
            test byte [nr_biti_1], 1h
            jnz repeta
            push dword [numar_curent]
            push dword formatp
            push dword [descriptor_fisier]
            call [fprintf]
            add esp, 4*3
        jmp repeta
        
        final:
            push dword [descriptor_fisier]
            call [fclose]
            add esp, 4
        sfarsit:
            push dword 0
            call [exit]