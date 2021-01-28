/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   square.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-orch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 08:20:26 by eel-orch          #+#    #+#             */
/*   Updated: 2020/12/29 08:20:50 by eel-orch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/square.h"

/*static bool is_in_square(t_square *sq, t_vector3 hitp)
{
    t_vector3   cp;
    double      halfd;
    cp = sub_vec(hitp, sq->center);
    halfd = sq->size / 2;
    return (fabs(cp.x) <= halfd && fabs(cp.y) <= halfd && fabs(cp.z) <= halfd);
}

bool        try_sq(t_ray *ray, t_square *sq, double *t)
{
    t_vector3 hitpoint;
    if (contain_plane(sq->center, sq->orientation, ray, t))
    {
        hitpoint = get_ray_hitp(ray->origin, *t, ray->dir);
        return (is_in_square(sq, hitpoint));
    }
    return (false);
}*/

bool			inside_square(t_square *square, t_vector intersection)
{
	t_vector 	center_to_hit;
	float		max_to_center;

	max_to_center = square->side * sqrt(2) / 2;
	center_to_hit = point_vector(square->center, intersection);
	if (fmaxf(magnitude(center_to_hit) - max_to_center, 0) > 0)
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
    t_intersection 	inter;
	t_plan			plan;
	bool			is_inside;

	plan = plan_sqaure(square);
	inter = ray_plans_intersection(&plan, ray);
	if (inter.hit != -1)
	{
		is_inside = inside_square(square, inter.point);
		if (!is_inside)
			inter.hit = -1;
	}
	return (inter);
}
