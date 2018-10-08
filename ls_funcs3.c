/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_funcs3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmukwind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/15 10:23:06 by cmukwind          #+#    #+#             */
/*   Updated: 2018/09/29 11:51:16 by cmukwind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ls_ll(char *av)
{
	struct dirent	*de;
	DIR				*dr;
	char			*join;

	join = NULL;
	num_blks(av, join);
	dr = NULL;
	de = (struct dirent*)av;
	if (av != NULL)
	{
		((f_d_check(av)) == 2) ? dr = opendir(av) : 0;
		if ((f_d_check(av)) == 1)
		{
			dostat(av);
			return ;
		}
	}
	ls_ll_2(de, dr, av);
}

void	ls_ll_2(struct dirent *de, DIR *dr, char *av)
{
	int		i;
	char	*path;
	char	**temp;

	i = 0;
	path = ft_strjoin(av, "/");
	temp = (char**)malloc(sizeof(char*) * (BUFF_SIZE));
	while ((de = readdir(dr)) != NULL)
		if (de->d_name[0] != '.')
			temp[i++] = ft_strjoin(path, de->d_name);
	temp[i] = NULL;
	ft_strdel(&path);
	sort_ls(temp);
	i = -1;
	while (temp[++i])
		dostat(temp[i]);
	closedir(dr);
	ft_arraydel(&temp);
	return ;
}

void	lr_only(char *av)
{
	ls_only_2(av);
}

void	ls_cr(char *av)
{
	struct dirent	*de;
	DIR				*dr;

	de = (struct dirent*)av;
	dr = NULL;
	dr = NULL;
	if (av != NULL)
	{
		((f_d_check(av)) == 2) ? dr = opendir(av) : 0;
		if ((f_d_check(av)) == 1)
		{
			ft_printf("%s\n", av);
			return ;
		}
	}
	ls_cr_2(de, dr, av);
	(dr) ? closedir(dr) : 0;
	return ;
}

void	ls_cr_2(struct dirent *de, DIR *dr, char *av)
{
	char			**arrp;
	char			*y;
	char			*x;

	arrp = NULL;
	y = NULL;
	x = NULL;
	while ((de = readdir(dr)) != NULL)
		if (de->d_name[0] != '.')
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
			ls_cr(x);
			free(x);
		}
	free(y);
	closedir(dr);
}
