/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_stack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguerrer </var/mail/aguerrer>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/19 18:08:41 by aguerrer          #+#    #+#             */
/*   Updated: 2021/07/26 18:32:42 by aguerrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

static int	is_unique(int *stack, int index)
{
	int		i;

	i = -1;
	while (++i < index)
		if (stack[i] == stack[index])
			return (0);
	return (1);
}

static int	go_to_start(char ***argv)
{
	int		sign;

	while ((***argv < '0' || ***argv > '9') && ***argv != '-')
	{
		if (!***argv)
			(*argv)++;
		else if (***argv == ' ' || ***argv == '\t' || ***argv == '+')
			(**argv)++;
		else
			return (0);
	}
	if (***argv == '-')
		sign = -1;
	else
		sign = 1;
	if (***argv == '-')
		**argv += 1;
	if (***argv < '0' || ***argv > '9')
		return (0);
	return (sign);
}

static int	get_number(int *nbr, char ***argv)
{
	int		sign;

	*nbr = 0;
	sign = go_to_start(argv);
	if (!sign)
		return (0);
	while (***argv >= '0' && ***argv <= '9')
	{
		if (*nbr > INT_MAX / 10 || (*nbr == INT_MAX / 10 && (***argv > '8' \
						|| (***argv == '8' && sign == 1))))
			return (0);
		else if (*nbr == INT_MAX / 10 && ***argv == '8' && sign == -1)
		{
			sign = 1;
			*nbr = -10 * *nbr - 8;
		}
		else
			*nbr = 10 * *nbr + ***argv - '0';
		(**argv)++;
	}
	if (***argv != ' ' && ***argv != 0 && ***argv != '\t')
		return (0);
	*nbr *= sign;
	return (1);
}

int	get_ttl_len(char *argv[], int len)
{
	int		res;
	int		i;
	int		j;

	res = 0;
	i = -1;
	while (++i < len)
	{
		j = -1;
		while (argv[i][++j])
		{
			if (j == 0 && argv[i][j] != ' ')
				res += 1;
			else if (argv[i][j] != ' ' && argv[i][j - 1] == ' ')
				res += 1;
		}
	}
	return (res);
}

int	*get_stack(char *argv[], int *len)
{
	int		*res;
	int		ttl_len;
	int		i;

	ttl_len = get_ttl_len(argv, *len);
	res = (int *)malloc(sizeof(int) * ttl_len);
	if (!res)
		return (NULL);
	i = -1;
	while (++i < ttl_len)
	{
		if (!get_number(res + i, &argv) || !is_unique(res, i))
		{
			free(res);
			return (NULL);
		}
	}
	*len = ttl_len;
	return (res);
}
