/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-orch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/05 18:22:17 by eel-orch          #+#    #+#             */
/*   Updated: 2021/01/18 12:03:53 by eel-orch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAY_H
# define RAY_H

# include "../include/rt.h"

typedef struct	s_ray
{
	t_vector	orig;
	t_vector	dir;
}				t_ray;

typedef	struct	s_intersection
{
	float		hit;
	bool		is_shadow;
	t_vector	point;
	t_vector	normal;
	t_vector	color;
}				t_intersection;

t_vector		position(t_ray ray, float speed);
bool			ray_dot_normal(t_vector ray_dir, t_vector *normal);
t_ray			ray_for_pixel(int x, int y);
#endif
