/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_haystackhaystack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 15:15:03 by lnicosia          #+#    #+#             */
/*   Updated: 2018/11/08 14:29:33 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!needle[0])
		return ((char*)haystack);
	while (haystack[i] && i < len)
	{
		if (needle[0] == haystack[i])
		{
			j = 0;
			while (needle[j] == haystack[i + j] && needle[j] && (i + j < len))
			{
				j++;
			}
			if (!needle[j])
				return ((char*)haystack + i);
		}
		i++;
	}
	return (0);
}
