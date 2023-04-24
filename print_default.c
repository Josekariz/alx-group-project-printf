#include "main.h"

/**
 * print_default - prints a character and a percent sign
 * @format: the format specifier
 *
 * Return: the number of characters printed (always 2)
 */
int print_default(char format)
{
_putchar('%');
_putchar(format);
return (2);
}
