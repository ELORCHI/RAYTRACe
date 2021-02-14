/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shadow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-orch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 08:39:34 by eel-orch          #+#    #+#             */
/*   Updated: 2021/01/18 11:19:40 by eel-orch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/rt.h"
#include "../include/ray.h"
#include "../include/light.h"
#include "../include/world.h"

t_vector	adjust_intersection(t_intersection inter)
{
	t_vector result;
	result = add_vectors(multp_vectors(inter.normal, 0.01), inter.point);
	return (result);
	result.w = 0;
}

void	is_shadow(t_world world, t_intersection *intersection, t_light *light)
{
	t_vector		hit_light;
	t_vector		hit_shadow;
	t_intersection	shadow;
	float			distance;
	float			dis_to_shadow;
	t_ray			ray;

	intersection->point = adjust_intersection(*intersection); // thie problem might be here
	hit_light = point_vector(intersection->point, light->orig);
	distance = magnitude(hit_light);
	ray.dir = normaliz(hit_light);
	ray.orig = intersection->point;
	shadow = intersect_world(world, ray);
	if (shadow.hit == -1)
		intersection->is_shadow = false;
	else
	{
		hit_shadow = point_vector(intersection->point, shadow.point);
		dis_to_shadow = magnitude(hit_shadow);
		if ((distance - dis_to_shadow) >= 0)
			intersection->is_shadow = true;
		else
			intersection->is_shadow = false;
	}
}