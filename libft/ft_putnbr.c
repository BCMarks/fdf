/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmarks <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/15 15:38:55 by bmarks            #+#    #+#             */
/*   Updated: 2019/06/10 15:52:52 by bmarks           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	ft_putnbr(int n)
{
	unsigned int	num;
	char			digit;

	if (n < 0)
	{
		ft_putchar('-');
		n *= -1;
	}
	num = n;
	if (num >= 10)
		ft_putnbr(num / 10);
	digit = (num % 10) + '0';
	ft_putchar(digit);
}
