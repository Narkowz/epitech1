;;
;; EPITECH PROJECT, 2025
;; strlen.asm
;; File description:
;; strlen
;;

section .text
    global strlen

strlen:
    mov rax, 0
.loop:
    cmp byte [rdi + rax], 0
    je .done
    inc rax
    jmp .loop
.done:
    ret
