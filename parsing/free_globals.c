/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_globals.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-orch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 14:45:43 by eel-orch          #+#    #+#             */
/*   Updated: 2021/02/10 14:45:46 by eel-orch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

//free camera
//not tested yet
void	free_globals()
{
	t_light *tmp;
	t_camera *free_cam;

	while (g_light != NULL)
	{
		tmp = g_light;
		g_light = g_light->next;
		free(tmp);
	}
	free(g_intersection);
	while (g_all_cameras != NULL)
	{
		free_cam = g_all_cameras;
		g_all_cameras = g_all_cameras->next;
		free(free_cam);
	}
}