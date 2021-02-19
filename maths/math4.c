/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math4.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-orch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 18:47:44 by eel-orch          #+#    #+#             */
/*   Updated: 2021/02/19 18:47:48 by eel-orch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/rt.h"
#include <stdlib.h>
#include <stdio.h>

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

void		fill_for_morm_shit(float x1, float x2)
{
	g_intersection[0] = x1;
	g_intersection[1] = x2;
}

bool		solve_quadratic(float a, float b, float c)
{
	float discr;
	float x;
	float y;
	float min;
	float max;

	fill_for_morm_shit(-1, -1);
	discr = (b * b) + (-4 * a * c);
	if (discr < 0)
		return (false);
	x = 0.5 * (-b - sqrt(discr)) / a;
	y = 0.5 * (-b + sqrt(discr)) / a;
	min = fminf(x, y);
	max = fmaxf(x, y);
	if (min >= 0)
		fill_for_morm_shit(min, max);
	else if (max >= 0)
		fill_for_morm_shit(max, max);
	else
	{
		fill_for_morm_shit(-1, -1);
		return (false);
	}
	return (true);
}
