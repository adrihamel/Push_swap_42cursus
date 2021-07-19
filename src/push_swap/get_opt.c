/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_opt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguerrer </var/mail/aguerrer>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/19 18:15:13 by aguerrer          #+#    #+#             */
/*   Updated: 2021/07/19 18:16:42 by aguerrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

t_opt	get_opt(int *ac, char ***av, int get_stream, t_file **stream)
{
	int		i;

	if (get_stream)
		*stream = NULL;
	while (--(*ac) && (++(*av))[0][0] == '-' && (!get_stream || !*stream))
	{
		i = 0;
		if (!(*av)[0][1])
			return (ERROR);
		if ((*av)[0][1] >= '0' && (*av)[0][1] <= '9')
			return (NONE);
	}
	return (NONE);
}
