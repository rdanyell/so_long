/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdanyell <rdanyell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 12:01:20 by rdanyell          #+#    #+#             */
/*   Updated: 2022/02/18 12:01:27 by rdanyell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*tmp;

	if (del)
	{
		while (*lst)
		{
			del((*lst)->content);
			tmp = *lst;
			*lst = tmp->next;
			free(tmp);
		}
		*lst = NULL;
	}
}
