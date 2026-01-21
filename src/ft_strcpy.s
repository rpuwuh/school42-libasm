
;char *strcpy(char *dest, const char *src);
; C implementation from man 3
; The strcpy() and strncpy() functions return a pointer to the destination string dest.
;strcpy(char *dest, const char *src)
;{
;    size_t i;
; 
;    for (i = 0; src[i] != '\0'; i++)
;        dest[i] = src[i];
;
;    dest[i] = '\0';
;    return dest;
;}

; RDI (char *dest), RSI (const char *src), RDX, RCX, R8, R9 - args, RAX - return value
; RDI - dest, RSI - src

global ft_strcpy
ft_strcpy:
    mov    rax, 0x00    ; move the error value (0) or initialization value as well

    ; note: this protection lines commented out because it should behaive like standard strcpy
    ;test   rdi, rdi             ; check if the pointer is null
    ;jz     .return          ; jump to .return if the pointer is null
    ;test    rsi, rsi             ; check if the pointer is null
    ;jz     .return          ; jump to .return if the pointer is null
    
    push   rdx
    mov    rdx, 0x0

.mainLoop:
    mov dl, byte [rsi + rax]    ; byte from s1
    
    cmp rdx, 0x0
    je .end
    
    mov    byte [rdi + rax], dl
    inc    rax          ; increment the counter
    jmp    .mainLoop

.end:
    mov    byte [rdi + rax], 0x00
    mov    rax, rdi
    pop    rdx

.return:
    ret ; return
