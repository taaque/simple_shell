#include "ss_shell.h"
/**
 *ss_checkerfunc - checks for builtin_funcs
 *@ss_cmd: user_input tokenized
 *@ss_buff: buffer from getline_func
 *Return: if cmd_excuted 1, else 0
 */
int ss_checkerfunc(char **ss_cmd, char *ss_buff)
{
        /*first checking builtin functions*/
        if (ss_handle_builtinfunc(ss_cmd, ss_buff))
                return (1);
        else if (**ss_cmd == '/')
        {
                /*executing the command at position 0*/
                ss_executfunc(ss_cmd[0], ss_cmd);
                return (1);
        }
        return (0);
}
