/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_funcs1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmukwind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/14 15:15:08 by cmukwind          #+#    #+#             */
/*   Updated: 2018/09/29 11:46:19 by cmukwind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	funcs_op(char *av)
{
	int		i;

	i = -1;
	if (g_ol == 1)
		ls_only_2(av);
	else if (g_ca == 0 && g_la == 1 && g_cr == 0 && g_lr == 0 && g_ll == 1)
		ls_lla(av);
	else if (g_ca == 0 && g_la == 1 && g_cr == 0 && g_lr == 1 && g_ll == 0)
		ls_ar(av);
	else if (g_ca == 0 && g_la == 1 && g_cr == 0 && g_lr == 1 && g_ll == 1)
		ls_arl(av);
	else if (g_ca == 0 && g_la == 0 && g_cr == 0 && g_lr == 1 && g_ll == 1)
		ls_rl(av);
	else if (g_ca == 0 && g_la == 1 && g_cr == 1 && g_lr == 0 && g_ll == 0)
		ls_acr(av);
	else if (g_ca == 0 && g_la == 0 && g_cr == 1 && g_lr == 1 && g_ll == 0)
		ls_rcr(av);
	else if (g_ca == 0 && g_la == 1 && g_cr == 1 && g_lr == 1 && g_ll == 0)
		ls_arcr(av);
	else if (g_ca == 0 && g_la == 1 && g_cr == 1 && g_lr == 0 && g_ll == 1)
		ls_alcr(av);
	else
		funcs_op_2(av);
}

void	funcs_op_2(char *av)
{
	if (g_ca == 0 && g_la == 0 && g_cr == 1 && g_lr == 0 && g_ll == 0)
		ls_cr(av);
	if (g_ca == 0 && g_lr == 1 && g_cr == 0 && g_la == 0 && g_ll == 0)
		lr_only(av);
	if (g_ca == 0 && g_la == 1 && g_cr == 0 && g_lr == 0 && g_ll == 0)
		ls_la(av);
	if (g_ca == 0 && g_ll == 1 && g_la == 0 && g_cr == 0 && g_lr == 0)
		ls_ll(av);
	if (g_ca == 1 && g_ll == 0 && g_la == 0 && g_cr == 0 && g_lr == 0)
		ls_ca(av);
}

void	file_check(int i, char **av)
{
	if (g_lr == 1)
		rev_nsort(i, av);
	while (av[i])
	{
		if (f_d_check(av[i]) == -1)
		{
			ft_printf("ft_ls: %s: No such file or directory\n", av[--i]);
			return ;
		}
		if (f_d_check(av[i]) == 1)
		{
			funcs_op(av[i]);
			g_check = 1;
		}
		i++;
	}
}

void	dir_check(int i, char **av)
{
	if (f_d_check(av[i]) == 2)
	{
		if (g_check == 1)
			ft_printf("\n%s:\n", av[i]);
		funcs_op(av[i]);
	}
}

void	file_dir_check(int i, char **av)
{
	int		j;

	j = i;
	(g_lr == 1) ? rev_nsort(i, av) : sort_nls(i, av);
	while (av[i])
	{
		if (f_d_check(av[i]) == -1)
		{
			ft_printf("ft_ls: %s: No such file or directory\n", av[--i]);
			return ;
		}
		while (av[i] && (f_d_check(av[i]) == 1 || f_d_check(av[i]) == 2))
		{
			ft_printf("%s\n", av[i++]);
			g_check = 1;
		}
		while (av[j] && (f_d_check(av[j]) == 1 || f_d_check(av[j]) == 2))
			funcs_op(av[j++]);
	}
	return ;
}
