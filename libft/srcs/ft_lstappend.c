/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstappend.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguerrer </var/mail/aguerrer>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/18 19:54:02 by aguerrer          #+#    #+#             */
/*   Updated: 2021/07/18 19:54:38 by aguerrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstappend(t_list **lst, t_list *link)
{
	t_list	*cache;

	if (!lst)
		return ;
	if (!*lst)
		*lst = link;
	else
	{
		cache = *lst;
		while (cache->next)
			cache = cache->next;
		cache->next = link;
	}
}
