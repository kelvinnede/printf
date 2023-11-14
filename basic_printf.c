#include "main.h"
#include <unistd.h>
#include <stdarg.h>

/**
 * basic_printf - Custom printf function for handling %c, %s, and %%
 * @format: Format string containing format specifiers.
 *
 * This function produces output according to a format. It handles
 * the conversion specifiers %c, %s, and %%.
 *
 * Return: The number of characters printed (excluding the null byte).
 *         Write output to stdout, the standard output stream.
 */
int basic_printf(const char *format, ...)
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
			char c = va_arg(args, int);

			count += write(1, &c, 1);
		}
		else
		{
			char *str = va_arg(args, char *);

			count += write(1, str, 0);
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

	va_end(args);

	return (count);
}
