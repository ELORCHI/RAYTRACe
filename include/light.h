/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-orch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 10:03:54 by eel-orch          #+#    #+#             */
/*   Updated: 2021/01/25 16:23:50 by eel-orch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIGHT_H
# define LIGHT_H

# include "rt.h"
# include "sphere.h"
# include "ray.h"
# include "world.h"

typedef struct 	s_light
{
	t_vector 		color;
	t_vector		orig;
	float			ratio;
	struct s_light 	*next;
}				t_light;

typedef struct 	s_embient
{
	t_vector 	color;
	float		ratio;
}				t_embient;

t_light			*g_light;
t_embient		g_embient;


t_vector 		embient(t_vector inter_color);
//t_vector		ft_light(t_ray *ray, t_intersection intersection);
t_vector 		hit_to_light(t_vector hit, t_vector light);
t_vector		light(t_intersection inter);
void			is_shadow(t_world world, t_intersection *intersection);

#endif
