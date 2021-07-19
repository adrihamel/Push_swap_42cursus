/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_opt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguerrer </var/mail/aguerrer>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/19 18:15:13 by aguerrer          #+#    #+#             */
/*   Updated: 2021/07/19 18:52:53 by aguerrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

t_opt	get_opt(int *argc, char ***argv, int get_stream, t_file **stream)
{
	int		i;

	if (get_stream)
		*stream = NULL;
	while (--(*argc) && (++(*argv))[0][0] == '-' && (!get_stream || !*stream))
	{
		i = 0;
		if (!(*argv)[0][1])
			return (ERROR);
		if ((*argv)[0][1] >= '0' && (*argv)[0][1] <= '9')
			return (NONE);
	}
	return (NONE);
}
