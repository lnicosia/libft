/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_noprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 15:03:58 by lnicosia          #+#    #+#             */
/*   Updated: 2020/05/01 18:45:17 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_noprintf(const char *restrict format, ...)
{
	t_data	data;

	if (!format)
		return (-1);
	init_data(&data, 1);
	data.mode = NO_PRINT;
	va_start(data.ap, format);
	parse_format(format, &data);
	va_end(data.ap);
	return (data.ret);
}
