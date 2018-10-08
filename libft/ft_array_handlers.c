/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array_handlers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmukwind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/24 17:08:10 by cmukwind          #+#    #+#             */
/*   Updated: 2018/09/29 12:28:07 by cmukwind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			arraylen(char **array)
{
	int		i;

	i = 0;
	while (array[i])
		i++;
	return (i);
}

void		free2d(char **array)
{
	int		i;

	i = 0;
	while (array[i])
	{
		ft_strdel(&array[i]);
		i++;
	}
	ft_arraydel(&array);
}

char		**arraypush(char **array, char *str)
{
	char	**new;
	int		i;

	i = 0;
	if (array == NULL)
	{
		new = (char **)malloc(sizeof(char*) * 2);
		new[0] = ft_strdup(str);
		new[1] = NULL;
	}
	else
	{
		new = (char**)malloc(sizeof(char *) * (arraylen(array) + 2));
		while (array[i])
		{
			new[i] = ft_strdup(array[i]);
			i++;
		}
		new[i] = ft_strdup(str);
		new[++i] = NULL;
		free2d(array);
	}
	return (new);
}
