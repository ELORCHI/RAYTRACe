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

	denom = dot_product(ray.dir, plan->normal);
	if (fabsf(denom) > 0.00001f)
	{
		origin_point = normaliz(point_vector(ray.orig, plan->point));
		nom = dot_product(plan->normal, origin_point) / denom;
		if (nom >= 0.0000f)
		{
			inter.color = plan->color;
			inter.hit =  nom;// what is the hit value to compute the point;
			inter.point  = position(ray,nom);
			inter.normal = plan->normal;
			return (inter);
		}
	}
	inter.hit = -1;
	return (inter);
}
