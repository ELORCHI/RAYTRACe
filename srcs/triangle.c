/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   triangle.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-orch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 18:30:33 by eel-orch          #+#    #+#             */
/*   Updated: 2021/01/19 18:44:11 by eel-orch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  "../include/triangle.h"

t_intersection ray_triangles_intersections(t_ray ray, t_triangle *triangle)
{
	// calulate two vectors AC AB using  the triangle vertices
	// then caluclate the normal using the cross product if these
	// test of the ray intersect the defined by the calculeted normal
	// if it is then using the the product test  if the point is inside or not 
}
