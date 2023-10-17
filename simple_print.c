"include "main.h"

int print_from_to(char *start, char* stop, char *expect)
{
	int sum = 0;
	while (start <= stop)
		 {
			 if (start != expect)
				 sum += _putchar(*start);
			 start++;
		 }
	return (sum);
}
int print_rev(va_list ap, params_t *params)
{
	int len, sum = 0;
	char* str = va_arg(ap,char*);
	   
	if (str)
	{
		for (len = 0; *str; str++)
			len++;
		str--;
		for(; len > 0; len--, len--)
			sum += _putchar(*str);
	}
	return (sum);
}
