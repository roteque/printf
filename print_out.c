#include "main.h"

/**
 * _printf - is a function that selects the correct function to print.
 * @format: identifier to look for.
 * @c char specifier
 * @s string specifiers
 * @% modulus
 *
 * Return: the length of the string.
 **/

int _printf(const char *format, ...)
{	int char_count = 0;
	va_list list;

	if (format == NULL)
	return (-1);
	va_start(list, format);
	while (*format)
	{
	if (*format != '%')
	{
	write(1, format, 1);
	char_count++;
	}
	else
	{	format++;
	if (*format == '\0')
	break;
	if (*format == '%')
	{
	write(1, format, 1);
	char_count++;
	}
	else if (*format == 'c')
	{	char letter = va_arg(list, int);
	write(1, &letter, 1);
	char_count++;
	}
	else if (*format == 's')
	{char *str = va_arg(list, char*);
	int str_count = 0;

	while (str[str_count] != '\0')
	{str_count++;
	}	write(1, str, str_count);
	char_count = char_count + str_count;
	}
}
	format++;
}
	va_end(list);
	return (char_count);
}
