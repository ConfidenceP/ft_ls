/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_unbr_base.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmukwind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/04 11:27:05 by cmukwind          #+#    #+#             */
/*   Updated: 2018/08/25 14:21:27 by cmukwind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#include "ft_printf.h"

int		ft_put_unbr_base(uintmax_t nb, char *base)
{
	int				a;
	int				count;
	unsigned int	len_str;

	count = 0;
	len_str = ls_strlen(base);
	a = nb % len_str;
	if (nb > 0)
	{
		nb = nb / len_str;
		count += ft_put_unbr_base(nb, base);
		ls_putchar(base[a]);
		count++;
	}
	return (count);
}
