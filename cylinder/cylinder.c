/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-orch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 12:08:53 by eel-orch          #+#    #+#             */
/*   Updated: 2021/02/01 12:09:16 by eel-orch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/rt.h"
#include "../include/cylinder.h"
#include "../include/world.h"
#include "../include/ray.h"


bool			if_hit(t_cylinder *cylinder, t_ray ray)
{
	float 			a;
	float			b;
	float			c;
	float			ray_dot_normal;
	t_vector		X;
	
	ray_dot_normal = dot_product(ray.dir, cylinder->normal);
	X = point_vector(cylinder->point, ray.orig);
	a = 1 - ray_dot_normal * ray_dot_normal;
	b = 2 * (dot_product(ray.dir, X) - ray_dot_normal * dot_product(X, cylinder->normal));
	c = dot_product(X, X) - dot_product(X, cylinder->normal) * dot_product(X, cylinder->normal) - cylinder->raduis * cylinder->raduis;
	return (solve_quadratic(a, b, c));
}

t_vector		normal_at_cylindert(t_cylinder *cylinder, t_vector inter_point)
{
	t_vector 	normal_at_inter;
	t_vector 	vec;
	float		dot;

	vec = point_vector(cylinder->point, inter_point);
	dot = dot_product(cylinder->normal, vec);
	normal_at_inter = subb_vectors(vec, multp_vectors(cylinder->normal, -1 * dot));
	normal_at_inter = normaliz(normal_at_inter);
	return (normal_at_inter);
}

t_intersection	ray_cylinders_intersection(t_cylinder *cylinder, t_ray ray)
{
    t_intersection 	inter;
	float			finit;

	inter.hit = -1;
	if (if_hit(cylinder, ray))
	{
		finit = dot_product(ray.dir, cylinder->normal) * g_intersection;
		if (finit > 0 && ((finit - cylinder->height) <= 0))
		{	
			inter.hit = g_intersection;
			inter.point = position(ray, g_intersection);
			inter.normal = normal_at_cylindert(cylinder, inter.point);
			inter.color = cylinder->color;// make sure all intersection data_structure are filled before you try to read them
		}
	}
	return (inter);
}