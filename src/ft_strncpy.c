/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/08 11:42:58 by lnicosia          #+#    #+#             */
/*   Updated: 2018/11/07 12:37:30 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strncpy(char *dst, char *src, size_t len)
{
	size_t i;

	i = 0;
	while (i < len && *src)
	{
		dst[i] = src[i];
		i++;
	}
	if (i < len)
	{
		while (dst[i])
		{
			dst[i] = '\0';
			i++;
		}
	}
	return (dst);
}
