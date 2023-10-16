#include "main.h"

/**
 * _putchar - writes a character
 * @a:character
 * Return: On success 1 On error, -1 returned 
 */
int _putchar(int a)
{

static char buf[OUTPUT_BUF_SIZE];
static int lj;

if (a == BUF_FLUSH || lj >= OUTPUT_BUF_SIZE)
{
write(1, buf, lj);
lj = 0;
}
if (a != BUF_FLUSH)
buf[lj++] = a;
return (1);
}

/**
 * _puts - prints a
 * @str: string
 * Return: nothing
 */
int _puts(char *str)
{
char *ch = str;
while (*str)
_putchar(*str++);
return (str - ch);
}

/**
 * get_precision - gets the precision from the format string
 * @p: the format string
 * @prm: the parameters struct
 * @ptarg: argument pointer
 *
 * Return: new pointer
 */
char *get_precision(char *p, prm_t *prm, va_list ptarg)
{
int d = 0;

if (*p != '.')
return (p);
p++;
if (*p == '*')
{
d = va_arg(ptarg, int);
p++;
}
else
{
while (_isdigit(*p))
d = d * 10 + (*p++ - '0');
}
prm->precision = d;
return (p);
}

/**
 * get_flag - finds the flag
 * @s:format
 * @prm: parameters
 * Return: if flag exists
 */
int get_flag(char *s, prm_t *prm)
{
/*switch num_1*/
int lp = 0;
switch (*s)
{
case '+':
lp = prm->plus_flag = 1;
break;
case ' ':
lp = prm->space_flag = 1;
break;
case '#':
lp = prm->hashtag_flag = 1;
break;
case '-':
lp = prm->minus_flag = 1;
break;
case '0':
lp = prm->zero_flag = 1;
break;
}
return (lp);
}

/**
 * get_specifier - finds format function
 * @s: format
 * Return: number of bytes printed
 */
int (*get_specifier(char *s))(va_list ptarg, prm_t *prm)
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
int j = 0;
while (specifiers[j].specifier)
{
if (*s == specifiers[j].specifier[0])
{
return (specifiers[j].f);
}
j++;
}
return (NULL);
}

/**
 * get_print_func - finds format
 * @s: format
 * @ptarg: argument
 * @prm: parameters
 * Return: the number of bytes printed
 */
int get_print_func(char *s, va_list ptarg, prm_t *prm)
{
int (*f)(va_list, prm_t *) = get_specifier(s);

if (f)
return (f(ptarg, prm));
return (0);
}

/**
 * get_modifier - finds the modifier func
 * @s: the format string
 * @prm: the parameters struct
 * Return: if modifier was valid
 */
int get_modifier(char *s, prm_t *prm)
{
/*switch num_2*/
int lp_1 = 0;
switch (*s)
{
case 'h':
lp_1 = prm->h_modifier = 1;
break;
case 'l':
lp_1 = prm->l_modifier = 1;
break;
}
return (lp_1);
}

/**
 * get_width - gets the width
 * @s: format
 * @prm: parameters
 * @ptarg: argument
 * Return: return new ptr
 */
char *get_width(char *s, prm_t *prm, va_list ptarg)
{
int d = 0;
if (*s == '*')
{
d = va_arg(ptarg, int);
s++;
}
else
{
while (_isdigit(*s))
d = d * 10 + (*s++ - '0');
}
prm->width = d;
return (s);
}


