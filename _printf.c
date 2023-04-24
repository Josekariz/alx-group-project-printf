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
				case 'd':
				case 'i':
					snprintf(buffer, sizeof(buffer), "%d", va_arg(arg, int));
					printed_chars += puts(buffer);
					break;
				default:
					printed_chars += print_default(format[i]);
					break;
			}
		}
		else
		{
			printed_chars = print_char(format[i], printed_chars);
		}
	}

	va_end(arg);
	return (printed_chars);
}
/**
 * print_char - prints a single character
 * @c: the character to print
 * @printed_chars: the total number of characters printed so far
 *
 * Return: the number of characters printed
 */
int print_char(char c, int printed_chars)
{
	_putchar(c);
	return (printed_chars + 1);
}
