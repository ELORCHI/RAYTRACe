/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-orch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 09:47:10 by eel-orch          #+#    #+#             */
/*   Updated: 2021/01/21 10:59:52 by eel-orch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/sphere.h"
#include "../include/rt.h"
#include "../include/camera.h"

t_vector	normal_at(t_sphere sphere, t_vector hit_point)
{
	t_vector normal;

	normal = normaliz(point_vector(sphere.orig, hit_point));
	return (normal);
}
