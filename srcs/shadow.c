/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shadow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-orch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 08:39:34 by eel-orch          #+#    #+#             */
/*   Updated: 2021/01/18 11:19:40 by eel-orch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/rt.h"
#include "../include/ray.h"
#include "../include/light.h"
#include "../include/world.h"

t_vector	adjust_intersection(t_intersection inter)
{
	t_vector result;

	result = add_vectors(multp_vectors(inter.normal, 0.01), inter.point);
	result.w = 0;
	return (result);
}

void		is_shadow(t_world world, t_intersection *inter, t_light *light)
{
	t_vector		hit_light;
	t_vector		hit_shadow;
	t_intersection	shadow;
	float			distance;
	t_ray			ray;

	inter->point = adjust_intersection(*inter);
	hit_light = point_vector(inter->point, light->orig);
	distance = magnitude(hit_light);
	ray.dir = normaliz(hit_light);
	ray.orig = inter->point;
	shadow = intersect_world(world, ray);
	if (shadow.hit == -1)
		inter->is_shadow = false;
	else
	{
		hit_shadow = point_vector(inter->point, shadow.point);
		if ((distance - (magnitude(hit_shadow))) >= 0)
			inter->is_shadow = true;
		else
			inter->is_shadow = false;
	}
}

int			ft_quit(int keycode)
{
	exit(EXIT_SUCCESS);
	return (0);
}

void		next_image(t_data **tmp_img)
{
	(*tmp_img)->next = (t_data *)malloc(sizeof(t_data));
	*tmp_img = (*tmp_img)->next;
	(*tmp_img)->next = NULL;
	(*tmp_img)->head = g_img;
}
