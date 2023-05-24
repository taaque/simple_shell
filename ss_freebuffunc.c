#include "ss_shell.h"
/**
* ss_freebuffunc - free_ss_Buff
* @ss_buff: buffer
*
* Return: non
*/
void ss_freebuffunc(char **ss_buff)
{
	int k = 0;
	/*check if buffer is not empty*/
	if (!ss_buff || ss_buff == NULL)
	{
		return;
	}
	while (ss_buff[k])
	{
		/*free the buffer*/
		free(ss_buff[k]);
		/*increament k*/
		k++;
	}
	free(ss_buff);
}
