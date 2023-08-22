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

void print_int(int num) 
{
    printf("%d", num);
}

void print_unsigned_int(unsigned int num) 
{
    printf("%u", num);
}

void print_octal(unsigned int num) 
{
    printf("%o", num);
}

void print_hex_lower(unsigned int num) 
{
    printf("%x", num);
}

void print_hex_upper(unsigned int num) 
{
    printf("%X", num);
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
	    else if (format[i] == 'd' || format[i] == 'i') 
	    {
                int num = va_arg(args, int);
                print_int(num);
                count++;
            } 
	    else if (format[i] == 'u') 
	    {
                unsigned int num = va_arg(args, unsigned int);
                print_unsigned_int(num);
                count++;
            } 
	    else if (format[i] == 'o') 
	    {
                unsigned int num = va_arg(args, unsigned int);
                print_octal(num);
                count++;
            } 
	    else if (format[i] == 'x') 
	    {
                unsigned int num = va_arg(args, unsigned int);
                print_hex_lower(num);
                count++;
            } 
	    else if (format[i] == 'X') 
	    {
                unsigned int num = va_arg(args, unsigned int);
                print_hex_upper(num);
                count++;
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

