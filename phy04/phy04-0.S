	.global summ
	.intel_syntax noprefix
	.text
	//summ(int N, int* A, int* B, int*R)
	//		edi		esi		edx	   ecx
summ:
	push ebp
	mov ebp, esp
	mov ecx, [ebp + 8]
	push ebx
.Loop:
	dec ecx
	mov eax, [ebp + 12] 
	mov ebx, [eax + 4 * ecx] //+A[k]
	mov eax, [ebp + 16]
	add ebx, [eax + 4 * ecx] //+B[k]
	mov eax, [ebp + 20]
	mov [eax + 4 * ecx], ebx
	inc ecx
	loop .Loop

	pop ebx

	pop ebp
	ret