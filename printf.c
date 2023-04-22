#include <stdio.h>
#include"main.h"
#include <stdarg.h>
/**
 * digits - count how many digits are in h
 * @h:the number to be counted
 * Return:number of digits in h
 */
int digit_count(int d)
{
	int digits = 0;
	
	if (d >= 9)
	{
		digits += digit_count(d / 10);
	}
	putchar((d % 10) + '0');
	digits++;
	return (digits);
}
/**
 * _printf - produces output according to a format.
 * @format:character string
 * Return:the number of characters printed (excluding the null byte)
 */
int _printf(const char *format, ...)
{
	va_list args;
	int count = 0, c, d;
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
			else if (*format == 'd' || *format == 'i')
			{
				d = va_arg(args, int);
				if (d < 0)
				{
					putchar('-');
					count++;
					d = -d;
				}
				count += digit_count(d);
			}
			else if (*format == '%')
			{
				putchar('%');
				count++;
			}
			else
			{
				putchar('%');
				putchar(*format);
				count += 2;
			}
			format++;
		}
		else
		{
			putchar(*format);
			count++;
			format++;
		}
	}
	va_end(args);
	return (count);
}

