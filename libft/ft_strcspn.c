/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcspn.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmarks <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/28 14:11:59 by bmarks            #+#    #+#             */
/*   Updated: 2019/06/10 15:56:06 by bmarks           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

size_t	ft_strcspn(const char *s1, const char *s2)
{
	size_t	i[2];
	int		brk;

	i[0] = 0;
	i[1] = 0;
	brk = 0;
	while (*(s1 + i[0]))
	{
		while (*(s2 + i[1]))
		{
			if (*(s1 + i[0]) != *(s2 + i[1]))
				brk = 1;
			i[1]++;
		}
		if (brk)
			break ;
		i[1] = 0;
		i[0]++;
	}
	if (!brk)
		return (ft_strlen(s1));
	i[0] = 0;
	while (ft_strchr(s2, *(s1 + i[0])) == NULL && *(s1 + i[0]))
		i[0]++;
	return (i[0]);
}
