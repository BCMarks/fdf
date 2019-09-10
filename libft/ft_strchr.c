/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmarks <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 12:43:11 by bmarks            #+#    #+#             */
/*   Updated: 2019/06/10 15:55:03 by bmarks           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strchr(const char *s, int n)
{
	int	i;

	i = 0;
	while (*(s + i))
	{
		if (*(s + i) == n)
			return ((char *)(s + i));
		i++;
	}
	if (n == '\0')
		return ((char *)(s + i));
	return (NULL);
}
