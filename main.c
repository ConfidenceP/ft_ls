/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmukwind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/14 10:40:57 by cmukwind          #+#    #+#             */
/*   Updated: 2018/09/29 12:04:27 by cmukwind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		flag_c(char c)
{
	int			i;
	char		*str;

	i = 0;
	str = "larR-A";
	if (str[0] == c)
		g_ll = 1;
	if (str[1] == c)
		g_la = 1;
	if (str[2] == c)
		g_lr = 1;
	if (str[3] == c)
		g_cr = 1;
	if (str[4] == c)
		g_ol = 1;
	if (str[5] == c)
		g_ca = 1;
	if (!ft_strchr(str, c))
	{
		ft_printf("ft_ls: illegal option -- %c\n", c);
		ft_printf("usage: ft_ls [-ARalr] [file ...]\n");
		return (-1);
	}
	return (1);
}

int		f_d_check(char *av)
{
	struct stat	buf;
	int			i;

	i = 0;
	stat(av, &buf);
	if (S_ISREG(buf.st_mode))
		return (1);
	else if (S_ISDIR(buf.st_mode))
		return (2);
	else
		return (-1);
	return (0);
}

void	arg_check(char **av)
{
	int			i;
	int			j;

	i = 0;
	while (av[++i] && av[i][0] == '-')
	{
		j = 0;
		while (av[i][++j])
		{
			if (ft_strcmp(av[1], "--") == 0)
			{
				g_ol = 1;
				if (av[i + 1] && f_d_check(av[i + 1]) == -1)
				{
					ft_printf("ls: %s: No such file or directory\n", av[++i]);
					return ;
				}
				break ;
			}
			if (flag_c(av[i][j]) == -1)
				return ;
		}
	}
	arg_check_2(i, av);
}

void	arg_check_2(int i, char **av)
{
	int		j;

	j = i;
	if (i == 1)
		g_ol = 1;
	if (!av[i])
		funcs_op(".");
	else
	{
		sort_nls(i, av);
		--i;
		while (av[++i])
			if (f_d_check(av[i]) == 1)
				funcs_op(av[i]);
		(i > j) ? g_check = 1 : 0;
		i = j - 1;
		while (av[++i])
			if (f_d_check(av[i]) == 2)
				dir_check(i, av);
	}
	return ;
}

int		main(int ac, char **av)
{
	int		i;
	char	**new;

	i = 0;
	new = (char**)malloc(sizeof(char *) * (arraylen(av) + 2));
	while (av[i])
	{
		new[i] = ft_strdup(av[i]);
		i++;
	}
	new[i] = NULL;
	(ac == 1) ? ls_only(".") : arg_check(new);
	ft_arraydel(&new);
	return (0);
}
