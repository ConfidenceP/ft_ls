/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_funcs.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmukwind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/28 15:38:05 by cmukwind          #+#    #+#             */
/*   Updated: 2018/09/29 11:51:13 by cmukwind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	dostat(char *filename)
{
	struct stat	info;

	if (lstat(filename, &info) == -1)
		perror(filename);
	else
		show_file_info(filename, &info);
}

void	num_blks(char *av, char *join)
{
	int				i;
	DIR				*dr;
	struct dirent	*de;
	struct stat		blk;
	char			*store;

	i = 0;
	dr = opendir(av);
	if (f_d_check(av) == 2 && g_ll == 1)
	{
		while ((de = readdir(dr)) != NULL)
		{
			join = ft_strjoin(av, "/");
			if (de->d_name[0] != '.')
			{
				store = ft_strjoin(join, de->d_name);
				stat(store, &blk);
				i += blk.st_blocks;
				ft_strdel(&store);
			}
			ft_strdel(&join);
		}
		ft_printf("total %i\n", i);
		closedir(dr);
	}
}

void	ls_print(char **av)
{
	int		i;

	i = 0;
	if (g_lr == 1)
	{
		while (av[i])
			i++;
		while (av[--i])
			ft_printf("%s\n", av[i]);
	}
	else
		while (av[i])
			ft_printf("%s\n", av[i++]);
	return ;
}

void	print_arr(char **arra)
{
	int		i;

	i = -1;
	while (arra[++i])
		ft_printf("%s\n", arra[i]);
}

void	ls_alcr_2(struct dirent *de, DIR *dr, char *av)
{
	char			**arrp;
	char			*y;
	char			*x;

	arrp = NULL;
	y = NULL;
	x = NULL;
	while ((de = readdir(dr)) != NULL)
		arrp = arraypush(arrp, de->d_name);
	arrp = sort_ls(arrp);
	print_arr(arrp);
	ft_arraydel(&arrp);
	dr = opendir(av);
	y = ft_strjoin(av, "/");
	while ((de = readdir(dr)) != NULL)
		if (de->d_name[0] != '.' && de->d_type == DT_DIR)
		{
			x = ft_strjoin(y, de->d_name);
			ft_printf("\n%s:\n", x);
			ls_alcr(x);
			free(x);
		}
	free(y);
	closedir(dr);
}
