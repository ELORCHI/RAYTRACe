/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light_and_shading.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-orch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 08:21:36 by eel-orch          #+#    #+#             */
/*   Updated: 2021/01/19 16:34:35 by eel-orch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/rt.h"
#include "../include/ray.h"
#include "../include/sphere.h"
#include "../include/light.h"
#include <stdio.h>

t_vector	hit_to_eye(t_vector dir)
{
	t_vector vect;
	vect = multp_vectors(dir, -1);
	return (vect);
}

t_vector 	hit_to_light(t_vector hit, t_vector light)
{
	t_vector vect;

	vect = point_vector(hit, light);
	return (vect);
}

/*t_vector	normal_at(t_sphere sphere, t_vector world_point)
{
	t_vector object_point;
	t_vector object_normal;
	t_vector world_normal;
	t_mat4x4 inverse;

	inverse = identity_mat();
	inverse_4x4(&inverse, &(sphere.trans));
	object_point = mat_vec_multi(inverse, world_point);
	object_normal = point_vector(sphere.orig, object_point);
	world_normal = mat_vec_multi(transpose(inverse), object_normal);
	world_normal.w = 0;
	world_normal = normaliz(world_normal);
	return (world_normal);
}*/

// the next function iiiis nor working yet
float		reflect(t_vector in, t_vector normal, t_vector dir, t_vector hit)
{
	t_vector 	reflect;
	t_vector 	tmp;
	t_vector 	hit_eye;
	float		dot;
	t_vector	hit_light;

	hit_light = normaliz(hit_to_light(hit, g_light->orig));
	dot = fmaxf(dot_product(hit_light, normal), 0);
	if (dot > 0.0f)
	{
		tmp = multp_vectors(normal, -2 * dot_product(in, normal));
		reflect = point_vector(tmp, in);
		hit_eye = hit_to_eye(dir);
		dot = fmaxf(dot_product(reflect, hit_eye), 0);
		dot = powf(dot, 1.4);
		dot = g_light->ratio * dot;
	}
	else
		return 0;
	return (dot);
}

t_vector	embient(t_vector color)
{
	t_vector result;

	result = normaliz_color(color_multp(g_embient.color, color));
	result = normaliz_color(multp_vectors(result, g_embient.ratio));
	return (result);
}

/*t_vector	defuse(t_vector color, t_vector normal, t_vector hit)
{
	t_vector	hit_light;
	t_vector	result;
	float		dot;
	float		tmp;

	hit_light = normaliz(hit_to_light(hit, g_light->orig));
	dot = fmaxf(dot_product(hit_light, normal), 0);
	result = color_multp(color, g_light->color);
	tmp = dot * g_light->ratio;
	result = multp_vectors(result, tmp);
	result = normaliz_color(result);
	return (result);
}*/

t_vector	defuse(t_intersection intersection)
{
	t_vector	hit_light;
	t_vector	result;
	float		dot;
	float		tmp;

	hit_light = normaliz(hit_to_light(intersection.point, g_light->orig));
	dot = fmaxf(dot_product(hit_light, intersection.normal), 0);
	result = color_multp(intersection.color, g_light->color);
	result = normaliz_color(result);
	tmp = dot * g_light->ratio;
	result = multp_vectors(result, tmp);
	result = normaliz_color(result);
	return (result);
}

t_vector	ft_light(t_ray *ray, t_intersection inter)
{
	t_vector color;
	t_vector normal;
	t_vector hit_point;

	color = (t_vector){0, 0, 0, 0};
	/**
	//hit_point = position(*ray, intersection);
	//normal = normal_at(*sphere, hit_point);
	//color = defuse(sphere->color, normal, hit_point);
	**/
	/**the last three lines will be changed due to the inter structure **/
	//if (inter.is_shadow == false)
		color = defuse(inter);
	//t_vector test = (t_vector){255, 255, 11,0};//embient(sphere->color);
	//color  = add_vectors(color, test);
	color = add_vectors(color, embient(inter.color));
	color = normaliz_color(color);
	//print_vector(color);
	return (color);
}
