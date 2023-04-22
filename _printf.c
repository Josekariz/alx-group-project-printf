#include "main.h"

/**
 * _printf - prints output according to a format
 * @format: pointer to a format string
 *
 * Return: number of characters printed
 **/
int _printf(const char *format, ...)
{
va_list args;
int count = 0;
char *str;

va_start(args, format);
while (*format)
{
if (*format == '%')
{
format++;
if (*format == 'c')
{
_putchar(va_arg(args, int));
count++;
}
else if (*format == 's')
{
str = va_arg(args, char *);
while (*str)
{
_putchar(*str++);
count++;
}
}
else if (*format == '%')
{
_putchar('%');
count++;
}
}
else
{
_putchar(*format);
count++;
}
format++;
}
va_end(args);
return (count);
}
