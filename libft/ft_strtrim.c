/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmukwind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/06 14:24:34 by cmukwind          #+#    #+#             */
/*   Updated: 2018/06/10 11:39:32 by cmukwind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	unsigned int	index1;
	unsigned int	index2;
	unsigned int	index3;
	char			*str;

	if (!s)
		return (NULL);
	index1 = 0;
	while (s[index1] == ' ' || s[index1] == '\n' || s[index1] == '\t')
		index1++;
	if (s[index1] == '\0')
		return (ft_strcpy((char*)ft_memalloc(sizeof(char) * 2), ""));
	index2 = ft_strlen(s) - 1;
	while (s[index2] == ' ' || s[index2] == '\n' || s[index2] == '\t')
		index2--;
	str = (char*)ft_memalloc(sizeof(char) * index2 - index1 + 2);
	if (str == NULL)
		return (NULL);
	index3 = -1;
	while (++index3 < index2 - index1 + 1)
		str[index3] = s[index1 + index3];
	str[index3] = '\0';
	return (str);
}
