/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sorted.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguerrer </var/mail/aguerrer>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/19 18:03:55 by aguerrer          #+#    #+#             */
/*   Updated: 2021/07/19 19:05:25 by aguerrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(int *stack, int len, int order)
{
	int		i;

	i = -1;
	while (++i < len - 1)
		if ((order == ASCENDING && stack[i] > stack[i + 1]) \
				|| (order == DESCENDING && stack[i] < stack[i + 1]))
			return (0);
	return (1);
}
