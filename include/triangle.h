/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   triangle.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-orch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 18:15:30 by eel-orch          #+#    #+#             */
/*   Updated: 2021/01/21 15:33:54 by eel-orch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TRIANGLE_H
# define TRIANGLE_H

# include "rt.h"
# include "ray.h"

typedef struct	s_triangle
{
	t_vector			p1;
	t_vector			p2;
	t_vector			p3;
	t_vector			normal;
	t_vector			color;
	struct s_triangle	*next;
}				t_triangle;

typedef struct	s_vertex
{
	t_vector	edge1;
	t_vector	edge2;
	t_vector	ray_to_tr;
	float		u;
	float		v;
}				t_vertex;

t_intersection	ray_triangles_intersections(t_ray ray, t_triangle *triangle);
t_vector		normal_tr(t_triangle tr);
#endif
