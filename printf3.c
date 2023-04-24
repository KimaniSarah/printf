#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>

/**
 * _printf - produces output according to a format
 * @format: a character string containing zero or more directives
 *
 * Return: the number of characters printed (excluding the null byte used to end output to strings)
 */
int _printf(const char *format, ...)
{
    int count = 0;
    const char *p;
    va_list arg;
    char c, *s;
    int d;
    unsigned int u;
    char buffer[32];

    va_start(arg, format);
    for (p = format; *p != '\0'; p++)
    {
        if (*p != '%')
        {
            write(1, p, 1);
            count++;
        }
        else
        {
            switch (*++p)
            {
                case 'c':
                    c = va_arg(arg, int);
                    write(1, &c, 1);
                    count++;
                    break;
                case 's':
                    s = va_arg(arg, char *);
                    while (*s != '\0')
                    {
                        write(1, s++, 1);
                        count++;
                    }
                    break;
                case 'd':
                case 'i':
                    d = va_arg(arg, int);
                    if (d < 0)
                    {
                        write(1, "-", 1);
                        count++;
                        d = -d;
                    }
                    if (d / 10)
                    {
                        _printf("%d", d / 10);
                    }
                    c = d % 10 + '0';
                    write(1, &c, 1);
                    count++;
                    break;
                case 'u':
                    u = va_arg(arg, unsigned int);
                    if (u / 10)
                    {
                        _printf("%u", u / 10);
                    }
                    c = u % 10 + '0';
                    write(1, &c, 1);
                    count++;
                    break;
                case 'b':
                    u = va_arg(arg, unsigned int);
                    int i = 0;
                    if (u == 0)
                    {
                        buffer[i++] = '0';
                    }
                    while (u != 0)
                    {
                        buffer[i++] = (u % 2 == 0) ? '0' : '1';
                        u /= 2;
                    }
                    while (i--)
                    {
                        write(1, &buffer[i], 1);
                        count++;
                    }
                    break;
                case 'S':
                    s = va_arg(arg, char *);
                    while (*s != '\0')
                    {
                        if (*s > 31 && *s < 127)
                        {
                            write(1, s, 1);
                            count++;
                        }
                        else
                        {
                            _printf("\\x%02X", (unsigned char)*s);
                            count += 4;
                        }
                        s++;
                    }
                    break;
                case '%':
                    write(1, "%", 1);
                    count++;
                    break;
                default:
                    write(1, "%", 1);
                    write(1, &(*p), 1);
                    count += 2;
                    break;
            }
        }
    }
    va_end(arg);

    return count;
}
