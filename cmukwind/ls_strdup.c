/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmukwind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/25 07:55:45 by cmukwind          #+#    #+#             */
/*   Updated: 2018/08/21 15:25:14 by cmukwind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ls_strdup(const char *str)
{
	int		index;
	char	*pstr;

	index = 0;
	pstr = (char *)malloc(sizeof(char) * ls_strlen(str) + 1);
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
