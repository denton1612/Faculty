bits 32 ; assembling for the 32 bits architecture

; declare the EntryPoint (a label defining the very first instruction of the program)
global start        

; declare external functions needed by our program
extern exit               ; tell nasm that exit exists even if we won't be defining it
extern scanf
extern printf
import scanf msvcrt.dll
import printf msvcrt.dll
import exit msvcrt.dll    ; exit is a function that ends the calling process. It is defined in msvcrt.dll
                          ; msvcrt.dll contains exit, printf and all the other important C-runtime specific functions

; our data is declared here (the variables needed by our program)
segment data use32 class=data
    format_s db '%s'
    s db 0
    ls db $ - s ; lungimea lui s
    d resb $ - s  ; rezervam pentru d ls octeti
    caractere_speciale db '!@#$%^&*'
    lcs db $ - caractere_speciale
    
; our code starts here
segment code use32 class=code
    start:
        push s
        push format_s
        call [scanf]
        cld
        mov ecx, [ls]
        jecxz sfarsit
        mov esi, s
        mov edi, d
        repeta:
            lodsb
            mov bl, al
            push ecx
            push esi
            mov ecx, [lcs]
            mov esi, caractere_speciale
            repeta1:
                lodsb
                cmp al, bl
            loopne repeta1
            mov al, bl
            jnz not_c_s
            c_s:
                stosb
            not_c_s:
            pop esi
            pop ecx      
        loop repeta
        sfarsit:
        mov al, '0'
        stosb 
        push dword [d]
        push format_s
        call [printf]
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program


