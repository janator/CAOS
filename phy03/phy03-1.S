	.data
format_1:
	.asciz "%d"
format_2:
	.asciz "%d\n"
num1:
	.word 0
num2:
	.word 0

	.text
	.global main
main:
	push {lr} 

	ldr r1, =num1
	ldr r0, =format_1
	bl scanf

	ldr r1, =num2
	ldr r0, =format_1
	bl scanf

	ldr r4, =num1 
	ldr r3, [r4] 

	ldr r4, =num2
	ldr r2, [r4]

	add r1, r2, r3

	ldr r0, =format_2
	bl printf

	pop {pc}