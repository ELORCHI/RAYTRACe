#include "../include/rt.h"
#include "../include/cylinder.h"
#include "../include/world.h"
#include "../include/ray.h"



bool			if_hit(t_cylinder *cylinder, t_ray ray)
{
	float 			a;
	float			b;
	float			c;
	float			ray_dot_normal;
	t_vector		X;
	
	ray_dot_normal = dot_product(ray.dir, cylinder->normal);
	X = point_vector(cylinder->point, ray.orig);
	a = 1 - ray_dot_normal * ray_dot_normal;
	b = 2 * (dot_product(ray.dir, X) - ray_dot_normal * dot_product(X, cylinder->normal));
	c = dot_product(X, X) - dot_product(X, cylinder->normal) * dot_product(X, cylinder->normal) - cylinder->raduis * cylinder->raduis;
	return (solve_quadratic(a, b, c));
}

t_intersection	ray_cylinders_intersection(t_cylinder *cylinder, t_ray ray)
{
    t_intersection 	inter;
	float			finit;

	inter.hit = -1;
	if (if_hit(cylinder, ray))
	{
		finit = dot_product(ray.dir, cylinder->normal) * g_intersection;
	
	}
	return (inter);
}