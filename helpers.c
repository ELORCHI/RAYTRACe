/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-orch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 11:29:45 by eel-orch          #+#    #+#             */
/*   Updated: 2021/02/19 11:29:48 by eel-orch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/world.h"
#include "parsing/parsing.h"

void	check_mandatory(i)
{
	if (i == -1)
		ft_exit("ERROR \nInvalid scene file");
	else if (g_is_amb == 0)
	{
		ft_exit("ERROR\nambient light is missing");
		g_error = 1;
	}
	else if (g_is_resolution == 0)
	{
		ft_exit("ERROR\nresolution is missing");
		g_error = 1;
	}
}

void	init_world(t_world *world)
{
	world->sphere = NULL;
	world->plan = NULL;
	world->square = NULL;
	world->triangle = NULL;
	world->cylinder = NULL;
}

void	ft_free(char **to_free)
{
	int i;

	i = 0;
	while (to_free[i] != NULL)
	{
		free(to_free[i]);
		i++;
	}
	free(to_free);
}

void	noghmizete(t_world **world)
{
	if (g_error == 1)
		free_world(*world);
	else
		render(world);
}

void	free_world(t_world *world)
{
	free_spheres(&(world->sphere));
	free_planes(&(world->plan));
	free_cylinders(&(world->cylinder));
	free_squares(&(world->square));
	free_triangles(&(world->triangle));
	free_globals();
	free(world);
}
