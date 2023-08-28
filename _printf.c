#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include "main.h"

int _printf(const char *format, ...);

int main() {
    _printf("Character: %c\nString: %s\nPercentage: %%\nInteger (d/i): %d\nUnsigned Integer (u): %u\nOctal (o): %o\nHexadecimal (x): %x\nHexadecimal (X): %X\n",
            'A', "Hello, printf!", 123, 456, 789, 255, 255);

    return 0;
}

int _printf(const char *format, ...) {
    va_list args;
    va_start(args, format);

    int charCount = 0;
    const char *ptr = format;

    while (*ptr != '\0') {
        if (*ptr == '%') {
            ptr++;
            switch (*ptr) {
                case 'c': {
                    char c = va_arg(args, int);
                    putchar(c);
                    charCount++;
                    break;
                }
                case 's': {
                    char *s = va_arg(args, char *);
                    while (*s != '\0') {
                        putchar(*s);
                        s++;
                        charCount++;
                    }
                    break;
                }
                case '%': {
                    putchar('%');
                    charCount++;
                    break;
                }
                case 'd':
                case 'i': {
                    int num = va_arg(args, int);
                    char buffer[20];
                    sprintf(buffer, "%d", num);
                    char *str = buffer;
                    while (*str != '\0') {
                        putchar(*str);
                        str++;
                        charCount++;
                    }
                    break;
                }
                case 'u': {
                    unsigned int num = va_arg(args, unsigned int);
                    char buffer[20];
                    sprintf(buffer, "%u", num);
                    char *str = buffer;
                    while (*str != '\0') {
                        putchar(*str);
                        str++;
                        charCount++;
                    }
                    break;
                }
                case 'o': {
                    unsigned int num = va_arg(args, unsigned int);
                    char buffer[20];
                    sprintf(buffer, "%o", num);
                    char *str = buffer;
                    while (*str != '\0') {
                        putchar(*str);
                        str++;
                        charCount++;
                    }
                    break;
                }
                case 'x': {
                    unsigned int num = va_arg(args, unsigned int);
                    char buffer[20];
                    sprintf(buffer, "%x", num);
                    char *str = buffer;
                    while (*str != '\0') {
                        putchar(*str);
                        str++;
                        charCount++;
                    }
                    break;
                }
                case 'X': {
                    unsigned int num = va_arg(args, unsigned int);
                    char buffer[20];
                    sprintf(buffer, "%X", num);
                    char *str = buffer;
                    while (*str != '\0') {
                        putchar(*str);
                        str++;
                        charCount++;
                    }
                    break;
                }
                default:
                    putchar(*ptr);
                    charCount++;
            }
        } else {
            putchar(*ptr);
            charCount++;
        }
        ptr++;
    }

    va_end(args);
    return charCount;
}
Remember that the provided code is a simplified implementation of the _printf function and may not handle all possible edge cases or follow the exact behavior of the standard library printf function. For production use, it's recommended to use the standard library function.






