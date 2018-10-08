/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmukwind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/01 08:46:32 by cmukwind          #+#    #+#             */
/*   Updated: 2018/08/23 11:47:39 by cmukwind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ls_putstr(char const *str)
{
	int	index;

	index = 0;
	while (str[index] != '\0')
	{
		ls_putchar(str[index]);
		index++;
	}
	return (index);
}
