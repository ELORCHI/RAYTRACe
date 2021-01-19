/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-orch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 09:47:10 by eel-orch          #+#    #+#             */
/*   Updated: 2021/01/19 12:13:50 by eel-orch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/sphere.h"
#include "../include/rt.h"

/*void		sphere_transform(t_sphere *sphere)
{

}*/

t_vector	normal_at(t_sphere sphere, t_vector world_point)
{
	t_vector object_point;
	t_vector object_normal;
	t_vector world_normal;
	t_mat4x4 inverse;

	inverse = identity_mat();
	//inverse_4x4(&inverse, &(sphere.trans));
	object_point = mat_vec_multi(inverse, world_point);
	object_normal = point_vector(sphere.orig, object_point);
	world_normal = mat_vec_multi(transpose(inverse), object_normal);
	world_normal.w = 0;
	world_normal = normaliz(world_normal);
	return (world_normal);
}

t_sphere	*next_sphere(t_sphere *sphere)
{
	t_sphere *next;
	next = NULL;
	if (sphere->next != NULL)
		next = sphere->next;
	return (next);
}

t_sphere 	*add_sphere(t_sphere *first)
{
	t_sphere *new;

	new = (t_sphere *)malloc(sizeof(t_sphere));
	first->next = new;
	//new->trans = identity_mat();
	return (new);
}

