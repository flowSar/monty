#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>


/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;


/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	char *(*f)(stack_t **stack, unsigned int line_number);
} instruction_t;


/**
 * struct list - doubly linked list representation of a stack (or queue)
 * @content : opcode or value
 * @line_number: line_number
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct list
{
	char *content;
	int line_number;
	struct list *next;
	struct list *prev;

} List;


void handle_file_instrctions(int argc, char **argv);
void execute(FILE *file);
int _strlen(char *str);
int _isequal(char *str1, char *str2);
int getArraylen(instruction_t *array);
char *isElementDigit(char *elem);
/*----------parse string----------*/

int get_length(char *str);

/*-------------------stack function---------*/
char *push(stack_t **head, unsigned int line_number);
char *pop(stack_t **head, unsigned int line_number);
char *pall(stack_t **head, unsigned int line_number);
char *pint(stack_t **head, unsigned int line_number);
char *swap(stack_t **head, unsigned int line_number);
char *add(stack_t **head, unsigned int line_number);
char *nop(stack_t **head, unsigned int line_number);
char *sub(stack_t **head, unsigned int line_number);
char *div_fu(stack_t **head, unsigned int line_number);
char *mul(stack_t **head, unsigned int line_number);
char *mod(stack_t **head, unsigned int line_number);
char *pchar(stack_t **head, unsigned int line_number);

/*----------------queue function----------*/
void q_push(stack_t **head, unsigned int line_number);
void q_pop(stack_t **head, unsigned int line_number);
void q_pall(stack_t **head, unsigned int line_number);
void q_pint(stack_t **head, unsigned int line_number);
void q_swap(stack_t **head, unsigned int line_number);
void q_add(stack_t **head, unsigned int line_number);
void q_nop(stack_t **head, unsigned int line_number);
void q_sub(stack_t **head, unsigned int line_number);
void q_div_fu(stack_t **head, unsigned int line_number);
void q_mul(stack_t **head, unsigned int line_number);
void q_mod(stack_t **head, unsigned int line_number);
void q_pchar(stack_t **head, unsigned int line_number);

/*-------------memory managment-------*/
void free_memory(char **list);
void free_stack(stack_t **head);

/* error*/
void handle_error(List **list, stack_t **stack,
int line_number, char *type, char *msg1);
void stack_err(List **list, stack_t **stack, FILE *file, char *str, char *in, int ln);

/*------------linkedList--------------*/


char *exract(char *str, int first, int last);
void split_string(List **head, char *str, int line_number);
void execute_intructions(List **head, FILE *file);
void readFromFile(FILE *file);
instruction_t *Is_Instruction_exist(char *str);
void _push(List **head, char **content, int line_number);
void pull(List **head);
void free_linked_list(List **head);

char *check_prev(List **node);

#endif
