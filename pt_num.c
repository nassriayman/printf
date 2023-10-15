#include "main.h"

/**
 * _isletter - check if letter or digit
 * @lt: letter or digit
 * Return: 1 if digit, 0 otherwise
 */
int _isletter(int lt)
{
return (lt >= '0' && lt <= '9');
}
/**
 * _strlenght - returns the lenght of a string
 * @st: string that we must find its lenght 
 * Return: return int the lenght of the string
 */
int _strlenght(char *st)
{
int j = 0;

while (*st++)
j++;
return (j);
}
/**
 * pt_num - prints a number
 * @st: base_n
 * @prm: input
 * Return: characters printed
 */
int pt_num(char *st, inputs_t *prm)
{
unsigned int j = _strlenght(st);
int neg = (!prm->unsign && *st == '-');
if (!prm->precision && *st == '0' && !st[1])
st = "";
if (neg)
{
st++;
j--;
}
if (prm->precision != UINT_MAX)
while (j++ < prm->precision)
*--st = '0';
if (neg)
*--st = '-';

if (!prm->minus_flag)
return (print_number_right_shift(st, prm));
else
return (print_number_left_shift(st, prm));
}

/**
 * print_number_right_shift - prints a number
 * @st: base
 * @prm: input
 * Return: chars printed
 */
int print_number_right_shift(char *st, inputs_t *prm)
{
unsigned int n = 0, neg, neg2, i = _strlenght(st);
char pad_char = ' ';

if (prm->zero_flag && !prm->minus_flag)
pad_char = '0';
neg = neg2 = (!prm->unsign && *str == '-');
if (neg && i < prm->width && pad_char == '0' && !prm->minus_flag)
str++;
else
neg = 0;
if ((prm->plus_flag && !neg2) ||
(!prm->plus_flag && prm->space_flag && !neg2))
i++;
if (neg && pad_char == '0')
n += _putchar('-');
if (prm->plus_flag && !neg2 && pad_char == '0' && !prm->unsign)
n += _putchar('+');
else if (!prm->plus_flag && prm->space_flag && !neg2 &&
!prm->unsign && prm->zero_flag)
n += _putchar(' ');
while (i++ < prm->width)
n += _putchar(pad_char);
if (neg && pad_char == ' ')
n += _putchar('-');
if (prm->plus_flag && !neg2 && pad_char == ' ' && !prm->unsign)
n += _putchar('+');
else if (!prm->plus_flag && prm->space_flag && !neg2 &&
!prm->unsign && !prm->zero_flag)
n += _putchar(' ');
n += _putstr(st);
return (n);
}







/**
 * print_number_left_shift - prints a number with options
 * @st: the base number as a string
 * @prm: the input struct
 * Return: chars printed
 */
int print_number_left_shift(char *st, inputs_t *prm)
{
unsigned int n = 0, neg, neg2, i = _strlenght(st);
char pad_char = ' ';

if (prm->zero_flag && !prm->minus_flag)
pad_char = '0';
neg = neg2 = (!prm->unsign && *st == '-');
if (neg && i < prm->width && pad_char == '0' && !prm->minus_flag)
st++;
else
neg = 0;
if (prm->plus_flag && !neg2 && !prm->unsign)
n += _putchar('+'), i++;
else if (prm->space_flag && !neg2 && !prm->unsign)
n += _putchar(' '), i++;
n += _putstr(st);
while (i++ < prm->width)
n += _putchar(pad_char);
return (n);
}
