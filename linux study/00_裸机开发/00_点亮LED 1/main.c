/* Author:jiang lanxing
 * light led by key
 * auto recognize boot from nand or nor */
#include "S3C2440.h"

int main()
{
	GPFCON &= ~((3<<8)|(3<<10)|(3<<12)|(3<<4)|3);
	GPFCON |=  ((1<<8)|(1<<10)|(1<<12));
	GPGCON &= ~(3<<6);

	while(1)
	{
		int key0 = GPFDAT&0x1; /* EINT0->LED4->GPF6 */
		int key2 = GPFDAT&0X4; /* EINT2->LED2->GPF5 */
		int key11 = GPGDAT&0X8; /* EINT11->LED10->GPF4 */
		if( key0 == 0 )
		{
			GPFDAT &= ~(1<<6);
		}
		else
		{
			GPFDAT |= (1<<6);	
		}
		if( key2 == 0 )
		{
			GPFDAT &= ~(1<<5);
		}
		else
		{
			GPFDAT |= (1<<5);	
		}
		if( key11 == 0 )
		{
			GPFDAT &= ~(1<<4);
		}
		else
		{
			GPFDAT |= (1<<4);	
		}
	}
	return 0;
}

