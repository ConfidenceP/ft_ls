/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmukwind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/28 13:32:47 by cmukwind          #+#    #+#             */
/*   Updated: 2018/06/07 17:14:15 by cmukwind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	long long int	result;
	long long int	sign;
	unsigned int	index;

	result = 0;
	sign = 1;
	index = 0;
	while (str[index] == ' ' || str[index] == '\t' || str[index] == '\v' ||
			str[index] == '\n' || str[index] == '\r' || str[index] == '\f')
		index++;
	if (str[index] == '-' || str[index] == '+')
	{
		if (str[index] == '-')
			sign = -1;
		index++;
	}
	while (str[index] >= 48 && str[index] <= 57)
	{
		result = result * 10 + str[index] - 48;
		index++;
	}
	return ((int)(result * sign));
}
