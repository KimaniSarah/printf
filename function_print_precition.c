#include "main.h"
/**
 * get_precision - Calculates the precision for printing
 * @format: Formatted string in which to print the arguments
 * @i: List of arguments to be printed.
 * @list: list of arguments.
 * Ben and Sarah
 * Return: P.
 */
int get_precision(const char *format, int *i, va_list list)
{
	int c = *i + 1;
	int p = -1;

	if (format[c] != '.')
		return (p);

	p = 0;

	for (c += 1; format[c] != '\0'; c++)
	{
		if (isdigit(format[c]))
		{
			p *= 10;
			p += format[c] - '0';
		}
		else if (format[c] == '*')
		{
			c++;
			p = va_arg(list, int);
			break;
		}
		else
			break;
	}

	*i = c - 1;

	return (p);
}
