/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 11:51:04 by lnicosia          #+#    #+#             */
/*   Updated: 2018/11/12 13:37:08 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*res;
	t_list	*tmp;

	if (!lst || !f)
		return (NULL);
	res = ft_lstnew(f(lst)->content, sizeof(f(lst)));
	tmp = res;
	while (lst->next != NULL)
	{
		lst = lst->next;
		tmp->next = ft_lstnew(f(lst)->content, sizeof(f(lst)));
		tmp = tmp->next;
	}
	return (res);
}
