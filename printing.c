#include <stdio.h>
#include <stdarg.h>
#include "main.h"

/**
 * _printf - produces output according to a format
 * @format: character string
 *
 * Return: the number of characters printed.
 */

int _printf(const char *format, ...)
{
	int i;
	va_list args;
	sign conv;

	va_start(args, format);

	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] == '%')
		{
			char specifier = format[i + 1];

			if (specifier == 'c')
			{
				conv.c = va_arg(args, int);
				printf("%c", conv.c);
			}

			else if (specifier == 's')
			{
				conv.s = va_arg(args, char *);

				if (conv.s)
				{
					printf("%s", conv.s);
				}
				else
				{
					printf("(nil)");
				}
			}

			else if (specifier == '%')
			{
				putchar('%');
			}
			else
			{
				putchar('%');
				putchar(specifier);
			}
			i++;
		}
		
		else
		{
			putchar(format[i]);
		}
	}

	va_end(args);
	
	return (i);
}
