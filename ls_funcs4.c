/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_funcs4.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmukwind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 13:28:45 by cmukwind          #+#    #+#             */
/*   Updated: 2018/09/29 11:54:44 by cmukwind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ls_ar(char *av)
{
	struct dirent	*de;
	DIR				*dr;

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
	ls_ar_2(de, dr);
}

void	ls_ar_2(struct dirent *de, DIR *dr)
{
	int		i;
	char	**temp;

	i = 0;
	temp = (char**)malloc(sizeof(char*) * (BUFF_SIZE));
	while ((de = readdir(dr)) != NULL)
		temp[i++] = ft_strdup(de->d_name);
	temp[i] = NULL;
	rev_sort(temp);
	i = -1;
	while (temp[++i])
		ft_printf("%s\n", temp[i]);
	closedir(dr);
	ft_arraydel(&temp);
	return ;
}

void	ls_arl(char *av)
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
	ls_arl_2(i, de, dr, av);
}

void	ls_arl_2(int i, struct dirent *de, DIR *dr, char *av)
{
	char		*path;
	char		**temp;

	path = ft_strjoin(av, "/");
	temp = (char**)malloc(sizeof(char*) * (BUFF_SIZE));
	while ((de = readdir(dr)) != NULL)
		temp[i++] = ft_strdup(ft_strjoin(path, de->d_name));
	temp[i] = NULL;
	rev_sort(temp);
	i = -1;
	while (temp[++i])
		dostat(temp[i]);
	closedir(dr);
	ft_arraydel(&temp);
	return ;
}

void	ls_rl(char *av)
{
	int				i;
	struct dirent	*de;
	DIR				*dr;
	char			*join;

	join = NULL;
	i = 0;
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
	ls_rl_2(i, de, dr, av);
}
