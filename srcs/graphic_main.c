/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmarks <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 11:06:26 by bmarks            #+#    #+#             */
/*   Updated: 2019/09/11 16:18:50 by bmarks           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static int	col_index(int i)
{
	static int	col = -1;
	static int	col2;

	if (i)
	{
		col += 1;
		if (col == 8)
			col = 0;
		return (col);
	}
	else
	{
		col2 += 1;
		if (col2 == 8)
			col2 = 0;
		return (col2);
	}
}

static void	disp_mesh(void *p[], char ***mesh, int size)
{
	int			i;
	int			j;
	const int	c[] = {RED, ORANGE, YELLOW, GREEN, BLUE, INDIGO, VIOLET};

	mlx_clear_window(p[0], p[1]);
	i = 0;
	while (i < size)
	{
		j = 0;
		while (mesh[i][j] != NULL)
		{
			if (ft_atoi(mesh[i][j]) < 5)
				mlx_string_put(p[0], p[1], 100 * j, 100 * i, c[col_index(0)], mesh[i][j]);
			else
				mlx_string_put(p[0], p[1], 100 * j, 100 * i, c[col_index(1)], mesh[i][j]);
			j++;
		}
		i++;
	}	
}

static void	change_mesh(int key, void *p[], char ***mesh, int size)
{
	int		i;
	int		j;
	char	*tmp;

	i = 0;
	if (key == KEY_UP)
	{
		while (i < size)
		{
			j = 0;
			while (mesh[i][j] != NULL)
			{
				tmp = mesh[i][j];
				mesh[i][j] = ft_itoa(ft_atoi(tmp) + 1);
				free(tmp);
				j++;
			}
			i++;
		}
	}
	else
	{
		while (i < size)
		{
			j = 0;
			while (mesh[i][j] != NULL)
			{
				tmp = mesh[i][j];
				mesh[i][j] = ft_itoa(ft_atoi(tmp) - 1);
				free(tmp);
				j++;
			}
			i++;
		}
	}
	disp_mesh(p, mesh, size);
}

static int	key_input(int key, void *p[])
{
	key == KEY_ESC ? (exit(0)) : NULL;
	key == KEY_SPACE ? (disp_mesh(p, p[2], *(int *)p[3])) : NULL;
	key == KEY_UP || key == KEY_DOWN ? (change_mesh(key, p, p[2], *(int *)p[3])) : NULL;
	return (0);
}

void		graphic_main(char ***mesh, int size)
{
	void	*p[4];

	p[0] = mlx_init();
	p[1] = mlx_new_window(p[0], 2560, 1400, "fdf");

	p[2] = mesh;
	p[3] = &size;
	disp_mesh(p, mesh, size);
	mlx_key_hook(p[1], &key_input, p);
	mlx_loop(p[0]);
}
