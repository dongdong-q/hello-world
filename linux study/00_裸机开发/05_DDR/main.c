#include "uart.h"
#include "sdram_init.h"
int main()
{
	uart_init();
	sdram_init();
	myputs("uart0 is printing ... \n\r");
	if(sdram_test()==0)
		myputs("sdram init is good \n\r");
	else
		myputs("sdram init error \n\r");
	while(1)
		{
			mygetc();
		}
	return 0;
}
