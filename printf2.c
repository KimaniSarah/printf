#include "main.h"
#include <stdarg.h>
#include <stdio.h>
/**
 * number_to_binary - changes a number to binary code
 * @h:the number to be changed to binary
 * Return:binary number
 */
int number_to_binary(unsigned int h)
{
	if (h == 0)
	{
		return (0);
	}
	number_to_binary(h / 2);
	putchar((h % 2) + '0');
	return (0);
}
/**
 * _printf - the unsigned int argument is converted to binary
 * @format:a string of characters
 * Return: the number of characters printed
 */
int _printf(const char *format, ...)
{
	va_list arg;
	int count = 0;
	unsigned int h;

	va_start(arg, format);
	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			if (*format == 'b')
			{
				h = va_arg(arg, int);
				count += number_to_binary(h);
			}
			else
			{
				putchar(*format);
				count++;
			}
		}
		format++;
	}
	va_end (arg);
	putchar('\n');

	return (count);
}
