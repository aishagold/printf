#include "main.h"
#include <stdarg.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>

/**
 * _putchar - prints a single character to standard output
 * @c: the character to print
 * Return: 1 on success
 * On error, return -1 and set erno appropriately
 */

int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * _printf - produces output according to a format
 * @format: character string with format specifier
 * Return: total no of characters printed(excluding null byte)
 */

int _printf(const char *format, ...)
{
	int totalchar = 0;
	va_list args;

	va_start(args, format);

	for (; *format != '\0'; format++)
	{
		if (*format != '%')
		{
			_putchar(*format);
			totalchar++;
		}
		else
		{
			format++;

			if (*format == 'c')
			{
				char c = va_arg(args, int);

				_putchar(c);
				totalchar++;
			}
			else if (*format == 's')
			{
			const char *str = va_arg(args, const char *);

				fputs(str, stdout);
				totalchar += strlen(str);
			}
			else if (*format == '%')
			{
				_putchar('%');
				totalchar++;
			}
		}
	}
	va_end(args);
	return (totalchar);
}
