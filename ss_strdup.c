#include "ss_shell.h"
/**
* ss_strdup - dupicates str
* @ss_str: str to duplicate
*
* Return: pointer to duplicate_str
*/
char *ss_strdup(char *ss_str)
{
        int k;
        int strlen;
        char *ssptr;

        /*check if the string is not null*/
        if (ss_str == NULL)
                return (NULL);
        /*get length of the string*/
        strlen = ss_strlen(ss_str);
        /*allocate memory for for dup*/
        ssptr = malloc(sizeof(char) * (strlen + 1));
        if (!ssptr)
                return (NULL);
        /*duplicate*/
        for (k = 0; *ss_str != '\0'; ss_str++, k++)
                ssptr[k] = ss_str[0];

        ssptr[k++] = '\0';
        /*return dup string pointer*/
        return (ssptr);
}
