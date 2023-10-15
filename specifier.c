#include "main.h"

/**
 * get_specifier - finds format function
 * @s: format
 * Return: number of bytes printed
 */



int (*get_specifier(char *s))(va_list ap, params_t *params)
{
specifier_t specifiers[] = {
{"c", print_char},
{"d", print_int},
{"i", print_int},
{"s", print_string},
{"%", print_percent},
{"b", print_binary},
{"o", print_octal},
{"u", print_unsigned},
{"x", print_hex},
{"X", print_HEX},
{"p", print_address},
{"S", print_S},
{"r", print_rev},
{"R", print_rot13},
{NULL, NULL}
};
int i = 0;
while (specifiers[i].specifier)
{
if (*s == specifiers[i].specifier[0])
{
return (specifiers[i].f);
}
i++;
}
return (NULL);
}

/**
 * get_print_func - finds format
 * @s: format
 * @ap: argument
 * @params: parameters
 * Return: the number of bytes printed
 */
int get_print_func(char *s, va_list ap, params_t *params)
{
int (*f)(va_list, params_t *) = get_specifier(s);

if (f)
return (f(ap, params));
return (0);
}

/**
 * get_flag - finds the flag
 * @s:format
 * @params: parameters
 * Return: if flag excists
 */
int get_flag(char *s, params_t *params)
{
/*switch num_1*/
int lp = 0;
switch (*s)
{
case '+':
lp = params->plus_flag = 1;
break;
case ' ':
lp = params->space_flag = 1;
break;
case '#':
lp = params->hashtag_flag = 1;
break;
case '-':
lp = params->minus_flag = 1;
break;
case '0':
lp = params->zero_flag = 1;
break;
}
return (lp);
}
/**
 * get_modifier - finds the modifier func
 * @s: the format string
 * @params: the parameters struct
 * Return: if modifier was valid
 */
int get_modifier(char *s, params_t *params)
{
/*switch num_2*/
int lp_1 = 0;
switch (*s)
{
case 'h':
lp_1 = params->h_modifier = 1;
break;
case 'l':
lp_1 = params->l_modifier = 1;
break;
}
return (lp_1);
}

/**
 * get_width - gets the width
 * @s: format
 * @params: parameters
 * @ap: argument
 * Return: return new ptr
 */
char *get_width(char *s, params_t *params, va_list ap)
{
int d = 0;
if (*s == '*')
{
d = va_arg(ap, int);
s++;
}
else
{
while (_isdigit(*s))
d = d * 10 + (*s++ - '0');
}
params->width = d;
return (s);
}

