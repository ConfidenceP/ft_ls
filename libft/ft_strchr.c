/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmukwind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/30 13:54:13 by cmukwind          #+#    #+#             */
/*   Updated: 2018/06/04 16:29:21 by cmukwind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	size_t	index;

	index = 0;
	while (str[index] != '\0')
	{
		if (str[index] == c)
			return ((char*)str + index);
		index++;
	}
	if (str[index] == '\0' && str[index] == c)
		return ((char*)str + index);
	return (NULL);
}
