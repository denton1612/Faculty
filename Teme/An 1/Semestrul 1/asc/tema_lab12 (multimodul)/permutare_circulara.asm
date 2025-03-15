%ifndef  _PERMUTARE_CIRCULARA_ASM_ ; continuam daca _PERMUTARE_CIRCULARA_ASM_ este nedefinit
%define  _PERMUTARE_CIRCULARA_ASM_ ; si ne asiguram ca devine definit
permutare_circulara:
    mov eax, [esp+4]
    mov ecx, [esp+8]
    ror eax, cl
    
    ret

%endif

