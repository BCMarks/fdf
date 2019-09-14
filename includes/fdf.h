/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmarks <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 15:43:16 by bmarks            #+#    #+#             */
/*   Updated: 2019/09/14 13:30:20 by bmarks           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <fcntl.h>
# include <math.h>
# include <mlx.h>
# include "../libft/includes/libft.h"
# include "key_mac.h"
# include "hex_colours.h"

# define ERR_USE {ft_putendl("Usage: ./fdf [filepath]"); exit(-1);}
# define ERR_DIR {ft_putendl("Error: Directory not valid for reading."); exit(-1);}
# define ERR_FFILE {ft_putendl("Error: File doesn't exist."); exit(-1);}
# define ERR_BFILE {ft_putendl("Error: File contains non-integers."); exit(-1);}

typedef struct			s_data
{
	char				*file;
	char				**mesh[1000];
	int					m_x;
	int					m_y;
	int					m_max_z;
	int					m_min_z;
	int					w_x;
	int					w_y;
	int					x_offset;
	int					y_offset;
	int					mode;
}						t_data;

void	graphic_main(t_data);
void	grey_win(void *p[], t_data data);
int		col_pick(t_data data, int i, int j);
void	disp_mesh_2d(void *p[], t_data data);
void	disp_mesh_3d(void *p[], t_data data);

#endif
