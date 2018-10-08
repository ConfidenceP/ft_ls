/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmukwind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/04 10:34:22 by cmukwind          #+#    #+#             */
/*   Updated: 2018/06/12 10:31:22 by cmukwind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int nbr1, int fd)
{
	unsigned int	nbr2;

	nbr2 = nbr1;
	if (nbr1 == -2147483648)
		ft_putstr_fd("-2147483648", fd);
	else if (nbr1 < 0)
	{
		ft_putchar_fd('-', fd);
		ft_putnbr_fd(-nbr1, fd);
	}
	else if (nbr2 >= 10)
	{
		ft_putnbr_fd(nbr2 / 10, fd);
		ft_putchar_fd(nbr2 % 10 + '0', fd);
	}
	else
		ft_putchar_fd(nbr2 + '0', fd);
}
