#include <stdarg.h>
#include <unistd.h>

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
			/* Handle %c and %s cases */
			if (*(format + 1) == 'c')
			{
				char c = (char)va_arg(args, int);

				count += write(1, &c, 1);
			}
			else if (*(format + 1) == 's')
			{
				count += write(1, va_arg(args, char*), 1);
			}

			format += 2;
		}
		else if (*format == '%' && *(format + 1) == '%')
		{
			/* Handle %% case */
			count += write(1, "%", 1);
			format += 2;
		}
		else
		{
			/* Regular character, just print it */
			count += write(1, format, 1);
			format++;
		}
	}

	va_end(args);

	return (count);
}
