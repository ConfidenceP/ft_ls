/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmukwind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/06 07:40:13 by cmukwind          #+#    #+#             */
/*   Updated: 2018/06/16 15:05:20 by cmukwind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	unsigned int	index;
	char			*pnewstr;

	index = 0;
	pnewstr = (char*)malloc(sizeof(char) * len + 1);
	if (!s || (pnewstr == NULL))
		return (NULL);
	while (index < len)
	{
		pnewstr[index] = s[index + start];
		index++;
	}
	pnewstr[index] = '\0';
	return (pnewstr);
}
