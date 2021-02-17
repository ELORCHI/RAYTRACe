#include "../include/triangle.h"
#include "../include/ray.h"
#include "../include/plan.h"

void	check(t_vertex vertex, t_intersection *inter, t_ray ray, t_triangle *tr)
{
	static float 	near = FLT_MAX;
	static int		i = 0;

	near = FLT_MAX;
	if (inter->hit > EPSILON && inter->hit < near)
	{
		inter->point = position(ray, inter->hit);
		inter->color = tr->color;
		inter->normal = tr->normal;
		near = inter->hit;
	}
	if (i == 1)
		near = FLT_MAX;
	if (tr->next == NULL)
		i = 1;
}

t_vertex	helper(t_triangle *tr, t_vector *cross, float *dot, t_ray ray)
{
	t_vertex vertex;

	vertex.edge1 = point_vector(tr->p1, tr->p2);
	vertex.edge2 = point_vector(tr->p1, tr->p3);
	*cross = cross_product(vertex.edge2, ray.dir);
	*dot = dot_product(vertex.edge1, *cross);
	return (vertex);
}

int				for_normintte(t_vertex *vertex, t_vector *cross, t_ray ray, float *dot)
{

	vertex->u = (*dot) * dot_product(vertex->ray_to_tr, *cross);
	if (vertex->u < 0.0 || vertex->u > 1.0)
				return 0;
	*cross = cross_product(vertex->edge1, vertex->ray_to_tr);
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
			vertex = helper(tmp_tr, &cross, &dot, ray);
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
	return (inter);
}