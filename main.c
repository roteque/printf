#include <limits.h>
#include <stdio.h>
#include "main.h"

/**
 * main - Entry point
 * @format: identifier to look for.
 * Return: Always 0
 */
int _printf(const char *format, ...);
int _printf_id(const char *format, ...);

int main(void)
{
	int len = 5, len2 = 7;
	
	_printf("Let's try to printf a simple sentence.\n");
	printf("Let's try to printf a simple sentence.\n");
	printf("Character:[%c]\n", 'H');
	printf("Character:[%c]\n", 'H');
	_printf("String:[%s]\n", "I am a string !");
	printf("String:[%s]\n", "I am a string !");
	_printf("Percent:[%%]\n");
	printf("Percent:[%%]\n");
	_printf("Len:[%d]\n", len);
        printf("Len:[%d]\n", len2);
	_printf("Length:[%d, %i]\n", len, len);
	printf("Length:[%d, %i]\n", len2, len2);

	return (0);
}
