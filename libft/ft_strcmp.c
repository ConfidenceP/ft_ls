/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmukwind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/28 17:00:19 by cmukwind          #+#    #+#             */
/*   Updated: 2018/05/31 11:04:01 by cmukwind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strcmp(const char *str1, const char *str2)
{
	unsigned int	index;

	index = 0;
	while (str1[index] != '\0' && str1[index] == str2[index])
		index++;
	return ((unsigned char)str1[index] - (unsigned char)str2[index]);
}
