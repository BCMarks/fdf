/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmarks <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 13:44:18 by bmarks            #+#    #+#             */
/*   Updated: 2019/06/10 15:43:36 by bmarks           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

static void	str_number(char *str, int n, int len)
{
	int				og_len;
	int				stop;
	unsigned int	n2;
	char			digit;

	og_len = len - 1;
	stop = 1;
	n2 = n;
	if (n < 0)
	{
		*str = '-';
		n2 = -n;
		stop++;
	}
	while (len > stop)
	{
		if (n2 % 10 >= 0 || n2 % 10 <= 9)
		{
			digit = (n2 % 10) + '0';
			*(str + len - 2) = digit;
			len--;
		}
		n2 /= 10;
	}
	*(str + og_len) = '\0';
}

char		*ft_itoa(int n)
{
	char			*str;
	unsigned int	num;
	int				len;

	num = n;
	len = 1;
	if (n < 0)
	{
		num = -n;
		len++;
	}
	while (num > 9)
	{
		num /= 10;
		len++;
	}
	if (!(str = (char *)malloc(sizeof(char) * len + 1)))
		return (NULL);
	str_number(str, n, len + 1);
	return (str);
}
