#include "ss_shell.h"

/**
* ss_handle_builtinfunc  - builtin_func execution handler
* @ss_cmd: tokenized ss_cmd
* @ss_buff: buffer input from stdin
*
* Return: 1 if executed, else 0
*/

int ss_handle_builtinfunc(char **ss_cmd, char *ss_buff)
{
	/*struct builtin*/
	ss_builtin ssbuiltin[] = {{"env", "exit"}};
	/*compare*/
	if (ss_strcmp(*ss_cmd, ssbuiltin->ss_env) == 0)
	{
		/*print envirnment*/
		ss_printenvfunc();
		return (1);
	}
	else if (ss_strcmp(*ss_cmd, ssbuiltin->ss_exit) == 0)
	{
		/*exit command*/
		ss_exitcmdfunc(ss_cmd, ss_buff);
		return (1);
	}
	return (0);
}
