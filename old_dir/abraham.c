#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>

/**
 * _printf - Custom printf function.
 * @format: Format specifier string.
 *
 * Return: Number of characters printed (excluding null byte).
 */
int _printf(const char *format, ...)
{
	va_list args;
	int count = 0;
	const char *ptr;
	char buffer[1024];

	va_start(args, format);

	for (ptr = format; *ptr; ptr++)
	{
		if (*ptr == '%' && ptr[1])
		{
			ptr++;
			switch (*ptr)
			{
				case 'c':
					count += _putchar(va_arg(args, int));
					break;
				case 's':
					count += _puts(va_arg(args, char *));
					break;
				case 'd':
				case 'i':
					count += _print_number(va_arg(args, int));
					break;/* Add more cases for other conversion specifiers */
				default:
					_putchar('%');
					_putchar(*ptr);
					count += 2;
			}
		}
		else
		{
			_putchar(*ptr);
			count++;
		}
	}

	va_end(args);

	return (count);
}

/**
 * _putchar - Writes a character to stdout.
 * @c: The character to print.
 *
 * Return: 1 on success, -1 on error.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * _puts - Writes a string to stdout.
 * @s: The string to print.
 *
 * Return: The number of characters printed.
 */
int _puts(const char *s)
{
	int count = 0;

	while (*s)
	{
		_putchar(*s);
		s++;
		count++;
	}

	return (count);
}

/**
 * _print_number - Prints an integer to stdout.
 * @n: The integer to print.
 *
 * Return: The number of digits printed.
 */
int _print_number(int n)
{
	int count = 0;
	char buffer[20];
	int i = 0;

	if (n < 0)
	{
		_putchar('-');
		count++;
		n = -n;
	}

	if (n == 0)
	{
		_putchar('0');
		return (1);
	}

	while (n != 0)
	{
		buffer[i++] = n % 10 + '0';
		n /= 10;
	}

	while (--i >= 0)
	{
		_putchar(buffer[i]);
		count++;
	}

	return (count);
}
