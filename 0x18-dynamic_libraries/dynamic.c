#include <unistd.h>
#include "main.h"

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 * Return: On success 1, -1 on error
 */
int _putchar(char c)
{
    return write(1, &c, 1);
}

/**
 * _islower - checks for lowercase character
 * @c: The character to check
 * Return: 1 if c is lowercase, 0 otherwise
 */
int _islower(int c)
{
    return (c >= 'a' && c <= 'z');
}

/**
 * _isalpha - checks for alphabetic character
 * @c: The character to check
 * Return: 1 if c is alphabetic, 0 otherwise
 */
int _isalpha(int c)
{
    return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}

/**
 * _abs - computes the absolute value of an integer
 * @n: The integer
 * Return: Absolute value of n
 */
int _abs(int n)
{
    return (n < 0) ? -n : n;
}

/**
 * _isupper - checks for uppercase character
 * @c: The character to check
 * Return: 1 if c is uppercase, 0 otherwise
 */
int _isupper(int c)
{
    return (c >= 'A' && c <= 'Z');
}

/**
 * _isdigit - checks for digit character
 * @c: The character to check
 * Return: 1 if c is a digit, 0 otherwise
 */
int _isdigit(int c)
{
    return (c >= '0' && c <= '9');
}

/**
 * _strlen - returns the length of a string
 * @s: The string
 * Return: Length of the string
 */
int _strlen(char *s)
{
    int len = 0;

    while (s[len])
        len++;
    return len;
}

/**
 * _puts - prints a string to stdout
 * @s: The string to print
 */
void _puts(char *s)
{
    while (*s)
        _putchar(*s++);
}

/**
 * _strcpy - copies a string
 * @dest: Destination string
 * @src: Source string
 * Return: Pointer to dest
 */
char *_strcpy(char *dest, char *src)
{
    char *ptr = dest;

    while ((*ptr++ = *src++));
    return dest;
}

/**
 * _atoi - converts a string to an integer
 * @s: The string to convert
 * Return: The integer
 */
int _atoi(char *s)
{
    int num = 0;

    while (*s >= '0' && *s <= '9') {
        num = num * 10 + (*s - '0');
        s++;
    }
    return num;
}

/**
 * _strcat - concatenates two strings
 * @dest: Destination string
 * @src: Source string
 * Return: Pointer to dest
 */
char *_strcat(char *dest, char *src)
{
    char *ptr = dest + _strlen(dest);

    while ((*ptr++ = *src++));
    return dest;
}

/**
 * _strncat - concatenates two strings with n bytes from src
 * @dest: Destination string
 * @src: Source string
 * @n: Number of bytes to concatenate
 * Return: Pointer to dest
 */
char *_strncat(char *dest, char *src, int n)
{
    char *ptr = dest + _strlen(dest);

    while (n-- && (*ptr++ = *src++));
    *ptr = '\0';
    return dest;
}

/**
 * _strncpy - copies a string up to n bytes
 * @dest: Destination string
 * @src: Source string
 * @n: Number of bytes to copy
 * Return: Pointer to dest
 */
char *_strncpy(char *dest, char *src, int n)
{
    char *ptr = dest;

    while (n-- && (*ptr++ = *src++));
    while (n-- > 0)
        *ptr++ = '\0';
    return dest;
}

/**
 * _strcmp - compares two strings
 * @s1: First string
 * @s2: Second string
 * Return: Negative if s1 < s2, positive if s1 > s2, 0 if equal
 */
int _strcmp(char *s1, char *s2)
{
    while (*s1 && (*s1 == *s2)) {
        s1++;
        s2++;
    }
    return (*s1 - *s2);
}

/**
 * _memset - fills memory with a constant byte
 * @s: Pointer to memory area
 * @b: The byte to set
 * @n: Number of bytes to set
 * Return: Pointer to s
 */
char *_memset(char *s, char b, unsigned int n)
{
    char *ptr = s;

    while (n--)
        *ptr++ = b;
    return s;
}

/**
 * _memcpy - copies memory area
 * @dest: Destination memory area
 * @src: Source memory area
 * @n: Number of bytes to copy
 * Return: Pointer to dest
 */
char *_memcpy(char *dest, char *src, unsigned int n)
{
    char *ptr = dest;

    while (n--)
        *ptr++ = *src++;
    return dest;
}

/**
 * _strchr - locates a character in a string
 * @s: The string
 * @c: The character to locate
 * Return: Pointer to first occurrence of c or NULL
 */
char *_strchr(char *s, char c)
{
    while (*s) {
        if (*s == c)
            return s;
        s++;
    }
    return NULL;
}

/**
 * _strspn - gets the length of a prefix substring
 * @s: The string
 * @accept: The characters to match
 * Return: Number of bytes in the initial segment of s
 */
unsigned int _strspn(char *s, char *accept)
{
    unsigned int count = 0;

    while (*s && _strchr(accept, *s++))
        count++;
    return count;
}

/**
 * _strpbrk - locates the first occurrence of any of the bytes
 * @s: The string
 * @accept: The characters to match
 * Return: Pointer to the byte in s or NULL
 */
char *_strpbrk(char *s, char *accept)
{
    while (*s) {
        if (_strchr(accept, *s))
            return s;
        s++;
    }
    return NULL;
}

/**
 * _strstr - locates a substring
 * @haystack: The string to search in
 * @needle: The substring to find
 * Return: Pointer to the beginning of the located substring or NULL
 */
char *_strstr(char *haystack, char *needle)
{
    char *h = haystack, *n;

    while (*h) {
        n = needle;
        char *start = h;

        while (*n && (*h == *n)) {
            h++;
            n++;
        }
        if (!*n)
            return start;

        h = start + 1;
    }
    return NULL;
}

