;ssize_t write(int fd, const void *buf, size_t count);

;syscall name	%rax	arg0 (%rdi)        arg1 (%rsi)	    arg2 (%rdx)
;write      	0x01	unsigned int fd	   const char *buf	size_t count
; RDI, RSI, RDX, RCX, R8, R9 - args, RAX - return value

global ft_write
extern __errno_location

;section .text
ft_write:   ; implicit registers initialization
    mov    rax, 0x01    ; syscall number (i.e. write)
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
