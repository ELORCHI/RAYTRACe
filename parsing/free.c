/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-orch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 10:25:12 by eel-orch          #+#    #+#             */
/*   Updated: 2021/02/19 10:25:15 by eel-orch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	free_spheres(t_sphere **sphere)
{
	t_sphere *tmp_sphere;

	if (g_sphere == 1)
	{
		while (*sphere)
		{
			tmp_sphere = *sphere;
			*sphere = (*sphere)->next;
			free(tmp_sphere);
		}
	}
}

void	free_triangles(t_triangle **tr)
{
	t_triangle *tmp_tr;

	if (g_tr == 1)
	{
		while (*tr)
		{
			tmp_tr = *tr;
			*tr = (*tr)->next;
			free(tmp_tr);
		}
	}
}

void	free_cylinders(t_cylinder **cylinder)
{
	t_cylinder *tmp_cy;

	if (g_cyl == 1)
	{
		while (*cylinder)
		{
			tmp_cy = *cylinder;
			*cylinder = (*cylinder)->next;
			free(tmp_cy);
		}
	}
}

void	free_squares(t_square **square)
{
	t_square *tmp_sq;

	if (g_sq == 1)
	{
		while (*square)
		{
			tmp_sq = *square;
			*square = (*square)->next;
			free(tmp_sq);
		}
	}
}

void	free_planes(t_plan **plan)
{
	t_plan *tmp_plan;

	if (g_plan == 1)
	{
		while (*plan)
		{
			tmp_plan = *plan;
			*plan = (*plan)->next;
			free(tmp_plan);
		}
	}
}
