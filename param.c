#include "main.h"
void init_params(params_t *params, va_list ap)
{
	params->h_modifier = 0;
	params->hashtag_flag = 0;
	params->unsign = 0;
	params->l_modifier = 0;
	params->width = 0;
	params->minus_flag = 0;
	params->plus_flag = 0;
	params->space_flag = 0;
	params->precesion = UINT_MAX;
	params->zero_flag = 0 ;    
}
