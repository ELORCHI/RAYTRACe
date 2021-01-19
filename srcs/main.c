/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-orch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 17:39:56 by eel-orch          #+#    #+#             */
/*   Updated: 2021/01/19 12:57:35 by eel-orch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ray.h"
#include "../include/sphere.h"
#include "../include/light.h"
#include "../include/camera.h"
#include "../include/world.h"
#include <unistd.h>
#include <stdio.h>

void	ft_init(t_sphere **sphere)
{
	//t_ray	*ray;
	//t_sphere *sphere;
	//t_light	 *light;
	//t_embient embient;
	*sphere = (t_sphere *)malloc(sizeof(t_sphere));
	(*sphere)->orig = (t_vector){0, 0, 0,0};
	(*sphere)->rad  = 1;
	//translat(*sphere, 0, 0, 0);
	//print_mat4((*sphere)->trans);
	(*sphere)->color = (t_vector){0, 1, 1, 0};
	(*sphere)->next = NULL;

	g_light = (t_light *)malloc(sizeof(t_light));
	g_light->orig = (t_vector){-10, 10, -10, 1};
	g_light->color = (t_vector){1, 1, 1, 0};
	g_light->ratio = 1;

	g_embient.color = (t_vector){1, 1, 1, 0};
	g_embient.ratio = 0.2;

	g_resolution.hsize = 1000;
	g_resolution.vsize = 1000;
	g_resolution.fov = 90;
	t_vector from = (t_vector){0, 0 , -5, 1};
	t_vector to = (t_vector){0, 0, 1, 1};
	t_vector up = (t_vector){0, 1, 0, 0};
	set_camera_view(from, to, up);
	//print_mat4(g_camera.view);
	//camera();
	//g_camera.view = identity_mat();
}

t_intersection	intersect_objects(t_world world, t_ray ray)
{
	t_intersection	hit;
	t_intersection	next_hit;

	hit = ray_sphere_intersection(&ray, world.sphere);
	if (hit.hit != -1 && hit.hit < FLT_MAX)
		hit = next_hit;
	//printf("%f\n",hit.hit);
	//hit = ray_plans
	return (hit);
}

t_intersection	intersect_world(t_world world, t_ray ray)
{
	t_intersection  inter;

	inter = intersect_objects(world, ray);
	return (inter);
}

bool			check_intersection(t_intersection intersection)
{
	if (intersection.hit != -1)
		return (true);
	return (false);
}

void			render(t_world world)
{
	t_mlx	    	canvas;
	t_ray	    	ray;
	t_intersection  intersection;
	t_vector		color;

	canvas.mlx_ptr = mlx_init();
	canvas.win_ptr = mlx_new_window(canvas.mlx_ptr, g_resolution.hsize, g_resolution.vsize, "MINI_RT");
	canvas.y = 0;
	color = world.sphere->color;
	while (canvas.y < g_resolution.vsize)
	{
		canvas.x = 0;
		while (canvas.x < g_resolution.hsize)
		{
			ray = ray_for_pixel(canvas.x, canvas.y);
			intersection = intersect_world(world, ray);
			//if intersection exist
			if (check_intersection(intersection) == true)
			{
				//is_shadow(world, &intersection);
				//color = ft_light(&ray, intersection);
				ft_draw(canvas, color, 0);
			}
			else
				ft_draw(canvas, color, 1);
			canvas.x++;
		}
		canvas.y++;
	}
	mlx_loop(canvas.mlx_ptr);
}

int 			main()
{
	t_world	world;

	// camera//
	ft_init(&(world.sphere));
	//printf("%f", g_camera.pixel_size);	
	print_mat4(g_camera.view);
	render(world);
	//print_mat4(g_camera.view);
	//t_ray ray = ray_for_pixel(100, 50);
	//print_vector(ray.dir);
	return (0);
}
