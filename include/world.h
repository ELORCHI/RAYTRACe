/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   world.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-orch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 14:48:43 by eel-orch          #+#    #+#             */
/*   Updated: 2021/01/28 14:48:45 by eel-orch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WORLD_H
# define WORLD_H

# include "rt.h"
# include "square.h"
# include "sphere.h"
# include "ray.h"
# include "plan.h" 
# include "camera.h"
# include "triangle.h"
# include "cylinder.h"


typedef struct s_world
{
	t_sphere	*sphere;
	t_plan		*plan;
	t_triangle	*triangle;
	t_cylinder	*cylinder;
	t_square	*square;
}				t_world;

# include "../parsing/parsing.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include "unistd.h"

typedef struct	s_bmp
{
	char		header[54];
	int			filesize;
	int			bfoff_bits;
	int			bisize;
	int			bi_planes;
	int			bitcount;
	int			imagesize;
	int			width_in_bytes;
	int			fd;
	int			pos;
}				t_bmp;

int				g_free;

t_intersection	intersect_world(t_world world, t_ray ray);
t_intersection	intersect_objects(t_world world, t_ray ray);
void			free_world(t_world *world);
int				create_bmp_file(void);
int				render(t_world **world);
void			check_mandatory(void);
void 			init_world(t_world *world);
void			ft_free(char **to_free);
#endif
