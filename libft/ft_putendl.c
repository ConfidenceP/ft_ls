/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmukwind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/01 09:00:06 by cmukwind          #+#    #+#             */
/*   Updated: 2018/06/05 17:02:44 by cmukwind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl(char const *str)
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
	ft_putchar('\n');
}
