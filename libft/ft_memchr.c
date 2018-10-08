/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmukwind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/24 10:31:51 by cmukwind          #+#    #+#             */
/*   Updated: 2018/05/31 11:01:11 by cmukwind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t num_bits)
{
	char			*pstr;
	unsigned long	index;

	index = 0;
	pstr = (char*)str;
	while (index < num_bits)
	{
		if ((char)pstr[index] == (char)c)
		{
			return ((char *)str + index);
		}
		index++;
	}
	return (NULL);
}
