/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguerrer </var/mail/aguerrer>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/18 20:30:48 by aguerrer          #+#    #+#             */
/*   Updated: 2021/07/19 19:07:02 by aguerrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "utils.h"

# define ASCENDING 1
# define DESCENDING 0

int		find_instructions(t_stack stack, t_fun *fun_list, t_opt opt);
int		quick_sort_a(t_stack *stack, t_fun *fun_list, int len, t_opt opt);
int		quick_sort_b(t_stack *stack, t_fun *fun_list, int len, t_opt opt);
int		is_sorted(int *stack, int len, int order);
void	sort_3(t_stack *stack, t_fun *fun_list, int len, t_opt opt);
void	push_sort_3(t_stack *stack, t_fun *fun_list, int len, t_opt opt);
int		get_mediane(int *mediane, int *stack, int len);
void	reg_quick_sort(int *array, int len);

#endif
