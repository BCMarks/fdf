/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmarks <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/04 15:52:38 by bmarks            #+#    #+#             */
/*   Updated: 2019/06/10 16:01:26 by bmarks           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

static int	ft_strc(char const *s, char c)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	while (*(s + i) == c && *(s + i))
		i++;
	while (*(s + i))
	{
		count++;
		while (*(s + i) != c && *(s + i))
			i++;
		while (*(s + i) == c && *(s + i))
			i++;
	}
	return (count);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**fresh;
	int		i[2];
	int		k;

	if (!s || !(fresh = (char **)malloc(sizeof(char *) * (ft_strc(s, c) + 1))))
		return (NULL);
	i[0] = 0;
	i[1] = 0;
	k = 0;
	while (*(s + i[0]) && ft_strc(s, c))
	{
		i[1] = 0;
		while (*(s + i[0]) == c && *(s + i[0]))
			i[0]++;
		while (*(s + i[0] + i[1]) != c && *(s + i[0] + i[1]))
			i[1]++;
		if (!(fresh[k] = ft_strsub(s, (unsigned int)i[0], (size_t)i[1])))
			return (NULL);
		k++;
		if (k == ft_strc(s, c))
			break ;
		i[0] += i[1];
	}
	fresh[k] = NULL;
	return (fresh);
}
