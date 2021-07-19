/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguerrer </var/mail/aguerrer>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/19 18:20:17 by aguerrer          #+#    #+#             */
/*   Updated: 2021/07/19 19:03:43 by aguerrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	quick_sort_a(t_stack *stack, t_fun *fun_list, int len, t_opt opt)
{
	int		mediane;
	int		nb_elem;
	int		pushed_under;

	if (is_sorted(stack->a, len, ASCENDING))
		return (1);
	nb_elem = len;
	if (len <= 3)
	{
		sort_3(stack, fun_list, len, opt);
		return (1);
	}
	pushed_under = 0;
	if (!get_mediane(&mediane, stack->a, len))
		return (0);
	while (len != nb_elem / 2 + nb_elem % 2)
	{
		if (stack->a[0] < mediane && (len--))
			pb(stack, opt);
		else if ((++pushed_under))
			ra(stack, opt);
	}
	while (nb_elem / 2 + nb_elem % 2 != stack->alen && pushed_under--)
		rra(stack, opt);
	return (quick_sort_a(stack, fun_list, nb_elem / 2 + nb_elem % 2, opt)
		&& quick_sort_b(stack, fun_list, nb_elem / 2, opt));
	return (1);
}

int	quick_sort_b(t_stack *stack, t_fun *fun_list, int len, t_opt opt)
{
	int		mediane;
	int		nb_elem;
	int		pushed_under;

	pushed_under = 0;
	if (is_sorted(stack->b, len, DESCENDING))
		while (len--)
			pa(stack, opt);
	if (len <= 3)
	{
		push_sort_3(stack, fun_list, len, opt);
		return (1);
	}
	nb_elem = len;
	if (!get_mediane(&mediane, stack->b, len))
		return (0);
	while (len != nb_elem / 2)
	{
		if (stack->b[0] >= mediane && len--)
			pa(stack, opt);
		else if (++pushed_under)
			rb(stack, opt);
	}
	while (nb_elem / 2 != stack->blen && pushed_under--)
		rrb(stack, opt);
	return (quick_sort_a(stack, fun_list, nb_elem / 2 + nb_elem % 2, opt)
		&& quick_sort_b(stack, fun_list, nb_elem / 2, opt));
}
