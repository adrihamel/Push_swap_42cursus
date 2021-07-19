/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguerrer </var/mail/aguerrer>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/19 18:18:48 by aguerrer          #+#    #+#             */
/*   Updated: 2021/07/19 19:03:22 by aguerrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	quick_sort_3(t_stack *stack, t_fun *fun_list, t_opt opt)
{
	if (stack->a[0] < stack->a[1] && stack->a[0] < stack->a[2])
	{
		if (stack->a[1] > stack->a[2])
			follow_instructions(stack, fun_list, "rra sa", opt);
	}
	else if (stack->a[0] > stack->a[1] && stack->a[0] > stack->a[2])
	{
		if (stack->a[1] < stack->a[2])
			ra(stack, opt);
		else
			follow_instructions(stack, fun_list, "sa rra", opt);
	}
	else
	{
		if (stack->a[1] < stack->a[2])
			sa(stack, opt);
		else
			rra(stack, opt);
	}
}

void	sort_3(t_stack *stack, t_fun *fun_list, int len, t_opt opt)
{
	if (len == 3 && stack->alen == 3)
		quick_sort_3(stack, fun_list, opt);
	else if (len == 2)
	{
		if (stack->a[0] > stack->a[1])
			sa(stack, opt);
	}
	else if (len == 3)
	{
		while (len != 3 || !(stack->a[0] < stack->a[1] \
					&& stack->a[1] < stack->a[2]))
		{
			if (len == 3 && stack->a[0] > stack->a[1] && stack->a[2])
				sa(stack, opt);
			else if (len == 3 && !(stack->a[2] > stack->a[0] \
						&& stack->a[2] > stack->a[1]))
			{
				pb(stack, opt);
				len--;
			}
			else if (stack->a[0] > stack->a[1])
				sa(stack, opt);
			else if (len++)
				pa(stack, opt);
		}
	}
}

void	push_sort_3(t_stack *stack, t_fun *fun_list, int len, t_opt opt)
{
	if (len == 1)
		pa(stack, opt);
	else if (len == 2)
	{
		if (stack->b[0] < stack->b[1])
			sb(stack, opt);
		follow_instructions(stack, fun_list, "pa pa", opt);
	}
	else if (len == 3)
	{
		while (len || !(stack->a[0] < stack->a[1] && stack->a[1] < stack->a[2]))
		{
			if (len == 1 && stack->a[0] > stack->a[1])
				sa(stack, opt);
			else if (len == 1 || (len >= 2 && stack->b[0] > stack->b[1]) \
					|| (len == 3 && stack->b[0] > stack->b[2]))
			{
				pa(stack, opt);
				len--;
			}
			else
				sb(stack, opt);
		}
	}
}
