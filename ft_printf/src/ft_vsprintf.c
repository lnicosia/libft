/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vsprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/13 10:27:50 by lnicosia          #+#    #+#             */
/*   Updated: 2020/05/01 18:44:24 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_vsprintf(char *restrict str, const char *restrict format, va_list ap)
{
	t_data	data;

	if (!format)
		return (-1);
	init_data(&data, 1);
	data.str = str;
	data.mode = STR;
	va_copy(data.ap, ap);
	parse_format(format, &data);
	str[data.i] = '\0';
	return (data.ret);
}
