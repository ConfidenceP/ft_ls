/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmukwind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/23 14:12:36 by cmukwind          #+#    #+#             */
/*   Updated: 2018/05/31 11:00:13 by cmukwind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t num_bits)
{
	unsigned long	index;
	char			*psrc;
	char			*pdest;

	index = 0;
	psrc = (char*)src;
	pdest = (char*)dest;
	while (index < num_bits)
	{
		pdest[index] = psrc[index];
		index++;
	}
	return (dest);
}
