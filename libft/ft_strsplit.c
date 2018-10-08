/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmukwind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/07 12:11:11 by cmukwind          #+#    #+#             */
/*   Updated: 2018/06/12 10:29:50 by cmukwind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_wordcnt(char const *s, char c)
{
	unsigned int	index;
	unsigned int	cntr;

	index = 0;
	cntr = 0;
	while (s[index])
	{
		while (s[index] == c)
			index++;
		if (s[index] != '\0')
			cntr++;
		while (s[index] && (s[index] != c))
			index++;
	}
	return (cntr);
}

static char	*ft_strndup(const char *str, size_t n)
{
	char			*pstr;

	pstr = (char *)malloc(sizeof(char) * n + 1);
	if (pstr == NULL)
		return (NULL);
	pstr = ft_strncpy(pstr, str, n);
	pstr[n] = '\0';
	return (pstr);
}

char		**ft_strsplit(char const *s, char c)
{
	int		i;
	int		j;
	int		k;
	char	**sstr;

	if (!s)
		return (NULL);
	i = 0;
	k = 0;
	if (!(sstr = (char **)malloc(sizeof(char *) * (ft_wordcnt(s, c)) + 1)))
		return (NULL);
	while (s[i])
	{
		while (s[i] == c)
			i++;
		j = i;
		while (s[i] && s[i] != c)
			i++;
		if (i > j)
			sstr[k++] = ft_strndup(s + j, i - j);
	}
	sstr[k] = NULL;
	return (sstr);
}
