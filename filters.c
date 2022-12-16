#include "monty.h"

/**
 * check_n - checks for number validity
 * @n: string number
 * Return: 1 if valied, or -1 if not
 */

int check_n(const char *n)
{
	int i = 0;

	if (n[0] == '-' && n[1] == '0')
		return (1);
	if (n[0] == '-')
		i++;
	while (n[i] != '\0')
	{
		if (!(n[i] >= '0' && n[i] <= '9'))
			return (-1);
		i++;
	}
	return (1);
}

/**
 * filter - filters opcode
 * @opcode: opcode
 * Return: 1 on success, -1 if it fails
 */

int filter(char *opcode)
{
	char *a[] = {"add", "sub", "div", "swap", "mul", "mod", "nop", NULL};
	int i = 0;

	while (a[i] != NULL)
	{
		if (strcmp(opcode, a[i]) == 0)
			return (1);
		i++;
	}
	return (-1);
}
