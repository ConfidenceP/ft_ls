/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   funcs.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmukwind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/25 15:01:18 by cmukwind          #+#    #+#             */
/*   Updated: 2018/09/18 15:36:36 by cmukwind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		pf_hex_p(va_list ap)
{
	uintmax_t	hexa;
	char		*base;
	int			ret;

	hexa = (uintmax_t)va_arg(ap, void *);
	base = "0123456789abcdef";
	if (hexa == 0)
	{
		ls_putstr("0x");
		ls_putnbr(hexa);
		return (3);
	}
	else
	{
		ls_putstr("0x");
		ret = ft_put_unbr_base(hexa, base);
	}
	return (ret + 2);
}

int		pf_hex_x(va_list ap)
{
	unsigned int	hexa;
	char			*base;
	int				ret;

	hexa = va_arg(ap, unsigned int);
	base = "0123456789abcdef";
	if (hexa == 0)
	{
		ls_putnbr(hexa);
		return (1);
	}
	else
	{
		ls_putstr("0x");
		ret = ft_put_unbr_base(hexa, base);
	}
	return (ret + 2);
}

int		pf_hex_h(va_list ap)
{
	unsigned int	hexa;
	char			*base;
	int				ret;

	hexa = va_arg(ap, unsigned int);
	base = "0123456789ABCDEF";
	if (hexa == 0)
	{
		ls_putnbr(hexa);
		return (1);
	}
	else
	{
		ls_putstr("0X");
		ret = ft_put_unbr_base(hexa, base);
	}
	return (ret + 2);
}

int		pf_hex(va_list ap)
{
	unsigned int	hex;
	char			*base;
	int				ret;

	hex = va_arg(ap, unsigned int);
	base = "0123456789ABCDEF";
	if (hex == 0)
	{
		ls_putnbr(hex);
		return (1);
	}
	else
		ret = ft_put_unbr_base(hex, base);
	return (ret);
}

int		pf_hex_a(va_list ap)
{
	unsigned int	hexa;
	char			*base;
	int				ret;

	hexa = va_arg(ap, unsigned int);
	base = "0123456789abcdef";
	if (hexa == 0)
	{
		ls_putnbr(hexa);
		return (1);
	}
	else
		ret = ft_put_unbr_base(hexa, base);
	return (ret);
}
