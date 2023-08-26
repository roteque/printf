#include "main.h"

/**
 * _printf - is a function that selects the correct function to print.
 * @format: identifier to look for.
 * @c char specifier
 * @s string specifiers
 * @% modulus*
 * Return: the length of the string.
 **/

int _printf(const char *format, ...)
{	int i, printed_char = 0, printed = 0, width, size, precision, buff_ind = 0, flags;
	va_list list;

	char buffer[BUFF_SIZE];

	if (format == NULL)
	return (-1);

	va_start(list, format);

	for (i = 0; format && format[i] != '\0'; i++)
	{
	if (format[i] != '%')
	{
		buffer[buff_ind++] = format[i];
		if (buff_ind == BUFF_SIZE)
			print_buffer(buffer, &buff_ind);
		printed_char++;
	}
	else
	{
		print_buffer(buffer, &buff_ind);
		flags = get_flags(format, &i);
		precision = get_precision(format, &i, list);
		size = get_size(format, &i);
		++i:
	}
	else
	{
		printed = handle_print(format, &i, list, buffer, flags, width, precision, size);
		if (printed == -1)
			return (-1);
		printed_chars += printed;
	}
	}
	print_buffer(buffer, &buff_ind);
	va_end(list);
	return (printed_char);
}


/**
 * print_buffer - prints the content of the biffer if it exits
 * @buffer: array of characters
 * @buff_ind: indext at which to add next character. represents th length
 */
void print_buffer(char buffer[], int *buff_ind)
{
	if (*buff_ind > 0)
		write(1, &buffer[0], *buff_ind);
	*buff_ind = 0;
}
