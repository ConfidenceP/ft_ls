/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmukwind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/04 10:25:01 by cmukwind          #+#    #+#             */
/*   Updated: 2018/06/12 09:33:12 by cmukwind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char const *str, int fd)
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
	ft_putchar_fd('\n', fd);
}
