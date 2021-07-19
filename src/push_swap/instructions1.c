/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguerrer </var/mail/aguerrer>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/19 18:04:33 by aguerrer          #+#    #+#             */
/*   Updated: 2021/07/19 19:01:09 by aguerrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "utils.h"

void	sa(t_stack *stack, t_opt opt)
{
	print_instr("sa", opt);
	if (stack->alen > 1)
	{
		ft_array_swap(stack->a, 0, 1);
		print_a(*stack, opt, 0, 1);
	}
	else
		print_a(*stack, opt, -1, -1);
	print_b(*stack, opt, -1, -1);
}

void	sb(t_stack *stack, t_opt opt)
{
	print_instr("sb", opt);
	print_a(*stack, opt, -1, -1);
	if (stack->blen > 1)
	{
		ft_array_swap(stack->b, 0, 1);
		print_b(*stack, opt, 0, 1);
	}
	else
		print_b(*stack, opt, -1, -1);
}

void	ss(t_stack *stack, t_opt opt)
{
	print_instr("ss", opt);
	sb(stack, NONE);
	sa(stack, NONE);
	if (stack->alen > 1)
		print_a(*stack, opt, 0, 1);
	else
		print_a(*stack, opt, -1, -1);
	if (stack->blen > 1)
		print_b(*stack, opt, 0, 1);
	else
		print_b(*stack, opt, -1, -1);
}

void	pa(t_stack *stack, t_opt opt)
{
	int		i;

	print_instr("pa", opt);
	if (stack->blen)
	{
		stack->alen++;
		i = stack->alen;
		while (--i > 0)
			stack->a[i] = stack->a[i - 1];
		stack->a[0] = stack->b[0];
		i = -1;
		stack->blen--;
		while (++i < stack->blen)
			stack->b[i] = stack->b[i + 1];
		print_a(*stack, opt, 0, 0);
	}
	else
		print_a(*stack, opt, -1, -1);
	print_b(*stack, opt, -1, -1);
}

void	pb(t_stack *stack, t_opt opt)
{
	int		i;

	print_instr("pb", opt);
	if (stack->alen)
	{
		stack->blen++;
		i = stack->blen;
		while (--i > 0)
			stack->b[i] = stack->b[i - 1];
		stack->b[0] = stack->a[0];
		i = -1;
		stack->alen--;
		while (++i < stack->alen)
			stack->a[i] = stack->a[i + 1];
		print_a(*stack, opt, -1, -1);
		print_b(*stack, opt, 0, 0);
	}
	else
	{
		print_a(*stack, opt, -1, -1);
		print_b(*stack, opt, -1, -1);
	}
}
