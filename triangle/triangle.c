/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   triangle.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-orch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 18:30:33 by eel-orch          #+#    #+#             */
/*   Updated: 2021/01/19 18:44:11 by eel-orch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  "../include/triangle.h"

t_intersection	plan_triangle(t_ray *ray, t_triangle *tr;)
{
    t_intersection  inter;
    t_plan	    plan;

    plan.normal = tr->normal;
    plan.point = tr->p1;
    inter = ray_plans_intersection(&plan);
    return (inter);
}

t_intersection	ray_triangles_intersections(t_ray ray, t_triangle *triangle)
{
    t_vector	    v1;
    t_vector	    v2;
    t_vector	    v3;
    t_intersection  intersection;

    v1 = vector_point(triangle->p2, triangle->p1); 
    v2 = vector_point(triangle->p3, triangle->p1);
    triangle->normal = normaliz(cross_product(v1, v2));
    intersection = plan_triangle(ray, triangle);
    if (intersection.hit != -1)
    {

    }
}
    /// READ THE NOTEED ARTICEL AGAIN TO FINISH THE IMPLEMENTATION
	// calulate two vectors AC AB using  the triangle vertices
	// then caluclate the normal using the cross product if these
	// test of the ray intersect the defined by the calculeted normal
	// if it is then using the the product test  if the point is inside or not 
}
