/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_pile.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguerrer </var/mail/aguerrer>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/19 18:08:41 by aguerrer          #+#    #+#             */
/*   Updated: 2021/07/19 18:14:56 by aguerrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

static int	is_unique(int *pile, int index)
{
	int		i;

	i = -1;
	while (++i < index)
		if (pile[i] == pile[index])
			return (0);
	return (1);
}

static int	go_to_start(char ***input)
{
	int		sign;

	while ((***input < '0' || ***input > '9') && ***input != '-')
	{
		if (!***input)
			(*input)++;
		else if (***input == ' ' || ***input == '\t')
			(**input)++;
		else
			return (0);
	}
	if (***input == '-')
		sign = -1;
	else
		sign = 1;
	if (***input == '-')
		**input += 1;
	if (***input < '0' || ***input > '9')
		return (0);
	return (sign);
}

static int	get_number(int *nbr, char ***input)
{
	int		sign;

	*nbr = 0;
	sign = go_to_start(input);
	if (!sign)
		return (0);
	while (***input >= '0' && ***input <= '9')
	{
		if (*nbr > INT_MAX / 10 || (*nbr == INT_MAX / 10 && (***input > '8' \
				|| (***input == '8' && sign == 1))))
			return (0);
		else if (*nbr == INT_MAX / 10 && ***input == '8' && sign == -1)
		{
			sign = 1;
			*nbr = -10 * *nbr - 8;
		}
		else
			*nbr = 10 * *nbr + ***input - '0';
		(**input)++;
	}
	if (***input != ' ' && ***input != 0 && ***input != '\t')
		return (0);
	*nbr *= sign;
	return (1);
}

int	get_ttl_len(char **input, int len)
{
	int		res;
	int		i;
	int		j;

	res = 0;
	i = -1;
	while (++i < len)
	{
		j = -1;
		while (input[i][++j])
		{
			if (j == 0 && input[i][j] != ' ')
				res += 1;
			else if (input[i][j] != ' ' && input[i][j - 1] == ' ')
				res += 1;
		}
	}
	return (res);
}

int	*get_pile(char **input, int *len)
{
	int		*res;
	int		ttl_len;
	int		i;

	ttl_len = get_ttl_len(input, *len);
	res = (int *)malloc(sizeof(int) * ttl_len);
	if (!res)
		return (NULL);
	i = -1;
	while (++i < ttl_len)
	{
		if (!get_number(res + i, &input) || !is_unique(res, i))
		{
			free(res);
			return (NULL);
		}
	}
	*len = ttl_len;
	return (res);
}
