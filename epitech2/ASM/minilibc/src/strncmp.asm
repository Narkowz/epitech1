;;
;; EPITECH PROJECT, 2025
;; strncmp.asm
;; File description:
;; strncmp
;;

section .text
    global strncmp

strncmp:
.loop:
    test rdx, rdx
    jz .done
    mov al, [rdi]
    mov bl, [rsi]
    cmp al, bl
    jne .done
    test al, al
    jz .done
    inc rdi
    inc rsi
    dec rdx
    jmp .loop
.done:
    sub al, bl
    movsx rax, al
    ret
