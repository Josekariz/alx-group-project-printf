#include "main.h"

/**
 * _printf - produces output according to a format
 * @format: format string containing directives
 *
 * Return: number of characters printed
 */
int _printf(const char *format, ...)
{
	va_list args;
	int i, count = 0;

	va_start(args, format);

	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] == '%')
		{
			i++;
			switch (format[i])
			{
				case 'c':
					count += print_char(va_arg(args, int));
					break;
				case 's':
					count += print_str(va_arg(args, char *));
					break;
				case '%':
					count += putchar('%');
					break;
				default:
					count += putchar('%');
					count += putchar(format[i]);
					break;
			}
		}
		else
		{
			count += putchar(format[i]);
		}
	}

	va_end(args);

	return (count);
}

/**
 * print_char - prints a character to the standard output stream
 * @c: character to print
 *
 * Return: number of characters printed
 */
int print_char(int c)
{
	return (putchar(c));
}

/**
 * print_str - prints a string to the standard output stream
 * @str: pointer to the string to print
 *
 * Return: number of characters printed
 */
int print_str(char *str)
{
	int i, count = 0;

	if (str == NULL)
		str = "(null)";

	for (i = 0; str[i] != '\0'; i++)
		count += putchar(str[i]);

	return (count);
}
