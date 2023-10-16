#include "main.h"

/**
 * print_octal - prints octal numbers
 * @ptarg: argument
 * @prm: parameters
 * Return: bytes
 */
int print_octal(va_list ptarg, prm_t *prm)
{
    unsigned long num_oct;
    char *str;
    int count = 0;

    if (prm->l_modifier)
        num_oct = (unsigned long)va_arg(ptarg, unsigned long);
    else if (prm->h_modifier)
        num_oct = (unsigned short int)va_arg(ptarg, unsigned int);
    else
        num_oct = (unsigned int)va_arg(ptarg, unsigned int);

    str = convert(num_oct, 8, CONVERT_UNSIGNED, prm);
    if (prm->hashtag_flag && num_oct)
        *--str = '0';
    prm->unsign = 1;

    return (count += print_number(str, prm));
}

/**
 * print_hex - prints unsigned hex
 * @ptarg: argument
 * @prm: parameters
 * Return: bytes printed
 */
int print_hex(va_list ptarg, prm_t *prm)
{
    unsigned long num_hex;
    int count = 0;
    char *str;

    if (prm->l_modifier)
        num_hex = (unsigned long)va_arg(ptarg, unsigned long);
    else if (prm->h_modifier)
        num_hex = (unsigned short int)va_arg(ptarg, unsigned int);
    else
        num_hex = (unsigned int)va_arg(ptarg, unsigned int);

    str = convert(num_hex, 16, CONVERT_UNSIGNED | CONVERT_LOWERCASE, prm);
    if (prm->hashtag_flag && num_hex)
    {
        *--str = 'x';
        *--str = '0';
    }
    prm->unsign = 1;

    return (count += print_number(str, prm));
}

/**
 * print_HEX - prints hex numbers UPPER
 * @ptarg: argument
 * @prm: parameters
 * Return: bytes printed
 */
int print_HEX(va_list ptarg, prm_t *prm)
{
    unsigned long num_HEX;
    int count = 0;
    char *str;

    if (prm->l_modifier)
        num_HEX = (unsigned long)va_arg(ptarg, unsigned long);
    else if (prm->h_modifier)
        num_HEX = (unsigned short int)va_arg(ptarg, unsigned int);
    else
        num_HEX = (unsigned int)va_arg(ptarg, unsigned int);

    str = convert(num_HEX, 16, CONVERT_UNSIGNED, prm);
    if (prm->hashtag_flag && num_HEX)
    {
        *--str = 'X';
        *--str = '0';
    }
    prm->unsign = 1;

    return (count += print_number(str, prm));
}

/**
 * print_binary - prints binary
 * @ptarg: argument
 * @prm: parameters
 * Return: bytes printed
 */
int print_binary(va_list ptarg, prm_t *prm)
{
    unsigned int num_bin = va_arg(ptarg, unsigned int);
    char *str = convert(num_bin, 2, CONVERT_UNSIGNED, prm);
    int count = 0;

    if (prm->hashtag_flag && num_bin)
        *--str = '0';
    prm->unsign = 1;

    return (count += print_number(str, prm));
}

