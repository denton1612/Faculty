bits 32

global start
extern exit
import exit msvcrt.dll

 ; Se da un sir de octeti S. Sa se obtina in sirul D multimea elementelor din S.
 
segment data use32 class=data
    s db 1, 4, 2, 4, 8, 2, 1, 1
    ls equ ls-s
    d times ls db 0
    ld db 0
    
segment code use32 class=code
    mov ecx, ls-1
    mov ebx, ecx
    mov esi, 0
    mov edi, 0
    mov al, [s+esi]
    mov [d+edi], al
    inc esi
    inc byte [ld]
    
    repeta1:
        mov al, [s+esi]
        mov ecx, 
        repeta2:
            cmp al, [d+edi]
            inc edi
        loopne