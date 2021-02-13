/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-orch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 14:46:11 by eel-orch          #+#    #+#             */
/*   Updated: 2021/02/12 16:12:19 by eel-orch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ray.h"
#include "../include/sphere.h"
#include "../include/light.h"
#include "../include/camera.h"
#include "../include/world.h"
#include "../include/plan.h"
#include "../include/triangle.h"
#include "../include/square.h"
#include <unistd.h>
#include <stdio.h>

void	ft_init(t_sphere **sphere)
{
	//t_ray	*ray;
	//t_sphere *sphere;
	//t_light	 *light;
	//t_embient embient;
	*sphere = (t_sphere *)malloc(sizeof(t_sphere));
	(*sphere)->orig = (t_vector){0, 0, 10,0};
	(*sphere)->rad  = 1;
	(*sphere)->color = (t_vector){0, 1, 0, 0};
	(*sphere)->next = (t_sphere *)malloc(sizeof(t_sphere));
	
	t_sphere *tmp = (*sphere)->next;
	tmp->orig = (t_vector){1, 5, 10, 0};
	tmp->rad = 1;
	tmp->next = NULL;
	tmp->color = (t_vector){1, 1, 0, 0};

	g_light = (t_light *)malloc(sizeof(t_light));
	g_light->orig = (t_vector){0, 50, 10, 1};
	g_light->color = (t_vector){1, 1, 1, 0};
	g_light->ratio = 0.1;
	g_light->next = (t_light *)malloc(sizeof(t_light));

	t_light *tmp_light = g_light->next;
	tmp_light->orig = (t_vector){0, 0, 0, 1};
	tmp_light->color = (t_vector){1, 1, 1, 1};
	tmp_light->ratio = 1;
	tmp_light->next = NULL;
	//-5 0 3
	g_embient.color = (t_vector){0, 1, 1, 0};
	g_embient.ratio = 0.1;

	g_resolution.hsize = 1000;
	g_resolution.vsize = 1000;
	g_resolution.fov = 90;
	// t_vector from = (t_vector){5, 0 , 0, 1};
	g_camera = (t_camera *)malloc(sizeof(t_camera));
	g_camera->orig = (t_vector){0, 0, 0, 1};
	g_camera->dir = (t_vector){0, 0, 3, 1};
	// (0,0 , 10)
	// (0,0,0 10)
	set_camera_view(g_camera->orig, g_camera->dir);
}

t_intersection	intersect_objects(t_world world, t_ray ray)
{
	t_intersection	last;
	t_intersection	next_hit;

	//next_hit = ray_sphere_intersection(&ray, world.sphere);
	//next_hit = ray_sqaures_intersection(world.square, ray);
	//next_hit = ray_cylinders_intersection(world.cylinder, ray);
	
	last.hit = FLT_MAX;
	// next_hit = ray_sqaures_intersection(world.square, ray);
	// if (next_hit.hit != -1 && next_hit.hit < last.hit)
	// 		last = next_hit;
	next_hit = ray_triangles_intersections(ray, world.triangle);
	if (next_hit.hit != -1 && next_hit.hit < last.hit)
		last = next_hit;
	// next_hit = ray_sphere_intersection(ray, world.sphere);
	// if (next_hit.hit != -1 && next_hit.hit < last.hit)
	// 	last = next_hit;
	next_hit = ray_plans_intersection(world.plan, ray);
	if (next_hit.hit != -1 && next_hit.hit < last.hit)
		last = next_hit;
	if (last.hit == FLT_MAX)
		last.hit = -1;
	return (last);
}

t_intersection	intersect_world(t_world world, t_ray ray)
{
	t_intersection  inter;

	inter = intersect_objects(world, ray);
	return (inter);
}

bool			check_intersection(t_intersection intersection)
{
	if (intersection.hit != -1 && intersection.hit > 0)
		return (true);
	return (false);
}

int				key_press(int keycode)
{
	if (keycode == 53)
		exit(0);
	return (0);
}

int				ft_quit(int keycode)
{
		exit(0);
		return (0);
}

void			render(t_world world)
{
	t_mlx	    	canvas;
	t_ray	    	ray;
	t_intersection  intersection;
	t_vector		color = (t_vector){0,0,0,0};
	t_vector		emb;

	canvas.mlx_ptr = mlx_init();
	canvas.win_ptr = mlx_new_window(canvas.mlx_ptr, g_resolution.hsize, g_resolution.vsize, "MINI_RT");
	canvas.y = 0;
	while (canvas.y < g_resolution.vsize)
	{
		canvas.x = 0;
		while (canvas.x < g_resolution.hsize)
		{
			ray = ray_for_pixel(canvas.x, canvas.y);
			intersection = intersect_world(world, ray);
			if (check_intersection(intersection) == true)
			{
				//print_vector(intersection.color);
				//is_shadow(world, &intersection);
				color = light(intersection, ray, world);
				//color = intersection.color;
				//print_vector(color);
				ft_draw(canvas, color, 0);
			}
			else
				ft_draw(canvas, color, 1);
			canvas.x++;
		}
		canvas.y++;
	}
	mlx_hook(canvas.win_ptr, 2, 0, key_press, &canvas.mlx_ptr);
	mlx_hook(canvas.win_ptr, 17, 0, ft_quit, &canvas.mlx_ptr);
	mlx_loop(canvas.mlx_ptr);
}

int 			main()
{
	t_world	world;

	///////sphere///////
	ft_init(&(world.sphere));

	///////plan/////////
	world.plan = (t_plan *)malloc(sizeof(t_plan));
	world.plan->normal = (t_vector){0, 1, 0, 0};
	world.plan->color = (t_vector){1, 0, 0, 0};
	world.plan->point = (t_vector){0, -100, 0, 1};
	// world.plan->next = (t_plan *)malloc(sizeof(t_plan));
	world.plan->next = NULL;
	// t_plan *tmp_plan = world.plan->next;
	// tmp_plan->normal = (t_vector){1, 0, 0, 0};
	// tmp_plan->color = (t_vector){1, 1, 1, 0};
	// tmp_plan->point = (t_vector){-5, 0, 0, 1};
	// world.plan->next->next = NULL;
	//////triangle//////
	world.triangle = (t_triangle *)malloc(sizeof(t_triangle));
	world.triangle->p1 = (t_vector){0, 3, 5, 1};
	world.triangle->p2 = (t_vector){0 , 8, 9, 1};
	world.triangle->p3 = (t_vector){3, 6, 9, 1};
	world.triangle->color = (t_vector){1, 0, 0, 0};
	world.triangle->next = (t_triangle *)malloc(sizeof(t_triangle));

	t_triangle *tmp_tr = world.triangle->next;

	tmp_tr->p1 = (t_vector){5, 2, 5, 1};
	tmp_tr->p2 = (t_vector){5, 5, 9, 1};
	tmp_tr->p3 = (t_vector){5, 4, 9, 1};
	tmp_tr->color = (t_vector){1, 0, 0, 0};
	// tmp_tr->next = NULL;
	world.triangle->next->next = NULL;
	//tmp_tr->next = NULL;
	/////square///////
	world.square = (t_square *)malloc(sizeof(t_square));
	world.square->center = (t_vector){-5, 0, 3, 0};
	world.square->side = 1;
	world.square->color = (t_vector){1, 1, 1, 0};
	world.square->normal = (t_vector){-1, 0, 0, 0};
	world.square->next = (t_square *)malloc(sizeof(t_square));
	
	t_square *tmp_square = world.square->next;
	tmp_square->center = (t_vector){5, 0, 3, 0};
	tmp_square->normal =(t_vector){1, 0, 0, 0};
	tmp_square->color = (t_vector){1, 1 ,1, 0};
	tmp_square->side = 1;
	tmp_square->next = NULL;

	/////cylinder/////
	world.cylinder = (t_cylinder *)malloc(sizeof(t_cylinder));
	world.cylinder->normal = (t_vector){0, 1, 0, 0};
	world.cylinder->height = 4;
	world.cylinder->raduis = 1;
	world.cylinder->point = (t_vector){0, 0, 0, 0};
	world.cylinder->color = (t_vector){1, 0, 0, 0};

	//printf("%f", g_camera.pixel_size);	
	//printf("%f", g_camera.pixel_size);	
	//printf("%f", g_camera.pixel_size);	
	//print_mat4(g_camera.view);
	//t_mat4x4 invers;
	//inverse_4x4(&invers, &(g_camera.view));
	//invers = transpose(invers);
	//world.sphere->orig = mat_vec_multi(invers, world.sphere->orig);
	//print_vector(world.sphere->orig);
	//g_light->orig = mat_vec_multi(invers, g_light->orig);	
	//print_mat4(g_camera.view);
	render(world);
	//print_mat4(g_camera.view);
	//t_ray ray = ray_for_pixel(100, 50);
	//print_vector(ray.dir);
	return (0);
}
