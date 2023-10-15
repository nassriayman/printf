#include "main.h"


/**
 * print_HEX - prints hex numbers UPPER
 * @ptarg:argument
 * @prm: the inputs struct
 * Return: bytes printed
 */
int print_HEX(va_list ptarg, inputs_t *prm)
{
unsigned long ln_1;
int ch = 0;
char *str;

if (prm->l_modifier)
ln_1 = (unsigned long)va_arg(ptarg, unsigned long);
else if (prm->h_modifier)
ln_1 = (unsigned short int)va_arg(ptarg, unsigned int);
else
ln_1 = (unsigned int)va_arg(ptarg, unsigned int);

str = convert(ln_1, 16, CONVERT_UNSIGNED, prm);
if (prm->hashtag_flag && ln_1)
{
*--str = 'X';
*--str = '0';
}
prm->unsign = 1;
return (ch += pt_num(str, prm));
}


/**
 * print_octal - prints octal numbers
 * @ptarg:argument
 * @prm:inputs
 * Return: bytes
 */
int print_octal(va_list ptarg, inputs_t *prm)
{
unsigned long l;
char *str;
int counter = 0;

if (prm->l_modifier)
l = (unsigned long)va_arg(ptarg, unsigned long);
else if (prm->h_modifier)
l = (unsigned short int)va_arg(ptarg, unsigned int);
else
l = (unsigned int)va_arg(ptarg, unsigned int);
str = convert(l, 8, CONVERT_UNSIGNED, prm);
if (prm->hashtag_flag && l)
*--str = '0';
prm->unsign = 1;
return (counter += pt_num(str, prm));
}


/**
 * print_binary - prints binary
 * @ptarg: argument
 * @prm: inputs
 * Return: bytes printed
 */
int print_binary(va_list ptarg, inputs_t *prm)
{
unsigned int number = va_arg(ptarg, unsigned int);
char *str = convert(num, 2, CONVERT_UNSIGNED, prm);
int counter = 0;

if (prm->hashtag_flag && number)
*--str = '0';
prm->unsign = 1;
return (counter += pt_num(str, prm));
}

/**
 * print_hex - prints unsigned hex
 * @ptarg:argument
 * @prm: inputs
 * Return: bytes printed
 */
int print_hex(va_list ptarg, inputs_t *prm)
{
unsigned long ln;
int ch = 0;
char *str;

if (prm->l_modifier)
ln = (unsigned long)va_arg(ptarg, unsigned long);
else if (prm->h_modifier)
ln = (unsigned short int)va_arg(ptarg, unsigned int);
else
ln = (unsigned int)va_arg(ptarg, unsigned int);

str = convert(ln, 16, CONVERT_UNSIGNED | CONVERT_LOWERCASE, prm);
if (prm->hashtag_flag && ln)
{
*--str = 'x';
*--str = '0';
}
prm->unsign = 1;
return (ch += pt_num(str, prm));
}

