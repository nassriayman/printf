#include "main.h"

/**
 * init_prm - Initialize parameters
 * @prm: modified parameters structure 
 * @ptarg: argument list
 * Return: nothing to return
 */
void init_prm(prm_t *prm, va_list ptarg)
{
prm->unsign = 0;
prm->space_flag = 0;
prm->width = 0;
prm->minus_flag = 0;
prm->hashtag_flag = 0;
prm->h_modifier = 0;
prm->precision = UINT_MAX;
prm->plus_flag = 0;
prm->l_modifier = 0;
prm->zero_flag = 0;
(void)ptarg;
}
/**
 * print_number_right_shift - prints a number
 * @str: base
 * @prm: parameter
 * Return: chars printed
 */
int print_number_right_shift(char *str, prm_t *prm)
{
unsigned int n = 0, neg, neg2, j = _strlen(str);
char pad_char = ' ';

if (prm->zero_flag && !prm->minus_flag)
pad_char = '0';
neg = neg2 = (!prm->unsign && *str == '-');
if (neg && j < prm->width && pad_char == '0' && !prm->minus_flag)
str++;
else
neg = 0;
if ((prm->plus_flag && !neg2) ||
(!prm->plus_flag && prm->space_flag && !neg2))
j++;
if (neg && pad_char == '0')
n += _putchar('-');
if (prm->plus_flag && !neg2 && pad_char == '0' && !prm->unsign)
n += _putchar('+');
else if (!prm->plus_flag && prm->space_flag && !neg2 &&
!prm->unsign && prm->zero_flag)
n += _putchar(' ');
while (j++ < prm->width)
n += _putchar(pad_char);
if (neg && pad_char == ' ')
n += _putchar('-');
if (prm->plus_flag && !neg2 && pad_char == ' ' && !prm->unsign)
n += _putchar('+');
else if (!prm->plus_flag && prm->space_flag && !neg2 &&
!prm->unsign && !prm->zero_flag)
n += _putchar(' ');
n += _puts(str);
return (n);
}

/**
 * print_number_left_shift - prints a number with options
 * @str: the base number as a string
 * @prm: the parameter struct
 * Return: chars printed
 */
int print_number_left_shift(char *str, prm_t *prm)
{
unsigned int n = 0, neg, neg2, j = _strlen(str);
char pad_char = ' ';

if (prm->zero_flag && !prm->minus_flag)
pad_char = '0';
neg = neg2 = (!prm->unsign && *str == '-');
if (neg && j < prm->width && pad_char == '0' && !prm->minus_flag)
str++;
else
neg = 0;
if (prm->plus_flag && !neg2 && !prm->unsign)
n += _putchar('+'), j++;
else if (prm->space_flag && !neg2 && !prm->unsign)
n += _putchar(' '), j++;
n += _puts(str);
while (j++ < prm->width)
n += _putchar(pad_char);
return (n);
}

/**
 * _isdigit - check character
 * @c: character
 * Return: 1 if digit, 0 otherwise
 */
int _isdigit(int c)
{
return (c >= '0' && c <= '9');
}

/**
 * _strlen - returns the length of a string
 * @s: string whose length to check
 * Return: integer length of string
 */
int _strlen(char *s)
{
int j = 0;

while (*s++)
j++;
return (j);
}

/**
 * print_number - prints a number
 * @str: base
 * @prm: parameter
 * Return: chars printed
 */
int print_number(char *str, prm_t *prm)
{
unsigned int j = _strlen(str);
int neg = (!prm->unsign && *str == '-');
if (!prm->precision && *str == '0' && !str[1])
str = "";
if (neg)
{
str++;
j--;
}
if (prm->precision != UINT_MAX)
while (j++ < prm->precision)
*--str = '0';
if (neg)
*--str = '-';

if (!prm->minus_flag)
return (print_number_right_shift(str, prm));
else
return (print_number_left_shift(str, prm));
}

