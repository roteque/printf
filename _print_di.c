#include <stdarg.h>
#include <stdio.h>
#include "main.h"

/**
 * Handles d and i specifiers
 * @const char: character to change
 * 
 * Return 0 (Success)
 */

void my_printf(const char *format, ...) {
    va_list args;
    va_start(args, format);

    while (*format) {
        if (*format == '%') {
            format++;

            if (*format == 'd' || *format == 'i') {
                int value = va_arg(args, int);
                printf("%d", value);
            } else {
                putchar('%');
                putchar(*format);
            }
        } else {
            putchar(*format);
        }

        format++;
    }

    va_end(args);
}
