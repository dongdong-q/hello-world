#include "uart.h"
int main(int a)
{
	uart_init();
	myputs("uart0 is printing ... \n\r");
	myputs("uart0 is printing ... \n\r");
if(a==0)
	myputs("write register ok \n\r");
else
	myputs("write register bad \n\r");

	while(1)
		{
			mygetc();
		}
	return 0;
}
