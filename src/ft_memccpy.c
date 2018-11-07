/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 17:27:40 by lnicosia          #+#    #+#             */
/*   Updated: 2018/11/07 18:00:05 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			i;
	char			*str;
	const char		*source;
	unsigned char	cchar;

	cchar = c;
	str = dst;
	source = src;
	i = 0;
	while (i < n)
	{
		str[i] = source[i];
		if (source[i] == cchar)
			return (str + i);
		i++;
	}
	return (0);
}
