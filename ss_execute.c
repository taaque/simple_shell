#include "ss_shell.h"

/**
 * ss_executfunc - executes cmd inputs
 *@ss_pathcmd: single pointer to ss_pathcmd
 *@ss_cmd: to vector_array of cmd_pointers
 *
 * Return: 0
 */
void ss_executfunc(char *ss_pathcmd, char **ss_cmd)
{
	/*child process id*/
	pid_t ss_cpid;
	int ss_stat;

	/*pointer to envornment*/
	char **ssenv = environ;

	/*fork child process*/
	ss_cpid = fork();
	if (ss_cpid < 0)
		perror(ss_pathcmd);
	if (ss_cpid == 0)
	{
		/*execute*/
		execve(ss_pathcmd, ss_cmd, ssenv);
		/*check errors*/
		perror(ss_pathcmd);
		/*free memory*/
		free(ss_pathcmd);
		ss_freebuffunc(ss_cmd);
		exit(98);
	}
	else
		wait(&ss_stat);
}
