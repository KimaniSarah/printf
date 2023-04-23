#include <stdarg.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/**
 * num_len - get the length of a number
 * @n: number to get length of
 *
 * Return: length of number
 */
int num_len(int n)
{
	int len = 0;

	while (n != 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}
/**
 * _printf - prints a formatted string to the standard output
 * @format: format string to print
 *
 * Return: number of characters printed
 */
int _printf(const char *format, ...)
{
	va_list args;
	int count = 0;
	const char *p;
	char *s;
	int i, precision;

	va_start(args, format);

	for (p = format; *p != '\0'; p++)
	{
		if (*p != '%')
		{
			putchar(*p);
			count++;
			continue;
		}

		precision = -1;

		/* Handle precision for non-custom conversion specifiers */
		if (*(p + 1) == '.')
		{
			if (isdigit(*(p + 2)))
				precision = atoi(p + 2);
			else if (*(p + 2) == '*')
				precision = va_arg(args, int);
		}

		switch (*(++p))
		{
			case 'c':
				putchar(va_arg(args, int));
				count++;
				break;
			case 's':
				s = va_arg(args, char *);
				if (s == NULL)
					s = "(null)";
				if (precision == -1)
				{
					printf("%s", s);
					count += strlen(s);
				}
				else
				{
					printf("%.*s", precision, s);
					count += precision;
				}
				break;
			case 'd':
			case 'i':
				i = va_arg(args, int);
				printf("%.*d", precision, i);
				count += num_len(i);
				break;
			case '%':
				putchar('%');
				count++;
				break;
			default:
				putchar('%');
				putchar(*p);
				count += 2;
				break;
		}
	}

	va_end(args);

	return (count);
}
