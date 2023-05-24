#include "ss_shell.h"

/**
* _putchar - writes char to stdout
* @ch: character
*
* Return: Success 1.
* Error, -1
*/
int _putchar(char ch)
{
	return (write(1, &ch, 1));
}

/**
* ss_printfunc - print_str
* @ss_str: str
*
* Return: num of char_printed
*/
int ss_printfunc(char *ss_str)
{
	int k = 0;
	/*while string is true*/
	while (ss_str[k] != '\0')
	{
		/*put character*/
		_putchar(ss_str[k]);
		k++;
	}

	return (k);
}
