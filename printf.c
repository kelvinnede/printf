#define _GNU_SOURCE
#include "main.h"
#include <stdio.h>
#include <unistd.h>
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
		if ((*format == 'd' || *format == 'i'))
		{
			int num = va_arg(args, int);

			num_length = snprintf(num_str, sizeof(num_str), "%d", num);

			count += write(1, num_str, num_length);
			format++;
		}
		else if (*format == 'b')
		{
			unsigned int num = va_arg(args, unsigned int);

			print_binary(num);
			format++;
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

	int i;

	for (i = 0; i < size; i++)
	{
		binary[i] = num % 2;
		num /= 2;
	}

	for (i = size - 1; i >= 0; i--)
	{
		_putchar('0' + binary[i]);
	}

	_putchar('\n');
}

/**
 * _putchar - Write a character to the standard output (stdout).
 * @c: The character to write.
 *
 * Return: On success, 1 is returned. On error, -1 is returned.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

