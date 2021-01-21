/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   world.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-orch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 14:58:49 by eel-orch          #+#    #+#             */
/*   Updated: 2021/01/21 15:27:54 by eel-orch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WORLD_H
# define WORLD_H

# include "rt.h"
# include "sphere.h"
# include "ray.h"
# include "plan.h"
# include "camera.h"
#include "triangle.h"

typedef struct s_world
{
	t_sphere	*sphere;
	t_plan		*plan;
	t_triangle	*triangle;
}				t_world;

t_intersection	intersect_world(t_world world, t_ray ray);
#endif
