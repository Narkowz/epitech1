;;
;; EPITECH PROJECT, 2025
;; strchr.asm
;; File description:
;; strchr
;;

section .text
    global strchr

strchr:
    mov rax, rdi
.loop:
    cmp byte [rax], 0
    je .not_found
    cmp byte [rax], sil
    je .found
    inc rax
    jmp .loop
.found:
    ret
.not_found:
    mov rax, 0
    ret
