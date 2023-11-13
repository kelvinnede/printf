#include <stdarg.h>
#include <stdio.h>

int _printf(const char *format, ...);

int main(void)
{
	_printf("%b\n", 98);
	return (0);
}

int _printf(const char *format, ...)
{
	va_list args;
	int count = 0;

	va_start(args, format);

	while (*format)
	{
		if (*format == '%' && *(format + 1) == 'b')
		{
			unsigned int num = va_arg(args, unsigned int);
			print_binary(num);
			format += 2; // Move format pointer past '%b'
			count += count_binary_digits(num);
		}
		else
		{
			putchar(*format);
			format++;
			count++;
		}
	}

	va_end(args);

	return (count);
}

void print_binary(unsigned int num)
{
	if (num / 2 != 0)
		print_binary(num / 2);

	putchar('0' + num % 2);
}

int count_binary_digits(unsigned int num)
{
	int count = 0;

	do
	{
		count++;
		num /= 2;
	} while (num != 0);

	return (count);
}
