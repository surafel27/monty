#include "monty.h"

/**
 * get_opcode - get the function for opcode
 * @opcode: opcode given by user
 * Return: returns a correspoinding function
 */

void (*get_opcode(char *opcode))(stack_t **stack, unsigned int line_number)
{
	instruction_t op[] = {
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"nop", nop},
		{"swap", swap},
		{"add", add},
		{"sub", sub},
		{"mul", mul},
		{"div", _div},
		{"mod", mod},
		{NULL, NULL}
	};
	int i = 0;

	while (op[i].opcode != NULL)
	{
		if (strcmp(opcode, op[i].opcode) == 0)
		{
			return (op[i].f);
		}
		i++;
	}
	return (NULL);
}
