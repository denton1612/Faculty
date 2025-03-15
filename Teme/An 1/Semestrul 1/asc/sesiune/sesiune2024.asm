bits 32

global start
extern exit, printf
import exit msvcrt.dll
import printf msvcrt.dll

segment data use32 class=data
    sir db 'eu, tu.'
    len equ $-sir
    rez resb 200
    lungime dd 0
    format1 db '%d', 0
    format2 db '%s', 10, 0
    punct db '.'
    spatiu db ' '
    virgula db ','
    tabla db '0123456789', 0
    ok db 0
   
segment code use32 class=code
    numarBiti:
        xor eax, eax
        mov edx, [esp+4]
        mov ecx, 8
        repeta1:
            shr edx, 1
            adc eax, 0
        loop repeta1
        ret
    afisare:
        mov eax, [esp+4]
        mov ecx, 32
        repeta2:
            shl eax, 1
            jc este_1
            cmp byte [ok], 0
            je repeta2
            push 0
            push format1
            call [printf]
            add esp, 4
            jmp gata
            este_1:
            mov byte [ok], 1
            push 1
            push format1
            call [printf]
            add esp, 4
            gata:
        loop repeta2
        ret
    start:
        mov ecx, len
        mov esi, sir
        mov edi, rez
        mov ebx, tabla
        repeta:
            push ecx
            lodsb
            cmp al, [punct]
            jne nu_e_punct
            mov al, '!'
            stosb
            inc dword [lungime]
            jmp afara
            nu_e_punct:
            cmp al, [spatiu]
            jne nu_e_spatiu
            mul al
            shr ax, 8
            stosb
            jmp afara
            nu_e_spatiu:
            cmp al, [virgula]
            jne e_litera
            mov al, 0
            mov ebx, tabla
            executa:
                xlat
                stosb
                inc al
                inc dword [lungime]
                cmp al, 10
                jb executa
            jmp afara
            e_litera:
            movzx eax, al
            mov ebx, eax
            push eax
            call numarBiti
            add esp, 4
            test eax, 01h
            jz par
            ror bl, 1
            mov al, bl
            stosb 
            inc dword [lungime]
            jmp afara
            par:
            mov al, bl
            stosb
            inc dword [lungime]
            afara:
            pop ecx
        loop repeta
        
        push rez
        push format2
        call [printf]
        add esp, 8
        
        
        