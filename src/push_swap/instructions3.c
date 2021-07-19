/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguerrer </var/mail/aguerrer>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/19 18:04:59 by aguerrer          #+#    #+#             */
/*   Updated: 2021/07/19 19:03:04 by aguerrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	rrr(t_stack *stack, t_opt opt)
{
	print_instr("rrr", opt);
	rra(stack, NONE);
	rrb(stack, NONE);
	if (stack->alen > 1)
		print_a(*stack, opt, 0, 0);
	else
		print_a(*stack, opt, -1, -1);
	if (stack->blen > 1)
		print_b(*stack, opt, 0, 0);
	else
		print_b(*stack, opt, -1, -1);
}
