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
		last = next_hit;
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

void			norm_shit2(t_world world, t_data *tmp_img)
{
	t_ray			ray;
	t_vector		color;
	t_intersection	intersection;

	ray = ray_for_pixel(g_canvas.x, g_canvas.y);
	intersection = intersect_world(world, ray);
	if (check_intersection(intersection) == true)
	{
		color = light(intersection, ray, world);
		ft_draw(g_canvas, color, 0, &tmp_img);
	}
	else
		ft_draw(g_canvas, color, 1, &tmp_img);
}

void			norm_shit(t_world world, t_data *tmp_img)
{
	t_vector		color;
	t_ray			ray;
	t_intersection	intersection;

	tmp_img->img = mlx_new_image(g_canvas.mlx_ptr,
	g_resolution.hsize, g_resolution.vsize);
	tmp_img->addr = mlx_get_data_addr(tmp_img->img, &(tmp_img->bits_per_pixel),
	&(tmp_img->line_length), &(tmp_img->endian));
	tmp_img->addr = mlx_get_data_addr(tmp_img->img,
	&(tmp_img->bits_per_pixel), &(tmp_img->line_length), &(tmp_img->endian));
	tmp_img->addr = mlx_get_data_addr(tmp_img->img, &(tmp_img->bits_per_pixel),
	&(tmp_img->line_length), &(tmp_img->endian));
	g_canvas.y = 0;
	while (g_canvas.y < g_resolution.vsize)
	{
		g_canvas.x = 0;
		while (g_canvas.x < g_resolution.hsize)
		{
			norm_shit2(world, tmp_img);
			g_canvas.x++;
		}
		g_canvas.y++;
	}
}

void			mlx_hooks_loop(void)
{
	mlx_hook(g_canvas.win_ptr, 2, 0, key_press, &g_canvas.mlx_ptr);
	mlx_hook(g_canvas.win_ptr, 17, 0, ft_quit, &g_canvas.mlx_ptr);
	mlx_loop(g_canvas.mlx_ptr);
}

int				render(t_world **world)
{
	t_camera		*tmp;
	t_data			*tmp_img;

	tmp = g_all_cameras;
	init_image();
	tmp_img = g_img;
	while (tmp != NULL)
	{
		g_nb_cameras++;
		g_camera = tmp;
		set_camera_view(g_camera->orig, g_camera->dir);
		norm_shit(**world, tmp_img);
		if (tmp->next != NULL)
			next_image(&tmp_img);
		tmp = tmp->next;
	}
	g_display_img = g_img;
	if (g_save == 1)
		return (create_bmp_file());
	if (g_all_cameras != NULL)
		mlx_put_image_to_window(g_canvas.mlx_ptr, g_canvas.win_ptr,
		g_display_img->img, 0, 0);
	mlx_hooks_loop();
	return (0);
}
