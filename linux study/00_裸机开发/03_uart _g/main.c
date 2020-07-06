#include "uart.h"
int main()
{
	uart_init();
	myputs("uart0 is printing ... \n\r");
	while(1)
		{
			mygetc();
		}
	return 0;
}
