/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstinsert.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <lnicosia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 10:37:43 by lnicosia          #+#    #+#             */
/*   Updated: 2021/03/25 12:43:36 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	Add new after the current node
*/

void	ft_dlstadd(t_dlist **lst, t_dlist *new)
{
	if (!new)
		return ;
	if (!(*lst))
	{
		*lst = new;
		return ;
	}
	new->prev = *lst;
	new->next = (*lst)->next;
	(*lst)->next = new;
}

/*
**	Add new before the current node
*/

void	ft_dlstreplace(t_dlist **lst, t_dlist *new)
{
	if (!new)
		return ;
	new->prev = (*lst)->prev;
	new->next = *lst;
	(*lst)->prev = new;
}

/*
**	Insert an item in a double linked list by using the given comparison function
*/

void	ft_dlstinsert(t_dlist **lst, t_dlist *new, int (*compare)(void *, void *))
{
	int	type;

	if (!new || !compare)
		return ;
	//ft_printf("Inserting %s\n", new->content);
	if (!(*lst))
	{
		*lst = new;
		return ;
	}
	type = 0;
	//ft_printf("Comparison between |%s| and |%s| = %d\n",
	//(*lst)->content, new->content, compare((*lst)->content, new->content));
	if (compare((*lst)->content, new->content) <= 0)
		type = 1;
	else
		type = -1;
	while (*lst && (*lst)->next && compare((*lst)->content, new->content) <= 0)
	{
		//ft_printf("next\n");
		*lst = (*lst)->next;
	}
	while (*lst && (*lst)->prev && compare((*lst)->content, new->content) > 0)
	{
		//ft_printf("previous\n");
		*lst = (*lst)->prev;
	}
	if (type == 1)
		ft_dlstadd(lst, new);
	else if (type == -1)
		ft_dlstreplace(lst, new);
}