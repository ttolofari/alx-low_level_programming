#include "main.h"

int is_palindrome_helper(char *s, int i, int len);
int get_length(char *s);

/**
 * is_palindrome - checks if a string is a palindrome
 * @s: string to reverse
 *
 * Return: 1 if it is, 0 it's not
 */
int get_length(char *s)
{
	if (*s == '\0')
	{
		return (0);
	}
	else
	{
		return (1 + get_length(s + 1));
	}
}

/**
 * get_length - gets the length of the string
 * @s: string to obtain s
 *
 * Return: length of string
 */
int is_palindrome_helper(char *s, int start, int end)
{
	if (start >= end)
	{
		return (1);
	}
	if (s[start] != s[end])
	{
		return (0);
	}
	return (is_palindrome_helper(s, start + 1, end - 1));
}

/**
 * is_palindrome_helper - helper function to check
 * if string is palindrome recursively
 * @s: string to check
 * @start: position to begin
 * @end: position to end
 *
 * Return: the check if palindrome
 */
int is_palindrome(char *s)
{
	int length = get_length(s);
	return (is_palindrome_helper(s, 0, length - 1));
}
