#include <stdarg.h>
#include <stdio.h>
#include "main.h"
/**
 * print_char - print character
 * @c:the character to be printed
 * Return:number of characters printed
 */
int print_char(char c)
{
	putchar(c);
	return (1);
}
/**
 * print_string - prints a string
 * @str:the string to be printed
 * Return:the number of characters printed
 */
int print_string(char *str)
{
	int count = 0;

	putchar(*str++);
	count++;
	return (count);
}
/**
 * _printf -  produces output according to a format.
 * @format:character string that contain c,%,s
 * Return:the no of characters printed (excluding the null byte)
 */
int _printf(const char *format, ...)
{
	const char *p_format = format;
	va_list arg;
	int count = 0;
	char *str, c;
	int (*f_print_string)(char *) = &print_string;

	va_start(arg, format);
	while (*p_format != '\0')
	{
		if (*p_format == '%')
		{
			p_format++;
			if (*p_format == 's')
			{
				str = va_arg(arg, char*);
				count += f_print_string(str);
			}
			if (*p_format == 'c')
			{
				c = va_arg(arg, int);
				count += print_char(c);
			}
			else
			{
				putchar(*p_format);
				count++;
			}
		}
		else
		{
			putchar(*p_format);
			count++;
		}
	}
	va_end(arg);
	return (count);
}
