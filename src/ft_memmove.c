/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 17:27:40 by lnicosia          #+#    #+#             */
/*   Updated: 2018/11/08 12:18:22 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	size_t		i;
	char		*tmp;
	const char	*source;

	tmp = dst;
	source = src;
	i = 0;
	while (i < n)
	{
		tmp[i] = source[i];
		i++;
	}
	return (dst);
}
