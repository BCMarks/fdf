/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmarks <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 14:54:34 by bmarks            #+#    #+#             */
/*   Updated: 2019/06/10 15:57:38 by bmarks           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*fresh;
	size_t	len;

	if (s1 && s2)
	{
		len = ft_strlen(s1) + ft_strlen(s2) + 1;
		if (!(fresh = (char *)malloc(sizeof(char) * len)))
			return (NULL);
		ft_strcpy(fresh, s1);
		ft_strcat(fresh, s2);
		return (fresh);
	}
	return (NULL);
}
