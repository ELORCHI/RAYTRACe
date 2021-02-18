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
	*sphere = (t_sphere *)malloc(sizeof(t_sphere));
	(*sphere)->orig = (t_vector){-2, 2, 0,0};
	(*sphere)->rad  = 0.5;
	(*sphere)->color = (t_vector){1, 0, 0, 0};
	(*sphere)->next = (t_sphere *)malloc(sizeof(t_sphere));
	
	t_sphere *tmp = (*sphere)->next;
	tmp->orig = (t_vector){-4, 0, 0, 0};
	tmp->rad = 1;
	tmp->color = (t_vector){1, 1, 1, 0};
	tmp->next = NULL;

	g_light = (t_light *)malloc(sizeof(t_light));
	g_light->orig = (t_vector){0, 20, 0, 1};
	g_light->color = (t_vector){1, 1, 1, 0};
	g_light->ratio = 1;
	g_light->next = (t_light *)malloc(sizeof(t_light));

	t_light *tmp_light = g_light->next;
	tmp_light->orig = (t_vector){0, 2, 0, 1};
	tmp_light->color = (t_vector){0, 0, 0, 1};
	tmp_light->ratio = 0.5;
	tmp_light->next = NULL;

	g_embient.color = (t_vector){1, 1, 1, 0};
	g_embient.ratio = 0.1;

	g_resolution.hsize = 200;
	g_resolution.vsize = 200;

	g_all_cameras = (t_camera *)malloc(sizeof(t_camera));
	g_all_cameras->orig = (t_vector){0, 15, 0, 1};
	g_all_cameras->dir = (t_vector){-2, 2, 0, 1};
	g_all_cameras->fov = 60;
	g_all_cameras->next = NULL;//(t_camera *)malloc(sizeof(t_camera));

	// t_camera *test = g_all_cameras->next;
	// test->orig =  (t_vector){0, , 0, 1};
	// test->dir =  (t_vector){0, 0, 0, 1};
	// test->fov = 90;
	// test->next = NULL;
}

t_intersection	intersect_objects(t_world world, t_ray ray)
{
	t_intersection	last;
	t_intersection	next_hit;

	last.hit = FLT_MAX;
	next_hit = ray_sqaures_intersection(world.square, ray);
	if (next_hit.hit != -1 && next_hit.hit < last.hit)
			last = next_hit;
	next_hit = ray_triangles_intersections(ray, world.triangle);
	if (next_hit.hit != -1 && next_hit.hit < last.hit)
		last = next_hit;
	next_hit = ray_sphere_intersection(ray, world.sphere);
	if (next_hit.hit != -1 && next_hit.hit < last.hit)
	{
		last = next_hit;
	}
	next_hit = ray_plans_intersection(world.plan, ray);
	if (next_hit.hit != -1 && next_hit.hit < last.hit)
	 	last = next_hit;
	next_hit = ray_cylinders_intersection(world.cylinder, ray);
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
	if (keycode == 123)
	{
		if (display_img->next == NULL)
			display_img = g_img;
		else
			display_img = display_img->next;
		mlx_put_image_to_window(g_canvas.mlx_ptr, g_canvas.win_ptr, display_img->img, 0, 0);
	}
	return (0);
}

int				ft_quit(int keycode)
{
	exit(EXIT_SUCCESS);
	return (0);
}

void			next_image(t_data **tmp_img)
{
		(*tmp_img)->next = (t_data *)malloc(sizeof(t_data));
		*tmp_img = (*tmp_img)->next;
		(*tmp_img)->next = NULL;
		(*tmp_img)->head = g_img;
}

void			init_image()
{
	g_canvas.mlx_ptr = mlx_init();
	g_canvas.win_ptr = mlx_new_window(g_canvas.mlx_ptr, g_resolution.hsize, g_resolution.vsize, "MINI_RT");
	g_img = (t_data *)malloc(sizeof(t_data));
	g_img->next = NULL;
	nb_cameras = -1;
	g_save = 0;
}

void		norm_shit(t_world world, t_data *tmp_img)
{
	t_vector		color;
	t_ray			ray;
	t_intersection	intersection;

	tmp_img->img = mlx_new_image(g_canvas.mlx_ptr, g_resolution.hsize, g_resolution.vsize);
	tmp_img->addr =  mlx_get_data_addr(tmp_img->img, &(tmp_img->bits_per_pixel), &(tmp_img->line_length), &(tmp_img->endian));	
		tmp_img->addr =  mlx_get_data_addr(tmp_img->img, &(tmp_img->bits_per_pixel), &(tmp_img->line_length), &(tmp_img->endian));
	tmp_img->addr =  mlx_get_data_addr(tmp_img->img, &(tmp_img->bits_per_pixel), &(tmp_img->line_length), &(tmp_img->endian));	
	g_canvas.y = 0;
	while (g_canvas.y < g_resolution.vsize)
	{
		g_canvas.x = 0;
		while (g_canvas.x < g_resolution.hsize)
		{
			ray = ray_for_pixel(g_canvas.x, g_canvas.y);
			intersection = intersect_world(world, ray);
			if (check_intersection(intersection) == true)
			{
				color = light(intersection, ray, world);
				ft_draw(g_canvas, color, 0, &tmp_img);
			}
			else
				ft_draw(g_canvas, color, 1, &tmp_img);
			g_canvas.x++;
		}
		g_canvas.y++;
	}
}

int			render(t_world **world)
{
	t_camera		*tmp;
	t_data			*tmp_img;
	int				quit;

	tmp = g_all_cameras;
	init_image();
	tmp_img = g_img;
	while (tmp != NULL)
	{
		nb_cameras++;
		g_camera = tmp;
		set_camera_view(g_camera->orig, g_camera->dir);
		norm_shit(**world, tmp_img);
		if (tmp->next != NULL)
			next_image(&tmp_img);
		tmp = tmp->next;
	}
	display_img = g_img;
	if (g_save == 1)
		return (create_bmp_file());
	mlx_put_image_to_window(g_canvas.mlx_ptr, g_canvas.win_ptr, display_img->img, 0, 0);
	mlx_hook(g_canvas.win_ptr, 2, 0, key_press, &g_canvas.mlx_ptr);
	mlx_hook(g_canvas.win_ptr, 17, 0, ft_quit, &g_canvas.mlx_ptr);
	mlx_loop(g_canvas.mlx_ptr);
	return (0);
}

// int 			main()
// {
// 	t_world	world;

// 	///////sphere///////
// 	ft_init(&(world.sphere));

// 	///////plan/////////
// 	world.plan = (t_plan *)malloc(sizeof(t_plan));
// 	world.plan->normal = (t_vector){0, 1, 0, 0};
// 	world.plan->color = (t_vector){0, 0.5, 1, 0};
// 	world.plan->point = (t_vector){0, -50, 0, 1};
// 	// world.plan->next = (t_plan *)malloc(sizeof(t_plan));
// 	world.plan->next = NULL;
// 	// t_plan *tmp_plan = world.plan->next;
// 	// tmp_plan->normal = (t_vector){1, 0, 0, 0};
// 	// tmp_plan->color = (t_vector){1, 1, 1, 0};
// 	// tmp_plan->point = (t_vector){-5, 0, 0, 1};
// 	// world.plan->next->next = NULL;
// 	//////triangle//////
// 	world.triangle = (t_triangle *)malloc(sizeof(t_triangle));
// 	world.triangle->p1 = (t_vector){2, 10, 0, 1};
// 	world.triangle->p2 = (t_vector){2 , 10, 0, 1};
// 	world.triangle->p3 = (t_vector){3, 10, 0, 1};
// 	world.triangle->color = (t_vector){0, 1, 1, 0};
// 	world.triangle->normal = (t_vector){0, 1, 0, 0};
// 	world.triangle->next = NULL;
// 	//2,287373739739735435643643673736743647367397373739738973973773
// 	//tmp_tr->next = NULL;
// 	/////square///////
// 	world.square = (t_square *)malloc(sizeof(t_square));
// 	world.square->center = (t_vector){-5, 0, 3, 0};
// 	world.square->side = 1;
// 	world.square->color = (t_vector){1, 1, 1, 0};
// 	world.square->normal = (t_vector){-1, 0, 0, 0};
// 	world.square->next = (t_square *)malloc(sizeof(t_square));
	
// 	t_square *tmp_square = world.square->next;
// 	tmp_square->center = (t_vector){0, 2, 10, 0};
// 	tmp_square->normal =(t_vector){0, 1, 0, 0};
// 	tmp_square->color = (t_vector){1, 0, 1, 0};
// 	tmp_square->side = 1;
// 	tmp_square->next = NULL;

// 	/////cylinder/////
// 	world.cylinder = (t_cylinder *)malloc(sizeof(t_cylinder));
// 	world.cylinder->normal = (t_vector){0.5, 0.5, 0, 0};
// 	world.cylinder->normal = normaliz(world.cylinder->normal);
// 	world.cylinder->height = 2;
// 	world.cylinder->raduis = 1;
// 	world.cylinder->point = (t_vector){0, 2, 0, 0};
// 	world.cylinder->color = (t_vector){0.5, 0.5, 0, 0};
// 	world.cylinder->next = (t_cylinder *)malloc(sizeof(t_cylinder));

// 	t_cylinder *tmp_cyl = world.cylinder->next;
// 	tmp_cyl->normal = (t_vector){0, 1, 0, 0};
// 	tmp_cyl->height = 4;
// 	tmp_cyl->raduis = 1;
// 	tmp_cyl->point = (t_vector){3, 3, 3, 0};
// 	tmp_cyl->color = (t_vector){1, 0, 0, 0};
// 	tmp_cyl->next = NULL;
	
// 	render(&world);
// 	return (0);
//}
