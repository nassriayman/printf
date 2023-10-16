#include "main.h"

/**
 * print_address - print address
 * @ap: argument
 * @prm: parameters
 * Return: bytes printed
 */
int print_address(va_list ptarg, prm_t *prm)
{
unsigned long int nm_value1 = va_arg(ptarg, unsigned long int);
char *string_pointer;
if (!nm_value1)
return (_puts("(nil)"));
string_pointer = convert(nm_value1, 16, CONVERT_UNSIGNED | CONVERT_LOWERCASE, prm);
*--string_pointer = 'x';
*--string_pointer = '0';
return (print_number(string_pointer, prm));
}

/**
 * convert - converter functions
 * @num: number
 * @base: base
 * @flags: the argument
 * @prm: paramater 
 *
 * Return: string
 */
char *convert(long int num, int base, int flags, prm_t *prm)
{
static char *numbers_array;
static char buffer[50];
char sign_character = 0;
char *pointer;
unsigned long nm_value = num;
(void)prm;

if (!(flags & CONVERT_UNSIGNED) && num < 0)
{
nm_value = -num;
sign_character = '-';
}

numbers_array = flags & CONVERT_LOWERCASE ? "0123456789abcdef" : "0123456789ABCDEF";
pointer = &buffer[49];
*pointer = '\0';

do	{
*--pointer = numbers_array[nm_value % base];
nm_value /= base;
} while (nm_value != 0);

if (sign_character)
*--pointer = sign_character;
return (pointer);
}

/**
 * print_unsigned - prints int numbers
 * @ap: argument
 * @prm: parameters
 * Return: bytes printed
 */
int print_unsigned(va_list ptarg, prm_t *prm)
{
unsigned long ln_val;

if (prm->l_modifier)
ln_val = (unsigned long)va_arg(ptarg, unsigned long);
else if (prm->h_modifier)
ln_val = (unsigned short int)va_arg(ptarg, unsigned int);
else
ln_val = (unsigned int)va_arg(ptarg, unsigned int);
prm->unsign = 1;
return (print_number(convert(ln_val, 10, CONVERT_UNSIGNED, prm), prm));
}

