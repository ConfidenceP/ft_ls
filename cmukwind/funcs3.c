/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   funcs3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmukwind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/21 12:23:05 by cmukwind          #+#    #+#             */
/*   Updated: 2018/09/18 15:37:58 by cmukwind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		check_flag_15a(char *p, va_list ap)
{
	char	*str;
	int		j;
	int		k;

	str = "sSdDioOuUxX";
	j = 0;
	k = 0;
	while (str[j] && (str[j] != p[k]))
		j++;
	if (j == 0)
		return (pf_putstr(ap));
	else if (j == 1)
		return (pf_putwstr(ap));
	else if ((j >= 2 && j <= 4) || j == 7 || j == 8)
		return (pf_putnbr(ap));
	else if (j == 5 || j == 6)
	{
		ls_putchar('0');
		return (pf_octal_b(ap) + 1);
	}
	else
		return (check_flag_15b(p, ap));
}

int		check_flag_15b(char *p, va_list ap)
{
	char	*str;
	int		j;
	int		k;

	str = "sSdDioOuUxX";
	j = 0;
	k = 0;
	(void)ap;
	while (str[j] && (str[j] != p[k]))
		j++;
	if (j == 9)
		return (pf_hex_x(ap));
	else if (j == 10)
		return (pf_hex_h(ap));
	else
		return (ls_putchar(p[0]));
	return (1);
}

int		check_flag_18a(char *p, va_list ap)
{
	char		*str;
	int			j;
	int			k;

	str = "sSdDioOuUxX";
	j = 0;
	k = 0;
	while (str[j] && str[j] != p[0])
		j++;
	if (j == 0 || j == 1)
		return (pf_putstr(ap));
	else if (j >= 2 && j <= 4)
	{
		k = va_arg(ap, int);
		if (k >= 0)
			ls_putchar('+');
		ls_putnbr(k);
		return (digit_count(k) + 1);
	}
	return (0);
}

int		check_flag(char *p, int i, va_list ap)
{
	int		k;

	k = 0;
	if (i == 15)
		return (check_flag_15a(p, ap));
	if (i == 16)
	{
		if (*p == 'd' || *p == 'i')
		{
			k = va_arg(ap, int);
			if (k >= 0)
				ls_putchar('+');
			ls_putnbr(k);
			if (k == 0)
				return (digit_count(++k) + 1);
			if (k >= 0)
				return (digit_count(k) + 1);
			else
				return (digit_count(k));
		}
		else if (*p == 'D')
			return (plus_flag(ap));
	}
	return (1);
}

int		plus_flag(va_list ap)
{
	long long	j;

	j = va_arg(ap, long long);
	if (j >= 0)
		ls_putchar('+');
	ft_putwnbr(j);
	if (j == 0)
		return (digit_count(++j) + 1);
	if (j >= 0)
		return (digit_count(j) + 1);
	else
		return (digit_count(j));
	return (1);
}
