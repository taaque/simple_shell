#include "ss_shell.h"
/**
* ss_strchr - char locater in str
* @ss_str: str
* @ch: char to locate
*
* Return: pointer to first occurence char
* else NULL
*/
char *ss_strchr(char *ss_str, char ch)
{
	/*while string is true*/
	while (*ss_str)
	{
		/*check the character*/
		if (*ss_str == ch)
		{
			return (ss_str);
		}
		ss_str++;
	}
	/*if not the character return string*/
	if (!ch)
	{
		return (ss_str);
	}
	return (NULL);
}
/**
* ss_strcmp - compare_ 2_str
* @ss_str1: first str;
* @ss_str2: second str;
*
* Return: differ btwn two strs
*/
int ss_strcmp(char *ss_str1, char *ss_str2)
{
	int ssoutpt;
	int k = 0;

	/*while the condition is true */
	while (*(ss_str1 + k) == *(ss_str2 + k) && *(ss_str1 + k) != '\0')
		k++;
	/*get the difference*/
	ssoutpt = (*(ss_str1 + k) - *(ss_str2 + k));
	return (ssoutpt);
}
/**
* ss_strncmp - compares 2 strs up to n_bytes
* @ss_str1: first str
* @ss_str2: second str
* @k: num_of_bytes
*
* Return: differnce btwn 2 strs
*/
int ss_strncmp(char *ss_str1, char *ss_str2, int k)
{
	int j;

	/*for each character in str1 and str2*/
	for (j = 0; ss_str1[j] && ss_str2[j] && j < k; j++)
	{
		/*compare the string to a certain numberof bytes*/
		if (ss_str1[j] != ss_str2[j])
			return (ss_str1[j] - ss_str2[j]);
	}
	return (0);
}
/**
* ss_strlen - returns len of str
* @ss_str: str
*
* Return: len of str_passed
*/
int ss_strlen(char *ss_str)
{
	int cnt = 0;
	/*while not end of string*/
	while (*ss_str != '\0')
	{
		/*count*/
		cnt++;
		ss_str++;
	}
	return (cnt);
}
