#include "ss_shell.h"

/**
 * ss_executfunc - executes cmd inputs
 *@ssinfo1: single pointer to ss_info->ss_pathcmd
 *@ssinfo2: ss_info->ss_cmd to vector_array of cmd pointers
 *
 * Return: 0
 */
void ss_executfunc(char *ss_pathcmd, char **ss_cmd)
{
        pid_t ss_cpid;
        int ss_stat;

        char **ssenv = environ;

        ss_cpid = fork();
        if (ss_cpid < 0)
                perror(ss_pathcmd);
        if (ss_cpid == 0)
        {
                execve(ss_pathcmd, ss_cmd, ssenv);
                perror(ss_pathcmd);
                free(ss_pathcmd);
                ss_freebuffunc(ss_cmd);
                exit(98);
        }
        else
                wait(&ss_stat);
}
