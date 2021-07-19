/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguerrer </var/mail/aguerrer>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/19 18:20:17 by aguerrer          #+#    #+#             */
/*   Updated: 2021/07/19 18:23:15 by aguerrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	quick_sort_a(t_piles *piles, t_fun *fun_list, int len, t_opt opt)
{
	int		mediane;
	int		nb_elem;
	int		pushed_under;

	if (is_sorted(piles->a, len, ASCENDING))
		return (1);
	nb_elem = len;
	if (len <= 3)
	{
		sort_3(piles, fun_list, len, opt);
		return (1);
	}
	pushed_under = 0;
	if (!get_mediane(&mediane, piles->a, len))
		return (0);
	while (len != nb_elem / 2 + nb_elem % 2)
	{
		if (piles->a[0] < mediane && (len--))
			pb(piles, opt);
		else if ((++pushed_under))
			ra(piles, opt);
	}
	while (nb_elem / 2 + nb_elem % 2 != piles->alen && pushed_under--)
		rra(piles, opt);
	return (quick_sort_a(piles, fun_list, nb_elem / 2 + nb_elem % 2, opt)
		&& quick_sort_b(piles, fun_list, nb_elem / 2, opt));
	return (1);
}

int	quick_sort_b(t_piles *piles, t_fun *fun_list, int len, t_opt opt)
{
	int		mediane;
	int		nb_elem;
	int		pushed_under;

	pushed_under = 0;
	if (is_sorted(piles->b, len, DESCENDING))
		while (len--)
			pa(piles, opt);
	if (len <= 3)
	{
		push_sort_3(piles, fun_list, len, opt);
		return (1);
	}
	nb_elem = len;
	if (!get_mediane(&mediane, piles->b, len))
		return (0);
	while (len != nb_elem / 2)
	{
		if (piles->b[0] >= mediane && len--)
			pa(piles, opt);
		else if (++pushed_under)
			rb(piles, opt);
	}
	while (nb_elem / 2 != piles->blen && pushed_under--)
		rrb(piles, opt);
	return (quick_sort_a(piles, fun_list, nb_elem / 2 + nb_elem % 2, opt)
		&& quick_sort_b(piles, fun_list, nb_elem / 2, opt));
}
