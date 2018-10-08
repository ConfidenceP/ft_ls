/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmukwind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/30 16:33:06 by cmukwind          #+#    #+#             */
/*   Updated: 2018/06/04 16:10:42 by cmukwind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	size_t	index1;
	size_t	index2;

	index1 = 0;
	if (*needle == '\0' || (*haystack == '\0' && *needle == '\0'))
		return ((char*)haystack);
	if (*haystack == '\0')
		return (NULL);
	while (haystack[index1] != '\0')
	{
		index2 = 0;
		while (haystack[index1 + index2] == needle[index2] && needle[index2])
			index2++;
		if (needle[index2] == '\0')
			return ((char*)haystack + index1);
		index1++;
	}
	return (NULL);
}
