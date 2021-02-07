/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   triangle.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-orch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 18:30:33 by eel-orch          #+#    #+#             */
/*   Updated: 2021/01/21 18:00:08 by eel-orch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/triangle.h"
#include "../include/ray.h"
#include "../include/plan.h"

/*t_intersection	plan_triangle(t_ray ray, t_triangle *tr)
{
	t_intersection	inter;
	t_plan			plan;

	plan.normal = tr->normal;
	plan.point = tr->p1;
	plan.color = tr->color;
	inter = ray_plans_intersection(&plan , ray);
	return (inter);
}

bool			is_inside(t_triangle *tr, t_intersection intersection)
{
	t_vector 	v1;
	t_vector 	v2;
	t_vector 	v3;
	float		dot;

	v1 = point_vector(tr->p2, tr->p1);
	v2 = point_vector(tr->p3, tr->p2);
	v3 = point_vector(tr->p1, tr->p3);
	dot = dot_product(cross_product(v1, point_vector(intersection.point, tr->p1)), tr->normal);
	if (dot < 0.0000f)
		return (false);
	dot = dot_product(cross_product(v2, point_vector(intersection.point, tr->p2)), tr->normal);
	if (dot < 0.0000f)
		return (false);
	dot = dot_product(cross_product(v3, point_vector(intersection.point, tr->p3)), tr->normal);
	if (dot < 0.0000f)
		return (false);
	return (true);
}

t_intersection	ray_triangles_intersections(t_ray ray, t_triangle *triangle)
{
	t_vector	    v1;
	t_vector	    v2;
	t_vector	    v3;
	t_intersection  intersection;
	float			dot;

	v1 = point_vector(triangle->p2, triangle->p1); 
	v2 = point_vector(triangle->p3, triangle->p1);
	triangle->normal = normaliz(cross_product(v1, v2));
	intersection = plan_triangle(ray, triangle);
	if (intersection.hit != -1)
	{
		if (is_inside(triangle, intersection) == true)
			return (intersection);
		intersection.hit = -1;
		//intersection.normal = triangle->normal;
		return (intersection);
	}
	return (intersection);
}*/

t_intersection	ray_triangles_intersections(t_ray ray, t_triangle *triangle)
{
	t_vector 		edge1;
	t_vector 		edge2;
	t_vector		cross;
	t_intersection	inter;
	float			dot;
	t_vector		ray_to_tr;
	float			u;

	edge1 = point_vector(triangle->p1, triangle->p2);
	edge2 = point_vector(triangle->p1, triangle->p3);
	cross = cross_product(ray.dir, edge2);
	dot = dot_product(edge1, cross);
	if (dot > -EPSILON && dot < EPSILON) // ray parallel to the triangle
	{
		inter.hit = -1;
		return (inter);
	}
	dot = 1.0/ dot;
	ray_to_tr = point_vector(triangle->p1, ray.orig);
	u = dot * dot_product(ray_to_tr, cross);
	if (u < 0.0 || u > 1.0)
	{
		inter.hit = -1;
		return (inter);
	}
	t_vector q;
	q = cross_product(ray_to_tr, edge1);
	float v;
	v = dot * dot_product(ray.dir, q);
	if (v < 0.0 || (v + u > 1.0))
	{
		inter.hit = -1;
		return(inter);
	}
	inter.hit = dot * dot_product(q, edge2);
	if (inter.hit > EPSILON)
	{
		inter.point = position(ray, inter.hit);
		return(inter);
	}
	inter.hit = -1;
	return (inter);
}
