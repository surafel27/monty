#include "monty.h"

/**
 * push - inserts a node to the TOS
 * @stack: pointer to pointer to top of stack
 * @line_number: line number
 * @n: number to be added
 *
 */

void push(stack_t **stack, unsigned int line_number, const char *n)
{
	stack_t *new;

	if (isdigit(atoi(n)) != 0 || (atoi(n) == 0 && *n != '0'))
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		free_list(stack);
		exit(EXIT_FAILURE);
	}

	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	new->n = atoi(n);
	new->prev = NULL;
	if (*stack != NULL)
		(*stack)->prev = new;
	new->next = *stack;
	*stack = new;
}

/**
 * pall - prints all elements of the list
 * @stack: pointer to pointer to TOS
 * @line_number: line number
 *
 */

void pall(stack_t **stack, unsigned int line_number)
{
	(void)line_number;

	if (!(stack) || !(*stack))
		return;
	while (*stack != NULL)
	{
		fprintf(stdout, "%d\n", (*stack)->n);
		*stack = (*stack)->next;
	}
}


/**
 * pop - removes the TOS element
 * @stack: pointer to TOS
 * @line_number: line number
 *
 */

void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = NULL;

	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		free_list(stack);
		exit(EXIT_FAILURE);
	}

	tmp = *stack;
	if ((*stack)->next == NULL)
	{
		*stack = NULL;
		free(tmp);
	}
	else
	{
		*stack = (*stack)->next;
		(*stack)->prev = NULL;
		free(tmp);
	}
}

/**
 * swap - swaps the top two elements of stack
 * @stack: pointer to TOS
 * @line_number: line number
 *
 */

void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = NULL;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	tmp = (*stack)->next;
	(*stack)->next = tmp->next;
	if (tmp->next != NULL)
		tmp->next->prev = *stack;
	tmp->next = *stack;
	tmp->prev = NULL;
	(*stack)->prev = tmp;
	*stack = tmp;
}


/**
 * pint - prints the value of TOS
 * @stack: pointer to TOS
 * @line_number: line number
 *
 */

void pint(stack_t **stack, unsigned int line_number)
{
	if (!(stack) || !(*stack))
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	fprintf(stdout, "%d\n", (*stack)->n);
}
