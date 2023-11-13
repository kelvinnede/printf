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
	int count = 0, num_length;
	char num_str[12];

	va_start(args, format);

	while (*format)
	{
		if (*format == '%' && (*(format + 1) == 'd' || *(format + 1) == 'i'))
		{
			num_length = snprintf(num_str, sizeof(num_str), "%d", va_arg(args, int));

			count += write(1, num_str, num_length);
			format += 2;
		}
		else if (*format == '%' && *(format + 1) == 'b')
		{
			unsigned int num = va_arg(args, unsigned int);

			print_binary(num);
			format += 2;
		}
		else if (*format == '%' && *(format + 1) == '%')
		{
			count += write(1, "%", 1);
			format += 2;
		}
		else
		{
			count += write(1, format++, 1);
		}
	}

	va_end(args);

	return (count);
}

/**
 * print_binary - Print binary representation of an unsigned integer.
 * @num: Unsigned integer to be printed in binary.
 */
void print_binary(unsigned int num)
{
	int size = sizeof(unsigned int) * 8;
	int binary[32];
	char binary_str[32];

	int i, count = 0;

	for (i = 0; i < size; i++)
	{
		binary[i] = num % 2;
		num /= 2;
	}

	for (i = size - 1; i >= 0; i--)
	{
		binary_str[count++] = binary[i] + '0';
	}

	binary_str[count] = '\0';

	write(1, binary_str, count);
}
