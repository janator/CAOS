#include <asm/unistd_32.h>
	.intel_syntax noprefix
	.text
	.global _start
_start:
	push  ebp
	mov   ebp, esp
.while:
    mov   eax, __NR_read  
    mov   ebx, 0
    sub   esp, 4  
    mov   ecx, esp
    mov   edx, 1
    int   0x80
    add   esp, 4
    cmp   eax, 0
    je    .end


    mov   eax, __NR_write
    mov   ebx, 1
    sub   esp, 4
    mov   ecx, esp
    mov   edx, 1
    int   0x80
    add   esp, 4
    jmp .while

.end:
   pop   ebp
   mov   esp, ebp
   mov   eax, __NR_exit
   mov   ebx, 1
   int   0x80