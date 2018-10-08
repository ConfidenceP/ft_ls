/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmukwind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/12 09:29:27 by cmukwind          #+#    #+#             */
/*   Updated: 2018/08/23 08:49:21 by cmukwind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_putwstr(wchar_t *wstr)
{
	char	res;
	int		i;

	res = 0;
	i = 0;
	if (wstr == NULL)
		return (ls_putstr("(null)"));
	while (wstr[i] != 48)
		res += ls_putchar(wstr[i++]);
	return (res);
}
