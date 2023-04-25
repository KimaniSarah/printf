#include "main.h"

void print_buffer(char buffer[], int *buff_ind);

/**
 * _printf - Printf function
 * @format: format.
 * Return: Printed chars.
 */
int _printf(const char *format, ...)
{
	int q, printing = 0, printed_chars = 0;
	int flags, width, precision, size, buff_ind = 0;
	va_list list;
	char buffer[BUFF_SIZE];

	if (format == NULL)
		return (-1);

	va_start(list, format);

	for (q = 0; format && format[q] != '\0'; q++)
	{
		if (format[q] != '%')
		{
			buffer[buff_ind++] = format[q];
			if (buff_ind == BUFF_SIZE)
				print_buffer(buffer, &buff_ind);
			/* write(1, &format[q], 1);*/
			printed_chars++;
		}
		else
		{
			print_buffer(buffer, &buff_ind);
			flags = get_flags(format, &q);
			width = get_width(format, &q, list);
			precision = get_precision(format, &q, list);
			size = get_size(format, &q);
			++q;
			printing = handle_print(format, &q, list, buffer,
				flags, width, precision, size);
			if (printing == -1)
				return (-1);
			printed_chars += printing;
		}
	}

	print_buffer(buffer, &buff_ind);

	va_end(list);

	return (printed_chars);
}
/**
 * print_buffer - the buffer if it exist
 * @buffer: Array of chars
 * ben and sarah
 * @buff_ind: Index at which to add next char, represents the length.
 */
void print_buffer(char buffer[], int *buff_ind)
{
	if (*buff_ind > 0)
		write(1, &buffer[0], *buff_ind);

	*buff_ind = 0;
}
