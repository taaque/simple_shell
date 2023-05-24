#include "ss_shell.h"

/**
* ss_appendpathfunc - adds_path to cmd
* @ss_path: pointer to path
* @ss_cmd: cmd pointer
*
* Return: Success returns buff containing_cmd with path
* else NULL
*/
char *ss_appendpathfunc(char *ss_path, char *ss_cmd)
{
	/*variables*/
	char *ss_buff;

	size_t k = 0, m = 0;
	/*check variable*/
	if (ss_cmd == 0)
		ss_cmd = "";
	if (ss_path == 0)
		ss_path = "";
	/*allocate memory*/
	ss_buff = malloc(sizeof(char) * (ss_strlen(ss_path) +
	/*count string length*/
	ss_strlen(ss_cmd) + 2));
	/*buffer is true*/
	if (!ss_buff)
		return (NULL);
	/*while path is true*/
	while (ss_path[k])
	{
		ss_buff[k] = ss_path[k];
		k++;
	}
	/*check for / character */
	if (ss_path[k - 1] != '/')
	{
		ss_buff[k] = '/';
		k++;
	}
	/*cmd inputis true*/
	while (ss_cmd[m])
	{
		ss_buff[k + m] = ss_cmd[m];
		m++;
	}
	ss_buff[k + m] = '\0';
	return (ss_buff);
}
