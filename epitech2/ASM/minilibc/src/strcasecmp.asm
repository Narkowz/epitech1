;;
;; EPITECH PROJECT, 2025
;; strcasecmp.asm
;; File description:
;; strcasecmp
;;

section .text
    global strcasecmp

strcasecmp:
.loop:
    mov al, byte [rdi]
    mov bl, byte [rsi]
    cmp al, 0
    je .done
    cmp al, 'A'
    jb .no_change
    cmp al, 'Z'
    ja .no_change
    add al, 32

.no_change:
    cmp bl, 'A'
    jb .compare
    cmp bl, 'Z'
    ja .compare
    add bl, 32

.compare:
    cmp al, bl
    jne .done
    inc rdi
    inc rsi
    jmp .loop

.done:
    xor eax, eax
    ret
