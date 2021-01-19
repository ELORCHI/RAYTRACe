/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-orch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 18:42:23 by eel-orch          #+#    #+#             */
/*   Updated: 2021/01/18 15:39:15 by eel-orch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/camera.h"

void	camera(void)
{
	float half_view;
	float aspect;

	g_resolution.fov *= (M_PI / 180); 
	half_view = tan(g_resolution.fov / 2);
	aspect = (float)g_resolution.hsize / (float)g_resolution.vsize;
	if (aspect >= 1.0f)
	{
		g_camera.half_width = half_view;
		g_camera.half_height = (half_view / aspect);		
	}
	else
	{
		g_camera.half_width  = half_view * aspect;
		g_camera.half_height = half_view;
	}
	g_camera.pixel_size = (g_camera.half_width * 2) / (float)(g_resolution.hsize);
}
