.intel_syntax noprefix
.text
.global mergesort
merge:
        push    ebp
        mov     ebp, esp
        mov eax, 0
        mov [ebp - 4], eax // ebp - 4 --- it1, in --- ebp + 16
        mov eax, 0
        mov [ebp - 8], eax // ebp - 8 --- it2, out --- ebp + 20
        // mid = (from + to) / 2;
        mov eax, [ebp + 8]
        add eax, [ebp + 12]
        shr eax, 1
        mov [ebp - 12], eax  // ebp - 12 --- middle
        
        jmp     .L2

.L2:
	// while (from + it1 < mid) && (mid + it2 < to)
        mov     edx, [ebp + 8]  // from
        add     edx, [ebp - 4]	 // +it1
        cmp     [ebp - 12], edx
        jle     .L6
        mov     edx, [ebp - 12] // mid
        add     edx, [ebp - 8]  // +it2

        cmp     [ebp + 12], edx
        jg      .L5
        jmp 	.L6

.L5:
        mov     edx, [ebp + 8]  // from
        add     edx, [ebp - 4]	 // +it1
        mov 	 eax, [ebp + 16] // *in
        mov 	 eax, [eax + 4 * edx] // in[from + it1]
	 	mov     edx, [ebp - 12] // mid
        add     edx, [ebp - 8]  // +it2
        mov 	 ecx, [ebp + 16]
        mov 	 ecx, [ecx + 4 * edx] // in[mid + it2]
        cmp 	 eax, ecx

        jge 	 .L3
        mov      edx, [ebp + 8]  // from
        add      edx, [ebp - 4]	 // +it1
        mov 	 ecx, edx
        add 	 edx, [ebp - 8]	 // +it2
        mov 	 eax, [ebp + 16] // *in
        mov 	 eax, [eax + 4 * ecx]
        mov 	 ecx, [ebp + 20] // *out
        mov 	 [ecx + 4 * edx], eax
        mov 	 eax, [ebp - 4]
        inc 	 eax // ++it1
        mov 	 [ebp - 4], eax
        jmp     .L2
.L3:
        mov     edx, [ebp + 8]  // from
        add     edx, [ebp - 4]	 // +it1
        add 	 edx, [ebp - 8]	 // +it2
        mov 	 ecx, [ebp - 12] // mid
        add 	 ecx, [ebp - 8]  // +it2
        mov 	 eax, [ebp + 16] // *in
        mov 	 eax, [eax + 4 * ecx]
        mov 	 ecx, [ebp + 20] // *out
        mov 	 [ecx + 4 * edx], eax  
        mov 	 eax, [ebp - 8]
        inc 	 eax  //++it2
        mov 	 [ebp - 8], eax

        jmp     .L2

.L6:
        mov     edx, [ebp + 8]
        add     edx, [ebp - 4] // from + it1
        cmp     edx, [ebp - 12]
        jl      .L7   
        jmp 	.L8     

.L7:
        mov      edx, [ebp + 8]  // from
        add      edx, [ebp - 4]	 // +it1
        mov 	 ecx, edx
        add 	 edx, [ebp - 8]	 // +it2
        mov 	 eax, [ebp + 16] // *in
        mov 	 eax, [eax + 4 * ecx]
        mov 	 ecx, [ebp + 20] // *out
        mov 	 [ecx + 4 * edx], eax
        mov 	 eax, [ebp - 4]
        inc 	 eax // ++it1
        mov 	 [ebp - 4], eax
        jmp 	 .L6

.L8:
        mov     edx, [ebp - 12]
        add     edx, [ebp - 8] // mid + it2
        cmp     [ebp + 12], edx
        ja      .L9
        jmp 	.L10

.L9:


        mov     edx, [ebp + 8]  // from
        add     edx, [ebp - 4]	 // +it1
        add 	 edx, [ebp - 8]	 // +it2
        mov 	 ecx, [ebp - 12] // mid
        add 	 ecx, [ebp - 8]  // +it2
        mov 	 eax, [ebp + 16] // *in
        mov 	 eax, [eax + 4 * ecx]
        mov 	 ecx, [ebp + 20] // *out
        mov 	 [ecx + 4 * edx], eax
        mov 	 eax, [ebp - 8]
        inc 	 eax  //++it2
        mov 	 [ebp - 8], eax
        jmp     .L8

.L11:
        mov 	eax, [ebp + 8]  // from
        mov 	ecx, [ebp + 20]  // *out
        mov 	ecx, [ecx + 4 * eax]  // out[from]
        mov 	edx, [ebp + 16] // *in       
        mov 	[edx + 4 * eax], ecx
        mov 	eax, [ebp + 8] // ++from
        inc 	eax
        mov 	[ebp + 8], eax
.L10:
        mov 	eax, [ebp + 8]
        cmp 	eax, [ebp + 12]
        jb 		.L11
        mov 	esp, ebp
        pop     ebp
        ret

 mergesort:
        push    ebp
        mov     ebp, esp
        mov     eax, [ebp + 8]
        inc     eax  // from + 1
        cmp     [ebp + 12], eax
        jle     .L15
        // mid = (from + to) / 2
        mov edx, [ebp + 8]
        add edx, [ebp + 12]
        shr edx, 1

        mov     eax, [ebp + 20]  // *out
        push 	eax
        mov     eax, [ebp + 16]  // *in
        push	eax
        push	edx   // mid
        mov 	eax, [ebp + 8]  // from
        push 	eax
        call    mergesort

        mov edx, [ebp + 8]
        add edx, [ebp + 12]
        shr edx, 1
        mov     eax, [ebp + 20]  // *out
        push 	eax
        mov     eax, [ebp + 16]  // *in
        push	eax
        mov     eax, [ebp + 12]   // to
        push 	eax
        push    edx   // mid
        call    mergesort

        mov    eax, [ebp + 20]  // *out
        push 	eax
        mov     eax, [ebp + 16]  // *in
        push	eax
        mov     eax, [ebp + 12]   // to
        push 	eax
        mov     eax, [ebp + 8]   // from
        push	eax
        call    merge
.L15:
		mov esp, ebp
        pop ebp
        ret
       
metka:
	.string "%d/n"