/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguerrer </var/mail/aguerrer>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/19 17:59:19 by aguerrer          #+#    #+#             */
/*   Updated: 2021/07/19 19:08:38 by aguerrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	error(void)
{
	ft_putstr("Error\n");
	exit(0);
}

static void	usage(void)
{
	ft_putstr("usage: ./push_swap int_list\n");
	exit(0);
}

static void	delete_stack(t_stack stack)
{
	free(stack.a);
	free(stack.b);
}

static t_stack	init_stack(int argc, char *argv[])
{
	t_stack	stack;

	stack.alen = argc;
	stack.a = get_stack(argv, &stack.alen);
	if (!stack.a)
		error();
	stack.blen = 0;
	stack.b = (int *)malloc(sizeof(int) * stack.alen);
	if (!stack.b)
	{
		free(stack.a);
		error();
	}
	return (stack);
}

int	main(int argc, char *argv[])
{
	t_stack	stack;
	t_opt	opt;
	t_fun	*fun_list;

	opt = get_opt(&argc, &argv, 0, NULL);
	if (opt == NONE)
		opt = INSTR_ONLY;
	if (opt == ERROR || argc == 0)
		usage();
	stack = init_stack(argc, argv);
	fun_list = initialize_fun_list();
	if (!fun_list || !quick_sort_a(&stack, fun_list, stack.alen, opt))
	{
		delete_funlist(fun_list);
		delete_stack(stack);
		error();
	}
	delete_funlist(fun_list);
	delete_stack(stack);
	return (0);
}
