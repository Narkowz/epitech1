;;
;; EPITECH PROJECT, 2025
;; strrchr.asm
;; File description:
;; strrchr
;;

section .text
    global strrchr

strrchr:
    mov rax, 0
    mov rcx, rdi
.loop:
    cmp byte [rdi], 0
    je .done
    cmp byte [rdi], sil 
    jne .next
    mov rax, rdi
.next:
    inc rdi
    jmp .loop
.done:
    ret
