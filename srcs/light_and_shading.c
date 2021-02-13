/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light_and_shading.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-orch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 08:21:36 by eel-orch          #+#    #+#             */
/*   Updated: 2021/01/25 16:16:49 by eel-orch         ###   ########.fr       */
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

	vect = normaliz(point_vector(hit, light));
	vect.w = 0;
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

//this function will be added as the default light cause its always computed even if its a shadow
//intersextion
// add it when parssing aboject
// multiply the light by the imbient dont add it
/*t_vector	embient(t_vector color)
{
	t_vector result;

	result = color_multp(g_embient.color, color);
	result = multp_vectors(result, g_embient.ratio);
	//print_vector(result);
	return (result);
}*/

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

/*t_vector	defuse(t_intersection intersection)
{
	t_vector	hit_light;
	t_vector	result;
	float		dot;
	float		tmp;

	//print_vector(intersection.color);
	hit_light = normaliz(hit_to_light(intersection.point, g_light->orig));
	dot = fmaxf(dot_product(hit_light, intersection.normal), 0);
	result = color_multp(intersection.color, g_light->color);
	//result = normaliz_color(result);
	tmp = dot * g_light->ratio;
	result = multp_vectors(result, tmp);
	result = normaliz_color(result);
	return (result);
}*/

/*t_vector	defuse(t_intersection intersection)
{
	t_vector	hit_light;
	t_vector	result;
	float		dot;

	result = (t_vector){0, 0, 0, 0};
	hit_light = normaliz(hit_to_light(intersection.point, g_light->orig));
	dot = dot_product(hit_light, intersection.normal);
	//print_vector(intersection.normal);
	if (dot >= 0.000f)
	{
		result = normaliz_color(add_vectors(intersection.color, g_light->color));
		result = multp_vectors(result, dot);
		result = normaliz_color(multp_vectors(result, g_light->ratio));
		return (result);
	}
	return (result);
}*/

/*t_vector	defuse(t_intersection intersection)
{
	t_vector 	hit_light;
	t_vector 	result;
	float		dot;

	hit_light = normaliz(hit_to_light(intersection.point, g_light->orig));
	dot = dot_product(hit_light, intersection.normal);
	//print_vector(intersection.color);
	if (dot >= 0)
	{
		result = color_multp(intersection.color, g_light->color);
		normaliz_color(result);
		result = normaliz_color(multp_vectors(result, dot));
		result = multp_vectors(result, g_light->ratio);
		normaliz_color(result);
		//./print_vector(result);
		return (result);
	}
	return (intersection.color);
}*/

/*t_vector	ft_light(t_ray *ray, t_intersection inter)
{
	t_vector color;

	color = (t_vector){0, 0, 0, 0};
	color = defuse(inter);
	//print_vector(color);
	return (color);
}*/
