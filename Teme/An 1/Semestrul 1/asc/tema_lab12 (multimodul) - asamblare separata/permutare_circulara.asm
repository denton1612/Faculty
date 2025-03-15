bits 32

global permutare_circulara
segment code use32 public code 

permutare_circulara:
    mov eax, [esp+4]
    mov ecx, [esp+8]
    ror eax, cl
    
    ret



