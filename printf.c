#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>

/**
 * _printf - Custom printf function
 * @format: Format string
 *
 * Return: Number of characters printed (excluding the null byte)
 */
int _printf(const char *format, ...)
{
	va_list args;
	int count = 0;

	va_start(args, format);

	while (*format)
	{
		if (*format == '%' && *(format + 1))
		{
			format++;
			switch (*format)
			{
				case 'c':
					count += write(1, &va_arg(args, int), 1);
					break;
				case 's':
					count += write(1, va_arg(args, char*), 0);
					break;
				case 'd':
				case 'i':
					count += dprintf(1, "%d", va_arg(args, int));
					break;
				case '%':
					count += write(1, "%", 1);
					break;
				default:
					count += write(1, "%", 1) + write(1, format, 1);
			}
		}
		else
		{
			count += write(1, format, 1);
		}
		format++;
	}

	va_end(args);

	return (count);
}
