/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmukwind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/04 08:28:14 by cmukwind          #+#    #+#             */
/*   Updated: 2018/06/05 17:05:46 by cmukwind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char const *str, int fd)
{
	size_t	index;

	index = 0;
	if (!str)
		return ;
	while (str[index] != '\0')
	{
		ft_putchar_fd(str[index], fd);
		index++;
	}
}
