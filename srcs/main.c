/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmarks <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 15:42:59 by bmarks            #+#    #+#             */
/*   Updated: 2019/09/10 16:13:49 by bmarks           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	main(int argc, char **argv)
{
	int		fd;
	char	*line[1000];
	int		**mesh;
	int		i;

	if (argc != 2)
		ERROR;
	i = 0;
	fd = open(argv[1], O_RDONLY);
	while (get_next_line(fd, &line[i]))
		i++;
	close(fd);
	//line array
	//strsplit each line
	//atoi + itoa validation
	//go from there
	while (i > -1)
		free(line[i--]);
	return (0);
}
