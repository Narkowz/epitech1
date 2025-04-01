;;
;; EPITECH PROJECT, 2025
;; strpbrk.asm
;; File description:
;; strpbrk
;;

section .text
    global strpbrk

strpbrk:
.loop:
    mov al, [rdi]
    test al, al
    jz .not_found
    push rdi
    push rsi
.check:
    mov bl, [rsi]
    test bl, bl
    jz .next
    cmp al, bl
    je .found
    inc rsi
    jmp .check
.next:
    pop rsi
    pop rdi
    inc rdi
    jmp .loop
.found:
    pop rsi
    pop rdi
    mov rax, rdi
    ret
.not_found:
    xor rax, rax
    ret
