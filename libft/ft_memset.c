/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmukwind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/23 11:10:35 by cmukwind          #+#    #+#             */
/*   Updated: 2018/06/16 11:54:57 by cmukwind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *dest, int src, size_t num_bits)
{
	unsigned char	*conv;

	conv = (unsigned char*)dest;
	while (num_bits > 0)
	{
		*conv = src;
		conv++;
		num_bits--;
	}
	return (dest);
}
