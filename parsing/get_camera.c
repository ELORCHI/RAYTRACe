/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_camera.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-orch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 16:24:15 by eel-orch          #+#    #+#             */
/*   Updated: 2021/02/10 16:24:18 by eel-orch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	init_camera()
{
	g_cameras->half_height = 0;
	g_cameras->half_width = 0;
	g_cameras->pixel_size = 0;
	g_cameras->orig = (t_vector){0, 0, 0, 0};
	g_cameras->dir = (t_vector){0, 0, 0, 0};
	g_cameras->next = NULL;
}

void	add_cameras(t_camera **tmp)
{
	t_camera *pars;
	t_camera *prev;

	pars = g_cameras;
	while (pars->next != NULL)
	{
		prev = pars;
		pars = pars->next;
	}
	pars->next = *tmp;
	pars->previous = prev;
}

void	get_camera(char **params)
{
	t_camera 	*tmp;
	static int 	i = 0;

	count_params(params, 4);
	tmp = (t_camera *)malloc(sizeof(t_camera));
	init_camera();
	params++;
	tmp->orig = get_vector(*params);// change vector to assigne 0 or one to the vetor
	params++;
	tmp->dir = get_vector(*params);
	params++;
	get_scalar(*params, &(tmp->fov));
	if (tmp->fov < 0 || tmp->fov > 180)
		ft_exit("ERROR\n FOV must be positive");
	tmp->next = NULL;
	if (i == 0)
	{
		g_cameras = tmp;
		g_cameras->previous = NULL;
	}
	else
		add_cameras(&tmp);
}