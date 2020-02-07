#include <asm/unistd_32.h>
	 .intel_syntax noprefix
    .text
    .global _start

_start:
	pop ebp
	mov ebp, esp
	mov   eax, __NR_brk
	mov   ebx, 0
	int   0x80

	mov   edi, eax
	mov   esi, eax
	mov   eax, 1
	mov   [ebp + 8], eax
	inc   edi
	mov   eax, __NR_brk
    mov   ebx, edi
    int   0x80
	dec   edi
	mov   eax, 10
    mov   [edi], eax
    inc   edi

while:
	add   edi, 1024
	mov   eax, __NR_brk
	mov   ebx, edi
	int   0x80
	sub   edi, 1024
	mov   eax, __NR_read
	mov   ebx, 0
	mov   ecx, edi
	mov   edx, 1024
	int   0x80
	add   edi, 1024
	add   [ebp + 8], eax
	cmp   eax, 1024
	jz    while

	mov   edi, 0
	mov   ecx, [ebp + 8]

print:
	mov   [ebp + 12], ecx
	dec   ecx
	inc   edi
	cmp   ecx, 0
	jz    endl
	mov   al, [esi + ecx]
	cmp   al, 10
	jnz   end
endl:
	mov   eax, __NR_write
	mov   ebx, 1
	add   ecx, esi
	mov   edx, edi
	int   0x80
	mov   edi, 0

end:
	mov   ecx, [ebp + 12]
	loop  print
	mov   eax, __NR_brk
	mov   ebx, esi
	int   0x80
	pop   ebp
	mov   esp, ebp
	mov   eax, __NR_exit
	mov   ebx, 1
	int   0x80