/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 11:09:45 by lnicosia          #+#    #+#             */
/*   Updated: 2018/11/07 14:42:14 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <ctype.h>

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
	ft_putendl("isalpha:\n");
	ft_putstr("is G alpha? isalpha: "); ft_putnbr(isalpha('z')); ft_putstr(" ft_isalpha: "); ft_putnbr(ft_isalpha('z'));
	ft_putendl("");
	return (0);
}
