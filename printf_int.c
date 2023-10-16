#include "main.h"

/**
 * print_percent - prints string
 * @ptarg: argument
 * @prm: parameters
 * Return: number of chars printed
 */
int print_percent(va_list ptarg, prm_t *prm)
{
    (void)ptarg;
    (void)prm;
    return (_putchar('%'));
}

/**
 * print_string - prints string
 * @ptarg: argument
 * @prm: parameters
 * Return: number chars printed
 */
int print_string(va_list ptarg, prm_t *prm)
{
    char *str = va_arg(ptarg, char *), pdd_char = ' ';
    unsigned int pdd = 0, sum = 0, i = 0, j;
    (void)prm;
    switch ((int)(!str))
    case 1:
        str = NULL_STRING;
        j = pdd = _strlen(str);
        if (prm->precision < pdd)
            j = pdd = prm->precision;
        if (prm->minus_flag)
        {
            if (prm->precision != UINT_MAX)
                for (i = 0; i < pdd; i++)
                    sum += _putchar(*str++);
            else
                sum += _puts(str);
        }
        while (j++ < prm->width)
            sum += _putchar(pdd_char);
        if (!prm->minus_flag)
        {
            if (prm->precision != UINT_MAX)
                for (i = 0; i < pdd; i++)
                    sum += _putchar(*str++);
            else
                sum += _puts(str);
        }
        return (sum);
}

/**
 * print_char - prints char
 * @ptarg: argument
 * @prm: parameters
 * Return: number chars
 */
int print_char(va_list ptarg, prm_t *prm)
{
    char pad_char = ' ';
    unsigned int pad = 1, sum = 0, ch = va_arg(ptarg, int);
    if (prm->minus_flag)
        sum += _putchar(ch);
    while (pad++ < prm->width)
        sum += _putchar(pad_char);
    if (!prm->minus_flag)
        sum += _putchar(ch);
    return (sum);
}

/**
 * print_S - specifier
 * @ptarg: argument
 * @prm: parameters
 * Return: number chars printed
 */
int print_S(va_list ptarg, prm_t *prm)
{
    char *str = va_arg(ptarg, char *);
    char *hex;
    int sum = 0;
    if ((int)(!str))
        return (_puts(NULL_STRING));
    for (; *str; str++)
    {
        if ((*str > 0 && *str < 32) || *str >= 127)
        {
            sum += _putchar('\\');
            sum += _putchar('x');
            hex = convert(*str, 16, 0, prm);
            if (!hex[1])
                sum += _putchar('0');
            sum += _puts(hex);
        }
        else
            sum += _putchar(*str);
    }
    return (sum);
}

/**
 * print_int - prints int
 * @ptarg: argument
 * @prm: parameters
 * Return: the number int printed
 */
int print_int(va_list ptarg, prm_t *prm)
{
    long l;
    if (prm->l_modifier)
        l = va_arg(ptarg, long);
    else if (prm->h_modifier)
        l = (short int)va_arg(ptarg, int);
    else
        l = (int)va_arg(ptarg, int);
    return (print_number(convert(l, 10, 0, prm), prm));
}

