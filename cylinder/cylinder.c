#include "../include/rt.h"
#include "../include/cylinder.h"
#include "../include/world.h"
#include "../include/ray.h"

float			ft_help(float a, float b, float c)
{

	if (solve_quadratic(a, b, c))
	{
		
		return (g_intersection);
	}
	else
		return (-1);
}

float			if_hit(t_cylinder *cylinder, t_ray ray)
{
	float 			a;
	float			b;
	float			c;
	float			ray_dot_normal;
	t_vector		X;
	
	ray_dot_normal = dot_product(ray.dir, cylinder->normal);
	X = point_vector(cylinder->point, ray.orig);
	a = 1 - ray_dot_normal * ray_dot_normal;
	b = 2 * (dot_product(ray.dir, X) - (dot_product(ray.dir, cylinder.normal) * dot_product(X, cylinder->normal)));
	c = dot_product(X, X) - dot_product(X, cylinder.normal) * dot_product(X, cylinder) - cylinder->raduis * cylinder->cylinder;
}

t_intersection	ray_cylinders_intersection(t_cylinder *cylinder, t_ray ray)
{
    t_intersection inter;
	float 			a;
	float			b;
	float			c;
	float			ray_dot_normal;
	t_vector		X;
	
	ray_dot_normal = dot_product(ray.dir, cylinder->normal);
	X = point_vector(cylinder->point, ray.orig);
	a = 1 - ray_dot_normal * ray_dot_normal;
	b = 2 * (dot_product(ray.dir, X) - (dot_product(ray.dir, cylinder.normal) * dot_product(X, cylinder->normal)));
	c = dot_product(X, X) - dot_product(X, cylinder.normal) * dot_product(X, cylinder) - cylinder->raduis * cylinder->cylinder;
	solve_quadratic();
	return (inter);
}