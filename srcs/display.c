/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmarks <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 11:56:25 by bmarks            #+#    #+#             */
/*   Updated: 2019/09/14 13:30:25 by bmarks           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	grey_win(void *p[], t_data data)
{
	int	i;
	int	j;

	i = -1;
	mlx_clear_window(p[0], p[1]);
	while (++i < data.w_y)
	{
		j = -1;
		while (++j < data.w_x)
			mlx_pixel_put(p[0], p[1], j, i, 0x696969);
	}
}

void	disp_mesh_3d(void *p[], t_data data)
{
	grey_win(p, data);
}

void	disp_mesh_2d(void *p[], t_data data)
{
	int			i;
	int			j;
	int			k[2];

	grey_win(p, data);
	i = 0;
	while (i < data.m_y)
	{
		j = 0;
		while (data.mesh[i][j] != NULL)
		{
			k[0] = -1;
			while (++k[0] < 8)
			{
				k[1] = -1;
				while (++k[1] < 8)
					mlx_pixel_put(p[0], p[1], data.x_offset + 8 * j + k[0], data.y_offset + 8 * i + k[1], col_pick(data, i, j));
			}
			j++;
		}
		i++;
	}
}
