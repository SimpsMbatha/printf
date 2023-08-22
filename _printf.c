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
    if (s != NULL) 
    {
        printf("%s", s);
    }
}

int _printf(const char *format, ...) 
{
    if (format == NULL)
    {
        return -1;
    }

    int i = 0;
    int count = 0;
    va_list args;
    va_start(args, format);

    while (format[i] != '\0') 
    {
        if (format[i] == '%') 
	{
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
	}
        i++;
    }

    va_end(args);
    return count;
}
