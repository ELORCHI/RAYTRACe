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

void			fill_inter(t_intersection *in, t_plan *pl, t_ray ray, float t)
{
	in->color = pl->color;
	in->point = position(ray, t);
	in->hit = t;
	in->normal = normaliz(pl->normal);
}

t_intersection	ray_plans_intersection(t_plan *plan, t_ray ray)
{
	float			denom;
	float			nom;
	t_vector		origin_point;
	t_intersection	inter;
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
				fill_inter(&inter, tmp_plan, ray, nom);
		}
		tmp_plan = tmp_plan->next;
	}
	if (inter.hit == FLT_MAX)
		inter.hit = -1;
	return (inter);
}
