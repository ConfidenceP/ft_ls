/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uputwnbr_base.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmukwind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/20 10:34:11 by cmukwind          #+#    #+#             */
/*   Updated: 2018/08/21 15:25:54 by cmukwind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned long long		ft_uputwnbr_base(unsigned long long nb, char *base)
{
	unsigned long long	a;
	int					i;

	if ((unsigned long)nb == -9223372036854775808u)
	{
		ls_putstr("-9223372036854775808");
		return (1);
	}
	if (nb < 0)
	{
		ls_putchar('-');
		nb = nb * -1;
	}
	i = ls_strlen(base);
	a = nb % i;
	nb = nb / i;
	if (nb > 0)
		ft_uputwnbr_base(nb, base);
	ls_putchar(base[a]);
	return (nb);
}
