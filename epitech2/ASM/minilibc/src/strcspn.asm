;;
;; EPITECH PROJECT, 2025
;; strcspn.asm
;; File description:
;; strcspn
;;

section .text
    global strcspn

strcspn:
    xor rax, rax
.loop:
    mov dl, [rdi]
    test dl, dl
    jz .done
    push rdi
    push rsi
.check:
    mov bl, [rsi]
    test bl, bl
    jz .next
    cmp dl, bl
    je .done
    inc rsi
    jmp .check
.next:
    pop rsi
    pop rdi
    inc rdi
    inc rax
    jmp .loop
.done:
    pop rsi
    pop rdi
    ret
