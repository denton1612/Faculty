bits 32

global maxim
extern len

segment data public data use32
    poz db -1
    max_poz db 0
    max db 0
    
segment code public code use32
    maxim:
        xor edx, edx ; aici vom salva suma octetilor maximali
        mov esi, [esp+8]
        mov edi, [esp+4]
        mov ecx, len
        repeta:
            push ecx
            mov ecx, 4
            mov byte [poz], -1
            mov byte [max_poz], 0
            verifica:
                lodsb
                inc byte [poz]
                cmp al, [max]
                jb ok
                mov [max], al
                mov bl, [poz]
                mov [max_poz], bl
                ok:
            loop verifica
            mov al, [max_poz]
            movzx eax, al
            add edx, [esi+eax]
            add al, '0'
            stosb
            mov byte [poz], -1
            mov byte [max_poz], 0
            pop ecx
        loop .repeta
        mov eax, edx ; in eax se va returna suma
        ret