#ifndef MAIN_H
#define MAIN_H

int _printf(const char *format, ...);

/**
 * specifier - holds 2 members.
 * @c: integer
 * @s: pointer to a character.
 *
 * Return: void
 */

struct specifier
{
	int c;
	char *s;
};

typedef struct specifier sign;

#endif
