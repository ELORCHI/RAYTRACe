/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-orch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 10:01:32 by eel-orch          #+#    #+#             */
/*   Updated: 2021/01/25 16:44:49 by eel-orch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/rt.h"
#include "../include/ray.h"
#include "../include/sphere.h"
#include "../include/light.h"
#include <stdio.h>

t_vector	embient(t_vector inter_color)
{
	t_vector embient_color;
	t_vector color;

	embient_color = multp_vectors(g_embient.color, g_embient.ratio);
	return (embient_color);
}

float	dot3(t_vector vec1, t_vector vec2)
{
	float dot;

	dot = (vec1.x * vec2.x) + (vec1.y * vec2.y) + (vec1.z * vec2.z);
	return (dot);
}

t_vector	defuse(t_intersection inter, t_ray ray, t_world world)
{
	t_vector 	light_dir;
	t_vector	defuse_;
	t_vector	tmp_shade;
	t_light		*tmp_light;
	float		dot;

	t_intersection test = inter;
	defuse_ = (t_vector){0, 0, 0, 0};
	tmp_light = g_light;
	dot = dot3(inter.normal, ray.dir);
	if (dot >= 0)
		inter.normal =  multp_vectors(inter.normal, -1);
	while (tmp_light != NULL)
	{
		is_shadow(world, &inter, tmp_light);
		if (inter.is_shadow == false)
		{
			light_dir = normaliz(point_vector(inter.point, tmp_light->orig));
			dot = fmaxf(dot3(light_dir, inter.normal), 0);
			tmp_shade = multp_vectors(tmp_light->color, dot * tmp_light->ratio);
			defuse_ = add_colors(defuse_, tmp_shade);
		}
		tmp_light = tmp_light->next;
	}
	return (defuse_);
}

t_vector	light(t_intersection inter, t_ray ray, t_world world)
{
	t_vector defuse_;
	t_vector emb;
	t_vector pixel_color;

	emb = embient(inter.color);
	defuse_ = defuse(inter, ray, world);
	pixel_color = add_colors(defuse_, emb);
	pixel_color = color_multp(inter.color, pixel_color);
	return (pixel_color);
}
