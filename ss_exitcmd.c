#include "ss_shell.h"
/**
* ss_exitcmdfunc - exit_cmd_handling
* @ss_cmd: cmd_tokenized
* @ss_buff: input_buffer from_stdin
*
* Return: non
*/
void ss_exitcmdfunc(char **ss_cmd, char *ss_buff)
{
	/*free buffer memory*/
	free(ss_buff);
	/*free the cmd tokenized input*/
	ss_freebuffunc(ss_cmd);
	/*exit*/
	exit(0);
}
