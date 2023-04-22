#include <stdarg.h>
#include <stdio.h>
/**
 * _printf -  produces output according to a format.
 * @format:character string.
 * Return: the number of characters printed (excluding the null byt)
 */
int _printf(const char *format, ...)
{
	va_list arg;
	int field_width, count = 0;
	unsigned int u, o, x, X;
	void *p;
	char *s;
	char c;

	va_start(arg, format);
	while (*format != '\0')
	{
		if (*format == '%')
		{
			field_width = 0;
			format++;
			while (*format >= '0' && *format <= '9')
			{
				field_width = field_width * 10 + (*format - '0');
				format++;
			}
			switch (*format)
			{
				case 'u':
					u = va_arg(arg, unsigned int);
					count += printf("%*u", field_width, u);
					break;
				case 'i':
				case 'd':
					count += printf("%*d", field_width, va_arg(arg, int));
					break;
				case 'o':
					o = va_arg(arg, unsigned int);
					count += printf("%*o", field_width, o);
					break;
				case 'x':
					x = va_arg(arg, unsigned int);
					count += printf("%*x", field_width, x);
					break;
				case 'X':
					X = va_arg(arg, unsigned int);
					count += printf("%*X", field_width, X);
					break;
				case 's':
					s = va_arg(arg, char *);
					count += printf("%*s", field_width, s);
					break;
				case 'p':
					p = va_arg(arg, void *);
					count += printf("%*p", field_width, p);
					break;
				case 'c':
					c = va_arg(arg, int);
					count += printf("%*c", field_width, c);
					break;
				case '%':
					putchar('%');
					count++;
					break;
				default:
					putchar(*format);
					count++;
					break;
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
