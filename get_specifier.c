#include "main.h"

/**
 * get_width - gets the width
 * @fmt: format
 * @prm: inputs
 * @ptarg: argument
 * Return: return new ip
 */
char *get_width(char *fmt, inputs_t *prm, va_list ptarg)
{
    int d = 0;
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
    prm->width = d;
    return (fmt);
}

/**
 * get_modifier - finds the modifier func
 * @fmt: the format string
 * @prm: the parameters struct
 * Return: if modifier was valid
 */
int get_modifier(char *fmt, inputs_t *prm)
{
    int p_1 = 0;
    switch (*fmt)
    {
    case 'h':
        p_1 = prm->h_modifier = 1;
        break;
    case 'l':
        p_1 = prm->l_modifier = 1;
        break;
    }
    return (p_1);
}

/**
 * get_flag - finds the flag
 * @fmt: format
 * @prm: parameters
 * Return: if flag excists
 */
int get_flag(char *fmt, inputs_t *prm)
{
    int p = 0;
    switch (*fmt)
    {
    case '+':
        p = prm->plus_flag = 1;
        break;
    case ' ':
        p = prm->space_flag = 1;
        break;
    case '#':
        p = prm->hashtag_flag = 1;
        break;
    case '-':
        p = prm->minus_flag = 1;
        break;
    case '0':
        p = prm->zero_flag = 1;
        break;
    }
    return (p);
}

/**
 * get_print_funct - finds format
 * @fmt: format
 * @ptarg: argument
 * @prm: parameters
 * Return: the number of bytes printed
 */
int get_print_funct(char *fmt, va_list ptarg, inputs_t *prm)
{
    int (*f)(va_list, inputs_t *) = get_specifier(fmt);

    if (f)
        return (f(ptarg, prm));
    return (0);
}

/**
 * get_specifier - finds format function
 * @fmt: format
 * Return: number of bytes printed
 */
int (*get_specifier(char *fmt))(va_list ptarg, inputs_t *prm)
{
    specifier_t specifiers[] = {
	{"b", print_binary},        
	{"c", print_char},
        {"d", print_int},
        {"i", print_int},
        {"s", print_string},
        {"%", print_percent},
        {"o", print_octal},
        {"u", print_unsigned},
        {"x", print_hex},
        {"X", print_HEX},
        {"p", print_add},
        {"S", print_S},
        {"r", print_rv},
        {"R", print_rotat13},
        {NULL, NULL}
    };
    int i = 0;
    while (specifiers[i].specifier)
    {
        if (*fmt == specifiers[i].specifier[0])
        {
            return (specifiers[i].f);
        }
        i++;
    }
    return (NULL);
}
