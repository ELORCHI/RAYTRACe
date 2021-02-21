/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light_and_shading.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-orch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 08:21:36 by eel-orch          #+#    #+#             */
/*   Updated: 2021/01/25 16:16:49 by eel-orch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/rt.h"
#include "../include/ray.h"
#include "../include/sphere.h"
#include "../include/light.h"

t_vector		hit_to_eye(t_vector dir)
{
	t_vector vect;

	vect = multp_vectors(dir, -1);
	return (vect);
}

t_vector		hit_to_light(t_vector hit, t_vector light)
{
	t_vector vect;

	vect = normaliz(point_vector(hit, light));
	vect.w = 0;
	return (vect);
}

t_intersection	intersect_world(t_world world, t_ray ray)
{
	t_intersection	inter;

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
		if (g_display_img->next == NULL)
			g_display_img = g_img;
		else
			g_display_img = g_display_img->next;
		mlx_put_image_to_window(g_canvas.mlx_ptr, g_canvas.win_ptr,
		g_display_img->img, 0, 0);
	}
	return (0);
}
