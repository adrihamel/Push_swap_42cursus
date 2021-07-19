/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguerrer </var/mail/aguerrer>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/19 18:07:24 by aguerrer          #+#    #+#             */
/*   Updated: 2021/07/19 18:37:15 by aguerrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include <unistd.h>
#include "libft.h"

void	print_instr(char *instr, t_opt opt)
{
	if (opt == NONE)
		return ;
	else
	{
		ft_putstr(instr);
		ft_putchar('\n');
	}
}

void	print_a(t_piles piles, t_opt opt, int imin, int imax)
{
	int		i;

	if (opt == NONE || opt == INSTR_ONLY)
		return ;
	ft_putstr("a :\t");
	i = 0;
	while (imin >= 0 && imax >= imin && i < piles.alen)
	{
		if (i < imin)
			ft_putnbr(piles.a[i++]);
		else if (i >= imin && i <= imax)
			ft_putnbr((piles.a[i++]));
		else
			ft_putnbr(piles.a[i++]);
		ft_putchar(' ');
	}
	if (!i)
	{
		while (i < piles.alen)
		{
			ft_putnbr(piles.a[i++]);
			ft_putchar(' ');
		}
	}
	ft_putstr("\n");
}

void	print_b(t_piles piles, t_opt opt, int imin, int imax)
{
	int		i;

	if (opt == NONE || opt == INSTR_ONLY)
		return ;
	ft_putstr("b :\t");
	i = 0;
	while (imin >= 0 && imax >= imin && i < piles.blen)
	{
		if (i < imin)
			ft_putnbr(piles.b[i++]);
		else if (i >= imin && i <= imax)
			ft_putnbr((piles.b[i++]));
		else
			ft_putnbr(piles.b[i++]);
		ft_putchar(' ');
	}
	if (!i)
	{
		while (i < piles.blen)
		{
			ft_putnbr(piles.b[i++]);
			ft_putchar(' ');
		}
	}
	ft_putstr("\n");
}
