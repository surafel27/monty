#include "monty.h"

/**
 * mul - computs the modulus of TOS
 * @stack: pointer to TOS
 * @line_number: line number
 *
 */
void mul(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = NULL;

	if (!(*stack) || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't mul, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	tmp = (*stack)->next;
	tmp->n = tmp->n * tmp->prev->n;
	*stack = tmp;
	tmp->prev->next = NULL;
	free(tmp->prev);
}

/**
 * sub - computs the modulus of TOS
 * @stack: pointer to TOS
 * @line_number: line number
 *
 */
void sub(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = NULL;

	if (!(*stack) || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	tmp = (*stack)->next;
	tmp->n = tmp->n - tmp->prev->n;
	*stack = tmp;
	tmp->prev->next = NULL;
	free(tmp->prev);
}

/**
 * add - computs the modulus of TOS
 * @stack: pointer to TOS
 * @line_number: line number
 *
 */
void add(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = NULL;

	if (!(*stack) || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	tmp = (*stack)->next;
	tmp->n = tmp->n + tmp->prev->n;
	*stack = tmp;
	tmp->prev->next = NULL;
	free(tmp->prev);
}
/**
 * _div - computs the modulus of TOS
 * @stack: pointer to TOS
 * @line_number: line number
 *
 */
void _div(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = NULL;

	if (!(*stack) || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't div, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	tmp = (*stack)->next;
	tmp->n = tmp->n / tmp->prev->n;
	*stack = tmp;
	tmp->prev->next = NULL;
	free(tmp->prev);
}

/**
 * mod - computs the modulus of TOS
 * @stack: pointer to TOS
 * @line_number: line number
 *
 */
void mod(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = NULL;

	if (!(*stack) || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't mod, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	tmp = (*stack)->next;
	tmp->n = tmp->n % tmp->prev->n;
	*stack = tmp;
	tmp->prev->next = NULL;
	free(tmp->prev);
}
