#include "monty.h"

/**
 * handle_file_instrctions- this function open the file and call
 * the function that will handle instructions.
 * @argc: argc
 * @argv: argv
 */

void handle_file_instrctions(int argc, char **argv)
{
	FILE *file = NULL;

	if (argc == 2)
	{
		file = fopen(argv[1], "r");
		if (file == NULL)
		{
			fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
			exit(EXIT_FAILURE);
		}
		readFromFile(file);
	}
	else
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	fclose(file);
}

/**
 * readFromFile- read text from the file and sent for split
 * @file: file
 */

void readFromFile(FILE *file)
{
	char buffer[1024];
	List *head = NULL;
	int ln = 1;

	while (fgets(buffer, sizeof(buffer), file) != NULL)
	{
		split_string(&head, buffer, ln);
		ln++;
	}
	execute_intructions(&head, file);
	free_linked_list(&head);
}

/**
 * execute_intructions- this execute file text instuctions
 * @head: head of the list of instructions.
 * @file: file.
 *
 */

void execute_intructions(List **head, FILE *file)
{
	stack_t *stack_head = NULL;
	instruction_t *func = NULL;
	List *node = (*head);
	char *err = NULL;

	while (node)
	{
		if (_isequal("push", node->content) == 0)
		{
			if (node->next == NULL)
				break;
			if (_isequal(isElementDigit(node->next->content), "nd") == 0)
				stack_err(head, &stack_head, file, "dg", NULL, node->line_number);
			else
			{ func = Is_Instruction_exist(node->content);
				err = func->f(&stack_head, atoi(node->next->content));
				if (err != NULL)
				{ free(func);
					stack_err(head, &stack_head, file, err, NULL, node->line_number); }
				node = node->next->next;
			}
		} else
		{ func = Is_Instruction_exist(node->content);
			if (func != NULL)
			{
				err = func->f(&stack_head, node->line_number);
				if (err != NULL)
				{ free(func);
					stack_err(head, &stack_head, file, err, NULL, node->line_number);
				} node = node->next;
			} else
			{
				if (_isequal("#", node->content) == 0
				|| node->content == NULL || check_prev(&node) != NULL)
				{ node = node->next;
					continue; }
				stack_err(head, &stack_head, file, "uk", node->content, node->line_number);
			}
		} free(func);
	} free_stack(&stack_head);
}

/**
 * Is_Instruction_exist- check is this instructions existe
 * and bring it functions
 * @str: opcode.
 *
 * Return: null if doesn't existe and point to function to
 * struct that has opcode functions.
 */

instruction_t *Is_Instruction_exist(char *str)
{
	int i = 0;
	instruction_t *fun = NULL;
	instruction_t functions[] = {
		{"push", push}, {"pall", pall}, {"pop", pop}, {"pint", pint},
		{"pop", pop}, {"swap", swap}, {"add", add}, {"nop", nop},
		{"sub", sub}, {"div", div_fu}, {"mul", mul}, {"mod", mod},
		{"pchar", pchar}, {NULL, NULL}
	};

	fun = malloc(sizeof(instruction_t));
	while (i < 14)
	{
		if (_isequal(str, functions[i].opcode) == 0)
		{
			fun->opcode = str;
			fun->f = functions[i].f;
			return (fun);
		}
		i++;
	}
	free(fun);
	return (NULL);
}
/**
 * check_prev- check prev opcode if not equal push so
 * we can avoid unknown intruction
 * @node: current node.
 *
 * Return: null if doesn't existe or push and found if exise.
 */
char *check_prev(List **node)
{
	char *tmp = NULL;

	if ((*node)->prev == NULL)
		return (NULL);
	tmp = (*node)->prev->content;

	if (_isequal(tmp, "push") == 0)
	{
		return (NULL);
	}
	else if (Is_Instruction_exist(tmp) != NULL)
	{
		if ((*node)->line_number == (*node)->prev->line_number)
			return ("found");
		else
			return (NULL);
	}
	return (NULL);

}
