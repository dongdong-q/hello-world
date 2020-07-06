#include "uart.h"
#include "sdram_init.h"

void delay(int  i)
{
	for(;i--;i>0);
}

char g_char='a';
char g_char3='A';
const char g_char2='B';
int g_A=0;
int g_B;

int main()
{
	uart_init();
	myputs("uart0 is printing ... \n\r");
	/*sdram_init();
	myputs("uart0 is printing ... \n\r");
	if(sdram_test()==0)
		myputs("sdram init is good \n\r");
	else
		myputs("sdram init error \n\r");*/
	while(1)
		{
			myputc(g_char++);
			myputc(g_char3++);
			delay(1000000);
			//mygetc();
		}
	return 0;
}

