section .data
    message db "Hello, World!", 10  ; Chaîne avec un saut de ligne
    length equ $-message             ; Calcul de la longueur

section .text
    global _start

_start:
    ; Appel système write(1, message, length)
    mov rax, 1        ; syscall numéro 1 (write)
    mov rdi, 1        ; 1 = STDOUT
    mov rsi, message  ; Adresse du message
    mov rdx, length   ; Longueur du message
    syscall

    ; Appel système exit(0)
    mov rax, 60       ; syscall numéro 60 (exit)
    xor rdi, rdi      ; Code de retour 0
    syscall
