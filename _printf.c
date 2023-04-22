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
					/* code to print a character */
					break;
				case 's':
					count += print_str(va_arg(args, char *));
					break;
				case '%':
					/* code to print a percent sign */
					break;
				default:
					/* code to handle invalid conversion specifiers */
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
