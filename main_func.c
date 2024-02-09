
#include "monty.h"

/**
 * _strlen- _strlen function for getting the len of the string
 * @str: string.
 *
 * Return: return length of str.
 */

int _strlen(char *str)
{
	int i = 0, len = 0;

	if (str == NULL)
		return (0);

	while (str[i] != '\0')
	{
		len += 1;
		i++;
	}
	return (len);
}

/**
 * _isequal- _isequal function for checking if two strings is equal.
 * @str1: string 1
 * @str2: string 2.
 *
 * Return: return 0 if str1 == str2 and -1 if not.
 */

int _isequal(char *str1, char *str2)
{
	int i = 0;

	if (str1 == NULL)
		return (-1);
	if (_strlen(str1) != _strlen(str2))
	{
		return (-1);
	}
	while (str1[i] != '\0')
	{
		if (str1[i] != str2[i] && str1[i] != str2[i] + 32 && str1[i] + 32 != str2[i])
			return (-1);
		i++;
	}
	return (0);
}
/**
 * getArraylen- getArraylen function for getting list of struct length
 * @array: array.
 *
 * Return: return length of array.
 */
int getArraylen(instruction_t *array)
{
	int i = 0, len = 0;

	if (array == NULL)
		return (0);
	while (array[i].opcode != NULL)
	{
		len++;
		i++;
	}
	return (len + 1);
}

/**
 * isElementDigit- this function is for checking is the elment full
 *  digit or has char if it's digit we return it if not we return nd=nondigit.
 * @elem: string 1
 *
 * Return: return digit or nd if elemnt not a digit.
 */
char *isElementDigit(char *elem)
{
	int i = 0;

	while (elem[i] != '\0')
	{
		char *c = &elem[i];

		if (atoi(c) == 0 && _isequal(c, "0") != 0)
		{
			return ("nd");
		}
		i++;
	}
	return (elem);
}
