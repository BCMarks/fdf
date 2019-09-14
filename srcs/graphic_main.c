/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmarks <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 11:06:26 by bmarks            #+#    #+#             */
/*   Updated: 2019/09/14 13:09:10 by bmarks           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include <stdio.h>

int	col_pick(t_data data, int i, int j)
{
	int	c;

	if (ft_atoi(data.mesh[i][j]) <
			data.m_min_z + (data.m_max_z - data.m_min_z) / 3)
		c = BROWN;
	else if (ft_atoi(data.mesh[i][j]) <
			data.m_min_z + 2 * (data.m_max_z - data.m_min_z) / 3)
		c = RED;
	else if (ft_atoi(data.mesh[i][j]) <
			data.m_min_z + 3 * (data.m_max_z - data.m_min_z) / 3)
		c = ORANGE;
	else
		c = GOLD;
	return (c);
}

static int	key_input(int key, void *p[])
{
	key == KEY_ESC ? (exit(0)) : NULL;
	if (key == KEY_SPACE)
	{
		if (((t_data *)p[2])->mode == 1)
		{
			disp_mesh_2d(p, *(t_data *)p[2]);
			((t_data *)p[2])->mode = 0;
		}
		else
		{
			disp_mesh_3d(p, *(t_data *)p[2]);
			((t_data *)p[2])->mode = 1;
		}
	}
	return (0);
}

void		graphic_main(t_data data)
{
	void	*p[4];

	printf("z_max = %d z_min = %d\n", data.m_max_z, data.m_min_z);	
	printf("mx = %d my = %d\n", data.m_x, data.m_y);
	printf("wx = %d wy = %d\n", data.w_x, data.w_y);
	printf("x_offset = %d y_offset = %d\n", data.x_offset, data.y_offset);
	p[0] = mlx_init();
	p[1] = mlx_new_window(p[0], data.w_x, data.w_y, ft_strjoin("fdf - ", data.file));
	p[2] = &data;
	disp_mesh_2d(p, data);
	mlx_key_hook(p[1], &key_input, p);
	mlx_loop(p[0]);
}
