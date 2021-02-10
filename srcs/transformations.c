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

// check this if there is a camera prplm
//check if the mat_vec_multi fucntion return the right vector or point 
// ps : check the vector.w element for each

t_mat4x4	view_transform(t_vector from, t_vector to, t_vector up)
{
	t_vector forward;
	t_vector left;
	t_vector true_up;
	t_mat4x4 view_matrix;

	forward = normaliz(point_vector(from, to));
	left = normaliz(cross_product(forward, normaliz(up)));
	true_up = cross_product(left, forward);
	forward = multp_vectors(forward, -1);
	view_matrix = mat_creat(left, true_up, forward, vec4_creat(0, 0, 0, 1));
	view_matrix = transpose(view_matrix);
	view_matrix = mat_multp(view_matrix, translation(- from.x, - from.y, - from.z)); 
	return (view_matrix);
}

//not tested yet
//to avoid the case of null vectors when creatin camera's vectors
void		set_camera_view()
{
	float		dot;
	t_vector	forward;
	t_vector	up;
	t_vector	test;

	up = (t_vector){0, 1, 0, 0};
	forward = point_vector(g_camera->orig, g_camera->dir);
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

/*int main()
{
	t_vector from = vec4_creat(1, 3, 2, 1);
	t_vector to = vec4_creat(4, -2, 8, 1);
	t_vector up = vec4_creat(1, 1, 0, 0);
	t_mat4x4 view;

	view = view_transform(from, to, up);
	print_mat4(view);
	return (0);
}*/
