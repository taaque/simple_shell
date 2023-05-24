#include "ss_shell.h"
/**
* ss_printenvfunc - printing env string
*
* Return: non
*/
void ss_printenvfunc(void)
{
	int k = 0;
	char **ssenv = environ;
	/*iterate through environment string*/
	while (ssenv[k])
	{
		/*write standard output file number*/
		write(STDOUT_FILENO, (const void *)ssenv[k], ss_strlen(ssenv[k]));
		write(STDOUT_FILENO, "\n", 1);

		k++;
	}
}
