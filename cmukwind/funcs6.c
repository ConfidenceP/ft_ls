/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   funcs6.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmukwind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/25 14:58:34 by cmukwind          #+#    #+#             */
/*   Updated: 2018/08/25 15:33:11 by cmukwind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		digit_count(intmax_t nb)
{
	int	i;

	i = 0;
	if (nb < 0)
	{
		nb *= -1;
		i++;
	}
	while (nb)
	{
		nb = nb / 10;
		i++;
	}
	return (i);
}

int		pf_octal(va_list ap)
{
	unsigned int	oct;
	char			*base;

	oct = va_arg(ap, unsigned int);
	if (oct == 0)
		return (ls_putchar('0'));
	base = "01234567";
	return (ft_put_unbr_base(oct, base));
}

int		pf_octal_b(va_list ap)
{
	unsigned int	oct;
	char			*base;

	oct = va_arg(ap, unsigned int);
	base = "01234567";
	return (ft_put_unbr_base(oct, base));
}

int		pf_woctal(va_list ap)
{
	unsigned long long	oct;
	char				*base;

	oct = va_arg(ap, unsigned long long);
	if (oct == 0)
		return (ls_putchar('0'));
	base = "01234567";
	return (ft_put_unbr_base(oct, base));
}

int		pf_woctal_b(va_list ap)
{
	unsigned long long	oct;
	char				*base;

	oct = va_arg(ap, unsigned long long);
	base = "01234567";
	return (ft_put_unbr_base(oct, base));
}
