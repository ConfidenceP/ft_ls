/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmukwind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 07:40:36 by cmukwind          #+#    #+#             */
/*   Updated: 2018/06/12 10:59:53 by cmukwind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *str1, const char *str2, size_t num_bits)
{
	unsigned int	index;

	index = 0;
	if (num_bits == 0)
		return (0);
	while (str1[index] != '\0' && str1[index] == str2[index]
			&& num_bits - 1 > index)
		index++;
	return ((unsigned char)str1[index] - (unsigned char)str2[index]);
}
