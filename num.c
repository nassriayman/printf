#include "main.h"

/**
 * cvt - a functions converter for printf
 * @num: number
 * @base_n: base of number, refers to number of digits for a number
 * @flgs: argument
 * @prm: input 
 *
 * Return: string of array
 */
char *cvt(long int num, int base_n, int flgs, inputs_t *prm)
{
static char *arr;
static char buffer[50];
char sign_n = 0;
char *ip;
unsigned long n = num;
(void)prm;

if (!(flgs & CONVERT_UNSIGNED) && num < 0)
{
n = -num;
sign_n = '-';

}
arr = flgs & CONVERT_LOWERCASE ? "0123456789abcdef" : "0123456789ABCDEF";
ip = &buffer[49];
*ip = '\0';

do	{
*--ip = arr[n % base_n];
n /= base_n;
} while (n != 0);

if (sign_n)
*--ip = sign_n;
return (ip);
}

/**
 * pt_int - prints integral unsigned numbers
 * @ptarg: argument
 * @prm: inputs
 * Return: bytes printed of an input number
 */
int print_int(va_list ptarg, inputs_t *prm)
{
unsigned long ln;

if (prm->l_modifier)
ln = (unsigned long)va_arg(ptarg, unsigned long);
else if (prm->h_modifier)
ln = (unsigned short int)va_arg(ptarg, unsigned int);
else
ln = (unsigned int)va_arg(ptarg, unsigned int);
prm->unsign = 1;
return (pt_num(cvt(ln, 10, CONVERT_UNSIGNED, prm), prm));
}


/**
 * print_add - print the address of an input
 * @ptarg: argument
 * @prm: inputs
 * Return: bytes printed
 */
int print_add(va_list ptarg, inputs_t *prm)
{
unsigned long int n_1 = va_arg(ptarg, unsigned long int);
char *str;
if (!n_1)
return (_puts("(nil)"));
str = cvt(n_1, 16, CONVERT_UNSIGNED | CONVERT_LOWERCASE, prm);
*--str = 'x';
*--str = '0';
return (pt_num(str, prm));
}
