/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   funcs4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmukwind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/21 14:49:29 by cmukwind          #+#    #+#             */
/*   Updated: 2018/08/25 14:23:48 by cmukwind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		pf_dec(va_list ap)
{
	unsigned int	nb;
	int				count;

	count = 0;
	nb = va_arg(ap, unsigned int);
	count = digit_count(nb);
	ft_uputnbr(nb);
	if (nb == 0)
		return (count + 1);
	return (count);
}

int		pf_wdec(va_list ap)
{
	unsigned long long	nb;
	int					count;

	count = 0;
	nb = va_arg(ap, unsigned long long);
	count = digit_count(nb);
	ft_putwnbr(nb);
	return (count);
}

int		pf_percent(va_list ap)
{
	(void)ap;
	ls_putchar('%');
	return (1);
}

int		move_on(va_list ap)
{
	(void)ap;
	return (0);
}

int		pf_putwnbr(va_list ap)
{
	long long		nb;
	unsigned int	count;

	nb = va_arg(ap, long long);
	count = digit_count(nb);
	ft_putwnbr(nb);
	return (count);
}
