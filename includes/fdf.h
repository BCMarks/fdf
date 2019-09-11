/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmarks <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 15:43:16 by bmarks            #+#    #+#             */
/*   Updated: 2019/09/11 16:30:29 by bmarks           ###   ########.fr       */
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

# define ERROR {ft_putendl("ERROR"); exit(-1);}

typedef struct			s_data
{
	char				**info[1000];
	int					**mesh[1000];
	int					w_height;
	int					w_width;
}						t_data;

void	graphic_main(char ***mesh, int size);
#endif
