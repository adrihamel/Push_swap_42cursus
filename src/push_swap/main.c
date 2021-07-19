/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguerrer </var/mail/aguerrer>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/19 17:59:19 by aguerrer          #+#    #+#             */
/*   Updated: 2021/07/19 18:03:09 by aguerrer         ###   ########.fr       */
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

static void	delete_piles(t_piles piles)
{
	free(piles.a);
	free(piles.b);
}

static t_piles	init_piles(int argc, char *argv[])
{
	t_piles	piles;

	piles.alen = argc;
	piles.a = get_pile(argv, &piles.alen);
	if (!piles.a)
		error();
	piles.blen = 0;
	piles.b = (int *)malloc(sizeof(int) * piles.alen);
	if (!piles.b)
	{
		free(piles.a);
		error();
	}
	return (piles);
}

int	main(int argc, char *argv[])
{
	t_piles	piles;
	t_opt	opt;
	t_fun	*fun_list;

	opt = get_opt(&argc, &argv, 0, NULL);
	if (opt == NONE)
		opt = INSTR_ONLY;
	if (opt == ERROR || argc == 0)
		usage();
	piles = init_piles(argc, argv);
	fun_list = initialize_fun_list();
	if (!fun_list || !quick_sort_a(&piles, fun_list, piles.alen, opt))
	{
		delete_funlist(fun_list);
		delete_piles(piles);
		error();
	}
	delete_funlist(fun_list);
	delete_piles(piles);
	return (0);
}
