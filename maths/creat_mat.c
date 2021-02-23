/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creat_mat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-orch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 09:28:55 by eel-orch          #+#    #+#             */
/*   Updated: 2021/02/23 09:29:00 by eel-orch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/rt.h"
#include <stdlib.h>
#include <stdio.h>

t_mat4x4	mat_creat(t_vector v1, t_vector v2, t_vector v3, t_vector v4)
{
	t_mat4x4 new_mat;

	new_mat.c1 = v1;
	new_mat.c2 = v2;
	new_mat.c3 = v3;
	new_mat.c4 = v4;
	return (new_mat);
}

bool		mat_cmp(t_mat4x4 first, t_mat4x4 second)
{
	if (vect_cmp(first.c1, second.c1) && vect_cmp(first.c2, second.c2)
			&& vect_cmp(first.c3, second.c3) && vect_cmp(first.c4, second.c4))
		return (true);
	return (false);
}

t_mat2x2	mat2_creat(t_vec2 v1, t_vec2 v2)
{
	t_mat2x2 mat;

	mat.c1 = v1;
	mat.c2 = v2;
	return (mat);
}

t_mat3x3	mat3_creat(t_vec3 v1, t_vec3 v2, t_vec3 v3)
{
	t_mat3x3 mat;

	mat.c1 = v1;
	mat.c2 = v2;
	mat.c3 = v3;
	return (mat);
}
