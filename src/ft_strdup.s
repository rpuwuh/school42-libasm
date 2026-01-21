;char *strdup(const char *s); // we can call malloc

global ft_strdup
extern  __errno_location
extern malloc
extern free
extern ft_strlen
extern ft_strcpy

;void *malloc(size_t size);
; RAX - return value
; RDI, RSI, RDX, RCX, R8, R9 - args,

ft_strdup:
    push    rdi ; save input string in rsi to call ft_strcpy later

    call    ft_strlen ; now length is in RAX
    inc     rax ; add 1 to length to allocate memory for null terminator
    
    mov     rdi, rax ; save length in rdi
    call    malloc ; allocate memory
    pop     rsi ; restore input string, wich was saved in stack from rdi
    cmp     rax, 0 ; check if malloc failed
    je      .error ; jump to .error if malloc failed

    mov     rdi, rax ; save pointer to allocated memory in rdi
    call    ft_strcpy ; copy string
    ret


.error:
    neg rax ; rax = -errno, abs value of errno
    push rax ; save errno
    call __errno_location wrt ..plt ; get errno location
    pop rcx ; restore errno
    mov [rax], rcx ; save errno
    mov rax, 0x0
    ret
