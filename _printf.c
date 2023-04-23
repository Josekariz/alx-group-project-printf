#include "main.h"
#include <stdio.h>
#include <stdarg.h>

/**
 * _printf - prints output according to a format
 * @format: pointer to a format string
 * Return: number of characters printed
 **/
int _printf(const char *format, ...)
{
	va_list args;
	int count = 0, i = 0;

	va_start(args, format);
	for (; format && format[i]; i++)
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i] == 'c')
			{
				_putchar(va_arg(args, int)), count++;
			}
			else if (format[i] == 's')
			{
				char *s = va_arg(args, char *);

				s = (!s) ? "(null)" : s;
				while (*s)
				{
					_putchar(*s++), count++;
				}
			}
			else if (format[i] == '%')
			{
				_putchar('%'), count++;
			}
		}
		else
		{
			_putchar(format[i]), count++;
		}
	}
	va_end(args);
	return (count);
}