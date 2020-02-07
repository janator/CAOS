	.text
	.global main
main:
	push  {r4, r5, r6, lr}
	mov   r0, #0
	mov   r1, #100
	bl    realloc
	mov   r4, r0  
	mov   r5, #10
	mov   r6, #0

read:
	ldr   r0, =stdin
	ldr   r0, [r0]
	bl    fgetc
	cmp   r0, #-1
	beq   write
	cmp   r0, #32
	blo   read
	cmp   r0, #127
	bcs   read
	strb  r0, [r4, r6]
	add   r6, r6, #1
	cmp   r5, r6
	beq   resize
	b     read
write:
    cmp   r6, #0
    beq   end
    ldr   r1, =stdout
    ldr   r1, [r1]
    sub   r6, r6, #1
    ldrb  r0, [r4, r6]
    bl    fputc
    b     write

resize:
    mov   r0, #5
    mul   r1, r0, r5
    mov   r0, r4
    mov   r5, r1
    bl    realloc
    mov   r4, r0
    b     read

end:
	mov   r0, r4
	bl    free
	pop {r4, r5, r6, lr}
	bx lr