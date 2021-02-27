/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   square.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-orch <eel-orch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 14:20:30 by eel-orch          #+#    #+#             */
/*   Updated: 2021/01/28 14:22:27 by eel-orch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/square.h"
#include <stdio.h>

float			dot(t_vector vec1, t_vector vec2)
{
	float dot;

	dot = vec1.x * vec2.x + vec1.y * vec2.y + vec1.z * vec2.z;
	return (dot);
}

bool			inside_square(t_square *square, t_vector intersection)
{
	t_vector	width;
	t_vector	hight;
	t_vector	center_to_inter;
	float		proj_width;
	float		proj_hight;

	hight = normaliz(cross_product((t_vector){0, 1, 0, 0}, square->normal));
	if (hight.x == 0 && hight.y == 0 && hight.z == 0)
		hight = normaliz(cross_product((t_vector){1, 0, 0, 0}, square->normal));
	width = normaliz(cross_product(square->normal, hight));
	center_to_inter = point_vector(square->center, intersection);
	proj_hight = dot(hight, center_to_inter);
	proj_width = dot_product(width, center_to_inter);
	if ((fabs(proj_width) > (square->side / 2)) ||
	(fabs(proj_hight) > (square->side / 2)))
		return (false);
	return (true);
}

t_plan			plan_sqaure(t_square *square)
{
	t_plan plan;

	plan.normal = square->normal;
	plan.point = square->center;
	plan.color = square->color;
	return (plan);
}

t_intersection	ray_sqaures_intersection(t_square *square, t_ray ray)
{
	t_intersection	inter;
	t_intersection	inter_plan;
	t_plan			*plan;
	bool			is_inside;

	plan = (t_plan *)malloc(sizeof(t_plan));
	inter.hit = FLT_MAX;
	while (square != NULL)
	{
		square->normal = normaliz(square->normal);
		*plan = plan_sqaure(square);
		plan->next = NULL;
		inter_plan = ray_plans_intersection(plan, ray);
		if (inter_plan.hit != -1 && inter_plan.hit < inter.hit)
		{
			is_inside = inside_square(square, inter_plan.point);
			if (is_inside == true)
				inter = inter_plan;
		}
		square = square->next;
	}
	if (inter.hit == FLT_MAX)
		inter.hit = -1;
	free(plan);
	return (inter);
}
