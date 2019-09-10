/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmarks <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/04 09:36:55 by bmarks            #+#    #+#             */
/*   Updated: 2019/06/10 15:46:46 by bmarks           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*nlst;
	t_list	*data;
	t_list	*head;

	if (lst && f)
	{
		data = f(lst);
		nlst = ft_lstnew(data->content, data->content_size);
		head = nlst;
		lst = lst->next;
		while (lst != NULL)
		{
			data = f(lst);
			nlst->next = ft_lstnew(data->content, data->content_size);
			lst = lst->next;
			nlst = nlst->next;
		}
		return (head);
	}
	return (NULL);
}
