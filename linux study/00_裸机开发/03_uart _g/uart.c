/* init uart */
#include "S3C2440.h"

void uart_init(void)
{
	/* GPH3=RXD GPH2=TXD */
	GPHCON &= ~(( 3<<4 )|(3<<6));
	GPHCON |= (( 2<<4 )|(2<<6));
	/* GPH2 GH3 PULL UP */
	GPHUP &= ~((1<<2)|(1<<3));

	/* bauderate 115200 */
	/* clock UBRDIVn = (int)( UART clock / ( buad rate x 16) ) –1 */
	UBRDIV0 = 26;

	/* DATALENGTH=8 STOPBIT=1 */
	ULCON0 &= ~(0b111);
	ULCON0 |= 0b11;

	/* clock = pclk = fclk/8 = 48M/8 */
	/* triger by interrupt */
	UCON0 &= ~((0b11<<10)|(0b1111));
	UCON0 |= 0b0101;
}

void myputc(char c)
{
	while (!(UTRSTAT0 & 0b10));
	UTXH0 =c;
}

void mygetc()
{
	char c;
	while(UTRSTAT0 & 0b1)
		{
			c = URXH0;
			myputc(c);
		}
}
void myputs(char *s)
{
	while(*s)
		{
			myputc(*s);
			s++;
		}
}





