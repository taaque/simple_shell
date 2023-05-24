#include "ss_shell.h"
/**
 *ss_handlesignalfunc - track interactive_mode
 *@k: signal_num
 *Return: non
 */
void ss_handlesignalfunc(int k)
{
	/*signal number from input*/
	(void)k;
	/*write standard error file number*/
	write(STDERR_FILENO, "\n", 1);
	write(STDERR_FILENO, "$ ", 2);
}
