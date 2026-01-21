;int strcmp(const char *s1, const char *s2);
; RDI, RSI, RDX, RCX, R8, R9 - args, RAX - return value

global ft_strcmp

ft_strcmp:   ; implicit registers initialization
    mov    rax, 0x00    ; move the error value (0) or initialization value as well
    ;test   rdi, rdi             ; check if the pointer is null, note: this lines commented out because it should behaive like standard strcmp
    ;jz     .return          ; jump to .return if the pointer is null, note: this lines commented out because it should behaive like standard strcmp
    ;test    rsi, rsi             ; check if the pointer is null, note: this lines commented out because it should behaive like standard strcmp
    ;jz     .return          ; jump to .return if the pointer is null, note: this lines commented out because it should behaive like standard strcmp
    
    push   rdx
    push   rcx
    mov   rdx, 0x0
    mov   rcx, 0x0

.mainLoop:
    mov dl, byte [rdi + rax]    ; byte from s1
    mov cl, byte [rsi + rax]    ; byte from s2
    
    cmp rdx, rcx
    jne .end
    test rdx, rdx
    jz .end
    inc    rax          ; increment the counter
    jmp    .mainLoop

.end:
    mov    rax, rdx
    sub    rax, rcx
    pop    rcx
    pop    rdx

.return:
    ret ; return
