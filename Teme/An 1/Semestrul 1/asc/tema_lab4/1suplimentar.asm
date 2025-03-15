bits 32 ; assembling for the 32 bits architecture

; declare the EntryPoint (a label defining the very first instruction of the program)
global start        

; declare external functions needed by our program
extern exit               ; tell nasm that exit exists even if we won't be defining it
import exit msvcrt.dll    ; exit is a function that ends the calling process. It is defined in msvcrt.dll
                          ; msvcrt.dll contains exit, printf and all the other important C-runtime specific functions

; our data is declared here (the variables needed by our program)
segment data use32 class=data
    ;Se dau cuvintele A si B. Se cere dublucuvantul C:
    ;bitii 0-3 ai lui C coincid cu bitii 5-8 ai lui B
    ;bitii 4-10 ai lui C sunt invers fata de bitii 0-6 ai lui B
    ;bitii 11-18 ai lui C sunt 1
    ;bitii 19-31 ai lui C coincid cu bitii 3-15 ai lui B

    a dw 0000_1111_0000_0101b
    b dw 1111_1010_0101_0000b
    c dd 0
; our code starts here
segment code use32 class=code
    start:
        mov ax, 0000000111100000b ; cream o masca pentru a extrage bitii 5-8 ai lui b
        and ax, [b] ; salvam bitii 5-8 ai lui b in ax
        mov cl, 5 ; mutam acei biti pe poz 0-3 (poz pe care o vor avea in c)
        shr ax, cl ; mutam acei biti pe poz 0-3 (poz pe care o vor avea in c) 
        or [c], ax ; punem bitii corespunzatori pe poz 0-3 in c
        mov ax, 1111111110000000b ; cream o masca pentru a extrage bitii 0-6 ai lui b, insa in loc de zerouri vom avea 1 (pentru ca bitii in c trebuie sa fie invers 
        or ax, [b] ; salvam bitii 0-6 ai lui b (in rest 1)
        not ax ; avem in ax bitii 0-6 inversati ai lui b
        mov cl, 4
        shl ax, 4
        or [c], ax ; punem bitii corespunzatori pe poz 4-10 in c
        mov eax, 0000000000001111111100000000000b
        or [c], eax
        mov ax, 1111111111111000b
        and ax, [b]
        or [c+2], ax
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
