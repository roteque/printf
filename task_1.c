#include "main.h"

/**
 * _printf_id - is a function that selects the correct function to print.
 * @format: identifier to look for.
 * @d integer specifier
 * @i integer specifiers
 *
 * Return: the length of the string.
 **/

int _printf_id(const char *format, ...)
{	int char_count = 0;
	va_list list;

	if (format == NULL)
	return (-1);
	va_start(list, format);
	while (*format)
	{
	if (*format != '%')
	{       write(1, format, 1);
	char_count++;
	}
	else
	{	format++;
	if (*format == '\0')
	break;
	else if (*format == 'd')
	{       int num = va_arg(list, int);
	char num_str[25];
	int num_len = snprintf(num_str, sizeof(num_str), "%d", num);

	write(1, num_str, num_len);
	char_count += num_len;
	}
	else if (*format == 'i')
	{       int num = va_arg(list, int);
	char num_str[25];
	int num_len = snprintf(num_str, sizeof(num_str), "%d", num);

	write(1, num_str, num_len);
	char_count += num_len;
	}
	else
	{
	write(1, format - 1, 2);
	char_count += 2;
	}
	}
	format++;
	}	va_end(list);
	return (char_count);
}
