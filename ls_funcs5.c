/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_funcs5.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmukwind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/28 17:28:59 by cmukwind          #+#    #+#             */
/*   Updated: 2018/09/29 11:41:02 by cmukwind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ls_rl_2(int i, struct dirent *de, DIR *dr, char *av)
{
	char		*path;
	char		**temp;

	path = ft_strjoin(av, "/");
	temp = (char**)malloc(sizeof(char*) * (BUFF_SIZE));
	while ((de = readdir(dr)) != NULL)
		if (de->d_name[0] != '.')
			temp[i++] = ft_strjoin(path, de->d_name);
	temp[i] = NULL;
	rev_sort(temp);
	i = -1;
	while (temp[++i])
		dostat(temp[i]);
	closedir(dr);
	ft_arraydel(&temp);
	ft_strdel(&path);
	return ;
}

void	ls_la(char *av)
{
	int				i;
	struct dirent	*de;
	DIR				*dr;

	i = 0;
	dr = NULL;
	de = (struct dirent*)av;
	if (av != NULL)
	{
		((f_d_check(av)) == 2) ? dr = opendir(av) : 0;
		if ((f_d_check(av)) == 1)
		{
			ft_printf("%s\n", av);
			return ;
		}
	}
	ls_la_2(de, dr);
}

void	ls_la_2(struct dirent *de, DIR *dr)
{
	int		i;
	char	**temp;

	i = 0;
	temp = (char**)malloc(sizeof(char*) * (BUFF_SIZE));
	while ((de = readdir(dr)) != NULL)
		temp[i++] = ft_strdup(de->d_name);
	temp[i] = NULL;
	sort_ls(temp);
	i = -1;
	while (temp[++i])
		ft_printf("%s\n", temp[i]);
	closedir(dr);
	ft_arraydel(&temp);
	return ;
}

void	ls_acr(char *av)
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
	ls_acr_2(de, dr, av);
	(dr) ? closedir(dr) : 0;
	return ;
}

void	ls_acr_2(struct dirent *de, DIR *dr, char *av)
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
			ls_acr(x);
			free(x);
		}
	free(y);
	closedir(dr);
}
