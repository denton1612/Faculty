bits 32

global start

extern exit
import exit msvcrt.dll

; Se da un sir de cuvinte s. Sa se construiasca sirul de octeti d, astfel incat d sa contina pentru fiecare pozitie din s:
; - numarul de biti de 0, daca numarul este negativ
; - numarul de biti de 1, daca numarul este pozitiv

segment data use32 class=data
    s dw -22, 145, -48, 127
    l db ($ - s) / 2
    d db 0


segment code use32 class=code

    ; "subprogram" care calculeaza nr de biti de 1 din reprezentarea binara a unui numar
    
    nr_biti_1:
        add esp, 4
        pop ebx
        mov eax, 0
        .repeta:
            shl ebx, 1
            adc eax, 0
            cmp ebx, 0
            jnz .repeta
        sub esp, 8
        ret 
    start:
    
    ; vom parcurge fiecare numar din sirul s, vom verifica daca acesta este negativ, caz in care ii vom inversa toti bitii, dupa care apelam "subprogramul"
    ; nr_biti_1 si salvam rezultatul returnat in sirul d
        
        cld
        mov esi, s
        mov edi, d
        mov ecx, [l]
        repeta:
            mov eax, 0
            lodsw
            cmp ax, 0
            jg final
            not ax
            final:
            push eax
            call nr_biti_1
            add esp, 4
            stosb 
        loop repeta
        
    push dword 0
    call [exit]