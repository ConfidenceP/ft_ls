/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmukwind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/25 07:55:45 by cmukwind          #+#    #+#             */
/*   Updated: 2018/09/12 16:20:30 by cmukwind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	int		index;
	char	*pstr;

	index = 0;
	pstr = (char *)malloc(sizeof(char) * ft_strlen(str) + 1);
	if (pstr == NULL)
		return (NULL);
	while (str[index] != '\0')
	{
		pstr[index] = str[index];
		index++;
	}
	pstr[index] = '\0';
	return (pstr);
}
