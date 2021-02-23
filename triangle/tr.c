/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tr.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-orch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 10:01:19 by eel-orch          #+#    #+#             */
/*   Updated: 2021/02/19 10:01:21 by eel-orch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/triangle.h"
#include "../include/ray.h"
#include "../include/plan.h"

t_vector		normal_tr(t_triangle tr)
{
	t_vector vec1;
	t_vector vec2;
	t_vector normal;

	vec1 = point_vector(tr.p2, tr.p1);
	vec2 = point_vector(tr.p2, tr.p3);
	normal = normaliz(cross_product(vec1, vec2));
	return (normal);
}

void			check(t_intersection *inter, t_ray ray, t_triangle *tr)
{
	static float	near = FLT_MAX;
	static int		i = 0;

	if (inter->hit > EPSILON && inter->hit < near)
	{
		inter->point = position(ray, inter->hit);
		inter->color = tr->color;
		inter->normal = normal_tr(*tr);
		near = inter->hit;
	}
	else
		inter->hit = -1;
	if (i == 1)
		near = FLT_MAX;
	if (tr->next == NULL)
		i = 1;
}

t_vertex		help(t_triangle *tr, t_vector *cross, float *dot, t_ray ray)
{
	t_vertex vertex;

	vertex.edge1 = point_vector(tr->p1, tr->p2);
	vertex.edge2 = point_vector(tr->p1, tr->p3);
	*cross = cross_product(vertex.edge2, ray.dir);
	*dot = dot_product(vertex.edge1, *cross);
	if (*dot > -EPSILON && *dot < EPSILON)
		*dot = -1.22;
	else
		*dot = 1.0 / *dot;
	return (vertex);
}

int				for_norm(t_vertex *ver, t_vector *cross, t_ray ray, float *dot)
{
	ver->u = (*dot) * dot_product(ver->ray_to_tr, *cross);
	if (ver->u < 0.0 || ver->u > 1.0)
		return (0);
	*cross = cross_product(ver->edge1, ver->ray_to_tr);
	ver->v = (*dot) * dot_product(ray.dir, *cross);
	if (ver->v < 0.0 || (ver->v + ver->u > 1.0))
		return (0);
	return (1);
}

t_intersection	ray_triangles_intersections(t_ray ray, t_triangle *triangle)
{
	t_vertex		vertex;
	t_vector		cross;
	t_intersection	inter;
	t_triangle		*tmp_tr;
	float			dot;

	tmp_tr = triangle;
	inter.hit = -1;
	while (tmp_tr != NULL)
	{
		while (1)
		{
			vertex = help(tmp_tr, &cross, &dot, ray);
			if (dot == -1.22)
				break ;
			vertex.ray_to_tr = point_vector(tmp_tr->p1, ray.orig);
			if (for_norm(&vertex, &cross, ray, &dot) == 0)
				break ;
			inter.hit = dot * dot_product(cross, vertex.edge2);
			check(&inter, ray, tmp_tr);
			break ;
		}
		tmp_tr = tmp_tr->next;
	}
	return (inter);
}
