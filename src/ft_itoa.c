/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 13:20:20 by lnicosia          #+#    #+#             */
/*   Updated: 2018/11/09 14:00:36 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_itoa(int nbr)
{
	int		i;
	int		size;
	int		nb2;
	char	*str;

	i = 0;
	size = 0;
	nb2 = nbr;
	if (nbr < 0)
		size ++;
	if (nbr == 0)
		size++;
	while (nb2 != 0)
	{
		nb2 = nb2 / 10;
		size++;
	}
	if (!(str = ft_strnew(size)))
		return (0);
	if (nbr == -2147483648)
	{
		str[--size] = '-';
		str[--size] = '2';
		nbr = 147483648;
	}
	if (nbr < 0)
	{
		str[0] = '-';
		i = 1;
		nbr = -nbr;
	}
	while (size > i)
	{
		str[size - 1] = nbr % 10;
		nbr = nbr / 10;
		size--;
	}
	return (str);
}
