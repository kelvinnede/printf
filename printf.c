#define _GNU_SOURCE
#include "main.h"
#include <unistd.h>
#include <stdio.h>
#include <stdarg.h>

/**
 * _printf - Custom printf function.
 * @format: Format string containing format specifiers.
 *
 * Return: The number of characters printed.
 */
int _printf(const char *format, ...)
{
		va_list args;
		int count = 0;
		char c;

		va_start(args, format);

		while (*format)
		{
			if (*format == '%' && *(format + 1) == 'c')
			{
				count += write(1, &c, 1);
			}
		}

		va_end(args);

		return (count);
}
