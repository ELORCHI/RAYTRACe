/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quadratic.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-orch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 09:23:53 by eel-orch          #+#    #+#             */
/*   Updated: 2021/02/23 09:23:56 by eel-orch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/rt.h"
#include <stdlib.h>
#include <stdio.h>

void	min_max(float *min, float *max, float x, float y)
{
	*min = fminf(x, y);
	*max = fmaxf(x, y);
}

bool	solve_quadratic(float a, float b, float c)
{
	float discr;
	float x;
	float y;
	float min;
	float max;

	discr = (b * b) + (-4 * a * c);
	if (discr < 0)
		return (false);
	x = 0.5 * (-b - sqrt(discr)) / a;
	y = 0.5 * (-b + sqrt(discr)) / a;
	min_max(&min, &max, x, y);
	if (min >= 0)
	{
		g_intersection[0] = min;
		g_intersection[1] = max;
	}
	else if (max >= 0)
	{
		g_intersection[0] = max;
		g_intersection[1] = max;
	}
	else
		return (false);
	return (true);
}
