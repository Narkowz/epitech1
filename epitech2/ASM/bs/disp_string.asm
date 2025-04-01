section .data
    fmt db "%s: %d", 10, 0   ; Format pour printf ("%s: %d\n")

section .text
    global disp_string
    extern printf
    extern my_strlen

disp_string:
    push rbp
    mov rbp, rsp

    mov rdi, rdi          ; Charger l'adresse de la chaîne en paramètre
    call my_strlen        ; Appeler my_strlen, résultat dans RAX

    mov rsi, rdi          ; Premier argument (string)
    mov rdx, rax          ; Deuxième argument (longueur)

    mov rdi, fmt          ; Format pour printf
    mov rax, 0            ; Indiquer que printf utilise des registres
    call printf           ; Appeler printf

    pop rbp
    ret
