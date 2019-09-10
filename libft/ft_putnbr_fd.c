/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmarks <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/15 15:38:55 by bmarks            #+#    #+#             */
/*   Updated: 2019/06/10 15:53:06 by bmarks           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	num;
	char			digit;

	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		n *= -1;
	}
	num = n;
	if (num >= 10)
		ft_putnbr_fd((num / 10), fd);
	digit = (num % 10) + '0';
	ft_putchar_fd(digit, fd);
}
