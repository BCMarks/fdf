/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmarks <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 14:38:20 by bmarks            #+#    #+#             */
/*   Updated: 2019/06/10 16:02:04 by bmarks           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strstr(const char *s1, const char *s2)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!*s2)
		return ((char *)s1);
	while (*(s1 + i))
	{
		while (*(s1 + i + j) == *(s2 + j))
		{
			j++;
			if (!*(s2 + j))
				return ((char *)(s1 + i));
		}
		i++;
		j = 0;
	}
	return (NULL);
}
