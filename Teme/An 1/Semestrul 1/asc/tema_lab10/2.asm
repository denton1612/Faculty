bits 32
global start

extern exit, printf, fopen, fread, fclose
import exit msvcrt.dll
import printf msvcrt.dll
import fopen msvcrt.dll
import fread msvcrt.dll
import fclose msvcrt.dll

segment data use32 class=data
    ; Se da un fisier text. Sa se citeasca continutul fisierului, sa se contorizeze numarul de vocale si sa se afiseze aceasta valoare. Numele fisierului text este definit in segmentul de date.
    formatScriere db 'u'
    nr_vocale db 0
    fisier db "continut.txt", 0
    modalitate db "r", 0
    sir_vocale db "aeiouAEIOU"
    len_voc equ $-sir_vocale
    len equ 100
    descriptor_fisier dd -1
    text times len db 0
    
segment code use32 class=code
    start:
    ;deschidem fisierul 'continut.txt' pentru citire(r)
        push dword modalitate
        push dword fisier
        call [fopen]
        add esp, 8
        
    ;stocam descriptorul de fisier in memorie si trecem la sfarsitul programului daca a esuat deschiderea (eax=0)
        mov [descriptor_fisier], eax
        cmp eax, 0
        je final
        
    ;citim din fisier si salvam in memorie 
        push dword [descriptor_fisier]
        push dword len
        push dword 1
        push text
        call [fread]
        add esp, 4*4
        
    ;vom parcurge tot textul citit (lungimea 100) de la offset ul text, caracter cu caracter (byte cu byte), dupa care vom verifica daca caracterul curenta este vocala
    ;in caz afirmativ, incrementam valoarea de la offset ul nr_vocale, dupa care trecem la urmatorul caracter si tot asa
        mov ecx, len
        mov esi, text ; pregatim incarcarea in al a caracterelor
    
    ;parcurgem tot sirul de caractere
        repeta:
            push ecx
            mov ecx, len_voc ; pentru parcurgerea sirului de vocale
            lodsb 
            mov bl, al ; memoram in bl caracterul curent
            push esi
            mov esi, sir_vocale ; pregatim incarcarea in al a vocalelor 
            ; incarcam in al vocala curenta din sirul de vocale si verificam egalitatea caracterului curent din fisier cu aceasta
            verifica_voc:
                lodsb 
                cmp al, bl
            loopne verifica_voc ; ne oprim din loop cand caracterul curent este chiar o VOCALA
            pop esi
            cmp bl, 'U'
            je vocU
            cmp ecx, 0 ; daca ecx != 0, inseamna ca caracterul era o VOCALA (s-a oprit loop ul inainte de a ajunge la finalul sirului de voc => caracterul este VOCALA)
            je non_voc 
            vocU:
                inc byte [nr_vocale]
            non_voc: ; tratam cazul in care nu a fost vocala
            pop ecx
        loop repeta
        
        push dword [descriptor_fisier]
        call [fclose]
        add esp, 4
       
        push dword [nr_vocale]
        push dword formatScriere
        call [printf]
        add esp, 8
        
        final:
        push dword 0
        call [exit]
        
        