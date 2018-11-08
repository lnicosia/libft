/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 15:49:01 by lnicosia          #+#    #+#             */
/*   Updated: 2018/11/08 16:56:50 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;
	int	res;

	i = 0;
	res = 0;
	if (!s[i])
		return (0);
	if (c == '\0')
	{
		while (s[i])
			i++;
		return ((char*)s + i);
	}
	while (s[i])
	{
		if (c == s[i])
			res = i;
		i++;
	}
	return ((char*)s + res);
}
