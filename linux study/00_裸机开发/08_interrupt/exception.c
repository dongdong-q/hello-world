#include "my_printf.h"
void printException(unsigned int cpsr , char * str)
{
	my_printf("Exception! cpsr = %x str = %s \n\r",cpsr,str);

}
