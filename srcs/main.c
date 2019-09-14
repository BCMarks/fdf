/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmarks <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 15:42:59 by bmarks            #+#    #+#             */
/*   Updated: 2019/09/14 12:11:20 by bmarks           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void	free_mesh(char ***mesh, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (mesh[i][j] != NULL)
		{
			free(mesh[i][j]);
			j++;
		}
		free(mesh[i]);
		i++;
	}
}

static void	val_mesh(char ***mesh, int size)
{
	int		i;
	int		j;
	char	*tmp;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (mesh[i][j] != NULL)
		{
			tmp = ft_itoa(ft_atoi(mesh[i][j]));
			if (!ft_strequ(tmp, mesh[i][j]))
			{
				free(tmp);
				free_mesh(mesh, size);
				ERR_BFILE;
			}
			else
				free(tmp);
			j++;
		}
		i++;
	}
}

static void	fill_data(t_data *data)
{
	int	i;
	int	j;
	int	l;
	int	s;

	i = 0;
	l = ft_atoi(data->mesh[0][0]);
	s = ft_atoi(data->mesh[0][0]);
	while (i < data->m_y)
	{
		j = 0;
		while (data->mesh[i][j] != NULL)
		{
			s = (s > ft_atoi(data->mesh[i][j])) ? ft_atoi(data->mesh[i][j]) : s;
			l = (l < ft_atoi(data->mesh[i][j])) ? ft_atoi(data->mesh[i][j]) : l;
			j++;
		}
		i++;
	}
	data->m_x = j;
	data->m_max_z = l;
	data->m_min_z = s;
	data->w_x = 8 * (data->m_x * cos(M_PI / 6) + data->m_y * cos(M_PI / 6));
	data->w_y = 8 * (l - s + sqrt(pow(j, 2) + pow(data->m_y, 2)) *
			sin(atan(data->m_y / j) + M_PI / 6));
	data->x_offset = (data->w_x - 8 * data->m_x) / 2;
	data->y_offset = (data->w_y - 8 * data->m_y) / 2;
	data->mode = 0;
}

int			main(int argc, char **argv)
{
	int		fd;
	char	*line;
	t_data	data;
	int		i;

	if (argc != 2)
		ERR_USE;
	i = 0;
	if ((fd = open(argv[1], O_DIRECTORY)) != -1)
		ERR_DIR;
	if ((fd = open(argv[1], O_RDONLY)) == -1)
		ERR_FFILE;
	while (get_next_line(fd, &line))
	{
		data.mesh[i] = ft_strsplit(line, ' ');
		free(line);
		i++;
	}
	free(line);
	close(fd);
	val_mesh(data.mesh, i);
	data.file = ft_strdup(argv[1]);
	data.m_y = i;
	fill_data(&data);
	graphic_main(data);	
	free_mesh(data.mesh, i);	
	return (0);
}
