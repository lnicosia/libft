/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/12 20:11:49 by lnicosia          #+#    #+#             */
/*   Updated: 2018/11/07 12:19:42 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int				ft_strlen2(char *str)
{
	int len;

	len = 0;
	while (str[len] != '\0')
	{
		len++;
	}
	return (len);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	srclen;
	unsigned int	destlen;

	i = size;
	srclen = ft_strlen2(src);
	destlen = ft_strlen2(dest);
	while (*dest)
	{
		dest++;
		if (i > 0)
			i--;
	}
	while (*src && i > 1)
	{
		*dest = *src;
		src++;
		dest++;
		i--;
	}
	*dest = '\0';
	if (size > destlen)
		return (srclen + destlen);
	return (size + srclen);
}
