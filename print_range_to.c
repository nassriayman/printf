#include "main.h"

/**
 * print_range_to - prints a range of char
 * @start: start
 * @stop: stop
 * @except: except
 * Return: number bytes printed
 */
int print_range_to(char *start, char *stop, char *except)
{
int sum = 0;
while (start <= stop)
{
if (start != except)
sum += _putchar(*start);
start++;
}
return (sum);
}

/**
 * print_rv - string in reverse
 * @ptarg: string
 * @prm: inputs
 * Return: number bytes printed
 */
int print_rv(va_list ptarg, inputs_t *prm)
{
int len, sum = 0;
char *str = va_arg(ptarg, char *);
(void)params;

if (str)
{
for (len = 0; *str; str++)
len++;
str--;
for (; len > 0; len--, str--)
sum += _putchar(*str);
}
return (sum);
}

/**
 * print_rotat13 - prints in rot13
 * @ptarg: string
 * @prm:inputs
 * Return: number bytes printed
 */
int print_rotat13(va_list ptarg, inputs_t *prm)
{
int j, index;
int coun = 0;
char array[] =
"NOPQRSTUVWXYZABCDEFGHIJKLM      nopqrstuvwxyzabcdefghijklm";
char *a = va_arg(ptarg, char *);
(void)prm;

j = 0;
index = 0;
while (a[j])
{
if ((a[j] >= 'A' && a[j] <= 'Z')
|| (a[j] >= 'a' && a[j] <= 'z'))
{
index = a[j] - 65;
coun += _putchar(array[index]);
}
else
coun += _putchar(a[j]);
j++;
}
return (coun);
}
