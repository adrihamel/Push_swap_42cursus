/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguerrer </var/mail/aguerrer>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/18 19:55:06 by aguerrer          #+#    #+#             */
/*   Updated: 2021/07/18 19:56:16 by aguerrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstcpy(t_list *lst)
{
	t_list	*cpy;
	t_list	*new_link;

	if (!lst)
		return (NULL);
	cpy = NULL;
	while (lst)
	{
		new_link = ft_lstnew(lst->content, lst->content_size);
		if (!new_link)
			return (cpy);
		ft_lstappend(&cpy, new_link);
		lst = lst->next;
	}
	return (cpy);
}
