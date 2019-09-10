/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmarks <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/20 14:52:38 by bmarks            #+#    #+#             */
/*   Updated: 2019/06/10 15:49:45 by bmarks           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	*ft_memmove(void *s1, const void *s2, size_t n)
{
	unsigned char	*dst;
	unsigned char	*src;
	size_t			i;

	if (s1 == NULL && s2 == NULL)
		return (s1);
	dst = (unsigned char *)s1;
	src = (unsigned char *)s2;
	if (s2 < s1)
	{
		i = n;
		while (i-- > 0)
			dst[i] = src[i];
	}
	else
	{
		i = 0;
		while (i < n)
		{
			dst[i] = src[i];
			i++;
		}
	}
	return (s1);
}
