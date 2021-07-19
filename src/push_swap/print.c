/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguerrer </var/mail/aguerrer>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/19 18:07:24 by aguerrer          #+#    #+#             */
/*   Updated: 2021/07/19 19:04:41 by aguerrer         ###   ########.fr       */
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

void	print_a(t_stack stack, t_opt opt, int imin, int imax)
{
	int		i;

	if (opt == NONE || opt == INSTR_ONLY)
		return ;
	i = 0;
	while (imin >= 0 && imax >= imin && i < stack.alen)
		ft_putnbr(stack.a[i++]);
}

void	print_b(t_stack stack, t_opt opt, int imin, int imax)
{
	int		i;

	if (opt == NONE || opt == INSTR_ONLY)
		return ;
	i = 0;
	while (imin >= 0 && imax >= imin && i < stack.blen)
		ft_putnbr(stack.b[i++]);
}
