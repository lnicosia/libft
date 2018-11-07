/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 15:49:01 by lnicosia          #+#    #+#             */
/*   Updated: 2018/11/07 15:52:21 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = 0;
	str = ft_strdup(s);
	while (str[i])
	{
		if (c == s[i])
			j = i;
		i++;
	}
	return (str + j);
}
