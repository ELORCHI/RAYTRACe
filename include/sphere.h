/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-orch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 09:12:05 by eel-orch          #+#    #+#             */
/*   Updated: 2021/01/19 11:26:38 by eel-orch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPHERE_H
# define SPHERE_H

# include "../include/rt.h"
# include "../include/ray.h"
# include <stdlib.h>

typedef	struct	s_sphere
{
	t_vector		orig;
	t_vector		color;
	float			rad;
	struct s_sphere	*next;
}				t_sphere;

bool			ft_touch(t_ray ray, t_sphere *sphere);
t_intersection	ray_sphere_intersection(t_ray ray, t_sphere *sphere);
bool			check_inter(t_ray ray, t_sphere *sphere);
t_vector		normal_at(t_sphere sphere, t_vector world_point);
void			translat(t_sphere *sphere, float x, float y, float z);

#endif
