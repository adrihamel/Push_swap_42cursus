/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   follow_instructions.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguerrer </var/mail/aguerrer>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/19 18:05:20 by aguerrer          #+#    #+#             */
/*   Updated: 2021/07/19 19:05:18 by aguerrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "libft.h"

static int	leninstr(char *instr)
{
	int	len;

	len = 0;
	while (instr && instr[len] && instr[len] != ' ')
		len++;
	return (len);
}

int	follow_instructions(t_stack *stack, t_fun *fun_list,
		char *instr, t_opt opt)
{
	int		i;
	int		instr_found;

	while (instr[0])
	{
		while (instr[0] == ' ')
			instr++;
		instr_found = 0;
		i = -1;
		while (!instr_found && fun_list[++i].instr)
		{
			if (ft_strnequ(instr, fun_list[i].instr, leninstr(instr)))
			{
				fun_list[i].f(stack, opt);
				instr_found = 1;
			}
		}
		if (!instr_found)
			return (0);
		instr += leninstr(instr);
	}
	return (1);
}
