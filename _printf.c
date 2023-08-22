#include <stdio.h>
#include <stdarg.h>
#include "main.h"

/**
 * print_char - prints a character.
 * @c: the character to print.
 *
 * Return: void
 */

void print_char(char c)
{
	putchar(c);
}

/**
 * print_string - print a string.
 * @s: the string to print.
 *
 * Return: void
 */

void print_string(const char *s)
{
	if (s)
	{
		while (*s)
		{
			putchar(*s);
			s++;
		}
	}
	else
	{
		printf("(nil)");
	}
}

int _printf(const char *format, ...)
{
	int i = 0;
	int c;
	char *s;
	va_list args;

	va_start(args, format);

	if (format == NULL)
	{
		return (-1);
	}

	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			i++;

			if (format[i] == '\0')
			{
				va_end(args);
				return (-1);
			}

			else if (format[i] == ' ')
			{
				va_end(args);
				return (-1);
			}

			else if (format[i] == 'c')
			{
				c = va_arg(args, int);
				print_char(c);
			}
			else if (format[i] == 's')
			{
				s = va_arg(args, char *);
				print_string(s);
			}
			else if (format[i] == '%')
			{
				putchar('%');
			}
			else
			{
				putchar('%');
				putchar(format[i]);
			}
		}
		else
		{
			print_char(format[i]);
		}
		i++;
	}
	va_end(args);

	return (i);
}
