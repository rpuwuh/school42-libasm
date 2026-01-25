;size_t strlen(const char *s);

; RDI, RSI, RDX, RCX, R8, R9 - args, RAX - return value

global ft_strlen

ft_strlen:   ; implicit registers initialization
    mov    rax, 0x00    ; counter for the loop

    ;cmp    rdi, 0x00    ; check if the pointer is null, note: this lines commented out because it should behaive like standard strlen
    ;je     .return      ; jump to .return if the pointer is null, note: this lines commented out because it should behaive like standard strlen


.mainLoop:
    cmp    byte [rdi + rax], 0x00     ; check if the pointer is null
    je     .return                    ; jump to .L2 if the value is null
    inc    rax                        ; increment the counter
    jmp    .mainLoop                  ; jump to .mainLoop

.return:
    ret
