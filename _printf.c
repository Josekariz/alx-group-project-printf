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
	int counter, j = 0;

	va_start(args, format);

	for (; format[j] != '\0'; j++)
	{

		if (format[j] != '%')
		{
			_putchar(format[j]);
		}
		else if (format[j + 1] == 'c')
		{
			_putchar(va_arg(args, int));
			j++;
		}
		else if (format[j + 1] == 's')
		{
			int return_value = puts_string(va_arg(args, char*));

			j++;
			counter += (return_value - 1);
		}
		counter += 1;
	}
	va_end(args);

	return (counter);
}
