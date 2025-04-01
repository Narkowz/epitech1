;;
;; EPITECH PROJECT, 2025
;; memeset.asm
;; File description:
;; memset
;;

section .text
    global memset

memset:
    mov rax, rdi
    mov rcx, rdx
    mov rdx, rsi

.loop:
    test rcx, rcx
    jz .done
    mov byte [rdi], dl
    inc rdi
    dec rcx
    jmp .loop
.done:
    mov rax, rax
    ret
