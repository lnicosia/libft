/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstdelfront.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <lnicosia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 10:33:21 by lnicosia          #+#    #+#             */
/*   Updated: 2021/03/25 11:40:09 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_dlstpopfront(t_dlist **alst)
{
	t_dlist	*new;

	if (!alst)
		return ;
	new = (*alst)->next;
	if ((*alst)->content)
		free((*alst)->content);
	free(*alst);
	*alst = new;
}


void	ft_dlstdelfront(t_dlist **lst)
{
	while (*lst && (*lst)->prev)
		*lst = (*lst)->prev;
	while (*lst)
		ft_dlstpopfront(lst);
}
