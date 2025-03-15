bits 32

global start
extern exit
import exit msvcrt.dll

segment data use32 class = data
 ;Se da un sir de dublucuvinte continand date impachetate (4 octeti scrisi ca un singur dublucuvant). Sa se obtina un nou sir de dublucuvinte, in care fiecare dublucuvant se va obtine dupa regula: suma octetilor de ordin impar va forma cuvantul de ordin impar, iar suma octetilor de ordin par va forma cuvantul de ordin par. Octetii se considera numere cu semn, astfel ca extensiile pe cuvant se vor realiza corespunzator aritmeticii cu semn.
 
s dd 127F5678h, 0ABCDABCDh, 0FFFFFFFFh
l equ ($-s)/4 ; lungimea sirului s (nr de dublucuvinte)
d times l dd 0

segment code use32 class = code
    start:
        mov ecx, l
        cld
        mov esi, s
        mov edi, d
        repeta1:
            lodsb ; in al vom avea octetul de ordin 0 al dw din sir
            cbw ; convertim octetul de ordin 0 la word
            mov bx, ax ; in bx vom stoca octetul de ordin 0 convertit la word
            lodsb ; in al vom avea octetul de ordin 1 al dw din sir
            cbw ; convertim octetul de ordin 1 la word
            mov dx, ax ; in dx vom stoca octetul de ordin 1 convertit la word 
            lodsb ; in al vom avea octetul de ordin 2
            cbw ; convertim octetul de ordin 2 la word
            add ax, bx ; primul word din dublucuvant (suma octetilor de ordin par)
            stosw ; vom stoca in cuvantul de ordin par (0) suma octetilor de ordin par 
            lodsb ; in al vom avea octetul de ordin 3 al dw din sir
            cbw ; convertim octetul de ordin 3 la word
            add ax, dx ; al doilea word din dublucuvant (suma octetilor de ordin impar)
            stosw ; vom stoca in cuvantul de ordin impar (1) suma octetilor de ordin impar
        loop repeta1
        
    push dword 0
    call [exit]