#include "ss_shell.h"
/**
* main - main call stack
* @ss_argc: args_count
* @ss_argv: args_vector
* @envp: env_vector
*
* Return: 0
*/
int main(int ss_argc, char *ss_argv[], char *envp[])
{
	char *SS_BUFF;

	ss_info ssinfo[] = {SSINFO_INIT};
	ssize_t ss_linesize = 0;
	size_t BUFF_SIZE = 1024;
	(void)ss_argc, (void)envp;
	if (ss_argc < 1)
		return (-1);
	signal(SIGINT, ss_handlesignalfunc);
	for (;;)
	{
		ss_freebuffunc(ssinfo->ss_cmd);/* free ss_cmd, ss_paths and ss_pathcmd */
		ss_freebuffunc(ssinfo->ss_paths);
		free(ssinfo->ss_pathcmd);
		ss_promptfunc();/* display prompt and get input */
		ss_linesize = getline(&SS_BUFF, &BUFF_SIZE, stdin);
		if (ss_linesize < 0) /* check some conditions */
			break;
		ssinfo->ss_linecnt++;
		if (SS_BUFF[ss_linesize - 1] == '\n')
			SS_BUFF[ss_linesize - 1] = '\0';
		ssinfo->ss_cmd = ss_tokenizerfunc(SS_BUFF);
		if (ssinfo->ss_cmd == NULL || *ssinfo->ss_cmd == NULL
			|| **ssinfo->ss_cmd == '\0')
			continue;
		if (ss_checkerfunc(ssinfo->ss_cmd, SS_BUFF))
			continue;
		ssinfo->ss_path = ss_findpathfunc();/* find path and tokenize */
		ssinfo->ss_paths = ss_tokenizerfunc(ssinfo->ss_path);
		ssinfo->ss_pathcmd = &(*ss_testpathfunc(ssinfo->ss_path, ssinfo->ss_cmd[0]));
		if (!ssinfo->ss_pathcmd)
			perror(ss_argv[0]);
		else
			ss_executfunc(ssinfo->ss_pathcmd, ssinfo->ss_cmd);/*exec of pathcmd, cmd*/
	}
	if (ss_linesize < 0 && ss_flags.ss_interactive)
		write(STDERR_FILENO, "\n", 1);
	free(SS_BUFF);
	return (0);
}
