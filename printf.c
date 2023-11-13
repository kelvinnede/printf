#include "main.h"
#include <stdarg.h>
#include <unistd.h>

/**
 * _putchar - Write a character to stdout
 * @c: The character to print
 *
 * Return: 1 (success), -1 (error)
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * _puts - Write a string to stdout
 * @str: The string to print
 *
 * Return: Number of characters printed (excluding null byte)
 */
int _puts(char *str)
{
	int count = 0;

	while (*str)
	{
		count += _putchar(*str);
		str++;
	}

	return (count);
}

/**
 * _print_binary - Print the binary representation of an unsigned integer
 * @n: The unsigned integer to convert and print
 *
 * Return: Number of characters printed (excluding null byte)
 */
int _print_binary(unsigned int n)
{
	int count = 0;

	if (n / 2)
		count += _print_binary(n / 2);

	return (_putchar((n % 2) + '0') + count);
}

/**
 * _printf - Custom printf function
 * @format: Format string
 *
 * Return: Number of characters printed (excluding null byte)
 */
int _printf(const char *format, ...)
{
	va_list args;
	int count = 0;

	va_start(args, format);

	while (*format)
	{
		if (*format == '%' && (*(format + 1) == 'c' || *(format + 1) == 's' || *(format + 1) == '%' || *(format + 1) == 'b'))
		{
			format++; /* Move to the conversion specifier */
			switch (*format)
			{
				case 'c':
					count += _putchar(va_arg(args, int));
					break;
				case 's':
					count += _puts(va_arg(args, char *));
					break;
				case '%':
					count += _putchar('%');
					break;
				case 'b':
					count += _print_binary(va_arg(args, unsigned int));
					break;
				default:
					count += _putchar('%');
					count += _putchar(*format);
			}
		}
		else
		{
			count += _putchar(*format);
		}
		format++;
	}

	va_end(args);

	return (count);
}
