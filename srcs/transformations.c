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
//check if the mat_vec_multi fucntion return the right vector or point 
// ps : check the vector.w element for each

/*void	translat(t_sphere *sphere, float x, float y, float z)
{
	t_mat4x4	tmp;

	tmp = translation(x, y, z);
	inverse_4x4(&(sphere->trans), &tmp);
}

void	scale(t_sphere *sphere, float x, float y, float z)
{
	t_mat4x4 tmp;

	tmp = scaling(x, y, y);
	inverse_4x4(&(sphere->trans), &tmp);
}*/

// need to test this and compare it with the given up given in sceen.rt
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

void		set_camera_view(t_vector from, t_vector to, t_vector up)
{
	float		dot;
	t_vector	forward;

	forward = point_vector(from, to);
	dot = dot_product(forward, up);
	/*if (dot == .0f)
	{
		up.x = 1;
		up.y = 1;
	}*/
	camera();
	g_camera.view = view_transform(from, to, up);
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
