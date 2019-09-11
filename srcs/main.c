/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmarks <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 15:42:59 by bmarks            #+#    #+#             */
/*   Updated: 2019/09/11 16:11:50 by bmarks           ###   ########.fr       */
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
				ERROR;
			}
			else
				free(tmp);
			j++;
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	int		fd;
	char	*line;
	t_data	data;
	int		i;

	if (argc != 2)
		ERROR;
	i = 0;
	if ((fd = open(argv[1], O_RDONLY)) == -1)
		ERROR;
	while (get_next_line(fd, &line))
	{
		data.info[i] = ft_strsplit(line, ' ');
		free(line);
		i++;
	}
	free(line);
	close(fd);
	val_mesh(data.info, i);
	graphic_main(data.info, i);	
	free_mesh(data.info, i);	
	return (0);
}
