/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdanyell <rdanyell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 12:01:59 by rdanyell          #+#    #+#             */
/*   Updated: 2022/02/18 12:02:02 by rdanyell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*tmp;
	t_list	*element;

	if (lst)
	{
		tmp = NULL;
		while (lst && f)
		{
			element = ft_lstnew(f(lst->content));
			if (!element)
			{
				ft_lstclear(&tmp, del);
				return (NULL);
			}
			ft_lstadd_back(&tmp, element);
			lst = lst->next;
		}
		return (tmp);
	}
	return (NULL);
}
