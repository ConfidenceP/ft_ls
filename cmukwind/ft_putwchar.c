/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwchar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmukwind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/19 09:39:37 by cmukwind          #+#    #+#             */
/*   Updated: 2018/08/23 08:52:34 by cmukwind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

inline static int	size_wchar(unsigned int wchar)
{
	if (wchar <= 127)
		return (1);
	else if (wchar >= 128 && wchar <= 2047)
		return (2);
	else if (wchar >= 2048 && wchar <= 65535)
		return (3);
	else if (wchar >= 65536 && wchar <= 2097151)
		return (4);
	else
		return (0);
}

int					ft_putwchar(wchar_t wchar)
{
	char					res;
	char					size;
	unsigned char			curr_byte;

	res = 0;
	size = size_wchar(wchar);
	if (size == 1)
		return (ls_putchar(wchar));
	curr_byte = (260 << (4 - size)) | (wchar >> ((size - 1) * 6));
	res += ls_putchar(curr_byte);
	size--;
	while (size--)
	{
		curr_byte = ((wchar >> ((size) * 6)) & 63) | 128;
		res += ls_putchar(curr_byte);
	}
	return (res);
}
