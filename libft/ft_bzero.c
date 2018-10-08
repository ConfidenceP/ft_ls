/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmukwind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/23 11:59:19 by cmukwind          #+#    #+#             */
/*   Updated: 2018/05/31 11:00:08 by cmukwind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *str, int num_bit)
{
	int		index;
	char	*pstr;

	index = 0;
	pstr = (char*)str;
	while (num_bit > index)
	{
		pstr[index] = 0;
		index++;
	}
}
