#include <S3C2440.h>
void sdram_init(void)
{
	BWSCON=0x02000000;
	BANKCON6=0x00018001;
	REFRESH=0x008004f5;
	BANKSIZE=0x000000b7;
	MRSRB6=0x00000020;
}
int sdram_test(void)
{
	volatile unsigned char *p=(volatile unsigned char *)0x30000000;
	int i;
	for(i=0;i<100;i++)
		p[i]=0x41;
	for(i=0;i<100;i++)
		if(p[i]!=0x41)
			return -1;
	return 0;
}
