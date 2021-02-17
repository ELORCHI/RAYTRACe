/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   world.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-orch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 14:48:43 by eel-orch          #+#    #+#             */
/*   Updated: 2021/01/28 14:48:45 by eel-orch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WORLD_H
# define WORLD_H

# include "rt.h"
# include "square.h"
# include "sphere.h"
# include "ray.h"
# include "plan.h" 
# include "camera.h"
# include "triangle.h"
# include "cylinder.h"

typedef struct s_world
{
	t_sphere	*sphere;
	t_plan		*plan;
	t_triangle	*triangle;
	t_cylinder	*cylinder;
	t_square	*square;
}				t_world;

t_intersection	intersect_world(t_world world, t_ray ray);
t_intersection	intersect_objects(t_world world, t_ray ray);
void			render(t_world world);
#endif
