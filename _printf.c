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
<<<<<<< HEAD
    if (s != NULL) 
    {
        printf("%s", s);
    }
=======
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
>>>>>>> 2206545687d2c5d8fd3002bdaf95bc643970c20e
}

int _printf(const char *format, ...) 
{
<<<<<<< HEAD
    if (format == NULL)
    {
        return -1;
    }
=======
	int i;
	int count = 0;
	int c;
	char *s;
	va_list args;
>>>>>>> 66bc95ca6cad5e6ae594ac1d7ece3b160c7d6389

    int i = 0;
    int count = 0;
    va_list args;
    va_start(args, format);

    while (format[i] != '\0') 
    {
        if (format[i] == '%') 
	{
<<<<<<< HEAD
            i++;
            if (format[i] == '\0') 
	    {
                va_end(args);
                return -1;
            } 
	    else if (format[i] == 'c') 
	    {
                int c = va_arg(args, int);
                print_char(c);
                count++;
		} 
	    else if (format[i] == 's') 
		{
                char *s = va_arg(args, char *);
                print_string(s);
                count += (s != NULL) ? strlen(s) : 0;
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
	else 
	{
            print_char(format[i]);
            count++;
=======
		return (-1);
	}

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
>>>>>>> 66bc95ca6cad5e6ae594ac1d7ece3b160c7d6389
	}
        i++;
    }

    va_end(args);
    return count;
}
