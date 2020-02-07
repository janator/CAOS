#include <asm/unistd_32.h>
	.intel_syntax noprefix
	.text
	.global _start
_start:
    mov   eax, __NR_write  
    mov   ebx, 1  
    mov   ecx, hello_ptr 
    mov   edx, 13 
    int   0x80  
    mov   eax, __NR_exit 
    int   0x80
	.data
hello:
    .string "Hello, World!"
hello_ptr:
    .long   hello