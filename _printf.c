#include "main.h"

int my_printf(const char *format, ...)
{
unsigned int j = 0;
int rt_value = 0;
va_list args;
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
int r_val = puts_string(va_arg(args, char *));
j++;
rt_value += (r_val - 1);
}
else if (format[j + 1] == '%')
{
_putchar('%');
j++;
}
rt_value += 1;
}
va_end(args);
return (rt_value);
}
