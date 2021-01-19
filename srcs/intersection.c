/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-orch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 08:56:33 by eel-orch          #+#    #+#             */
/*   Updated: 2021/01/16 14:21:38 by eel-orch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/sphere.h"
#include "../include/ray.h"
#include "../include/light.h"
#include <unistd.h>
#include <stdio.h>

#define wall_z 10
#define wall_size 7.0
#define	canvas_pixels 600
#include <unistd.h>

// check if A B C have the right vectors to be calculated
bool	ft_touch(t_ray *ray, t_sphere *sphere, float *inter)
{
	t_vector	sphere_to_ray;
	float 		a;
	float 		b;
	float 		c;

	sphere_to_ray = point_vector(sphere->orig, ray->orig);
	a = dot_product(ray->dir, ray->dir);
	b = 2 * dot_product(sphere_to_ray, ray->dir);
	c = dot_product(sphere_to_ray, sphere_to_ray) - 1;
	return (solve_quadratic(a, b, c, inter));
}

float 	*ray_sphere_intersection(t_ray *ray, t_sphere *sphere, float *intersections)
{
	t_ray new_ray;

	//print_vector(ray->dir);
	new_ray.orig = mat_vec_multi(sphere->trans, ray->orig);
	new_ray.orig.w = 0;
	new_ray.dir = mat_vec_multi(sphere->trans, ray->dir);
	new_ray.dir.w = 0;
	new_ray.inter = (t_vector){0, 0, 0, 0};
	//print_vector(new_ray.orig);
	//print_vector(new_ray.dir);
	//print_vector(new_ray.inter);
	if (ft_touch(&new_ray, sphere, intersections) == true)
	{
		//printf("%f", *intersections);
		//printf("==%f\n", *(intersections + 1));
		return (intersections);
	}
	else
		return (NULL);
}

float	hit(float *intersections)
{
	if (intersections == NULL)
		return (-1);
	//write(0, "b", 1);
	if (intersections[0] >= 0) // to review this condition;
		return (intersections[0]);
	else
		return (-1);
}

void	ft_init_ray(t_ray *ray)
{
	ray->orig = vec4_creat(0,0,-5,0);
	ray->dir = vec4_creat(0,0,1,1);
	ray->inter = vec4_creat(0,0,0,0);
}

void	ft_init_sphere(t_sphere *sphere)
{
	sphere->orig = (t_vector){0,0,0,0};
	sphere->rad  = 1;
	sphere->trans = identity_mat();
	sphere->color = (t_vector){1, 0, 0 , 0};
	sphere->next = NULL;
}
int check_inter(t_ray *ray, t_sphere *sphere, float *intersections)
{
	//float *intersections;
	float point;

	//intersections = (float *)malloc(sizeof(float));
	intersections = ray_sphere_intersection(ray, sphere, intersections);
	point = hit(intersections);
	//printf("%f", point);
	if (point != -1)
	{
		//free(intersections);
		return (1);
	}
	//free(intersections);
	return (0);
}

void	ft_draw(void *mlx_ptr, void *win_ptr, int x, int y,int color)
{
	if (color != 0)
	{
		//printf("%d\n",color);
		//color = color / 100;
		mlx_pixel_put(mlx_ptr, win_ptr, x, y, color);
	}
	else
		mlx_pixel_put(mlx_ptr, win_ptr, x, y, 255 / 20);
}

int		create_trgb(t_vector color)
{
	int r = floorf(color.x * 255);
	int g = floorf(color.y * 255);
	int b = floorf(color.z * 255);
	//printf("%d %d %d\n", r, g, b);

	return((r << 16) | (g << 8) | b);
}


void	ft_help2(t_ray *ray, t_sphere *sphere, void *mlx_ptr, void *win_ptr)
{
	int 		x;
	int 		y;
	float 		px;
	float 		py;
	float 		half;
	float 		pixel_size;
	t_vector	position;
	float *intersections;

	int i;
	int ccc;
	x = 0;
	y = 0;
	intersections = (float *)malloc(sizeof(float) * 2);
	intersections[0] = 1.1;
	intersections[1] = 1.1;
	half = wall_size / 2;
	pixel_size = wall_size / canvas_pixels;
	while (y < canvas_pixels)
	{
		x = 0;
		py = half - (pixel_size * y);
		//py = -1 * py;
		while (x < canvas_pixels)
		{
			px = (-1 * half) + (pixel_size * x);
			//px = -1 * py;
			position = vec4_creat(px, py, wall_z, 1);
			ray->dir = normaliz(point_vector(ray->orig, position));
			//bool i = check_inter(ray ,sphere);
			i = check_inter(ray, sphere, intersections);
			//printf("%d", i);
			//i = 1;
			//printf("%i",i);
			//if (i == 0)
			//{
				//printf("ok");
				//break;
			//}

			if (i == 1)
			{
				t_vector color = ft_light(ray, sphere, *intersections);
				ccc = create_trgb(color);
				//printf("%d\n", ccc);
				ft_draw(mlx_ptr, win_ptr, x, y, ccc);
			}
			else
				ft_draw(mlx_ptr, win_ptr, x, y, 0);
			x++;
			// x and y values might be switched
		}
		y++;
		//if (i == 0)
			//break;
	}
	mlx_loop(mlx_ptr);
}

void	ft_help(t_ray *ray, t_sphere *sphere)
{
	void 	*mlx_ptr;
	void 	*win_ptr;

	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, canvas_pixels, canvas_pixels, "RT");
	ft_help2(ray, sphere, mlx_ptr, win_ptr);
}

//t_light *light;
//t_embient embient;

int main()
{
	t_ray	*ray;
	t_sphere *sphere;
	//t_light	 *light;
	//t_embient embient;

	ray = (t_ray *)malloc(sizeof(t_ray));
	ray->orig = vec4_creat(0, 0, -5, 0);
	ray->dir = vec4_creat(0, 0, 1, 1);
	ray->inter = vec4_creat(0, 0, 0, 0);

	sphere = (t_sphere *)malloc(sizeof(t_sphere));
	sphere->orig = (t_vector){0,0,0,0};
	sphere->rad  = 1;
	sphere->trans = scaling(1, 1, 1);
	sphere->color = (t_vector){1, 1, 1, 0};
	sphere->next = NULL;

	g_light = (t_light *)malloc(sizeof(t_light));
	g_light->orig = (t_vector){-10, 10, -10, 1};
	g_light->color = (t_vector){0, 1, 1, 0};
	g_light->ratio = 1;

	g_embient.color = (t_vector){1, 1, 1, 0};
	g_embient.ratio = 0.2;
	//ft_init_sphere(sphere);
	//ft_init_ray(ray);
	ft_help(ray, sphere);
	return 0;
}
