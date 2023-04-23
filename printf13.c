#include <stdio.h>
#include"main.h"
#include <string.h>
#include <stdarg.h>
/**
 * _printf - produces output according to a format.
 * @format:a string character
 * Return:the number of characters printed (excluding the null byte(
 */
int _printf(const char *format, ...)
{
	va_list args;
	int count = 0;
	char *s;
	int len;
	int h;

	va_start(args, format);

	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			if (*format == 'r')
			{
				s = va_arg(args, char *);
				len = strlen(s);
				for (h = len - 1; h >= 0; h--)
		{
					putchar(s[h]);
					count++;
				}
			}
			else
			{
				putchar('%');
				putchar(*format);
				count += 2;
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

