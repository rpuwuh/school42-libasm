;ssize_t read(int fd, void *buf, size_t count);

;syscall name	%rax	arg0 (%rdi)	   arg1 (%rsi)	   arg2 (%rdx)
;read		    0x00	int fd		   void *buf	   size_t count
; RDI, RSI, RDX, RCX, R8, R9 - args, RAX - return value

global ft_read
extern __errno_location

ft_read:
    mov rax, 0x00
    ;mov    rdi, rdi     ; fd - already setted up
    ;mov    rsi, rsi     ; buf - already setted up
    ;mov    rdx, rdx     ; count - already setted up
	syscall
    cmp rax, 0
    jl .error
	ret

.error:
    neg rax ; rax = -errno, abs value of errno
    push rax ; save errno
    call __errno_location wrt ..plt ; get errno location
    pop rcx ; restore errno
    mov [rax], rcx ; save errno
    mov rax, -1
    ret