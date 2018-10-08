/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_funcs6.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmukwind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/28 17:31:19 by cmukwind          #+#    #+#             */
/*   Updated: 2018/09/29 11:41:10 by cmukwind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ls_rcr(char *av)
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
	ls_rcr_2(de, dr, av);
	(dr) ? closedir(dr) : 0;
	return ;
}

void	ls_rcr_2(struct dirent *de, DIR *dr, char *av)
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
	arrp = rev_sort(arrp);
	print_arr(arrp);
	ft_arraydel(&arrp);
	dr = opendir(av);
	y = ft_strjoin(av, "/");
	while ((de = readdir(dr)) != NULL)
		if (de->d_name[0] != '.' && de->d_type == DT_DIR)
		{
			x = ft_strjoin(y, de->d_name);
			ft_printf("\n%s:\n", x);
			ls_rcr(x);
			free(x);
		}
	free(y);
	closedir(dr);
}

void	ls_arcr(char *av)
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
	ls_arcr_2(de, dr, av);
	(dr) ? closedir(dr) : 0;
	return ;
}

void	ls_arcr_2(struct dirent *de, DIR *dr, char *av)
{
	char			**arrp;
	char			*y;
	char			*x;

	arrp = NULL;
	y = NULL;
	x = NULL;
	while ((de = readdir(dr)) != NULL)
		arrp = arraypush(arrp, de->d_name);
	arrp = rev_sort(arrp);
	print_arr(arrp);
	ft_arraydel(&arrp);
	dr = opendir(av);
	y = ft_strjoin(av, "/");
	while ((de = readdir(dr)) != NULL)
		if (de->d_name[0] != '.' && de->d_type == DT_DIR)
		{
			x = ft_strjoin(y, de->d_name);
			ft_printf("\n%s:\n", x);
			ls_arcr(x);
			free(x);
		}
	free(y);
	closedir(dr);
}

void	ls_alcr(char *av)
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
			dostat(av);
			return ;
		}
	}
	ls_alcr_2(de, dr, av);
	(dr) ? closedir(dr) : 0;
	return ;
}
