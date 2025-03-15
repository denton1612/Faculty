bits 32

global start
extern exit, fopen, fread, fclose, printf
import exit msvcrt.dll
import fopen msvcrt.dll
import fread msvcrt.dll
import fclose msvcrt.dll
import printf msvcrt.dll

; Se da in segmentul de date numele unui fisier text. Acesta contine un text codificat care va trebui decodificat de program si sa fie afisat. (Mesajul a fost ascuns prin mutarea fiecarei litere cu 2 poz la dreapta ex. a -> c, y -> a, z -> b)

segment data use32 class=data
    nume_fiser db 'input.txt', 0
    mod_acces db 'r', 0
    descriptor dd -1
    caracter_curent db 0
    formatp db 'Mesajul original este: %s', 0
    continut_decodificat resb 200
    spatiu equ ' '
    punct equ '.'
    
segment code use32 class=code

    ; conventie cdecl
    decodificare:
        mov al, [esp+4]
        cmp al, 'a'
        jne nu_este_a
        mov al, 'y'
        jmp conversie
        nu_este_a:
        cmp al, 'b'
        jne nu_este_b
        mov al, 'z'
        jmp conversie
        nu_este_b:
        sub al, 2
        conversie:
        movzx eax, al
        
        ret
    
    start:
        push dword mod_acces
        push dword nume_fiser
        call [fopen]
        add esp, 4*2
        
        cmp eax, 0
        je final
        
        mov [descriptor], eax
        mov edi, continut_decodificat
        
        repeta:
            push dword [descriptor]
            push 1
            push 1
            push caracter_curent
            call [fread]
            add esp, 4*4
            
            cmp byte [caracter_curent], spatiu
            mov al, [caracter_curent]
            je final_repeta
            cmp byte [caracter_curent], punct 
            jne mai_departe
            stosb
            jmp afisare
            mai_departe:
            
            mov al, [caracter_curent]
            movzx eax, al
            push eax
            call decodificare
            add esp, 4
            
            final_repeta:
            stosb
        jmp repeta
        
        afisare:
        mov al, 0
        stosb
        push continut_decodificat
        push formatp
        call [printf]
        add esp, 4*2
        
        push dword [descriptor]
        call [fclose]
        add esp, 4
        
        final:
        push dword 0
        call [exit]