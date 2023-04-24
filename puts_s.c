#include "main.h"

/**
 * puts_s - prints a string
 * @str: pointer to string to print
 *
 * Return: the number of characters printed (excluding the null byte)
 */
int puts_s(char *str)
{
int i;

if (str == NULL)
str = "(null)";

for (i = 0; str[i]; i++)
_putchar(str[i]);

return (i);
}
