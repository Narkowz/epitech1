;;
;; EPITECH PROJECT, 2025
;; strcmp.asm
;; File description:
;; strcmp
;;

section .text
    global strcmp

strcmp:
.loop:
    mov al, [rdi]
    mov bl, [rsi]
    cmp al, bl
    jne .done
    test al, al
    jz .done
    inc rdi
    inc rsi
    jmp .loop
.done:
    sub al, bl
    movsx rax, al
    ret
