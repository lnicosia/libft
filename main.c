/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 11:09:45 by lnicosia          #+#    #+#             */
/*   Updated: 2018/11/07 12:10:50 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		main(int argc, char **argv)
{
	(void) argc;
	(void) argv;
	
	ft_putendl("This is a test for my own libft");
	ft_putendl("\nputnbr:\n");
	ft_putnbr(-2147483648); ft_putchar('\n');
	ft_putnbr(2147483647); ft_putchar('\n');
	ft_putnbr(0); ft_putchar('\n');
	ft_putnbr(24); ft_putchar('\n');
	
	ft_putendl("\nstrlen:\n");
	ft_putstr("Bonjour is "); ft_putnbr(ft_strlen("Bonjour")); ft_putendl(" char long\n");
	return (0);
}
