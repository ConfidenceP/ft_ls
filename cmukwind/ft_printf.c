/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmukwind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/16 10:55:08 by cmukwind          #+#    #+#             */
/*   Updated: 2018/09/18 15:37:19 by cmukwind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		cspec(char p)
{
	char	*spec;
	int		i;

	spec = "sSpdDioOuUxXcC%#+";
	i = 0;
	while (spec[i])
	{
		if (spec[i] == p)
			return (i);
		i++;
	}
	return (-1);
}

void	specs_init(int (**specs)(va_list ap))
{
	specs[0] = &pf_putstr;
	specs[1] = &pf_putstr;
	specs[2] = &pf_hex_p;
	specs[3] = &pf_putnbr;
	specs[4] = &pf_putwnbr;
	specs[5] = &pf_putnbr;
	specs[6] = &pf_octal;
	specs[7] = &pf_woctal;
	specs[8] = &pf_dec;
	specs[9] = &pf_wdec;
	specs[10] = &pf_hex_a;
	specs[11] = &pf_hex;
	specs[12] = &pf_putchar;
	specs[13] = &pf_putchar;
	specs[14] = &pf_percent;
	specs[15] = &move_on;
	specs[16] = &move_on;
}

int		ft_printf(const char *format, ...)
{
	va_list		ap;
	int			(*specs[17])(va_list ap);
	int			i;
	int			count;
	char		*f2;

	f2 = (char*)format;
	count = 0;
	i = -1;
	specs_init(specs);
	va_start(ap, format);
	while (f2[++i] != '\0')
		if (f2[i] == '%' && cspec(f2[i + 1]) != -1)
		{
			if (f2[i + 2] && (cspec(f2[i + 1]) >= 15 && cspec(f2[i + 1]) <= 17))
				count += check_flag(&f2[i + 2], cspec(f2[i + 1]), ap);
			count += specs[cspec(f2[i + 1])](ap);
			(cspec(f2[i + 1]) >= 15 && cspec(f2[i + 1]) <= 17) ? i++ : 0;
			i++;
		}
		else
			count += (f2[i] == '%' && f2[i + 1] != '%') ? 0 : ls_putchar(f2[i]);
	va_end(ap);
	return (count);
}
