#include <stdio.h>
#include"main.h"
#include <stdarg.h>
/**
 * _printf - produces output according to a format.
 * @format:character string
 * Return:the number of characters printed (excluding the null byte)
 */
int _printf(const char *format, ...)
{
	va_list args;
	int count = 0, c;
	char *s;

	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (*format == 'c')
			{
				c = va_arg(args, int);
				putchar(c);
				count++;
			}
			else if (*format == 's')
			{
				s = va_arg(args, char *);
				while (*s)
				{
					putchar(*s++);
					count++;
				}
			}
			else if (*format == '%')
			{
				putchar('%');
				count++;
			}
		}
		else
		{
			putchar(*format);
			count++;
		}
		format++;
	}
	va_end(args);
	return (count);
}
