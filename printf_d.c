#define _GNU_SOURCE
#include "main.h"
#include <unistd.h>
#include <stdarg.h>

/**
 * _printf_d - Handle %d and %i conversion specifiers.
 * @args: Variable arguments.
 *
 * Return: The number of characters printed.
 */
int _printf_d(va_list args)
{
	int count = 0;
	int num = va_arg(args, int);
	char num_str[12];

	int num_length = snprintf(num_str, sizeof(num_str), "%d", num);

	count += write(1, num_str, num_length);

	return (count);
}

