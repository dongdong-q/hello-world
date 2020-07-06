#include "init.h"
void copy2sdram(void)
{
extern int __code_start,__bss_start;
volatile unsigned int *dest = (volatile unsigned int *)&__code_start;
volatile unsigned int *end = (volatile unsigned int *)&__bss_start;
volatile unsigned int *src = (volatile unsigned int *)0;
while(dest<=end)
{
*dest++=*src++;
}

}
void clean_bss(void)
{
extern int __bss_start,__end;
volatile unsigned int *start = (volatile unsigned int *)&__bss_start;
volatile unsigned int *end = (volatile unsigned int *)&__end;

while(start<=end)
{
*start++=0;
}

}
