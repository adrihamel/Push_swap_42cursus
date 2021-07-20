/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguerrer </var/mail/aguerrer>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/18 20:31:26 by aguerrer          #+#    #+#             */
/*   Updated: 2021/07/20 23:13:22 by aguerrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include "libft.h"

# define INT_MAX 2147483647

typedef struct s_stack
{
	int		*a;
	int		*b;
	int		alen;
	int		blen;
}				t_stack;

typedef enum e_opt
{
	NONE,
	INSTR_ONLY,
	ERROR
}				t_opt;

typedef struct s_fun {
	char	*instr;
	void	(*f)(t_stack *, t_opt);
}				t_fun;

int				*get_stack(char **input, int *len);
t_opt			get_opt(int *ac, char ***av);
t_fun			*initialize_fun_list(void);
void			delete_funlist(t_fun *fun_list);
int				follow_instructions(t_stack *stack, t_fun *fun_list, \
									char *instr, t_opt opt);
void			sa(t_stack *stack, t_opt opt);
void			sb(t_stack *stack, t_opt opt);
void			ss(t_stack *stack, t_opt opt);
void			pa(t_stack *stack, t_opt opt);
void			pb(t_stack *stack, t_opt opt);
void			ra(t_stack *stack, t_opt opt);
void			rb(t_stack *stack, t_opt opt);
void			rr(t_stack *stack, t_opt opt);
void			rra(t_stack *stack, t_opt opt);
void			rrb(t_stack *stack, t_opt opt);
void			rrr(t_stack *stack, t_opt opt);
void			print_instr(char *instr, t_opt opt);
void			print_a(t_stack stack, t_opt opt, int imin, int imax);
void			print_b(t_stack stack, t_opt opt, int imin, int imax);

#endif
