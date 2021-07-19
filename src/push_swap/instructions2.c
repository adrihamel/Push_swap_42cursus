/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguerrer </var/mail/aguerrer>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/19 18:04:46 by aguerrer          #+#    #+#             */
/*   Updated: 2021/07/19 19:02:40 by aguerrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	ra(t_stack *stack, t_opt opt)
{
	int		i;
	int		tmp;

	print_instr("ra", opt);
	if (stack->alen > 1)
	{
		tmp = stack->a[0];
		i = -1;
		while (++i < stack->alen - 1)
			stack->a[i] = stack->a[i + 1];
		stack->a[stack->alen - 1] = tmp;
		print_a(*stack, opt, stack->alen - 1, stack->alen - 1);
	}
	else
		print_a(*stack, opt, -1, -1);
	print_b(*stack, opt, -1, -1);
}

void	rb(t_stack *stack, t_opt opt)
{
	int		i;
	int		tmp;

	print_instr("rb", opt);
	print_a(*stack, opt, -1, -1);
	if (stack->blen > 1)
	{
		tmp = stack->b[0];
		i = -1;
		while (++i < stack->blen - 1)
			stack->b[i] = stack->b[i + 1];
		stack->b[stack->blen - 1] = tmp;
		print_b(*stack, opt, stack->blen - 1, stack->blen - 1);
	}
	else
		print_b(*stack, opt, -1, -1);
}

void	rr(t_stack *stack, t_opt opt)
{
	print_instr("rr", opt);
	ra(stack, NONE);
	rb(stack, NONE);
	if (stack->alen > 1)
		print_a(*stack, opt, stack->alen - 1, stack->alen - 1);
	else
		print_a(*stack, opt, -1, -1);
	if (stack->blen > 1)
		print_b(*stack, opt, stack->blen - 1, stack->blen - 1);
	else
		print_b(*stack, opt, -1, -1);
}

void	rra(t_stack *stack, t_opt opt)
{
	int		i;
	int		tmp;

	print_instr("rra", opt);
	if (stack->alen > 1)
	{
		tmp = stack->a[stack->alen - 1];
		i = stack->alen;
		while (--i > 0)
			stack->a[i] = stack->a[i - 1];
		stack->a[0] = tmp;
		print_a(*stack, opt, 0, 0);
	}
	else
		print_a(*stack, opt, -1, -1);
	print_b(*stack, opt, -1, -1);
}

void	rrb(t_stack *stack, t_opt opt)
{
	int		i;
	int		tmp;

	print_instr("rrb", opt);
	print_a(*stack, opt, -1, -1);
	if (stack->blen > 1)
	{
		tmp = stack->b[stack->blen - 1];
		i = stack->blen;
		while (--i > 0)
			stack->b[i] = stack->b[i - 1];
		stack->b[0] = tmp;
		print_b(*stack, opt, 0, 0);
	}
	else
		print_b(*stack, opt, -1, -1);
}
