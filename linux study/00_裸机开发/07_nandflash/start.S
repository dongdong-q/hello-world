.text
.global _start

_start:

	/* 关闭看门狗 */
	ldr r0, =0x53000000
	ldr r1, =0
	str r1, [r0]

	/* 设置内存: sp 栈 */
	/* 分辨是nor/nand启动
	 * 写0到0地址, 再读出来
	 * 如果得到0, 表示0地址上的内容被修改了, 它对应ram, 这就是nand启动
	 * 否则就是nor启动
	 */
	mov r1, #0
	ldr r0, [r1] /* 读出原来的值备份 */
	str r1, [r1] /* 0->[0] */ 
	ldr r2, [r1] /* r2=[0] */
	cmp r1, r2   /* r1==r2? 如果相等表示是NAND启动 */
	ldr sp, =0x40000000+4096 /* 先假设是nor启动 */
	moveq sp, #4096  /* nand启动 */
	streq r0, [r1]   /* 恢复原来的值 */

	/* OM[2:3]=0b00 */
	/* LOCKTIME DEFAULT VALUE *(0X4C000000)=0xFFFFFFFF */
	ldr r0,=0xFFFFFFFF
	ldr r1,=0x4C000000
	str r0,[r1]

	/* 设置cpu异步模式和fast bus */
	mrc p15,0,r0,c1,c0,0 
 	orr r0,r0,#0xc0000000 /* #R1_nF:OR:R1_iA */ 
	mcr p15,0,r0,c1,c0,0

	/* 设置PLL for FCLK PCLK HCLK */
	/* 设置 CLKDIVN *(0x4C000014)=0x5 */
	/* HCLK=FCLK/4 PCLK=HCLK/2 */
	ldr r0,=0x5
	ldr r1,=0x4C000014
	str r0,[r1]

	/* MPLLCON 400MHZ *(0x4C000004)=0x0005c011 */
	/* MDIV=92 PDIV=1 SDIV=1 MPLL=400MHZ */
	/* 修改48MHZ 0x00038022 */
	ldr r0,=0x0005c011
	ldr r1,=0x4C000004
	str r0,[r1]

	/* CAMDIVN[9]=0 *(0x4C000018)=0x4*/
	ldr r0,=0x4
	ldr r1,=0x4C000018
	str r0,[r1]

	bl sdram_init

	/* 重定位text,rodata,data段 
	ldr r1, =data_load_addr  
	ldr r2, =data_start 	
	ldr r3, =data_end 	

cpy:
	ldr r4, [r1]
	str r4, [r2]
	add r1, r1, #4
	add r2, r2, #4
	cmp r2, r3
	ble cpy*/
/*
	ldr r0,=0x800
	ldr r1,=0x30000000
	ldr r2,[r0]
	str r2,[r1]*/
	bl copy2sdram

	/* 清除BSS段 
	ldr r1, =bss_start
	ldr r2, =bss_end
	mov r3, #0
clean:
	str r3, [r1]
	add r1, r1, #4
	cmp r1, r2
	ble clean*/
	bl clean_bss

	//bl main/* 使用BL命令相对跳转, 程序仍然在NOR/sram执行 */
	ldr pc,=main /* 绝对跳转, 跳到SDRAM */

halt:
	b halt
	


