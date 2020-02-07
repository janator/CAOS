	.intel_syntax noprefix
	.text
	.global my_sin	
my_sin:
	push ebp
	mov ebp, esp
	sub esp, 8
	movsd xmm0, [ebp + 8]

	mov eax, -1
	cvtsi2sd xmm2, eax
	mulsd xmm2, xmm0
	mulsd xmm2, xmm0  // in xmm2 -x^2

	mov eax, 2
	cvtsi2sd xmm3, eax // xmm3 2

	movsd xmm4, xmm0
	mov eax, 1
	cvtsi2sd xmm5, eax

	mov ecx, 0
	movsd xmm1, xmm0 // xmm1 - answer
Loop:
	mulsd xmm4, xmm2
	divsd xmm4, xmm3
	addsd xmm3, xmm5 
	divsd xmm4, xmm3
	addsd xmm3, xmm5
	addsd xmm1, xmm4
	add ecx, 1
	cmp ecx, 10000
	jl Loop
	
	movsd  [ebp - 8], xmm1
	fld qword ptr [ebp - 8]
	
	mov esp, ebp
	pop	 ebp
	ret