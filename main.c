/* main.c */

#include "main.h"

int main(void)
{
	int len;

	len = _printf("I'm not going anywhere. You can print that wherever you want to. "
                  "I'm here and I'm a Spur for life\n");
	_printf("Number of characters printed: %d\n", len);

	len = _printf("This is a character: %c\n", 'A');
	_printf("Number of characters printed: %d\n", len);

	len = _printf("This is a string: %s\n", "Hello, World!");
	_printf("Number of characters printed: %d\n", len);

	return (0);
}
