/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-orch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 11:42:45 by eel-orch          #+#    #+#             */
/*   Updated: 2021/01/25 15:05:41 by eel-orch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ray.h"
#include "../include/camera.h"

t_vector	position(t_ray ray, float speed)
{
	t_vector position;

	position = add_vectors(ray.orig, multp_vectors(ray.dir, speed));
	return (position);
}

bool		ray_dot_normal(t_vector ray_dir, t_vector *normal)
{
	float dot;

	dot = dot_product(ray_dir, *normal);
	if (dot > 0.0f)
		return (true);
	*normal = multp_vectors(*normal, -1);
	return (false);
}

t_vector	ft_pixel(t_vector pixel)
{
	static t_mat4x4	inverse;
	static int		i = 0;
	t_vector		result;

	if (i == g_nb_cameras)
	{
		inverse_4x4(&inverse, &(g_camera->view));
		i++;
	}
	result = mat_vec_multi(transpose(inverse), pixel);
	return (result);
}

t_ray		ray_for_pixel(int x, int y)
{
	float		py;
	float		px;
	t_vector	pixel;
	t_ray		ray;

	px = (x + 0.5) * g_camera->pixel_size;
	py = (y + 0.5) * g_camera->pixel_size;
	px = g_camera->half_width - px;
	py = g_camera->half_height - py;
	pixel = vec4_creat(px, py, -1, 1);
	pixel = ft_pixel(pixel);
	ray.orig = ft_pixel(vec4_creat(0, 0, 0, 1));
	ray.dir = normaliz(point_vector(ray.orig, pixel));
	return (ray);
}
