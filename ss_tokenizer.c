#include "ss_shell.h"

/**
* ss_tokenizerfunc - creates tokens from_input
* @ss_buff: input to tokenize
*
* Return: array_of_str
*/
char **ss_tokenizerfunc(char *ss_buff)
{
	/*variables*/
	char *ssbuffp = NULL, *ssbuff = NULL, *sstoken = NULL;
	char *ssdelim = " :\t\r\n";
	char **ss_tokens = NULL;
	int ss_toksize = 1;
	size_t ssindx = 0;
	size_t ssflag = 0;
	/*duplicate buffer*/
	ssbuff = ss_strdup(ss_buff);
	if (!ssbuff)/*if buffer is true*/
		return (NULL);
	ssbuffp = ssbuff;/*assign buffer input to ssbuffp*/
	while (*ssbuffp)/*while bufferp is true*/
	{
		if (ss_strchr(ssdelim, *ssbuffp) != NULL && ssflag == 0)/*check delimeter*/
		{
			ss_toksize++;/*increment tokenize variable*/
			ssflag = 1;
		}
		else if (ss_strchr(ssdelim, *ssbuffp) == NULL && ssflag == 1)
			ssflag = 0;
		ssbuffp++;
	}
	ss_tokens = malloc(sizeof(char *) * (ss_toksize + 1));/*allocate memory*/
	sstoken = strtok(ssbuff, ssdelim);/*tokenize*/
	while (sstoken)
	{
		ss_tokens[ssindx] = ss_strdup(sstoken);
		if (ss_tokens[ssindx] == NULL)
		{
			free(ss_tokens);/*free memory */
			return (NULL);
		}
		sstoken = strtok(NULL, ssdelim);
		ssindx++;
	}
	ss_tokens[ssindx] = '\0';
	free(ssbuff);/*free buffer*/
	return (ss_tokens);
}
