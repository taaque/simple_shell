#ifndef SHELL_H
#define SHELL_H
/* ss_shell header files*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include <stdbool.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <stdarg.h>
/*initialize ss_info args*/
#define SSINFO_INIT {NULL, NULL, 0, 0, NULL, NULL}
/* external env_vargs */
extern char **environ;
extern __sighandler_t signal(int __sig, __sighandler_t __handler);
/**
* struct myss_info - contains args to pass into a funct,
* provides uniform prototype for funct pointer struct
* @ss_pathcmd: a string from path command
* @ss_path: the file path
* @ss_linecnt: counts the number of lines
* @ss_finalexit: the final exit
* @ss_cmd: contains the command
* @ss_paths: containts the paths
*/
typedef struct myss_info
{
	char *ss_pathcmd;
	char *ss_path;
	int ss_linecnt;
	int ss_finalexit;
	char **ss_cmd;
	char **ss_paths;
} ss_info;
/**
* struct myss_builtin - contains builtin args to pass into a funct,
* @ss_env: environment variable
* @ss_exit: the exit argument
*/
typedef struct myss_builtin
{
	char *ss_env;
	char *ss_exit;
} ss_builtin;
/**
* struct myss_flags - contains bool flag arg to pass into a funct,
* @ss_interactive: check if interactive
*/
struct myss_flags
{
	bool ss_interactive;
} ss_flags;
char *ss_appendpathfunc(char *, char *);
int ss_checkerfunc(char **, char *);
char *ss_testpathfunc(char *, char *);
void ss_promptfunc(void);
void ss_handlesignalfunc(int k);
char **ss_tokenizerfunc(char *);
void ss_exitcmdfunc(char **, char *);
int ss_handle_builtinfunc(char **, char *ss_buff);
void ss_printenvfunc(void);
void ss_executfunc(char *, char **);
char *ss_findpathfunc(void);
void ss_freebuffunc(char **);
int ss_strncmp(char *ss_str1, char *ss_str2, int k);
char *ss_strdup(char *ss_str);
char *ss_strchr(char *, char c);
int ss_strcmp(char *, char *);
int ss_strlen(char *);
int ss_printfunc(char *ss_str);
int _putchar(char c);
int ss_printfunc(char *ss_str);
#endif
