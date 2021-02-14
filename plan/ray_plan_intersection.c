/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_plan_intersection.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-orch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 08:46:16 by eel-orch          #+#    #+#             */
/*   Updated: 2021/01/19 18:14:58 by eel-orch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ray.h"
#include "../include/plan.h"
#include <stdio.h>
//thiis code is found on stuck_overflow

/*float denom = normal.dot(ray.direction);

if (denom > 0)
{
	float t = -((center - ray.origin).dot(normal)) / denom;

	if (t >= 0)
	{
		rec.tHit = t;
		rec.anyHit = true;
		computeSurfaceHitFields(ray, rec);
		return true;
	}
}

float denom = normal.dot(ray.direction);
if (abs(denom) > 0.0001f) // your favorite epsilon
{
	float t = (center - ray.origin).dot(normal) / denom;
	if (t >= 0) return true; // you might want to allow an epsilon here too
}
return false;*/

t_intersection	ray_plans_intersection(t_plan *plan, t_ray ray)
{
	float 			denom;
	float			nom;
	t_vector		origin_point;
	t_intersection 	inter;
	t_plan			*tmp_plan;
	float			near;// reaplace this one by the inter.hit its the same
	
	tmp_plan = plan;
	inter.hit = -1;
	near = FLT_MAX;
	while (tmp_plan != NULL)
	{
		denom = dot_product(ray.dir, tmp_plan->normal);
		if (fabsf(denom) > EPSILON)// i might need to remove fabsf from here
		{
			origin_point = normaliz(point_vector(ray.orig, tmp_plan->point));
			nom = dot_product(tmp_plan->normal, origin_point) / denom;
			if (nom > EPSILON && nom < near)
			{
				inter.color = tmp_plan->color;
				inter.hit =  nom;
				inter.point  = position(ray,nom);
				inter.normal = tmp_plan->normal;
				near = inter.hit;
			}
		}
		tmp_plan = tmp_plan->next;
	}
	if (near == FLT_MAX)
		inter.hit = -1;
	return (inter);
}
