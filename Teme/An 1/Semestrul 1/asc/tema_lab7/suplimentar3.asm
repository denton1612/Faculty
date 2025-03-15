bits 32

global start
extern exit
import exit msvcrt.dll

; Se da un sir de caractere S. Sa se construiasca sirul D care sa contina toate literele mici din sirul S.

segment data use32 class=data
    s db 'a', 'A', 'b', 'B', '2', '%', 'x'
    ls equ $-s
    d times ls db 0
    
segment code use32 class=code
    start:
        mov ecx, ls ; numarul de loop uri = lungimea sirului s (vom parcurge fiecare element din s)
        mov esi, 0 ; poz curenta in s
        mov edi, 0 ; poz curenta in d
        jecxz sfarsit
        repeta:
            cmp byte [s+esi], 'a'
            jnae out_of_interval
            cmp byte [s+esi], 'z'
            ja out_of_interval
                ; am verificat daca caracterul din s este in intervalul ['a', 'z']
            mov al, [s+esi]
            mov [d+edi], al
                ; daca este, atunci il vom introduce in d
            inc edi ; trecem pe poz urmatoare in d doar daca am introdus un nou caracter
            out_of_interval:
                inc esi ; daca caracterul nu era din intervalul ['a', 'z'], atunci doar treceam la caracterul urmator din s
        loop repeta
        sfarsit
        
            push dword 0
            call [exit]
                
            
            
            