/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmukwind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/24 09:35:07 by cmukwind          #+#    #+#             */
/*   Updated: 2018/06/16 13:24:07 by cmukwind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t num_bits)
{
	char	*pdest;
	char	*psrc;

	pdest = (char*)dest;
	psrc = (char*)src;
	if (src < dest)
	{
		pdest = (char*)dest + num_bits - 1;
		psrc = (char*)src + num_bits - 1;
		while (num_bits != 0)
		{
			*pdest-- = *psrc--;
			num_bits--;
		}
	}
	else
	{
		while (num_bits != 0)
		{
			*pdest++ = *psrc++;
			num_bits--;
		}
	}
	return (dest);
}
