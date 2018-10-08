/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uputnbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmukwind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/23 07:47:37 by cmukwind          #+#    #+#             */
/*   Updated: 2018/08/25 14:22:38 by cmukwind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_uputnbr(unsigned int nbr1)
{
	unsigned int	nbr2;

	nbr2 = nbr1;
	if (nbr2 >= 10)
	{
		ft_uputnbr(nbr2 / 10);
		ls_putchar(nbr2 % 10 + '0');
	}
	else
		ls_putchar(nbr2 + '0');
	return (0);
}
