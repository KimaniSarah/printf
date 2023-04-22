#include "main.h"
#include <stdio.h>
#include <stdarg.h>
/**
 * _printf - handle format specifier p
 * @format:a string of characters
 * Return:the number of characters printed (excluding the null )
 */
int _printf(const char *format, ...)
{
	void *p;
	va_list arg;
	int count = 0;

	va_start(arg, format);
	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			if (*format == 'p')
			{
				p = va_arg(arg, void *);
				count += printf("%p", p);
				format += 2;
				putchar('\n');
			}
		}
		else
		{
			putchar(*format);
			count++;
		}
		format++;
	}
	va_end(arg);

	return (count);
}
