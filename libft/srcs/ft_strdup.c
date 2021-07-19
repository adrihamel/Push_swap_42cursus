/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguerrer </var/mail/aguerrer>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/18 20:09:25 by aguerrer          #+#    #+#             */
/*   Updated: 2021/07/18 20:10:39 by aguerrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*res;
	int		i;

	res = ft_strnew(ft_strlen(s1));
	if (!s1 || !res)
		return (NULL);
	i = -1;
	while (s1[++i])
		res[i] = s1[i];
	return (res);
}
