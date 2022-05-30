/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 15:03:58 by lnicosia          #+#    #+#             */
/*   Updated: 2020/05/01 18:45:17 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int			ft_bprintf(int force_flush, const char *restrict format, ...)
{
	static t_data	data;
	static int		first_call = 1;

	if (first_call == 1)
	{
		write(1, "First call\n", 11);
		init_data(&data, 1);
		first_call = 0;
	}
	if (!format)
		return (-1);
	reset_options(&data);
	data.ret = 0;
	va_start(data.ap, format);
	parse_format(format, &data);
	if (force_flush == 1)
	{
		write(1, data.buffer, data.i);
		data.i = 0;
	}
	va_end(data.ap);
	return (data.ret);
}
