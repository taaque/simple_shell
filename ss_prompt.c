#include "ss_shell.h"
/**
* ss_promptfunc - printing "$ " for input
* if interactive_mode prints the prompt
* Return: non
*/
void ss_promptfunc(void)
{
        /*check if interactive*/
        if ((isatty(STDIN_FILENO) == 1) && (isatty(STDOUT_FILENO) == 1))
                /*interactive*/
                ss_flags.ss_interactive = 1;
        if (ss_flags.ss_interactive)
                /*write error*/
                write(STDERR_FILENO, "$ ", 2);
}
