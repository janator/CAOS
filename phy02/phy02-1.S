	.text
	.global summ
summ:
	ldr r3, [r2]
	add r2, r2, #4
	sub r1, r1, #1
	add r0, r0, r3

	cmp r1, #0
	bgt summ

	mov r1, r0
	bx lr