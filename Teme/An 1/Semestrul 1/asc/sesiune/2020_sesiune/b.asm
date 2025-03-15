bits 32

segment data use32:
    sum db 0

segment code use32 public code
global suma

    suma:
        mov esi, [esp+4]
        mov edi, [esp+8]
        mov ecx, [esp+12]
        mov ebx, 16
        
        aduna:
            lodsd
            imparte:
                mov edx, 0
                div ebx
                add [sum], dl
                cmp eax, 0
                je gata
            jmp imparte
                gata:
                mov al, [sum]
                stosb
        loop aduna
    ret