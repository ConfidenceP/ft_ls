/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmukwind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/23 14:58:38 by cmukwind          #+#    #+#             */
/*   Updated: 2018/06/16 12:30:05 by cmukwind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t num_bits)
{
	size_t	index;
	char	*psrc;
	char	*pdest;

	index = 0;
	psrc = (char*)src;
	pdest = (char*)dest;
	while (index < num_bits)
	{
		pdest[index] = psrc[index];
		if ((unsigned char)psrc[index] == (unsigned char)c)
			return ((char*)(dest + index + 1));
		index++;
	}
	return (NULL);
}
