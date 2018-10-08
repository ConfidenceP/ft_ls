/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmukwind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/05 07:59:40 by cmukwind          #+#    #+#             */
/*   Updated: 2018/06/05 17:00:27 by cmukwind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	unsigned int	index;
	char			*str;

	index = 0;
	if (!s || !f)
		return (NULL);
	str = (char*)malloc(sizeof(char) * (ft_strlen(s)) + 1);
	if (str == NULL)
		return (NULL);
	while (s[index])
	{
		str[index] = f(s[index]);
		index++;
	}
	str[index] = '\0';
	return (str);
}
