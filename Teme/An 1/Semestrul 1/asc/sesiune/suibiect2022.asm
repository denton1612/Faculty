bits 32

global start
extern exit, printf
import exit msvcrt.dll
import printf msvcrt.dll

segment data use32 class=data
    s1 dw 12abh, 34cdh, 56efh
    s2 dw 3500h, 0011h, 7ffbh
    len equ (s2-s1)/2
    s3 times len dd 0
    sir_afisare times 33*len db 0
    format db '%s', 0
    sortat dd 1
    index dd 0
    
segment code use32 class=code
    nr_biti_1:
        mov edx, [esp+4]
        mov ecx, 32
        xor eax, eax
        repeta:
            shl edx, 1
            adc eax, 0
        loop repeta
        ret
    
    afisare_in_baza_2:
        mov edx, [esp+4]
        mov ecx, 32
        xor al, al
        roteste:
            shl edx, 1
            adc al, '0'
            stosb
            xor al, al
        loop roteste
        ret
        
    start:
        mov esi, s1
        mov ebx, s2
        mov edi, s3
        mov ecx, len
        muta:             ; loop ul acesta creeaza sirul de dd s3 formate din word urile de la aceeasi pozitie din s1 si s2
            movsw
            push esi
            mov esi, ebx
            movsw
            mov ebx, esi
            pop esi
        loop muta
        mov ecx, len
        mov esi, s3
        parcurge:
            ; voi sorta folosind bubble sort
            push ecx
            compara:
                lodsb
                movzx eax, al ; voi extinde octetul de la poz i din s3 in eax (fara semn pt a nu influenta nr de biti de 1)
                push eax
                call nr_biti_1
                add esp, 4
                mov ebx, eax ; ebx va retine nr de biti de 1 din octetul de la poz i din s3
                lodsb
                movzx eax, al ; voi extinde octetul de la poz i+1 din s3 in eax voi
                push eax
                call nr_biti_1 ; eax va retine nr de biti de 1 din octetul de la poz i+1 din s3
                add esp, 4
                cmp ebx, eax
                jb ok
                mov dl, [esi-1] ; dl contine octetul de pe poz i+1 din s3
                cmp byte [esi-2], dl
                jle ok
                mov dword [sortat], 0 ; daca ebx !< eax, atunci sirul nu este sortat
                cmp ebx, eax
                ja interschimba ; daca ebx > eax, atunci trebuie interschimbati octetii
                mov dl, [esi-1] ; dl contine octetul de pe poz i+1 din s3
                cmp byte [esi-2], dl
                jle ok
                mov bl, [esi-2]
                mov [esi-2], dl
                mov [esi-1], bl
                jmp ok
                interschimba:
                mov dl, [esi-1]
                mov bl, [esi-2]
                mov [esi-2], dl
                mov [esi-1], bl
                ok:
                dec esi ; pentru ca in al sa se incarce octetul de la poz i+1 din s3, nu i+2
                push esi
                sub esi, s3
                push esi
                pop ax
                pop dx
                mov bx, 4
                div bx
                cmp dx, 3
                pop esi
                jb compara
                cmp dword [sortat], 0
                ja afara
                mov dword [sortat], 1 
                sub esi, 3
            jmp compara
            afara:
            inc esi
            pop ecx
            parcurge1:
                jmp parcurge
        loop parcurge1
        
        ; ajunsi in punctul asta, sirul de dd s3 are dd urile construite conform cerinteti
        ; este nevoie doar sa il mai afisam in baza 2
        
        mov esi, s3
        mov edi, sir_afisare
        mov ecx, len
        construieste:
            push ecx
            lodsd
            push eax
            call afisare_in_baza_2
            mov eax, '|'
            stosd
            pop ecx
        loop construieste
        mov al, 0
        stosb 
        push sir_afisare
        push format
        call [printf]
        add esp, 8
        
        
    