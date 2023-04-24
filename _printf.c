#include "main.h"

/**
 * _printf - prints output according to a format
 * @format: character string containing zero or more directives
 *
 * Return: the number of characters printed (excluding the null byte)
 */
int _printf(const char *format, ...)
{
	int i, printed_chars = 0;
	va_list arg;
	char buffer[1024];

	va_start(arg, format);

	for (i = 0; format[i]; i++)
	{
		if (format[i] == '%')
		{
			i++;
			switch (format[i])
			{
				case 'c':
					_putchar(va_arg(arg, int));
					printed_chars++;
					break;
				case 's':
					printed_chars += puts_s(va_arg(arg, char *));
					break;
				case '%':
					_putchar('%');
					printed_chars++;
					break;
				default:
					printed_chars += print_default(format[i]);
					break;
			}
		}
		else
		{
			_putchar(format[i]);
			printed_chars++;
		}
	}

	va_end(arg);
	return (printed_chars);
}
