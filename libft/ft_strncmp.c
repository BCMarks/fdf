/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmarks <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 10:57:23 by bmarks            #+#    #+#             */
/*   Updated: 2019/06/10 15:59:25 by bmarks           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (0);
	while ((*(s1 + i) == *(s2 + i)) && *(s1 + i) && *(s2 + i) && i < (int)n - 1)
		i++;
	if (((unsigned char)*(s1 + i) - (unsigned char)*(s2 + i)) > 0)
		return (1);
	else if (((unsigned char)*(s1 + i) - (unsigned char)*(s2 + i)) < 0)
		return (-1);
	return (0);
}
