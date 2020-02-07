	.text
	.global main
main:
	push {lr} 	

while:
	ldr r0, =stdin
	ldr r0, [r0]
	bl fgetc

	cmp r0, #-1
	beq end

	cmp r0, #48
	blt while

	cmp r0, #57
	bhi while

	ldr r1, =stdout
	ldr r1, [r1]
	bl fputc

	b while
end:

	pop {lr}
	bx lr