#include "main.h"


/**
 * _putchar - writes a character
 * @ch:character
 * Return: On success 1 On error, -1 returned 
 */
int _putchar(int c)
{
static int p;
static char buf[OUTPUT_BUF_SIZE];

if (ch == BUF_FLUSH || p >= OUTPUT_BUF_SIZE)
{
write(1, buf, p);
p = 0;
}
if (ch != BUF_FLUSH)
buf[p++] = ch;
return (1);
}


/**
 * _putstr - prints a string
 * @st: string
 * Return: nothing to return
 */
int _putstr(char *st)
{
char *ch = st;
while (*st)
_putchar(*st++);
return (st - ch);
}
