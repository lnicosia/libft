/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 11:09:45 by lnicosia          #+#    #+#             */
/*   Updated: 2018/11/07 15:13:17 by lnicosia         ###   ########.fr       */
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
	ft_putstr("\nis Z alpha? isalpha: "); ft_putnbr(isalpha('Z')); ft_putstr(" ft_isalpha: "); ft_putnbr(ft_isalpha('Z'));
	ft_putstr("\nis @ alpha? isalpha: "); ft_putnbr(isalpha('@')); ft_putstr(" ft_isalpha: "); ft_putnbr(ft_isalpha('@'));

	ft_putendl("\n\nisdigit:\n");
	ft_putstr("is 0 digit? isdigit: "); ft_putnbr(isdigit('0')); ft_putstr(" ft_isdigit: "); ft_putnbr(ft_isdigit('0'));
	ft_putstr("\nis 9 digit? isdigit: "); ft_putnbr(isdigit('9')); ft_putstr(" ft_isdigit: "); ft_putnbr(ft_isdigit('9'));
	ft_putstr("\nis / digit? isdigit: "); ft_putnbr(isdigit('/')); ft_putstr(" ft_isdigit: "); ft_putnbr(ft_isdigit('/'));
	ft_putstr("\nis : digit? isdigit: "); ft_putnbr(isdigit('/')); ft_putstr(" ft_isdigit: "); ft_putnbr(ft_isdigit(':'));

	ft_putendl("\n\nisalnum:");
	ft_putstr("\nis 0 alnum? isalnum: "); ft_putnbr(isalnum('0')); ft_putstr(" ft_isalnum: "); ft_putnbr(ft_isalnum('0'));
	ft_putstr("\nis / alnum? isalnum: "); ft_putnbr(isalnum('/')); ft_putstr(" ft_isalnum: "); ft_putnbr(ft_isalnum('/'));
	ft_putstr("\nis A alnum? isalnum: "); ft_putnbr(isalnum('A')); ft_putstr(" ft_isalnum: "); ft_putnbr(ft_isalnum('A'));
	ft_putstr("\nis @ alnum? isalnum: "); ft_putnbr(isalnum('@')); ft_putstr(" ft_isalnum: "); ft_putnbr(ft_isalnum('@'));
	ft_putendl("");
	return (0);
}
