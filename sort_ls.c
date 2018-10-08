/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_ls.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmukwind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/11 13:22:09 by cmukwind          #+#    #+#             */
/*   Updated: 2018/09/29 12:00:39 by cmukwind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char	**sort_ls(char **av)
{
	int		j;
	int		i;
	int		k;
	char	*temp;

	j = -1;
	k = 0;
	while (av[k])
		k++;
	while (++j < (k - 1))
	{
		i = j;
		while (++i < k)
			if (ft_strcmp(av[j], av[i]) > 0)
			{
				temp = ft_strdup(av[j]);
				free(av[j]);
				av[j] = ft_strdup(av[i]);
				free(av[i]);
				av[i] = ft_strdup(temp);
				free(temp);
			}
	}
	return (av);
}

char	**sort_nls(int j, char **av)
{
	int		i;
	int		k;
	char	*temp;

	j -= 1;
	k = 0;
	while (av[k])
		k++;
	while (++j < (k - 1))
	{
		i = j;
		while (++i < k)
			if (ft_strcmp(av[j], av[i]) > 0)
			{
				temp = ft_strdup(av[j]);
				free(av[j]);
				av[j] = ft_strdup(av[i]);
				free(av[i]);
				av[i] = ft_strdup(temp);
				free(temp);
			}
	}
	return (av);
}

char	**rev_sort(char **av)
{
	int		j;
	int		i;
	int		k;
	char	*temp;

	j = -1;
	k = 0;
	while (av[k])
		k++;
	while (++j < (k - 1))
	{
		i = j;
		while (++i < k)
			if (ft_strcmp(av[j], av[i]) < 0)
			{
				temp = ft_strdup(av[j]);
				free(av[j]);
				av[j] = ft_strdup(av[i]);
				free(av[i]);
				av[i] = ft_strdup(temp);
				free(temp);
			}
	}
	return (av);
}

char	**rev_nsort(int j, char **av)
{
	int		i;
	int		k;
	char	*temp;

	j -= 1;
	k = 0;
	while (av[k])
		k++;
	while (++j < (k - 1))
	{
		i = j;
		while (++i < k)
			if (ft_strcmp(av[j], av[i]) < 0)
			{
				temp = ft_strdup(av[j]);
				free(av[j]);
				av[j] = ft_strdup(av[i]);
				free(av[i]);
				av[i] = ft_strdup(temp);
				free(temp);
			}
	}
	return (av);
}
