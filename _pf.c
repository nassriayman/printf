#include "main.h"

/**
 * _printf - prints anything
 * @format: string
 * Return: number of bytes printed
 */
int _printf(const char *format, ...)
{
    int s = 0;
    va_list ptarg; 
    char *ptr, *start;
    prm_t prm = PARAMS_INIT; 
    va_start(ptarg, format); 
    if (!format || (format[0] == '%' && !format[1]))
        return (-1);
    if (format[0] == '%' && format[1] == ' ' && !format[2])
        return (-1);
    for (ptr = (char *)format; *ptr; ptr++)
    {
        init_prm(&prm, ptarg); 
        if (*ptr != '%')
        {
            s += _putchar(*ptr);
            continue;
        }
        start = ptr;
        ptr++;
        while (get_flag(ptr, &prm)) 
        {
            ptr++;
        }
        ptr = get_width(ptr, &prm, ptarg);
        ptr = get_precision(ptr, &prm, ptarg);
        if (get_modifier(ptr, &prm)) 
            ptr++;
        if (!get_specifier(ptr))
            s += print_from_to(start, ptr, 
                               prm.l_modifier || prm.h_modifier ? ptr - 1 : 0);
        else
            s += get_print_func(ptr, ptarg, &prm); 
    }
    _putchar(BUF_FLUSH);
    va_end(ptarg); 
    return (s);
}

