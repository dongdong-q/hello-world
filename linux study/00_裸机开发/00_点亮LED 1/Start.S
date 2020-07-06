.text
.global _start

_start:
	mov r0,#0
	ldr r1,=0x53000000
	str r0,[r1] /* disable watchdog */
	
	ldr sp,=0x40000000+4096
	ldr r1,[r0] /* store [0] to r1 */
	mov r2,#1
	str r2,[r0]
	ldr r3,[r0]
	cmp r2,r3
	ldreq sp,=4096 /* boot from nand */
	streq r1,[r0]

	bl main

halt:
    b halt
