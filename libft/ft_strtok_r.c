/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtok_r.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmarks <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/28 15:14:21 by bmarks            #+#    #+#             */
/*   Updated: 2019/06/10 16:02:42 by bmarks           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strtok_r(char *s1, const char *s2, char **lasts)
{
	char	*end;

	if (s1 == NULL)
		s1 = *lasts;
	if (*s1 == '\0')
	{
		*lasts = s1;
		return (NULL);
	}
	s1 = s1 + ft_strspn(s1, s2);
	if (*s1 == '\0')
	{
		*lasts = s1;
		return (NULL);
	}
	end = s1 + ft_strcspn(s1, s2);
	if (*end == '\0')
	{
		*lasts = end;
		return (s1);
	}
	*end = '\0';
	*lasts = end + 1;
	return (s1);
}
