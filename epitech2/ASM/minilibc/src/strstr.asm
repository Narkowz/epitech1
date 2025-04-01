;;
;; EPITECH PROJECT, 2025
;; strstr.asm
;; File description:
;; strstr
;;

section .text
    global strstr

strstr:
    mov rax, rdi
    test rsi, rsi
    jz .done
.loop:
    test byte [rax], 0
    jz .not_found
    push rax
    push rsi
.check:
    mov al, [rax]
    mov bl, [rsi]
    cmp bl, 0
    je .found
    cmp al, bl
    jne .next
    inc rax
    inc rsi
    jmp .check
.next:
    pop rsi
    pop rax
    inc rax
    jmp .loop
.found:
    pop rsi
    pop rax
    ret
.not_found:
    xor rax, rax
.done:
    ret
