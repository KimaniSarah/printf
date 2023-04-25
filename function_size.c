#include "main.h"
/**
 * get_size - Calculates the size
 * @format: Formatted string in which to print the arguments
 * @i: List of arguments to be printed.
 *
 * Return: Precision.
 */
int get_size(const char *format, int *i)
{
	int c = *i + 1;
	int size = 0;

	if (format[c] == 'l')
		size = S_LONG;
	else if (format[c] == 'h')
		size = S_SHORT;
	if (size == 0)
		*i = c - 1;
	else
		*i = c;
	return (size);
}
