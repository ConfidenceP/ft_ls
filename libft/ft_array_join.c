/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array_join.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmukwind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/23 15:44:57 by cmukwind          #+#    #+#             */
/*   Updated: 2018/09/23 18:07:23 by cmukwind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_arraydel(char ***arr)
{
	int i;

	i = 0;
	while ((*arr)[i])
		i++;
	i--;
	while (i >= 0)
		ft_strdel(&(*arr)[i--]);
	ft_strdel(*arr);
	free(*arr);
}

char		**ft_array_join(char ***arr, char *str)
{
	char	**new;
	int		i;

	if (!*arr)
	{
		if (!(new = (char **)malloc(sizeof(char*) * 2)))
			return (NULL);
		new[0] = ft_strdup(str);
		new[1] = NULL;
		return (new);
	}
	i = 0;
	while ((*arr)[i])
		i++;
	if (!(new = (char **)malloc(sizeof(char*) * (i + 2))))
		return (NULL);
	i = -1;
	while ((*arr)[++i])
		new[i] = ft_strdup((*arr)[i]);
	new[i] = ft_strdup(str);
	new[i] = NULL;
	ft_arraydel(arr);
	return (new);
}
