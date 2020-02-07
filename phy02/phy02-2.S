	.text
	.global solve
solve:
	push {r4, r5}
	mov r4, #-1

	b solve1
solve1:
	add r4, r4, #1
	mul r5, r0, r4 // Ax
	add r5, r5, r1 // Ax + B
	mul r5, r5, r4 // Ax^2 + Bx
	add r5, r5, r2 // Ax^2 + Bx + C
	mul r5, r5, r4 // Ax^3 + Bx^2 + Cx
	add r5, r5, r3 // Ax^3 + Bx^2 + Cx + D
	cmp r5, #0
	bne solve1
	mov r0, r4
	mov r1, r0
	pop {r4, r5}
	bx lr