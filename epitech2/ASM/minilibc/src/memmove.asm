;;
;; EPITECH PROJECT, 2025
;; memmove.asm
;; File description:
;; memmove
;;

section .text
    global memmove

memmove:
    cmp rdi, rsi
    ja move_backward    ; Si dest > src, on copie de droite à gauche
    je done             ; Si dest == src, pas besoin de copier

move_forward:
    cld                 ; Direction forward
    mov rcx, rdx
    rep movsb
    jmp done

move_backward:
    add rsi, rdx        ; Pointe vers la fin de src
    add rdi, rdx        ; Pointe vers la fin de dest
    std                 ; Direction backward
    mov rcx, rdx
    dec rsi
    dec rdi
    rep movsb

done:
    cld                 ; Réinitialise la direction
    ret
