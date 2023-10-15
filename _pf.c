#include "main.h"

/**
 * _pf - prints any input by user
 * @fmt: string
 * Return: number of bytes printed
 */


int _pf(const char *fmt, ...)
{

va_list ptarg;

int sum = 0;

char *ip, *start;
inputs_t prm = PARMS_INITIALISATION;
va_start(ptarg, fmt);
if (!fmt || (fmt[0] == '%' && !fmt[1]))
return (-1);
if (fmt[0] == '%' && fmt[1] == ' ' && !fmt[2])
return (-1);
for (ip = (char *)fmt; *ip; ip++)
{
init_prm(&prm, ptarg);
if (*ip != '%')
{
sum += _putchar(*ip);
continue;
}
start = ip;
ip++;
while (get_flag(ip, &prm))
{
ip++;
}
ip = get_width(ip, &prm, ptarg);
ip = get_precision(ip, &prm, ptarg);
if (get_modifier(ip, &prm))
ip++;
if (!get_specifier(ip))
sum += print_range_to(start, ip,
prm.l_modifier || prm.h_modifier ? ip - 1 : 0);
else
sum += get_print_func(ip, ptarg, &prm);
}
_putchar(BUF_FLUSH);
va_end(ptarg);
return (sum);
}
