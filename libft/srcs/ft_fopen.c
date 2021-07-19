/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fopen.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguerrer </var/mail/aguerrer>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/18 19:51:10 by aguerrer          #+#    #+#             */
/*   Updated: 2021/07/18 19:53:11 by aguerrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

t_file	*ft_fopen(const char *path)
{
	t_file	*stream;

	stream = (t_file *)malloc(sizeof(t_file));
	if (!stream)
		return (NULL);
	stream->fd = open(path, O_RDONLY);
	if (stream->fd == -1)
	{
		free(stream);
		printf("siii");
		return (NULL);
	}
	ft_bzero(stream->buf, sizeof(char) * (BUFF_SIZE + 1));
	stream->i = 0;
	return (stream);
}
