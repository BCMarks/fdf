/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmarks <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 12:22:01 by bmarks            #+#    #+#             */
/*   Updated: 2019/06/10 15:58:48 by bmarks           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	char	*fresh;

	i = 0;
	if (s && f)
	{
		if (!(fresh = (char *)malloc(sizeof(char) * ft_strlen(s) + 1)))
			return (NULL);
		while (*(s + i))
		{
			*(fresh + i) = f(i, *(s + i));
			i++;
		}
		*(fresh + i) = '\0';
		return (fresh);
	}
	return (NULL);
}
