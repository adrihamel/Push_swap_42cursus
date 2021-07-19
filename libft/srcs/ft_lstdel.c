/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguerrer </var/mail/aguerrer>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/18 19:56:32 by aguerrer          #+#    #+#             */
/*   Updated: 2021/07/18 19:56:40 by aguerrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*cache;

	if (!*alst)
		return ;
	while ((*alst)->next)
	{
		cache = (*alst)->next;
		ft_lstdelone(alst, del);
		*alst = cache;
	}
	ft_lstdelone(alst, del);
}
