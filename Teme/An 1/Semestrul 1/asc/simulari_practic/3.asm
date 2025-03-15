bits 32

global start

extern exit, scanf, fopen, fprintf, fclose
import exit msvcrt.dll
import scanf msvcrt.dll
import fopen msvcrt.dll
import fprintf msvcrt.dll
import fclose msvcrt.dll

; Sa se citeasca un numar n de la tastatura, apoi sa se citeasca mai multe cuvinte pana cand se citeste caracterul '#'. Sa se scrie intr-un fisier text toate cuvintele care au cel putin n vocale

segment data use32 class=data
    descriptor_fisier dd -1
    n dd 0
    stop equ '#'
    nume_fisier db 'output.txt', 0
    mod_acces db 'w', 0
    sir_vocale db 'aeiou*', 0
    len_vocale equ $-sir_vocale
    formats1 db '%u', 0
    formats2 db '%s', 0
    formatpf db '%s', 10, 0
    cuvant_curent resb 100
    nr_vocale_curent dd 0
    
segment code use32 class=code

    ; subprogram care verifica daca caracterul memorat de pe stiva este vocala (eax : bool)
    verifica_vocala:
        mov al, [esp+4]
        mov ecx, len_vocale
        mov edi, sir_vocale
        repeta1:
            scasb
        loopne repeta1
        cmp ecx, 0
        jna nu_e_vocala
        mov eax, 1
        jmp final
        nu_e_vocala:
            mov eax, 0
        final:
            ret
            
    start:
        push dword n
        push dword formats1
        call [scanf]
        add esp, 4*2
    
        push dword mod_acces
        push dword nume_fisier
        call [fopen]
        add esp, 4*2
        
        cmp eax, 0
        je sfarsit 
        
        mov [descriptor_fisier], eax
        
        repeta:
        mov dword [nr_vocale_curent], 0
        
        push dword cuvant_curent
        push dword formats2
        call [scanf]
        add esp, 4*2
        
        cmp byte [cuvant_curent], stop
        je sfarsit
        mov esi, cuvant_curent
        mov ecx, 100
        
        parcurge:
            lodsb
            cmp al, 0
            je final_cuvant
            movzx eax, al
            push eax
            call verifica_vocala
            add esp, 4
            add [nr_vocale_curent], eax
        loop parcurge
        
        final_cuvant:
            mov eax, [nr_vocale_curent]
            cmp eax, [n]
            jb repeta
            push dword cuvant_curent
            push dword formatpf
            push dword [descriptor_fisier]
            call [fprintf]
            
        jmp repeta
        
    sfarsit:
        push dword [descriptor_fisier]
        call [fclose]
        add esp, 4
        
        push dword 0
        call [exit]