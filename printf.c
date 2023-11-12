#include "main.h"
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
				str = va_arg(args, char*), count += write(1, str, 0);
			format += 2;
		}
		else if (*format == '%' && (*(format + 1) == 'd' || *(format + 1) == 'i'))
		{
			num_length = snprintf(num_str, sizeof(num_str), "%d", va_arg(args, int));
			count += write(1, num_str, num_length);
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
