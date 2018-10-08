/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   funcs5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmukwind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/22 13:29:24 by cmukwind          #+#    #+#             */
/*   Updated: 2018/08/25 14:16:53 by cmukwind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		pf_putwstr(va_list ap)
{
	wchar_t	*wstr;
	int		i;

	wstr = va_arg(ap, wchar_t*);
	i = 0;
	if (wstr == NULL)
	{
		return (ls_putstr("(null)"));
	}
	while (wstr[i] != '\0')
	{
		ft_putwchar(wstr[i]);
		i++;
	}
	return (i);
}
