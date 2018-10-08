/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmukwind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/01 08:46:32 by cmukwind          #+#    #+#             */
/*   Updated: 2018/06/05 17:01:19 by cmukwind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr(char const *str)
{
	size_t	index;

	index = 0;
	if (!str)
		return ;
	while (str[index] != '\0')
	{
		ft_putchar(str[index]);
		index++;
	}
}
