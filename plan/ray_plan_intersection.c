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

	tmp_plan = plan;
	inter.hit = FLT_MAX;

	while (tmp_plan != NULL)
	{
		tmp_plan->normal = normaliz(tmp_plan->normal);
		denom = dot_product(ray.dir, tmp_plan->normal);
		if (fabsf(denom) > EPSILON)
		{
			origin_point = point_vector(tmp_plan->point, ray.orig);
			nom = dot_product(normaliz(tmp_plan->normal), origin_point) / denom;
			nom *= -1;
			if (nom > EPSILON && nom < inter.hit)
			{
				inter.color = tmp_plan->color;
				inter.hit =  nom;
				inter.point  = position(ray, nom);
				inter.normal = normaliz(tmp_plan->normal);
			}
		}
		tmp_plan = tmp_plan->next;
	}
	if (inter.hit == FLT_MAX)
		inter.hit = -1;
	return (inter);
}
