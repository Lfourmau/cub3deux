/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfourmau <lfourmau@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 08:21:18 by lfourmau          #+#    #+#             */
/*   Updated: 2021/03/11 13:28:23 by lfourmau         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

#include "libft/libft.h"
#include "mlx/mlx.h"
#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include <fcntl.h>

# define LEFTLOOK 123
# define RIGHTLOOK 124
# define WKEY 13
# define AKEY 0
# define SKEY 1
# define DKEY 2
# define ESC 53


typedef struct	parsing_struct
	{
		int 	horiz_res;
		int 	vertic_res;	
		int		color_f;
		int		color_c;
		char	*NO;
		char	*SO;
		char	*WE;
		char	*EA;
		char	*S;
	}			parse_struct;

typedef struct	map_struct
	{
		char	**map;
		char 	spawn;
		int		nb_spawns;
		int		spawn_x;
		int		spawn_y;
		void	*mlx_ptr;
		void	*win_ptr;
	}			map_struct;

typedef struct  big_struct
{
	parse_struct	*ps;
	map_struct		*ms;
}				big_struct;

int				full_parsing(char *map, big_struct *bs);
int				check_full_numbers(char **splitresult, int i);
void			parsing_struct_init(big_struct *bs);
int				number_of_split(char **splitresult);
int				check_identifiers_textures(char *line);
char			**map_nextline(char **map, char *line, int n);
void			parse_map(char *line, big_struct *bs, int j);
void			free_splits(char **chain, int i);
void			display_spaces(char **map);
int				check_spawn_close(big_struct *bs);
int				limit_colors(char **colors);
int				isspawn(char c);
int				check_around(char c);
int     		check_cub(char *str);
int				check_struct(big_struct *bs);
int				free_struct(big_struct *bs, char *line);

int 			window_prog(big_struct *bs);

#endif
