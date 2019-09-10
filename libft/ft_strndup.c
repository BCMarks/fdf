/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmarks <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/13 12:05:38 by bmarks            #+#    #+#             */
/*   Updated: 2019/06/13 12:09:31 by bmarks           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strndup(const char *s, size_t n)
{
	char	*ns;
	int		i;

	i = 0;
	if (!(ns = (char *)malloc(n + 1)))
		return (NULL);
	while (*(s + i))
	{
		*(ns + i) = *(s + i);
		i++;
	}
	*(ns + i) = '\0';
	return (ns);
}
