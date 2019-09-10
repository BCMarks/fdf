/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmarks <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/20 12:38:36 by bmarks            #+#    #+#             */
/*   Updated: 2019/06/10 15:48:58 by bmarks           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	*ft_memcpy(void *s1, const void *s2, size_t n)
{
	size_t	i;
	char	*dst;
	char	*src;

	if (s1 != NULL || s2 != NULL)
	{
		i = 0;
		dst = (char *)s1;
		src = (char *)s2;
		while (i < n)
		{
			*(dst + i) = *(src + i);
			i++;
		}
	}
	return (s1);
}
