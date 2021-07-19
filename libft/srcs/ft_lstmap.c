/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguerrer </var/mail/aguerrer>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/18 19:57:52 by aguerrer          #+#    #+#             */
/*   Updated: 2021/07/18 19:58:32 by aguerrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*map_lst;

	map_lst = NULL;
	while (lst)
	{
		ft_lstappend(&map_lst, f(lst));
		lst = lst->next;
	}
	return (map_lst);
}
