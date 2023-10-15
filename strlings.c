#include "main.h"

/**
 * get_precision - gets the precision from the format string
 * @fmt: the format string
 * @prm: the parameters struct
 * @ptarg: argument pointer
 *
 * Return: new pointer
 */
char *get_precision(char *fmt, inputs_t *prm, va_list ptarg)
{
    int d = 0;

    if (*fmt != '.')
        return (fmt);
    fmt++;
    if (*fmt == '*')
    {
        d = va_arg(ptarg, int);
        fmt++;
    }
    else
    {
        while (_isletter(*fmt))
            d = d * 10 + (*fmt++ - '0');
    }
    prm->precision = d;
    return (fmt);
}
