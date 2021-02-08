#include "../include/triangle.h"
#include "../include/ray.h"
#include "../include/plan.h"


t_intersection	check(t_vertex vertex, t_intersection inter, t_ray ray, t_triangle tr)
{
	if (inter.hit > EPSILON)
	{
		inter.point = position(ray, inter.hit);
		inter.color = tr.color;
		inter.normal = cross_product(vertex.edge1, vertex.edge2);
		return(inter);
	}
	inter.hit = -1;
	return (inter);
}

t_intersection	ray_triangles_intersections(t_ray ray, t_triangle *triangle)
{
	t_vertex	 	vertex;
	t_vector	 	cross;
	t_intersection inter;
	float			dot;

	inter.hit = -1;
	vertex.edge1 = point_vector(triangle->p1, triangle->p2);
	vertex.edge2 = point_vector(triangle->p1, triangle->p3);
	cross = cross_product(ray.dir, vertex.edge2);
	dot = dot_product(vertex.edge1, cross);
	if (dot > -EPSILON && dot < EPSILON) 
		return (inter);
	dot = 1.0 / dot;
	vertex.ray_to_tr = point_vector(triangle->p1, ray.orig);
	vertex.u = dot * dot_product(vertex.ray_to_tr, cross);
	if (vertex.u < 0.0 || vertex.u > 1.0)
		return (inter);
	cross = cross_product(vertex.ray_to_tr, vertex.edge1);
	vertex.v = dot * dot_product(ray.dir, cross);
	if (vertex.v < 0.0 || (vertex.v + vertex.u > 1.0))
		return (inter);
	inter.hit = dot * dot_product(cross, vertex.edge2);
	return (check(vertex, inter, ray, *triangle));
}