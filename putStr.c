#include "main.h"

/**
 * puts_string - prints a string to stdout
 * @string: the string to be printed
 *
 * Return: number of characters printed
 */
int puts_string(char *string)
{
int index = 0, count = 0;

if (string != NULL)
{
while (string[index] != '\0')
{
_putchar(string[index]);
count++;
index++;
}
}
return (count);
}
