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
#include <stdio.h>

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

t_vector		normal_at_cylinder(t_cylinder *cylinder, t_vector inter_point)
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

float			which_finit(t_cylinder *cylinder, t_ray ray)
{
	float finit;
	float tmp;

	finit = -1;
	tmp = dot_product(ray.dir, cylinder->normal) * g_intersection[0] + dot_product(point_vector(cylinder->point, ray.orig), cylinder->normal);
	if (tmp >= 0 && tmp <= cylinder->height)
		finit = tmp;
	else
	{
		tmp = dot_product(ray.dir, cylinder->normal) * g_intersection[1] + dot_product(point_vector(cylinder->point, ray.orig), cylinder->normal);
		if (tmp >= 0 && tmp <= cylinder->height)
		{	
			finit = tmp;
			g_intersection[0] = g_intersection[1];
		}
	}
	return (finit);
}

// it might be a problem in the cylinder because it did not show well at the bottom
// check the normal and all
// line 83 i also removed the coparison to checkk if the intersection is near than the prevoious one 
	// after shosing the right finit

t_intersection	ray_cylinders_intersection(t_cylinder *cylinder, t_ray ray)
{
    t_intersection 	inter;
	t_cylinder		*tmp_cyl;
	float			finit;

	inter.hit = FLT_MAX;
	tmp_cyl = cylinder;
	while (tmp_cyl != NULL)
	{
		if (if_hit(tmp_cyl, ray))// an error were here i was checking always the first cylinder
		{
			finit = which_finit(tmp_cyl, ray);//also here
			if (finit > 0 && g_intersection[0] < inter.hit)
			{
				inter.hit = g_intersection[0];
				inter.point = position(ray, inter.hit);
				inter.normal = normal_at_cylinder(tmp_cyl, inter.point);// aand here
				inter.color = tmp_cyl->color;
			}
		}
		tmp_cyl = tmp_cyl->next;
	}
	if (inter.hit == FLT_MAX)
		inter.hit = -1;
	return (inter);
}