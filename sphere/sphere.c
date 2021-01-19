/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-orch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 17:35:45 by eel-orch          #+#    #+#             */
/*   Updated: 2021/01/19 16:18:36 by eel-orch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ray.h"
#include "../include/light.h"
#include "../include/camera.h"
#include "../include/sphere.h"

bool		ft_touch(t_ray *ray, t_sphere *sphere)
{
	t_vector	sphere_to_ray;
	float 		a;
	float 		b;
	float 		c;

	sphere_to_ray = point_vector(sphere->orig, ray->orig);
	a =  1;
	b = 2 * dot_product(sphere_to_ray, ray->dir);
	c = dot_product(sphere_to_ray, sphere_to_ray) - (sphere->rad * sphere->rad);
	return (solve_quadratic(a, b, c));
}

bool		check_inter(t_ray *ray, t_sphere *sphere)
{

	if (ft_touch(ray, sphere) == true)
	{
		if (g_intersection >= 0.f)
			return (true);
	}
	return (false);
}

t_intersection	ray_sphere_intersection(t_ray *ray, t_sphere *sphere)
{
	float			if_hit;
	t_intersection	inter;	

	if_hit = check_inter(ray, sphere);
	if (if_hit == true)
	{
		inter.hit = g_intersection;
		inter.point = position(*ray, if_hit);		
		inter.normal = mat_vec_multi(g_camera.view,normal_at(*sphere, inter.point));
		inter.color = sphere->color;
		return (inter);
	}
	inter.hit = -1;
	return (inter);
}
