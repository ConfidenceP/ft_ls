/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmukwind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/06 11:05:38 by cmukwind          #+#    #+#             */
/*   Updated: 2018/06/13 17:00:03 by cmukwind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	unsigned int	index1;
	unsigned int	index2;
	char			*pnstr;

	if (!s1 || !s2)
		return (NULL);
	index1 = 0;
	index2 = 0;
	pnstr = (char*)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2)) + 1);
	if (pnstr == NULL)
		return (NULL);
	while (s1[index1])
	{
		pnstr[index1] = s1[index1];
		index1++;
	}
	while (s2[index2])
	{
		pnstr[index1] = s2[index2];
		index1++;
		index2++;
	}
	pnstr[index1] = '\0';
	return (pnstr);
}
