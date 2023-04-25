#include "main.h"

/**
 * print_pointer - Prints the value of a pointer variable
 * @types: List a of arguments
 * Ben and Sarah
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed.
 */
int print_pointer(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	char c = 0, padd = ' ';
	int m = BUFF_SIZE - 2, length = 2, padd_start = 1; /* length=2, for '0x' */
	unsigned long num_addrs;
	char map_to[] = "0123456789abcdef";
	void *addrs = va_arg(types, void *);

	UNUSED(width);
	UNUSED(size);

	if (addrs == NULL)
		return (write(1, "(nil)", 5));

	buffer[BUFF_SIZE - 1] = '\0';
	UNUSED(precision);

	num_addrs = (unsigned long)addrs;

	while (num_addrs > 0)
	{
		buffer[m--] = map_to[num_addrs % 16];
		num_addrs /= 16;
		length++;
	}

	if ((flags & F_ZERO) && !(flags & F_MINUS))
		padd = '0';
	if (flags & F_PLUS)
		c = '+', length++;
	else if (flags & F_SPACE)
		c = ' ', length++;

	m++;

	return (write_pointer(buffer, m, length,
		width, flags, padd, c, padd_start));
}

/**
 * print_non_printable - Prints ascii codes in hexa of non printable chars
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */
int print_non_printable(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int w = 0, nice = 0;
	char *str = va_arg(types, char *);

	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	if (str == NULL)
		return (write(1, "(null)", 6));

	while (str[w] != '\0')
	{
		if (is_printable(str[w]))
			buffer[w + nice] = str[w];
		else
			nice += append_hexa_code(str[w], buffer, w + nice);

		w++;
	}

	buffer[w + nice] = '\0';

	return (write(1, buffer, w + nice));
}

/**
 * print_reverse - Prints reverse string.
 * @types: Lista of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Numbers of chars printed
 */

int print_reverse(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	char *str;
	int e, c = 0;

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(size);

	str = va_arg(types, char *);

	if (str == NULL)
	{
		UNUSED(precision);

		str = ")Null(";
	}
	for (e = 0; str[e]; e++)
		;

	for (e = e - 1; e >= 0; e--)
	{
		char z = str[e];

		write(1, &z, 1);
		c++;
	}
	return (c);
}
/**
 * print_rot13string - Print a string in rot13.
 * @types: Lista of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Numbers of chars printed
 */
int print_rot13string(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	char y;
	char *str;
	unsigned int u, p;
	int count = 0;
	char in[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char out[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	str = va_arg(types, char *);
	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	if (str == NULL)
		str = "(AHYY)";
	for (u = 0; str[u]; u++)
	{
		for (p = 0; in[p]; p++)
		{
			if (in[p] == str[u])
			{
				y = out[p];
				write(1, &y, 1);
				count++;
				break;
			}
		}
		if (!in[p])
		{
			p = str[u];
			write(1, &y, 1);
			count++;
		}
	}
	return (count);
}

