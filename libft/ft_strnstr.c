/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmukwind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/31 08:53:32 by cmukwind          #+#    #+#             */
/*   Updated: 2018/06/04 16:21:16 by cmukwind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t num_bits)
{
	size_t	index1;
	size_t	index2;

	index1 = 0;
	if (*needle == '\0' || (*haystack == '\0' && *needle == '\0'))
		return ((char*)haystack);
	if (*haystack == '\0')
		return (NULL);
	while (haystack[index1] != '\0' || num_bits > index1)
	{
		index2 = 0;
		while ((index1 + index2 < num_bits) &&
				haystack[index1 + index2] == needle[index2] && needle[index2])
			index2++;
		if (needle[index2] == '\0')
			return ((char*)haystack + index1);
		index1++;
	}
	return (NULL);
}
