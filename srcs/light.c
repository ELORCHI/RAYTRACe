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
	//color = color_multp(inter_color, embient_color);
	return (embient_color);
}

t_vector	defuse(t_intersection inter)
{
	t_vector 	light_dir;
	t_vector	defuse_;
	float		diff;

	defuse_ = (t_vector){0, 0, 0, 0};
	if (inter.is_shadow == false)
	{
		light_dir = normaliz(point_vector(inter.point, g_light->orig));
		//print_vector(light_dir);
		diff = fmaxf(dot_product(light_dir, inter.normal), 0.0f);
		defuse_ = multp_vectors(g_light->color, diff);
		//print_vector(inter.normal);
		//printf("%f\n", diff);
	}
	return (defuse_);
}

t_vector	light(t_intersection inter)
{
	t_vector defuse_;
	t_vector emb;
	t_vector pixel_color;

	emb = embient(inter.color);
	defuse_ = defuse(inter);
	//print_vector(defuse_);
	pixel_color = add_colors(defuse_, emb);
	pixel_color = color_multp(inter.color, pixel_color);
	return (pixel_color);
}
