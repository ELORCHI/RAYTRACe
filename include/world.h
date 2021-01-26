/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   world.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Pythagoras <Pythagoras@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 14:58:49 by eel-orch          #+#    #+#             */
/*   Updated: 2021/01/26 23:53:12 by Pythagoras       ###   ########.fr       */
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
#include "cylinder.h"

typedef struct s_world
{
	t_sphere	*sphere;
	t_plan		*plan;
	t_triangle	*triangle;
	t_cylinder	*cylinders;
}				t_world;

t_intersection	intersect_world(t_world world, t_ray ray);
#endif
