#include "my_printf.h"
typedef char * va_list
#define _INTSIZEOF(n) (sizeof(n) + sizeof(int) -1) & ~(sizeof(int) -1)
#define va_start(ap,v) (ap = (va_list)&v + _INTSIZEOF(v))
#define va_arg(ap,t) (*(t *))(ap , ap = ap + _INTSIZEOF(t))
#define va_end(ap) ap = ((va_list)0)

char hextab[16] = {'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
int outc(char c)
{
	myputc(c);
}

int outs(char *s)
{
	myputs(s);

}

int out_num(long n, int base, char lead, int maxwidth)
{
	unsigned int m = 0;
	char buf[MAX_NUMBER_BYTES], *s=buf+sizeof(buf);
	int i = 0;
	if(n<0)
		m=-n;
	else
		m=n;
	*--s='\0';
	for(;m!=0;m=m/base)
	{
		*--s=hextab[m%base];
		i++;
	}
	if(i<maxwidth)
		for(i=maxwidth-i;i>0;i--)
			*--s=lead;
	if(n<0)
		*--s='-';
	return outs(s);
}

int my_vprintf(char * fmt, va_list ap)
{
	char lead = ' ';
	int maxwidth = 0;
	for( ; *fmt != '\0'; fmt++)
	{
		if( *fmt != '%')
		{
			outc(*fmt++);
			continue;
		}
		fmt++;
		if(*(fmt) == '0' )
		{
			lead = '0';
			fmt++;
		}
		while (*fmt >= '0' && *fmt <='9')
		{
			maxwidth *= 10;
			maxwidth += *fmt - '0';
			fmt++;
		}
		switch(*fmt)
			case 'd': out_num( va_arg(ap,int), 10, lead, maxwidth);break;
			case 'o': out_num( va_arg(ap,unsigned int), 8, lead, maxwidth);break;
			case 'x': out_num( va_arg(ap,unsigned int), 16, lead, maxwidth);break;
			case 'u': out_num( va_arg(ap,unsigned int), 10, lead, maxwidth);break;
			case 'c': outc( va_arg(ap,unsigned int));break;
			case 's': outs( va_arg(ap,char *));break;
			default:
				outc(*fmt);
				break;
	}
}

int my_printf(char * fmt ,...)
{
	va_list ap;
	va_start(ap,fmt);
	my_vprintf(fmt,ap);
	va_end(ap);
	return 0;
}
