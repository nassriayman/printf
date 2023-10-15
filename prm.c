#include "main.h"

/**
 * init_prm - prm
 * @prm: inputs
 * @ptarg: argument
 * Return: no return
 */
void init_prm(inputs_t *prm, va_list ptarg)
{
prm->unsign = 0;
prm->width = 0;
prm->precision = UINT_MAX;


prm->space_flag = 0;
prm->plus_flag = 0;
prm->hashtag_flag = 0;


prm->h_modifier = 0;
prm->l_modifier = 0;
prm->zero_flag = 0;
prm->minus_flag = 0;
(void)ptarg;
}
