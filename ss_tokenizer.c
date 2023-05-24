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
	/*if buffer is true*/
	if (!ssbuff)
		return (NULL);
	/*assign buffer input to ssbuffp*/
	ssbuffp = ssbuff;

	/*while bufferp is true*/
	while (*ssbuffp)
	{
		/*check delimeter*/
		if (ss_strchr(ssdelim, *ssbuffp) != NULL && ssflag == 0)
		{
			/*increment tokenize variable*/
			ss_toksize++;
			ssflag = 1;
		}
		else if (ss_strchr(ssdelim, *ssbuffp) == NULL && ssflag == 1)
			ssflag = 0;
		ssbuffp++;
	}
	/*allocate memory*/
	ss_tokens = malloc(sizeof(char *) * (ss_toksize + 1));
	/*tokenize*/
	sstoken = strtok(ssbuff, ssdelim);
	while (sstoken)
	{
		ss_tokens[ssindx] = ss_strdup(sstoken);
		if (ss_tokens[ssindx] == NULL)
		{
			/*free memory */
			free(ss_tokens);
			return (NULL);
		}
		sstoken = strtok(NULL, ssdelim);
		ssindx++;
	}
	ss_tokens[ssindx] = '\0';
	/*free buffer*/
	free(ssbuff);
	return (ss_tokens);
}
