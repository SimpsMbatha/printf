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
	int i;
	int count = 0;
	int c;
	char *s;
	va_list args;

	va_start(args, format);

	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] == '%')
		{
			putchar(format[i]);
			count++;
		}
		else
		{
			i++;
			
			else if (format[i] == 'c')
			{
				c = va_arg(args, int);
				print_char(c);
				count++;
			}
			else if (format[i] == 's')
			{
				s = va_arg(args, char *);
				print_string(s);
				count += 5;
			}
			else if (format[i] == '%')
			{
				putchar('%');
				count++;
			}
			else
			{
				putchar('%');
				putchar(format[i]);
				count += 2;
			}
		}
	}
	va_end(args);

	return (i);
}
