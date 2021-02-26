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
# include "light.h"
# include "../parsing/parsing.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include "unistd.h"


typedef struct	s_mem
{
	void			*mem;
	struct s_mem	*next;
}				t_mem;


typedef	struct	s_world
{
	t_sphere	*sphere;
	t_plan		*plan;
	t_triangle	*triangle;
	t_cylinder	*cylinder;
	t_square	*square;
}				t_world;

typedef	struct	s_light
{
	t_vector		color;
	t_vector		orig;
	float			ratio;
	struct s_light	*next;
}				t_light;

typedef	struct	s_embient
{
	t_vector	color;
	float		ratio;
}				t_embient;

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
t_light			*g_light;
t_embient		g_embient;

t_intersection	intersect_world(t_world world, t_ray ray);
t_intersection	intersect_objects(t_world world, t_ray ray);
void			free_world(t_world *world);
int				create_bmp_file(void);
int				render(t_world **world);
void			check_mandatory(int i);
void			init_world(t_world *world);
void			ft_free(char **to_free);
void			free_world(t_world *world);
void			noghmizete(t_world **world);
void			next_image(t_data **tmp_img);
int				ft_quit(int keycode);
int				key_press(int keycode);
bool			check_intersection(t_intersection intersection);
t_intersection	intersect_world(t_world world, t_ray ray);
void			init_image(void);
void			is_shadow(t_world world,
				t_intersection *intersection, t_light *light);
t_vector		light(t_intersection inter, t_ray ray, t_world world);
t_vector		embient(t_vector inter_color);
t_vector		hit_to_light(t_vector hit, t_vector light);
void			free_images(void);
#endif
