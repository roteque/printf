#include <limits.h>
#include <stdio.h>
#include "main.h"

/**
 * main - Entry point
 * @format: identifier to look for.
 * Return: Always 0
 */
int _printf(const char *format, ...);

int main(void)
{
	printf("Character:[%c]\n", 'H');
	printf("Character:[%c]\n", 'H');
	_printf("String:[%s]\n", "I am a string !");
	printf("String:[%s]\n", "I am a string !");
	_printf("Percent:[%%]\n");
	printf("Percent:[%%]\n");
	return (0);
}
