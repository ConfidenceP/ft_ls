/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmukwind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/24 14:58:43 by cmukwind          #+#    #+#             */
/*   Updated: 2018/06/16 13:29:17 by cmukwind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *str1, const void *str2, size_t num_bits)
{
	size_t	index;
	char	*pstr1;
	char	*pstr2;

	index = 0;
	pstr1 = (char*)str1;
	pstr2 = (char*)str2;
	while (index < num_bits)
	{
		if (pstr1[index] != pstr2[index])
			return ((unsigned char)pstr1[index] - (unsigned char)pstr2[index]);
		index++;
	}
	return (0);
}
