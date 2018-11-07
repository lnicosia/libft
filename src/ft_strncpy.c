/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/08 11:42:58 by lnicosia          #+#    #+#             */
/*   Updated: 2018/08/16 19:09:29 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int i;

	i = 0;
	while (i < n && *src)
	{
		dest[i] = src[i];
		i++;
	}
	if (i < n)
	{
		while (dest[i])
		{
			dest[i] = '\0';
			i++;
		}
	}
	return (dest);
}
