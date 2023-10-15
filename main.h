#ifndef _PRINTF_H
#define _PRINTF_H

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include <limits.h>
#include <stdlib.h>

#define OUTPUT_BUF_SIZE 1024
#define BUF_FLUSH -1


#define NULL_STRING "(null)"

#define PARMS_INITIALISATION {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}

#define CONVERT_LOWERCASE	1
#define CONVERT_UNSIGNED	2

/**
 * struct parameters - parameters struct
 * @unsign: flag if unsigned value
 * @plus_flag: on if plus_flag specified
 * @space_flag: on if hashtag_flag specified
 * @hashtag_flag: on if _flag specified
 * @zero_flag: on if _flag specified
 * @minus_flag: on if _flag specified
 * @width: field width specified
 * @precision: field precision specified
 * @h_modifier: on if h_modifier is specified
 * @l_modifier: on if l_modifier is specified
 */
typedef struct inputs
{
	unsigned int unsign			: 1;

	unsigned int plus_flag		: 1;
	unsigned int space_flag		: 1;
	unsigned int hashtag_flag	: 1;
	unsigned int zero_flag		: 1;
	unsigned int minus_flag		: 1;

	unsigned int width;
	unsigned int precision;

	unsigned int h_modifier		: 1;
	unsigned int l_modifier		: 1;
} inputs_t;

/**
 * struct specifier - Struct token
 * @specifier: format token
 * @f: The function associated
 */
typedef struct specifier
{
	char *specifier;
	int (*f)(va_list, inputs_t *);
} specifier_t;

int _putstr(char *str);
int _putchar(int ch);

int print_chr(va_list ptarg, inputs_t *prm);

int print_string(va_list ptarg, inputs_t *prm);
int print_percent(va_list ptarg, inputs_t *prm);



int get_modifier(char *sum, inputs_t *prm);
int print_unsigned(va_list ptarg, inputs_t *prm);
int print_add(va_list ptarg, inputs_t *prm);

int (*get_specifier(char *sum))(va_list ptarg, inputs_t *prm);


char *cvt(long int num, int base, int flags, inputs_t *prm);
char *get_width(char *sum, inputs_t *prm, va_list ptarg);

int print_hex(va_list ptarg, inputs_t *prm);
int print_HEX(va_list ptarg, inputs_t *prm);
int print_binary(va_list ptarg, inputs_t *prm);
int print_octal(va_list ptarg, inputs_t *prm);
int print_int(va_list ptarg, inputs_t *prm);
int print_S(va_list ptarg, inputs_t *prm);

int get_print_funct(char *sum, va_list ptarg, inputs_t *prm);
int get_flag(char *sum, inputs_t *prm);
int print_range_to(char *start, char *stop, char *except);
int print_rv(va_list ptarg, inputs_t *prm);
int print_rotat13(va_list ptarg, inputs_t *prm);

int _isletter(int ch);
int _strlenght(char *sum);
int pt_num(char *str, inputs_t *prm);
int print_number_right_shift(char *str, inputs_t *prm);
int print_number_left_shift(char *str, inputs_t *prm);

void init_prm(inputs_t *prm, va_list ptarg);

char *get_precision(char *p, inputs_t *prm, va_list ptarg);

int _printf(const char *fmt, ...);







#endif



