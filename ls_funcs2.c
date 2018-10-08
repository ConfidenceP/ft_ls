/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_funcs2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmukwind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/29 12:04:57 by cmukwind          #+#    #+#             */
/*   Updated: 2018/09/29 12:54:44 by cmukwind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ls_only(char *av)
{
	struct dirent	*de;
	DIR				*dr;
	char			**temp;
	int				i;

	i = 0;
	de = (struct dirent*)av;
	dr = opendir(".");
	temp = (char**)malloc(sizeof(char*) * (BUFF_SIZE));
	while ((de = readdir(dr)) != NULL)
		if (de->d_name[0] != '.')
			temp[i++] = ft_strdup(de->d_name);
	temp[i] = NULL;
	sort_ls(temp);
	i = -1;
	while (temp[++i])
		ft_printf("%s\n", temp[i]);
	ft_arraydel(&temp);
	closedir(dr);
	return ;
}

void	ls_only_2(char *av)
{
	struct dirent	*de;
	DIR				*dr;
	char			**temp;
	int				i;

	i = 0;
	de = (struct dirent*)av;
	temp = (char**)malloc(sizeof(char*) * (BUFF_SIZE));
	if (f_d_check(av) == 1)
	{
		temp[i] = ft_strdup(&av[i]);
		i++;
	}
	else if (f_d_check(av) == 2)
	{
		dr = opendir(av);
		while ((de = readdir(dr)) != NULL)
			if (de->d_name[0] != '.')
				temp[i++] = ft_strdup(de->d_name);
		closedir(dr);
	}
	temp[i] = NULL;
	sort_ls(temp);
	ls_print(temp);
	ft_arraydel(&temp);
}

void	ls_ca(char *av)
{
	struct dirent	*de;
	DIR				*dr;
	char			**temp;
	int				i;

	i = 0;
	de = (struct dirent*)av;
	temp = (char**)malloc(sizeof(char*) * (BUFF_SIZE));
	if (f_d_check(av) == 1)
	{
		temp[i] = ft_strdup(&av[i]);
		i++;
	}
	else if (f_d_check(av) == 2)
	{
		dr = opendir(av);
		while ((de = readdir(dr)) != NULL)
			((ft_strcmp(de->d_name, ".") != 0) && (ft_strcmp(de->d_name,
					"..") != 0)) ? temp[i++] = ft_strdup(de->d_name) : 0;
		closedir(dr);
	}
	temp[i] = NULL;
	sort_ls(temp);
	ls_print(temp);
	ft_arraydel(&temp);
}

void	ls_lla(char *av)
{
	int				i;
	struct dirent	*de;
	DIR				*dr;
	char			*join;

	i = 0;
	join = NULL;
	num_blks_la(av, join);
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
	ls_lla_2(i, de, dr, av);
}

void	ls_lla_2(int i, struct dirent *de, DIR *dr, char *av)
{
	char	*path;
	char	**temp;

	path = ft_strjoin(av, "/");
	temp = (char**)malloc(sizeof(char*) * (BUFF_SIZE));
	while ((de = readdir(dr)) != NULL)
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
