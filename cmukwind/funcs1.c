/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   funcs1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmukwind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/19 09:17:33 by cmukwind          #+#    #+#             */
/*   Updated: 2018/08/25 11:23:13 by cmukwind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		pf_putstr(va_list ap)
{
	char		*str;
	long long	count;

	str = va_arg(ap, char*);
	if (str == NULL)
		return (ls_putstr("(null)"));
	count = ls_strlen(str);
	ls_putstr(str);
	return (count);
}

int		pf_putnbr(va_list ap)
{
	int				nb;
	unsigned int	count;

	nb = va_arg(ap, int);
	count = digit_count(nb);
	ls_putnbr(nb);
	return (count);
}

int		pf_putchar(va_list ap)
{
	char c;

	c = va_arg(ap, unsigned long int);
	ls_putchar(c);
	return (1);
}

int		pf_ptradd(va_list ap)
{
	long long		ptr;
	char			*base;

	ptr = va_arg(ap, long long);
	base = "0123456789abcdef";
	ls_putstr("0x");
	return (ls_putnbr_base(ptr, base));
}

int		pf_putwchar(va_list ap)
{
	wchar_t	c;
	int		len;

	len = 0;
	c = va_arg(ap, wchar_t);
	if (c <= 127)
		len = 1;
	else if (c >= 128 && c <= 2047)
		len = 2;
	else if (c >= 2048 && c <= 65535)
		len = 3;
	else if (c >= 65536 && c <= 2097151)
		len = 4;
	write(1, &c, len);
	return (len);
}
