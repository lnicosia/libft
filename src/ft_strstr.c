/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 15:15:03 by lnicosia          #+#    #+#             */
/*   Updated: 2018/11/07 15:15:46 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = 0;
	str = ft_strdup(haystack);
	if (!needle[0])
		return (str);
	while (str[i])
	{
		if (needle[0] == haystack[i])
		{
			j = 0;
			while (needle[j] == str[i + j] && needle[j])
			{
				j++;
			}
			if (!needle[j])
				return (str + i);
		}
		i++;
	}
	return (0);
}
