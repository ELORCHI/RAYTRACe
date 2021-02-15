/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-orch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 12:10:57 by eel-orch          #+#    #+#             */
/*   Updated: 2021/02/01 12:11:01 by eel-orch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "libft/libft.h"
# include "gnl/get_next_line.h"
# include "../include/camera.h"
# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <math.h>
# include "../include/rt.h"
# include "../include/light.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

int 		ft_int_size(int i);
int			is_float(char *line);
int			get_scalar(char *line, float *scalar);
int			nb_zeros(char *line, int nb ,int index);
void		get_resolution(char **line);
void		ft_exit(char *error_message);
bool    	get_color(char *line, t_vector *color);
bool 		count_params(char **line, int params_number);
float		ft_atof(char *line);
t_vector 	get_vector(char *line);
void		free_planes(t_plan **plan);
void		free_squares(t_square **square);
void		free_cylinders(t_cylinder **cylinder);
void		free_triangles(t_triangle **tr);
void		free_spheres(t_sphere **sphere);
void		free_globals();
int			is_rt(char *line);
void		get_ambient(char **line);
void    	get_light(char **params);
void		get_camera(char **params);
void		get_cylinders(t_cylinder **cylinder, char **params);
void 		get_triangles(t_triangle **trinagle, char **params);
void		get_squares(t_square **square, char **params);
void 		get_plans(t_plan **plan, char **params);
void 		get_spheres(t_sphere **sphere, char **params);
#endif
