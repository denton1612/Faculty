bits 32 ; assembling for the 32 bits architecture

; declare the EntryPoint (a label defining the very first instruction of the program)
global start        

; declare external functions needed by our program
extern exit               ; tell nasm that exit exists even if we won't be defining it
import exit msvcrt.dll    ; exit is a function that ends the calling process. It is defined in msvcrt.dll
                          ; msvcrt.dll contains exit, printf and all the other important C-runtime specific functions

; our data is declared here (the variables needed by our program)
; Se da un sir de caractere S. Sa se construiasca sirul D care sa contina toate literele mici din sirul S.
segment data use32 class=data
    s db 'a', 'A', 'b', 'B', '2', '%', 'x'
    l db $ - s
    d resb $ - s

; our code starts here
segment code use32 class=code
    start:
        mov ecx, [l]
        cld
        mov esi, s
        mov edi, d
        repeta:
            lodsb
            cmp al, 'a'
            jb sfarsit
            cmp al, 'z'
            ja sfarsit
            stosb
            sfarsit:
        loop repeta
    
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
