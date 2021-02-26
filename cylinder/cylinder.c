/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-orch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 12:08:53 by eel-orch          #+#    #+#             */
/*   Updated: 2021/02/24 09:25:44 by eel-orch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/rt.h"
#include "../include/cylinder.h"
#include "../include/world.h"
#include "../include/ray.h"
#include <stdio.h>

bool			if_hit(t_cylinder *cylinder, t_ray ray)
{
	float			a;
	float			b;
	float			c;
	float			ray_dot_normal;
	t_vector		x;

	ray_dot_normal = dot_product(ray.dir, cylinder->normal);
	x = point_vector(cylinder->point, ray.orig);
	a = 1 - ray_dot_normal * ray_dot_normal;
	b = 2 * (dot_product(ray.dir, x) - ray_dot_normal *
	dot_product(x, cylinder->normal));
	c = dot_product(x, x) - dot_product(x, cylinder->normal) *
	dot_product(x, cylinder->normal) -
	(cylinder->raduis / 2.0) * (cylinder->raduis / 2.0);
	return (solve_quadratic(a, b, c));
}

t_vector		normal_at_cylinder(t_cylinder *cylinder, t_vector inter_point)
{
	t_vector	normal_at_inter;
	t_vector	vec;
	float		dot;

	vec = point_vector(cylinder->point, inter_point);
	dot = dot_product(cylinder->normal, vec);
	normal_at_inter = subb_vectors(inter_point,
	add_vectors(cylinder->point, multp_vectors(cylinder->normal, dot)));
	normal_at_inter = normaliz(normal_at_inter);
	return (normal_at_inter);
}

float			which_finit(t_cylinder *cylinder, t_ray ray)
{
	float finit;
	float tmp;

	finit = -1;
	tmp = dot_product(ray.dir, cylinder->normal) * g_intersection[0] +
	dot_product(point_vector(cylinder->point, ray.orig), cylinder->normal);
	if (tmp >= 0 && tmp <= cylinder->height)
		finit = tmp;
	else
	{
		tmp = dot_product(ray.dir, cylinder->normal) * g_intersection[1] +
		dot_product(point_vector(cylinder->point, ray.orig), cylinder->normal);
		if (tmp >= 0 && tmp <= cylinder->height)
		{
			finit = tmp;
			g_intersection[0] = g_intersection[1];
		}
	}
	return (finit);
}

t_intersection	ray_cylinders_intersection(t_cylinder *cylinder, t_ray ray)
{
	t_intersection	inter;
	t_cylinder		*tmp_cyl;
	float			finit;

	inter.hit = FLT_MAX;
	tmp_cyl = cylinder;
	while (tmp_cyl != NULL)
	{
		tmp_cyl->normal = normaliz(tmp_cyl->normal);
		if (if_hit(tmp_cyl, ray))
		{
			finit = which_finit(tmp_cyl, ray);
			if (finit > 0 && g_intersection[0] < inter.hit)
			{
				inter.hit = g_intersection[0];
				inter.point = position(ray, inter.hit);
				inter.normal = normal_at_cylinder(tmp_cyl, inter.point);
				inter.color = tmp_cyl->color;
			}
		}
		tmp_cyl = tmp_cyl->next;
	}
	if (inter.hit == FLT_MAX)
		inter.hit = -1;
	return (inter);
}
