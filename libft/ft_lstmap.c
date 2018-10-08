/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmukwind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/15 14:12:46 by cmukwind          #+#    #+#             */
/*   Updated: 2018/06/16 11:04:59 by cmukwind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*nlst;
	t_list	*lstm;

	if (lst == NULL)
		return (NULL);
	lstm = f(lst);
	nlst = lstm;
	while (lst->next != NULL)
	{
		lst = lst->next;
		if (!(lstm->next = f(lst)))
		{
			free(lstm->next);
			return (NULL);
		}
		lstm = lstm->next;
	}
	return (nlst);
}
