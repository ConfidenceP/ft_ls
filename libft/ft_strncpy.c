/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmukwind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 08:02:42 by cmukwind          #+#    #+#             */
/*   Updated: 2018/09/12 09:26:24 by cmukwind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dest, const char *src, size_t len)
{
	size_t	index;

	index = 0;
	while (src[index] != '\0' && index < len)
	{
		dest[index] = src[index];
		index++;
	}
	while (index < len)
	{
		dest[index] = '\0';
		index++;
	}
	return (dest);
}
