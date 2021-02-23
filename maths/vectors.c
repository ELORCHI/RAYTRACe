/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectors.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-orch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 09:21:35 by eel-orch          #+#    #+#             */
/*   Updated: 2021/02/23 09:21:37 by eel-orch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/rt.h"
#include <stdlib.h>
#include <stdio.h>

t_vector	point_vector(t_vector from, t_vector to)
{
	t_vector vec;

	vec.x = to.x - from.x;
	vec.y = to.y - from.y;
	vec.z = to.z - from.z;
	vec.w = 0;
	return (vec);
}

t_vector	multp_vectors(t_vector vec, float scalar)
{
	vec.x = vec.x * scalar;
	vec.y = vec.y * scalar;
	vec.z = vec.z * scalar;
	vec.w = 0;
	return (vec);
}

t_vector	add_vectors(t_vector vec1, t_vector vec2)
{
	t_vector summ_vec;

	summ_vec.x = vec1.x + vec2.x;
	summ_vec.y = vec1.y + vec2.y;
	summ_vec.z = vec1.z + vec2.z;
	summ_vec.w = 0;
	return (summ_vec);
}

t_vector	subb_vectors(t_vector vec1, t_vector vec2)
{
	vec2 = multp_vectors(vec2, -1);
	return (add_vectors(vec1, vec2));
}

t_vector	div_vectors(t_vector vec, float scalar)
{
	scalar = 1 / scalar;
	return (multp_vectors(vec, scalar));
}
