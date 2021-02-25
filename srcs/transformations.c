/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transformations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-orch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 17:23:18 by eel-orch          #+#    #+#             */
/*   Updated: 2021/01/19 12:03:42 by eel-orch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/rt.h"
#include "../include/ray.h"
#include "../include/sphere.h"
#include "../include/camera.h"
#include <stdio.h>

t_mat4x4	view_transform(t_vector from, t_vector to, t_vector up)
{
	t_vector forward;
	t_vector left;
	t_vector true_up;
	t_mat4x4 view_matr;

	forward = g_camera->dir;
	left = normaliz(cross_product(forward, normaliz(up)));
	true_up = cross_product(left, forward);
	forward = multp_vectors(forward, -1);
	view_matr = mat_creat(left, true_up, forward, vec4_creat(0, 0, 0, 1));
	view_matr = transpose(view_matr);
	view_matr = mat_multp(view_matr, translation(-from.x, -from.y, -from.z));
	return (view_matr);
}

void		set_camera_view(t_vector vec1, t_vector vec2)
{
	t_vector	forward;
	t_vector	up;
	t_vector	test;

	vec1 = (t_vector){0, 0, 0, 0};
	vec2 = (t_vector){0, 0, 0, 0};
	up = (t_vector){0, 1, 0, 0};
	forward = normaliz(g_camera->dir);
	test = cross_product(normaliz(forward), up);
	if (test.x == 0 && test.y == 0 && test.z == 0)
	{
		up.x = 0;
		up.y = 0;
		up.z = 1;
	}
	camera();
	g_camera->view = view_transform(g_camera->orig, g_camera->dir, up);
}

void		init_image(void)
{
	g_canvas.mlx_ptr = mlx_init();
	g_canvas.win_ptr = mlx_new_window(g_canvas.mlx_ptr, g_resolution.hsize,
	g_resolution.vsize, "MINI_RT");
	g_img = (t_data *)malloc(sizeof(t_data));
	g_img->next = NULL;
	g_nb_cameras = -1;
}
