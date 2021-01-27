/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   world.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-orch <eel-orch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 14:11:28 by eel-orch          #+#    #+#             */
/*   Updated: 2021/01/27 14:11:36 by eel-orch         ###   ########.fr       */
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
