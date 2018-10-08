/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmukwind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/30 07:10:10 by cmukwind          #+#    #+#             */
/*   Updated: 2018/06/10 11:02:07 by cmukwind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t destsize)
{
	size_t	index1;
	size_t	index2;

	index1 = 0;
	index2 = 0;
	if (ft_strlen(dest) < destsize)
		index1 = ft_strlen(dest);
	else
		index1 = destsize;
	while ((src[index2]) && ((index1 + index2 + 1) < destsize))
	{
		dest[index1 + index2] = src[index2];
		index2++;
	}
	if (index1 != destsize)
		dest[index1 + index2] = '\0';
	return (index1 + ft_strlen(src));
}
