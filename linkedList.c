#include "monty.h"
/*hold: is for holding the index of first char, hold_one is for assuring*/
/*that we can insert space after we found piece of char.*/
/*push_number: because we onle need of opcode per line we need to be sure */
/*we don't push more than 2 times*/
/**
 * split_string- this function is for checking is the elment full
 * @head: linkedlist head.
 * @str: string.
 * @line_number: instruction line number.
 */
void split_string(List **head, char *str, int line_number)
{
	int i = 0, hold = 0, hold_one = 0, f_space = 0, push_number = 0;
	char delm1 = ' ', delm2 = ';';
	char *chunck = NULL;

	while (str[i] != '\0' && str[i] != '\n')
	{
		if (str[i] != ' ')
		{
			if (hold_one == 0)
			{
				hold = i;
				hold_one = 1;
			}
			f_space = 1;
		}
		if (str[i] == delm1 || str[i] == delm2)
		{
			hold_one = 0;
			if (f_space != 0)
			{
				push_number++;
				chunck = exract(str, hold, i);
				if (chunck)
					_push(head, &chunck, line_number);
				if (push_number == 2)
					break;
				f_space = 0;
			}
		}
		i++;
	}
	if (str[i - 1] != ' ' && str[i - 1] != ';' && push_number < 2)
	{
		chunck = exract(str, hold, i);
		_push(head, &chunck, line_number);
	}
}
/**
 * exract- this function is for checking is the elment full
 * @str: linkedlist head.
 * @first: string.
 * @last: instruction line number.
 *
 * Return: return chunck if possible and NULL if not.
 */
char *exract(char *str, int first, int last)
{
	int len = 0, i = 0, j = 0;
	char *chunck = NULL;

	len = last - first;
	i = first;

	if (first == 0 && last == 0)
		return (NULL);
	chunck = malloc((len + 1) * sizeof(char));

	while (str[i] != '\0' && i < last)
	{
		if (str[i] != ' ' && str[i] != ';')
			chunck[j] = str[i];
		j++;
		i++;
	}
	chunck[j] = '\0';
	return (chunck);

}
/**
 * _push- push instruction to the linkedlist
 * @head: linkedlist head.
 * @content: content.
 * @line_number: instruction line number.
 */
void _push(List **head, char **content, int line_number)
{
	List *node = NULL, *new_node = NULL;

	if ((*head) == NULL)
	{
		(*head) = malloc(sizeof(List));
		(*head)->content = *content;
		(*head)->line_number = line_number;
		(*head)->next = NULL;
		(*head)->prev = NULL;
	}
	else
	{
		node = (*head);
		while (node->next)
		{
			node = node->next;
		}
		new_node = malloc(sizeof(List));
		new_node->content = *content;
		new_node->line_number = line_number;
		node->next = new_node;
		new_node->prev = node;
		new_node->next = NULL;
	}

}

/**
 * pull- pull instruction from the linkedlist
 * @head: linkedlist head.
 */

void pull(List **head)
{
	List *node = NULL;

	if ((*head) != NULL)
	{
		node = (*head);
		while (node)
		{
			printf("%d -> %s\n", node->line_number, node->content);
			node = node->next;
		}
	}
}
