/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-orch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 17:39:56 by eel-orch          #+#    #+#             */
/*   Updated: 2021/01/21 18:47:08 by eel-orch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ray.h"
#include "../include/sphere.h"
#include "../include/light.h"
#include "../include/camera.h"
#include "../include/world.h"
#include "../include/plan.h"
#include "../include/triangle.h"
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
	(*sphere)->color = (t_vector){0, 1, 1, 0};
	(*sphere)->next = NULL;

	g_light = (t_light *)malloc(sizeof(t_light));
	g_light->orig = (t_vector){0, 0 , -5, 1};
	g_light->color = (t_vector){1, 1, 1, 0};
	g_light->ratio = 0.5;	
	//g_light->color = multp_vectors(g_light->color, g_light->ratio);

	g_embient.color = (t_vector){1, 1, 1, 0};
	g_embient.ratio = 0.2;
		
	(*sphere)->color = embient((*sphere)->color);
	
	g_resolution.hsize = 1000;
	g_resolution.vsize = 1000;
	g_resolution.fov = 90;
	// t_vector from = (t_vector){5, 0 , 0, 1};
	t_vector from = (t_vector){0, 0 , -5, 1};
	t_vector to = (t_vector){0, 0, 1, 1};
	t_vector up = (t_vector){0, 1, 0, 0};
	set_camera_view(from, to, up);
}

//this function needs to be modified
t_intersection	intersect_objects(t_world world, t_ray ray)
{
	t_intersection	hit;
	t_intersection	next_hit;

	//next_hit = ray_plans_intersection(world.plan,  ray);
	//next_hit = ray_triangles_intersections(ray, world.triangle);
	next_hit = ray_sphere_intersection(&ray, world.sphere);
	if (next_hit.hit != -1 && next_hit.hit < FLT_MAX)
		hit = next_hit;
	//printf("%f\n",hit.hit);
	//hit = ray_plans
	return (next_hit);
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
	// print_vector(color);
	while (canvas.y < g_resolution.vsize)
	{
		canvas.x = 0;
		while (canvas.x < g_resolution.hsize)
		{
			ray = ray_for_pixel(canvas.x, canvas.y);
			intersection = intersect_world(world, ray);
			// print_vector(intersection.color);
			if (check_intersection(intersection) == true)
			{
				// print_vector(intersection.color);
				color = add_colors(color, ft_light(&ray, intersection));
				print_vector(color);
				color = normaliz_color(add_vectors(embient(color), color));
				// color = multp_vectors(color, g_embient.ratio);
				//color = normaliz_color(color);
				//t_vector test = ft_light(&ray, intersection);
				//print_vector (test);
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

// you have to transform everthing by the camera transformation
// evrything means objects not rays because they are already generated using that camera

int 			main()
{
	t_world	world;

	ft_init(&(world.sphere));

	///////plan/////////
	world.plan = (t_plan *)malloc(sizeof(t_plan));
	world.plan->normal = (t_vector){1, 1, 0, 0};
	world.plan->color = (t_vector){-10, 0, 0, 0};
	world.plan->point = (t_vector){0, 0, 0, 1};
	//////triangle//////
	
	
	world.triangle = (t_triangle *)malloc(sizeof(t_triangle));
	world.triangle->p1 = (t_vector){0, 0 , 0, 1};
	world.triangle->p2 = (t_vector){0 , 1 , 0, 1};
	world.triangle->p3 = (t_vector){0, 0, 1, 1};
	world.triangle->color = (t_vector){1, 0, 0, 0};
	//printf("%f", g_camera.pixel_size);	
	//printf("%f", g_camera.pixel_size);	
	//printf("%f", g_camera.pixel_size);	
	//print_mat4(g_camera.view);
	//world.sphere->orig = mat_vec_multi(g_camera.view, world.sphere->orig);
	//_light->orig = mat_vec_multi(g_camera.view, g_light->orig);
	render(world);
	//print_mat4(g_camera.view);
	//t_ray ray = ray_for_pixel(100, 50);
	//print_vector(ray.dir);
	return (0);
}
