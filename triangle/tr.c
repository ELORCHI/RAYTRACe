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

// void			check(t_intersection *inter, t_ray ray, t_triangle *tr)
// {
// 	static float	near = FLT_MAX;
// 	static int		i = 0;

// 	near = FLT_MAX;
// 	if (inter->hit > EPSILON && inter->hit < near)
// 	{
// 		inter->point = position(ray, inter->hit);
// 		inter->color = tr->color;
// 		inter->normal = (t_vector){0, 1, 0, 0};//normal_tr(*tr);
// 		near = inter->hit;
// 	}
// 	if (i == 1)
// 		near = FLT_MAX;
// 	if (tr->next == NULL)
// 		i = 1;
// }

// t_vertex		help(t_triangle *tr, t_vector *cross, float *dot, t_ray ray)
// {
// 	t_vertex vertex;

// 	vertex.edge1 = point_vector(tr->p1, tr->p2);
// 	vertex.edge2 = point_vector(tr->p1, tr->p3);
// 	*cross = cross_product(vertex.edge2, ray.dir);
// 	*dot = dot_product(vertex.edge1, *cross);
// 	return (vertex);
// }

// int				for_norm(t_vertex *ver, t_vector *cross, t_ray ray, float *dot)
// {
// 	ver->u = (*dot) * dot_product(ver->ray_to_tr, *cross);
// 	if (ver->u < 0.0 || ver->u > 1.0)
// 		return (0);
// 	*cross = cross_product(ver->edge1, ver->ray_to_tr);
// 	ver->v = (*dot) * dot_product(ray.dir, *cross);
// 	if (ver->v < 0.0 || (ver->v + ver->u > 1.0))
// 		return (0);
// 	return (1);
// }

// t_intersection	ray_triangles_intersections(t_ray ray, t_triangle *triangle)
// {
// 	t_vertex		vertex;
// 	t_vector		cross;
// 	t_intersection	inter;
// 	t_triangle		*tmp_tr;
// 	float			dot;

// 	tmp_tr = triangle;
// 	inter.hit = -1;
// 	while (tmp_tr != NULL)
// 	{
// 		while (1)
// 		{
// 			vertex = help(tmp_tr, &cross, &dot, ray);
// 			if (dot > -EPSILON && dot < EPSILON)
// 				break ;
// 			dot = 1.0 / dot;
// 			vertex.ray_to_tr = point_vector(tmp_tr->p1, ray.orig);
// 			if (for_norm(&vertex, &cross, ray, &dot) == 0)
// 				break ;
// 			inter.hit = dot * dot_product(cross, vertex.edge2);
// 			check(&inter, ray, tmp_tr);
// 			break ;
// 		}
// 		tmp_tr = tmp_tr->next;
// 	}
// 	return (inter);
// }

t_vector		normal_tr(t_triangle tr)
{
	t_vector vec1;
	t_vector vec2;
	t_vector normal;

	vec1 = point_vector(tr.p2, tr.p1);
	vec2 = point_vector(tr.p1, tr.p3);
	normal = normaliz(cross_product(vec1, vec2));
	return (normal);
}

void	check(t_vertex vertex, t_intersection *inter, t_ray ray, t_triangle *tr)
{
	static float 	near = FLT_MAX;
	static int		i = 0;
	near = FLT_MAX;
	if (inter->hit > EPSILON && inter->hit < near)
	{
		inter->point = position(ray, inter->hit);
		inter->color = tr->color;
		print_vector(tr->color);
		exit(0);
		inter->normal = normal_tr(*tr);//cross_product(vertex.edge1, vertex.edge2);
		near = inter->hit;
	}
	if (i == 1)
		near = FLT_MAX;
	if (tr->next == NULL)
		i = 1;
}

t_vertex	hel(t_triangle *tr, t_vector *cross, float *dot, t_ray ray)
{
	t_vertex vertex;

	vertex.edge1 = point_vector(tr->p1, tr->p2);
	vertex.edge2 = point_vector(tr->p1, tr->p3);//try changing this two
	*cross = cross_product(vertex.edge2, ray.dir);//naybe changing this cross
	*dot = dot_product(vertex.edge1, *cross);
	return (vertex);
}


int				for_normintte(t_vertex *vertex, t_vector *cross, t_ray ray, float *dot)
{
	vertex->u = (*dot) * dot_product(vertex->ray_to_tr, *cross);
	if (vertex->u < 0.0 || vertex->u > 1.0)
		return 0;
	*cross = cross_product(vertex->ray_to_tr, vertex->edge1);//try switching cross sw
	vertex->v = (*dot) * dot_product(ray.dir, *cross);
	if (vertex->v < 0.0 || (vertex->v + vertex->u > 1.0))
		return (0);
	return (1);
}

t_intersection	ray_triangles_intersections(t_ray ray, t_triangle *triangle)
{
	t_vertex	 	vertex;
	t_vector	 	cross;
	t_intersection 	inter;
	t_triangle		*tmp_tr;
	float			dot;
	tmp_tr = triangle;
	inter.hit = -1;
	while (tmp_tr != NULL)
	{
		while (1)
		{
			vertex = hel(tmp_tr, &cross, &dot, ray);
			if (dot > -EPSILON && dot < EPSILON)
				break;
			dot = 1.0 / dot;
			vertex.ray_to_tr = point_vector(tmp_tr->p1, ray.orig);
			if (for_normintte(&vertex, &cross, ray, &dot) == 0)
				break;
			inter.hit = dot * dot_product(cross, vertex.edge2);
			check(vertex, &inter, ray, tmp_tr);
			break;
		}
		tmp_tr = tmp_tr->next;
	}
	inter.color = (t_vector){1, 1, 1, 0};
	return (inter);
}