/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_wunbr_base.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmukwind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/20 09:32:27 by cmukwind          #+#    #+#             */
/*   Updated: 2018/08/21 15:22:24 by cmukwind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned long long	ft_put_wunbr_base(unsigned long long nb, char *base)
{
	unsigned long long	a;
	unsigned long long	len_str;

	len_str = ls_strlen(base);
	a = nb % len_str;
	nb = nb / len_str;
	if (nb > 0)
		ft_putwnbr_base(nb, base);
	ls_putchar(base[a]);
	return (nb);
}
