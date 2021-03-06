/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-orch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 17:35:45 by eel-orch          #+#    #+#             */
/*   Updated: 2021/01/20 16:12:12 by eel-orch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/rt.h"
#include "../include/ray.h"
#include "../include/light.h"
#include "../include/camera.h"
#include "../include/sphere.h"

bool			ft_touch(t_ray ray, t_sphere *sphere)
{
	t_vector	sphere_to_ray;
	float		a;
	float		b;
	float		c;

	sphere_to_ray = point_vector(sphere->orig, ray.orig);
	a = 1;
	b = 2 * dot_product(sphere_to_ray, ray.dir);
	c = dot_product(sphere_to_ray, sphere_to_ray) - (sphere->rad * sphere->rad);
	return (solve_quadratic(a, b, c));
}

bool			check_inter(t_ray ray, t_sphere *sphere)
{
	if (ft_touch(ray, sphere) == true)
	{
		if (g_intersection[0] >= 0)
			return (true);
	}
	return (false);
}

t_intersection	ray_sphere_intersection(t_ray ray, t_sphere *sphere)
{
	float			if_hit;
	t_intersection	inter;
	t_sphere		*tmp_sphere;

	tmp_sphere = sphere;
	inter.hit = FLT_MAX;
	while (tmp_sphere != NULL)
	{
		if_hit = check_inter(ray, tmp_sphere);
		if (if_hit == true && g_intersection[0] < inter.hit)
		{
			inter.hit = g_intersection[0];
			inter.point = position(ray, inter.hit);
			inter.normal = normal_at(*tmp_sphere, inter.point);
			inter.color = tmp_sphere->color;
		}
		tmp_sphere = tmp_sphere->next;
	}
	if (inter.hit == FLT_MAX)
		inter.hit = -1;
	return (inter);
}
