#include "main.h"
#include <stdarg.h>
#include <unistd.h>
#include <string.h>

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
		if (*format == '%' && (*(format + 1) == 'c' || *(format + 1) == 's'))
		{
			if (*(format + 1) == 'c')
			{
				char c = (char)va_arg(args, int);
				char char_array[2];

				char_array[0] = c;
				char_array[1] = '\0';
				count += write(1, char_array, 1);
			}
			else if (*(format + 1) == 's')
			{
				char *str = va_arg(args, char *);

				count += write(1, str, strlen(str));
			}

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
