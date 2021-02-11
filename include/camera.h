/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-orch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 18:56:23 by eel-orch          #+#    #+#             */
/*   Updated: 2021/01/18 15:38:51 by eel-orch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAMERA_H
# define CAMERA_H

# include "rt.h"

typedef struct	s_resolution
{
	int 	hsize;
	int 	vsize;
	//float	aspect;
	float	fov;
}				t_resolution;

typedef struct 	s_camera
{
	float		half_height;
	float		half_width;
	float		pixel_size;
	float		fov;//sheck that
	t_vector	orig;
	t_vector	dir;
	t_mat4x4	view;
	struct		s_camera *previous;
	struct  	s_camera *next;
}				t_camera;

void		set_camera_view(t_vector from, t_vector to);
void		camera(void);

t_resolution	g_resolution;
t_camera 		*g_camera;
t_camera		*g_cameras;
#endif
