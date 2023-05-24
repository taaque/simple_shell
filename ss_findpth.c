#include "ss_shell.h"

/**
* ss_findpathfunc - path_find from global_enviroment
*
* Return: Null, if path not_found else path_is_found.
*/
char *ss_findpathfunc(void)
{
	/*variables*/
	int k;

	char **ssenv = environ;
	char *sspath = NULL;

	/*if environment true*/
	while (*ssenv)
	{
		/*compare*/
		if (ss_strncmp(*ssenv, "PATH=", 5) == 0)
		{
			sspath = *ssenv;
			/*while sspath true*/
			while (*sspath && k < 5)
			{
				sspath++;
				k++;
			}
			return (sspath);
		}
		/*increment*/
		ssenv++;
	}
	return (NULL);
}
