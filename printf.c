#define _GNU_SOURCE
#include "main.h"
#include <unistd.h>
#include <stdio.h>
#include <stdarg.h>

int _printf(const char *format, ...);
int print_binary(unsigned int num);

/**
 * _printf - Custom printf function.
 * @format: Format string containing format specifiers.
 *
 * Return: The number of characters printed.
 */
int _printf(const char *format, ...)
{
	va_list args;
	int count = 0, num_length;
	char c, *str = NULL, num_str[12];

	va_start(args, format);

	while (*format)
	{
		if (*format == '%' && (*(format + 1) == 'c' || *(format + 1) == 's'))
		{
			if (*(format + 1) == 'c')
				count += write(1, &c, 1);
			else
				str = va_arg(args, char *), count += write(1, str, 0);
			format += 2;
		}
		else if (*format == '%' && (*(format + 1) == 'd' || *(format + 1) == 'i'))
		{
			num_length = snprintf(num_str, sizeof(num_str), "%d", va_arg(args, int));

			count += write(1, num_str, num_length);
			format += 2;
		}
		else if (*format == '%' && *(format + 1) == 'b')
		{
			unsigned int num = va_arg(args, unsigned int);

			count += print_binary(num);
			format += 2;
		}
		else if (*format == '%' && *(format + 1) == '%')
		{
			count += write(1, "%", 1);
			format += 2;
		}
		else
			count += write(1, format++, 1);
	}

	va_end(args);

	return (count);
}

/**
 * print_binary - function to print binary representation an unsigned int.
 * @num: The unsigned int to be converted and printed.
 *
 * Return: The number of characters printed.
 */
int print_binary(unsigned int num)
{
	if (num / 2 != 0)
		print_binary(num / 2);

	char c = num % 2 + '0';

	return (write(1, &c, 1));
}
