section .text
    global my_strlen

my_strlen:
    mov rax, 0      ; Initialiser la longueur à 0
.loop:
    cmp byte [rdi + rax], 0   ; Vérifier si on atteint la fin de la chaîne
    je .done
    inc rax
    jmp .loop
.done:
    ret
