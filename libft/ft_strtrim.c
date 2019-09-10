/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmarks <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 15:10:24 by bmarks            #+#    #+#             */
/*   Updated: 2019/06/10 16:02:57 by bmarks           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strtrim(char const *s)
{
	char	*fresh;
	int		i;
	int		len;
	int		p[2];

	if (s)
	{
		i = 0;
		len = (int)ft_strlen(s);
		p[0] = 0;
		p[1] = 0;
		while (*(s + p[0]) == 32 || *(s + p[0]) == 10 || *(s + p[0]) == 9)
			p[0]++;
		while ((*(s + len - p[1] - 1) == 32 || *(s + len - p[1] - 1) == 10
				|| *(s + len - p[1] - 1) == 9) && len - p[1] - 1 > p[0])
			p[1]++;
		p[1] = len - p[1];
		if (!(fresh = (char *)malloc(sizeof(char) * (p[1] - p[0] + 1))))
			return (NULL);
		while (*(s + p[0]) && p[0] < p[1])
			*(fresh + i++) = *(s + p[0]++);
		*(fresh + i) = '\0';
		return (fresh);
	}
	return (NULL);
}
