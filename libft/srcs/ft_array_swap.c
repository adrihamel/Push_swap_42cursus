/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array_swap.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguerrer </var/mail/aguerrer>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/18 19:41:26 by aguerrer          #+#    #+#             */
/*   Updated: 2021/07/18 19:41:33 by aguerrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_array_swap(int *array, int i1, int i2)
{
	int		tmp;

	if (!array)
		return ;
	tmp = array[i1];
	array[i1] = array[i2];
	array[i2] = tmp;
}
