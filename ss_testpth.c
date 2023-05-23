#include "ss_shell.h"

/**
*ss_testpathfunc - checks whether path is valid
* @ss_path: pointer to tokenized_pth
* @ss_cmd: ss_cmd input
*
* Return: on success pth_appended with cmd
* else NULL
*/
char *ss_testpathfunc(char *ss_path, char *ss_cmd)
{
        char *ssoutpt;

        int k = 0;
        /*while the path s true*/
        while (&ss_path[k])
        {
                /*append the path*/
                ssoutpt = ss_appendpathfunc(&ss_path[k], ss_cmd);
                /*if accessis true return output*/
                if (access(ssoutpt, F_OK | X_OK) == 0)
                        return (ssoutpt);
                /*free output buffer*/
                free(ssoutpt);
                k++;
        }
        return (NULL);
}
