#include <stdarg.h>
#include <stdio.h>

/**
 * _printf - Custom printf function with support for %b specifier
 * @format: Format string containing optional specifiers
 *
 * Return: Number of characters printed (excluding null byte)
 */
int _printf(const char *format, ...);

/**
 * main - Main function to demonstrate the usage of _printf
 *
 * Return: Always 0
 */
int main(void)
{
	// Print the binary representation of 98 using %b specifier
	_printf("%b\n", 98);
	return (0);
}

/**
 * print_binary - Recursively print binary representation of a number
 * @num: Unsigned integer to be converted to binary
 */
void print_binary(unsigned int num)
{
	if (num / 2 != 0)
		print_binary(num / 2);

	// Print binary digit
	putchar('0' + num % 2);
}

/**
 * count_binary_digits - Count the number of binary digits in a number
 * @num: Unsigned integer to be counted
 *
 * Return: Number of binary digits
 */
int count_binary_digits(unsigned int num)
{
	int count = 0;

	// Iterate until the number becomes zero
	do
	{
		count++;
		num /= 2;
	} while (num != 0);

	// Return the count of binary digits
	return (count);
}
