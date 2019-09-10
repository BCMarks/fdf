/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmarks <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 15:29:32 by bmarks            #+#    #+#             */
/*   Updated: 2019/06/10 15:47:08 by bmarks           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*nlst;

	if (!(nlst = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	if (content == NULL)
	{
		nlst->content = NULL;
		nlst->content_size = 0;
	}
	else
	{
		if (!(nlst->content = malloc(content_size)))
			return (NULL);
		ft_memcpy(nlst->content, content, content_size);
		nlst->content_size = content_size;
	}
	nlst->next = NULL;
	return (nlst);
}
