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

void	is_shadow(t_world world, t_intersection *intersection)
{
	t_vector		hit_light;
	t_vector		hit_shadow;
	t_intersection	shadow;
	float			distance;
	t_ray			ray;

	hit_light = hit_to_light(intersection->point, g_light->orig);
	distance = magnitude(hit_light);
	ray.dir = normaliz(hit_light);
	ray.orig = intersection->point;
	shadow = intersect_world(world, ray);
	// avoid intersecting the obejct with itself
	if (shadow.hit == -1)
		intersection->is_shadow = false;
	else
	{
		hit_shadow = hit_to_light(intersection->point, shadow.point);
		if (distance > magnitude(hit_shadow))
			intersection->is_shadow = true;
		else
			intersection->is_shadow = false;
	}
}
