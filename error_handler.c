#include "monty.h"
/**
 * stack_err- handle_error
 * @list: eror type.
 * @stack: additional infor about error.
 * @file: file.
 * @ln: instruction line number.
 * @str: stack head.
 * @in:linkedlist head.
 */
void stack_err(List **list, stack_t **stack,
FILE *file, char *str, char *in, int ln)
{

	if (_isequal(str, "pint") == 0)
		fprintf(stderr, "L%d: can't pint, stack empty\n", ln);
	else if (_isequal(str, "pop") == 0)
		fprintf(stderr, "L%d: can't pop an empty stack\n", ln);
	else if (_isequal(str, "swap") == 0)
		fprintf(stderr, "L%d: can't swap, stack too short\n", ln);
	else if (_isequal(str, "add") == 0)
		fprintf(stderr, "L%d: can't add, stack too short\n", ln);
	else if (_isequal(str, "sub") == 0)
		fprintf(stderr, "L%d: can't sub, stack too short\n", ln);
	else if (_isequal(str, "div") == 0)
		fprintf(stderr, "L%d: can't div, stack too short\n", ln);
	else if (_isequal(str, "division") == 0)
		fprintf(stderr, "division by zero\n");
	else if (_isequal(str, "mul") == 0)
		fprintf(stderr, "L%d: can't mul, stack too short\n", ln);
	else if (_isequal(str, "mod") == 0)
		fprintf(stderr, "L%d: can't mod, stack too short\n", ln);
	else if (_isequal(str, "uk") == 0)
		fprintf(stderr, "L%d: unknown instruction %s\n", ln, in);
	else if (_isequal(str, "dg") == 0)
		fprintf(stderr, "L%d: usage: push integer\n", ln);

	free_linked_list(list);
	free_stack(stack);
	fclose(file);
	exit(EXIT_FAILURE);
}
