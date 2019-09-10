/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmarks <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/14 12:13:21 by bmarks            #+#    #+#             */
/*   Updated: 2019/06/10 15:49:59 by bmarks           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	*ft_memset(void *s, int n, size_t i)
{
	unsigned char	*c;
	size_t			j;

	j = 0;
	c = (unsigned char *)s;
	while (j < i)
		*(c + j++) = n;
	return (s);
}
