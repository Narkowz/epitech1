;;
;; EPITECH PROJECT, 2025
;; memcpy.asm
;; File description:
;; memcpy
;;

section .text
    global memcpy

memcpy:
    mov rax, rdi
.loop:
    test rdx, rdx
    jz .done
    mov al, [rsi]
    mov [rdi], al
    inc rdi
    inc rsi
    dec rdx
    jmp .loop
.done:
    ret
