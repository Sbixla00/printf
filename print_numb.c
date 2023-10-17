#include "main.h"

int _isdigit(int c)
{
	return (c >= '0' && c <= '9');
}
int _strlen(char* s)
{
	int i = 0;
	while(*s++)
	{
		i++;
	}
	return (i);
}
int print_number(char *s, params_t *params)
{
	unsigned int i = _strlen(s);
	int neg = (!params->unsign && *s == '-');
	if (!params->precesion && *s == '0' && !s[1])
		s = "";
	if (neg)
	{
		s++;
		i--;
	}
	if (params->precesion != UINT_MAX)
		while(i++ < params->precesion)
			*--s = '0';
	if(neg)
		*--s = '-';
	if (!params->minus_flag)
		return (print_number_right_shift(s, params));
	else
		return (print_number_left_shift(s, params));
}
int print_number_right_shift (char *str, params_t *params)
{
	unsigned int n = 0, neg, neg2, i = _strlen(str);
	char pad_char = ' ';
	if (params->zero_flag && !params->minus_flag)
		pad_char = '0';
	neg = neg2 = (!params->unsign && *str == '-');
	if (neg && i < params->width && pad_char ==  '0'  && !params->minus_flag)
		str++;
	else
		neg = 0;
	if ((params->plus_flag && !neg2) ||
			(!params->plus_flag && params->space_flag && !neg2))
		i++;
	if (neg && pad_char == '0')
		n += _putchar('-');
	if (params->plus_flag && !neg2 && pad_char == == '0' && !params->unsign)
	{
		n += _putchar ('+');
	}
	else if (!params->plus_flag && params->space_flag && !neg2 &&
			!params->unsign && params->zero_flag)
		n += _putchar(' ');
	while (i++ < params->width)
		n += putchar (pad_char);
	if (neg && pad_char == ' ')
		n += _putchar('-');
	if (params->plus_flag && !neg2 && pad_char == && !params->unsign)
		n += _putchar('+');
	else if (!params->plus_flag && params->space_flag &&
			!params->unsign && !params->zero_flag)
		n += _putchar(' ');
	n += _puts (str);
	return (n);
}
int print_number_left_shift (char *str, params_t *params)
{
	unsigned int n = 0, neg, neg2, i = _strlen(str);
	char pad_char = ' ';
	if (params->zero_flag && !params->minus_flag)
		pad_char = '0';
	neg = neg2 = (!params->unsign && *str == '-');
	if (neg && i < params->width && pad_char == '0' && !params->minus_flag)
		str++;
	else 
		neg = 0;
	if (params->plus_flag && !neg2 && !params->unsign)
		n = _putchar('+'), i++;
	else if (params->space_flag && !neg2 && !params->unsign)
		n += _putchar(' '), i++;
	n += _puts(str);
	while (i++<params->width)
		n += _putchar(pad_char);
	return (n);
}
