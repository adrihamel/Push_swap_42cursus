/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_mediane.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguerrer </var/mail/aguerrer>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/19 18:03:21 by aguerrer          #+#    #+#             */
/*   Updated: 2021/07/19 19:04:57 by aguerrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_mediane(int *mediane, int *stack, int len)
{
	int		*cache;
	int		i;

	cache = (int *)malloc(sizeof(int) * len);
	if (!cache)
		return (0);
	i = -1;
	while (++i < len)
		cache[i] = stack[i];
	reg_quick_sort(cache, len);
	*mediane = cache[len / 2];
	free(cache);
	return (1);
}
