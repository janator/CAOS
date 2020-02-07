	.intel_syntax noprefix
	.text
	.global dot_product
dot_product:
	push ebp
	mov ebp, esp
	mov eax, [ebp + 8]
	mov edx, 0
	cvtsi2ss xmm2, edx
L1:
	cmp eax, 4
	jl L2
	sub eax, 4
	mov edx, [ebp + 12]
	movups xmm0, [edx + 4 * eax]
	mov edx, [ebp + 16]
	movups xmm1, [edx + 4 * eax]
	dpps xmm0, xmm1, 0xF1
	addss xmm2, xmm0
	jmp L1
L2:
	cmp eax, 0
	jz L3
	dec eax
	mov edx, [ebp + 12]
	movss xmm0, [edx + 4 * eax]
	mov edx, [ebp + 16]
	movss xmm1, [edx + 4 * eax]
	mulss xmm0, xmm1
	addss xmm2, xmm0
	jmp L2
L3:
	movss [ebp - 4], xmm2
	fld dword ptr [ebp - 4]
	pop ebp
	ret